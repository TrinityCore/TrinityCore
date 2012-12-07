/*
* Copyright (C) 2011-2012 Project SkyFire <http://www.projectskyfire.org/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License,  or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful,  but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not,  see <http://www.gnu.org/licenses/>.
*/

#include "ScriptPCH.h"

class npc_lodestone : public CreatureScript
{
    public:
        npc_lodestone() : CreatureScript("npc_lodestone") { }

    struct npc_lodestoneAI : public ScriptedAI
    {
        npc_lodestoneAI(Creature* creature) : ScriptedAI(creature) { }

        void JustDied(Unit* killer)
        {
            if (Player* player = killer->ToPlayer())
            {
                if (player->GetQuestStatus(27136) == QUEST_STATUS_INCOMPLETE)
                {
                    if (Creature* totem = me->FindNearestCreature(45088, 20.0f, true))
                    {
                        totem->CastSpell(totem, 84163, true);
                        player->KilledMonsterCredit(45091, 0);
                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature *creature) const
    {
        return new npc_lodestoneAI(creature);
    }
};

#define CREW_SAY_1 "They poisoned our supplies... we had cultists onboard all along..."
#define CREW_SAY_2 "Everyone started dropping like flies... everyone who ate the rations."
#define CREW_SAY_3 "They tricked us into ambushing the Horde gunship... but why?"
#define CREW_SAY_4 "I heard them praying to their dark gods as everything went black... the Twilight's Hammer did this!"
#define CREW_SAY_5 "Twilight scum! You did this to us!"
class npc_slaincrewmember : public CreatureScript
{
    public:
        npc_slaincrewmember() : CreatureScript("npc_slaincrewmember") { }

    struct npc_slaincrewmemberAI : public ScriptedAI
    {
        npc_slaincrewmemberAI(Creature* creature) : ScriptedAI(creature) { }

        uint64 playerGUID;
        bool QuestInProgress;
        uint32 sayTimer;

        void Reset()
        {
            playerGUID = 0;
            QuestInProgress = false;
            sayTimer = 3000;
        }
        void SetData(uint32 Id,  uint32 Value)
        {
            switch (Id)
            {
                case 1: // Set the GUID of the player
                {
                    playerGUID = Value;
                    QuestInProgress = true;
                    break;
                }
            }
        }
        void UpdateAI(uint32 const diff)
        {
            if(!QuestInProgress)
                return;

            Player* player = Unit::GetPlayer(*me, playerGUID);

            if(!player)
                return;

            if (sayTimer <= diff)
            {
                switch (RAND(0, 1, 2, 3, 4))
                {
                    case 0:
                        me->MonsterSay(CREW_SAY_1, LANG_UNIVERSAL, NULL);
                        player->KilledMonsterCredit(42758, 0);
                        QuestInProgress = false;
                        break;
                    case 1:
                        me->MonsterSay(CREW_SAY_2, LANG_UNIVERSAL, NULL);
                        player->KilledMonsterCredit(42758, 0);
                        QuestInProgress = false;
                        break;
                    case 2:
                        me->MonsterSay(CREW_SAY_3, LANG_UNIVERSAL, NULL);
                        player->KilledMonsterCredit(42758, 0);
                        QuestInProgress = false;
                        break;
                    case 3:
                        me->MonsterSay(CREW_SAY_4, LANG_UNIVERSAL, NULL);
                        player->KilledMonsterCredit(42758, 0);
                        QuestInProgress = false;
                        break;
                    case 4:
                        me->MonsterSay(CREW_SAY_5, LANG_UNIVERSAL, NULL);
                        me->setFaction(14);
                        me->AddThreat(player, 53.0f);
                        me->AI()->AttackStart(player);
                        QuestInProgress = false;
                        break;
                }
            }
            else sayTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_slaincrewmemberAI(creature);
    }
};
void AddSC_deepholm()
{
    new npc_lodestone();
    new npc_slaincrewmember();
}
