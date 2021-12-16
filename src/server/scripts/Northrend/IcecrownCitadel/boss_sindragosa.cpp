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

#include "icecrown_citadel.h"
#include "CommonHelpers.h"
#include "Containers.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum Texts
{
    SAY_AGGRO                           = 0, // You are fools to have come to this place! The icy winds of Northrend will consume your souls!
    SAY_UNCHAINED_MAGIC                 = 1, // Suffer, mortals, as your pathetic magic betrays you!
    EMOTE_WARN_BLISTERING_COLD          = 2, // %s prepares to unleash a wave of blistering cold!
    SAY_BLISTERING_COLD                 = 3, // Can you feel the cold hand of death upon your heart?
    SAY_RESPITE_FOR_A_TORMENTED_SOUL    = 4, // Aaah! It burns! What sorcery is this?!
    SAY_AIR_PHASE                       = 5, // Your incursion ends here! None shall survive!
    SAY_PHASE_2                         = 6, // Now feel my master's limitless power and despair!
    EMOTE_WARN_FROZEN_ORB               = 7, // %s fires a frozen orb towards $N!
    SAY_KILL                            = 8, // Perish!
                                             // A flaw of mortality...
    SAY_BERSERK                         = 9, // Enough! I tire of these games!
    SAY_DEATH                           = 10, // Free...at last...
    EMOTE_BERSERK_RAID                  = 11
};

enum Spells
{
    // Sindragosa
    SPELL_SINDRAGOSA_S_FURY     = 70608,
    SPELL_TANK_MARKER           = 71039,
    SPELL_FROST_AURA            = 70084,
    SPELL_PERMAEATING_CHILL     = 70109,
    SPELL_CLEAVE                = 19983,
    SPELL_TAIL_SMASH            = 71077,
    SPELL_FROST_BREATH_P1       = 69649,
    SPELL_FROST_BREATH_P2       = 73061,
    SPELL_UNCHAINED_MAGIC       = 69762,
    SPELL_BACKLASH              = 69770,
    SPELL_ICY_GRIP              = 70117,
    SPELL_ICY_GRIP_JUMP         = 70122,
    SPELL_BLISTERING_COLD       = 70123,
    SPELL_FROST_BEACON          = 70126,
    SPELL_ICE_TOMB_TARGET       = 69712,
    SPELL_ICE_TOMB_DUMMY        = 69675,
    SPELL_ICE_TOMB_UNTARGETABLE = 69700,
    SPELL_ICE_TOMB_DAMAGE       = 70157,
    SPELL_ASPHYXIATION          = 71665,
    SPELL_FROST_BOMB_TRIGGER    = 69846,
    SPELL_FROST_BOMB_VISUAL     = 70022,
    SPELL_BIRTH_NO_VISUAL       = 40031,
    SPELL_FROST_BOMB            = 69845,
    SPELL_MYSTIC_BUFFET         = 70128,

    // Spinestalker
    SPELL_BELLOWING_ROAR        = 36922,
    SPELL_CLEAVE_SPINESTALKER   = 40505,
    SPELL_TAIL_SWEEP            = 71370,

    // Rimefang
    SPELL_FROST_BREATH          = 71386,
    SPELL_FROST_AURA_RIMEFANG   = 71387,
    SPELL_ICY_BLAST             = 71376,
    SPELL_ICY_BLAST_AREA        = 71380,

    // Frostwarden Handler
    SPELL_FOCUS_FIRE            = 71350,
    SPELL_ORDER_WHELP           = 71357,
    SPELL_CONCUSSIVE_SHOCK      = 71337,

    // Frost Infusion
    SPELL_FROST_INFUSION_CREDIT = 72289,
    SPELL_FROST_IMBUED_BLADE    = 72290,
    SPELL_FROST_INFUSION        = 72292,
};

enum Events
{
    // Sindragosa
    EVENT_BERSERK                   = 1,
    EVENT_CLEAVE                    = 2,
    EVENT_TAIL_SMASH                = 3,
    EVENT_FROST_BREATH              = 4,
    EVENT_UNCHAINED_MAGIC           = 5,
    EVENT_ICY_GRIP                  = 6,
    EVENT_BLISTERING_COLD           = 7,
    EVENT_BLISTERING_COLD_YELL      = 8,
    EVENT_AIR_PHASE                 = 9,
    EVENT_ICE_TOMB                  = 10,
    EVENT_FROST_BOMB                = 11,
    EVENT_LAND                      = 12,
    EVENT_AIR_MOVEMENT              = 21,
    EVENT_THIRD_PHASE_CHECK         = 22,
    EVENT_AIR_MOVEMENT_FAR          = 23,
    EVENT_LAND_GROUND               = 24,

    // Spinestalker
    EVENT_BELLOWING_ROAR            = 13,
    EVENT_CLEAVE_SPINESTALKER       = 14,
    EVENT_TAIL_SWEEP                = 15,

    // Rimefang
    EVENT_FROST_BREATH_RIMEFANG     = 16,
    EVENT_ICY_BLAST                 = 17,
    EVENT_ICY_BLAST_CAST            = 18,

    // Trash
    EVENT_FROSTWARDEN_ORDER_WHELP   = 19,
    EVENT_CONCUSSIVE_SHOCK          = 20,

    // event groups
    EVENT_GROUP_LAND_PHASE          = 1,
};

enum FrostwingData
{
    DATA_MYSTIC_BUFFET_STACK    = 0,
    DATA_FROSTWYRM_OWNER        = 1,
    DATA_WHELP_MARKER           = 2,
    DATA_LINKED_GAMEOBJECT      = 3,
    DATA_TRAPPED_PLAYER         = 4,
    DATA_IS_THIRD_PHASE         = 5
};

enum MovementPoints
{
    POINT_FROSTWYRM_FLY_IN  = 1,
    POINT_FROSTWYRM_LAND    = 2,
    POINT_AIR_PHASE         = 3,
    POINT_TAKEOFF           = 4,
    POINT_LAND              = 5,
    POINT_AIR_PHASE_FAR     = 6,
    POINT_LAND_GROUND       = 7,
};

enum Shadowmourne
{
    QUEST_FROST_INFUSION        = 24757
};

