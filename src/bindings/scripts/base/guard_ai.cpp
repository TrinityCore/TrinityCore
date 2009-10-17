/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>.sourceforge.net/>
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
SDName: Guard_AI
SD%Complete: 90
SDComment:
SDCategory: Guards
EndScriptData */
#include "precompiled.h"
#include "guard_ai.h"
// **** This script is for use within every single guard to save coding time ****
#define GENERIC_CREATURE_COOLDOWN 5000
#define SAY_GUARD_SIL_AGGRO1        -1070001
#define SAY_GUARD_SIL_AGGRO2        -1070002
#define SAY_GUARD_SIL_AGGRO3        -1070003
guardAI::guardAI(Creature* pCreature) : ScriptedAI(pCreature),
    GlobalCooldown(0),
    BuffTimer(0)
{}
void guardAI::Reset()
{
    GlobalCooldown = 0;
    BuffTimer = 0;                                          //Rebuff as soon as we can
}
void guardAI::EnterCombat(Unit *who)
{
    if (m_creature->GetEntry() == 15184)
        DoScriptText(RAND(SAY_GUARD_SIL_AGGRO1,SAY_GUARD_SIL_AGGRO2,SAY_GUARD_SIL_AGGRO3), m_creature, who);
    if (SpellEntry const *spell = m_creature->reachWithSpellAttack(who))
        DoCastSpell(who, spell);
}
void guardAI::JustDied(Unit *Killer)
{
    //Send Zone Under Attack message to the LocalDefense and WorldDefense Channels
    if (Player* pKiller = Killer->GetCharmerOrOwnerPlayerOrPlayerItself())
        m_creature->SendZoneUnderAttackMessage(pKiller);
}
void guardAI::UpdateAI(const uint32 diff)
{
    //Always decrease our global cooldown first
    if (GlobalCooldown > diff)
        GlobalCooldown -= diff;
    else GlobalCooldown = 0;
    //Buff timer (only buff when we are alive and not in combat
    if (m_creature->isAlive() && !m_creature->isInCombat())
        if (BuffTimer < diff)
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
        }                                                   //Try agian in 30 seconds
        else BuffTimer = 30000;
    }else BuffTimer -= diff;
    //Return since we have no target
    if (!UpdateVictim())
        return;
    // Make sure our attack is ready and we arn't currently casting
    if (m_creature->isAttackReady() && !m_creature->IsNonMeleeSpellCasted(false))
    {
        //If we are within range melee the target
        if (m_creature->IsWithinMeleeRange(m_creature->getVictim()))
        {
            bool Healing = false;
            SpellEntry const *info = NULL;
            //Select a healing spell if less than 30% hp
            if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() < 30)
                info = SelectSpell(m_creature, -1, -1, SELECT_TARGET_ANY_FRIEND, 0, 0, 0, 0, SELECT_EFFECT_HEALING);
            //No healing spell available, select a hostile spell
            if (info) Healing = true;
            else info = SelectSpell(m_creature->getVictim(), -1, -1, SELECT_TARGET_ANY_ENEMY, 0, 0, 0, 0, SELECT_EFFECT_DONTCARE);
            //20% chance to replace our white hit with a spell
            if (info && rand() % 5 == 0 && !GlobalCooldown)
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
                if ((*m_creature).GetMotionMaster()->GetCurrentMovementGeneratorType()!=IDLE_MOTION_TYPE)
                {
                    (*m_creature).GetMotionMaster()->Clear(false);
                    (*m_creature).GetMotionMaster()->MoveIdle();
                }
                //Cast spell
                if (Healing) DoCastSpell(m_creature,info);
                else DoCastSpell(m_creature->getVictim(),info);
                //Set our global cooldown
                GlobalCooldown = GENERIC_CREATURE_COOLDOWN;
            }                                               //If no spells available and we arn't moving run to target
            else if ((*m_creature).GetMotionMaster()->GetCurrentMovementGeneratorType()!=TARGETED_MOTION_TYPE)
            {
                //Cancel our current spell and then mutate new movement generator
                m_creature->InterruptNonMeleeSpells(false);
                (*m_creature).GetMotionMaster()->Clear(false);
                (*m_creature).GetMotionMaster()->MoveChase(m_creature->getVictim());
            }
        }
    }
}
void guardAI::DoReplyToTextEmote(uint32 em)
{
    switch(em)
    {
        case TEXTEMOTE_KISS:    m_creature->HandleEmoteCommand(EMOTE_ONESHOT_BOW);    break;
        case TEXTEMOTE_WAVE:    m_creature->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);   break;
        case TEXTEMOTE_SALUTE:  m_creature->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE); break;
        case TEXTEMOTE_SHY:     m_creature->HandleEmoteCommand(EMOTE_ONESHOT_FLEX);   break;
        case TEXTEMOTE_RUDE:
        case TEXTEMOTE_CHICKEN: m_creature->HandleEmoteCommand(EMOTE_ONESHOT_POINT);  break;
    }
}
void guardAI_orgrimmar::ReceiveEmote(Player* pPlayer, uint32 text_emote)
{
    if (pPlayer->GetTeam()==HORDE)
        DoReplyToTextEmote(text_emote);
}
void guardAI_stormwind::ReceiveEmote(Player* pPlayer, uint32 text_emote)
{
    if (pPlayer->GetTeam() == ALLIANCE)
        DoReplyToTextEmote(text_emote);
}
