/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
SDName: Duskwood
SD%Complete: 100
SDComment: Quest Support:8735
SDCategory: Duskwood
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Player.h"

enum TwilightCorrupter
{
    NPC_TWILIGHT_CORRUPTER          = 15625,
    YELL_TWILIGHT_CORRUPTOR_RESPAWN = 0,
    YELL_TWILIGHT_CORRUPTOR_AGGRO   = 1,
    YELL_TWILIGHT_CORRUPTOR_KILL    = 2,

    SPELL_SOUL_CORRUPTION           = 25805,
    SPELL_CREATURE_OF_NIGHTMARE     = 25806,
    SPELL_LEVEL_UP                  = 24312,

    EVENT_SOUL_CORRUPTION           = 1,
    EVENT_CREATURE_OF_NIGHTMARE     = 2,

    QUEST_NIGHTMARES_CORRUPTION     = 8735
};

/*######
# boss_twilight_corrupter
######*/

class boss_twilight_corrupter : public CreatureScript
{
public:
    boss_twilight_corrupter() : CreatureScript("boss_twilight_corrupter") { }

    struct boss_twilight_corrupterAI : public ScriptedAI
    {
        boss_twilight_corrupterAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            KillCount = 0;
        }

        void Reset() override
        {
            _events.Reset();
            Initialize();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(YELL_TWILIGHT_CORRUPTOR_AGGRO);
            _events.ScheduleEvent(EVENT_SOUL_CORRUPTION, 15000);
            _events.ScheduleEvent(EVENT_CREATURE_OF_NIGHTMARE, 30000);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
            {
                ++KillCount;
                Talk(YELL_TWILIGHT_CORRUPTOR_KILL, victim);

                if (KillCount == 3)
                {
                    DoCast(me, SPELL_LEVEL_UP, true);
                    KillCount = 0;
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SOUL_CORRUPTION:
                        DoCastAOE(SPELL_SOUL_CORRUPTION);
                        _events.ScheduleEvent(EVENT_SOUL_CORRUPTION, urand(15000, 19000));
                        break;
                    case EVENT_CREATURE_OF_NIGHTMARE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            DoCast(target, SPELL_CREATURE_OF_NIGHTMARE);
                        _events.ScheduleEvent(EVENT_CREATURE_OF_NIGHTMARE, 45000);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        private:
            EventMap _events;
            uint8 KillCount;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_twilight_corrupterAI(creature);
    }
};

/*######
# at_twilight_grove
######*/

Position const TwillightCorrupter = { -10328.16f, -489.57f, 49.95f, 0.0f };

class at_twilight_grove : public AreaTriggerScript
{
    public:
        at_twilight_grove() : AreaTriggerScript("at_twilight_grove") { }

        bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/) override
        {
            if (player->GetQuestStatus(QUEST_NIGHTMARES_CORRUPTION) == QUEST_STATUS_INCOMPLETE)
                if (!player->FindNearestCreature(NPC_TWILIGHT_CORRUPTER, 500.0f, true))
                    if (Creature* corrupter = player->SummonCreature(NPC_TWILIGHT_CORRUPTER, TwillightCorrupter, TEMPSUMMON_MANUAL_DESPAWN, 60000))
                        corrupter->AI()->Talk(YELL_TWILIGHT_CORRUPTOR_RESPAWN, player);

            return false;
        };
};

void AddSC_duskwood()
{
    new boss_twilight_corrupter();
    new at_twilight_grove();
}
