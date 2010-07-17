/**
 @file Stopwatch.h
 
 @maintainer Morgan McGuire, matrix@graphics3d.com
  
 @created 2005-10-05
 @edited  2005-10-05

 Copyright 2000-2003, Morgan McGuire.
 All rights reserved.
 */

#ifndef G3D_STOPWATCH_H
#define G3D_STOPWATCH_H

#include "G3D/platform.h"
#include "G3D/Queue.h"
#include "G3D/G3DGameUnits.h"
#include "G3D/g3dmath.h"

namespace G3D {

/**
 Utility class for profiling duration and frame rates.
 */
class Stopwatch {
private:
    /** True between tick and tock */
    bool                    inBetween;

    /** The initial cycle count. */
    uint64                  cycleStart;

    /** The time at which tick was called. */
    RealTime                timeStart;

    /** The time at which the previous tock was called, -1 if never. */
    RealTime                lastTockTime;

    RealTime                lastDuration;
    int64                   lastCycleCount;

    /** Frames per second. */
    double                  m_fps;

    /** Weighted fps */
    double                  emwaFPS;
    double                  m_smoothFPS;

    /** Weighted duration */
    RealTime                emwaDuration;

    /** The overhead for calling into the class. */
    int64                   cycleOverhead;
   
    /** Called from the constructor. */
    void computeOverhead();

public:

    Stopwatch();

    /** Returns the number of times that tick was called per wall-clock second; 
        e.g. frames-per-second. */
    double FPS() const {
        return m_fps;
    }

    /** Amount of time between the most recent tick and tock calls.  0 if tick has
        never been called. */
    RealTime elapsedTime() const {
        return lastDuration;
    }

    /** Time-smoothed value that is stable to the nearest 1%.
        This is useful if you are displaying elapsed time in real-time 
        and want a stable number.*/
    RealTime smoothElapsedTime() const {
        return emwaDuration;
    }

    /** Time-smoothed value of fps that is stable to the nearest integer for fps > 10 and 
      to the first decimal place for fps <= 10.
      This is useful if you
      are displaying the frame rate in real-time and want a stable (readable) number.*/
    double smoothFPS() const {
        return m_smoothFPS;
    }

    /** The elapsed cycle time between tick and tock.  An attempt is made to factor out all
        tick/tock overhead, so that back-to-back calls should return zero.  
        Unreliable on non-x86 platforms.*/
    uint64 elapsedCycles() const {
        return lastCycleCount;
    }

    /** Call at the beginning of the period that you want timed. */
    void tick();

    /** Call at the end of the period that you want timed. */
    void tock();
};


}

#endif