Position const RimefangFlyPos      = {4413.309f, 2456.421f, 233.3795f, 2.890186f};
Position const RimefangLandPos     = {4413.309f, 2456.421f, 203.3848f, 2.890186f};
Position const SpinestalkerFlyPos  = {4418.895f, 2514.233f, 230.4864f, 3.396045f};
Position const SpinestalkerLandPos = {4418.895f, 2514.233f, 203.3848f, 3.396045f};
Position const SindragosaSpawnPos  = {4818.700f, 2483.710f, 287.0650f, 3.089233f};
Position const SindragosaFlyPos    = {4475.190f, 2484.570f, 234.8510f, 3.141593f};
Position const SindragosaLandPos   = {4419.190f, 2484.570f, 203.3848f, 3.141593f};
Position const SindragosaAirPos    = {4475.990f, 2484.430f, 247.9340f, 3.141593f};
Position const SindragosaAirPosFar = {4525.600f, 2485.150f, 245.0820f, 3.141593f};
Position const SindragosaFlyInPos  = {4419.190f, 2484.360f, 232.5150f, 3.141593f};

class FrostwyrmLandEvent : public BasicEvent
{
    public:
        FrostwyrmLandEvent(Creature& owner, Position const& dest) : _owner(owner), _dest(dest) { }

        bool Execute(uint64 /*eventTime*/, uint32 /*updateTime*/) override
        {
            _owner.GetMotionMaster()->MoveLand(POINT_FROSTWYRM_LAND, _dest);
            return true;
        }

    private:
        Creature& _owner;
        Position const& _dest;
};

class FrostBombExplosion : public BasicEvent
{
    public:
        FrostBombExplosion(Creature* owner, ObjectGuid sindragosaGUID) : _owner(owner), _sindragosaGUID(sindragosaGUID) { }

        bool Execute(uint64 /*eventTime*/, uint32 /*updateTime*/) override
        {
            _owner->CastSpell(nullptr, SPELL_FROST_BOMB, CastSpellExtraArgs().SetOriginalCaster(_sindragosaGUID));
            _owner->RemoveAurasDueToSpell(SPELL_FROST_BOMB_VISUAL);
            return true;
        }

    private:
        Creature* _owner;
        ObjectGuid _sindragosaGUID;
};

class FrostBeaconSelector : NonTankTargetSelector
{
    public:
        FrostBeaconSelector(Unit* source) : NonTankTargetSelector(source, true) { }

        bool operator()(WorldObject* target) const
        {
            if (Unit* unitTarget = target->ToUnit())
                return !NonTankTargetSelector::operator()(unitTarget) ||
                    unitTarget->HasAura(SPELL_ICE_TOMB_UNTARGETABLE);

            return false;
        }
};

struct boss_sindragosa : public BossAI
{
    boss_sindragosa(Creature* creature) : BossAI(creature, DATA_SINDRAGOSA)
    {
        Initialize();
    }

    void Initialize()
    {
        _mysticBuffetStack = 0;
        _isInAirPhase = false;
        _isThirdPhase = false;
    }

