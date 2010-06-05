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

#include "ScriptedPch.h"
#include "ScriptedGuardAI.h"

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
    if (me->GetEntry() == 15184)
        DoScriptText(RAND(SAY_GUARD_SIL_AGGRO1,SAY_GUARD_SIL_AGGRO2,SAY_GUARD_SIL_AGGRO3), me, who);

    if (SpellEntry const *spell = me->reachWithSpellAttack(who))
        DoCastSpell(who, spell);
}

void guardAI::JustDied(Unit *Killer)
{
    //Send Zone Under Attack message to the LocalDefense and WorldDefense Channels
    if (Player* pKiller = Killer->GetCharmerOrOwnerPlayerOrPlayerItself())
        me->SendZoneUnderAttackMessage(pKiller);
}

void guardAI::UpdateAI(const uint32 diff)
{
    //Always decrease our global cooldown first
    if (GlobalCooldown > diff)
        GlobalCooldown -= diff;
    else GlobalCooldown = 0;

    //Buff timer (only buff when we are alive and not in combat
    if (me->isAlive() && !me->isInCombat())
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
            }                                                   //Try again in 30 seconds
            else BuffTimer = 30000;
        } else BuffTimer -= diff;

    //Return since we have no target
    if (!UpdateVictim())
        return;

    // Make sure our attack is ready and we arn't currently casting
    if (me->isAttackReady() && !me->IsNonMeleeSpellCasted(false))
    {
        //If we are within range melee the target
        if (me->IsWithinMeleeRange(me->getVictim()))
        {
            bool Healing = false;
            SpellEntry const *info = NULL;

            //Select a healing spell if less than 30% hp
            if (me->GetHealth()*100 / me->GetMaxHealth() < 30)
                info = SelectSpell(me, 0, 0, SELECT_TARGET_ANY_FRIEND, 0, 0, 0, 0, SELECT_EFFECT_HEALING);

            //No healing spell available, select a hostile spell
            if (info) Healing = true;
            else info = SelectSpell(me->getVictim(), 0, 0, SELECT_TARGET_ANY_ENEMY, 0, 0, 0, 0, SELECT_EFFECT_DONTCARE);

            //20% chance to replace our white hit with a spell
            if (info && rand() % 5 == 0 && !GlobalCooldown)
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
                if ((*me).GetMotionMaster()->GetCurrentMovementGeneratorType() != IDLE_MOTION_TYPE)
                {
                    (*me).GetMotionMaster()->Clear(false);
                    (*me).GetMotionMaster()->MoveIdle();
                }

                //Cast spell
                if (Healing) DoCastSpell(me,info);
                else DoCastSpell(me->getVictim(),info);

                //Set our global cooldown
                GlobalCooldown = GENERIC_CREATURE_COOLDOWN;

            }                                               //If no spells available and we arn't moving run to target
            else if ((*me).GetMotionMaster()->GetCurrentMovementGeneratorType() != TARGETED_MOTION_TYPE)
            {
                //Cancel our current spell and then mutate new movement generator
                me->InterruptNonMeleeSpells(false);
                (*me).GetMotionMaster()->Clear(false);
                (*me).GetMotionMaster()->MoveChase(me->getVictim());
            }
        }
    }
}

void guardAI::DoReplyToTextEmote(uint32 em)
{
    switch(em)
    {
        case TEXTEMOTE_KISS:    me->HandleEmoteCommand(EMOTE_ONESHOT_BOW);    break;
        case TEXTEMOTE_WAVE:    me->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);   break;
        case TEXTEMOTE_SALUTE:  me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE); break;
        case TEXTEMOTE_SHY:     me->HandleEmoteCommand(EMOTE_ONESHOT_FLEX);   break;
        case TEXTEMOTE_RUDE:
        case TEXTEMOTE_CHICKEN: me->HandleEmoteCommand(EMOTE_ONESHOT_POINT);  break;
    }
}

void guardAI_orgrimmar::ReceiveEmote(Player* pPlayer, uint32 text_emote)
{
    if (pPlayer->GetTeam() == HORDE)
        DoReplyToTextEmote(text_emote);
}

void guardAI_stormwind::ReceiveEmote(Player* pPlayer, uint32 text_emote)
{
    if (pPlayer->GetTeam() == ALLIANCE)
        DoReplyToTextEmote(text_emote);
}
