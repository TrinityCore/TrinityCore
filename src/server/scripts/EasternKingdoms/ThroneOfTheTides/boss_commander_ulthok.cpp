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
#include "throne_of_the_tides.h"

#define SPELL_DARK_FISSURE          DUNGEON_MODE(76047,96311)
#define SPELL_DARK_FISSURE_AURA     DUNGEON_MODE(76066,91371)
#define SPELL_SQUEEZE               DUNGEON_MODE(76026,95463)

enum Spells
{
    SPELL_ENRAGE                = 76100,
    SPELL_CURSE_OF_FATIGUE      = 76094,
    SPELL_PULL_TARGET           = 67357, // HACK!!
};

enum Yells
{
    SAY_AGGRO                   = -1643007,
    SAY_AGGRO_WHISP             = -1643008,
    SAY_DEATH                   = -1643009,
    SAY_DEATH_WHISP             = -1643010,
};

class boss_commander_ulthok : public CreatureScript
{
public:
    boss_commander_ulthok() : CreatureScript("boss_commander_ulthok") {}

    struct boss_commander_ulthokAI : public ScriptedAI
    {
        boss_commander_ulthokAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 DarkFissureTimer;
        uint32 EnrageTimer;
        uint32 SqueezeTimer;
        uint32 CurseTimer;
        uint32 TargetTimer;
        Unit* SqueezeTarget;

        InstanceScript *instance;

        void Reset()
        {
            DarkFissureTimer = 22500;
            EnrageTimer = urand(12000,18000);
            SqueezeTimer = 25500;
            CurseTimer = 32000;
            TargetTimer = 20000;

            me->GetMotionMaster()->MoveTargetedHome();

            if (instance)
                instance->SetData(DATA_COMMANDER_ULTHOK_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);
            DoScriptText(SAY_AGGRO_WHISP, me);

            if (instance)
                instance->SetData(DATA_COMMANDER_ULTHOK_EVENT, IN_PROGRESS);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (TargetTimer <= diff)
            {
                SqueezeTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                TargetTimer = 22500;
            } else TargetTimer -= diff;

            if (DarkFissureTimer <= diff)
            {
                DoCastVictim(SPELL_DARK_FISSURE);
                DarkFissureTimer = 22500;
            } else DarkFissureTimer -= diff;

            if (EnrageTimer <= diff)
            {
                DoCast(me, SPELL_ENRAGE);
                EnrageTimer = urand(12000,15000);
            } else EnrageTimer -= diff;

            if (SqueezeTimer <= diff)
            {
                DoCast(SqueezeTarget, SPELL_PULL_TARGET, true);
                DoCast(SqueezeTarget, SPELL_SQUEEZE, true);
                SqueezeTimer = 22500;
            } else SqueezeTimer -= diff;

            if (CurseTimer <= diff)
            {
                DoCast(SqueezeTarget, SPELL_CURSE_OF_FATIGUE, true);
                CurseTimer = 22500;
            } else CurseTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);
            DoScriptText(SAY_DEATH_WHISP, me);

            if (instance)
                instance->SetData(DATA_COMMANDER_ULTHOK_EVENT, DONE);
        }
    };

    CreatureAI* GetAI(Creature *creature) const
    {
        return new boss_commander_ulthokAI (creature);
    }
};

void AddSC_boss_commander_ulthok()
{
    new boss_commander_ulthok();
}