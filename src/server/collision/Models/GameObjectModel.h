/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
 
#ifndef _GAMEOBJECT_MODEL_H
#define _GAMEOBJECT_MODEL_H

#include <G3D/Matrix3.h>
#include <G3D/Vector3.h>
#include <G3D/AABox.h>
#include <G3D/Ray.h>

#include "Define.h"

namespace VMAP
{
    class WorldModel;
}

class GameObject;
struct GameObjectDisplayInfoEntry;

class GameObjectModel /*, public Intersectable*/
{
    uint32 _phasemask;
    G3D::AABox _bound;
    G3D::Matrix3 _invRotation;
    G3D::Vector3 _pos;
    //G3D::Vector3 iRot;
    float _invScale;
    float _scale;
    VMAP::WorldModel* _model;

    GameObjectModel() : _phasemask(0), _model(NULL) {}
    bool Initialize(const GameObject& go, const GameObjectDisplayInfoEntry& info);

public:
    std::string name;

    const G3D::AABox& getBounds() const { return _bound; }

    ~GameObjectModel();

    const G3D::Vector3& getPosition() const { return _pos;}

    /**	Enables\disables collision. */
    void Disable() { _phasemask = 0;}
    void Enable(uint32 phasemask) { _phasemask = phasemask;}

    bool intersectRay(const G3D::Ray& Ray, float& MaxDist, bool StopAtFirstHit, uint32 ph_mask) const;

    static GameObjectModel* Create(const GameObject& go);
};

#endif // _GAMEOBJECT_MODEL_H