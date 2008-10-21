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
SDName: Boss_Onyxia
SD%Complete: 50
SDComment: Phase 2 has many errors. Recommend Rewrite of entire script.
SDCategory: Onyxia's Lair
EndScriptData */

#include "precompiled.h"

#define SPELL_WINGBUFFET            18500
#define SPELL_FLAMEBREATH           18435
#define SPELL_CLEAVE                19983
#define SPELL_TAILSWEEP             15847
#define SPELL_KNOCK_AWAY            19633

#define SPELL_ENGULFINGFLAMES       20019
#define SPELL_DEEPBREATH            23461
#define SPELL_FIREBALL              18392

#define SPELL_BELLOWINGROAR         18431
#define SPELL_HEATED_GROUND         22191

#define SPELL_SUMMONWHELP           17646

#define SAY_AGGRO           "How fortuitous. Usually, I must leave my lair to feed."
#define SAY_KILL            "Learn your place mortal!"
#define SAY_PHASE_2_TRANS   "This meaningless exertion bores me. I'll incinerate you from above!"
#define SAY_PHASE_3_TRANS   "It seems you'll need another lesson!"
#define EMOTE_BREATH        "takes a deep breath..."

static float MovementLocations[7][3]=
{
    {-65.8444, -213.809, -60.2985},
    {22.87639, -217.152, -60.0548},
    {-33.5561, -182.682, -60.9457},
    {-31.4963, -250.123, -60.1278},
    {-2.78999, -181.431, -60.8962},
    {-54.9415, -232.242, -60.5555},
    {10.56655, -241.478, -60.9426},
};

static float SpawnLocations[4][3]=
{
    {-30.127, -254.463, -89.440},
    {-30.817, -177.106, -89.258},
    {14.480, -241.560, -85.6300},
    {17.372, -190.840, -85.2810},
};

#define CREATURE_WHELP      11262

struct TRINITY_DLL_DECL boss_onyxiaAI : public ScriptedAI
{
    boss_onyxiaAI(Creature* c) : ScriptedAI(c) {Reset();}

    uint32 Phase;

    uint32 FlameBreathTimer;
    uint32 CleaveTimer;
    uint32 TailSweepTimer;
    uint32 MovementTimer;
    uint32 EngulfingFlamesTimer;
    uint32 SummonWhelpsTimer;
    uint32 BellowingRoarTimer;
    uint32 WingBuffetTimer;

    void Reset()
    {
        Phase = 1;

        FlameBreathTimer = 20000;
        TailSweepTimer = 2000;
        CleaveTimer = 15000;
        MovementTimer = 5000;
        EngulfingFlamesTimer = 15000;
        SummonWhelpsTimer = 45000;
        BellowingRoarTimer = 30000;
        WingBuffetTimer = 17000;
    }

    void Aggro(Unit* who)
    {
        DoYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);
    }

    void KilledUnit(Unit *victim)
    {
        DoYell(SAY_KILL, LANG_UNIVERSAL, NULL);
    }

    void UpdateAI(const uint32 diff)
    {
        if(!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if(((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 60) && (Phase == 1))
        {
            Phase = 2;
            m_creature->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
            m_creature->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
            m_creature->GetMotionMaster()->Clear(false);
            m_creature->GetMotionMaster()->MoveIdle();
            DoYell(SAY_PHASE_2_TRANS, LANG_UNIVERSAL, NULL);
        }

        if(((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 40) && (Phase == 2))
        {
            Phase = 3;
            m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
            m_creature->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
            DoYell(SAY_PHASE_3_TRANS, LANG_UNIVERSAL, NULL);
        }

        if(Phase == 1 || Phase == 3)
        {
            if(FlameBreathTimer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_FLAMEBREATH);
                FlameBreathTimer = 15000;
            }else FlameBreathTimer -= diff;

            if(TailSweepTimer < diff)
            {
                Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 1);
                if(target && !m_creature->HasInArc(M_PI, target))
                    DoCast(target, SPELL_TAILSWEEP);

                TailSweepTimer = 10000;
            }else TailSweepTimer -= diff;

            if(CleaveTimer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_CLEAVE);
                CleaveTimer = 10000;
            }else CleaveTimer -= diff;

            if(WingBuffetTimer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_WINGBUFFET);
                WingBuffetTimer = 7000 + ((rand()%8)*1000);
            }else WingBuffetTimer -= diff;

            DoMeleeAttackIfReady();
        }

        if(Phase == 2)
        {
            if(!m_creature->isHover())
            {
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                m_creature->SetHover(true);
            }

            if(!m_creature->GetMotionMaster()->empty() && (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() != POINT_MOTION_TYPE))
                m_creature->GetMotionMaster()->Clear(false);

            if(MovementTimer < diff)
            {
                uint32 random = rand()%8;
                if(random < 7)
                    m_creature->GetMotionMaster()->MovePoint(0, MovementLocations[random][0], MovementLocations[random][1], MovementLocations[random][2]);
                else
                {
                    DoTextEmote(EMOTE_BREATH, NULL);
                    DoCast(m_creature->getVictim(), SPELL_DEEPBREATH);
                }
                MovementTimer = 25000;
            }else MovementTimer -= diff;

            if(EngulfingFlamesTimer < diff)
            {
                DoCast(SelectUnit(SELECT_TARGET_RANDOM, 0), SPELL_ENGULFINGFLAMES);
                EngulfingFlamesTimer = 10000;
            }else EngulfingFlamesTimer -= diff;

            if(SummonWhelpsTimer < diff)
            {
                uint32 max = rand()%20;
                for(uint8 i = 0; i < max; ++i)
                {
                    uint8 random = rand()%4;
                    Creature* Whelp = m_creature->SummonCreature(CREATURE_WHELP, SpawnLocations[random][0], SpawnLocations[random][1], SpawnLocations[random][2], 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30000);
                    if(Whelp)
                        Whelp->AI()->AttackStart(SelectUnit(SELECT_TARGET_RANDOM, 0));
                }
                SummonWhelpsTimer = 45000;
            }else SummonWhelpsTimer -= diff;
        }

        if(Phase == 3)
        {
            if(BellowingRoarTimer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_BELLOWINGROAR);
                BellowingRoarTimer = 30000;
            }else BellowingRoarTimer -= diff;
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
    newscript->GetAI = GetAI_boss_onyxiaAI;
    m_scripts[nrscripts++] = newscript;
}
