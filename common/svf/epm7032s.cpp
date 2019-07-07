
#include "svf/epm7032s.hpp"

using namespace SVF;


void EPM7032S::beginSequence()
{
    clearSequence();

    svf << "! Target device: Altera MAX7032S CPLD (EPM7032S)"
    svf << "!" << endl;
    // Set the JTAG clock frequency
    svf << "FREQUENCY 1.00E+07 HZ;" << endl;
    svf << "!" << endl;
    // We are not using the TRST signal
    svf << "TRST ABSENT;" << endl;
    svf << "ENDDR IDLE;" << endl;
    svf << "ENDIR IRPAUSE;" << endl;
    svf << "STATE IDLE;" << endl;

    // Power up?
    svf << "SIR 10 TDI (071);" << endl;
    svf << "RUNTEST IDLE 10003 TCK ENDSTATE IDLE;" << endl;
}
