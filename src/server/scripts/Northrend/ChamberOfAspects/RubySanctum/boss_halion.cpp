/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Spell.h"
#include "Vehicle.h"
#include "MapManager.h"
#include "GameObjectAI.h"
#include "ScriptedCreature.h"
#include "ruby_sanctum.h"
#include "Player.h"

/* ScriptData
SDName: ruby_sanctum
SDAuthors: Kaelima, Warpten
SD%Complete: 90%
SDComment: Based on Kaelima's initial work (half of it). Corporeality handling is a pure guess, we lack info.
SDCategory: Chamber of Aspects
EndScriptData */

enum Texts
{
    // Shared
    SAY_REGENERATE                     = 0, // Without pressure in both realms, %s begins to regenerate.

    // Halion
    SAY_INTRO                          = 1, // Meddlesome insects! You are too late. The Ruby Sanctum is lost!
    SAY_AGGRO                          = 2, // Your world teeters on the brink of annihilation. You will ALL bear witness to the coming of a new age of DESTRUCTION!
    SAY_METEOR_STRIKE                  = 3, // The heavens burn!
    SAY_PHASE_TWO                      = 4, // You will find only suffering within the realm of twilight! Enter if you dare!
    SAY_DEATH                          = 5, // Relish this victory, mortals, for it will be your last! This world will burn with the master's return!
    SAY_KILL                           = 6, // Another "hero" falls.
    SAY_BERSERK                        = 7, // Not good enough.
    EMOTE_CORPOREALITY_POT             = 8, // Your efforts force %s further out of the physical realm!
    EMOTE_CORPOREALITY_PIP             = 9, // Your companions' efforts force %s further into the physical realm!

    // Twilight Halion
    SAY_SPHERE_PULSE                   = 1, // Beware the shadow!
    SAY_PHASE_THREE                    = 2, // I am the light and the darkness! Cower, mortals, before the herald of Deathwing!
    EMOTE_CORPOREALITY_TIT             = 3, // Your companions' efforts force %s further into the twilight realm!
    EMOTE_CORPOREALITY_TOT             = 4, // Your efforts force %s further out of the twilight realm!

    EMOTE_WARN_LASER                   = 0, // The orbiting spheres pulse with dark energy!
};

enum Spells
{
    // Halion
    SPELL_FLAME_BREATH                  = 74525,
    SPELL_CLEAVE                        = 74524,
    SPELL_METEOR_STRIKE                 = 74637,
    SPELL_TAIL_LASH                     = 74531,

    SPELL_FIERY_COMBUSTION              = 74562,
    SPELL_MARK_OF_COMBUSTION            = 74567,
    SPELL_FIERY_COMBUSTION_EXPLOSION    = 74607,
    SPELL_FIERY_COMBUSTION_SUMMON       = 74610,

    // Combustion & Consumption
    SPELL_SCALE_AURA                    = 70507, // Aura created in spell_dbc.
    SPELL_COMBUSTION_DAMAGE_AURA        = 74629,
    SPELL_CONSUMPTION_DAMAGE_AURA       = 74803,

    // Twilight Halion
    SPELL_DARK_BREATH                   = 74806,

    SPELL_MARK_OF_CONSUMPTION           = 74795,
    SPELL_SOUL_CONSUMPTION              = 74792,
    SPELL_SOUL_CONSUMPTION_EXPLOSION    = 74799,
    SPELL_SOUL_CONSUMPTION_SUMMON       = 74800,

    // Living Inferno
    SPELL_BLAZING_AURA                  = 75885,

    // Halion Controller
    SPELL_COSMETIC_FIRE_PILLAR          = 76006,
    SPELL_FIERY_EXPLOSION               = 76010,
    SPELL_CLEAR_DEBUFFS                 = 75396,

    // Meteor Strike
    SPELL_METEOR_STRIKE_COUNTDOWN       = 74641,
    SPELL_METEOR_STRIKE_AOE_DAMAGE      = 74648,
    SPELL_METEOR_STRIKE_FIRE_AURA_1     = 74713,
    SPELL_METEOR_STRIKE_FIRE_AURA_2     = 74718,
    SPELL_BIRTH_NO_VISUAL               = 40031,

    // Shadow Orb
    SPELL_TWILIGHT_CUTTER               = 74768, // Unknown dummy effect (EFFECT_0)
    SPELL_TWILIGHT_CUTTER_TRIGGERED     = 74769,
    SPELL_TWILIGHT_PULSE_PERIODIC       = 78861,
    SPELL_TRACK_ROTATION                = 74758,

    // Misc
    SPELL_TWILIGHT_DIVISION             = 75063, // Phase spell from phase 2 to phase 3
    SPELL_LEAVE_TWILIGHT_REALM          = 74812,
    SPELL_TWILIGHT_PHASING              = 74808, // Phase spell from phase 1 to phase 2
    SPELL_SUMMON_TWILIGHT_PORTAL        = 74809, // Summons go 202794
    SPELL_SUMMON_EXIT_PORTALS           = 74805, // Custom spell created in spell_dbc.
    SPELL_TWILIGHT_MENDING              = 75509,
    SPELL_TWILIGHT_REALM                = 74807,
    SPELL_DUSK_SHROUD                   = 75476,
    SPELL_TWILIGHT_PRECISION            = 78243,
    SPELL_COPY_DAMAGE                   = 74810  // Aura not found in DBCs.
};

enum Events
{
    // Halion
    EVENT_ACTIVATE_FIREWALL     = 1,
    EVENT_CLEAVE                = 2,
    EVENT_BREATH                = 3,
    EVENT_METEOR_STRIKE         = 4,
    EVENT_FIERY_COMBUSTION      = 5,
    EVENT_TAIL_LASH             = 6,

    // Twilight Halion
    EVENT_SOUL_CONSUMPTION      = 8,

    // Meteor Strike
    EVENT_SPAWN_METEOR_FLAME    = 9,

    // Halion Controller
    EVENT_START_INTRO           = 10,
    EVENT_INTRO_PROGRESS_1      = 11,
    EVENT_INTRO_PROGRESS_2      = 12,
    EVENT_INTRO_PROGRESS_3      = 13,
    EVENT_CHECK_CORPOREALITY    = 14,
    EVENT_SHADOW_PULSARS_SHOOT  = 15,
    EVENT_TRIGGER_BERSERK       = 16,
    EVENT_TWILIGHT_MENDING      = 17
};

enum Actions
{
    // Meteor Strike
    ACTION_METEOR_STRIKE_BURN   = 1,
    ACTION_METEOR_STRIKE_AOE    = 2,

    // Halion Controller
    ACTION_MONITOR_CORPOREALITY = 3,

    // Orb Carrier
    ACTION_SHOOT                = 4
};

enum Phases
{
    PHASE_ALL           = 0,
    PHASE_INTRO         = 1,
    PHASE_ONE           = 2,
    PHASE_TWO           = 3,
    PHASE_THREE         = 4
};

