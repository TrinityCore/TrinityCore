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
SDName: Generic_Creature
SD%Complete: 80
SDComment: Should be replaced with core based AI
SDCategory: Creatures
EndScriptData */

#include "precompiled.h"

#define GENERIC_CREATURE_COOLDOWN   5000

struct TRINITY_DLL_DECL generic_creatureAI : public ScriptedAI
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
        if (!m_creature->IsWithinMeleeRange(who))
        {
            IsSelfRooted = true;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Always decrease our global cooldown first
        if (GlobalCooldown > diff)
            GlobalCooldown -= diff;
        else GlobalCooldown = 0;

        //Buff timer (only buff when we are alive and not in combat
        if (!m_creature->isInCombat() && m_creature->isAlive())
            if (BuffTimer < diff )
            {
                //Find a spell that targets friendly and applies an aura (these are generally buffs)
                SpellEntry const *info = SelectSpell(m_creature, -1, -1, SELECT_TARGET_ANY_FRIEND, 0, 0, 0, 0, SELECT_EFFECT_AURA);

                if (info && !GlobalCooldown)
                {
                    //Cast the buff spell
                    DoCastSpell(m_creature, info);

                    //Set our global cooldown
                    GlobalCooldown = GENERIC_CREATURE_COOLDOWN;

                    //Set our timer to 10 minutes before rebuff
                    BuffTimer = 600000;
                }//Try agian in 30 seconds
                else BuffTimer = 30000;
            }else BuffTimer -= diff;

        //Return since we have no target
        if (!UpdateVictim() )
            return;

        //If we are within range melee the target
        if( m_creature->IsWithinMeleeRange(m_creature->getVictim()))
        {
            //Make sure our attack is ready and we arn't currently casting
            if( m_creature->isAttackReady() && !m_creature->IsNonMeleeSpellCasted(false))
            {
                bool Healing = false;
                SpellEntry const *info = NULL;

                //Select a healing spell if less than 30% hp
                if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 30)
                    info = SelectSpell(m_creature, -1, -1, SELECT_TARGET_ANY_FRIEND, 0, 0, 0, 0, SELECT_EFFECT_HEALING);

                //No healing spell available, select a hostile spell
                if (info) Healing = true;
                else info = SelectSpell(m_creature->getVictim(), -1, -1, SELECT_TARGET_ANY_ENEMY, 0, 0, 0, 0, SELECT_EFFECT_DONTCARE);

                //50% chance if elite or higher, 20% chance if not, to replace our white hit with a spell
                if (info && (rand() % (m_creature->GetCreatureInfo()->rank > 1 ? 2 : 5) == 0) && !GlobalCooldown)
                {
                    //Cast the spell
                    if (Healing)DoCastSpell(m_creature, info);
                    else DoCastSpell(m_creature->getVictim(), info);

                    //Set our global cooldown
                    GlobalCooldown = GENERIC_CREATURE_COOLDOWN;
                }
                else m_creature->AttackerStateUpdate(m_creature->getVictim());

                m_creature->resetAttackTimer();
            }
        }
        else
        {
            //Only run this code if we arn't already casting
            if (!m_creature->IsNonMeleeSpellCasted(false))
            {
                bool Healing = false;
                SpellEntry const *info = NULL;

                //Select a healing spell if less than 30% hp ONLY 33% of the time
                if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 30 && rand() % 3 == 0)
                    info = SelectSpell(m_creature, -1, -1, SELECT_TARGET_ANY_FRIEND, 0, 0, 0, 0, SELECT_EFFECT_HEALING);

                //No healing spell available, See if we can cast a ranged spell (Range must be greater than ATTACK_DISTANCE)
                if (info) Healing = true;
                else info = SelectSpell(m_creature->getVictim(), -1, -1, SELECT_TARGET_ANY_ENEMY, 0, 0, NOMINAL_MELEE_RANGE, 0, SELECT_EFFECT_DONTCARE);

                //Found a spell, check if we arn't on cooldown
                if (info && !GlobalCooldown)
                {
                    //If we are currently moving stop us and set the movement generator
                    if (!IsSelfRooted)
                    {
                        IsSelfRooted = true;
                    }

                    //Cast spell
                    if (Healing) DoCastSpell(m_creature,info);
                    else DoCastSpell(m_creature->getVictim(),info);

                    //Set our global cooldown
                    GlobalCooldown = GENERIC_CREATURE_COOLDOWN;


                }//If no spells available and we arn't moving run to target
                else if (IsSelfRooted)
                {
                    //Cancel our current spell and then allow movement agian
                    m_creature->InterruptNonMeleeSpells(false);
                    IsSelfRooted = false;
                }
            }
        }
    }
};

CreatureAI* GetAI_generic_creature(Creature *_Creature)
{
    return new generic_creatureAI (_Creature);
}

struct TRINITY_DLL_DECL trigger_periodicAI : public NullCreatureAI
{
    trigger_periodicAI(Creature* c) : NullCreatureAI(c)
    {
        if(me->m_spells[0])
        {
            if(me->m_spells[1])
                spell = GetSpellStore()->LookupEntry(HEROIC(me->m_spells[0], me->m_spells[1]));
            else
                spell = GetSpellStore()->LookupEntry(me->m_spells[0]);
        }
        else
            spell = NULL;

        if(me->m_spells[2])
        {
            if(me->m_spells[3])
                interval = HEROIC(me->m_spells[2], me->m_spells[3]);
            else
                interval = me->m_spells[2];
        }
        else
            interval = 1000;
        timer = interval;
    }

    uint32 timer, interval;
    const SpellEntry * spell;

    void UpdateAI(const uint32 diff)
    {
        if(timer < diff)
        {
            if(spell)
                me->CastSpell(me, spell, true);
            timer = interval;
        }
        else
            timer -= diff;
    }
};

CreatureAI* GetAI_trigger_periodic(Creature *_Creature)
{
    return new trigger_periodicAI (_Creature);
}

void AddSC_generic_creature()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="generic_creature";
    newscript->GetAI = &GetAI_generic_creature;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="trigger_periodic";
    newscript->GetAI = &GetAI_trigger_periodic;
    newscript->RegisterSelf();
}

