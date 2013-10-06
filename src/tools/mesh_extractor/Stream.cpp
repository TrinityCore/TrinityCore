#include "Stream.h"
#include <iostream>

Stream::Stream(char* buffer, uint32 size) : _size(size), _position(0)
{
    _buffer = new char[size];
    memcpy(_buffer, buffer, size); // Initialize the buffer
}

Stream::~Stream()
{
    delete[] _buffer;
}

char* Stream::Read(uint32 size)
{
    char* buff = new char[size];
    memcpy(buff, &_buffer[_position], size);
    _position += size;
    return buff;
}

void Stream::Seek(uint32 position, uint32 type)
{
    switch (type)
    {
        case SEEK_SET:
            _position = position;
            break;
        case SEEK_CUR:
            _position += position;
            break;
    }
}

std::string Stream::ReadString()
{
    std::string str;
    while (true)
    {
        char b = Read<char>();
        if (b == 0)
            break;
        str.push_back(b);
    }
    return str;
}