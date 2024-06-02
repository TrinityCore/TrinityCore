#include <efsw/efsw.h>
#include <efsw/efsw.hpp>
#include <vector>

#define TOBOOL( i ) ( ( i ) == 0 ? false : true )

/*************************************************************************************************/
class Watcher_CAPI : public efsw::FileWatchListener {
  public:
	efsw_watcher mWatcher;
	efsw_pfn_fileaction_callback mFn;
	void* mParam;

  public:
	Watcher_CAPI( efsw_watcher watcher, efsw_pfn_fileaction_callback fn, void* param ) :
		mWatcher( watcher ), mFn( fn ), mParam( param ) {}

	void handleFileAction( efsw::WatchID watchid, const std::string& dir,
						   const std::string& filename, efsw::Action action,
						   std::string oldFilename = "" ) {
		mFn( mWatcher, watchid, dir.c_str(), filename.c_str(), (enum efsw_action)action,
			 oldFilename.c_str(), mParam );
	}
};

/*************************************************************************************************
 * globals
 */
static std::vector<Watcher_CAPI*> g_callbacks;

Watcher_CAPI* find_callback( efsw_watcher watcher, efsw_pfn_fileaction_callback fn ) {
	for ( std::vector<Watcher_CAPI*>::iterator i = g_callbacks.begin(); i != g_callbacks.end();
		  ++i ) {
		Watcher_CAPI* callback = *i;

		if ( callback->mFn == fn && callback->mWatcher == watcher )
			return *i;
	}

	return NULL;
}

Watcher_CAPI* remove_callback( efsw_watcher watcher ) {
	std::vector<Watcher_CAPI*>::iterator i = g_callbacks.begin();

	while ( i != g_callbacks.end() ) {
		Watcher_CAPI* callback = *i;

		if ( callback->mWatcher == watcher )
			i = g_callbacks.erase( i );
		else
			++i;
	}

	return NULL;
}

/*************************************************************************************************/
efsw_watcher efsw_create( int generic_mode ) {
	return ( efsw_watcher ) new efsw::FileWatcher( TOBOOL( generic_mode ) );
}

void efsw_release( efsw_watcher watcher ) {
	remove_callback( watcher );
	delete (efsw::FileWatcher*)watcher;
}

const char* efsw_getlasterror() {
	static std::string log_str;
	log_str = efsw::Errors::Log::getLastErrorLog();
	return log_str.c_str();
}

EFSW_API void efsw_clearlasterror() {
	efsw::Errors::Log::clearLastError();
}

efsw_watchid efsw_addwatch( efsw_watcher watcher, const char* directory,
							efsw_pfn_fileaction_callback callback_fn, int recursive, void* param ) {
	return efsw_addwatch_withoptions( watcher, directory, callback_fn, recursive, 0, 0, param );
}

efsw_watchid  efsw_addwatch_withoptions(efsw_watcher watcher, const char* directory,
										efsw_pfn_fileaction_callback callback_fn, int recursive,
										efsw_watcher_option *options, int options_number,
										void* param) {
	Watcher_CAPI* callback = find_callback( watcher, callback_fn );

	if ( callback == NULL ) {
		callback = new Watcher_CAPI( watcher, callback_fn, param );
		g_callbacks.push_back( callback );
	}

	std::vector<efsw::WatcherOption> watcher_options{};
	for ( int i = 0; i < options_number; i++ ) {
		efsw_watcher_option* option = &options[i];
		watcher_options.emplace_back( efsw::WatcherOption{
			static_cast<efsw::Option>(option->option), option->value } );
	}

	return ( (efsw::FileWatcher*)watcher )
		->addWatch( std::string( directory ), callback, TOBOOL( recursive ), watcher_options );
}

void efsw_removewatch( efsw_watcher watcher, const char* directory ) {
	( (efsw::FileWatcher*)watcher )->removeWatch( std::string( directory ) );
}

void efsw_removewatch_byid( efsw_watcher watcher, efsw_watchid watchid ) {
	( (efsw::FileWatcher*)watcher )->removeWatch( watchid );
}

void efsw_watch( efsw_watcher watcher ) {
	( (efsw::FileWatcher*)watcher )->watch();
}

void efsw_follow_symlinks( efsw_watcher watcher, int enable ) {
	( (efsw::FileWatcher*)watcher )->followSymlinks( TOBOOL( enable ) );
}

int efsw_follow_symlinks_isenabled( efsw_watcher watcher ) {
	return (int)( (efsw::FileWatcher*)watcher )->followSymlinks();
}

void efsw_allow_outofscopelinks( efsw_watcher watcher, int allow ) {
	( (efsw::FileWatcher*)watcher )->allowOutOfScopeLinks( TOBOOL( allow ) );
}

int efsw_outofscopelinks_isallowed( efsw_watcher watcher ) {
	return (int)( (efsw::FileWatcher*)watcher )->allowOutOfScopeLinks();
}
