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
#include "CellImpl.h"
#include "Containers.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Texts
{
    // The Lich King
    SAY_LICH_KING_INTRO         = 0,

    // Valithria Dreamwalker
    SAY_VALITHRIA_ENTER_COMBAT  = 0,
    SAY_VALITHRIA_DREAM_PORTAL  = 1,
    SAY_VALITHRIA_75_PERCENT    = 2,
    SAY_VALITHRIA_25_PERCENT    = 3,
    SAY_VALITHRIA_DEATH         = 4,
    SAY_VALITHRIA_PLAYER_DEATH  = 5,
    SAY_VALITHRIA_BERSERK       = 6,
    SAY_VALITHRIA_SUCCESS       = 7,
};

enum Spells
{
    // Valithria Dreamwalker
    SPELL_COPY_DAMAGE                   = 71948,
    SPELL_DREAM_PORTAL_VISUAL_PRE       = 71304,
    SPELL_NIGHTMARE_PORTAL_VISUAL_PRE   = 71986,
    SPELL_NIGHTMARE_CLOUD               = 71970,
    SPELL_NIGHTMARE_CLOUD_VISUAL        = 71939,
    SPELL_PRE_SUMMON_DREAM_PORTAL       = 72224,
    SPELL_PRE_SUMMON_NIGHTMARE_PORTAL   = 72480,
    SPELL_SUMMON_DREAM_PORTAL           = 71305,
    SPELL_SUMMON_NIGHTMARE_PORTAL       = 71987,
    SPELL_DREAMWALKERS_RAGE             = 71189,
    SPELL_DREAM_SLIP                    = 71196,
    SPELL_ACHIEVEMENT_CHECK             = 72706,
    SPELL_CLEAR_ALL                     = 71721,
    SPELL_CORRUPTION_VALITHRIA          = 70904,
    SPELL_MANA_VOID_AURA                = 71085,
    SPELL_COLUMN_OF_FROST_AURA          = 70715,
    SPELL_WEAKENED_SOUL                 = 72232,

    // The Lich King
    SPELL_TIMER_GLUTTONOUS_ABOMINATION  = 70915,
    SPELL_TIMER_SUPPRESSER              = 70912,
    SPELL_TIMER_BLISTERING_ZOMBIE       = 70914,
    SPELL_TIMER_RISEN_ARCHMAGE          = 70916,
    SPELL_TIMER_BLAZING_SKELETON        = 70913,
    SPELL_SUMMON_SUPPRESSER             = 70936,
    SPELL_RECENTLY_SPAWNED              = 72954,
    SPELL_SPAWN_CHEST                   = 71207,

    // Risen Archmage
    SPELL_CORRUPTION                    = 70602,
    SPELL_FROSTBOLT_VOLLEY              = 70759,
    SPELL_MANA_VOID                     = 71179,
    SPELL_COLUMN_OF_FROST               = 70704,
    SPELL_COLUMN_OF_FROST_DAMAGE        = 70702,

    // Blazing Skeleton
    SPELL_FIREBALL                      = 70754,
    SPELL_LEY_WASTE                     = 69325,

    // Suppresser
    SPELL_SUPPRESSION                   = 70588,

    // Blistering Zombie
    SPELL_ACID_BURST                    = 70744,

    // Gluttonous Abomination
    SPELL_GUT_SPRAY                     = 70633,
    SPELL_ROT_WORM_SPAWNER              = 70675,

    // Dream Cloud
    SPELL_EMERALD_VIGOR                 = 70873,

    // Nightmare Cloud
    SPELL_TWISTED_NIGHTMARE             = 71941,
};

#define SUMMON_PORTAL RAID_MODE<uint32>(SPELL_PRE_SUMMON_DREAM_PORTAL, SPELL_PRE_SUMMON_DREAM_PORTAL, \
                                        SPELL_PRE_SUMMON_NIGHTMARE_PORTAL, SPELL_PRE_SUMMON_NIGHTMARE_PORTAL)

#define EMERALD_VIGOR RAID_MODE<uint32>(SPELL_EMERALD_VIGOR, SPELL_EMERALD_VIGOR, \
                                        SPELL_TWISTED_NIGHTMARE, SPELL_TWISTED_NIGHTMARE)

enum Events
{
    // Valithria Dreamwalker
    EVENT_INTRO_TALK = 1,
    EVENT_BERSERK,
    EVENT_DREAM_PORTAL,
    EVENT_DREAM_SLIP,

