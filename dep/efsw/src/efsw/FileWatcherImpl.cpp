#include <efsw/FileWatcherImpl.hpp>
#include <efsw/String.hpp>
#include <efsw/System.hpp>

namespace efsw {

FileWatcherImpl::FileWatcherImpl( FileWatcher * parent ) :
	mFileWatcher( parent ),
	mInitOK( false ),
	mIsGeneric( false )
{
	System::maxFD();
}

FileWatcherImpl::~FileWatcherImpl()
{
}

bool FileWatcherImpl::initOK()
{
	return mInitOK;
}

bool FileWatcherImpl::linkAllowed( const std::string& curPath, const std::string& link )
{
	return ( mFileWatcher->followSymlinks() && mFileWatcher->allowOutOfScopeLinks() ) || -1 != String::strStartsWith( curPath, link );
}

}
