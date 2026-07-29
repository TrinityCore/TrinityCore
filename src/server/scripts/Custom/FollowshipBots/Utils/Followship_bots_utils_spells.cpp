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

#include <random>

#include "Map.h"
#include "ObjectAccessor.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "ThreatManager.h"
#include "Unit.h"

#include "Followship_bots_druid.h"
#include "Followship_bots_hunter.h"
#include "Followship_bots_mage.h"
#include "Followship_bots_monk.h"
#include "Followship_bots_paladin.h"
#include "Followship_bots_priest.h"
#include "Followship_bots_rogue.h"
#include "Followship_bots_shaman.h"
#include "Followship_bots_warlock.h"
#include "Followship_bots_warrior.h"
#include "Followship_bots_utils.h"
#include "Followship_bots_mgr.h"

#include "Followship_bots_group_handler.h"
#include "Followship_bots_pet_handler.h"
#include "Followship_bots_powers_handler.h"
#include "Followship_bots_spells_handler.h"

std::unordered_map<uint32 /*spellId*/, uint32 /*readyTimeMs*/> spellCooldowns;



std::unordered_map<FSB_Class, DispelAbility> DispelTable =
{
    { FSB_Class::Priest,  { SPELL_PRIEST_PURIFY,   { DISPEL_MAGIC, DISPEL_DISEASE }, 8000 } },
    { FSB_Class::Paladin, { SPELL_PALADIN_CLEANSE,       { DISPEL_MAGIC, DISPEL_DISEASE, DISPEL_POISON }, 8000  }},
    { FSB_Class::Druid,   { SPELL_DRUID_REMOVE_CORRUPTION, { DISPEL_CURSE, DISPEL_POISON }, 8000  }},
    { FSB_Class::Druid,   { SPELL_DRUID_NATURE_CURE,       { DISPEL_MAGIC, DISPEL_CURSE, DISPEL_POISON }, 8000 }},
    { FSB_Class::Shaman,  { SPELL_SHAMAN_PURIFY_SPIRIT,    { DISPEL_MAGIC }, 8000 } },
    { FSB_Class::Shaman,  { SPELL_SHAMAN_CLEANSE_SPIRIT,   { DISPEL_CURSE }, 8000 } },
    { FSB_Class::Mage,    { SPELL_MAGE_REMOVE_CURSE,     { DISPEL_CURSE }, 8000  }},
    { FSB_Class::Monk,    { SPELL_MONK_DETOX_HEAL, { DISPEL_POISON, DISPEL_DISEASE}, 8000 }},
};

std::unordered_map<FSB_Class, OffensiveDispelAbility> OffensiveDispelTable =
{
    { FSB_Class::Priest,  { SPELL_PRIEST_DISPEL_MAGIC, OFFDISPEL_MAGIC } },
    { FSB_Class::Shaman,  { SPELL_SHAMAN_PURGE,        OFFDISPEL_MAGIC } },
    { FSB_Class::Hunter,    { SPELL_HUNTER_TRANQUILIZING_SHOT, OFFDISPEL_MAGIC } },
    { FSB_Class::Mage,    { SPELL_MAGE_SPELL_STEAL,     OFFDISPEL_STEAL } },
    { FSB_Class::Monk,    { SPELL_MONK_DETOX_ATTACK, OFFDISPEL_MAGIC } },
};

namespace FSBSpellsUtils
{
    bool IsSpellReady(uint32 spellId)
    {
        uint32 now = getMSTime();

        auto it = spellCooldowns.find(spellId);
        if (it == spellCooldowns.end())
            return true; // no cooldown stored ? ready

        return now >= it->second;
    }

    void PutSpellOnCooldown(uint32 spellId, uint32 cooldownMs)
    {
        if (!spellId || !cooldownMs)
            return;

        uint32 now = getMSTime();

        spellCooldowns[spellId] = now + cooldownMs;
    }

    bool CanCastNow(Unit* me, uint32 now, uint32 globalCooldownUntil)
    {
        return me
            && now >= globalCooldownUntil
            && !me->HasUnitState(UNIT_STATE_CASTING);
    }

