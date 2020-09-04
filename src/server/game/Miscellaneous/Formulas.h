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

#include "Creature.h"
#include "GameTables.h"
#include "Map.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"
#include "World.h"

namespace Trinity
{
    inline uint32 GetExpansionForLevel(uint32 level)
    {
        if (level < 60)
            return EXPANSION_CLASSIC;
        else if (level < 70)
            return EXPANSION_THE_BURNING_CRUSADE;
        else if (level < 80)
            return EXPANSION_WRATH_OF_THE_LICH_KING;
        else if (level < 85)
            return EXPANSION_CATACLYSM;
        else if (level < 90)
            return EXPANSION_MISTS_OF_PANDARIA;
        else if (level < 100)
            return EXPANSION_WARLORDS_OF_DRAENOR;
        else
            return CURRENT_EXPANSION;
    }

    namespace Honor
    {
        inline float hk_honor_at_level_f(uint8 level, float multiplier = 1.0f)
        {
            float honor = multiplier * level * 1.55f;
            sScriptMgr->OnHonorCalculation(honor, level, multiplier);
            return honor;
        }

        inline uint32 hk_honor_at_level(uint8 level, float multiplier = 1.0f)
        {
            return uint32(ceil(hk_honor_at_level_f(level, multiplier)));
        }
    } // namespace Trinity::Honor

    namespace XP
    {
        inline uint8 GetGrayLevel(uint8 pl_level)
        {
            uint8 level;

            if (pl_level < 7)
                level = 0;
            else if (pl_level < 35)
            {
                uint8 count = 0;
                for (int i = 15; i <= pl_level; ++i)
                    if (i % 5 == 0) ++count;

                level = (pl_level - 7) - (count - 1);
            }
            else
                level = pl_level - 10;

            sScriptMgr->OnGrayLevelCalculation(level, pl_level);
            return level;
        }

        inline XPColorChar GetColorCode(uint8 pl_level, uint8 mob_level)
        {
            XPColorChar color;

            if (mob_level >= pl_level + 5)
                color = XP_RED;
            else if (mob_level >= pl_level + 3)
                color = XP_ORANGE;
            else if (mob_level >= pl_level - 2)
                color = XP_YELLOW;
            else if (mob_level > GetGrayLevel(pl_level))
                color = XP_GREEN;
            else
                color = XP_GRAY;

            sScriptMgr->OnColorCodeCalculation(color, pl_level, mob_level);
            return color;
        }

        inline uint8 GetZeroDifference(uint8 pl_level)
        {
            uint8 diff;

            if (pl_level < 4)
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
            return diff;
        }

        inline uint32 BaseGain(uint8 pl_level, uint8 mob_level)
        {
            uint32 baseGain;

            GtXpEntry const* xpPlayer = sXpGameTable.GetRow(pl_level);
            GtXpEntry const* xpMob = sXpGameTable.GetRow(mob_level);

            if (mob_level >= pl_level)
            {
                uint8 nLevelDiff = mob_level - pl_level;
                if (nLevelDiff > 4)
                    nLevelDiff = 4;

                baseGain = uint32(round(xpPlayer->PerKill * (1 + 0.05f * nLevelDiff)));
            }
            else
            {
                uint8 gray_level = GetGrayLevel(pl_level);
                if (mob_level > gray_level)
                {
                    uint8 ZD = GetZeroDifference(pl_level);
                    baseGain = uint32(round(xpMob->PerKill * ((1 - ((pl_level - mob_level) / float(ZD))) * (xpMob->Divisor / xpPlayer->Divisor))));
                }
                else
                    baseGain = 0;
            }

            sScriptMgr->OnBaseGainCalculation(baseGain, pl_level, mob_level);
            return baseGain;
        }

        inline uint32 Gain(Player* player, Unit* u, bool isBattleGround = false)
        {
            Creature* creature = u->ToCreature();
            uint32 gain = 0;

            if (!creature || creature->CanGiveExperience())
            {
                float xpMod = 1.0f;

                gain = BaseGain(player->getLevel(), u->GetLevelForTarget(player));

                if (gain && creature)
                {
                    // Players get only 10% xp for killing creatures of lower expansion levels than himself
                    if ((uint32(creature->GetCreatureTemplate()->GetHealthScalingExpansion()) < GetExpansionForLevel(player->getLevel())))
                        gain = uint32(round(gain / 10.0f));

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
            return gain;
        }

        inline float xp_in_group_rate(uint32 count, bool isRaid)
        {
            float rate;

            if (isRaid)
            {
                // FIXME: Must apply decrease modifiers depending on raid size.
                // set to < 1 to, so client will display raid related strings
                rate = 0.99f;
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
            return rate;
        }
    } // namespace Trinity::XP

    namespace Currency
    {
        inline uint32 ConquestRatingCalculator(uint32 rate)
        {
            if (rate <= 1500)
                return 1350; // Default conquest points
            else if (rate > 3000)
                rate = 3000;

            // http://www.arenajunkies.com/topic/179536-conquest-point-cap-vs-personal-rating-chart/page__st__60#entry3085246
            return uint32(1.4326 * ((1511.26 / (1 + 1639.28 / exp(0.00412 * rate))) + 850.15));
        }

        inline uint32 BgConquestRatingCalculator(uint32 rate)
        {
            // WowWiki: Battleground ratings receive a bonus of 22.2% to the cap they generate
            return uint32((ConquestRatingCalculator(rate) * 1.222f) + 0.5f);
        }
    } // namespace Trinity::Currency
} // namespace Trinity

#endif
