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

/*
 * Comment: Find in the future best timers and the event is not implemented.
 */

#include "ScriptMgr.h"
#include "azjol_nerub.h"
#include "Containers.h"
#include "InstanceScript.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum Events
{
    // Krik'thir the Gatewatcher
    EVENT_SEND_GROUP = 1,
    EVENT_SWARM,
    EVENT_MIND_FLAY,
    EVENT_FRENZY,

    // Watchers - Shared
    EVENT_WEB_WRAP,
    EVENT_INFECTED_BITE,

    // Watcher Gashra
    EVENT_ENRAGE,
    // Watcher Narjil
    EVENT_BLINDING_WEBS,
    // Watcher Silthik
    EVENT_POISON_SPRAY,

    // Anubar Skirmisher
    EVENT_ANUBAR_CHARGE,
    EVENT_BACKSTAB,

    // Anubar Shadowcaster
    EVENT_SHADOW_BOLT,
    EVENT_SHADOW_NOVA,

    // Anubar Warrior
    EVENT_STRIKE,
    EVENT_CLEAVE
};

enum Spells
{
    // Krik'thir the Gatewatcher
    SPELL_SUBBOSS_AGGRO_TRIGGER     = 52343,
    SPELL_SWARM                     = 52440,
    SPELL_MIND_FLAY                 = 52586,
    SPELL_CURSE_OF_FATIGUE          = 52592,
    SPELL_FRENZY                    = 28747,

    // Watchers - Shared
    SPELL_WEB_WRAP                  = 52086,
    SPELL_WEB_WRAP_WRAPPED          = 52087,
    SPELL_INFECTED_BITE             = 52469,

    // Watcher Gashra
    SPELL_ENRAGE                    = 52470,
    // Watcher Narjil
    SPELL_BLINDING_WEBS             = 52524,
    // Watcher Silthik
    SPELL_POISON_SPRAY              = 52493,

    // Anub'ar Warrior
    SPELL_CLEAVE                    = 49806,
    SPELL_STRIKE                    = 52532,

    // Anub'ar Skirmisher
    SPELL_CHARGE                    = 52538,
    SPELL_BACKSTAB                  = 52540,
    SPELL_FIXATE_TRIGGER            = 52536,
    SPELL_FIXATE_TRIGGERED          = 52537,

    // Anub'ar Shadowcaster
    SPELL_SHADOW_BOLT               = 52534,
    SPELL_SHADOW_NOVA               = 52535,

    // Skittering Infector
    SPELL_ACID_SPLASH               = 52446
};

enum Data
{
    DATA_PET_GROUP
};

enum Actions
{
    ACTION_GASHRA_DIED,
    ACTION_NARJIL_DIED,
    ACTION_SILTHIK_DIED,
    ACTION_WATCHER_ENGAGED,
    ACTION_PET_ENGAGED,
    ACTION_PET_EVADE
};

enum Yells
{
    SAY_AGGRO       = 0,
    SAY_SLAY        = 1,
    SAY_DEATH       = 2,
    SAY_SWARM       = 3,
    SAY_PREFIGHT    = 4,
    SAY_SEND_GROUP  = 5
};

class boss_krik_thir : public CreatureScript
{
    public:
        boss_krik_thir() : CreatureScript("boss_krik_thir") { }

        struct boss_krik_thirAI : public BossAI
        {
            boss_krik_thirAI(Creature* creature) : BossAI(creature, DATA_KRIKTHIR), _hadFrenzy(false), _petsInCombat(false), _watchersActive(0) { }

            void SummonAdds()
            {
                if (instance->GetBossState(DATA_KRIKTHIR) == DONE)
                    return;

                for (uint8 i = 1; i <= 3; ++i)
                {
                    std::list<TempSummon*> adds;
                    me->SummonCreatureGroup(i, &adds);
                    for (TempSummon* add : adds)
                        add->AI()->SetData(DATA_PET_GROUP, i);
                }
            }

            void Reset() override
            {
                BossAI::Reset();
                _hadFrenzy = false;
                _petsInCombat = false;
                _watchersActive = 0;
                me->SetReactState(REACT_PASSIVE);
            }

            void JustAppeared() override
            {
                BossAI::JustAppeared();
                SummonAdds();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
                summons.clear();
                _JustDied();
                Talk(SAY_DEATH);
            }

