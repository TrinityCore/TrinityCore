/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
SDName: Generic_Creature
SD%Complete: 80
SDComment: Should be replaced with core based AI
SDCategory: Creatures
EndScriptData */

#include "ScriptPCH.h"

#define GENERIC_CREATURE_COOLDOWN   5000

class generic_creature : public CreatureScript
{
public:
    generic_creature() : CreatureScript("generic_creature") { }

    struct generic_creatureAI : public ScriptedAI
    {
        generic_creatureAI(Creature *c) : ScriptedAI(c) {}

        uint32 GlobalCooldown;      //This variable acts like the global cooldown that players have (1.5 seconds)
        uint32 BuffTimer;           //This variable keeps track of buffs
        bool IsSelfRooted;

        void Reset()
        {
            GlobalCooldown = 0;
            BuffTimer = 0;          //Rebuff as soon as we can
            IsSelfRooted = false;
        }

        void EnterCombat(Unit *who)
        {
            if (!me->IsWithinMeleeRange(who))
                IsSelfRooted = true;
        }

        void UpdateAI(const uint32 diff)
        {
            //Always decrease our global cooldown first
            if (GlobalCooldown > diff)
                GlobalCooldown -= diff;
            else GlobalCooldown = 0;

            //Buff timer (only buff when we are alive and not in combat
            if (!me->isInCombat() && me->isAlive())
            {
                if (BuffTimer <= diff)
                {
                    //Find a spell that targets friendly and applies an aura (these are generally buffs)
                    SpellEntry const *info = SelectSpell(me, 0, 0, SELECT_TARGET_ANY_FRIEND, 0, 0, 0, 0, SELECT_EFFECT_AURA);

                    if (info && !GlobalCooldown)
                    {
                        //Cast the buff spell
                        DoCastSpell(me, info);

                        //Set our global cooldown
                        GlobalCooldown = GENERIC_CREATURE_COOLDOWN;

                        //Set our timer to 10 minutes before rebuff
                        BuffTimer = 600000;
                    }//Try agian in 30 seconds
                    else BuffTimer = 30000;
                } else BuffTimer -= diff;
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            //If we are within range melee the target
            if (me->IsWithinMeleeRange(me->getVictim()))
            {
                //Make sure our attack is ready and we arn't currently casting
                if (me->isAttackReady() && !me->IsNonMeleeSpellCasted(false))
                {
                    bool Healing = false;
                    SpellEntry const *info = NULL;

                    //Select a healing spell if less than 30% hp
                    if (me->GetHealth()*100 / me->GetMaxHealth() < 30)
                        info = SelectSpell(me, 0, 0, SELECT_TARGET_ANY_FRIEND, 0, 0, 0, 0, SELECT_EFFECT_HEALING);

                    //No healing spell available, select a hostile spell
                    if (info) Healing = true;
                    else info = SelectSpell(me->getVictim(), 0, 0, SELECT_TARGET_ANY_ENEMY, 0, 0, 0, 0, SELECT_EFFECT_DONTCARE);

                    //50% chance if elite or higher, 20% chance if not, to replace our white hit with a spell
                    if (info && (rand() % (me->GetCreatureInfo()->rank > 1 ? 2 : 5) == 0) && !GlobalCooldown)
                    {
                        //Cast the spell
                        if (Healing)DoCastSpell(me, info);
                        else DoCastSpell(me->getVictim(), info);

                        //Set our global cooldown
                        GlobalCooldown = GENERIC_CREATURE_COOLDOWN;
                    }
                    else me->AttackerStateUpdate(me->getVictim());

                    me->resetAttackTimer();
                }
            }
            else
            {
                //Only run this code if we arn't already casting
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    bool Healing = false;
                    SpellEntry const *info = NULL;

                    //Select a healing spell if less than 30% hp ONLY 33% of the time
                    if (me->GetHealth()*100 / me->GetMaxHealth() < 30 && rand() % 3 == 0)
                        info = SelectSpell(me, 0, 0, SELECT_TARGET_ANY_FRIEND, 0, 0, 0, 0, SELECT_EFFECT_HEALING);

                    //No healing spell available, See if we can cast a ranged spell (Range must be greater than ATTACK_DISTANCE)
                    if (info) Healing = true;
                    else info = SelectSpell(me->getVictim(), 0, 0, SELECT_TARGET_ANY_ENEMY, 0, 0, NOMINAL_MELEE_RANGE, 0, SELECT_EFFECT_DONTCARE);

                    //Found a spell, check if we arn't on cooldown
                    if (info && !GlobalCooldown)
                    {
                        //If we are currently moving stop us and set the movement generator
                        if (!IsSelfRooted)
                            IsSelfRooted = true;

                        //Cast spell
                        if (Healing) DoCastSpell(me,info);
                        else DoCastSpell(me->getVictim(),info);

                        //Set our global cooldown
                        GlobalCooldown = GENERIC_CREATURE_COOLDOWN;

                    }//If no spells available and we arn't moving run to target
                    else if (IsSelfRooted)
                    {
                        //Cancel our current spell and then allow movement agian
                        me->InterruptNonMeleeSpells(false);
                        IsSelfRooted = false;
                    }
                }
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new generic_creatureAI(creature);
    }
};

class trigger_periodic : public CreatureScript
{
public:
    trigger_periodic() : CreatureScript("trigger_periodic") { }

    struct trigger_periodicAI : public NullCreatureAI
    {
        trigger_periodicAI(Creature* c) : NullCreatureAI(c)
        {
            spell = me->m_spells[0] ? GetSpellStore()->LookupEntry(me->m_spells[0]) : NULL;
            interval = me->GetAttackTime(BASE_ATTACK);
            timer = interval;
        }

        uint32 timer, interval;
        const SpellEntry * spell;

        void UpdateAI(const uint32 diff)
        {
            if (timer <= diff)
            {
                if (spell)
                    me->CastSpell(me, spell, true);
                timer = interval;
            }
            else
                timer -= diff;
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new trigger_periodicAI(creature);
    }
};

class trigger_death : public CreatureScript
{
public:
    trigger_death() : CreatureScript("trigger_death") { }

    struct trigger_deathAI : public NullCreatureAI
    {
        trigger_deathAI(Creature* c) : NullCreatureAI(c) {}
        void JustDied(Unit *killer)
        {
            if (me->m_spells[0])
                me->CastSpell(killer, me->m_spells[0], true);
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new trigger_deathAI(creature);
    }
};

void AddSC_generic_creature()
{
    //new generic_creature;
    new trigger_periodic;
    //new trigger_death;
}
