
#ifndef PACKER_HPP
#define PACKER_HPP

#include <iostream>

#include "ByteStream.hpp"

using namespace std;


/**
 * This function creates a POF based on the provided data
 */
void pack(
        ByteStream& bitstream,
        string creatorSoftware,
        string targetDevice,
        ostream& poffile
        );

/**
 * This function extracts selected information from a given POF
 */
void unpack(
        istream& poffile,
        string& creatorSoftware,
        string& targetDevice,
        ByteStream& bitstream
        );


#endif