            void JustEngagedWith(Unit* who) override
            {
                _petsInCombat = false;
                me->SetReactState(REACT_AGGRESSIVE);
                summons.DoZoneInCombat();

                events.CancelEvent(EVENT_SEND_GROUP);
                events.ScheduleEvent(EVENT_SWARM, 5s);
                events.ScheduleEvent(EVENT_MIND_FLAY, randtime(Seconds(1), Seconds(3)));

                BossAI::JustEngagedWith(who);
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (!me->HasReactState(REACT_PASSIVE))
                {
                    ScriptedAI::MoveInLineOfSight(who);
                    return;
                }

                if (me->CanStartAttack(who, false) && me->IsWithinDistInMap(who, me->GetAttackDistance(who) + me->m_CombatDistance))
                    JustEngagedWith(who);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                summons.DespawnAll();
                _DespawnAtEvade();
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case -ACTION_GATEWATCHER_GREET:
                        if (!instance->GetData(DATA_GATEWATCHER_GREET) && me->IsAlive() && !me->IsInCombat() && !_petsInCombat)
                        {
                            instance->SetData(DATA_GATEWATCHER_GREET, 1);
                            Talk(SAY_PREFIGHT);
                        }
                        break;
                    case ACTION_GASHRA_DIED:
                    case ACTION_NARJIL_DIED:
                    case ACTION_SILTHIK_DIED:
                        if (!_watchersActive) // something is wrong
                        {
                            EnterEvadeMode(EVADE_REASON_OTHER);
                            return;
                        }
                        if (!--_watchersActive) // if there are no watchers currently in combat...
                            events.RescheduleEvent(EVENT_SEND_GROUP, Seconds(5)); // ...send the next watcher after the targets sooner
                        break;
                    case ACTION_WATCHER_ENGAGED:
                        ++_watchersActive;
                        break;
                    case ACTION_PET_ENGAGED:
                        if (_petsInCombat || me->IsInCombat())
                            break;
                        _petsInCombat = true;
                        Talk(SAY_AGGRO);
                        events.ScheduleEvent(EVENT_SEND_GROUP, 70s);
                        break;
                    case ACTION_PET_EVADE:
                        EnterEvadeMode(EVADE_REASON_OTHER);
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && !_petsInCombat)
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (me->HealthBelowPct(10) && !_hadFrenzy)
                {
                    _hadFrenzy = true;
                    events.ScheduleEvent(EVENT_FRENZY, 1s);
                }

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SEND_GROUP:
                            DoCastAOE(SPELL_SUBBOSS_AGGRO_TRIGGER, true);
                            events.Repeat(Seconds(70));
                            break;

                        case EVENT_SWARM:
                            DoCastAOE(SPELL_SWARM);
                            Talk(SAY_SWARM);
                            break;

                        case EVENT_MIND_FLAY:
                            DoCastVictim(SPELL_MIND_FLAY);
                            events.Repeat(randtime(Seconds(9), Seconds(11)));
                            break;

                        case EVENT_FRENZY:
                            DoCastSelf(SPELL_FRENZY);
                            DoCastAOE(SPELL_CURSE_OF_FATIGUE);
                            events.Repeat(Seconds(15));
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }

            void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
            {
                if (spellInfo->Id == SPELL_SUBBOSS_AGGRO_TRIGGER)
                    DoZoneInCombat();
            }

            void SpellHitTarget(WorldObject* /*target*/, SpellInfo const* spellInfo) override
            {
                if (spellInfo->Id == SPELL_SUBBOSS_AGGRO_TRIGGER)
                    Talk(SAY_SEND_GROUP);
            }

            private:
                bool _hadFrenzy;
                bool _petsInCombat;
                uint8 _watchersActive;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<boss_krik_thirAI>(creature);
        }
};

struct npc_gatewatcher_petAI : public ScriptedAI
{
    npc_gatewatcher_petAI(Creature* creature, bool isWatcher) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _petGroup(0), _isWatcher(isWatcher) { }

