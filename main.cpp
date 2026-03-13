#include "Compressor.h"
#include "Decompressor.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Insufficient number of arguments entered." << '\n';
        return -1;
    }

    fs::path file_path = argv[1];

    std::string action = argv[2];

    try
    {
        if (action == "compress")
        {
            std::cout << "Compressing File " + file_path.filename().string() + " ..." << std::endl;
            Compressor *compressor = new Compressor(file_path);
            delete compressor;
            std::cout << "File Compressed Successfully!" << std::endl;
        }
        else if (action == "decompress")
        {
            std::cout << "Decompressing File " + file_path.filename().string() + " ..." << std::endl;
            Decompressor *decompressor = new Decompressor(file_path);
            delete decompressor;
            std::cout << "File Decompressed Successfully!" << std::endl;
        }
        else
        {
            std::cerr << "Non-existent action." << '\n';
            return -1;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return -1;
    }

    return 0;
}