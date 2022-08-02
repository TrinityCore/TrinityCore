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

#ifndef TRINITY_FORMULAS_H
#define TRINITY_FORMULAS_H

// @tswow-begin
#include "TSPlayer.h"
#include "TSMutable.h"
#include "TSEvents.h"
#include "TSCreature.h"
#include "CreatureData.h"
// @tswow-end
#include "DBCStores.h"
#include "Creature.h"
#include "Log.h"
#include "Map.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"
#include "World.h"

namespace Trinity
{
    namespace Honor
    {
        inline float hk_honor_at_level_f(uint8 level, float multiplier = 1.0f)
        {
            float honor = multiplier * level * 1.55f;
            sScriptMgr->OnHonorCalculation(honor, level, multiplier);
            FIRE(World,OnCalcHonor, TSMutableNumber<float>(&honor), level, multiplier);
            return honor;
        }

        inline uint32 hk_honor_at_level(uint8 level, float multiplier = 1.0f)
        {
            return uint32(ceil(hk_honor_at_level_f(level, multiplier)));
        }
    } // namespace Trinity::Honor

    namespace XP
    {
        // @tswow-begin add player argument
        inline uint8 GetGrayLevel(Player* player, uint8 pl_level)
        // @tswow-end
        {
            uint8 level;

            if (pl_level <= 5)
                level = 0;
            else if (pl_level <= 39)
                level = pl_level - 5 - pl_level / 10;
            else if (pl_level <= 59)
                level = pl_level - 1 - pl_level / 5;
            else
                level = pl_level - 9;

            sScriptMgr->OnGrayLevelCalculation(level, pl_level);
            // @tswow-begin
            FIRE(
                  Player,OnCalcGreyLevel
                , TSPlayer(player)
                , TSMutableNumber<uint8>(&level)
                );
            // @tswow-end
            return level;
        }

        // @tswow-begin player/creature arguments
        inline XPColorChar GetColorCode(Player* player, Creature* creature, uint8 pl_level, uint8 mob_level)
        // @tswow-end
        {
            XPColorChar color;

            if (mob_level >= pl_level + 5)
                color = XP_RED;
            else if (mob_level >= pl_level + 3)
                color = XP_ORANGE;
            else if (mob_level >= pl_level - 2)
                color = XP_YELLOW;
            // @tswow-begin player argument
            else if (mob_level > GetGrayLevel(player, pl_level))
            // @tswow-end
                color = XP_GREEN;
            else
                color = XP_GRAY;

            sScriptMgr->OnColorCodeCalculation(color, pl_level, mob_level);
            // @tswow-begin
            FIRE_ID(
                  creature->GetCreatureTemplate()->events.id
                , Creature,OnCalcColorCode
                , TSCreature(creature)
                , TSMutableNumber<uint8>((uint8*)(&color))
                , TSPlayer(player)
                , pl_level
                , mob_level
            )
            // @tswow-end
            return color;
        }

        // @tswow-begin
        inline uint8 GetZeroDifference(Player* player, uint8 pl_level)
        // @tswow-end
        {
            uint8 diff;

            if (pl_level < 8)
                diff = 5;
            else if (pl_level < 10)
                diff = 6;
            else if (pl_level < 12)
                diff = 7;
            else if (pl_level < 16)
                diff = 8;
            else if (pl_level < 20)
                diff = 9;
            else if (pl_level < 30)
                diff = 11;
            else if (pl_level < 40)
                diff = 12;
            else if (pl_level < 45)
                diff = 13;
            else if (pl_level < 50)
                diff = 14;
            else if (pl_level < 55)
                diff = 15;
            else if (pl_level < 60)
                diff = 16;
            else
                diff = 17;

            sScriptMgr->OnZeroDifferenceCalculation(diff, pl_level);
            FIRE(Player,OnCalcZeroDiff
                , TSPlayer(player)
                , TSMutableNumber<uint8>(&diff)
            );
            return diff;
        }