    // The Lich King
    EVENT_GLUTTONOUS_ABOMINATION_SUMMONER,
    EVENT_SUPPRESSER_SUMMONER,
    EVENT_BLISTERING_ZOMBIE_SUMMONER,
    EVENT_RISEN_ARCHMAGE_SUMMONER,
    EVENT_BLAZING_SKELETON_SUMMONER,

    // Risen Archmage
    EVENT_FROSTBOLT_VOLLEY,
    EVENT_MANA_VOID,
    EVENT_COLUMN_OF_FROST,

    // Blazing Skeleton
    EVENT_FIREBALL,
    EVENT_LEY_WASTE,

    // Suppresser
    EVENT_SUPPRESSION,

    // Gluttonous Abomination
    EVENT_GUT_SPRAY,

    // Dream Cloud
    // Nightmare Cloud
    EVENT_CHECK_PLAYER,
    EVENT_EXPLODE,
};

enum Misc
{
    ACTION_ENTER_COMBAT    = 1,
    MISSED_PORTALS         = 2,
    ACTION_DEATH           = 3,
    ACTION_SETUP_ARCHMAGES = 4,
    DATA_SUPPRESSERS_COUNT = 4,
    POINT_VALITHRIA        = 42,
    SUMMON_GROUP_ALL       = 1,
    SUMMON_GROUP_10        = 2,
    SUMMON_GROUP_25        = 3
};

Position const ValithriaSpawnPos = {4210.813f, 2484.443f, 364.9558f, 0.01745329f};

struct ValithriaManaVoidSelector
{
        explicit ValithriaManaVoidSelector(WorldObject const* source) : _source(source)
        {
        }

        bool operator()(Unit* unit) const
        {
            return unit->GetPowerType() == POWER_MANA && _source->GetDistance(unit) > 15.0f;
        }

        WorldObject const* _source;
};

class ValithriaDelayedCastEvent : public BasicEvent
{
    public:
        ValithriaDelayedCastEvent(Creature* trigger, uint32 spellId, ObjectGuid originalCaster, Milliseconds despawnTime) : _trigger(trigger), _originalCaster(originalCaster), _spellId(spellId), _despawnTime(despawnTime)
        {
        }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _trigger->CastSpell(_trigger, _spellId, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                .SetOriginalCaster(_originalCaster));
            if (_despawnTime != 0s)
                _trigger->DespawnOrUnsummon(_despawnTime);
            return true;
        }

    private:
        Creature* _trigger;
        ObjectGuid _originalCaster;
        uint32 _spellId;
        Milliseconds _despawnTime;
};

class ValithriaAuraRemoveEvent : public BasicEvent
{
    public:
        ValithriaAuraRemoveEvent(Creature* trigger, uint32 spellId) : _trigger(trigger), _spellId(spellId)
        {
        }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _trigger->RemoveAurasDueToSpell(_spellId);
            return true;
        }

    private:
        Creature* _trigger;
        uint32 _spellId;
};

class ValithriaDespawner : public BasicEvent
{
    public:
        explicit ValithriaDespawner(Creature* creature) : _creature(creature)
        {
        }

        bool Execute(uint64 /*currTime*/, uint32 /*diff*/) override
        {
            Trinity::CreatureWorker<ValithriaDespawner> worker(_creature, *this);
            Cell::VisitGridObjects(_creature, worker, 333.0f);
            return true;
        }

        void operator()(Creature* creature) const
        {
            switch (creature->GetEntry())
            {
                case NPC_VALITHRIA_DREAMWALKER:
                    if (InstanceScript* instance = creature->GetInstanceScript())
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, creature);
                    [[fallthrough]];
                case NPC_BLAZING_SKELETON:
                case NPC_SUPPRESSER:
                case NPC_BLISTERING_ZOMBIE:
                case NPC_GLUTTONOUS_ABOMINATION:
                case NPC_MANA_VOID:
                case NPC_COLUMN_OF_FROST:
                case NPC_ROT_WORM:
                case NPC_RISEN_ARCHMAGE:
                case NPC_GREEN_DRAGON_COMBAT_TRIGGER:
                    break;
                default:
                    return;
            }

            creature->DespawnOrUnsummon(0s, 10s);
        }

    private:
        Creature* _creature;
};

