

#define boot_loader_size (0x8000) //32 kilobyte
#define main_application_Start_Address (FLASH_BASE_ADDRESS +BOOT_LOADER_SIZE)

/ FLASH MEMORY                      /
/ BLR CODE / MAIN APPLICATION CODE /

void jump_to_main(void)
{
    //function pointer returns nothing and takes nothing 
    typedef void (*void_fn)(void);
    
    //find the address of the main application 

    //each entry in the vector table is 4 byte
    //we add the stack pointer to this 
    uint32_t* reset_vector_entry =  (uint32_t*) (main_application_Start_Address+ 4U);

    //Now the table itself contain another pointer.
    uint32_t* reset_vector = (uint32_t*) (*reset_vector_entry);

    //we have to interpret that address as the functiom and jump to that
    void_fn jump_fn = (void_fn)reset_vector;

    jump_fn();


}
int main(void)
{

    //read gpio pins and so 
   jump_to_main();
    //never return 

    return 0;
}

//also ensure to pad the bootloader
bytes_to_pad= bootloader_size-len(raw_file)
padding= something 

//write to the file 

//perform this operation in another c function 
