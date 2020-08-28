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

#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Unit.h"
#include "SpellInfo.h"
#include "zulgurub.h"

enum Yells
{
    // Jin'do the Godbreaker
    SAY_INTRO                       = 0,
    SAY_AGGRO                       = 1,
    SAY_ANNOUNCE_SHADOWS_OF_HAKKAR  = 2,
    SAY_JINDO_SPIRIT_PHASE          = 3,

    // Spirit of Hakkar
    SAY_HAKKAR_IMPRISONED           = 0,
    SAY_HAKKAR_FREED                = 1,

    // Jin'do the Godbreaker - Trigger
    SAY_JINDO_DEFEATED              = 0,

    // Shadow of Hakkar
    SAY_SHADOW_DEFEATED             = 0
};

enum Spells
{
    // Jin'do the Godbreaker
    SPELL_DRAIN_SPIRIT_ESSENCE          = 97321,
    SPELL_ADD_PLAYERS_TO_THREAT_LIST    = 100401,
    SPELL_SPIRIT_WORLD                  = 98861,
    SPELL_VANISH                        = 97002,
    SPELL_SHADOWS_OF_HAKKAR             = 97172,
    SPELL_DEADZONE                      = 97170,
    SPELL_SHADOW_SPIKE                  = 97158,
    SPELL_CALL_SPIRIT                   = 97152,
    SPELL_TRANSFORM                     = 96716,

    // Hakkar's Spirit
    SPELL_HAKKAR_BREAKS_FREE            = 97209,

    // Hakkar's Chains
    SPELL_BRITTLE_BARRIER               = 97417,
    SPELL_HAKKARS_CHAINS                = 97022,
    SPELL_HAKKARS_CHAINS_VISUAL         = 97091,
    SPELL_ARCANE_EXPLOSION_VISUAL       = 97032,

    // Spirit Portal
    SPELL_SUMMON_SPIRIT                 = 97123,

    // Gurubashi Spirit Warrior
    SPELL_FRENZY                        = 97088,
    SPELL_SPIRIT_WARRIORS_GAZE          = 97597,

    // Sundered Rift
    SPELL_SUNDER_RIFT                   = 97320
};

enum Events
{
    // Jin'do the Godbreaker
    EVENT_TALK_INTRO = 1,
    EVENT_DRAIN_SPIRIT_ESSENCE,
    EVENT_SHADOWS_OF_HAKKAR,
    EVENT_DEADZONE,
    EVENT_ENTER_SPIRIT_WORLD,
    EVENT_TALK_SPIRIT_OF_HAKKAR,
    EVENT_SHADOW_SPIKE,
    EVENT_CALL_SPIRIT,

    // Gurubashi Spirit Warrior
    EVENT_FRENZY,
    EVENT_SPIRIT_WARRIORS_GAZE
};

enum Phases
{
    PHASE_PRE_FIGHT = 1,
    PHASE_ONE       = 2,
    PHASE_TWO       = 3
};

enum GurubashiSpiritWarriorMask
{
    GURUBASHI_SPIRIT_WARRIOR_MASK_1 = 0x1,
    GURUBASHI_SPIRIT_WARRIOR_MASK_2 = 0x2,
    GURUBASHI_SPIRIT_WARRIOR_MASK_3 = 0x4,
    GURUBASHI_SPIRIT_WARRIOR_MASK_4 = 0x8
};

uint8 gurubashiSpiritWarriorMaskByIndex[4] =
{
    GURUBASHI_SPIRIT_WARRIOR_MASK_1,
    GURUBASHI_SPIRIT_WARRIOR_MASK_2,
    GURUBASHI_SPIRIT_WARRIOR_MASK_3,
    GURUBASHI_SPIRIT_WARRIOR_MASK_4
};

enum MovementPoints
{
    POINT_ENTER_SPIRIT_WORLD = 1
};

enum SummonGroups
{
    SUMMON_GROUP_HAKKARS_CHAINS_1   = 0,
    SUMMON_GROUP_HAKKARS_CHAINS_2   = 1,
    SUMMON_GROUP_HAKKARS_CHAINS_3   = 2,
    SUMMON_GROUP_TWISTED_SHADOW     = 3,
    SUMMON_GROUP_SPIRIT_PORTAL      = 4
};

