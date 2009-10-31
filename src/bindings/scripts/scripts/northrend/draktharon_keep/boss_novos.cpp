/*
* Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
*
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

/* Script Data Start
SDName: Boss novos
SDAuthor: Tartalo
SD%Complete: 100
SDComment:
SDCategory:
Script Data End */

/*** SQL START ***
update creature_template set scriptname = 'boss_novos' where entry = '';
*** SQL END ***/
#include "precompiled.h"
#include "drak_tharon_keep.h"

enum Spells
{
    SPELL_ARCANE_BLAST                        = 49198,
    H_SPELL_ARCANE_BLAST                      = 59909,
    SPELL_ARCANE_FIELD                        = 47346,
    SPELL_BLIZZARD                            = 49034,
    H_SPELL_BLIZZARD                          = 59854,
    SPELL_FROSTBOLT                           = 49037,
    H_SPELL_FROSTBOLT                         = 59855,
    SPELL_WRATH_OF_MISERY                     = 50089,
    H_SPELL_WRATH_OF_MISERY                   = 59856,
    SPELL_SUMMON_MINIONS                      = 59910 //Summons an army of Fetid Troll Corpses to assist the caster.
};
//not in db
enum Yells
{
    SAY_AGGRO                              = -1600000,
    SAY_KILL                               = -1600001,
    SAY_DEATH                              = -1600002,
    SAY_NECRO_ADD                          = -1600003,
    SAY_REUBBLE_1                          = -1600004,
    SAY_REUBBLE_2                          = -1600005
};
enum Creatures
{
    CREATURE_RISEN_SHADOWCASTER            = 27600,
    CREATURE_FETID_TROLL_CORPSE            = 27598,
    CREATURE_HULKING_CORPSE                = 27597,
    CREATURE_CRYSTAL_HANDLER               = 26627
};
enum CombatPhase
{
    IDLE,
    PHASE_1,
    PHASE_2
};
enum Achievements
{
    ACHIEV_OH_NOVOS                   = 2057
};

struct Location
{
    float x,y,z;
};

static Location AddSpawnPoint = { -379.20, -816.76, 59.70};
static Location CrystalHandlerSpawnPoint = { -326.626343, -709.956604, 27.813314 };
static Location AddDestinyPoint = { -382.169, -711.369, 27.375};

struct TRINITY_DLL_DECL boss_novosAI : public Scripted_NoMovementAI
{
    boss_novosAI(Creature *c) : Scripted_NoMovementAI(c), lSummons(me)
    {
        pInstance = c->GetInstanceData();
        Reset();
    }

    uint32 uiTimer;
    uint32 uiCrystalHandlerTimer;

    bool bAchiev;

    SummonList lSummons;

    std::list<uint64> luiCrystals;

    CombatPhase Phase;

    ScriptedInstance* pInstance;

