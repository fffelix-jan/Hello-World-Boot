void print_int(int value)
{
    char buffer[16];
    int i = 0;

    if (value < 0)
    {
        value = -value;
        write_char('-');
    }

    do
    {
        buffer[i++] = (value % 10) + '0';
        value /= 10;
    } while (value);

    while (i--)
    {
        write_char(buffer[i]);
    }
}

void printf(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    for (const char* p = format; *p; ++p)
    {
        if (*p != '%')
        {
            write_char(*p);
            continue;
        }

        ++p;

        switch (*p)
        {
        case 'd':
            print_int(va_arg(args, int));
            break;
        default:
            break;
        }
    }

    va_end(args);
}

int read_int()
{
    int value = 0;
    char ch;

    while (1)
    {
        ch = read_char();

        if (ch >= '0' && ch <= '9')
        {
            value = value * 10 + (ch - '0');
            write_char(ch);
        }
        else if (ch == '\r')
        {
            write_string("\r\n");
            break;
        }
        else
        {
            // ignore other characters
        }
    }

    return value;
}
