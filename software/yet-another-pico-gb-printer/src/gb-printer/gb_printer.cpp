
#include "gb_printer.h"

/* Serial IO */
// This circular buffer contains a stream of raw packets from the gameboy
uint8_t gbp_serialIO_raw_buffer[GBP_BUFFER_SIZE] = { 0 };

#ifdef GBP_FEATURE_PARSE_PACKET_MODE
/* Packet Buffer */
gbp_pkt_t gbp_pktState = { GBP_REC_NONE, 0 };
uint8_t gbp_pktbuff[GBP_PKT_PAYLOAD_BUFF_SIZE_IN_BYTE] = { 0 };
uint8_t gbp_pktbuffSize = 0;
#ifdef GBP_FEATURE_PARSE_PACKET_USE_DECOMPRESSOR
gbp_pkt_tileAcc_t tileBuff = { 0 };
#endif
#endif

#ifdef GBP_FEATURE_PARSE_PACKET_MODE
inline void gbp_parse_packet_loop();
#endif

/*******************************************************************************
  Utility Functions
*******************************************************************************/

const char* gbpCommand_toStr(int val) {
  switch (val) {
    case GBP_COMMAND_INIT: return "INIT";
    case GBP_COMMAND_PRINT: return "PRNT";
    case GBP_COMMAND_DATA: return "DATA";
    case GBP_COMMAND_BREAK: return "BREK";
    case GBP_COMMAND_INQUIRY: return "INQY";
    default: return "?";
  }
}


void gpio_irq_callback(uint gpio, uint32_t events) {
  if (gpio == GBP_SC_PIN) {
    bool so_bit = gpio_get(GBP_SO_PIN);  // Read the bit from the master (SO = Serial Output from Master)
    bool tx_bit;
#ifdef GBP_FEATURE_USING_RISING_CLOCK_ONLY_ISR
    tx_bit = gpb_serial_io_OnRising_ISR(so_bit);
#else
    bool sc_level = gpio_get(GBP_SC_PIN);
    tx_bit = gpb_serial_io_OnChange_ISR(sc_level, so_bit);
#endif
    gpio_put(GBP_SI_PIN, tx_bit);  // Write the response bit back to the master
  }
}

void gbp_init(){
  #ifdef GBP_FEATURE_USING_RISING_CLOCK_ONLY_ISR
  gpio_set_irq_enabled_with_callback(GBP_SC_PIN, GPIO_IRQ_EDGE_RISE, true, &gpio_irq_callback);
#else
  gpio_set_irq_enabled_with_callback(GBP_SC_PIN, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &gpio_irq_callback);
#endif
}