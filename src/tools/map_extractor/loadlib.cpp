/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#define _CRT_SECURE_NO_DEPRECATE

#include "loadlib.h"
#include <CascLib.h>

u_map_fcc MverMagic = { { 'R','E','V','M' } };

ChunkedFile::ChunkedFile()
{
    data = nullptr;
    data_size = 0;
}

ChunkedFile::~ChunkedFile()
{
    free();
}

bool ChunkedFile::loadFile(std::shared_ptr<CASC::Storage const> mpq, std::string const& fileName, bool log)
{
    free();
    std::unique_ptr<CASC::File> file(mpq->OpenFile(fileName.c_str(), CASC_LOCALE_ALL_WOW, log));
    if (!file)
        return false;

    int64 fileSize = file->GetSize();
    if (fileSize == -1)
        return false;

    data_size = uint32(fileSize);
    data = new uint8[data_size];
    uint32 bytesRead = 0;
    if (!file->ReadFile(data, data_size, &bytesRead) || bytesRead != data_size)
        return false;

    parseChunks();
    if (prepareLoadedData())
        return true;

    printf("Error loading %s\n", fileName.c_str());
    free();

    return false;
}

bool ChunkedFile::loadFile(std::shared_ptr<CASC::Storage const> mpq, uint32 fileDataId, std::string const& description, bool log)
{
    free();
    std::unique_ptr<CASC::File> file(mpq->OpenFile(fileDataId, CASC_LOCALE_ALL_WOW, log));
    if (!file)
        return false;

    int64 fileSize = file->GetSize();
    if (fileSize == -1)
        return false;

    data_size = fileSize;
    data = new uint8[data_size];
    uint32 bytesRead = 0;
    if (!file->ReadFile(data, data_size, &bytesRead) || bytesRead != data_size)
        return false;

    parseChunks();
    if (prepareLoadedData())
        return true;

    printf("Error loading %s\n", description.c_str());
    free();

    return false;
}

bool ChunkedFile::prepareLoadedData()
{
    FileChunk* chunk = GetChunk("MVER");
    if (!chunk)
        return false;

    // Check version
    file_MVER* version = chunk->As<file_MVER>();
    if (version->fcc != MverMagic.fcc)
        return false;
    if (version->ver != FILE_FORMAT_VERSION)
        return false;
    return true;
}

void ChunkedFile::free()
{
    for (auto& chunk : chunks)
        delete chunk.second;

    chunks.clear();

    delete[] data;
    data = nullptr;
    data_size = 0;
}

u_map_fcc InterestingChunks[] =
{
    { { 'R', 'E', 'V', 'M' } },
    { { 'N', 'I', 'A', 'M' } },
    { { 'O', '2', 'H', 'M' } },
    { { 'K', 'N', 'C', 'M' } },
    { { 'T', 'V', 'C', 'M' } },
    { { 'O', 'M', 'W', 'M' } },
    { { 'Q', 'L', 'C', 'M' } },
    { { 'O', 'B', 'F', 'M' } },
    { { 'D', 'H', 'P', 'M' } },
    { { 'D', 'I', 'A', 'M' } }
};

bool IsInterestingChunk(u_map_fcc const& fcc)
{
    for (u_map_fcc const& f : InterestingChunks)
        if (f.fcc == fcc.fcc)
            return true;

    return false;
}

void ChunkedFile::parseChunks()
{
    uint8* ptr = GetData();
    // Make sure there's enough data to read u_map_fcc struct and the uint32 size after it
    while (ptr <= GetData() + GetDataSize() - 8)
    {
        u_map_fcc header = *(u_map_fcc*)ptr;
        if (IsInterestingChunk(header))
        {
            uint32 size = *(uint32*)(ptr + 4);
            if (size <= data_size)
            {
                std::swap(header.fcc_txt[0], header.fcc_txt[3]);
                std::swap(header.fcc_txt[1], header.fcc_txt[2]);

                FileChunk* chunk = new FileChunk(ptr, size);
                chunk->parseSubChunks();
                chunks.insert({ std::string(header.fcc_txt, 4), chunk });
            }

            // move to next chunk
            ptr += size + 8;
        }
        else
            ++ptr;
    }
}

FileChunk* ChunkedFile::GetChunk(std::string const& name)
{
    auto range = chunks.equal_range(name);
    if (std::distance(range.first, range.second) == 1)
        return range.first->second;

    return nullptr;
}

FileChunk::~FileChunk()
{
    for (auto& subchunk : subchunks)
        delete subchunk.second;

    subchunks.clear();
}

void FileChunk::parseSubChunks()
{
    uint8* ptr = data + 8; // skip self
    while (ptr < data + size)
    {
        u_map_fcc header = *(u_map_fcc*)ptr;
        if (IsInterestingChunk(header))
        {
            uint32 subsize = *(uint32*)(ptr + 4);
            if (subsize < size)
            {
                std::swap(header.fcc_txt[0], header.fcc_txt[3]);
                std::swap(header.fcc_txt[1], header.fcc_txt[2]);

                FileChunk* chunk = new FileChunk(ptr, subsize);
                chunk->parseSubChunks();
                subchunks.insert({ std::string(header.fcc_txt, 4), chunk });
            }

            // move to next chunk
            ptr += subsize + 8;
        }
        else
            ++ptr;
    }
}

FileChunk* FileChunk::GetSubChunk(std::string const& name)
{
    auto range = subchunks.equal_range(name);
    if (std::distance(range.first, range.second) == 1)
        return range.first->second;

    return nullptr;
}