    void Reset() override
    {
        BossAI::Reset();
        DoCastSelf(SPELL_TANK_MARKER, true);
        events.ScheduleEvent(EVENT_BERSERK, 10min);
        events.ScheduleEvent(EVENT_CLEAVE, 10s, EVENT_GROUP_LAND_PHASE);
        events.ScheduleEvent(EVENT_TAIL_SMASH, 20s, EVENT_GROUP_LAND_PHASE);
        events.ScheduleEvent(EVENT_FROST_BREATH, 8s, 12s, EVENT_GROUP_LAND_PHASE);
        events.ScheduleEvent(EVENT_UNCHAINED_MAGIC, 9s, 14s, EVENT_GROUP_LAND_PHASE);
        events.ScheduleEvent(EVENT_ICY_GRIP, 33500ms, EVENT_GROUP_LAND_PHASE);
        events.ScheduleEvent(EVENT_AIR_PHASE, 50s);
        Initialize();

        if (instance->GetData(DATA_SINDRAGOSA_INTRO))
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
        }
    }

    void JustDied(Unit* /* killer */) override
    {
        _JustDied();
        Talk(SAY_DEATH);

        if (Is25ManRaid() && me->HasAura(SPELL_SHADOWS_FATE))
            DoCastAOE(SPELL_FROST_INFUSION_CREDIT, true);

    }

    void JustEngagedWith(Unit* victim) override
    {
        if (!instance->CheckRequiredBosses(DATA_SINDRAGOSA, victim->ToPlayer()))
        {
            EnterEvadeMode(EVADE_REASON_SEQUENCE_BREAK);
            instance->DoCastSpellOnPlayers(LIGHT_S_HAMMER_TELEPORT);
            return;
        }

        DoCastSelf(SPELL_FROST_AURA);
        DoCastSelf(SPELL_PERMAEATING_CHILL);
        Talk(SAY_AGGRO);
        instance->SetBossState(DATA_SINDRAGOSA, IN_PROGRESS);
        me->SetCombatPulseDelay(5);
        me->setActive(true);
        me->SetFarVisible(true);
        DoZoneInCombat();
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (_isInAirPhase && why == EVADE_REASON_BOUNDARY)
            return;
        BossAI::EnterEvadeMode(why);
    }

    void JustReachedHome() override
    {
        BossAI::JustReachedHome();
        instance->SetBossState(DATA_SINDRAGOSA, FAIL);
        me->SetCanFly(false);
        me->SetDisableGravity(false);
        me->SetReactState(REACT_DEFENSIVE);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_KILL);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_START_FROSTWYRM)
        {

            instance->SetData(DATA_SINDRAGOSA_INTRO, 0);
            if (TempSummon* summon = me->ToTempSummon())
                summon->SetTempSummonType(TEMPSUMMON_DEAD_DESPAWN);

            if (me->isDead())
                return;

            me->setActive(true);
            me->SetFarVisible(true);
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetSpeedRate(MOVE_FLIGHT, 4.0f);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            Milliseconds moveTime = Milliseconds(uint64(me->GetExactDist(&SindragosaFlyPos) / (me->GetSpeed(MOVE_FLIGHT) * 0.001f)));
            me->m_Events.AddEvent(new FrostwyrmLandEvent(*me, SindragosaLandPos), me->m_Events.CalculateTime(moveTime + 250ms));
            me->GetMotionMaster()->MovePoint(POINT_FROSTWYRM_FLY_IN, SindragosaFlyPos);
            DoCastSelf(SPELL_SINDRAGOSA_S_FURY);
        }
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
            case DATA_MYSTIC_BUFFET_STACK:
                return _mysticBuffetStack;
            case DATA_IS_THIRD_PHASE:
                return _isThirdPhase;
            default:
                return 0xFFFFFFFF;
        }
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
            return;

        switch (point)
        {
            case POINT_FROSTWYRM_LAND:
                me->setActive(false);
                me->SetFarVisible(false);
                me->SetCanFly(false);
                me->SetDisableGravity(false);
                me->SetHomePosition(SindragosaLandPos);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetSpeedRate(MOVE_FLIGHT, 2.5f);

                // Sindragosa enters combat as soon as she lands
                DoZoneInCombat();
                break;
            case POINT_TAKEOFF:
                events.ScheduleEvent(EVENT_AIR_MOVEMENT, 1ms);
                break;
            case POINT_AIR_PHASE:
            {
                CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                args.AddSpellMod(SPELLVALUE_MAX_TARGETS, RAID_MODE<int32>(2, 5, 2, 6));
                me->CastSpell(nullptr, SPELL_ICE_TOMB_TARGET, args);
                me->SetFacingTo(float(M_PI), true);
                events.ScheduleEvent(EVENT_AIR_MOVEMENT_FAR, 1ms);
                events.ScheduleEvent(EVENT_FROST_BOMB, 9s);
                break;
            }
            case POINT_AIR_PHASE_FAR:
                me->SetFacingTo(float(M_PI), true);
                events.ScheduleEvent(EVENT_LAND, 30s);
                break;
            case POINT_LAND:
                events.ScheduleEvent(EVENT_LAND_GROUND, 1ms);
                break;
            case POINT_LAND_GROUND:
            {
                me->SetCanFly(false);
                me->SetDisableGravity(false);
                me->SetReactState(REACT_DEFENSIVE);

                _isInAirPhase = false;
                // trigger Asphyxiation
                EntryCheckPredicate pred(NPC_ICE_TOMB);
                summons.DoAction(ACTION_TRIGGER_ASPHYXIATION, pred);
                break;
            }
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_isThirdPhase && !HealthAbovePct(35))
        {
            events.CancelEvent(EVENT_AIR_PHASE);
            events.ScheduleEvent(EVENT_THIRD_PHASE_CHECK, 1s);
            _isThirdPhase = true;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        if (summon->GetEntry() == NPC_FROST_BOMB)
        {
            summon->CastSpell(summon, SPELL_FROST_BOMB_VISUAL, true);
            summon->CastSpell(summon, SPELL_BIRTH_NO_VISUAL, true);
            summon->m_Events.AddEvent(new FrostBombExplosion(summon, me->GetGUID()), summon->m_Events.CalculateTime(5500ms));
        }
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        BossAI::SummonedCreatureDespawn(summon);
        if (summon->GetEntry() == NPC_ICE_TOMB)
            summon->AI()->JustDied(summon);
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        Unit* unitTarget = target->ToUnit();
        if (!unitTarget)
            return;

        if (uint32 spellId = sSpellMgr->GetSpellIdForDifficulty(70127, me))
            if (spellId == spellInfo->Id)
                if (Aura const* mysticBuffet = unitTarget->GetAura(spellId))
                    _mysticBuffetStack = std::max<uint8>(_mysticBuffetStack, mysticBuffet->GetStackAmount());
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
                case EVENT_BERSERK:
                    Talk(EMOTE_BERSERK_RAID);
                    Talk(SAY_BERSERK);
                    DoCastSelf(SPELL_BERSERK);
                    break;
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    events.ScheduleEvent(EVENT_CLEAVE, 15s, 20s, EVENT_GROUP_LAND_PHASE);
                    break;
                case EVENT_TAIL_SMASH:
                    DoCastSelf(SPELL_TAIL_SMASH);
                    events.ScheduleEvent(EVENT_TAIL_SMASH, 27s, 32s, EVENT_GROUP_LAND_PHASE);
                    break;
                case EVENT_FROST_BREATH:
                    DoCastVictim(_isThirdPhase ? SPELL_FROST_BREATH_P2 : SPELL_FROST_BREATH_P1);
                    events.ScheduleEvent(EVENT_FROST_BREATH, 20s, 25s, EVENT_GROUP_LAND_PHASE);
                    break;
                case EVENT_UNCHAINED_MAGIC:
                    Talk(SAY_UNCHAINED_MAGIC);
                    DoCastSelf(SPELL_UNCHAINED_MAGIC);
                    events.ScheduleEvent(EVENT_UNCHAINED_MAGIC, 30s, 35s, EVENT_GROUP_LAND_PHASE);
                    break;
                case EVENT_ICY_GRIP:
                    DoCastSelf(SPELL_ICY_GRIP);
                    events.ScheduleEvent(EVENT_BLISTERING_COLD, 1s, EVENT_GROUP_LAND_PHASE);
                    break;
                case EVENT_BLISTERING_COLD:
                    Talk(EMOTE_WARN_BLISTERING_COLD);
                    DoCastSelf(SPELL_BLISTERING_COLD);
                    events.ScheduleEvent(EVENT_BLISTERING_COLD_YELL, 5s, EVENT_GROUP_LAND_PHASE);
                    break;
                case EVENT_BLISTERING_COLD_YELL:
                    Talk(SAY_BLISTERING_COLD);
                    break;
                case EVENT_AIR_PHASE:
                {
                    _isInAirPhase = true;
                    Talk(SAY_AIR_PHASE);
                    me->SetCanFly(true);
                    me->SetDisableGravity(true);
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    Position pos;
                    pos.Relocate(me);
                    pos.m_positionZ += 17.0f;
                    me->GetMotionMaster()->MoveTakeoff(POINT_TAKEOFF, pos);
                    events.CancelEventGroup(EVENT_GROUP_LAND_PHASE);
                    events.ScheduleEvent(EVENT_AIR_PHASE, 110s);
                    break;
                }
                case EVENT_AIR_MOVEMENT:
                    me->GetMotionMaster()->MovePoint(POINT_AIR_PHASE, SindragosaAirPos);
                    break;
                case EVENT_AIR_MOVEMENT_FAR:
                    me->GetMotionMaster()->MovePoint(POINT_AIR_PHASE_FAR, SindragosaAirPosFar);
                    break;
                case EVENT_ICE_TOMB:
                {
                    CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                    args.AddSpellMod(SPELLVALUE_MAX_TARGETS, 1);
                    me->CastSpell(nullptr, SPELL_ICE_TOMB_TARGET, args);
                    events.ScheduleEvent(EVENT_ICE_TOMB, 16s, 23s);
                    break;
                }
                case EVENT_FROST_BOMB:
                {
                    float destX, destY, destZ;
                    destX = float(rand_norm()) * 75.0f + 4350.0f;
                    destY = float(rand_norm()) * 75.0f + 2450.0f;
                    destZ = 205.0f; // random number close to ground, get exact in next call
                    me->UpdateGroundPositionZ(destX, destY, destZ);
                    me->CastSpell({ destX, destY, destZ }, SPELL_FROST_BOMB_TRIGGER, false);
                    events.ScheduleEvent(EVENT_FROST_BOMB, 6s, 8s);
                    break;
                }
                case EVENT_LAND:
                {
                    events.CancelEvent(EVENT_FROST_BOMB);
                    me->GetMotionMaster()->MovePoint(POINT_LAND, SindragosaFlyInPos);
                    break;
                }
                case EVENT_LAND_GROUND:
                    events.ScheduleEvent(EVENT_CLEAVE, 13s, 15s, EVENT_GROUP_LAND_PHASE);
                    events.ScheduleEvent(EVENT_TAIL_SMASH, 19s, 23s, EVENT_GROUP_LAND_PHASE);
                    events.ScheduleEvent(EVENT_FROST_BREATH, 10s, 15s, EVENT_GROUP_LAND_PHASE);
                    events.ScheduleEvent(EVENT_UNCHAINED_MAGIC, 12s, 17s, EVENT_GROUP_LAND_PHASE);
                    events.ScheduleEvent(EVENT_ICY_GRIP, 35s, 40s, EVENT_GROUP_LAND_PHASE);
                    me->GetMotionMaster()->MoveLand(POINT_LAND_GROUND, SindragosaLandPos);
                    break;
                case EVENT_THIRD_PHASE_CHECK:
                {
                    if (!_isInAirPhase)
                    {
                        Talk(SAY_PHASE_2);
                        events.ScheduleEvent(EVENT_ICE_TOMB, 7s, 10s);
                        events.RescheduleEvent(EVENT_ICY_GRIP, 35s, 40s);
                        DoCastSelf(SPELL_MYSTIC_BUFFET, true);
                    }
                    else
                        events.ScheduleEvent(EVENT_THIRD_PHASE_CHECK, 5s);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    uint8 _mysticBuffetStack;
    bool _isInAirPhase;
    bool _isThirdPhase;
};

struct npc_ice_tomb : public ScriptedAI
{
    npc_ice_tomb(Creature* creature) : ScriptedAI(creature)
    {
        _existenceCheckTimer = 0;
        SetCombatMovement(false);
    }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void SetGUID(ObjectGuid const& guid, int32 id) override
    {
        if (id == DATA_TRAPPED_PLAYER)
        {
            _trappedPlayerGUID = guid;
            _existenceCheckTimer = 1000;
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_TRIGGER_ASPHYXIATION)
            if (Player* player = ObjectAccessor::GetPlayer(*me, _trappedPlayerGUID))
                player->CastSpell(player, SPELL_ASPHYXIATION, true);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->RemoveAllGameObjects();

        if (Player* player = ObjectAccessor::GetPlayer(*me, _trappedPlayerGUID))
        {
            _trappedPlayerGUID.Clear();
            player->RemoveAurasDueToSpell(SPELL_ICE_TOMB_DAMAGE);
            player->RemoveAurasDueToSpell(SPELL_ASPHYXIATION);
            player->RemoveAurasDueToSpell(SPELL_ICE_TOMB_UNTARGETABLE);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!_trappedPlayerGUID)
            return;

        if (_existenceCheckTimer <= diff)
        {
            Player* player = ObjectAccessor::GetPlayer(*me, _trappedPlayerGUID);
            if (!player || player->isDead() || !player->HasAura(SPELL_ICE_TOMB_DAMAGE))
            {
                // Remove object
                JustDied(me);
                me->DespawnOrUnsummon();
                return;
            }
            _existenceCheckTimer = 1000;
        }
        else
            _existenceCheckTimer -= diff;
    }

private:
    ObjectGuid _trappedPlayerGUID;
    uint32 _existenceCheckTimer;
};

struct npc_spinestalker : public ScriptedAI
{
    npc_spinestalker(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _summoned(false) { }

    void InitializeAI() override
    {
        // Increase add count
        if (!me->isDead())
        {
            _instance->SetData(DATA_SINDRAGOSA_FROSTWYRMS, me->GetSpawnId());  // this cannot be in Reset because reset also happens on evade
            Reset();
        }
    }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_BELLOWING_ROAR, 20s, 25s);
        _events.ScheduleEvent(EVENT_CLEAVE_SPINESTALKER, 10s, 15s);
        _events.ScheduleEvent(EVENT_TAIL_SWEEP, 8s, 12s);

        if (!_summoned)
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
        }
    }

    void JustAppeared() override
    {
        ScriptedAI::JustAppeared();
        _instance->SetData(DATA_SINDRAGOSA_FROSTWYRMS, me->GetSpawnId());  // this cannot be in Reset because reset also happens on evade
    }

    void JustDied(Unit* /*killer*/) override
    {
        _events.Reset();
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_START_FROSTWYRM)
        {
            if (_summoned)
                return;

            _summoned = true;
            if (me->isDead())
                return;

            me->setActive(true);
            me->SetFarVisible(true);
            me->SetSpeedRate(MOVE_FLIGHT, 2.0f);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            Milliseconds moveTime = Milliseconds(uint64(me->GetExactDist(&SpinestalkerFlyPos) / (me->GetSpeed(MOVE_FLIGHT) * 0.001f)));
            me->m_Events.AddEvent(new FrostwyrmLandEvent(*me, SpinestalkerLandPos), me->m_Events.CalculateTime(moveTime + 250ms));
            me->SetDefaultMovementType(IDLE_MOTION_TYPE);
            me->GetMotionMaster()->MoveIdle();
            me->StopMoving();
            me->GetMotionMaster()->MovePoint(POINT_FROSTWYRM_FLY_IN, SpinestalkerFlyPos);
            me->SetReactState(REACT_DEFENSIVE);
        }
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != EFFECT_MOTION_TYPE || point != POINT_FROSTWYRM_LAND)
            return;

        me->setActive(false);
        me->SetFarVisible(false);
        me->SetCanFly(false);
        me->SetDisableGravity(false);
        me->SetHomePosition(SpinestalkerLandPos);
        me->SetFacingTo(SpinestalkerLandPos.GetOrientation());
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        me->SetReactState(REACT_AGGRESSIVE);
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
                case EVENT_BELLOWING_ROAR:
                    DoCastSelf(SPELL_BELLOWING_ROAR);
                    _events.ScheduleEvent(EVENT_BELLOWING_ROAR, 25s, 30s);
                    break;
                case EVENT_CLEAVE_SPINESTALKER:
                    DoCastVictim(SPELL_CLEAVE_SPINESTALKER);
                    _events.ScheduleEvent(EVENT_CLEAVE_SPINESTALKER, 10s, 15s);
                    break;
                case EVENT_TAIL_SWEEP:
                    DoCastSelf(SPELL_TAIL_SWEEP);
                    _events.ScheduleEvent(EVENT_TAIL_SWEEP, 22s, 25s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    bool _summoned;
};

