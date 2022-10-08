/*
 * Copyright (C) 2022 BfaCore Reforged
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

#ifndef DEF_ASSAULT_ON_VIOLET_HOLD_H
#define DEF_ASSAULT_ON_VIOLET_HOLD_H

#include "Map.h"
#include "Creature.h"
#include "ObjectMgr.h"
#include "InstanceScenario.h"


#define DataHeader "VHA"
#define VHAScriptName "instance_violet_hold_assault"

constexpr uint32 EncounterCount = 8;

enum VHADataTypes
{
    DATA_ANUBESSET          = 1,
    DATA_MINDFLAYER_KAARHJ  = 2,
    DATA_SHIVERMAW          = 3,
    DATA_BLOOD_PRINCESS     = 4,
    DATA_FESTERFACE         = 5,
    DATA_MANASTORM          = 6,
    DATA_BELTRUG            = 7,
    DATA_SAELORN            = 8,
};

enum VHACreaturesIds
{
    // Bosses
    BOSS_SHIVERMAW          = 101951,
    BOSS_FESTERFACE         = 101995,
    BOSS_ANUBESSET          = 102246,
    BOSS_BLOOD_PRINCESS     = 102431,
    BOSS_MANASTORM          = 101976,
    BOSS_MINDFLAYER_KAARHJ  = 101950,
    BOSS_SAELORN            = 102387,
    BOSS_BELTRUG            = 102446,

    NPC_TELETRANSPORTATION_PORTAL = 102267,
    NPC_PORTAL_LEGION             = 102279,

    // Portal Keepers
    NPC_PORTAL_INQUISITOR   = 102337,
    NPC_PORTAL_DREADLORD    = 102336,
    NPC_PORTAL_JAILER       = 102335,
    NPC_PORTAL_FELGUARD     = 102302,

    // Portal Minions
    NPC_CORROSIVE_FELHOUND      = 102373,
    NPC_EREDAR_INVADER          = 102370,
    NPC_FEL_INCITER             = 102377,
    NPC_FELGUARD_DESTROYER      = 102368,
    NPC_FELHOUND_MAGE_SLAYER    = 102372,
    NPC_FELSTALKER_RAVENER      = 102369,
    NPC_SHADOW_COUNCIL_WARLOCK  = 102380,
    NPC_WRATHGUARD_BLADEWEAVER  = 102376,

    // Elite Legion Squad
    NPC_BLAZING_INFERNAL        = 102398,
    NPC_EREDAR_SHADOW_MENDER    = 102400,
    NPC_INFILTRATOR_ASSASIN     = 102395,
    NPC_WRATHLORD_BULWARK       = 102397,

    // Sael'orn Elite Squad
    NPC_ACOLYTE_OF_SAELORN      = 112738,
    NPC_VENOMHIDE_SHADOWSPINNER = 112733,
    NPC_BROOD_OF_SAELORN        = 112732,

    // Beltrug Elite Squad
    NPC_WRATHGUARD_DECIMATOR    = 112741,
    NPC_SHADOWY_OVERFIEND       = 112739,
};

enum VHAGameObjectsIds
{
    GO_THALENA_DOOR     = 246997,
    GO_FESTERFACE_DOOR  = 246998,
    GO_KAARHJ_DOOR      = 247000,
    GO_SHIVERMAW_DOOR   = 246999,
    GO_ANUBESSET_DOOR   = 247385,
    GO_MANASTORM_DOOR   = 246990,
};

const Position CenterRoom = { 4632.729f, 4013.699f, 94.021f };

using SpellTargets = std::list<WorldObject*>;

struct PlayerFilter
{
    bool operator() (WorldObject*& target)
    {
        if (target->ToPlayer())
            return false;

        return true;
    }
};

struct HealerSelector : public std::unary_function<Unit*, bool>
{
    const Unit* _source;
    bool _playerOnly;

    HealerSelector(Unit* source, bool playerOnly) : _source(source) , _playerOnly(playerOnly)
    {}

    bool operator() (Unit* target) const
    {
        if (!target)
            return false;

        if (!target->ToPlayer() || !_playerOnly)
            return false;

        switch (target->ToPlayer()->GetSpecializationId())
        {
            case TALENT_SPEC_DRUID_RESTORATION:
            case TALENT_SPEC_SHAMAN_RESTORATION:
            case TALENT_SPEC_MONK_MISTWEAVER:
            case TALENT_SPEC_PALADIN_HOLY:
            case TALENT_SPEC_PRIEST_DISCIPLINE:
            case TALENT_SPEC_PRIEST_HOLY:
                return true;

            default : return false;
        }
    }
};

#endif
