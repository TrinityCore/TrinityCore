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
SDName: razorscale
SD%Complete: 65
EndScriptData */

#include "precompiled.h"
#include "ulduar.h"

//wrong text ids. correct are between -1000000 AND -1999999
//between -2000000 and -2999999 are custom texts so wtf?
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

#define SPELL_SUMMONADDS            17646

#define CREATURE_ADDS               33846

static float MovementLocations[4][3] =
{
    {607.7, -281.9, 408.6},
    {602.0, -245.5, 424.7},
    {612.3, -230.8, 409.1},
    {624.1, -251.8, 426.1}
};

static float SpawnLocations[4][3] =
{
    {602.0, -248.1, 391.2},
    {624.4, -232-4, 391.1},
    {643.3, -256.4, 391.4},
    {626.6, -271.5, 391.4},
};

struct TRINITY_DLL_DECL boss_razorscaleAI : public BossAI
{
    boss_razorscaleAI(Creature *pCreature) : BossAI(pCreature, TYPE_RAZORSCALE) {}

    uint32 Phase;

    uint32 FlameBreathTimer;
    uint32 FUSEARMORTimer;
    uint32 DEVOURINGFLAMETimer;
    uint32 MovementTimer;
    uint32 SummonAddsTimer;
    uint32 WingBuffetTimer;
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
        WingBuffetTimer = 17000;
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

        if(m_creature->GetPositionY() > -60 || m_creature->GetPositionX() < 450) // Not Blizzlike, anti-exploit to prevent players from pulling bosses to vehicles.
        {
            m_creature->RemoveAllAuras();
            m_creature->DeleteThreatList();
            m_creature->CombatStop(false);
            m_creature->GetMotionMaster()->MoveTargetedHome();
        }

        if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 99 && Phase == 1)
        {
            Phase = 2;
            m_creature->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            m_creature->SetHover(true);
            m_creature->GetMotionMaster()->Clear(false);
            m_creature->GetMotionMaster()->MoveIdle();
            DoScriptText(SAY_PHASE_2_TRANS, m_creature);
        }

        if ((m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 50 && Phase == 2)
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
            if (FlameBreathTimer <= diff)
            {
                DoCastVictim(SPELL_FLAMEBREATH);
                FlameBreathTimer = 15000;
            } else FlameBreathTimer -= diff;

            if (DEVOURINGFLAMETimer <= diff)
            {
                std::list<Unit*> pTargets;
                SelectTargetList(pTargets, 10, SELECT_TARGET_RANDOM, 100, true);
                for (std::list<Unit*>::iterator i = pTargets.begin(); i != pTargets.end(); ++i)
                    if (!m_creature->HasInArc(M_PI, *i))
                    {
                        DoCast(*i, SPELL_DEVOURINGFLAME);
                        break;
                    }

                DEVOURINGFLAMETimer = 10000;
            } else DEVOURINGFLAMETimer -= diff;

            if (FUSEARMORTimer <= diff)
            {
                DoCastVictim(SPELL_FUSEARMOR);
                FUSEARMORTimer = 10000;
            } else FUSEARMORTimer -= diff;

            if (WingBuffetTimer <= diff)
            {
                DoCast(SPELL_WINGBUFFET);
                WingBuffetTimer = urand(7000,14000);
            } else WingBuffetTimer -= diff;

            DoMeleeAttackIfReady();
        }

        if (Phase == 2)
        {
            if (InitialSpawn)
                SummonAdds();

            InitialSpawn = false;

            if (FireballTimer <= diff)
            {
                std::list<Unit*> pTargets;
                SelectTargetList(pTargets, 10, SELECT_TARGET_RANDOM, 100, true);
                for (std::list<Unit*>::iterator i = pTargets.begin(); i != pTargets.end(); ++i)
                    if (!m_creature->HasInArc(M_PI, *i))
                    {
                        DoCast(*i, SPELL_FIREBALL);
                        break;
                    }

                FireballTimer = 18000;
            } else FireballTimer -= diff;

            if (MovementTimer <= diff)
            {
                if (urand(0,99) < 30)
                {
                    DoScriptText(EMOTE_BREATH, m_creature);
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(pTarget, SPELL_FLAMEBUFFET);
                }
                else ChangePosition();

                MovementTimer = 25000;
            } else MovementTimer -= diff;

            if (SummonAddsTimer <= diff)
                SummonAdds();
            else SummonAddsTimer -= diff;
        }
    }

    void ChangePosition()
    {
        /* Malfunctioning, Razorscale is flying around randomly, attacking players from hundreds of yards away.
        uint8 random = urand(0,3);
        m_creature->GetMotionMaster()->MovePoint(0, MovementLocations[random][0], MovementLocations[random][1], MovementLocations[random][2]); */
    }

    void SummonAdds()
    {
        for (uint32 i = 0; i < 4; ++i)
        {
            uint8 random = urand(0,3);
            if (Creature *pAdd = m_creature->SummonCreature(CREATURE_ADDS, SpawnLocations[random][0], SpawnLocations[random][1], SpawnLocations[random][2], 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30000))
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 200, true))
                    pAdd->AI()->AttackStart(pTarget);
        }
        SummonAddsTimer = 45000;
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
    newscript->Name = "boss_razorscale";
    newscript->GetAI = &GetAI_boss_razorscale;
    newscript->RegisterSelf();
}
