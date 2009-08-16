/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* ScriptData
SDName: Ashenvale
SD%Complete: 70
SDComment: Quest support: 6544, 6482
SDCategory: Ashenvale Forest
EndScriptData */

/* ContentData
npc_torek
npc_ruul_snowhoof
EndContentData */

#include "precompiled.h"
#include "escortAI.h"

/*####
# npc_torek
####*/

#define SAY_READY                   -1000106
#define SAY_MOVE                    -1000107
#define SAY_PREPARE                 -1000108
#define SAY_WIN                     -1000109
#define SAY_END                     -1000110

#define SPELL_REND                  11977
#define SPELL_THUNDERCLAP           8078

#define QUEST_TOREK_ASSULT          6544

#define ENTRY_SPLINTERTREE_RAIDER   12859
#define ENTRY_DURIEL                12860
#define ENTRY_SILVERWING_SENTINEL   12896
#define ENTRY_SILVERWING_WARRIOR    12897

struct TRINITY_DLL_DECL npc_torekAI : public npc_escortAI
{
    npc_torekAI(Creature *c) : npc_escortAI(c) {}

    uint32 Rend_Timer;
    uint32 Thunderclap_Timer;
    bool Completed;

    void WaypointReached(uint32 i)
    {
        Player* pPlayer = Unit::GetPlayer(PlayerGUID);

        if (!pPlayer)
            return;

        switch (i)
        {
        case 1:
            DoScriptText(SAY_MOVE, m_creature, pPlayer);
            break;
        case 8:
            DoScriptText(SAY_PREPARE, m_creature, pPlayer);
            break;
        case 19:
            //TODO: verify location and creatures amount.
            m_creature->SummonCreature(ENTRY_DURIEL,1776.73,-2049.06,109.83,1.54,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,25000);
            m_creature->SummonCreature(ENTRY_SILVERWING_SENTINEL,1774.64,-2049.41,109.83,1.40,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,25000);
            m_creature->SummonCreature(ENTRY_SILVERWING_WARRIOR,1778.73,-2049.50,109.83,1.67,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,25000);
            break;
        case 20:
            DoScriptText(SAY_WIN, m_creature, pPlayer);
            Completed = true;
            if (pPlayer && pPlayer->GetTypeId() == TYPEID_PLAYER)
                CAST_PLR(pPlayer)->GroupEventHappens(QUEST_TOREK_ASSULT,m_creature);
            break;
        case 21:
            DoScriptText(SAY_END, m_creature, pPlayer);
            break;
        }
    }

    void Reset()
    {
        Rend_Timer = 5000;
        Thunderclap_Timer = 8000;
        Completed = false;
    }

    void EnterCombat(Unit* who)
    {
    }

    void JustSummoned(Creature* summoned)
    {
        summoned->AI()->AttackStart(m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;

        if (Rend_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_REND);
            Rend_Timer = 20000;
        }else Rend_Timer -= diff;

        if (Thunderclap_Timer < diff)
        {
            DoCast(m_creature,SPELL_THUNDERCLAP);
            Thunderclap_Timer = 30000;
        }else Thunderclap_Timer -= diff;
    }
};

bool QuestAccept_npc_torek(Player* pPlayer, Creature* pCreature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_TOREK_ASSULT)
    {
        //TODO: find companions, make them follow Torek, at any time (possibly done by mangos/database in future?)
        DoScriptText(SAY_READY, pCreature, pPlayer);
        pCreature->setFaction(113);

        if (npc_escortAI* pEscortAI = CAST_AI(npc_torekAI, pCreature->AI()))
            pEscortAI->Start(true, true, pPlayer->GetGUID());
    }

    return true;
}

CreatureAI* GetAI_npc_torek(Creature* pCreature)
{
    return new npc_torekAI(pCreature);
}

/*####
# npc_ruul_snowhoof
####*/

#define QUEST_FREEDOM_TO_RUUL    6482
#define GO_CAGE                  178147

struct TRINITY_DLL_DECL npc_ruul_snowhoofAI : public npc_escortAI
{
    npc_ruul_snowhoofAI(Creature *c) : npc_escortAI(c) {}

    void WaypointReached(uint32 i)
    {
        Player* pPlayer = Unit::GetPlayer(PlayerGUID);

        if (!pPlayer)
            return;

        switch(i)
        {
        case 0:    {
                m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                GameObject* Cage = m_creature->FindNearestGameObject(GO_CAGE, 20);
                if (Cage)
                    Cage->SetGoState(GO_STATE_ACTIVE);
                break;}
        case 13:
                m_creature->SummonCreature(3922, 3449.218018, -587.825073, 174.978867, 4.714445, TEMPSUMMON_DEAD_DESPAWN, 60000);
                m_creature->SummonCreature(3921, 3446.384521, -587.830872, 175.186279, 4.714445, TEMPSUMMON_DEAD_DESPAWN, 60000);
                m_creature->SummonCreature(3926, 3444.218994, -587.835327, 175.380600, 4.714445, TEMPSUMMON_DEAD_DESPAWN, 60000);
                break;
        case 19:
                m_creature->SummonCreature(3922, 3508.344482, -492.024261, 186.929031, 4.145029, TEMPSUMMON_DEAD_DESPAWN, 60000);
                m_creature->SummonCreature(3921, 3506.265625, -490.531006, 186.740128, 4.239277, TEMPSUMMON_DEAD_DESPAWN, 60000);
                m_creature->SummonCreature(3926, 3503.682373, -489.393799, 186.629684, 4.349232, TEMPSUMMON_DEAD_DESPAWN, 60000);
                break;

        case 21:{
                if (pPlayer && pPlayer->GetTypeId() == TYPEID_PLAYER)
                    CAST_PLR(pPlayer)->GroupEventHappens(QUEST_FREEDOM_TO_RUUL,m_creature);

                break;  }
        }
    }

    void EnterCombat(Unit* who) {}

    void Reset()
    {
        GameObject* Cage = m_creature->FindNearestGameObject(GO_CAGE, 20);
        if (Cage)
            Cage->SetGoState(GO_STATE_READY);
    }

    void JustSummoned(Creature* summoned)
    {
        summoned->AI()->AttackStart(m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);
    }
};

bool QuestAccept_npc_ruul_snowhoof(Player* pPlayer, Creature* pCreature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_FREEDOM_TO_RUUL)
    {
        pCreature->setFaction(113);

        if (npc_escortAI* pEscortAI = CAST_AI(npc_ruul_snowhoofAI, (pCreature->AI())))
            pEscortAI->Start(true, false, pPlayer->GetGUID());
    }
    return true;
}

CreatureAI* GetAI_npc_ruul_snowhoofAI(Creature* pCreature)
{
    return new npc_ruul_snowhoofAI(pCreature);
}

void AddSC_ashenvale()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_torek";
    newscript->GetAI = &GetAI_npc_torek;
    newscript->pQuestAccept = &QuestAccept_npc_torek;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_ruul_snowhoof";
    newscript->GetAI = &GetAI_npc_ruul_snowhoofAI;
    newscript->pQuestAccept = &QuestAccept_npc_ruul_snowhoof;
    newscript->RegisterSelf();
}