        // @tswow-begin player/creature arguments
        inline uint32 BaseGain(Player* player, Creature* creature, uint8 pl_level, uint8 mob_level, ContentLevels content)
        // @tswow-end
        {
            uint32 baseGain;
            uint32 nBaseExp;

            switch (content)
            {
                case CONTENT_1_60:
                    nBaseExp = 45;
                    break;
                case CONTENT_61_70:
                    nBaseExp = 235;
                    break;
                case CONTENT_71_80:
                    nBaseExp = 580;
                    break;
                default:
                    TC_LOG_ERROR("misc", "BaseGain: Unsupported content level %u", content);
                    nBaseExp = 45;
                    break;
            }

            if (mob_level >= pl_level)
            {
                uint8 nLevelDiff = mob_level - pl_level;
                if (nLevelDiff > 4)
                    nLevelDiff = 4;

                baseGain = ((pl_level * 5 + nBaseExp) * (20 + nLevelDiff) / 10 + 1) / 2;
            }
            else
            {
                // @tswow-begin player argument
                uint8 gray_level = GetGrayLevel(player, pl_level);
                // @tswow-end
                if (mob_level > gray_level)
                {
                    // @tswow-begin player argument
                    uint8 ZD = GetZeroDifference(player,pl_level);
                    // @tswow-end
                    baseGain = (pl_level * 5 + nBaseExp) * (ZD + mob_level - pl_level) / ZD;
                }
                else
                    baseGain = 0;
            }

            if (sWorld->getIntConfig(CONFIG_MIN_CREATURE_SCALED_XP_RATIO))
            {
                // Use mob level instead of player level to avoid overscaling on gain in a min is enforced
                uint32 baseGainMin = (mob_level * 5 + nBaseExp) * sWorld->getIntConfig(CONFIG_MIN_CREATURE_SCALED_XP_RATIO) / 100;
                baseGain = std::max(baseGainMin, baseGain);
            }

            // @tswow-begin
            FIRE_ID(
                  creature->GetCreatureTemplate()->events.id
                , Creature,OnCalcBaseGain
                , TSCreature(creature)
                , TSMutableNumber<uint32>(&baseGain)
                , TSPlayer(player)
            );
            // @tswow-end
            sScriptMgr->OnBaseGainCalculation(baseGain, pl_level, mob_level, content);
            return baseGain;
        }

        inline uint32 Gain(Player* player, Unit* u, bool isBattleGround = false)
        {
            Creature* creature = u->ToCreature();
            uint32 gain = 0;

            if (!creature || creature->CanGiveExperience())
            {
                float xpMod = 1.0f;

                // @tswow-begin player/creature arguments
                gain = BaseGain(player, creature, player->GetLevel(), u->GetLevel(), GetContentLevelsForMapAndZone(u->GetMapId(), u->GetZoneId()));
                // @tswow-end

                if (gain && creature)
                {
                    if (creature->isElite())
                    {
                        // Elites in instances have a 2.75x XP bonus instead of the regular 2x world bonus.
                        if (u->GetMap()->IsDungeon())
                            xpMod *= 2.75f;
                        else
                            xpMod *= 2.0f;
                    }

                    xpMod *= creature->GetCreatureTemplate()->ModExperience;
                }

                xpMod *= isBattleGround ? sWorld->getRate(RATE_XP_BG_KILL) : sWorld->getRate(RATE_XP_KILL);
                if (creature && creature->m_PlayerDamageReq) // if players dealt less than 50% of the damage and were credited anyway (due to CREATURE_FLAG_EXTRA_NO_PLAYER_DAMAGE_REQ), scale XP gained appropriately (linear scaling)
                    xpMod *= 1.0f - 2.0f * creature->m_PlayerDamageReq / creature->GetMaxHealth();

                gain = uint32(gain * xpMod);
            }

            sScriptMgr->OnGainCalculation(gain, player, u);
            // @tswow-begin
            FIRE_ID(
                creature->GetCreatureTemplate()->events.id
                , Creature,OnCalcGain
                , TSCreature(creature)
                , TSMutableNumber<uint32>(&gain)
                , TSPlayer(player)
            );
            // @tswow-end
            return gain;
        }

        // @tswow-begin player argument
        inline float xp_in_group_rate(Player* player, uint32 count, bool isRaid)
        // @tswow-end
        {
            float rate;

            if (isRaid)
            {
                // FIXME: Must apply decrease modifiers depending on raid size.
                rate = 1.0f;
            }
            else
            {
                switch (count)
                {
                    case 0:
                    case 1:
                    case 2:
                        rate = 1.0f;
                        break;
                    case 3:
                        rate = 1.166f;
                        break;
                    case 4:
                        rate = 1.3f;
                        break;
                    case 5:
                    default:
                        rate = 1.4f;
                }
            }

            sScriptMgr->OnGroupRateCalculation(rate, count, isRaid);
            // @tswow-begin
            FIRE(
                  Player,OnCalcGroupGain
                , TSPlayer(player)
                , TSMutableNumber<float>(&rate)
                , count
                , isRaid
            );
            return rate;
        }
    } // namespace Trinity::XP
} // namespace Trinity

#endif