enum ZGPhaseIds
{
    PHASE_ID_DEFAULT        = 169,
    PHASE_ID_SPIRIT_WORLD   = 173
};

enum Sounds
{
    SOUND_SPIRIT_OF_HAKKAR_LAUGH = 24245
};

enum Actions
{
    // ACTION_TRIGGER_JINDO_INTRO = 0 (zulgurub.h)
    ACTION_DESPAWN_HAKKAR_AND_JINDO = 1
};

Position const JindoPhaseTwoMovePosition                = { -11787.0f,  -1695.73f, 52.95971f };
Position const JindoTheGodBreakerSpiritWorldSummonPos   = { -11786.32f, -1715.629f, 43.72891f, 1.466077f };
Position const HakkarSummonPos                          = { -11786.46f, -1690.924f, 53.01948f, 1.605703f };

Position const GurubashiSpiritWarriorPositions[] =
{
    { -11842.13f, -1595.407f, 40.80637f, 1.887366f },
    { -11738.26f, -1591.258f, 40.80482f, 2.184395f },
    { -11836.9f,  -1699.074f, 40.80555f, 6.147334f },
    { -11735.41f, -1696.579f, 40.80545f, 4.828507f }
};

class FaceToJindoEvent : public BasicEvent
{
    public:
        FaceToJindoEvent(Creature* owner) :  _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->SetFacingTo(4.712389f);
            return true;
        }
    private:
        Creature* _owner;
};

class DelayedTalkEvent : public BasicEvent
{
    public:
        DelayedTalkEvent(Creature* owner, uint8 textId) :  _owner(owner), _textId(textId) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            if (_owner->IsAIEnabled)
                _owner->AI()->Talk(_textId);
            return true;
        }
    private:
        Creature* _owner;
        uint8 _textId;
};

class AttackJindoEvent : public BasicEvent
{
    public:
        AttackJindoEvent(Creature* owner) :  _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->HandleEmoteCommand(EMOTE_ONESHOT_ATTACK1H);

            if (InstanceScript* instance = _owner->GetInstanceScript())
                if (Creature* jindo = instance->GetCreature(DATA_JINDO_THE_GODBREAKER))
                    jindo->AI()->DoAction(ACTION_DESPAWN_HAKKAR_AND_JINDO);

            return true;
        }
    private:
        Creature* _owner;
};

struct boss_jindo_the_godbreaker : public BossAI
{
    boss_jindo_the_godbreaker(Creature* creature) : BossAI(creature, DATA_JINDO_THE_GODBREAKER)
    {
        Initialize();
    }

    void Initialize()
    {
        _brokenChainsCount = 0;
    }

    void Reset() override
    {
        _Reset();
        Initialize();
        events.SetPhase(PHASE_PRE_FIGHT);
        events.ScheduleEvent(EVENT_DRAIN_SPIRIT_ESSENCE, 1s, 0, PHASE_PRE_FIGHT);
        PhasingHandler::AddPhase(me, PHASE_ID_SPIRIT_WORLD, true);
    }

