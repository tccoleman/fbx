#ifndef FBXUTIL_H
#define FBXUTIL_H

#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

namespace fbx {

	// "Constants"
#define 	FBX_VERSION				7400
#define		FBX_HEADER_VERSION		1003
#define		FBX_SCENEINFO_VERSION	100
#define		FBX_TEMPLATES_VERSION	100


    // WARNING:
    // this assumes that float is 32bit and double is 64bit
    // both conforming to IEEE 754, it does not assume endianness
    // it also assumes that signed integers are two's complement
    class Reader {
    public:
        Reader(std::ifstream *input);
        Reader(char *input);

        std::uint8_t readUint8();
        std::int8_t readInt8();
        std::uint16_t readUint16();
        std::int16_t readInt16();
        std::uint32_t readUint32();
        std::int32_t readInt32();
        std::uint64_t readUint64();
        std::string readString(uint32_t length);
        float readFloat();
        double readDouble();

        void read(char*, uint32_t);
    private:
        uint8_t getc();
        std::ifstream *ifstream;
        char *buffer;
        uint32_t i;
    };
    class Writer {
    public:
        Writer(std::ofstream *output);

        void write(std::uint8_t);
        void write(std::int8_t);
        void write(std::uint16_t);
        void write(std::int16_t);
        void write(std::uint32_t);
        void write(std::int32_t);
        void write(std::uint64_t);
        void write(std::int64_t);
        void write(const std::string&);
        void write(float);
        void write(double);
		void writeBlockSentinelData();

		fpos_t tell() {
			if (ofstream)
				return ofstream->tellp().seekpos();
			return 0;
		}

    private:
        void putc(uint8_t);
        std::ofstream *ofstream;
    };
}

#endif // FBXUTIL_H