enum Misc
{
    DATA_TWILIGHT_DAMAGE_TAKEN   = 1,
    DATA_MATERIAL_DAMAGE_TAKEN   = 2,
    DATA_STACKS_DISPELLED        = 3,
    DATA_FIGHT_PHASE             = 4,
    DATA_EVADE_METHOD            = 5
};

enum OrbCarrierSeats
{
    SEAT_NORTH            = 0,
    SEAT_SOUTH            = 1,
    SEAT_EAST             = 2,
    SEAT_WEST             = 3
};

enum CorporealityEvent
{
    CORPOREALITY_NONE               = 0,
    CORPOREALITY_TWILIGHT_MENDING   = 1,
    CORPOREALITY_INCREASE           = 2,
    CORPOREALITY_DECREASE           = 3
};

Position const HalionSpawnPos = {3156.67f, 533.8108f, 72.98822f, 3.159046f};

uint8 const MAX_CORPOREALITY_STATE = 11;

struct CorporealityEntry
{
    uint32 materialRealmSpell;
    uint32 twilightRealmSpell;
};

CorporealityEntry const _corporealityReference[MAX_CORPOREALITY_STATE] = {
    {74836, 74831},
    {74835, 74830},
    {74834, 74829},
    {74833, 74828},
    {74832, 74827},
    {74826, 74826},
    {74827, 74832},
    {74828, 74833},
    {74829, 74834},
    {74830, 74835},
    {74831, 74836}
};

struct generic_halionAI : public BossAI
{
    generic_halionAI(Creature* creature, uint32 bossId) : BossAI(creature, bossId), _canEvade(false) { }

    void EnterCombat(Unit* /*who*/) OVERRIDE
    {
        _EnterCombat();
        me->AddAura(SPELL_TWILIGHT_PRECISION, me);
        _canEvade = false;
        events.ScheduleEvent(EVENT_CLEAVE, urand(8000, 10000));
        events.ScheduleEvent(EVENT_TAIL_LASH, 10000);
        events.ScheduleEvent(EVENT_BREATH, urand(10000, 15000));
    }

    void Reset() OVERRIDE
    {
        _canEvade = false;
        _Reset();
    }

    void JustReachedHome() OVERRIDE
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _JustReachedHome();
    }

    void ExecuteEvent(uint32 eventId) OVERRIDE
    {
        switch (eventId)
        {
            case EVENT_CLEAVE:
                DoCastVictim(SPELL_CLEAVE);
                events.ScheduleEvent(EVENT_CLEAVE, urand(8000, 10000));
                break;
            case EVENT_TAIL_LASH:
                DoCastAOE(SPELL_TAIL_LASH);
                events.ScheduleEvent(EVENT_TAIL_LASH, 10000);
                break;
            case EVENT_BREATH:
                DoCast(me, me->GetEntry() == NPC_HALION ? SPELL_FLAME_BREATH : SPELL_DARK_BREATH);
                events.ScheduleEvent(EVENT_BREATH, urand(10000, 12000));
                break;
        }
    }

    void UpdateAI(uint32 diff) OVERRIDE
    {
        if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
            ExecuteEvent(eventId);

        DoMeleeAttackIfReady();
    }

    void SetData(uint32 index, uint32 dataValue) OVERRIDE
    {
        switch (index)
        {
            case DATA_EVADE_METHOD:
                _canEvade = (dataValue == 1);
                break;
            default:
                break;
        }
    }

    void SpellHit(Unit* /*who*/, SpellInfo const* spellInfo) OVERRIDE
    {
        if (spellInfo->Id == SPELL_TWILIGHT_MENDING)
            Talk(SAY_REGENERATE);
    }

protected:
    bool _canEvade;
};

class boss_halion : public CreatureScript
{
    public:
        boss_halion() : CreatureScript("boss_halion") { }

        struct boss_halionAI : public generic_halionAI
        {
            boss_halionAI(Creature* creature) : generic_halionAI(creature, DATA_HALION)
            {
                me->SetHomePosition(HalionSpawnPos);
            }

            void Reset() OVERRIDE
            {
                generic_halionAI::Reset();
                me->SetReactState(REACT_DEFENSIVE);
                me->RemoveAurasDueToSpell(SPELL_TWILIGHT_PHASING);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }

            void EnterEvadeMode() OVERRIDE
            {
                // Phase 1: We always can evade. Phase 2 & 3: We can evade if and only if the controller tells us to.
                if (events.IsInPhase(PHASE_ONE) || _canEvade)
                    generic_halionAI::EnterEvadeMode();
            }

            void EnterCombat(Unit* who) OVERRIDE
            {
                Talk(SAY_AGGRO);

                events.Reset();
                events.SetPhase(PHASE_ONE);

                generic_halionAI::EnterCombat(who);

                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
                instance->SetBossState(DATA_HALION, IN_PROGRESS);

                events.ScheduleEvent(EVENT_ACTIVATE_FIREWALL, 5000);
                events.ScheduleEvent(EVENT_METEOR_STRIKE, urand(20000, 25000));
                events.ScheduleEvent(EVENT_FIERY_COMBUSTION, urand(15000, 18000));

                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->SetData(DATA_FIGHT_PHASE, PHASE_ONE);
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                _JustDied();

                Talk(SAY_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                if (Creature* twilightHalion = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_TWILIGHT_HALION)))
                    if (twilightHalion->IsAlive())
                        twilightHalion->Kill(twilightHalion);

                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                    if (controller->IsAlive())
                        controller->Kill(controller);
            }

            Position const* GetMeteorStrikePosition() const { return &_meteorStrikePos; }

            void DamageTaken(Unit* attacker, uint32& damage) OVERRIDE
            {
                if (me->HealthBelowPctDamaged(75, damage) && events.IsInPhase(PHASE_ONE))
                {
                    events.SetPhase(PHASE_TWO);
                    Talk(SAY_PHASE_TWO);

                    me->CastStop();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    DoCast(me, SPELL_TWILIGHT_PHASING);

                    if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                        controller->AI()->SetData(DATA_FIGHT_PHASE, PHASE_TWO);
                    return;
                }

                if (events.IsInPhase(PHASE_THREE))
                {
                    // Don't consider copied damage.
                    if (!me->InSamePhase(attacker))
                        return;

                    if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                        controller->AI()->SetData(DATA_MATERIAL_DAMAGE_TAKEN, damage);
                }
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (events.IsInPhase(PHASE_TWO))
                    return;

                // Rough radius, it is not an exactly perfect circle
                if (me->GetDistance2d(HalionControllerSpawnPos.GetPositionX(), HalionControllerSpawnPos.GetPositionY()) > 48.5f)
                {
                    EnterEvadeMode();
                    return;
                }

                generic_halionAI::UpdateAI(diff);
            }