struct npc_rimefang_icc : public ScriptedAI
{
    npc_rimefang_icc(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _summoned(false)
    {
        Initialize();
    }

    void Initialize()
    {
        _icyBlastCounter = 0;
    }

    void InitializeAI() override
    {
        // Increase add count
        if (!me->isDead())
        {
            _instance->SetData(DATA_SINDRAGOSA_FROSTWYRMS, me->GetSpawnId());  // this cannot be in Reset because reset also happens on evade
            Reset();
        }
    }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_FROST_BREATH_RIMEFANG, 12s, 15s);
        _events.ScheduleEvent(EVENT_ICY_BLAST, 30s, 35s);
        Initialize();

        if (!_summoned)
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
        }
    }

    void JustAppeared() override
    {
        ScriptedAI::JustAppeared();
        _instance->SetData(DATA_SINDRAGOSA_FROSTWYRMS, me->GetSpawnId());  // this cannot be in Reset because reset also happens on evade
    }

    void JustDied(Unit* /*killer*/) override
    {
        _events.Reset();
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_START_FROSTWYRM)
        {
            if (_summoned)
                return;

            _summoned = true;
            if (me->isDead())
                return;

            me->setActive(true);
            me->SetFarVisible(true);
            me->SetSpeedRate(MOVE_FLIGHT, 2.0f);
            me->SetImmuneToPC(true);
            Milliseconds moveTime = Milliseconds(uint64(me->GetExactDist(&RimefangFlyPos) / (me->GetSpeed(MOVE_FLIGHT) * 0.001f)));
            me->m_Events.AddEvent(new FrostwyrmLandEvent(*me, RimefangLandPos), me->m_Events.CalculateTime(moveTime + 250ms));
            me->SetDefaultMovementType(IDLE_MOTION_TYPE);
            me->GetMotionMaster()->MoveIdle();
            me->StopMoving();
            me->GetMotionMaster()->MovePoint(POINT_FROSTWYRM_FLY_IN, RimefangFlyPos);
            me->SetReactState(REACT_DEFENSIVE);
        }
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != EFFECT_MOTION_TYPE || point != POINT_FROSTWYRM_LAND)
            return;

        me->setActive(false);
        me->SetFarVisible(false);
        me->SetCanFly(false);
        me->SetDisableGravity(false);
        me->SetHomePosition(RimefangLandPos);
        me->SetFacingTo(RimefangLandPos.GetOrientation());
        me->SetImmuneToPC(false);
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustEngagedWith(Unit* /*victim*/) override
    {
        DoCastSelf(SPELL_FROST_AURA_RIMEFANG, true);
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
                case EVENT_FROST_BREATH_RIMEFANG:
                    DoCastSelf(SPELL_FROST_BREATH);
                    _events.ScheduleEvent(EVENT_FROST_BREATH_RIMEFANG, 35s, 40s);
                    break;
                case EVENT_ICY_BLAST:
                {
                    _icyBlastCounter = RAID_MODE<uint8>(5, 7, 6, 8);
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->SetCanFly(true);
                    me->GetMotionMaster()->MovePoint(POINT_FROSTWYRM_FLY_IN, RimefangFlyPos);
                    Milliseconds moveTime = Milliseconds(uint64(me->GetExactDist(&RimefangFlyPos)/(me->GetSpeed(MOVE_FLIGHT)*0.001f)));
                    _events.ScheduleEvent(EVENT_ICY_BLAST, moveTime + 60s, moveTime + 70s);
                    _events.ScheduleEvent(EVENT_ICY_BLAST_CAST, moveTime + 250ms);
                    break;
                }
                case EVENT_ICY_BLAST_CAST:
                    if (--_icyBlastCounter)
                    {
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                        {
                            me->SetFacingToObject(target);
                            DoCast(target, SPELL_ICY_BLAST);
                        }
                        _events.ScheduleEvent(EVENT_ICY_BLAST_CAST, 3s);
                    }
                    else if (Unit* victim = me->SelectVictim())
                    {
                        me->SetReactState(REACT_DEFENSIVE);
                        AttackStart(victim);
                        me->SetCanFly(false);
                    }
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    uint8 _icyBlastCounter;
    bool _summoned;
};

