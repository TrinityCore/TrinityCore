/*
 *
 */

#ifndef MANGOS_FEARMOVEMENTGENERATOR_H
#define MANGOS_FEARMOVEMENTGENERATOR_H

#include "MovementGenerator.h"
#include "ObjectGuid.h"

#define DEFAULT_INIT_FLEE_TIME      2000
#define DEFAULT_INIT_FLEE_DIST      28.0f
#define INIT_FLEE_TIME_RAND_MULT    0.25f
#define PATH_LENGTH_LIMIT           45.0f
#define MAX_DIST_BYPASS_INIT        28.0f
#define POST_INIT_RADIUS            20.0f
#define REACHABLE_RADIUS            5.0f
#define INIT_FLEE_ANGLE_MULT        0.95f
#define NEXT_CHECK_TIME_LOWER_BOUND 200
#define NEXT_CHECK_TIME_UPPER_BOUND 500

template<class T>
class FearMovementGenerator : public MovementGeneratorMedium< T, FearMovementGenerator<T> >
{
public:
    explicit FearMovementGenerator(ObjectGuid fright) : 
        i_initialFleeTime(DEFAULT_INIT_FLEE_TIME), _timeInitDone(false), _pointInitDone(false), _forceWalking(false),
        _customSpeed(-1.0f), i_frightGuid(fright), i_nextCheckTime(0), _forceUpdate(false)
    {
        
    }

    void Initialize(T &);
    void Finalize(T &);
    void Interrupt(T &);
    void Reset(T &);
    bool Update(T &, uint32 const&);

    void UnitSpeedChanged() override { _forceUpdate = true; }
    MovementGeneratorType GetMovementGeneratorType() const { return FLEEING_MOTION_TYPE; }

    ShortTimeTracker i_initialFleeTime;
    bool _timeInitDone;
    bool _pointInitDone;

protected:
    bool _forceWalking;
    float _customSpeed;   

private:
    void _setTargetLocation(T &owner);
    bool _getPoint(T &owner, float &x, float &y, float &z);

    ObjectGuid i_frightGuid;
    TimeTracker i_nextCheckTime;    
    bool _forceUpdate;
};

class TimedFearMovementGenerator : public FearMovementGenerator<Creature>
{
public:
    TimedFearMovementGenerator(ObjectGuid fright, uint32 time);
   
    bool Update(Unit &, uint32 const&);
    void Initialize(Unit &);
    void Finalize(Unit &);

    MovementGeneratorType GetMovementGeneratorType() const { return TIMED_FLEEING_MOTION_TYPE; }

private:
    TimeTracker i_totalFleeTime;
};

#endif
