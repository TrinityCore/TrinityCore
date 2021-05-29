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
#include "GameTime.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "ulduar.h"
#include "Vehicle.h"

enum Yells
{
    SAY_AGGRO       = 0,
    SAY_SUMMON      = 1,
    SAY_SLAG_POT    = 2,
    SAY_SCORCH      = 3,
    SAY_SLAY        = 4,
    SAY_BERSERK     = 5,
    SAY_DEATH       = 6,
    EMOTE_JETS      = 7
};

enum Spells
{
    SPELL_FLAME_JETS            = 62680,
    SPELL_SCORCH                = 62546,
    SPELL_SLAG_POT              = 62717,
    SPELL_SLAG_POT_DAMAGE       = 65722,
    SPELL_SLAG_IMBUED           = 62836,
    SPELL_ACTIVATE_CONSTRUCT    = 62488,
    SPELL_STRENGHT              = 64473,
    SPELL_GRAB                  = 62707,
    SPELL_BERSERK               = 47008,

    // Iron Construct
    SPELL_HEAT                  = 65667,
    SPELL_MOLTEN                = 62373,
    SPELL_BRITTLE               = 62382,
    SPELL_BRITTLE_25            = 67114,
    SPELL_SHATTER               = 62383,
    SPELL_GROUND                = 62548,
};

enum Events
{
    EVENT_JET           = 1,
    EVENT_SCORCH        = 2,
    EVENT_SLAG_POT      = 3,
    EVENT_GRAB_POT      = 4,
    EVENT_CHANGE_POT    = 5,
    EVENT_END_POT       = 6,
    EVENT_CONSTRUCT     = 7,
    EVENT_BERSERK       = 8,
};

enum Actions
{
    ACTION_REMOVE_BUFF = 20,
};

enum Creatures
{
    NPC_IRON_CONSTRUCT  = 33121,
    NPC_GROUND_SCORCH   = 33221,
};

enum AchievementData
{
    DATA_SHATTERED                  = 29252926,
    ACHIEVEMENT_IGNIS_START_EVENT   = 20951,
};

#define CONSTRUCT_SPAWN_POINTS 20

Position const ConstructSpawnPosition[CONSTRUCT_SPAWN_POINTS] =
{
    {630.366f, 216.772f, 360.891f, 3.001970f},
    {630.594f, 231.846f, 360.891f, 3.124140f},
    {630.435f, 337.246f, 360.886f, 3.211410f},
    {630.493f, 313.349f, 360.886f, 3.054330f},
    {630.444f, 321.406f, 360.886f, 3.124140f},
    {630.366f, 247.307f, 360.888f, 3.211410f},
    {630.698f, 305.311f, 360.886f, 3.001970f},
    {630.500f, 224.559f, 360.891f, 3.054330f},
    {630.668f, 239.840f, 360.890f, 3.159050f},
    {630.384f, 329.585f, 360.886f, 3.159050f},
    {543.220f, 313.451f, 360.886f, 0.104720f},
    {543.356f, 329.408f, 360.886f, 6.248280f},
    {543.076f, 247.458f, 360.888f, 6.213370f},
    {543.117f, 232.082f, 360.891f, 0.069813f},
    {543.161f, 305.956f, 360.886f, 0.157080f},
    {543.277f, 321.482f, 360.886f, 0.052360f},
    {543.316f, 337.468f, 360.886f, 6.195920f},
    {543.280f, 239.674f, 360.890f, 6.265730f},
    {543.265f, 217.147f, 360.891f, 0.174533f},
    {543.256f, 224.831f, 360.891f, 0.122173f},
};

class boss_ignis : public CreatureScript
{
    public:
        boss_ignis() : CreatureScript("boss_ignis") { }

        struct boss_ignis_AI : public BossAI
        {
            boss_ignis_AI(Creature* creature) : BossAI(creature, DATA_IGNIS)
            {
                Initialize();
            }

            void Initialize()
            {
                _slagPotGUID.Clear();
                _shattered = false;
                _firstConstructKill = 0;
            }

