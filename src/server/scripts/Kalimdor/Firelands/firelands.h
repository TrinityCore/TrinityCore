/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#ifndef DEF_FIRELANDS_H
#define DEF_FIRELANDS_H

#define FLScriptName "instance_firelands"

enum Data
{
    DATA_SHANNOX                = 0,
    DATA_RHYOLITH               = 1,
    DATA_BETHTILAC              = 2,
    DATA_ALYSRAZOR              = 3,
    DATA_BALEROC                = 4,
    DATA_STAGHELM               = 5,
    DATA_RAGNAROS               = 6,
    DATA_RIPLIMB                = 7,
    DATA_RAGEFACE               = 8,
    DATA_RHYOLITH_HEALTH_SHARED = 9,
    DATA_EVENT                  = 10,
    DATA_RAGNAROS_PLATFORM      = 11,
    DATA_MAJORDOMO_ALYSRAZOR    = 13,
    DATA_TEAM                    = 14,

};

enum CreatureIds
{
    NPC_SHANNOX                     = 53691,
    NPC_RAGEFACE                    = 53695,
    NPC_RIPLIMB                     = 53694,
    NPC_RHYOLITH                    = 52558,
    NPC_BETHTILAC                   = 52498,
    NPC_ALYSRAZOR                   = 52530,
    NPC_BALEROC                     = 53494,
    NPC_STAGHELM                    = 52571,
    NPC_RAGNAROS                    = 52409,
    NPC_KAR                            = 53616,
    // alysrazor event
    NPC_BLAZING_MONSTROSITY_LEFT    = 53786,
    NPC_BLAZING_MONSTROSITY_RIGHT   = 53791,
    NPC_EGG_PILE                    = 53795,
    NPC_HARBINGER_OF_FLAME          = 53793,
    NPC_MOLTEN_EGG_TRASH            = 53914,
    NPC_SMOULDERING_HATCHLING       = 53794,

    //Ragnaros
    NPC_SULFURAS_SMASH              = 53268,
    NPC_MAGMA_TRAP                  = 53086,
    NPC_LAVA_WAVE                   = 53363,
    NPC_SPLITTING_BLOW              = 53393,
    NPC_ENGULFING_FLAMES            = 53485,
    NPC_MOLTEN_SEED                 = 53186,
    NPC_LAVA_SCION                  = 53231,
    NPC_SON_OF_FLAME                = 53140,
    NPC_LIVING_METEOR               = 53500,
    NPC_MOLTEN_ELEMENTAL            = 53189,
    NPC_SULFURAS                    = 53420,
    NPC_ENTRAPPING_ROOTS            = 54074,
    NPC_DREADFLAME                  = 54127,
    NPC_CLOUDBURST                  = 54147,
    NPC_DREADFLAME_SPAWN            = 54203,
    NPC_BREATH_OF_FROST             = 53953,
    NPC_HAMUUL                      = 54109,
    NPC_MALFURION                   = 54110,
    NPC_CENARIUS                    = 53872,
    NPC_HEART_OF_RAGNAROS           = 54293,

    NPC_CIRCLE_OF_THRONES_PORTAL    = 54247,
};

enum GameobjectIds
{
    GO_CIRCLE_OF_THORNS_PORTAL1 = 209137,
    GO_CIRCLE_OF_THORNS_PORTAL2 = 209346,
    GO_CIRCLE_OF_THORNS_PORTAL3 = 209098,

    GO_BRIDGE_OF_RHYOLITH       = 209255,
    GO_FIRE_WALL_BALEROC        = 209066,
    GO_RAID_BRIDGE_FORMING      = 209277,
    GO_RAGNAROS_FLOOR           = 208835,
    GO_STICKY_WEB               = 208877,
    GO_MOLTEN_METEOR            = 208966,
    GO_FIRE_WALL_FENDRAL        = 208906,
    GO_CACHE_OF_THE_FIRELORD    = 208967,
    GO_CACHE_OF_THE_FIRELORD_H  = 209261,
    GO_SULFURON_BRIDGE          = 209251,
    GO_DOOR_RAGNAROS            = 209073,
    GO_PLATFORM_RAGN            = 208835, // destructable - heroic
    GO_VOLCANO                  = 209253,
    GO_MOLTEN_GROUND            = 209252,
    GO_TRAP_DOOR                = 208873,
};
enum AlysrazorEvent
{
    ACTION_LAUNCH_EVENT_ALYSRAZOR,
};
enum MajordomoAlysrazorEvent
{
    EVENT_MAJORDOMO_NOT_DONE,
    EVENT_MAJORDOMO_DONE,
};
enum QuestDefines
{
    // quest
    GO_BRANCH_OF_NORDRASSIL                     = 209100,

    // Cannot find rhyolith fragment, summon it manualy
    SPELL_CREATE_EMBERSTONE_FRAGMENT            = 100518,
    SPELL_CREATE_CHITINOUS_FRAGMENT             = 100520,
    SPELL_CREATE_PYRESHELL_FRAGMENT             = 100519,

    SPELL_CHARGED_RHYOLITH_FOCUS                = 100481,
    SPELL_CHARGED_EMBERSTONE_FOCUS              = 100499,
    SPELL_CHARGED_CHITINOUS_FOCUS               = 100501,
    SPELL_CHARGED_PYRESHELL_FOCUS               = 100500,

    SPELL_TRANSFORM_CHARGED_RHYOLITH_FOCUS      = 100477,
    SPELL_TRANSFORM_CHARGED_EMBERSTONE_FOCUS    = 100496,
    SPELL_TRANSFORM_CHARGED_CHITINOUS_FOCUS     = 100498,
    SPELL_TRANSFORM_CHARGED_PYRESHELL_FOCUS     = 100497,

    GO_RHYOLITH_FRAGMENT                        = 209033,
    GO_EMBERSTONE_FRAGMENT                      = 209035,
    GO_PYRESHELL_FRAGMENT                       = 209036,
    GO_OBSIDIAN_FLECKED_CHITIN                  = 209037,

    NPC_DULL_RHYOLITH_FOCUS                     = 53951,
    NPC_DULL_EMBERSTONE_FOCUS                   = 53968,
    NPC_DULL_CHITINOUS_FOCUS                    = 53970,
    NPC_DULL_PYRESHELL_FOCUS                    = 53963,

    NPC_CHARGED_RHYOLITH_FOCUS                  = 53955,
    NPC_CHARGED_EMBERSTONE_FOCUS                = 53969,
    NPC_CHARGED_CHITINOUS_FOCUS                 = 53971,
    NPC_CHARGED_PYRESHELL_FOCUS                 = 53967,

    EVENT_PORTALS                               = 28888,

    SPELL_LEGENDARY_PORTAL_OPENING              = 101029,
    SPELL_BRANCH_OF_NORDRASSIL_WIN_COSMETIC     = 100326,
};

class DelayedAttackStartEvent : public BasicEvent
{
public:
    DelayedAttackStartEvent(Creature* owner) : _owner(owner) { }

    bool Execute(uint64 /*e_time*/, uint32 /*p_time*/) override
    {
        _owner->AI()->DoZoneInCombat(_owner, 200.0f);
        return true;
    }

private:
    Creature* _owner;
};


#endif
