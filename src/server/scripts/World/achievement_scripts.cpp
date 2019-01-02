/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "BattlegroundSA.h"
#include "BattlegroundIC.h"
#include "Vehicle.h"
#include "Player.h"
#include "Creature.h"

class achievement_resilient_victory : public AchievementCriteriaScript
{
    public:
        achievement_resilient_victory() : AchievementCriteriaScript("achievement_resilient_victory") { }

        bool OnCheck(Player* source, Unit* target) override
        {
            if (Battleground* bg = source->GetBattleground())
                return bg->CheckAchievementCriteriaMeet(BG_CRITERIA_CHECK_RESILIENT_VICTORY, source, target);

            return false;
        }
};

class achievement_bg_control_all_nodes : public AchievementCriteriaScript
{
    public:
        achievement_bg_control_all_nodes() : AchievementCriteriaScript("achievement_bg_control_all_nodes") { }

        bool OnCheck(Player* source, Unit* /*target*/) override
        {
            if (Battleground* bg = source->GetBattleground())
                return bg->IsAllNodesControlledByTeam(source->GetTeam());

            return false;
        }
};

class achievement_save_the_day : public AchievementCriteriaScript
{
    public:
        achievement_save_the_day() : AchievementCriteriaScript("achievement_save_the_day") { }

        bool OnCheck(Player* source, Unit* target) override
        {
            if (Battleground* bg = source->GetBattleground())
                return bg->CheckAchievementCriteriaMeet(BG_CRITERIA_CHECK_SAVE_THE_DAY, source, target);

            return false;
        }
};

class achievement_bg_ic_resource_glut : public AchievementCriteriaScript
{
    public:
        achievement_bg_ic_resource_glut() : AchievementCriteriaScript("achievement_bg_ic_resource_glut") { }

        bool OnCheck(Player* source, Unit* /*target*/) override
        {
            if (source->HasAura(SPELL_OIL_REFINERY) && source->HasAura(SPELL_QUARRY))
                return true;

            return false;
        }
};

class achievement_bg_ic_glaive_grave : public AchievementCriteriaScript
{
    public:
        achievement_bg_ic_glaive_grave() : AchievementCriteriaScript("achievement_bg_ic_glaive_grave") { }

        bool OnCheck(Player* source, Unit* /*target*/) override
        {
            if (Creature* vehicle = source->GetVehicleCreatureBase())
            {
                if (vehicle->GetEntry() == NPC_GLAIVE_THROWER_H ||  vehicle->GetEntry() == NPC_GLAIVE_THROWER_A)
                    return true;
            }

            return false;
        }
};

class achievement_bg_ic_mowed_down : public AchievementCriteriaScript
{
    public:
        achievement_bg_ic_mowed_down() : AchievementCriteriaScript("achievement_bg_ic_mowed_down") { }

        bool OnCheck(Player* source, Unit* /*target*/) override
        {
            if (Creature* vehicle = source->GetVehicleCreatureBase())
            {
                if (vehicle->GetEntry() == NPC_KEEP_CANNON)
                    return true;
            }

            return false;
        }
};

class achievement_bg_sa_artillery : public AchievementCriteriaScript
{
    public:
        achievement_bg_sa_artillery() : AchievementCriteriaScript("achievement_bg_sa_artillery") { }

        bool OnCheck(Player* source, Unit* /*target*/) override
        {
            if (Creature* vehicle = source->GetVehicleCreatureBase())
            {
                if (vehicle->GetEntry() == NPC_ANTI_PERSONNAL_CANNON)
                    return true;
            }

            return false;
        }
};

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

            return source->GetBattleground()->GetArenaType() == _arenaType;
        }

    private:
        uint8 const _arenaType;
};

class achievement_sickly_gazelle : public AchievementCriteriaScript
{
public:
    achievement_sickly_gazelle() : AchievementCriteriaScript("achievement_sickly_gazelle") { }

    bool OnCheck(Player* /*source*/, Unit* target) override
    {
        if (!target)
            return false;

        if (Player* victim = target->ToPlayer())
            if (victim->IsMounted())
                return true;

        return false;
    }
};

class achievement_everything_counts : public AchievementCriteriaScript
{
    public:
        achievement_everything_counts() : AchievementCriteriaScript("achievement_everything_counts") { }

        bool OnCheck(Player* source, Unit* target) override
        {
            if (Battleground* bg = source->GetBattleground())
                return bg->CheckAchievementCriteriaMeet(BG_CRITERIA_CHECK_EVERYTHING_COUNTS, source, target);

            return false;
        }
};

class achievement_bg_av_perfection : public AchievementCriteriaScript
{
    public:
        achievement_bg_av_perfection() : AchievementCriteriaScript("achievement_bg_av_perfection") { }

        bool OnCheck(Player* source, Unit* target) override
        {
            if (Battleground* bg = source->GetBattleground())
                return bg->CheckAchievementCriteriaMeet(BG_CRITERIA_CHECK_AV_PERFECTION, source, target);

            return false;
        }
};

class achievement_bg_sa_defense_of_ancients : public AchievementCriteriaScript
{
    public:
        achievement_bg_sa_defense_of_ancients() : AchievementCriteriaScript("achievement_bg_sa_defense_of_ancients") { }

        bool OnCheck(Player* source, Unit* target) override
        {
            if (Battleground* bg = source->GetBattleground())
                return bg->CheckAchievementCriteriaMeet(BG_CRITERIA_CHECK_DEFENSE_OF_THE_ANCIENTS, source, target);

            return false;
        }
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

class achievement_not_even_a_scratch : public AchievementCriteriaScript
{
    public:
        achievement_not_even_a_scratch() : AchievementCriteriaScript("achievement_not_even_a_scratch") { }

        bool OnCheck(Player* source, Unit* target) override
        {
            if (Battleground* bg = source->GetBattleground())
                return bg->CheckAchievementCriteriaMeet(BG_CRITERIA_CHECK_NOT_EVEN_A_SCRATCH, source, target);

            return false;
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

void AddSC_achievement_scripts()
{
    new achievement_resilient_victory();
    new achievement_bg_control_all_nodes();
    new achievement_save_the_day();
    new achievement_bg_ic_resource_glut();
    new achievement_bg_ic_glaive_grave();
    new achievement_bg_ic_mowed_down();
    new achievement_bg_sa_artillery();
    new achievement_sickly_gazelle();
    new achievement_everything_counts();
    new achievement_bg_av_perfection();
    new achievement_arena_kills("achievement_arena_2v2_kills", ARENA_TYPE_2v2);
    new achievement_arena_kills("achievement_arena_3v3_kills", ARENA_TYPE_3v3);
    new achievement_arena_kills("achievement_arena_5v5_kills", ARENA_TYPE_5v5);
    new achievement_bg_sa_defense_of_ancients();
    new achievement_tilted();
    new achievement_not_even_a_scratch();
    new achievement_flirt_with_disaster_perf_check();
    new achievement_killed_exp_or_honor_target();
}
