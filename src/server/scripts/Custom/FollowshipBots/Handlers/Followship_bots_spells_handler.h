/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "Creature.h"

#include "Followship_bots_defines.h"

enum class FSBSpellType
{
    Any,
    Emergency,
    Heal,
    Buff,
    Damage
};

// Struct for spell info (could mirror your FSBotSpells)
struct FSBSpellDefinition
{
    uint32 spellId = 0;
    FSBSpellType type = FSBSpellType::Damage;
    float manaCostOverride = 0.0f;      // for spells that do not have a dbc value
    float hpThreshold = 100.f;  // optional
    float chance = 100.f;       // 0-100%
    float dist = 0.0f;          // desired distance to target
    bool isSelfCast = false;    // cast on self
    uint32 cooldownMs = 0;      // static cooldown duration (legacy) or DB override
    uint32 allowedRoles = FSB_ROLEMASK_ANY;
    bool isLocationSpell = false; // cast at position, not unit target
    FSB_Race allowedRace = FSB_Race::None;   // 0 = any race
    FSB_Class allowedClass = FSB_Class::None; // 0 = any class
    uint32 dbId = 0;            // back-reference to bot_spells.id
};

using FSBSpellTable = std::vector<FSBSpellDefinition>;
extern std::unordered_map<FSB_Class, FSBSpellTable const*> sBotSpellTables;

struct FSBSpellRuntime
{
    FSBSpellDefinition const* def; // pointer to static definition
    uint32 nextReadyMs = 0; // runtime cooldown
};

struct FSBSpellsData
{
    ObjectGuid beaconTargetGuid = ObjectGuid::Empty;
    ObjectGuid soulstoneTargetGuid = ObjectGuid::Empty;
};

namespace FSBSpells
{
    void InitBotSpellTables();
    void InitSpellRuntime(Creature* bot, std::vector<FSBSpellRuntime>& _runtimeSpells);
    FSBSpellTable const* GetBotSpellTableForClass(FSB_Class botClass);

    std::vector<FSBSpellRuntime*> BotGetAvailableSpells(Creature* bot, std::vector<FSBSpellRuntime>& runtimeSpells, FSBSpellType desiredType, bool requireSelfCast);
    FSBSpellRuntime* SelectBestHealSpell(Creature* bot, const std::vector<FSBSpellRuntime*>& heals, Unit* target);
    FSBSpellRuntime* SelectRandomHealSpell(Creature* bot, const std::vector<FSBSpellRuntime*>& heals, Unit* target);
    FSBSpellRuntime* SelectBestDamageSpell(Creature* bot, const std::vector<FSBSpellRuntime*>& damageSpells, Unit* target);

    void HandleOnSpellCast(Creature* bot, FSB_Class botClass, uint32 spellId);
    void HandleOnSpellCastGeneric(Creature*bot, uint32 spellId);

    bool BotTryDispel(Creature* bot);
    bool BotTryOffensiveDispel(Creature* bot);

    bool BotCastSpell(Creature* bot, uint32 spellId, Unit* target);
    SpellCastResult BotCastSpellWithResult(Creature* bot, uint32 spellId, Unit* target);
    bool BotCastSpellOnDeadTarget(Creature* bot, uint32 spellId, Unit* target);
    bool BotCastSpellatLocation(Creature* bot, uint32 spellId, const Position& pos);
    bool BotCastSpellWithCooldown(Creature* bot, uint32 spellId, Unit* target, uint32 cooldown);
    bool BotCastSpellatLocationWithCooldown(Creature* bot, uint32 spellId, const Position& pos, uint32 cooldown);

    Position GetOffensiveAoEPosition(Creature* bot);
    Position GetHealingAoEPosition(Creature* bot);
}

struct FSBSpellQuery
{
    FSBSpellType type = FSBSpellType::Any;
    FSB_Class allowedClass = FSB_Class::None; // 0 = any
    FSB_Race allowedRace = FSB_Race::None;    // 0 = any
    uint32 roleMask = FSB_ROLEMASK_ANY;       // 0 = any
    bool includeSelfCast = false;
    bool requireLocationSpell = false;
    bool respectCooldown = true;              // check SpellHistory + DB override
    bool excludeAlreadyPresentAura = false;   // target must not have the aura
    Unit* target = nullptr;                   // required for aura/cooldown checks
};

namespace FSBSpellsDB
{
    bool LoadBotSpellsFromDB();
    std::vector<FSBSpellDefinition> const& GetBotSpellCache();

    std::vector<FSBSpellDefinition const*> QuerySpells(FSBSpellQuery const& query, Creature* bot);
    bool IsSpellReady(Creature* bot, FSBSpellDefinition const& def);
    uint32 GetEffectiveCooldown(Creature* bot, uint32 spellId, uint32 dbCooldownMs);
}
