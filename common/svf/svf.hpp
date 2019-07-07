
#ifndef SVF_HPP
#define SVF_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "bitstream.hpp"

using namespace std;


/**
 * This class and it's child classes serve the purpose
 * of importing a bitstream and generating the appropriate sequence
 * of JTAG transactions to program the corresponding target device
 */
class SVFFile
{
protected:
    /** Our bitstream */
    Bitstream* bitstream = NULL;

    /** Our SVF sequence */
    ostringstream svf;

    /** Instruction register bit width */
    uint16_t irWidth = 0;

    /** Data register bit widths */
    map<uint16_t, uint16_t> drWidths;

public:
    SVFFile() { bitstream = NULL; }
    SVFFile(Bitstream* b) { importBitstream(b); }

    /**
     * Use this method to import a bitstream
     * after the object has been initialized
     */
    void importBitstream(Bitstream* b) { bitstream = b; }

    /**
     * Generate the appropriate sequence of JTAG transactions
     * to program the target device
     *
     * This method must be overloaded by the child classes.
     */
    virtual void generateSequence() = 0;

    /**
     * Remove all lines from the SVF buffer
     */
    void clearSequence() { svf.str(""); }

    /**
     * Output the generated SVF to a stream
     */
    void exportToStream(ostream& stream);

    /**
     * Output the generated SVF to a file
     */
    void saveToFile(string filename);

protected:
    /**
     * This defines the bit width of the instruction register
     * of the target device's JTAG machine
     */
    void setIRWidth(uint16_t width) { irWidth = width; }

    uint16_t getIRWidth() { return irWidth; }

    /**
     * This defines the bit width of the data register
     * selected by the specified instruction register value
     */
    void setDRWidth(uint16_t ir, uint16_t width) { drWidths.insert(make_pair(ir, width)); }

    uint16_t getDRWidth(uint16_t r) { return drWidths[r]; }

    /**
     * The child classes must implement a method
     * that sets up all used registers of the corresponding target device
     * in order to be able to use the SVF instruction macros
     */
    virtual void setupRegisterWidths() = 0;


    /********* SVF macros (IEEE 1532) *********/

    static string state(string state);
    static string runtest(uint32_t run_count, string run_clk);

    uint16_t currentIRValue = 0;
    string sir(uint16_t ir);
    string sdr(uint16_t dr);

    /**
     * Creates a SVF-conform hexadecimal representation
     * of the value including the least significant n bits
     */
    static string hexfill(uint32_t value, uint8_t bits);
};


/**
 * Allows to output a SVF-formatted string e.g. to stdout
 */
ostream& operator<<(ostream& stream, SVFFile& f);


#endif
