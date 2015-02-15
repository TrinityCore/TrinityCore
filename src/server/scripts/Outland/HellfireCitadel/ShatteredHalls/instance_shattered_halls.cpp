/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Instance_Shattered_Halls
SD%Complete: 50
SDComment: instance not complete
SDCategory: Hellfire Citadel, Shattered Halls
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "shattered_halls.h"

enum Spells
{
    SPELL_CLEAVE    = 15284,

    SPELL_EXECUTE_1 = 39288,
    SPELL_EXECUTE_2,
    SPELL_EXECUTE_3
};

DoorData const doorData[] =
{
    {GO_GRAND_WARLOCK_CHAMBER_DOOR_1, DATA_NETHEKURSE, DOOR_TYPE_PASSAGE, BOUNDARY_S   },
    {GO_GRAND_WARLOCK_CHAMBER_DOOR_2, DATA_NETHEKURSE, DOOR_TYPE_PASSAGE, BOUNDARY_N   },
    {0,                               0,               DOOR_TYPE_ROOM,    BOUNDARY_NONE}
};

class instance_shattered_halls : public InstanceMapScript
{
    public:
        instance_shattered_halls() : InstanceMapScript("instance_shattered_halls", 540) { }

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_shattered_halls_InstanceMapScript(map);
        }

        struct instance_shattered_halls_InstanceMapScript : public InstanceScript
        {
            instance_shattered_halls_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                executionTimer = 0;
                executed = 0;
                _team = 0;
            }

            void OnPlayerEnter(Player* player) override
            {
                Aura* ex = nullptr;

                if (!_team)
                    _team = player->GetTeam();

                player->RemoveAurasDueToSpell(SPELL_EXECUTE_1);
                player->RemoveAurasDueToSpell(SPELL_EXECUTE_2);
                player->RemoveAurasDueToSpell(SPELL_EXECUTE_3);

                if (!executionTimer || executionerGUID.IsEmpty())
                    return;

                switch (executed)
                {
                    case 0:
                        ex = player->AddAura(SPELL_EXECUTE_1, player);
                        break;
                    case 1:
                        ex = player->AddAura(SPELL_EXECUTE_2, player);
                        break;
                    case 2:
                        ex = player->AddAura(SPELL_EXECUTE_3, player);
                        break;
                    default:
                        break;
                }

                if (ex)
                    ex->SetDuration(executionTimer);
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_GRAND_WARLOCK_CHAMBER_DOOR_1:
                    case GO_GRAND_WARLOCK_CHAMBER_DOOR_2:
                        AddDoor(go, true);
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_GRAND_WARLOCK_CHAMBER_DOOR_1:
                    case GO_GRAND_WARLOCK_CHAMBER_DOOR_2:
                        AddDoor(go, false);
                    default:
                        break;
                }
            }

            void OnCreatureCreate(Creature* creature) override
            {
                if (!_team)
                {
                    Map::PlayerList const &players = instance->GetPlayers();
                    if (!players.isEmpty())
                        if (Player* player = players.begin()->GetSource())
                            _team = player->GetTeam();
                }

                switch (creature->GetEntry())
                {
                    case NPC_GRAND_WARLOCK_NETHEKURSE:
                        nethekurseGUID = creature->GetGUID();
                        break;
                    case NPC_KARGATH_BLADEFIST:
                        kargathGUID = creature->GetGUID();
                        break;
                    case NPC_RANDY_WHIZZLESPROCKET:
                        if (_team == HORDE)
                            creature->UpdateEntry(NPC_DRISELLA);
                        break;
                    case NPC_SHATTERED_EXECUTIONER:
                        executionTimer = 55 * MINUTE * IN_MILLISECONDS;
                        DoCastSpellOnPlayers(SPELL_EXECUTE_1);
                        executionerGUID = creature->GetGUID();
                        SaveToDB();
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_SHATTERED_EXECUTIONER:
                        if (state == DONE)
                        {
                            DoRemoveAurasDueToSpellOnPlayers(SPELL_EXECUTE_1);
                            DoRemoveAurasDueToSpellOnPlayers(SPELL_EXECUTE_2);
                            DoRemoveAurasDueToSpellOnPlayers(SPELL_EXECUTE_3);
                            executionTimer = 0;
                            SaveToDB();
                        }
                        break;
                    case DATA_KARGATH:
                        if (Creature* executioner = instance->GetCreature(executionerGUID))
                            executioner->AI()->Reset();
                        break;
                    case DATA_OMROGG:
                        break;
                }
                return true;
            }

            ObjectGuid GetGuidData(uint32 data) const override
            {
                switch (data)
                {
                    case NPC_GRAND_WARLOCK_NETHEKURSE:
                        return nethekurseGUID;
                        break;
                    case NPC_KARGATH_BLADEFIST:
                        return kargathGUID;
                        break;
                    case NPC_SHATTERED_EXECUTIONER:
                        return executionerGUID;
                        break;
                    default:
                        return ObjectGuid::Empty;
                        break;
                }
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                if (!instance->IsHeroic())
                    return;

                data << uint32(executed) << ' '
                    << executionTimer << ' ';
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                if (!instance->IsHeroic())
                    return;

                uint32 readbuff;
                data >> readbuff;
                executed = uint8(readbuff);
                data >> readbuff;

                if (executed > VictimCount)
                {
                    executed = VictimCount;
                    executionTimer = 0;
                    return;
                }

                if (!readbuff)
                    return;

                Creature* executioner = nullptr;

                instance->LoadGrid(Executioner.GetPositionX(), Executioner.GetPositionY());
                if (Creature* kargath = instance->GetCreature(kargathGUID))
                    if (executionerGUID.IsEmpty())
                        executioner = kargath->SummonCreature(NPC_SHATTERED_EXECUTIONER, Executioner);

                if (executioner)
                    for (uint8 i = executed; i < VictimCount; ++i)
                        executioner->SummonCreature(executionerVictims[i](GetData(DATA_TEAM_IN_INSTANCE)), executionerVictims[i].GetPos());

                executionTimer = readbuff;
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_PRISONERS_EXECUTED:
                        return executed;
                        break;
                    case DATA_TEAM_IN_INSTANCE:
                        return _team;
                        break;
                    default:
                        return 0;
                        break;
                }
            }

            void Update(uint32 diff) override
            {
                if (!executionTimer)
                    return;

                if (executionTimer <= diff)
                {                        
                    switch (++executed)
                    {
                        case 1:
                            DoRemoveAurasDueToSpellOnPlayers(SPELL_EXECUTE_1);
                            DoCastSpellOnPlayers(SPELL_EXECUTE_2);
                            executionTimer = 10 * MINUTE * IN_MILLISECONDS;
                            break;
                        case 2:
                            DoRemoveAurasDueToSpellOnPlayers(SPELL_EXECUTE_2);
                            DoCastSpellOnPlayers(SPELL_EXECUTE_3);
                            executionTimer = 15 * MINUTE * IN_MILLISECONDS;
                            break;
                        default:
                            DoRemoveAurasDueToSpellOnPlayers(SPELL_EXECUTE_3);
                            executionTimer = 0;
                            break;
                    }

                    if (Creature* executioner = instance->GetCreature(executionerGUID))
                        executioner->AI()->SetData(1, executed);

                    SaveToDB();
                }
                else
                    executionTimer -= diff;
            }

        protected:
            ObjectGuid nethekurseGUID;
            ObjectGuid kargathGUID;
            ObjectGuid executionerGUID;

            uint8 executed;
            uint32 executionTimer;
            uint32 _team;
        };
};

