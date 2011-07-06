/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Harbinger_Skyriss
SD%Complete: 45
SDComment: CombatAI not fully implemented. Timers will need adjustments. Need more docs on how event fully work. Reset all event and force start over if fail at one point?
SDCategory: Tempest Keep, The Arcatraz
EndScriptData */

/* ContentData
boss_harbinger_skyriss
boss_harbinger_skyriss_illusion
EndContentData */

#include "ScriptPCH.h"
#include "arcatraz.h"

enum eSays
{
    SAY_INTRO              = -1552000,
    SAY_AGGRO              = -1552001,
    SAY_KILL_1             = -1552002,
    SAY_KILL_2             = -1552003,
    SAY_MIND_1             = -1552004,
    SAY_MIND_2             = -1552005,
    SAY_FEAR_1             = -1552006,
    SAY_FEAR_2             = -1552007,
    SAY_IMAGE              = -1552008,
    SAY_DEATH              = -1552009,
};

enum eSpells
{
    SPELL_FEAR             = 39415,
    SPELL_MIND_REND        = 36924,
    H_SPELL_MIND_REND      = 39017,
    SPELL_DOMINATION       = 37162,
    H_SPELL_DOMINATION     = 39019,
    H_SPELL_MANA_BURN      = 39020,
    SPELL_66_ILLUSION      = 36931,                       //entry 21466
    SPELL_33_ILLUSION      = 36932,                       //entry 21467
};

class boss_harbinger_skyriss : public CreatureScript
{
    public:

        boss_harbinger_skyriss()
            : CreatureScript("boss_harbinger_skyriss")
        {
        }
        struct boss_harbinger_skyrissAI : public ScriptedAI
        {
            boss_harbinger_skyrissAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
                Intro = false;
            }

            InstanceScript *pInstance;

            bool Intro;
            bool IsImage33;
            bool IsImage66;

            uint32 Intro_Phase;
            uint32 Intro_Timer;
            uint32 MindRend_Timer;
            uint32 Fear_Timer;
            uint32 Domination_Timer;
            uint32 ManaBurn_Timer;

            void Reset()
            {
                if (!Intro)
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);

                IsImage33 = false;
                IsImage66 = false;

                Intro_Phase = 1;
                Intro_Timer = 5000;
                MindRend_Timer = 3000;
                Fear_Timer = 15000;
                Domination_Timer = 30000;
                ManaBurn_Timer = 25000;
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (!Intro)
                    return;

                ScriptedAI::MoveInLineOfSight(who);
            }

            void EnterCombat(Unit* /*who*/) {}

            void JustDied(Unit* /*Killer*/)
            {
                DoScriptText(SAY_DEATH, me);
                if (pInstance)
                    pInstance->SetData(TYPE_HARBINGERSKYRISS, DONE);
            }

            void JustSummoned(Creature* summon)
            {
                if (!summon)
                    return;
                if (IsImage66)
                    summon->SetHealth(summon->CountPctFromMaxHealth(33));
                else
                    summon->SetHealth(summon->CountPctFromMaxHealth(66));
                if (me->getVictim())
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        summon->AI()->AttackStart(target);
            }

            void KilledUnit(Unit* victim)
            {
                //won't yell killing pet/other unit
                if (victim->GetEntry() == 21436)
                    return;

                DoScriptText(RAND(SAY_KILL_1, SAY_KILL_2), me);
            }

            void DoSplit(uint32 val)
            {
                if (me->IsNonMeleeSpellCasted(false))
                    me->InterruptNonMeleeSpells(false);

                DoScriptText(SAY_IMAGE, me);

                if (val == 66)
                    DoCast(me, SPELL_66_ILLUSION);
                else
                    DoCast(me, SPELL_33_ILLUSION);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!Intro)
                {
                    if (!pInstance)
                        return;

                    if (Intro_Timer <= diff)
                    {
                        switch(Intro_Phase)
                        {
                        case 1:
                            DoScriptText(SAY_INTRO, me);
                            pInstance->HandleGameObject(pInstance->GetData64(DATA_SPHERE_SHIELD), true);
                            ++Intro_Phase;
                            Intro_Timer = 25000;
                            break;
                        case 2:
                            DoScriptText(SAY_AGGRO, me);
                            if (Unit* mellic = Unit::GetUnit(*me, pInstance->GetData64(DATA_MELLICHAR)))
                            {
                                //should have a better way to do this. possibly spell exist.
                                mellic->setDeathState(JUST_DIED);
                                mellic->SetHealth(0);
                                pInstance->SetData(TYPE_SHIELD_OPEN, IN_PROGRESS);
                            }
                            ++Intro_Phase;
                            Intro_Timer = 3000;
                            break;
                        case 3:
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                            Intro = true;
                            break;
                        }
                    }
                    else
                        Intro_Timer -=diff;
                }
                if (!UpdateVictim())
                    return;

                if (!IsImage66 && !HealthAbovePct(66))
                {
                    DoSplit(66);
                    IsImage66 = true;
                }
                if (!IsImage33 && !HealthAbovePct(33))
                {
                    DoSplit(33);
                    IsImage33 = true;
                }

                if (MindRend_Timer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                        DoCast(target, SPELL_MIND_REND);
                    else
                        DoCast(me->getVictim(), SPELL_MIND_REND);

                    MindRend_Timer = 8000;
                }
                else
                    MindRend_Timer -=diff;

                if (Fear_Timer <= diff)
                {
                    if (me->IsNonMeleeSpellCasted(false))
                        return;

                    DoScriptText(RAND(SAY_FEAR_1, SAY_FEAR_2), me);

                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                        DoCast(target, SPELL_FEAR);
                    else
                        DoCast(me->getVictim(), SPELL_FEAR);

                    Fear_Timer = 25000;
                }
                else
                    Fear_Timer -=diff;

                if (Domination_Timer <= diff)
                {
                    if (me->IsNonMeleeSpellCasted(false))
                        return;

                    DoScriptText(RAND(SAY_MIND_1, SAY_MIND_2), me);

                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                        DoCast(target, SPELL_DOMINATION);
                    else
                        DoCast(me->getVictim(), SPELL_DOMINATION);

                    Domination_Timer = 16000+rand()%16000;
                }
                else
                    Domination_Timer -=diff;

                if (IsHeroic())
                {
                    if (ManaBurn_Timer <= diff)
                    {
                        if (me->IsNonMeleeSpellCasted(false))
                            return;

                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                            DoCast(target, H_SPELL_MANA_BURN);

                        ManaBurn_Timer = 16000+rand()%16000;
                    }
                    else
                        ManaBurn_Timer -=diff;
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_harbinger_skyrissAI (creature);
        }
};

#define SPELL_MIND_REND_IMAGE   36929
#define H_SPELL_MIND_REND_IMAGE 39021

class boss_harbinger_skyriss_illusion : public CreatureScript
{
    public:

        boss_harbinger_skyriss_illusion()
            : CreatureScript("boss_harbinger_skyriss_illusion")
        {
        }
        struct boss_harbinger_skyriss_illusionAI : public ScriptedAI
        {
            boss_harbinger_skyriss_illusionAI(Creature* creature) : ScriptedAI(creature) {}

            void Reset() { }

            void EnterCombat(Unit* /*who*/) { }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_harbinger_skyriss_illusionAI(creature);
        }
};

void AddSC_boss_harbinger_skyriss()
{
    new boss_harbinger_skyriss();
    new boss_harbinger_skyriss_illusion();
}

