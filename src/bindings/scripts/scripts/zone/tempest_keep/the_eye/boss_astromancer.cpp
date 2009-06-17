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
SDName: Boss_Astromancer
SD%Complete: 80
SDComment:
SDCategory: Tempest Keep, The Eye
EndScriptData */

#include "precompiled.h"
#include "def_the_eye.h"

#define SAY_AGGRO                           -1550007
#define SAY_SUMMON1                         -1550008
#define SAY_SUMMON2                         -1550009
#define SAY_KILL1                           -1550010
#define SAY_KILL2                           -1550011
#define SAY_KILL3                           -1550012
#define SAY_DEATH                           -1550013
#define SAY_VOIDA                           -1550014
#define SAY_VOIDB                           -1550015

#define SPELL_ARCANE_MISSILES                 33031
#define SPELL_MARK_OF_THE_ASTROMANCER         33045
#define MARK_OF_SOLARIAN                      33023
#define SPELL_BLINDING_LIGHT                  33009
#define SPELL_FEAR                            29321
#define SPELL_VOID_BOLT                       39329
#define SPELL_SPOTLIGHT                       25824
#define SPELL_WRATH_OF_THE_ASTROMANCER        42783

#define CENTER_X                             432.909f
#define CENTER_Y                             -373.424f
#define CENTER_Z                             17.9608f
#define CENTER_O                             1.06421f
#define SMALL_PORTAL_RADIUS                  12.6f
#define LARGE_PORTAL_RADIUS                  26.0f
#define PORTAL_Z                             17.005f

#define SOLARIUM_AGENT                       18925
#define SOLARIUM_PRIEST                      18806
#define ASTROMANCER_SOLARIAN_SPOTLIGHT       18928

#define MODEL_HUMAN                          18239
#define MODEL_VOIDWALKER                     18988

#define SOLARIUM_HEAL                        41378
#define SOLARIUM_SMITE                       31740
#define SOLARIUM_SILENCE                     37160

#define WV_ARMOR                    31000
#define MIN_RANGE_FOR_DOT_JUMP      20.0f

                             // x,          y,      z,         o
static float SolarianPos[4] = {432.909, -373.424, 17.9608, 1.06421};

struct TRINITY_DLL_DECL boss_high_astromancer_solarianAI : public ScriptedAI
{
    boss_high_astromancer_solarianAI(Creature *c) : ScriptedAI(c), Summons(m_creature)
    {
        pInstance = c->GetInstanceData();

        defaultarmor = m_creature->GetArmor();
        defaultsize = m_creature->GetFloatValue(OBJECT_FIELD_SCALE_X);
    }

    ScriptedInstance *pInstance;
    SummonList Summons;

    uint8 Phase;

    uint32 ArcaneMissiles_Timer;
    uint32 MarkOfTheAstromancer_Timer;
    uint32 BlindingLight_Timer;
    uint32 Fear_Timer;
    uint32 VoidBolt_Timer;
    uint32 Phase1_Timer;
    uint32 Phase2_Timer;
    uint32 Phase3_Timer;
    uint32 AppearDelay_Timer;
    uint32 MarkOfTheSolarian_Timer;
    uint32 Jump_Timer;
    uint32 defaultarmor;
    uint32 Wrath_Timer;

    float defaultsize;
    float Portals[3][3];

    bool AppearDelay;
    bool BlindingLight;

    void Reset()
    {
        ArcaneMissiles_Timer = 2000;
        MarkOfTheAstromancer_Timer = 15000;
        BlindingLight_Timer = 41000;
        Fear_Timer = 20000;
        VoidBolt_Timer = 10000;
        Phase1_Timer = 50000;
        Phase2_Timer = 10000;
        Phase3_Timer = 15000;
        AppearDelay_Timer = 2000;
        BlindingLight = false;
        AppearDelay = false;
        MarkOfTheSolarian_Timer=45000;
        Jump_Timer=8000;
        Wrath_Timer = 20000+rand()%5000;//twice in phase one
        Phase = 1;
        Wrath_Timer = 20000+rand()%5000;//twice in phase one

        if(pInstance)
            pInstance->SetData(DATA_HIGHASTROMANCERSOLARIANEVENT, NOT_STARTED);

        m_creature->SetArmor(defaultarmor);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetVisibility(VISIBILITY_ON);
        m_creature->SetFloatValue(OBJECT_FIELD_SCALE_X, defaultsize);
        m_creature->SetDisplayId(MODEL_HUMAN);

        Summons.DespawnAll();
    }

