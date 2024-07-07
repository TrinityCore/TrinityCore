#ifndef EFSW_LOCK_HPP
#define EFSW_LOCK_HPP

#include <efsw/Mutex.hpp>

namespace efsw {

/** Simple mutex class */
class Lock {
  public:
	explicit Lock( Mutex& mutex ) : mMutex( mutex ) { mMutex.lock(); }

	~Lock() { mMutex.unlock(); }

  private:
	Mutex& mMutex;
};

} // namespace efsw

#endif
