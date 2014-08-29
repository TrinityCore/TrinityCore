/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "blackwing_descent.h"
#include "ScriptPCH.h"

#define MAX_ENCOUNTER 6

class instance_blackwing_descent : public InstanceMapScript
{
public:
    instance_blackwing_descent() : InstanceMapScript("instance_blackwing_descent", 669) { }

    struct instance_blackwing_descent_InstanceMapScript : public InstanceScript
    {
        instance_blackwing_descent_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            memset(&Encounter, 0, sizeof(Encounter));
        }

        // Magmaw
        uint64 uiMagmaw;
        uint64 uiMagmawsHead;

        // Omnotron Defense System
        uint64 uiOmnotron;
        uint64 uiArcanotron;
        uint64 uiElectron;
        uint64 uiMagmatron;
        uint64 uiToxitron;

        // Maloriak
        uint64 uiMaloriak;

        // Atramedes
        uint64 uiAtramedes;
        uint64 uiPreNefarian;
        uint64 uiPreAtramedes;

        // Chimaeron
        uint64 uiChimaeron;
        uint64 uiBileOTron;
        uint64 uiFinkleEinhorn;

        // Nefarian
        uint64 uiNefarian;
        uint64 uiOnyxia;

        // Misc
        uint32 uiEncounter[MAX_ENCOUNTER];
        uint64 uiLordVictorNefarian;

        // Gobs
        uint64 gobPreBossDoor;
        uint64 gobMaloriaksCauldron;
        uint64 gobAtramedesBossDoor;
        uint64 gobOnyxiaPlatform;

        void Initialize()
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                uiEncounter[i] = NOT_STARTED;

            // Magmaw
            uiMagmaw = 0;
            uiMagmawsHead = 0;

            // Omnotron Defense System
            uiOmnotron = 0;
            uiArcanotron = 0;
            uiElectron = 0;
            uiMagmatron = 0;
            uiToxitron = 0;

            // Maloriak
            uiMaloriak = 0;

            // Atramedes
            uiAtramedes = 0;
            uiPreNefarian = 0;
            uiPreAtramedes = 0;

            // Chimaeron
            uiChimaeron = 0;
            uiBileOTron = 0;
            uiFinkleEinhorn = 0;

            // Nefarian
            uiNefarian = 0;
            uiOnyxia = 0;

            // Misc
            uiLordVictorNefarian = 0;

