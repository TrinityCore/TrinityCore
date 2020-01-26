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

/* ScriptData
SDName: Boss_Kaelthas
SD%Complete: 60
SDComment: SQL, weapon scripts, mind control, need correct spells(interruptible/uninterruptible), phoenix spawn location & animation, phoenix behaviour & spawn during gravity lapse
SDCategory: Tempest Keep, The Eye
EndScriptData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "the_eye.h"

enum Yells
{
    // Kael'thas Speech
    SAY_INTRO                                  = 0,
    SAY_INTRO_CAPERNIAN                        = 1,
    SAY_INTRO_TELONICUS                        = 2,
    SAY_INTRO_THALADRED                        = 3,
    SAY_INTRO_SANGUINAR                        = 4,
    SAY_PHASE2_WEAPON                          = 5,
    SAY_PHASE3_ADVANCE                         = 6,
    SAY_PHASE4_INTRO2                          = 7,
    SAY_PHASE5_NUTS                            = 8,
    SAY_SLAY                                   = 9,
    SAY_MIND_CONTROL                           = 10,
    SAY_GRAVITY_LAPSE                          = 11,
    SAY_SUMMON_PHOENIX                         = 12,
    SAY_DEATH                                  = 13,
    EMOTE_PYROBLAST                            = 14,

    // Thaladred the Darkener speech
    SAY_THALADRED_AGGRO                        = 0,
    SAY_THALADRED_DEATH                        = 1,
    EMOTE_THALADRED_GAZE                       = 2,

    //Lord Sanguinar speech
    SAY_SANGUINAR_AGGRO                        = 0,
    SAY_SANGUINAR_DEATH                        = 1,

    // Grand Astromancer Capernian speech
    SAY_CAPERNIAN_AGGRO                        = 0,
    SAY_CAPERNIAN_DEATH                        = 1,

    // Master Engineer Telonicus speech
    SAY_TELONICUS_AGGRO                        = 0,
    SAY_TELONICUS_DEATH                        = 1
};

enum Spells
{
    // Phase 2 spells
    SPELL_SUMMON_WEAPONS                        = 36976,
    SPELL_SUMMON_WEAPONA                        = 36958,
    SPELL_SUMMON_WEAPONB                        = 36959,
    SPELL_SUMMON_WEAPONC                        = 36960,
    SPELL_SUMMON_WEAPOND                        = 36961,
    SPELL_SUMMON_WEAPONE                        = 36962,
    SPELL_SUMMON_WEAPONF                        = 36963,
    SPELL_SUMMON_WEAPONG                        = 36964,
    SPELL_RESSURECTION                          = 36450,

    // Phase 4 spells
    SPELL_FIREBALL                              = 36805,
    SPELL_PYROBLAST                             = 36819,
    SPELL_FLAME_STRIKE                          = 36735,
    SPELL_FLAME_STRIKE_VIS                      = 36730,
    SPELL_FLAME_STRIKE_DMG                      = 36731,
    SPELL_ARCANE_DISRUPTION                     = 36834,
    SPELL_SHOCK_BARRIER                         = 36815,
    SPELL_PHOENIX_ANIMATION                     = 36723,
    //SPELL_MIND_CONTROL                        = 32830,
    SPELL_MIND_CONTROL                          = 36797,
    SPELL_BANISH                                = 40370,  // Cast on Phoenix

    // Phase 5 spells
    SPELL_KAEL_GAINING_POWER                    = 36091,
    SPELL_KAEL_EXPLODES                         = 36373,
    SPELL_KAEL_EXPLODES2                        = 36375,
    SPELL_KAEL_EXPLODES3                        = 36092,
    SPELL_KAEL_EXPLODES4                        = 36354,
    SPELL_KAEL_STUNNED                          = 36185,
    SPELL_FULLPOWER                             = 36187,
    SPELL_NETHER_BEAM                           = 35873,
    SPELL_PURE_NETHER_BEAM                      = 36196,
    SPELL_SUMMON_NETHER_VAPOR                   = 35865,

    // Visual, phase transition spells
    SPELL_NETHER_BEAM_VISUAL                    = 36089, // Channeled by trigger on Kael'thas.
    SPELL_NETHER_BEAM_VISUAL2                   = 36090, // Channeled by trigger on Kael'thas.
    SPELL_NETHER_BEAM_VISUAL3                   = 36364, // Cast by Kael'thas on himself, purple glowing effect.

    // Gravity Lapse spells
    SPELL_GRAVITY_LAPSE                         = 35941,
    SPELL_GRAVITY_LAPSE_PERIODIC                = 34480,
    SPELL_GRAVITY_LAPSE_FLIGHT_AURA             = 39432, // Cast by players on themselves, allows flight

    // 25 teleport spells, one for each raid member...
    SPELL_GRAVITY_LAPSE_TELE_FRONT              = 35966,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_RIGHT        = 35967,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_LEFT         = 35968,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_RIGHT  = 35969,
    SPELL_GRAVITY_LAPSE_TELE_BACK               = 35970,
    SPELL_GRAVITY_LAPSE_TELE_TO_CASTER          = 35971,
    SPELL_GRAVITY_LAPSE_TELE_BACK_LEFT          = 35972,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_LEFT2        = 35973,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_LEFT        = 35974,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_LEFT2       = 35975,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_LEFT3        = 35976,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_LEFT   = 35977,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_FRONT       = 35978,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK        = 35979,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_RIGHT2       = 35980,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_RIGHT       = 35981,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_FRONT_RIGHT = 35982,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_FRONT2      = 35983,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_FRONT_LEFT  = 35984,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_LEFT3       = 35985,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_LEFT2  = 35986,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK2       = 35987,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_RIGHT2 = 35988,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_RIGHT2      = 35989,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_RIGHT3 = 35990,

    // Thaladred the Darkener spells
    SPELL_PSYCHIC_BLOW                          = 10689,
    SPELL_SILENCE                               = 30225,
    SPELL_REND                                  = 36965,
    // Lord Sanguinar spells
    SPELL_BELLOWING_ROAR                        = 40636,
    // Grand Astromancer Capernian spells

    SPELL_CAPERNIAN_FIREBALL                    = 36971,
    SPELL_CONFLAGRATION                         = 37018,
    SPELL_ARCANE_EXPLOSION                      = 36970,
    //Master Engineer Telonicus spells
    SPELL_BOMB                                  = 37036,
    SPELL_REMOTE_TOY                            = 37027,
    //Nether Vapor spell
    SPELL_NETHER_VAPOR                          = 35859,
    //Phoenix spell
    SPELL_BURN                                  = 36720,
    SPELL_EMBER_BLAST                           = 34341,
    SPELL_REBIRTH                               = 41587
};

enum Creatures
{
    NPC_PHOENIX                             = 21362,
    NPC_PHOENIX_EGG                         = 21364
};

enum Models
{
    //Phoenix egg and phoenix model
    MODEL_ID_PHOENIX                        = 19682,
    MODEL_ID_PHOENIX_EGG                    = 20245
};

enum Actions
{
    ACTION_START_ENCOUNTER,
    ACTION_REVIVE_ADVISORS,
    ACTION_PREPARE_ADVISORS,
    ACTION_ACTIVE_ADVISOR,
    ACTION_SCHEDULE_COMBAT_EVENTS
};

enum Advisors
{
    ADVISOR_THALADRED,
    ADVISOR_SANGUINAR,
    ADVISOR_CAPERNIAN,
    ADVISOR_TELONICUS,
    MAX_ADVISORS                            = 4,

    MAX_DEFEATED_ADVISORS                   = 4,
    MAX_KILLED_ADVISORS                     = 8
};

enum Events
{
    EVENT_START_ENCOUNTER = 1,
    EVENT_ACTIVE_ADVISOR,
    EVENT_SUMMON_WEAPONS,
    EVENT_REVIVE_ADVISORS,
    EVENT_ENGAGE_COMBAT,
    EVENT_FULL_POWER,
    EVENT_FIREBALL,
    EVENT_ARCANE_DISRUPTION,
    EVENT_FLAMESTRIKE,
    EVENT_MIND_CONTROL,
    EVENT_SUMMON_PHOENIX,
    EVENT_SHOCK_BARRIER,
    EVENT_PYROBLAST,
    EVENT_PYROBLAST_CAST,
    EVENT_GAINING_POWER,
    EVENT_END_TRANSITION,
    EVENT_GRAVITY_LAPSE,
    EVENT_NETHER_BEAM,

    // Movement updates
    EVENT_TRANSITION_1,
    EVENT_TRANSITION_2,
    EVENT_TRANSITION_3,
    EVENT_TRANSITION_4,
    EVENT_TRANSITION_5,
    EVENT_TRANSITION_6,

    // Phase transition
    EVENT_SIZE_INCREASE,
    EVENT_EXPLODE,
    EVENT_RESUME_COMBAT,

    // Advisors
    EVENT_DELAYED_RESSURECTION,

    // Event groups
    EVENT_GROUP_COMBAT  = 1,  // Default abilities
    EVENT_GROUP_SPECIAL = 2   // Special abilities (Pyroblast, Nether Beam, Shock Barrier)
};

enum Phases
{
    PHASE_NONE,
    PHASE_INTRO,
    PHASE_REVIVED_ADVISORS,
    PHASE_COMBAT,
    PHASE_TRANSITION
};

enum MovementPoints
{
    POINT_START_TRANSITION               = 1,
    POINT_TRANSITION_CENTER_ASCENDING    = 2,
    POINT_TRANSITION_HALFWAY_ASCENDING   = 3,
    POINT_TRANSITION_TOP                 = 4,
    POINT_TRANSITION_HALFWAY_DESCENDING  = 5,
    POINT_END_TRANSITION                 = 6
};

uint32 m_auiSpellSummonWeapon[]=
{
    SPELL_SUMMON_WEAPONA, SPELL_SUMMON_WEAPONB, SPELL_SUMMON_WEAPONC, SPELL_SUMMON_WEAPOND,
    SPELL_SUMMON_WEAPONE, SPELL_SUMMON_WEAPONF, SPELL_SUMMON_WEAPONG
};

uint32 GravityLapseSpells[] =
{
    SPELL_GRAVITY_LAPSE_TELE_FRONT,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_RIGHT,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_LEFT,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_RIGHT,
    SPELL_GRAVITY_LAPSE_TELE_BACK,
    SPELL_GRAVITY_LAPSE_TELE_TO_CASTER,
    SPELL_GRAVITY_LAPSE_TELE_BACK_LEFT,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_LEFT2,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_LEFT,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_LEFT2,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_LEFT3,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_LEFT,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_FRONT,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK,
    SPELL_GRAVITY_LAPSE_TELE_FRONT_RIGHT2,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_RIGHT,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_FRONT_RIGHT,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_FRONT2,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_FRONT_LEFT,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_LEFT3,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_LEFT2,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK2,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_RIGHT2,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_RIGHT2,
    SPELL_GRAVITY_LAPSE_TELE_CASTER_BACK_RIGHT3
};

const float CAPERNIAN_DISTANCE          = 20.0f;            //she casts away from the target
//const float KAEL_VISIBLE_RANGE          = 50.0f;

Position const afGravityPos = {795.0f, 0.0f, 70.0f};

Position const TransitionPos[6] =
{
    // First two values are not static, they seem to differ on each sniff.
    { 794.0522f, -0.96732f, 48.97848f, 0.0f },
    { 796.641f, -0.5888171f, 48.72847f, 3.176499f },
    { 795.007f, -0.471827f, 75.0f, 0.0f },
    { 795.007f, -0.471827f, 75.0f, 3.133458f },
    { 792.419f, -0.504778f, 50.0505f, 0.0f },
    { 792.419f, -0.504778f, 50.0505f, 3.130386f }
};

struct advisorbase_ai : public ScriptedAI
{
    advisorbase_ai(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        instance = creature->GetInstanceScript();
    }

    void Initialize()
    {
        _hasRessurrected = false;
        _inFakeDeath = false;
        DelayRes_Target.Clear();
    }

    void Reset() override
    {
        Initialize();

        me->SetStandState(UNIT_STAND_STATE_STAND);
        me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED));

        //reset encounter
        if (instance->GetBossState(DATA_KAELTHAS) == IN_PROGRESS)
            if (Creature* Kaelthas = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_KAELTHAS)))
                Kaelthas->AI()->EnterEvadeMode();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || _inFakeDeath || me->HasUnitFlag(UNIT_FLAG_NON_ATTACKABLE))
            return;

        ScriptedAI::MoveInLineOfSight(who);
    }

    void AttackStart(Unit* who) override
    {
        if (!who || _inFakeDeath || me->HasUnitFlag(UNIT_FLAG_NON_ATTACKABLE))
            return;

        ScriptedAI::AttackStart(who);
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_RESSURECTION)
        {
            _hasRessurrected = true;
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED));
            me->SetStandState(UNIT_STAND_STATE_STAND);
            events.ScheduleEvent(EVENT_DELAYED_RESSURECTION, 2000);
        }
    }

    void DamageTaken(Unit* killer, uint32 &damage) override
    {
        if (damage >= me->GetHealth() && !_inFakeDeath && !_hasRessurrected)
        {
            //prevent death
            damage = 0;
            _inFakeDeath = true;

            me->InterruptNonMeleeSpells(false);
            me->SetHealth(0);
            me->RemoveAllAurasOnDeath();
            me->ModifyAuraState(AURA_STATE_HEALTHLESS_20_PERCENT, false);
            me->ModifyAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, false);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED));
            me->SetTarget(ObjectGuid::Empty);
            me->SetStandState(UNIT_STAND_STATE_DEAD);
            me->GetMotionMaster()->Clear();
            JustDied(killer);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* kael = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_KAELTHAS)))
            kael->AI()->DoAction(ACTION_ACTIVE_ADVISOR);
    }

    void UpdateAI(uint32 diff) override
    {
        if (_hasRessurrected)
            events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            if (eventId == EVENT_DELAYED_RESSURECTION)
            {
                _inFakeDeath = false;

                Unit* Target = ObjectAccessor::GetUnit(*me, DelayRes_Target);
                if (!Target)
                    Target = me->GetVictim();

                DoResetThreat();
                AttackStart(Target);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveChase(Target);
                me->AddThreat(Target, 0.0f);
            }
        }
    }
    public:
        EventMap events;
        InstanceScript* instance;
        bool _hasRessurrected;
        bool _inFakeDeath;
        ObjectGuid DelayRes_Target;
};

class boss_kaelthas : public CreatureScript
{
    public:

        boss_kaelthas() : CreatureScript("boss_kaelthas") { }

        struct boss_kaelthasAI : public BossAI
        {
            boss_kaelthasAI(Creature* creature) : BossAI(creature, DATA_KAELTHAS)
            {
                Initialize();
            }

            void Initialize()
            {
                _advisorCounter = 0;
                _pyrosCast = 0;
                _netherbeamsCast = 0;
                _phase = PHASE_NONE;
                _scaleStage = 0;
                _hasFullPower = false;
            }

            void Reset() override
            {
                Initialize();
                DoAction(ACTION_PREPARE_ADVISORS);
                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->SetEmoteState(EMOTE_ONESHOT_NONE);
                me->SetDisableGravity(false);
                me->SetTarget(ObjectGuid::Empty);
                me->SetObjectScale(1.0f);
                BossAI::Reset();
            }

            void JustReachedHome() override
            {
                BossAI::JustReachedHome();

                // Rebuild the surrounding environment.
                if (GameObject* statue = instance->GetGameObject(DATA_KAEL_STATUE_LEFT))
                    statue->ResetDoorOrButton();

                if (GameObject* statue = instance->GetGameObject(DATA_KAEL_STATUE_RIGHT))
                    statue->ResetDoorOrButton();

                if (GameObject* window = instance->GetGameObject(DATA_TEMPEST_BRIDGE_WINDOW))
                    window->ResetDoorOrButton();
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_START_ENCOUNTER:
                        Talk(SAY_INTRO);
                        me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);

                        _advisorGuid[ADVISOR_THALADRED] = instance->GetGuidData(DATA_THALADREDTHEDARKENER);
                        _advisorGuid[ADVISOR_SANGUINAR] = instance->GetGuidData(DATA_LORDSANGUINAR);
                        _advisorGuid[ADVISOR_CAPERNIAN] = instance->GetGuidData(DATA_GRANDASTROMANCERCAPERNIAN);
                        _advisorGuid[ADVISOR_TELONICUS] = instance->GetGuidData(DATA_MASTERENGINEERTELONICUS);

                        _phase = PHASE_INTRO;
                        instance->SetBossState(DATA_KAELTHAS, IN_PROGRESS);
                        events.ScheduleEvent(EVENT_START_ENCOUNTER, 23000);
                        break;
                    case ACTION_PREPARE_ADVISORS:
                        for (uint8 i = 0; i < MAX_ADVISORS; ++i)
                        {
                            if (Creature* creature = ObjectAccessor::GetCreature(*me, _advisorGuid[i]))
                            {
                                creature->Respawn(true);
                                creature->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                                creature->AI()->EnterEvadeMode();
                            }
                        }
                        break;
                    case ACTION_ACTIVE_ADVISOR:
                        // They have already been active, so we are not handling new ones, just counting their death.
                        if (_phase == PHASE_REVIVED_ADVISORS)
                            ++_advisorCounter;

                        switch (_advisorCounter)
                        {
                            case ADVISOR_THALADRED:
                                Talk(SAY_INTRO_THALADRED);
                                events.ScheduleEvent(EVENT_ACTIVE_ADVISOR, 7000);
                                break;
                            case ADVISOR_SANGUINAR:
                                Talk(SAY_INTRO_SANGUINAR);
                                events.ScheduleEvent(EVENT_ACTIVE_ADVISOR, 12500);
                                break;
                            case ADVISOR_CAPERNIAN:
                                Talk(SAY_INTRO_CAPERNIAN);
                                events.ScheduleEvent(EVENT_ACTIVE_ADVISOR, 7000);
                                break;
                            case ADVISOR_TELONICUS:
                                Talk(SAY_INTRO_TELONICUS);
                                events.ScheduleEvent(EVENT_ACTIVE_ADVISOR, 8400);
                                break;
                            case MAX_DEFEATED_ADVISORS:
                                // Every advisor defeated - Phase 2 starts.
                                Talk(SAY_PHASE2_WEAPON);
                                events.ScheduleEvent(EVENT_SUMMON_WEAPONS, 3500);
                                break;
                            case MAX_KILLED_ADVISORS:
                                // Every advisor killed - Phase 3 starts.
                                events.ScheduleEvent(EVENT_ENGAGE_COMBAT, 5000);
                                break;
                            default:
                                break;
                        }
                        break;
                    case ACTION_SCHEDULE_COMBAT_EVENTS:
                        _phase = PHASE_COMBAT;
                        events.SetPhase(PHASE_COMBAT);
                        events.ScheduleEvent(EVENT_FIREBALL, 1000, EVENT_GROUP_COMBAT, PHASE_COMBAT);
                        events.ScheduleEvent(EVENT_ARCANE_DISRUPTION, 45000, EVENT_GROUP_COMBAT, PHASE_COMBAT);
                        events.ScheduleEvent(EVENT_FLAMESTRIKE, 30000, EVENT_GROUP_COMBAT, PHASE_COMBAT);
                        events.ScheduleEvent(EVENT_MIND_CONTROL, 40000, EVENT_GROUP_COMBAT, PHASE_COMBAT);
                        events.ScheduleEvent(EVENT_SUMMON_PHOENIX, 50000, EVENT_GROUP_COMBAT, PHASE_COMBAT);
                        break;
                    default:
                        break;
                }
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (_phase == PHASE_NONE && me->IsValidAttackTarget(who) && me->IsWithinDistInMap(who, 30.0f))
                {
                    DoAction(ACTION_START_ENCOUNTER);
                    who->SetInCombatWith(me);
                    me->AddThreat(who, 0.0f);
                    me->SetTarget(who->GetGUID());
                }
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (_phase == PHASE_NONE)
                {
                    DoAction(ACTION_START_ENCOUNTER);
                    me->SetTarget(attacker->GetGUID());
                }

                if (!_hasFullPower && me->HealthBelowPctDamaged(50, damage))
                {
                    _hasFullPower = true;
                    me->AttackStop();
                    me->InterruptNonMeleeSpells(false);
                    events.CancelEventGroup(EVENT_GROUP_COMBAT);
                    events.CancelEventGroup(EVENT_GROUP_SPECIAL);
                    events.SetPhase(PHASE_TRANSITION);
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->MovePoint(POINT_START_TRANSITION, TransitionPos[0]);
                }
            }

            void MovementInform(uint32 type, uint32 point) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (point)
                {
                    case POINT_START_TRANSITION:
                        events.ScheduleEvent(EVENT_TRANSITION_1, 1000);
                        break;
                    case POINT_TRANSITION_CENTER_ASCENDING:
                        me->SetFacingTo(float(M_PI), true);
                        Talk(SAY_PHASE5_NUTS);
                        me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                        me->SetDisableGravity(true);
                        //me->SetHover(true); -- Set in sniffs, but breaks his visual.
                        events.ScheduleEvent(EVENT_TRANSITION_2, 2000);
                        events.ScheduleEvent(EVENT_SIZE_INCREASE, 5000);
                        break;
                    case POINT_TRANSITION_HALFWAY_ASCENDING:
                        DoCast(me, SPELL_NETHER_BEAM_VISUAL3, true);
                        events.ScheduleEvent(EVENT_TRANSITION_3, 1000);
                        break;
                    case POINT_TRANSITION_TOP:
                        events.ScheduleEvent(EVENT_EXPLODE, 10000);
                        break;
                    case POINT_TRANSITION_HALFWAY_DESCENDING:
                        events.ScheduleEvent(EVENT_TRANSITION_5, 2000);
                        break;
                    case POINT_END_TRANSITION:
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->InterruptNonMeleeSpells(false);
                        me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                        me->RemoveAurasDueToSpell(SPELL_FULLPOWER);

                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0))
                            AttackStart(target);

                        DoAction(ACTION_SCHEDULE_COMBAT_EVENTS);
                        events.ScheduleEvent(EVENT_GRAVITY_LAPSE, 10000, EVENT_GROUP_COMBAT, PHASE_COMBAT);
                        break;
                    default:
                        break;
                }
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(SAY_SLAY);
            }

            void JustSummoned(Creature* summoned) override
            {
                // if not phoenix, then it's one of the 7 weapons
                if (summoned->GetEntry() != NPC_PHOENIX)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        summoned->AI()->AttackStart(target);

                    summons.Summon(summoned);
                }
            }

            void JustDied(Unit* killer) override
            {
                Talk(SAY_DEATH);
                BossAI::JustDied(killer);
            }

            void UpdateAI(uint32 diff) override
            {
                if (_phase == PHASE_COMBAT)
                    if (!UpdateVictim())
                        return;

                events.Update(diff);

                // SPELL_KAEL_GAINING_POWER and SPELL_KAEL_STUNNED are channeling spells that need to be interrupted during his transition.
                if (me->HasUnitState(UNIT_STATE_CASTING) && !me->FindCurrentSpellBySpellId(SPELL_KAEL_GAINING_POWER) && !me->FindCurrentSpellBySpellId(SPELL_KAEL_STUNNED))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_START_ENCOUNTER:
                            me->AddUnitFlag(UNIT_FLAG_PACIFIED);
                            DoAction(ACTION_ACTIVE_ADVISOR);
                            break;
                        case EVENT_ACTIVE_ADVISOR:
                            if (Creature* advisor = ObjectAccessor::GetCreature(*me, _advisorGuid[_advisorCounter]))
                            {
                                advisor->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);

                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                    advisor->AI()->AttackStart(target);
                            }
                            ++_advisorCounter;
                            break;
                        case EVENT_SUMMON_WEAPONS:
                        {
                            DoCast(me, SPELL_SUMMON_WEAPONS, false);

                            uint8 uiMaxWeapon = sizeof(m_auiSpellSummonWeapon) / sizeof(uint32);

                            for (uint32 i = 0; i < uiMaxWeapon; ++i)
                                DoCast(me, m_auiSpellSummonWeapon[i], true);

                            events.ScheduleEvent(EVENT_REVIVE_ADVISORS, 120000);
                            break;
                        }
                        case EVENT_REVIVE_ADVISORS:
                            _phase = PHASE_REVIVED_ADVISORS;
                            Talk(SAY_PHASE3_ADVANCE);
                            DoCast(me, SPELL_RESSURECTION);
                            break;
                        case EVENT_ENGAGE_COMBAT:
                            Talk(SAY_PHASE4_INTRO2);

                            // Sometimes people can collect Aggro in Phase 1-3. Reset threat before releasing Kael.
                            DoResetThreat();

                            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED));

                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                AttackStart(target);

                            DoAction(ACTION_SCHEDULE_COMBAT_EVENTS);
                            events.ScheduleEvent(EVENT_PYROBLAST, 60000, EVENT_GROUP_COMBAT, PHASE_COMBAT);
                            break;
                        case EVENT_FIREBALL:
                            DoCastVictim(SPELL_FIREBALL);
                            events.ScheduleEvent(EVENT_FIREBALL, 2500, EVENT_GROUP_COMBAT, PHASE_COMBAT);
                            break;
                        case EVENT_ARCANE_DISRUPTION:
                            DoCastVictim(SPELL_ARCANE_DISRUPTION, true);
                            events.ScheduleEvent(EVENT_ARCANE_DISRUPTION, 60000, EVENT_GROUP_COMBAT, PHASE_COMBAT);
                            break;
                        case EVENT_FLAMESTRIKE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_FLAME_STRIKE);

                            events.ScheduleEvent(EVENT_FLAMESTRIKE, 30000, EVENT_GROUP_COMBAT, PHASE_COMBAT);
                            break;
                        case EVENT_MIND_CONTROL:
                            Talk(SAY_MIND_CONTROL);
                            DoCastAOE(SPELL_MIND_CONTROL, true);
                            events.ScheduleEvent(EVENT_MIND_CONTROL, 60000, EVENT_GROUP_COMBAT, PHASE_COMBAT);
                            break;
                        case EVENT_SUMMON_PHOENIX:
                            DoCast(me, SPELL_PHOENIX_ANIMATION);
                            Talk(SAY_SUMMON_PHOENIX);
                            events.ScheduleEvent(EVENT_SUMMON_PHOENIX, urand(45000, 60000), EVENT_GROUP_COMBAT, PHASE_COMBAT);
                            break;
                        case EVENT_END_TRANSITION:
                            me->SetEmoteState(EMOTE_ONESHOT_NONE);
                            DoCast(SPELL_FULLPOWER);
                            events.ScheduleEvent(EVENT_TRANSITION_4, 2000);
                            break;
                        case EVENT_PYROBLAST:
                            _pyrosCast = 0;
                            Talk(EMOTE_PYROBLAST);
                            DoCast(me, SPELL_SHOCK_BARRIER);
                            events.DelayEvents(10000, EVENT_GROUP_COMBAT);
                            events.ScheduleEvent(EVENT_PYROBLAST_CAST, 1000, EVENT_GROUP_SPECIAL, PHASE_COMBAT);
                            break;
                        case EVENT_PYROBLAST_CAST:
                            if (_pyrosCast < 3)
                            {
                                DoCastVictim(SPELL_PYROBLAST);
                                events.ScheduleEvent(EVENT_PYROBLAST_CAST, 3000);
                                _pyrosCast++;
                            }
                            else
                                events.ScheduleEvent(EVENT_PYROBLAST, 60000, EVENT_GROUP_COMBAT, PHASE_COMBAT);
                            break;
                        case EVENT_GRAVITY_LAPSE:
                            Talk(SAY_GRAVITY_LAPSE);
                            DoCastAOE(SPELL_GRAVITY_LAPSE);
                            DoCast(me, SPELL_NETHER_VAPOR);
                            events.DelayEvents(24000, EVENT_GROUP_COMBAT);
                            events.ScheduleEvent(EVENT_NETHER_BEAM, 3000, EVENT_GROUP_SPECIAL, PHASE_COMBAT);
                            events.ScheduleEvent(EVENT_SHOCK_BARRIER, 1000, EVENT_GROUP_SPECIAL, PHASE_COMBAT);
                            events.ScheduleEvent(EVENT_GRAVITY_LAPSE, 30000, EVENT_GROUP_SPECIAL, PHASE_COMBAT);
                            break;
                        case EVENT_NETHER_BEAM:
                            if (_netherbeamsCast <= 8)
                            {
                                if (Unit* unit = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                    DoCast(unit, SPELL_NETHER_BEAM);

                                _netherbeamsCast++;
                                events.ScheduleEvent(EVENT_NETHER_BEAM, 3000);
                            }
                            else
                                _netherbeamsCast = 0;
                            break;
                        case EVENT_TRANSITION_1:
                            me->GetMotionMaster()->MovePoint(POINT_TRANSITION_CENTER_ASCENDING, TransitionPos[1]);
                            break;
                        case EVENT_TRANSITION_2:
                            DoCast(me, SPELL_KAEL_GAINING_POWER);
                            me->GetMotionMaster()->Clear();
                            me->RemoveUnitMovementFlag(MOVEMENTFLAG_ROOT);
                            me->GetMotionMaster()->MovePoint(POINT_TRANSITION_HALFWAY_ASCENDING, TransitionPos[2], false);
                            break;
                        case EVENT_TRANSITION_3:
                            me->GetMotionMaster()->MovePoint(POINT_TRANSITION_TOP, TransitionPos[3], false);
                            break;
                        case EVENT_TRANSITION_4:
                            me->GetMotionMaster()->MovePoint(POINT_TRANSITION_HALFWAY_DESCENDING, TransitionPos[4], false);
                            break;
                        case EVENT_TRANSITION_5:
                            me->GetMotionMaster()->MovePoint(POINT_END_TRANSITION, TransitionPos[5], false);
                            break;
                        case EVENT_EXPLODE:
                            me->InterruptNonMeleeSpells(false);
                            me->RemoveAurasDueToSpell(SPELL_NETHER_BEAM_VISUAL3);
                            DoCast(me, SPELL_KAEL_EXPLODES3, true);
                            DoCast(me, SPELL_KAEL_STUNNED); // Core doesn't handle the emote properly while flying.
                            me->SetEmoteState(EMOTE_STATE_DROWNED);

                            // Destroy the surrounding environment.
                            if (GameObject* statue = instance->GetGameObject(DATA_KAEL_STATUE_LEFT))
                                statue->UseDoorOrButton();

                            if (GameObject* statue = instance->GetGameObject(DATA_KAEL_STATUE_RIGHT))
                                statue->UseDoorOrButton();

                            if (GameObject* window = instance->GetGameObject(DATA_TEMPEST_BRIDGE_WINDOW))
                                window->UseDoorOrButton();

                            events.ScheduleEvent(EVENT_END_TRANSITION, 10000);
                            break;
                        case EVENT_SIZE_INCREASE:
                            switch (_scaleStage)
                            {
                                case 0:
                                    me->SetObjectScale(1.4f);
                                    events.ScheduleEvent(EVENT_SIZE_INCREASE, 5000);
                                    break;
                                case 1:
                                    me->SetObjectScale(1.8f);
                                    events.ScheduleEvent(EVENT_SIZE_INCREASE, 3000);
                                    break;
                                case 2:
                                    me->SetObjectScale(2.0f);
                                    events.ScheduleEvent(EVENT_SIZE_INCREASE, 1000);
                                    break;
                                case 3:
                                    me->SetObjectScale(2.2f);
                                    break;
                                default:
                                    break;
                            }
                            ++_scaleStage;
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING) && !me->FindCurrentSpellBySpellId(SPELL_KAEL_GAINING_POWER) && !me->FindCurrentSpellBySpellId(SPELL_KAEL_STUNNED))
                        return;
                }

                if (events.IsInPhase(PHASE_COMBAT))
                    DoMeleeAttackIfReady();
            }
        private:
            uint8 _advisorCounter;
            uint8 _phase;
            uint8 _pyrosCast;
            uint8 _scaleStage;
            uint8 _netherbeamsCast;
            bool _hasFullPower;
            ObjectGuid _advisorGuid[MAX_ADVISORS];
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTheEyeAI<boss_kaelthasAI>(creature);
        }
};

class boss_thaladred_the_darkener : public CreatureScript
{
    public:

        boss_thaladred_the_darkener() : CreatureScript("boss_thaladred_the_darkener") { }

        struct boss_thaladred_the_darkenerAI : public advisorbase_ai
        {
            boss_thaladred_the_darkenerAI(Creature* creature) : advisorbase_ai(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                Gaze_Timer = 100;
                Silence_Timer = 20000;
                Rend_Timer = 4000;
                PsychicBlow_Timer = 10000;
            }

            uint32 Gaze_Timer;
            uint32 Silence_Timer;
            uint32 Rend_Timer;
            uint32 PsychicBlow_Timer;

            void Reset() override
            {
                Initialize();

                advisorbase_ai::Reset();
            }

            void EnterCombat(Unit* who) override
            {
                Talk(SAY_THALADRED_AGGRO);
                me->AddThreat(who, 5000000.0f);
            }

            void JustDied(Unit* killer) override
            {
                if (_hasRessurrected)
                    Talk(SAY_THALADRED_DEATH);

                advisorbase_ai::JustDied(killer);
            }

            void UpdateAI(uint32 diff) override
            {
                advisorbase_ai::UpdateAI(diff);

                if (!UpdateVictim() || _inFakeDeath)
                    return;

                //Gaze_Timer
                if (Gaze_Timer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        DoResetThreat();
                        me->AddThreat(target, 5000000.0f);
                        Talk(EMOTE_THALADRED_GAZE, target);
                        Gaze_Timer = 8500;
                    }
                }
                else
                    Gaze_Timer -= diff;

                //Silence_Timer
                if (Silence_Timer <= diff)
                {
                    DoCastVictim(SPELL_SILENCE);
                    Silence_Timer = 20000;
                }
                else
                    Silence_Timer -= diff;

                //Rend_Timer
                if (Rend_Timer <= diff)
                {
                    DoCastVictim(SPELL_REND);
                    Rend_Timer = 4000;
                }
                else
                    Rend_Timer -= diff;

                //PsychicBlow_Timer
                if (PsychicBlow_Timer <= diff)
                {
                    DoCastVictim(SPELL_PSYCHIC_BLOW);
                    PsychicBlow_Timer = 20000 + rand32() % 5000;
                }
                else
                    PsychicBlow_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTheEyeAI<boss_thaladred_the_darkenerAI>(creature);
        }
};

class boss_lord_sanguinar : public CreatureScript
{
    public:

        boss_lord_sanguinar() : CreatureScript("boss_lord_sanguinar") { }

        struct boss_lord_sanguinarAI : public advisorbase_ai
        {
            boss_lord_sanguinarAI(Creature* creature) : advisorbase_ai(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                Fear_Timer = 20000;
            }

            uint32 Fear_Timer;

            void Reset() override
            {
                Initialize();
                advisorbase_ai::Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_SANGUINAR_AGGRO);
            }

            void JustDied(Unit* killer) override
            {
                if (_hasRessurrected)
                    Talk(SAY_SANGUINAR_DEATH);

                advisorbase_ai::JustDied(killer);
            }

            void UpdateAI(uint32 diff) override
            {
                advisorbase_ai::UpdateAI(diff);

                if (!UpdateVictim() || _inFakeDeath)
                    return;

                //Fear_Timer
                if (Fear_Timer <= diff)
                {
                    DoCastVictim(SPELL_BELLOWING_ROAR);
                    Fear_Timer = 25000 + rand32() % 10000;                //approximately every 30 seconds
                }
                else
                    Fear_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };
        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTheEyeAI<boss_lord_sanguinarAI>(creature);
        }
};

class boss_grand_astromancer_capernian : public CreatureScript
{
    public:

        boss_grand_astromancer_capernian() : CreatureScript("boss_grand_astromancer_capernian") { }

        struct boss_grand_astromancer_capernianAI : public advisorbase_ai
        {
            boss_grand_astromancer_capernianAI(Creature* creature) : advisorbase_ai(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                Fireball_Timer = 2000;
                Conflagration_Timer = 20000;
                ArcaneExplosion_Timer = 5000;
                Yell_Timer = 2000;
                Yell = false;
            }

            uint32 Fireball_Timer;
            uint32 Conflagration_Timer;
            uint32 ArcaneExplosion_Timer;
            uint32 Yell_Timer;
            bool Yell;

            void Reset() override
            {
                Initialize();

                advisorbase_ai::Reset();
            }

            void JustDied(Unit* killer) override
            {
                if (_hasRessurrected)
                    Talk(SAY_CAPERNIAN_DEATH);

                advisorbase_ai::JustDied(killer);
            }

            void AttackStart(Unit* who) override
            {
                if (!who || me->HasUnitFlag(UNIT_FLAG_NON_ATTACKABLE))
                    return;

                if (me->Attack(who, true))
                {
                    me->AddThreat(who, 0.0f);
                    me->SetInCombatWith(who);
                    who->SetInCombatWith(me);

                    me->GetMotionMaster()->MoveChase(who, CAPERNIAN_DISTANCE);
                }
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_CAPERNIAN_AGGRO);
            }

            void UpdateAI(uint32 diff) override
            {
                advisorbase_ai::UpdateAI(diff);

                if (!UpdateVictim() || _inFakeDeath)
                    return;

                //Fireball_Timer
                if (Fireball_Timer <= diff)
                {
                    DoCastVictim(SPELL_CAPERNIAN_FIREBALL);
                    Fireball_Timer = 4000;
                }
                else
                    Fireball_Timer -= diff;

                //Conflagration_Timer
                if (Conflagration_Timer <= diff)
                {
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0);

                    if (target && me->IsWithinDistInMap(target, 30))
                        DoCast(target, SPELL_CONFLAGRATION);
                    else
                        DoCastVictim(SPELL_CONFLAGRATION);

                    Conflagration_Timer = 10000 + rand32() % 5000;
                }
                else
                    Conflagration_Timer -= diff;

                //ArcaneExplosion_Timer
                if (ArcaneExplosion_Timer <= diff)
                {
                    bool InMeleeRange = false;
                    Unit* target = NULL;
                    ThreatContainer::StorageType const &threatlist = me->getThreatManager().getThreatList();
                    for (ThreatContainer::StorageType::const_iterator i = threatlist.begin(); i!= threatlist.end(); ++i)
                    {
                        Unit* unit = ObjectAccessor::GetUnit(*me, (*i)->getUnitGuid());
                                                                    //if in melee range
                        if (unit && unit->IsWithinDistInMap(me, 5))
                        {
                            InMeleeRange = true;
                            target = unit;
                            break;
                        }
                    }

                    if (InMeleeRange)
                        DoCast(target, SPELL_ARCANE_EXPLOSION);

                    ArcaneExplosion_Timer = 4000 + rand32() % 2000;
                }
                else
                    ArcaneExplosion_Timer -= diff;

                //Do NOT deal any melee damage.
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTheEyeAI<boss_grand_astromancer_capernianAI>(creature);
        }
};

class boss_master_engineer_telonicus : public CreatureScript
{
    public:

        boss_master_engineer_telonicus() : CreatureScript("boss_master_engineer_telonicus") { }

        struct boss_master_engineer_telonicusAI : public advisorbase_ai
        {
            boss_master_engineer_telonicusAI(Creature* creature) : advisorbase_ai(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                Bomb_Timer = 10000;
                RemoteToy_Timer = 5000;
            }

            uint32 Bomb_Timer;
            uint32 RemoteToy_Timer;

            void Reset() override
            {
                Initialize();

                advisorbase_ai::Reset();
            }

            void JustDied(Unit* killer) override
            {
                if (_hasRessurrected)
                    Talk(SAY_TELONICUS_DEATH);

                advisorbase_ai::JustDied(killer);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_TELONICUS_AGGRO);
            }

            void UpdateAI(uint32 diff) override
            {
                advisorbase_ai::UpdateAI(diff);

                if (!UpdateVictim() || _inFakeDeath)
                    return;

                //Bomb_Timer
                if (Bomb_Timer <= diff)
                {
                    DoCastVictim(SPELL_BOMB);
                    Bomb_Timer = 25000;
                }
                else
                    Bomb_Timer -= diff;

                //RemoteToy_Timer
                if (RemoteToy_Timer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_REMOTE_TOY);

                    RemoteToy_Timer = 10000 + rand32() % 5000;
                }
                else
                    RemoteToy_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTheEyeAI<boss_master_engineer_telonicusAI>(creature);
        }
};

class npc_kael_flamestrike : public CreatureScript
{
    public:

        npc_kael_flamestrike() : CreatureScript("npc_kael_flamestrike") { }

        struct npc_kael_flamestrikeAI : public ScriptedAI
        {
            npc_kael_flamestrikeAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
                SetCombatMovement(false);
            }

            void Initialize()
            {
                Timer = 5000;
                Casting = false;
                KillSelf = false;
            }

            uint32 Timer;
            bool Casting;
            bool KillSelf;

            void Reset() override
            {
                Initialize();

                me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->setFaction(14);
            }

            void MoveInLineOfSight(Unit* /*who*/) override { }

            void EnterCombat(Unit* /*who*/) override { }

            void UpdateAI(uint32 diff) override
            {
                if (!Casting)
                {
                    DoCast(me, SPELL_FLAME_STRIKE_VIS);
                    Casting = true;
                }

                //Timer
                if (Timer <= diff)
                {
                    if (!KillSelf)
                    {
                        me->InterruptNonMeleeSpells(false);
                        DoCast(me, SPELL_FLAME_STRIKE_DMG);
                    }
                    else
                        me->KillSelf();

                    KillSelf = true;
                    Timer = 1000;
                }
                else
                    Timer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTheEyeAI<npc_kael_flamestrikeAI>(creature);
        }
};