    bool CheckSpellContextRequirements(Creature* bot, uint32 spellId, Unit* target)
    {
        if (!bot || !bot->IsInWorld() || bot->IsDuringRemoveFromWorld() || !bot->IsAlive())
            return false;

        if (!target || !target->IsInWorld() || target->IsDuringRemoveFromWorld() || !target->IsAlive())
            return false;

        if (!spellId)
            return false;

        switch (spellId)
        {

            // Can only be cast on more than 2/3 attackers
            // OR when 2/3 attackers are around
            // This way we limit spells to CC instead of general/spam use
        case SPELL_PALADIN_REPENTANCE:
            return CheckRepentanceRequirements(bot, target);

        case SPELL_HUNTER_SCARE_BEAST:
            return CheckCrowdControlRequirements(bot, 30.f) && target->GetCreatureType() == CREATURE_TYPE_BEAST;

        case SPELL_WARRIOR_CLEAVE:
        case SPELL_SHAMAN_CRASH_LIGHTNING:
            return CheckCrowdControlRequirements(bot, 5.f);

        case SPELL_PRIEST_PSYCHIC_SCREAM:
        case SPELL_PALADIN_DIVINE_STORM:
        case SPELL_PALADIN_CONSECRATION:
        case SPELL_ROGUE_BLACK_POWDER:
        case SPELL_ROGUE_FAN_KNIVES:
            return CheckCrowdControlRequirements(bot, 8.f);

        case SPELL_MAGE_ARCANE_EXPLOSION:
        case SPELL_WARRIOR_COLOSSUS_SMASH:
        case SPELL_DRUID_STARFIRE:
        case SPELL_WARLOCK_HOWL_TERROR:
        case SPELL_ROGUE_SHURIKEN_STORM:
        case SPELL_ROGUE_CRIMSON_TEMPEST:
        case SPELL_SHAMAN_THUNDERSTORM:
            return CheckCrowdControlRequirements(bot, 10.f);

        case SPELL_PRIEST_HOLY_NOVA:
        case SPELL_MAGE_FROST_NOVA:
            return CheckCrowdControlRequirements(bot, 12.f);

        case SPELL_ROGUE_BLIND:
            return CheckCrowdControlRequirements(bot, 15.f);

        case SPELL_MONK_PARALYSIS:
        case SPELL_MONK_PARALYSIS_CHI:
            return CheckCrowdControlRequirements(bot, 20.f);

        case SPELL_MAGE_BLIZZARD:
        case SPELL_MAGE_FLAMESTRIKE:
        case SPELL_DRUID_HIBERNATE:
        case SPELL_MAGE_POLYMORPH:
        case SPELL_SHAMAN_HEX:
            return CheckCrowdControlRequirements(bot, 30.f);

        case SPELL_SHAMAN_CHAIN_LIGHTNING:
            return CheckCrowdControlRequirements(bot, 40.f);

            // Rogue Stealth Req
        case SPELL_ROGUE_CHEAP_SHOT:
        case SPELL_ROGUE_AMBUSH:
            return bot->HasAura(SPELL_ROGUE_STEALTH);

            // Bot Power Depleted
        case SPELL_MAGE_ARCANE_SURGE:
        case SPELL_MONK_BLACK_OX_BREW:
            return bot->GetPowerPct(bot->GetPowerType()) <= 10;

        case SPELL_PALADIN_LAY_ON_HANDS:
        case SPELL_PALADIN_DIVINE_SHIELD:
            return bot->GetPowerPct(bot->GetPowerType()) <= 20;

        case SPELL_ROGUE_THISTLE_TEA:
            return bot->GetPowerPct(bot->GetPowerType()) <= 30;

        case SPELL_MAGE_EVOCATION:
            return bot->GetPowerPct(bot->GetPowerType()) <= 50;

            //Silence Interrupt
        case SPELL_SHAMAN_WIND_SHEAR:
        case SPELL_MONK_SPEAR_HAND_STRIKE:
        case SPELL_HUNTER_COUNTER_SHOT:
        case SPELL_ROGUE_KICK:
        case SPELL_PRIEST_SILENCE:
        case SPELL_WARLOCK_CURSE_TONGUES:
        case SPELL_PALADIN_REBUKE:
        case SPELL_WARRIOR_PUMMEL:
        case SPELL_MAGE_COUNTERSPELL:
            return target && target->HasUnitState(UNIT_STATE_CASTING);

            // Bot Health Depleted
        case SPELL_MAGE_ICE_BLOCK:
            return target == bot && bot->GetHealthPct() < 10;

        case SPELL_SHAMAN_ASTRAL_SHIFT:
        case SPELL_WARRIOR_LAST_STAND:
            return target == bot && bot->GetHealthPct() < 30;

        case SPELL_HUNTER_ASPECT_TURTLE:
        case SPELL_DRUID_BEAR_SURVIVAL_INSTINCTS:
        case SPELL_DRUID_IRONBARK:
        case SPELL_DRUID_CELESTIAL_ALIGNMENT:
            return target == bot && bot->GetHealthPct() < 50;

        case SPELL_MAGE_ICE_BARRIER:
            return target == bot && bot->GetHealthPct() < 75;

            // Target Health Depleted
        case SPELL_WARRIOR_EXECUTE:
            return target && target->GetHealthPct() <= 20;

            // RACIAL
        case SPELL_PANDAREN_QUAKING_PALM:
        {
            FSB_Race race = FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry());
            return (race == FSB_Race::Pandaren || race == FSB_Race::PandarenHorde) && CheckCrowdControlRequirements(bot, 5.f);
        }

        case SPELL_DRAENEI_GIFT_NAARU:
            return FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()) == FSB_Race::Draenei;

