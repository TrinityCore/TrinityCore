/**
 @file G3DGameUnits.h

 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 @created 2002-10-05
 @edited  2006-11-10
 */

#ifndef G3D_GAMEUNITS_H
#define G3D_GAMEUNITS_H

#include "G3D/platform.h"

namespace G3D {
/**
 Time, in seconds.
 */
typedef double GameTime;
typedef double SimTime;

/**
 Actual wall clock time in seconds.
 */
typedef double RealTime;

enum AMPM {AM, PM};

/** \deprecated */
enum {SECOND=1, MINUTE=60, HOUR = 60*60, DAY=24*60*60, SUNRISE=24*60*60/4, SUNSET=24*60*60*3/4, MIDNIGHT=0, METER=1, KILOMETER=1000};

/**
 Converts a 12 hour clock time into the number of seconds since 
 midnight.  Note that 12:00 PM is noon and 12:00 AM is midnight.

 Example: <CODE>toSeconds(10, 00, AM)</CODE>
 */
SimTime toSeconds(int hour, int minute, double seconds, AMPM ap);
SimTime toSeconds(int hour, int minute, AMPM ap);

}

#endif
