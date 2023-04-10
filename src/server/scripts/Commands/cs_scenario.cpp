/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "Chat.h"
#include "ScenarioMgr.h"
#include "Scenario.h"
#include "DBCEnums.h"

class scenario_commandscript : public CommandScript
{
public:
    scenario_commandscript() : CommandScript("scenario_commandscript") { }

    //std::vector<ChatCommand> GetCommands() const override
    //{
    //   /* static std::vector<ChatCommand> scenarioCommandTable =
    //    {
    //        {    "info",     SEC_GAMEMASTER, false,  &HandleScenarioInfoCommand, ""},
    //        {    "step",     SEC_GAMEMASTER, false,  &HandleScenarioStepCommand, ""}
    //    };

    //    static std::vector<ChatCommand> commandTable =
    //    {
    //        {  "scenario",   SEC_GAMEMASTER, false,                        NULL, "", scenarioCommandTable }
    //    };
    //    return commandTable;*/
    //}

    static std::string GetScenarioTypeString(uint8 /*type*/)
    {
       /* switch (type)
        {
            case SCENARIO_TYPE_DEFAULT:
                return "Scenario";
            case SCENARIO_TYPE_CHALLENGE_MODE:
                return "Challenge";
            case SCENARIO_TYPE_USE_DUNGEON_DISPLAY:
                return "Dungeon";
            case SCENARIO_TYPE_LEGION_INVASION:
                return "Raid";
            case SCENARIO_TYPE_BOOST_TUTORIAL:
                return "Solo";
            default:
                break;
        }*/

        return "Unknown";
    }

    static std::string GetScenarioDifficultyString(uint8 difficulty)
    {
        switch (difficulty)
        {
            case DIFFICULTY_N_SCENARIO:
                return "Normal";
            case DIFFICULTY_HC_SCENARIO:
                return "Heroic";
            default:
                break;
        }

        return "Unknown";
    }

    static bool HandleScenarioInfoCommand(ChatHandler* handler, char const* args)
    {
        Player* target = NULL;
        std::string playerName;
        if (!handler->extractPlayerTarget((char*)args, &target, NULL, &playerName))
            return false;

        Map* map = target->GetMap();
        if (!map)
            return false;

        InstanceMap* instance = map->ToInstanceMap();
        if (!instance)
        {
            handler->PSendSysMessage("Target is not in instance.");
            return false;
        }

       /* Scenario* progress = sScenarioMgr->GetScenario(instance->GetInstanceId());
        if (!progress)
        {
            handler->PSendSysMessage("There is no scenario progress for map %u instanceId %u", instance->GetInstanceId());
            return false;
        }*/

        /*ScenarioEntry const* scenario = sScenarioStore.LookupEntry(progress->GetScenarioId());
        handler->PSendSysMessage("ScenarioId: '%s' (%u) Current Step: %u Steps: %u (Completed: %s) (Completed: %s)",
            scenario->Name[DEFAULT_LOCALE].Str[DEFAULT_LOCALE], progress->GetScenarioId(), progress->GetCurrentStep(), progress->GetStepCount(false), progress->IsCompleted(false) ? "true" : "false",
            progress->IsCompleted(true) ? "true" : "false");
        handler->PSendSysMessage("Scenario Type: %s Difficulty: %s (%u)",*/
            //GetScenarioTypeString(scenario->Type).c_str(), GetScenarioDifficultyString(map->GetDifficultyID()).c_str(), map->GetDifficultyID());
        return true;
    }

    static bool HandleScenarioStepCommand(ChatHandler* handler, char const* /*args*/)
    {
        Player* player = handler->GetSession()->GetPlayer();
        //char* stepstr = strtok((char*)args, " ");
        //uint8 step = stepstr ? atoi(stepstr) : 0;

        Map* map = player->GetMap();
        if (!map)
            return false;

        InstanceMap* instance = map->ToInstanceMap();
        if (!instance)
        {
            handler->PSendSysMessage("Player is not in instance.");
            return false;
        }

        /*Scenario* progress = sScenarioMgr->GetScenario(instance->GetInstanceId());
        if (!progress)
        {
            handler->PSendSysMessage("There is no scenario progress for map %u instanceId %u", instance->GetInstanceId());
            return false;
        }

        progress->SetCurrentStep(step);*/
        return true;
    }
};

void AddSC_scenario_commandscript()
{
    //new scenario_commandscript();
}
