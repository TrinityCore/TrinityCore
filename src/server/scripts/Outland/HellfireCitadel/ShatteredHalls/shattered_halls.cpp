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
#include "InstanceScript.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "shattered_halls.h"
#include "TemporarySummon.h"

class at_nethekurse_exit : public AreaTriggerScript
{
    public:
        at_nethekurse_exit() : AreaTriggerScript("at_nethekurse_exit") { };

        bool OnTrigger(Player* player, AreaTriggerEntry const*, bool /*entered*/) override
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

class boss_shattered_executioner : public CreatureScript
{
    public:
        boss_shattered_executioner() : CreatureScript("boss_shattered_executioner") { }

        struct boss_shattered_executionerAI : public BossAI
        {
            boss_shattered_executionerAI(Creature* creature) : BossAI(creature, DATA_SHATTERED_EXECUTIONER)
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
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                else
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);

                Initialize();
            }

            void JustSummoned(Creature*) override { } // avoid despawn of prisoners on death/reset

            void JustDied(Unit*) override
            {
                _JustDied();

                if (instance->GetData(DATA_PRISONERS_EXECUTED) > 0)
                    return;

                Map::PlayerList const &players = instance->instance->GetPlayers();
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
                        me->Kill(victim);

                    if (data == 1)
                    {
                        Map::PlayerList const &players = instance->instance->GetPlayers();
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
                        case 2:
                            me->RemoveLootMode(LOOT_MODE_HARD_MODE_2);
                        case 1:
                            me->RemoveLootMode(LOOT_MODE_HARD_MODE_3);
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetShatteredHallsAI<boss_shattered_executionerAI>(creature);
        }
};

class spell_kargath_executioner : public SpellScriptLoader
{
    public:
        spell_kargath_executioner() : SpellScriptLoader("spell_kargath_executioner") { }

        class spell_kargath_executioner_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_kargath_executioner_AuraScript);

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
                DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_kargath_executioner_AuraScript::AreaCheck);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_kargath_executioner_AuraScript();
        }
};

class spell_remove_kargath_executioner : public SpellScriptLoader
{
    public:
        spell_remove_kargath_executioner() : SpellScriptLoader("spell_remove_kargath_executioner") { }

        class spell_remove_kargath_executioner_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_remove_kargath_executioner_SpellScript);

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
                OnEffectHitTarget += SpellEffectFn(spell_remove_kargath_executioner_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_remove_kargath_executioner_SpellScript();
        }
};

void AddSC_shattered_halls()
{
    new at_nethekurse_exit();
    new boss_shattered_executioner();
    new spell_kargath_executioner();
    new spell_remove_kargath_executioner();
}
