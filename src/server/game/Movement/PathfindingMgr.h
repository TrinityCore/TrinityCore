
#ifndef _PATHFINDINGMGR_H_
#define _PATHFINDINGMGR_H_

#include "Pathfinding.h"
#include "Map.h"
#include "MMapFactory.h"
#include "MMapManager.h"
#include <mutex>
#include <thread>
//#include <boost/thread/thread.hpp>

class PathfindingMgr;
typedef std::queue<PathParameter*> PFParameterQueue;

class PFThread
{
public:
    PFThread(PathfindingMgr* pfMgr, uint32 threadIndex);
    ~PFThread();

    void StartThread();
    void ThreadRun();
    void DestroyThread();

    void AddPathParameter(PathParameter* pfParameter);
    bool ExecturePathfinding(bool force);

    bool IsIDLE() { return m_IsIDLE && !m_pfParameter; }

private:
    PathfindingMgr* m_pfMgr;
    MMAP::MMapManager* m_pMMap;
    dtNavMesh const* _navMesh;              // the nav mesh
    dtNavMeshQuery const* _navMeshQuery;    // the nav mesh query used to find the path
    uint32 m_ThreadIndex;
    bool m_IsIDLE;
    bool m_IsRun;
    std::thread* _thread;
    std::chrono::milliseconds timespan;

    PathParameter* m_pfParameter;
};

class PathfindingMgr
{
    typedef std::vector<PFThread*> PFThreads;

private:
    PathfindingMgr();
    ~PathfindingMgr();

public:
    PathfindingMgr(PathfindingMgr const&) = delete;
    PathfindingMgr(PathfindingMgr&&) = delete;

    PathfindingMgr& operator= (PathfindingMgr const&) = delete;
    PathfindingMgr& operator= (PathfindingMgr&&) = delete;

    static PathfindingMgr* instance();

    void OutputPathfindingError();
    void InitializePFMgr();
    void ClearPFThreads();
    void AddPFParameter(PathParameter* pfParameter);
    void AddFinishPFParameter(PathParameter* pfParameter);
    void Update();

private:
    int GetCPUNumber() const;
    void ProcessFinishPFParameter(PathParameter* pfParameter);

private:
    PFThreads m_pfThreads;
    PFParameterQueue m_WaitPFQueue;
    PFParameterQueue m_FinishPFQueue;

    std::mutex m_fpQueueLock;
    std::mutex m_addfpQueueLock;

    uint32 pathErrorCount;
};

#define sFPMgr PathfindingMgr::instance()

#endif // _PATHFINDINGMGR_H_
