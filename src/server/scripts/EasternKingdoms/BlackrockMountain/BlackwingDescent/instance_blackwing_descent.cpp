/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "GameObject.h"
#include "PhasingHandler.h"
#include "ScriptMgr.h"

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
        ObjectGuid uiMagmaw;
        ObjectGuid uiMagmawsHead;

        // Omnotron Defense System
        ObjectGuid uiOmnotron;
        ObjectGuid uiArcanotron;
        ObjectGuid uiElectron;
        ObjectGuid uiMagmatron;
        ObjectGuid uiToxitron;

        // Maloriak
        ObjectGuid uiMaloriak;

        // Atramedes
        ObjectGuid uiAtramedes;
        ObjectGuid uiPreNefarian;
        ObjectGuid uiPreAtramedes;

        // Chimaeron
        ObjectGuid uiChimaeron;
        ObjectGuid uiBileOTron;
        ObjectGuid uiFinkleEinhorn;

        // Nefarian
        ObjectGuid uiNefarian;
        ObjectGuid uiOnyxia;

        // Misc
        uint32 uiEncounter[MAX_ENCOUNTER];
        ObjectGuid uiLordVictorNefarian;
        uint32 uidrakonidCount;

        // Gobs
        ObjectGuid gobPreBossDoor;
        ObjectGuid gobMaloriaksCauldron;
        ObjectGuid gobAtramedesBossDoor;
        ObjectGuid gobOnyxiaPlatform;

        void Initialize() override
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                uiEncounter[i] = NOT_STARTED;

            // Misc
            uidrakonidCount = 0;
        }

        bool IsEncounterInProgress() const override 
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (uiEncounter[i] == IN_PROGRESS)
                    return true;

            return false;
        }

        void OnCreatureCreate(Creature* creature) override
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
            case NPC_DRAKONID_CHAIN:
                if(Creature * magmaw = instance->GetCreature(uiMagmaw))
                {
                    if(uidrakonidCount < 2)
                    {
                        magmaw->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
                        magmaw->SetReactState(REACT_PASSIVE);
                        if(creature->isDead())
                            SetData(DATA_DRAKONID, 1);
                    }
                }
                break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch(go->GetEntry())
            {
            case GOB_DOOR_PRE_BOSSES:
                gobPreBossDoor = go->GetGUID();
                HandleGameObject(ObjectGuid::Empty, (GetData(DATA_MAGMAW)==DONE) && (GetData(DATA_OMNOTRON_DEFENSE_SYSTEM)==DONE), go);
                break;

            case GOB_MALORIAKS_CAULDRON:
                gobMaloriaksCauldron = go->GetGUID();
                break;

            case GOB_DOOR_ATRAMEDES:
                gobAtramedesBossDoor = go->GetGUID();
                HandleGameObject(ObjectGuid::Empty, (GetData(DATA_MALORIAK)==DONE) && (GetData(DATA_CHIMAERON)==DONE), go);
                break;

            case GOB_ONYXIA_PLATFORM:
                gobOnyxiaPlatform = go->GetGUID();
                //go->SetPhaseMask(GetData(DATA_ATRAMEDES)==DONE ? 1 : 2, true);
                break;
            }
        }

        ObjectGuid GetGuidData(uint32 identifier) const override
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

            return ObjectGuid::Empty;
        }

        void SetData(uint32 type, uint32 /*value*/) override
        {
            switch(type)
            {
                case DATA_DRAKONID:
                    ++uidrakonidCount;
                    if(uidrakonidCount >= 2)
                    {
                        if(Creature * magmaw = instance->GetCreature(uiMagmaw))
                        {
                            magmaw->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
                            magmaw->SetReactState(REACT_AGGRESSIVE);
                        }
                    }
                    break;
            }
        }

        uint32 GetData(uint32 type) const override 
        {
            return Encounter[type];
        }

        bool SetBossState(uint32 data, EncounterState state) override
        {
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
                        PhasingHandler::ResetPhaseShift(onyxiaPlatform);
                    break;
                }
            }

            return true;
        }

    private:
        uint32 Encounter[MAX_ENCOUNTER];
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_blackwing_descent_InstanceMapScript(map);
    }
};

void AddSC_instance_blackwing_descent()
{
    new instance_blackwing_descent();
}
