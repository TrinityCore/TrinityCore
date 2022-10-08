/*
 * Copyright (C) 2022 BfaCore Reforged
 * Copyright (C) 2010 - 2012 ProjectSkyfire <http://www.projectskyfire.org/>
 *
 * Copyright (C) 2011 - 2012 ArkCORE <http://www.arkania.net/>
 *
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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
#include "hour_of_twilight.h"
#include "InstanceScript.h"
#include "TemporarySummon.h"
#include "GameObject.h"

#define ENCOUNTERS 3

/* Boss Encounters
    Arcurion
    Asira Dawnslayer
    Archbishop Benedictus
 */

class instance_hour_of_twilight : public InstanceMapScript
{
public:
    instance_hour_of_twilight() : InstanceMapScript("instance_hour_of_twilight", 940) // CHANGE THIS MAPID!!!
    { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_hour_of_twilight_InstanceMapScript(map);
    }

    struct instance_hour_of_twilight_InstanceMapScript: public InstanceScript
    {
        instance_hour_of_twilight_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

        uint32 uiEncounter[ENCOUNTERS];

        ObjectGuid uiAsira;
        ObjectGuid uiArcurion;
        ObjectGuid uiArchbishop;
        ObjectGuid uiThrall;
        ObjectGuid uiThrallSecond;
        ObjectGuid uiThrallFinal;
        ObjectGuid iceWallGUID;
        uint32 uiTeamInInstance;
        uint32 totalTrash;
        char msg[500];

        void Initialize() override
        {
            totalTrash = 0;

            for (uint8 i = 0; i < ENCOUNTERS; ++i)
                uiEncounter[i] = NOT_STARTED;
        }

        bool IsEncounterInProgress() const override 
        {
            for (uint8 i = 0; i < ENCOUNTERS; ++i)
            {
                if (uiEncounter[i] == IN_PROGRESS)
                    return true;
            }
            return false;
        }

        void OnPlayerEnter(Player* player) override
        {
            if (!uiTeamInInstance)
                uiTeamInInstance = player->GetTeam();
        }

        void OnCreatureCreate(Creature* pCreature) override
        {
            switch (pCreature->GetEntry())
            {
                case BOSS_ARCURION:
                    uiArcurion = pCreature->GetGUID();
                    break;
                case BOSS_ASIRA_DAWNSLAYER:
                    uiAsira = pCreature->GetGUID();
                    break;
                case BOSS_ARCHBISHOP_BENEDICTUS:
                    uiArchbishop = pCreature->GetGUID();
                    break;
                case NPC_THRALL:
                    uiThrall = pCreature->GetGUID();
                    break;
                case NPC_THRALL_SECOND:
                    uiThrallSecond = pCreature->GetGUID();
                    break;
                case NPC_THRALL_FINAL:
                    uiThrallFinal = pCreature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_ICE_WALL:
                    iceWallGUID = go->GetGUID();
                    break;
                case GO_HOLY_WALL:
                    if (uiEncounter[2] == DONE || uiEncounter[2] == NOT_STARTED)
                        HandleGameObject(go->GetGUID(), true, go);
                    break;
            }
        }

        ObjectGuid GetGuidData(uint32 identifier) const override
        {
            switch (identifier)
            {
                case DATA_ARCURION:
                    return uiArcurion;
                case DATA_ASIRA_DAWNSLAYER:
                    return uiAsira;
                case DATA_ARCHBISHOP_BENEDICTUS:
                    return uiArchbishop;
                case DATA_THRALL:
                    return uiThrall;
                case DATA_THRALL_SECOND:
                    return uiThrallSecond;
                case DATA_THRALL_FINAL:
                    return uiThrallFinal;

            }
            return ObjectGuid::Empty;
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_TRASH_KILLED:
                    return totalTrash;
                case DATA_ARCURION:
                    return uiEncounter[0];
                case DATA_ASIRA_DAWNSLAYER:
                    return uiEncounter[1];
                case DATA_ARCHBISHOP_BENEDICTUS:
                    return uiEncounter[2];
                default:
                    break;
            }
            return 0;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_ARCURION:
                    uiEncounter[0] = data;

