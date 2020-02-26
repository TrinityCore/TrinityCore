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
#include "CreatureTextMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Group.h"
#include "InstanceScript.h"
#include "LFGMgr.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "the_slave_pens.h"

enum Spells
{
    // Ahune
    SPELL_SYNCH_HEALTH                  = 46430,
    SPELL_AHUNES_SHIELD                 = 45954,
    SPELL_STAY_SUBMERGED                = 46981,
    SPELL_AHUNE_SELF_STUN               = 46416,
    SPELL_AHUNE_ACHIEVEMENT             = 62043,
    SPELL_AHUNE_SPANKY_HANDS            = 46146,
    SPELL_COLD_SLAP                     = 46145,
    SPELL_RESURFACE                     = 46402,
    SPELL_SUBMERGED                     = 37751,
    SPELL_STAND                         = 37752,

    //Earther Ring Flamecaller
    SPELL_FIND_OPENING_VISUAL           = 45964,
    SPELL_FIND_OPENING_BEAM_END         = 46333,
    SPELL_FIND_OPENING_TRIGGER          = 46341,
    SPELL_FIND_OPENING_CHANNEL          = 46345,
    SPELL_BONFIRE_VISUAL                = 46339,
    SPELL_FOUND_OPENING                 = 46421,

    //Ahune Bunny
    SPELL_SUMMON_COLDWEAVE              = 46143,
    SPELL_SUMMON_FROSTWIND              = 46382,
    SPELL_SUMMON_HAILSTONE              = 46176,
    SPELL_SUMMONING_VISUAL_1            = 45937,
    SPELL_SUMMONING_RHYME_AURA          = 45926,
    SPELL_SUMMONING_RHYME_BONFIRE       = 45930,
    SPELL_FORCE_WHISP_FLIGHT            = 46603,
    SPELL_SHAMANS_LOOK_FOR_OPENING      = 46422,
    SPELL_CLOSE_OPENING_VISUAL          = 46236,
    SPELL_ICE_BOMBARD                   = 46397,
    SPELL_ICE_BOMBARDMENT_DEST_PICKER   = 46398,
    SPELL_ICE_BOMBARDMENT               = 46396,

    // Ice Spear
    SPELL_SUMMON_ICE_SPEAR_BUNNY        = 46359,
    SPELL_ICE_SPEAR_KNOCKBACK           = 46360,
    SPELL_SUMMON_ICE_SPEAR_GO           = 46369,
    SPELL_ICE_SPEAR_AURA                = 46371,
    SPELL_ICE_SPEAR_TARGET_PICKER       = 46372,
    SPELL_ICE_SPEAR_DELAY               = 46878,
    SPELL_ICE_SPEAR_VISUAL              = 75498,

    // Slippery Floor
    SPELL_SLIPPERY_FLOOR_AMBIENT        = 46314,
    SPELL_SLIPPERY_FLOOR_PERIODIC       = 46320,
    SPELL_SLIPPERY_FLOOR_SLIP           = 45947,
    SPELL_SLIPPERY_FLOOR_YOU_SLIPPED    = 45946,

    // Frozen Core
    SPELL_SUICIDE                       = 45254,
    SPELL_SUMMON_LOOT_MISSILE           = 45941,
    SPELL_FROZEN_CORE_GETS_HIT          = 46810,
    SPELL_MINION_DESPAWNER              = 46843,
    SPELL_GHOST_DISGUISE                = 46786
};

enum Emotes
{
    EMOTE_EARTHEN_ASSAULT               = 0,
    EMOTE_RETREAT                       = 0,
    EMOTE_RESURFACE                     = 1
};

enum Says
{
    SAY_PLAYER_TEXT_1                    = 0,
    SAY_PLAYER_TEXT_2                    = 1,
    SAY_PLAYER_TEXT_3                    = 2
};

enum Events
{
    EVENT_EMERGE = 1,
    EVENT_INITIAL_EMERGE,
    EVENT_SYNCH_HEALTH,
    EVENT_LOOKFOROPENING_0,
    EVENT_LOOKFOROPENING_1,
    EVENT_LOOKFOROPENING_2,
    EVENT_SUMMON_HAILSTONE,
    EVENT_SUMMON_COLDWEAVE,
    EVENT_SUMMON_FROSTWIND,
    EVENT_SUMMON_AHUNE,
    EVENT_CLOSE_OPENING,
    EVENT_AHUNE_PHASE_ONE,
    EVENT_AHUNE_PHASE_TWO,
    EVENT_START_LOOKING_FOR_OPENING,
    EVENT_STOP_LOOKING_FOR_OPENING
};

