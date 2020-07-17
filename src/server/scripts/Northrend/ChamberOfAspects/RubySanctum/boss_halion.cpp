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
#include "DB2Stores.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ruby_sanctum.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

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

    EMOTE_WARN_LASER                   = 0  // The orbiting spheres pulse with dark energy!
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
    SPELL_SPAWN_LIVING_EMBERS           = 75880,
    SPELL_SUMMON_LIVING_EMBER           = 75881,

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
    SPELL_SUMMON_EXIT_PORTALS           = 74805, // Custom spell created in spell_dbc. // Used in Cataclysm, need a sniff of cata and up
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
    EVENT_SOUL_CONSUMPTION      = 7,

    // Meteor Strike
    EVENT_SPAWN_METEOR_FLAME    = 8,

    // Halion Controller
    EVENT_START_INTRO           = 9,
    EVENT_INTRO_PROGRESS_1      = 10,
    EVENT_INTRO_PROGRESS_2      = 11,
    EVENT_INTRO_PROGRESS_3      = 12,
    EVENT_CHECK_CORPOREALITY    = 13,
    EVENT_SHADOW_PULSARS_SHOOT  = 14,
    EVENT_TRIGGER_BERSERK       = 15,
    EVENT_TWILIGHT_MENDING      = 16,
    EVENT_ACTIVATE_EMBERS       = 17,
    EVENT_EVADE_CHECK           = 18
};

enum Actions
{
    // Meteor Strike
    ACTION_METEOR_STRIKE_BURN   = 1,
    ACTION_METEOR_STRIKE_AOE    = 2,

    // Halion Controller
    ACTION_MONITOR_CORPOREALITY = 3,

    // Orb Carrier
    ACTION_WARNING_SHOOT        = 4,
    ACTION_SHOOT                = 5,
    ACTION_ACTIVATE_EMBERS      = 6
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
    DATA_SPAWNED_FLAMES          = 5
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
Position const HalionRespawnPos = {3156.625f, 533.2674f, 72.97205f, 0.0f};

uint8 const MAX_CORPOREALITY_STATE = 11;

struct CorporealityEntry
{
    uint32 twilightRealmSpell;
    uint32 materialRealmSpell;
};

CorporealityEntry const _corporealityReference[MAX_CORPOREALITY_STATE] =
{
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

class boss_halion : public CreatureScript
{
    public:
        boss_halion() : CreatureScript("boss_halion") { }

        struct boss_halionAI : public BossAI
        {
            boss_halionAI(Creature* creature) : BossAI(creature, DATA_HALION) { }

            void EnterEvadeMode(EvadeReason why) override
            {
                if (why == EVADE_REASON_BOUNDARY || events.IsInPhase(PHASE_ONE))
                    if (Creature* controller = instance->GetCreature(DATA_HALION_CONTROLLER))
                        controller->AI()->EnterEvadeMode(why);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);

                events.Reset();
                events.SetPhase(PHASE_ONE);

                _EnterCombat();
                me->AddAura(SPELL_TWILIGHT_PRECISION, me);
                events.ScheduleEvent(EVENT_ACTIVATE_FIREWALL, Seconds(5));
                events.ScheduleEvent(EVENT_BREATH, randtime(Seconds(5), Seconds(15)));
                events.ScheduleEvent(EVENT_CLEAVE, randtime(Seconds(6), Seconds(10)));
                events.ScheduleEvent(EVENT_TAIL_LASH, randtime(Seconds(7), Seconds(12)));
                events.ScheduleEvent(EVENT_FIERY_COMBUSTION, randtime(Seconds(15), Seconds(18)));
                events.ScheduleEvent(EVENT_METEOR_STRIKE, Seconds(18));

                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

                if (Creature* controller = instance->GetCreature(DATA_HALION_CONTROLLER))
                    controller->AI()->SetData(DATA_FIGHT_PHASE, PHASE_ONE);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                Talk(SAY_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

                if (Creature* twilightHalion = instance->GetCreature(DATA_TWILIGHT_HALION))
                    if (twilightHalion->IsAlive())
                        twilightHalion->KillSelf();

                if (Creature* controller = instance->GetCreature(DATA_HALION_CONTROLLER))
                    if (controller->IsAlive())
                        controller->KillSelf();
            }

            Position const* GetMeteorStrikePosition() const { return &_meteorStrikePos; }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (me->HealthBelowPctDamaged(75, damage) && events.IsInPhase(PHASE_ONE))
                {
                    events.SetPhase(PHASE_TWO);
                    Talk(SAY_PHASE_TWO);

                    me->CastStop();
                    me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                    DoCastSelf(SPELL_TWILIGHT_PHASING);

                    if (Creature* controller = instance->GetCreature(DATA_HALION_CONTROLLER))
                        controller->AI()->SetData(DATA_FIGHT_PHASE, PHASE_TWO);
                    return;
                }

                if (events.IsInPhase(PHASE_THREE))
                {
                    // Don't consider copied damage.
                    if (!me->IsInPhase(attacker))
                        return;

                    if (Creature* controller = instance->GetCreature(DATA_HALION_CONTROLLER))
                        controller->AI()->SetData(DATA_MATERIAL_DAMAGE_TAKEN, damage);
                }
            }

            void SpellHit(Unit* /*who*/, SpellInfo const* spellInfo) override
            {
                if (spellInfo->Id == SPELL_TWILIGHT_MENDING)
                    Talk(SAY_REGENERATE);
            }

            void UpdateAI(uint32 diff) override
            {
                if (events.IsInPhase(PHASE_TWO))
                    return;

                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CLEAVE, randtime(Seconds(8), Seconds(10)));
                            break;
                        case EVENT_TAIL_LASH:
                            DoCastAOE(SPELL_TAIL_LASH);
                            events.ScheduleEvent(EVENT_TAIL_LASH, randtime(Seconds(11), Seconds(16)));
                            break;
                        case EVENT_BREATH:
                            DoCastSelf(SPELL_FLAME_BREATH);
                            events.ScheduleEvent(EVENT_BREATH, randtime(Seconds(16), Seconds(25)));
                            break;
                        case EVENT_ACTIVATE_FIREWALL:
                            // Flame ring is activated 5 seconds after starting encounter, DOOR_TYPE_ROOM is only instant.
                            for (uint8 i = DATA_FLAME_RING; i <= DATA_TWILIGHT_FLAME_RING; ++i)
                                if (GameObject* flameRing = instance->GetGameObject(i))
                                    instance->HandleGameObject(ObjectGuid::Empty, false, flameRing);
                            break;
                        case EVENT_METEOR_STRIKE:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_TWILIGHT_REALM))
                            {
                                _meteorStrikePos = target->GetPosition();
                                me->CastSpell(_meteorStrikePos.GetPositionX(), _meteorStrikePos.GetPositionY(), _meteorStrikePos.GetPositionZ(), SPELL_METEOR_STRIKE, true, nullptr, nullptr, me->GetGUID());
                                Talk(SAY_METEOR_STRIKE);
                            }
                            events.ScheduleEvent(EVENT_METEOR_STRIKE, Seconds(38));
                            break;
                        }
                        case EVENT_FIERY_COMBUSTION:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_TWILIGHT_REALM))
                                me->CastSpell(target, SPELL_FIERY_COMBUSTION, TRIGGERED_IGNORE_SET_FACING);
                            events.ScheduleEvent(EVENT_FIERY_COMBUSTION, Seconds(25));
                            break;
                        }
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void SetData(uint32 index, uint32 value) override
            {
                if (index != DATA_FIGHT_PHASE)
                    return;

                events.SetPhase(value);
            }

        private:
            Position _meteorStrikePos;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetRubySanctumAI<boss_halionAI>(creature);
        }
};