    void JustAppeared() override
    {
        SetupEncounter();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        Talk(SAY_AGGRO);
        events.SetPhase(PHASE_ONE);
        events.ScheduleEvent(EVENT_SHADOWS_OF_HAKKAR, 21s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_DEADZONE, 13s, 0, PHASE_ONE);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        DoCastSelf(SPELL_TRANSFORM, true);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(70, damage) && !events.IsInPhase(PHASE_TWO))
        {
            events.SetPhase(PHASE_TWO);
            me->InterruptNonMeleeSpells(true);
            me->AttackStop();
            me->SetReactState(REACT_PASSIVE);
            me->GetMotionMaster()->MovePoint(POINT_ENTER_SPIRIT_WORLD, JindoPhaseTwoMovePosition);
            Talk(SAY_JINDO_SPIRIT_PHASE);
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
            return;

        if (id == POINT_ENTER_SPIRIT_WORLD)
        {
            me->SetFacingTo(1.570796f);
            events.ScheduleEvent(EVENT_ENTER_SPIRIT_WORLD, 1s);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_HAKKARS_CHAINS:
                summon->CastSpell(summon, SPELL_HAKKARS_CHAINS_VISUAL);
                summon->CastSpell(summon, SPELL_BRITTLE_BARRIER);
                summon->CastSpell(summon, SPELL_HAKKARS_CHAINS);
                summon->SetReactState(REACT_PASSIVE);
                summon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                [[fallthrough]];
            case NPC_JINDO_THE_GODBREAKER:
            case NPC_SPIRIT_OF_HAKKAR:
            case NPC_GURUBASHI_SPIRIT:
            case NPC_SPIRIT_PORTAL:
                PhasingHandler::AddPhase(summon, PHASE_ID_SPIRIT_WORLD, true);
                PhasingHandler::RemovePhase(summon, PHASE_ID_DEFAULT, true);
                break;
            case NPC_TWISTED_SPIRIT:
                if (TempSummon* creature = summon->ToTempSummon())
                {
                    if (Creature* summoner = creature->GetSummonerCreatureBase())
                    {
                        if (summoner->GetEntry() == NPC_SPIRIT_PORTAL)
                            if (summon->IsAIEnabled)
                                summon->AI()->DoZoneInCombat();
                    }
                    else
                    {
                        PhasingHandler::AddPhase(summon, PHASE_ID_SPIRIT_WORLD, true);
                        PhasingHandler::RemovePhase(summon, PHASE_ID_DEFAULT, true);
                        summon->GetMotionMaster()->MoveRandom(5.0f);
                    }
                }
                break;
            case NPC_TWISTED_SHADOW:
                summon->GetMotionMaster()->MoveRandom(5.0f);
                if (Map* map = summon->GetMap())
                    map->SummonCreature(NPC_TWISTED_SPIRIT, summon->GetPosition());
                break;
            default:
                break;
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        switch (summon->GetEntry())
        {
            case NPC_GURUBASHI_SPIRIT_WARRIOR:
                if (berserkersByMaskMap.find(summon->GetGUID()) != berserkersByMaskMap.end())
                {
                    uint32 killedSpiritWarriorMask = instance->GetData(DATA_KILLED_GURUBASHI_SPIRIT_WARRIORS);
                    instance->SetData(DATA_KILLED_GURUBASHI_SPIRIT_WARRIORS, killedSpiritWarriorMask | berserkersByMaskMap[summon->GetGUID()]);

                    Map* map = me->GetMap();
                    if (!map)
                        return;

                    if (Creature* shadow = map->SummonCreature(NPC_GURUBASHI_SHADOW, summon->GetHomePosition()))
                    {
                        shadow->SetReactState(REACT_PASSIVE);
                        shadow->GetMotionMaster()->MoveRandom(8.0f);
                    }

                    if (Creature* spirit = map->SummonCreature(NPC_GURUBASHI_SPIRIT, summon->GetHomePosition()))
                        spirit->GetMotionMaster()->MoveRandom(8.0f);
                }
                break;
            case NPC_HAKKARS_CHAINS:
                summon->DespawnOrUnsummon(2s + 500ms);
                if (Creature* spirit = instance->GetCreature(DATA_SPIRIT_OF_HAKKAR))
                {
                    if (_brokenChainsCount < 2)
                        spirit->PlayDirectSound(SOUND_SPIRIT_OF_HAKKAR_LAUGH);
                    else
                    {
                        for (ObjectGuid guid : summons)
                        {
                            if (Creature* summon = ObjectAccessor::GetCreature(*me, guid))
                            {
                                if (summon->GetEntry() != NPC_JINDO_THE_GODBREAKER && summon->GetEntry() != NPC_SPIRIT_OF_HAKKAR
                                    && summon->GetEntry() != NPC_SHADOW_OF_HAKKAR)
                                {
                                    summon->KillSelf();
                                    summon->DespawnOrUnsummon(1s);
                                }
                            }
                        }

                        if (spirit->IsAIEnabled)
                            spirit->AI()->Talk(SAY_HAKKAR_FREED);

                        spirit->CastSpell(spirit, SPELL_HAKKAR_BREAKS_FREE);

                        me->KillSelf();
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        spirit->m_Events.AddEventAtOffset(new FaceToJindoEvent(spirit), 1s + 500ms);
                        spirit->m_Events.AddEventAtOffset(new AttackJindoEvent(spirit), 19s + 500ms);

                        if (Creature* shadow = instance->GetCreature(DATA_SHADOW_OF_HAKKAR))
                        {
                            shadow->m_Events.AddEventAtOffset(new DelayedTalkEvent(shadow, SAY_SHADOW_DEFEATED), 22s + 100ms);
                            shadow->DespawnOrUnsummon(28s);
                        }

                        if (Creature* jindo = instance->GetCreature(DATA_JINDO_THE_GODBREAKER_SPIRIT_WORLD))
                        {
                            jindo->InterruptNonMeleeSpells(true);
                            jindo->m_Events.AddEventAtOffset(new DelayedTalkEvent(jindo, SAY_JINDO_DEFEATED), 18s + 500ms);
                        }
                    }
                    _brokenChainsCount++;
                }
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_TRIGGER_JINDO_INTRO:
                if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveAurasDueToSpell(SPELL_COSMETIC_ALPHA_STATE_25_PCT);
                    events.ScheduleEvent(EVENT_TALK_INTRO, 11s, 0, PHASE_PRE_FIGHT);
                }
                break;
            case ACTION_DESPAWN_HAKKAR_AND_JINDO:
                me->RemoveAurasDueToSpell(SPELL_SPIRIT_WORLD);
                summons.DespawnEntry(NPC_JINDO_THE_GODBREAKER);
                summons.DespawnEntry(NPC_SPIRIT_OF_HAKKAR);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !events.IsInPhase(PHASE_PRE_FIGHT))
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TALK_INTRO:
                    Talk(SAY_INTRO);
                    break;
                case EVENT_DRAIN_SPIRIT_ESSENCE:
                    DoCastSelf(SPELL_DRAIN_SPIRIT_ESSENCE);
                    events.Repeat(20s);
                    break;
                case EVENT_SHADOWS_OF_HAKKAR:
                    DoCastSelf(SPELL_SHADOWS_OF_HAKKAR);
                    Talk(SAY_ANNOUNCE_SHADOWS_OF_HAKKAR);
                    events.Repeat(19s, 20s);
                    break;
                case EVENT_DEADZONE:
                    DoCastSelf(SPELL_DEADZONE);
                    events.Repeat(19s, 20s);
                    break;
                case EVENT_ENTER_SPIRIT_WORLD:
                    DoCastAOE(SPELL_ADD_PLAYERS_TO_THREAT_LIST);
                    DoCastAOE(SPELL_SPIRIT_WORLD);
                    DoCastSelf(SPELL_VANISH);
                    events.ScheduleEvent(EVENT_TALK_SPIRIT_OF_HAKKAR, 5s, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_SHADOW_SPIKE, 2s + 500ms, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_CALL_SPIRIT, 6s, 0, PHASE_TWO);
                    break;
                case EVENT_TALK_SPIRIT_OF_HAKKAR:
                    if (Creature* hakkar = instance->GetCreature(DATA_SPIRIT_OF_HAKKAR))
                        if (hakkar->IsAIEnabled)
                            hakkar->AI()->Talk(SAY_HAKKAR_IMPRISONED);
                    break;
                case EVENT_SHADOW_SPIKE:
                    if (Creature* jindo = instance->GetCreature(DATA_JINDO_THE_GODBREAKER_SPIRIT_WORLD))
                        jindo->CastSpell(jindo, SPELL_SHADOW_SPIKE);
                    events.Repeat(3s + 500ms);
                    break;
                case EVENT_CALL_SPIRIT:
                    if (Creature* jindo = instance->GetCreature(DATA_JINDO_THE_GODBREAKER_SPIRIT_WORLD))
                        jindo->CastSpell(jindo, SPELL_CALL_SPIRIT);
                    events.Repeat(11s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    void SetupEncounter()
    {
        Map* map = me->GetMap();
        if (!map)
            return;

        // We need to summon the creatures via map to avoid them to use Jin'do's PhaseShift

        if (Creature* jindo = map->SummonCreature(NPC_JINDO_THE_GODBREAKER, JindoTheGodBreakerSpiritWorldSummonPos))
            jindo->SetReactState(REACT_PASSIVE);

        if (Creature* spirit = map->SummonCreature(NPC_SPIRIT_OF_HAKKAR, HakkarSummonPos))
            spirit->SetReactState(REACT_PASSIVE);

        if (Creature* shadow = map->SummonCreature(NPC_SHADOW_OF_HAKKAR, HakkarSummonPos))
            shadow->SetReactState(REACT_PASSIVE);

        map->SummonCreatureGroup(urand(SUMMON_GROUP_HAKKARS_CHAINS_1, SUMMON_GROUP_HAKKARS_CHAINS_3));
        map->SummonCreatureGroup(SUMMON_GROUP_TWISTED_SHADOW);
        map->SummonCreatureGroup(SUMMON_GROUP_SPIRIT_PORTAL);

        uint32 killedSpiritWarriorMask = instance->GetData(DATA_KILLED_GURUBASHI_SPIRIT_WARRIORS);
        for (uint8 i = 0; i < 4; i++)
        {
            if (!(killedSpiritWarriorMask & gurubashiSpiritWarriorMaskByIndex[i]))
            {
                if (Creature* warrior = map->SummonCreature(NPC_GURUBASHI_SPIRIT_WARRIOR, GurubashiSpiritWarriorPositions[i]))
                {
                    warrior->GetMotionMaster()->MoveRandom(8.0f);
                    berserkersByMaskMap.emplace(warrior->GetGUID(), gurubashiSpiritWarriorMaskByIndex[i]);
                }
            }
            else
            {
                if (Creature* shadow = map->SummonCreature(NPC_GURUBASHI_SHADOW, GurubashiSpiritWarriorPositions[i]))
                    shadow->GetMotionMaster()->MoveRandom(8.0f);

                if (Creature* spirit = map->SummonCreature(NPC_GURUBASHI_SPIRIT, GurubashiSpiritWarriorPositions[i]))
                    spirit->GetMotionMaster()->MoveRandom(8.0f);
            }
        }
    }

    std::unordered_map<ObjectGuid, uint8> berserkersByMaskMap;
    uint8 _brokenChainsCount;
};

struct npc_jindo_gurubashi_spirit_warrior : public ScriptedAI
{
    npc_jindo_gurubashi_spirit_warrior(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript()) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_FRENZY, 5s);
        _events.ScheduleEvent(EVENT_SPIRIT_WARRIORS_GAZE, 11s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _events.Reset();
        _EnterEvadeMode();
        me->GetMotionMaster()->MoveTargetedHome();
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_BROKEN_GROUND)
            summon->ApplySpellImmune(0, IMMUNITY_ID, SPELL_SUNDER_RIFT, true);
    }

