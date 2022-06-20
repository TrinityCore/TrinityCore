/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include <memory>

namespace G3D
{
    class Quat;
}

namespace VMAP
{
    class WorldModel;
    enum class ModelIgnoreFlags : uint32;
}

class GameObject;
class PhaseShift;
struct GameObjectDisplayInfoEntry;

class TC_COMMON_API GameObjectModelOwnerBase
{
public:
    virtual ~GameObjectModelOwnerBase() = default;

    virtual bool IsSpawned() const = 0;
    virtual uint32 GetDisplayId() const = 0;
    virtual bool IsInPhase(PhaseShift const& /*phaseShift*/) const = 0;
    virtual G3D::Vector3 GetPosition() const = 0;
    virtual G3D::Quat GetRotation() const = 0;
    virtual float GetScale() const = 0;
    virtual void DebugVisualizeCorner(G3D::Vector3 const& /*corner*/) const = 0;
};

class TC_COMMON_API GameObjectModel /*, public Intersectable*/
{
    GameObjectModel() : _collisionEnabled(false), iInvScale(0), iScale(0), iModel(nullptr) { }
public:
    const G3D::AABox& getBounds() const { return iBound; }

    ~GameObjectModel();

    const G3D::Vector3& getPosition() const { return iPos;}

    /* Enables/disables collision */
    void enableCollision(bool enable) { _collisionEnabled = enable; }
    bool isCollisionEnabled() const { return _collisionEnabled; }

    bool intersectRay(G3D::Ray const& ray, float& maxDist, bool stopAtFirstHit, PhaseShift const& phaseShift, VMAP::ModelIgnoreFlags ignoreFlags) const;

    static GameObjectModel* Create(std::unique_ptr<GameObjectModelOwnerBase> modelOwner, std::string const& dataPath);

    bool UpdatePosition();

private:
    bool initialize(std::unique_ptr<GameObjectModelOwnerBase> modelOwner, std::string const& dataPath);

    bool _collisionEnabled;
    G3D::AABox iBound;
    G3D::Matrix3 iInvRot;
    G3D::Vector3 iPos;
    float iInvScale;
    float iScale;
    VMAP::WorldModel* iModel;
    std::unique_ptr<GameObjectModelOwnerBase> owner;
};

TC_COMMON_API void LoadGameObjectModelList(std::string const& dataPath);

#endif // _GAMEOBJECT_MODEL_H
