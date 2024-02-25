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

#ifndef SceneObject_h__
#define SceneObject_h__

#include "Object.h"
#include "GridObject.h"

struct SceneTemplate;

enum class SceneType : uint32
{
    Normal      = 0,
    PetBattle   = 1
};

class TC_GAME_API SceneObject final : public WorldObject, public GridObject<SceneObject>
{
public:
    SceneObject();
    ~SceneObject();

protected:
    void BuildValuesCreate(ByteBuffer* data, Player const* target) const override;
    void BuildValuesUpdate(ByteBuffer* data, Player const* target) const override;
    void ClearUpdateMask(bool remove) override;

public:
    void BuildValuesUpdateForPlayerWithMask(UpdateData* data, UF::ObjectData::Mask const& requestedObjectMask,
        UF::SceneObjectData::Mask const& requestedSceneObjectMask, Player const* target) const;

    struct ValuesUpdateForPlayerWithMaskSender // sender compatible with MessageDistDeliverer
    {
        explicit ValuesUpdateForPlayerWithMaskSender(SceneObject const* owner) : Owner(owner) { }

        SceneObject const* Owner;
        UF::ObjectData::Base ObjectMask;
        UF::SceneObjectData::Base SceneObjectMask;

        void operator()(Player const* player) const;
    };

    void AddToWorld() override;
    void RemoveFromWorld() override;

    void Update(uint32 diff) override;
    void Remove();

    static SceneObject* CreateSceneObject(uint32 sceneId, Unit* creator, Position const& pos, ObjectGuid privateObjectOwner);
    bool Create(ObjectGuid::LowType lowGuid, SceneType type, uint32 sceneId, uint32 scriptPackageId, Map* map, Unit* creator,
        Position const& pos, ObjectGuid privateObjectOwner);

    ObjectGuid GetCreatorGUID() const override { return *m_sceneObjectData->CreatedBy; }
    ObjectGuid GetOwnerGUID() const override { return *m_sceneObjectData->CreatedBy; }
    uint32 GetFaction() const override { return 0; }

    float GetStationaryX() const override { return _stationaryPosition.GetPositionX(); }
    float GetStationaryY() const override { return _stationaryPosition.GetPositionY(); }
    float GetStationaryZ() const override { return _stationaryPosition.GetPositionZ(); }
    float GetStationaryO() const override { return _stationaryPosition.GetOrientation(); }
    void RelocateStationaryPosition(Position const& pos) { _stationaryPosition.Relocate(pos); }

    void SetCreatedBySpellCast(ObjectGuid castId) { _createdBySpellCast = castId; }

    UF::UpdateField<UF::SceneObjectData, 0, TYPEID_SCENEOBJECT> m_sceneObjectData;

private:
    bool ShouldBeRemoved() const;

    Position _stationaryPosition;
    ObjectGuid _createdBySpellCast;
};

#endif // SceneObject_h__
