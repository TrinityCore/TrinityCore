/*
 * Copyright (C) 2008 - 2010 Trinity <http://www.trinitycore.org/>
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

#include "ScriptedPch.h"
#include "ulduar.h"

#define GAMEOBJECT_GIVE_OF_THE_OBSERVER 194821

enum Spells
{
    SPELL_ASCEND                    = 64487,
    SPELL_BERSERK                   = 47008,
    SPELL_BIG_BANG                  = 64443,
    H_SPELL_BIG_BANG                = 64584,
    SPELL_COSMIC_SMASH              = 62301,
    H_SPELL_COSMIC_SMASH            = 64598,
    SPELL_PHASE_PUNCH               = 64412,
    SPELL_QUANTUM_STRIKE            = 64395,
    H_SPELL_QUANTUM_STRIKE          = 64592,
    SPELL_BLACK_HOLE_EXPLOSION      = 64122,
    SPELL_ARCANE_BARAGE             = 64599,
    H_SPELL_ARCANE_BARAGE           = 64607
};

enum Creatures
{
    CREATURE_COLLAPSING_STAR        = 32955,
    CREATURE_BLACK_HOLE             = 32953,
    CREATURE_LIVING_CONSTELLATION   = 33052,
    CREATURE_DARK_MATTER            = 33089
};

#define NORDRASSIL_X               1614.288574
#define NORDRASSIL_Y               -320.713287
#define NORDRASSIL_Z               417.321167
#define NORDRASSIL_X               1614.276245
#define NORDRASSIL_Y               -287.016632
#define NORDRASSIL_Z               417.321106
#define NORDRASSIL_X               1650.428467
#define NORDRASSIL_Y               -292.331390
#define NORDRASSIL_Z               417.321167
#define NORDRASSIL_X               1649.501831
#define NORDRASSIL_Y               -324.609222
#define NORDRASSIL_Z               417.322174

enum Texts
{
    SAY_AGGRO                    = -1620000,
    SAY_KILL_1                   = -1620005,
    SAY_KILL_2                   = -1620006,
    SAY_BIG_BANG_1               = -1620002,
    SAY_BIG_BANG_2               = -1620003,
    SAY_PHASE_2                  = -1620003,
    SAY_BLACK_HOLE               = -1620004,
	SAY_BERSERK                  = -1620007,
    SAY_SUMMON_COLLAPSING_STAR   = -1620008,
    SAY_ENGADED_FOR_FIRTS_TIME   = -1620001,
    SAY_SUMMON1                  = -1620010,
    SAY_SUMMON2                  = -1620011,
    SAY_SUMMON3                  = -1620012,
    SAY_DEATH_1                  = -1620013,
    SAY_DEATH_2                  = -1620014,
    SAY_DEATH_3                  = -1620015,
    SAY_DEATH_4                  = -1620009,
    SAY_DEFEAT_1                 = -1620016,
    SAY_DEFEAT_2                 = -1620017,
    SAY_DEFEAT_3                 = -1620018
};

struct boss_algalonAI : public ScriptedAI
{
    boss_algalonAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    std::list<uint64> m_lCollapsingStarGUIDList;

    uint32 Phase;
    uint32 Ascend_Timer;
    uint32 Berserk_Timer;
    uint32 BigBang_Timer;
    uint32 CosmicSmash_Timer;
    uint32 PhasePunch_Timer;
    uint32 QuantumStrike_Timer;
    uint32 CollapsingStar_Timer;
    uint32 uiPhase_timer;
    uint32 uiStep;

    uint64 BlackHoleGUID;

    bool Enrage;
    bool m_bIsHeroicMode;
    bool Summon;

    void EnterCombat(Unit* who)
    {
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        me->SetReactState(REACT_PASSIVE);
    }

    void KilledUnit(Unit *victim)
    {
        DoScriptText(RAND(SAY_KILL_1,SAY_KILL_2), me);
    }

    void Reset()
    {
        Phase = 1;

        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        DoScriptText(SAY_DEFEAT_1, me);
        DoScriptText(SAY_DEFEAT_2, me);
        DoScriptText(SAY_DEFEAT_3, me);
        if (pInstance)
            pInstance->SetData(TYPE_ALGALON, NOT_STARTED);

        BlackHoleGUID = 0;

        Ascend_Timer = 480000; //8 minutes
        QuantumStrike_Timer = 4000 + rand()%10000;
        Berserk_Timer = 360000; //6 minutes
        CollapsingStar_Timer = urand(15000, 20000); //Spawns between 15 to 20 seconds
        BigBang_Timer = 90000;
        PhasePunch_Timer = 8000;
        CosmicSmash_Timer = urand(30000, 60000);
    }

    void JumpToNextStep(uint32 uiTimer)
    {
        uiPhase_timer = uiTimer;
        ++uiStep;
    }

    void Aggro(Unit* pWho)
    {
        me->InterruptSpell(CURRENT_CHANNELED_SPELL);
        me->SetInCombatWithZone();
        if (pInstance)
            pInstance->SetData(TYPE_ALGALON, IN_PROGRESS);
    }

    void DespawnCollapsingStar()
    {
        if (m_lCollapsingStarGUIDList.empty())
            return;
        for(std::list<uint64>::iterator itr = m_lCollapsingStarGUIDList.begin(); itr != m_lCollapsingStarGUIDList.end(); ++itr)
        {
            if (Creature* pTemp = (Creature*)Unit::GetUnit(*me, *itr))
            {
                if (pTemp->isAlive())
                    pTemp->ForcedDespawn();
            }
        }
        m_lCollapsingStarGUIDList.clear();
    }

    void JustSummoned(Creature* pSummoned)
    {
        if (pSummoned->GetEntry() == CREATURE_COLLAPSING_STAR)
        {
            Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
            if (me->getVictim())
                pSummoned->AI()->AttackStart(pTarget ? pTarget : me->getVictim());
            m_lCollapsingStarGUIDList.push_back(pSummoned->GetGUID());
        }
    }

    void SummonCollapsingStar(Unit* target)
    {
        DoScriptText(SAY_SUMMON_COLLAPSING_STAR, me);
        me->SummonCreature(CREATURE_COLLAPSING_STAR,target->GetPositionX()+15.0,target->GetPositionY()+15.0,target->GetPositionZ(),0, TEMPSUMMON_TIMED_DESPAWN, 100000);
        DoScriptText(SAY_BLACK_HOLE, me);
        me->SummonCreature(CREATURE_BLACK_HOLE,target->GetPositionX()+15.0,target->GetPositionY()+15.0,target->GetPositionZ(),0, TEMPSUMMON_TIMED_DESPAWN, 27000);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if ((me->GetHealth()*100 / me->GetMaxHealth()) < 20 && Phase == 1)
        {
            Phase = 2;
            DoScriptText(SAY_PHASE_2, me);
        }

        if ((me->GetHealth()*100 / me->GetMaxHealth()) < 2)
        {
            me->SummonGameObject(GAMEOBJECT_GIVE_OF_THE_OBSERVER, 1634.258667, -295.101166,417.321381,0,0,0,0,0,-10);

            DoScriptText(SAY_DEATH_1, me);
            DoScriptText(SAY_DEATH_2, me);
            DoScriptText(SAY_DEATH_3, me);
            DoScriptText(SAY_DEATH_4, me);

            me->DisappearAndDie();

            if (pInstance)
                pInstance->SetData(TYPE_ALGALON, DONE);
        }

        if (Phase == 1)
        {
            if (!Summon)
            {
                if (uiPhase_timer <= diff)
                {
                    switch(uiStep)
                    {
                        case 1: DoScriptText(SAY_SUMMON1, m_creature); break; JumpToNextStep(3000);
                        case 2: DoScriptText(SAY_SUMMON2, m_creature); break; JumpToNextStep(3000);
                        case 3: DoScriptText(SAY_SUMMON3, m_creature); break; JumpToNextStep(3000);
                        case 4: DoScriptText(SAY_ENGADED_FOR_FIRTS_TIME, m_creature); break; JumpToNextStep(3000);
                        case 5: DoScriptText(SAY_AGGRO, m_creature); break;
                        case 6: m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE); break;
                        case 7: m_creature->SetReactState(REACT_AGGRESSIVE); break;
                    }
                }else uiPhase_timer -= diff;
            }

            if(QuantumStrike_Timer <= diff)
            {
                DoCast(me->getVictim(), m_bIsHeroicMode ? H_SPELL_QUANTUM_STRIKE : SPELL_QUANTUM_STRIKE, true);

                QuantumStrike_Timer = 4000 + rand()%10000;
            }else QuantumStrike_Timer -= diff;

            if(BigBang_Timer <= diff)
            {
                DoScriptText(RAND(SAY_BIG_BANG_1,SAY_BIG_BANG_2), me);
                DoCast(me->getVictim(), m_bIsHeroicMode ? H_SPELL_BIG_BANG : SPELL_BIG_BANG, true);

                BigBang_Timer = 90000;
            }else BigBang_Timer -= diff;

            if(Ascend_Timer <= diff)
            {
                DoCast(me->getVictim(),SPELL_ASCEND, true);

                Ascend_Timer = 480000;
            }else Ascend_Timer -= diff;

            if(PhasePunch_Timer <= diff)
            {
                DoCast(me->getVictim(),SPELL_PHASE_PUNCH, true);

                PhasePunch_Timer = 8000;
            }else PhasePunch_Timer -= diff;

            if(CosmicSmash_Timer <= diff)
            {
                DoCast(SelectUnit(SELECT_TARGET_RANDOM, 0), m_bIsHeroicMode ? H_SPELL_COSMIC_SMASH : SPELL_COSMIC_SMASH, true);

                CosmicSmash_Timer = urand(30000, 60000);
            }else CosmicSmash_Timer -= diff;

            if(Berserk_Timer <= diff)
            {
                DoScriptText(SAY_BERSERK, me);
                DoCast(me->getVictim(),SPELL_BERSERK, true);

                Berserk_Timer = 360000;
            }else Berserk_Timer -= diff;

            DoMeleeAttackIfReady();

            EnterEvadeIfOutOfCombatArea(diff);
        }

        if (Phase == 2)
        {
            if (Enrage)
            {
                if (Ascend_Timer  <= diff)
                {
                    DoCast(me, SPELL_ASCEND);
                    DoScriptText(SAY_BERSERK, me);
                    Ascend_Timer = 360000 + rand()%5000;
                    Enrage = false;
                } else Ascend_Timer -= diff;
            }
        }

        DoMeleeAttackIfReady();
    }
};
//Collapsing Star
struct mob_collapsing_starAI : public ScriptedAI
{
    mob_collapsing_starAI(Creature *pCreature) : ScriptedAI(pCreature)
    {
        pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* pInstance;

    uint32 BlackHoleExplosion_Timer;

    void Reset()
    {
        BlackHoleExplosion_Timer = 0;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if(BlackHoleExplosion_Timer <= diff)
        {
            me->CastSpell(me, SPELL_BLACK_HOLE_EXPLOSION, false);
            BlackHoleExplosion_Timer = 0;
        }else BlackHoleExplosion_Timer -= diff;
    }
};

CreatureAI* GetAI_boss_algalon(Creature* pCreature)
{
    return new boss_algalonAI(pCreature);
}

CreatureAI* GetAI_mob_collapsing_star(Creature* pCreature)
{
    return new mob_collapsing_starAI(pCreature);
}

void AddSC_boss_Algalon()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_algalon";
    newscript->GetAI = &GetAI_boss_algalon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_collapsing_star";
    newscript->GetAI = &GetAI_mob_collapsing_star;
    newscript->RegisterSelf();
}