                    /*if(uiEncounter[0] == IN_PROGRESS)
                    {
                        if (Creature* thrall = instance->GetCreature(uiThrall))
                        {
                            //thrall->AI()->DoAction(ACTION_START_ARCURION);
                        }
                    }
                    else */if(uiEncounter[0] == DONE)
                    {
                        if (Creature* thrall = instance->GetCreature(uiThrall))
                        {
                            thrall->AI()->DoAction(ACTION_MOVE);
                            thrall->RemoveUnitFlag(UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                        }
                    }

                    break;
                case DATA_ASIRA_DAWNSLAYER:
                    uiEncounter[1] = data;

                    if (uiEncounter[1] == IN_PROGRESS)
                    {
                        if (Creature* thrall = instance->GetCreature(uiThrallSecond))
                        {
                            thrall->AI()->DoAction(ACTION_START_ASIRA);
                        }
                    }
                    else if (uiEncounter[1] == DONE)
                    {
                        if (Creature* thrall = instance->GetCreature(uiThrallSecond))
                        {
                            thrall->AI()->DoAction(ACTION_MOVE);
                        }
                        if (Creature* thrallFinal = instance->GetCreature(uiThrallFinal))
                        {
                            thrallFinal->SetVisible(true);
                        }
                    }
                    break;
                case DATA_ARCHBISHOP_BENEDICTUS:
                    uiEncounter[2] = data;
                    if (uiEncounter[2] == IN_PROGRESS)
                    {
                        if (Creature* thrall = instance->GetCreature(uiThrallFinal))
                        {
                            thrall->AI()->DoAction(ACTION_START_BENEDICTUS);
                        }
                    }
                    break;
                case DATA_TRASH_KILLED:
                    totalTrash++;
                    break;
                case DATA_RESET_TOTALTRASH:
                    totalTrash = 0;
                    break;

            }

            if (data == DONE)
                SaveToDB();

            if (Creature* thrall = instance->GetCreature(uiThrall))
            {
                switch(totalTrash)
                {
                    case 2:
                        thrall->AI()->DoAction(ACTION_MOVE);
                        break;
                    case 5:
                        thrall->AI()->DoAction(ACTION_SUMMON_WAVE_3);
                        break;
                    case 13:
                        thrall->AI()->DoAction(ACTION_MOVE);
                        break;
                    case 14:
                        if (uiEncounter[0] != IN_PROGRESS && uiEncounter[0] != NOT_STARTED)
                        {
                            thrall->AI()->DoAction(ACTION_MOVE);
                        }
                        break;
                }
            }

            if (Creature* thrallSecond = instance->GetCreature(uiThrallSecond))
            {
                switch (totalTrash)
                {
                    case 18:
                        thrallSecond->AI()->DoAction(ACTION_MOVE);
                        break;
                    case 22:
                        thrallSecond->AI()->DoAction(ACTION_MOVE);
                        break;
                    case 26:
                        thrallSecond->AI()->DoAction(ACTION_MOVE);
                        break;
                    case 27:
                        if (uiEncounter[1] != IN_PROGRESS && uiEncounter[1] != NOT_STARTED)
                        {
                            thrallSecond->AI()->DoAction(ACTION_MOVE);
                        }
                        break;
                }
            }

            if (Creature* thrallFinal = instance->GetCreature(uiThrallFinal))
            {
                switch (totalTrash)
                {
                    case 30:
                        thrallFinal->AI()->DoAction(ACTION_MOVE);
                        break;
                    case 33:
                        thrallFinal->AI()->DoAction(ACTION_MOVE);
                        break;
                    case 36:
                        if (Creature* archbishop = instance->GetCreature(uiArchbishop))
                        {
                            archbishop->AI()->DoAction(ACTION_MOVE_BENEDICTUS);
                        }
                        break;
                }
            }

        }
    };
};

void AddSC_instance_hour_of_twilight()
{
    new instance_hour_of_twilight();
}
