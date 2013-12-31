#ifndef STREAM_H
#define STREAM_H

#include "Define.h"
#include <iostream>

class Stream
{
public:
    Stream(char* buffer, uint32 size);
    ~Stream();

    template<typename T>
    T Read()
    {
        T ret = *((T*)(&_buffer[_position]));
        _position += sizeof(T);
        return ret;
    }

    template<typename T>
    void Read(T* dest, uint32 size)
    {
        memcpy(dest, &_buffer[_position], size);
        _position += size;
    }

    template<typename T>
    void Skip()
    {
        _position += sizeof(T);
    }

    char* Read(uint32 size);
    std::string ReadString();

    void Reset()
    {
        _position = 0;
    }

    void Seek(uint32 position, uint32 type);

    uint32 GetSize()
    {
        return _size;
    }

    uint32 GetPos()
    {
        return _position;
    }

private:
    char* _buffer;
    uint32 _size;
    uint32 _position;
};
#endif