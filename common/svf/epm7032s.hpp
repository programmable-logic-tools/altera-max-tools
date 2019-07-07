
#ifndef SVF_EPM7032S_HPP
#define SVF_EPM7032S_HPP

#include "svf/svf.hpp"


namespace SVF
{

class EPM7032S: public SVFFile
{
public:
    /**
     * This method appends an SVF header
     */
    void beginSequence();

    /**
     * This method appends a sequence to the SVF stream
     * that checks if the target device is compatible
     */
    void checkViableTarget();

    /**
     * This method appends a sequence to the SVF stream
     * that erases all pages in the target device's flash memory
     */
    void bulkErase();

    /**
     * This method appends a sequence to the SVF stream
     * that programs our bitstream to the target device's flash memory
     */
    void programFlash();

    /**
     * This method appends a SVF footer
     */
    void endSequence();

    /**
     * Overload the parent class's generator method
     */
    virtual void generateJtagSequence()
    {
        beginSequence();
        checkViableTarget();
        bulkErase();
        programFlash();
        endSequence();
    }
}; // end class

} // end namespace

#endif
