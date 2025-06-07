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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Conversation.h"
#include "ConversationAI.h"
#include "Creature.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "PathGenerator.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"
#include "SpellAuras.h"
#include "SpellHistory.h"
#include "SpellScript.h"
#include "black_rook_hold.h"

enum AmalgamOfSoulsSpells
{
    SPELL_SWIRLING_SCYTHE           = 195254,
    SPELL_SWIRLING_SCYTHE_DAMAGE    = 196517,
    SPELL_REAP_SOUL                 = 194956,
    SPELL_SOUL_ECHOES               = 194966,
    SPELL_SOUL_ECHOES_CLONE_CASTER  = 194981,
    SPELL_SOUL_ECHOES_DAMAGE        = 194960,
    SPELL_SOULGORGE                 = 196930,
    SPELL_CALL_SOULS                = 196078,
    SPELL_CALL_SOULS_AREATRIGGER    = 196925,
    SPELL_SOUL_BURST                = 196587,
    SPELL_TRANSFORM_TIMER           = 224032, // Achievement

    // Outro
    SPELL_SUMMON_MINIBOSS_A         = 196619,
    SPELL_SUMMON_MINIBOSS_B         = 196620,
    SPELL_SUMMON_MINIBOSS_C         = 196646,
    SPELL_START_SPLIT_CONVERSATION  = 197075,
    SPELL_SECRET_DOOR_CHANNEL_LEFT  = 205210,
    SPELL_SECRET_DOOR_CHANNEL_MID   = 205211,
    SPELL_SECRET_DOOR_CHANNEL_RIGHT = 205212
};

enum AmalgamOfSoulsEvents
{
    EVENT_SWIRLING_SCYTE = 1,
    EVENT_REAP_SOUL,
    EVENT_SOUL_ECHOES,
    EVENT_CHECK_ALIVE_SOULS,
    EVENT_SOUL_BURST,

    EVENT_OUTRO
};

enum AmalgamOfSoulsTexts
{
    SAY_AGGRO           = 0,
    SAY_SWIRLING_SCYTHE = 1,
    SAY_SOUL_ECHOES     = 2,
    SAY_REAP_SOUL       = 3,
    SAY_CALL_SOULS      = 4,
    SAY_SOUL_BURST      = 5,

    SAY_OUTRO           = 0
};

enum AmalgamOfSoulsConversation
{
    NPC_LORD_ETHELDRIN_RAVENCREST  = 99857,
    NPC_LADY_VELANDRAS_RAVENCREST  = 99858,
    NPC_STAELLIS_RIVERMOOR         = 99426,

    POINT_SECRET_DOOR              = 0
};

enum AmalgamOfSoulsMisc
{
    POINT_START_CALL_SOULS    = 0,

    POINT_RESTLESS_SOUL       = 0,
    POINT_AMALGAM_OF_SOULS    = 1,

    SUMMON_GROUP_RESTLESS_SOULS = 0,

    NPC_RESTLESS_SOUL = 99664,

    SOUL_ECHOES_STALKER_ANIM_KIT_1 = 9038,
    SOUL_ECHOES_STALKER_ANIM_KIT_2 = 9039,
    SOUL_ECHOES_STALKER_ANIM_KIT_3 = 9176
};

uint16 RandomAnimKit[3] =
{
    SOUL_ECHOES_STALKER_ANIM_KIT_1,
    SOUL_ECHOES_STALKER_ANIM_KIT_2,
    SOUL_ECHOES_STALKER_ANIM_KIT_3
};

constexpr Position AmalgamOfSoulsPosition = { 3252.25f, 7581.75f, 12.884051f };
constexpr Position EtheldrinOutroPosition = { 3226.6829f, 7552.8877f, 15.355894f };
constexpr Position VelandrasOutroPosition = { 3228.9f, 7548.45f, 14.977584f };
constexpr Position StaellisOutroPosition =  { 3233.22f, 7548.13f, 15.162442f };

// 98542 - Amalgam of Souls
struct boss_amalgam_of_souls : public BossAI
{
    boss_amalgam_of_souls(Creature* creature) : BossAI(creature, DATA_AMALGAM_OF_SOULS), callSoulsActive(false) { }

