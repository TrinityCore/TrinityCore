/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "World.h"
#include "SharedDefines.h"
#include "ScriptMgr.h"
#include "Player.h"

namespace Trinity
{
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

            GtOCTLevelExperienceEntry const* BaseExpPlayer = sGtOCTLevelExperienceStore.EvaluateTable(pl_level - 1, 1);
            GtOCTLevelExperienceEntry const* BaseExpMob = sGtOCTLevelExperienceStore.EvaluateTable(mob_level - 1, 1);

            GtOCTLevelExperienceEntry const* CoefPlayer = sGtOCTLevelExperienceStore.EvaluateTable(pl_level - 1, 4);
            GtOCTLevelExperienceEntry const* CoefMob = sGtOCTLevelExperienceStore.EvaluateTable(mob_level - 1, 4);

            if (mob_level >= pl_level)
            {
                uint8 nLevelDiff = mob_level - pl_level;
                if (nLevelDiff > 4)
                    nLevelDiff = 4;

                baseGain = uint32(round(BaseExpPlayer->Data * (1 + 0.05f * nLevelDiff)));
            }
            else
            {
                uint8 gray_level = GetGrayLevel(pl_level);
                if (mob_level > gray_level)
                {
                    uint8 ZD = GetZeroDifference(pl_level);
                    baseGain = uint32(round(BaseExpMob->Data * ((1 - ((pl_level - mob_level) / float(ZD))) * (CoefMob->Data / CoefPlayer->Data))));
                }
                else
                    baseGain = 0;
            }

            sScriptMgr->OnBaseGainCalculation(baseGain, pl_level, mob_level);
            return baseGain;
        }

        inline uint32 Gain(Player* player, Unit* u)
        {
            Creature* creature = u->ToCreature();
            uint32 gain = 0;

            if (!creature || (!creature->IsTotem() && !creature->IsPet() && !creature->IsCritter() &&
                !(creature->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_XP_AT_KILL)))
            {
                float xpMod = 1.0f;

                gain = BaseGain(player->getLevel(), u->getLevel());

                if (gain && creature)
                {
                    // Players get only 10% xp for killing creatures of lower expansion levels than himself
                    if ((uint32(creature->GetCreatureTemplate()->expansion) < GetExpansionForLevel(player->getLevel())))
                        gain = uint32(round(gain / 10.0f));

                    if (creature->isElite())
                    {
                        // Elites in instances have a 2.75x XP bonus instead of the regular 2x world bonus.
                        if (u->GetMap() && u->GetMap()->IsDungeon())
                            xpMod *= 2.75f;
                        else
                            xpMod *= 2.0f;
                    }

                    xpMod *= creature->GetCreatureTemplate()->ModExperience;
                }

                xpMod *= sWorld->getRate(RATE_XP_KILL);
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
