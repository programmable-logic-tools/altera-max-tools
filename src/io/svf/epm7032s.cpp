
#include "svf/epm7032s.hpp"

using namespace SVF;


void EPM7032S::setupRegisterWidths()
{
    setIRWidth(10);
    setDRWidth(IR_ISC_ENABLE, 0);
    setDRWidth(IR_ISC_DISABLE, 0);
    setDRWidth(IR_01E, 237);
}


void EPM7032S::generateSequence()
{
    clearSequence();

    svf << "!" << endl;
    svf << "! Target device: Altera MAX7032S CPLD (EPM7032S)" << endl;
    svf << "!" << endl;

    enterISP();
    checkSiliconID();
    bulkErase();
    program();
    verify();
    exitISP();
}


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
    svf << state("IDLE");
    svf << "!" << endl;

    // Enter ISP mode: I/O pins transition to a safe state (see device datasheet)
    svf << sir(IR_ISC_ENABLE);
    // Wait for a little longer than 1ms in the idle state
    svf << "RUNTEST IDLE 10003 TCK ENDSTATE IDLE;" << endl;
}


void EPM7032S::checkSiliconID()
{
    svf << "TODO: Check Silicon ID" << endl;
}


void EPM7032S::bulkErase()
{
    svf << "TODO: Bulk Erase" << endl;
}


void EPM7032S::program()
{
    svf << "TODO: Program" << endl;
    // program all the pages
}


void EPM7032S::verify()
{
    svf << "TODO: Verify" << endl;
}


void EPM7032S::exitISP()
{
    svf << sir(IR_ISC_DISABLE);
    svf << runtest(10003, "TCK");
    svf << sir(IR_01E);
    svf << runtest(10000, "TCK");
    svf << state("IDLE");
}