    virtual void _JustEngagedWith() = 0;
    void JustEngagedWith(Unit* who) override
    {
        if (_isWatcher)
        {
            _isWatcher = false;
            if (TempSummon* meSummon = me->ToTempSummon())
                if (Creature* summoner = meSummon->GetSummonerCreatureBase())
                    summoner->AI()->DoAction(ACTION_WATCHER_ENGAGED);
        }

        if (me->HasReactState(REACT_PASSIVE))
        {
            std::list<Creature*> others;
            me->GetCreatureListWithEntryInGrid(others, 0, 40.0f);
            for (Creature* other : others)
                if (other->AI()->GetData(DATA_PET_GROUP) == _petGroup)
                {
                    other->SetReactState(REACT_AGGRESSIVE);
                    other->AI()->AttackStart(who);
                }

            if (TempSummon* meSummon = me->ToTempSummon())
                if (Creature* summoner = meSummon->GetSummonerCreatureBase())
                    summoner->AI()->DoAction(ACTION_PET_ENGAGED);
        }
        _JustEngagedWith();
        ScriptedAI::JustEngagedWith(who);
        me->SetCombatPulseDelay(5);
    }

    void SetData(uint32 data, uint32 value) override
    {
        if (data == DATA_PET_GROUP)
        {
            _petGroup = value;
            me->SetReactState(_petGroup ? REACT_PASSIVE : REACT_AGGRESSIVE);
        }
    }

    uint32 GetData(uint32 data) const override
    {
        if (data == DATA_PET_GROUP)
            return _petGroup;
        return 0;
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!me->HasReactState(REACT_PASSIVE))
        {
            ScriptedAI::MoveInLineOfSight(who);
            return;
        }

        if (me->CanStartAttack(who, false) && me->IsWithinDistInMap(who, me->GetAttackDistance(who) + me->m_CombatDistance))
            JustEngagedWith(who);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_SUBBOSS_AGGRO_TRIGGER)
            DoZoneInCombat();
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (TempSummon* meSummon = me->ToTempSummon())
        {
            if (Creature* summoner = meSummon->GetSummonerCreatureBase())
                summoner->AI()->DoAction(ACTION_PET_EVADE);
            else
                me->DespawnOrUnsummon();
            return;
        }
        ScriptedAI::EnterEvadeMode(why);
    }

    EventMap _events;
    InstanceScript* _instance;
    uint32 _petGroup;
    bool _isWatcher;
};

class npc_watcher_gashra : public CreatureScript
{
    public:
        npc_watcher_gashra() : CreatureScript("npc_watcher_gashra") { }

        struct npc_watcher_gashraAI : public npc_gatewatcher_petAI
        {
            npc_watcher_gashraAI(Creature* creature) : npc_gatewatcher_petAI(creature, true) { }

            void Reset() override
            {
                _events.Reset();
            }

            void _JustEngagedWith() override
            {
                _events.ScheduleEvent(EVENT_ENRAGE, randtime(Seconds(3), Seconds(5)));
                _events.ScheduleEvent(EVENT_WEB_WRAP, randtime(Seconds(16), Seconds(19)));
                _events.ScheduleEvent(EVENT_INFECTED_BITE, randtime(Seconds(7),Seconds(11)));
            }

            void JustDied(Unit* /*killer*/) override
            {
                Creature* krikthir = _instance->GetCreature(DATA_KRIKTHIR);
                if (krikthir && krikthir->IsAlive())
                    krikthir->AI()->DoAction(ACTION_GASHRA_DIED);
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
                        case EVENT_ENRAGE:
                            DoCastSelf(SPELL_ENRAGE);
                            _events.Repeat(randtime(Seconds(12), Seconds(20)));
                            break;
                        case EVENT_WEB_WRAP:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f))
                                DoCast(target, SPELL_WEB_WRAP);
                            _events.Repeat(randtime(Seconds(13), Seconds(19)));
                            break;
                        case EVENT_INFECTED_BITE:
                            DoCastVictim(SPELL_INFECTED_BITE);
                            _events.Repeat(randtime(Seconds(23), Seconds(27)));
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }

            private:
                EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<npc_watcher_gashraAI>(creature);
        }
};

class npc_watcher_narjil : public CreatureScript
{
    public:
        npc_watcher_narjil() : CreatureScript("npc_watcher_narjil") { }

        struct npc_watcher_narjilAI : public npc_gatewatcher_petAI
        {
            npc_watcher_narjilAI(Creature* creature) : npc_gatewatcher_petAI(creature, true)
            {
            }

            void Reset() override
            {
                _events.Reset();
            }

