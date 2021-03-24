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

#ifndef TRINITY_SPELLDEFINES_H
#define TRINITY_SPELLDEFINES_H

#include "Define.h"
#include "EnumFlag.h"

namespace UF
{
    struct SpellCastVisual;
}

namespace WorldPackets
{
    namespace Spells
    {
        struct SpellCastVisual;
    }
}

enum class SpellInterruptFlags : uint32
{
    None                        = 0,
    Movement                    = 0x00000001,
    DamagePushbackPlayerOnly    = 0x00000002,
    Stun                        = 0x00000004, // useless, even spells without it get interrupted
    Combat                      = 0x00000008,
    DamageCancelsPlayerOnly     = 0x00000010,
    MeleeCombat                 = 0x00000020, // NYI
    Immunity                    = 0x00000040, // NYI
    DamageAbsorb                = 0x00000080,
    ZeroDamageCancels           = 0x00000100,
    DamagePushback              = 0x00000200,
    DamageCancels               = 0x00000400
};

DEFINE_ENUM_FLAG(SpellInterruptFlags);

enum class SpellAuraInterruptFlags : uint32
{
    None                        = 0,
    HostileActionReceived       = 0x00000001,
    Damage                      = 0x00000002,
    Action                      = 0x00000004,
    Moving                      = 0x00000008,
    Turning                     = 0x00000010,
    Anim                        = 0x00000020,
    Dismount                    = 0x00000040,
    UnderWater                  = 0x00000080, // TODO: disallow casting when swimming (SPELL_FAILED_ONLY_ABOVEWATER)
    AboveWater                  = 0x00000100, // TODO: disallow casting when not swimming (SPELL_FAILED_ONLY_UNDERWATER)
    Sheathing                   = 0x00000200,
    Interacting                 = 0x00000400, // TODO: more than gossip, replace all the feign death removals by aura type
    Looting                     = 0x00000800,
    Attacking                   = 0x00001000,
    ItemUse                     = 0x00002000,
    DamageChannelDuration       = 0x00004000,
    Shapeshifting               = 0x00008000,
    ActionDelayed               = 0x00010000,
    Mount                       = 0x00020000,
    Standing                    = 0x00040000,
    LeaveWorld                  = 0x00080000,
    StealthOrInvis              = 0x00100000,
    InvulnerabilityBuff         = 0x00200000,
    EnterWorld                  = 0x00400000,
    PvPActive                   = 0x00800000,
    NonPeriodicDamage           = 0x01000000,
    LandingOrFlight             = 0x02000000,
    Release                     = 0x04000000,
    DamageCancelsScript         = 0x08000000, // NYI dedicated aura script hook
    EnteringCombat              = 0x10000000,
    Login                       = 0x20000000,
    Summon                      = 0x40000000,
    LeavingCombat               = 0x80000000,

    NOT_VICTIM                  = (HostileActionReceived | Damage | NonPeriodicDamage)
};

DEFINE_ENUM_FLAG(SpellAuraInterruptFlags);

enum class SpellAuraInterruptFlags2 : uint32
{
    None                        = 0,
    Falling                     = 0x00000001, // NYI
    Swimming                    = 0x00000002, // NYI
    NotMoving                   = 0x00000004, // NYI
    Ground                      = 0x00000008, // NYI
    Transform                   = 0x00000010, // NYI
    Jump                        = 0x00000020,
    ChangeSpec                  = 0x00000040, // NYI
    AbandonVehicle              = 0x00000080, // NYI
    StartOfEncounter            = 0x00000100, // NYI
    EndOfEncounter              = 0x00000200, // NYI
    Disconnect                  = 0x00000400, // NYI
    EnteringInstance            = 0x00000800, // NYI
    DuelEnd                     = 0x00001000, // NYI
    LeaveArenaOrBattleground    = 0x00002000, // NYI
    ChangeTalent                = 0x00004000, // NYI
    ChangeGlyph                 = 0x00008000, // NYI
    SeamlessTransfer            = 0x00010000, // NYI
    WarModeLeave                = 0x00020000, // NYI
    TouchingGround              = 0x00040000, // NYI
    ChromieTime                 = 0x00080000, // NYI
    SplineFlightOrFreeFlight    = 0x00100000, // NYI
    ProcOrPeriodicAttacking     = 0x00200000  // NYI
};

DEFINE_ENUM_FLAG(SpellAuraInterruptFlags2);

struct SpellCastVisual
{
    uint32 SpellXSpellVisualID = 0;
    uint32 ScriptVisualID = 0;

    operator UF::SpellCastVisual() const;
    operator WorldPackets::Spells::SpellCastVisual() const;
};

#endif
