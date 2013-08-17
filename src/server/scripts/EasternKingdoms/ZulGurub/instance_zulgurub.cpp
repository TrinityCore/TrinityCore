/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
SDName: Instance_ZulGurub
SD%Complete: 80
SDComment: Missing reset function after killing a boss for Ohgan, Thekal.
SDCategory: Zul'Gurub
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "zulgurub.h"

class instance_zulgurub : public InstanceMapScript
{
    public: instance_zulgurub(): InstanceMapScript(ZGScriptName, 309) {}

        struct instance_zulgurub_InstanceMapScript : public InstanceScript
        {
            instance_zulgurub_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
            }

            void Initialize() OVERRIDE
            {
                _zealotLorkhanGUID = 0;
                _zealotZathGUID = 0;
                _highPriestTekalGUID = 0;
                _jindoTheHexxerGUID = 0;
                _vilebranchSpeakerGUID = 0;
                _arlokkGUID = 0;
                _goForcefieldGUID = 0;
                _goGongOfBethekkGUID = 0;
            }

            bool IsEncounterInProgress() const OVERRIDE
            {
                // not active in Zul'Gurub
                return false;
            }

            void OnCreatureCreate(Creature* creature) OVERRIDE
            {
                switch (creature->GetEntry())
                {
                    case NPC_ZEALOT_LORKHAN:
                        _zealotLorkhanGUID = creature->GetGUID();
                        break;
                    case NPC_ZEALOT_ZATH:
                        _zealotZathGUID = creature->GetGUID();
                        break;
                    case NPC_HIGH_PRIEST_THEKAL:
                        _highPriestTekalGUID = creature->GetGUID();
                        break;
                    case NPC_JINDO_THE_HEXXER:
                        _jindoTheHexxerGUID = creature->GetGUID();
                        break;
                    case NPC_VILEBRANCH_SPEAKER:
                        _vilebranchSpeakerGUID = creature->GetGUID();
                        break;
                    case NPC_ARLOKK:
                        _arlokkGUID = creature->GetGUID();
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) OVERRIDE
            {
                switch (go->GetEntry())
                {
                    case GO_FORCEFIELD:
                        _goForcefieldGUID = go->GetGUID();
                        break;
                    case GO_GONG_OF_BETHEKK:
                        _goGongOfBethekkGUID = go->GetGUID();
                        if (GetBossState(DATA_ARLOKK) == DONE)
                            go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        else
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    default:
                        break;
                }
            }

            uint64 GetData64(uint32 uiData) const OVERRIDE
            {
                switch (uiData)
                {
                    case DATA_LORKHAN:
                        return _zealotLorkhanGUID;
                        break;
                    case DATA_ZATH:
                        return _zealotZathGUID;
                        break;
                    case DATA_THEKAL:
                        return _highPriestTekalGUID;
                        break;
                    case DATA_JINDO:
                        return _jindoTheHexxerGUID;
                        break;
                    case NPC_ARLOKK:
                        return _arlokkGUID;
                        break;
                    case GO_FORCEFIELD:
                        return _goForcefieldGUID;
                        break;
                    case GO_GONG_OF_BETHEKK:
                        return _goGongOfBethekkGUID;
                        break;
                }
                return 0;
            }

            std::string GetSaveData() OVERRIDE
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "Z G " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(const char* str) OVERRIDE
            {
                if (!str)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(str);

                char dataHead1, dataHead2;

                std::istringstream loadStream(str);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'Z' && dataHead2 == 'G')
                {
                    for (uint32 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }
        private:
            //If all High Priest bosses were killed. Lorkhan, Zath and Ohgan are added too.
            //Storing Lorkhan, Zath and Thekal because we need to cast on them later. Jindo is needed for healfunction too.

            uint64 _zealotLorkhanGUID;
            uint64 _zealotZathGUID;
            uint64 _highPriestTekalGUID;
            uint64 _jindoTheHexxerGUID;
            uint64 _vilebranchSpeakerGUID;
            uint64 _arlokkGUID;
            uint64 _goForcefieldGUID;
            uint64 _goGongOfBethekkGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
        {
            return new instance_zulgurub_InstanceMapScript(map);
        }
};

void AddSC_instance_zulgurub()
{
    new instance_zulgurub();
}
