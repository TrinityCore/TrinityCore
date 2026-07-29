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

#include <algorithm>
#include <vector>

#include "Containers.h"
#include "CreatureAI.h"
#include "DB2Stores.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Log.h"
#include "ThreatManager.h"

#include "Followship_bots.h"
#include "Followship_bots_config.h"
#include "Followship_bots_utils.h"
#include "Followship_bots_ai_base.h"
#include "Followship_bots_mgr.h"

#include "Followship_bots_gossip_handler.h"
#include "Followship_bots_powers_handler.h"

namespace FSBUtils
{
    const char* BotClassToString(FSB_Class cls)
    {
        switch (cls)
        {
        case FSB_Class::Warrior: return "Warrior";
        case FSB_Class::Priest:  return "Priest";
        case FSB_Class::Mage:    return "Mage";
        case FSB_Class::Rogue:   return "Rogue";
        case FSB_Class::Druid:   return "Druid";
        case FSB_Class::Paladin: return "Paladin";
        case FSB_Class::Hunter:      return "Hunter";
        case FSB_Class::Warlock:     return "Warlock";
        case FSB_Class::Shaman:      return "Shaman";
        case FSB_Class::Monk:        return "Monk";
        case FSB_Class::DeathKnight: return "Death Knight";
        default:                     return "Unknown";
        }
    }

    const char* BotRaceToString(FSB_Race race)
    {
        switch (race)
        {
        case FSB_Race::Human:    return "Human";
        case FSB_Race::Dwarf:    return "Dwarf";
        case FSB_Race::Draenei:  return "Draenei";
        case FSB_Race::NightElf: return "Night Elf";
        case FSB_Race::Gnome:    return "Gnome";
        case FSB_Race::Worgen:   return "Worgen";
        case FSB_Race::Pandaren: return "Pandaren";
        case FSB_Race::VoidElf:  return "Void Elf";
        case FSB_Race::Orc:        return "Orc";
        case FSB_Race::Undead:     return "Undead";
        case FSB_Race::Tauren:     return "Tauren";
        case FSB_Race::Troll:      return "Troll";
        case FSB_Race::BloodElf:   return "Blood Elf";
        case FSB_Race::Goblin:     return "Goblin";
        case FSB_Race::PandarenHorde: return "Pandaren (Horde)";
        case FSB_Race::HighmountainTauren:  return "Highmountain Tauren";
        case FSB_Race::Nightborne:          return "Nightborne";
        case FSB_Race::LightforgedDraenei:  return "Lightforged Draenei";
        case FSB_Race::EarthenAlliance:     return "Earthen (Alliance)";
        case FSB_Race::EarthenHorde:        return "Earthen (Horde)";
        case FSB_Race::HaranirAlliance:     return "Haranir (Alliance)";
        case FSB_Race::HaranirHorde:        return "Haranir (Horde)";
        default:                 return "Unknown";
        }
    }

    const char* BotRoleToString(FSB_Roles role)
    {
        switch (role)
        {
        case FSB_ROLE_NONE:               return "none";
        case FSB_ROLE_MELEE_DAMAGE:     return "melee damage dealer";
        case FSB_ROLE_MELEE_DAMAGE_2:   return "melee damage dealer";
        case FSB_ROLE_MELEE_DAMAGE_3:   return "melee damage dealer";
        case FSB_ROLE_RANGED_DAMAGE:    return "ranged damage dealer";
        case FSB_ROLE_HEALER:           return "healer";
        case FSB_ROLE_ASSIST:           return "support";
        case FSB_ROLE_TANK:             return "tank";
        case FSB_ROLE_RANGED_FROST:     return "frost mage";
        case FSB_ROLE_RANGED_ARCANE:    return "arcane mage";
        case FSB_ROLE_RANGED_FIRE:      return "fire mage";
        case FSB_ROLE_RANGED_AFFLICTION: return "affliction warlock";
        case FSB_ROLE_RANGED_DEMONOLOGY: return "demonology warlock";
        case FSB_ROLE_RANGED_DESTRUCTION: return "destruction warlock";
        default:                          return "unknown role";
        }
    }

