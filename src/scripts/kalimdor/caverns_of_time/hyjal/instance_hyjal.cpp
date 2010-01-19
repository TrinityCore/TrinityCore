 /* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Instance_Mount_Hyjal
SD%Complete: 100
SDComment: Instance Data Scripts and functions to acquire mobs and set encounter status for use in various Hyjal Scripts
SDCategory: Caverns of Time, Mount Hyjal
EndScriptData */

#include "ScriptedPch.h"
#include "hyjal.h"
#include "hyjal_trash.h"

enum eEnums
{
    MAX_ENCOUNTER       = 5,

    GO_ANCIENT_GEM      = 185557
};
/* Battle of Mount Hyjal encounters:
0 - Rage Winterchill event
1 - Anetheron event
2 - Kaz'rogal event
3 - Azgalor event
4 - Archimonde event
*/

struct TRINITY_DLL_DECL instance_mount_hyjal : public ScriptedInstance
{
    instance_mount_hyjal(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint32 m_auiEncounter[MAX_ENCOUNTER];
    std::string str_data;

    std::list<uint64> m_uiAncientGemGUID;

    uint64 RageWinterchill;
    uint64 Anetheron;
    uint64 Kazrogal;
    uint64 Azgalor;
    uint64 Archimonde;
    uint64 JainaProudmoore;
    uint64 Thrall;
    uint64 TyrandeWhisperwind;
    uint64 HordeGate;
    uint64 ElfGate;

    uint32 Trash;

    uint32 hordeRetreat;
    uint32 allianceRetreat;
    bool ArchiYell;

    uint32 RaidDamage;

    #define YELL_EFFORTS        "All of your efforts have been in vain, for the draining of the World Tree has already begun. Soon the heart of your world will beat no more."
    #define YELL_EFFORTS_NAME   "Archimonde"

    void Initialize()
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        m_uiAncientGemGUID.clear();

        RageWinterchill = 0;
        Anetheron = 0;
        Kazrogal = 0;
        Azgalor = 0;
        Archimonde = 0;
        JainaProudmoore = 0;
        Thrall = 0;
        TyrandeWhisperwind = 0;
        HordeGate = 0;
        ElfGate = 0;
        ArchiYell = false;
        RaidDamage = 0;

        Trash = 0;

        hordeRetreat = 0;
        allianceRetreat = 0;
    }

    bool IsEncounterInProgress() const
    {
        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS) return true;