enum Actions
{
    ACTION_START_EVENT     = -2574500,
    ACTION_STOP_EVENT      = -2574501,
    ACTION_AHUNE_RETREAT   = -2586500,
    ACTION_AHUNE_RESURFACE = -2586501,
    ACTION_EMOTE_RESURFACE = -2575400
};

enum Phases
{
    PHASE_ONE = 0,
    PHASE_TWO = 1
};

enum Points
{
    POINT_FLAMECALLER_000,
    POINT_FLAMECALLER_001,
    POINT_FLAMECALLER_002
};

enum Misc
{
    MAX_FLAMECALLERS = 3
};

Position const SummonPositions[] =
{
    { -99.1021f, -233.7526f, -1.22307f, 1.588250f },  // Ahune
    { -98.0151f, -230.4555f, -1.21089f, 1.797689f },  // Frozen Core
    { -143.172f, -147.6801f, -3.16113f, 4.852015f },  // Bonfire Bunny 000
    { -134.304f, -145.7803f, -1.70332f, 4.677482f },  // Bonfire Bunny 001
    { -125.036f, -144.2065f, -1.91660f, 4.991642f }  // Bonfire Bunny 002
};

Position const FlameCallerSpots[] =
{
    { -145.2233f, -137.5543f, -1.59056f, 5.427049f },
    { -137.4383f, -136.4050f, -1.72384f, 5.336747f },
    { -129.0413f, -132.1494f, -2.09285f, 5.460842f }
};

struct boss_ahune : public BossAI
{
    boss_ahune(Creature* creature) : BossAI(creature, DATA_AHUNE)
    {
        me->SetControlled(true, UNIT_STATE_ROOT);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_INITIAL_EMERGE, 4ms);
        events.ScheduleEvent(EVENT_SYNCH_HEALTH, 3s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        if (Creature* ahuneBunny = instance->GetCreature(DATA_AHUNE_BUNNY))
            ahuneBunny->AI()->DoAction(ACTION_STOP_EVENT);
        summons.DespawnAll();
        me->DespawnOrUnsummon();
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->DoCastSpellOnPlayers(SPELL_AHUNE_ACHIEVEMENT);

        if (Creature* ahuneBunny = instance->GetCreature(DATA_AHUNE_BUNNY))
            Unit::Kill(me, ahuneBunny);
        if (Creature* frozenCore = instance->GetCreature(DATA_FROZEN_CORE))
            Unit::Kill(me, frozenCore);

        Map::PlayerList const& players = me->GetMap()->GetPlayers();
        if (!players.isEmpty())
        {
            if (Group* group = players.begin()->GetSource()->GetGroup())
                if (group->isLFGGroup())
                    sLFGMgr->FinishDungeon(group->GetGUID(), 286, me->GetMap());
        }

        _JustDied();
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_AHUNE_RETREAT)
        {
            Submerge();
            events.ScheduleEvent(EVENT_EMERGE, 35s);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_INITIAL_EMERGE:
                DoCastSelf(SPELL_STAND);
                DoCastSelf(SPELL_AHUNE_SPANKY_HANDS);
                DoCastSelf(SPELL_AHUNES_SHIELD);
                break;
            case EVENT_EMERGE:
                Emerge();
                break;
            case EVENT_SYNCH_HEALTH:
                if (Creature* frozenCore = instance->GetCreature(DATA_FROZEN_CORE))
                    DoCast(frozenCore, SPELL_SYNCH_HEALTH, true);
                else
                    DoCastSelf(SPELL_SUICIDE);
                events.Repeat(3s);
                break;
            default:
                break;
        }
    }

    void Emerge()
    {
        if (Creature* frozenCore = instance->GetCreature(DATA_FROZEN_CORE))
            frozenCore->AI()->DoAction(ACTION_AHUNE_RESURFACE);

        DoCastSelf(SPELL_AHUNES_SHIELD);
        me->RemoveAurasDueToSpell(SPELL_AHUNE_SELF_STUN);
        me->RemoveAurasDueToSpell(SPELL_STAY_SUBMERGED);
        DoCastSelf(SPELL_STAND);
        DoCastSelf(SPELL_RESURFACE, true);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        events.ScheduleEvent(EVENT_SYNCH_HEALTH, 3s);
    }

    void Submerge()
    {
        if (Creature* frozenCore = instance->GetCreature(DATA_FROZEN_CORE))
            frozenCore->AI()->DoAction(ACTION_AHUNE_RETREAT);
        me->RemoveAurasDueToSpell(SPELL_AHUNES_SHIELD);
        DoCastSelf(SPELL_SUBMERGED, true);
        DoCastSelf(SPELL_AHUNE_SELF_STUN, true);
        DoCastSelf(SPELL_STAY_SUBMERGED, true);
        me->HandleEmoteCommand(EMOTE_ONESHOT_SUBMERGE);
        events.Reset();
    }
};