struct npc_sindragosa_trash : public ScriptedAI
{
    npc_sindragosa_trash(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        _instance = creature->GetInstanceScript();
        _frostwyrmId = 0;
    }

    void Initialize()
    {
        _isTaunted = false;
    }

    void InitializeAI() override
    {
        _frostwyrmId = (me->GetHomePosition().GetPositionY() < 2484.35f) ? DATA_RIMEFANG : DATA_SPINESTALKER;
        // Increase add count
        if (!me->isDead())
        {
            if (me->GetEntry() == NPC_FROSTWING_WHELP)
                _instance->SetData(_frostwyrmId, me->GetSpawnId());  // this cannot be in Reset because reset also happens on evade
            Reset();
        }
    }

    void Reset() override
    {
        // This is shared AI for handler and whelps
        if (me->GetEntry() == NPC_FROSTWARDEN_HANDLER)
        {
            _events.ScheduleEvent(EVENT_FROSTWARDEN_ORDER_WHELP, 3s);
            _events.ScheduleEvent(EVENT_CONCUSSIVE_SHOCK, 8s, 10s);
        }

        Initialize();
    }

    void JustAppeared() override
    {
        ScriptedAI::JustAppeared();

        // Increase add count
        if (me->GetEntry() == NPC_FROSTWING_WHELP)
            _instance->SetData(_frostwyrmId, me->GetSpawnId());  // this cannot be in Reset because reset also happens on evade
    }

