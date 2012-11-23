/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
SDName: Razorfen Kraul
SD%Complete: 100
SDComment: Quest support: 1144
SDCategory: Razorfen Kraul
EndScriptData */

/* ContentData
npc_willix
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "razorfen_kraul.h"
#include "Player.h"

#define SAY_READY -1047000
#define SAY_POINT -1047001
#define SAY_AGGRO1 -1047002
#define SAY_BLUELEAF -1047003
#define SAY_DANGER -1047004
#define SAY_BAD -1047005
#define SAY_THINK -1047006
#define SAY_SOON -1047007
#define SAY_FINALY -1047008
#define SAY_WIN -1047009
#define SAY_END -1047010

#define QUEST_WILLIX_THE_IMPORTER 1144
#define ENTRY_BOAR 4514

class npc_willix : public CreatureScript
{
public:
    npc_willix() : CreatureScript("npc_willix") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_WILLIX_THE_IMPORTER)
        {
            CAST_AI(npc_escortAI, (creature->AI()))->Start(true, false, player->GetGUID());
            DoScriptText(SAY_READY, creature, player);
            creature->setFaction(113);
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_willixAI(creature);
    }

    struct npc_willixAI : public npc_escortAI
    {
        npc_willixAI(Creature* creature) : npc_escortAI(creature) {}

        void WaypointReached(uint32 waypointId)
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 3:
                    me->HandleEmoteCommand(EMOTE_STATE_POINT);
                    DoScriptText(SAY_POINT, me, player);
                    break;
                case 4:
                    me->SummonCreature(ENTRY_BOAR, 2137.66f, 1843.98f, 48.08f, 1.54f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    break;
                case 8:
                    DoScriptText(SAY_BLUELEAF, me, player);
                    break;
                case 9:
                    DoScriptText(SAY_DANGER, me, player);
                    break;
                case 13:
                    DoScriptText(SAY_BAD, me, player);
                    break;
                case 14:
                    me->SummonCreature(ENTRY_BOAR, 2078.91f, 1704.54f, 56.77f, 1.54f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    break;
                case 25:
                    DoScriptText(SAY_THINK, me, player);
                    break;
                case 31:
                    DoScriptText(SAY_SOON, me, player);
                    break;
                case 42:
                    DoScriptText(SAY_FINALY, me, player);
                    break;
                case 43:
                    me->SummonCreature(ENTRY_BOAR, 1956.43f, 1596.97f, 81.75f, 1.54f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    break;
                case 45:
                    DoScriptText(SAY_WIN, me, player);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    if (player->GetTypeId() == TYPEID_PLAYER)
                        CAST_PLR(player)->GroupEventHappens(QUEST_WILLIX_THE_IMPORTER, me);
                    break;
                case 46:
                    DoScriptText(SAY_END, me, player);
                    break;
            }
        }

        void Reset() {}

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO1, me, NULL);
        }

        void JustSummoned(Creature* summoned)
        {
            summoned->AI()->AttackStart(me);
        }

        void JustDied(Unit* /*killer*/)
        {
            if (Player* player = GetPlayerForEscort())
                CAST_PLR(player)->FailQuest(QUEST_WILLIX_THE_IMPORTER);
        }
    };

};

void AddSC_razorfen_kraul()
{
    new npc_willix();
}