    void Reset() override
    {
        _Reset();
        callSoulsActive = false;
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _JustDied();

        DoCastSelf(SPELL_SUMMON_MINIBOSS_A);
        DoCastSelf(SPELL_SUMMON_MINIBOSS_B);
        DoCastSelf(SPELL_SUMMON_MINIBOSS_C);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        summons.DespawnAll();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        events.ScheduleEvent(EVENT_SWIRLING_SCYTE, 8100ms);
        events.ScheduleEvent(EVENT_SOUL_ECHOES, 16900ms);
        events.ScheduleEvent(EVENT_REAP_SOUL, 20200ms);
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        if (id == POINT_START_CALL_SOULS)
        {
            Talk(SAY_CALL_SOULS);
            DoCastSelf(SPELL_CALL_SOULS);
            DoCastSelf(SPELL_CALL_SOULS_AREATRIGGER, TRIGGERED_FULL_MASK);
            events.ScheduleEvent(EVENT_CHECK_ALIVE_SOULS, 1s);
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (IsHeroicOrHigher())
        {
            if (me->HealthBelowPctDamaged(50, damage) && !callSoulsActive)
            {
                callSoulsActive = true;

                DoStopAttack();
                me->SetReactState(REACT_PASSIVE);
                events.CancelEvent(EVENT_SWIRLING_SCYTE);
                events.CancelEvent(EVENT_SOUL_ECHOES);
                events.CancelEvent(EVENT_REAP_SOUL);

                me->GetMotionMaster()->MovePoint(POINT_START_CALL_SOULS, me->GetHomePosition(), false);
            }
        }
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
                case EVENT_SWIRLING_SCYTE:
                {
                    Talk(SAY_SWIRLING_SCYTHE);
                    DoCastVictim(SPELL_SWIRLING_SCYTHE);
                    events.Repeat(20600ms);
                    break;
                }
                case EVENT_REAP_SOUL:
                {
                    Talk(SAY_REAP_SOUL);
                    DoCastVictim(SPELL_REAP_SOUL);
                    events.Repeat(13400ms);
                    break;
                }
                case EVENT_SOUL_ECHOES:
                {
                    Talk(SAY_SOUL_ECHOES);
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_SOUL_ECHOES);
                    events.Repeat(26700ms);
                    break;
                }
                case EVENT_CHECK_ALIVE_SOULS:
                {
                    Creature* restlessSoul = me->FindNearestCreature(NPC_RESTLESS_SOUL, 100.0f);
                    if (restlessSoul)
                        events.Repeat(500ms);
                    else
                        events.ScheduleEvent(EVENT_SOUL_BURST, 5s);
                    break;
                }
                case EVENT_SOUL_BURST:
                {
                    me->RemoveAurasDueToSpell(SPELL_CALL_SOULS_AREATRIGGER);
                    Talk(SAY_SOUL_BURST);
                    DoCastSelf(SPELL_SOUL_BURST);
                    events.ScheduleEvent(EVENT_SWIRLING_SCYTE, 14200ms);
                    events.ScheduleEvent(EVENT_SOUL_ECHOES, 23s);
                    events.ScheduleEvent(EVENT_REAP_SOUL, 26400ms);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    bool callSoulsActive = false;
};

// 99090 - Soul Echoes Stalker
struct npc_amalgam_of_souls_soul_echoes_stalker : public ScriptedAI
{
    npc_amalgam_of_souls_soul_echoes_stalker(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(WorldObject* summoner) override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetAIAnimKitId(RandomAnimKit[urand(SOUL_ECHOES_STALKER_ANIM_KIT_1, SOUL_ECHOES_STALKER_ANIM_KIT_3)]);
        summoner->CastSpell(me, SPELL_SOUL_ECHOES_CLONE_CASTER, TRIGGERED_FULL_MASK);
    }
};

// 99664 - Restless Soul
struct npc_amalgam_of_souls_restless_soul : public ScriptedAI
{
    npc_amalgam_of_souls_restless_soul(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SetReactState(REACT_PASSIVE);
        DoCastSelf(SPELL_TRANSFORM_TIMER);
        me->GetMotionMaster()->MovePoint(POINT_RESTLESS_SOUL, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + frand(10.0f, 12.0f), false);
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        if (id == POINT_RESTLESS_SOUL)
        {
            Creature* amalgamOfSouls = me->GetInstanceScript()->GetCreature(DATA_AMALGAM_OF_SOULS);
            if (!amalgamOfSouls)
                return;

            me->GetMotionMaster()->MovePoint(POINT_AMALGAM_OF_SOULS, AmalgamOfSoulsPosition);
        }
    }
};

// 99857 - Lord Etheldrin Ravencrest
struct npc_amalgam_of_souls_lord_etheldrin_ravencrest : public ScriptedAI
{
    npc_amalgam_of_souls_lord_etheldrin_ravencrest(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SetStandState(UNIT_STAND_STATE_KNEEL);
        DoCastSelf(SPELL_START_SPLIT_CONVERSATION);
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        if (id == POINT_SECRET_DOOR)
        {
            _scheduler.Schedule(1s, [this](TaskContext task)
            {
                Talk(SAY_OUTRO);

                task.Schedule(4s, [this](TaskContext task)
                {
                    Creature* velandras = me->FindNearestCreature(NPC_LADY_VELANDRAS_RAVENCREST, 100.0f);
                    Creature* staellis = me->FindNearestCreature(NPC_STAELLIS_RIVERMOOR, 100.0f);
                    if (!velandras || !staellis)
                        return;

                    DoCastSelf(SPELL_SECRET_DOOR_CHANNEL_RIGHT);
                    me->DespawnOrUnsummon(6s);

                    velandras->AI()->DoCastSelf(SPELL_SECRET_DOOR_CHANNEL_MID);
                    velandras->DespawnOrUnsummon(6s);

                    staellis->AI()->DoCastSelf(SPELL_SECRET_DOOR_CHANNEL_LEFT);
                    staellis->DespawnOrUnsummon(6s);

                    task.Schedule(6s, [this](TaskContext /*task*/)
                    {
                        if (InstanceScript* instance = me->GetInstanceScript())
                        {
                            if (GameObject* door = instance->GetGameObject(DATA_BOSS_1_POST_BOSS_DOOR))
                                door->SetGoState(GO_STATE_ACTIVE);
                        }
                    });
                });
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 194981 - Soul Echoes
class spell_amalgam_of_souls_soul_echoes_clone_caster : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SOUL_ECHOES_DAMAGE });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_SOUL_ECHOES_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_amalgam_of_souls_soul_echoes_clone_caster::OnRemove, EFFECT_0, SPELL_AURA_CLONE_CASTER, AURA_EFFECT_HANDLE_REAL);
    }
};

// 196930 - Soulgorge
class spell_amalgam_of_souls_soulgorge : public AuraScript
{
    void OnApply(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/) const
    {
        if (Creature* creatureCaster = GetCaster()->ToCreature())
            creatureCaster->DespawnOrUnsummon(3s);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_amalgam_of_souls_soulgorge::OnApply, EFFECT_1, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 196078 - Call Souls
class spell_amalgam_of_souls_call_souls : public SpellScript
{
    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        if (Creature* creatureCaster = GetCaster()->ToCreature())
            creatureCaster->SummonCreatureGroup(SUMMON_GROUP_RESTLESS_SOULS);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_amalgam_of_souls_call_souls::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 196587 - Soul Burst
class spell_amalgam_of_souls_soul_burst : public SpellScript
{
    void HandleAfterCast() const
    {
        if (Creature* creatureCaster = GetCaster()->ToCreature())
            creatureCaster->SetReactState(REACT_AGGRESSIVE);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_amalgam_of_souls_soul_burst::HandleAfterCast);
    }
};

// 195254 - Swirling Scythe
// ID - 5167
/* THIS AREATRIGGER SHOULD ROTATE, BUT IT DOESNT, MAYBE BECAUSE ROLLPITCHYAW IS NYI */
/*
[1] UpdateType: CreateObject2
[1] Object Guid: Full: 0x344278BBA009AAC0004AE40000069ECB AreaTrigger/0 R4254/S19172 Map: 1501 (Black Rook Hold) Entry: 9899 Low: 433867
[1] Object Type: 11 (AreaTrigger)
[1] NoBirthAnim: False
[1] EnablePortals: False
[1] PlayHoverAnim: False
[1] HasMovementUpdate: False
[1] HasMovementTransport: False
[1] Stationary: True
[1] HasCombatVictim: False
[1] HasServerTime: False
[1] HasVehicleCreate: False
[1] HasAnimKitCreate: False
[1] HasRotation: False
[1] HasAreaTrigger: True
[1] HasGameObject: False
[1] HasSmoothPhasing: False
[1] ThisIsYou: False
[1] SceneObjCreate: False
[1] HasPlayerCreateData: False
[1] HasConversation: False
[1] PauseTimesCount: 0
[1] Stationary Position: X: 3256.5698 Y: 7584.2847 Z: 12.884896
[1] Stationary Orientation: 5.879039
[1] ElapsedMs: 10
[1] RollPitchYaw1: X: 0 Y: 0 Z: 0
[1] HasAbsoluteOrientation: False
[1] HasDynamicShape: True
[1] HasAttached: False
[1] HasFaceMovementDir: False
[1] HasFollowsTerrain: True
[1] Unk bit WoD62x: False
[1] HasTargetRollPitchYaw: True
[1] HasScaleCurveID: False
[1] HasMorphCurveID: False
[1] HasFacingCurveID: False
[1] HasMoveCurveID: False
[1] HasAreaTriggerSphere: True
[1] HasAreaTriggerBox: False
[1] HasAreaTriggerPolygon: False
[1] HasAreaTriggerCylinder: False
[1] HasAreaTriggerDisk: False
[1] HasAreaTriggerBoundedPlane: False
[1] HasAreaTriggerSpline: True
[1] HasAreaTriggerOrbit: False
[1] HasAreaTriggerMovementScript: False
[1] (AreaTriggerSpline) TimeToTarget: 1401
[1] (AreaTriggerSpline) ElapsedTimeForMovement: 0
[1] (AreaTriggerSpline) PointsCount: 4
[1] (AreaTriggerSpline) [0] Points: X: 3256.5698 Y: 7584.2847 Z: 12.884896
[1] (AreaTriggerSpline) [1] Points: X: 3256.5698 Y: 7584.2847 Z: 12.884896
[1] (AreaTriggerSpline) [2] Points: X: 3266.8752 Y: 7579.8774 Z: 12.884896
[1] (AreaTriggerSpline) [3] Points: X: 3266.8752 Y: 7579.8774 Z: 12.884896
[1] (AreaTriggerSpline) Computed Distance: 11.208270416945858
[1] (AreaTriggerSpline) Computed Speed: 8.000193017091977
[1] TargetRollPitchYaw: X: 0 Y: 0 Z: 370.0098
[1] Radius: 3.5
[1] RadiusTarget: 3.5
[1] FieldFlags: 0 (None)
[1] EntryID: 9899
[1] DynamicFlags: 0
[1] Scale: 1
[1] (OverrideScaleCurve) StartTimeOffset: 0
[1] (OverrideScaleCurve) [0] Points: X: 0 Y: 0
[1] (OverrideScaleCurve) [1] Points: X: 0 Y: 0
[1] (OverrideScaleCurve) ParameterCurve: 0
[1] (OverrideScaleCurve) OverrideActive: False
[1] Caster: Full: 0x204278BBA0603B80004AE40000069E4B Creature/0 R4254/S19172 Map: 1501 (Black Rook Hold) Entry: 98542 (Amalgam of Souls) Low: 433739
[1] Duration: 30000
[1] TimeToTarget: 1401
[1] TimeToTargetScale: 30000
[1] TimeToTargetExtraScale: 0
[1] TimeToTargetPos: 30000
[1] SpellID: 195254
[1] SpellForVisuals: 195254
[1] (SpellVisual) SpellXSpellVisualID: 90198
[1] (SpellVisual) ScriptVisualID: 0
[1] BoundsRadius2D: 3.5
[1] DecalPropertiesID: 39
[1] CreatingEffectGUID: Full: 0xBC4278BBA0BEAD83004AE40005069ECA Cast/3 R4254/S19172 Map: 1501 (Black Rook Hold) Entry: 195254 (Swirling Scythe) Low: 84319946
[1] NumUnitsInside: 0
[1] NumPlayersInside: 0
[1] OrbitPathTarget: Full: 0x0
[1] RollPitchYaw: X: 0 Y: 0 Z: 0
[1] PositionalSoundKitID: 0
[1] (ExtraScaleCurve) StartTimeOffset: 0
[1] (ExtraScaleCurve) [0] Points: X: 0 Y: 0
[1] (ExtraScaleCurve) [1] Points: X: 0 Y: 0
[1] (ExtraScaleCurve) ParameterCurve: 1065353217
[1] (ExtraScaleCurve) OverrideActive: True
[1] HeightIgnoresScale: False
[1] Field_261: False
[1] (OverrideMoveCurveX) StartTimeOffset: 0
[1] (OverrideMoveCurveX) [0] Points: X: 0 Y: 0
[1] (OverrideMoveCurveX) [1] Points: X: 0 Y: 0
[1] (OverrideMoveCurveX) ParameterCurve: 0
[1] (OverrideMoveCurveX) OverrideActive: False
[1] (OverrideMoveCurveY) StartTimeOffset: 0
[1] (OverrideMoveCurveY) [0] Points: X: 0 Y: 0
[1] (OverrideMoveCurveY) [1] Points: X: 0 Y: 0
[1] (OverrideMoveCurveY) ParameterCurve: 0
[1] (OverrideMoveCurveY) OverrideActive: False
[1] (OverrideMoveCurveZ) StartTimeOffset: 0
[1] (OverrideMoveCurveZ) [0] Points: X: 0 Y: 0
[1] (OverrideMoveCurveZ) [1] Points: X: 0 Y: 0
[1] (OverrideMoveCurveZ) ParameterCurve: 0
[1] (OverrideMoveCurveZ) OverrideActive: False
[1] (VisualAnim) AnimationDataID: 4294967295
[1] (VisualAnim) AnimKitID: 0
[1] (VisualAnim) AnimProgress: 0
[1] (VisualAnim) IsDecay: False*/
struct at_amalgam_of_souls_swirling_scythe : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnInitialize() override
    {
        Position destPos = at->GetPosition();
        PathGenerator path(at);
        path.CalculatePath(destPos.GetPositionX(), destPos.GetPositionY(), destPos.GetPositionZ(), false);

        at->InitSplines(path.GetPath());
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer() || !at->GetCaster())
            return;

        unit->CastSpell(unit, SPELL_SWIRLING_SCYTHE_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }
};

// 196925 - Call Souls
// ID - 5293
struct at_amalgam_of_souls_call_souls : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->GetEntry() != NPC_RESTLESS_SOUL)
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        unit->CastSpell(caster, SPELL_SOULGORGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }
};

// 197075 - Start Split Conversation
// ID - 754
class conversation_amalgam_of_souls_outro : public ConversationAI
{
public:
    conversation_amalgam_of_souls_outro(Conversation* conversation) : ConversationAI(conversation) { }

