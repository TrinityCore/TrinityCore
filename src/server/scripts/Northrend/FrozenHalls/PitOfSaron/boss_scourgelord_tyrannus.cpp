/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "pit_of_saron.h"
#include "Vehicle.h"
#include "Player.h"

enum Yells
{
    //Gorkun
    SAY_GORKUN_INTRO_2              = 0,
    SAY_GORKUN_OUTRO_1              = 1,
    SAY_GORKUN_OUTRO_2              = 2,

    //Tyrannus
    SAY_AMBUSH_1                    = 3,
    SAY_AMBUSH_2                    = 4,
    SAY_GAUNTLET_START              = 5,
    SAY_TYRANNUS_INTRO_1            = 6,
    SAY_TYRANNUS_INTRO_3            = 7,
    SAY_AGGRO                       = 8,
    SAY_SLAY                        = 9,
    SAY_DEATH                       = 10,
    SAY_MARK_RIMEFANG_1             = 11,
    SAY_MARK_RIMEFANG_2             = 12,
    SAY_DARK_MIGHT_1                = 13,
    SAY_DARK_MIGHT_2                = 14,

    //Jaina
    SAY_JAYNA_OUTRO_3               = 3,
    SAY_JAYNA_OUTRO_4               = 4,
    SAY_JAYNA_OUTRO_5               = 5,

    //Sylvanas
    SAY_SYLVANAS_OUTRO_3            = 3,
    SAY_SYLVANAS_OUTRO_4            = 4
};

enum Spells
{
    SPELL_OVERLORD_BRAND            = 69172,
    SPELL_OVERLORD_BRAND_HEAL       = 69190,
    SPELL_OVERLORD_BRAND_DAMAGE     = 69189,
    SPELL_FORCEFUL_SMASH            = 69155,
    SPELL_UNHOLY_POWER              = 69167,
    SPELL_MARK_OF_RIMEFANG          = 69275,
    SPELL_HOARFROST                 = 69246,

    SPELL_ICY_BLAST                 = 69232,
    SPELL_ICY_BLAST_AURA            = 69238,

    SPELL_EJECT_ALL_PASSENGERS      = 50630,
    SPELL_FULL_HEAL                 = 43979,
};

enum Events
{
    EVENT_OVERLORD_BRAND    = 1,
    EVENT_FORCEFUL_SMASH    = 2,
    EVENT_UNHOLY_POWER      = 3,
    EVENT_MARK_OF_RIMEFANG  = 4,

    // Rimefang
    EVENT_MOVE_NEXT         = 5,
    EVENT_HOARFROST         = 6,
    EVENT_ICY_BLAST         = 7,

    EVENT_INTRO_1           = 8,
    EVENT_INTRO_2           = 9,
    EVENT_INTRO_3           = 10,
    EVENT_COMBAT_START      = 11,
};

enum Phases
{
    PHASE_NONE      = 0,
    PHASE_INTRO     = 1,
    PHASE_COMBAT    = 2,
    PHASE_OUTRO     = 3
};

enum Actions
{
    ACTION_START_INTRO      = 1,
    ACTION_START_RIMEFANG   = 2,
    ACTION_START_OUTRO      = 3,
    ACTION_END_COMBAT       = 4,
};

#define GUID_HOARFROST 1

static const Position rimefangPos[10] =
{
    {1017.299f, 168.9740f, 642.9259f, 0.000000f},
    {1047.868f, 126.4931f, 665.0453f, 0.000000f},
    {1069.828f, 138.3837f, 665.0453f, 0.000000f},
    {1063.042f, 164.5174f, 665.0453f, 0.000000f},
    {1031.158f, 195.1441f, 665.0453f, 0.000000f},
    {1019.087f, 197.8038f, 665.0453f, 0.000000f},
    {967.6233f, 168.9670f, 665.0453f, 0.000000f},
    {969.1198f, 140.4722f, 665.0453f, 0.000000f},
    {986.7153f, 141.6424f, 665.0453f, 0.000000f},
    {1012.601f, 142.4965f, 665.0453f, 0.000000f},
};

static const Position miscPos = {1018.376f, 167.2495f, 628.2811f, 0.000000f};   //tyrannus combat start position

