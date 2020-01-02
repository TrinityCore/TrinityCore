/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "blackwing_lair.h"
#include "InstanceScript.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

enum Say
{
    SAY_EGGS_BROKEN1        = 0,
    SAY_EGGS_BROKEN2        = 1,
    SAY_EGGS_BROKEN3        = 2,
    SAY_DEATH               = 3,
};

enum Spells
{
    // @todo orb uses the wrong spell, this needs sniffs
    SPELL_MINDCONTROL       = 42013,
    SPELL_CHANNEL           = 45537,
    SPELL_EGG_DESTROY       = 19873,

    SPELL_CLEAVE            = 22540,
    SPELL_WARSTOMP          = 24375,
    SPELL_FIREBALLVOLLEY    = 22425,
    SPELL_CONFLAGRATION     = 23023
};

enum Summons
{
    NPC_ELITE_DRACHKIN      = 12422,
    NPC_ELITE_WARRIOR       = 12458,
    NPC_WARRIOR             = 12416,
    NPC_MAGE                = 12420,
    NPC_WARLOCK             = 12459,

    GO_EGG                  = 177807
};

enum EVENTS
{
    EVENT_CLEAVE            = 1,
    EVENT_STOMP             = 2,
    EVENT_FIREBALL          = 3,
    EVENT_CONFLAGRATION     = 4
};

class boss_razorgore : public CreatureScript
{
public:
    boss_razorgore() : CreatureScript("boss_razorgore") { }

    struct boss_razorgoreAI : public BossAI
    {
        boss_razorgoreAI(Creature* creature) : BossAI(creature, DATA_RAZORGORE_THE_UNTAMED)
        {
            Initialize();
        }

        void Initialize()
        {
            secondPhase = false;
        }

        void Reset() override
        {
            _Reset();

            Initialize();
            instance->SetData(DATA_EGG_EVENT, NOT_STARTED);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            Talk(SAY_DEATH);

            instance->SetData(DATA_EGG_EVENT, NOT_STARTED);
        }

        void DoChangePhase()
        {
            events.ScheduleEvent(EVENT_CLEAVE, 15s);
            events.ScheduleEvent(EVENT_STOMP, 35s);
            events.ScheduleEvent(EVENT_FIREBALL, 7s);
            events.ScheduleEvent(EVENT_CONFLAGRATION, 12s);

            secondPhase = true;
            me->RemoveAllAuras();
            me->SetFullHealth();
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_PHASE_TWO)
                DoChangePhase();
        }

        void DamageTaken(Unit* /*who*/, uint32& damage) override
        {
            // @todo this is wrong - razorgore should still take damage, he should just nuke the whole room and respawn if he dies during P1
            if (!secondPhase)
                damage = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CLEAVE:
                        DoCastVictim(SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE, 7s, 10s);
                        break;
                    case EVENT_STOMP:
                        DoCastVictim(SPELL_WARSTOMP);
                        events.ScheduleEvent(EVENT_STOMP, 15s, 25s);
                        break;
                    case EVENT_FIREBALL:
                        DoCastVictim(SPELL_FIREBALLVOLLEY);
                        events.ScheduleEvent(EVENT_FIREBALL, 12s, 15s);
                        break;
                    case EVENT_CONFLAGRATION:
                        DoCastVictim(SPELL_CONFLAGRATION);
                        events.ScheduleEvent(EVENT_CONFLAGRATION, 30s);
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
            DoMeleeAttackIfReady();
        }

    private:
        bool secondPhase;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackwingLairAI<boss_razorgoreAI>(creature);
    }
};

class go_orb_of_domination : public GameObjectScript
{
    public:
        go_orb_of_domination() : GameObjectScript("go_orb_of_domination") { }

        struct go_orb_of_dominationAI : public GameObjectAI
        {
            go_orb_of_dominationAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

            InstanceScript* instance;

            bool GossipHello(Player* player) override
            {
                if (instance->GetData(DATA_EGG_EVENT) != DONE)
                {
                    if (Creature* razorgore = instance->GetCreature(DATA_RAZORGORE_THE_UNTAMED))
                    {
                        razorgore->Attack(player, true);
                        player->CastSpell(razorgore, SPELL_MINDCONTROL);
                    }
                }
                return true;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetBlackwingLairAI<go_orb_of_dominationAI>(go);
        }
};

class spell_egg_event : public SpellScriptLoader
{
    public:
        spell_egg_event() : SpellScriptLoader("spell_egg_event") { }

        class spell_egg_eventSpellScript : public SpellScript
        {
            PrepareSpellScript(spell_egg_eventSpellScript);

            void HandleOnHit()
            {
                if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                    instance->SetData(DATA_EGG_EVENT, SPECIAL);
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_egg_eventSpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_egg_eventSpellScript();
        }
};

void AddSC_boss_razorgore()
{
    new boss_razorgore();
    new go_orb_of_domination();
    new spell_egg_event();
}