struct boss_valithria_dreamwalker : public ScriptedAI
{
    boss_valithria_dreamwalker(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _portalCount(RAID_MODE<uint32>(3, 8, 3, 8))
    {
        Initialize();
        _spawnHealth = me->GetHealth();
    }

    void Initialize()
    {
        _missedPortals = 0;
        _under25PercentTalkDone = false;
        _over75PercentTalkDone = false;
        _justDied = false;
        _done = false;
    }

    void InitializeAI() override
    {
        if (CreatureData const* data = me->GetCreatureData())
            if (data->curhealth)
                _spawnHealth = data->curhealth;

        ScriptedAI::InitializeAI();
    }

    void Reset() override
    {
        _events.Reset();
        me->SetHealth(_spawnHealth);
        me->SetReactState(REACT_PASSIVE);
        me->LoadCreaturesAddon();
        // immune to percent heals
        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_OBS_MOD_HEALTH, true);
        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_HEAL_PCT, true);
        // Glyph of Dispel Magic - not a percent heal by effect, its cast with custom basepoints
        me->ApplySpellImmune(0, IMMUNITY_ID, 56131, true);
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        Initialize();
    }

    void AttackStart(Unit* /*target*/) override
    {
    }

    void DoAction(int32 action) override
    {
        if (action != ACTION_ENTER_COMBAT)
            return;

        DoCastSelf(SPELL_COPY_DAMAGE);
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        _events.ScheduleEvent(EVENT_INTRO_TALK, 15s);
        _events.ScheduleEvent(EVENT_DREAM_PORTAL, 45s, 48s);
        if (IsHeroic())
            _events.ScheduleEvent(EVENT_BERSERK, 420s);
    }

    void HealReceived(Unit* healer, uint32& heal) override
    {
        if (!me->hasLootRecipient())
            me->SetTappedBy(healer);

        me->LowerPlayerDamageReq(heal);

        // encounter complete
        if (me->HealthAbovePctHealed(100, heal) && !_done)
        {
            _done = true;
            Talk(SAY_VALITHRIA_SUCCESS);
            _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->RemoveAurasDueToSpell(SPELL_CORRUPTION_VALITHRIA);
            DoCastSelf(SPELL_ACHIEVEMENT_CHECK);
            DoCastAOE(SPELL_DREAMWALKERS_RAGE);
            _events.ScheduleEvent(EVENT_DREAM_SLIP, 3500ms);
            if (Creature* lichKing = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_VALITHRIA_LICH_KING)))
                lichKing->AI()->EnterEvadeMode();
        }
        else if (!_over75PercentTalkDone && me->HealthAbovePctHealed(75, heal))
        {
            _over75PercentTalkDone = true;
            Talk(SAY_VALITHRIA_75_PERCENT);
        }
        else if (_instance->GetBossState(DATA_VALITHRIA_DREAMWALKER) == NOT_STARTED)
        {
            if (Creature* archmage = me->FindNearestCreature(NPC_RISEN_ARCHMAGE, 30.0f))
                DoZoneInCombat(archmage); // on one of them, that will make it all start
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(25, damage))
        {
            if (!_under25PercentTalkDone)
            {
                _under25PercentTalkDone = true;
                Talk(SAY_VALITHRIA_25_PERCENT);
            }

            if (damage >= me->GetHealth())
            {
                damage = 0;
                if (!_justDied)
                {
                    _justDied = true;
                    Talk(SAY_VALITHRIA_DEATH);
                    _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    if (Creature* trigger = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_VALITHRIA_TRIGGER)))
                        trigger->AI()->DoAction(ACTION_DEATH);
                }
            }
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_DREAM_SLIP)
        {
            DoCastSelf(SPELL_CLEAR_ALL);
            DoCastSelf(SPELL_REPUTATION_BOSS_KILL, true);
            // this display id was found in sniff instead of the one on aura
            me->SetDisplayId(11686);
            me->SetUninteractible(true);
            me->DespawnOrUnsummon(4s);
            if (Creature* trigger = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_VALITHRIA_TRIGGER)))
                Unit::Kill(me, trigger);

            if (Creature* lichKing = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_VALITHRIA_LICH_KING)))
                lichKing->CastSpell(lichKing, SPELL_SPAWN_CHEST);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_DREAM_PORTAL_PRE_EFFECT)
        {
            summon->m_Events.AddEvent(new ValithriaDelayedCastEvent(summon, SPELL_SUMMON_DREAM_PORTAL, me->GetGUID(), 6s), summon->m_Events.CalculateTime(15s));
            summon->m_Events.AddEvent(new ValithriaAuraRemoveEvent(summon, SPELL_DREAM_PORTAL_VISUAL_PRE), summon->m_Events.CalculateTime(15s));
        }
        else if (summon->GetEntry() == NPC_NIGHTMARE_PORTAL_PRE_EFFECT)
        {
            summon->m_Events.AddEvent(new ValithriaDelayedCastEvent(summon, SPELL_SUMMON_NIGHTMARE_PORTAL, me->GetGUID(), 6s), summon->m_Events.CalculateTime(15s));
            summon->m_Events.AddEvent(new ValithriaAuraRemoveEvent(summon, SPELL_NIGHTMARE_PORTAL_VISUAL_PRE), summon->m_Events.CalculateTime(15s));
        }
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_DREAM_PORTAL || summon->GetEntry() == NPC_NIGHTMARE_PORTAL)
            if (summon->AI()->GetData(MISSED_PORTALS))
                ++_missedPortals;
    }

    void UpdateAI(uint32 diff) override
    {
        // does not enter combat
        if (_instance->GetBossState(DATA_VALITHRIA_DREAMWALKER) != IN_PROGRESS)
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INTRO_TALK:
                    Talk(SAY_VALITHRIA_ENTER_COMBAT);
                    break;
                case EVENT_BERSERK:
                    Talk(SAY_VALITHRIA_BERSERK);
                    break;
                case EVENT_DREAM_PORTAL:
                    if (!IsHeroic())
                        Talk(SAY_VALITHRIA_DREAM_PORTAL);
                    for (uint32 i = 0; i < _portalCount; ++i)
                        DoCastSelf(SUMMON_PORTAL);
                    _events.ScheduleEvent(EVENT_DREAM_PORTAL, 45s, 48s);
                    break;
                case EVENT_DREAM_SLIP:
                    DoCastSelf(SPELL_DREAM_SLIP);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == MISSED_PORTALS)
            return _missedPortals;

        return 0;
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    uint32 _spawnHealth;
    uint32 const _portalCount;
    uint32 _missedPortals;
    bool _under25PercentTalkDone;
    bool _over75PercentTalkDone;
    bool _justDied;
    bool _done;
};