class boss_tyrannus : public CreatureScript
{
    public:
        boss_tyrannus() : CreatureScript("boss_tyrannus") { }

        struct boss_tyrannusAI : public BossAI
        {
            boss_tyrannusAI(Creature* creature) : BossAI(creature, DATA_TYRANNUS)
            {
            }

            void InitializeAI() OVERRIDE
            {
                if (instance->GetBossState(DATA_TYRANNUS) != DONE)
                    Reset();
                else
                    me->DespawnOrUnsummon();
            }

            void Reset() OVERRIDE
            {
                events.Reset();
                events.SetPhase(PHASE_NONE);
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                instance->SetBossState(DATA_TYRANNUS, NOT_STARTED);
            }

            Creature* GetRimefang()
            {
                return ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_RIMEFANG));
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                Talk(SAY_AGGRO);
            }

            void AttackStart(Unit* victim) OVERRIDE
            {
                if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                    return;

                if (victim && me->Attack(victim, true) && !events.IsInPhase(PHASE_INTRO))
                    me->GetMotionMaster()->MoveChase(victim);
            }

            void EnterEvadeMode() OVERRIDE
            {
                instance->SetBossState(DATA_TYRANNUS, FAIL);
                if (Creature* rimefang = GetRimefang())
                    rimefang->AI()->EnterEvadeMode();

                me->DespawnOrUnsummon();
            }

            void KilledUnit(Unit* victim) OVERRIDE
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                Talk(SAY_DEATH);
                instance->SetBossState(DATA_TYRANNUS, DONE);

                // Prevent corpse despawning
                if (TempSummon* summ = me->ToTempSummon())
                    summ->SetTempSummonType(TEMPSUMMON_DEAD_DESPAWN);

                // Stop combat for Rimefang
                if (Creature* rimefang = GetRimefang())
                    rimefang->AI()->DoAction(ACTION_END_COMBAT);
            }

            void DoAction(int32 actionId) OVERRIDE
            {
                if (actionId == ACTION_START_INTRO)
                {
                    Talk(SAY_TYRANNUS_INTRO_1);
                    events.SetPhase(PHASE_INTRO);
                    events.ScheduleEvent(EVENT_INTRO_1, 14000, 0, PHASE_INTRO);
                    events.ScheduleEvent(EVENT_INTRO_2, 22000, 0, PHASE_INTRO);
                    events.ScheduleEvent(EVENT_INTRO_3, 34000, 0, PHASE_INTRO);
                    events.ScheduleEvent(EVENT_COMBAT_START, 36000, 0, PHASE_INTRO);
                    instance->SetBossState(DATA_TYRANNUS, IN_PROGRESS);
                }
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim() && !events.IsInPhase(PHASE_INTRO))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INTRO_1:
                            //Talk(SAY_GORKUN_INTRO_2, pGorkunOrVictus);
                            break;
                        case EVENT_INTRO_2:
                            Talk(SAY_TYRANNUS_INTRO_3);
                            break;
                        case EVENT_INTRO_3:
                            me->ExitVehicle();
                            me->GetMotionMaster()->MovePoint(0, miscPos);
                            break;
                        case EVENT_COMBAT_START:
                            if (Creature* rimefang = me->GetCreature(*me, instance->GetData64(DATA_RIMEFANG)))
                                rimefang->AI()->DoAction(ACTION_START_RIMEFANG);    //set rimefang also infight
                            events.SetPhase(PHASE_COMBAT);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            me->SetReactState(REACT_AGGRESSIVE);
                            DoCast(me, SPELL_FULL_HEAL);
                            DoZoneInCombat();
                            events.ScheduleEvent(EVENT_OVERLORD_BRAND, urand(5000, 7000));
                            events.ScheduleEvent(EVENT_FORCEFUL_SMASH, urand(14000, 16000));
                            events.ScheduleEvent(EVENT_MARK_OF_RIMEFANG, urand(25000, 27000));
                            break;
                        case EVENT_OVERLORD_BRAND:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                                DoCast(target, SPELL_OVERLORD_BRAND);
                            events.ScheduleEvent(EVENT_OVERLORD_BRAND, urand(11000, 12000));
                            break;
                        case EVENT_FORCEFUL_SMASH:
                            DoCastVictim(SPELL_FORCEFUL_SMASH);
                            events.ScheduleEvent(EVENT_UNHOLY_POWER, 1000);
                            break;
                        case EVENT_UNHOLY_POWER:
                            Talk(SAY_DARK_MIGHT_1);
                            Talk(SAY_DARK_MIGHT_2);
                            DoCast(me, SPELL_UNHOLY_POWER);
                            events.ScheduleEvent(EVENT_FORCEFUL_SMASH, urand(40000, 48000));
                            break;
                        case EVENT_MARK_OF_RIMEFANG:
                            Talk(SAY_MARK_RIMEFANG_1);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                            {
                                Talk(SAY_MARK_RIMEFANG_2, target);
                                DoCast(target, SPELL_MARK_OF_RIMEFANG);
                            }
                            events.ScheduleEvent(EVENT_MARK_OF_RIMEFANG, urand(24000, 26000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetPitOfSaronAI<boss_tyrannusAI>(creature);
        }
};

