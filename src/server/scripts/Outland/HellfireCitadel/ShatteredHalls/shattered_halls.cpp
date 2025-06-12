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
#include "InstanceScript.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "shattered_halls.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

Position const Executioner = { 152.8524f, -83.63912f, 2.021005f, 0.06981317f };

class at_nethekurse_exit : public AreaTriggerScript
{
    public:
        at_nethekurse_exit() : AreaTriggerScript("at_nethekurse_exit") { };

        bool OnTrigger(Player* player, AreaTriggerEntry const*) override
        {
            if (InstanceScript* is = player->GetInstanceScript())
            {
                if (is->instance->IsHeroic())
                {
                    Creature* executioner = nullptr;

                    is->instance->LoadGrid(Executioner.GetPositionX(), Executioner.GetPositionY());
                    if (Creature* kargath = ObjectAccessor::GetCreature(*player, is->GetGuidData(NPC_KARGATH_BLADEFIST)))
                    {
                        if (is->GetGuidData(NPC_SHATTERED_EXECUTIONER).IsEmpty())
                        {
                            executioner = kargath->SummonCreature(NPC_SHATTERED_EXECUTIONER, Executioner);
                            kargath->AI()->DoAction(ACTION_EXECUTIONER_TAUNT);
                        }
                    }

                    if (executioner)
                        for (uint8 i = 0; i < VictimCount; ++i)
                            executioner->SummonCreature(executionerVictims[i](is->GetData(DATA_TEAM_IN_INSTANCE)), executionerVictims[i].GetPos());
                }
            }

            return false;
        }
};

enum Spells
{
    SPELL_CLEAVE = 15284
};

struct boss_shattered_executioner : public BossAI
{
    boss_shattered_executioner(Creature* creature) : BossAI(creature, DATA_SHATTERED_EXECUTIONER)
    {
        Initialize();
    };

    void Initialize()
    {
        cleaveTimer = 500;
    }

    void Reset() override
    {
        _Reset();

        // _Reset() resets the loot mode, so we add them again, if any
        uint32 prisonersExecuted = instance->GetData(DATA_PRISONERS_EXECUTED);
        if (prisonersExecuted == 0)
            me->AddLootMode(LOOT_MODE_HARD_MODE_3);
        if (prisonersExecuted <= 1)
            me->AddLootMode(LOOT_MODE_HARD_MODE_2);
        if (prisonersExecuted <= 2)
            me->AddLootMode(LOOT_MODE_HARD_MODE_1);

        if (instance->GetBossState(DATA_KARGATH) == DONE)
            me->SetImmuneToPC(false);
        else
            me->SetImmuneToPC(true);

        Initialize();
    }

    void JustSummoned(Creature*) override { } // avoid despawn of prisoners on death/reset

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        if (instance->GetData(DATA_PRISONERS_EXECUTED) > 0)
            return;

        Map::PlayerList const& players = instance->instance->GetPlayers();
        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        {
            Player* pl = itr->GetSource();
            uint32 qId = pl->GetTeam() == ALLIANCE ? QUEST_IMPRISONED_A : QUEST_IMPRISONED_H;
            if (pl->GetQuestStatus(qId) == QUEST_STATUS_INCOMPLETE)
                pl->CompleteQuest(qId);
        }
    }

    void SetData(uint32 type, uint32 data) override
    {
        if (type == DATA_PRISONERS_EXECUTED && data <= 3)
        {
            if (Creature* victim = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_FIRST_PRISONER + data - 1)))
                Unit::Kill(me, victim);

            if (data == 1)
            {
                Map::PlayerList const& players = instance->instance->GetPlayers();
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    Player* pl = itr->GetSource();
                    uint32 qId = pl->GetTeam() == ALLIANCE ? QUEST_IMPRISONED_A : QUEST_IMPRISONED_H;
                    if (pl->GetQuestStatus(qId) == QUEST_STATUS_INCOMPLETE)
                        pl->FailQuest(qId);
                }
            }

            switch (data)
            {
                case 3:
                    me->RemoveLootMode(LOOT_MODE_HARD_MODE_1);
                    [[fallthrough]];
                case 2:
                    me->RemoveLootMode(LOOT_MODE_HARD_MODE_2);
                    [[fallthrough]];
                case 1:
                    me->RemoveLootMode(LOOT_MODE_HARD_MODE_3);
                    [[fallthrough]];
                default:
                    break;
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (cleaveTimer <= diff)
        {
            DoCast(SPELL_CLEAVE);
            cleaveTimer = urand(5000, 7000);
        }
        else
            cleaveTimer -= diff;

        DoMeleeAttackIfReady();
    }
private:
    uint32 cleaveTimer;
};

// 39288, 39289, 39290 - Kargath's Executioner
class spell_kargath_executioner : public AuraScript
{
    PrepareAuraScript(spell_kargath_executioner);

    bool AreaCheck(Unit* target)
    {
        if (target->GetMap()->GetId() != 540)
            return false;

        return true;
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void Register() override
    {
        DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_kargath_executioner::AreaCheck);
    }
};

// 39291 - Remove Kargath's Executioner
class spell_remove_kargath_executioner : public SpellScript
{
    PrepareSpellScript(spell_remove_kargath_executioner);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetCaster();

        target->RemoveAurasDueToSpell(SPELL_KARGATH_EXECUTIONER_1);
        target->RemoveAurasDueToSpell(SPELL_KARGATH_EXECUTIONER_2);
        target->RemoveAurasDueToSpell(SPELL_KARGATH_EXECUTIONER_3);
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_remove_kargath_executioner::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_shattered_halls()
{
    new at_nethekurse_exit();
    RegisterShatteredHallsCreatureAI(boss_shattered_executioner);
    RegisterSpellScript(spell_kargath_executioner);
    RegisterSpellScript(spell_remove_kargath_executioner);
}