            void ExecuteEvent(uint32 eventId) OVERRIDE
            {
                switch (eventId)
                {
                    case EVENT_ACTIVATE_FIREWALL:
                        // Flame ring is activated 5 seconds after starting encounter, DOOR_TYPE_ROOM is only instant.
                        for (uint8 i = DATA_FLAME_RING; i <= DATA_TWILIGHT_FLAME_RING; ++i)
                            if (GameObject* flameRing = ObjectAccessor::GetGameObject(*me, instance->GetData64(i)))
                                instance->HandleGameObject(instance->GetData64(DATA_FLAME_RING), false, flameRing);
                        break;
                    case EVENT_METEOR_STRIKE:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_TWILIGHT_REALM))
                        {
                            target->GetPosition(&_meteorStrikePos);
                            me->CastSpell(_meteorStrikePos.GetPositionX(), _meteorStrikePos.GetPositionY(), _meteorStrikePos.GetPositionZ(), SPELL_METEOR_STRIKE, true, NULL, NULL, me->GetGUID());
                            Talk(SAY_METEOR_STRIKE);
                        }
                        events.ScheduleEvent(EVENT_METEOR_STRIKE, 40000);
                        break;
                    }
                    case EVENT_FIERY_COMBUSTION:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_TWILIGHT_REALM))
                            DoCast(target, SPELL_FIERY_COMBUSTION);
                        events.ScheduleEvent(EVENT_FIERY_COMBUSTION, 25000);
                        break;
                    }
                    default:
                        generic_halionAI::ExecuteEvent(eventId);
                        break;
                }
            }

            void SetData(uint32 index, uint32 value) OVERRIDE
            {
                switch (index)
                {
                    case DATA_FIGHT_PHASE:
                        events.SetPhase(value);
                        break;
                    default:
                        generic_halionAI::SetData(index, value);
                }
            }

        private:
            Position _meteorStrikePos;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetRubySanctumAI<boss_halionAI>(creature);
        }
};

typedef boss_halion::boss_halionAI HalionAI;

class boss_twilight_halion : public CreatureScript
{
    public:
        boss_twilight_halion() : CreatureScript("boss_twilight_halion") { }

        struct boss_twilight_halionAI : public generic_halionAI
        {
            boss_twilight_halionAI(Creature* creature) : generic_halionAI(creature, DATA_TWILIGHT_HALION)
            {
                Creature* halion = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION));
                if (!halion)
                    return;

                // Using AddAura because no spell cast packet in sniffs.
                halion->AddAura(SPELL_COPY_DAMAGE, me); // We use explicit targeting here to avoid conditions + SPELL_ATTR6_CANT_TARGET_SELF.
                me->AddAura(SPELL_COPY_DAMAGE, halion);
                me->AddAura(SPELL_DUSK_SHROUD, me);

                me->SetHealth(halion->GetHealth());
                me->SetPhaseMask(0x20, true);
                me->SetReactState(REACT_AGGRESSIVE);
            }

            void EnterCombat(Unit* who) OVERRIDE
            {
                events.Reset();
                events.SetPhase(PHASE_TWO);

                generic_halionAI::EnterCombat(who);

                events.ScheduleEvent(EVENT_SOUL_CONSUMPTION, 20000);

                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 2);
            }

            // Never evade
            void EnterEvadeMode() OVERRIDE { }

            void KilledUnit(Unit* victim) OVERRIDE
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);

                // Victims should not be in the Twilight Realm
                me->CastSpell(victim, SPELL_LEAVE_TWILIGHT_REALM, true);
            }

            void JustDied(Unit* killer) OVERRIDE
            {
                if (Creature* halion = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION)))
                {
                    // Ensure looting
                    if (me->IsDamageEnoughForLootingAndReward())
                        halion->LowerPlayerDamageReq(halion->GetMaxHealth());

                    if (halion->IsAlive())
                        killer->Kill(halion);
                }

                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                    if (controller->IsAlive())
                        controller->Kill(controller);

                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void DamageTaken(Unit* attacker, uint32& damage) OVERRIDE
            {
                if (me->HealthBelowPctDamaged(50, damage) && events.IsInPhase(PHASE_TWO))
                {
                    events.SetPhase(PHASE_THREE);
                    me->CastStop();
                    DoCast(me, SPELL_TWILIGHT_DIVISION);
                    Talk(SAY_PHASE_THREE);
                    return;
                }

                if (events.IsInPhase(PHASE_THREE))
                {
                    // Don't consider copied damage.
                    if (!me->InSamePhase(attacker))
                        return;

                    if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                        controller->AI()->SetData(DATA_TWILIGHT_DAMAGE_TAKEN, damage);
                }
            }

            void SpellHit(Unit* who, SpellInfo const* spell) OVERRIDE
            {
                switch (spell->Id)
                {
                    case SPELL_TWILIGHT_DIVISION:
                        if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                            controller->AI()->DoAction(ACTION_MONITOR_CORPOREALITY);
                        break;
                    default:
                        generic_halionAI::SpellHit(who, spell);
                        break;
                }
            }

            void ExecuteEvent(uint32 eventId) OVERRIDE
            {
                switch (eventId)
                {
                    case EVENT_SOUL_CONSUMPTION:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, SPELL_TWILIGHT_REALM))
                            DoCast(target, SPELL_SOUL_CONSUMPTION);
                        events.ScheduleEvent(EVENT_SOUL_CONSUMPTION, 20000);
                        break;
                    default:
                        generic_halionAI::ExecuteEvent(eventId);
                        break;
                }
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetRubySanctumAI<boss_twilight_halionAI>(creature);
        }
};

class npc_halion_controller : public CreatureScript
{
    public:
        npc_halion_controller() : CreatureScript("npc_halion_controller") { }

        struct npc_halion_controllerAI : public ScriptedAI
        {
            npc_halion_controllerAI(Creature* creature) : ScriptedAI(creature),
                _instance(creature->GetInstanceScript()), _summons(me)
            {
                me->SetPhaseMask(me->GetPhaseMask() | 0x20, true);
            }

            void Reset() OVERRIDE
            {
                _summons.DespawnAll();
                _events.Reset();
                _materialCorporealityValue = 5;
                _materialDamageTaken = 0;
                _twilightDamageTaken = 0;

                DoCast(me, SPELL_CLEAR_DEBUFFS);
            }

            void JustSummoned(Creature* who) OVERRIDE
            {
                _summons.Summon(who);
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                _events.Reset();
                _summons.DespawnAll();

                DoCast(me, SPELL_CLEAR_DEBUFFS);
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                _twilightDamageTaken = 0;
                _materialDamageTaken = 0;

                _events.ScheduleEvent(EVENT_TRIGGER_BERSERK, 8 * MINUTE * IN_MILLISECONDS);
            }

            void JustReachedHome() OVERRIDE
            {
                if (Creature* twilightHalion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_TWILIGHT_HALION)))
                    twilightHalion->DespawnOrUnsummon();

