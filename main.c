void print_string(const char* str)
{
    volatile char* video_memory = (volatile char*)0xb8000;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        video_memory[i * 2] = str[i];
        video_memory[i * 2 + 1] = 0x0f;
    }
}

void bootloader_main()
{
    print_string("Hello world, what is your name?");
    while (1) {}
}
