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
SDName: Arathi Highlands
SD%Complete: 100
SDComment: Quest support: 665
SDCategory: Arathi Highlands
EndScriptData */

/* ContentData
npc_professor_phizzlethorpe
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

/*######
## npc_professor_phizzlethorpe
######*/

enum eEnums
{
    SAY_PROGRESS_1      = -1000264,
    SAY_PROGRESS_2      = -1000265,
    SAY_PROGRESS_3      = -1000266,
    EMOTE_PROGRESS_4    = -1000267,
    SAY_AGGRO           = -1000268,
    SAY_PROGRESS_5      = -1000269,
    SAY_PROGRESS_6      = -1000270,
    SAY_PROGRESS_7      = -1000271,
    EMOTE_PROGRESS_8    = -1000272,
    SAY_PROGRESS_9      = -1000273,

    QUEST_SUNKEN_TREASURE   = 665,
    MOB_VENGEFUL_SURGE      = 2776
};

class npc_professor_phizzlethorpe : public CreatureScript
{
    public:

        npc_professor_phizzlethorpe()
            : CreatureScript("npc_professor_phizzlethorpe")
        {
        }

        struct npc_professor_phizzlethorpeAI : public npc_escortAI
        {
            npc_professor_phizzlethorpeAI(Creature* c) : npc_escortAI(c) {}

            void WaypointReached(uint32 uiPointId)
            {
                Player* player = GetPlayerForEscort();

                if (!player)
                    return;

                switch (uiPointId)
                {
                case 4:DoScriptText(SAY_PROGRESS_2, me, player);break;
                case 5:DoScriptText(SAY_PROGRESS_3, me, player);break;
                case 8:DoScriptText(EMOTE_PROGRESS_4, me);break;
                case 9:
                    {
                    me->SummonCreature(MOB_VENGEFUL_SURGE, -2052.96f, -2142.49f, 20.15f, 1.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    me->SummonCreature(MOB_VENGEFUL_SURGE, -2052.96f, -2142.49f, 20.15f, 1.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    break;
                    }
                case 10:DoScriptText(SAY_PROGRESS_5, me, player);break;
                case 11:
                    DoScriptText(SAY_PROGRESS_6, me, player);
                    SetRun();
                    break;
                case 19:DoScriptText(SAY_PROGRESS_7, me, player); break;
                case 20:
                    DoScriptText(EMOTE_PROGRESS_8, me);
                    DoScriptText(SAY_PROGRESS_9, me, player);
                    if (player)
                        CAST_PLR(player)->GroupEventHappens(QUEST_SUNKEN_TREASURE, me);
                    break;
                }
            }

            void JustSummoned(Creature* summoned)
            {
                summoned->AI()->AttackStart(me);
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoScriptText(SAY_AGGRO, me);
            }

            void UpdateAI(const uint32 diff)
            {
                npc_escortAI::UpdateAI(diff);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_professor_phizzlethorpeAI(creature);
        }

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
        {
            if (quest->GetQuestId() == QUEST_SUNKEN_TREASURE)
            {
                DoScriptText(SAY_PROGRESS_1, creature, player);
                if (npc_escortAI* pEscortAI = CAST_AI(npc_professor_phizzlethorpeAI, (creature->AI())))
                    pEscortAI->Start(false, false, player->GetGUID(), quest);

                creature->setFaction(113);
            }
            return true;
        }
};

void AddSC_arathi_highlands()
{
    new npc_professor_phizzlethorpe();
}