class npc_phoenix_tk : public CreatureScript
{
    public:

        npc_phoenix_tk() : CreatureScript("npc_phoenix_tk") { }

        struct npc_phoenix_tkAI : public ScriptedAI
        {
            npc_phoenix_tkAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                Cycle_Timer = 2000;
            }

            uint32 Cycle_Timer;

            void Reset() override
            {
                Initialize();
                DoCast(me, SPELL_BURN, true);
            }

            void JustDied(Unit* /*killer*/) override
            {
                //is this spell in use anylonger?
                //DoCast(me, SPELL_EMBER_BLAST, true);
                me->SummonCreature(NPC_PHOENIX_EGG, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 16000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (Cycle_Timer <= diff)
                {
                    //spell Burn should possible do this, but it doesn't, so do this for now.
                    uint32 dmg = urand(4500, 5500);
                    if (me->GetHealth() > dmg)
                        me->ModifyHealth(-int32(dmg));
                    Cycle_Timer = 2000;
                }
                else
                    Cycle_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTheEyeAI<npc_phoenix_tkAI>(creature);
        }
};

class npc_phoenix_egg_tk : public CreatureScript
{
    public:

        npc_phoenix_egg_tk() : CreatureScript("npc_phoenix_egg_tk") { }

        struct npc_phoenix_egg_tkAI : public ScriptedAI
        {
            npc_phoenix_egg_tkAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                Rebirth_Timer = 15000;
            }