struct npc_green_dragon_combat_trigger : public BossAI
{
    npc_green_dragon_combat_trigger(Creature* creature) : BossAI(creature, DATA_VALITHRIA_DREAMWALKER) { }

    void Reset() override
    {
        _Reset();
        me->SetReactState(REACT_PASSIVE);
        summons.DespawnAll();
        // Setup Archmages
        me->SummonCreatureGroup(SUMMON_GROUP_ALL);
        if (Is25ManRaid())
            me->SummonCreatureGroup(SUMMON_GROUP_25);
        else
            me->SummonCreatureGroup(SUMMON_GROUP_10);

        EntryCheckPredicate pred(NPC_RISEN_ARCHMAGE);
        summons.DoAction(ACTION_SETUP_ARCHMAGES, pred);
    }

    void JustEnteredCombat(Unit* target) override
    {
        if (IsEngaged())
            return;

        if (!instance->CheckRequiredBosses(DATA_VALITHRIA_DREAMWALKER, target->ToPlayer()))
        {
            EnterEvadeMode(EvadeReason::SequenceBreak);
            instance->DoCastSpellOnPlayers(LIGHT_S_HAMMER_TELEPORT);
            return;
        }

        EngagementStart(target);

        me->setActive(true);
        DoZoneInCombat();
        instance->SetBossState(DATA_VALITHRIA_DREAMWALKER, IN_PROGRESS);
        if (Creature* valithria = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VALITHRIA_DREAMWALKER)))
            valithria->AI()->DoAction(ACTION_ENTER_COMBAT);
        EntryCheckPredicate pred(NPC_RISEN_ARCHMAGE);
        summons.DoAction(ACTION_ENTER_COMBAT, pred);
    }

    void JustExitedCombat() override
    {
        EngagementOver();

        me->setActive(false);

        // JustExitedCombat is called on death too, so if creature is dead, avoid "respawn" event
        if (!me->IsAlive())
            return;
        DoAction(ACTION_DEATH);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_DEATH)
        {
            instance->SetBossState(DATA_VALITHRIA_DREAMWALKER, NOT_STARTED);
            me->m_Events.AddEventAtOffset(new ValithriaDespawner(me), 5s);
            if (Creature* lichKing = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VALITHRIA_LICH_KING)))
                lichKing->AI()->EnterEvadeMode();
        }
    }
};

