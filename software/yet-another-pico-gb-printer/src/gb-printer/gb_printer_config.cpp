#include "gb_printer_config.h"

unsigned int Next_ID, Next_dir;                           //for directories and filenames
unsigned char printer_memory_buffer_core_0[9 * 640 + 1];  //Game Boy printer buffer of 9*640 bytes (maximum possible + margin in case of buffer overflow), core 0
unsigned char printer_memory_buffer_core_1[9 * 640 + 1];  //Game Boy printer buffer of 9*640 bytes (maximum possible + margin in case of buffer overflow), core 1
unsigned char TFT_memory_buffer[240 * 160];               //TFT buffer, a whole display vertical strip
unsigned char PNG_image_color[144 * 160];                 //"color" RGB 2bbp data, cannot be more than a full Game Boy screen at once
char png_storage_file_name[64];                           //character string to store images
char tmp_storage_file_name[64];                           //character string to store images
unsigned char inner_palette;                              //inner palette to use for core 1
unsigned char inner_lower_margin;                         //inner margin to use for core 1
//This array contains preformated pixels for 2bbp png mode, 4 pixels per bytes, assuming a 4x upscaling factor and so 4 consecutive pixels identical stored per bytes
unsigned char PNG_compress_4x[4] = { 0b00000000, 0b01010101, 0b10101010, 0b11111111 };  //lookup table for PNG 2 bpp format. 1 byte = 4 identical pixels on a line
//unsigned char PNG_palette_RGB[12] = { 123, 129, 16, 89, 121, 66, 73, 90, 40, 46, 69, 54 };//DMG palette
//unsigned char PNG_palette_RGB[12] = { 197, 202, 165, 140, 146, 107, 105, 108, 90, 24, 24, 24 };//GBpocket palette
//unsigned char PNG_palette_RGB[12] = { 255, 255, 255, 127, 253, 55, 0, 100, 198, 0, 0, 0 };//GBcolor palette
unsigned char PNG_palette_RGB[12] = { 0xFF, 0xFF, 0xFF,
                                      0xAA, 0xAA, 0xAA,
                                      0x55, 0x55, 0x55,
                                      0x00, 0x00, 0x00 };  //RGB colors as they will appear in the PNG file
unsigned char image_palette[4];                            //2 bpp local color palette sent by the Game Boy
unsigned char DATA_packet_counter = 0;                     //counter for packets transmitted
unsigned char DATA_packet_to_print = 0;                    //counter for packets transmitted for core 1
unsigned char local_byte_LSB = 0;                          //storage byte for conversion
unsigned char local_byte_MSB = 0;                          //storage byte for conversion
unsigned char pixel_level = 0;                             //storage byte for conversion
unsigned int DATA_bytes_counter = 0;                       //counter for data bytes
unsigned int DATA_bytes_to_print = 0;                      //counter for data bytes
unsigned int IMAGE_bytes_counter = 0;                      //counter for data bytes
unsigned int tile_column, tile_line, pixel_line = 0;       //storage variables for conversion
unsigned int offset_x = 0;                                 //local variable for decoder
unsigned int max_tile_line = 0;                            //local variable for decoder
unsigned int max_pixel_line = 0;                           //local variable for decoder
unsigned int TFT_offset = 8;                               //offset for display in automatic mode in pixels
unsigned int max_files_per_folder = 1024;                  //FAT32 limits the number of entries, so better be carefull
unsigned long lines_in_image_file = 0;                     //to keep tack of image file length
unsigned long myTime;                                      //timer for PNG encoder
unsigned long FILE_number = 0;                             //counter of file per session
bool SDcard_READY = 0;                                     //self explanatory
bool PRINT_flag = 0;                                       //self explanatory
bool TEAR_mode = 0;                                        //self explanatory
bool skip_byte_on_display = 1;   