/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Boss_Gruul
SD%Complete: 60
SDComment: Ground Slam need further development (knock back effect and shatter effect must be added to the core)
SDCategory: Gruul's Lair
EndScriptData */

#include "ScriptPCH.h"
#include "gruuls_lair.h"

enum eEnums
{
    SAY_AGGRO                   = -1565010,
    SAY_SLAM1                   = -1565011,
    SAY_SLAM2                   = -1565012,
    SAY_SHATTER1                = -1565013,
    SAY_SHATTER2                = -1565014,
    SAY_SLAY1                   = -1565015,
    SAY_SLAY2                   = -1565016,
    SAY_SLAY3                   = -1565017,
    SAY_DEATH                   = -1565018,

    EMOTE_GROW                  = -1565019,

    SPELL_GROWTH                = 36300,
    SPELL_CAVE_IN               = 36240,
    SPELL_GROUND_SLAM           = 33525,                    //AoE Ground Slam applying Ground Slam to everyone with a script effect (most likely the knock back, we can code it to a set knockback)
    SPELL_REVERBERATION         = 36297,
    SPELL_SHATTER               = 33654,

    SPELL_SHATTER_EFFECT        = 33671,
    SPELL_HURTFUL_STRIKE        = 33813,
    SPELL_STONED                = 33652,                    //Spell is self cast by target

    SPELL_MAGNETIC_PULL         = 28337,
    SPELL_KNOCK_BACK            = 24199,                    //Knockback spell until correct implementation is made
};

class boss_gruul : public CreatureScript
{
public:
    boss_gruul() : CreatureScript("boss_gruul") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_gruulAI (creature);
    }

    struct boss_gruulAI : public ScriptedAI
    {
        boss_gruulAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 m_uiGrowth_Timer;
        uint32 m_uiCaveIn_Timer;
        uint32 m_uiCaveIn_StaticTimer;
        uint32 m_uiGroundSlamTimer;
        uint32 m_uiHurtfulStrike_Timer;
        uint32 m_uiReverberation_Timer;

        bool m_bPerformingGroundSlam;

        void Reset()
        {
            m_uiGrowth_Timer= 30000;
            m_uiCaveIn_Timer= 27000;
            m_uiCaveIn_StaticTimer = 30000;
            m_uiGroundSlamTimer= 35000;
            m_bPerformingGroundSlam= false;
            m_uiHurtfulStrike_Timer= 8000;
            m_uiReverberation_Timer= 60000+45000;

            if (instance)
                instance->SetData(DATA_GRUULEVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);

            if (instance)
                instance->SetData(DATA_GRUULEVENT, IN_PROGRESS);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY1, SAY_SLAY2, SAY_SLAY3), me);
        }

        void JustDied(Unit* /*Killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            if (instance)
            {
                instance->SetData(DATA_GRUULEVENT, DONE);
                instance->HandleGameObject(instance->GetData64(DATA_GRUULDOOR), true);         // Open the encounter door
            }
        }

        void SpellHitTarget(Unit* target, const SpellInfo* pSpell)
        {
            //This to emulate effect1 (77) of SPELL_GROUND_SLAM, knock back to any direction
            //It's initially wrong, since this will cause fall damage, which is by comments, not intended.
            if (pSpell->Id == SPELL_GROUND_SLAM)
            {
                if (target->GetTypeId() == TYPEID_PLAYER)
                {
                    switch (urand(0, 1))
                    {
                        case 0: target->CastSpell(target, SPELL_MAGNETIC_PULL, true, NULL, NULL, me->GetGUID()); break;
                        case 1: target->CastSpell(target, SPELL_KNOCK_BACK, true, NULL, NULL, me->GetGUID()); break;
                    }
                }
            }

            //this part should be in the core
            if (pSpell->Id == SPELL_SHATTER)
            {
                //this spell must have custom handling in the core, dealing damage based on distance
                target->CastSpell(target, SPELL_SHATTER_EFFECT, true);

                if (target->HasAura(SPELL_STONED))
                    target->RemoveAurasDueToSpell(SPELL_STONED);

                //clear this, if we are still performing
                if (m_bPerformingGroundSlam)
                {
                    m_bPerformingGroundSlam = false;

                    //and correct movement, if not already
                    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() != TARGETED_MOTION_TYPE)
                    {
                        if (me->getVictim())
                            me->GetMotionMaster()->MoveChase(me->getVictim());
                    }
                }
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            // Growth
            // Gruul can cast this spell up to 30 times
            if (m_uiGrowth_Timer <= uiDiff)
            {
                DoScriptText(EMOTE_GROW, me);
                DoCast(me, SPELL_GROWTH);
                m_uiGrowth_Timer = 30000;
            }
            else
                m_uiGrowth_Timer -= uiDiff;

            if (m_bPerformingGroundSlam)
            {
                if (m_uiGroundSlamTimer <= uiDiff)
                {
                    m_uiGroundSlamTimer =120000;
                    m_uiHurtfulStrike_Timer= 8000;

                    if (m_uiReverberation_Timer < 10000)     //Give a little time to the players to undo the damage from shatter
                        m_uiReverberation_Timer += 10000;

                    DoCast(me, SPELL_SHATTER);
                }
                else
                    m_uiGroundSlamTimer -= uiDiff;
            }
            else
            {
                // Hurtful Strike
                if (m_uiHurtfulStrike_Timer <= uiDiff)
                {
                    Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 1);

                    if (target && me->IsWithinMeleeRange(me->getVictim()))
                        DoCast(target, SPELL_HURTFUL_STRIKE);
                    else
                        DoCast(me->getVictim(), SPELL_HURTFUL_STRIKE);

                    m_uiHurtfulStrike_Timer= 8000;
                }
                else
                    m_uiHurtfulStrike_Timer -= uiDiff;

                // Reverberation
                if (m_uiReverberation_Timer <= uiDiff)
                {
                    DoCast(me->getVictim(), SPELL_REVERBERATION, true);
                    m_uiReverberation_Timer = urand(15000, 25000);
                }
                else
                    m_uiReverberation_Timer -= uiDiff;

                // Cave In
                if (m_uiCaveIn_Timer <= uiDiff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_CAVE_IN);

                    if (m_uiCaveIn_StaticTimer >= 4000)
                        m_uiCaveIn_StaticTimer -= 2000;

                        m_uiCaveIn_Timer = m_uiCaveIn_StaticTimer;
                }
                else
                    m_uiCaveIn_Timer -= uiDiff;

                // Ground Slam, Gronn Lord's Grasp, Stoned, Shatter
                if (m_uiGroundSlamTimer <= uiDiff)
                {
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveIdle();

                    m_bPerformingGroundSlam= true;
                    m_uiGroundSlamTimer = 10000;

                    DoCast(me, SPELL_GROUND_SLAM);
                }
                else
                    m_uiGroundSlamTimer -= uiDiff;

                DoMeleeAttackIfReady();
            }
        }
    };

};

void AddSC_boss_gruul()
{
    new boss_gruul();
}
