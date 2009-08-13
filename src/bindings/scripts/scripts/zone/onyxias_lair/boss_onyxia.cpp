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
SDName: Boss_Onyxia
SD%Complete: 90
SDComment: Spell Heated Ground is wrong, flying animation, visual for area effect
SDCategory: Onyxia's Lair
EndScriptData */

#include "precompiled.h"

#define SAY_AGGRO                   -1249000
#define SAY_KILL                    -1249001
#define SAY_PHASE_2_TRANS           -1249002
#define SAY_PHASE_3_TRANS           -1249003
#define EMOTE_BREATH                -1249004

#define SPELL_WINGBUFFET            18500
#define SPELL_FLAMEBREATH           18435
#define SPELL_CLEAVE                19983
#define SPELL_TAILSWEEP             15847
#define SPELL_KNOCK_AWAY            19633

#define SPELL_ENGULFINGFLAMES       20019
#define SPELL_DEEPBREATH            23461
#define SPELL_FIREBALL              18392

#define SPELL_BELLOWINGROAR         18431
#define SPELL_HEATED_GROUND         22191       //Wrong Spell

#define SPELL_SUMMONWHELP           17646

#define CREATURE_WHELP      11262

static float MovementLocations[4][3]=
{
    {-64.0523, -213.0619, -68.2985},
    {12.4636, -220.01490, -68.0548},
    {-38.8391, -182.3220, -68.9457},
    {-37.0390, -244.8760, -68.1278}
};

static float SpawnLocations[4][3]=
{
    {-30.127, -254.463, -89.440},
    {-30.817, -177.106, -89.258},
    {14.480, -241.560, -85.6300},
    {17.372, -190.840, -85.2810},
};

struct TRINITY_DLL_DECL boss_onyxiaAI : public ScriptedAI
{
    boss_onyxiaAI(Creature* c) : ScriptedAI(c) {}

    uint32 Phase;

    uint32 FlameBreathTimer;
    uint32 CleaveTimer;
    uint32 TailSweepTimer;
    uint32 MovementTimer;
    uint32 EngulfingFlamesTimer;
    uint32 SummonWhelpsTimer;
    uint32 BellowingRoarTimer;
    uint32 WingBuffetTimer;
    uint32 KnockAwayTimer;
    uint32 FireballTimer;

    bool InitialSpawn;

    void Reset()
    {
        Phase = 1;

        FlameBreathTimer = 20000;
        TailSweepTimer = 2000;
        CleaveTimer = 15000;
        MovementTimer = 3000;
        EngulfingFlamesTimer = 15000;
        SummonWhelpsTimer = 45000;
        BellowingRoarTimer = 30000;
        WingBuffetTimer = 17000;
        KnockAwayTimer = 15000;
        FireballTimer = 18000;

        InitialSpawn = true;
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        DoZoneInCombat();
    }

    void JustDied(Unit* Killer)
    {
    }

    void KilledUnit(Unit *victim)
    {
        DoScriptText(SAY_KILL, m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 60) && (Phase == 1))
        {
            Phase = 2;
            m_creature->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            m_creature->SetHover(true);
            m_creature->GetMotionMaster()->Clear(false);
            m_creature->GetMotionMaster()->MoveIdle();
            DoScriptText(SAY_PHASE_2_TRANS, m_creature);
        }

        if (((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 40) && (Phase == 2))
        {
            Phase = 3;
            m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            m_creature->SetHover(false);
            m_creature->GetMotionMaster()->MovePoint(0, -10.6155, -219.357, -87.7344);
            DoStartMovement(m_creature->getVictim());
            m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
            DoScriptText(SAY_PHASE_3_TRANS, m_creature);
            m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
        }

        if (Phase == 1 || Phase == 3)
        {
            if (FlameBreathTimer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_FLAMEBREATH);
                FlameBreathTimer = 15000;
            }else FlameBreathTimer -= diff;

            if (TailSweepTimer < diff)
            {
                Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 1);
                if (target && !m_creature->HasInArc(M_PI, target))
                    DoCast(target, SPELL_TAILSWEEP);

                TailSweepTimer = 10000;
            }else TailSweepTimer -= diff;

