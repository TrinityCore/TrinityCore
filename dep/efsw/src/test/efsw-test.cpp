#include <efsw/FileSystem.hpp>
#include <efsw/System.hpp>
#include <efsw/efsw.hpp>
#include <iostream>
#include <signal.h>

bool STOP = false;

void sigend( int ) {
	std::cout << std::endl << "Bye bye" << std::endl;
	STOP = true;
}

/// Processes a file action
class UpdateListener : public efsw::FileWatchListener {
  public:
	UpdateListener() {}

	std::string getActionName( efsw::Action action ) {
		switch ( action ) {
			case efsw::Actions::Add:
				return "Add";
			case efsw::Actions::Modified:
				return "Modified";
			case efsw::Actions::Delete:
				return "Delete";
			case efsw::Actions::Moved:
				return "Moved";
			default:
				return "Bad Action";
		}
	}

	void handleFileAction( efsw::WatchID watchid, const std::string& dir,
						   const std::string& filename, efsw::Action action,
						   std::string oldFilename = "" ) override {
		std::cout << "Watch ID " << watchid << " DIR ("
				  << dir + ") FILE (" +
						 ( oldFilename.empty() ? "" : "from file " + oldFilename + " to " ) +
						 filename + ") has event "
				  << getActionName( action ) << std::endl;
	}
};

efsw::WatchID handleWatchID( efsw::WatchID watchid ) {
	switch ( watchid ) {
		case efsw::Errors::FileNotFound:
		case efsw::Errors::FileRepeated:
		case efsw::Errors::FileOutOfScope:
		case efsw::Errors::FileRemote:
		case efsw::Errors::WatcherFailed:
		case efsw::Errors::Unspecified: {
			std::cout << efsw::Errors::Log::getLastErrorLog().c_str() << std::endl;
			break;
		}
		default: {
			std::cout << "Added WatchID: " << watchid << std::endl;
		}
	}

	return watchid;
}

int main( int argc, char** argv ) {
	signal( SIGABRT, sigend );
	signal( SIGINT, sigend );
	signal( SIGTERM, sigend );

	std::cout << "Press ^C to exit demo" << std::endl;

	bool commonTest = true;
	bool useGeneric = false;
	std::string path;

	if ( argc >= 2 ) {
		path = std::string( argv[1] );

		if ( efsw::FileSystem::isDirectory( path ) ) {
			commonTest = false;
		}

		if ( argc >= 3 ) {
			if ( std::string( argv[2] ) == "true" ) {
				useGeneric = true;
			}
		}
	}

	UpdateListener* ul = new UpdateListener();

	/// create the file watcher object
	efsw::FileWatcher fileWatcher( useGeneric );

	fileWatcher.followSymlinks( false );
	fileWatcher.allowOutOfScopeLinks( false );

	if ( commonTest ) {
		std::string CurPath( efsw::System::getProcessPath() );

		std::cout << "CurPath: " << CurPath.c_str() << std::endl;

			 /// starts watching
		fileWatcher.watch();

		/// add a watch to the system
		handleWatchID( fileWatcher.addWatch( CurPath + "test", ul, true ) );

		/// adds another watch after started watching...
		efsw::System::sleep( 100 );

		efsw::WatchID watchID =
			handleWatchID( fileWatcher.addWatch( CurPath + "test2", ul, true ) );

		/// delete the watch
		if ( watchID > 0 ) {
			efsw::System::sleep( 1000 );
			fileWatcher.removeWatch( watchID );
		}
	} else {
		if ( fileWatcher.addWatch( path, ul, true ) > 0 ) {
			fileWatcher.watch();

			std::cout << "Watching directory: " << path.c_str() << std::endl;

			if ( useGeneric ) {
				std::cout << "Using generic backend watcher" << std::endl;
			}
		} else {
			std::cout << "Error trying to watch directory: " << path.c_str() << std::endl;
			std::cout << efsw::Errors::Log::getLastErrorLog().c_str() << std::endl;
		}
	}

	while ( !STOP ) {
		efsw::System::sleep( 100 );
	}

	return 0;
}