struct npc_the_lich_king_controller : public ScriptedAI
{
    npc_the_lich_king_controller(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_GLUTTONOUS_ABOMINATION_SUMMONER, 5s);
        _events.ScheduleEvent(EVENT_SUPPRESSER_SUMMONER, 10s);
        _events.ScheduleEvent(EVENT_BLISTERING_ZOMBIE_SUMMONER, 15s);
        _events.ScheduleEvent(EVENT_RISEN_ARCHMAGE_SUMMONER, 20s);
        _events.ScheduleEvent(EVENT_BLAZING_SKELETON_SUMMONER, 30s);
        me->SetReactState(REACT_PASSIVE);
    }

    void JustReachedHome() override
    {
        me->setActive(false);
    }

    void JustEngagedWith(Unit* /*target*/) override
    {
        Talk(SAY_LICH_KING_INTRO);
        me->setActive(true);
    }

    uint32 GetData(uint32 data) const override
    {
        if (data == DATA_SUPPRESSERS_COUNT)
            return RAID_MODE<uint32>(4, 6, 4, 6);
        else
            return 0;
    }

    void JustSummoned(Creature* summon) override
    {
        // must not be in dream phase
        PhasingHandler::RemovePhase(summon, 173, true);
        DoZoneInCombat(summon);
        if (summon->GetEntry() != NPC_SUPPRESSER)
            if (Unit* target = me->GetCombatManager().GetAnyTarget())
                summon->AI()->AttackStart(target);
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
                case EVENT_GLUTTONOUS_ABOMINATION_SUMMONER:
                    DoCastSelf(SPELL_TIMER_GLUTTONOUS_ABOMINATION);
                    break;
                case EVENT_SUPPRESSER_SUMMONER:
                    DoCastSelf(SPELL_TIMER_SUPPRESSER);
                    break;
                case EVENT_BLISTERING_ZOMBIE_SUMMONER:
                    DoCastSelf(SPELL_TIMER_BLISTERING_ZOMBIE);
                    break;
                case EVENT_RISEN_ARCHMAGE_SUMMONER:
                    DoCastSelf(SPELL_TIMER_RISEN_ARCHMAGE);
                    break;
                case EVENT_BLAZING_SKELETON_SUMMONER:
                    DoCastSelf(SPELL_TIMER_BLAZING_SKELETON);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

struct npc_risen_archmage : public ScriptedAI
{
    npc_risen_archmage(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        _isInitialArchmage = false;
    }

    bool CanAIAttack(Unit const* target) const override
    {
        return target->GetEntry() != NPC_VALITHRIA_DREAMWALKER;
    }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_FROSTBOLT_VOLLEY, 5s, 15s);
        _events.ScheduleEvent(EVENT_MANA_VOID, 20s, 25s);
        _events.ScheduleEvent(EVENT_COLUMN_OF_FROST, 10s, 20s);
        Initialize();
    }

    void JustEnteredCombat(Unit* who) override
    {
        if (IsEngaged())
            return;

        me->InterruptNonMeleeSpells(false);

        EngagementStart(who);

        if (_isInitialArchmage)
        {
            if (Creature* lichKing = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_VALITHRIA_LICH_KING)))
                DoZoneInCombat(lichKing);

            if (Creature* trigger = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_VALITHRIA_TRIGGER)))
                DoZoneInCombat(trigger);
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_ENTER_COMBAT)
            DoZoneInCombat();
        else if (action == ACTION_SETUP_ARCHMAGES)
            _isInitialArchmage = true;
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_COLUMN_OF_FROST)
        {
            summon->CastSpell(summon, SPELL_COLUMN_OF_FROST_AURA, true);
            summon->m_Events.AddEvent(new ValithriaDelayedCastEvent(summon, SPELL_COLUMN_OF_FROST_DAMAGE, ObjectGuid::Empty, 8s), summon->m_Events.CalculateTime(2s));
        }
        else if (summon->GetEntry() == NPC_MANA_VOID)
        {
            summon->CastSpell(summon, SPELL_MANA_VOID_AURA, true);
            summon->DespawnOrUnsummon(36s);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!me->IsInCombat() && me->IsAlive() && _isInitialArchmage && !me->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
            DoCastSelf(SPELL_CORRUPTION);

        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FROSTBOLT_VOLLEY:
                    DoCastSelf(SPELL_FROSTBOLT_VOLLEY);
                    _events.ScheduleEvent(EVENT_FROSTBOLT_VOLLEY, 8s, 15s);
                    break;
                case EVENT_MANA_VOID:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, ValithriaManaVoidSelector(me)))
                        DoCast(target, SPELL_MANA_VOID);
                    _events.ScheduleEvent(EVENT_MANA_VOID, 20s, 25s);
                    break;
                case EVENT_COLUMN_OF_FROST:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, -10.0f, true))
                        DoCast(target, SPELL_COLUMN_OF_FROST);
                    _events.ScheduleEvent(EVENT_COLUMN_OF_FROST, 15s, 25s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    bool _isInitialArchmage;
};

