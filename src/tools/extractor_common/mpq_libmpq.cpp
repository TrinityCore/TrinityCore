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

#include "mpq_libmpq.h"
#include "StringFormat.h"
#include "Util.h"
#include <boost/filesystem/directory.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <algorithm>
#include <array>
#include <stdexcept>
#include <cstdio>

ArchiveSet gOpenArchives;

MPQArchive::MPQArchive(char const* filename)
{
    int result = libmpq__archive_open(&mpq_a, filename, -1);
    printf("Opening %s\n", filename);
    switch(result)
    {
        case LIBMPQ_ERROR_OPEN:
            throw std::runtime_error(Trinity::StringFormat("Error opening archive '{}': Does file really exist?", filename));
        case LIBMPQ_ERROR_FORMAT:
            throw std::runtime_error(Trinity::StringFormat("Error opening archive '{}': Bad file format", filename));
        case LIBMPQ_ERROR_SEEK:
            throw std::runtime_error(Trinity::StringFormat("Error opening archive '{}': Seeking in file failed", filename));
        case LIBMPQ_ERROR_READ:
            throw std::runtime_error(Trinity::StringFormat("Error opening archive '{}': Read error in archive", filename));
        case LIBMPQ_ERROR_MALLOC:
            throw std::runtime_error(Trinity::StringFormat("Error opening archive '{}': Maybe not enough memory", filename));
        default:
            throw std::runtime_error(Trinity::StringFormat("Error opening archive '{}': Unknown error", filename));
        case 0:
            // success
            break;
    }
}

void MPQArchive::close()
{
    if (mpq_a)
    {
        libmpq__archive_close(mpq_a);
        mpq_a = nullptr;
    }
}

MPQFile::MPQFile(char const* filename):
    eof(false),
    buffer(nullptr),
    pointer(0),
    size(0)
{
    for (ArchiveSet::iterator i = gOpenArchives.begin(); i != gOpenArchives.end(); ++i)
    {
        mpq_archive *mpq_a = i->mpq_a;
        if (!mpq_a)
            continue;

        uint32_t filenum;
        if(libmpq__file_number(mpq_a, filename, &filenum)) continue;
        libmpq__off_t transferred;
        libmpq__file_size_unpacked(mpq_a, filenum, &size);

        // HACK: in patch.mpq some files don't want to open and give 1 for filesize
        if (size<=1) {
//            printf("warning: file %s has size %d; cannot read.\n", filename, size);
            eof = true;
            buffer = 0;
            return;
        }
        buffer = new char[size];

        //libmpq_file_getdata
        libmpq__file_read(mpq_a, filenum, (unsigned char*)buffer, size, &transferred);
        /*libmpq_file_getdata(&mpq_a, hash, fileno, (unsigned char*)buffer);*/
        return;

    }
    eof = true;
    buffer = nullptr;
}

size_t MPQFile::read(void* dest, size_t bytes)
{
    if (eof) return 0;

    size_t rpos = pointer + bytes;
    if (rpos > size_t(size)) {
        bytes = size - pointer;
        eof = true;
    }

    memcpy(dest, &(buffer[pointer]), bytes);

    pointer = rpos;

    return bytes;
}

void MPQFile::seek(int offset)
{
    pointer = offset;
    eof = (pointer >= size);
}

void MPQFile::seekRelative(int offset)
{
    pointer += offset;
    eof = (pointer >= size);
}

void MPQFile::close()
{
    delete[] buffer;
    buffer = nullptr;
    eof = true;
}

namespace MPQ
{
struct ArchiveData
{
    std::string_view NamePattern;
    bool Required;
};

constexpr std::array<ArchiveData, 11> Archives =
{{
    { .NamePattern = "{installDir}/Data/patch-?.MPQ", .Required = true },
    { .NamePattern = "{installDir}/Data/{locale}/patch-{locale}-?.MPQ", .Required = true },
    { .NamePattern = "{installDir}/Data/patch.MPQ", .Required = true },
    { .NamePattern = "{installDir}/Data/{locale}/patch-{locale}.MPQ", .Required = true },
    { .NamePattern = "{installDir}/Data/expansion.MPQ", .Required = true },
    { .NamePattern = "{installDir}/Data/lichking.MPQ", .Required = true },
    { .NamePattern = "{installDir}/Data/common.MPQ", .Required = true },
    { .NamePattern = "{installDir}/Data/common-2.MPQ", .Required = true },
    { .NamePattern = "{installDir}/Data/{locale}/locale-{locale}.MPQ", .Required = true },
    //{ .NamePattern = "{installDir}/Data/{locale}/speech-{locale}.MPQ", .Required = false },
    { .NamePattern = "{installDir}/Data/{locale}/expansion-locale-{locale}.MPQ", .Required = true },
    { .NamePattern = "{installDir}/Data/{locale}/lichking-locale-{locale}.MPQ", .Required = true },
    //{ .NamePattern = "{installDir}/Data/{locale}/expansion-speech-{locale}.MPQ", .Required = false },
    //{ .NamePattern = "{installDir}/Data/{locale}/lichking-speech-{locale}.MPQ", .Required = false },
}};

bool FileNameMatchesArchivePattern(std::string_view const& fileName, std::string_view const& pattern)
{
    return std::ranges::equal(fileName, pattern, [](char fileChar, char patternChar)
    {
        return patternChar == '?' || charToLower(fileChar) == charToLower(patternChar);
    });
}

std::vector<boost::filesystem::path> ResolveArchiveFileList(std::string_view inputPath, std::string_view localeName, std::string_view namePattern)
{
    boost::filesystem::path path = Trinity::StringFormat(fmt::runtime(namePattern), fmt::arg("installDir", inputPath), fmt::arg("locale", localeName));
    std::vector<boost::filesystem::path> absolutePaths;

    std::string fileNamePattern = path.filename().string();
    if (fileNamePattern.find('?') != std::string::npos)
    {
        // scan directory
        boost::system::error_code ec;
        for (boost::filesystem::directory_entry const& dirEntry : boost::filesystem::directory_iterator(path.parent_path(), ec))
        {
            if (!FileNameMatchesArchivePattern(dirEntry.path().filename().string(), fileNamePattern))
                continue;

            absolutePaths.push_back(dirEntry.path().lexically_normal().make_preferred());
        }

        std::ranges::sort(absolutePaths, [](boost::filesystem::path const& left, boost::filesystem::path const& right)
        {
            return std::ranges::lexicographical_compare(left.string(), right.string(), std::ranges::greater(), charToLower, charToLower);
        });
    }
    else
        absolutePaths.push_back(path.lexically_normal().make_preferred());

    return absolutePaths;
}

bool OpenArchive(std::string_view inputPath, std::string_view localeName, ArchiveData const& archive)
{
    std::vector<boost::filesystem::path> fileNames = ResolveArchiveFileList(inputPath, localeName, archive.NamePattern);
    for (boost::filesystem::path const& fileName : fileNames)
    {
        if (!exists(fileName))
        {
            if (archive.Required)
                return false;

            continue;
        }

        try
        {
            gOpenArchives.emplace_back(fileName.string().c_str());
        }
        catch (std::exception const& e)
        {
            printf("%s\n", e.what());
            if (archive.Required)
                return false;
        }
    }

    return true;
}

bool OpenArchives(std::string_view inputPath, std::string_view localeName)
{
    for (ArchiveData const& archive : Archives)
        if (!OpenArchive(inputPath, localeName, archive))
            if (archive.Required)
                return false;

    return true;
}

void CloseArchives()
{
    gOpenArchives.clear();
}
}