                if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION)))
                {
                    halion->AI()->SetData(DATA_EVADE_METHOD, 1);
                    halion->AI()->EnterEvadeMode();
                }

                _instance->SetBossState(DATA_HALION, FAIL);
            }

            void DoAction(int32 action) OVERRIDE
            {
                switch (action)
                {
                    case ACTION_INTRO_HALION:
                        _events.Reset();
                        _events.SetPhase(PHASE_INTRO);
                        _events.ScheduleEvent(EVENT_START_INTRO, 2000);
                        break;
                    case ACTION_MONITOR_CORPOREALITY:
                    {
                        for (uint8 itr = DATA_HALION; itr <= DATA_TWILIGHT_HALION; itr++)
                        {
                            Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(itr));
                            if (!halion)
                                continue;

                            halion->CastSpell(halion, GetSpell(_materialCorporealityValue, itr == DATA_TWILIGHT_HALION), false);
                            halion->AI()->SetData(DATA_FIGHT_PHASE, PHASE_THREE);

                            if (itr == DATA_TWILIGHT_HALION)
                                continue;

                            halion->RemoveAurasDueToSpell(SPELL_TWILIGHT_PHASING);
                            halion->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        }

                        // Summon Twilight portals
                        DoCast(me, SPELL_SUMMON_EXIT_PORTALS);

                        _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_TOGGLE, 1);
                        // Hardcoding doesn't really matter here.
                        _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_MATERIAL, 50);
                        _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_TWILIGHT, 50);

                        _events.ScheduleEvent(EVENT_CHECK_CORPOREALITY, 7500);
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                // The IsInCombat() check is needed because that check should be false when Halion is
                // not engaged, while it would return true without as UpdateVictim() checks for
                // combat state.
                if (!(_events.IsInPhase(PHASE_INTRO)) && me->IsInCombat() && !UpdateVictim())
                {
                    EnterEvadeMode();
                    return;
                }

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_START_INTRO:
                            DoCast(me, SPELL_COSMETIC_FIRE_PILLAR, true);
                            _events.ScheduleEvent(EVENT_INTRO_PROGRESS_1, 4000);
                            break;
                        case EVENT_INTRO_PROGRESS_1:
                            for (uint8 i = DATA_BURNING_TREE_3; i <= DATA_BURNING_TREE_4; ++i)
                                if (GameObject* tree = ObjectAccessor::GetGameObject(*me, _instance->GetData64(i)))
                                    _instance->HandleGameObject(_instance->GetData64(i), true, tree);
                            _events.ScheduleEvent(EVENT_INTRO_PROGRESS_2, 4000);
                            break;
                        case EVENT_INTRO_PROGRESS_2:
                            for (uint8 i = DATA_BURNING_TREE_1; i <= DATA_BURNING_TREE_2; ++i)
                                if (GameObject* tree = ObjectAccessor::GetGameObject(*me, _instance->GetData64(i)))
                                    _instance->HandleGameObject(_instance->GetData64(i), true, tree);
                            _events.ScheduleEvent(EVENT_INTRO_PROGRESS_3, 4000);
                            break;
                        case EVENT_INTRO_PROGRESS_3:
                            DoCast(me, SPELL_FIERY_EXPLOSION);
                            if (Creature* halion = me->GetMap()->SummonCreature(NPC_HALION, HalionSpawnPos))
                                halion->AI()->Talk(SAY_INTRO);
                            break;
                        case EVENT_TWILIGHT_MENDING:
                            if (ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION))) // Just check if physical Halion is spawned
                                if (Creature* twilightHalion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_TWILIGHT_HALION)))
                                    twilightHalion->CastSpell((Unit*)NULL, SPELL_TWILIGHT_MENDING, true);
                            break;
                        case EVENT_TRIGGER_BERSERK:
                            for (uint8 i = DATA_HALION; i <= DATA_TWILIGHT_HALION; i++)
                                if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(i)))
                                    halion->CastSpell(halion, SPELL_BERSERK, true);
                            break;
                        case EVENT_SHADOW_PULSARS_SHOOT:
                            if (Creature* twilightHalion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_TWILIGHT_HALION)))
                                twilightHalion->AI()->Talk(SAY_SPHERE_PULSE);

                            if (Creature* orbCarrier = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ORB_CARRIER)))
                                orbCarrier->AI()->DoAction(ACTION_SHOOT);

                            _events.ScheduleEvent(EVENT_SHADOW_PULSARS_SHOOT, 29000);
                            break;
                        case EVENT_CHECK_CORPOREALITY:
                            UpdateCorporeality();
                            _events.ScheduleEvent(EVENT_CHECK_CORPOREALITY, 5000);
                            break;
                        default:
                            break;
                    }
                }
            }

            void SetData(uint32 id, uint32 value) OVERRIDE
            {
                switch (id)
                {
                    case DATA_MATERIAL_DAMAGE_TAKEN:
                        _materialDamageTaken += value;
                        break;
                    case DATA_TWILIGHT_DAMAGE_TAKEN:
                        _twilightDamageTaken += value;
                        break;
                    case DATA_FIGHT_PHASE:
                        _events.SetPhase(value);
                        switch (value)
                        {
                            case PHASE_ONE:
                                DoZoneInCombat();
                                break;
                            case PHASE_TWO:
                                _events.ScheduleEvent(EVENT_SHADOW_PULSARS_SHOOT, 29000);
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }
            }

        private:
            //// @todo Find out a better scaling, if any.
            // [0   , 0.98[: Corporeality goes down
            // [0.98, 0.99]: Do nothing
            // ]0.99, 1.01[: Twilight Mending
            // [1.01, 1.02]: Do nothing
            // ]1.02, +oo [: Corporeality goes up
            void UpdateCorporeality()
            {
                uint8 oldValue = _materialCorporealityValue;
                if (_twilightDamageTaken == 0 || _materialDamageTaken == 0)
                {
                    _events.ScheduleEvent(EVENT_TWILIGHT_MENDING, 100);
                    _twilightDamageTaken = 0;
                    _materialDamageTaken = 0;
                    return;
                }

                float damageRatio = float(_materialDamageTaken) / float(_twilightDamageTaken);

                CorporealityEvent action = CORPOREALITY_NONE;
                if (damageRatio < 0.98f)                             // [0   , 0.98[: Corporeality goes down
                    action = CORPOREALITY_DECREASE;
                else if (0.99f < damageRatio && damageRatio < 1.01f) // ]0.99, 1.01[: Twilight Mending
                    action = CORPOREALITY_TWILIGHT_MENDING;
                else if (1.02f < damageRatio)                        // ]1.02, +oo [: Corporeality goes up
                    action = CORPOREALITY_INCREASE;

                switch (action)
                {
                    case CORPOREALITY_NONE:
                    {
                        _materialDamageTaken = 0;
                        _twilightDamageTaken = 0;
                        return;
                    }
                    case CORPOREALITY_INCREASE:
                    {
                        if (_materialCorporealityValue >= (MAX_CORPOREALITY_STATE - 1))
                            return;
                        ++_materialCorporealityValue;
                        break;
                    }
                    case CORPOREALITY_DECREASE:
                    {
                        if (_materialCorporealityValue <= 0)
                            return;
                        --_materialCorporealityValue;
                        break;
                    }
                    case CORPOREALITY_TWILIGHT_MENDING:
                    {
                        _events.ScheduleEvent(EVENT_TWILIGHT_MENDING, 100);
                        _materialDamageTaken = 0;
                        _twilightDamageTaken = 0;
                        return;
                    }
                }

                _materialDamageTaken = 0;
                _twilightDamageTaken = 0;

                _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_MATERIAL, _materialCorporealityValue * 10);
                _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_TWILIGHT, 100 - _materialCorporealityValue * 10);

                for (uint8 itr = DATA_HALION; itr <= DATA_TWILIGHT_HALION; itr++)
                {
                    if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(itr)))
                    {
                        RemoveCorporeality(halion, itr == DATA_TWILIGHT_HALION);
                        halion->CastSpell(halion, GetSpell(_materialCorporealityValue, itr == DATA_TWILIGHT_HALION), true);

                        if (itr == DATA_TWILIGHT_HALION)
                            halion->AI()->Talk(oldValue < _materialCorporealityValue ? EMOTE_CORPOREALITY_TOT : EMOTE_CORPOREALITY_TIT, halion);
                        else // if (itr == DATA_HALION)
                            halion->AI()->Talk(oldValue > _materialCorporealityValue ? EMOTE_CORPOREALITY_POT : EMOTE_CORPOREALITY_PIP, halion);
                    }
                }
            }

            void RemoveCorporeality(Creature* who, bool isTwilight = false)
            {
                for (uint8 i = 0; i < MAX_CORPOREALITY_STATE; i++)
                {
                    uint32 spellID = (isTwilight ? _corporealityReference[i].twilightRealmSpell : _corporealityReference[i].materialRealmSpell);
                    if (who->HasAura(spellID))
                    {
                        who->RemoveAurasDueToSpell(spellID);
                        break;
                    }
                }
            }

            uint32 GetSpell(uint8 pctValue, bool isTwilight = false) const
            {
                CorporealityEntry entry = _corporealityReference[pctValue];
                return isTwilight ? entry.twilightRealmSpell : entry.materialRealmSpell;
            }

            EventMap _events;
            InstanceScript* _instance;
            SummonList _summons;

            uint32 _twilightDamageTaken;
            uint32 _materialDamageTaken;
            uint8 _materialCorporealityValue;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetRubySanctumAI<npc_halion_controllerAI>(creature);
        }
};