    void SetData(uint32 type, uint32 data) override
    {
        if (type == DATA_WHELP_MARKER)
            _isTaunted = data != 0;
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_FROSTWYRM_OWNER)
            return _frostwyrmId;
        else if (type == DATA_WHELP_MARKER)
            return uint32(_isTaunted);
        return 0;
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
                case EVENT_FROSTWARDEN_ORDER_WHELP:
                    DoCastSelf(SPELL_ORDER_WHELP);
                    _events.ScheduleEvent(EVENT_FROSTWARDEN_ORDER_WHELP, 3s);
                    break;
                case EVENT_CONCUSSIVE_SHOCK:
                    DoCastSelf(SPELL_CONCUSSIVE_SHOCK);
                    _events.ScheduleEvent(EVENT_CONCUSSIVE_SHOCK, 10s, 13s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    uint32 _frostwyrmId;
    bool _isTaunted; // Frostwing Whelp only
};

// 70598 - Sindragosa's Fury
class spell_sindragosa_s_fury : public SpellScript
{
    PrepareSpellScript(spell_sindragosa_s_fury);

    bool Load() override
    {
        // This script should execute only in Icecrown Citadel
        return InstanceHasScript(GetCaster(), ICCScriptName);
    }

    void SelectDest()
    {
        if (Position* dest = const_cast<WorldLocation*>(GetExplTargetDest()))
        {
            float destX = float(rand_norm()) * 75.0f + 4350.0f;
            float destY = float(rand_norm()) * 75.0f + 2450.0f;
            float destZ = 205.0f; // random number close to ground, get exact in next call
            GetCaster()->UpdateGroundPositionZ(destX, destY, destZ);
            dest->Relocate(destX, destY, destZ);
        }
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* obj) -> bool
        {
            // remove GMs
            if (Player* player = obj->ToPlayer())
                return player->IsGameMaster();

            // remove non-players too
            return true;
        });

        _targetCount = targets.size();
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);

        if (!GetHitUnit()->IsAlive() || !_targetCount)
            return;

        if (GetHitUnit()->IsImmunedToDamage(GetSpellInfo()))
        {
            GetCaster()->SendSpellDamageImmune(GetHitUnit(), GetSpellInfo()->Id);
            return;
        }

        float resistance = float(GetHitUnit()->GetResistance(SpellSchoolMask(GetSpellInfo()->SchoolMask)));
        uint32 minResistFactor = uint32((resistance / (resistance + 510.0f)) * 10.0f) * 2;
        uint32 randomResist = urand(0, (9 - minResistFactor) * 100) / 100 + minResistFactor;

        uint32 damage = (uint32(GetEffectValue() / _targetCount) * randomResist) / 10;

        SpellNonMeleeDamage damageInfo(GetCaster(), GetHitUnit(), GetSpellInfo()->Id, GetSpellInfo()->SchoolMask);
        damageInfo.damage = damage;
        GetCaster()->SendSpellNonMeleeDamageLog(&damageInfo);
        GetCaster()->DealSpellDamage(&damageInfo, false);
    }

    void Register() override
    {
        BeforeCast += SpellCastFn(spell_sindragosa_s_fury::SelectDest);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sindragosa_s_fury::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_sindragosa_s_fury::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
    }

    uint32 _targetCount = 0;
};

// 69762 - Unchained Magic
class spell_sindragosa_unchained_magic : public SpellScript
{
    PrepareSpellScript(spell_sindragosa_unchained_magic);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        std::vector<WorldObject*> healers;
        std::vector<WorldObject*> casters;
        for (WorldObject* target : targets)
        {
            Player* player = target->ToPlayer();
            if (!player)
                continue;

            if (Trinity::Helpers::Entity::IsPlayerHealer(player))
            {
                healers.push_back(target);
                continue;
            }

            switch (player->GetClass())
            {
                case CLASS_PRIEST:
                case CLASS_MAGE:
                case CLASS_WARLOCK:
                    casters.push_back(target);
                    break;
                case CLASS_SHAMAN:
                    if (Trinity::Helpers::Entity::GetPlayerSpecialization(player) != SPEC_SHAMAN_ENHANCEMENT)
                        casters.push_back(target);
                    break;
                case CLASS_DRUID:
                    if (Trinity::Helpers::Entity::GetPlayerSpecialization(player) != SPEC_DRUID_FERAL)
                        casters.push_back(target);
                    break;
                default:
                    break;
            }
        }

        targets.clear();

