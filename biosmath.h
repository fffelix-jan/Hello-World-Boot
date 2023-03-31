unsigned int intsqrt(unsigned int x)
{
    unsigned int result = 0;
    unsigned int bit = 1 << 30; // The second-to-top bit is set: 1 << 30 for 32 bits
    // Find the highest bit set in the input
    while (bit > x)
        bit >>= 2;

    while (bit != 0)
    {
        if (x >= result + bit)
        {
            x -= result + bit;
            result = (result >> 1) + bit;
        }
        else
        {
            result >>= 1;
        }
        bit >>= 2;
    }
    return result;
}