typedef boss_halion::boss_halionAI HalionAI;

class boss_twilight_halion : public CreatureScript
{
    public:
        boss_twilight_halion() : CreatureScript("boss_twilight_halion") { }

        struct boss_twilight_halionAI : public BossAI
        {
            boss_twilight_halionAI(Creature* creature) : BossAI(creature, DATA_TWILIGHT_HALION)
            {
                Creature* halion = instance->GetCreature(DATA_HALION);
                if (!halion)
                    return;

                // Using AddAura because no spell cast packet in sniffs.
                halion->AddAura(SPELL_COPY_DAMAGE, me); // We use explicit targeting here to avoid conditions + SPELL_ATTR6_CANT_TARGET_SELF.
                me->AddAura(SPELL_COPY_DAMAGE, halion);
                DoCastSelf(SPELL_DUSK_SHROUD, true);

                me->SetHealth(halion->GetHealth());
                PhasingHandler::AddPhase(me, 174, false);
                me->SetReactState(REACT_DEFENSIVE);
                me->AddUnitFlag(UNIT_FLAG_IN_COMBAT);
                events.ScheduleEvent(EVENT_TAIL_LASH, Seconds(12));
                events.ScheduleEvent(EVENT_SOUL_CONSUMPTION, Seconds(15));
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.SetPhase(PHASE_TWO);

                _EnterCombat();
                me->AddAura(SPELL_TWILIGHT_PRECISION, me);
                events.ScheduleEvent(EVENT_CLEAVE, Seconds(3));
                events.ScheduleEvent(EVENT_BREATH, Seconds(12));

                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 2);
            }