typedef npc_halion_controller::npc_halion_controllerAI controllerAI;

class npc_orb_carrier : public CreatureScript
{
    public:
        npc_orb_carrier() : CreatureScript("npc_orb_carrier") { }

        struct npc_orb_carrierAI : public ScriptedAI
        {
            npc_orb_carrierAI(Creature* creature) : ScriptedAI(creature),
                instance(creature->GetInstanceScript())
            {
                ASSERT(creature->GetVehicleKit());
            }

            void UpdateAI(uint32 /*diff*/) OVERRIDE
            {
                /// According to sniffs this spell is cast every 1 or 2 seconds.
                /// However, refreshing it looks bad, so just cast the spell if
                /// we are not channeling it.
                if (!me->HasUnitState(UNIT_STATE_CASTING))
                    me->CastSpell((Unit*)NULL, SPELL_TRACK_ROTATION, false);

                /// Workaround: This is here because even though the above spell has SPELL_ATTR1_CHANNEL_TRACK_TARGET,
                /// we are having two creatures involded here. This attribute is handled clientside, meaning the client
                /// sends orientation update itself. Here, no packet is sent, and the creature does not rotate. By
                /// forcing the carrier to always be facing the rotation focus, we ensure everything works as it should.
                if (Creature* rotationFocus = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_ORB_ROTATION_FOCUS)))
                    me->SetFacingToObject(rotationFocus); // setInFront
            }

            void DoAction(int32 action) OVERRIDE
            {
                if (action == ACTION_SHOOT)
                {
                    Vehicle* vehicle = me->GetVehicleKit();
                    Unit* southOrb = vehicle->GetPassenger(SEAT_SOUTH);
                    Unit* northOrb = vehicle->GetPassenger(SEAT_NORTH);
                    if (southOrb && northOrb)
                    {
                        if (northOrb->GetTypeId() == TYPEID_UNIT)
                            northOrb->ToCreature()->AI()->Talk(EMOTE_WARN_LASER);
                        TriggerCutter(northOrb, southOrb);
                    }

                    if (!IsHeroic())
                        return;

                    Unit* eastOrb = vehicle->GetPassenger(SEAT_EAST);
                    Unit* westOrb = vehicle->GetPassenger(SEAT_WEST);
                    if (eastOrb && westOrb)
                        TriggerCutter(eastOrb, westOrb);
                }
            }
        private:
            InstanceScript* instance;

            void TriggerCutter(Unit* caster, Unit* target)
            {
                caster->CastSpell(caster, SPELL_TWILIGHT_PULSE_PERIODIC, true);
                target->CastSpell(target, SPELL_TWILIGHT_PULSE_PERIODIC, true);
                caster->CastSpell(target, SPELL_TWILIGHT_CUTTER, false);
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetRubySanctumAI<npc_orb_carrierAI>(creature);
        }
};

class npc_meteor_strike_initial : public CreatureScript
{
    public:
        npc_meteor_strike_initial() : CreatureScript("npc_meteor_strike_initial") { }

        struct npc_meteor_strike_initialAI : public ScriptedAI
        {
            npc_meteor_strike_initialAI(Creature* creature) : ScriptedAI(creature),
                _instance(creature->GetInstanceScript())
            {
                SetCombatMovement(false);
            }

            void DoAction(int32 action) OVERRIDE
            {
                switch (action)
                {
                    case ACTION_METEOR_STRIKE_AOE:
                        DoCast(me, SPELL_METEOR_STRIKE_AOE_DAMAGE, true);
                        DoCast(me, SPELL_METEOR_STRIKE_FIRE_AURA_1, true);
                        for (std::list<Creature*>::iterator itr = _meteorList.begin(); itr != _meteorList.end(); ++itr)
                            (*itr)->AI()->DoAction(ACTION_METEOR_STRIKE_BURN);
                        break;
                }
            }

            void IsSummonedBy(Unit* summoner) OVERRIDE
            {
                Creature* owner = summoner->ToCreature();
                if (!owner)
                    return;

                // Let Halion Controller count as summoner
                if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->JustSummoned(me);

                DoCast(me, SPELL_METEOR_STRIKE_COUNTDOWN);
                DoCast(me, SPELL_BIRTH_NO_VISUAL); // Unknown purpose

                if (HalionAI* halionAI = CAST_AI(HalionAI, owner->AI()))
                {
                    Position const* ownerPos = halionAI->GetMeteorStrikePosition();
                    Position newPos;
                    float angle[4];
                    angle[0] = me->GetAngle(ownerPos);
                    angle[1] = me->GetAngle(ownerPos) - static_cast<float>(M_PI/2);
                    angle[2] = me->GetAngle(ownerPos) - static_cast<float>(-M_PI/2);
                    angle[3] = me->GetAngle(ownerPos) - static_cast<float>(M_PI);

                    _meteorList.clear();
                    for (uint8 i = 0; i < 4; i++)
                    {
                        angle[i] = Position::NormalizeOrientation(angle[i]);
                        me->SetOrientation(angle[i]);
                        me->GetNearPosition(newPos, 10.0f, 0.0f); // Exact distance
                        if (Creature* meteor = me->SummonCreature(NPC_METEOR_STRIKE_NORTH + i, newPos, TEMPSUMMON_TIMED_DESPAWN, 30000))
                            _meteorList.push_back(meteor);
                    }
                }
            }