            uint32 Rebirth_Timer;

            void Reset() override
            {
                Initialize();
            }

            //ignore any
            void MoveInLineOfSight(Unit* /*who*/) override { }

            void AttackStart(Unit* who) override
            {
                if (me->Attack(who, false))
                {
                    me->SetInCombatWith(who);
                    who->SetInCombatWith(me);

                    DoStartNoMovement(who);
                }
            }

            void JustSummoned(Creature* summoned) override
            {
                summoned->AddThreat(me->GetVictim(), 0.0f);
                summoned->CastSpell(summoned, SPELL_REBIRTH, false);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!Rebirth_Timer)
                    return;

                if (Rebirth_Timer <= diff)
                {
                    me->SummonCreature(NPC_PHOENIX, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 5000);
                    Rebirth_Timer = 0;
                }
                else
                    Rebirth_Timer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTheEyeAI<npc_phoenix_egg_tkAI>(creature);
        }
};

// 35941 - Gravity Lapse
class spell_kael_gravity_lapse : public SpellScriptLoader
{
    public:
        spell_kael_gravity_lapse() : SpellScriptLoader("spell_kael_gravity_lapse") { }

        class spell_kael_gravity_lapse_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_kael_gravity_lapse_SpellScript);

        public:
            spell_kael_gravity_lapse_SpellScript()
            {
                _targetCount = 0;
            }

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo(GravityLapseSpells);
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetHitUnit(), GravityLapseSpells[_targetCount], true);
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_GRAVITY_LAPSE_PERIODIC, true);
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_GRAVITY_LAPSE_FLIGHT_AURA, true);
                _targetCount++;
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_kael_gravity_lapse_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }

            private:
                 uint8 _targetCount;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_kael_gravity_lapse_SpellScript();
        }
};

void AddSC_boss_kaelthas()
{
    new boss_kaelthas();
    new boss_thaladred_the_darkener();
    new boss_lord_sanguinar();
    new boss_grand_astromancer_capernian();
    new boss_master_engineer_telonicus();
    new npc_kael_flamestrike();
    new npc_phoenix_tk();
    new npc_phoenix_egg_tk();
    new spell_kael_gravity_lapse();
}