        bool const is25ManRaid = GetCaster()->GetMap()->Is25ManRaid();
        if (!healers.empty())
        {
            Trinity::Containers::RandomResize(healers, size_t(is25ManRaid ? 3 : 1));
            while (!healers.empty())
            {
                targets.push_back(healers.back());
                healers.pop_back();
            }
        }
        if (!casters.empty())
        {
            Trinity::Containers::RandomShuffle(casters);
            size_t const maxSize = is25ManRaid ? 6 : 2;
            while (!casters.empty() && targets.size() < maxSize)
            {
                targets.push_back(casters.back());
                casters.pop_back();
            }
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sindragosa_unchained_magic::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 69649, 71056, 71057, 71058 - Frost Breath
// 73061, 73062, 73063, 73064 - Frost Breath
class spell_sindragosa_frost_breath : public SpellScript
{
    PrepareSpellScript(spell_sindragosa_frost_breath);

    void HandleInfusion()
    {
        Player* target = GetHitPlayer();
        if (!target)
            return;

        // Check difficulty and quest status
        if (!(target->GetRaidDifficulty() & RAID_DIFFICULTY_MASK_25MAN) || target->GetQuestStatus(QUEST_FROST_INFUSION) != QUEST_STATUS_INCOMPLETE)
            return;

        // Check if player has Shadow's Edge equipped and not ready for infusion
        if (!target->HasAura(SPELL_UNSATED_CRAVING) || target->HasAura(SPELL_FROST_IMBUED_BLADE))
            return;

        Aura* infusion = target->GetAura(SPELL_FROST_INFUSION, target->GetGUID());
        if (infusion && infusion->GetStackAmount() >= 3)
        {
            target->RemoveAura(infusion);
            target->CastSpell(target, SPELL_FROST_IMBUED_BLADE, TRIGGERED_FULL_MASK);
        }
        else
            target->CastSpell(target, SPELL_FROST_INFUSION, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_sindragosa_frost_breath::HandleInfusion);
    }
};

// 69766 - Instability
class spell_sindragosa_instability : public AuraScript
{
    PrepareAuraScript(spell_sindragosa_instability);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_BACKLASH });
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
        {
            CastSpellExtraArgs args(aurEff);
            args.OriginalCaster = GetCasterGUID();
            args.AddSpellBP0(aurEff->GetAmount());
            GetTarget()->CastSpell(GetTarget(), SPELL_BACKLASH, args);
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_sindragosa_instability::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 70126 - Frost Beacon
class spell_sindragosa_frost_beacon : public AuraScript
{
    PrepareAuraScript(spell_sindragosa_frost_beacon);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_ICE_TOMB_DAMAGE });
    }

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_ICE_TOMB_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sindragosa_frost_beacon::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 70157 - Ice Tomb (Trap)
class spell_sindragosa_ice_tomb_trap : public AuraScript
{
    PrepareAuraScript(spell_sindragosa_ice_tomb_trap);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        if (!sObjectMgr->GetCreatureTemplate(NPC_ICE_TOMB))
            return false;
        if (!sObjectMgr->GetGameObjectTemplate(GO_ICE_BLOCK))
            return false;
        return true;
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        if (aurEff->GetTickNumber() == 1)
        {
            if (Unit* caster = GetCaster())
            {
                Position pos = GetTarget()->GetPosition();

                if (TempSummon* summon = caster->SummonCreature(NPC_ICE_TOMB, pos))
                {
                    summon->AI()->SetGUID(GetTarget()->GetGUID(), DATA_TRAPPED_PLAYER);
                    GetTarget()->CastSpell(GetTarget(), SPELL_ICE_TOMB_UNTARGETABLE);
                    if (GameObject* go = summon->SummonGameObject(GO_ICE_BLOCK, pos, QuaternionData(), 0s))
                    {
                        go->SetSpellId(SPELL_ICE_TOMB_DAMAGE);
                        summon->AddGameObject(go);
                    }
                }
            }
        }
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_ICE_TOMB_UNTARGETABLE);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sindragosa_ice_tomb_trap::PeriodicTick, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sindragosa_ice_tomb_trap::HandleRemove, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 70117 - Icy Grip
class spell_sindragosa_icy_grip : public SpellScript
{
    PrepareSpellScript(spell_sindragosa_icy_grip);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_ICY_GRIP_JUMP });
    }

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetHitUnit()->CastSpell(GetCaster(), SPELL_ICY_GRIP_JUMP, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sindragosa_icy_grip::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class MysticBuffetTargetFilter
{
    public:
        explicit MysticBuffetTargetFilter(Unit* caster) : _caster(caster) { }

        bool operator()(WorldObject* unit) const
        {
            return !unit->IsWithinLOSInMap(_caster);
        }

    private:
        Unit* _caster;
};

// 70127, 72528, 72529, 72530 - Mystic Buffet
class spell_sindragosa_mystic_buffet : public SpellScript
{
    PrepareSpellScript(spell_sindragosa_mystic_buffet);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(MysticBuffetTargetFilter(GetCaster()));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sindragosa_mystic_buffet::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 71376 - Icy Blast
class spell_rimefang_icy_blast : public SpellScript
{
    PrepareSpellScript(spell_rimefang_icy_blast);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_ICY_BLAST_AREA });
    }

    void HandleTriggerMissile(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        if (Position const* pos = GetExplTargetDest())
            if (TempSummon* summon = GetCaster()->SummonCreature(NPC_ICY_BLAST, *pos, TEMPSUMMON_TIMED_DESPAWN, 40s))
                summon->CastSpell(summon, SPELL_ICY_BLAST_AREA, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_rimefang_icy_blast::HandleTriggerMissile, EFFECT_1, SPELL_EFFECT_TRIGGER_MISSILE);
    }
};

class OrderWhelpTargetSelector
{
    public:
        explicit OrderWhelpTargetSelector(Creature* owner) : _owner(owner) { }

        bool operator()(Creature* creature)
        {
            if (!creature->AI()->GetData(DATA_WHELP_MARKER) && creature->AI()->GetData(DATA_FROSTWYRM_OWNER) == _owner->AI()->GetData(DATA_FROSTWYRM_OWNER))
                return false;
            return true;
        }

    private:
        Creature* _owner;
};

// 71357 - Order Whelp
class spell_frostwarden_handler_order_whelp : public SpellScript
{
    PrepareSpellScript(spell_frostwarden_handler_order_whelp);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_FOCUS_FIRE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(Trinity::ObjectTypeIdCheck(TYPEID_PLAYER, false));
        if (targets.empty())
            return;

        WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
        targets.clear();
        targets.push_back(target);
    }

    void HandleForcedCast(SpellEffIndex effIndex)
    {
        // caster is Frostwarden Handler, target is player, caster of triggered is whelp
        PreventHitDefaultEffect(effIndex);
        std::list<Creature*> unitList;
        GetCreatureListWithEntryInGrid(unitList, GetCaster(), NPC_FROSTWING_WHELP, 150.0f);
        if (Creature* creature = GetCaster()->ToCreature())
            unitList.remove_if(OrderWhelpTargetSelector(creature));

        if (unitList.empty())
            return;

        Trinity::Containers::SelectRandomContainerElement(unitList)->CastSpell(GetHitUnit(), uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_frostwarden_handler_order_whelp::HandleForcedCast, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_frostwarden_handler_order_whelp::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

// 71350 - Focus Fire
class spell_frostwarden_handler_focus_fire : public SpellScript
{
    PrepareSpellScript(spell_frostwarden_handler_focus_fire);

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetCaster()->GetThreatManager().AddThreat(GetHitUnit(), float(GetEffectValue()), GetSpellInfo(), true, true);
        GetCaster()->GetAI()->SetData(DATA_WHELP_MARKER, 1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_frostwarden_handler_focus_fire::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_frostwarden_handler_focus_fire_aura : public AuraScript
{
    PrepareAuraScript(spell_frostwarden_handler_focus_fire_aura);

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (Unit* caster = GetCaster())
        {
            caster->GetThreatManager().AddThreat(GetTarget(), -float(GetEffectInfo(EFFECT_1).CalcValue()), GetSpellInfo(), true, true);
            caster->GetAI()->SetData(DATA_WHELP_MARKER, 0);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_frostwarden_handler_focus_fire_aura::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 69712 - Ice Tomb (Target)
class spell_sindragosa_ice_tomb_target : public SpellScript
{
    PrepareSpellScript(spell_sindragosa_ice_tomb_target);

    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        Unit* caster = GetCaster();
        unitList.remove_if(FrostBeaconSelector(caster));
    }

    void HandleSindragosaTalk(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creatureCaster = GetCaster()->ToCreature())
            if (creatureCaster->GetAI()->GetData(DATA_IS_THIRD_PHASE))
                creatureCaster->AI()->Talk(EMOTE_WARN_FROZEN_ORB, GetHitUnit());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sindragosa_ice_tomb_target::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectLaunchTarget += SpellEffectFn(spell_sindragosa_ice_tomb_target::HandleSindragosaTalk, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class at_sindragosa_lair : public AreaTriggerScript
{
    public:
        at_sindragosa_lair() : AreaTriggerScript("at_sindragosa_lair") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            if (InstanceScript* instance = player->GetInstanceScript())
            {
                if (!instance->GetData(DATA_SPINESTALKER))
                    if (Creature* spinestalker = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_SPINESTALKER)))
                        spinestalker->AI()->DoAction(ACTION_START_FROSTWYRM);

                if (!instance->GetData(DATA_RIMEFANG))
                    if (Creature* rimefang = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_RIMEFANG)))
                        rimefang->AI()->DoAction(ACTION_START_FROSTWYRM);

                if (!instance->GetData(DATA_SINDRAGOSA_FROSTWYRMS) && !instance->GetGuidData(DATA_SINDRAGOSA) && instance->GetBossState(DATA_SINDRAGOSA) != DONE)
                {
                    if (player->GetMap()->IsHeroic() && !instance->GetData(DATA_HEROIC_ATTEMPTS))
                        return true;

                    player->GetMap()->LoadGrid(SindragosaSpawnPos.GetPositionX(), SindragosaSpawnPos.GetPositionY());
                    if (Creature* sindragosa = player->GetMap()->SummonCreature(NPC_SINDRAGOSA, SindragosaSpawnPos))
                        sindragosa->AI()->DoAction(ACTION_START_FROSTWYRM);
                }
            }

            return true;
        }
};

class achievement_all_you_can_eat : public AchievementCriteriaScript
{
    public:
        achievement_all_you_can_eat() : AchievementCriteriaScript("achievement_all_you_can_eat") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;
            return target->GetAI()->GetData(DATA_MYSTIC_BUFFET_STACK) <= 5;
        }
};

void AddSC_boss_sindragosa()
{
    // Creatures
    RegisterIcecrownCitadelCreatureAI(boss_sindragosa);
    RegisterIcecrownCitadelCreatureAI(npc_ice_tomb);
    RegisterIcecrownCitadelCreatureAI(npc_spinestalker);
    RegisterIcecrownCitadelCreatureAI(npc_rimefang_icc);
    RegisterIcecrownCitadelCreatureAI(npc_sindragosa_trash);

    // Spells
    RegisterSpellScript(spell_sindragosa_s_fury);
    RegisterSpellScript(spell_sindragosa_unchained_magic);
    RegisterSpellScript(spell_sindragosa_frost_breath);
    RegisterSpellScript(spell_sindragosa_instability);
    RegisterSpellScript(spell_sindragosa_frost_beacon);
    RegisterSpellScript(spell_sindragosa_ice_tomb_trap);
    RegisterSpellScript(spell_sindragosa_icy_grip);
    RegisterSpellScript(spell_sindragosa_mystic_buffet);
    RegisterSpellScript(spell_rimefang_icy_blast);
    RegisterSpellScript(spell_frostwarden_handler_order_whelp);
    RegisterSpellAndAuraScriptPair(spell_frostwarden_handler_focus_fire, spell_frostwarden_handler_focus_fire_aura);
    RegisterSpellScriptWithArgs(spell_trigger_spell_from_caster, "spell_sindragosa_ice_tomb", SPELL_ICE_TOMB_DUMMY, TRIGGERED_IGNORE_SET_FACING);
    RegisterSpellScriptWithArgs(spell_trigger_spell_from_caster, "spell_sindragosa_ice_tomb_dummy", SPELL_FROST_BEACON);
    RegisterSpellScript(spell_sindragosa_ice_tomb_target);

    // AreaTriggers
    new at_sindragosa_lair();

    // Achievements
    new achievement_all_you_can_eat();
}
