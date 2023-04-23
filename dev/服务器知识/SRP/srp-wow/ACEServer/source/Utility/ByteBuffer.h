/* 
 * Copyright (C) 2005 MaNGOS <http://www.magosproject.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _BYTEBUFFER_H
#define _BYTEBUFFER_H

#include <string>
#include <vector>
#include <list>
#include <map>
#include <cassert>

class ByteBuffer
{
    public:
        class error
        {
        };

        const static size_t DEFAULT_SIZE = 0x1000;

        ByteBuffer(): _rpos(0), _wpos(0)
        {
            _storage.reserve(DEFAULT_SIZE);
        }
        ByteBuffer(size_t res): _rpos(0), _wpos(0)
        {
            _storage.reserve(res);
        }
        ByteBuffer(const ByteBuffer &buf): _rpos(buf._rpos), _wpos(buf._wpos), _storage(buf._storage) { }

        void clear()
        {
            _storage.clear();
            _rpos = _wpos = 0;
        }

        
        
        

        template <typename T> void append(T value)
        {
            append((unsigned char *)&value, sizeof(value));
        }
        template <typename T> void put(size_t pos,T value)
        {
            put(pos,(unsigned char *)&value,sizeof(value));
        }

        
        ByteBuffer &operator<<(bool value)
        {
            append<char>((char)value);
            return *this;
        }
        ByteBuffer &operator<<(unsigned char value)
        {
            append<unsigned char>(value);
            return *this;
        }
        ByteBuffer &operator<<(unsigned short value)
        {
            append<unsigned short>(value);
            return *this;
        }
        ByteBuffer &operator<<(unsigned long value)
        {
            append<unsigned long>(value);
            return *this;
        }
        ByteBuffer &operator<<(unsigned __int64 value)
        {
            append<unsigned _int64>(value);
            return *this;
        }
        ByteBuffer &operator<<(float value)
        {
            append<float>(value);
            return *this;
        }
        ByteBuffer &operator<<(double value)
        {
            append<double>(value);
            return *this;
        }
        ByteBuffer &operator<<(const std::string &value)
        {
            append((unsigned char *)value.c_str(), value.length());
            append((unsigned char)0);
            return *this;
        }
        ByteBuffer &operator<<(const char *str)
        {
            append((unsigned char *)str, strlen(str));
            append((unsigned char)0);
            return *this;
        }

        
        ByteBuffer &operator>>(bool &value)
        {
            value = read<char>() > 0 ? true : false;
            return *this;
        }
        ByteBuffer &operator>>(unsigned char &value)
        {
            value = read<unsigned char>();
            return *this;
        }
        ByteBuffer &operator>>(unsigned short &value)
        {
            value = read<unsigned short>();
            return *this;
        }
        ByteBuffer &operator>>(unsigned long &value)
        {
            value = read<unsigned long>();
            return *this;
        }
        ByteBuffer &operator>>(unsigned __int64 &value)
        {
            value = read<unsigned __int64>();
            return *this;
        }
        ByteBuffer &operator>>(float &value)
        {
            value = read<float>();
            return *this;
        }
        ByteBuffer &operator>>(double &value)
        {
            value = read<double>();
            return *this;
        }
        ByteBuffer &operator>>(std::string& value)
        {
            value.clear();
            while (true)
            {
                char c=read<char>();
                if (c==0)
                    break;
                value+=c;
            }
            return *this;
        }

        unsigned char operator[](size_t pos)
        {
            return read<unsigned char>(pos);
        }

        size_t rpos()
        {
            return _rpos;
        };

        size_t rpos(size_t rpos)
        {
            _rpos = rpos;
            return _rpos;
        };

        size_t wpos()
        {
            return _wpos;
        }

        size_t wpos(size_t wpos)
        {
            _wpos = wpos;
            return _wpos;
        }

        template <typename T> T read()
        {
            T r=read<T>(_rpos);
            _rpos += sizeof(T);
            return r;
        };
        template <typename T> T read(size_t pos) const
        {
            assert(pos + sizeof(T) <= size());
            return *((T*)&_storage[pos]);
        }

        void read(unsigned char *dest, size_t len)
        {
            if (_rpos + len <= size())
            {
                memcpy(dest, &_storage[_rpos], len);
            }
            else
            {
                throw error();
            }
            _rpos += len;
        }

        const unsigned char *contents() const { return &_storage[0]; };

        inline size_t size() const { return _storage.size(); };
        
        void resize(size_t newsize)
        {
            _storage.resize(newsize);
            _rpos = 0;
            _wpos = size();
        };
        void reserve(size_t ressize)
        {
            if (ressize > size()) _storage.reserve(ressize);
        };

        
        void append(const std::string& str)
        {
            append((unsigned char *)str.c_str(),str.size() + 1);
        }
        void append(const char *src, size_t cnt)
        {
            return append((const unsigned char *)src, cnt);
        }
        void append(const unsigned char *src, size_t cnt)
        {
            if (!cnt) return;

            
            
            
            
            
            assert(size() < 10000000);

            if (_storage.size() < _wpos + cnt)
                _storage.resize(_wpos + cnt);
            memcpy(&_storage[_wpos], src, cnt);
            _wpos += cnt;
        }
        void append(const ByteBuffer& buffer)
        {
            append(buffer.contents(),buffer.size());
        }

        void put(size_t pos, const unsigned char *src, size_t cnt)
        {
            assert(pos + cnt <= size());
            memcpy(&_storage[pos], src, cnt);
        }
        void print_storage()
        {
            printf("STORAGE_SIZE: %u\n", size() );
            for(unsigned char i = 0; i < size(); i++)
                printf("%u - ", read<unsigned char>(i) );
        }

		void hexlike()
		{
			unsigned long j = 1, k = 1;
			printf("STORAGE_SIZE: %u\n", size() );
			for(unsigned long i = 0; i < size(); i++)
			{
				if ((i == (j*8)) && ((i != (k*16))))
				{
					if (read<unsigned char>(i) < 0x0F)
					{
						printf("| 0%X ", read<unsigned char>(i) );
					}
					else
					{
						printf("| %X ", read<unsigned char>(i) );
					}

					j++;
				}
				else if (i == (k*16))
				{
					if (read<unsigned char>(i) < 0x0F)
					{
						printf("\n0%X ", read<unsigned char>(i) );
					}
					else
					{
						printf("\n%X ", read<unsigned char>(i) );
					}

					k++;
					j++;
				}
				else
				{
					if (read<unsigned char>(i) < 0x0F)
					{
						printf("0%X ", read<unsigned char>(i) );
					}
					else
					{
						printf("%X ", read<unsigned char>(i) );
					}
				}
			}
			printf("\n");

		}



        
        
        

    protected:
        
        size_t _rpos, _wpos;
        std::vector<unsigned char> _storage;
};





template <typename T> ByteBuffer &operator<<(ByteBuffer &b, std::vector<T> v)
{
    b << (unsigned long)v.size();
    for (typename std::vector<T>::iterator i = v.begin(); i != v.end(); i++)
    {
        b << *i;
    }
    return b;
}


template <typename T> ByteBuffer &operator>>(ByteBuffer &b, std::vector<T> &v)
{
    unsigned long vsize;
    b >> vsize;
    v.clear();
    while(vsize--)
    {
        T t;
        b >> t;
        v.push_back(t);
    }
    return b;
}


template <typename T> ByteBuffer &operator<<(ByteBuffer &b, std::list<T> v)
{
    b << (unsigned long)v.size();
    for (typename std::list<T>::iterator i = v.begin(); i != v.end(); i++)
    {
        b << *i;
    }
    return b;
}


template <typename T> ByteBuffer &operator>>(ByteBuffer &b, std::list<T> &v)
{
    unsigned long vsize;
    b >> vsize;
    v.clear();
    while(vsize--)
    {
        T t;
        b >> t;
        v.push_back(t);
    }
    return b;
}


template <typename K, typename V> ByteBuffer &operator<<(ByteBuffer &b, std::map<K, V> &m)
{
    b << (unsigned long)m.size();
    for (typename std::map<K, V>::iterator i = m.begin(); i != m.end(); i++)
    {
        b << i->first << i->second;
    }
    return b;
}


template <typename K, typename V> ByteBuffer &operator>>(ByteBuffer &b, std::map<K, V> &m)
{
    unsigned long msize;
    b >> msize;
    m.clear();
    while(msize--)
    {
        K k;
        V v;
        b >> k >> v;
        m.insert(make_pair(k, v));
    }
    return b;
}
#endif
