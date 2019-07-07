
#ifndef SVF_HPP
#define SVF_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include "bitstream.hpp"

using namespace std;


/**
 * This class and it's child classes serve the purpose
 * of importing a bitstream and generating the appropriate sequence
 * of JTAG transactions to program the corresponding target device
 */
class SVFFile
{
private:
    /** Our bitstream */
    Bitstream* bitstream = NULL;

    /** Our SVF sequence */
    ostringstream svf;

public:
    SVFFile() { bitstream = NULL; clearSequence(); }
    SVFFile(Bitstream* b) { importBitstream(b); }

    /**
     * Remove all lines from the SVF buffer
     */
    void clearSequence() { svf.str(""); }

    /**
     * Use this method to import a bitstream
     * after the object has been initialized
     */
    void importBitstream(Bitstream* b) { bitstream = b; generateJtagSequence(); }

    /**
     * Generate the appropriate sequence of JTAG transactions
     * to program the target device
     *
     * This method must be overloaded by the child classes.
     */
    virtual void generateJtagSequence() {}

    /**
     * Output the generated SVF to a stream
     */
    void exportToStream(ostream& stream) { stream << svf; }

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
};

#endif