struct npc_blazing_skeleton : public ScriptedAI
{
    npc_blazing_skeleton(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_FIREBALL, 2s, 4s);
        _events.ScheduleEvent(EVENT_LEY_WASTE, 15s, 20s);
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
                case EVENT_FIREBALL:
                    if (!me->IsWithinMeleeRange(me->GetVictim()))
                        DoCastVictim(SPELL_FIREBALL);
                    _events.ScheduleEvent(EVENT_FIREBALL, 2s, 4s);
                    break;
                case EVENT_LEY_WASTE:
                    DoCastSelf(SPELL_LEY_WASTE);
                    _events.ScheduleEvent(EVENT_LEY_WASTE, 15s, 20s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    EventMap _events;
};

struct npc_suppresser : public ScriptedAI
{
    npc_suppresser(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _events.Reset();
    }

    void IsSummonedBy(WorldObject* /*summoner*/) override
    {
        if (Creature* valithria = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_VALITHRIA_DREAMWALKER)))
        {
            me->EngageWithTarget(valithria);
            me->GetThreatManager().FixateTarget(valithria);
        }
        else
            me->DespawnOrUnsummon();
    }

    void MovementInform(uint32 type, uint32 /*id*/) override
    {
        if (type == CHASE_MOTION_TYPE)
            _events.RescheduleEvent(EVENT_SUPPRESSION, 1ms);
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
                case EVENT_SUPPRESSION:
                    DoCastAOE(SPELL_SUPPRESSION);
                    _events.Repeat(5s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    InstanceScript* const _instance;
};

struct npc_blistering_zombie : public ScriptedAI
{
    npc_blistering_zombie(Creature* creature) : ScriptedAI(creature) { }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastSelf(SPELL_ACID_BURST, true);
    }
};