            void Reset() override { }
            void EnterEvadeMode(EvadeReason /*why*/) override { }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);

                // Victims should not be in the Twilight Realm
                me->CastSpell(victim, SPELL_LEAVE_TWILIGHT_REALM, true);
            }

            void JustDied(Unit* killer) override
            {
                if (Creature* halion = instance->GetCreature(DATA_HALION))
                {
                    // Ensure looting
                    if (me->IsDamageEnoughForLootingAndReward())
                        halion->LowerPlayerDamageReq(halion->GetMaxHealth());

                    if (halion->IsAlive())
                        killer->Kill(halion);
                }

                if (Creature* controller = instance->GetCreature(DATA_HALION_CONTROLLER))
                    if (controller->IsAlive())
                        controller->KillSelf();

                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                //Needed because we already have UNIT_FLAG_IN_COMBAT, otherwise EnterCombat won't ever be called
                if (!events.IsInPhase(PHASE_TWO) && !events.IsInPhase(PHASE_THREE))
                    EnterCombat(attacker);

                if (me->HealthBelowPctDamaged(50, damage) && events.IsInPhase(PHASE_TWO))
                {
                    events.SetPhase(PHASE_THREE);
                    me->CastStop();
                    DoCastSelf(SPELL_TWILIGHT_DIVISION);
                    Talk(SAY_PHASE_THREE);
                    return;
                }

                if (events.IsInPhase(PHASE_THREE))
                {
                    // Don't consider copied damage.
                    if (!me->IsInPhase(attacker))
                        return;

                    if (Creature* controller = instance->GetCreature(DATA_HALION_CONTROLLER))
                        controller->AI()->SetData(DATA_TWILIGHT_DAMAGE_TAKEN, damage);
                }
            }

            void SpellHit(Unit* /*who*/, SpellInfo const* spell) override
            {
                switch (spell->Id)
                {
                    case SPELL_TWILIGHT_DIVISION:
                        if (Creature* controller = instance->GetCreature(DATA_HALION_CONTROLLER))
                            controller->AI()->DoAction(ACTION_MONITOR_CORPOREALITY);
                        break;
                    case SPELL_TWILIGHT_MENDING:
                        Talk(SAY_REGENERATE);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CLEAVE, randtime(Seconds(7), Seconds(10)));
                            break;
                        case EVENT_TAIL_LASH:
                            DoCastAOE(SPELL_TAIL_LASH);
                            events.ScheduleEvent(EVENT_TAIL_LASH, randtime(Seconds(12), Seconds(16)));
                            break;
                        case EVENT_BREATH:
                            DoCastSelf(SPELL_DARK_BREATH);
                            events.ScheduleEvent(EVENT_BREATH, randtime(Seconds(10), Seconds(14)));
                            break;
                        case EVENT_SOUL_CONSUMPTION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, SPELL_TWILIGHT_REALM))
                                me->CastSpell(target, SPELL_SOUL_CONSUMPTION, TRIGGERED_IGNORE_SET_FACING);
                            events.ScheduleEvent(EVENT_SOUL_CONSUMPTION, Seconds(20));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
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
                Initialize();
            }

            void Initialize()
            {
                _materialCorporealityValue = 5;
                _materialDamageTaken = 0;
                _twilightDamageTaken = 0;
            }

            void JustRespawned() override
            {
                if (!_instance->GetGuidData(DATA_HALION).IsEmpty() || _instance->GetBossState(DATA_GENERAL_ZARITHRIAN) != DONE)
                    return;

                Reset();
                me->GetMap()->SummonCreature(NPC_HALION, HalionRespawnPos);
            }

            void Reset() override
            {
                _summons.DespawnAll();
                _events.Reset();
                Initialize();

                DoCastSelf(SPELL_CLEAR_DEBUFFS);
            }

            void JustSummoned(Creature* who) override
            {
                _summons.Summon(who);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _events.Reset();
                _summons.DespawnAll();

                DoCastSelf(SPELL_CLEAR_DEBUFFS);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _twilightDamageTaken = 0;
                _materialDamageTaken = 0;

                _events.ScheduleEvent(EVENT_TRIGGER_BERSERK, Minutes(8));
                _events.ScheduleEvent(EVENT_EVADE_CHECK, Seconds(5));
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                if (Creature* twilightHalion = _instance->GetCreature(DATA_TWILIGHT_HALION))
                {
                    twilightHalion->DespawnOrUnsummon();
                    _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, twilightHalion);
                }

                if (Creature* halion = _instance->GetCreature(DATA_HALION))
                {
                    halion->DespawnOrUnsummon();
                    _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, halion);
                }

                _instance->SetBossState(DATA_HALION, FAIL);
                _summons.DespawnAll();

                uint32 corpseDelay = me->GetCorpseDelay();
                uint32 respawnDelay = me->GetRespawnDelay();

                me->SetCorpseDelay(1);
                me->SetRespawnDelay(30);

                me->DespawnOrUnsummon();

                me->SetCorpseDelay(corpseDelay);
                me->SetRespawnDelay(respawnDelay);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_INTRO_HALION:
                        _events.Reset();
                        _events.SetPhase(PHASE_INTRO);
                        _events.ScheduleEvent(EVENT_START_INTRO, Seconds(2));
                        break;
                    case ACTION_INTRO_HALION_2:
                        if (!_instance->GetGuidData(DATA_HALION).IsEmpty())
                            return;

                        for (uint8 i = DATA_BURNING_TREE_1; i <= DATA_BURNING_TREE_4; ++i)
                            if (GameObject* tree = _instance->GetGameObject(i))
                                _instance->HandleGameObject(ObjectGuid::Empty, true, tree);
                        me->GetMap()->SummonCreature(NPC_HALION, HalionRespawnPos);
                        break;
                    case ACTION_MONITOR_CORPOREALITY:
                    {
                        for (uint8 itr = DATA_HALION; itr <= DATA_TWILIGHT_HALION; itr++)
                        {
                            Creature* halion = _instance->GetCreature(itr);
                            if (!halion)
                                continue;

                            halion->CastSpell(halion, GetSpell(_materialCorporealityValue, itr == DATA_TWILIGHT_HALION), false);
                            halion->AI()->SetData(DATA_FIGHT_PHASE, PHASE_THREE);

                            if (itr == DATA_TWILIGHT_HALION)
                                continue;

                            halion->RemoveAurasDueToSpell(SPELL_TWILIGHT_PHASING);
                            halion->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                        }

                        // Summon Twilight portals
                        DoCastSelf(SPELL_SUMMON_EXIT_PORTALS);

                        _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_TOGGLE, 1);
                        // Hardcoding doesn't really matter here.
                        _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_MATERIAL, 50);
                        _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_TWILIGHT, 50);

                        _events.ScheduleEvent(EVENT_CHECK_CORPOREALITY, Seconds(7));
                        break;
                    }
                    case ACTION_ACTIVATE_EMBERS:
                        _events.ScheduleEvent(EVENT_ACTIVATE_EMBERS, Seconds(6));
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                // The IsInCombat() check is needed because that check should be false when Halion is
                // not engaged, while it would return true without as UpdateVictim() checks for
                // combat state.
                if (!_events.IsInPhase(PHASE_INTRO) && me->IsInCombat() && !UpdateVictim())
                {
                    EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
                    return;
                }

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_START_INTRO:
                            DoCastSelf(SPELL_COSMETIC_FIRE_PILLAR, true);
                            _events.ScheduleEvent(EVENT_INTRO_PROGRESS_1, Seconds(4));
                            break;
                        case EVENT_INTRO_PROGRESS_1:
                            for (uint8 i = DATA_BURNING_TREE_3; i <= DATA_BURNING_TREE_4; ++i)
                                if (GameObject* tree = _instance->GetGameObject(i))
                                    _instance->HandleGameObject(ObjectGuid::Empty, true, tree);
                            _events.ScheduleEvent(EVENT_INTRO_PROGRESS_2, Seconds(4));
                            break;
                        case EVENT_INTRO_PROGRESS_2:
                            for (uint8 i = DATA_BURNING_TREE_1; i <= DATA_BURNING_TREE_2; ++i)
                                if (GameObject* tree = _instance->GetGameObject(i))
                                    _instance->HandleGameObject(ObjectGuid::Empty, true, tree);
                            _events.ScheduleEvent(EVENT_INTRO_PROGRESS_3, Seconds(4));
                            break;
                        case EVENT_INTRO_PROGRESS_3:
                            DoCastSelf(SPELL_FIERY_EXPLOSION);
                            if (!_instance->GetGuidData(DATA_HALION).IsEmpty())
                                return;
                            if (Creature* halion = me->GetMap()->SummonCreature(NPC_HALION, HalionSpawnPos))
                                halion->AI()->Talk(SAY_INTRO);
                            break;
                        case EVENT_TWILIGHT_MENDING:
                            if (_instance->GetCreature(DATA_HALION)) // Just check if physical Halion is spawned
                                if (Creature* twilightHalion = _instance->GetCreature(DATA_TWILIGHT_HALION))
                                    twilightHalion->CastSpell((Unit*)nullptr, SPELL_TWILIGHT_MENDING, true);
                            break;
                        case EVENT_TRIGGER_BERSERK:
                            for (uint8 i = DATA_HALION; i <= DATA_TWILIGHT_HALION; i++)
                                if (Creature* halion = _instance->GetCreature(i))
                                    halion->CastSpell(halion, SPELL_BERSERK, true);
                            break;
                        case EVENT_SHADOW_PULSARS_SHOOT:
                            if (Creature* orbCarrier = _instance->GetCreature(DATA_ORB_CARRIER))
                                orbCarrier->AI()->DoAction(ACTION_WARNING_SHOOT);
                            _events.ScheduleEvent(EVENT_SHADOW_PULSARS_SHOOT, Seconds(30));
                            break;
                        case EVENT_CHECK_CORPOREALITY:
                            UpdateCorporeality();
                            _events.ScheduleEvent(EVENT_CHECK_CORPOREALITY, Seconds(5));
                            break;
                        case EVENT_ACTIVATE_EMBERS:
                            _summons.DoZoneInCombat(NPC_LIVING_EMBER);
                            break;
                        case EVENT_EVADE_CHECK:
                            DoCheckEvade();
                            _events.Repeat(Seconds(5));
                            break;
                        default:
                            break;
                    }
                }
            }

            void DoCheckEvade()
            {
                Map::PlayerList const &players = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                    if (Player* player = i->GetSource())
                        if (player->IsAlive() && CheckBoundary(player) && !player->IsGameMaster())
                            return;

                EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
            }

            void SetData(uint32 id, uint32 value) override
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
                                _events.ScheduleEvent(EVENT_SHADOW_PULSARS_SHOOT, Seconds(35));
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
                    _events.ScheduleEvent(EVENT_TWILIGHT_MENDING, Milliseconds(100));
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
                        _events.ScheduleEvent(EVENT_TWILIGHT_MENDING, Milliseconds(100));
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
                    if (Creature* halion = _instance->GetCreature(itr))
                    {
                        halion->CastSpell(halion, GetSpell(_materialCorporealityValue, itr == DATA_TWILIGHT_HALION), true);

                        if (itr == DATA_TWILIGHT_HALION)
                            halion->AI()->Talk(oldValue < _materialCorporealityValue ? EMOTE_CORPOREALITY_TOT : EMOTE_CORPOREALITY_TIT, halion);
                        else // if (itr == DATA_HALION)
                            halion->AI()->Talk(oldValue > _materialCorporealityValue ? EMOTE_CORPOREALITY_POT : EMOTE_CORPOREALITY_PIP, halion);
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetRubySanctumAI<npc_halion_controllerAI>(creature);
        }
};