    void Reset()
    {
        Phase = IDLE;
        luiCrystals.clear();
        bAchiev = true;
        m_creature->CastStop();
        lSummons.DespawnAll();
        if (pInstance)
        {
            pInstance->SetData(DATA_NOVOS_EVENT, NOT_STARTED);
            luiCrystals.push_back(pInstance->GetData64(DATA_NOVOS_CRYSTAL_1));
            luiCrystals.push_back(pInstance->GetData64(DATA_NOVOS_CRYSTAL_2));
            luiCrystals.push_back(pInstance->GetData64(DATA_NOVOS_CRYSTAL_3));
            luiCrystals.push_back(pInstance->GetData64(DATA_NOVOS_CRYSTAL_4));
            for (std::list<uint64>::iterator itr = luiCrystals.begin(); itr != luiCrystals.end(); ++itr)
            {
                if (GameObject* pTemp = pInstance->instance->GetGameObject(*itr))
                    pTemp->SetGoState(GO_STATE_READY);
            }
        }
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        Phase = PHASE_1;
        uiCrystalHandlerTimer = 30000;
        uiTimer = 1000;
        DoCast(m_creature,SPELL_ARCANE_FIELD);
        if (pInstance)
        {
            for (std::list<uint64>::iterator itr = luiCrystals.begin(); itr != luiCrystals.end(); ++itr)
            {
                if (GameObject *pTemp = pInstance->instance->GetGameObject(*itr))
                    pTemp->SetGoState(GO_STATE_ACTIVE);
            }
            pInstance->SetData(DATA_NOVOS_EVENT, IN_PROGRESS);
        }
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void UpdateAI(const uint32 diff)
    {
        switch (Phase)
        {
            case PHASE_1:
                if (uiTimer <= diff)
                {
                    Creature *pSummon = m_creature->SummonCreature(RAND(CREATURE_FETID_TROLL_CORPSE,CREATURE_HULKING_CORPSE,CREATURE_RISEN_SHADOWCASTER), AddSpawnPoint.x, AddSpawnPoint.y , AddSpawnPoint.z, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN,20000);
                    pSummon->GetMotionMaster()->MovePoint(0, AddDestinyPoint.x, AddDestinyPoint.y, AddDestinyPoint.z);
                    //If spell is casted stops casting arcane field so no spell casting
                    //DoCast(m_creature,SPELL_SUMMON_MINIONS);
                    uiTimer = 3000;
                } else uiTimer -= diff;
                if (uiCrystalHandlerTimer <= diff)
                {
                    //TODO: say
                    Creature *pCrystalHandler = m_creature->SummonCreature(CREATURE_CRYSTAL_HANDLER, CrystalHandlerSpawnPoint.x, CrystalHandlerSpawnPoint.y , CrystalHandlerSpawnPoint.z, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN,20000);
                    pCrystalHandler->GetMotionMaster()->MovePoint(0, AddDestinyPoint.x, AddDestinyPoint.y, AddDestinyPoint.z);
                    uiCrystalHandlerTimer = urand(20000,30000);
                } else uiCrystalHandlerTimer -= diff;
                break;
            case PHASE_2:
                if (uiTimer <= diff)
                {
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(pTarget, HEROIC(RAND(SPELL_ARCANE_BLAST,SPELL_BLIZZARD,SPELL_FROSTBOLT,SPELL_WRATH_OF_MISERY),
                                               RAND(H_SPELL_ARCANE_BLAST,H_SPELL_BLIZZARD,H_SPELL_FROSTBOLT,H_SPELL_WRATH_OF_MISERY)));
                    uiTimer = urand(1000,3000);
                } else uiTimer -= diff;
                break;
        }
    }
    void JustDied(Unit* killer)
    {
        if (pInstance)
        {
            pInstance->SetData(DATA_NOVOS_EVENT, DONE);

            if (HeroicMode && bAchiev)
                pInstance->DoCompleteAchievement(ACHIEV_OH_NOVOS);
        }
        lSummons.DespawnAll();
    }

    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;
        DoScriptText(SAY_KILL, m_creature);
    }

    void JustSummoned(Creature *summon)
    {
        lSummons.Summon(summon);
    }

    void RemoveCrystal()
    {
        if (!luiCrystals.empty())
        {
            if (pInstance)
                if (GameObject *pTemp = pInstance->instance->GetGameObject(luiCrystals.back()))
                    pTemp->SetGoState(GO_STATE_READY);
            luiCrystals.pop_back();
        }
        if (luiCrystals.empty())
        {
            m_creature->CastStop();
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            Phase = PHASE_2;
            uiTimer = 1000;
        }
    }
};

struct TRINITY_DLL_DECL mob_crystal_handlerAI : public ScriptedAI
{
    mob_crystal_handlerAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance *pInstance;

    void JustDied(Unit* killer)
    {
        if (Creature* pNovos = Unit::GetCreature(*m_creature, pInstance ? pInstance->GetData64(DATA_NOVOS) : 0))
            CAST_AI(boss_novosAI,pNovos->AI())->RemoveCrystal();
    }
};

struct TRINITY_DLL_DECL mob_novos_minionAI : public ScriptedAI
{
    mob_novos_minionAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance *pInstance;

    void MovementInform(uint32 type, uint32 id)
    {
        if(type != POINT_MOTION_TYPE)
            return;
        if (Creature* pNovos = Unit::GetCreature(*m_creature, pInstance ? pInstance->GetData64(DATA_NOVOS) : 0))
            CAST_AI(boss_novosAI, pNovos->AI())->bAchiev = false;
    }
};

CreatureAI* GetAI_boss_novos(Creature* pCreature)
{
    return new boss_novosAI (pCreature);
}

CreatureAI* GetAI_mob_crystal_handler(Creature* pCreature)
{
    return new mob_crystal_handlerAI (pCreature);
}

CreatureAI* GetAI_mob_novos_minion(Creature* pCreature)
{
    return new mob_novos_minionAI (pCreature);
}

void AddSC_boss_novos()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_novos";
    newscript->GetAI = &GetAI_boss_novos;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_crystal_handler";
    newscript->GetAI = &GetAI_mob_crystal_handler;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_novos_minion";
    newscript->GetAI = &GetAI_mob_novos_minion;
    newscript->RegisterSelf();
}