    void JustDied(Unit* killer) override
    {
        if (Creature* jindo = _instance->GetCreature(DATA_JINDO_THE_GODBREAKER))
            jindo->AI()->SummonedCreatureDies(me, killer);

        if (me->GetEntry() == NPC_GURUBASHI_SPIRIT)
            me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FRENZY:
                    DoCastSelf(SPELL_FRENZY);
                    _events.Repeat(5s);
                    break;
                case EVENT_SPIRIT_WARRIORS_GAZE:
                    DoCastAOE(SPELL_SPIRIT_WARRIORS_GAZE);
                    _events.RescheduleEvent(EVENT_FRENZY, 3s + 700ms);
                    _events.Repeat(22s);
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
};

struct spell_jindo_shadow_spike : public SpellScript
{
    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_jindo_shadow_spike::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

struct spell_jindo_call_spirit : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_SPIRIT });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_SPIRIT, false);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_jindo_call_spirit::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

struct spell_jindo_spirit_warriors_gaze : public SpellScript
{
    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, false);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_jindo_spirit_warriors_gaze::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

struct spell_jindo_body_slam : public SpellScript
{
    void HandleShieldBreakEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitCreature();
        if (!target)
            return;

        if (target->GetEntry() == NPC_HAKKARS_CHAINS && target->HasAura(SPELL_BRITTLE_BARRIER))
        {
            target->RemoveAurasDueToSpell(SPELL_BRITTLE_BARRIER);
            target->CastSpell(target, SPELL_ARCANE_EXPLOSION_VISUAL);
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_jindo_body_slam::HandleShieldBreakEffect, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

void AddSC_boss_jindo_the_godbreaker()
{
    RegisterZulGurubCreatureAI(boss_jindo_the_godbreaker);
    RegisterZulGurubCreatureAI(npc_jindo_gurubashi_spirit_warrior);
    RegisterSpellScript(spell_jindo_shadow_spike);
    RegisterSpellScript(spell_jindo_call_spirit);
    RegisterSpellScript(spell_jindo_spirit_warriors_gaze);
    RegisterSpellScript(spell_jindo_body_slam);
}
