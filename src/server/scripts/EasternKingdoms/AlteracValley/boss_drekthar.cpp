/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

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
    YELL_AGGRO                                    = 0,
    YELL_EVADE                                    = 1,
    YELL_RESPAWN                                  = 2,
    YELL_RANDOM                                   = 3
};

class boss_drekthar : public CreatureScript
{
public:
    boss_drekthar() : CreatureScript("boss_drekthar") { }

    struct boss_drektharAI : public ScriptedAI
    {
        boss_drektharAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 WhirlwindTimer;
        uint32 Whirlwind2Timer;
        uint32 KnockdownTimer;
        uint32 FrenzyTimer;
        uint32 YellTimer;
        uint32 ResetTimer;

        void Reset() override
        {
            WhirlwindTimer    = urand(1 * IN_MILLISECONDS, 20 * IN_MILLISECONDS);
            Whirlwind2Timer   = urand(1 * IN_MILLISECONDS, 20 * IN_MILLISECONDS);
            KnockdownTimer    = 12 * IN_MILLISECONDS;
            FrenzyTimer       = 6 * IN_MILLISECONDS;
            ResetTimer        = 5 * IN_MILLISECONDS;
            YellTimer         = urand(20 * IN_MILLISECONDS, 30 * IN_MILLISECONDS); //20 to 30 seconds
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(YELL_AGGRO);
        }

        void JustRespawned() override
        {
            Reset();
            Talk(YELL_RESPAWN);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (WhirlwindTimer <= diff)
            {
                DoCastVictim(SPELL_WHIRLWIND);
                WhirlwindTimer =  urand(8 * IN_MILLISECONDS, 18 * IN_MILLISECONDS);
            } else WhirlwindTimer -= diff;

            if (Whirlwind2Timer <= diff)
            {
                DoCastVictim(SPELL_WHIRLWIND2);
                Whirlwind2Timer = urand(7 * IN_MILLISECONDS, 25 * IN_MILLISECONDS);
            } else Whirlwind2Timer -= diff;

            if (KnockdownTimer <= diff)
            {
                DoCastVictim(SPELL_KNOCKDOWN);
                KnockdownTimer = urand(10 * IN_MILLISECONDS, 15 * IN_MILLISECONDS);
            } else KnockdownTimer -= diff;

            if (FrenzyTimer <= diff)
            {
                DoCastVictim(SPELL_FRENZY);
                FrenzyTimer = urand(20 * IN_MILLISECONDS, 30 * IN_MILLISECONDS);
            } else FrenzyTimer -= diff;

            if (YellTimer <= diff)
            {
                Talk(YELL_RANDOM);
                YellTimer = urand(20 * IN_MILLISECONDS, 30 * IN_MILLISECONDS); //20 to 30 seconds
            } else YellTimer -= diff;

            // check if creature is not outside of building
            if (ResetTimer <= diff)
            {
                if (me->GetDistance2d(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY()) > 50)
                {
                    EnterEvadeMode();
                    Talk(YELL_EVADE);
                }
                ResetTimer = 5 * IN_MILLISECONDS;
            } else ResetTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_drektharAI(creature);
    }
};

void AddSC_boss_drekthar()
{
    new boss_drekthar;
}