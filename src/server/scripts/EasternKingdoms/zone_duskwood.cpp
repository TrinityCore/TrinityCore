/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
    ITEM_FRAGMENT                   = 21149,
    NPC_TWILIGHT_CORRUPTER          = 15625,
    YELL_TWILIGHTCORRUPTOR_RESPAWN  = 0,
    YELL_TWILIGHTCORRUPTOR_AGGRO    = 1,
    YELL_TWILIGHTCORRUPTOR_KILL     = 2,
    SPELL_SOUL_CORRUPTION           = 25805,
    SPELL_CREATURE_OF_NIGHTMARE     = 25806,
    SPELL_LEVEL_UP                  = 24312,

    EVENT_SOUL_CORRUPTION           = 1,
    EVENT_CREATURE_OF_NIGHTMARE     = 2,
    FACTION_HOSTILE                 = 14
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
        boss_twilight_corrupterAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            KillCount                 = 0;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(YELL_TWILIGHTCORRUPTOR_AGGRO);
            _events.ScheduleEvent(EVENT_SOUL_CORRUPTION, 15000);
            _events.ScheduleEvent(EVENT_CREATURE_OF_NIGHTMARE, 30000);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
            {
                ++KillCount;
                Talk(YELL_TWILIGHTCORRUPTOR_KILL, victim);

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

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SOUL_CORRUPTION:
                        DoCastVictim(SPELL_SOUL_CORRUPTION);
                        _events.ScheduleEvent(EVENT_SOUL_CORRUPTION, rand()%4000+15000);
                        break;
                    case EVENT_CREATURE_OF_NIGHTMARE:
                        DoCastVictim(SPELL_CREATURE_OF_NIGHTMARE);
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

class at_twilight_grove : public AreaTriggerScript
{
public:
    at_twilight_grove() : AreaTriggerScript("at_twilight_grove") { }

    bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/) override
    {
        if (player->HasQuestForItem(ITEM_FRAGMENT))
        {
            if (Unit* corrupter = player->SummonCreature(NPC_TWILIGHT_CORRUPTER, -10328.16f, -489.57f, 49.95f, 0, TEMPSUMMON_MANUAL_DESPAWN, 60000))
                corrupter->setFaction(FACTION_HOSTILE);

            if (Creature* CorrupterSpeaker = player->SummonCreature(1, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ()-1, 0, TEMPSUMMON_TIMED_DESPAWN, 15000))
            {
                CorrupterSpeaker->SetName("Twilight Corrupter");
                CorrupterSpeaker->SetVisible(true);
                CorrupterSpeaker->AI()->Talk(YELL_TWILIGHTCORRUPTOR_RESPAWN, player);
            }
        }
        return false;
    };
};

void AddSC_duskwood()
{
    new boss_twilight_corrupter();
    new at_twilight_grove();
}
