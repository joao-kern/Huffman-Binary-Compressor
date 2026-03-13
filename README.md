# C++ Custom File Compressor (Huffman Coding)

A high-performance, lossless file compression utility built entirely from scratch in C++.

This project goes beyond standard library usage by implementing the classic **Huffman Coding** algorithm alongside custom **bit-level file I/O operations**. It was designed with a focus on deep computer science fundamentals, including memory management, bitwise operations, and the architecture of binary file formats.

## 🚀 Key Features

- **Custom Bit-Stream Architecture:** Implements bespoke `BitReader` and `BitWriter` classes to handle data at the bit level (rather than byte level), packing variable-length Huffman codes seamlessly into standard 8-bit output buffers.
- **Proprietary Binary Format (`Format.h`):** Defines a custom, memory-aligned POD (Plain Old Data) header structure to serialize the compression metadata. It safely stores the file signature, original extension, and the symbol frequency array.
- **Two-Pass Compression Algorithm:** 1. Reads the raw file to analyze byte frequencies and dynamically generate an optimal Prefix Code tree. 2. Reads the file a second time to encode and write the compressed bitstream.
- **Huffman Implementation:** Features a custom-built `Huffman tree` for optimal Prefix Code generation. The decoding logic utilizes a cursor-driven state machine, ensuring safe, memory-efficient bit traversal and robust protection against corrupted bitstreams.
- **Universal File Support:** Processes data strictly as `uint8_t` (bytes) rather than strings, allowing the compression of _any_ file type (text, binaries, executables), not just `.txt` files.
- **Memory Safe:** Strict adherence to Object-Oriented principles and raw pointer lifecycle management to ensure zero memory leaks during tree generation and file stream handling.

## 🧠 Technical Architecture

### The File Header (`Format.h`)

To ensure robust decompression, the output file begins with a strict binary header:

1.  **Signature:** A magic number/string to validate the file type.
2.  **Original Extension:** A statically sized `char[16]` array to remember the original file format (e.g., `.pdf`, `.txt`).
3.  **Total Symbols:** A `uint64_t` count to prevent the decompressor from reading padded "garbage" bits at the end of the final byte.
4.  **Frequency Array:** A statically allocated `std::array<std::size_t, 256>` mapping each possible byte (0-255) to its exact frequency, allowing the decompressor to reconstruct the exact same Huffman Tree perfectly.

## 🛠️ Getting Started

### Prerequisites

- A C++17 (or higher) compatible compiler (GCC, Clang, MSVC).
- Standard C++ libraries only (No external dependencies).

### Compilation

You can use the `Makefile` from the root directory:

```bash
make
```

Or compile the project using `g++` from the root directory:

```bash
g++ main.cpp core/*.cpp bitstream/*.cpp huffman/*.cpp -I ./huffman -I ./core -I ./bitstream -o compressor -O3
```

(Note: Replace the folder paths with your actual directory structure if different).

## 💻 Usage

The program runs via the command line interface:

**To Compress a file:**

```bash
./compressor <path_to_your_file> compress
```

**To Decompress a file:**

```bash
./compressor <path_to_compressed_file> decompress
```

## 🎯 Learning Outcomes

This project was developed as a hands-on exploration of lower-level software engineering concepts. It served as a practical application of Data Structures (Binary Trees, Priority Queues/Sorting), File System interactions, Endianness, and Bitwise manipulation (<<, >>, &, |).