    void StartEvent()
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if(pInstance)
            pInstance->SetData(DATA_HIGHASTROMANCERSOLARIANEVENT, IN_PROGRESS);
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%3)
        {
        case 0: DoScriptText(SAY_KILL1, m_creature); break;
        case 1: DoScriptText(SAY_KILL2, m_creature); break;
        case 2: DoScriptText(SAY_KILL3, m_creature); break;
        }
    }

    void JustDied(Unit *victim)
    {
        m_creature->SetFloatValue(OBJECT_FIELD_SCALE_X, defaultsize);
        m_creature->SetDisplayId(MODEL_HUMAN);
        DoScriptText(SAY_DEATH, m_creature);

        if(pInstance)
            pInstance->SetData(DATA_HIGHASTROMANCERSOLARIANEVENT, DONE);
    }

    void EnterCombat(Unit *who)
    {
        StartEvent();
    }

    void SummonMinion(uint32 entry, float x, float y, float z)
    {
        Creature* Summoned = m_creature->SummonCreature(entry, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
        if(Summoned)
        {
            if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                Summoned->AI()->AttackStart(target);

            Summons.Summon(Summoned);
        }
    }

    float Portal_X(float radius)
    {
        if ((rand()%2)==1)
            radius = -radius;

        return (radius * (float)(rand()%100)/100.0f + CENTER_X);
    }

    float Portal_Y(float x, float radius)
    {
        float z;

        switch(rand()%2)
        {
            case 0: z = 1; break;
            case 1: z = -1; break;
        }
        return (z*sqrt(radius*radius - (x - CENTER_X)*(x - CENTER_X)) + CENTER_Y);
    }

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim() )
            return;

        if (AppearDelay)
        {
            m_creature->StopMoving();
            m_creature->AttackStop();
            if (AppearDelay_Timer < diff)
            {
                AppearDelay = false;
                if (Phase == 2)
                {
                    m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    m_creature->SetVisibility(VISIBILITY_OFF);
                }
                AppearDelay_Timer = 2000;
            }else AppearDelay_Timer -= diff;
        }

        if (Phase == 1)
        {
            if (BlindingLight_Timer < diff){
                BlindingLight = true;
                BlindingLight_Timer = 45000;
            }else BlindingLight_Timer -= diff;

            if( Wrath_Timer < diff)
            {
                m_creature->InterruptNonMeleeSpells(false);
                DoCast(SelectTarget(SELECT_TARGET_RANDOM,1,100,true), SPELL_WRATH_OF_THE_ASTROMANCER, true);
                Wrath_Timer = 20000+rand()%5000;
            }else Wrath_Timer -= diff;

            if (ArcaneMissiles_Timer < diff)
            {
                if(BlindingLight)
                {
                    DoCast(m_creature->getVictim(), SPELL_BLINDING_LIGHT);
                    BlindingLight = false;
                }else{
                    Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0);

                    if(!m_creature->HasInArc(2.5f, target))
                        target = m_creature->getVictim();

                    if(target)
                        DoCast(target, SPELL_ARCANE_MISSILES);
                }
                ArcaneMissiles_Timer = 3000;
            }else ArcaneMissiles_Timer -= diff;

            if (MarkOfTheSolarian_Timer < diff)
            {
                DoCast(m_creature->getVictim(), MARK_OF_SOLARIAN);
                MarkOfTheSolarian_Timer = 45000;
            }else MarkOfTheSolarian_Timer -= diff;

            if (MarkOfTheAstromancer_Timer < diff) //A debuff that lasts for 5 seconds, cast several times each phase on a random raid member, but not the main tank
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true);
                if(target)
                    DoCast(target, SPELL_MARK_OF_THE_ASTROMANCER);
                else DoCast(m_creature->getVictim(), SPELL_MARK_OF_THE_ASTROMANCER);
                MarkOfTheAstromancer_Timer = 15000;
            }else MarkOfTheAstromancer_Timer -= diff;

            //Phase1_Timer
            if (Phase1_Timer < diff)
            {
                Phase = 2;
                Phase1_Timer = 50000;
                //After these 50 seconds she portals to the middle of the room and disappears, leaving 3 light portals behind.
                m_creature->GetMotionMaster()->Clear();
                m_creature->Relocate(SolarianPos[0], SolarianPos[1], SolarianPos[2], SolarianPos[3]);
                for(int i=0; i<=2; ++i)
                {
                    if (!i)
                    {
                        Portals[i][0] = Portal_X(SMALL_PORTAL_RADIUS);
                        Portals[i][1] = Portal_Y(Portals[i][0], SMALL_PORTAL_RADIUS);
                        Portals[i][2] = CENTER_Z;
                    }
                    else
                    {
                        Portals[i][0] = Portal_X(LARGE_PORTAL_RADIUS);
                        Portals[i][1] = Portal_Y(Portals[i][0], LARGE_PORTAL_RADIUS);
                        Portals[i][2] = PORTAL_Z;
                    }
                }
                if((abs(Portals[2][0] - Portals[1][0]) < 7) && (abs(Portals[2][1] - Portals[1][1]) < 7))
                {
                    int i=1;
                    if(abs(CENTER_X + 26.0f - Portals[2][0]) < 7)
                        i = -1;
                    Portals[2][0] = Portals[2][0]+7*i;
                    Portals[2][1] = Portal_Y(Portals[2][0], LARGE_PORTAL_RADIUS);
                }
                for (int i=0; i<=2; i++)
                {
                    Creature* Summoned = m_creature->SummonCreature(ASTROMANCER_SOLARIAN_SPOTLIGHT, Portals[i][0], Portals[i][1], Portals[i][2], CENTER_O, TEMPSUMMON_TIMED_DESPAWN, Phase2_Timer+Phase3_Timer+AppearDelay_Timer+1700);
                    if(Summoned)
                    {
                        Summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        Summoned->CastSpell(Summoned, SPELL_SPOTLIGHT, false);
                    }
                }
                AppearDelay = true;
            }else Phase1_Timer-=diff;
        }
        else if(Phase == 2)
        {
            //10 seconds after Solarian disappears, 12 mobs spawn out of the three portals.
            m_creature->AttackStop();
            m_creature->StopMoving();
            if (Phase2_Timer < diff)
            {
                Phase = 3;
                for (int i=0; i<=2; i++)
                    for (int j=1; j<=4; j++)
                        SummonMinion(SOLARIUM_AGENT, Portals[i][0], Portals[i][1], Portals[i][2]);

                DoScriptText(SAY_SUMMON1, m_creature);
                Phase2_Timer = 10000;
            } else Phase2_Timer -= diff;
        }
        else if(Phase == 3)
        {
            m_creature->AttackStop();
            m_creature->StopMoving();

            //Check Phase3_Timer
            if(Phase3_Timer < diff)
            {
                Phase = 1;

                //15 seconds later Solarian reappears out of one of the 3 portals. Simultaneously, 2 healers appear in the two other portals.
                int i = rand()%3;
                m_creature->GetMotionMaster()->Clear();
                m_creature->Relocate(Portals[i][0], Portals[i][1], Portals[i][2], CENTER_O);

                for (int j=0; j<=2; j++)
                    if (j!=i)
                        SummonMinion(SOLARIUM_PRIEST, Portals[j][0], Portals[j][1], Portals[j][2]);

                m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                m_creature->SetVisibility(VISIBILITY_ON);

                DoScriptText(SAY_SUMMON2, m_creature);
                AppearDelay = true;
                Phase3_Timer = 15000;
            }else Phase3_Timer -= diff;
        }
        else if(Phase == 4)
        {
            //Fear_Timer
            if (Fear_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_FEAR);
                Fear_Timer = 20000;
            }else Fear_Timer -= diff;

            //VoidBolt_Timer
            if (VoidBolt_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_VOID_BOLT);
                VoidBolt_Timer = 10000;
            }else VoidBolt_Timer -= diff;
        }

        //When Solarian reaches 20% she will transform into a huge void walker.
        if(Phase != 4 && ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth())<20))
        {
            Phase = 4;

            //To make sure she wont be invisible or not selecatble
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            m_creature->SetVisibility(VISIBILITY_ON);
            DoScriptText(SAY_VOIDA, m_creature);
            DoScriptText(SAY_VOIDB, m_creature);
            m_creature->SetArmor(WV_ARMOR);
            m_creature->SetDisplayId(MODEL_VOIDWALKER);
            m_creature->SetFloatValue(OBJECT_FIELD_SCALE_X, defaultsize*2.5f);
        }

        DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL mob_solarium_priestAI : public ScriptedAI
{
    mob_solarium_priestAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance *pInstance;

    uint32 healTimer;
    uint32 holysmiteTimer;
    uint32 aoesilenceTimer;

    void Reset()
    {
        healTimer = 9000;
        holysmiteTimer = 1;
        aoesilenceTimer = 15000;
    }

    void EnterCombat(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (healTimer < diff)
        {
            Unit* target = NULL;

            switch(rand()%2)
            {
                case 0:
                    if(pInstance)
                        target = Unit::GetUnit((*m_creature), pInstance->GetData64(DATA_ASTROMANCER));
                    break;
                case 1:
                    target = m_creature;
                    break;
            }

            if(target)
            {
                DoCast(target,SOLARIUM_HEAL);
                healTimer = 9000;
            }
        } else healTimer -= diff;

        if(holysmiteTimer < diff)
        {
            DoCast(m_creature->getVictim(), SOLARIUM_SMITE);
            holysmiteTimer = 4000;
        } else holysmiteTimer -= diff;

        if (aoesilenceTimer < diff)
        {
            DoCast(m_creature->getVictim(), SOLARIUM_SILENCE);
            aoesilenceTimer = 13000;
        } else aoesilenceTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_solarium_priest(Creature *_Creature)
{
    return new mob_solarium_priestAI (_Creature);
}

CreatureAI* GetAI_boss_high_astromancer_solarian(Creature *_Creature)
{
    return new boss_high_astromancer_solarianAI (_Creature);
}

void AddSC_boss_high_astromancer_solarian()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_high_astromancer_solarian";
    newscript->GetAI = &GetAI_boss_high_astromancer_solarian;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_solarium_priest";
    newscript->GetAI = &GetAI_mob_solarium_priest;
    newscript->RegisterSelf();
}

