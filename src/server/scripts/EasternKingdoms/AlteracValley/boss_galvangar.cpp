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
    SPELL_CLEAVE                                  = 15284,
    SPELL_FRIGHTENING_SHOUT                       = 19134,
    SPELL_WHIRLWIND1                              = 15589,
    SPELL_WHIRLWIND2                              = 13736,
    SPELL_MORTAL_STRIKE                           = 16856
};

enum Yells
{
    YELL_AGGRO                                    = -1810021,
    YELL_EVADE                                    = -1810022
};

class boss_galvangar : public CreatureScript
{
public:
    boss_galvangar() : CreatureScript("boss_galvangar") { }

    struct boss_galvangarAI : public ScriptedAI
    {
        boss_galvangarAI(Creature *c) : ScriptedAI(c) {}

        uint32 uiCleaveTimer;
        uint32 uiFrighteningShoutTimer;
        uint32 uiWhirlwind1Timer;
        uint32 uiWhirlwind2Timer;
        uint32 uiMortalStrikeTimer;
        uint32 uiResetTimer;

        void Reset()
        {
            uiCleaveTimer                     = urand(1*IN_MILLISECONDS, 9*IN_MILLISECONDS);
            uiFrighteningShoutTimer           = urand(2*IN_MILLISECONDS, 19*IN_MILLISECONDS);
            uiWhirlwind1Timer                 = urand(1*IN_MILLISECONDS, 13*IN_MILLISECONDS);
            uiWhirlwind2Timer                 = urand(5*IN_MILLISECONDS, 20*IN_MILLISECONDS);
            uiMortalStrikeTimer               = urand(5*IN_MILLISECONDS, 20*IN_MILLISECONDS);
            uiResetTimer                      = 5*IN_MILLISECONDS;
        }

        void EnterCombat(Unit * /*who*/)
        {
            DoScriptText(YELL_AGGRO, me);
        }

        void JustRespawned()
        {
            Reset();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiCleaveTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CLEAVE);
                uiCleaveTimer =  urand(10*IN_MILLISECONDS, 16*IN_MILLISECONDS);
            } else uiCleaveTimer -= diff;

            if (uiFrighteningShoutTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FRIGHTENING_SHOUT);
                uiFrighteningShoutTimer = urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS);
            } else uiFrighteningShoutTimer -= diff;

            if (uiWhirlwind1Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_WHIRLWIND1);
                uiWhirlwind1Timer = urand(6*IN_MILLISECONDS, 10*IN_MILLISECONDS);
            } else uiWhirlwind1Timer -= diff;

            if (uiWhirlwind2Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_WHIRLWIND2);
                uiWhirlwind2Timer = urand(10*IN_MILLISECONDS, 25*IN_MILLISECONDS);
            } else uiWhirlwind2Timer -= diff;

            if (uiMortalStrikeTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_MORTAL_STRIKE);
                uiMortalStrikeTimer = urand(10*IN_MILLISECONDS, 30*IN_MILLISECONDS);
            } else uiMortalStrikeTimer -= diff;

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
        return new boss_galvangarAI(creature);
    }
};

void AddSC_boss_galvangar()
{
    new boss_galvangar;
}
