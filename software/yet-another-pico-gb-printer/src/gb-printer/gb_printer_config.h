#ifndef __GB_PRINTER_CONFIG__H__
#define __GB_PRINTER_CONFIG__H__

#include <stdint.h>

#define GBP_BUFFER_SIZE 650  //maximal size of data buffer 640 bytes + commands
#define GBP_FEATURE_PARSE_PACKET_MODE
#define GBP_FEATURE_PARSE_PACKET_USE_DECOMPRESSOR

extern unsigned int Next_ID, Next_dir;                           //for directories and filenames
extern unsigned char printer_memory_buffer_core_0[9 * 640 + 1];  //Game Boy printer buffer of 9*640 bytes (maximum possible + margin in case of buffer overflow), core 0
extern unsigned char printer_memory_buffer_core_1[9 * 640 + 1];  //Game Boy printer buffer of 9*640 bytes (maximum possible + margin in case of buffer overflow), core 1
extern unsigned char TFT_memory_buffer[240 * 160];               //TFT buffer, a whole display vertical strip
extern unsigned char PNG_image_color[144 * 160];                 //"color" RGB 2bbp data, cannot be more than a full Game Boy screen at once
extern char png_storage_file_name[64];                           //character string to store images
extern char tmp_storage_file_name[64];                           //character string to store images
extern unsigned char inner_palette;                              //inner palette to use for core 1
extern unsigned char inner_lower_margin;                         //inner margin to use for core 1
//This array contains preformated pixels for 2bbp png mode, 4 pixels per bytes, assuming a 4x upscaling factor and so 4 consecutive pixels identical stored per bytes
extern unsigned char PNG_compress_4x[4];  //lookup table for PNG 2 bpp format. 1 byte = 4 identical pixels on a line
//unsigned char PNG_palette_RGB[12] = { 123, 129, 16, 89, 121, 66, 73, 90, 40, 46, 69, 54 };//DMG palette
//unsigned char PNG_palette_RGB[12] = { 197, 202, 165, 140, 146, 107, 105, 108, 90, 24, 24, 24 };//GBpocket palette
//unsigned char PNG_palette_RGB[12] = { 255, 255, 255, 127, 253, 55, 0, 100, 198, 0, 0, 0 };//GBcolor palette
extern unsigned char PNG_palette_RGB[12];  //RGB colors as they will appear in the PNG file
extern unsigned char image_palette[4];                            //2 bpp local color palette sent by the Game Boy
extern unsigned char DATA_packet_counter;                     //counter for packets transmitted
extern unsigned char DATA_packet_to_print;                    //counter for packets transmitted for core 1
extern unsigned char local_byte_LSB;                          //storage byte for conversion
extern unsigned char local_byte_MSB;                          //storage byte for conversion
extern unsigned char pixel_level;                             //storage byte for conversion
extern unsigned int DATA_bytes_counter;                       //counter for data bytes
extern unsigned int DATA_bytes_to_print;                      //counter for data bytes
extern unsigned int IMAGE_bytes_counter;                      //counter for data bytes
extern unsigned int tile_column, pixel_line;       //storage variables for conversion
extern unsigned int offset_x;                                 //local variable for decoder
extern unsigned int max_tile_line;                            //local variable for decoder
extern unsigned int max_pixel_line;                           //local variable for decoder
extern unsigned int TFT_offset;                               //offset for display in automatic mode in pixels
extern unsigned int max_files_per_folder;                  //FAT32 limits the number of entries, so better be carefull
extern unsigned long lines_in_image_file;                     //to keep tack of image file length
extern unsigned long myTimetimer;
extern unsigned long FILE_number;                             //counter of file per session
extern bool SDcard_READY;                                     //self explanatory
extern bool PRINT_flag;                                      //self explanatory
extern bool TEAR_mode;                                        //self explanatory
extern bool skip_byte_on_displa;     

#endif  //!__GB_PRINTER_CONFIG__H__

