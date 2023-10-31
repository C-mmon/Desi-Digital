uint16_t ora16[byte_count / sizeof(uint16_t)];
uint16_t oro16[byte_count / sizeof(uint16_t)];

Then copy our data from 

memcpy(ora16, output_rand, byte_count);
memcpy(oro16, output_rom, byte_count);