    const char* ChatterTypeToString(FSB_ChatterType type)
    {
        switch (type)
        {
            case FSB_ChatterType::None:         return "no personality";
            case FSB_ChatterType::Neutral:      return "neutral and balanced";
            case FSB_ChatterType::Positive:     return "optimistic and friendly";
            case FSB_ChatterType::Negative:     return "cynical and sarcastic";
            case FSB_ChatterType::Cynical:      return "pessimistic, sarcastic, and world-weary";
            case FSB_ChatterType::Bitter:       return "resentful, grumpy, and hostile";
            case FSB_ChatterType::Cold:         return "detached, aloof, and emotionless";
            case FSB_ChatterType::Guarded:      return "distrustful, cautious, and defensive";
            case FSB_ChatterType::Serious:      return "stern, no-nonsense, and focused";
            case FSB_ChatterType::Dry:          return "deadpan, understated humor";
            case FSB_ChatterType::Curious:      return "inquisitive, asks questions, and open";
            case FSB_ChatterType::Warm:         return "friendly, approachable, and kind";
            case FSB_ChatterType::Enthusiastic:  return "excited, energetic, and optimistic";
            case FSB_ChatterType::Cheerful:     return "always upbeat, tries to lift spirits";
            case FSB_ChatterType::Devoted:      return "loyal, deeply caring, and protective";
            case FSB_ChatterType::Morbid:       return "survivalist, thrill-seeking, loves gore";
            case FSB_ChatterType::Narcissist:   return "self-centered, in love with themselves, oblivious";
            case FSB_ChatterType::Sadist:       return "cruel, humiliating, enjoys suffering";
            case FSB_ChatterType::Hyperthymic:   return "overly optimistic, high energy, highly extroverted";
            case FSB_ChatterType::Autotelic:    return "internally motivated, selfless, and autonomous";
            case FSB_ChatterType::Autistic:     return "over-analyzes, intense empathy, extreme emotional responses";
            default:                            return "mysterious";
        }
    }

    const char* GenderToString(Gender gender)
    {
        switch (gender)
        {
            case GENDER_MALE:   return "male";
            case GENDER_FEMALE: return "female";
            default:            return "unknown gender";
        }
    }

    Races BotRaceToTC(FSB_Race race)
    {
        switch (race)
        {
        case FSB_Race::Human:    return RACE_HUMAN;
        case FSB_Race::Dwarf:    return RACE_DWARF;
        case FSB_Race::Draenei:  return RACE_DRAENEI;
        case FSB_Race::NightElf: return RACE_NIGHTELF;
        case FSB_Race::Gnome:    return RACE_GNOME;
        case FSB_Race::Worgen:   return RACE_WORGEN;
        case FSB_Race::Pandaren: return RACE_PANDAREN_ALLIANCE;
        case FSB_Race::VoidElf:  return RACE_VOID_ELF;
        case FSB_Race::Orc:        return RACE_ORC;
        case FSB_Race::Undead:     return RACE_UNDEAD_PLAYER;
        case FSB_Race::Tauren:     return RACE_TAUREN;
        case FSB_Race::Troll:      return RACE_TROLL;
        case FSB_Race::BloodElf:   return RACE_BLOODELF;
        case FSB_Race::Goblin:     return RACE_GOBLIN;
        case FSB_Race::PandarenHorde: return RACE_PANDAREN_HORDE;
        case FSB_Race::HighmountainTauren:  return RACE_HIGHMOUNTAIN_TAUREN;
        case FSB_Race::Nightborne:          return RACE_NIGHTBORNE;
        case FSB_Race::LightforgedDraenei:  return RACE_LIGHTFORGED_DRAENEI;
        case FSB_Race::EarthenAlliance:     return RACE_EARTHEN_DWARF_ALLIANCE;
        case FSB_Race::EarthenHorde:        return RACE_EARTHEN_DWARF_HORDE;
        case FSB_Race::HaranirAlliance:     return RACE_HARANIR_ALLIANCE;
        case FSB_Race::HaranirHorde:        return RACE_HARANIR_HORDE;
        default:
            TC_LOG_WARN("scripts.ai.fsb", "FSB Utils BotRaceToTC has no mapping for race {}", race);
            return RACE_NONE;
        }
    }