            // Gobs
            gobPreBossDoor = 0;
            gobMaloriaksCauldron = 0;
            gobAtramedesBossDoor = 0;
            gobOnyxiaPlatform = 0;
        }

        bool IsEncounterInProgress() const
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (uiEncounter[i] == IN_PROGRESS)
                    return true;

            return false;
        }

        void OnCreatureCreate(Creature* creature, bool /*add*/)
        {
            switch (creature->GetEntry())
            {

                // Magmaw
            case BOSS_MAGMAW:
                uiMagmaw = creature->GetGUID();
                break;
            case NPC_MAGMAWS_HEAD:
                uiMagmawsHead = creature->GetGUID();
                break;

                // Omnotron Defense System
            case BOSS_OMNOTRON:
                uiOmnotron = creature->GetGUID();
                break;
            case NPC_ARCANOTRON:
                uiArcanotron = creature->GetGUID();
                break;
            case NPC_ELECTRON:
                uiElectron = creature->GetGUID();
                break;
            case NPC_MAGMATRON:
                uiMagmatron = creature->GetGUID();
                break;
            case NPC_TOXITRON:
                uiToxitron = creature->GetGUID();
                break;

                // Maloriak
            case BOSS_MALORIAK:
                uiMaloriak = creature->GetGUID();
                break;

                // Atramedes
            case BOSS_ATRAMEDES:
                uiAtramedes = creature->GetGUID();
                break;
            case NPC_PRE_NEFARIAN:
                uiPreNefarian = creature->GetGUID();
                break;
            case NPC_PRE_ATRAMEDES:
                uiPreAtramedes = creature->GetGUID();
                break;

                // Chimaeron
            case BOSS_CHIMAERON:
                uiChimaeron = creature->GetGUID();
                break;
            case NPC_BILE_O_TRON:
                uiBileOTron = creature->GetGUID();
                break;
            case NPC_FINKLE_EINHORN:
                uiFinkleEinhorn = creature->GetGUID();
                break;

                // Nefarian
            case BOSS_NEFARIAN:
                uiNefarian = creature->GetGUID();
                break;
            case NPC_ONYXIA:
                uiOnyxia = creature->GetGUID();
                break;

                // Misc
            case NPC_LORD_VICTOR_NEFARIAN:
                uiLordVictorNefarian = creature->GetGUID();
                break;
            }
        }

        void OnGameObjectCreate(GameObject* go, bool /*add*/)
        {
            switch(go->GetEntry())
            {
            case GOB_DOOR_PRE_BOSSES:
                gobPreBossDoor = go->GetGUID();
                HandleGameObject(NULL, (GetData(DATA_MAGMAW)==DONE) && (GetData(DATA_OMNOTRON_DEFENSE_SYSTEM)==DONE), go);
                break;

            case GOB_MALORIAKS_CAULDRON:
                gobMaloriaksCauldron = go->GetGUID();
                break;

            case GOB_DOOR_ATRAMEDES:
                gobAtramedesBossDoor = go->GetGUID();
                HandleGameObject(NULL, (GetData(DATA_MALORIAK)==DONE) && (GetData(DATA_CHIMAERON)==DONE), go);
                break;

            case GOB_ONYXIA_PLATFORM:
                gobOnyxiaPlatform = go->GetGUID();
                //go->SetPhaseMask(GetData(DATA_ATRAMEDES)==DONE ? 1 : 2, true);
                break;
            }
        }

        uint64 GetData64(uint32 identifier)
        {
            switch(identifier)
            {
            case BOSS_MAGMAW:
                return uiMagmaw;
                break;
            case NPC_MAGMAWS_HEAD:
                return uiMagmawsHead;
                break;

                // Omnotron Defense System
            case BOSS_OMNOTRON:
                return uiOmnotron;
                break;
            case NPC_ARCANOTRON:
                return uiArcanotron;
                break;
            case NPC_ELECTRON:
                return uiElectron;
                break;
            case NPC_MAGMATRON:
                return uiMagmatron;
                break;
            case NPC_TOXITRON:
                return uiToxitron;
                break;

                // Maloriak
            case BOSS_MALORIAK:
                return uiMaloriak;
                break;

                // Atramedes
            case BOSS_ATRAMEDES:
                return uiAtramedes;
                break;
            case NPC_PRE_NEFARIAN:
                return uiPreNefarian;
                break;
            case NPC_PRE_ATRAMEDES:
                return uiPreAtramedes;
                break;

                // Chimaeron
            case BOSS_CHIMAERON:
                return uiChimaeron;
                break;
            case NPC_BILE_O_TRON:
                return uiBileOTron;
                break;
            case NPC_FINKLE_EINHORN:
                return uiFinkleEinhorn;
                break;

                // Nefarian
            case BOSS_NEFARIAN:
                return uiNefarian;
                break;
            case NPC_ONYXIA:
                return uiOnyxia;
                break;

                // Misc
            case NPC_LORD_VICTOR_NEFARIAN:
                return uiLordVictorNefarian;
                break;

            }

            return NULL;
        }

        uint32 GetData(uint32 type)
        {
            return Encounter[type];
        }

        bool SetBossState(uint32 data, EncounterState state) {
            if (!InstanceScript::SetBossState(data, state))
                return false;

            if(state == DONE)
            {
                switch(data)
                {
                case DATA_MAGMAW:
                case DATA_OMNOTRON_DEFENSE_SYSTEM:
                    HandleGameObject(gobPreBossDoor, GetBossState(DATA_MAGMAW)==DONE && GetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM)==DONE);
                    break;

                case DATA_MALORIAK:
                case DATA_CHIMAERON:
                    HandleGameObject(gobAtramedesBossDoor, GetBossState(DATA_MALORIAK)==DONE && GetBossState(DATA_CHIMAERON)==DONE);
                    break;

                case DATA_ATRAMEDES:
                    if(GameObject* onyxiaPlatform = instance->GetGameObject(gobOnyxiaPlatform))
                        onyxiaPlatform->SetPhaseMask(PHASEMASK_NORMAL, true);
                    break;
                }
            }

            return true;
        }

       /*bool CheckRequiredBosses(uint32 bossId, Player const* player = NULL) const
       {
            if ((player->GetSession()->GetSecurity() > SEC_GAMEMASTER ))
                return true;

            switch (bossId)
            {

            }

            return true;
        }*/

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "B D" << GetBossSaveData();

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

            if (dataHead1 == 'B' && dataHead2 == 'D')
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                {
                    uint32 tmpState;
                    loadStream >> tmpState;
                    if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                        tmpState = NOT_STARTED;
                    Encounter[i] = tmpState;
                }
            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }

    private:
        uint32 Encounter[MAX_ENCOUNTER];
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_blackwing_descent_InstanceMapScript(map);
    }
};

void AddSC_instance_blackwing_descent()
{
    new instance_blackwing_descent();
}