struct npc_frozen_core : public ScriptedAI
{
    npc_frozen_core(Creature* creature) : ScriptedAI(creature)
    {
        _instance = me->GetInstanceScript();
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetRegenerateHealth(false);
        DoCastSelf(SPELL_FROZEN_CORE_GETS_HIT);
        DoCastSelf(SPELL_ICE_SPEAR_AURA);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* ahune = _instance->GetCreature(DATA_AHUNE))
            Unit::Kill(me, ahune);

        DoCast(SPELL_SUMMON_LOOT_MISSILE);
        DoCast(SPELL_MINION_DESPAWNER);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_AHUNE_RETREAT)
        {
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetImmuneToPC(false);
            me->RemoveAurasDueToSpell(SPELL_ICE_SPEAR_AURA);
            _events.ScheduleEvent(EVENT_SYNCH_HEALTH, 3s, 0, PHASE_TWO);
        }
        else if (action == ACTION_AHUNE_RESURFACE)
        {
            _events.Reset();
            DoCastSelf(SPELL_ICE_SPEAR_AURA);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetImmuneToPC(true);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SYNCH_HEALTH:
                    if (Creature* ahune = _instance->GetCreature(DATA_AHUNE))
                        DoCast(ahune, SPELL_SYNCH_HEALTH, true);
                    else
                        DoCastSelf(SPELL_SUICIDE);
                    _events.Repeat(3s);
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

struct npc_ahune_bunny : public ScriptedAI
{
    npc_ahune_bunny(Creature* creature) : ScriptedAI(creature), _summons(me)
    {
        _instance = me->GetInstanceScript();
        _submerged = false;
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_AHUNE)
            return;

        DoZoneInCombat(summon);
        _summons.Summon(summon);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _summons.DespawnAll();
        ResetFlameCallers();
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_START_EVENT)
        {
            DoCastSelf(SPELL_SUMMONING_VISUAL_1);
            me->SummonCreature(NPC_SHAMAN_BONFIRE_BUNNY_000, SummonPositions[2], TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_SHAMAN_BONFIRE_BUNNY_001, SummonPositions[3], TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_SHAMAN_BONFIRE_BUNNY_002, SummonPositions[4], TEMPSUMMON_MANUAL_DESPAWN);

            for (uint8 counter = 0; counter < MAX_FLAMECALLERS; ++counter)
                if (Creature* flameCaller = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_FLAMECALLER_000 + counter)))
                    flameCaller->GetMotionMaster()->MovePoint(counter, FlameCallerSpots[counter].GetPosition());

            _submerged = false;
            _events.Reset();
            _events.SetPhase(PHASE_ONE);
            _events.ScheduleEvent(EVENT_SUMMON_AHUNE, 10s);
            _events.ScheduleEvent(EVENT_START_LOOKING_FOR_OPENING, 14s, 0, PHASE_ONE);
            _events.ScheduleEvent(EVENT_SUMMON_COLDWEAVE, 22s, 0, PHASE_ONE);
            _events.ScheduleEvent(EVENT_SUMMON_HAILSTONE, 14s, 0, PHASE_ONE);
            _events.ScheduleEvent(EVENT_AHUNE_PHASE_TWO, 108s, 0, PHASE_ONE);
        }
        else if (action == ACTION_STOP_EVENT)
        {
            _summons.DespawnAll();
            _events.Reset();
            ResetFlameCallers();

            me->SummonGameObject(GO_ICE_STONE, -69.90455f, -162.2449f, -2.366563f, 2.426008f, QuaternionData(0.0f, 0.0f, 0.9366722f, 0.3502074f), 0);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_START_LOOKING_FOR_OPENING:
                    Talk(EMOTE_EARTHEN_ASSAULT);
                    for (uint8 counter = 0; counter < MAX_FLAMECALLERS; ++counter)
                        if (Creature* flamecaller = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_FLAMECALLER_000 + counter)))
                            DoCast(flamecaller, SPELL_SHAMANS_LOOK_FOR_OPENING, true);
                    break;
                case EVENT_SUMMON_HAILSTONE:
                    DoCast(SPELL_SUMMON_HAILSTONE);
                    break;
                case EVENT_SUMMON_COLDWEAVE:
                    DoCast(SPELL_SUMMON_COLDWEAVE);
                    DoCast(SPELL_SUMMON_COLDWEAVE);
                    _events.Repeat(8s);
                    if (_submerged)
                        _events.ScheduleEvent(EVENT_SUMMON_FROSTWIND, 4s, 0, PHASE_ONE);
                    break;
                case EVENT_SUMMON_FROSTWIND:
                    DoCast(SPELL_SUMMON_FROSTWIND);
                    break;
                case EVENT_SUMMON_AHUNE:
                    if (TempSummon* ahune = me->SummonCreature(NPC_AHUNE, SummonPositions[0], TEMPSUMMON_DEAD_DESPAWN))
                    {
                        ahune->SummonCreature(NPC_FROZEN_CORE, SummonPositions[1], TEMPSUMMON_CORPSE_DESPAWN);
                        DoZoneInCombat(ahune);
                        DoCast(ahune, SPELL_RESURFACE);
                    }
                    break;
                case EVENT_CLOSE_OPENING:
                    if (Creature* flamecaller = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_FLAMECALLER_000)))
                        flamecaller->AI()->DoAction(ACTION_EMOTE_RESURFACE);
                    DoCast(SPELL_CLOSE_OPENING_VISUAL);
                    DoCastSelf(SPELL_ICE_BOMBARD);
                    break;
                case EVENT_AHUNE_PHASE_TWO:
                    if (Creature* flamecaller = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_FLAMECALLER_000)))
                        DoCast(flamecaller, SPELL_FOUND_OPENING);
                    if (Creature* ahune = _instance->GetCreature(DATA_AHUNE))
                        ahune->AI()->DoAction(ACTION_AHUNE_RETREAT);
                    _events.Reset();
                    _events.SetPhase(PHASE_TWO);
                    _events.ScheduleEvent(EVENT_CLOSE_OPENING, 25s, 0, PHASE_TWO);
                    _events.ScheduleEvent(EVENT_AHUNE_PHASE_ONE, 35s, 0, PHASE_TWO);
                    break;
                case EVENT_AHUNE_PHASE_ONE:
                    _submerged = true;
                    _events.Reset();
                    _events.SetPhase(PHASE_ONE);
                    _events.ScheduleEvent(EVENT_SUMMON_COLDWEAVE, 8s, 0, PHASE_ONE);
                    _events.ScheduleEvent(EVENT_SUMMON_HAILSTONE, 5s, 0, PHASE_ONE);
                    _events.ScheduleEvent(EVENT_START_LOOKING_FOR_OPENING, 5s, 0, PHASE_ONE);
                    _events.ScheduleEvent(EVENT_AHUNE_PHASE_TWO, 100s, 0, PHASE_ONE);
                    break;
                default:
                    break;
            }
        }
    }

    void ResetFlameCallers()
    {
        for (uint8 counter = 0; counter < MAX_FLAMECALLERS; ++counter)
            if (Creature* flamecaller = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_FLAMECALLER_000 + counter)))
                flamecaller->AI()->EnterEvadeMode();
    }