    Team GetTeamFromFSBRace(FSB_Race race)
    {
        switch (race)
        {
            case FSB_Race::Human:
            case FSB_Race::Dwarf:
            case FSB_Race::NightElf:
            case FSB_Race::Gnome:
            case FSB_Race::Draenei:
            case FSB_Race::Worgen:
            case FSB_Race::Pandaren:
            case FSB_Race::VoidElf:
            case FSB_Race::HighmountainTauren:
            case FSB_Race::Nightborne:
            case FSB_Race::LightforgedDraenei:
            case FSB_Race::EarthenAlliance:
            case FSB_Race::HaranirAlliance:
                return Team::ALLIANCE;

            case FSB_Race::Orc:
            case FSB_Race::Undead:
            case FSB_Race::Tauren:
            case FSB_Race::Troll:
            case FSB_Race::BloodElf:
            case FSB_Race::Goblin:
            case FSB_Race::PandarenHorde:
            case FSB_Race::EarthenHorde:
            case FSB_Race::HaranirHorde:
                return Team::HORDE;

            default:
                TC_LOG_WARN("scripts.fsb.general", "GetTeamFromFSBRace: Unknown or unsupported FSB race {}. Defaulting to NEUTRAL.", uint8(race));
                return Team::PANDARIA_NEUTRAL;
        }
    }

    uint32 GetFactionForFSBRace(FSB_Race race)
    {
        Races tcRace = BotRaceToTC(race);
        if (tcRace == RACE_NONE)
        {
            TC_LOG_WARN("scripts.fsb.general", "GetFactionForFSBRace: Unknown FSB race {}. Defaulting to Human faction.", uint8(race));
            tcRace = RACE_HUMAN;
        }

        if (ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(tcRace))
            return rEntry->FactionID;

        return 0;
    }

    Language GetLanguageForFSBRace(FSB_Race race)
    {
        switch (race)
        {
        case FSB_Race::Human:               return LANG_COMMON;
        case FSB_Race::Dwarf:               return LANG_DWARVISH;
        case FSB_Race::NightElf:            return LANG_DARNASSIAN;
        case FSB_Race::Gnome:               return LANG_GNOMISH;
        case FSB_Race::Draenei:             return LANG_DRAENEI;
        case FSB_Race::Worgen:              return LANG_COMMON;
        case FSB_Race::Pandaren:            return LANG_COMMON;
        case FSB_Race::VoidElf:             return LANG_THALASSIAN;
        case FSB_Race::Orc:                 return LANG_ORCISH;
        case FSB_Race::Undead:              return LANG_GUTTERSPEAK;
        case FSB_Race::Tauren:              return LANG_TAURAHE;
        case FSB_Race::Troll:               return LANG_TROLL;
        case FSB_Race::BloodElf:            return LANG_THALASSIAN;
        case FSB_Race::Goblin:              return LANG_GOBLIN;
        case FSB_Race::PandarenHorde:       return LANG_ORCISH;
        case FSB_Race::HighmountainTauren:  return LANG_TAURAHE;
        case FSB_Race::Nightborne:          return LANG_SHALASSIAN;
        case FSB_Race::LightforgedDraenei:  return LANG_DRAENEI;
        case FSB_Race::EarthenAlliance:     return LANG_EARTHEN;
        case FSB_Race::EarthenHorde:        return LANG_EARTHEN;
        case FSB_Race::HaranirAlliance:     return LANG_HARANI;
        case FSB_Race::HaranirHorde:        return LANG_HARANI;
        default:                            return LANG_UNIVERSAL;
        }
    }

