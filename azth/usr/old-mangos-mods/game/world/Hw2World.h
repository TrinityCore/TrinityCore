/* 
 * File:   Hw2World.h
 * Author: giuseppe
 *
 * Created on 18 agosto 2013, 17.31
 */

#ifndef HW2WORLD_H
#define	HW2WORLD_H

#include "Define.h"

class World;

class Hw2World {
    public:
        Hw2World(World *w);
        ~Hw2World();
        
    void AzerothExtra(const char *stringa, uint8 scelta);
        
    World *world;   
};

#endif	/* HW2WORLD_H */

