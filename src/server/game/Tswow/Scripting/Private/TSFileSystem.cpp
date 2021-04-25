#include "TSFileSystem.h"

#include <boost/filesystem.hpp>
#include <string>

namespace fs = boost::filesystem;

TSString ReadFile(TSString file, TSString def)
{
    if(!fs::exists(file.std_str()))
    {
        return def;
    }

    std::ifstream t(file.std_str());
    std::string str((std::istreambuf_iterator<char>(t)),
        std::istreambuf_iterator<char>());
    return str;
}

void mkdirs(std::string const& pathstr)
{
    auto path = fs::path(pathstr);
    auto parent_path = path.parent_path();
    if (parent_path.string().size() > 0)
    {
        fs::create_directories(path.parent_path());
    }
}

bool FileExists(TSString file)
{
    return fs::exists(file.std_str());
}

void WriteFile(TSString file, TSString value)
{
    mkdirs(file.std_str());
    std::ofstream(file.std_str()) << value.std_str();
}

void AppendFile(TSString file, TSString value)
{
    mkdirs(file.std_str());
    std::ofstream outfile;
    outfile.open(file.std_str(), std::ios_base::app); // append instead of overwrite
    outfile << value.std_str();
}

TSArray<TSString> ReadDirectory(TSString directory)
{
    TSArray<TSString> arr;

    if(directory.get_length() == 0)
    {
        directory = JSTR("./");
    }

    if(!fs::exists(directory.std_str()))
    {
        return arr;
    }

    boost::filesystem::recursive_directory_iterator end;
    for (boost::filesystem::recursive_directory_iterator dir(directory.std_str()); dir != end; ++dir)
    {
        if(boost::filesystem::is_regular_file(dir->path()))
        {
            arr.push(TSString(dir->path().string()));
        }
    }
    return arr;
}