    Language GetTeamLanguageForFSBRace(FSB_Race race)
    {
        Team team = GetTeamFromFSBRace(race);
        if (team == ALLIANCE) return LANG_COMMON;
        if (team == HORDE)    return LANG_ORCISH;
        return LANG_UNIVERSAL;
    }

    const char* PowerTypeToString(Powers power)
    {
        switch (power)
        {
        case POWER_MANA:   return "Mana";
        case POWER_RAGE:   return "Rage";
        case POWER_ENERGY: return "Energy";
        case POWER_FOCUS:  return "Focus";
        case POWER_HOLY_POWER: return "Holy";
        case POWER_SOUL_SHARDS:return "Sould Shards";
        case POWER_CHI:    return "Chi";
        default:           return "Other";
        }
    }

    Classes FSBToTCClass(FSB_Class botClass)
    {
        switch (botClass)
        {
        case FSB_Class::Warrior:            return CLASS_WARRIOR;
        case FSB_Class::Priest:             return CLASS_PRIEST;
        case FSB_Class::Mage:               return CLASS_MAGE;
        case FSB_Class::Rogue:              return CLASS_ROGUE;
        case FSB_Class::Druid:              return CLASS_DRUID;
        case FSB_Class::Paladin:            return CLASS_PALADIN;
        case FSB_Class::Hunter:             return CLASS_HUNTER;
        case FSB_Class::Warlock:            return CLASS_WARLOCK;
        case FSB_Class::Shaman:             return CLASS_SHAMAN;
        case FSB_Class::Monk:               return CLASS_MONK;
        case FSB_Class::None:               return CLASS_NONE;
        default:
            break;
        }

        return CLASS_NONE;
    }


    float GetRandomLeftAngle()
    {
        // Base left is +90 degrees (M_PI/2)
        // Add a random small offset for natural variation
        return (M_PI / 2.0f) + frand(-SIDE_OFFSET_MAX, SIDE_OFFSET_MAX);
    }

    float GetRandomRightAngle()
    {
        // Base right is -90 degrees (-M_PI/2)
        // Add a random small offset for natural variation
        return (-M_PI / 2.0f) + frand(-SIDE_OFFSET_MAX, SIDE_OFFSET_MAX);
    }

    bool TryChargeHire(Player* player, uint32 duration)
    {
        uint32 pLevel = player->GetLevel();

        int64 price = int64(FollowshipBotsConfig::configFSBPricePerLevel) * pLevel * duration;

        if (!player->HasEnoughMoney(price))
        {
            player->GetSession()->SendNotification(FSB_PLAYER_NOTIFICATION_PAYMENT_FAIL);
            return false;
        }

        player->ModifyMoney(-price);
        player->GetSession()->SendNotification(FSB_PLAYER_NOTIFICATION_PAYMENT_SUCCESS);
        return true;
    }

    bool BotIsHealerClass(Creature* bot)
    {
        if (!bot)
            return false;

        FSB_Class cls = FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry());

        if (cls == FSB_Class::Priest || cls == FSB_Class::Druid || cls == FSB_Class::Paladin || cls == FSB_Class::Shaman || cls == FSB_Class::Monk)
            return true;

