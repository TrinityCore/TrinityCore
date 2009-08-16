/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

/* ScriptData
SDName: Ungoro Crater
SD%Complete: 100
SDComment: Support for Quest: 4245
SDCategory: Ungoro Crater
EndScriptData */

/* ContentData
npc_a-me
EndContentData */

#include "precompiled.h"
#include "escort_ai.h"

#define SAY_READY -1000200
#define SAY_AGGRO1 -1000201
#define SAY_SEARCH -1000202
#define SAY_AGGRO2 -1000203
#define SAY_AGGRO3 -1000204
#define SAY_FINISH -1000205

#define SPELL_DEMORALIZINGSHOUT  13730

#define QUEST_CHASING_AME 4245
#define ENTRY_TARLORD 6519
#define ENTRY_TARLORD1 6519
#define ENTRY_STOMPER 6513


struct TRINITY_DLL_DECL npc_ameAI : public npc_escortAI
{
    npc_ameAI(Creature *c) : npc_escortAI(c) {}

    uint32 DEMORALIZINGSHOUT_Timer;

    void WaypointReached(uint32 i)
    {
        Player* pPlayer = GetPlayerForEscort();

        if (!pPlayer)
            return;

        switch (i)
        {

         case 19:
            m_creature->SummonCreature(ENTRY_STOMPER, -6391.69, -1730.49, -272.83, 4.96, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
            DoScriptText(SAY_AGGRO1, m_creature, pPlayer);
            break;
            case 28:
            DoScriptText(SAY_SEARCH, m_creature, pPlayer);
            break;
            case 38:
            m_creature->SummonCreature(ENTRY_TARLORD, -6370.75, -1382.84, -270.51, 6.06, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
            DoScriptText(SAY_AGGRO2, m_creature, pPlayer);
            break;
            case 49:
            m_creature->SummonCreature(ENTRY_TARLORD1, -6324.44, -1181.05, -270.17, 4.34, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
            DoScriptText(SAY_AGGRO3, m_creature, pPlayer);
            break;
         case 55:
            DoScriptText(SAY_FINISH, m_creature, pPlayer);
            if (pPlayer)
                pPlayer->GroupEventHappens(QUEST_CHASING_AME,m_creature);
            break;

        }
    }

    void Reset()
    {
      DEMORALIZINGSHOUT_Timer = 5000;
    }

    void JustSummoned(Creature* summoned)
    {
        summoned->AI()->AttackStart(m_creature);
    }

    void JustDied(Unit* killer)
    {
        if (Player* pPlayer = GetPlayerForEscort())
            pPlayer->FailQuest(QUEST_CHASING_AME);
    }

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);
        if (!UpdateVictim())
            return;

        if (DEMORALIZINGSHOUT_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_DEMORALIZINGSHOUT);
            DEMORALIZINGSHOUT_Timer = 70000;
        }else DEMORALIZINGSHOUT_Timer -= diff;

    }
};

bool QuestAccept_npc_ame(Player* pPlayer, Creature* pCreature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_CHASING_AME)
    {
        CAST_AI(npc_escortAI, (pCreature->AI()))->Start(false, false, pPlayer->GetGUID());
        DoScriptText(SAY_READY, pCreature, pPlayer);
        pCreature->SetUInt32Value(UNIT_FIELD_BYTES_1,0);
        // Change faction so mobs attack
        pCreature->setFaction(113);
    }
    return true;
}

CreatureAI* GetAI_npc_ame(Creature* pCreature)
{
    return new npc_ameAI(pCreature);
}

void AddSC_ungoro_crater()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_ame";
    newscript->GetAI = &GetAI_npc_ame;
    newscript->pQuestAccept = &QuestAccept_npc_ame;
    newscript->RegisterSelf();
}