class boss_rimefang : public CreatureScript
{
    public:
        boss_rimefang() : CreatureScript("boss_rimefang") { }

        struct boss_rimefangAI : public ScriptedAI
        {
            boss_rimefangAI(Creature* creature) : ScriptedAI(creature), _vehicle(creature->GetVehicleKit())
            {
                ASSERT(_vehicle);
            }

            void Reset() OVERRIDE
            {
                _events.Reset();
                _events.SetPhase(PHASE_NONE);
                _currentWaypoint = 0;
                _hoarfrostTargetGUID = 0;
                me->SetCanFly(true);
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }

            void JustReachedHome() OVERRIDE
            {
                _vehicle->InstallAllAccessories(false);
            }

            void DoAction(int32 actionId) OVERRIDE
            {
                if (actionId == ACTION_START_RIMEFANG)
                {
                    _events.SetPhase(PHASE_COMBAT);
                    DoZoneInCombat();
                    _events.ScheduleEvent(EVENT_MOVE_NEXT, 500, 0, PHASE_COMBAT);
                    _events.ScheduleEvent(EVENT_ICY_BLAST, 15000, 0, PHASE_COMBAT);
                }
                else if (actionId == ACTION_END_COMBAT)
                    _EnterEvadeMode();
            }

            void SetGUID(uint64 guid, int32 type) OVERRIDE
            {
                if (type == GUID_HOARFROST)
                {
                    _hoarfrostTargetGUID = guid;
                    _events.ScheduleEvent(EVENT_HOARFROST, 1000);
                }
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim() && !_events.IsInPhase(PHASE_COMBAT))
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MOVE_NEXT:
                            if (_currentWaypoint >= 10 || _currentWaypoint == 0)
                                _currentWaypoint = 1;
                            me->GetMotionMaster()->MovePoint(0, rimefangPos[_currentWaypoint]);
                            ++_currentWaypoint;
                            _events.ScheduleEvent(EVENT_MOVE_NEXT, 2000, 0, PHASE_COMBAT);
                            break;
                        case EVENT_ICY_BLAST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_ICY_BLAST);
                            _events.ScheduleEvent(EVENT_ICY_BLAST, 15000, 0, PHASE_COMBAT);
                            break;
                        case EVENT_HOARFROST:
                            if (Unit* target = me->GetUnit(*me, _hoarfrostTargetGUID))
                            {
                                DoCast(target, SPELL_HOARFROST);
                                _hoarfrostTargetGUID = 0;
                            }
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            Vehicle* _vehicle;
            uint64 _hoarfrostTargetGUID;
            EventMap _events;
            uint8 _currentWaypoint;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new boss_rimefangAI(creature);
        }
};

class player_overlord_brandAI : public PlayerAI
{
    public:
        player_overlord_brandAI(Player* player, uint64 casterGUID) : PlayerAI(player), _tyrannusGUID(casterGUID) { }