            void Reset() override
            {
                _Reset();
                if (Vehicle* _vehicle = me->GetVehicleKit())
                    _vehicle->RemoveAllPassengers();

                instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEVEMENT_IGNIS_START_EVENT);
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                Talk(SAY_AGGRO);
                events.ScheduleEvent(EVENT_JET, 30s);
                events.ScheduleEvent(EVENT_SCORCH, 25s);
                events.ScheduleEvent(EVENT_SLAG_POT, 35s);
                events.ScheduleEvent(EVENT_CONSTRUCT, 15s);
                events.ScheduleEvent(EVENT_END_POT, 40s);
                events.ScheduleEvent(EVENT_BERSERK, 480s);
                Initialize();
                instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEVEMENT_IGNIS_START_EVENT);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_SHATTERED)
                    return _shattered ? 1 : 0;

                return 0;
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustSummoned(Creature* summon) override
            {
                if (summon->GetEntry() == NPC_IRON_CONSTRUCT)
                {
                    summon->SetFaction(FACTION_MONSTER_2);
                    summon->SetReactState(REACT_AGGRESSIVE);
                    summon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED | UNIT_FLAG_STUNNED);
                    summon->SetImmuneToPC(false);
                    summon->SetControlled(false, UNIT_STATE_ROOT);
                }

                summon->AI()->AttackStart(me->GetVictim());
                summon->AI()->DoZoneInCombat();
                summons.Summon(summon);
            }

            void DoAction(int32 action) override
            {
                if (action != ACTION_REMOVE_BUFF)
                    return;

                me->RemoveAuraFromStack(SPELL_STRENGHT);
                // Shattered Achievement
                time_t secondKill = GameTime::GetGameTime();
                if ((secondKill - _firstConstructKill) < 5)
                    _shattered = true;
                _firstConstructKill = secondKill;
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
                        case EVENT_JET:
                            Talk(EMOTE_JETS);
                            DoCast(me, SPELL_FLAME_JETS);
                            events.ScheduleEvent(EVENT_JET, 35s, 40s);
                            break;
                        case EVENT_SLAG_POT:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 100, true))
                            {
                                Talk(SAY_SLAG_POT);
                                _slagPotGUID = target->GetGUID();
                                DoCast(target, SPELL_GRAB);
                                events.DelayEvents(3s);
                                events.ScheduleEvent(EVENT_GRAB_POT, 500ms);
                            }
                            events.ScheduleEvent(EVENT_SLAG_POT, RAID_MODE(30s, 15s));
                            break;
                        case EVENT_GRAB_POT:
                            if (Unit* slagPotTarget = ObjectAccessor::GetUnit(*me, _slagPotGUID))
                            {
                                slagPotTarget->EnterVehicle(me, 0);
                                events.CancelEvent(EVENT_GRAB_POT);
                                events.ScheduleEvent(EVENT_CHANGE_POT, 1s);
                            }
                            break;
                        case EVENT_CHANGE_POT:
                            if (Unit* slagPotTarget = ObjectAccessor::GetUnit(*me, _slagPotGUID))
                            {
                                DoCast(slagPotTarget, SPELL_SLAG_POT, true);
                                slagPotTarget->EnterVehicle(me, 1);
                                events.CancelEvent(EVENT_CHANGE_POT);
                                events.ScheduleEvent(EVENT_END_POT, 10s);
                            }
                            break;
                        case EVENT_END_POT:
                            if (Unit* slagPotTarget = ObjectAccessor::GetUnit(*me, _slagPotGUID))
                            {
                                slagPotTarget->ExitVehicle();
                                slagPotTarget = nullptr;
                                _slagPotGUID.Clear();
                                events.CancelEvent(EVENT_END_POT);
                            }
                            break;
                        case EVENT_SCORCH:
                            Talk(SAY_SCORCH);
                            if (Unit* target = me->GetVictim())
                                me->SummonCreature(NPC_GROUND_SCORCH, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 45s);
                            DoCast(SPELL_SCORCH);
                            events.ScheduleEvent(EVENT_SCORCH, 25s);
                            break;
                        case EVENT_CONSTRUCT:
                            Talk(SAY_SUMMON);
                            DoSummon(NPC_IRON_CONSTRUCT, ConstructSpawnPosition[urand(0, CONSTRUCT_SPAWN_POINTS - 1)], 30s, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT);
                            DoCast(SPELL_STRENGHT);
                            DoCast(me, SPELL_ACTIVATE_CONSTRUCT);
                            events.ScheduleEvent(EVENT_CONSTRUCT, RAID_MODE(40s, 30s));
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK, true);
                            Talk(SAY_BERSERK);
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }

        private:
            ObjectGuid _slagPotGUID;
            time_t _firstConstructKill;
            bool _shattered;

        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<boss_ignis_AI>(creature);
        }
};

class npc_iron_construct : public CreatureScript
{
    public:
        npc_iron_construct() : CreatureScript("npc_iron_construct") { }

