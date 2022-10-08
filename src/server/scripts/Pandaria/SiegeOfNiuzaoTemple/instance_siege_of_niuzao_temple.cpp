/*
 * Trinity Core and update by MoPCore Forums
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
 *
 * Dungeon: Siege of Niuzao Temple.
 * Description: Instance Script.
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"

#include "siege_of_niuzao_temple.h"

class instance_siege_of_niuzao_temple : public InstanceMapScript
{
    public:
        instance_siege_of_niuzao_temple() : InstanceMapScript("instance_siege_of_niuzao_temple", 1011) { }

        struct instance_siege_of_niuzao_temple_InstanceMapScript : public InstanceScript
        {
            instance_siege_of_niuzao_temple_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                Initialize();
            }

            // Bosses.
            uint64 uiVizierJinbak;
            uint64 uiCommanderVojak;
            uint64 uiGeneralPavalak;
            uint64 uiWingLeaderNeronok;

            void Initialize()
            {
                SetBossNumber(MAX_ENCOUNTERS);

                // Bosses.
                uiVizierJinbak = 0;
                uiCommanderVojak = 0;
                uiGeneralPavalak = 0;
                uiWingLeaderNeronok = 0;

                for (uint32 i = 0; i < MAX_ENCOUNTERS; ++i)
                    SetBossState(i, NOT_STARTED);
            }

            bool IsEncounterInProgress() const
            {
                for (uint32 i = 0; i < MAX_ENCOUNTERS; ++i)
                    if (GetBossState(i) == IN_PROGRESS)
                        return true;

                return false;
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch(creature->GetEntry())
                {
                    // Bosses.
                    case BOSS_VIZIER_JINBAK:
                        uiVizierJinbak = creature->GetGUID();
                        break;
                    case BOSS_COMMANDER_VOJAK:
                        uiCommanderVojak = creature->GetGUID();
                        break;
                    case BOSS_GENERAL_PAVALAK:
                        uiGeneralPavalak = creature->GetGUID();
                        break;
                    case BOSS_WING_LEADER_NERONOK:
                        uiWingLeaderNeronok = creature->GetGUID();
                        break;

                    default: break;
                }
            }

            /*
            void OnUnitDeath(Unit* killed)
            {
                if (killed->GetTypeId() == TYPEID_PLAYER) return;

                switch(killed->ToCreature()->GetEntry())
                {
                }
            }

            void OnGameObjectCreate(GameObject* go)
            {
                switch (go->GetEntry())
                {
                }
            }

            void OnGameObjectRemove(GameObject* go)
            {
                switch (go->GetEntry())
                {
                }
            }
            */

            void SetData(uint32 type, uint32 data)
            {
                SetBossState(type, EncounterState(data));

                if (data == DONE)
                    SaveToDB();
            }

            uint32 GetData(uint32 type)
            {
                return GetBossState(type);
            }

            uint64 GetData64(uint32 data)
            {
                switch(data)
                {
                    // Bosses.
                    case DATA_VIZIER_JINBAK:        return uiVizierJinbak;       break;
                    case DATA_COMMANDER_VOJAK:      return uiCommanderVojak;     break;
                    case DATA_GENERAL_PAVALAK:      return uiGeneralPavalak;     break;
                    case DATA_WING_LEADER_NERONOK:  return uiWingLeaderNeronok;  break;

                    default:                        return 0;                    break;
                }
            }

            bool SetBossState(uint32 data, EncounterState state)
            {
                if (!InstanceScript::SetBossState(data, state))
                    return false;

                if (state == DONE)
                {
                    switch(data)
                    {
                        case DATA_VIZIER_JINBAK_EVENT:
                        case DATA_COMMANDER_VOJAK_EVENT:
                        case DATA_GENERAL_PAVALAK_EVENT:
                        case DATA_WING_LEADER_NERONOK_EVENT:
                        break;
                    }
                }

                return true;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "S N " << GetBossSaveData();

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

                std::istringstream loadStream(in);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'S' && dataHead2 == 'N')
                {
                    for (uint32 i = 0; i < MAX_ENCOUNTERS; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
            
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
            
                        // Below makes the player on-instance-entry display of bosses killed shit work (SMSG_RAID_INSTANCE_INFO).
                        // Like, say an unbound player joins the party and he tries to enter the dungeon / raid.
                        // This makes sure binding-to-instance-on-entrance confirmation box will properly display bosses defeated / available.
                        SetBossState(i, EncounterState(tmpState));
                    }
                }
                else OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_siege_of_niuzao_temple_InstanceMapScript(map);
        }
};

void AddSC_instance_siege_of_niuzao_temple()
{
    new instance_siege_of_niuzao_temple();
}