            void _JustEngagedWith() override
            {
                _events.ScheduleEvent(EVENT_BLINDING_WEBS, randtime(Seconds(13), Seconds(18)));
                _events.ScheduleEvent(EVENT_WEB_WRAP, randtime(Seconds(3), Seconds(5)));
                _events.ScheduleEvent(EVENT_INFECTED_BITE, randtime(Seconds(7), Seconds(11)));
            }

            void JustDied(Unit* /*killer*/) override
            {
                Creature* krikthir = _instance->GetCreature(DATA_KRIKTHIR);
                if (krikthir && krikthir->IsAlive())
                    krikthir->AI()->DoAction(ACTION_NARJIL_DIED);
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
                        case EVENT_BLINDING_WEBS:
                            DoCastVictim(SPELL_BLINDING_WEBS);
                            _events.Repeat(randtime(Seconds(23), Seconds(27)));
                            break;
                        case EVENT_WEB_WRAP:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100, true))
                                DoCast(target, SPELL_WEB_WRAP);
                            _events.Repeat(randtime(Seconds(13), Seconds(19)));
                            break;
                        case EVENT_INFECTED_BITE:
                            DoCastVictim(SPELL_INFECTED_BITE);
                            _events.Repeat(randtime(Seconds(20), Seconds(25)));
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }

            private:
                EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<npc_watcher_narjilAI>(creature);
        }
};

class npc_watcher_silthik : public CreatureScript
{
    public:
        npc_watcher_silthik() : CreatureScript("npc_watcher_silthik") { }

        struct npc_watcher_silthikAI : public npc_gatewatcher_petAI
        {
            npc_watcher_silthikAI(Creature* creature) : npc_gatewatcher_petAI(creature, true)
            {
            }

            void Reset() override
            {
                _events.Reset();
            }

            void _JustEngagedWith() override
            {
                _events.ScheduleEvent(EVENT_POISON_SPRAY, randtime(Seconds(16), Seconds(19)));
                _events.ScheduleEvent(EVENT_WEB_WRAP, randtime(Seconds(7), Seconds(11)));
                _events.ScheduleEvent(EVENT_INFECTED_BITE, randtime(Seconds(3), Seconds(5)));
            }

            void JustDied(Unit* /*killer*/) override
            {
                Creature* krikthir = _instance->GetCreature(DATA_KRIKTHIR);
                if (krikthir && krikthir->IsAlive())
                    krikthir->AI()->DoAction(ACTION_SILTHIK_DIED);
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
                        case EVENT_POISON_SPRAY:
                            DoCastVictim(SPELL_POISON_SPRAY);
                            _events.Repeat(randtime(Seconds(13), Seconds(19)));
                            break;
                        case EVENT_WEB_WRAP:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100, true))
                                DoCast(target, SPELL_WEB_WRAP);
                            _events.Repeat(randtime(Seconds(13), Seconds(17)));
                            break;
                        case EVENT_INFECTED_BITE:
                            DoCastVictim(SPELL_INFECTED_BITE);
                            _events.Repeat(randtime(Seconds(20), Seconds(24)));
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }

            private:
                EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<npc_watcher_silthikAI>(creature);
        }
};

class npc_anub_ar_warrior : public CreatureScript
{
    public:
        npc_anub_ar_warrior() : CreatureScript("npc_anub_ar_warrior") { }

        struct npc_anub_ar_warriorAI : public npc_gatewatcher_petAI
        {
            npc_anub_ar_warriorAI(Creature* creature) : npc_gatewatcher_petAI(creature, false) { }

            void Reset() override
            {
                _events.Reset();
            }

            void _JustEngagedWith() override
            {
                _events.ScheduleEvent(EVENT_CLEAVE, randtime(Seconds(7), Seconds(9)));
                _events.ScheduleEvent(EVENT_STRIKE, randtime(Seconds(5), Seconds(10)));
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
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            _events.Repeat(randtime(Seconds(10), Seconds(16)));
                            break;
                        case EVENT_STRIKE:
                            DoCastVictim(SPELL_STRIKE);
                            _events.Repeat(randtime(Seconds(15), Seconds(19)));
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<npc_anub_ar_warriorAI>(creature);
        }
};

class npc_anub_ar_skirmisher : public CreatureScript
{
    public:
        npc_anub_ar_skirmisher() : CreatureScript("npc_anub_ar_skirmisher") { }

        struct npc_anub_ar_skirmisherAI : public npc_gatewatcher_petAI
        {
            npc_anub_ar_skirmisherAI(Creature* creature) : npc_gatewatcher_petAI(creature, false) { }