class npc_orb_carrier : public CreatureScript
{
    public:
        npc_orb_carrier() : CreatureScript("npc_orb_carrier") { }

        struct npc_orb_carrierAI : public ScriptedAI
        {
            npc_orb_carrierAI(Creature* creature) : ScriptedAI(creature),
                _instance(creature->GetInstanceScript())
            {
                ASSERT(creature->GetVehicleKit());
            }

            void UpdateAI(uint32 diff) override
            {
                /// According to sniffs this spell is cast every 1 or 2 seconds.
                /// However, refreshing it looks bad, so just cast the spell if
                /// we are not channeling it.
                if (!me->HasUnitState(UNIT_STATE_CASTING))
                    me->CastSpell((Unit*)nullptr, SPELL_TRACK_ROTATION, false);

                scheduler.Update(diff);

                /// Workaround: This is here because even though the above spell has SPELL_ATTR1_CHANNEL_TRACK_TARGET,
                /// we are having two creatures involded here. This attribute is handled clientside, meaning the client
                /// sends orientation update itself. Here, no packet is sent, and the creature does not rotate. By
                /// forcing the carrier to always be facing the rotation focus, we ensure everything works as it should.
                if (Creature* rotationFocus = _instance->GetCreature(DATA_ORB_ROTATION_FOCUS))
                    me->SetFacingToObject(rotationFocus); // setInFront
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_WARNING_SHOOT:
                    {
                        Vehicle* vehicle = me->GetVehicleKit();
                        Unit* northOrb = vehicle->GetPassenger(SEAT_NORTH);
                        if (northOrb && northOrb->GetTypeId() == TYPEID_UNIT)
                            northOrb->ToCreature()->AI()->Talk(EMOTE_WARN_LASER);

                        scheduler.Schedule(Seconds(5), [this](TaskContext /*context*/)
                        {
                            DoAction(ACTION_SHOOT);
                        });
                        break;
                    }
                    case ACTION_SHOOT:
                    {
                        Vehicle* vehicle = me->GetVehicleKit();
                        Unit* southOrb = vehicle->GetPassenger(SEAT_SOUTH);
                        Unit* northOrb = vehicle->GetPassenger(SEAT_NORTH);
                        if (southOrb && northOrb)
                            TriggerCutter(northOrb, southOrb);

                        if (Creature* twilightHalion = _instance->GetCreature(DATA_TWILIGHT_HALION))
                            twilightHalion->AI()->Talk(SAY_SPHERE_PULSE);

                        if (!IsHeroic())
                            return;

                        Unit* eastOrb = vehicle->GetPassenger(SEAT_EAST);
                        Unit* westOrb = vehicle->GetPassenger(SEAT_WEST);
                        if (eastOrb && westOrb)
                            TriggerCutter(eastOrb, westOrb);
                        break;
                    }
                    default:
                        break;
                }
            }
        private:
            InstanceScript* _instance;
            TaskScheduler scheduler;