    void OnStart() override
    {
        LocaleConstant privateOwnerLocale = conversation->GetPrivateObjectOwnerLocale();
        _events.ScheduleEvent(EVENT_OUTRO, conversation->GetLastLineEndTime(privateOwnerLocale));
    }

    void OnUpdate(uint32 diff) override
    {
        _events.Update(diff);

        switch (_events.ExecuteEvent())
        {
            case EVENT_OUTRO:
            {
                Creature* etheldrin = conversation->FindNearestCreature(NPC_LORD_ETHELDRIN_RAVENCREST, 100.0f);
                Creature* velandras = conversation->FindNearestCreature(NPC_LADY_VELANDRAS_RAVENCREST, 100.0f);
                Creature* staellis = conversation->FindNearestCreature(NPC_STAELLIS_RIVERMOOR, 100.0f);
                if (!etheldrin|| !velandras || !staellis)
                    return;

                etheldrin->SetStandState(UNIT_STAND_STATE_STAND);
                etheldrin->GetMotionMaster()->MovePoint(POINT_SECRET_DOOR, EtheldrinOutroPosition);

                velandras->SetStandState(UNIT_STAND_STATE_STAND);
                velandras->GetMotionMaster()->MovePoint(POINT_SECRET_DOOR, VelandrasOutroPosition);

                staellis->SetStandState(UNIT_STAND_STATE_STAND);
                staellis->GetMotionMaster()->MovePoint(POINT_SECRET_DOOR, StaellisOutroPosition);
                break;
            }
            default:
                break;
        }
    }

private:
    EventMap _events;
};

void AddSC_boss_amalgam_of_souls()
{
    RegisterBlackRookHoldCreatureAI(boss_amalgam_of_souls);
    RegisterBlackRookHoldCreatureAI(npc_amalgam_of_souls_soul_echoes_stalker);
    RegisterBlackRookHoldCreatureAI(npc_amalgam_of_souls_restless_soul);
    RegisterBlackRookHoldCreatureAI(npc_amalgam_of_souls_lord_etheldrin_ravencrest);

    RegisterSpellScript(spell_amalgam_of_souls_soul_echoes_clone_caster);
    RegisterSpellScript(spell_amalgam_of_souls_soulgorge);
    RegisterSpellScript(spell_amalgam_of_souls_call_souls);
    RegisterSpellScript(spell_amalgam_of_souls_soul_burst);

    RegisterAreaTriggerAI(at_amalgam_of_souls_swirling_scythe);
    RegisterAreaTriggerAI(at_amalgam_of_souls_call_souls);

    RegisterConversationAI(conversation_amalgam_of_souls_outro);
}
