
#include <stdint.h>
#include "svf/epm7032s.hpp"
#include "bitstream.hpp"


int main()
{
    Bitstream b(15033);

    SVF::EPM7032S f(&b);
    f.generateSequence();
//    f.saveToFile("test.svf");

    cout << f;

    return 0;
}
