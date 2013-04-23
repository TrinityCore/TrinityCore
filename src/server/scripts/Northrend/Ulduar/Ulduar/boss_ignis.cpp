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
#include "ulduar.h"
#include "Vehicle.h"

enum Yells
{
    SAY_AGGRO       = 0,
    SAY_SLAY        = 1,
    SAY_DEATH       = 2,
    SAY_SUMMON      = 3,
    SAY_SLAG_POT    = 4,
    SAY_SCORCH      = 5,
    SAY_BERSERK     = 6,
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
    SPELL_STRENGTH              = 64473,
    SPELL_GRAB                  = 62707,
    SPELL_BERSERK               = 47008,
    SPELL_GRAB_ENTER_VEHICLE    = 62711,    

    // Iron Construct
    SPELL_HEAT                  = 65667,
    SPELL_MOLTEN                = 62373,
    SPELL_BRITTLE_10            = 62382,
    SPELL_BRITTLE_25            = 67114,
    SPELL_SHATTER               = 62383,
    SPELL_GROUND                = 62548,
    SPELL_FREEZE_ANIM           = 63354
};

#define SPELL_BRITTLE RAID_MODE(SPELL_BRITTLE_10, SPELL_BRITTLE_25)

enum Events
{
    EVENT_JET           = 1,
    EVENT_SCORCH        = 2,
    EVENT_SLAG_POT      = 3,
    EVENT_GRAB_POT      = 4,
    EVENT_CHANGE_POT    = 5,
    EVENT_END_POT       = 6,
    EVENT_CONSTRUCT     = 7,
    EVENT_BERSERK       = 8
};

enum Actions
{
    ACTION_REMOVE_BUFF = 20
};

enum Creatures
{
    NPC_IRON_CONSTRUCT  = 33121,
    NPC_GROUND_SCORCH   = 33221
};

enum AchievementData
{
    DATA_SHATTERED                      = 29252926,
    ACHIEVEMENT_IGNIS_START_EVENT       = 20951,
    ACHIEVEMENT_SHATTERED_TIME_LIMIT    = 5*IN_MILLISECONDS
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
    {543.256f, 224.831f, 360.891f, 0.122173f}
};

/* 
    TODO: 
    - Shatter Achievement (2925/2926)
*/

class AchievShatterHelper
{
    public:
        explicit AchievShatterHelper(const uint64 timeLimit) : gotInformed(false), achievFulfilled(false), timer(0), limit(timeLimit) {}

        // Called when an Iron Construct got Shattered
        void Inform()
        {
            if (achievFulfilled)
                return; // Nothing to be done

            if (gotInformed)                // Check if timer is ok
            {
                if (timer <= limit)
                    achievFulfilled = true;
            }
            else                            // First information, start tracking
            {
                gotInformed = true;
                timer = 0;
            }
        }

        void Reset()
        {
            gotInformed = achievFulfilled = false;
            timer = 0;
        }

        // Updated by boss script
        void Update(uint32 diff)
        {
            if (achievFulfilled || !gotInformed)    // Nothing to be done if achievement got already fulfilled, or tracking was not started yet.
                return;

            timer += diff;
            if (timer > limit)  // Check timeout
            {
                gotInformed = false;
                timer = 0;
            }
        }

        bool GotAchievFulfilled() const
        {
            return achievFulfilled;
        }
    private:        
        bool gotInformed;       // Starts time-tracking
        bool achievFulfilled;   // Set if achievement was completed successfully
        const uint64 limit;     // Time-limit, set on construction
        uint64 timer;           // Current timer
};

class boss_ignis : public CreatureScript
{
    public:
        boss_ignis() : CreatureScript("boss_ignis") { }

        struct boss_ignis_AI : public BossAI
        {
            boss_ignis_AI(Creature* creature) : BossAI(creature, BOSS_IGNIS), vehicle(me->GetVehicleKit()), shatteredHelper(ACHIEVEMENT_SHATTERED_TIME_LIMIT)
            {
                ASSERT(vehicle);
            }

