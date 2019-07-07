
#include "svf/epm7032s.hpp"

using namespace SVF;


void EPM7032S::enterISP()
{
    // Set the JTAG clock frequency
    svf << "FREQUENCY 1.00E+07 HZ;" << endl;
    svf << "!" << endl;

    // We are not using the TRST signal
    svf << "TRST ABSENT;" << endl;
    // After shifting the data register (DR), returns to the idle state
    svf << "ENDDR IDLE;" << endl;
    // After shifting the instruction register (IR), proceed to the IR pause state
    svf << "ENDIR IRPAUSE;" << endl;
    // Go to state idle now
    svf << "STATE IDLE;" << endl;

    // Enter ISP mode: I/O pins transition to a safe state (see device datasheet)
    svf << "SIR 10 TDI (071);" << endl;
    // Wait for a little longer than 1ms in the idle state
    svf << "RUNTEST IDLE 10003 TCK ENDSTATE IDLE;" << endl;
}


void EPM7032S::checkSiliconID()
{

}


void EPM7032S::bulkErase()
{

}


void EPM7032S::program()
{

}


void EPM7032S::verify()
{

}


void EPM7032S::exitISP()
{

}
