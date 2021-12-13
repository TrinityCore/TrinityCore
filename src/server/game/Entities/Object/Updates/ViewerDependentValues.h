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

#include "Conversation.h"
#include "Creature.h"
#include "GameObject.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "World.h"
#include "WorldSession.h"

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
    using value_type = UF::ObjectData::DynamicFlagsTag::value_type;

    static value_type GetValue(UF::ObjectData const* objectData, Object const* object, Player const* receiver)
    {
        value_type dynamicFlags = objectData->DynamicFlags;
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
                        dynFlags |= GO_DYNFLAG_LO_ACTIVATE | GO_DYNFLAG_LO_SPARKLE | GO_DYNFLAG_LO_HIGHLIGHT;
                    else if (receiver->IsGameMaster())
                        dynFlags |= GO_DYNFLAG_LO_ACTIVATE;
                    break;
                case GAMEOBJECT_TYPE_GENERIC:
                    if (gameObject->ActivateToQuest(receiver))
                        dynFlags |= GO_DYNFLAG_LO_SPARKLE | GO_DYNFLAG_LO_HIGHLIGHT;
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
                case GAMEOBJECT_TYPE_CAPTURE_POINT:
                    if (!gameObject->CanInteractWithCapturePoint(receiver))
                        dynFlags |= GO_DYNFLAG_LO_NO_INTERACT;
                    else
                        dynFlags &= ~GO_DYNFLAG_LO_NO_INTERACT;
                    break;
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
    using value_type = UF::UnitData::DisplayIDTag::value_type;

    static value_type GetValue(UF::UnitData const* unitData, Unit const* unit, Player const* receiver)
    {
        value_type displayId = unitData->DisplayID;
        if (unit->IsCreature())
        {
            CreatureTemplate const* cinfo = unit->ToCreature()->GetCreatureTemplate();

            // this also applies for transform auras
            if (SpellInfo const* transform = sSpellMgr->GetSpellInfo(unit->GetTransformSpell(), unit->GetMap()->GetDifficultyID()))
            {
                for (SpellEffectInfo const& spellEffectInfo : transform->GetEffects())
                {
                    if (spellEffectInfo.IsAura(SPELL_AURA_TRANSFORM))
                    {
                        if (CreatureTemplate const* transformInfo = sObjectMgr->GetCreatureTemplate(spellEffectInfo.MiscValue))
                        {
                            cinfo = transformInfo;
                            break;
                        }
                    }
                }
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
    using value_type = UF::UnitData::FactionTemplateTag::value_type;

    static value_type GetValue(UF::UnitData const* unitData, Unit const* unit, Player const* receiver)
    {
        value_type factionTemplate = unitData->FactionTemplate;
        if (unit->IsControlledByPlayer() && receiver != unit && sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GROUP) && unit->IsInRaidWith(receiver))
        {
            FactionTemplateEntry const* ft1 = unit->GetFactionTemplateEntry();
            FactionTemplateEntry const* ft2 = receiver->GetFactionTemplateEntry();
            if (ft1 && ft2 && !ft1->IsFriendlyTo(ft2))
                // pretend that all other HOSTILE players have own faction, to allow follow, heal, rezz (trade wont work)
                factionTemplate = receiver->GetFaction();
        }

        return factionTemplate;
    }
};

template<>
class ViewerDependentValue<UF::UnitData::FlagsTag>
{
public:
    using value_type = UF::UnitData::FlagsTag::value_type;

    static value_type GetValue(UF::UnitData const* unitData, Unit const* /*unit*/, Player const* receiver)
    {
        value_type flags = unitData->Flags;
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
    using value_type = UF::UnitData::AuraStateTag::value_type;

    static value_type GetValue(UF::UnitData const* /*unitData*/, Unit const* unit, Player const* receiver)
    {
        // Check per caster aura states to not enable using a spell in client if specified aura is not by target
        return unit->BuildAuraStateUpdateForTarget(receiver);
    }
};

template<>
class ViewerDependentValue<UF::UnitData::PvpFlagsTag>
{
public:
    using value_type = UF::UnitData::PvpFlagsTag::value_type;

    static value_type GetValue(UF::UnitData const* unitData, Unit const* unit, Player const* receiver)
    {
        value_type pvpFlags = unitData->PvpFlags;
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
    using value_type = UF::UnitData::NpcFlagsTag::value_type;

    static value_type GetValue(UF::UnitData const* unitData, uint32 i, Unit const* unit, Player const* receiver)
    {
        value_type npcFlag = unitData->NpcFlags[i];
        if (i == 0 && unit->IsCreature() && !receiver->CanSeeSpellClickOn(unit->ToCreature()))
            npcFlag &= ~UNIT_NPC_FLAG_SPELLCLICK;

        return npcFlag;
    }
};

template<>
class ViewerDependentValue<UF::GameObjectData::FlagsTag>
{
public:
    using value_type = UF::GameObjectData::FlagsTag::value_type;

    static value_type GetValue(UF::GameObjectData const* gameObjectData, GameObject const* gameObject, Player const* receiver)
    {
        value_type flags = gameObjectData->Flags;
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
    using value_type = UF::GameObjectData::LevelTag::value_type;

    static value_type GetValue(UF::GameObjectData const* gameObjectData, GameObject const* gameObject, Player const* /*receiver*/)
    {
        value_type level = gameObjectData->Level;
        bool isStoppableTransport = gameObject->GetGoType() == GAMEOBJECT_TYPE_TRANSPORT && !gameObject->GetGOValue()->Transport.StopFrames->empty();
        return isStoppableTransport ? gameObject->GetGOValue()->Transport.PathProgress : level;
    }
};

template<>
class ViewerDependentValue<UF::GameObjectData::StateTag>
{
public:
    using value_type = UF::GameObjectData::StateTag::value_type;

    static value_type GetValue(UF::GameObjectData const* gameObjectData, GameObject const* gameObject, Player const* /*receiver*/)
    {
        value_type state = gameObjectData->State;
        bool isStoppableTransport = gameObject->GetGoType() == GAMEOBJECT_TYPE_TRANSPORT && !gameObject->GetGOValue()->Transport.StopFrames->empty();
        if (isStoppableTransport && gameObject->GetGoState() == GO_STATE_TRANSPORT_ACTIVE)
            if ((gameObject->GetGOValue()->Transport.StateUpdateTimer / 20000) & 1)
                state = GO_STATE_TRANSPORT_STOPPED;

        return state;
    }
};

template<>
class ViewerDependentValue<UF::ConversationData::LastLineEndTimeTag>
{
public:
    using value_type = UF::ConversationData::LastLineEndTimeTag::value_type;

    static value_type GetValue(UF::ConversationData const* /*conversationData*/, Conversation const* conversation, Player const* receiver)
    {
        LocaleConstant locale = receiver->GetSession()->GetSessionDbLocaleIndex();
        return conversation->GetLastLineEndTime(locale).count();
    }
};

template<>
class ViewerDependentValue<UF::ConversationLine::StartTimeTag>
{
public:
    using value_type = UF::ConversationLine::StartTimeTag::value_type;

    static value_type GetValue(UF::ConversationLine const* conversationLineData, Conversation const* conversation, Player const* receiver)
    {
        value_type startTime = conversationLineData->StartTime;
        LocaleConstant locale = receiver->GetSession()->GetSessionDbLocaleIndex();

        if (Milliseconds const* localizedStartTime = conversation->GetLineStartTime(locale, conversationLineData->ConversationLineID))
            startTime = localizedStartTime->count();

        return startTime;
    }
};
}

#endif // ViewerDependentValues_h__