            void TriggerCutter(Unit* caster, Unit* target)
            {
                caster->CastSpell(caster, SPELL_TWILIGHT_PULSE_PERIODIC, true);
                target->CastSpell(target, SPELL_TWILIGHT_PULSE_PERIODIC, true);
                caster->CastSpell(target, SPELL_TWILIGHT_CUTTER, false);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
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

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_METEOR_STRIKE_AOE:
                        DoCastSelf(SPELL_METEOR_STRIKE_AOE_DAMAGE, true);
                        DoCastSelf(SPELL_METEOR_STRIKE_FIRE_AURA_1, true);
                        for (std::list<Creature*>::iterator itr = _meteorList.begin(); itr != _meteorList.end(); ++itr)
                            (*itr)->AI()->DoAction(ACTION_METEOR_STRIKE_BURN);
                        break;
                }
            }

            void IsSummonedBy(Unit* summoner) override
            {
                Creature* owner = summoner->ToCreature();
                if (!owner)
                    return;

                // Let Controller count as summoner
                if (Creature* controller = _instance->GetCreature(DATA_HALION_CONTROLLER))
                    controller->AI()->JustSummoned(me);

                DoCastSelf(SPELL_METEOR_STRIKE_COUNTDOWN);
                DoCastSelf(SPELL_BIRTH_NO_VISUAL);

                if (HalionAI* halionAI = CAST_AI(HalionAI, owner->AI()))
                {
                    Position const* ownerPos = halionAI->GetMeteorStrikePosition();
                    float randomAdjustment = frand(static_cast<float>(M_PI / 5.0f), static_cast<float>(M_PI / 2.0f));
                    float angle[4];
                    angle[0] = me->GetAngle(ownerPos);
                    angle[1] = angle[0] + randomAdjustment;
                    angle[2] = angle[0] + static_cast<float>(M_PI);
                    angle[3] = angle[2] + randomAdjustment;

                    _meteorList.clear();
                    for (uint8 i = 0; i < 4; i++)
                    {
                        angle[i] = Position::NormalizeOrientation(angle[i]);
                        me->SetOrientation(angle[i]);
                        Position newPos = me->GetNearPosition(10.0f, 0.0f); // Exact distance
                        if (Creature* meteor = me->SummonCreature(NPC_METEOR_STRIKE_NORTH + i, newPos, TEMPSUMMON_TIMED_DESPAWN, 30000))
                            _meteorList.push_back(meteor);
                    }
                }
            }

            void UpdateAI(uint32 /*diff*/) override { }
            void EnterEvadeMode(EvadeReason /*why*/) override { }
        private:
            InstanceScript* _instance;
            std::list<Creature*> _meteorList;
        };

        CreatureAI* GetAI(Creature* creature) const override
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
                _instance(creature->GetInstanceScript()), _spawnCount(0)
            {
                SetCombatMovement(false);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_METEOR_STRIKE_BURN)
                {
                    DoCastSelf(SPELL_METEOR_STRIKE_FIRE_AURA_2, true);
                    me->setActive(true);
                    _events.ScheduleEvent(EVENT_SPAWN_METEOR_FLAME, Milliseconds(500));
                }
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                // Let Halion Controller count as summoner.
                if (Creature* controller = _instance->GetCreature(DATA_HALION_CONTROLLER))
                    controller->AI()->JustSummoned(me);
            }

            void SetData(uint32 dataType, uint32 dataCount) override
            {
                if (dataType == DATA_SPAWNED_FLAMES)
                    _spawnCount += dataCount;
            }

            uint32 GetData(uint32 dataType) const override
            {
                if (dataType == DATA_SPAWNED_FLAMES)
                    return _spawnCount;
                return 0;
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (_events.ExecuteEvent() == EVENT_SPAWN_METEOR_FLAME)
                {
                    Position pos = me->GetNearPosition(5.0f, frand(-static_cast<float>(M_PI / 6.0f), static_cast<float>(M_PI / 6.0f)));
                    if (Creature* flame = me->SummonCreature(NPC_METEOR_STRIKE_FLAME, pos, TEMPSUMMON_TIMED_DESPAWN, 25000))
                        flame->AI()->SetGUID(me->GetGUID());
                }
            }

        private:
            InstanceScript* _instance;
            EventMap _events;
            uint8 _spawnCount;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetRubySanctumAI<npc_meteor_strikeAI>(creature);
        }
};

