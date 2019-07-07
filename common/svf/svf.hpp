
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
    SVFFile() { setupRegisterWidths(); bitstream = NULL; clearSequence(); }
    SVFFile(Bitstream* b) :SVFFile() { importBitstream(b); }

    /**
     * Use this method to import a bitstream
     * after the object has been initialized
     */
    void importBitstream(Bitstream* b) { bitstream = b; generateSequence(); }

    /**
     * Output the generated SVF to a stream
     */
    void exportToStream(ostream& stream) { stream << svf.str(); }

    /**
     * Output the generated SVF to a file
     */
    void saveToFile(string filename)
    {
        // Open file as stream
        ofstream f(filename);
        if (f.fail())
        {
            cerr << "Error: Failed to open " << filename << " for writing." << endl;
            return;
        }
        // Write the SVF to the file
        exportToStream(f);
        // Close the file
        f.close();
    }

protected:
    /**
     * This defines the bit width of the instruction register
     * of the target device's JTAG machine
     */
    void setIRWidth(uint16_t width) { irWidth = width; }

    /**
     * This defines the bit width of the data register
     * selected by the specified instruction register value
     */
    void setDRWidth(uint16_t ir, uint16_t width) { drWidths.insert(make_pair(ir, width)); }

    /**
     * The child classes must implement a method
     * that sets up all used registers of the corresponding target device
     * in order to be able to use the SVF instruction macros
     */
    virtual void setupRegisterWidths() {};

    /**
     * Generate the appropriate sequence of JTAG transactions
     * to program the target device
     *
     * This method must be overloaded by the child classes.
     */
    virtual void generateSequence() {}

    /**
     * Remove all lines from the SVF buffer
     */
    void clearSequence() { svf.str(""); }

};


#endif
