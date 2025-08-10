#include <efsw/efsw.h>

#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#ifdef _WIN32
	#include <Windows.h>
#else
	#include <unistd.h>
#endif

const char PATH_SEPARATOR =
#ifdef _WIN32
	'\\';
#else
	'/';
#endif

bool STOP = false;

void sigend( int sig ) {
	printf( "Bye bye" );
	STOP = true;
}

void sleepMsecs( int msecs ) {
#ifdef _WIN32
	Sleep( msecs );
#else
	sleep( msecs );
#endif	
}

const char * getActionName( enum efsw_action action ) {
	switch ( action ) {
		case EFSW_ADD:
			return "Add";
		case EFSW_MODIFIED:
			return "Modified";
		case EFSW_DELETE:
			return "Delete";
		case EFSW_MOVED:
			return "Moved";
		default:
			return "Bad Action";
	}
}

void handleFileAction( efsw_watcher watcher, efsw_watchid watchid, 
						const char* dir, const char* filename,
						enum efsw_action action, const char* oldFilename,
						void* param ) {
	if ( strlen( oldFilename ) == 0 ) {
		printf( "Watch ID %ld DIR (%s) FILE (%s) has event %s\n", 
			watchid, dir, filename, getActionName( action ));
	} else {
		printf( "Watch ID %ld DIR (%s) FILE (from file %s to %s) has event %s\n",
			watchid, dir, oldFilename, filename, getActionName( action ));
	}
}

efsw_watchid handleWatchID( efsw_watchid watchid ) {
	switch ( watchid ) {
		case EFSW_NOTFOUND:
		case EFSW_REPEATED:
		case EFSW_OUTOFSCOPE:
		case EFSW_REMOTE:
		case EFSW_WATCHER_FAILED:
		case EFSW_UNSPECIFIED: {
			printf( "%s\n", efsw_getlasterror() );
			break;
		}
		default: {
			printf( "Added WatchID: %ld\n", watchid );
		}
	}

	return watchid;
}

int main( int argc, char** argv ) {
	signal( SIGABRT, sigend );
	signal( SIGINT, sigend );
	signal( SIGTERM, sigend );

	printf("Press ^C to exit demo\n");

	bool commonTest = true;
	bool useGeneric = false;
	char *path = 0;

	if ( argc >= 2 ) {
		path = argv[1];

		struct stat s;
		if( stat(path,&s) == 0 && (s.st_mode & S_IFDIR) == S_IFDIR ) {
			commonTest = false;
		}

		if ( argc >= 3 ) {
			if ( strcmp( argv[2], "true" ) == 0 ) {
				useGeneric = true;
			}
		}
	}

	/// create the file watcher object
	efsw_watcher fileWatcher = efsw_create( useGeneric );
	efsw_follow_symlinks( fileWatcher, false );
	efsw_allow_outofscopelinks( fileWatcher, false );

	if ( commonTest ) {
		char cwd[256];
		getcwd( cwd, sizeof(cwd) );
		printf( "CurPath: %s\n", cwd );

		/// starts watching
		efsw_watch( fileWatcher );

		/// add a watch to the system
		char path1[256];
		sprintf(path1, "%s%ctest", cwd, PATH_SEPARATOR );
		handleWatchID( efsw_addwatch_withoptions( fileWatcher, path1, handleFileAction, true, 0, 0, 0 ) );

		/// adds another watch after started watching...
		sleepMsecs( 100 );

		char path2[256];
		sprintf(path2, "%s%ctest2", cwd, PATH_SEPARATOR );
		efsw_watchid watchID = handleWatchID(
			efsw_addwatch_withoptions( fileWatcher, path2, handleFileAction, true, 0, 0, 0 ) );

		/// delete the watch
		if ( watchID > 0 ) {
			sleepMsecs( 1000 );
			efsw_removewatch_byid( fileWatcher, watchID );
		}
	} else {
		if ( efsw_addwatch( fileWatcher, path, handleFileAction, true, 0 ) > 0 ) {
			efsw_watch( fileWatcher );

			printf( "Watching directory: %s\n", path );

			if ( useGeneric ) {
				printf( "Using generic backend watcher\n" );
			}
		} else {
			printf( "Error trying to watch directory: %s\n", path );
			printf( "%s\n", efsw_getlasterror() );
		}
	}

	while ( !STOP ) {
		sleepMsecs( 100 );
	}

	efsw_release( fileWatcher );
	
	return 0;
}
