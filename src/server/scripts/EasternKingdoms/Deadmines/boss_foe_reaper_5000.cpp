/*
* Copyright (C) 2008-2018 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "deadmines.h"

enum Texts
{
    // Foe Reaper 5000
    SAY_ON_LINE                         = 0,
    SAY_ANNOUNCE_OVERDRIVE              = 1,
    SAY_OVERDRIVE                       = 2,
    SAY_HARVEST_ACQUIRING_TARGET        = 3,
    SAY_HARVEST                         = 4,
    SAY_SAFETY_RESTRICTIONS_OFFLINE     = 5,
    SAY_ANNOUNCE_RESTRICTIONS_OFFLINE   = 6,
    SAY_SLAY                            = 7,
    SAY_DEATH                           = 8,

    // General Purpose Bunny
    SAY_ANNOUNCE_FOUNDRY_DISRUPTED      = 0,
    SAY_ANNOUNCE_MOLTEN_SLAG            = 1
};

enum Spells
{
    // Foe Reaper 5000
    SPELL_ENERGIZE                      = 89132,
    SPELL_ON_LINE                       = 89198,
    SPELL_RED_EYES                      = 24263,
    SPELL_ON_LINE_2                     = 89121,
    SPELL_REAPER_STRIKE                 = 88490,
    SPELL_OVERDRIVE                     = 88481,
    SPELL_ACQUIRING_TARGET              = 88492,
    SPELL_HARVEST                       = 88497,
    SPELL_HARVEST_SWEEP                 = 88521,
    SPELL_SAFETY_RESTRICTIONS_OFFLINE   = 88522,

    // General Purpose Bunny
    SPELL_SUMMON_MOLTEN_SLAG_1          = 91839,
    SPELL_SUMMON_MOLTEN_SLAG_2          = 91841,
    SPELL_SUMMON_MOLTEN_SLAG_3          = 91842,
    SPELL_SUMMON_MOLTEN_SLAG_4          = 91843,

    // Molten Slag
    SPELL_MOLTEN_SHIELD                 = 91815,
    SPELL_FIXATE_TARGETING              = 91831,

    // Player
    SPELL_FIXATE_TAUNT                  = 91829
};

uint32 randomSlagSpells[] =
{
    SPELL_SUMMON_MOLTEN_SLAG_1,
    SPELL_SUMMON_MOLTEN_SLAG_2,
    SPELL_SUMMON_MOLTEN_SLAG_3,
    SPELL_SUMMON_MOLTEN_SLAG_4
};

enum Events
{
    // Foe Reaper 5000
    EVENT_ON_LINE = 1,
    EVENT_RED_EYES,
    EVENT_ON_LINE_2,
    EVENT_ANNOUNCE_DISRUPTING_FOUNDRY,
    EVENT_ANNOUNCE_MOLTEN_SLAG,
    EVENT_SUMMON_MOLTEN_SLAG,
    EVENT_OVERDRIVE,
    EVENT_MOVE_OVERDRIVE,
    EVENT_END_OVERDRIVE,
    EVENT_ACQUIRING_TARGET,
    EVENT_HARVEST,
    EVENT_HARVEST_SWEEP,
    EVENT_ANNOUNCE_SAFETY_RESTRICTIONS_OFFLINE,

    // Molten Slag
    EVENT_MOLTEN_SHIELD,
    EVENT_FIXATE_PLAYER
};

enum Phases
{
    PHASE_INTRO = 1,
    PHASE_1     = 2,
};

enum Points
{
    POINT_MOVE_OVERDRIVE    = 1,
    POINT_MOVE_HARVEST      = 2
};

class boss_foe_reaper_5000 : public CreatureScript
{
    public:
        boss_foe_reaper_5000() : CreatureScript("boss_foe_reaper_5000") { }

        struct boss_foe_reaper_5000AI : public BossAI
        {
            boss_foe_reaper_5000AI(Creature* creature) : BossAI(creature, DATA_FOE_REAPER_5000)
            {
                me->setPowerType(POWER_ENERGY);
                me->SetMaxPower(POWER_ENERGY, 100);
                Initialize();
            }

            void Initialize()
            {
                _safetyRestrictionsOffline = false;
            }

            void Reset() override
            {
                _Reset();
                Initialize();
                if (!instance->GetData(DATA_FOE_REAPER_INTRO))
                    events.SetPhase(PHASE_INTRO);
                else
                {
                    me->RemoveAurasDueToSpell(SPELL_OFF_LINE);
                    {
                        DoCast(me, SPELL_RED_EYES, true);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED | UNIT_FLAG_IMMUNE_TO_PC);
                    }
                }
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();
                events.SetPhase(PHASE_1);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_OVERDRIVE, Seconds(9));
                events.ScheduleEvent(EVENT_ACQUIRING_TARGET, Seconds(35));
                if (IsHeroic())
                {
                    events.ScheduleEvent(EVENT_ANNOUNCE_DISRUPTING_FOUNDRY, Seconds(4));
                    events.ScheduleEvent(EVENT_ANNOUNCE_MOLTEN_SLAG, Seconds(6) + Milliseconds(400));
                    events.ScheduleEvent(EVENT_SUMMON_MOLTEN_SLAG, Seconds(17));
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
                summons.DespawnAll();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                if (IsHeroic())
                    if (Creature* prototypeReaper = instance->GetCreature(DATA_PROTOTYPE_REAPER))
                        prototypeReaper->DespawnOrUnsummon(0);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                summons.DespawnAll();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                if (IsHeroic())
                    if (Creature* prototypeReaper = instance->GetCreature(DATA_PROTOTYPE_REAPER))
                        prototypeReaper->DespawnOrUnsummon(0, Seconds(30));
                _DespawnAtEvade();
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);

                if (summon->GetEntry() == NPC_FOE_REAPER_TARGETING_BUNNY)
                {
                    me->StopMoving();
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFacingToObject(summon);

                }
            }

            void MovementInform(uint32 type, uint32 point) override
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (point)
                {
                    case POINT_MOVE_OVERDRIVE:
                        events.ScheduleEvent(EVENT_MOVE_OVERDRIVE, Seconds(1));
                        break;
                    case POINT_MOVE_HARVEST:
                        me->RemoveAurasDueToSpell(SPELL_HARVEST);
                        events.ScheduleEvent(EVENT_HARVEST_SWEEP, Seconds(1));
                        break;
                    default:
                        break;
                }
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
            {
                switch (spell->Id)
                {
                    case SPELL_ENERGIZE:
                        if (me->GetPower(POWER_ENERGY) == 100)
                        {
                            instance->SetData(DATA_FOE_REAPER_INTRO, DONE);
                            events.ScheduleEvent(EVENT_ON_LINE, Seconds(3));
                        }
                        break;
                    case SPELL_OVERDRIVE:
                        Talk(SAY_OVERDRIVE);
                        me->AttackStop();
                        me->SetReactState(REACT_PASSIVE);
                        events.ScheduleEvent(EVENT_MOVE_OVERDRIVE, Seconds(2));
                        events.ScheduleEvent(EVENT_END_OVERDRIVE, Seconds(10));
                        break;
                    case SPELL_HARVEST:
                        Talk(SAY_HARVEST);
                        events.ScheduleEvent(EVENT_HARVEST, Seconds(2));
                        break;
                    default:
                        break;
                }
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case 0:
                        break;
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
            {
                if (me->HealthBelowPct(30) && !_safetyRestrictionsOffline)
                {
                    Talk(SAY_SAFETY_RESTRICTIONS_OFFLINE);
                    DoCastSelf(SPELL_SAFETY_RESTRICTIONS_OFFLINE, true);
                    events.ScheduleEvent(EVENT_ANNOUNCE_SAFETY_RESTRICTIONS_OFFLINE, Seconds(3) + Milliseconds(800));
                    _safetyRestrictionsOffline = true;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && !events.IsInPhase(PHASE_INTRO))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ON_LINE:
                            DoCastSelf(SPELL_ON_LINE);
                            events.ScheduleEvent(EVENT_RED_EYES, Seconds(8) + Milliseconds(400));
                            break;
                        case EVENT_RED_EYES:
                            DoCastSelf(SPELL_RED_EYES, true);
                            events.ScheduleEvent(EVENT_ON_LINE_2, Seconds(2) + Milliseconds(400));
                            break;
                        case EVENT_ON_LINE_2:
                            me->RemoveAurasDueToSpell(SPELL_OFF_LINE);
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED | UNIT_FLAG_IMMUNE_TO_PC);
                            DoCastSelf(SPELL_ON_LINE_2, true);
                            Talk(SAY_ON_LINE);
                            break;
                        case EVENT_ANNOUNCE_DISRUPTING_FOUNDRY:
                            if (Creature* bunny = me->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 100.0f, true))
                                bunny->AI()->Talk(SAY_ANNOUNCE_FOUNDRY_DISRUPTED);
                            break;
                        case EVENT_ANNOUNCE_MOLTEN_SLAG:
                            if (Creature* bunny = me->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 100.0f, true))
                                bunny->AI()->Talk(SAY_ANNOUNCE_MOLTEN_SLAG);
                            break;
                        case EVENT_SUMMON_MOLTEN_SLAG:
                        {
                            uint8 i = RAND(0, 3);
                            if (Creature* bunny = me->FindNearestCreature(NPC_GENERAL_PURPOSE_DUMMY_JMF, 100.0f, true))
                                bunny->CastSpell(bunny, randomSlagSpells[i], true);
                            events.Repeat(Seconds(21), Seconds(22));
                            break;
                        }
                        case EVENT_OVERDRIVE:
                            DoCastSelf(SPELL_OVERDRIVE);
                            Talk(SAY_ANNOUNCE_OVERDRIVE);
                            events.Repeat(Seconds(53));
                            break;
                        case EVENT_MOVE_OVERDRIVE:
                        {
                            // Let's just copy the random movement generator part here except we are walking
                            // and use our own position instead of our home position
                            float respX, respY, respZ, respO, destX, destY, destZ, travelDistZ;
                            me->GetPosition(respX, respY, respZ, respO);
                            Map const* map = me->GetMap();
                            const float angle = float(rand_norm()) * static_cast<float>(M_PI * 2.0f);
                            const float range = 15.0f;
                            const float distanceX = range * std::cos(angle);
                            const float distanceY = range * std::sin(angle);
                            destX = respX + distanceX;
                            destY = respY + distanceY;
                            Trinity::NormalizeMapCoord(destX);
                            Trinity::NormalizeMapCoord(destY);
                            travelDistZ = 10.0f;
                            destZ = map->GetHeight(me->GetPhaseShift(), destX, destY, respZ + travelDistZ - 2.0f, false);
                            if (std::fabs(destZ - respZ) > travelDistZ)
                            {
                                destZ = map->GetHeight(me->GetPhaseShift(), destX, destY, respZ - 2.0f, true);

                                if (std::fabs(destZ - respZ) > travelDistZ)
                                {
                                    destZ = map->GetHeight(me->GetPhaseShift(), destX, destY, respZ + travelDistZ - 2.0f, true);

                                    if (std::fabs(destZ - respZ) > travelDistZ)
                                        return;
                                }
                            }
                            me->GetMotionMaster()->MovePoint(POINT_MOVE_OVERDRIVE, destX, destY, destZ, true);
                            break;
                        }
                        case EVENT_END_OVERDRIVE:
                            me->GetMotionMaster()->Clear();
                            me->SetReactState(REACT_AGGRESSIVE);
                            me->AI()->AttackStart(me->GetVictim());
                            events.CancelEvent(EVENT_MOVE_OVERDRIVE);
                            break;
                        case EVENT_ACQUIRING_TARGET:
                            Talk(SAY_HARVEST_ACQUIRING_TARGET);
                            DoCastAOE(SPELL_ACQUIRING_TARGET, true);
                            events.Repeat(Seconds(55));
                            break;
                        case EVENT_HARVEST:
                            if (Creature* bunny = instance->GetCreature(DATA_FOE_REAPER_BUNNY))
                                me->GetMotionMaster()->MovePoint(POINT_MOVE_HARVEST, bunny->GetPosition(), true);
                            break;
                        case EVENT_HARVEST_SWEEP:
                            DoCastAOE(SPELL_HARVEST_SWEEP);
                            me->setAttackTimer(BASE_ATTACK, me->GetFloatValue(UNIT_FIELD_BASEATTACKTIME));
                            summons.DespawnEntry(NPC_FOE_REAPER_TARGETING_BUNNY);
                            me->SetReactState(REACT_AGGRESSIVE);
                            me->AI()->AttackStart(me->GetVictim());
                            break;
                        case EVENT_ANNOUNCE_SAFETY_RESTRICTIONS_OFFLINE:
                            Talk(SAY_ANNOUNCE_RESTRICTIONS_OFFLINE);
                            break;
                        default:
                            break;
                    }
                }

                DoSpellAttackIfReady(SPELL_REAPER_STRIKE);
            }
        private:
            bool _safetyRestrictionsOffline;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetDeadminesAI<boss_foe_reaper_5000AI>(creature);
        }
};

class npc_foe_reaper_5000_molten_slag : public CreatureScript
{
    public:
        npc_foe_reaper_5000_molten_slag() : CreatureScript("npc_foe_reaper_5000_molten_slag") { }

        struct npc_foe_reaper_5000_molten_slagAI : public ScriptedAI
        {
            npc_foe_reaper_5000_molten_slagAI(Creature* creature) : ScriptedAI(creature) { }

            void InitializeAI() override
            {
                me->SetReactState(REACT_PASSIVE);
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                DoZoneInCombat();
                _events.ScheduleEvent(EVENT_MOLTEN_SHIELD, Seconds(3));
                _events.ScheduleEvent(EVENT_FIXATE_PLAYER, Seconds(3));
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->DespawnOrUnsummon(Seconds(5));
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MOLTEN_SHIELD:
                            DoCastSelf(SPELL_MOLTEN_SHIELD, true);
                            me->SetReactState(REACT_AGGRESSIVE);
                            me->SetInCombatWithZone();
                            break;
                        case EVENT_FIXATE_PLAYER:
                            DoCastAOE(SPELL_FIXATE_TARGETING, true);
                            _events.Repeat(Seconds(12));
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetDeadminesAI<npc_foe_reaper_5000_molten_slagAI>(creature);
        }
};

class spell_foe_reaper_5000_acquire_target : public SpellScriptLoader
{
    public:
        spell_foe_reaper_5000_acquire_target() : SpellScriptLoader("spell_foe_reaper_5000_acquire_target") { }

        class spell_foe_reaper_5000_acquire_target_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foe_reaper_5000_acquire_target_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foe_reaper_5000_acquire_target_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_foe_reaper_5000_acquire_target_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foe_reaper_5000_acquire_target_SpellScript();
        }
};

class FixateTargetingCheck
{
    public:
        FixateTargetingCheck() { }

        bool operator()(WorldObject* object)
        {
            if (Unit* unit = object->ToUnit())
                if ((unit->GetEntry() == NPC_PROTOTYPE_REAPER && unit->IsCharmedOwnedByPlayerOrPlayer()) || unit->GetTypeId() == TYPEID_PLAYER)
                    return false;

            return true;
        }
};

class spell_foe_reaper_5000_fixate_targeting : public SpellScriptLoader
{
    public:
        spell_foe_reaper_5000_fixate_targeting() : SpellScriptLoader("spell_foe_reaper_5000_fixate_targeting") { }

        class spell_foe_reaper_5000_fixate_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foe_reaper_5000_fixate_targeting_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(FixateTargetingCheck());

                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_foe_reaper_5000_fixate_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_foe_reaper_5000_fixate_targeting_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foe_reaper_5000_fixate_targeting_SpellScript();
        }
};

class spell_foe_reaper_5000_fixate : public SpellScriptLoader
{
    public:
        spell_foe_reaper_5000_fixate() : SpellScriptLoader("spell_foe_reaper_5000_fixate") { }

        class spell_foe_reaper_5000_fixate_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_foe_reaper_5000_fixate_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_FIXATE_TAUNT });
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                    GetHitUnit()->CastSpell(caster, SPELL_FIXATE_TAUNT, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_foe_reaper_5000_fixate_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_foe_reaper_5000_fixate_SpellScript();
        }
};

void AddSC_boss_foe_reaper_5000()
{
    new boss_foe_reaper_5000();
    new npc_foe_reaper_5000_molten_slag();
    new spell_foe_reaper_5000_acquire_target();
    new spell_foe_reaper_5000_fixate_targeting();
    new spell_foe_reaper_5000_fixate();
}
