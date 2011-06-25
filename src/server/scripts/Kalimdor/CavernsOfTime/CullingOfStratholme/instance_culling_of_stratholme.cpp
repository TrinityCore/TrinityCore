/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "culling_of_stratholme.h"

#define MAX_ENCOUNTER 7
#define ACHIEVEMENT_ZOMBIEFEST 1872
#define ZOMBIEFEST_MIN_COUNT   100

/* Culling of Stratholme encounters:
0 - Plague Crates
1 - Meathook
2 - Salramm the Fleshcrafter
3 - Chrono-Lord Epoch
4 - Mal'Ganis
5 - Infinite Corruptor (Heroic only)
6 - Arthas
*/

enum Texts
{
    SAY_CRATES_COMPLETED    = 0,
};

Position const ChromieSummonPos = {1813.298f, 1283.578f, 142.3258f, 3.878161f};

class instance_culling_of_stratholme : public InstanceMapScript
{
public:
    instance_culling_of_stratholme() : InstanceMapScript("instance_culling_of_stratholme", 595) { }

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_culling_of_stratholme_InstanceMapScript(pMap);
    }

    struct instance_culling_of_stratholme_InstanceMapScript : public InstanceScript
    {
        instance_culling_of_stratholme_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {}

        uint64 uiArthas;
        uint64 uiMeathook;
        uint64 uiSalramm;
        uint64 uiEpoch;
        uint64 uiMalGanis;
        uint64 uiInfinite;
		uint64 uiChromie;

        uint64 uiShkafGate;
        uint64 uiMalGanisGate1;
        uint64 uiMalGanisGate2;
        uint64 uiExitGate;
        uint64 uiMalGanisChest;
        uint32 uiCountdownTimer;
        uint16 uiCountdownMinute;
		uint64 _genericBunnyGUID;
		uint32 _crateCount;
		// Zombiefest!
		uint32 zombiesCount;
		uint32 zombieFestTimer;

        uint32 m_auiEncounter[MAX_ENCOUNTER];
        std::string str_data;

        uint32 uiCountCrates;

    
        void Initialize()
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            uiCountCrates = 0;
            uiCountdownTimer = 0;
            uiCountdownMinute = 26;
			zombiesCount = 0;
			zombieFestTimer = 0;
        }


        bool IsEncounterInProgress() const
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS) return true;

            return false;
        }

        void OnCreatureCreate(Creature* pCreature)
        {
            switch(pCreature->GetEntry())
            {
                case NPC_ARTHAS:
                    uiArthas = pCreature->GetGUID();
                    break;
                case NPC_MEATHOOK:
                    uiMeathook = pCreature->GetGUID();
                    break;
                case NPC_SALRAMM:
                    uiSalramm = pCreature->GetGUID();
                    break;
                case NPC_EPOCH:
                    uiEpoch = pCreature->GetGUID();
                    break;
                case NPC_MAL_GANIS:
                    uiMalGanis = pCreature->GetGUID();
                    break;
                case NPC_INFINITE:                                  // default unattackable
                    uiInfinite = pCreature->GetGUID();
                    pCreature->SetVisible(false);
                    pCreature->setFaction(35);
                    break;
				case NPC_GENERIC_BUNNY:
					_genericBunnyGUID = pCreature->GetGUID();
                    break;
				case NPC_CHROMIE:
					uiChromie = pCreature->GetGUID();
					pCreature->SetVisible(false);
                    break;
            }
        }

        void GiveQuestKillAllInInstance(uint32 entry)
        {
            Map::PlayerList const &PlayerList = instance->GetPlayers();

            if (PlayerList.isEmpty())
                return;

            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            {
                if (Player* i_pl = i->getSource())
                    i_pl->KilledMonsterCredit(entry, 0);
            }
        }

        void OnGameObjectCreate(GameObject* pGo)
        {
            switch(pGo->GetEntry())
            {
                case GO_SHKAF_GATE:
                    uiShkafGate = pGo->GetGUID();
                    break;
                case GO_MALGANIS_GATE_1:
                    uiMalGanisGate1 = pGo->GetGUID();
                    break;
                case GO_MALGANIS_GATE_2:
                    uiMalGanisGate2 = pGo->GetGUID();
                    break;
                case GO_EXIT_GATE:
                    uiExitGate = pGo->GetGUID();
                    if (m_auiEncounter[4] == DONE)
                        HandleGameObject(uiExitGate, true);
                    break;
                case GO_MALGANIS_CHEST_N:
                case GO_MALGANIS_CHEST_H:
                    uiMalGanisChest = pGo->GetGUID();
                    if (m_auiEncounter[4] == DONE)
                        pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                    break;
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            switch(type)
            {
                case DATA_CRATES_EVENT:
                    switch(data)
                    {
                    case 0: //Entfernt Worldstate
                        DoUpdateWorldState(WORLDSTATE_NUMBER_CRATES_SHOW, 0);
                        break;
                    case 1: //Addiert ein Punkt
                        uiCountCrates++;
                        DoUpdateWorldState(WORLDSTATE_NUMBER_CRATES_COUNT, uiCountCrates);
                        if(uiCountCrates >= 5)
                        {
                            m_auiEncounter[0] = DONE;
                            GiveQuestKillAllInInstance(CREDIT_DISPELLING_ILLUSIONS);
                            SaveToDB();
                        }
                        break;
                    case 2: //Startet den Worldstate
                        uiCountCrates = 0;
                        m_auiEncounter[0] = IN_PROGRESS;
                        DoUpdateWorldState(WORLDSTATE_NUMBER_CRATES_SHOW, 1);
                        DoUpdateWorldState(WORLDSTATE_NUMBER_CRATES_COUNT, uiCountCrates);
                        break;
                    }
                break;
                case DATA_MEATHOOK_EVENT:
                    m_auiEncounter[1] = data;
                    break;
                case DATA_SALRAMM_EVENT:
                    m_auiEncounter[2] = data;
                    break;
                case DATA_EPOCH_EVENT:
                    m_auiEncounter[3] = data;
                    break;
                case DATA_MAL_GANIS_EVENT:
                    m_auiEncounter[4] = data;
                    switch (m_auiEncounter[4])
                    {
                        case NOT_STARTED:
                            HandleGameObject(uiMalGanisGate2, true);
                            break;
                        case IN_PROGRESS:
                            HandleGameObject(uiMalGanisGate2, false);
                            break;
                        case DONE:
                            GiveQuestKillAllInInstance(CREDIT_A_ROYAL_ESCORT);
							if (Creature* pCreature = instance->GetCreature(uiChromie))
                            {
                                pCreature->SetVisible(true);
                            }
                            HandleGameObject(uiExitGate, true);
                            HandleGameObject(uiMalGanisGate2, true);
                            if (GameObject* pGo = instance->GetGameObject(uiMalGanisChest))
                                pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                            break;
                    }
                    break;
                case DATA_INFINITE_EVENT:
                    m_auiEncounter[5] = data;
                    switch (m_auiEncounter[5])
                    {
                        case DONE:
                            uiCountdownMinute = 0;
                            DoUpdateWorldState(WORLDSTATE_NUMBER_INFINITE_SHOW, 0);
                            break;
                        case IN_PROGRESS: //make visible
                        {
                            if (Creature* pCreature = instance->GetCreature(uiInfinite))
                            {
                                pCreature->SetVisible(true);
                                pCreature->RestoreFaction();
                            }
                        }   break;
                    }
	               break;
	           case DATA_ZOMBIEFEST:
	                    if (data == ACHI_START)
	                        zombieFestTimer = 60 * IN_MILLISECONDS;
	                    else if (data == ACHI_INCREASE)
	                        ++zombiesCount;
	                    else if (data == ACHI_RESET)
	                    {
	                        zombiesCount = 0;
	                        zombieFestTimer = 0;
	                    }
                    break;
                    case DATA_CRATE_COUNT:
                        _crateCount = data;
                        if (_crateCount == 5)
                        {
                            if (Creature* bunny = instance->GetCreature(_genericBunnyGUID))
                                bunny->CastSpell(bunny, SPELL_CRATES_CREDIT, true);

                           /* // Summon Chromie and global whisper
                            if (Creature* chromie = instance->SummonCreature(NPC_CHROMIE_2, ChromieSummonPos))
                                if (!instance->GetPlayers().isEmpty())
                                    if (Player* plr = instance->GetPlayers().getFirst()->getSource())
                                        sCreatureTextMgr->SendChat(chromie, SAY_CRATES_COMPLETED, plr->GetGUID(), CHAT_TYPE_END, LANG_ADDON, TEXT_RANGE_MAP);*/
                        }
						//DoUpdateWorldState(WORLDSTATE_CRATES_REVEALED, _crateCount);
                        break;
                case DATA_ARTHAS_EVENT:
                    m_auiEncounter[6] = data;
                    break;
            }

            if (data == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 type)
        {
            switch(type)
            {
                case DATA_CRATES_EVENT:               return m_auiEncounter[0];
                case DATA_MEATHOOK_EVENT:             return m_auiEncounter[1];
                case DATA_SALRAMM_EVENT:              return m_auiEncounter[2];
                case DATA_EPOCH_EVENT:                return m_auiEncounter[3];
                case DATA_MAL_GANIS_EVENT:            return m_auiEncounter[4];
                case DATA_INFINITE_EVENT:             return m_auiEncounter[5];
                case DATA_ARTHAS_EVENT:               return m_auiEncounter[6];
                case DATA_COUNTDOWN:                  return uiCountdownMinute;
                case DATA_CRATE_COUNT:                return _crateCount;
	            case DATA_ZOMBIEFEST:
	                if (zombieFestTimer == 0)
	                        return ACHI_IS_NOT_STARTED;
	                    else
	                        return ACHI_IS_IN_PROGRESS;
            }
            return 0;
        }

        uint64 GetData64(uint32 identifier)
        {
            switch(identifier)
            {
                case DATA_ARTHAS:                     return uiArthas;
                case DATA_MEATHOOK:                   return uiMeathook;
                case DATA_SALRAMM:                    return uiSalramm;
                case DATA_EPOCH:                      return uiEpoch;
                case DATA_MAL_GANIS:                  return uiMalGanis;
                case DATA_INFINITE:                   return uiInfinite;
                case DATA_SHKAF_GATE:                 return uiShkafGate;
                case DATA_MAL_GANIS_GATE_1:           return uiMalGanisGate1;
                case DATA_MAL_GANIS_GATE_2:           return uiMalGanisGate2;
                case DATA_EXIT_GATE:                  return uiExitGate;
                case DATA_MAL_GANIS_CHEST:            return uiMalGanisChest;
            }
            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "C S " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " "
                << m_auiEncounter[2] << " " << m_auiEncounter[3] << " " << m_auiEncounter[4] << " " << m_auiEncounter[5] << " " << m_auiEncounter[6] << " " << uiCountdownMinute;

            str_data = saveStream.str();

            OUT_SAVE_INST_DATA_COMPLETE;
            return str_data;
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
            uint16 data0, data1, data2, data3, data4, data5, data6, data7;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3 >> data4 >> data5 >> data6 >> data7;

            if (dataHead1 == 'C' && dataHead2 == 'S')
            {
                m_auiEncounter[0] = data0;
                m_auiEncounter[1] = data1;
                m_auiEncounter[2] = data2;
                m_auiEncounter[3] = data3;
                m_auiEncounter[4] = data4;
                m_auiEncounter[5] = data5;
                m_auiEncounter[6] = data6;
                uiCountdownMinute = data7;

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS || m_auiEncounter[i] == SPECIAL)
                        m_auiEncounter[i] = NOT_STARTED;

            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        void Update(uint32 diff)
        {
            if (GetData(DATA_INFINITE_EVENT) == SPECIAL || GetData(DATA_INFINITE_EVENT) == IN_PROGRESS)
                if (uiCountdownMinute)
                {
                    if (uiCountdownTimer < diff)
                    {
                        uiCountdownMinute--;

                        if (uiCountdownMinute)
                        {
                            DoUpdateWorldState(WORLDSTATE_NUMBER_INFINITE_SHOW, 1);
                            DoUpdateWorldState(WORLDSTATE_NUMBER_INFINITE_TIMER, uiCountdownMinute);
                        }
                        else
                        {
                            DoUpdateWorldState(WORLDSTATE_NUMBER_INFINITE_SHOW, 0);
                        }
                        SaveToDB();
                        uiCountdownTimer += 60000;
                    }
                    uiCountdownTimer -= diff;
                }
	
	            // Achievement Zombiefest! control
	            if (zombieFestTimer)
	            {
	                if (zombiesCount >= ZOMBIEFEST_MIN_COUNT)
	                {
	                    DoCompleteAchievement(ACHIEVEMENT_ZOMBIEFEST);
	
	                    SetData(DATA_ZOMBIEFEST, ACHI_RESET);
	                    return;
	                }
	
	                if (zombieFestTimer <= diff)
	                    SetData(DATA_ZOMBIEFEST, ACHI_RESET);
	                else zombieFestTimer -= diff;
	            }
	
        }
    };
};

void AddSC_instance_culling_of_stratholme()
{
    new instance_culling_of_stratholme();
}
