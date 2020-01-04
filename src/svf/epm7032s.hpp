
#ifndef SVF_EPM7032S_HPP
#define SVF_EPM7032S_HPP

#include "svf/svf.hpp"


namespace SVF
{

class EPM7032S: public SVFFile
{
public:
    EPM7032S() :SVFFile() { setupRegisterWidths(); };
    EPM7032S(Bitstream* b) :EPM7032S() { importBitstream(b); };
    virtual ~EPM7032S() {};

    /**
     * Overload the parent class's generator method
     *
     * See also:
     * MAX7000 Programmable Logic Device Family datasheet, page 17: Programming Sequence
     */
    virtual void generateSequence();

protected:
    /**
     * IEEE 1532 instructions
     */
    const uint16_t IR_ISC_ENABLE = 0x71;
    const uint16_t IR_ISC_DISABLE = 0x79;
    // ISC_PROGRAM?
    // ISC_NOOP?
    const uint16_t IR_01E = 0x3E;

    virtual void setupRegisterWidths();

    /**
     * This method appends an SVF header
     */
    void enterISP();

    /**
     * This method appends a sequence to the SVF stream
     * that checks if the target device is compatible
     */
    void checkSiliconID();

    /**
     * This method appends a sequence to the SVF stream
     * that erases all pages in the target device's flash memory
     */
    void bulkErase();

    /**
     * This method appends a sequence to the SVF stream
     * that programs our bitstream to the target device's flash memory
     */
    void program();

    /**
     * The flash programming consists of n flash page writes
     */
    void programPage();

    /**
     * This method appends a sequence to the SVF stream
     * that checks the correctness of every bit
     * in the target device's flash memory
     */
    void verify();

    /**
     * This method appends a SVF footer
     */
    void exitISP();

}; // end class

} // end namespace


#endif
