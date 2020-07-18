#ifndef EFSW_THREAD_HPP
#define EFSW_THREAD_HPP

#include <efsw/base.hpp>

namespace efsw {

namespace Platform { class ThreadImpl; }
namespace Private { struct ThreadFunc; }

/** @brief Thread manager class */
class Thread {
	public:
		typedef void (*FuncType)(void*);

		template <typename F>
		Thread( F function );

		template <typename F, typename A>
		Thread( F function, A argument );

		template <typename C>
		Thread( void(C::*function)(), C* object );

		virtual ~Thread();

		/** Launch the thread */
		virtual void	launch();

		/** Wait the thread until end */
		void			wait();

		/** Terminate the thread */
		void			terminate();
	protected:
		Thread();
	private:
		friend class Platform::ThreadImpl;

		/** The virtual function to run in the thread */
		virtual void	run();

		Platform::ThreadImpl *		mThreadImpl;       ///< OS-specific implementation of the thread
		Private::ThreadFunc *		mEntryPoint; ///< Abstraction of the function to run
};

//! NOTE: Taken from SFML2 threads
namespace Private {

// Base class for abstract thread functions
struct ThreadFunc
{
	virtual ~ThreadFunc() {}
	virtual void run() = 0;
};

// Specialization using a functor (including free functions) with no argument
template <typename T>
struct ThreadFunctor : ThreadFunc
{
	ThreadFunctor(T functor) : m_functor(functor) {}
	virtual void run() {m_functor();}
	T m_functor;
};

// Specialization using a functor (including free functions) with one argument
template <typename F, typename A>
struct ThreadFunctorWithArg : ThreadFunc
{
	ThreadFunctorWithArg(F function, A arg) : m_function(function), m_arg(arg) {}
	virtual void run() {m_function(m_arg);}
	F m_function;
	A m_arg;
};

// Specialization using a member function
template <typename C>
struct ThreadMemberFunc : ThreadFunc
{
	ThreadMemberFunc(void(C::*function)(), C* object) : m_function(function), m_object(object) {}
	virtual void run() {(m_object->*m_function)();}
	void(C::*m_function)();
	C* m_object;
};

}

template <typename F>
Thread::Thread(F functor) :
	mThreadImpl      (NULL),
	mEntryPoint( new Private::ThreadFunctor<F>(functor) )
{
}

template <typename F, typename A>
Thread::Thread(F function, A argument) :
	mThreadImpl(NULL),
	mEntryPoint( new Private::ThreadFunctorWithArg<F efCOMMA A>(function, argument) )
{
}

template <typename C>
Thread::Thread(void(C::*function)(), C* object) :
	mThreadImpl(NULL),
	mEntryPoint( new Private::ThreadMemberFunc<C>(function, object) )
{
}

}

#endif
