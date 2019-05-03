/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
SDName: Sunken_Temple
SD%Complete: 100
SDComment: Area Trigger + Puzzle event support
SDCategory: Sunken Temple
EndScriptData */

/* ContentData
at_malfurion_Stormrage_trigger
EndContentData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "sunken_temple.h"

/*#####
# at_malfurion_Stormrage_trigger
#####*/

enum MalfurionMisc
{
    NPC_MALFURION_STORMRAGE           = 15362,
    QUEST_ERANIKUS_TYRANT_OF_DREAMS   = 8733,
    QUEST_THE_CHARGE_OF_DRAGONFLIGHTS = 8555,
};

class at_malfurion_stormrage : public AreaTriggerScript
{
    public:
        at_malfurion_stormrage() : AreaTriggerScript("at_malfurion_stormrage") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*at*/) override
        {
            if (player->GetInstanceScript() && !player->FindNearestCreature(NPC_MALFURION_STORMRAGE, 15.0f) &&
                player->GetQuestStatus(QUEST_THE_CHARGE_OF_DRAGONFLIGHTS) == QUEST_STATUS_REWARDED && player->GetQuestStatus(QUEST_ERANIKUS_TYRANT_OF_DREAMS) != QUEST_STATUS_REWARDED)
                player->SummonCreature(NPC_MALFURION_STORMRAGE, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), -1.52f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 100000);
            return false;
        }
};

/*#####
# go_atalai_statue
#####*/

class go_atalai_statue : public GameObjectScript
{
    public:
        go_atalai_statue() : GameObjectScript("go_atalai_statue") { }

        struct go_atalai_statueAI : public GameObjectAI
        {
            go_atalai_statueAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

            InstanceScript* instance;

            bool GossipHello(Player* /*player*/) override
            {
                instance->SetData(EVENT_STATE, me->GetEntry());
                return false;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetSunkenTempleAI<go_atalai_statueAI>(go);
        }
};

void AddSC_sunken_temple()
{
    new at_malfurion_stormrage();
    new go_atalai_statue();
}