        struct npc_iron_constructAI : public ScriptedAI
        {
            npc_iron_constructAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
            {
                Initialize();
                creature->SetReactState(REACT_PASSIVE);
            }

            void Initialize()
            {
                _brittled = false;
            }

            void Reset() override
            {
                Initialize();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (me->HasAura(RAID_MODE(SPELL_BRITTLE, SPELL_BRITTLE_25)) && damage >= 5000)
                {
                    DoCast(SPELL_SHATTER);
                    if (Creature* ignis = _instance->GetCreature(DATA_IGNIS))
                        if (ignis->AI())
                            ignis->AI()->DoAction(ACTION_REMOVE_BUFF);

                    me->DespawnOrUnsummon(1s);
                }
            }

            void UpdateAI(uint32 /*uiDiff*/) override
            {
                if (!UpdateVictim())
                    return;

                if (Aura* aur = me->GetAura(SPELL_HEAT))
                {
                    if (aur->GetStackAmount() >= 10)
                    {
                        me->RemoveAura(SPELL_HEAT);
                        DoCast(SPELL_MOLTEN);
                        _brittled = false;
                    }
                }

                // Water pools
                if (me->IsInWater() && !_brittled && me->HasAura(SPELL_MOLTEN))
                {
                    DoCast(SPELL_BRITTLE);
                    me->RemoveAura(SPELL_MOLTEN);
                    _brittled = true;
                }

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* _instance;
            bool _brittled;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_iron_constructAI>(creature);
        }
};

class npc_scorch_ground : public CreatureScript
{
    public:
        npc_scorch_ground() : CreatureScript("npc_scorch_ground") { }

        struct npc_scorch_groundAI : public ScriptedAI
        {
            npc_scorch_groundAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                me->SetControlled(true, UNIT_STATE_ROOT);
                creature->SetDisplayId(16925); //model 2 in db cannot overwrite wdb fields
            }

            void Initialize()
            {
                _heat = false;
                _constructGUID.Clear();
                _heatTimer = 0;
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (!_heat)
                {
                    if (who->GetEntry() == NPC_IRON_CONSTRUCT)
                    {
                        if (!who->HasAura(SPELL_HEAT) || !who->HasAura(SPELL_MOLTEN))
                        {
                            _constructGUID = who->GetGUID();
                            _heat = true;
                        }
                    }
                }
            }

            void Reset() override
            {
                Initialize();
                DoCast(me, SPELL_GROUND);
            }

            void UpdateAI(uint32 uiDiff) override
            {
                if (_heat)
                {
                    if (_heatTimer <= uiDiff)
                    {
                        Creature* construct = ObjectAccessor::GetCreature(*me, _constructGUID);
                        if (construct && !construct->HasAura(SPELL_MOLTEN))
                        {
                            me->AddAura(SPELL_HEAT, construct);
                            _heatTimer = 1000;
                        }
                    }
                    else
                        _heatTimer -= uiDiff;
                }
            }

        private:
            ObjectGuid _constructGUID;
            uint32 _heatTimer;
            bool _heat;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_scorch_groundAI>(creature);
        }
};

// 62717, 63477 - Slag Pot
class spell_ignis_slag_pot : public SpellScriptLoader
{
    public:
        spell_ignis_slag_pot() : SpellScriptLoader("spell_ignis_slag_pot") { }

        class spell_ignis_slag_pot_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_ignis_slag_pot_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SLAG_POT_DAMAGE, SPELL_SLAG_IMBUED });
            }

            void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
            {
                if (Unit* caster = GetCaster())
                {
                    Unit* target = GetTarget();
                    caster->CastSpell(target, SPELL_SLAG_POT_DAMAGE, true);
                }
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget()->IsAlive())
                    GetTarget()->CastSpell(GetTarget(), SPELL_SLAG_IMBUED, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_ignis_slag_pot_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                AfterEffectRemove += AuraEffectRemoveFn(spell_ignis_slag_pot_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_ignis_slag_pot_AuraScript();
        }
};

class achievement_ignis_shattered : public AchievementCriteriaScript
{
    public:
        achievement_ignis_shattered() : AchievementCriteriaScript("achievement_ignis_shattered") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (UnitAI* ai = target ? target->GetAI() : nullptr)
                return ai->GetData(DATA_SHATTERED) != 0;

            return false;
        }
};

void AddSC_boss_ignis()
{
    new boss_ignis();
    new npc_iron_construct();
    new npc_scorch_ground();
    new spell_ignis_slag_pot();
    new achievement_ignis_shattered();
}
