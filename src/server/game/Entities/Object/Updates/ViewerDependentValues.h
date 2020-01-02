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

#ifndef ViewerDependentValues_h__
#define ViewerDependentValues_h__

#include "Creature.h"
#include "GameObject.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "World.h"

namespace UF
{
template<typename Tag>
class ViewerDependentValue
{
};

template<>
class ViewerDependentValue<UF::ObjectData::DynamicFlagsTag>
{
public:
    using ValueType = UF::ObjectData::DynamicFlagsTag::ValueType;

    static ValueType GetValue(ValueType dynamicFlags, Object const* object, Player const* receiver)
    {
        if (Unit const* unit = object->ToUnit())
        {
            dynamicFlags &= ~UNIT_DYNFLAG_TAPPED;

            if (Creature const* creature = object->ToCreature())
            {
                if (creature->hasLootRecipient() && !creature->isTappedBy(receiver))
                    dynamicFlags |= UNIT_DYNFLAG_TAPPED;

                if (!receiver->isAllowedToLoot(creature))
                    dynamicFlags &= ~UNIT_DYNFLAG_LOOTABLE;
            }

            // unit UNIT_DYNFLAG_TRACK_UNIT should only be sent to caster of SPELL_AURA_MOD_STALKED auras
            if (dynamicFlags & UNIT_DYNFLAG_TRACK_UNIT)
                if (!unit->HasAuraTypeWithCaster(SPELL_AURA_MOD_STALKED, receiver->GetGUID()))
                    dynamicFlags &= ~UNIT_DYNFLAG_TRACK_UNIT;
        }
        else if (GameObject const* gameObject = object->ToGameObject())
        {
            uint16 dynFlags = 0;
            uint16 pathProgress = 0xFFFF;
            switch (gameObject->GetGoType())
            {
                case GAMEOBJECT_TYPE_QUESTGIVER:
                    if (gameObject->ActivateToQuest(receiver))
                        dynFlags |= GO_DYNFLAG_LO_ACTIVATE;
                    break;
                case GAMEOBJECT_TYPE_CHEST:
                case GAMEOBJECT_TYPE_GOOBER:
                    if (gameObject->ActivateToQuest(receiver))
                        dynFlags |= GO_DYNFLAG_LO_ACTIVATE | GO_DYNFLAG_LO_SPARKLE;
                    else if (receiver->IsGameMaster())
                        dynFlags |= GO_DYNFLAG_LO_ACTIVATE;
                    break;
                case GAMEOBJECT_TYPE_GENERIC:
                    if (gameObject->ActivateToQuest(receiver))
                        dynFlags |= GO_DYNFLAG_LO_SPARKLE;
                    break;
                case GAMEOBJECT_TYPE_TRANSPORT:
                case GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT:
                {
                    if (uint32 transportPeriod = gameObject->GetTransportPeriod())
                    {
                        float timer = float(gameObject->GetGOValue()->Transport.PathProgress % transportPeriod);
                        pathProgress = uint16(timer / float(transportPeriod) * 65535.0f);
                    }
                    break;
                }
                default:
                    break;
            }

            dynamicFlags = (pathProgress << 16) | dynFlags;
        }

        return dynamicFlags;
    }
};

template<>
class ViewerDependentValue<UF::UnitData::DisplayIDTag>
{
public:
    using ValueType = UF::UnitData::DisplayIDTag::ValueType;

    static ValueType GetValue(ValueType displayId, Unit const* unit, Player const* receiver)
    {
        if (unit->IsCreature())
        {
            CreatureTemplate const* cinfo = unit->ToCreature()->GetCreatureTemplate();

            // this also applies for transform auras
            if (SpellInfo const* transform = sSpellMgr->GetSpellInfo(unit->getTransForm()))
                for (SpellEffectInfo const* effect : transform->GetEffectsForDifficulty(unit->GetMap()->GetDifficultyID()))
                    if (effect && effect->IsAura(SPELL_AURA_TRANSFORM))
                        if (CreatureTemplate const* transformInfo = sObjectMgr->GetCreatureTemplate(effect->MiscValue))
                        {
                            cinfo = transformInfo;
                            break;
                        }

            if (cinfo->flags_extra & CREATURE_FLAG_EXTRA_TRIGGER)
                if (receiver->IsGameMaster())
                    displayId = cinfo->GetFirstVisibleModel()->CreatureDisplayID;
        }

        return displayId;
    }
};

template<>
class ViewerDependentValue<UF::UnitData::FactionTemplateTag>
{
public:
    using ValueType = UF::UnitData::FactionTemplateTag::ValueType;