class npc_meteor_strike_flame : public CreatureScript
{
    public:
        npc_meteor_strike_flame() : CreatureScript("npc_meteor_strike_flame") { }

        struct npc_meteor_strike_flameAI : public ScriptedAI
        {
            npc_meteor_strike_flameAI(Creature* creature) : ScriptedAI(creature),
                _instance(creature->GetInstanceScript())
            {
                SetCombatMovement(false);
            }

            void SetGUID(ObjectGuid guid, int32 /*id = 0 */) override
            {
                _rootOwnerGuid = guid;
                _events.ScheduleEvent(EVENT_SPAWN_METEOR_FLAME, Milliseconds(800));
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                // Let Halion Controller count as summoner.
                if (Creature* controller = _instance->GetCreature(DATA_HALION_CONTROLLER))
                    controller->AI()->JustSummoned(me);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);
                if (_events.ExecuteEvent() != EVENT_SPAWN_METEOR_FLAME)
                    return;

                me->CastSpell(me, SPELL_METEOR_STRIKE_FIRE_AURA_2, true);

                Creature* meteorStrike = ObjectAccessor::GetCreature(*me, _rootOwnerGuid);
                if (!meteorStrike)
                    return;

                meteorStrike->AI()->SetData(DATA_SPAWNED_FLAMES, 1);
                if (meteorStrike->AI()->GetData(DATA_SPAWNED_FLAMES) > 5)
                    return;

                Position pos = me->GetNearPosition(5.0f, frand(-static_cast<float>(M_PI / 6.0f), static_cast<float>(M_PI / 6.0f)));
                if (Creature* flame = me->SummonCreature(NPC_METEOR_STRIKE_FLAME, pos, TEMPSUMMON_TIMED_DESPAWN, 25000))
                    flame->AI()->SetGUID(_rootOwnerGuid);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override { }

        private:
            InstanceScript* _instance;
            EventMap _events;
            ObjectGuid _rootOwnerGuid;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetRubySanctumAI<npc_meteor_strike_flameAI>(creature);
        }
};

class npc_combustion_consumption : public CreatureScript
{
    public:
        npc_combustion_consumption() : CreatureScript("npc_combustion_consumption") { }

        struct npc_combustion_consumptionAI : public ScriptedAI
        {
            npc_combustion_consumptionAI(Creature* creature) : ScriptedAI(creature),
                   _instance(creature->GetInstanceScript())
            {
                SetCombatMovement(false);

                switch (creature->GetEntry())
                {
                    case NPC_COMBUSTION:
                        _explosionSpell = SPELL_FIERY_COMBUSTION_EXPLOSION;
                        _damageSpell = SPELL_COMBUSTION_DAMAGE_AURA;
                        PhasingHandler::AddPhase(creature, DEFAULT_PHASE, false);
                        if (IsHeroic())
                            PhasingHandler::AddPhase(creature, 174, false);
                        break;
                    case NPC_CONSUMPTION:
                        _explosionSpell = SPELL_SOUL_CONSUMPTION_EXPLOSION;
                        _damageSpell = SPELL_CONSUMPTION_DAMAGE_AURA;
                        PhasingHandler::AddPhase(creature, 174, false);
                        if (IsHeroic())
                            PhasingHandler::AddPhase(creature, DEFAULT_PHASE, false);
                        break;
                    default: // Should never happen
                        _explosionSpell = 0;
                        _damageSpell = 0;
                        break;
                }
            }

            void IsSummonedBy(Unit* summoner) override
            {
                // Let Halion Controller count as summoner
                if (Creature* controller = _instance->GetCreature(DATA_HALION_CONTROLLER))
                    controller->AI()->JustSummoned(me);

                _summonerGuid = summoner->GetGUID();
            }

            void SetData(uint32 type, uint32 stackAmount) override
            {
                Unit* summoner = ObjectAccessor::GetUnit(*me, _summonerGuid);

                if (type != DATA_STACKS_DISPELLED || !_damageSpell || !_explosionSpell || !summoner)
                    return;

                me->CastCustomSpell(SPELL_SCALE_AURA, SPELLVALUE_AURA_STACK, stackAmount + 1, me);
                DoCastSelf(_damageSpell);

                int32 damage = 1200 + (stackAmount * 1290); // Needs more research.
                summoner->CastCustomSpell(_explosionSpell, SPELLVALUE_BASE_POINT0, damage, summoner);
            }

