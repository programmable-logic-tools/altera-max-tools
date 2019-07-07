
#include <stdint.h>
#include "bitstream.hpp"


int main()
{
    Bitstream b;
    b.setBitCount(15033);

    SVF::EPM7032S f(b);
    f.saveToFile("test.svf");

    return 0;
}
