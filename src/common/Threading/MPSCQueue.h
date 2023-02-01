/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MPSCQueue_h__
#define MPSCQueue_h__

#include <array>
#include <atomic>
#include <new>

namespace Trinity
{
namespace Impl
{
// C++ implementation of Dmitry Vyukov's lock free MPSC queue
// http://www.1024cores.net/home/lock-free-algorithms/queues/non-intrusive-mpsc-node-based-queue
template<typename T>
class MPSCQueueNonIntrusive
{
public:
    MPSCQueueNonIntrusive() : _head(new Node()), _tail(_head.load(std::memory_order_relaxed))
    {
        Node* front = _head.load(std::memory_order_relaxed);
        front->Next.store(nullptr, std::memory_order_relaxed);
    }

    ~MPSCQueueNonIntrusive()
    {
        T* output;
        while (Dequeue(output))
            delete output;

        Node* front = _head.load(std::memory_order_relaxed);
        delete front;
    }

    void Enqueue(T* input)
    {
        Node* node = new Node(input);
        Node* prevHead = _head.exchange(node, std::memory_order_acq_rel);
        prevHead->Next.store(node, std::memory_order_release);
    }

    bool Dequeue(T*& result)
    {
        Node* tail = _tail.load(std::memory_order_relaxed);
        Node* next = tail->Next.load(std::memory_order_acquire);
        if (!next)
            return false;

        result = next->Data;
        _tail.store(next, std::memory_order_release);
        delete tail;
        return true;
    }

private:
    struct Node
    {
        Node() = default;
        explicit Node(T* data) : Data(data)
        {
            Next.store(nullptr, std::memory_order_relaxed);
        }

        T* Data;
        std::atomic<Node*> Next;
    };

    std::atomic<Node*> _head;
    std::atomic<Node*> _tail;

    MPSCQueueNonIntrusive(MPSCQueueNonIntrusive const&) = delete;
    MPSCQueueNonIntrusive& operator=(MPSCQueueNonIntrusive const&) = delete;
};

// C++ implementation of Dmitry Vyukov's lock free MPSC queue
// http://www.1024cores.net/home/lock-free-algorithms/queues/intrusive-mpsc-node-based-queue
template<typename T, std::atomic<T*> T::* IntrusiveLink>
class MPSCQueueIntrusive
{
    using Atomic = std::atomic<T*>;

public:
    MPSCQueueIntrusive() : _dummy(), _dummyPtr(reinterpret_cast<T*>(_dummy.data())), _head(_dummyPtr), _tail(_dummyPtr)
    {
        // _dummy is constructed from raw byte array and is intentionally left uninitialized (it might not be default constructible)
        // so we init only its IntrusiveLink here
        Atomic* dummyNext = new (&(_dummyPtr->*IntrusiveLink)) Atomic();
        dummyNext->store(nullptr, std::memory_order_relaxed);
    }

    ~MPSCQueueIntrusive()
    {
        T* output;
        while (Dequeue(output))
            delete output;

        // destruct our dummy atomic
        (_dummyPtr->*IntrusiveLink).~Atomic();
    }

    void Enqueue(T* input)
    {
        (input->*IntrusiveLink).store(nullptr, std::memory_order_release);
        T* prevHead = _head.exchange(input, std::memory_order_acq_rel);
        (prevHead->*IntrusiveLink).store(input, std::memory_order_release);
    }

    bool Dequeue(T*& result)
    {
        T* tail = _tail.load(std::memory_order_relaxed);
        T* next = (tail->*IntrusiveLink).load(std::memory_order_acquire);
        if (tail == _dummyPtr)
        {
            if (!next)
                return false;

            _tail.store(next, std::memory_order_release);
            tail = next;
            next = (next->*IntrusiveLink).load(std::memory_order_acquire);
        }

        if (next)
        {
            _tail.store(next, std::memory_order_release);
            result = tail;
            return true;
        }

        T* head = _head.load(std::memory_order_acquire);
        if (tail != head)
            return false;

        Enqueue(_dummyPtr);
        next = (tail->*IntrusiveLink).load(std::memory_order_acquire);
        if (next)
        {
            _tail.store(next, std::memory_order_release);
            result = tail;
            return true;
        }
        return false;
    }

private:
    alignas(T) std::array<std::byte, sizeof(T)> _dummy;
    T* _dummyPtr;
    Atomic _head;
    Atomic _tail;

    MPSCQueueIntrusive(MPSCQueueIntrusive const&) = delete;
    MPSCQueueIntrusive& operator=(MPSCQueueIntrusive const&) = delete;
};
}
}

template<typename T, std::atomic<T*> T::* IntrusiveLink = nullptr>
using MPSCQueue = std::conditional_t<IntrusiveLink != nullptr, Trinity::Impl::MPSCQueueIntrusive<T, IntrusiveLink>, Trinity::Impl::MPSCQueueNonIntrusive<T>>;

#endif // MPSCQueue_h__
