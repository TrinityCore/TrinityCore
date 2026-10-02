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

/*
 * Some details may be missing
 * SPELL_IS_DEAD_CHECK is NYI, what it does is unknown
 * Trash from instance start to first boss should not spawn if players entered instance by LFG (gameobjects like veins and herbs are spawned)
 * Verify if Synch Health has correct script effect
 * SPELL_AHUNE_RESURFACES doesn't work, caster is friendly to players?
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Group.h"
#include "InstanceScript.h"
#include "LFGMgr.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "the_slave_pens.h"

enum AhuneTexts
{
    // Ahune Summon Loc Bunny
    EMOTE_EARTHEN_ASSAULT               = 0,

    // Ahune (sender is guessed)
    EMOTE_WON                           = 0,

    // Earthen Ring Flamecaller
    EMOTE_RETREAT                       = 0,
    EMOTE_RESURFACE                     = 1,

    // Player
    TEXT_INTRO_1                        = 24895,
    TEXT_INTRO_2                        = 24893,
    TEXT_INTRO_3                        = 24894
};

enum AhuneSpells
{
    // Ahune - Combat - Initial
    SPELL_IS_DEAD_CHECK                 = 61976,
    SPELL_STAND                         = 37752,
    SPELL_AHUNES_SHIELD                 = 45954,
    SPELL_AHUNE_SPANKY_HANDS            = 46146,

    // Ahune - Combat
    SPELL_SYNCH_HEALTH                  = 46430,
    SPELL_SUICIDE                       = 45254,

    // Ahune - Combat - Submerge
    SPELL_SUBMERGED                     = 37751,
    SPELL_STAY_SUBMERGED                = 46981,
    SPELL_AHUNE_SELF_STUN               = 46416,

    // Ahune - Combat - Death
    SPELL_AHUNE_DIES_ACHIEVEMENT        = 62043,

    // Frozen Core
    SPELL_ICE_SPEAR_CONTROL_AURA        = 46371,
    SPELL_FROZEN_CORE_GETS_HIT          = 46810,
    SPELL_SUMMON_LOOT_MISSILE           = 45941,
    SPELL_MINION_DESPAWNER              = 46843,

    // Earthen Ring Flamecaller
    SPELL_FIND_OPENING_CHANNEL          = 46345,
    SPELL_FIND_OPENING_VISUAL_TRIGGER   = 46341,

    // Shaman Bonfire Bunny
    SPELL_BONFIRE_DISGUISE              = 46339,
    SPELL_FIND_OPENING_VISUAL           = 45964,

    // Ahune Summon Loc Bunny
    SPELL_SUMMONING_VISUAL_1            = 45937,
    SPELL_AHUNE_RESURFACES              = 46402,
    SPELL_SUMMON_HAILSTONE              = 46176,
    SPELL_SHAMANS_LOOK_FOR_OPENING      = 46422,
    SPELL_FOUND_OPENING                 = 46421,
    SPELL_CLOSE_OPENING_VISUAL          = 46236,
    SPELL_ICE_BOMBARD                   = 46397,

    // Ahune Ice Spear Bunny
    SPELL_SUMMON_ICE_SPEAR_GO           = 46369,
    SPELL_ICE_SPEAR_VISUAL              = 75498,
    SPELL_ICE_SPEAR_DELAY               = 46878,

    // Ice Stone
    SPELL_SUMMONING_RHYME_AURA          = 45926,

    // Scripts
    SPELL_FORCE_WHISP_FLIGHT_MISSILE    = 46603,
    SPELL_SUMMONING_RHYME_BONFIRE       = 45930,
    SPELL_SUMMON_COLDWEAVE              = 46143,
    SPELL_SUMMON_FROSTWIND              = 46382,
    SPELL_ICE_SPEAR_KNOCKBACK           = 46360,
    SPELL_ICE_SPEAR_TARGET_PICKER       = 46372,
    SPELL_SUMMON_ICE_SPEAR_BUNNY        = 46359,
    SPELL_SLIPPERY_FLOOR_SLIP           = 45947,
    SPELL_SLIPPERY_FLOOR_YOU_SLIPPED    = 45946,
    SPELL_COLD_SLAP                     = 46145,
    SPELL_ICE_BOMBARDMENT               = 46396,
    SPELL_FIND_OPENING_BEAM_END         = 46333,
    SPELL_BEAM_ATTACK_AGAINST_AHUNE     = 46336,
    SPELL_SPANK_KNOCK_TO                = 46734
};

enum AhuneEvents
{
    // Ahune
    EVENT_SUMMON_FROZEN_CORE            = 1,

    // Shared
    EVENT_SYNCH_HEALTH,
    EVENT_SUICIDE,

    // Ahune Summon Loc Bunny
    EVENT_INTRO_1,
    EVENT_INTRO_2,
    EVENT_INTRO_3,
    EVENT_SUMMON_HAILSTONE,
    EVENT_SUBMERGE,
    EVENT_RESURFACE_1,
    EVENT_RESURFACE_2,
    EVENT_RESURFACE_3
};

enum AhuneActions
{
    ACTION_START_EVENT,
    ACTION_STOP_EVENT_WIPE,
    ACTION_STOP_EVENT_WIN,
    ACTION_RESET_CREATURES,
    ACTION_STOP_VISUALS,
    ACTION_START_VISUALS,
    ACTION_RETREAT_EMOTE,
    ACTION_RESURFACE_EMOTE,
    ACTION_ACTIVATE_CORE,
    ACTION_DEACTIVATE_CORE
};

enum AhunePaths
{
    PATH_FLAMECALLER_1                  = 2027370,
    PATH_FLAMECALLER_2                  = 2027360,
    PATH_FLAMECALLER_3                  = 2027350
};

enum AhuneMisc
{
    LFG_DUNGEON_ID_AHUNE                = 286,
    POINT_HOME                          = 0,
    DATA_GHOST_OF_AHUNE                 = 0,
    DATA_SUMMON_COUNT                   = 1
};

static const Position AhuneSpawnPosition = { -99.10210f, -233.75261f, -1.2229697f, 1.567972064018249511f };
static const Position CoreSpawnPosition  = { -98.01508f, -230.45549f, -1.2108916f, 1.797689080238342285f };

// 25740 - Ahune
struct boss_ahune : public BossAI
{
    boss_ahune(Creature* creature) : BossAI(creature, DATA_AHUNE), _summonCount(0) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(20, true);
        BossAI::InitializeAI();
    }

    void JustAppeared() override
    {
        DoZoneInCombat();
        DoCastSelf(SPELL_IS_DEAD_CHECK);
        DoCastSelf(SPELL_STAND);
        DoCastSelf(SPELL_AHUNES_SHIELD);
        DoCastSelf(SPELL_AHUNE_SPANKY_HANDS);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_SUMMON_FROZEN_CORE, 5s);
        events.ScheduleEvent(EVENT_SUICIDE, 2s);
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_FROZEN_CORE)
            return;

        DoZoneInCombat(summon);
        summons.Summon(summon);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_FOUND_OPENING)
        {
            me->RemoveAurasDueToSpell(SPELL_AHUNES_SHIELD);
            DoCastSelf(SPELL_SUBMERGED, true);
            DoCastSelf(SPELL_STAY_SUBMERGED, true);
            DoCastSelf(SPELL_AHUNE_SELF_STUN, true);
            me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            me->SetStandState(UNIT_STAND_STATE_SUBMERGED);

            events.CancelEvent(EVENT_SYNCH_HEALTH);

            if (Creature* core = instance->GetCreature(DATA_FROZEN_CORE))
                core->AI()->DoAction(ACTION_ACTIVATE_CORE);
        }
        else if (spellInfo->Id == SPELL_SHAMANS_LOOK_FOR_OPENING)
        {
            DoCastSelf(SPELL_STAND, true);
            DoCastSelf(SPELL_AHUNES_SHIELD, true);
            DoCastSelf(SPELL_AHUNE_SPANKY_HANDS, true);
            me->RemoveAurasDueToSpell(SPELL_AHUNE_SELF_STUN);
            me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);

            events.ScheduleEvent(EVENT_SYNCH_HEALTH, 4s);
        }
    }

    void SetData(uint32 type, uint32 value) override
    {
        if (type == DATA_SUMMON_COUNT)
            _summonCount = value;
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_SUMMON_COUNT)
            return _summonCount;

        return 0;
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        Talk(EMOTE_WON);

        if (Creature* bunny = instance->GetCreature(DATA_AHUNE_BUNNY))
            bunny->AI()->DoAction(ACTION_STOP_EVENT_WIPE);

        if (Creature* frozenCore = instance->GetCreature(DATA_FROZEN_CORE))
            frozenCore->DespawnOrUnsummon();

        summons.DespawnAll();

        me->DespawnOrUnsummon();
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->DoCastSpellOnPlayers(SPELL_AHUNE_DIES_ACHIEVEMENT);

        if (Creature* bunny = instance->GetCreature(DATA_AHUNE_BUNNY))
            bunny->AI()->DoAction(ACTION_STOP_EVENT_WIN);

        Map::PlayerList const& players = me->GetMap()->GetPlayers();
        if (!players.isEmpty())
        {
            if (Group* group = players.begin()->GetSource()->GetGroup())
                if (group->isLFGGroup())
                    sLFGMgr->FinishDungeon(group->GetGUID(), LFG_DUNGEON_ID_AHUNE, me->GetMap());
        }

        _JustDied();
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_SUMMON_FROZEN_CORE:
                me->SummonCreature(NPC_FROZEN_CORE, CoreSpawnPosition, TEMPSUMMON_MANUAL_DESPAWN);
                break;
            case EVENT_SYNCH_HEALTH:
                if (Creature* frozenCore = instance->GetCreature(DATA_FROZEN_CORE))
                    DoCast(frozenCore, SPELL_SYNCH_HEALTH, true);
                events.Repeat(2s);
                break;
            case EVENT_SUICIDE:
                if (Creature* frozenCore = instance->GetCreature(DATA_FROZEN_CORE))
                    if (!frozenCore->IsAlive())
                        DoCastSelf(SPELL_SUICIDE, true);
                events.Repeat(2s);
                break;
            default:
                break;
        }
    }

private:
    uint32 _summonCount;
};

// 25865 - Frozen Core
struct npc_frozen_core : public ScriptedAI
{
    npc_frozen_core(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(5, true);
        me->SetReactState(REACT_PASSIVE);
        me->SetRegenerateHealth(false);
        ScriptedAI::InitializeAI();
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_ICE_SPEAR_CONTROL_AURA);
        DoCastSelf(SPELL_FROZEN_CORE_GETS_HIT);
        DoCastSelf(SPELL_IS_DEAD_CHECK);
        _events.ScheduleEvent(EVENT_SYNCH_HEALTH, 0s);
        _events.ScheduleEvent(EVENT_SUICIDE, 0s);
    }

    void Reset() override
    {
        _events.Reset();
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_ACTIVATE_CORE)
        {
            // Not correct, aura is not removed. It stops working for a while but starts working again before phase end,
            // making it impossible to simply check in aura script if core is uninteractible
            me->RemoveAurasDueToSpell(SPELL_ICE_SPEAR_CONTROL_AURA);
            me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            me->SetImmuneToPC(false);
        }
        else if (action == ACTION_DEACTIVATE_CORE)
        {
            DoCastSelf(SPELL_ICE_SPEAR_CONTROL_AURA);
            me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            me->SetImmuneToPC(true);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastSelf(SPELL_SUMMON_LOOT_MISSILE, true);
        DoCastSelf(SPELL_MINION_DESPAWNER, true);
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SYNCH_HEALTH:
                    if (Creature* ahune = _instance->GetCreature(DATA_AHUNE))
                        DoCast(ahune, SPELL_SYNCH_HEALTH, true);
                    _events.Repeat(2s);
                    break;
                case EVENT_SUICIDE:
                    if (Creature* ahune = _instance->GetCreature(DATA_AHUNE))
                        if (!ahune->IsAlive())
                            DoCastSelf(SPELL_SUICIDE, true);
                    _events.Repeat(2s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript * _instance;
    EventMap _events;
};

// 25745 - [PH] Ahune Summon Loc Bunny
struct npc_ahune_bunny : public ScriptedAI
{
    npc_ahune_bunny(Creature* creature) : ScriptedAI(creature), _summons(me), _instance(creature->GetInstanceScript()) { }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_AHUNE)
            return;

        DoZoneInCombat(summon);
        _summons.Summon(summon);
    }

    void DoResetCreatures()
    {
        std::vector<Creature*> creatures;
        GetCreatureListWithEntryInGrid(creatures, me, NPC_EARTHEN_RING_FLAMECALLER, 200.0f);
        GetCreatureListWithEntryInGrid(creatures, me, NPC_SHAMAN_BONFIRE_BUNNY_000, 200.0f);
        GetCreatureListWithEntryInGrid(creatures, me, NPC_SHAMAN_BONFIRE_BUNNY_001, 200.0f);
        GetCreatureListWithEntryInGrid(creatures, me, NPC_SHAMAN_BONFIRE_BUNNY_002, 200.0f);
        for (Creature* creature : creatures)
            creature->AI()->DoAction(ACTION_RESET_CREATURES);

        std::vector<Creature*> beams;
        GetCreatureListWithEntryInGrid(beams, me, NPC_SHAMAN_BEAM_BUNNY_000, 200.0f);
        GetCreatureListWithEntryInGrid(beams, me, NPC_SHAMAN_BEAM_BUNNY_001, 200.0f);
        GetCreatureListWithEntryInGrid(beams, me, NPC_SHAMAN_BEAM_BUNNY_002, 200.0f);
        for (Creature* beam : beams)
            beam->RemoveAurasDueToSpell(SPELL_FIND_OPENING_BEAM_END);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_EVENT:
                _events.ScheduleEvent(EVENT_INTRO_1, 0s);
                _events.ScheduleEvent(EVENT_SUBMERGE, 110s);
                break;
            case ACTION_STOP_EVENT_WIPE:
                DoResetCreatures();
                _summons.DespawnAll();
                _events.Reset();

                me->SummonGameObject(GO_ICE_STONE, -69.90455f, -162.2449f, -2.366563f, 2.426008f, QuaternionData(0.0f, 0.0f, 0.9366722f, 0.3502074f), 0s);
                break;
            case ACTION_STOP_EVENT_WIN:
                DoResetCreatures();
                _summons.DespawnAll();
                _events.Reset();
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INTRO_1:
                    DoCastSelf(SPELL_SUMMONING_VISUAL_1);
                    _events.ScheduleEvent(EVENT_INTRO_2, 10s);
                    break;
                case EVENT_INTRO_2:
                    DoCastSelf(SPELL_AHUNE_RESURFACES);
                    _events.ScheduleEvent(EVENT_INTRO_3, 1s);
                    _events.ScheduleEvent(EVENT_SUMMON_HAILSTONE, 5s);
                    break;
                case EVENT_INTRO_3:
                    me->SummonCreature(NPC_AHUNE, AhuneSpawnPosition, TEMPSUMMON_MANUAL_DESPAWN);
                    break;

                case EVENT_SUMMON_HAILSTONE:
                    DoCastSelf(SPELL_SUMMON_HAILSTONE, true);
                    if (Creature* ahune = _instance->GetCreature(DATA_AHUNE))
                        DoCast(ahune, SPELL_SHAMANS_LOOK_FOR_OPENING, true);
                    break;

                case EVENT_SUBMERGE:
                    if (Creature* flamecaller = me->FindNearestCreatureWithOptions(200.0f, { .StringId = "EarthenRingFlamecaller3" }))
                        flamecaller->AI()->DoAction(ACTION_RETREAT_EMOTE);

                    if (Creature* ahune = _instance->GetCreature(DATA_AHUNE))
                        DoCast(ahune, SPELL_FOUND_OPENING, true);

                    _events.ScheduleEvent(EVENT_RESURFACE_1, 5s);
                    break;
                case EVENT_RESURFACE_1:
                {
                    std::vector<Creature*> bonfires;
                    GetCreatureListWithEntryInGrid(bonfires, me, NPC_SHAMAN_BONFIRE_BUNNY_000, 200.0f);
                    GetCreatureListWithEntryInGrid(bonfires, me, NPC_SHAMAN_BONFIRE_BUNNY_001, 200.0f);
                    GetCreatureListWithEntryInGrid(bonfires, me, NPC_SHAMAN_BONFIRE_BUNNY_002, 200.0f);
                    for (Creature* bonfire : bonfires)
                        bonfire->AI()->DoAction(ACTION_STOP_VISUALS);

                    std::vector<Creature*> beams;
                    GetCreatureListWithEntryInGrid(beams, me, NPC_SHAMAN_BEAM_BUNNY_000, 200.0f);
                    GetCreatureListWithEntryInGrid(beams, me, NPC_SHAMAN_BEAM_BUNNY_001, 200.0f);
                    GetCreatureListWithEntryInGrid(beams, me, NPC_SHAMAN_BEAM_BUNNY_002, 200.0f);
                    for (Creature* beam : beams)
                        beam->DespawnOrUnsummon();
                    _events.ScheduleEvent(EVENT_RESURFACE_2, 20s);
                    break;
                }
                case EVENT_RESURFACE_2:
                    DoCastSelf(SPELL_CLOSE_OPENING_VISUAL, true);
                    DoCastSelf(SPELL_ICE_BOMBARD, true);

                    if (Creature* flamecaller = me->FindNearestCreatureWithOptions(200.0f, { .StringId = "EarthenRingFlamecaller3" }))
                        flamecaller->AI()->DoAction(ACTION_RESURFACE_EMOTE);

                    _events.ScheduleEvent(EVENT_RESURFACE_3, 10s);
                    break;
                case EVENT_RESURFACE_3:
                {
                    DoCastSelf(SPELL_AHUNE_RESURFACES, true);
                    Talk(EMOTE_EARTHEN_ASSAULT);

                    std::vector<Creature*> creatures;
                    GetCreatureListWithEntryInGrid(creatures, me, NPC_EARTHEN_RING_FLAMECALLER, 200.0f);
                    for (Creature* creature : creatures)
                        creature->AI()->DoAction(ACTION_START_VISUALS);

                    if (Creature* core = _instance->GetCreature(DATA_FROZEN_CORE))
                        core->AI()->DoAction(ACTION_DEACTIVATE_CORE);

                    _events.ScheduleEvent(EVENT_SUMMON_HAILSTONE, 5s);
                    _events.ScheduleEvent(EVENT_SUBMERGE, 95s);
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    SummonList _summons;
    InstanceScript * _instance;
    EventMap _events;
};

// 25754 - Earthen Ring Flamecaller
struct npc_earthen_ring_flamecaller : public ScriptedAI
{
    npc_earthen_ring_flamecaller(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        _homePosition = me->GetHomePosition();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_EVENT:
                me->SetStandState(UNIT_STAND_STATE_STAND);

                if (me->HasStringId("EarthenRingFlamecaller1"))
                    me->GetMotionMaster()->MovePath(PATH_FLAMECALLER_1, false);
                else if (me->HasStringId("EarthenRingFlamecaller2"))
                    me->GetMotionMaster()->MovePath(PATH_FLAMECALLER_2, false);
                else if (me->HasStringId("EarthenRingFlamecaller3"))
                    me->GetMotionMaster()->MovePath(PATH_FLAMECALLER_3, false);
                break;
            case ACTION_RETREAT_EMOTE:
                Talk(EMOTE_RETREAT);
                break;
            case ACTION_RESURFACE_EMOTE:
                Talk(EMOTE_RESURFACE);
                break;
            case ACTION_START_VISUALS:
                me->RemoveAurasDueToSpell(SPELL_FIND_OPENING_VISUAL_TRIGGER);
                DoCastSelf(SPELL_FIND_OPENING_CHANNEL, true);

                if (me->HasStringId("EarthenRingFlamecaller1"))
                {
                    _scheduler.Schedule(45s, 55s, [this](TaskContext /*task*/)
                    {
                        me->RemoveAurasDueToSpell(SPELL_FIND_OPENING_CHANNEL);

                        if (Creature* bonfireBunny = _instance->GetCreature(DATA_BONFIRE_BUNNY_001))
                            DoCast(bonfireBunny, SPELL_FIND_OPENING_VISUAL_TRIGGER, true);
                    });
                }
                else if (me->HasStringId("EarthenRingFlamecaller2"))
                {
                    _scheduler.Schedule(75s, 80s, [this](TaskContext /*task*/)
                    {
                        me->RemoveAurasDueToSpell(SPELL_FIND_OPENING_CHANNEL);

                        if (Creature* bonfireBunny = _instance->GetCreature(DATA_BONFIRE_BUNNY_002))
                            DoCast(bonfireBunny, SPELL_FIND_OPENING_VISUAL_TRIGGER, true);
                    });
                }
                else if (me->HasStringId("EarthenRingFlamecaller3"))
                {
                    _scheduler.Schedule(20s, 25s, [this](TaskContext /*task*/)
                    {
                        me->RemoveAurasDueToSpell(SPELL_FIND_OPENING_CHANNEL);

                        if (Creature* bonfireBunny = _instance->GetCreature(DATA_BONFIRE_BUNNY_000))
                            DoCast(bonfireBunny, SPELL_FIND_OPENING_VISUAL_TRIGGER, true);
                    });
                }
                break;
            case ACTION_RESET_CREATURES:
                _scheduler.CancelAll();
                me->InterruptNonMeleeSpells(false);
                me->GetMotionMaster()->MovePoint(POINT_HOME, _homePosition);
                break;
            default:
                break;
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_HOME)
            me->SetStandState(UNIT_STAND_STATE_SIT);
    }

    void WaypointPathEnded(uint32/* waypointId*/, uint32 pathId) override
    {
        switch (pathId)
        {
            case PATH_FLAMECALLER_1:
                if (Creature* bonfireBunny = _instance->GetCreature(DATA_BONFIRE_BUNNY_001))
                    me->SetFacingToObject(bonfireBunny);

                DoCastSelf(SPELL_FIND_OPENING_CHANNEL);

                _scheduler.Schedule(45s, 55s, [this](TaskContext /*task*/)
                {
                    me->RemoveAurasDueToSpell(SPELL_FIND_OPENING_CHANNEL);

                    if (Creature* bonfireBunny = _instance->GetCreature(DATA_BONFIRE_BUNNY_001))
                        DoCast(bonfireBunny, SPELL_FIND_OPENING_VISUAL_TRIGGER, true);
                });
                break;
            case PATH_FLAMECALLER_2:
                if (Creature* bonfireBunny = _instance->GetCreature(DATA_BONFIRE_BUNNY_002))
                    me->SetFacingToObject(bonfireBunny);

                DoCastSelf(SPELL_FIND_OPENING_CHANNEL);

                _scheduler.Schedule(75s, 80s, [this](TaskContext /*task*/)
                {
                    me->RemoveAurasDueToSpell(SPELL_FIND_OPENING_CHANNEL);

                    if (Creature* bonfireBunny = _instance->GetCreature(DATA_BONFIRE_BUNNY_002))
                        DoCast(bonfireBunny, SPELL_FIND_OPENING_VISUAL_TRIGGER, true);
                });
                break;
            case PATH_FLAMECALLER_3:
                if (Creature* bonfireBunny = _instance->GetCreature(DATA_BONFIRE_BUNNY_000))
                    me->SetFacingToObject(bonfireBunny);

                DoCastSelf(SPELL_FIND_OPENING_CHANNEL);

                _scheduler.Schedule(20s, 25s, [this](TaskContext /*task*/)
                {
                    me->RemoveAurasDueToSpell(SPELL_FIND_OPENING_CHANNEL);

                    if (Creature* bonfireBunny = _instance->GetCreature(DATA_BONFIRE_BUNNY_000))
                        DoCast(bonfireBunny, SPELL_FIND_OPENING_VISUAL_TRIGGER, true);
                });
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    Position _homePosition;
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// 25971 - Shaman Bonfire Bunny 000
// 25972 - Shaman Bonfire Bunny 001
// 25973 - Shaman Bonfire Bunny 002
struct npc_shaman_bonfire_bunny : public ScriptedAI
{
    npc_shaman_bonfire_bunny(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_SUMMONING_RHYME_BONFIRE:
                DoCastSelf(SPELL_BONFIRE_DISGUISE);
                break;
            case SPELL_FIND_OPENING_VISUAL_TRIGGER:
                switch (me->GetEntry())
                {
                    case NPC_SHAMAN_BONFIRE_BUNNY_000:
                        if (Creature* beamBunny = _instance->GetCreature(DATA_BEAM_BUNNY_000))
                            DoCast(beamBunny, SPELL_FIND_OPENING_VISUAL);
                        break;
                    case NPC_SHAMAN_BONFIRE_BUNNY_001:
                        if (Creature* beamBunny = _instance->GetCreature(DATA_BEAM_BUNNY_001))
                            DoCast(beamBunny, SPELL_FIND_OPENING_VISUAL);
                        break;
                    case NPC_SHAMAN_BONFIRE_BUNNY_002:
                        if (Creature* beamBunny = _instance->GetCreature(DATA_BEAM_BUNNY_002))
                            DoCast(beamBunny, SPELL_FIND_OPENING_VISUAL);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_RESET_CREATURES)
        {
            me->RemoveAurasDueToSpell(SPELL_BONFIRE_DISGUISE);
            me->RemoveAurasDueToSpell(SPELL_FIND_OPENING_VISUAL);
        }
        else if (action == ACTION_STOP_VISUALS)
        {
            me->RemoveAurasDueToSpell(SPELL_FIND_OPENING_VISUAL);
        }
    }

private:
    InstanceScript* _instance;
};

// 25985 - Ahune Ice Spear Bunny
struct npc_ahune_ice_spear_bunny : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void JustAppeared() override
    {
        DoCastSelf(SPELL_SUMMON_ICE_SPEAR_GO);
        DoCastSelf(SPELL_ICE_SPEAR_VISUAL);

        _scheduler.Schedule(2500ms, [this](TaskContext /*task*/)
        {
            DoCastSelf(SPELL_ICE_SPEAR_DELAY);
            me->DespawnOrUnsummon(3500ms);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 188077 - Ice Spear
struct go_ahune_ice_spear : public GameObjectAI
{
    using GameObjectAI::GameObjectAI;

    void Reset() override
    {
        _scheduler.Schedule(2500ms, [this](TaskContext /*task*/)
        {
            me->UseDoorOrButton();
            me->DespawnOrUnsummon(3500ms);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 187882 - Ice Stone
struct go_ahune_ice_stone : public GameObjectAI
{
    using GameObjectAI::GameObjectAI;

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        ClearGossipMenuFor(player);
        CloseGossipMenuFor(player);
        me->CastSpell(player, SPELL_SUMMONING_RHYME_AURA, true);
        me->DespawnOrUnsummon();
        return true;
    }
};

// 45926 - Summoning Rhyme Aura
class spell_ahune_summoning_rhyme_aura : public AuraScript
{
    PrepareAuraScript(spell_ahune_summoning_rhyme_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FORCE_WHISP_FLIGHT_MISSILE, SPELL_SUMMONING_RHYME_BONFIRE }) &&
            sObjectMgr->GetBroadcastText(TEXT_INTRO_1) && sObjectMgr->GetBroadcastText(TEXT_INTRO_2) && sObjectMgr->GetBroadcastText(TEXT_INTRO_3);
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        if (InstanceScript* instance = target->GetInstanceScript())
        {
            if (Creature* bunny = instance->GetCreature(DATA_AHUNE_BUNNY))
                bunny->AI()->DoAction(ACTION_START_EVENT);

            std::vector<Creature*> flamecallers;
            GetCreatureListWithEntryInGrid(flamecallers, target, NPC_EARTHEN_RING_FLAMECALLER, 200.0f);
            for (Creature* flamecaller : flamecallers)
                flamecaller->AI()->DoAction(ACTION_START_EVENT);

            // Luma should cast 45926 on player before despawn, NYI
            if (Creature* luma = instance->GetCreature(DATA_LUMA_SKYMOTHER))
                luma->DespawnOrUnsummon();
        }

        target->HandleEmoteCommand(EMOTE_ONESHOT_SHOUT);
        target->Unit::Say(TEXT_INTRO_1);
        target->CastSpell(nullptr, SPELL_FORCE_WHISP_FLIGHT_MISSILE);
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();

        switch (aurEff->GetTickNumber())
        {
            case 1:
                target->CastSpell(nullptr, SPELL_SUMMONING_RHYME_BONFIRE, true);
                target->Unit::Say(TEXT_INTRO_2);
                break;
            case 2:
                target->Unit::Say(TEXT_INTRO_3);
                Remove();
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_ahune_summoning_rhyme_aura::AfterApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ahune_summoning_rhyme_aura::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 45954 - Ahune's Shield
class spell_ahune_ahunes_shield : public AuraScript
{
    PrepareAuraScript(spell_ahune_ahunes_shield);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_COLDWEAVE, SPELL_SUMMON_FROSTWIND });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->CastSpell(nullptr, SPELL_SUMMON_COLDWEAVE, true);
        GetTarget()->CastSpell(nullptr, SPELL_SUMMON_COLDWEAVE, true);

        if (Creature* creature = GetTarget()->ToCreature())
        {
            // This value was verified by two sniffs
            if (creature->AI()->GetData(DATA_SUMMON_COUNT) < 14)
                creature->AI()->SetData(DATA_SUMMON_COUNT, creature->AI()->GetData(DATA_SUMMON_COUNT) + 1);
            else
                creature->CastSpell(nullptr, SPELL_SUMMON_FROSTWIND, true);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ahune_ahunes_shield::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 46430 - Synch Health
class spell_ahune_synch_health : public SpellScript
{
    PrepareSpellScript(spell_ahune_synch_health);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->SetHealth(GetCaster()->GetHealth());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ahune_synch_health::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 46878 - Summon Ice Spear Delayer
class spell_ahune_summon_ice_spear_delayer : public AuraScript
{
    PrepareAuraScript(spell_ahune_summon_ice_spear_delayer);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ICE_SPEAR_KNOCKBACK });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->CastSpell(nullptr, SPELL_ICE_SPEAR_KNOCKBACK, true);
        Remove();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ahune_summon_ice_spear_delayer::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 46371 - Ice Spear Control Aura
class spell_ahune_ice_spear_control_aura : public AuraScript
{
    PrepareAuraScript(spell_ahune_ice_spear_control_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ICE_SPEAR_TARGET_PICKER });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->CastSpell(nullptr, SPELL_ICE_SPEAR_TARGET_PICKER, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ahune_ice_spear_control_aura::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 46372 - Ice Spear Target Picker
class spell_ahune_ice_spear_target_picker : public SpellScript
{
    PrepareSpellScript(spell_ahune_ice_spear_target_picker);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_ICE_SPEAR_BUNNY });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        // This is wrong, full list of targets is sent to client
        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SUMMON_ICE_SPEAR_BUNNY, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ahune_ice_spear_target_picker::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_ahune_ice_spear_target_picker::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 46320 - Slippery Floor Ambient Periodic
class spell_ahune_slippery_floor_periodic : public SpellScript
{
    PrepareSpellScript(spell_ahune_slippery_floor_periodic);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SLIPPERY_FLOOR_SLIP, SPELL_SLIPPERY_FLOOR_YOU_SLIPPED });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        if (target->isMoving())
        {
            target->CastSpell(target, SPELL_SLIPPERY_FLOOR_SLIP, true);
            target->CastSpell(target, SPELL_SLIPPERY_FLOOR_YOU_SLIPPED, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ahune_slippery_floor_periodic::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 46146 - Ahune Spanky Hands
class spell_ahune_spanky_hands : public AuraScript
{
    PrepareAuraScript(spell_ahune_spanky_hands);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_COLD_SLAP });
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        eventInfo.GetActor()->CastSpell(eventInfo.GetActionTarget(), SPELL_COLD_SLAP, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_ahune_spanky_hands::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 46843 - Minion Despawner
class spell_ahune_minion_despawner : public AuraScript
{
    PrepareAuraScript(spell_ahune_minion_despawner);

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* creature = GetTarget()->ToCreature())
            creature->DespawnOrUnsummon();
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_ahune_minion_despawner::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 46398 - Ice Bombardment Dest Picker
class spell_ahune_ice_bombardment_dest_picker : public SpellScript
{
    PrepareSpellScript(spell_ahune_ice_bombardment_dest_picker);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ICE_BOMBARDMENT });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitDest()->GetPosition(), SPELL_ICE_BOMBARDMENT, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_ahune_ice_bombardment_dest_picker::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 45964 - Find Opening Visual
class spell_ahune_find_opening_visual : public SpellScript
{
    PrepareSpellScript(spell_ahune_find_opening_visual);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FIND_OPENING_BEAM_END });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_FIND_OPENING_BEAM_END, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ahune_find_opening_visual::HandleScript, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 46333 - Find Opening Beam End
class spell_ahune_find_opening_beam_end : public AuraScript
{
    PrepareAuraScript(spell_ahune_find_opening_beam_end);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BEAM_ATTACK_AGAINST_AHUNE });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->CastSpell(nullptr, SPELL_BEAM_ATTACK_AGAINST_AHUNE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ahune_find_opening_beam_end::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 46735 - Spank - Force Bunny To Knock You To
class spell_ahune_spank_force_bunny_to_knock_you_to : public SpellScript
{
    PrepareSpellScript(spell_ahune_spank_force_bunny_to_knock_you_to);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SPANK_KNOCK_TO });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), SPELL_SPANK_KNOCK_TO);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ahune_spank_force_bunny_to_knock_you_to::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 46809 - Make Ahune's Ghost Burst
class spell_ahune_make_ahunes_ghost_burst : public SpellScript
{
    PrepareSpellScript(spell_ahune_make_ahunes_ghost_burst);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return sObjectMgr->GetCreatureTemplate(NPC_GHOST_OF_AHUNE);
    }

    /// @todo: Invisible Ghost of Ahune cannot be hit by this spell, remove this script
    /// when it will be fixed and change Ghost of Ahune's SAI to run script on this spell hit
    void HandleAfterCast()
    {
        if (Creature* creature = GetCaster()->FindNearestCreature(NPC_GHOST_OF_AHUNE, 200.0f))
            creature->AI()->SetData(DATA_GHOST_OF_AHUNE, DATA_GHOST_OF_AHUNE);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_ahune_make_ahunes_ghost_burst::HandleAfterCast);
    }
};

void AddSC_boss_ahune()
{
    RegisterSlavePensCreatureAI(boss_ahune);
    RegisterSlavePensCreatureAI(npc_frozen_core);
    RegisterSlavePensCreatureAI(npc_earthen_ring_flamecaller);
    RegisterSlavePensCreatureAI(npc_shaman_bonfire_bunny);
    RegisterSlavePensCreatureAI(npc_ahune_bunny);
    RegisterSlavePensCreatureAI(npc_ahune_ice_spear_bunny);
    RegisterSlavePensGameObjectAI(go_ahune_ice_spear);
    RegisterSlavePensGameObjectAI(go_ahune_ice_stone);
    RegisterSpellScript(spell_ahune_summoning_rhyme_aura);
    RegisterSpellScript(spell_ahune_ahunes_shield);
    RegisterSpellScript(spell_ahune_synch_health);
    RegisterSpellScript(spell_ahune_summon_ice_spear_delayer);
    RegisterSpellScript(spell_ahune_ice_spear_control_aura);
    RegisterSpellScript(spell_ahune_ice_spear_target_picker);
    RegisterSpellScript(spell_ahune_slippery_floor_periodic);
    RegisterSpellScript(spell_ahune_spanky_hands);
    RegisterSpellScript(spell_ahune_minion_despawner);
    RegisterSpellScript(spell_ahune_ice_bombardment_dest_picker);
    RegisterSpellScript(spell_ahune_find_opening_visual);
    RegisterSpellScript(spell_ahune_find_opening_beam_end);
    RegisterSpellScript(spell_ahune_spank_force_bunny_to_knock_you_to);
    RegisterSpellScript(spell_ahune_make_ahunes_ghost_burst);
}
