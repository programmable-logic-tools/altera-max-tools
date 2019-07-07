
#include "svf/svf.hpp"


void SVFFile::exportToStream(ostream& stream)
{
    stream << svf.str();
}


void SVFFile::saveToFile(string filename)
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


string SVFFile::state(string state)
{
    return "STATE " + state + ";\n";
}


string SVFFile::runtest(uint32_t run_count, string run_clk="")
{
    return "RUNTEST " + to_string(run_count) + (run_clk != "" ? " " + run_clk : "") + ";\n";
}


string SVFFile::sir(uint16_t ir)
{
    // Remember the current value inside the IR
    currentIRValue = ir;
    return "SIR (" + to_string(getIRWidth()) + ") TDI (" + hexfill(ir, getIRWidth()) + ");\n";
}


string SVFFile::sdr(uint16_t dr)
{
    uint16_t width = getDRWidth(currentIRValue);
    return "SDR (" + to_string(width) + ") TDI (" + hexfill(dr, width) + ");\n";
}


string SVFFile::hexfill(uint32_t value, uint8_t bits)
{
    // TODO
    ostringstream oss;
    oss << hex << value;
    return oss.str();
}


ostream& operator<<(ostream& stream, SVFFile& f)
{
    f.exportToStream(stream);
    return stream;
}
