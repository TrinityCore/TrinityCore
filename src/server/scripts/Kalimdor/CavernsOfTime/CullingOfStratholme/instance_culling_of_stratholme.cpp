/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "CreatureTextMgr.h"
#include "culling_of_stratholme.h"
#include "Player.h"
#include "TemporarySummon.h"
#include "SpellInfo.h"

#define MAX_EVENTS 7

/* Culling of Stratholme encounters:
0 - Meathook
1 - Salramm the Fleshcrafter
2 - Chrono-Lord Epoch
3 - Mal'Ganis
4 - Infinite Corruptor (Heroic only)
*/

enum Texts
{
    SAY_CRATES_COMPLETED    = 0,
};

Position const ChromieMiddleSummonPos = {1813.298f, 1283.578f, 142.3258f, 3.878161f};

class instance_culling_of_stratholme : public InstanceMapScript
{
    public:
        instance_culling_of_stratholme() : InstanceMapScript("instance_culling_of_stratholme", 595) { }

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_culling_of_stratholme_InstanceMapScript(map);
        }

        struct instance_culling_of_stratholme_InstanceMapScript : public InstanceScript
        {
            instance_culling_of_stratholme_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                _meathookGUID = 0;
                _salrammTheFleshcrafterGUID = 0;
                _chronoLordEpochGUID = 0;
                _malGanisGUID = 0;
                _infiniteCorruptorGUID = 0;
                _bookshelfGateGUID = 0;
                _malGanisInnerGateGUID = 0;
                _malGanisOuterGateGUID = 0;
                _exitGateGUID = 0;
                _malGanisChestGUID = 0;
                _totallyGenericBunnyGUID = 0;
                memset(&_encounterState[0], 0, sizeof(uint32) * MAX_EVENTS);
                _crateCount = 0;
                //_waveCount = 1;
            }

            bool IsEncounterInProgress() const
            {
                for (uint8 i = 0; i < MAX_EVENTS; ++i)
                    if (_encounterState[i] == IN_PROGRESS)
                        return true;

                return false;
            }

            void FillInitialWorldStates(WorldPacket& data)
            {
                data << uint32(WORLDSTATE_SHOW_CRATES) << uint32(0);
                data << uint32(WORLDSTATE_CRATES_REVEALED) << uint32(_crateCount);
                data << uint32(WORLDSTATE_WAVE_COUNT) << uint32(0);
                data << uint32(WORLDSTATE_TIME_GUARDIAN_SHOW) << uint32(0);
                data << uint32(WORLDSTATE_TIME_GUARDIAN) << uint32(25);
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    case NPC_MEATHOOK:
                        _meathookGUID = creature->GetGUID();
                        break;
                    case NPC_SALRAMM_THE_FLESHCRAFTER:
                        _salrammTheFleshcrafterGUID = creature->GetGUID();
                        break;
                    case NPC_CHRONO_LORD_EPOCH:
                        _chronoLordEpochGUID = creature->GetGUID();
                        break;
                    case NPC_MAL_GANIS:
                        _malGanisGUID = creature->GetGUID();
                        break;
                    case NPC_INFINITE_CORRUPTOR:
                        _infiniteCorruptorGUID = creature->GetGUID();
                        break;
                    case NPC_TOTALLY_GENERIC_BUNNY:
                        _totallyGenericBunnyGUID = creature->GetGUID();
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go)
            {
                switch (go->GetEntry())
                {
                    case GO_BOOKSHELF_GATE:
                        _bookshelfGateGUID = go->GetGUID();
                        break;
                    case GO_MAL_GANIS_INNER_GATE:
                        _malGanisInnerGateGUID = go->GetGUID();
                        break;
                    case GO_MAL_GANIS_OUTER_GATE:
                        _malGanisOuterGateGUID = go->GetGUID();
                        break;
                    case GO_EXIT_GATE:
                        _exitGateGUID = go->GetGUID();
                        if (_encounterState[5] == DONE)
                            HandleGameObject(_exitGateGUID, true);
                        break;
                    case GO_MALGANIS_CHEST_N:
                    case GO_MALGANIS_CHEST_H:
                        _malGanisChestGUID = go->GetGUID();
                        if (_encounterState[5] == DONE)
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                        break;
                }
            }

            //[DWF]If problems arise, check here first
            void SetData(uint32 type, uint32 data)
            {
                switch (type)
                {
                    case DATA_CHROMIE_EVENT:
                        _encounterState[0] = data;

                        switch (_encounterState[0])
                        {
                            case IN_PROGRESS:
                                //Show crates
                                DoUpdateWorldState(WORLDSTATE_SHOW_CRATES, 1);
                                break;
                        }
                        break;
                   case DATA_CRATE_COUNT:
                        _crateCount = data;
                        //All crates dispelled?
                        if (_crateCount == 5)
                        {
                            if (Creature* bunny = instance->GetCreature(_totallyGenericBunnyGUID))
                                bunny->CastSpell(bunny, SPELL_CRATES_CREDIT, true);
                        }
                        // todo: check instance status before hand
                        if (Creature* chromie = instance->SummonCreature(NPC_CHROMIE_MIDDLE, ChromieMiddleSummonPos))
-                                if (!instance->GetPlayers().isEmpty())
-                                    if (Player* player = instance->GetPlayers().getFirst()->getSource())
-                                        sCreatureTextMgr->SendChat(chromie, SAY_CRATES_COMPLETED, player->GetGUID(), CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_MAP);
                        //Otherwise show how many we've got so far
                        DoUpdateWorldState(WORLDSTATE_CRATES_REVEALED, _crateCount);
                        break;
                    case DATA_INITIAL_RP_EVENT:
                       _encounterState[1] = data;
                       
                       switch (_encounterState[1])
                       {
                           case IN_PROGRESS:
                               //Hide crates
                               DoUpdateWorldState(WORLDSTATE_SHOW_CRATES, 0);
                               break;
                       }
                        break;
                    case DATA_MEATHOOK_EVENT:
                        _encounterState[2] = data;
                        break;
                    case DATA_SALRAMM_EVENT:
                        _encounterState[3] = data;
                        break;
                    case DATA_EPOCH_EVENT:
                        _encounterState[4] = data;
                        break;
                    case DATA_MAL_GANIS_EVENT:
                        _encounterState[5] = data;

                        switch (_encounterState[5])
                        {
                            case NOT_STARTED:
                                HandleGameObject(_malGanisOuterGateGUID, true);
                                break;
                            case IN_PROGRESS:
                                HandleGameObject(_malGanisOuterGateGUID, false);
                                break;
                            case DONE:
                                HandleGameObject(_exitGateGUID, true);
                                if (GameObject* go = instance->GetGameObject(_malGanisChestGUID))
                                    go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                                break;
                        }
                        break;
                    case DATA_INFINITE_CORRUPTOR_EVENT:
                        _encounterState[6] = data;
                        break;
                }

                if (data == DONE)
                    SaveToDB();
            }

            uint32 GetData(uint32 type) const
            {
                switch (type)
                {
                    case DATA_CHROMIE_EVENT:
                        return _encounterState[0];
                    case DATA_INITIAL_RP_EVENT:
                        return _encounterState[1];
                    case DATA_MEATHOOK_EVENT:
                        return _encounterState[2];
                    case DATA_SALRAMM_EVENT:
                        return _encounterState[3];
                    case DATA_EPOCH_EVENT:
                        return _encounterState[4];
                    case DATA_MAL_GANIS_EVENT:
                        return _encounterState[5];
                    case DATA_INFINITE_CORRUPTOR_EVENT:
                        return _encounterState[6];
                    case DATA_CRATE_COUNT:
                        return _crateCount;
                }
                return 0;
            }

            uint64 GetData64(uint32 identifier) const
            {
                switch (identifier)
                {
                    case DATA_MEATHOOK:
                        return _meathookGUID;
                    case DATA_SALRAMM_THE_FLESHCRAFTER:
                        return _salrammTheFleshcrafterGUID;
                    case DATA_CHRONO_LORD_EPOCH:
                        return _chronoLordEpochGUID;
                    case DATA_MAL_GANIS:
                        return _malGanisGUID;
                    case DATA_INFINITE_CORRUPTOR:
                        return _infiniteCorruptorGUID;
                    case DATA_BOOKSHELF:
                        return _bookshelfGateGUID;
                    case DATA_MAL_GANIS_INNER_GATE:
                        return _malGanisInnerGateGUID;
                    case DATA_MAL_GANIS_OUTER_GATE:
                        return _malGanisOuterGateGUID;
                    case DATA_EXIT_GATE:
                        return _exitGateGUID;
                    case DATA_MAL_GANIS_CHEST:
                        return _malGanisChestGUID;
                }
                return 0;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "C S " << _encounterState[0] << ' ' << _encounterState[1] << ' '
                    << _encounterState[2] << ' ' << _encounterState[3] << ' ' << _encounterState[4] ' '
                    << _encounterState[5] << ' ' << _encounterState[6];

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(const char* in)
            {
                if (!in)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(in);

                char dataHead1, dataHead2;
                uint16 data0, data1, data2, data3, data4, data5, data6;

                std::istringstream loadStream(in);
                loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3 >> data4 >> data5 >> data6;

                if (dataHead1 == 'C' && dataHead2 == 'S')
                {
                    _encounterState[0] = data0;
                    _encounterState[1] = data1;
                    _encounterState[2] = data2;
                    _encounterState[3] = data3;
                    _encounterState[4] = data4;
                    _encounterState[5] = data5;
                    _encounterState[6] = data6;

                    for (uint8 i = 0; i < MAX_EVENTS; ++i)
                        if (_encounterState[i] == IN_PROGRESS)
                            _encounterState[i] = NOT_STARTED;

                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        private:
            uint64 _meathookGUID;
            uint64 _salrammTheFleshcrafterGUID;
            uint64 _chronoLordEpochGUID;
            uint64 _malGanisGUID;
            uint64 _infiniteCorruptorGUID;
            uint64 _bookshelfGateGUID;
            uint64 _malGanisInnerGateGUID;
            uint64 _malGanisOuterGateGUID;
            uint64 _exitGateGUID;
            uint64 _malGanisChestGUID;
            uint64 _totallyGenericBunnyGUID;
            uint32 _encounterState[MAX_EVENTS];
            uint32 _crateCount;
        };
};

void AddSC_instance_culling_of_stratholme()
{
    new instance_culling_of_stratholme();
}
