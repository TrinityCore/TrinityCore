/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Arathi Highlands
SD%Complete: 100
SDComment: Quest support: 665
SDCategory: Arathi Highlands
EndScriptData */

/* ContentData
npc_professor_phizzlethorpe
EndContentData */

#include "precompiled.h"
#include "../../npc/npc_escortAI.h"

/*######
## npc_professor_phizzlethorpe
######*/

#define SAY_PROGRESS_1      -1000235
#define SAY_PROGRESS_2      -1000236
#define SAY_PROGRESS_3      -1000237
#define EMOTE_PROGRESS_4    -1000238
#define SAY_AGGRO           -1000239
#define SAY_PROGRESS_5      -1000240
#define SAY_PROGRESS_6      -1000241
#define SAY_PROGRESS_7      -1000242
#define EMOTE_PROGRESS_8    -1000243
#define SAY_PROGRESS_9      -1000244

#define QUEST_SUNKEN_TREASURE   665
#define MOB_VENGEFUL_SURGE  2776

struct TRINITY_DLL_DECL npc_professor_phizzlethorpeAI : public npc_escortAI
{
    npc_professor_phizzlethorpeAI(Creature *c) : npc_escortAI(c) {}

    bool Completed;

    void WaypointReached(uint32 i)
    {
        Player* player = Unit::GetPlayer(PlayerGUID);

        switch(i)
        {
        case 4:DoScriptText(SAY_PROGRESS_2, m_creature, player);break;
        case 5:DoScriptText(SAY_PROGRESS_3, m_creature, player);break;
        case 8:DoScriptText(EMOTE_PROGRESS_4, m_creature);break;
        case 9:
            {
            m_creature->SummonCreature(MOB_VENGEFUL_SURGE, -2052.96, -2142.49, 20.15, 1.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
            m_creature->SummonCreature(MOB_VENGEFUL_SURGE, -2052.96, -2142.49, 20.15, 1.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
            break;
            }
        case 10:DoScriptText(SAY_PROGRESS_5, m_creature, player);break;
        case 11:DoScriptText(SAY_PROGRESS_6, m_creature, player);break;
        case 19:DoScriptText(SAY_PROGRESS_7, m_creature, player); break;
        case 20:
            DoScriptText(EMOTE_PROGRESS_8, m_creature);
            DoScriptText(SAY_PROGRESS_9, m_creature, player);
            Completed = true;
            if(player)
                ((Player*)player)->GroupEventHappens(QUEST_SUNKEN_TREASURE, m_creature);
            break;
        }
    }

    void JustSummoned(Creature *summoned)
    {
        summoned->AI()->AttackStart(m_creature);
    }

    void Reset()
    {
        Completed = true;
        m_creature->setFaction(35);
    }

    void Aggro(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature, NULL);
    }

    void JustDied(Unit* killer)
    {
        if (PlayerGUID && !Completed )
        {
            Player* player = Unit::GetPlayer(PlayerGUID);
            if (player)
                ((Player*)player)->FailQuest(QUEST_SUNKEN_TREASURE);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);
    }
};

bool QuestAccept_npc_professor_phizzlethorpe(Player* player, Creature* creature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_SUNKEN_TREASURE)
    {
        DoScriptText(SAY_PROGRESS_1, creature, player);
        ((npc_escortAI*)(creature->AI()))->Start(false, false, false, player->GetGUID());
        creature->setFaction(113);
    }
    return true;
}

CreatureAI* GetAI_npc_professor_phizzlethorpeAI(Creature *_Creature)
{
    npc_professor_phizzlethorpeAI* professor_phizzlethorpeAI = new npc_professor_phizzlethorpeAI(_Creature);

    professor_phizzlethorpeAI->AddWaypoint(0, -2066.45, -2085.96, 9.08);
    professor_phizzlethorpeAI->AddWaypoint(1, -2077.99, -2105.33, 13.24);
    professor_phizzlethorpeAI->AddWaypoint(2, -2074.60, -2109.67, 14.24);
    professor_phizzlethorpeAI->AddWaypoint(3, -2076.60, -2117.46, 16.67);
    professor_phizzlethorpeAI->AddWaypoint(4, -2073.51, -2123.46, 18.42, 2000);
    professor_phizzlethorpeAI->AddWaypoint(5, -2073.51, -2123.46, 18.42, 4000);
    professor_phizzlethorpeAI->AddWaypoint(6, -2066.60, -2131.85, 21.56);
    professor_phizzlethorpeAI->AddWaypoint(7, -2053.85, -2143.19, 20.31);
    professor_phizzlethorpeAI->AddWaypoint(8, -2043.49, -2153.73, 20.20, 12000);
    professor_phizzlethorpeAI->AddWaypoint(9, -2043.49, -2153.73, 20.20, 14000);
    professor_phizzlethorpeAI->AddWaypoint(10, -2043.49, -2153.73, 20.20, 10000);
    professor_phizzlethorpeAI->AddWaypoint(11, -2043.49, -2153.73, 20.20, 2000);
    professor_phizzlethorpeAI->AddWaypoint(12, -2053.85, -2143.19, 20.31);
    professor_phizzlethorpeAI->AddWaypoint(13, -2066.60, -2131.85, 21.56);
    professor_phizzlethorpeAI->AddWaypoint(14, -2073.51, -2123.46, 18.42);
    professor_phizzlethorpeAI->AddWaypoint(15, -2076.60, -2117.46, 16.67);
    professor_phizzlethorpeAI->AddWaypoint(16, -2074.60, -2109.67, 14.24);
    professor_phizzlethorpeAI->AddWaypoint(17, -2077.99, -2105.33, 13.24);
    professor_phizzlethorpeAI->AddWaypoint(18, -2066.45, -2085.96, 9.08);
    professor_phizzlethorpeAI->AddWaypoint(19, -2066.41, -2086.21, 8.97, 6000);
    professor_phizzlethorpeAI->AddWaypoint(20, -2066.41, -2086.21, 8.97, 2000);

    return (CreatureAI*)professor_phizzlethorpeAI;
}

void AddSC_arathi_highlands()
{
    Script * newscript;

    newscript = new Script;
    newscript->Name = "npc_professor_phizzlethorpe";
    newscript->GetAI = &GetAI_npc_professor_phizzlethorpeAI;
    newscript->pQuestAccept = &QuestAccept_npc_professor_phizzlethorpe;
    newscript->RegisterSelf();
}