private:
    InstanceScript * _instance;
    EventMap _events;
    SummonList _summons;
    bool _submerged;
};

struct npc_earthen_ring_flamecaller : public ScriptedAI
{
    npc_earthen_ring_flamecaller(Creature* creature) : ScriptedAI(creature)
    {
        _instance = me->GetInstanceScript();
        _mySpot = 0;
    }

    void Reset() override
    {
        _events.Reset();
    }

    void MovementInform(uint32 motionType, uint32 pointId) override
    {
        if (motionType != POINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_FLAMECALLER_000:
                _mySpot = POINT_FLAMECALLER_000;
                me->SetOrientation(FlameCallerSpots[_mySpot].GetOrientation());
                break;
            case POINT_FLAMECALLER_001:
                _mySpot = POINT_FLAMECALLER_001;
                me->SetOrientation(FlameCallerSpots[_mySpot].GetOrientation());
                break;
            case POINT_FLAMECALLER_002:
                _mySpot = POINT_FLAMECALLER_002;
                me->SetOrientation(FlameCallerSpots[_mySpot].GetOrientation());
                break;
            default:
                break;
        }

        DoCastSelf(SPELL_FIND_OPENING_CHANNEL);
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_SHAMANS_LOOK_FOR_OPENING:
                _events.ScheduleEvent(EVENT_LOOKFOROPENING_0, 17s);
                break;
            case SPELL_FOUND_OPENING:
                Talk(EMOTE_RETREAT);
                break;
            default:
                break;
        }
    }

    void DoAction(int action) override
    {
        if (action == ACTION_EMOTE_RESURFACE)
            Talk(EMOTE_RESURFACE);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_LOOKFOROPENING_0:
                    LookOpening(true, 0);
                    _events.ScheduleEvent(EVENT_LOOKFOROPENING_1, 26s);
                    break;
                case EVENT_LOOKFOROPENING_1:
                    LookOpening(true, 1);
                    _events.ScheduleEvent(EVENT_LOOKFOROPENING_2, 25s);
                    break;
                case EVENT_LOOKFOROPENING_2:
                    LookOpening(true, 2);
                    _events.ScheduleEvent(EVENT_STOP_LOOKING_FOR_OPENING, 27s);
                    break;
                case EVENT_STOP_LOOKING_FOR_OPENING:
                    LookOpening(false, _mySpot);
                    break;
                default:
                    break;
            }
        }
    }

    void LookOpening(bool activate, uint8 spot)
    {
        if (_mySpot != spot)
            return;

        if (Creature* bonfireBunny = _instance->GetCreature(DATA_BONFIRE_BUNNY_000 + spot))
            if (Creature* beamBunny = _instance->GetCreature(DATA_BEAM_BUNNY_000 + spot))
            {
                if (activate)
                {
                    DoCast(bonfireBunny, SPELL_FIND_OPENING_TRIGGER);
                    bonfireBunny->CastSpell(beamBunny, SPELL_FIND_OPENING_VISUAL, true);
                }
                else
                {
                    DoCastSelf(SPELL_FIND_OPENING_CHANNEL);
                    bonfireBunny->CastStop();
                    beamBunny->RemoveAurasDueToSpell(SPELL_FIND_OPENING_BEAM_END);
                }
            }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    uint8 _mySpot;
};