    static ValueType GetValue(ValueType factionTemplate, Unit const* unit, Player const* receiver)
    {
        if (unit->IsControlledByPlayer() && receiver != unit && sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GROUP) && unit->IsInRaidWith(receiver))
        {
            FactionTemplateEntry const* ft1 = unit->GetFactionTemplateEntry();
            FactionTemplateEntry const* ft2 = receiver->GetFactionTemplateEntry();
            if (ft1 && ft2 && !ft1->IsFriendlyTo(ft2))
                // pretend that all other HOSTILE players have own faction, to allow follow, heal, rezz (trade wont work)
                factionTemplate = receiver->getFaction();
        }

        return factionTemplate;
    }
};

template<>
class ViewerDependentValue<UF::UnitData::FlagsTag>
{
public:
    using ValueType = UF::UnitData::FlagsTag::ValueType;

    static ValueType GetValue(ValueType flags, Unit const* /*unit*/, Player const* receiver)
    {
        // Gamemasters should be always able to select units - remove not selectable flag
        if (receiver->IsGameMaster())
            flags &= ~UNIT_FLAG_NOT_SELECTABLE;

        return flags;
    }
};

template<>
class ViewerDependentValue<UF::UnitData::AuraStateTag>
{
public:
    using ValueType = UF::UnitData::AuraStateTag::ValueType;

    static ValueType GetValue(ValueType /*auraState*/, Unit const* unit, Player const* receiver)
    {
        // Check per caster aura states to not enable using a spell in client if specified aura is not by target
        return unit->BuildAuraStateUpdateForTarget(receiver);
    }
};

template<>
class ViewerDependentValue<UF::UnitData::PvpFlagsTag>
{
public:
    using ValueType = UF::UnitData::PvpFlagsTag::ValueType;

    static ValueType GetValue(ValueType pvpFlags, Unit const* unit, Player const* receiver)
    {
        if (unit->IsControlledByPlayer() && receiver != unit && sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GROUP) && unit->IsInRaidWith(receiver))
        {
            FactionTemplateEntry const* ft1 = unit->GetFactionTemplateEntry();
            FactionTemplateEntry const* ft2 = receiver->GetFactionTemplateEntry();
            if (ft1 && ft2 && !ft1->IsFriendlyTo(ft2))
                // Allow targeting opposite faction in party when enabled in config
                pvpFlags &= UNIT_BYTE2_FLAG_SANCTUARY;
        }

        return pvpFlags;
    }
};

template<>
class ViewerDependentValue<UF::UnitData::NpcFlagsTag>
{
public:
    using ValueType = UF::UnitData::NpcFlagsTag::ValueType;

    static ValueType GetValue(ValueType npcFlag, uint32 i, Unit const* unit, Player const* receiver)
    {
        if (i == 0 && unit->IsCreature() && !receiver->CanSeeSpellClickOn(unit->ToCreature()))
            npcFlag &= ~UNIT_NPC_FLAG_SPELLCLICK;

        return npcFlag;
    }
};

template<>
class ViewerDependentValue<UF::GameObjectData::FlagsTag>
{
public:
    using ValueType = UF::GameObjectData::FlagsTag::ValueType;

    static ValueType GetValue(ValueType flags, GameObject const* gameObject, Player const* receiver)
    {
        if (gameObject->GetGoType() == GAMEOBJECT_TYPE_CHEST)
            if (gameObject->GetGOInfo()->chest.usegrouplootrules && !gameObject->IsLootAllowedFor(receiver))
                flags |= GO_FLAG_LOCKED | GO_FLAG_NOT_SELECTABLE;

        return flags;
    }
};

template<>
class ViewerDependentValue<UF::GameObjectData::LevelTag>
{
public:
    using ValueType = UF::GameObjectData::LevelTag::ValueType;

    static ValueType GetValue(ValueType level, GameObject const* gameObject, Player const* /*receiver*/)
    {
        bool isStoppableTransport = gameObject->GetGoType() == GAMEOBJECT_TYPE_TRANSPORT && !gameObject->GetGOValue()->Transport.StopFrames->empty();
        return isStoppableTransport ? gameObject->GetGOValue()->Transport.PathProgress : level;
    }
};

template<>
class ViewerDependentValue<UF::GameObjectData::StateTag>
{
public:
    using ValueType = UF::GameObjectData::StateTag::ValueType;

    static ValueType GetValue(ValueType state, GameObject const* gameObject, Player const* /*receiver*/)
    {
        bool isStoppableTransport = gameObject->GetGoType() == GAMEOBJECT_TYPE_TRANSPORT && !gameObject->GetGOValue()->Transport.StopFrames->empty();
        if (isStoppableTransport && gameObject->GetGoState() == GO_STATE_TRANSPORT_ACTIVE)
            if ((gameObject->GetGOValue()->Transport.StateUpdateTimer / 20000) & 1)
                state = GO_STATE_TRANSPORT_STOPPED;

        return state;
    }
};
}

#endif // ViewerDependentValues_h__
