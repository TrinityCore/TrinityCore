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
#include "../../npc/npc_escortAI.h"
#include "def_razorfen_kraul.h"

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
        Player* player = Unit::GetPlayer(PlayerGUID);

        if (!player)
            return;

        switch (i)
        {
        case 3:
            m_creature->HandleEmoteCommand(EMOTE_STATE_POINT);
            DoScriptText(SAY_POINT, m_creature, player);
            break;
        case 4:
            m_creature->SummonCreature(ENTRY_BOAR, 2137.66, 1843.98, 48.08, 1.54, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
            break;
        case 8:
            DoScriptText(SAY_BLUELEAF, m_creature, player);
            break;
        case 9:
            DoScriptText(SAY_DANGER, m_creature, player);
            break;
        case 13:
            DoScriptText(SAY_BAD, m_creature, player);
            break;
        case 14:
            m_creature->SummonCreature(ENTRY_BOAR, 2078.91, 1704.54, 56.77, 1.54, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
            break;
        case 25:
            DoScriptText(SAY_THINK, m_creature, player);
            break;
        case 31:
            DoScriptText(SAY_SOON, m_creature, player);
            break;
        case 42:
            DoScriptText(SAY_FINALY, m_creature, player);
            break;
        case 43:
            m_creature->SummonCreature(ENTRY_BOAR, 1956.43, 1596.97, 81.75, 1.54,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
            break;
        case 45:
            DoScriptText(SAY_WIN, m_creature, player);
            if (player && player->GetTypeId() == TYPEID_PLAYER)
                CAST_PLR(player)->GroupEventHappens(QUEST_WILLIX_THE_IMPORTER,m_creature);
            break;
        case 46:
            DoScriptText(SAY_END, m_creature, player);
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
        if (PlayerGUID)
        {
            if (Player* player = Unit::GetPlayer(PlayerGUID))
                CAST_PLR(player)->FailQuest(QUEST_WILLIX_THE_IMPORTER);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);
    }
};

bool QuestAccept_npc_willix(Player* player, Creature* creature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_WILLIX_THE_IMPORTER)
    {
        CAST_AI(npc_escortAI, (creature->AI()))->Start(true, true, false, player->GetGUID());
        DoScriptText(SAY_READY, creature, player);
        creature->setFaction(113);
    }

    return true;
}

struct TRINITY_DLL_DECL npc_deaths_head_ward_keeperAI : public ScriptedAI
{
    npc_deaths_head_ward_keeperAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        Reset();
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

        if (QuillboarChanneling_Timer < diff)
        {
            if( m_creature->IsNonMeleeSpellCasted(false) )
                m_creature->InterruptNonMeleeSpells(true);
            DoCast(m_creature, SPELL_QUILLBOAR_CHANNELING);
            QuillboarChanneling_Timer = 1100;
        }else QuillboarChanneling_Timer -= diff;

    }
};

CreatureAI* GetAI_npc_deaths_head_ward_keeper(Creature *_Creature)
{
    return new npc_deaths_head_ward_keeperAI(_Creature);
}

CreatureAI* GetAI_npc_willix(Creature *_Creature)
{
    npc_willixAI* thisAI = new npc_willixAI(_Creature);

    thisAI->AddWaypoint(0, 2194.38, 1791.65, 65.48, 5000);
    thisAI->AddWaypoint(1, 2188.56, 1805.87, 64.45);
    thisAI->AddWaypoint(2, 2187, 1843.49, 59.33);
    thisAI->AddWaypoint(3, 2163.27, 1851.67, 56.73, 5000);
    thisAI->AddWaypoint(4, 2137.66, 1843.98, 48.08, 5000);
    thisAI->AddWaypoint(5, 2140.22, 1845.02, 48.32);
    thisAI->AddWaypoint(6, 2131.5, 1804.29, 46.85);
    thisAI->AddWaypoint(7, 2096.18, 1789.03, 51.13);
    thisAI->AddWaypoint(8, 2074.46, 1780.09, 55.64, 3000);
    thisAI->AddWaypoint(9, 2055.12, 1768.67, 58.46, 5000);
    thisAI->AddWaypoint(10, 2037.83, 1748.62, 60.27);
    thisAI->AddWaypoint(11, 2037.51, 1728.94, 60.85);
    thisAI->AddWaypoint(12, 2044.7, 1711.71, 59.71);
    thisAI->AddWaypoint(13, 2067.66, 1701.84, 57.77, 3000);
    thisAI->AddWaypoint(14, 2078.91, 1704.54, 56.77, 3000);
    thisAI->AddWaypoint(15, 2097.65, 1715.24, 54.74);
    thisAI->AddWaypoint(16, 2106.44, 1720.98, 54.41);
    thisAI->AddWaypoint(17, 2123.96, 1732.56, 52.27);
    thisAI->AddWaypoint(18, 2153.82, 1728.73, 51.92);
    thisAI->AddWaypoint(19, 2163.49, 1706.33, 54.42);
    thisAI->AddWaypoint(20, 2158.75, 1695.98, 55.70);
    thisAI->AddWaypoint(21, 2142.6, 1680.72, 58.24);
    thisAI->AddWaypoint(22, 2118.31, 1671.54, 59.21);
    thisAI->AddWaypoint(23, 2086.02, 1672.04, 61.24);
    thisAI->AddWaypoint(24, 2068.81, 1658.93, 61.24);
    thisAI->AddWaypoint(25, 2062.82, 1633.31, 64.35, 3000);
    thisAI->AddWaypoint(26, 2063.05, 1589.16, 63.26);
    thisAI->AddWaypoint(27, 2063.67, 1577.22, 65.89);
    thisAI->AddWaypoint(28, 2057.94, 1560.68, 68.40);
    thisAI->AddWaypoint(29, 2052.56, 1548.05, 73.35);
    thisAI->AddWaypoint(30, 2045.22, 1543.4, 76.65);
    thisAI->AddWaypoint(31, 2034.35, 1543.01, 79.70);
    thisAI->AddWaypoint(32, 2029.95, 1542.94, 80.79);
    thisAI->AddWaypoint(33, 2021.34, 1538.67, 80.8);
    thisAI->AddWaypoint(34, 2012.45, 1549.48, 79.93);
    thisAI->AddWaypoint(35, 2008.05, 1554.92, 80.44);
    thisAI->AddWaypoint(36, 2006.54, 1562.72, 81.11);
    thisAI->AddWaypoint(37, 2003.8, 1576.43, 81.57);
    thisAI->AddWaypoint(38, 2000.57, 1590.06, 80.62);
    thisAI->AddWaypoint(39, 1998.96, 1596.87, 80.22);
    thisAI->AddWaypoint(40, 1991.19, 1600.82, 79.39);
    thisAI->AddWaypoint(41, 1980.71, 1601.44, 79.77, 3000);
    thisAI->AddWaypoint(42, 1967.22, 1600.18, 80.62, 3000);
    thisAI->AddWaypoint(43, 1956.43, 1596.97, 81.75, 3000);
    thisAI->AddWaypoint(44, 1954.87, 1592.02, 82.18);
    thisAI->AddWaypoint(45, 1948.35, 1571.35, 80.96, 30000);
    thisAI->AddWaypoint(46, 1947.02, 1566.42, 81.80, 30000);

    return thisAI;
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

