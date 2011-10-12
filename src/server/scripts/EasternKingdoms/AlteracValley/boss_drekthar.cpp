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
        boss_drektharAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 WhirlwindTimer;
        uint32 Whirlwind2Timer;
        uint32 KnockdownTimer;
        uint32 FrenzyTimer;
        uint32 YellTimer;
        uint32 ResetTimer;

        void Reset()
        {
            WhirlwindTimer    = urand(1 * IN_MILLISECONDS, 20 * IN_MILLISECONDS);
            Whirlwind2Timer   = urand(1 * IN_MILLISECONDS, 20 * IN_MILLISECONDS);
            KnockdownTimer    = 12 * IN_MILLISECONDS;
            FrenzyTimer       = 6 * IN_MILLISECONDS;
            ResetTimer        = 5 * IN_MILLISECONDS;
            YellTimer         = urand(20 * IN_MILLISECONDS, 30 * IN_MILLISECONDS); //20 to 30 seconds
        }

        void EnterCombat(Unit* /*who*/)
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

            if (WhirlwindTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_WHIRLWIND);
                WhirlwindTimer =  urand(8 * IN_MILLISECONDS, 18 * IN_MILLISECONDS);
            } else WhirlwindTimer -= diff;

            if (Whirlwind2Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_WHIRLWIND2);
                Whirlwind2Timer = urand(7 * IN_MILLISECONDS, 25 * IN_MILLISECONDS);
            } else Whirlwind2Timer -= diff;

            if (KnockdownTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_KNOCKDOWN);
                KnockdownTimer = urand(10 * IN_MILLISECONDS, 15 * IN_MILLISECONDS);
            } else KnockdownTimer -= diff;

            if (FrenzyTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FRENZY);
                FrenzyTimer = urand(20 * IN_MILLISECONDS, 30 * IN_MILLISECONDS);
            } else FrenzyTimer -= diff;

            if (YellTimer <= diff)
            {
                DoScriptText(RAND(YELL_RANDOM1, YELL_RANDOM2, YELL_RANDOM3, YELL_RANDOM4, YELL_RANDOM5), me);
                YellTimer = urand(20 * IN_MILLISECONDS, 30 * IN_MILLISECONDS); //20 to 30 seconds
            } else YellTimer -= diff;

            // check if creature is not outside of building
            if (ResetTimer <= diff)
            {
                if (me->GetDistance2d(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY()) > 50)
                {
                    EnterEvadeMode();
                    DoScriptText(YELL_EVADE, me);
                }
                ResetTimer = 5 * IN_MILLISECONDS;
            } else ResetTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_drektharAI(creature);
    }
};

void AddSC_boss_drekthar()
{
    new boss_drekthar;
}