        return false;
    }

    bool BotIsCasterRole(Creature* bot)
    {
        if (!bot)
            return false;

        FSB_Roles role = FSBMgr::Get()->GetRole(bot);

        return role == FSB_ROLE_RANGED_ARCANE ||
            role == FSB_ROLE_RANGED_FIRE ||
            role == FSB_ROLE_RANGED_FROST ||
            role == FSB_ROLE_RANGED_DAMAGE ||
            role == FSB_ROLE_RANGED_DESTRUCTION ||
            role == FSB_ROLE_RANGED_AFFLICTION ||
            role == FSB_ROLE_RANGED_DEMONOLOGY ||
            role == FSB_ROLE_ASSIST ||
            role == FSB_ROLE_HEALER;
    }

    Unit* FindCreatureByName(WorldObject* bot, std::string name, float range)
    {
        if (!bot)
            return nullptr;

        // Replace underscores with spaces
        std::replace(name.begin(), name.end(), '_', ' ');

        // Optional: lowercase for case-insensitive matching
        std::string searchName = name;
        std::transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);

        std::list<WorldObject*> nearbyObjects;

        Trinity::AllWorldObjectsInRange checker(bot, range);
        Trinity::WorldObjectListSearcher<Trinity::AllWorldObjectsInRange> searcher(bot, nearbyObjects, checker);

        Cell::VisitAllObjects(bot, searcher, range);
        for (WorldObject* object : nearbyObjects)
        {
            if (!object)
                continue;

            Unit* c = object->ToUnit();
            if (!c)
                continue;

            // Lowercase creature name for comparison
            std::string creatureName = c->GetName();
            std::transform(creatureName.begin(), creatureName.end(), creatureName.begin(), ::tolower);

            if (creatureName == searchName)
                return c;
        }


        return nullptr;
    }

    std::vector<Creature*> FindNearbyBots(Creature* center, float radius)
    {
        std::vector<Creature*> result;

        Trinity::AnyUnitInObjectRangeCheck checker(center, radius);
        Trinity::CreatureListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(center, result, checker);

        Cell::VisitAllObjects(center, searcher, radius);

        // Filter only your bot entries
        result.erase(
            std::remove_if(result.begin(), result.end(),
                [center](Creature* c)
                {
                    return c == center || !c->IsAlive() || dynamic_cast<FSB_BaseAI*>(c->AI()) == nullptr;
                }),
            result.end()
        );

        return result;
    }

    bool IsBotInTradeCity(Creature* bot)
    {
        if (!bot)
            return false;

        uint32 zoneId = bot->GetZoneId();

        switch (zoneId)
        {
        case 1519:  // Stormwind City
        case 1537:  // Ironforge
        case 1657:  // Darnassus
        case 3557:  // The Exodar
        case 1637:  // Orgrimmar
        case 1638:  // Thunder Bluff
        case 1497:  // Undercity
        case 3487:  // Silvermoon City
            return true;

        default:
            return false;
        }
    }

    std::string WeatherStateToText(WeatherState state)
    {
        switch (state)
        {
            case WEATHER_STATE_FOG:               return "foggy";
            case WEATHER_STATE_DRIZZLE:           return "drizzling";
            case WEATHER_STATE_LIGHT_RAIN:        return "light rain";
            case WEATHER_STATE_MEDIUM_RAIN:       return "rain";
            case WEATHER_STATE_HEAVY_RAIN:        return "heavy rain";
            case WEATHER_STATE_LIGHT_SNOW:        return "light snow";
            case WEATHER_STATE_MEDIUM_SNOW:       return "snow";
            case WEATHER_STATE_HEAVY_SNOW:        return "heavy snow";
            case WEATHER_STATE_LIGHT_SANDSTORM:   return "light sandstorm";
            case WEATHER_STATE_MEDIUM_SANDSTORM:  return "sandstorm";
            case WEATHER_STATE_HEAVY_SANDSTORM:   return "heavy sandstorm";
            case WEATHER_STATE_THUNDERS:          return "thunderstorm";
            case WEATHER_STATE_BLACKRAIN:         return "black rain";
            case WEATHER_STATE_BLACKSNOW:         return "black snow";
            case WEATHER_STATE_FINE:
            default:                              return "clear";
        }
    }
}