struct npc_gluttonous_abomination : public ScriptedAI
{
    npc_gluttonous_abomination(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_GUT_SPRAY, 10s, 13s);
    }

    void JustDied(Unit* killer) override
    {
        if (killer && killer->GetEntry() == NPC_VALITHRIA_DREAMWALKER)
            return;

        DoCastSelf(SPELL_ROT_WORM_SPAWNER, true);
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
                case EVENT_GUT_SPRAY:
                    DoCastSelf(SPELL_GUT_SPRAY);
                    _events.ScheduleEvent(EVENT_GUT_SPRAY, 10s, 13s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

struct npc_dream_portal : public CreatureAI
{
    npc_dream_portal(Creature* creature) : CreatureAI(creature), _used(false) { }

    void OnSpellClick(Unit* /*clicker*/, bool spellClickHandled) override
    {
        if (!spellClickHandled)
            return;

        _used = true;
        me->DespawnOrUnsummon();
    }

    uint32 GetData(uint32 type) const override
    {
        return (type == MISSED_PORTALS && _used) ? 0 : 1;
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        UpdateVictim();
    }

private:
    bool _used;
};

struct npc_dream_cloud : public ScriptedAI
{
    npc_dream_cloud(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_CHECK_PLAYER, 1s);
        me->SetCorpseDelay(0); // remove corpse immediately
        me->LoadCreaturesAddon();
    }

    void UpdateAI(uint32 diff) override
    {
        // trigger
        if (_instance->GetBossState(DATA_VALITHRIA_DREAMWALKER) != IN_PROGRESS)
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CHECK_PLAYER:
                {
                    Player* player = nullptr;
                    Trinity::AnyPlayerInObjectRangeCheck check(me, 5.0f);
                    Trinity::PlayerSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, player, check);
                    Cell::VisitWorldObjects(me, searcher, 7.5f);
                    _events.ScheduleEvent(player ? EVENT_EXPLODE : EVENT_CHECK_PLAYER, 1s);
                    break;
                }
                case EVENT_EXPLODE:
                    me->GetMotionMaster()->MoveIdle();
                    // must use originalCaster the same for all clouds to allow stacking
                    me->CastSpell(me, EMERALD_VIGOR, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                        .SetOriginalCaster(_instance->GetGuidData(DATA_VALITHRIA_DREAMWALKER)));
                    me->DespawnOrUnsummon(100ms);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

// 71085 - Mana Void
class spell_dreamwalker_mana_void : public AuraScript
{
    void PeriodicTick(AuraEffect const* aurEff)
    {
        // first 3 ticks have amplitude 1 second
        // remaining tick every 500ms
        if (aurEff->GetTickNumber() <= 5)
            if (!(aurEff->GetTickNumber() & 1))
                PreventDefaultAction();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dreamwalker_mana_void::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 70912 - Summon Timer: Suppresser
// 70913 - Summon Timer: Blazing Skeleton
// 70915 - Summon Timer: Gluttonous Abomination
// 70916 - Summon Timer: Risen Archmage
class spell_dreamwalker_decay_periodic_timer : public AuraScript
{
    bool Load() override
    {
        _decayRate = GetId() != SPELL_TIMER_BLAZING_SKELETON ? 1000 : 5000;
        return true;
    }

    void DecayPeriodicTimer(AuraEffect* aurEff)
    {
        int32 timer = aurEff->GetPeriodicTimer();
        if (timer <= 5)
            return;

        aurEff->SetPeriodicTimer(timer - _decayRate);
    }

    void Register() override
    {
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_dreamwalker_decay_periodic_timer::DecayPeriodicTimer, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }

    int32 _decayRate = 0;
};

// 70921 - Summon Gluttonous Abomination
// 70933 - Summon Blazing Skeleton
// 71032 - Summon Blistering Zombie
// 71078 - Summon Risen Archmage
class spell_dreamwalker_summoner : public SpellScript
{
    bool Load() override
    {
        if (!GetCaster()->GetInstanceScript())
            return false;
        return true;
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_RECENTLY_SPAWNED));
        if (targets.empty())
            return;

        WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
        targets.clear();
        targets.push_back(target);
    }

    void HandleForceCast(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        if (!GetHitUnit())
            return;

        GetHitUnit()->CastSpell(GetCaster(), GetEffectInfo().TriggerSpell, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
            .SetOriginalCaster(GetCaster()->GetInstanceScript()->GetGuidData(DATA_VALITHRIA_LICH_KING)));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dreamwalker_summoner::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_dreamwalker_summoner::HandleForceCast, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
    }
};

// 70912 - Summon Timer: Suppresser
class spell_dreamwalker_summon_suppresser : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_SUPPRESSER });
    }

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        HandleSummon(GetCaster());
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        HandleSummon(GetCaster());
    }

    void HandleSummon(Unit* caster)
    {
        if (!caster || !caster->IsAIEnabled())
            return;

        std::list<Creature*> summoners;
        GetCreatureListWithEntryInGrid(summoners, caster, NPC_WORLD_TRIGGER, 90.0f);
        if (summoners.empty())
            return;

        uint8 suppresserNumber = caster->GetAI()->GetData(DATA_SUPPRESSERS_COUNT);
        for (uint8 i = 0; i < suppresserNumber; ++i)
            caster->CastSpell(Trinity::Containers::SelectRandomContainerElement(summoners), SPELL_SUMMON_SUPPRESSER, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dreamwalker_summon_suppresser::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        AfterEffectApply += AuraEffectApplyFn(spell_dreamwalker_summon_suppresser::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 70936 - Summon Suppresser
class spell_dreamwalker_summon_suppresser_effect : public SpellScript
{
    bool Load() override
    {
        if (!GetCaster()->GetInstanceScript())
            return false;
        return true;
    }

    void HandleForceCast(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        if (!GetHitUnit())
            return;

        GetHitUnit()->CastSpell(GetCaster(), GetEffectInfo().TriggerSpell, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
            .SetOriginalCaster(GetCaster()->GetInstanceScript()->GetGuidData(DATA_VALITHRIA_LICH_KING)));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dreamwalker_summon_suppresser_effect::HandleForceCast, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
    }
};

// 72224 - Summon Dream Portal
class spell_dreamwalker_summon_dream_portal : public SpellScript
{
    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        if (!GetHitUnit())
            return;

        uint32 spellId = RAND(71301, 72220, 72223, 72225);
        GetHitUnit()->CastSpell(GetHitUnit(), spellId, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dreamwalker_summon_dream_portal::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 72480 - Summon Nightmare Portal
class spell_dreamwalker_summon_nightmare_portal : public SpellScript
{
    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        if (!GetHitUnit())
            return;

        uint32 spellId = RAND(71977, 72481, 72482, 72483);
        GetHitUnit()->CastSpell(GetHitUnit(), spellId, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dreamwalker_summon_nightmare_portal::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 71970 - Nightmare Cloud
class spell_dreamwalker_nightmare_cloud : public AuraScript
{
public:
    spell_dreamwalker_nightmare_cloud()
    {
        _instance = nullptr;
    }

private:
    bool Load() override
    {
        _instance = GetOwner()->GetInstanceScript();
        return _instance != nullptr;
    }

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        if (_instance->GetBossState(DATA_VALITHRIA_DREAMWALKER) != IN_PROGRESS)
            PreventDefaultAction();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dreamwalker_nightmare_cloud::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }

    InstanceScript* _instance;
};

// 71941 - Twisted Nightmares
class spell_dreamwalker_twisted_nightmares : public SpellScript
{
    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);

        if (InstanceScript* instance = GetHitUnit()->GetInstanceScript())
            GetHitUnit()->CastSpell(nullptr, GetEffectInfo().TriggerSpell, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                .SetOriginalCaster(instance->GetGuidData(DATA_VALITHRIA_DREAMWALKER)));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dreamwalker_twisted_nightmares::HandleScript, EFFECT_2, SPELL_EFFECT_FORCE_CAST);
    }
};

// 47788 - Guardian Spirit
class spell_dreamwalker_guardian_spirit_restriction : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WEAKENED_SOUL });
    }

    bool Load() override
    {
        return InstanceHasScript(GetCaster(), ICCScriptName);
    }

    SpellCastResult SkipWithWeakenedSoul()
    {
        if (!GetExplTargetUnit() || GetExplTargetUnit()->HasAura(SPELL_WEAKENED_SOUL))
            return SPELL_FAILED_TARGET_AURASTATE;
        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dreamwalker_guardian_spirit_restriction::SkipWithWeakenedSoul);
    }
};

