/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
SDName: Instance_Shadowfang_Keep
SD%Complete: 60%
SDComment:
SDCategory: Shadowfang Keep
EndScriptData */

#include "ScriptMgr.h"
#include "shadowfang_keep.h"
#include "GameObject.h"

class instance_shadowfang_keep : public InstanceMapScript
{
public:
    instance_shadowfang_keep() : InstanceMapScript("instance_shadowfang_keep", 33) { }

    struct instance_shadowfang_keep_InstanceMapScript: public InstanceScript
    {
        instance_shadowfang_keep_InstanceMapScript(InstanceMap* map): InstanceScript(map)  { }

        void Initialize() override
        {
            SetBossNumber(MAX_ENCOUNTER);
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case BOSS_BARON_ASHBURY:
                    BaronAshburyGUID        = creature->GetGUID();
                    break;
                case BOSS_BARON_SILVERLAINE:
                    BaronSilverlaineGUID    = creature->GetGUID();
                    break;
                case BOSS_COMMANDER_SPRINGVALE:
                    CommanderSpringvaleGUID = creature->GetGUID();
                    break;
                case BOSS_LORD_GODFREY:
                    LordGodfreyGUID         = creature->GetGUID();
                    break;
                case BOSS_LORD_WALDEN:
                    LordWaldenGUID          = creature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch(go->GetEntry())
            {
                case GO_BARON_ASHBURY_DOOR: doorBaronAshbury    = go->GetGUID(); break;
                case GO_LORD_GODFREY_DOOR: doorGodfrey          = go->GetGUID(); break;
                case GO_LORD_WALDEN_DOOR: doorLordWalden        = go->GetGUID(); break;
            }
        }

        void OnPlayerEnter(Player* player) override
        {
            if (!TeamInInstance)
                TeamInInstance = player->GetTeam();
        }

        uint32 GetData(uint32 identifier) const override 
        {
            if (identifier == TEAM_IN_INSTANCE)
                return TeamInInstance;

            return 0;
        }

        ObjectGuid GetGuidData(uint32 identifier) const override
        {
            switch (identifier)
            {
                case DATA_BARON_ASHBURY:
                    return BaronAshburyGUID;
                case DATA_BARON_SILVERLAINE:
                    return BaronSilverlaineGUID;
                case DATA_COMMANDER_SPRINGVALE:
                    return CommanderSpringvaleGUID;
                case DATA_LORD_GODFREY:
                    return LordGodfreyGUID;
                case DATA_LORD_WALDEN:
                    return LordWaldenGUID;
                case GO_BARON_ASHBURY_DOOR:
                    return doorBaronAshbury;
                case GO_LORD_GODFREY_DOOR:
                    return doorGodfrey;
                case GO_LORD_WALDEN_DOOR:
                    return doorLordWalden;
            }
            return ObjectGuid::Empty;
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch(type)
            {
                case DATA_BARON_ASHBURY_EVENT:
                    if (state == DONE || state == FAIL)
                        HandleGameObject(doorBaronAshbury, true);
                    break;
                case DATA_LORD_GODFREY_EVENT:
                    if (state == DONE || state == FAIL)
                        HandleGameObject(doorGodfrey, true);
                    break;
                case DATA_LORD_WALDEN_EVENT:
                    if (state == DONE || state == FAIL)
                        HandleGameObject(doorLordWalden, true);
                    break;
                default:
                    break;
            }

            return true;
        }

        protected:
            uint32 TeamInInstance;

            ObjectGuid BaronAshburyGUID;
            ObjectGuid BaronSilverlaineGUID;
            ObjectGuid CommanderSpringvaleGUID;
            ObjectGuid LordGodfreyGUID;
            ObjectGuid LordWaldenGUID;

            ObjectGuid doorBaronAshbury;
            ObjectGuid doorGodfrey;
            ObjectGuid doorLordWalden;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_shadowfang_keep_InstanceMapScript(map);
    }
};

void AddSC_instance_shadowfang_keep()
{
    new instance_shadowfang_keep();
}
