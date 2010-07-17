/**
 @file Stopwatch.cpp
 
 @maintainer Morgan McGuire, matrix@graphics3d.com
  
 @created 2005-10-05
 @edited  2005-10-05

 Copyright 2000-2003, Morgan McGuire.
 All rights reserved.
 */

#include "G3D/Stopwatch.h"
#include "G3D/System.h"

namespace G3D {

Stopwatch::Stopwatch() : inBetween(false), lastTockTime(-1), 
    lastDuration(0), lastCycleCount(0), m_fps(0), emwaFPS(0),
    m_smoothFPS(0), emwaDuration(0) {
    computeOverhead();
}


void Stopwatch::computeOverhead() {
    cycleOverhead = 0;
    tick();
    tock();
    cycleOverhead = elapsedCycles();
}


void Stopwatch::tick() {
    // This is 'alwaysAssert' instead of 'debugAssert'
    // since people rarely profile in debug mode.
    alwaysAssertM(! inBetween, "Stopwatch::tick() called twice in a row.");
    inBetween = true;

    // We read RDTSC twice here, but it is more abstract to implement this
    // way and at least we're reading the cycle count last.
    timeStart = System::time();
    System::beginCycleCount(cycleStart);
}


void Stopwatch::tock() {
    System::endCycleCount(cycleStart);
    RealTime now = System::time();
    lastDuration = now - timeStart;
    if (abs(emwaDuration - lastDuration) > max(emwaDuration, lastDuration) * 0.50) {
        // Off by more than 50%
        emwaDuration = lastDuration;
    } else {
        emwaDuration = lastDuration * 0.05 + emwaDuration * 0.95;
    }

    lastCycleCount = cycleStart - cycleOverhead;
    if (lastCycleCount < 0) {
        lastCycleCount = 0;
    }

    if (lastTockTime != -1.0) {
        m_fps = 1.0 / (now - lastTockTime);

        // Time smooth the average
        emwaFPS = m_fps * 0.01 + emwaFPS * 0.99;

        if (abs(emwaFPS - m_fps) > max(emwaFPS, m_fps) * 0.08) {
            // The difference between emwa and m_fps is way off
            // update emwa directly.
            emwaFPS = m_fps;
        }
        
        // Update m_smoothFPS only when the value varies significantly
        // We round so as to not mislead the user as to the accuracy of 
        // the number.
        if (m_smoothFPS == 0) {
            m_smoothFPS = m_fps;
        } else if (emwaFPS <= 10) {
            if (::fabs(m_smoothFPS - emwaFPS) > .75) {
                m_smoothFPS = floor(emwaFPS * 10.0 + 0.5) / 10.0;
            }
        } else {
            if (::fabs(m_smoothFPS - emwaFPS) > 1.25) {
                m_smoothFPS = floor(emwaFPS + 0.5);
            }
        }
    }
    lastTockTime = now;

    alwaysAssertM(inBetween, "Stopwatch::tock() called without matching tick.");
    inBetween = false;
}

}