            void Reset()
            {
                _Reset();
                if (vehicle)
                    vehicle->RemoveAllPassengers();

                summons.DespawnAll();
                shatteredHelper.Reset();

                for (uint8 i = 0; i < CONSTRUCT_SPAWN_POINTS; i++)
                    if (Creature* construct = me->SummonCreature(NPC_IRON_CONSTRUCT, ConstructSpawnPosition[i]))
                        summons.Summon(construct);

                instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEVEMENT_IGNIS_START_EVENT);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                events.ScheduleEvent(EVENT_JET, 30*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SCORCH, 25*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SLAG_POT, 35*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_CONSTRUCT, 15*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_END_POT, 40*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_BERSERK, 8*MINUTE*IN_MILLISECONDS);
                slagPotGUID = 0;
                instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEVEMENT_IGNIS_START_EVENT);
            }

            void JustDied(Unit* /*victim*/)
            {
                _JustDied();
                Talk(SAY_DEATH);
                if (shatteredHelper.GotAchievFulfilled())
                {
                    instance->DoCompleteAchievement(RAID_MODE(2925,2926));
                }
            }

            void SummonedCreatureDespawn(Creature* summon)      // Gets called then an Iron Construct despawns through its own script
            {
                if (summon->GetEntry() == NPC_IRON_CONSTRUCT)
                    summons.Despawn(summon);
            }
            
            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)
            {
                if (summon->GetEntry() == NPC_IRON_CONSTRUCT)
                    summons.Despawn(summon);
            }

            uint32 GetData(uint32 type) const
            {
                if (type == DATA_SHATTERED)
                    return shatteredHelper.GotAchievFulfilled() ? 1 : 0;

                return 0;
            }

            void KilledUnit(Unit* /*victim*/)
            {
                if (!urand(0,5))
                    Talk(SAY_SLAY);
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_REMOVE_BUFF: // Action is called every time a construct is shattered.
                        me->RemoveAuraFromStack(SPELL_STRENGTH);
                        // Shattered Achievement - testing stage
                        shatteredHelper.Inform();
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                shatteredHelper.Update(diff);
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
                            events.DelayEvents(5*IN_MILLISECONDS);   // Cast time
                            events.ScheduleEvent(EVENT_JET, urand(35*IN_MILLISECONDS, 40*IN_MILLISECONDS));
                            return;
                        case EVENT_SLAG_POT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                            {
                                Talk(SAY_SLAG_POT);
                                slagPotGUID = target->GetGUID();
                                DoCast(target, SPELL_GRAB);
                                events.DelayEvents(3*IN_MILLISECONDS);
                                events.ScheduleEvent(EVENT_GRAB_POT, 0.5*IN_MILLISECONDS);
                            }
                            events.ScheduleEvent(EVENT_SLAG_POT, RAID_MODE(30*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            return;
                        case EVENT_GRAB_POT:
                            if (Unit* slagPotTarget = ObjectAccessor::GetUnit(*me, slagPotGUID))
                            {
                                slagPotTarget->EnterVehicle(me, 1);
                                events.ScheduleEvent(EVENT_CHANGE_POT, 1*IN_MILLISECONDS);
                            }
                            return;
                        case EVENT_CHANGE_POT:
                            if (Unit* slagPotTarget = ObjectAccessor::GetUnit(*me, slagPotGUID))
                            {
                                slagPotTarget->EnterVehicle(me, 1);
                                slagPotTarget->ClearUnitState(UNIT_STATE_ONVEHICLE);
                                DoCast(slagPotTarget, SPELL_SLAG_POT);
                                events.ScheduleEvent(EVENT_END_POT, 10*IN_MILLISECONDS);
                            }
                            return;
                        case EVENT_END_POT:
                            if (Unit* slagPotTarget = ObjectAccessor::GetUnit(*me, slagPotGUID))
                            {
                                slagPotTarget->ExitVehicle();
                                slagPotGUID = 0;
                            }
                            return;
                        case EVENT_SCORCH:
                            Talk(SAY_SCORCH);
                            if (Unit* target = me->getVictim())
                                me->SummonCreature(NPC_GROUND_SCORCH, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 45*IN_MILLISECONDS);
                            DoCast(SPELL_SCORCH);
                            events.ScheduleEvent(EVENT_SCORCH, 25*IN_MILLISECONDS);
                            return;
                        case EVENT_CONSTRUCT:
                            if (!summons.empty())
                            {
                                Talk(SAY_SUMMON);
                                DoCast(me, SPELL_ACTIVATE_CONSTRUCT);
                                events.ScheduleEvent(EVENT_CONSTRUCT, RAID_MODE(40*IN_MILLISECONDS, 30*IN_MILLISECONDS));
                            }
                            return;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK, true);
                            Talk(SAY_BERSERK);
                            return;
                        default:
                            return;
                    }
                }

                DoMeleeAttackIfReady();

                EnterEvadeIfOutOfCombatArea(diff);
            }

            private:
                AchievShatterHelper shatteredHelper;
                uint64 slagPotGUID;
                Vehicle* vehicle;
        };

        CreatureAI* GetAI(Creature* creature) const
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
            npc_iron_constructAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript())
            {
                creature->setActive(true);
                creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED | UNIT_FLAG_DISABLE_MOVE);
                DoCast(me, SPELL_FREEZE_ANIM, true);
            }

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
                brittled = false;
            }

            void JustReachedHome()
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED | UNIT_FLAG_DISABLE_MOVE);
                DoCast(me, SPELL_FREEZE_ANIM, true);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                if (me->HasAura(SPELL_BRITTLE) && damage >= 5*IN_MILLISECONDS)
                {
                    DoCast(SPELL_SHATTER);
                    if (Creature* ignis = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_IGNIS)))
                        if (ignis->AI())
                            ignis->AI()->DoAction(ACTION_REMOVE_BUFF);

                    me->DespawnOrUnsummon(1*IN_MILLISECONDS);
                }
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
            {
                if (spell->Id == SPELL_ACTIVATE_CONSTRUCT)
                {
                    me->RemoveAurasDueToSpell(SPELL_FREEZE_ANIM);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED | UNIT_FLAG_DISABLE_MOVE);
                    me->AI()->DoZoneInCombat();
                    if (Creature* ignis = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_IGNIS)))
                    {
                        me->AI()->AttackStart(ignis->getVictim());
                        ignis->CastSpell(ignis, SPELL_STRENGTH, true);
                    }
                }
            }

            void UpdateAI(uint32 /*uiDiff*/)
            {
                if (!UpdateVictim())
                    return;

                if (Aura* aur = me->GetAura(SPELL_HEAT))
                {
                    if (aur->GetStackAmount() >= 10)
                    {
                        me->RemoveAura(SPELL_HEAT);
                        DoCast(SPELL_MOLTEN);
                        brittled = false;
                    }
                }

                // Water pools
                if (me->IsInWater() && !brittled && me->HasAura(SPELL_MOLTEN))
                {
                    DoCast(SPELL_BRITTLE);
                    me->RemoveAura(SPELL_MOLTEN);
                    brittled = true;
                }

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* instance;
            bool brittled;
        };

        CreatureAI* GetAI(Creature* creature) const
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
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE |UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                creature->SetDisplayId(16925); //model 2 in db cannot overwrite wdb fields
            }

            void MoveInLineOfSight(Unit* unit)
            {
                if (!heat)
                {
                    if (unit->GetEntry() == NPC_IRON_CONSTRUCT)
                    {
                        if (!unit->HasAura(SPELL_HEAT) || !unit->HasAura(SPELL_MOLTEN))
                        {
                            constructGUID = unit->GetGUID();
                            heat = true;
                        }
                    }
                }
            }

            void Reset()
            {
                heat = false;
                DoCast(me, SPELL_GROUND);
                constructGUID = 0;
                heatTimer = 0;
            }

            void UpdateAI(uint32 uiDiff)
            {
                if (heat)
                {
                    if (heatTimer <= uiDiff)
                    {
                        Creature* construct = me->GetCreature(*me, constructGUID);
                        if (construct && !construct->HasAura(SPELL_MOLTEN))
                        {
                            me->AddAura(SPELL_HEAT, construct);
                            heatTimer = 1*IN_MILLISECONDS;
                        }
                    }
                    else
                        heatTimer -= uiDiff;
                }
            }

        private:
            uint64 constructGUID;
            uint32 heatTimer;
            bool heat;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetUlduarAI<npc_scorch_groundAI>(creature);
        }
};

