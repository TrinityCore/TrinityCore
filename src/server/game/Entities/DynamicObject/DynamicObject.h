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

#ifndef TRINITYCORE_DYNAMICOBJECT_H
#define TRINITYCORE_DYNAMICOBJECT_H

#include "Object.h"
#include "GridObject.h"
#include "MapObject.h"

class Unit;
class Aura;
class SpellInfo;

enum DynamicObjectType
{
    DYNAMIC_OBJECT_PORTAL           = 0x0,      // unused
    DYNAMIC_OBJECT_AREA_SPELL       = 0x1,
    DYNAMIC_OBJECT_FARSIGHT_FOCUS   = 0x2
};

class TC_GAME_API DynamicObject final : public WorldObject, public GridObject<DynamicObject>, public MapObject
{
    public:
        DynamicObject(bool isWorldObject);
        ~DynamicObject();

    protected:
        void BuildValuesCreate(ByteBuffer* data, Player const* target) const override;
        void BuildValuesUpdate(ByteBuffer* data, Player const* target) const override;
        void ClearUpdateMask(bool remove) override;

    public:
        void BuildValuesUpdateForPlayerWithMask(UpdateData* data, UF::ObjectData::Mask const& requestedObjectMask,
            UF::DynamicObjectData::Mask const& requestedDynamicObjectMask, Player const* target) const;

        struct ValuesUpdateForPlayerWithMaskSender // sender compatible with MessageDistDeliverer
        {
            explicit ValuesUpdateForPlayerWithMaskSender(DynamicObject const* owner) : Owner(owner) { }

            DynamicObject const* Owner;
            UF::ObjectData::Base ObjectMask;
            UF::DynamicObjectData::Base DynamicObjectMask;

            void operator()(Player const* player) const;
        };

        void AddToWorld() override;
        void RemoveFromWorld() override;

        bool CreateDynamicObject(ObjectGuid::LowType guidlow, Unit* caster, SpellInfo const* spell, Position const& pos, float radius, DynamicObjectType type, SpellCastVisual spellVisual);
        void Update(uint32 p_time) override;
        void Remove();
        void SetDuration(int32 newDuration);
        int32 GetDuration() const;
        void Delay(int32 delaytime);
        void SetAura(Aura* aura);
        void RemoveAura();
        void SetCasterViewpoint();
        void RemoveCasterViewpoint();
        Unit* GetCaster() const { return _caster; }
        uint32 GetFaction() const override;
        void BindToCaster();
        void UnbindFromCaster();
        uint32 GetSpellId() const { return m_dynamicObjectData->SpellID; }
        SpellInfo const* GetSpellInfo() const;
        ObjectGuid GetCasterGUID() const { return m_dynamicObjectData->Caster; }
        ObjectGuid GetCreatorGUID() const override { return GetCasterGUID(); }
        ObjectGuid GetOwnerGUID() const override { return GetCasterGUID(); }
        float GetRadius() const { return m_dynamicObjectData->Radius; }

        UF::UpdateField<UF::DynamicObjectData, 0, TYPEID_DYNAMICOBJECT> m_dynamicObjectData;

    protected:
        Aura* _aura;
        Aura* _removedAura;
        Unit* _caster;
        int32 _duration; // for non-aura dynobjects
        bool _isViewpoint;
};
#endif
