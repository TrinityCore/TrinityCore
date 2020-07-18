#include <efsw/efsw.hpp>

namespace efsw { namespace Errors {

static std::string LastError;

std::string Log::getLastErrorLog()
{
	return LastError;
}

Error Log::createLastError( Error err, std::string log )
{
	switch ( err )
	{
		case FileNotFound:		LastError = "File not found ( " + log + " )";					break;
		case FileRepeated:		LastError = "File reapeated in watches ( " + log + " )";		break;
		case FileOutOfScope:	LastError = "Symlink file out of scope ( " + log + " )";		break;
		case FileRemote:		LastError = "File is located in a remote file system, use a generic watcher. ( " + log + " )"; break;
		case Unspecified:
		default:				LastError = log;
	}

	return err;
}

}}