class spell_ignis_slag_pot : public SpellScriptLoader
{
    public:
        spell_ignis_slag_pot() : SpellScriptLoader("spell_ignis_slag_pot") { }

        class spell_ignis_slag_pot_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_ignis_slag_pot_AuraScript);

            bool Validate(SpellInfo const* /*spellEntry*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SLAG_POT_DAMAGE))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_SLAG_IMBUED))
                    return false;
                return true;
            }

            void HandleEffectPeriodic(AuraEffect const* aurEff)
            {
                Unit* aurEffCaster = aurEff->GetCaster();
                if (!aurEffCaster)
                    return;

                Unit* target = GetTarget();
                aurEffCaster->CastSpell(target, SPELL_SLAG_POT_DAMAGE, true);
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget()->isAlive())
                    GetTarget()->CastSpell(GetTarget(), SPELL_SLAG_IMBUED, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_ignis_slag_pot_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                AfterEffectRemove += AuraEffectRemoveFn(spell_ignis_slag_pot_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_ignis_slag_pot_AuraScript();
        }
};

// Selector removes targets that are neither player not pets
class spell_ignis_flame_jets : public SpellScriptLoader
{
    public:
        spell_ignis_flame_jets() : SpellScriptLoader("spell_ignis_flame_jets") { }

        class spell_ignis_flame_jets_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ignis_flame_jets_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(PlayerOrPetCheck());
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ignis_flame_jets_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ignis_flame_jets_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ignis_flame_jets_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_ignis_flame_jets_SpellScript();
        }
};

class spell_ignis_activate_construct : public SpellScriptLoader
{
    public:
        spell_ignis_activate_construct() : SpellScriptLoader("spell_ignis_activate_construct") {}

        class spell_ignis_activate_construct_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ignis_activate_construct_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (WorldObject* _target = Trinity::Containers::SelectRandomContainerElement(targets))
                {
                    targets.clear();
                    targets.push_back(_target);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ignis_activate_construct_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_ignis_activate_construct_SpellScript();
        }
};

class achievement_ignis_shattered : public AchievementCriteriaScript
{
    public:
        achievement_ignis_shattered() : AchievementCriteriaScript("achievement_ignis_shattered") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (target && target->IsAIEnabled)
                return target->GetAI()->GetData(DATA_SHATTERED);

            return false;
        }
};

void AddSC_boss_ignis()
{
    new boss_ignis();
    new npc_iron_construct();
    new npc_scorch_ground();
    new spell_ignis_slag_pot();
    new spell_ignis_flame_jets();
    new achievement_ignis_shattered();
    new spell_ignis_activate_construct();
}

#undef SPELL_BRITTLE 
