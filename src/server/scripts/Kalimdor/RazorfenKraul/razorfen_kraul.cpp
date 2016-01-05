/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2013 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "razorfen_kraul.h"
#include "Player.h"
#include "PetAI.h"
#include "SpellScript.h"

enum Willix
{
    SAY_READY                   = 0,
    SAY_POINT                   = 1,
    SAY_AGGRO1                  = 2,
    SAY_BLUELEAF                = 3,
    SAY_DANGER                  = 4,
    SAY_BAD                     = 5,
    SAY_THINK                   = 6,
    SAY_SOON                    = 7,
    SAY_FINALY                  = 8,
    SAY_WIN                     = 9,
    SAY_END                     = 10,

    QUEST_WILLIX_THE_IMPORTER   = 1144,
    ENTRY_BOAR                  = 4514
};

class npc_willix : public CreatureScript
{
public:
    npc_willix() : CreatureScript("npc_willix") { }

    struct npc_willixAI : public npc_escortAI
    {
        npc_willixAI(Creature* creature) : npc_escortAI(creature) { }

        void sQuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_WILLIX_THE_IMPORTER)
            {
                Start(true, false, player->GetGUID());
                Talk(SAY_READY, player);
                me->setFaction(113);
            }
        }

        void WaypointReached(uint32 waypointId) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 3:
                    me->HandleEmoteCommand(EMOTE_STATE_POINT);
                    Talk(SAY_POINT, player);
                    break;
                case 4:
                    me->SummonCreature(ENTRY_BOAR, 2137.66f, 1843.98f, 48.08f, 1.54f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    break;
                case 8:
                    Talk(SAY_BLUELEAF, player);
                    break;
                case 9:
                    Talk(SAY_DANGER, player);
                    break;
                case 13:
                    Talk(SAY_BAD, player);
                    break;
                case 14:
                    me->SummonCreature(ENTRY_BOAR, 2078.91f, 1704.54f, 56.77f, 1.54f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    break;
                case 25:
                    Talk(SAY_THINK, player);
                    break;
                case 31:
                    Talk(SAY_SOON, player);
                    break;
                case 42:
                    Talk(SAY_FINALY, player);
                    break;
                case 43:
                    me->SummonCreature(ENTRY_BOAR, 1956.43f, 1596.97f, 81.75f, 1.54f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    break;
                case 45:
                    Talk(SAY_WIN, player);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    player->GroupEventHappens(QUEST_WILLIX_THE_IMPORTER, me);
                    break;
                case 46:
                    Talk(SAY_END, player);
                    break;
            }
        }

        void Reset() override { }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO1);
        }

        void JustSummoned(Creature* summoned) override
        {
            summoned->AI()->AttackStart(me);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Player* player = GetPlayerForEscort())
                player->FailQuest(QUEST_WILLIX_THE_IMPORTER);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_willixAI(creature);
    }
};

void AddSC_razorfen_kraul()
{
    new npc_willix();
}
