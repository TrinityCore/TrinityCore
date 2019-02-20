/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include <atomic>
#include <utility>

// C++ implementation of Dmitry Vyukov's lock free MPSC queue
// http://www.1024cores.net/home/lock-free-algorithms/queues/non-intrusive-mpsc-node-based-queue
template<typename T>
class MPSCQueue
{
public:
    MPSCQueue() : _head(new Node()), _tail(_head.load(std::memory_order_relaxed))
    {
        Node* front = _head.load(std::memory_order_relaxed);
        front->Next.store(nullptr, std::memory_order_relaxed);
    }

    ~MPSCQueue()
    {
        T* output;
        while (this->Dequeue(output))
            ;

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
        explicit Node(T* data) : Data(data) { Next.store(nullptr, std::memory_order_relaxed); }

        T* Data;
        std::atomic<Node*> Next;
    };

    std::atomic<Node*> _head;
    std::atomic<Node*> _tail;

    MPSCQueue(MPSCQueue const&) = delete;
    MPSCQueue& operator=(MPSCQueue const&) = delete;
};

#endif // MPSCQueue_h__
