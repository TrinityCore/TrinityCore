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

#include "mpq_libmpq04.h"
#include <boost/filesystem.hpp>
#include <ios>
#include <deque>
#include <cstdio>
#include <fstream>
#include <algorithm>

ArchiveSet gOpenArchives;

MPQArchive::MPQArchive(char const* filename)
{
    this->filename =  std::string(filename);
    printf("Opening %s\n", filename);
    if(boost::filesystem::is_directory(filename))
    {
        is_directory = true;
        mpq_a = nullptr;
        gOpenArchives.push_front(this);
        return;
    }
    is_directory = false;
    int result = libmpq__archive_open(&mpq_a, filename, -1);
    if(result) {
        switch(result) {
            case LIBMPQ_ERROR_OPEN :
                printf("Error opening archive '%s': Does file really exist?\n", filename);
                break;
            case LIBMPQ_ERROR_FORMAT :            /* bad file format */
                printf("Error opening archive '%s': Bad file format\n", filename);
                break;
            case LIBMPQ_ERROR_SEEK :         /* seeking in file failed */
                printf("Error opening archive '%s': Seeking in file failed\n", filename);
                break;
            case LIBMPQ_ERROR_READ :              /* Read error in archive */
                printf("Error opening archive '%s': Read error in archive\n", filename);
                break;
            case LIBMPQ_ERROR_MALLOC :               /* maybe not enough memory? :) */
                printf("Error opening archive '%s': Maybe not enough memory\n", filename);
                break;
            default:
                printf("Error opening archive '%s': Unknown error\n", filename);
                break;
        }
        return;
    }
    gOpenArchives.push_front(this);
}

void MPQArchive::close()
{
    if(!is_directory)
    {
        libmpq__archive_close(mpq_a);
    }
    //gOpenArchives.erase(erase(&mpq_a);
}

MPQFile::MPQFile(char const* filename):
    eof(false),
    buffer(0),
    pointer(0),
    size(0)
{
    for(ArchiveSet::iterator i=gOpenArchives.begin(); i!=gOpenArchives.end();++i)
    {
        if((*i)->is_directory)
        {
            auto fullpath = (*i)->filename / boost::filesystem::path(filename);
            if(boost::filesystem::exists(fullpath))
            {
                std::ifstream fin;
                fin.open(fullpath.string(),std::ios::binary);
                fin.seekg(0, std::ios::end);
                size = fin.tellg();
                if (size > 0)
                {
                    buffer = new char[size];
                    fin.seekg(0,std::ios::beg);
                    fin.read(buffer,size);
                    eof = false;
                }
                else
                {
                    eof = true;
                    buffer = 0;
                    continue;
                }
                fin.close();
                return;
            }
            continue;
        }

        mpq_archive *mpq_a = (*i)->mpq_a;

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
    buffer = 0;
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
    eof = true;
    delete[] buffer;
    buffer = 0;
}

inline bool ends_with(std::string const& value, std::string const& ending)
{
  if (ending.size() > value.size()) return false;
  return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

void CheckMPQ(std::string path, bool use_directories, std::vector<std::string> & files)
{
  if (ends_with(path, ".MPQ") || ends_with(path, ".mpq"))
  {
    if (use_directories || !boost::filesystem::is_directory(path))
    {
      files.push_back(path);
    }
  }
}

// @tswow-begin
static std::vector<std::string> langs({
      "enGB", "enUS", "deDE", "esES", "frFR", "koKR"
    , "zhCN", "zhTW", "enCN", "enTW", "esMX", "ruRU"
  });

int BaseFileScore(std::string const& file)
{
  if (file.find("base") != std::string::npos) return 1;
  if (file.find("backup") != std::string::npos) return 2;
  if (file.find("expansion-locale") != std::string::npos) return 3;
  if (file.find("patch-") != std::string::npos) return 4;
  if (file.find("lichking-locale") != std::string::npos) return 9;
  if (file.find("locale-") != std::string::npos) return 5;
  if (file.find("expansion-speech") != std::string::npos) return 8;
  if (file.find("expansion") != std::string::npos) return 7;
  if (file.find("speech-") != std::string::npos) return 6;
  if (file.find("common.") != std::string::npos) return 10;
  if (file.find("lichking") != std::string::npos) return 11;
  if (file.find("patch.") != std::string::npos) return 12;
  if (file.find("common-2") != std::string::npos) return 13;
  return 0;
}

int LocaleIndex(std::string const& file)
{
  for (int i = 0; i < int(langs.size()); ++i)
  {
    if (file.find(langs[i]) != std::string::npos)
    {
      return i;
    }
  }
  return -1;
}

bool IsLocale(std::string const& file)
{
  return LocaleIndex(file) >= 0;
}

bool IsPatch(std::string const& file)
{
  return file.find("patch") != std::string::npos;
}

char PatchID(std::string const& file)
{
  // the "base" patch files are not read in order like normal patches.
  int locale_index = LocaleIndex(file);
  if (locale_index >= 0)
  {
    if (file.find("patch-" + langs[locale_index] + ".") != std::string::npos) return '1';
  }
  if (file.find("patch.") != std::string::npos) return '1';
  return toupper(file.substr(file.size() - 5, 1).c_str()[0]);
}

void ReadMPQFiles(std::string dataPath, bool use_directories)
{
  boost::filesystem::directory_iterator end;
  std::vector<std::string> files;
  for (boost::filesystem::directory_iterator itr(boost::filesystem::path(dataPath.c_str())); itr != end; ++itr)
  {
    CheckMPQ(itr->path().string(), use_directories, files);

    for (auto & lang : langs)
    {
      if (ends_with(itr->path().string(), lang) && boost::filesystem::is_directory(itr->path()))
      {
        for (boost::filesystem::directory_iterator localeItr(itr->path()); localeItr != end; ++localeItr)
        {
          CheckMPQ(localeItr->path().string(), use_directories, files);
        }
        break;
      }
    }
  }

  std::sort(files.begin(), files.end(), [](auto a, auto b) {
    if (IsPatch(a) && IsPatch(b))
    {
      if (PatchID(a) == PatchID(b))
      {
        if (IsLocale(a)) return true;
        else return false;
      }

      return PatchID(a) < PatchID(b);
    }

    if (IsPatch(a)) return false;
    if (IsPatch(b)) return true;

    return BaseFileScore(a) < BaseFileScore(b);
  });

  for (auto& file : files)
  {
      new MPQArchive(file.c_str());
  }
}
// @tswow-end
