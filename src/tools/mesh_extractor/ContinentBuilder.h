/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#ifndef CONT_BUILDER_H
#define CONT_BUILDER_H

#include <string>
#include "WDT.h"
#include "Define.h"
#include "TileBuilder.h"

#include <ace/Task.h>
#include <ace/Activation_Queue.h>
#include <ace/Method_Request.h>

class ContinentBuilder
{
public:
    ContinentBuilder(std::string continent, uint32 mapId, WDT* wdt, uint32 tn) :
        Continent(continent), TileMap(wdt), MapId(mapId),
        NumberOfThreads(tn), tileXMin(64), tileYMin(64), tileXMax(0), tileYMax(0)
        {}

    void Build();
    void getTileBounds(uint32 tileX, uint32 tileY, float* verts, int vertCount, float* bmin, float* bmax);
    void CalculateTileBounds();
    float bmin[3];
    float bmax[3];
private:
    std::string Continent;
    WDT* TileMap;
    uint32 MapId;
    uint32 NumberOfThreads;
    int tileXMin;
    int tileYMin;
    int tileXMax;
    int tileYMax;
};

class TileBuildRequest : public ACE_Method_Request
{
public:
    TileBuildRequest(ContinentBuilder* builder, std::string& continent, uint32 x, uint32 y, uint32 mapId, dtNavMeshParams& params) : _mapId(mapId), _builder(builder), _continent(continent), X(x), Y(y), _params(params) { }

    virtual int call();

private:
    uint32 _mapId;
    ContinentBuilder* _builder;
    std::string& _continent;
    uint32 X;
    uint32 Y;
    dtNavMeshParams& _params;
};

class BuilderThreadPool
{
public:
    BuilderThreadPool() : _queue(new ACE_Activation_Queue()) {}
    ~BuilderThreadPool() { _queue->queue()->close(); delete _queue; }

    void Enqueue(TileBuildRequest* request)
    {
        _queue->enqueue(request);
    }

    ACE_Activation_Queue* Queue() { return _queue; }

private:
    ACE_Activation_Queue* _queue;
};

class BuilderThread : public ACE_Task_Base
{
private:
    ContinentBuilder* _builder;
    ACE_Activation_Queue* _queue;
public:
    BuilderThread(ContinentBuilder* builder, ACE_Activation_Queue* queue) : _builder(builder), _queue(queue) { activate(); }

    int svc()
    {
        /// @ Set a timeout for dequeue attempts (only used when the queue is empty) as it will never get populated after thread starts
        ACE_Time_Value timeout(5);
        ACE_Method_Request* request = NULL;
        while ((request = _queue->dequeue(&timeout)) != NULL)
        {
            request->call();
            delete request;
            request = NULL;
        }
        return 0;
    }
};

#endif