class go_ahune_ice_stone : public GameObjectScript
{
public:
    go_ahune_ice_stone() : GameObjectScript("go_ahune_ice_stone") { }

    struct go_ahune_ice_stoneAI : public GameObjectAI
    {
        go_ahune_ice_stoneAI(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()) { }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
        {
            ClearGossipMenuFor(player);

            if (Creature* ahuneBunny = _instance->GetCreature(DATA_AHUNE_BUNNY))
                ahuneBunny->AI()->DoAction(ACTION_START_EVENT);

            if (Creature* luma = _instance->GetCreature(DATA_LUMA_SKYMOTHER))
                luma->CastSpell(player, SPELL_SUMMONING_RHYME_AURA, true);
            CloseGossipMenuFor(player);
            me->Delete();
            return true;
        }

    private:
        InstanceScript* _instance;
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return GetSlavePensAI<go_ahune_ice_stoneAI>(go);
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

// 45926 - Summoning Rhyme Aura
class spell_summoning_rhyme_aura : public AuraScript
{
    PrepareAuraScript(spell_summoning_rhyme_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FORCE_WHISP_FLIGHT, SPELL_SUMMONING_RHYME_BONFIRE });
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        if (!GetCaster())
            return;

        Creature* caster = GetCaster()->ToCreature();
        Player* player = GetTarget()->ToPlayer();
        if (!caster || !player)
            return;

        player->CastSpell(player, SPELL_FORCE_WHISP_FLIGHT);