            void UpdateAI(uint32 /*diff*/) OVERRIDE { }
            void EnterEvadeMode() OVERRIDE { }
        private:
            InstanceScript* _instance;
            std::list<Creature*> _meteorList;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetRubySanctumAI<npc_meteor_strike_initialAI>(creature);
        }
};

class npc_meteor_strike : public CreatureScript
{
    public:
        npc_meteor_strike() : CreatureScript("npc_meteor_strike") { }

        struct npc_meteor_strikeAI : public ScriptedAI
        {
            npc_meteor_strikeAI(Creature* creature) : ScriptedAI(creature),
                _instance(creature->GetInstanceScript())
            {
                _range = 5.0f;
                _spawnCount = 0;

                SetCombatMovement(false);
            }

            void DoAction(int32 action) OVERRIDE
            {
                if (action == ACTION_METEOR_STRIKE_BURN)
                {
                    DoCast(me, SPELL_METEOR_STRIKE_FIRE_AURA_2, true);
                    me->setActive(true);
                    _events.ScheduleEvent(EVENT_SPAWN_METEOR_FLAME, 500);
                }
            }

            void IsSummonedBy(Unit* /*summoner*/) OVERRIDE
            {
                // Let Halion Controller count as summoner.
                if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->JustSummoned(me);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (_spawnCount > 5)
                    return;

                _events.Update(diff);

                if (_events.ExecuteEvent() == EVENT_SPAWN_METEOR_FLAME)
                {
                    Position pos;
                    me->GetNearPosition(pos, _range, 0.0f);

                    if (Creature* flame = me->SummonCreature(NPC_METEOR_STRIKE_FLAME, pos, TEMPSUMMON_TIMED_DESPAWN, 25000))
                    {
                        if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                            controller->AI()->JustSummoned(flame);

                        flame->CastSpell(flame, SPELL_METEOR_STRIKE_FIRE_AURA_2, true);
                        ++_spawnCount;
                    }
                    _range += 5.0f;
                    _events.ScheduleEvent(EVENT_SPAWN_METEOR_FLAME, 800);
                }
            }

        private:
            InstanceScript* _instance;
            EventMap _events;
            float _range;
            uint8 _spawnCount;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetRubySanctumAI<npc_meteor_strikeAI>(creature);
        }
};

class npc_combustion_consumption : public CreatureScript
{
    public:
        npc_combustion_consumption() : CreatureScript("npc_combustion_consumption") { }

        struct npc_combustion_consumptionAI : public ScriptedAI
        {
            npc_combustion_consumptionAI(Creature* creature) : ScriptedAI(creature),
                   _instance(creature->GetInstanceScript()), _summonerGuid(0)
            {
                SetCombatMovement(false);

                switch (me->GetEntry())
                {
                    case NPC_COMBUSTION:
                        _explosionSpell = SPELL_FIERY_COMBUSTION_EXPLOSION;
                        _damageSpell = SPELL_COMBUSTION_DAMAGE_AURA;
                        me->SetPhaseMask(0x01, true);
                        break;
                    case NPC_CONSUMPTION:
                        _explosionSpell = SPELL_SOUL_CONSUMPTION_EXPLOSION;
                        _damageSpell = SPELL_CONSUMPTION_DAMAGE_AURA;
                        me->SetPhaseMask(0x20, true);
                        break;
                    default: // Should never happen
                        _explosionSpell = 0;
                        _damageSpell = 0;
                        break;
                }

                if (IsHeroic())
                    me->SetPhaseMask(0x01 | 0x20, true);
            }

            void IsSummonedBy(Unit* summoner) OVERRIDE
            {
                // Let Halion Controller count as summoner
                if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->JustSummoned(me);

                _summonerGuid = summoner->GetGUID();
            }

            void SetData(uint32 type, uint32 stackAmount) OVERRIDE
            {
                Unit* summoner = ObjectAccessor::GetUnit(*me, _summonerGuid);

                if (type != DATA_STACKS_DISPELLED || !_damageSpell || !_explosionSpell || !summoner)
                    return;

                me->CastCustomSpell(SPELL_SCALE_AURA, SPELLVALUE_AURA_STACK, stackAmount, me);
                DoCast(me, _damageSpell);

                int32 damage = 1200 + (stackAmount * 1290); // Needs more researches.
                summoner->CastCustomSpell(_explosionSpell, SPELLVALUE_BASE_POINT0, damage, summoner);
            }

            void UpdateAI(uint32 /*diff*/) OVERRIDE { }

        private:
            InstanceScript* _instance;
            uint32 _explosionSpell;
            uint32 _damageSpell;
            uint64 _summonerGuid;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetRubySanctumAI<npc_combustion_consumptionAI>(creature);
        }
};

class npc_living_inferno : public CreatureScript
{
    public:
        npc_living_inferno() : CreatureScript("npc_living_inferno") { }

        struct npc_living_infernoAI : public ScriptedAI
        {
            npc_living_infernoAI(Creature* creature) : ScriptedAI(creature) { }

            void IsSummonedBy(Unit* /*summoner*/) OVERRIDE
            {
                me->SetInCombatWithZone();
                me->CastSpell(me, SPELL_BLAZING_AURA, true);

                if (InstanceScript* instance = me->GetInstanceScript())
                    if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                        controller->AI()->JustSummoned(me);
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                me->DespawnOrUnsummon(1);
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetRubySanctumAI<npc_living_infernoAI>(creature);
        }
};

//! Need sniff data
class npc_living_ember : public CreatureScript
{
    public:
        npc_living_ember() : CreatureScript("npc_living_ember") { }

        struct npc_living_emberAI : public ScriptedAI
        {
            npc_living_emberAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() OVERRIDE
            {
                _hasEnraged = false;
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                _enrageTimer = 20000;
                _hasEnraged = false;
            }

            void IsSummonedBy(Unit* /*summoner*/) OVERRIDE
            {
                if (InstanceScript* instance = me->GetInstanceScript())
                    if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                        controller->AI()->JustSummoned(me);
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                me->DespawnOrUnsummon(1);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (!_hasEnraged && _enrageTimer <= diff)
                {
                    _hasEnraged = true;
                    DoCast(me, SPELL_BERSERK);
                }
                else _enrageTimer -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            uint32 _enrageTimer;
            bool _hasEnraged;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetRubySanctumAI<npc_living_emberAI>(creature);
        }
};

class go_twilight_portal : public GameObjectScript
{
    public:
        go_twilight_portal() : GameObjectScript("go_twilight_portal") { }

