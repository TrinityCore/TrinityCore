#ifndef EFSW_MUTEX_HPP
#define EFSW_MUTEX_HPP

#include <efsw/base.hpp>

namespace efsw {

namespace Platform {
class MutexImpl;
}

/** Simple mutex class */
class Mutex {
  public:
	Mutex();

	~Mutex();

	/** Lock the mutex */
	void lock();

	/** Unlock the mutex */
	void unlock();

  private:
	Platform::MutexImpl* mMutexImpl;
};

} // namespace efsw

#endif
