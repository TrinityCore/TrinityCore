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
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
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
    SPELL_SUPPRESSION_AURA  = 22247 // Suppression Device Spell
};

enum Events
{
    EVENT_CLEAVE            = 1,
    EVENT_BLASTWAVE         = 2,
    EVENT_MORTALSTRIKE      = 3,
    EVENT_KNOCKBACK         = 4,
    EVENT_CHECK             = 5,
    // Suppression Device Events
    EVENT_SUPPRESSION_CAST  = 6,
    EVENT_SUPPRESSION_RESET = 7
};

enum Actions
{
    ACTION_DEACTIVATE = 0
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

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();

            std::list<GameObject*> _goList;
            GetGameObjectListWithEntryInGrid(_goList, me, GO_SUPPRESSION_DEVICE, 200.0f);
            for (std::list<GameObject*>::const_iterator itr = _goList.begin(); itr != _goList.end(); itr++)
                ((*itr)->AI()->DoAction(ACTION_DEACTIVATE));
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
            go_suppression_deviceAI(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()), _active(true) { }

            void InitializeAI() override
            {
                if (_instance->GetBossState(DATA_BROODLORD_LASHLAYER) == DONE)
                {
                    Deactivate();
                    return;
                }

                _events.ScheduleEvent(EVENT_SUPPRESSION_CAST, 0s, 5s);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUPPRESSION_CAST:
                            if (me->GetGoState() == GO_STATE_READY)
                            {
                                me->CastSpell(nullptr, SPELL_SUPPRESSION_AURA, true);
                                me->SendCustomAnim(0);
                            }
                            _events.ScheduleEvent(EVENT_SUPPRESSION_CAST, 5s);
                            break;
                        case EVENT_SUPPRESSION_RESET:
                            Activate();
                            break;
                    }
                }
            }

            void OnLootStateChanged(uint32 state, Unit* /*unit*/) override
            {
                switch (state)
                {
                    case GO_ACTIVATED:
                        Deactivate();
                        _events.CancelEvent(EVENT_SUPPRESSION_CAST);
                        _events.ScheduleEvent(EVENT_SUPPRESSION_RESET, 30s, 120s);
                        break;
                    case GO_JUST_DEACTIVATED: // This case prevents the Gameobject despawn by Disarm Trap
                        me->SetLootState(GO_READY);
                        break;
                }
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_DEACTIVATE)
                {
                    Deactivate();
                    _events.CancelEvent(EVENT_SUPPRESSION_RESET);
                }
            }

            void Activate()
            {
                if (_active)
                    return;
                _active = true;
                if (me->GetGoState() == GO_STATE_ACTIVE)
                    me->SetGoState(GO_STATE_READY);
                me->SetLootState(GO_READY);
                me->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                _events.ScheduleEvent(EVENT_SUPPRESSION_CAST, 0s);
            }

            void Deactivate()
            {
                if (!_active)
                    return;
                _active = false;
                me->SetGoState(GO_STATE_ACTIVE);
                me->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                _events.CancelEvent(EVENT_SUPPRESSION_CAST);
            }

        private:
            InstanceScript* _instance;
            EventMap _events;
            bool _active;
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