            void UpdateAI(uint32 /*diff*/) override { }

        private:
            InstanceScript* _instance;
            uint32 _explosionSpell;
            uint32 _damageSpell;
            ObjectGuid _summonerGuid;
        };

        CreatureAI* GetAI(Creature* creature) const override
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

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                me->SetInCombatWithZone();
                me->CastSpell(me, SPELL_BLAZING_AURA, true);

                // SMSG_SPELL_GO for the living ember stuff isn't even sent to the client - Blizzard on drugs.
                if (me->GetMap()->GetDifficultyID() == DIFFICULTY_25_HC)
                    scheduler.Schedule(Seconds(3), [this](TaskContext /*context*/)
                    {
                        me->CastSpell(me, SPELL_SPAWN_LIVING_EMBERS, true);
                    });
                if (InstanceScript* instance = me->GetInstanceScript())
                    if (Creature* controller = instance->GetCreature(DATA_HALION_CONTROLLER))
                    {
                        controller->AI()->DoAction(ACTION_ACTIVATE_EMBERS);
                        controller->AI()->JustSummoned(me);
                    }
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->DespawnOrUnsummon(1);
            }

            void UpdateAI(uint32 diff) override
            {
                scheduler.Update(diff);
                ScriptedAI::UpdateAI(diff);
            }

        private:
            TaskScheduler scheduler;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetRubySanctumAI<npc_living_infernoAI>(creature);
        }
};

class npc_living_ember : public CreatureScript
{
    public:
        npc_living_ember() : CreatureScript("npc_living_ember") { }

        struct npc_living_emberAI : public ScriptedAI
        {
            npc_living_emberAI(Creature* creature) : ScriptedAI(creature) { }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                if (InstanceScript* instance = me->GetInstanceScript())
                    if (Creature* controller = instance->GetCreature(DATA_HALION_CONTROLLER))
                        controller->AI()->JustSummoned(me);
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->DespawnOrUnsummon(1);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
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
                        PhasingHandler::AddPhase(gameobject, 174, false);
                        _spellId = gameobject->GetGOInfo()->goober.spell;
                        break;
                    case GO_HALION_PORTAL_1:
                    case GO_HALION_PORTAL_2:
                        PhasingHandler::AddPhase(gameobject, DEFAULT_PHASE, false);
                        /// Because WDB template has non-existent spell ID, not seen in sniffs either, meh
                        _spellId = SPELL_TWILIGHT_REALM;
                        break;
                    default:
                        _spellId = 0;
                        break;
                }
            }

            bool GossipHello(Player* player) override
            {
                if (_spellId != 0)
                    player->CastSpell(player, _spellId, true);
                return true;
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (_instance->GetBossState(DATA_HALION) == IN_PROGRESS)
                    return;

                if (!_deleted)
                {
                    _deleted = true;
                    me->Delete();
                }
            }

        private:
            InstanceScript* _instance;
            uint32 _spellId;
            bool _deleted;
        };

        GameObjectAI* GetAI(GameObject* gameobject) const override
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

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_meteor_strike_marker_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
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

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ _markSpell });
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_DEATH)
                    return;

                if (GetTarget()->HasAura(_markSpell))
                    GetTarget()->RemoveAurasDueToSpell(_markSpell, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->CastSpell(GetTarget(), _markSpell, true);
            }

            void AddMarkStack(AuraEffect const* /*aurEff*/)
            {
                GetTarget()->CastSpell(GetTarget(), _markSpell, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_halion_combustion_consumption_AuraScript::AddMarkStack, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
                AfterEffectApply += AuraEffectApplyFn(spell_halion_combustion_consumption_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_combustion_consumption_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }

            uint32 _markSpell;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_halion_combustion_consumption_AuraScript(_spellID);
        }

    private:
        uint32 _spellID;
};

class spell_halion_combustion_consumption_periodic : public SpellScriptLoader
{
    public:
        spell_halion_combustion_consumption_periodic() : SpellScriptLoader("spell_halion_combustion_consumption_periodic") { }