class at_nethekurse_exit : public AreaTriggerScript
{
    public:
        at_nethekurse_exit() : AreaTriggerScript("at_nethekurse_exit") { };

        bool OnTrigger(Player* player, AreaTriggerEntry const*, bool /* entered */) override
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
                            kargath->AI()->SetData(1, is->GetData(DATA_TEAM_IN_INSTANCE));
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
                me->ResetLootMode();
                switch (instance->GetData(DATA_PRISONERS_EXECUTED))
                {
                    case 0:
                        me->AddLootMode(LOOT_MODE_HARD_MODE_3);
                    case 1:
                        me->AddLootMode(LOOT_MODE_HARD_MODE_2);
                    case 2:
                        me->AddLootMode(LOOT_MODE_HARD_MODE_1);
                    default:
                        break;
                }
            }

            void Reset() override
            {
                _Reset();
                if (instance->GetBossState(DATA_KARGATH) == DONE)
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                else
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);

                Initialize();
            }

            void JustSummoned(Creature*) override { }

            void JustDied(Unit*) override
            {
                _JustDied();
                Map::PlayerList const &players = instance->instance->GetPlayers();
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    Player* pl = itr->GetSource();
                    uint32 qId = pl->GetTeam() == ALLIANCE ? QUEST_IMPRISONED_A : QUEST_IMPRISONED_H;
                    if (pl->GetQuestStatus(qId) != QUEST_STATUS_NONE && pl->GetQuestStatus(qId) != QUEST_STATUS_FAILED)
                        pl->CompleteQuest(qId);
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == 1)
                {
                    uint32 entry = executionerVictims[data - 1](instance->GetData(DATA_TEAM_IN_INSTANCE));
                    if (Creature* victim = me->FindNearestCreature(entry, 30.0f, true))
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_shattered_executionerAI>(creature);
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

void AddSC_instance_shattered_halls()
{
    new instance_shattered_halls();
    new at_nethekurse_exit();
    new boss_shattered_executioner();
    new spell_kargath_executioner();
}