        void DamageDealt(Unit* /*victim*/, uint32& damage, DamageEffectType /*damageType*/) OVERRIDE
        {
            if (Creature* tyrannus = ObjectAccessor::GetCreature(*me, _tyrannusGUID))
                if (Unit* victim = tyrannus->GetVictim())
                    me->CastCustomSpell(SPELL_OVERLORD_BRAND_DAMAGE, SPELLVALUE_BASE_POINT0, damage, victim, true, NULL, NULL, tyrannus->GetGUID());
        }

        void HealDone(Unit* /*target*/, uint32& addHealth) OVERRIDE
        {
            if (Creature* tyrannus = ObjectAccessor::GetCreature(*me, _tyrannusGUID))
                me->CastCustomSpell(SPELL_OVERLORD_BRAND_HEAL, SPELLVALUE_BASE_POINT0, int32(addHealth * 5.5f), tyrannus, true, NULL, NULL, tyrannus->GetGUID());
        }

        void UpdateAI(uint32 /*diff*/) OVERRIDE { }

    private:
        uint64 _tyrannusGUID;
};

class spell_tyrannus_overlord_brand : public SpellScriptLoader
{
    public:
        spell_tyrannus_overlord_brand() : SpellScriptLoader("spell_tyrannus_overlord_brand") { }

        class spell_tyrannus_overlord_brand_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_tyrannus_overlord_brand_AuraScript);

            bool Load() OVERRIDE
            {
                return GetCaster() && GetCaster()->GetEntry() == NPC_TYRANNUS;
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
                    return;

                oldAI = GetTarget()->GetAI();
                oldAIState = GetTarget()->IsAIEnabled;
                GetTarget()->SetAI(new player_overlord_brandAI(GetTarget()->ToPlayer(), GetCasterGUID()));
                GetTarget()->IsAIEnabled = true;
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
                    return;

                GetTarget()->IsAIEnabled = oldAIState;
                UnitAI* thisAI = GetTarget()->GetAI();
                GetTarget()->SetAI(oldAI);
                delete thisAI;
            }

            void Register() OVERRIDE
            {
                AfterEffectApply += AuraEffectApplyFn(spell_tyrannus_overlord_brand_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_tyrannus_overlord_brand_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }

            UnitAI* oldAI;
            bool oldAIState;
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_tyrannus_overlord_brand_AuraScript();
        }
};

class spell_tyrannus_mark_of_rimefang : public SpellScriptLoader
{
    public:
        spell_tyrannus_mark_of_rimefang() : SpellScriptLoader("spell_tyrannus_mark_of_rimefang") { }

        class spell_tyrannus_mark_of_rimefang_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_tyrannus_mark_of_rimefang_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* caster = GetCaster();
                if (!caster || caster->GetTypeId() != TYPEID_UNIT)
                    return;

                if (InstanceScript* instance = caster->GetInstanceScript())
                    if (Creature* rimefang = ObjectAccessor::GetCreature(*caster, instance->GetData64(DATA_RIMEFANG)))
                        rimefang->AI()->SetGUID(GetTarget()->GetGUID(), GUID_HOARFROST);
            }

            void Register() OVERRIDE
            {
                AfterEffectApply += AuraEffectApplyFn(spell_tyrannus_mark_of_rimefang_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_tyrannus_mark_of_rimefang_AuraScript();
        }
};

class at_tyrannus_event_starter : public AreaTriggerScript
{
    public:
        at_tyrannus_event_starter() : AreaTriggerScript("at_tyrannus_event_starter") { }

        bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/) OVERRIDE
        {
            InstanceScript* instance = player->GetInstanceScript();
            if (player->IsGameMaster() || !instance)
                return false;

            if (instance->GetBossState(DATA_TYRANNUS) != IN_PROGRESS && instance->GetBossState(DATA_TYRANNUS) != DONE)
                if (Creature* tyrannus = ObjectAccessor::GetCreature(*player, instance->GetData64(DATA_TYRANNUS)))
                {
                    tyrannus->AI()->DoAction(ACTION_START_INTRO);
                    return true;
                }

            return false;
        }
};

void AddSC_boss_tyrannus()
{
    new boss_tyrannus();
    new boss_rimefang();
    new spell_tyrannus_overlord_brand();
    new spell_tyrannus_mark_of_rimefang();
    new at_tyrannus_event_starter();
}
