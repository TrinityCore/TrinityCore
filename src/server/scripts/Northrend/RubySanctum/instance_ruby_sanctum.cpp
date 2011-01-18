/* Copyright (C) 2010 Easy for TrinityCore <http://trinity-core.ru/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "ScriptPCH.h"
#include "ruby_sanctum.h"

static const DoorData doorData[5] =
{
    {GO_FIRE_FIELD,   DATA_BALTHARUS,       DOOR_TYPE_PASSAGE, BOUNDARY_NONE},
    {GO_FLAME_WALLS,  DATA_BALTHARUS,       DOOR_TYPE_PASSAGE, BOUNDARY_NONE},
    {GO_FLAME_WALLS,  DATA_RAGEFIRE,        DOOR_TYPE_PASSAGE, BOUNDARY_NONE},
    {GO_FLAME_WALLS,  DATA_ZARITHRIAN,      DOOR_TYPE_ROOM,    BOUNDARY_N   },
    {0,               0,                    DOOR_TYPE_ROOM,    BOUNDARY_NONE}
};

class instance_ruby_sanctum : public InstanceMapScript
{
    public:
        instance_ruby_sanctum() : InstanceMapScript("instance_ruby_sanctum", 724) { }

        struct instance_ruby_sanctum_InstanceMapScript : public InstanceScript
        {
            instance_ruby_sanctum_InstanceMapScript(Map *pMap) : InstanceScript(pMap)
            {
                SetBossNumber(MAX_ENCOUNTER);
                LoadDoorData(doorData);

                m_uiDataDamage = 0;

                m_uiXerestrasza = 0;
                m_uiTwilightHalion = 0;

                m_uiHalionPortalGUID = 0;
                m_uiTwilightPortalGUID = 0;
                m_uiBaltharusGUID = 0;
                m_uiZarithrianGUID = 0;
                m_uiRagefireGUID = 0;
                m_uiHalionGUID = 0;
                m_uiXerestraszaGUID = 0;
                m_uiTwilightHalionGUID = 0;
                m_uiGOFlameWallsGUID = 0;
                m_uiGOTwilightWallsGUID = 0;
            }

            void OnCreatureCreate(Creature *pCreature, bool  /*add*/)
            {
                switch(pCreature->GetEntry())
                {
                    case NPC_BALTHARUS:     m_uiBaltharusGUID = pCreature->GetGUID();   break;
                    case NPC_RAGEFIRE:      m_uiRagefireGUID = pCreature->GetGUID();    break;
                    case NPC_XERESTRASZA:   m_uiXerestraszaGUID = pCreature->GetGUID(); break;
                    case NPC_ZARITHRIAN:
                        m_uiZarithrianGUID = pCreature->GetGUID();
                        if (GetBossState(DATA_RAGEFIRE)==DONE && GetBossState(DATA_BALTHARUS)==DONE)
                        {
                            pCreature->SetReactState(REACT_AGGRESSIVE);
                            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        }
                        else
                        {
                            pCreature->SetReactState(REACT_PASSIVE);
                            pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        }
                        break;
                    case NPC_HALION:        
                        m_uiHalionGUID = pCreature->GetGUID();
                        if (GetBossState(DATA_ZARITHRIAN)==DONE && GetBossState(DATA_RAGEFIRE)==DONE && GetBossState(DATA_BALTHARUS)==DONE)
                        {
                            pCreature->SetVisible(true);
                            pCreature->SetReactState(REACT_AGGRESSIVE);
                            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        }
                        else
                        {
                            pCreature->SetVisible(false);
                            pCreature->SetReactState(REACT_PASSIVE);
                            pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        }
                        break;
                    case NPC_TWILIGHT_HALION: m_uiTwilightHalionGUID = pCreature->GetGUID(); break;
                }
            }

            void OnGameObjectCreate(GameObject* pGo, bool add)
            {
                switch (pGo->GetEntry())
                {
                    case GO_FIRE_FIELD:
                    case GO_FLAME_WALLS:
                    //case GO_FLAME_WALLS2:
                        AddDoor(pGo, add);
                        break;
                    case GO_TWILIGHT_PORTAL1: m_uiHalionPortalGUID = pGo->GetGUID(); break;
                    case GO_TWILIGHT_PORTAL2: m_uiTwilightPortalGUID = pGo->GetGUID(); break;
                    case GO_FLAME_WALLS2:     m_uiGOFlameWallsGUID = pGo->GetGUID(); break;
                    case GO_FLAME_WALLS3:     m_uiGOTwilightWallsGUID = pGo->GetGUID(); break;
                    default: break;
                }
            }

            void SetData(uint32 uiType, uint32 uiData)
            {
                switch(uiType)
                {
                    case DATA_XERESTRASZA:     m_uiXerestrasza    = uiData; break;
                    case DATA_TWILIGHT_HALION: m_uiTwilightHalion = uiData; break;
                    case DATA_DAMAGE:          m_uiDataDamage     = uiData; break;   
                }
            }

            uint32 GetData(uint32 uiType)
            {
                switch(uiType)
                {
                    case DATA_XERESTRASZA:     return m_uiXerestrasza;    break;
                    case DATA_TWILIGHT_HALION: return m_uiTwilightHalion; break;
                    case DATA_DAMAGE:          return m_uiDataDamage;     break;
                }
                return 0;
            }

            void BossZarithrian()
            {
                if (Creature* Zarithrian = instance->GetCreature(GetData64(DATA_ZARITHRIAN)))
                {
                    Zarithrian->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    Zarithrian->SetReactState(REACT_AGGRESSIVE);
                }
            }

            bool SetBossState(uint32 type, EncounterState state)
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_BALTHARUS:
                        if (state==DONE)
                        {
                            if (GetBossState(DATA_RAGEFIRE)==DONE)
                            {
                                BossZarithrian();
                            }
                        }
                        break;
                    case DATA_RAGEFIRE: 
                        if (state==DONE)
                        {
                            if (GetBossState(DATA_BALTHARUS)==DONE)
                            {
                                BossZarithrian();
                            }
                        }
                        break;
                    case DATA_ZARITHRIAN:
                        if (GetBossState(DATA_BALTHARUS)==DONE && GetBossState(DATA_RAGEFIRE)==DONE)
                        {
                            if (state==DONE)
                            {
                                if (Creature* halion = instance->GetCreature(GetData64(DATA_HALION)))
                                {
                                    halion->SummonCreature(NPC_SUMMON_HALIOH,SpawnPosHalion,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,20000);
                                }
                            }
                        }
                        break;
                    case DATA_HALION: break;
                }

                return true;
            }

            uint64 GetData64(uint32 uiData)
            {
                switch(uiData)
                {
                    case DATA_BALTHARUS:       return m_uiBaltharusGUID;      break;
                    case DATA_ZARITHRIAN:      return m_uiZarithrianGUID;     break;
                    case DATA_RAGEFIRE:        return m_uiRagefireGUID;       break;
                    case DATA_HALION:          return m_uiHalionGUID;         break;
                    case DATA_TWILIGHT_HALION: return m_uiTwilightHalionGUID; break;
                    case DATA_XERESTRASZA:     return m_uiXerestraszaGUID;    break;
                    case GO_TWILIGHT_PORTAL1:  return m_uiHalionPortalGUID;   break;
                    case GO_TWILIGHT_PORTAL2:  return m_uiTwilightPortalGUID; break;
                    case GO_FLAME_WALLS2:      return m_uiGOFlameWallsGUID;   break; 
                    case GO_FLAME_WALLS3:      return m_uiGOTwilightWallsGUID;   break; 
                    default: break;
                }
                return 0;
            }

            std::string GetSaveData()
            {
                std::ostringstream saveStream;
                saveStream << GetBossSaveData() << " " << m_uiXerestrasza;
                return saveStream.str();
            }

            void Load(const char* strIn)
            {
                if (!strIn)
                {
                    return;
                }

                std::istringstream loadStream(strIn);

                uint32 tmpState;
                
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                {
                    loadStream >> tmpState;
                    if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                        tmpState = NOT_STARTED;
                    SetBossState(i, EncounterState(tmpState));
                }

                loadStream >> m_uiXerestrasza;
            }

            private:
                uint32 m_uiXerestrasza;
                uint32 m_uiTwilightHalion;
                uint32 m_uiDataDamage;

                uint64 m_uiBaltharusGUID;
                uint64 m_uiZarithrianGUID;
                uint64 m_uiRagefireGUID;
                uint64 m_uiHalionGUID;
                uint64 m_uiXerestraszaGUID;
                uint64 m_uiTwilightHalionGUID;
                uint64 m_uiHalionPortalGUID;
                uint64 m_uiTwilightPortalGUID;
                uint64 m_uiGOFlameWallsGUID;
                uint64 m_uiGOTwilightWallsGUID;
        };
        
        InstanceScript* GetInstanceScript (InstanceMap *pMap) const
        {
            return new instance_ruby_sanctum_InstanceMapScript(pMap);
        }
};


void AddSC_instance_ruby_sanctum()
{
    new instance_ruby_sanctum;
}