        struct go_twilight_portalAI : public GameObjectAI
        {
            go_twilight_portalAI(GameObject* gameobject) : GameObjectAI(gameobject),
                _instance(gameobject->GetInstanceScript()), _deleted(false)
            {
                switch (gameobject->GetEntry())
                {
                    case GO_HALION_PORTAL_EXIT:
                        gameobject->SetPhaseMask(0x20, true);
                        _spellId = gameobject->GetGOInfo()->goober.spellId;
                        break;
                    case GO_HALION_PORTAL_1:
                    case GO_HALION_PORTAL_2: // Not used, not seen in sniffs. Just in case.
                        gameobject->SetPhaseMask(0x1, true);
                        /// Because WDB template has non-existent spell ID, not seen in sniffs either, meh
                        _spellId = SPELL_TWILIGHT_REALM;
                        break;
                    default:
                        _spellId = 0;
                        break;
                }
            }

            bool GossipHello(Player* player) OVERRIDE
            {
                if (_spellId != 0)
                    player->CastSpell(player, _spellId, true);
                return true;
            }

            void UpdateAI(uint32 /*diff*/) OVERRIDE
            {
                if (_instance->GetBossState(DATA_HALION) == IN_PROGRESS)
                    return;

                if (!_deleted)
                {
                    _deleted = true;
                    go->Delete();
                }
            }

        private:
            InstanceScript* _instance;
            uint32 _spellId;
            bool _deleted;
        };

        GameObjectAI* GetAI(GameObject* gameobject) const OVERRIDE
        {
            return GetRubySanctumAI<go_twilight_portalAI>(gameobject);
        }
};

class spell_halion_meteor_strike_marker : public SpellScriptLoader
{
    public:
        spell_halion_meteor_strike_marker() : SpellScriptLoader("spell_halion_meteor_strike_marker") { }

        class spell_halion_meteor_strike_marker_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_meteor_strike_marker_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetCaster())
                    return;

                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                    if (Creature* creCaster = GetCaster()->ToCreature())
                        creCaster->AI()->DoAction(ACTION_METEOR_STRIKE_AOE);
            }

            void Register() OVERRIDE
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_meteor_strike_marker_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_halion_meteor_strike_marker_AuraScript();
        }
};

class spell_halion_combustion_consumption : public SpellScriptLoader
{
    public:
        spell_halion_combustion_consumption(char const* scriptName, uint32 spell) : SpellScriptLoader(scriptName), _spellID(spell) { }

        class spell_halion_combustion_consumption_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_combustion_consumption_AuraScript);

        public:
            spell_halion_combustion_consumption_AuraScript(uint32 spellID) : AuraScript(), _markSpell(spellID) { }

            bool Validate(SpellInfo const* /*spell*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(_markSpell))
                    return false;
                return true;
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_DEATH)
                    return;

                if (GetTarget()->HasAura(_markSpell))
                    GetTarget()->RemoveAurasDueToSpell(_markSpell, 0, 0, AURA_REMOVE_BY_EXPIRE);
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->CastSpell(GetTarget(), _markSpell, true);
            }

            void AddMarkStack(AuraEffect const* /*aurEff*/)
            {
                GetTarget()->CastSpell(GetTarget(), _markSpell, true);
            }

            void Register() OVERRIDE
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_halion_combustion_consumption_AuraScript::AddMarkStack, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
                AfterEffectApply += AuraEffectApplyFn(spell_halion_combustion_consumption_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_combustion_consumption_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }

            uint32 _markSpell;
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_halion_combustion_consumption_AuraScript(_spellID);
        }

    private:
        uint32 _spellID;
};

class spell_halion_marks : public SpellScriptLoader
{
    public:
        spell_halion_marks(char const* scriptName, uint32 summonSpell, uint32 removeSpell) : SpellScriptLoader(scriptName),
            _summonSpell(summonSpell), _removeSpell(removeSpell) { }

        class spell_halion_marks_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_marks_AuraScript);

        public:
            spell_halion_marks_AuraScript(uint32 summonSpell, uint32 removeSpell) : AuraScript(),
                _summonSpellId(summonSpell), _removeSpellId(removeSpell) { }

            bool Validate(SpellInfo const* /*spell*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(_summonSpellId))
                    return false;
                return true;
            }

            /// We were purged. Force removed stacks to zero and trigger the appropriated remove handler.
            void BeforeDispel(DispelInfo* dispelData)
            {
                // Prevent any stack from being removed at this point.
                dispelData->SetRemovedCharges(0);

                if (Unit* dispelledUnit = GetUnitOwner())
                    if (dispelledUnit->HasAura(_removeSpellId))
                        dispelledUnit->RemoveAurasDueToSpell(_removeSpellId, 0, 0, AURA_REMOVE_BY_EXPIRE);
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
                    return;

                // Stacks marker
                GetTarget()->CastCustomSpell(_summonSpellId, SPELLVALUE_BASE_POINT1, aurEff->GetBase()->GetStackAmount(), GetTarget(), TRIGGERED_FULL_MASK, NULL, NULL, GetCasterGUID());
            }

            void Register() OVERRIDE
            {
                OnDispel += AuraDispelFn(spell_halion_marks_AuraScript::BeforeDispel);
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_marks_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }

            uint32 _summonSpellId;
            uint32 _removeSpellId;
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_halion_marks_AuraScript(_summonSpell, _removeSpell);
        }

    private:
        uint32 _summonSpell;
        uint32 _removeSpell;
};

class spell_halion_damage_aoe_summon : public SpellScriptLoader
{
    public:
        spell_halion_damage_aoe_summon() : SpellScriptLoader("spell_halion_damage_aoe_summon") { }

        class spell_halion_damage_aoe_summon_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_damage_aoe_summon_SpellScript);

            void HandleSummon(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                Unit* caster = GetCaster();
                uint32 entry = uint32(GetSpellInfo()->Effects[effIndex].MiscValue);
                SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(uint32(GetSpellInfo()->Effects[effIndex].MiscValueB));
                uint32 duration = uint32(GetSpellInfo()->GetDuration());

                Position pos;
                caster->GetPosition(&pos);
                if (Creature* summon = caster->GetMap()->SummonCreature(entry, pos, properties, duration, caster, GetSpellInfo()->Id))
                    if (summon->IsAIEnabled)
                        summon->AI()->SetData(DATA_STACKS_DISPELLED, GetSpellValue()->EffectBasePoints[EFFECT_1]);
            }

            void Register() OVERRIDE
            {
                OnEffectHit += SpellEffectFn(spell_halion_damage_aoe_summon_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_halion_damage_aoe_summon_SpellScript();
        }
};

class spell_halion_twilight_realm_handlers : public SpellScriptLoader
{
    public:
        spell_halion_twilight_realm_handlers(const char* scriptName, uint32 beforeHitSpell, bool isApplyHandler) : SpellScriptLoader(scriptName),
            _beforeHitSpell(beforeHitSpell), _isApplyHandler(isApplyHandler)
        { }

        class spell_halion_twilight_realm_handlers_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_twilight_realm_handlers_AuraScript);

        public:
            spell_halion_twilight_realm_handlers_AuraScript(uint32 beforeHitSpell, bool isApplyHandler) : AuraScript(),
                _isApply(isApplyHandler), _beforeHitSpellId(beforeHitSpell)
            { }

            bool Validate(SpellInfo const* /*spell*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(_beforeHitSpellId))
                    return false;
                return true;
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*handle*/)
            {
                GetTarget()->RemoveAurasDueToSpell(SPELL_TWILIGHT_REALM);
                if (InstanceScript* instance = GetTarget()->GetInstanceScript())
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_UNK7);
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*handle*/)
            {
                Unit* target = GetTarget();
                if (!target)
                    return;

                target->RemoveAurasDueToSpell(_beforeHitSpellId, 0, 0, AURA_REMOVE_BY_ENEMY_SPELL);
                if (InstanceScript* instance = target->GetInstanceScript())
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_UNK7);
            }

            void Register() OVERRIDE
            {
                if (!_isApply)
                {
                    AfterEffectApply += AuraEffectApplyFn(spell_halion_twilight_realm_handlers_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                    AfterEffectRemove += AuraEffectRemoveFn(spell_halion_twilight_realm_handlers_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                }
                else
                    AfterEffectApply += AuraEffectApplyFn(spell_halion_twilight_realm_handlers_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PHASE, AURA_EFFECT_HANDLE_REAL);
            }

            bool _isApply;
            uint32 _beforeHitSpellId;
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_halion_twilight_realm_handlers_AuraScript(_beforeHitSpell, _isApplyHandler);
        }

    private:
        uint32 _beforeHitSpell;
        bool _isApplyHandler;
};