        class spell_halion_combustion_consumption_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_combustion_consumption_periodic_AuraScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0)->TriggerSpell });
            }

            void HandleTick(AuraEffect const* aurEff)
            {
                PreventDefaultAction();
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                uint32 triggerSpell = GetSpellInfo()->GetEffect(aurEff->GetEffIndex())->TriggerSpell;
                int32 radius = caster->GetObjectScale() * M_PI * 10000 / 3;

                caster->CastCustomSpell(triggerSpell, SPELLVALUE_RADIUS_MOD, radius, (Unit*)nullptr, TRIGGERED_FULL_MASK, nullptr, aurEff, caster->GetGUID());
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_halion_combustion_consumption_periodic_AuraScript::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_halion_combustion_consumption_periodic_AuraScript();
        }
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

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ _summonSpellId });
            }

            /// We were purged. Force removed stacks to zero and trigger the appropriated remove handler.
            void BeforeDispel(DispelInfo* dispelData)
            {
                // Prevent any stack from being removed at this point.
                dispelData->SetRemovedCharges(0);

                if (Unit* dispelledUnit = GetUnitOwner())
                    if (dispelledUnit->HasAura(_removeSpellId))
                        dispelledUnit->RemoveAurasDueToSpell(_removeSpellId, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
                    return;

                // Stacks marker
                GetTarget()->CastCustomSpell(_summonSpellId, SPELLVALUE_BASE_POINT1, aurEff->GetBase()->GetStackAmount(), GetTarget(), TRIGGERED_FULL_MASK, nullptr, nullptr, GetCasterGUID());
            }

            void Register() override
            {
                OnDispel += AuraDispelFn(spell_halion_marks_AuraScript::BeforeDispel);
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_marks_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }

            uint32 _summonSpellId;
            uint32 _removeSpellId;
        };

        AuraScript* GetAuraScript() const override
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
                uint32 entry = uint32(GetSpellInfo()->GetEffect(effIndex)->MiscValue);
                SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(uint32(GetSpellInfo()->GetEffect(effIndex)->MiscValueB));
                uint32 duration = uint32(GetSpellInfo()->GetDuration());

                Position pos = caster->GetPosition();
                if (Creature* summon = caster->GetMap()->SummonCreature(entry, pos, properties, duration, caster, GetSpellInfo()->Id))
                    if (summon->IsAIEnabled)
                        summon->AI()->SetData(DATA_STACKS_DISPELLED, GetSpellValue()->EffectBasePoints[EFFECT_1]);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_halion_damage_aoe_summon_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };

        SpellScript* GetSpellScript() const override
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

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ _beforeHitSpellId });
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

                target->RemoveAurasDueToSpell(_beforeHitSpellId, ObjectGuid::Empty, 0, AURA_REMOVE_BY_ENEMY_SPELL);
                if (InstanceScript* instance = target->GetInstanceScript())
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_UNK7);
            }

            void Register() override
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

        AuraScript* GetAuraScript() const override
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

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_CLEAR_DEBUFFS,
                    SPELL_TWILIGHT_REALM,
                });
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                if (GetHitUnit()->HasAura(GetSpellInfo()->GetEffect(effIndex)->CalcValue()))
                    GetHitUnit()->RemoveAurasDueToSpell(GetSpellInfo()->GetEffect(effIndex)->CalcValue());
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_halion_clear_debuffs_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
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
                auto const& channelObjects = caster->m_unitData->ChannelObjects;
                if (Unit* channelTarget = (channelObjects.size() == 1 ? ObjectAccessor::GetUnit(*caster, *channelObjects.begin()) : nullptr))
                {
                    unitList.remove_if(TwilightCutterSelector(caster, channelTarget));
                    return;
                }

                // In case cutter caster werent found for some reason
                unitList.clear();
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_halion_twilight_cutter_SpellScript::RemoveNotBetween, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
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

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_SUMMON_TWILIGHT_PORTAL });
            }

            void Phase()
            {
                Unit* caster = GetCaster();
                caster->CastSpell(caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), SPELL_SUMMON_TWILIGHT_PORTAL, true);
                caster->GetMap()->SummonCreature(NPC_TWILIGHT_HALION, HalionSpawnPos);
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_halion_twilight_phasing_SpellScript::Phase);
            }
        };

        SpellScript* GetSpellScript() const override
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

            void Register() override
            {
                OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_halion_summon_exit_portals_SpellScript::SetDest0, EFFECT_0, TARGET_DEST_CASTER);
                OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_halion_summon_exit_portals_SpellScript::SetDest1, EFFECT_1, TARGET_DEST_CASTER);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_halion_summon_exit_portals_SpellScript();
        }
};

class spell_halion_spawn_living_embers : public SpellScriptLoader
{
    public:
        spell_halion_spawn_living_embers() : SpellScriptLoader("spell_halion_spawn_living_embers") { }

        class spell_halion_spawn_living_embers_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_spawn_living_embers_SpellScript);

            void SelectMeteorFlames(std::list<WorldObject*>& unitList)
            {
                if (!unitList.empty())
                    Trinity::Containers::RandomResize(unitList, 10);
            }

            void HandleScript(SpellEffIndex /* effIndex */)
            {
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_LIVING_EMBER, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_halion_spawn_living_embers_SpellScript::SelectMeteorFlames, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_halion_spawn_living_embers_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_halion_spawn_living_embers_SpellScript();
        }
};

class spell_halion_blazing_aura : public SpellScriptLoader
{
    public:
        spell_halion_blazing_aura() : SpellScriptLoader("spell_halion_blazing_aura") { }

        class spell_halion_blazing_aura_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_blazing_aura_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetHitUnit()->CastSpell(GetHitUnit(), GetSpellInfo()->GetEffect(EFFECT_1)->TriggerSpell);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_halion_blazing_aura_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_FORCE_CAST);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_halion_blazing_aura_SpellScript();
        }
};



void AddSC_boss_halion()
{
    new boss_halion();
    new boss_twilight_halion();

    new npc_halion_controller();
    new npc_meteor_strike_flame();
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
    new spell_halion_combustion_consumption_periodic();
    new spell_halion_damage_aoe_summon();
    new spell_halion_twilight_realm_handlers("spell_halion_leave_twilight_realm", SPELL_SOUL_CONSUMPTION, false);
    new spell_halion_twilight_realm_handlers("spell_halion_enter_twilight_realm", SPELL_FIERY_COMBUSTION, true);
    new spell_halion_summon_exit_portals();
    new spell_halion_twilight_phasing();
    new spell_halion_twilight_cutter();
    new spell_halion_clear_debuffs();
    new spell_halion_spawn_living_embers();
    new spell_halion_blazing_aura();
}