        case SPELL_DWARF_STONEFORM:
            return CheckDwarfStoneformRequirements(bot);

        case SPELL_HUMAN_WILL_TO_SURVIVE:
            return FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()) == FSB_Race::Human && HasAnyMechanic(bot, { MECHANIC_STUN });

        case SPELL_UNDEAD_WILL_OF_FORSAKEN:
            return FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()) == FSB_Race::Undead && HasAnyMechanic(bot, { MECHANIC_CHARM, MECHANIC_FEAR, MECHANIC_SLEEP });

        case SPELL_TAUREN_WAR_STOMP:
            return FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()) == FSB_Race::Tauren && CheckCrowdControlRequirements(bot, 8.f);

        case SPELL_BLOODELF_ARCANE_TORRENT:
            return FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()) == FSB_Race::BloodElf && target && FindEnemyBuffToDispel(target) && bot->IsWithinDist(target, 8.f);

        case SPELL_GOBLIN_ROCKET_BARRAGE:
            return FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()) == FSB_Race::Goblin && target && bot->IsWithinDist(target, 30.f);

        case SPELL_ORC_BLOOD_FURY:
            return FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()) == FSB_Race::Orc;

        case SPELL_TROLL_BERSERKING:
            return FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()) == FSB_Race::Troll;

        case SPELL_PALADIN_BLESSING_SANCTUARY:
            return HasAnyMechanic(target, { MECHANIC_FEAR, MECHANIC_HORROR, MECHANIC_SILENCE, MECHANIC_STUN });

        case SPELL_MONK_TIGER_LUST:
            return HasAnyMechanic(target, { MECHANIC_SNARE, MECHANIC_ROOT });

        case SPELL_HUNTER_TRANQUILIZING_SHOT:
            return HasAnyMechanic(target, { MECHANIC_ENRAGED }) || FindEnemyBuffToDispel(target);

        case SPELL_SHAMAN_ASCENDANCE:
        case SPELL_PALADIN_LIGHT_OF_DAWN:
            return !FSBGroup::BotGroupIsHealthy_Average(bot, 60);

        // NYI in TC
        //case SPELL_SHAMAN_SPIRIT_LINK_TOTEM:
        //    return !FSBGroup::BotGroupIsHealthy_Average(bot, 40);

        case SPELL_SHAMAN_DOWNPOUR:
            return !FSBGroup::BotGroupIsHealthy_Average(bot, 70);

        case SPELL_HUNTER_MONGOOSE_BITE:
        case SPELL_HUNTER_WING_CLIP:
        case SPELL_HUNTER_RAPTOR_STRIKE:
        case SPELL_HUNTER_DISENGAGE:
            return bot->IsWithinMeleeRange(target);

        case SPELL_HUNTER_MEND_PET:
            return FSBPet::GetBotPet(bot) && FSBPet::GetBotPet(bot)->GetHealthPct() < 50;

            //Summoned creatures
        case SPELL_MONK_SUMMON_SERPENT_STATUE:
            return CheckNoNpcInRangeRequirement(bot, 60849, 40.f);

        case SPELL_MONK_BLACK_OX_STATUE:
            return CheckNoNpcInRangeRequirement(bot, 61146, 40.f);

            // Is Not In Dungeon
        case SPELL_MAGE_BLINK:
            return !bot->GetMap()->IsDungeon();

        default:
            return true;
        }
    }

    bool CheckNoNpcInRangeRequirement(Creature* bot, uint32 entry, float range)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (!entry)
            return false;

        Creature* c = bot->FindNearestCreature(entry, range);

        if (c)
            return false;

        return true;
    }

    bool CheckDwarfStoneformRequirements(Creature* bot)
    {
        if (!bot || !bot->IsAlive())
            return false;

        if (FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()) != FSB_Race::Dwarf)
            return false;

        if (HasAnyNegativeDispel(bot, { DISPEL_CURSE, DISPEL_POISON, DISPEL_MAGIC, DISPEL_DISEASE }))
            return true;

        if (HasAnyMechanic(bot, { MECHANIC_BLEED }))
            return true;

        return false;
    }

    bool CheckRepentanceRequirements(Creature* bot, Unit* target)
    {
        if (!CheckCrowdControlRequirements(bot, 30.f))
            return false;

        static const std::unordered_set<uint32> allowedTypes =
        {
            CREATURE_TYPE_DRAGONKIN,
            CREATURE_TYPE_HUMANOID,
            CREATURE_TYPE_DEMON,
            CREATURE_TYPE_UNDEAD,
            CREATURE_TYPE_GIANT
        };

        return allowedTypes.contains(target->GetCreatureType());

    }

    bool CheckCrowdControlRequirements(Creature* bot, float range)
    {
        if (!bot || !bot->IsAlive())
            return false;

        Player* player = FSBMgr::Get()->GetBotOwner(bot);

        if (player && FSBCombatUtils::HasHostileInRange(bot, range, 3))
            return true;

        else (FSBCombatUtils::HasHostileInRange(bot, range, 2));

        return false;
    }

    DispelType ConvertAuraToDispelType(Aura* aura)
    {
        switch (aura->GetSpellInfo()->Dispel)
        {
        case DISPEL_MAGIC:   return DISPEL_MAGIC;
        case DISPEL_CURSE:   return DISPEL_CURSE;
        case DISPEL_DISEASE: return DISPEL_DISEASE;
        case DISPEL_POISON:  return DISPEL_POISON;
        default:             return (DispelType)-1;
        }
    }

    // Gets the Mana Potion spell id on a provided level
    uint32 GetManaPotionSpellForLevel(uint8 level)
    {
        for (auto const& entry : ManaPotionTable)
        {
            if (level >= entry.minLevel && level <= entry.maxLevel)
                return entry.spellId;
        }
        return 0;
    }

    uint32 GetHealthPotionSpellForLevel(uint8 level)
    {
        for (auto const& entry : HealthPotionTable)
        {
            if (level >= entry.minLevel && level <= entry.maxLevel)
                return entry.spellId;
        }
        return 0;
    }

    std::string GetSpellName(uint32 spellId)
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE);
        if (!spellInfo || !spellInfo->SpellName)
            return "unknown spell";

        std::string name = spellInfo->SpellName->Str[LOCALE_enUS];
        return name.empty() ? "unknown spell" : name;
    }

    const MountSpellList* GetMountSpellsForBot(FSB_Race race, uint8 level)
    {
        auto raceIt = MountSpells.find(race);
        if (raceIt == MountSpells.end())
            return nullptr;

        auto& levelMap = raceIt->second;

        // Find the highest level <= bot level
        MountSpellList const* bestList = nullptr;

        for (auto const& [reqLevel, spells] : levelMap)
        {
            if (level >= reqLevel)
                bestList = &spells;
        }

        return bestList; // may be nullptr if no mounts available
    }

    uint32 GetRandomMountSpellForBot(Creature* bot)
    {
        if (!bot)
            return 0;

        FSB_Race race = FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry());

        MountSpellList const* spells = GetMountSpellsForBot(race, bot->GetLevel());
        if (!spells || spells->empty())
            return 0;

        return (*spells)[urand(0, spells->size() - 1)];
    }

    bool CastRandomMountLevelSpell(Creature* bot)
    {
        if (!bot)
            return false;

        uint32 spellId = GetRandomMountSpellForBot(bot);
        if (!spellId)
            return false;

        SpellCastResult result = bot->CastSpell(bot, spellId, true);

        if (result == SPELL_CAST_OK)
            return true;

        return false;
    }

    Aura* FindEnemyBuffToDispel(Unit* enemy)
    {
        for (auto const& auraPair : enemy->GetAppliedAuras())
        {
            Aura* aura = auraPair.second->GetBase();
            if (!aura)
                continue;

            SpellInfo const* info = aura->GetSpellInfo();

            // Only beneficial auras
            if (!info->IsPositive())
                continue;

            // Only magic buffs
            if (info->Dispel == DISPEL_MAGIC)
                return aura;
        }

        return nullptr;
    }

    bool BotHasHealSpells(Creature* bot)
    {
        if (!bot)
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        auto botClass = baseAI->botClass;
        auto botRole = baseAI->botRole;
        uint32 botRoleMask = RoleToMask(botRole);

        auto it = sBotSpellTables.find(botClass);
        if (it == sBotSpellTables.end() || !it->second)
            return false;

        const auto& table = *(it->second);

        for (auto const& def : table)
        {
            if (def.type == FSBSpellType::Heal &&
                (def.allowedRoles == FSB_ROLEMASK_ANY || (def.allowedRoles & botRoleMask) != 0))
                return true;
        }

        return false;
    }

    bool BotHasHealSpellsForSelf(Creature* bot)
    {
        if (!bot)
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return false;

        auto botClass = baseAI->botClass;
        auto botRole = baseAI->botRole;
        uint32 botRoleMask = RoleToMask(botRole);

        auto it = sBotSpellTables.find(botClass);
        if (it == sBotSpellTables.end() || !it->second)
            return false;

        const auto& table = *(it->second);

        for (auto const& def : table)
        {
            if ((def.type == FSBSpellType::Heal && def.isSelfCast) &&
                (def.allowedRoles == FSB_ROLEMASK_ANY || (def.allowedRoles & botRoleMask) != 0))
                return true;
        }

        return false;
    }

    bool HasAnyMechanic(Unit* u, std::initializer_list<Mechanics> mechanics)
    {
        if (!u || !u->IsAlive())
            return false;

        for (auto const& auraPair : u->GetAppliedAuras())
        {
            Aura* aura = auraPair.second->GetBase();
            if (!aura)
                continue;

            SpellInfo const* info = aura->GetSpellInfo();
            if (!info)
                continue;

            for (Mechanics m : mechanics)
            {
                if (info->Mechanic == m)
                    return true;
            }
        }

        return false;
    }

    bool HasAnyAuraType(Unit* u, std::initializer_list<AuraType> auraTypes)
    {
        if (!u || !u->IsAlive())
            return false;

        for (auto const& auraPair : u->GetAppliedAuras())
        {
            Aura* aura = auraPair.second->GetBase();
            if (!aura)
                continue;

            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            {
                AuraEffect const* eff = aura->GetEffect(i);
                if (!eff)
                    continue;

                for (AuraType t : auraTypes)
                {
                    if (eff->GetAuraType() == t)
                        return true;
                }
            }
        }

        return false;
    }

    bool HasAnyNegativeDispel(Unit* u, std::initializer_list<DispelType> dispels)
    {
        if (!u || !u->IsAlive())
            return false;

        for (auto const& auraPair : u->GetAppliedAuras())
        {
            Aura* aura = auraPair.second->GetBase();
            if (!aura)
                continue;

            SpellInfo const* info = aura->GetSpellInfo();
            if (!info)
                continue;

            // Only negative auras
            if (info->IsPositive())
                continue;

            DispelType auraDispel = DispelType(info->Dispel);

            for (DispelType d : dispels)
            {
                if (auraDispel == d)
                    return true;
            }
        }

        return false;
    }

    bool IsCrowdControlWithRandomTarget(uint32 spellId)
    {
        switch (spellId)
        {
        case SPELL_MAGE_POLYMORPH:
        case SPELL_WARLOCK_FEAR:
        case SPELL_DRUID_HIBERNATE:
        case SPELL_WARLOCK_HAVOC:
        case SPELL_ROGUE_BLIND:
        case SPELL_PALADIN_REPENTANCE:
        case SPELL_HUNTER_SCATTER_SHOT:
        case SPELL_HUNTER_SCARE_BEAST:
        case SPELL_MONK_PARALYSIS:
        case SPELL_MONK_PARALYSIS_CHI:
        case SPELL_PANDAREN_QUAKING_PALM:
        case SPELL_SHAMAN_HEX:
            return true;
        default:
            return false;
        }
    }

    std::string GetSpellCastResultString(SpellCastResult result)
    {
        switch (result)
        {
            case SPELL_CAST_OK: return "SPELL_CAST_OK";
            case SPELL_FAILED_NOT_READY: return "SPELL_FAILED_NOT_READY";
            case SPELL_FAILED_OUT_OF_RANGE: return "SPELL_FAILED_OUT_OF_RANGE";
            case SPELL_FAILED_NOT_BEHIND: return "SPELL_FAILED_NOT_BEHIND";
            case SPELL_FAILED_NOT_INFRONT: return "SPELL_FAILED_NOT_INFRONT";
            case SPELL_FAILED_LINE_OF_SIGHT: return "SPELL_FAILED_LINE_OF_SIGHT";
            case SPELL_FAILED_MOVING: return "SPELL_FAILED_MOVING";
            case SPELL_FAILED_INTERRUPTED: return "SPELL_FAILED_INTERRUPTED";
            case SPELL_FAILED_NOT_KNOWN: return "SPELL_FAILED_NOT_KNOWN";
            case SPELL_FAILED_BAD_TARGETS: return "SPELL_FAILED_BAD_TARGETS";
            case SPELL_FAILED_IMMUNE: return "SPELL_FAILED_IMMUNE";
            case SPELL_FAILED_CANT_CAST_ON_TAPPED: return "SPELL_FAILED_CANT_CAST_ON_TAPPED";
            case SPELL_FAILED_NOT_MOUNTED: return "SPELL_FAILED_NOT_MOUNTED";
            case SPELL_FAILED_NOT_WHILE_GHOST: return "SPELL_FAILED_NOT_WHILE_GHOST";
            case SPELL_FAILED_NO_POWER: return "SPELL_FAILED_NO_POWER";
            case SPELL_FAILED_ALREADY_AT_FULL_HEALTH: return "SPELL_FAILED_ALREADY_AT_FULL_HEALTH";
            case SPELL_FAILED_ALREADY_AT_FULL_MANA: return "SPELL_FAILED_ALREADY_AT_FULL_MANA";
            case SPELL_FAILED_ALREADY_AT_FULL_POWER: return "SPELL_FAILED_ALREADY_AT_FULL_POWER";
            case SPELL_FAILED_LEVEL_REQUIREMENT: return "SPELL_FAILED_LEVEL_REQUIREMENT";
            case SPELL_FAILED_LOWLEVEL: return "SPELL_FAILED_LOWLEVEL";
            case SPELL_FAILED_HIGHLEVEL: return "SPELL_FAILED_HIGHLEVEL";
            case SPELL_FAILED_EQUIPPED_ITEM: return "SPELL_FAILED_EQUIPPED_ITEM";
            case SPELL_FAILED_CASTER_AURASTATE: return "SPELL_FAILED_CASTER_AURASTATE";
            case SPELL_FAILED_CASTER_DEAD: return "SPELL_FAILED_CASTER_DEAD";
            case SPELL_FAILED_CONFUSED: return "SPELL_FAILED_CONFUSED";
            case SPELL_FAILED_FLEEING: return "SPELL_FAILED_FLEEING";
            case SPELL_FAILED_STUNNED: return "SPELL_FAILED_STUNNED";
            case SPELL_FAILED_SILENCED: return "SPELL_FAILED_SILENCED";
            case SPELL_FAILED_PACIFIED: return "SPELL_FAILED_PACIFIED";
            case SPELL_FAILED_CHARMED: return "SPELL_FAILED_CHARMED";
            case SPELL_FAILED_NOT_IN_CONTROL: return "SPELL_FAILED_NOT_IN_CONTROL";
            case SPELL_FAILED_NOT_SHAPESHIFT: return "SPELL_FAILED_NOT_SHAPESHIFT";
            case SPELL_FAILED_NOT_STANDING: return "SPELL_FAILED_NOT_STANDING";
            case SPELL_FAILED_ONLY_STEALTHED: return "SPELL_FAILED_ONLY_STEALTHED";
            case SPELL_FAILED_INCORRECT_AREA: return "SPELL_FAILED_INCORRECT_AREA";
            case SPELL_FAILED_REQUIRES_AREA: return "SPELL_FAILED_REQUIRES_AREA";
            case SPELL_FAILED_NEED_AMMO: return "SPELL_FAILED_NEED_AMMO";
            case SPELL_FAILED_NEED_MORE_ITEMS: return "SPELL_FAILED_NEED_MORE_ITEMS";
            case SPELL_FAILED_NOPATH: return "SPELL_FAILED_NOPATH";
            case SPELL_FAILED_NOT_HERE: return "SPELL_FAILED_NOT_HERE";
            case SPELL_FAILED_NOT_ON_TAXI: return "SPELL_FAILED_NOT_ON_TAXI";
            case SPELL_FAILED_NOT_ON_TRANSPORT: return "SPELL_FAILED_NOT_ON_TRANSPORT";
            case SPELL_FAILED_NOT_TRADEABLE: return "SPELL_FAILED_NOT_TRADEABLE";
            case SPELL_FAILED_NOT_TRADING: return "SPELL_FAILED_NOT_TRADING";
            case SPELL_FAILED_NOT_UNSHEATHED: return "SPELL_FAILED_NOT_UNSHEATHED";
            case SPELL_FAILED_ITEM_NOT_READY: return "SPELL_FAILED_ITEM_NOT_READY";
            case SPELL_FAILED_ITEM_GONE: return "SPELL_FAILED_ITEM_GONE";
            case SPELL_FAILED_ITEM_NOT_FOUND: return "SPELL_FAILED_ITEM_NOT_FOUND";
            case SPELL_FAILED_ALREADY_BEING_TAMED: return "SPELL_FAILED_ALREADY_BEING_TAMED";
            case SPELL_FAILED_ALREADY_HAVE_CHARM: return "SPELL_FAILED_ALREADY_HAVE_CHARM";
            case SPELL_FAILED_ALREADY_HAVE_SUMMON: return "SPELL_FAILED_ALREADY_HAVE_SUMMON";
            case SPELL_FAILED_ALREADY_HAVE_PET: return "SPELL_FAILED_ALREADY_HAVE_PET";
            case SPELL_FAILED_CANT_BE_CHARMED: return "SPELL_FAILED_CANT_BE_CHARMED";
            case SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE: return "SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE";
            case SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED: return "SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED";
            case SPELL_FAILED_CANT_STEALTH: return "SPELL_FAILED_CANT_STEALTH";
            case SPELL_FAILED_DISABLED_BY_POWER_SCALING: return "SPELL_FAILED_DISABLED_BY_POWER_SCALING";
            case SPELL_FAILED_DONT_REPORT: return "SPELL_FAILED_DONT_REPORT";
            case SPELL_FAILED_ERROR: return "SPELL_FAILED_ERROR";
            case SPELL_FAILED_FIZZLE: return "SPELL_FAILED_FIZZLE";
            case SPELL_FAILED_LOW_CASTLEVEL: return "SPELL_FAILED_LOW_CASTLEVEL";
            case SPELL_FAILED_MAINHAND_EMPTY: return "SPELL_FAILED_MAINHAND_EMPTY";
            case SPELL_FAILED_AUTOTRACK_INTERRUPTED: return "SPELL_FAILED_AUTOTRACK_INTERRUPTED";
            case SPELL_FAILED_BAD_IMPLICIT_TARGETS: return "SPELL_FAILED_BAD_IMPLICIT_TARGETS";
            case SPELL_FAILED_PVP_TARGET_WHILE_UNFLAGGED: return "SPELL_FAILED_PVP_TARGET_WHILE_UNFLAGGED";
            case SPELL_FAILED_CHEST_IN_USE: return "SPELL_FAILED_CHEST_IN_USE";
            case SPELL_FAILED_ALREADY_OPEN: return "SPELL_FAILED_ALREADY_OPEN";
            case SPELL_FAILED_AURA_BOUNCED: return "SPELL_FAILED_AURA_BOUNCED";
            case SPELL_FAILED_CANT_UNTALENT: return "SPELL_FAILED_CANT_UNTALENT";
            case SPELL_FAILED_FOOD_LOWLEVEL: return "SPELL_FAILED_FOOD_LOWLEVEL";
            case SPELL_FAILED_NOT_FISHABLE: return "SPELL_FAILED_NOT_FISHABLE";
            case SPELL_FAILED_NOT_FLYING: return "SPELL_FAILED_NOT_FLYING";
            case SPELL_FAILED_LEGACY_SPELL: return "SPELL_FAILED_LEGACY_SPELL";
            default: return std::to_string(result);
        }
    }
}
