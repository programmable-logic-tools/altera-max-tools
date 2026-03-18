
#ifndef EPM7032S_HPP
#define EPM7032S_HPP

#include "devices.hpp"


/**
 * This class stores the configuration of an Altera MAX7032S PLD
 */
class EPM7032S: public ProgrammableLogicDevice
{
public:
    EPM7032S(): lab_count(2) {};
    ~EPM7032S();
};

#endif
