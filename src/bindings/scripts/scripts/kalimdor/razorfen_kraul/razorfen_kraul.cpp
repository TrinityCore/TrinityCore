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
SDName: Razorfen Kraul
SD%Complete: 100
SDComment: Quest support: 1144
SDCategory: Razorfen Kraul
EndScriptData */

/* ContentData
npc_willix
EndContentData */

#include "precompiled.h"
#include "escort_ai.h"
#include "razorfen_kraul.h"

#define SAY_READY -1047000
#define SAY_POINT -10470001
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
#define SPELL_QUILLBOAR_CHANNELING 7083

struct TRINITY_DLL_DECL npc_willixAI : public npc_escortAI
{
    npc_willixAI(Creature *c) : npc_escortAI(c) {}

    void WaypointReached(uint32 i)
    {
        Player* pPlayer = GetPlayerForEscort();

        if (!pPlayer)
            return;

        switch (i)
        {
        case 3:
            m_creature->HandleEmoteCommand(EMOTE_STATE_POINT);
            DoScriptText(SAY_POINT, m_creature, pPlayer);
            break;
        case 4:
            m_creature->SummonCreature(ENTRY_BOAR, 2137.66, 1843.98, 48.08, 1.54, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
            break;
        case 8:
            DoScriptText(SAY_BLUELEAF, m_creature, pPlayer);
            break;
        case 9:
            DoScriptText(SAY_DANGER, m_creature, pPlayer);
            break;
        case 13:
            DoScriptText(SAY_BAD, m_creature, pPlayer);
            break;
        case 14:
            m_creature->SummonCreature(ENTRY_BOAR, 2078.91, 1704.54, 56.77, 1.54, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
            break;
        case 25:
            DoScriptText(SAY_THINK, m_creature, pPlayer);
            break;
        case 31:
            DoScriptText(SAY_SOON, m_creature, pPlayer);
            break;
        case 42:
            DoScriptText(SAY_FINALY, m_creature, pPlayer);
            break;
        case 43:
            m_creature->SummonCreature(ENTRY_BOAR, 1956.43, 1596.97, 81.75, 1.54,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
            break;
        case 45:
            DoScriptText(SAY_WIN, m_creature, pPlayer);
            if (pPlayer && pPlayer->GetTypeId() == TYPEID_PLAYER)
                CAST_PLR(pPlayer)->GroupEventHappens(QUEST_WILLIX_THE_IMPORTER,m_creature);
            break;
        case 46:
            DoScriptText(SAY_END, m_creature, pPlayer);
            break;
        }
    }

    void Reset() {}

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO1, m_creature, NULL);
    }

    void JustSummoned(Creature* summoned)
    {
        summoned->AI()->AttackStart(m_creature);
    }

    void JustDied(Unit* killer)
    {
        if (Player* pPlayer = GetPlayerForEscort())
            CAST_PLR(pPlayer)->FailQuest(QUEST_WILLIX_THE_IMPORTER);
    }
};

bool QuestAccept_npc_willix(Player* pPlayer, Creature* pCreature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_WILLIX_THE_IMPORTER)
    {
        CAST_AI(npc_escortAI, (pCreature->AI()))->Start(true, false, pPlayer->GetGUID());
        DoScriptText(SAY_READY, pCreature, pPlayer);
        pCreature->setFaction(113);
    }

    return true;
}

struct TRINITY_DLL_DECL npc_deaths_head_ward_keeperAI : public ScriptedAI
{
    npc_deaths_head_ward_keeperAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance *pInstance;
    uint32 QuillboarChanneling_Timer;

    void Reset()
    {
        QuillboarChanneling_Timer = 1500;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->isAlive())
            return;

        if (pInstance)
            pInstance->SetData(TYPE_WARD_KEEPERS, NOT_STARTED);

        if (QuillboarChanneling_Timer <= diff)
        {
            if (m_creature->IsNonMeleeSpellCasted(false))
                m_creature->InterruptNonMeleeSpells(true);
            DoCast(m_creature, SPELL_QUILLBOAR_CHANNELING);
            QuillboarChanneling_Timer = 1100;
        } else QuillboarChanneling_Timer -= diff;

    }
};

CreatureAI* GetAI_npc_deaths_head_ward_keeper(Creature* pCreature)
{
    return new npc_deaths_head_ward_keeperAI(pCreature);
}

CreatureAI* GetAI_npc_willix(Creature* pCreature)
{
    return new npc_willixAI(pCreature);
}

void AddSC_razorfen_kraul()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_willix";
    newscript->GetAI = &GetAI_npc_willix;
    newscript->pQuestAccept = &QuestAccept_npc_willix;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_deaths_head_ward_keeper";
    newscript->GetAI = &GetAI_npc_deaths_head_ward_keeper;
    newscript->RegisterSelf();
}

