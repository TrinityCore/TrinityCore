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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "InstanceScript.h"
#include "Player.h"
#include "SpellAuras.h"
#include "shattered_halls.h"

DoorData const doorData[] =
{
    { GO_GRAND_WARLOCK_CHAMBER_DOOR_1, DATA_NETHEKURSE, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { GO_GRAND_WARLOCK_CHAMBER_DOOR_2, DATA_NETHEKURSE, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { 0,                               0,               DOOR_TYPE_ROOM,    BOUNDARY_NONE }
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

                player->CastSpell(player, SPELL_REMOVE_KARGATH_EXECUTIONER, true);

                if (!executionTimer || executionerGUID.IsEmpty())
                    return;

                switch (executed)
                {
                    case 0:
                        ex = player->AddAura(SPELL_KARGATH_EXECUTIONER_1, player);
                        break;
                    case 1:
                        ex = player->AddAura(SPELL_KARGATH_EXECUTIONER_2, player);
                        break;
                    case 2:
                        ex = player->AddAura(SPELL_KARGATH_EXECUTIONER_3, player);
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
                        DoCastSpellOnPlayers(SPELL_KARGATH_EXECUTIONER_1);
                        executionerGUID = creature->GetGUID();
                        SaveToDB();
                        break;
                    case NPC_CAPTAIN_ALINA:
                    case NPC_CAPTAIN_BONESHATTER:
                        victimsGUID[0] = creature->GetGUID();
                        break;
                    case NPC_ALLIANCE_VICTIM_1:
                    case NPC_HORDE_VICTIM_1:
                        victimsGUID[1] = creature->GetGUID();
                        break;
                    case NPC_ALLIANCE_VICTIM_2:
                    case NPC_HORDE_VICTIM_2:
                        victimsGUID[2] = creature->GetGUID();
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
                            DoCastSpellOnPlayers(SPELL_REMOVE_KARGATH_EXECUTIONER);
                            executionTimer = 0;
                            SaveToDB();
                        }
                        break;
                    case DATA_KARGATH:
                        if (Creature* executioner = instance->GetCreature(executionerGUID))
                            executioner->AI()->Reset(); // trigger removal of IMMUNE_TO_PC flag
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
                    case NPC_KARGATH_BLADEFIST:
                        return kargathGUID;
                    case NPC_SHATTERED_EXECUTIONER:
                        return executionerGUID;
                    case DATA_FIRST_PRISONER:
                    case DATA_SECOND_PRISONER:
                    case DATA_THIRD_PRISONER:
                        return victimsGUID[data - DATA_FIRST_PRISONER];
                    default:
                        return ObjectGuid::Empty;
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
                    case DATA_TEAM_IN_INSTANCE:
                        return _team;
                    default:
                        return 0;
                }
            }

            void Update(uint32 diff) override
            {
                if (!executionTimer)
                    return;

                if (executionTimer <= diff)
                {
                    DoCastSpellOnPlayers(SPELL_REMOVE_KARGATH_EXECUTIONER);
                    switch (++executed)
                    {
                        case 1:
                            DoCastSpellOnPlayers(SPELL_KARGATH_EXECUTIONER_2);
                            executionTimer = 10 * MINUTE * IN_MILLISECONDS;
                            break;
                        case 2:
                            DoCastSpellOnPlayers(SPELL_KARGATH_EXECUTIONER_3);
                            executionTimer = 15 * MINUTE * IN_MILLISECONDS;
                            break;
                        default:
                            executionTimer = 0;
                            break;
                    }

                    if (Creature* executioner = instance->GetCreature(executionerGUID))
                        executioner->AI()->SetData(DATA_PRISONERS_EXECUTED, executed);

                    SaveToDB();
                }
                else
                    executionTimer -= diff;
            }

        private:
            ObjectGuid nethekurseGUID;
            ObjectGuid kargathGUID;
            ObjectGuid executionerGUID;
            ObjectGuid victimsGUID[3];

            uint8 executed;
            uint32 executionTimer;
            uint32 _team;
        };
};

void AddSC_instance_shattered_halls()
{
    new instance_shattered_halls();
}