class spell_halion_clear_debuffs : public SpellScriptLoader
{
    public:
        spell_halion_clear_debuffs() : SpellScriptLoader("spell_halion_clear_debuffs") { }

        class spell_halion_clear_debuffs_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_clear_debuffs_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_CLEAR_DEBUFFS))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_TWILIGHT_REALM))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                if (GetHitUnit()->HasAura(GetSpellInfo()->Effects[effIndex].CalcValue()))
                    GetHitUnit()->RemoveAurasDueToSpell(GetSpellInfo()->Effects[effIndex].CalcValue());
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_halion_clear_debuffs_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_halion_clear_debuffs_SpellScript();
        }
};

class TwilightCutterSelector
{
    public:
        TwilightCutterSelector(Unit* caster, Unit* target) : _caster(caster), _channelTarget(target) { }

        bool operator()(WorldObject* unit)
        {
            return !unit->IsInBetween(_caster, _channelTarget, 4.0f);
        }

    private:
        Unit* _caster;
        Unit* _channelTarget;
};

class spell_halion_twilight_cutter : public SpellScriptLoader
{
    public:
        spell_halion_twilight_cutter() : SpellScriptLoader("spell_halion_twilight_cutter") { }

        class spell_halion_twilight_cutter_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_twilight_cutter_SpellScript);

            void RemoveNotBetween(std::list<WorldObject*>& unitList)
            {
                if (unitList.empty())
                    return;

                Unit* caster = GetCaster();
                if (Unit* channelTarget = ObjectAccessor::GetUnit(*caster, caster->GetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT)))
                {
                    unitList.remove_if(TwilightCutterSelector(caster, channelTarget));
                    return;
                }

                // In case cutter caster werent found for some reason
                unitList.clear();
            }

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_halion_twilight_cutter_SpellScript::RemoveNotBetween, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_halion_twilight_cutter_SpellScript();
        }
};

class spell_halion_twilight_phasing : public SpellScriptLoader
{
    public:
        spell_halion_twilight_phasing() : SpellScriptLoader("spell_halion_twilight_phasing") { }

        class spell_halion_twilight_phasing_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_twilight_phasing_SpellScript);

            void Phase()
            {
                Unit* caster = GetCaster();
                caster->CastSpell(caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), SPELL_SUMMON_TWILIGHT_PORTAL, true);
                caster->GetMap()->SummonCreature(NPC_TWILIGHT_HALION, HalionSpawnPos);
            }

            void Register() OVERRIDE
            {
                OnHit += SpellHitFn(spell_halion_twilight_phasing_SpellScript::Phase);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_halion_twilight_phasing_SpellScript();
        }
};

// 74805 - Summon Exit Portals
class spell_halion_summon_exit_portals : public SpellScriptLoader
{
    public:
        spell_halion_summon_exit_portals() : SpellScriptLoader("spell_halion_summon_exit_portals") { }

        class spell_halion_summon_exit_portals_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_summon_exit_portals_SpellScript);

            void SetDest0(SpellDestination& dest)
            {
                Position const offset = { 0.0f, 20.0f, 0.0f, 0.0f };
                dest.RelocateOffset(offset);
            }

            void SetDest1(SpellDestination& dest)
            {
                Position const offset = { 0.0f, -20.0f, 0.0f, 0.0f };
                dest.RelocateOffset(offset);
            }

            void Register() OVERRIDE
            {
                OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_halion_summon_exit_portals_SpellScript::SetDest0, EFFECT_0, TARGET_DEST_CASTER);
                OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_halion_summon_exit_portals_SpellScript::SetDest1, EFFECT_1, TARGET_DEST_CASTER);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_halion_summon_exit_portals_SpellScript();
        }
};

void AddSC_boss_halion()
{
    new boss_halion();
    new boss_twilight_halion();

    new npc_halion_controller();
    new npc_meteor_strike_initial();
    new npc_meteor_strike();
    new npc_combustion_consumption();
    new npc_orb_carrier();
    new npc_living_inferno();
    new npc_living_ember();

    new go_twilight_portal();

    new spell_halion_meteor_strike_marker();
    new spell_halion_combustion_consumption("spell_halion_soul_consumption", SPELL_MARK_OF_CONSUMPTION);
    new spell_halion_combustion_consumption("spell_halion_fiery_combustion", SPELL_MARK_OF_COMBUSTION);
    new spell_halion_marks("spell_halion_mark_of_combustion", SPELL_FIERY_COMBUSTION_SUMMON, SPELL_FIERY_COMBUSTION);
    new spell_halion_marks("spell_halion_mark_of_consumption", SPELL_SOUL_CONSUMPTION_SUMMON, SPELL_SOUL_CONSUMPTION);
    new spell_halion_damage_aoe_summon();
    new spell_halion_twilight_realm_handlers("spell_halion_leave_twilight_realm", SPELL_SOUL_CONSUMPTION, false);
    new spell_halion_twilight_realm_handlers("spell_halion_enter_twilight_realm", SPELL_FIERY_COMBUSTION, true);
    new spell_halion_summon_exit_portals();
    new spell_halion_twilight_phasing();
    new spell_halion_twilight_cutter();
    new spell_halion_clear_debuffs();
}