        switch (aurEff->GetTickNumber())
        {
            case 1:
                sCreatureTextMgr->SendChat(caster, SAY_PLAYER_TEXT_1, nullptr, CHAT_MSG_SAY, LANG_UNIVERSAL, TEXT_RANGE_NORMAL, 0, TEAM_OTHER, false, player);
                player->CastSpell(player, SPELL_SUMMONING_RHYME_BONFIRE, true);
                break;
            case 2:
                sCreatureTextMgr->SendChat(caster, SAY_PLAYER_TEXT_2, nullptr, CHAT_MSG_SAY, LANG_UNIVERSAL, TEXT_RANGE_NORMAL, 0, TEAM_OTHER, false, player);
                break;
            case 3:
                sCreatureTextMgr->SendChat(caster, SAY_PLAYER_TEXT_3, nullptr, CHAT_MSG_SAY, LANG_UNIVERSAL, TEXT_RANGE_NORMAL, 0, TEAM_OTHER, false, player);
                Remove();
                break;
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_summoning_rhyme_aura::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 46878 - Summon Ice Spear Delayer
class spell_summon_ice_spear_delayer : public AuraScript
{
    PrepareAuraScript(spell_summon_ice_spear_delayer);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_ICE_SPEAR_GO, SPELL_ICE_SPEAR_KNOCKBACK });
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        if (Unit* tmpCaster = GetCaster())
            if (Creature* caster = tmpCaster->ToCreature())
                switch (aurEff->GetTickNumber())
                {
                    case 1:
                        caster->CastSpell(caster, SPELL_SUMMON_ICE_SPEAR_GO);
                        break;
                    case 3:
                        if (GameObject* spike = caster->FindNearestGameObject(GO_ICE_SPEAR, 3.0f))
                            spike->UseDoorOrButton();
                        caster->AI()->DoCastAOE(SPELL_ICE_SPEAR_KNOCKBACK, true);
                        break;
                    case 5:
                        if (GameObject* spike = caster->FindNearestGameObject(GO_ICE_SPEAR, 3.0f))
                            spike->Delete();
                        caster->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_summon_ice_spear_delayer::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 46371 - Ice Spear Control Aura
class spell_ice_spear_control_aura : public AuraScript
{
    PrepareAuraScript(spell_ice_spear_control_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ICE_SPEAR_TARGET_PICKER });
    }

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_ICE_SPEAR_TARGET_PICKER);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ice_spear_control_aura::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 46372 - Ice Spear Target Picker
class spell_ice_spear_target_picker : public SpellScript
{
    PrepareSpellScript(spell_ice_spear_target_picker);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_ICE_SPEAR_BUNNY });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
        targets.clear();
        targets.push_back(target);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SUMMON_ICE_SPEAR_BUNNY, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ice_spear_target_picker::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_ice_spear_target_picker::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 46320 - Spell Slippery Floor Periodic
class spell_slippery_floor_periodic : public SpellScript
{
    PrepareSpellScript(spell_slippery_floor_periodic);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SLIPPERY_FLOOR_SLIP });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            if (target->isMoving())
            {
                target->CastSpell(target, SPELL_SLIPPERY_FLOOR_SLIP, true);
                target->CastSpell(target, SPELL_SLIPPERY_FLOOR_YOU_SLIPPED, true);
            }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_slippery_floor_periodic::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
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
        PreventDefaultAction();
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_COLD_SLAP, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_ahune_spanky_hands::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 46843 - Minion Despawner
class spell_ahune_minion_despawner : public SpellScript
{
    PrepareSpellScript(spell_ahune_minion_despawner);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (GetHitCreature())
            GetHitCreature()->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ahune_minion_despawner::HandleScript, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 46398 - Spell Ice Bombardment Dest Picker
class spell_ice_bombardment_dest_picker : public SpellScript
{
    PrepareSpellScript(spell_ice_bombardment_dest_picker);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ICE_BOMBARDMENT });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitDest()->GetPosition(), SPELL_ICE_BOMBARDMENT, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_ice_bombardment_dest_picker::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_ahune()
{
    RegisterSlavePensCreatureAI(boss_ahune);
    RegisterSlavePensCreatureAI(npc_frozen_core);
    RegisterSlavePensCreatureAI(npc_earthen_ring_flamecaller);
    RegisterSlavePensCreatureAI(npc_ahune_bunny);
    new go_ahune_ice_stone();
    RegisterSpellScript(spell_ahune_synch_health);
    RegisterAuraScript(spell_summoning_rhyme_aura);
    RegisterAuraScript(spell_summon_ice_spear_delayer);
    RegisterAuraScript(spell_ice_spear_control_aura);
    RegisterSpellScript(spell_ice_spear_target_picker);
    RegisterSpellScript(spell_slippery_floor_periodic);
    RegisterAuraScript(spell_ahune_spanky_hands);
    RegisterSpellScript(spell_ahune_minion_despawner);
    RegisterSpellScript(spell_ice_bombardment_dest_picker);
}
