#ifndef EFSW_FILEINFO_HPP
#define EFSW_FILEINFO_HPP

#include <efsw/base.hpp>
#include <string>
#include <map>
#include <list>

namespace efsw {

class FileInfo
{
	public:
		static bool exists( const std::string& filePath );

		static bool isLink( const std::string& filePath );

		static bool inodeSupported();

		FileInfo();

		FileInfo( const std::string& filepath );

		FileInfo( const std::string& filepath, bool linkInfo );

		bool operator==( const FileInfo& Other ) const;

		bool operator!=( const FileInfo& Other ) const;

		FileInfo& operator=( const FileInfo& Other );

		bool isDirectory();

		bool isRegularFile();

		bool isReadable();

		bool sameInode( const FileInfo& Other ) const;

		bool isLink();

		std::string linksTo();

		bool exists();

		void getInfo();

		void getRealInfo();

		std::string		Filepath;
		Uint64			ModificationTime;
		Uint64			Size;
		Uint32			OwnerId;
		Uint32			GroupId;
		Uint32			Permissions;
		Uint64			Inode;
};

typedef std::map<std::string, FileInfo>					FileInfoMap;
typedef std::list<FileInfo>								FileInfoList;
typedef std::list< std::pair< std::string, FileInfo> >	MovedList;

}

#endif

