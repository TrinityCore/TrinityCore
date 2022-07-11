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

#include "ScriptMgr.h"
#include "Battleground.h"
#include "BattlePetMgr.h"
#include "Creature.h"
#include "Player.h"
#include "WorldSession.h"

class achievement_arena_kills : public AchievementCriteriaScript
{
    public:
        achievement_arena_kills(char const* name, uint8 arenaType) : AchievementCriteriaScript(name),
            _arenaType(arenaType)
        {
        }

        bool OnCheck(Player* source, Unit* /*target*/) override
        {
            // this checks GetBattleground() for NULL already
            if (!source->InArena())
                return false;

            return ASSERT_NOTNULL(source->GetBattleground())->GetArenaType() == _arenaType;
        }

    private:
        uint8 const _arenaType;
};

enum ArgentTournamentAreas
{
    AREA_ARGENT_TOURNAMENT_FIELDS  = 4658,
    AREA_RING_OF_ASPIRANTS         = 4670,
    AREA_RING_OF_ARGENT_VALIANTS   = 4671,
    AREA_RING_OF_ALLIANCE_VALIANTS = 4672,
    AREA_RING_OF_HORDE_VALIANTS    = 4673,
    AREA_RING_OF_CHAMPIONS         = 4669,
};

class achievement_tilted : public AchievementCriteriaScript
{
    public:
        achievement_tilted() : AchievementCriteriaScript("achievement_tilted") { }

        bool OnCheck(Player* player, Unit* /*target*/) override
        {
            if (!player)
                return false;

            bool checkArea = player->GetAreaId() == AREA_ARGENT_TOURNAMENT_FIELDS ||
                                player->GetAreaId() == AREA_RING_OF_ASPIRANTS ||
                                player->GetAreaId() == AREA_RING_OF_ARGENT_VALIANTS ||
                                player->GetAreaId() == AREA_RING_OF_ALLIANCE_VALIANTS ||
                                player->GetAreaId() == AREA_RING_OF_HORDE_VALIANTS ||
                                player->GetAreaId() == AREA_RING_OF_CHAMPIONS;

            return checkArea && player->duel && player->duel->IsMounted;
        }
};

enum FlirtWithDisaster
{
    AURA_PERFUME_FOREVER           = 70235,
    AURA_PERFUME_ENCHANTRESS       = 70234,
    AURA_PERFUME_VICTORY           = 70233,
};

class achievement_flirt_with_disaster_perf_check : public AchievementCriteriaScript
{
    public:
        achievement_flirt_with_disaster_perf_check() : AchievementCriteriaScript("achievement_flirt_with_disaster_perf_check") { }

        bool OnCheck(Player* player, Unit* /*target*/) override
        {
            if (!player)
                return false;

            if (player->HasAura(AURA_PERFUME_FOREVER) || player->HasAura(AURA_PERFUME_ENCHANTRESS) || player->HasAura(AURA_PERFUME_VICTORY))
                return true;

            return false;
        }
};

class achievement_killed_exp_or_honor_target : public AchievementCriteriaScript
{
    public:
        achievement_killed_exp_or_honor_target() : AchievementCriteriaScript("achievement_killed_exp_or_honor_target") { }

        bool OnCheck(Player* player, Unit* target) override
        {
            return target && player->isHonorOrXPTarget(target);
        }
};

// 7433 - Newbie
class achievement_newbie : public AchievementScript
{
public:
    achievement_newbie() : AchievementScript("achievement_newbie") { }

    void OnCompleted(Player* player, AchievementEntry const* /*achievement*/) override
    {
        player->GetSession()->GetBattlePetMgr()->UnlockSlot(BattlePets::BattlePetSlot::Slot1);
        // TODO: Unlock trap
    }
};

// 6566 - Just a Pup
class achievement_just_a_pup : public AchievementScript
{
public:
    achievement_just_a_pup() : AchievementScript("achievement_just_a_pup") { }

    void OnCompleted(Player* player, AchievementEntry const* /*achievement*/) override
    {
        player->GetSession()->GetBattlePetMgr()->UnlockSlot(BattlePets::BattlePetSlot::Slot2);
    }
};

void AddSC_achievement_scripts()
{
    new achievement_arena_kills("achievement_arena_2v2_kills", ARENA_TYPE_2v2);
    new achievement_arena_kills("achievement_arena_3v3_kills", ARENA_TYPE_3v3);
    new achievement_arena_kills("achievement_arena_5v5_kills", ARENA_TYPE_5v5);
    new achievement_tilted();
    new achievement_flirt_with_disaster_perf_check();
    new achievement_killed_exp_or_honor_target();
    new achievement_newbie();
    new achievement_just_a_pup();
}
