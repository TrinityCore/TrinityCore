/*
 * Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
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

/* ScriptData
Name: razorscale
%Complete: 90
Comment: Made by Epsik from WoW Arthas wow.dsl.net.pk
Category:
EndScriptData */

#include "precompiled.h"
#include "def_ulduar.h"

#define SAY_AGGRO                   -2000000
#define SAY_KILL                    -2000001
#define SAY_PHASE_2_TRANS           -2000002
#define SAY_PHASE_3_TRANS           -2000003
#define EMOTE_BREATH                -2000004

#define SPELL_FLAMEBUFFET           64016
#define SPELL_FIREBALL              62796

#define SPELL_WINGBUFFET            62666
#define SPELL_FLAMEBREATH           63317
#define SPELL_FUSEARMOR             64771
#define SPELL_DEVOURINGFLAME        63014
#define SPELL_KNOCK_AWAY            19633

#define SPELL_BELLOWINGROAR         18431
#define SPELL_HEATED_GROUND         22191

#define SPELL_SUMMONADDS            17646

#define CREATURE_ADDS               33846

static float MovementLocations[4][3]=
{
    {607.7, -281.9, 408.6},
    {602.0, -245.5, 424.7},
    {612.3, -230.8, 409.1},
    {624.1, -251.8, 426.1}
};

static float SpawnLocations[4][3]=
{
    {602.0, -248.1, 391.2},
    {624.4, -232-4, 391.1},
    {643.3, -256.4, 391.4},
    {626.6, -271.5, 391.4},
};

struct TRINITY_DLL_DECL boss_razorscaleAI : public ScriptedAI
{
    boss_razorscaleAI(Creature* c) : ScriptedAI(c) {}

    uint32 Phase;

    uint32 FlameBreathTimer;
    uint32 FUSEARMORTimer;
    uint32 DEVOURINGFLAMETimer;
    uint32 MovementTimer;
    uint32 SummonAddsTimer;
    uint32 BellowingRoarTimer;
    uint32 WingBuffetTimer;
    uint32 KnockAwayTimer;
    uint32 FireballTimer;

    bool InitialSpawn;

    void Reset()
    {
        Phase = 1;

        FlameBreathTimer = 20000;
        DEVOURINGFLAMETimer = 2000;
        FUSEARMORTimer = 15000;
        MovementTimer = 3000;
        SummonAddsTimer = 45000;
        BellowingRoarTimer = 30000;
        WingBuffetTimer = 17000;
        KnockAwayTimer = 15000;
        FireballTimer = 18000;

        InitialSpawn = true;

        m_creature->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
        m_creature->ApplySpellImmune(1, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, true);
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

        if (((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 99) && (Phase == 1))
        {
            Phase = 2;
            m_creature->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            m_creature->SetHover(true);
            m_creature->GetMotionMaster()->Clear(false);
            m_creature->GetMotionMaster()->MoveIdle();
            DoScriptText(SAY_PHASE_2_TRANS, m_creature);
        }

        if (((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 50) && (Phase == 2))
        {
            Phase = 3;
            m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            m_creature->SetHover(false);
            m_creature->GetMotionMaster()->MovePoint(0, 619.6, -261.1, 391.471832);
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
            } else FlameBreathTimer -= diff;

            if (DEVOURINGFLAMETimer < diff)
            {
                Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 1);
                if (target && !m_creature->HasInArc(M_PI, target))
                    DoCast(target, SPELL_DEVOURINGFLAME);

                DEVOURINGFLAMETimer = 10000;
            } else DEVOURINGFLAMETimer -= diff;

            if (FUSEARMORTimer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_FUSEARMOR);
                FUSEARMORTimer = 10000;
            } else FUSEARMORTimer -= diff;

            if (WingBuffetTimer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_WINGBUFFET);
                WingBuffetTimer = 7000 + ((rand()%8)*1000);
            } else WingBuffetTimer -= diff;

            if (KnockAwayTimer < diff)
            {
                if (rand()%100 <= 30)
                {
                    DoCast(m_creature->getVictim(), SPELL_KNOCK_AWAY);
                }
                KnockAwayTimer = 15000;
            } else KnockAwayTimer -= diff;

            if (Phase == 3)
            {
                if (BellowingRoarTimer < diff)
                {
                    DoCast(m_creature->getVictim(), SPELL_BELLOWINGROAR);

                    BellowingRoarTimer = 30000;
                } else BellowingRoarTimer -= diff;

                if (SummonAddsTimer < diff)
                {
                    SummonAdds(Phase);

                    SummonAddsTimer = 45000;
                } else SummonAddsTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }

        if (Phase == 2)
        {
            if (InitialSpawn)
            {
                InitialSpawn = false;

                for(uint32 i = 0; i < 4; ++i)
                {
                    uint32 random = rand()%4;
                    Creature* Add = m_creature->SummonCreature(CREATURE_ADDS, SpawnLocations[random][0], SpawnLocations[random][1], SpawnLocations[random][2], 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30000);
                    if (Add)
                        Add->AI()->AttackStart(SelectUnit(SELECT_TARGET_RANDOM, 0));
                }
            }


            if (FireballTimer < diff)
            {
                DoCast(SelectUnit(SELECT_TARGET_RANDOM, 0), SPELL_FIREBALL);

                FireballTimer = 18000;
            } else FireballTimer -= diff;

            if (MovementTimer < diff)
            {
                if (rand()%100 <= 30)
                {
                    DoScriptText(EMOTE_BREATH, m_creature);
                    DoCast(m_creature->getVictim(), SPELL_FLAMEBUFFET);
                }
                else ChangePosition();

                MovementTimer = 25000;
            } else MovementTimer -= diff;

            if (SummonAddsTimer < diff)
            {
                SummonAdds(Phase);

                SummonAddsTimer = 45000;
            } else SummonAddsTimer -= diff;
        }
    }

    void ChangePosition()
    {
        /* Malfunctioning, Razorscale is flying around randomly, attacking players from hundreds of yards away.
        uint32 random = rand() % 4;
        if (random<4){
            m_creature->GetMotionMaster()->MovePoint(0, MovementLocations[random][0], MovementLocations[random][1], MovementLocations[random][2]);} */
    }

    void SummonAdds(uint32 Phase)
    {
        if (Phase == 2)
        {
            uint32 max = rand()%10;
            for(uint32 i = 0; i < 4; ++i)
            {
                uint32 random = rand()%3;
                Creature* Add = m_creature->SummonCreature(CREATURE_ADDS, SpawnLocations[random][0], SpawnLocations[random][1], SpawnLocations[random][2], 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30000);
                if (Add)
                    Add->AI()->AttackStart(SelectUnit(SELECT_TARGET_RANDOM, 0));
            }
        }

        if (Phase == 3)
        {
            uint32 max = rand() % 10 +1;
            if (max < 1)
            {
                for(uint32 i = 0; i < max; ++i)
                {
                    uint32 random = rand()%4;
                    Creature* Add = m_creature->SummonCreature(CREATURE_ADDS, SpawnLocations[random][0], SpawnLocations[random][1], SpawnLocations[random][2], 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30000);
                    if (Add)
                        Add->AI()->AttackStart(SelectUnit(SELECT_TARGET_RANDOM, 0));
                }
            }
        }
    }
};

CreatureAI* GetAI_boss_razorscale(Creature* pCreature)
{
    return new boss_razorscaleAI (pCreature);
}

void AddSC_boss_razorscale()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_razorscale";
    newscript->GetAI = &GetAI_boss_razorscale;
    newscript->RegisterSelf();
}
