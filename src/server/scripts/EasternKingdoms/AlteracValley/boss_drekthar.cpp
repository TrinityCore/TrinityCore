/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"

enum Spells
{
    SPELL_WHIRLWIND                               = 15589,
    SPELL_WHIRLWIND2                              = 13736,
    SPELL_KNOCKDOWN                               = 19128,
    SPELL_FRENZY                                  = 8269,
    SPELL_SWEEPING_STRIKES                        = 18765, // not sure
    SPELL_CLEAVE                                  = 20677, // not sure
    SPELL_WINDFURY                                = 35886, // not sure
    SPELL_STORMPIKE                               = 51876  // not sure
};

enum Yells
{
    YELL_AGGRO                                    = -1810000,
    YELL_EVADE                                    = -1810001,
    YELL_RESPAWN                                  = -1810002,
    YELL_RANDOM1                                  = -1810003,
    YELL_RANDOM2                                  = -1810004,
    YELL_RANDOM3                                  = -1810005,
    YELL_RANDOM4                                  = -1810006,
    YELL_RANDOM5                                  = -1810007
};

class boss_drekthar : public CreatureScript
{
public:
    boss_drekthar() : CreatureScript("boss_drekthar") { }

    struct boss_drektharAI : public ScriptedAI
    {
        boss_drektharAI(Creature *c) : ScriptedAI(c) {}

        uint32 uiWhirlwindTimer;
        uint32 uiWhirlwind2Timer;
        uint32 uiKnockdownTimer;
        uint32 uiFrenzyTimer;
        uint32 uiYellTimer;
        uint32 uiResetTimer;

        void Reset()
        {
            uiWhirlwindTimer = urand(1*IN_MILLISECONDS,20*IN_MILLISECONDS);
            uiWhirlwind2Timer = urand(1*IN_MILLISECONDS,20*IN_MILLISECONDS);
            uiKnockdownTimer = 12*IN_MILLISECONDS;
            uiFrenzyTimer = 6*IN_MILLISECONDS;
            uiResetTimer = 5*IN_MILLISECONDS;
            uiYellTimer = urand(20*IN_MILLISECONDS,30*IN_MILLISECONDS); //20 to 30 seconds
        }

        void EnterCombat(Unit * /*who*/)
        {
            DoScriptText(YELL_AGGRO, me);
        }

        void JustRespawned()
        {
            Reset();
            DoScriptText(YELL_RESPAWN, me);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiWhirlwindTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_WHIRLWIND);
                uiWhirlwindTimer =  urand(8*IN_MILLISECONDS,18*IN_MILLISECONDS);
            } else uiWhirlwindTimer -= diff;

            if (uiWhirlwind2Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_WHIRLWIND2);
                uiWhirlwind2Timer = urand(7*IN_MILLISECONDS,25*IN_MILLISECONDS);
            } else uiWhirlwind2Timer -= diff;

            if (uiKnockdownTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_KNOCKDOWN);
                uiKnockdownTimer = urand(10*IN_MILLISECONDS,15*IN_MILLISECONDS);
            } else uiKnockdownTimer -= diff;

            if (uiFrenzyTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FRENZY);
                uiFrenzyTimer = urand(20*IN_MILLISECONDS,30*IN_MILLISECONDS);
            } else uiFrenzyTimer -= diff;

            if (uiYellTimer <= diff)
            {
                DoScriptText(RAND(YELL_RANDOM1,YELL_RANDOM2,YELL_RANDOM3,YELL_RANDOM4,YELL_RANDOM5), me);
                uiYellTimer = urand(20*IN_MILLISECONDS,30*IN_MILLISECONDS); //20 to 30 seconds
            } else uiYellTimer -= diff;

            // check if creature is not outside of building
            if (uiResetTimer <= diff)
            {
                if (me->GetDistance2d(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY()) > 50)
                {
                    EnterEvadeMode();
                    DoScriptText(YELL_EVADE, me);
                }
                uiResetTimer = 5*IN_MILLISECONDS;
            } else uiResetTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };


    CreatureAI *GetAI(Creature *creature) const
    {
        return new boss_drektharAI(creature);
    }
};

void AddSC_boss_drekthar()
{
    new boss_drekthar;
}