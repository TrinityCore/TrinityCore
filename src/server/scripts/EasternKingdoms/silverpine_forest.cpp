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
SDName: Silverpine_Forest
SD%Complete: 100
SDComment: Quest support: 435
SDCategory: Silverpine Forest
EndScriptData */

/* ContentData
npc_deathstalker_erland
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "Player.h"

/*######
## npc_deathstalker_erland
######*/

enum eErland
{
    SAY_QUESTACCEPT     = -1000306,
    SAY_START           = -1000307,
    SAY_AGGRO_1         = -1000308,
    SAY_AGGRO_2         = -1000309,
    SAY_LAST            = -1000310,

    SAY_THANKS          = -1000311,
    SAY_RANE            = -1000312,
    SAY_ANSWER          = -1000313,
    SAY_MOVE_QUINN      = -1000314,

    SAY_GREETINGS       = -1000315,
    SAY_QUINN           = -1000316,
    SAY_ON_BYE          = -1000317,

    QUEST_ESCORTING     = 435,
    NPC_RANE            = 1950,
    NPC_QUINN           = 1951
};

class npc_deathstalker_erland : public CreatureScript
{
public:
    npc_deathstalker_erland() : CreatureScript("npc_deathstalker_erland") { }

    struct npc_deathstalker_erlandAI : public npc_escortAI
    {
        npc_deathstalker_erlandAI(Creature* creature) : npc_escortAI(creature) {}

        void WaypointReached(uint32 waypointId)
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 1:
                    DoScriptText(SAY_START, me, player);
                    break;
                case 13:
                    DoScriptText(SAY_LAST, me, player);
                    player->GroupEventHappens(QUEST_ESCORTING, me);
                    break;
                case 14:
                    DoScriptText(SAY_THANKS, me, player);
                    break;
                case 15:
                    if (Unit* Rane = me->FindNearestCreature(NPC_RANE, 20))
                        DoScriptText(SAY_RANE, Rane);
                    break;
                case 16:
                    DoScriptText(SAY_ANSWER, me);
                    break;
                case 17:
                    DoScriptText(SAY_MOVE_QUINN, me);
                    break;
                case 24:
                    DoScriptText(SAY_GREETINGS, me);
                    break;
                case 25:
                    if (Unit* Quinn = me->FindNearestCreature(NPC_QUINN, 20))
                        DoScriptText(SAY_QUINN, Quinn);
                    break;
                case 26:
                    DoScriptText(SAY_ON_BYE, me, NULL);
                    break;
            }
        }

        void Reset() {}

        void EnterCombat(Unit* who)
        {
            DoScriptText(RAND(SAY_AGGRO_1, SAY_AGGRO_2), me, who);
        }
    };

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_ESCORTING)
        {
            DoScriptText(SAY_QUESTACCEPT, creature, player);

            if (npc_escortAI* pEscortAI = CAST_AI(npc_deathstalker_erland::npc_deathstalker_erlandAI, creature->AI()))
                pEscortAI->Start(true, false, player->GetGUID());
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_deathstalker_erlandAI(creature);
    }
};

/*######
## AddSC
######*/

void AddSC_silverpine_forest()
{
    new npc_deathstalker_erland();
}
