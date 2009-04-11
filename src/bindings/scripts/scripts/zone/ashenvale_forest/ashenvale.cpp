/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "../../npc/npc_escortAI.h"

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
        Player* player = Unit::GetPlayer(PlayerGUID);

        if (!player)
            return;

        switch (i)
        {
        case 1:
            DoScriptText(SAY_MOVE, m_creature, player);
            break;
        case 8:
            DoScriptText(SAY_PREPARE, m_creature, player);
            break;
        case 19:
            //TODO: verify location and creatures amount.
            m_creature->SummonCreature(ENTRY_DURIEL,1776.73,-2049.06,109.83,1.54,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,25000);
            m_creature->SummonCreature(ENTRY_SILVERWING_SENTINEL,1774.64,-2049.41,109.83,1.40,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,25000);
            m_creature->SummonCreature(ENTRY_SILVERWING_WARRIOR,1778.73,-2049.50,109.83,1.67,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,25000);
            break;
        case 20:
            DoScriptText(SAY_WIN, m_creature, player);
            Completed = true;
            if (player && player->GetTypeId() == TYPEID_PLAYER)
                ((Player*)player)->GroupEventHappens(QUEST_TOREK_ASSULT,m_creature);
            break;
        case 21:
            DoScriptText(SAY_END, m_creature, player);
            break;
        }
    }

    void Reset()
    {
        Rend_Timer = 5000;
        Thunderclap_Timer = 8000;
        Completed = false;
    }

    void Aggro(Unit* who)
    {
    }

    void JustSummoned(Creature* summoned)
    {
        summoned->AI()->AttackStart(m_creature);
    }

    void JustDied(Unit* killer)
    {
        if (PlayerGUID && !Completed)
        {
            if (Player* player = Unit::GetPlayer(PlayerGUID))
                ((Player*)player)->FailQuest(QUEST_TOREK_ASSULT);
        }
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

bool QuestAccept_npc_torek(Player* player, Creature* creature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_TOREK_ASSULT)
    {
        //TODO: find companions, make them follow Torek, at any time (possibly done by mangos/database in future?)
        ((npc_escortAI*)(creature->AI()))->Start(true, true, true, player->GetGUID());
        DoScriptText(SAY_READY, creature, player);
        creature->setFaction(113);
    }

    return true;
}

CreatureAI* GetAI_npc_torek(Creature *_Creature)
{
    npc_torekAI* thisAI = new npc_torekAI(_Creature);

    thisAI->AddWaypoint(0, 1782.63, -2241.11, 109.73, 5000);
    thisAI->AddWaypoint(1, 1788.88, -2240.17, 111.71);
    thisAI->AddWaypoint(2, 1797.49, -2238.11, 112.31);
    thisAI->AddWaypoint(3, 1803.83, -2232.77, 111.22);
    thisAI->AddWaypoint(4, 1806.65, -2217.83, 107.36);
    thisAI->AddWaypoint(5, 1811.81, -2208.01, 107.45);
    thisAI->AddWaypoint(6, 1820.85, -2190.82, 100.49);
    thisAI->AddWaypoint(7, 1829.60, -2177.49, 96.44);
    thisAI->AddWaypoint(8, 1837.98, -2164.19, 96.71);       //prepare
    thisAI->AddWaypoint(9, 1839.99, -2149.29, 96.78);
    thisAI->AddWaypoint(10, 1835.14, -2134.98, 96.80);
    thisAI->AddWaypoint(11, 1823.57, -2118.27, 97.43);
    thisAI->AddWaypoint(12, 1814.99, -2110.35, 98.38);
    thisAI->AddWaypoint(13, 1806.60, -2103.09, 99.19);
    thisAI->AddWaypoint(14, 1798.27, -2095.77, 100.04);
    thisAI->AddWaypoint(15, 1783.59, -2079.92, 100.81);
    thisAI->AddWaypoint(16, 1776.79, -2069.48, 101.77);
    thisAI->AddWaypoint(17, 1776.82, -2054.59, 109.82);
    thisAI->AddWaypoint(18, 1776.88, -2047.56, 109.83);
    thisAI->AddWaypoint(19, 1776.86, -2036.55, 109.83);
    thisAI->AddWaypoint(20, 1776.90, -2024.56, 109.83);     //win
    thisAI->AddWaypoint(21, 1776.87, -2028.31, 109.83,60000);//stay
    thisAI->AddWaypoint(22, 1776.90, -2028.30, 109.83);

    return (CreatureAI*)thisAI;
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
        Player* player = Unit::GetPlayer(PlayerGUID);

        if (!player)
            return;

        switch(i)
        {
        case 0:    {
                m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                GameObject* Cage = FindGameObject(GO_CAGE, 20, m_creature);
                if(Cage)
                    Cage->SetGoState(0);
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
                if (player && player->GetTypeId() == TYPEID_PLAYER)
                    ((Player*)player)->GroupEventHappens(QUEST_FREEDOM_TO_RUUL,m_creature);

                break;  }
        }
    }

    void Aggro(Unit* who) {}

    void Reset()
    {
        if (!IsBeingEscorted)
            m_creature->setFaction(1602);

        GameObject* Cage = FindGameObject(GO_CAGE, 20, m_creature);
        if(Cage)
            Cage->SetGoState(1);
    }

    void JustSummoned(Creature* summoned)
    {
        summoned->AI()->AttackStart(m_creature);
    }

    void JustDied(Unit* killer)
    {
        if (PlayerGUID)
        {
            Player* player = Unit::GetPlayer(PlayerGUID);
            if (player)
                ((Player*)player)->FailQuest(QUEST_FREEDOM_TO_RUUL);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);
    }
};