        return false;
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch(pGo->GetEntry())
        {
            case 182060:
                HordeGate = pGo->GetGUID();
                if (allianceRetreat)
                    HandleGameObject(0, true, pGo);
                else
                    HandleGameObject(0, false, pGo);
                break;
            case 182061:
                ElfGate = pGo->GetGUID();
                if (hordeRetreat)
                    HandleGameObject(0, true, pGo);
                else
                    HandleGameObject(0, false, pGo);
                break;
            case GO_ANCIENT_GEM:
                m_uiAncientGemGUID.push_back(pGo->GetGUID());
                break;
        }
    }

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        switch(pCreature->GetEntry())
        {
            case 17767: RageWinterchill = pCreature->GetGUID(); break;
            case 17808: Anetheron = pCreature->GetGUID(); break;
            case 17888: Kazrogal = pCreature->GetGUID();  break;
            case 17842: Azgalor = pCreature->GetGUID(); break;
            case 17968: Archimonde = pCreature->GetGUID(); break;
            case 17772: JainaProudmoore = pCreature->GetGUID(); break;
            case 17852: Thrall = pCreature->GetGUID(); break;
            case 17948: TyrandeWhisperwind = pCreature->GetGUID(); break;
        }
    }

    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_RAGEWINTERCHILL: return RageWinterchill;
            case DATA_ANETHERON: return Anetheron;
            case DATA_KAZROGAL: return Kazrogal;
            case DATA_AZGALOR: return Azgalor;
            case DATA_ARCHIMONDE: return Archimonde;
            case DATA_JAINAPROUDMOORE: return JainaProudmoore;
            case DATA_THRALL: return Thrall;
            case DATA_TYRANDEWHISPERWIND: return TyrandeWhisperwind;
        }

        return 0;
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_RAGEWINTERCHILLEVENT: m_auiEncounter[0] = data; break;
            case DATA_ANETHERONEVENT:
                m_auiEncounter[1] = data;
                break;
            case DATA_KAZROGALEVENT:        m_auiEncounter[2] = data; break;
            case DATA_AZGALOREVENT:
                {
                    m_auiEncounter[3] = data;
                    if (data==DONE)
                    {
                        if (ArchiYell)break;
                        ArchiYell = true;

                        Creature* pCreature = instance->GetCreature(Azgalor);
                        if (pCreature)
                        {
                            Creature* pUnit = pCreature->SummonCreature(21987,pCreature->GetPositionX(),pCreature->GetPositionY(),pCreature->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN,10000);

                            Map* pMap = pCreature->GetMap();
                            if (pMap->IsDungeon() && pUnit)
                            {
                                pUnit->SetVisibility(VISIBILITY_OFF);
                                Map::PlayerList const &PlayerList = pMap->GetPlayers();
                                if (PlayerList.isEmpty())
                                     return;

                                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                {
                                     if (i->getSource())
                                     {
                                        WorldPacket data(SMSG_MESSAGECHAT, 200);
                                        pUnit->BuildMonsterChat(&data,CHAT_MSG_MONSTER_YELL,YELL_EFFORTS,0,YELL_EFFORTS_NAME,i->getSource()->GetGUID());
                                        i->getSource()->GetSession()->SendPacket(&data);

                                        WorldPacket data2(SMSG_PLAY_SOUND, 4);
                                        data2 << 10986;
                                        i->getSource()->GetSession()->SendPacket(&data2);
                                     }
                                }
                            }
                        }
                    }
                }
                break;
            case DATA_ARCHIMONDEEVENT:      m_auiEncounter[4] = data; break;
            case DATA_RESET_TRASH_COUNT:    Trash = 0;            break;

            case DATA_TRASH:
                if (data) Trash = data;
                else     Trash--;
                DoUpdateWorldState(WORLD_STATE_ENEMYCOUNT, Trash);
                break;
            case TYPE_RETREAT:
                if (data == SPECIAL)
                {
                    if (!m_uiAncientGemGUID.empty())
                    {
                        for (std::list<uint64>::iterator itr = m_uiAncientGemGUID.begin(); itr != m_uiAncientGemGUID.end(); ++itr)
                        {
                            //don't know how long it expected
                            DoRespawnGameObject(*itr,DAY);
                        }
                    }
                }
                break;
            case DATA_ALLIANCE_RETREAT:
                allianceRetreat = data;
                HandleGameObject(HordeGate, true);
                SaveToDB();
                break;
            case DATA_HORDE_RETREAT:
                hordeRetreat = data;
                HandleGameObject(ElfGate, true);
                SaveToDB();
                break;
            case DATA_RAIDDAMAGE:
                RaidDamage += data;
                if (RaidDamage >= MINRAIDDAMAGE)
                    RaidDamage = MINRAIDDAMAGE;
                break;
            case DATA_RESET_RAIDDAMAGE:
                RaidDamage = 0;
                break;
        }

         debug_log("TSCR: Instance Hyjal: Instance data updated for event %u (Data=%u)",type,data);

        if (data == DONE)
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2] << " "
                << m_auiEncounter[3] << " " << m_auiEncounter[4]
                << " " << allianceRetreat << " " << hordeRetreat
                << " " << RaidDamage;

            str_data = saveStream.str();

            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
        }

    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case DATA_RAGEWINTERCHILLEVENT: return m_auiEncounter[0];
            case DATA_ANETHERONEVENT:      return m_auiEncounter[1];
            case DATA_KAZROGALEVENT:       return m_auiEncounter[2];
            case DATA_AZGALOREVENT:        return m_auiEncounter[3];
            case DATA_ARCHIMONDEEVENT:     return m_auiEncounter[4];
            case DATA_TRASH:               return Trash;
            case DATA_ALLIANCE_RETREAT:    return allianceRetreat;
            case DATA_HORDE_RETREAT:       return hordeRetreat;
            case DATA_RAIDDAMAGE:          return RaidDamage;
        }
        return 0;
    }

    std::string GetSaveData()
    {
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
        std::istringstream loadStream(in);
        loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3] >> m_auiEncounter[4] >> allianceRetreat >> hordeRetreat >> RaidDamage;
        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS)                // Do not load an encounter as IN_PROGRESS - reset it instead.
                m_auiEncounter[i] = NOT_STARTED;
        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_mount_hyjal(Map* pMap)
{
    return new instance_mount_hyjal(pMap);
}

void AddSC_instance_mount_hyjal()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_hyjal";
    newscript->GetInstanceData = &GetInstanceData_instance_mount_hyjal;
    newscript->RegisterSelf();
}