            void Reset() override
            {
                _events.Reset();
            }

            void _JustEngagedWith() override
            {
                _events.ScheduleEvent(EVENT_ANUBAR_CHARGE, randtime(Seconds(6), Seconds(8)));
                _events.ScheduleEvent(EVENT_BACKSTAB, randtime(Seconds(7), Seconds(9)));
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
                        case EVENT_ANUBAR_CHARGE:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                                DoCast(target, SPELL_CHARGE);
                            _events.Repeat(randtime(Seconds(20), Seconds(25)));
                            break;
                        case EVENT_BACKSTAB:
                            if (me->GetVictim() && me->GetVictim()->isInBack(me))
                                DoCastVictim(SPELL_BACKSTAB);
                            _events.Repeat(randtime(Seconds(10), Seconds(13)));
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }

            void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
            {
                Unit* unitTarget = target->ToUnit();
                if (!unitTarget)
                    return;

                if (spellInfo->Id == SPELL_CHARGE)
                    DoCast(unitTarget, SPELL_FIXATE_TRIGGER);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<npc_anub_ar_skirmisherAI>(creature);
        }
};

class npc_anub_ar_shadowcaster : public CreatureScript
{
    public:
        npc_anub_ar_shadowcaster() : CreatureScript("npc_anub_ar_shadowcaster") { }

        struct npc_anub_ar_shadowcasterAI : public npc_gatewatcher_petAI
        {
            npc_anub_ar_shadowcasterAI(Creature* creature) : npc_gatewatcher_petAI(creature, false) { }

            void Reset() override
            {
                _events.Reset();
            }

            void _JustEngagedWith() override
            {
                _events.ScheduleEvent(EVENT_SHADOW_BOLT, 4s);
                _events.ScheduleEvent(EVENT_SHADOW_NOVA, randtime(Seconds(10), Seconds(14)));
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
                        case EVENT_SHADOW_BOLT:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                                DoCast(target, SPELL_SHADOW_BOLT);
                            _events.Repeat(randtime(Seconds(2), Seconds(4)));
                            break;
                        case EVENT_SHADOW_NOVA:
                            DoCastVictim(SPELL_SHADOW_NOVA);
                            _events.Repeat(randtime(Seconds(10), Seconds(16)));
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<npc_anub_ar_shadowcasterAI>(creature);
        }
};

class npc_skittering_swarmer : public CreatureScript
{
    public:
        npc_skittering_swarmer() : CreatureScript("npc_skittering_swarmer") { }

        struct npc_skittering_swarmerAI : public ScriptedAI
        {
            npc_skittering_swarmerAI(Creature* creature) : ScriptedAI(creature) { }

            void InitializeAI() override
            {
                ScriptedAI::InitializeAI();
                if (Creature* gatewatcher = me->GetInstanceScript()->GetCreature(DATA_KRIKTHIR))
                {
                    if (Unit* target = gatewatcher->getAttackerForHelper())
                        AttackStart(target);
                    gatewatcher->AI()->JustSummoned(me);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<npc_skittering_swarmerAI>(creature);
        }
};

class npc_skittering_infector : public CreatureScript
{
    public:
        npc_skittering_infector() : CreatureScript("npc_skittering_infector") { }

        struct npc_skittering_infectorAI : public ScriptedAI
        {
            npc_skittering_infectorAI(Creature* creature) : ScriptedAI(creature) { }

            void InitializeAI() override
            {
                ScriptedAI::InitializeAI();
                if (Creature* gatewatcher = me->GetInstanceScript()->GetCreature(DATA_KRIKTHIR))
                {
                    if (Unit* target = gatewatcher->getAttackerForHelper())
                        AttackStart(target);
                    gatewatcher->AI()->JustSummoned(me);
                }
            }

            void JustDied(Unit* killer) override
            {
                DoCastAOE(SPELL_ACID_SPLASH);
                ScriptedAI::JustDied(killer);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<npc_skittering_infectorAI>(creature);
        }
};

class npc_gatewatcher_web_wrap : public CreatureScript
{
    public:
        npc_gatewatcher_web_wrap() : CreatureScript("npc_gatewatcher_web_wrap") { }

        struct npc_gatewatcher_web_wrapAI : public NullCreatureAI
        {
            npc_gatewatcher_web_wrapAI(Creature* creature) : NullCreatureAI(creature) { }