class achievement_portal_jockey : public AchievementCriteriaScript
{
    public:
        achievement_portal_jockey() : AchievementCriteriaScript("achievement_portal_jockey") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            return target && !target->GetAI()->GetData(MISSED_PORTALS);
        }
};

void AddSC_boss_valithria_dreamwalker()
{
    // Creatures
    RegisterIcecrownCitadelCreatureAI(boss_valithria_dreamwalker);
    RegisterIcecrownCitadelCreatureAI(npc_green_dragon_combat_trigger);
    RegisterIcecrownCitadelCreatureAI(npc_the_lich_king_controller);
    RegisterIcecrownCitadelCreatureAI(npc_risen_archmage);
    RegisterIcecrownCitadelCreatureAI(npc_blazing_skeleton);
    RegisterIcecrownCitadelCreatureAI(npc_suppresser);
    RegisterIcecrownCitadelCreatureAI(npc_blistering_zombie);
    RegisterIcecrownCitadelCreatureAI(npc_gluttonous_abomination);
    RegisterIcecrownCitadelCreatureAI(npc_dream_portal);
    RegisterIcecrownCitadelCreatureAI(npc_dream_cloud);

    // Spells
    RegisterSpellScript(spell_dreamwalker_mana_void);
    RegisterSpellScript(spell_dreamwalker_decay_periodic_timer);
    RegisterSpellScript(spell_dreamwalker_summoner);
    RegisterSpellScript(spell_dreamwalker_summon_suppresser);
    RegisterSpellScript(spell_dreamwalker_summon_suppresser_effect);
    RegisterSpellScript(spell_dreamwalker_summon_dream_portal);
    RegisterSpellScript(spell_dreamwalker_summon_nightmare_portal);
    RegisterSpellScript(spell_dreamwalker_nightmare_cloud);
    RegisterSpellScript(spell_dreamwalker_twisted_nightmares);

    // Achievements
    RegisterSpellScript(spell_dreamwalker_guardian_spirit_restriction);
    new achievement_portal_jockey();
}
