/**
 @file Stopwatch.h
 
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
  
 @created 2005-10-05
 @edited  2009-05-10

 Copyright 2000-2009, Morgan McGuire.
 All rights reserved.
 */

#ifndef G3D_Stopwatch_h
#define G3D_Stopwatch_h

#include "G3D/platform.h"
#include "G3D/Queue.h"
#include "G3D/G3DGameUnits.h"
#include "G3D/g3dmath.h"

namespace G3D {

/**
  \brief Accurately measure durations and framerates.

  Example 1: For profiling code in the context of a rendering loop:
    <pre>
      sw.tick();
      ...timed code...
      sw.tock();

      screenPrintf("%f\n", sw.smoothFPS());
    </pre>


  Example 2: For profiling pieces of a sequence:
   <pre>
    Stopwatch sw;
    slowOperation();
    sw.after("slowOperation");
    kdTree.balance();
    sw.after("Balance tree");
   </pre>
 */
class Stopwatch {
private:

    std::string             myName;

    bool                    m_enabled;

    double                  startTime;
    std::string             prevMark;
    double                  prevTime;

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

    Stopwatch(const std::string& name = "Stopwatch");

    void setEnabled(bool e) {
        m_enabled = e;
    }

    /** A stopwatch only prints output when enabled */
    bool enabled() const {
        return m_enabled;
    }

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

    
    /** Reset the start time used by after() and the emwa value.*/
    void reset();

    /** Call after an operation has completed, with the name of the operation, to
        print a debug message listing the time since the previous after() call.
        
        Does nothing if the stopwatch is disabled.
     */
    void after(const std::string& s = "");

};

/** Because it is hard to remember the proper capitalization. */
typedef Stopwatch StopWatch;

}

#endif