            void JustDied(Unit* /*killer*/) override
            {
                if (TempSummon* meSummon = me->ToTempSummon())
                    if (Unit* summoner = meSummon->GetSummonerUnit())
                        summoner->RemoveAurasDueToSpell(SPELL_WEB_WRAP_WRAPPED);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAzjolNerubAI<npc_gatewatcher_web_wrapAI>(creature);
        }
};

// 52343 - Krik'Thir Subboss Aggro Trigger
class spell_gatewatcher_subboss_trigger : public SpellScriptLoader
{
    public:
        spell_gatewatcher_subboss_trigger() : SpellScriptLoader("spell_gatewatcher_subboss_trigger") { }

        class spell_gatewatcher_subboss_trigger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gatewatcher_subboss_trigger_SpellScript);

            void HandleTargets(std::list<WorldObject*>& targetList)
            {
                // Remove any Watchers that are already in combat
                auto it = targetList.begin();
                while (it != targetList.end())
                {
                    if (Creature* creature = (*it)->ToCreature())
                        if (creature->IsAlive() && !creature->IsInCombat())
                        {
                            ++it;
                            continue;
                        }
                    it = targetList.erase(it);
                }

                // Default to Krik'thir himself if he isn't engaged
                WorldObject* target = nullptr;
                if (GetCaster() && !GetCaster()->IsInCombat())
                    target = GetCaster();
                // Unless there are Watchers that aren't engaged yet
                if (!targetList.empty())
                {
                    // If there are, pick one of them at random
                    target = Trinity::Containers::SelectRandomContainerElement(targetList);
                }
                // And hit only that one
                targetList.clear();
                if (target)
                    targetList.push_back(target);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_gatewatcher_subboss_trigger_SpellScript::HandleTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_gatewatcher_subboss_trigger_SpellScript();
        }
};

// 52536 - Fixate Trigger
class spell_anub_ar_skirmisher_fixate : public SpellScriptLoader
{
    public:
        spell_anub_ar_skirmisher_fixate() : SpellScriptLoader("spell_anub_ar_skirmisher_fixate") { }

        class spell_anub_ar_skirmisher_fixate_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_anub_ar_skirmisher_fixate_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_FIXATE_TRIGGERED });
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                    target->CastSpell(GetCaster(), SPELL_FIXATE_TRIGGERED, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_anub_ar_skirmisher_fixate_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_anub_ar_skirmisher_fixate_SpellScript();
        }
};

// 52086 - Web Wrap
class spell_gatewatcher_web_wrap : public SpellScriptLoader
{
    public:
        spell_gatewatcher_web_wrap() : SpellScriptLoader("spell_gatewatcher_web_wrap") { }

        class spell_gatewatcher_web_wrap_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_gatewatcher_web_wrap_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_WEB_WRAP_WRAPPED });
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
                    return;

                if (Unit* target = GetTarget())
                    target->CastSpell(target, SPELL_WEB_WRAP_WRAPPED, true);
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_gatewatcher_web_wrap_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_MOD_ROOT, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_gatewatcher_web_wrap_AuraScript();
        }
};

class achievement_watch_him_die : public AchievementCriteriaScript
{
    public:
        achievement_watch_him_die() : AchievementCriteriaScript("achievement_watch_him_die") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            InstanceScript* instance = target->GetInstanceScript();
            if (!instance)
                return false;

            for (ANDataTypes watcherData : {DATA_WATCHER_GASHRA, DATA_WATCHER_NARJIL, DATA_WATCHER_SILTHIK})
            {
                if (Creature* watcher = instance->GetCreature(watcherData))
                    if (watcher->IsAlive())
                        continue;
                return false;
            }

            return true;
        }
};

void AddSC_boss_krik_thir()
{
    new boss_krik_thir();

    new npc_watcher_gashra();
    new npc_watcher_narjil();
    new npc_watcher_silthik();

    new npc_anub_ar_warrior();
    new npc_anub_ar_skirmisher();
    new npc_anub_ar_shadowcaster();

    new npc_skittering_swarmer();
    new npc_skittering_infector();
    new npc_gatewatcher_web_wrap();

    new spell_gatewatcher_subboss_trigger();
    new spell_anub_ar_skirmisher_fixate();
    new spell_gatewatcher_web_wrap();

    new achievement_watch_him_die();
}
