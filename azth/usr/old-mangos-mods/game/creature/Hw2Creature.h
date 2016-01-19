/* 
 * File:   Hw2Creature.h
 * Author: giuseppe
 *
 * Created on 9 agosto 2013, 11.58
 */

#ifndef HW2CREATURE_H
#define	HW2CREATURE_H

#include "Define.h"

class Creature;

class Hw2Creature {
    public:
        Hw2Creature(Creature *cr);
        ~Hw2Creature();

        Creature *creature;
		void AzerothRpgFunctions(uint8 tipo,uint32 diff=NULL);
		bool azGuard;
		uint32 react_timer, walk_timer , customScriptID;
		uint64 saved_target;
};

#endif	/* HW2CREATURE_H */

