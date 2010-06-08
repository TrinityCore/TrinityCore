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

#include "ScriptPCH.h"
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

enum Yells
{
    SAY_AGGRO                                   = -1603000,
    SAY_SLAY_1                                  = -1603001,
    SAY_SLAY_2                                  = -1603002,
    SAY_ENGADED_FOR_FIRTS_TIME                  = -1603003,
    SAY_PHASE_2                                 = -1603004,
    SAY_SUMMON_COLLAPSING_STAR                  = -1603005,
    SAY_DEATH_1                                 = -1603006,
    SAY_DEATH_2                                 = -1603007,
    SAY_DEATH_3                                 = -1603008,
    SAY_DEATH_4                                 = -1603009,
    SAY_DEATH_5                                 = -1603010,
    SAY_BERSERK                                 = -1603011,
    SAY_BIG_BANG_1                              = -1603012,
    SAY_BIG_BANG_2                              = -1603013,
    SAY_TIMER_1                                 = -1603014,
    SAY_TIMER_2                                 = -1603015,
    SAY_TIMER_3                                 = -1603016,
    SAY_SUMMON_1                                = -1603017,
    SAY_SUMMON_2                                = -1603018,
    SAY_SUMMON_3                                = -1603019,
};

struct boss_algalonAI : public ScriptedAI
{
    boss_algalonAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        Summon = false; // not in reset. intro speech done only once.
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
    bool Summon;

    void EnterCombat(Unit* who)
    {
        if (Summon)
        {
            DoScriptText(SAY_AGGRO, me);
            me->InterruptSpell(CURRENT_CHANNELED_SPELL);
            DoZoneInCombat(who->ToCreature());
        }
        else
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
            uiStep = 1;
        }

        if (pInstance)
            pInstance->SetData(TYPE_ALGALON, IN_PROGRESS);
    }

    void KilledUnit(Unit * /*victim*/)
    {
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), me);
    }

    void Reset()
    {
        Phase = 1;

        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        if (pInstance)
            pInstance->SetData(TYPE_ALGALON, NOT_STARTED);

        BlackHoleGUID = 0;

        uiPhase_timer = 0;
        Ascend_Timer = 480000; //8 minutes
        QuantumStrike_Timer = 4000 + rand()%10000;
        Berserk_Timer = 360000; //6 minutes
        CollapsingStar_Timer = urand(15000, 20000); //Spawns between 15 to 20 seconds
        BigBang_Timer = 90000;
        PhasePunch_Timer = 8000;
        CosmicSmash_Timer = urand(30000, 60000);
        Enrage = false;
    }

    void JumpToNextStep(uint32 uiTimer)
    {
        uiPhase_timer = uiTimer;
        ++uiStep;
    }

    void DespawnCollapsingStar()
    {
        if (m_lCollapsingStarGUIDList.empty())
            return;

        for (std::list<uint64>::const_iterator itr = m_lCollapsingStarGUIDList.begin(); itr != m_lCollapsingStarGUIDList.end(); ++itr)
        {
            if (Creature* pTemp = Unit::GetCreature(*me, *itr))
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
        me->SummonCreature(CREATURE_BLACK_HOLE,target->GetPositionX()+15.0,target->GetPositionY()+15.0,target->GetPositionZ(),0, TEMPSUMMON_TIMED_DESPAWN, 27000);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (Phase == 1 && HealthBelowPct(20))
        {
            Phase = 2;
            DoScriptText(SAY_PHASE_2, me);
        }

        if (HealthBelowPct(2))
        {
            me->SummonGameObject(GAMEOBJECT_GIVE_OF_THE_OBSERVER, 1634.258667, -295.101166,417.321381,0,0,0,0,0,0);

            // All of them. or random?
            DoScriptText(SAY_DEATH_1, me);
            DoScriptText(SAY_DEATH_2, me);
            DoScriptText(SAY_DEATH_3, me);
            DoScriptText(SAY_DEATH_4, me);
            DoScriptText(SAY_DEATH_5, me);

            me->DisappearAndDie();

            if (pInstance)
                pInstance->SetData(TYPE_ALGALON, DONE);

            return;
        }

        if (Phase == 1)
        {
            if (!Summon)
            {
                if (uiPhase_timer <= diff)
                {
                    switch(uiStep)
                    {
                        case 1:
                            DoScriptText(SAY_SUMMON_1, me);
                            JumpToNextStep(3000);
                            break;
                        case 2:
                            DoScriptText(SAY_SUMMON_2, me);
                            JumpToNextStep(3000);
                            break;
                        case 3:
                            DoScriptText(SAY_SUMMON_3, me);
                            JumpToNextStep(3000);
                            break;
                        case 4:
                            DoScriptText(SAY_ENGADED_FOR_FIRTS_TIME, me);
                            JumpToNextStep(3000);
                            break;
                        case 5:
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            me->SetReactState(REACT_AGGRESSIVE);
                            Summon = true;
                            break;
                    }
                } else uiPhase_timer -= diff;

                return;
            }

            if (QuantumStrike_Timer <= diff)
            {
                DoCast(me->getVictim(), RAID_MODE(SPELL_QUANTUM_STRIKE,H_SPELL_QUANTUM_STRIKE), true);

                QuantumStrike_Timer = urand(4000, 14000);
            } else QuantumStrike_Timer -= diff;

            if (BigBang_Timer <= diff)
            {
                DoScriptText(RAND(SAY_BIG_BANG_1,SAY_BIG_BANG_2), me);
                DoCast(me->getVictim(), RAID_MODE(SPELL_BIG_BANG,H_SPELL_BIG_BANG), true);

                BigBang_Timer = 90000;
            } else BigBang_Timer -= diff;

            if (Ascend_Timer <= diff)
            {
                DoCast(me->getVictim(),SPELL_ASCEND, true);

                Ascend_Timer = 480000;
            } else Ascend_Timer -= diff;

            if (PhasePunch_Timer <= diff)
            {
                DoCast(me->getVictim(),SPELL_PHASE_PUNCH, true);

                PhasePunch_Timer = 8000;
            } else PhasePunch_Timer -= diff;

            if (CosmicSmash_Timer <= diff)
            {
                DoCast(SelectUnit(SELECT_TARGET_RANDOM, 0), RAID_MODE(SPELL_COSMIC_SMASH,H_SPELL_COSMIC_SMASH), true);

                CosmicSmash_Timer = urand(30000, 60000);
            } else CosmicSmash_Timer -= diff;

            if (Berserk_Timer <= diff)
            {
                DoScriptText(SAY_BERSERK, me);
                DoCast(me->getVictim(),SPELL_BERSERK, true);

                Berserk_Timer = 360000;
            } else Berserk_Timer -= diff;

            DoMeleeAttackIfReady();

            EnterEvadeIfOutOfCombatArea(diff);
        }

        if (Phase == 2)
        {
            if (Enrage)
            {
                if (Ascend_Timer <= diff)
                {
                    DoCast(me, SPELL_ASCEND);
                    DoScriptText(SAY_BERSERK, me);
                    Ascend_Timer = urand(360000,365000);
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
        pInstance = pCreature->GetInstanceData();
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

        if (BlackHoleExplosion_Timer <= diff)
        {
            me->CastSpell(me, SPELL_BLACK_HOLE_EXPLOSION, false);
            BlackHoleExplosion_Timer = 0;
        } else BlackHoleExplosion_Timer -= diff;
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
