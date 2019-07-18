/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "blackfathom_deeps.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_POISON_CLOUD     = 3815,
    SPELL_FRENZIED_RAGE    = 3490
};

enum Events
{
    EVENT_POISON_CLOUD     = 1,
    EVENT_FRENZIED_RAGE
};

class boss_aku_mai : public CreatureScript
{
public:
    boss_aku_mai() : CreatureScript("boss_aku_mai") { }

    struct boss_aku_maiAI : public BossAI
    {
        boss_aku_maiAI(Creature* creature) : BossAI(creature, DATA_AKU_MAI)
        {
            Initialize();
        }

        void Initialize()
        {
            IsEnraged = false;
        }

        void Reset() override
        {
            Initialize();
            _Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_POISON_CLOUD, urand(5000, 9000));
        }

        void DamageTaken(Unit* /*atacker*/, uint32 &damage) override
        {
            if (!IsEnraged && me->HealthBelowPctDamaged(30, damage))
            {
                DoCast(me, SPELL_FRENZIED_RAGE);
                IsEnraged = true;
            }
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_POISON_CLOUD:
                    DoCastVictim(SPELL_POISON_CLOUD);
                    events.ScheduleEvent(EVENT_POISON_CLOUD, urand(25000, 50000));
                    break;
                default:
                    break;
            }
        }

        private:
            bool IsEnraged;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackfathomDeepsAI<boss_aku_maiAI>(creature);
    }
};

void AddSC_boss_aku_mai()
{
    new boss_aku_mai();
}
