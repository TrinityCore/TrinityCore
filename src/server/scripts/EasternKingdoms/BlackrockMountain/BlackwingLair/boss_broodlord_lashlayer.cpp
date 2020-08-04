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
#include "ScriptedCreature.h"

enum Say
{
    SAY_AGGRO               = 0,
    SAY_LEASH               = 1
};

enum Spells
{
    SPELL_CLEAVE            = 26350,
    SPELL_BLASTWAVE         = 23331,
    SPELL_MORTALSTRIKE      = 24573,
    SPELL_KNOCKBACK         = 25778,
    //Suppression Device Spell
    SPELL_SUPPRESSION_AURA  = 22247
};

enum Events
{
    EVENT_CLEAVE            = 1,
    EVENT_BLASTWAVE         = 2,
    EVENT_MORTALSTRIKE      = 3,
    EVENT_KNOCKBACK         = 4,
    EVENT_CHECK             = 5,
    //Suppression Device Events
    EVENT_SUPPRESSION_AURA  = 6,
    EVENT_SUPPRESSION_ANIM  = 7,
    EVENT_SUPPRESSION_RESET = 8
};

class boss_broodlord : public CreatureScript
{
public:
    boss_broodlord() : CreatureScript("boss_broodlord") { }

    struct boss_broodlordAI : public BossAI
    {
        boss_broodlordAI(Creature* creature) : BossAI(creature, DATA_BROODLORD_LASHLAYER) { }

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);
            Talk(SAY_AGGRO);

            events.ScheduleEvent(EVENT_CLEAVE, 8s);
            events.ScheduleEvent(EVENT_BLASTWAVE, 12s);
            events.ScheduleEvent(EVENT_MORTALSTRIKE, 20s);
            events.ScheduleEvent(EVENT_KNOCKBACK, 30s);
            events.ScheduleEvent(EVENT_CHECK, 1s);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CLEAVE:
                        DoCastVictim(SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE, 7s);
                        break;
                    case EVENT_BLASTWAVE:
                        DoCastVictim(SPELL_BLASTWAVE);
                        events.ScheduleEvent(EVENT_BLASTWAVE, 8s, 16s);
                        break;
                    case EVENT_MORTALSTRIKE:
                        DoCastVictim(SPELL_MORTALSTRIKE);
                        events.ScheduleEvent(EVENT_MORTALSTRIKE, 25s, 35s);
                        break;
                    case EVENT_KNOCKBACK:
                        DoCastVictim(SPELL_KNOCKBACK);
                        if (GetThreat(me->GetVictim()))
                            ModifyThreatByPercent(me->GetVictim(), -50);
                        events.ScheduleEvent(EVENT_KNOCKBACK, 15s, 30s);
                        break;
                    case EVENT_CHECK:
                        if (me->GetDistance(me->GetHomePosition()) > 150.0f)
                        {
                            Talk(SAY_LEASH);
                            EnterEvadeMode(EVADE_REASON_BOUNDARY);
                        }
                        events.ScheduleEvent(EVENT_CHECK, 1s);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackwingLairAI<boss_broodlordAI>(creature);
    }
};

class go_suppression_device : public GameObjectScript
{
    public:
        go_suppression_device() : GameObjectScript("go_suppression_device") { }

        struct go_suppression_deviceAI : public GameObjectAI
        {
            go_suppression_deviceAI(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()) { }

            void InitializeAI() override
            {
                _events.ScheduleEvent(EVENT_SUPPRESSION_AURA, Seconds(5));
                _events.ScheduleEvent(EVENT_SUPPRESSION_ANIM, Seconds(2));
            }

            void UpdateAI(uint32 diff) override
            {
                if (_instance->GetBossState(DATA_VAELASTRAZ_THE_CORRUPT) != DONE)
                    return;

                if (_instance->GetBossState(DATA_BROODLORD_LASHLAYER) == DONE)
                {
                    if (me->GetGoState() != GO_STATE_DESTROYED)
                    {
                        me->SetGoState(GO_STATE_DESTROYED);
                        me->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    }
                    return;
                };

                if (me->GetGoState() == GO_STATE_DESTROYED)
                    me->SetLootState(GO_READY); // NOT doing this will despawn the gameobject after using Disarm Trap

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUPPRESSION_AURA:
                            if (me->GetGoState() == GO_STATE_READY)
                                me->CastSpell(nullptr,SPELL_SUPPRESSION_AURA,true);
                            _events.ScheduleEvent(EVENT_SUPPRESSION_AURA, Seconds(5));
                            break;
                        case EVENT_SUPPRESSION_ANIM:
                            if (me->GetGoState() == GO_STATE_READY)
                                me->SendCustomAnim(0);
                            _events.ScheduleEvent(EVENT_SUPPRESSION_ANIM, Seconds(1), Seconds(2)); //in current retail Videos,there is a ~7 Seconds timer for the animation loop but they arent fully synched.
                            break;
                        case EVENT_SUPPRESSION_RESET:
                            if (me->GetGoState() == GO_STATE_DESTROYED)
                                me->SetGoState(GO_STATE_READY);
                            me->SetLootState(GO_READY);
                            me->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            break;
                    }
                }
            }

            void OnLootStateChanged(uint32 state, Unit* /*unit*/) override
            {
                if (state == GO_ACTIVATED)
                {
                    me->SetGoState(GO_STATE_DESTROYED);
                    me->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    _events.ScheduleEvent(EVENT_SUPPRESSION_RESET, Seconds(30), Seconds(120));
                }
            }

        private:
            InstanceScript* _instance;
            EventMap _events;
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetBlackwingLairAI<go_suppression_deviceAI>(go);
        }
};

void AddSC_boss_broodlord()
{
    new boss_broodlord();
    new go_suppression_device();
}