bool QuestAccept_npc_ruul_snowhoof(Player* player, Creature* creature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_FREEDOM_TO_RUUL)
    {
        creature->setFaction(113);
        ((npc_escortAI*)(creature->AI()))->Start(true, true, false, player->GetGUID());
    }
    return true;
}

CreatureAI* GetAI_npc_ruul_snowhoofAI(Creature *_Creature)
{
    npc_ruul_snowhoofAI* ruul_snowhoofAI = new npc_ruul_snowhoofAI(_Creature);

    ruul_snowhoofAI->AddWaypoint(0, 3347.250089, -694.700989, 159.925995);
    ruul_snowhoofAI->AddWaypoint(1, 3341.527039, -694.725891, 161.124542, 4000);
    ruul_snowhoofAI->AddWaypoint(2, 3338.351074, -686.088138, 163.444000);
    ruul_snowhoofAI->AddWaypoint(3, 3352.744873, -677.721741, 162.316269);
    ruul_snowhoofAI->AddWaypoint(4, 3370.291016, -669.366943, 160.751358);
    ruul_snowhoofAI->AddWaypoint(5, 3381.479492, -659.449097, 162.545303);
    ruul_snowhoofAI->AddWaypoint(6, 3389.554199, -648.500000, 163.651825);
    ruul_snowhoofAI->AddWaypoint(7, 3396.645020, -641.508911, 164.216019);
    ruul_snowhoofAI->AddWaypoint(8, 3410.498535, -634.299622, 165.773453);
    ruul_snowhoofAI->AddWaypoint(9, 3418.461426, -631.791992, 166.477615);
    ruul_snowhoofAI->AddWaypoint(10, 3429.500000, -631.588745, 166.921265);
    ruul_snowhoofAI->AddWaypoint(11,3434.950195, -629.245483, 168.333969);
    ruul_snowhoofAI->AddWaypoint(12,3438.927979, -618.503235, 171.503143);
    ruul_snowhoofAI->AddWaypoint(13,3444.217529, -609.293640, 173.077972, 1000); // Ambush 1
    ruul_snowhoofAI->AddWaypoint(14,3460.505127, -593.794189, 174.342255);
    ruul_snowhoofAI->AddWaypoint(15,3480.283203, -578.210327, 176.652313);
    ruul_snowhoofAI->AddWaypoint(16,3492.912842, -562.335449, 181.396301);
    ruul_snowhoofAI->AddWaypoint(17,3495.230957, -550.977600, 184.652267);
    ruul_snowhoofAI->AddWaypoint(18,3496.247070, -529.194214, 188.172028);
    ruul_snowhoofAI->AddWaypoint(19,3497.619385, -510.411499, 188.345322, 1000); // Ambush 2
    ruul_snowhoofAI->AddWaypoint(20,3498.498047, -497.787506, 185.806274);
    ruul_snowhoofAI->AddWaypoint(21,3484.218750, -489.717529, 182.389862, 4000); // End

    return (CreatureAI*)ruul_snowhoofAI;
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

