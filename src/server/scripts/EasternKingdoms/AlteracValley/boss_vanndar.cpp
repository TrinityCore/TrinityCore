/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

enum Yells
{
    YELL_AGGRO                                    = -1810008,
    YELL_EVADE                                    = -1810009,
    YELL_RESPAWN1                                 = -1810010,
    YELL_RESPAWN2                                 = -1810011,
    YELL_RANDOM1                                  = -1810012,
    YELL_RANDOM2                                  = -1810013,
    YELL_RANDOM3                                  = -1810014,
    YELL_RANDOM4                                  = -1810015,
    YELL_RANDOM5                                  = -1810016,
    YELL_RANDOM6                                  = -1810017,
    YELL_RANDOM7                                  = -1810018
};

enum Spells
{
    SPELL_AVATAR                                  = 19135,
    SPELL_THUNDERCLAP                             = 15588,
    SPELL_STORMBOLT                               = 20685 // not sure
};

class boss_vanndar : public CreatureScript
{
public:
    boss_vanndar() : CreatureScript("boss_vanndar") { }

    struct boss_vanndarAI : public ScriptedAI
    {
        boss_vanndarAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 AvatarTimer;
        uint32 ThunderclapTimer;
        uint32 StormboltTimer;
        uint32 ResetTimer;
        uint32 YellTimer;

        void Reset()
        {
            AvatarTimer        = 3 * IN_MILLISECONDS;
            ThunderclapTimer   = 4 * IN_MILLISECONDS;
            StormboltTimer     = 6 * IN_MILLISECONDS;
            ResetTimer         = 5 * IN_MILLISECONDS;
            YellTimer = urand(20 * IN_MILLISECONDS, 30 * IN_MILLISECONDS);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(YELL_AGGRO, me);
        }

        void JustRespawned()
        {
            Reset();
            DoScriptText(RAND(YELL_RESPAWN1, YELL_RESPAWN2), me);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (AvatarTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_AVATAR);
                AvatarTimer =  urand(15 * IN_MILLISECONDS, 20 * IN_MILLISECONDS);
            } else AvatarTimer -= diff;

            if (ThunderclapTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_THUNDERCLAP);
                ThunderclapTimer = urand(5 * IN_MILLISECONDS, 15 * IN_MILLISECONDS);
            } else ThunderclapTimer -= diff;

            if (StormboltTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_STORMBOLT);
                StormboltTimer = urand(10 * IN_MILLISECONDS, 25 * IN_MILLISECONDS);
            } else StormboltTimer -= diff;

            if (YellTimer <= diff)
            {
                DoScriptText(RAND(YELL_RANDOM1, YELL_RANDOM2, YELL_RANDOM3, YELL_RANDOM4, YELL_RANDOM5, YELL_RANDOM6, YELL_RANDOM7), me);
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
        return new boss_vanndarAI(creature);
    }
};

void AddSC_boss_vanndar()
{
    new boss_vanndar;
}