            if (CleaveTimer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_CLEAVE);
                CleaveTimer = 10000;
            }else CleaveTimer -= diff;

            if (WingBuffetTimer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_WINGBUFFET);
                WingBuffetTimer = 7000 + ((rand()%8)*1000);
            }else WingBuffetTimer -= diff;

            if (KnockAwayTimer < diff)
            {
                if (rand() <= 30)
                {
                    DoCast(m_creature->getVictim(), SPELL_KNOCK_AWAY);
                }
                KnockAwayTimer = 15000;
            }else KnockAwayTimer -= diff;

            if (Phase == 3)
            {
                if (BellowingRoarTimer < diff)
                {
                    DoCast(m_creature->getVictim(), SPELL_BELLOWINGROAR);

                    BellowingRoarTimer = 30000;
                }else BellowingRoarTimer -= diff;

                if (SummonWhelpsTimer < diff)
                {
                    SummonWhelps(Phase);

                    SummonWhelpsTimer = 45000;
                }else SummonWhelpsTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }

        if (Phase == 2)
        {
            if (InitialSpawn)
            {
                InitialSpawn = false;

                for(uint32 i = 0; i < 10; ++i)
                {
                    uint32 random = rand()%4;
                    Creature* Whelp = m_creature->SummonCreature(CREATURE_WHELP, SpawnLocations[random][0], SpawnLocations[random][1], SpawnLocations[random][2], 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30000);
                    if (Whelp)
                        Whelp->AI()->AttackStart(SelectUnit(SELECT_TARGET_RANDOM, 0));
                }
            }

            if (EngulfingFlamesTimer < diff)
            {
                DoCast(SelectUnit(SELECT_TARGET_RANDOM, 0), SPELL_ENGULFINGFLAMES);
                m_creature->HandleEmoteCommand(ANIM_FLY);

                EngulfingFlamesTimer = 10000;
            }
            else EngulfingFlamesTimer -= diff;

            if (FireballTimer < diff)
            {
                DoCast(SelectUnit(SELECT_TARGET_RANDOM, 0), SPELL_FIREBALL);

                FireballTimer = 18000;
            }
            else FireballTimer -= diff;

            if (MovementTimer < diff)
            {
                if (rand()%100 < 30)
                {
                    DoScriptText(EMOTE_BREATH, m_creature);
                    DoCast(m_creature->getVictim(), SPELL_DEEPBREATH);
                }
                else ChangePosition();

                MovementTimer = 25000;
            }else MovementTimer -= diff;

            if (SummonWhelpsTimer < diff)
            {
                SummonWhelps(Phase);

                SummonWhelpsTimer = 45000;
            }
            else SummonWhelpsTimer -= diff;
        }
    }

    void ChangePosition()
    {
        uint32 random = rand() % 4;
        if (random<4){
            m_creature->GetMotionMaster()->MovePoint(0, MovementLocations[random][0], MovementLocations[random][1], MovementLocations[random][2]);}
    }

    void SummonWhelps(uint32 Phase)
    {
        if (Phase == 2)
        {
            uint32 max = rand()%10;
            for(uint32 i = 0; i < max; ++i)
            {
                uint32 random = rand()%3;
                Creature* Whelp = m_creature->SummonCreature(CREATURE_WHELP, SpawnLocations[random][0], SpawnLocations[random][1], SpawnLocations[random][2], 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30000);
                if (Whelp)
                    Whelp->AI()->AttackStart(SelectUnit(SELECT_TARGET_RANDOM, 0));
            }
        }

        if (Phase == 3)
        {
            uint32 max = rand() % 10 +1;
            if (max < 5)
            {
                for(uint32 i = 0; i < max; ++i)
                {
                    uint32 random = rand()%4;
                    Creature* Whelp = m_creature->SummonCreature(CREATURE_WHELP, SpawnLocations[random][0], SpawnLocations[random][1], SpawnLocations[random][2], 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30000);
                    if (Whelp)
                        Whelp->AI()->AttackStart(SelectUnit(SELECT_TARGET_RANDOM, 0));
                }
            }
        }
    }
};

CreatureAI* GetAI_boss_onyxiaAI(Creature *_Creature)
{
    return new boss_onyxiaAI (_Creature);
}

void AddSC_boss_onyxia()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_onyxia";
    newscript->GetAI = &GetAI_boss_onyxiaAI;
    newscript->RegisterSelf();
}

