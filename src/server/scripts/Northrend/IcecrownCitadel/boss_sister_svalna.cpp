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
#include "Creature.h"
#include "CreatureAI.h"
#include "CreatureData.h"
#include "EventProcessor.h"
#include "InstanceScript.h"
#include "GridNotifiersImpl.h"
#include "Map.h"
#include "MotionMaster.h"
#include "MovementDefines.h"
#include "ObjectAccessor.h"
#include "PetDefines.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptMgr.h"
#include "SpellDefines.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Unit.h"
#include "VehicleDefines.h"

enum ICCSisterSvalnaTexts
{
    SAY_SVALNA_KILL_CAPTAIN       = 1, // happens when she kills a captain
    SAY_SVALNA_KILL               = 4,
    SAY_SVALNA_CAPTAIN_DEATH      = 5, // happens when a captain resurrected by her dies
    SAY_SVALNA_DEATH              = 6,
    EMOTE_SVALNA_IMPALE           = 7,
    EMOTE_SVALNA_BROKEN_SHIELD    = 8,

    SAY_CROK_INTRO_1              = 0, // Ready your arms, my Argent Brothers. The Vrykul will protect the Frost Queen with their lives.
    SAY_ARNATH_INTRO_2            = 5, // Even dying here beats spending another day collecting reagents for that madman, Finklestein.
    SAY_CROK_INTRO_3              = 1, // Enough idle banter! Our champions have arrived - support them as we push our way through the hall!
    SAY_SVALNA_EVENT_START        = 0, // You may have once fought beside me, Crok, but now you are nothing more than a traitor. Come, your second death approaches!
    SAY_CROK_COMBAT_WP_0          = 2, // Draw them back to us, and we'll assist you.
    SAY_CROK_COMBAT_WP_1          = 3, // Quickly, push on!
    SAY_CROK_FINAL_WP             = 4, // Her reinforcements will arrive shortly, we must bring her down quickly!
    SAY_SVALNA_RESURRECT_CAPTAINS = 2, // Foolish Crok. You brought my reinforcements with you. Arise, Argent Champions, and serve the Lich King in death!
    SAY_CROK_COMBAT_SVALNA        = 5, // I'll draw her attacks. Return our brothers to their graves, then help me bring her down!
    SAY_SVALNA_AGGRO              = 3, // Come, Scourgebane. I'll show the master which of us is truly worthy of the title of "Champion"!
    SAY_CAPTAIN_DEATH             = 0,
    SAY_CAPTAIN_RESURRECTED       = 1,
    SAY_CAPTAIN_KILL              = 2,
    SAY_CAPTAIN_SECOND_DEATH      = 3,
    SAY_CAPTAIN_SURVIVE_TALK      = 4,
    SAY_CROK_WEAKENING_GAUNTLET   = 6,
    SAY_CROK_WEAKENING_SVALNA     = 7,
    SAY_CROK_DEATH                = 8,
};

enum ICCSisterSvalnaSpells
{
    // Crok Scourgebane
    SPELL_ICEBOUND_ARMOR = 70714,
    SPELL_SCOURGE_STRIKE = 71488,
    SPELL_DEATH_STRIKE = 71489,

    // Sister Svalna
    SPELL_CARESS_OF_DEATH = 70078,
    SPELL_IMPALING_SPEAR_KILL = 70196,
    SPELL_REVIVE_CHAMPION = 70053,
    SPELL_UNDEATH = 70089,
    SPELL_IMPALING_SPEAR = 71443,
    SPELL_AETHER_SHIELD = 71463,
    SPELL_HURL_SPEAR = 71466,
    SPELL_DIVINE_SURGE = 71465,

    // Captain Arnath
    SPELL_DOMINATE_MIND = 14515,
    SPELL_FLASH_HEAL_NORMAL = 71595,
    SPELL_POWER_WORD_SHIELD_NORMAL = 71548,
    SPELL_SMITE_NORMAL = 71546,
    SPELL_FLASH_HEAL_UNDEAD = 71782,
    SPELL_POWER_WORD_SHIELD_UNDEAD = 71780,
    SPELL_SMITE_UNDEAD = 71778,

    // Captain Brandon
    SPELL_CRUSADER_STRIKE = 71549,
    SPELL_DIVINE_SHIELD = 71550,
    SPELL_JUDGEMENT_OF_COMMAND = 71551,
    SPELL_HAMMER_OF_BETRAYAL = 71784,

    // Captain Grondel
    SPELL_CHARGE = 71553,
    SPELL_MORTAL_STRIKE = 71552,
    SPELL_SUNDER_ARMOR = 71554,
    SPELL_CONFLAGRATION = 71785,

    // Captain Rupert
    SPELL_FEL_IRON_BOMB_NORMAL = 71592,
    SPELL_MACHINE_GUN_NORMAL = 71594,
    SPELL_ROCKET_LAUNCH_NORMAL = 71590,
    SPELL_FEL_IRON_BOMB_UNDEAD = 71787,
    SPELL_MACHINE_GUN_UNDEAD = 71788,
    SPELL_ROCKET_LAUNCH_UNDEAD = 71786,

    // Ymirjar Vrykuls
    SPELL_ARCTIC_CHILL = 71270,
    SPELL_FROZEN_ORB_CAST = 71274,
    SPELL_FROZEN_ORB_MISSILE = 71285,
    SPELL_SPIRIT_STREAM = 69929,
    SPELL_TWISTED_WINDS = 71306,
    SPELL_BARBARIC_STRIKE = 71257,
    SPELL_ADRENALINE_RUSH = 71258,
    SPELL_WHIRLWIND = 41056,
    SPELL_RAPID_SHOT = 71251,
    SPELL_ICE_TRAP = 71249,
    SPELL_SUMMON_WARHAWK = 71705,
    SPELL_VOLLEY = 71252,
    SPELL_YMIRJAR_SHOOT = 71253,
    SPELL_YMIRJAR_SHADOW_BOLT = 71296,
    SPELL_DEATH_EMBRACE = 71299,
    SPELL_BANISH = 71298,
    SPELL_SUMMON_YMIRJAR = 71303,
    SPELL_AWAKEN_YMIRJAR_FALLEN = 71302,
    SPELL_WARLORDS_PRESENCE = 71244,
};

enum ICCSisterSvalnaTimedEventIds
{
    // Crok Scourgebane
    EVENT_SCOURGE_STRIKE = 1,
    EVENT_DEATH_STRIKE,
    EVENT_HEALTH_CHECK,
    EVENT_CROK_INTRO_3,
    EVENT_START_PATHING,

    // Sister Svalna
    EVENT_ARNATH_INTRO_2,
    EVENT_SVALNA_START,
    EVENT_SVALNA_RESURRECT,
    EVENT_SVALNA_COMBAT,
    EVENT_IMPALING_SPEAR,
    EVENT_AETHER_SHIELD,

    // Captain Arnath
    EVENT_ARNATH_FLASH_HEAL,
    EVENT_ARNATH_PW_SHIELD,
    EVENT_ARNATH_SMITE,
    EVENT_ARNATH_DOMINATE_MIND,

    // Captain Brandon
    EVENT_BRANDON_CRUSADER_STRIKE,
    EVENT_BRANDON_DIVINE_SHIELD,
    EVENT_BRANDON_JUDGEMENT_OF_COMMAND,
    EVENT_BRANDON_HAMMER_OF_BETRAYAL,

    // Captain Grondel
    EVENT_GRONDEL_CHARGE_CHECK,
    EVENT_GRONDEL_MORTAL_STRIKE,
    EVENT_GRONDEL_SUNDER_ARMOR,
    EVENT_GRONDEL_CONFLAGRATION,

    // Captain Rupert
    EVENT_RUPERT_FEL_IRON_BOMB,
    EVENT_RUPERT_MACHINE_GUN,
    EVENT_RUPERT_ROCKET_LAUNCH,

    // Ymirjar Vrykuls
    EVENT_YMIRJAR_FROZEN_ORB,
    EVENT_YMIRJAR_TWISTED_WINDS,
    EVENT_YMIRJAR_SPIRIT_STREAM,
    EVENT_YMIRJAR_BARBARIC_STRIKE,
    EVENT_YMIRJAR_ADRENALINE_RUSH,
    EVENT_YMIRJAR_WHIRLWIND,
    EVENT_YMIRJAR_RAPID_SHOT,
    EVENT_YMIRJAR_ICE_TRAP,
    EVENT_YMIRJAR_VOLLEY,
    EVENT_YMIRJAR_SHOOT,
    EVENT_YMIRJAR_SHADOW_BOLT,
    EVENT_YMIRJAR_DEATH_EMBRACE,
    EVENT_YMIRJAR_BANISH,
    EVENT_YMIRJAR_SUMMON,
};

enum ICCSisterSvalnaActions
{
    ACTION_KILL_CAPTAIN = 1,
    ACTION_START_GAUNTLET,
    ACTION_RESURRECT_CAPTAINS,
    ACTION_CAPTAIN_DIES,
    ACTION_RESET_EVENT
};

enum ICCSisterSvalnaMovePoints
{
    POINT_SVALNA_LAND = 1
};

enum ICCYmirjarFrostWingMisc
{
    NPC_YMIRJAR_WARHAWK = 38154
};

// Helper defines
// Captain Arnath
#define SPELL_FLASH_HEAL (IsUndead ? SPELL_FLASH_HEAL_UNDEAD : SPELL_FLASH_HEAL_NORMAL)
#define SPELL_POWER_WORD_SHIELD (IsUndead ? SPELL_POWER_WORD_SHIELD_UNDEAD : SPELL_POWER_WORD_SHIELD_NORMAL)
#define SPELL_SMITE (IsUndead ? SPELL_SMITE_UNDEAD : SPELL_SMITE_NORMAL)

// Captain Rupert
#define SPELL_FEL_IRON_BOMB (IsUndead ? SPELL_FEL_IRON_BOMB_UNDEAD : SPELL_FEL_IRON_BOMB_NORMAL)
#define SPELL_MACHINE_GUN (IsUndead ? SPELL_MACHINE_GUN_UNDEAD : SPELL_MACHINE_GUN_NORMAL)
#define SPELL_ROCKET_LAUNCH (IsUndead ? SPELL_ROCKET_LAUNCH_UNDEAD : SPELL_ROCKET_LAUNCH_NORMAL)

class FrostwingVrykulSearcher
{
public:
    FrostwingVrykulSearcher(Creature const* source, float range) : _source(source), _range(range) { }

    bool operator()(Unit* unit)
    {
        if (!unit->IsAlive())
            return false;

        switch (unit->GetEntry())
        {
            case NPC_YMIRJAR_BATTLE_MAIDEN:
            case NPC_YMIRJAR_DEATHBRINGER:
            case NPC_YMIRJAR_FROSTBINDER:
            case NPC_YMIRJAR_HUNTRESS:
            case NPC_YMIRJAR_WARLORD:
                break;
            default:
                return false;
        }

        if (!unit->IsWithinDist(_source, _range, false))
            return false;

        return true;
    }

private:
    Creature const* _source;
    float _range;
};

class FrostwingGauntletRespawner
{
public:
    void operator()(Creature* creature)
    {
        switch (creature->GetOriginalEntry())
        {
            case NPC_YMIRJAR_BATTLE_MAIDEN:
            case NPC_YMIRJAR_DEATHBRINGER:
            case NPC_YMIRJAR_FROSTBINDER:
            case NPC_YMIRJAR_HUNTRESS:
            case NPC_YMIRJAR_WARLORD:
                break;
            case NPC_CROK_SCOURGEBANE:
            case NPC_CAPTAIN_ARNATH:
            case NPC_CAPTAIN_BRANDON:
            case NPC_CAPTAIN_GRONDEL:
            case NPC_CAPTAIN_RUPERT:
                creature->AI()->DoAction(ACTION_RESET_EVENT);
                break;
            case NPC_SISTER_SVALNA:
                creature->AI()->DoAction(ACTION_RESET_EVENT);
                // return, this creature is never dead if event is reset
                return;
            default:
                return;
        }

        uint32 corpseDelay = creature->GetCorpseDelay();
        uint32 respawnDelay = creature->GetRespawnDelay();
        creature->SetCorpseDelay(1);
        creature->SetRespawnDelay(2);

        if (CreatureData const* data = creature->GetCreatureData())
            creature->UpdatePosition(data->spawnPoint);

        creature->DespawnOrUnsummon();
        creature->SetCorpseDelay(corpseDelay);
        creature->SetRespawnDelay(respawnDelay);
    }
};

class CaptainSurviveTalk : public BasicEvent
{
public:
    explicit CaptainSurviveTalk(Creature const* owner) : _owner(owner) { }

    bool Execute(uint64 /*currTime*/, uint32 /*diff*/) override
    {
        _owner->AI()->Talk(SAY_CAPTAIN_SURVIVE_TALK);
        return true;
    }

private:
    Creature const* _owner;
};

struct boss_sister_svalna : public BossAI
{
    boss_sister_svalna(Creature* creature) : BossAI(creature, DATA_SISTER_SVALNA), _isEventInProgress(false) { }

    void InitializeAI() override
    {
        if (!me->isDead())
            Reset();

        me->SetReactState(REACT_PASSIVE);
    }

    void Reset() override
    {
        _Reset();
        me->SetReactState(REACT_DEFENSIVE);
        _isEventInProgress = false;
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_SVALNA_DEATH);

        uint64 delay = 1;
        for (uint8 itr = 0; itr < 4; ++itr)
        {
            if (Creature* crusader = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_CAPTAIN_ARNATH + itr)))
            {
                if (crusader->IsAlive() && crusader->GetEntry() == crusader->GetCreatureData()->id)
                {
                    crusader->m_Events.AddEvent(new CaptainSurviveTalk(crusader), crusader->m_Events.CalculateTime(delay));
                    delay += 6000;
                }
            }
        }
    }

    void JustEngagedWith(Unit* /*attacker*/) override
    {
        _JustEngagedWith();
        if (Creature* crok = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_CROK_SCOURGEBANE)))
            crok->AI()->Talk(SAY_CROK_COMBAT_SVALNA);
        DoCastSelf(SPELL_DIVINE_SURGE, true);
        events.ScheduleEvent(EVENT_SVALNA_COMBAT, 9s);
        events.ScheduleEvent(EVENT_IMPALING_SPEAR, 40s, 50s);
        events.ScheduleEvent(EVENT_AETHER_SHIELD, 100s, 110s);
    }

    void KilledUnit(Unit* victim) override
    {
        switch (victim->GetTypeId())
        {
            case TYPEID_PLAYER:
                Talk(SAY_SVALNA_KILL);
                break;
            case TYPEID_UNIT:
                switch (victim->GetEntry())
                {
                    case NPC_CAPTAIN_ARNATH:
                    case NPC_CAPTAIN_BRANDON:
                    case NPC_CAPTAIN_GRONDEL:
                    case NPC_CAPTAIN_RUPERT:
                        Talk(SAY_SVALNA_KILL_CAPTAIN);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        me->SetReactState(REACT_PASSIVE);
        me->SetDisableGravity(false);
        me->SetHover(false);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_KILL_CAPTAIN:
                DoCastSelf(SPELL_CARESS_OF_DEATH, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                break;
            case ACTION_START_GAUNTLET:
                me->setActive(true);
                me->SetFarVisible(true);
                _isEventInProgress = true;
                me->SetImmuneToAll(true);
                events.ScheduleEvent(EVENT_SVALNA_START, 25s);
                break;
            case ACTION_RESURRECT_CAPTAINS:
                events.ScheduleEvent(EVENT_SVALNA_RESURRECT, 7s);
                break;
            case ACTION_CAPTAIN_DIES:
                Talk(SAY_SVALNA_CAPTAIN_DEATH);
                break;
            case ACTION_RESET_EVENT:
                me->setActive(false);
                me->SetFarVisible(false);
                Reset();
                break;
            default:
                break;
        }
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_HURL_SPEAR && me->HasAura(SPELL_AETHER_SHIELD))
        {
            me->RemoveAurasDueToSpell(SPELL_AETHER_SHIELD);
            Talk(EMOTE_SVALNA_BROKEN_SHIELD, caster);
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != EFFECT_MOTION_TYPE || id != POINT_SVALNA_LAND)
            return;

        _isEventInProgress = false;
        me->setActive(false);
        me->SetFarVisible(false);
        me->SetImmuneToAll(false);
        me->SetDisableGravity(false);
        me->SetHover(false);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_IMPALING_SPEAR_KILL:
                Unit::Kill(me, target);
                break;
            case SPELL_IMPALING_SPEAR:
                if (TempSummon* summon = target->SummonCreature(NPC_IMPALING_SPEAR, *target))
                {
                    Talk(EMOTE_SVALNA_IMPALE, target);
                    CastSpellExtraArgs args;
                    args.AddSpellBP0(1);
                    summon->CastSpell(target, VEHICLE_SPELL_RIDE_HARDCODED, args);
                    summon->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_UNK1 | UNIT_FLAG2_ALLOW_ENEMY_INTERACT);
                }
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !_isEventInProgress)
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SVALNA_START:
                    Talk(SAY_SVALNA_EVENT_START);
                    break;
                case EVENT_SVALNA_RESURRECT:
                    Talk(SAY_SVALNA_RESURRECT_CAPTAINS);
                    DoCast(me, SPELL_REVIVE_CHAMPION, false);
                    break;
                case EVENT_SVALNA_COMBAT:
                    me->SetReactState(REACT_DEFENSIVE);
                    Talk(SAY_SVALNA_AGGRO);
                    break;
                case EVENT_IMPALING_SPEAR:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, true, -SPELL_IMPALING_SPEAR))
                    {
                        DoCast(me, SPELL_AETHER_SHIELD);
                        DoCast(target, SPELL_IMPALING_SPEAR);
                    }
                    events.ScheduleEvent(EVENT_IMPALING_SPEAR, 20s, 25s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _isEventInProgress;
};

struct npc_crok_scourgebane : public EscortAI
{
    npc_crok_scourgebane(Creature* creature) : EscortAI(creature), _instance(creature->GetInstanceScript()), _respawnTime(creature->GetRespawnDelay()), _corpseDelay(creature->GetCorpseDelay())
    {
        Initialize();
        SetDespawnAtEnd(false);
        SetDespawnAtFar(false);
        _isEventActive = false;
        _isEventDone = _instance->GetBossState(DATA_SISTER_SVALNA) == DONE;
        _currentWPid = 0;
    }

    void Initialize()
    {
        _didUnderTenPercentText = false;
        _wipeCheckTimer = 1000;
    }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_SCOURGE_STRIKE, urand(7500, 12500));
        _events.ScheduleEvent(EVENT_DEATH_STRIKE, 25s, 30s);
        me->SetReactState(REACT_DEFENSIVE);
        Initialize();
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_START_GAUNTLET)
        {
            if (_isEventDone || !me->IsAlive())
                return;

            _isEventActive = true;
            _isEventDone = true;

            // Load Grid with Sister Svalna
            me->GetMap()->LoadGrid(4356.71f, 2484.33f);

            if (Creature* svalna = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_SISTER_SVALNA)))
                svalna->AI()->DoAction(ACTION_START_GAUNTLET);

            Talk(SAY_CROK_INTRO_1);
            _events.ScheduleEvent(EVENT_ARNATH_INTRO_2, 7000);
            _events.ScheduleEvent(EVENT_CROK_INTRO_3, 14000);
            _events.ScheduleEvent(EVENT_START_PATHING, 35s);
            me->setActive(true);
            me->SetFarVisible(true);

            for (uint32 itr = 0; itr < 4; ++itr)
                if (Creature* crusader = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_CAPTAIN_ARNATH + itr)))
                    crusader->AI()->DoAction(ACTION_START_GAUNTLET);
        }
        else if (action == ACTION_RESET_EVENT)
        {
            _isEventActive = false;
            _isEventDone = _instance->GetBossState(DATA_SISTER_SVALNA) == DONE;
            me->setActive(false);
            me->SetFarVisible(false);
            _aliveTrash.clear();
            _currentWPid = 0;
        }
    }

    void SetGUID(ObjectGuid const& guid, int32 id) override
    {
        if (id == ACTION_VRYKUL_DEATH)
        {
            _aliveTrash.erase(guid);
            if (_aliveTrash.empty())
            {
                SetEscortPaused(false);
                if (_currentWPid == 4 && _isEventActive)
                {
                    _isEventActive = false;
                    me->setActive(false);
                    me->SetFarVisible(false);
                    Talk(SAY_CROK_FINAL_WP);
                    if (Creature* svalna = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_SISTER_SVALNA)))
                        svalna->AI()->DoAction(ACTION_RESURRECT_CAPTAINS);
                }
            }
        }
    }

    void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
    {
        switch (waypointId)
        {
            case 0: // pause pathing until trash pack is cleared
                me->SetImmuneToNPC(false);
                Talk(SAY_CROK_COMBAT_WP_0);
                if (!_aliveTrash.empty())
                    SetEscortPaused(true);
                break;
            case 1:
                Talk(SAY_CROK_COMBAT_WP_1);
                if (!_aliveTrash.empty())
                    SetEscortPaused(true);
                break;
            case 4:
                if (_aliveTrash.empty() && _isEventActive)
                {
                    _isEventActive = false;
                    me->setActive(false);
                    me->SetFarVisible(false);
                    Talk(SAY_CROK_FINAL_WP);
                    if (Creature* svalna = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_SISTER_SVALNA)))
                        svalna->AI()->DoAction(ACTION_RESURRECT_CAPTAINS);
                }
                break;
            default:
                break;
        }
    }

    void WaypointStarted(uint32 waypointId, uint32 /*pathId*/) override
    {
        _currentWPid = waypointId;
        switch (waypointId)
        {
            case 0:
            case 1:
            case 4:
            {
                // get spawns by home position
                float minY = 2600.0f;
                float maxY = 2650.0f;
                if (waypointId == 1)
                {
                    minY -= 50.0f;
                    maxY -= 50.0f;
                    // at waypoints 1 and 2 she kills one captain
                    if (Creature* svalna = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_SISTER_SVALNA)))
                        svalna->AI()->DoAction(ACTION_KILL_CAPTAIN);
                }
                else if (waypointId == 4)
                {
                    minY -= 100.0f;
                    maxY -= 100.0f;
                }

                // get all nearby vrykul
                std::list<Creature*> temp;
                FrostwingVrykulSearcher check(me, 80.0f);
                Trinity::CreatureListSearcher<FrostwingVrykulSearcher> searcher(me, temp, check);
                Cell::VisitGridObjects(me, searcher, 80.0f);

                _aliveTrash.clear();
                for (auto itr = temp.begin(); itr != temp.end(); ++itr)
                    if ((*itr)->GetHomePosition().GetPositionY() < maxY && (*itr)->GetHomePosition().GetPositionY() > minY)
                        _aliveTrash.insert((*itr)->GetGUID());
                break;
            }
            // at waypoints 1 and 2 she kills one captain
            case 2:
                if (Creature* svalna = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_SISTER_SVALNA)))
                    svalna->AI()->DoAction(ACTION_KILL_CAPTAIN);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        // check wipe
        if (!_wipeCheckTimer)
        {
            _wipeCheckTimer = 1000;
            Player* player = nullptr;
            Trinity::AnyPlayerInObjectRangeCheck check(me, 60.0f);
            Trinity::PlayerSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, player, check);
            Cell::VisitWorldObjects(me, searcher, 60.0f);
            // wipe
            if (!player)
            {
                damage *= 100;
                if (damage >= me->GetHealth())
                {
                    FrostwingGauntletRespawner respawner;
                    Trinity::CreatureWorker<FrostwingGauntletRespawner> worker(me, respawner);
                    Cell::VisitGridObjects(me, worker, 333.0f);
                    Talk(SAY_CROK_DEATH);
                }
                return;
            }
        }

        if (HealthBelowPct(10))
        {
            if (!_didUnderTenPercentText)
            {
                _didUnderTenPercentText = true;
                if (_isEventActive)
                    Talk(SAY_CROK_WEAKENING_GAUNTLET);
                else
                    Talk(SAY_CROK_WEAKENING_SVALNA);
            }

            damage = 0;
            DoCast(me, SPELL_ICEBOUND_ARMOR);
            _events.ScheduleEvent(EVENT_HEALTH_CHECK, 1s);
        }
    }

    void UpdateEscortAI(uint32 diff) override
    {
        if (_wipeCheckTimer <= diff)
            _wipeCheckTimer = 0;
        else
            _wipeCheckTimer -= diff;

        if (!UpdateVictim() && !_isEventActive)
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ARNATH_INTRO_2:
                    if (Creature* arnath = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_CAPTAIN_ARNATH)))
                        arnath->AI()->Talk(SAY_ARNATH_INTRO_2);
                    break;
                case EVENT_CROK_INTRO_3:
                    Talk(SAY_CROK_INTRO_3);
                    break;
                case EVENT_START_PATHING:
                    Start(true, true);
                    break;
                case EVENT_SCOURGE_STRIKE:
                    DoCastVictim(SPELL_SCOURGE_STRIKE);
                    _events.ScheduleEvent(EVENT_SCOURGE_STRIKE, 10s, 14s);
                    break;
                case EVENT_DEATH_STRIKE:
                    if (HealthBelowPct(20))
                        DoCastVictim(SPELL_DEATH_STRIKE);
                    _events.ScheduleEvent(EVENT_DEATH_STRIKE, 5s, 10s);
                    break;
                case EVENT_HEALTH_CHECK:
                    if (HealthAbovePct(15))
                    {
                        me->RemoveAurasDueToSpell(SPELL_ICEBOUND_ARMOR);
                        _didUnderTenPercentText = false;
                    }
                    else
                    {
                        // looks totally hacky to me
                        me->ModifyHealth(me->CountPctFromMaxHealth(5));
                        _events.ScheduleEvent(EVENT_HEALTH_CHECK, 1s);
                    }
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

    bool CanAIAttack(Unit const* target) const override
    {
        // do not see targets inside Frostwing Halls when we are not there
        return (me->GetPositionY() > 2660.0f) == (target->GetPositionY() > 2660.0f);
    }

private:
    EventMap _events;
    GuidSet _aliveTrash;
    InstanceScript* _instance;
    uint32 _currentWPid;
    uint32 _wipeCheckTimer;
    uint32 const _respawnTime;
    uint32 const _corpseDelay;
    bool _isEventActive;
    bool _isEventDone;
    bool _didUnderTenPercentText;
};

struct npc_argent_captainAI : public ScriptedAI
{
public:
    npc_argent_captainAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript()), _firstDeath(true)
    {
        FollowAngle = PET_FOLLOW_ANGLE;
        FollowDist = PET_FOLLOW_DIST;
        IsUndead = false;
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (_firstDeath)
        {
            _firstDeath = false;
            Talk(SAY_CAPTAIN_DEATH);
        }
        else
            Talk(SAY_CAPTAIN_SECOND_DEATH);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_CAPTAIN_KILL);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_START_GAUNTLET)
        {
            if (Creature* crok = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_CROK_SCOURGEBANE)))
            {
                me->SetReactState(REACT_DEFENSIVE);
                FollowAngle = me->GetAbsoluteAngle(crok) + me->GetOrientation();
                FollowDist = me->GetDistance2d(crok);
                me->GetMotionMaster()->MoveFollow(crok, FollowDist, FollowAngle, MOTION_SLOT_DEFAULT);
            }

            me->setActive(true);
            me->SetFarVisible(true);
        }
        else if (action == ACTION_RESET_EVENT)
        {
            _firstDeath = true;
        }
    }

    void JustEngagedWith(Unit* /*target*/) override
    {
        me->SetHomePosition(*me);
        if (IsUndead)
            DoZoneInCombat();
    }

    bool CanAIAttack(Unit const* target) const override
    {
        // do not see targets inside Frostwing Halls when we are not there
        return (me->GetPositionY() > 2660.0f) == (target->GetPositionY() > 2660.0f);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        // not yet following
        if (me->GetMotionMaster()->GetCurrentMovementGeneratorType(MOTION_SLOT_DEFAULT) != FOLLOW_MOTION_TYPE || IsUndead)
        {
            ScriptedAI::EnterEvadeMode(why);
            return;
        }

        if (!_EnterEvadeMode(why))
            return;

        if (!me->GetVehicle())
        {
            me->GetMotionMaster()->Clear();
            if (Creature* crok = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_CROK_SCOURGEBANE)))
                me->GetMotionMaster()->MoveFollow(crok, FollowDist, FollowAngle, MOTION_SLOT_DEFAULT);
        }

        Reset();
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_REVIVE_CHAMPION && !IsUndead)
        {
            IsUndead = true;
            me->setDeathState(JUST_RESPAWNED);
            uint32 newEntry = 0;
            switch (me->GetEntry())
            {
                case NPC_CAPTAIN_ARNATH:
                    newEntry = NPC_CAPTAIN_ARNATH_UNDEAD;
                    break;
                case NPC_CAPTAIN_BRANDON:
                    newEntry = NPC_CAPTAIN_BRANDON_UNDEAD;
                    break;
                case NPC_CAPTAIN_GRONDEL:
                    newEntry = NPC_CAPTAIN_GRONDEL_UNDEAD;
                    break;
                case NPC_CAPTAIN_RUPERT:
                    newEntry = NPC_CAPTAIN_RUPERT_UNDEAD;
                    break;
                default:
                    return;
            }

            Talk(SAY_CAPTAIN_RESURRECTED);
            me->UpdateEntry(newEntry, me->GetCreatureData());
            DoCast(me, SPELL_UNDEATH, true);
        }
    }

protected:
    EventMap Events;
    InstanceScript* instance;
    float FollowAngle;
    float FollowDist;
    bool IsUndead;

private:
    bool _firstDeath;
};

struct npc_captain_arnath : public npc_argent_captainAI
{
    npc_captain_arnath(Creature* creature) : npc_argent_captainAI(creature)
    {
    }

    void Reset() override
    {
        Events.Reset();
        Events.ScheduleEvent(EVENT_ARNATH_FLASH_HEAL, 4s, 7s);
        Events.ScheduleEvent(EVENT_ARNATH_PW_SHIELD, 8s, 14s);
        Events.ScheduleEvent(EVENT_ARNATH_SMITE, 3s, 6s);
        if (Is25ManRaid() && IsUndead)
            Events.ScheduleEvent(EVENT_ARNATH_DOMINATE_MIND, 22s, 27s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        Events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = Events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ARNATH_FLASH_HEAL:
                    if (Creature* target = FindFriendlyCreature())
                        DoCast(target, SPELL_FLASH_HEAL);
                    Events.ScheduleEvent(EVENT_ARNATH_FLASH_HEAL, 6s, 9s);
                    break;
                case EVENT_ARNATH_PW_SHIELD:
                {
                    std::list<Creature*> targets = DoFindFriendlyMissingBuff(40.0f, SPELL_POWER_WORD_SHIELD);
                    DoCast(Trinity::Containers::SelectRandomContainerElement(targets), SPELL_POWER_WORD_SHIELD);
                    Events.ScheduleEvent(EVENT_ARNATH_PW_SHIELD, 15s, 20s);
                    break;
                }
                case EVENT_ARNATH_SMITE:
                    DoCastVictim(SPELL_SMITE);
                    Events.ScheduleEvent(EVENT_ARNATH_SMITE, 4s, 7s);
                    break;
                case EVENT_ARNATH_DOMINATE_MIND:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                        DoCast(target, SPELL_DOMINATE_MIND);
                    Events.ScheduleEvent(EVENT_ARNATH_DOMINATE_MIND, 28s, 37s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    Creature* FindFriendlyCreature() const
    {
        Creature* target = nullptr;
        Trinity::MostHPMissingInRange u_check(me, 60.0f, 0);
        Trinity::CreatureLastSearcher<Trinity::MostHPMissingInRange> searcher(me, target, u_check);
        Cell::VisitGridObjects(me, searcher, 60.0f);
        return target;
    }
};

struct npc_captain_brandon : public npc_argent_captainAI
{
    npc_captain_brandon(Creature* creature) : npc_argent_captainAI(creature)
    {
    }

    void Reset() override
    {
        Events.Reset();
        Events.ScheduleEvent(EVENT_BRANDON_CRUSADER_STRIKE, 6s, 10s);
        Events.ScheduleEvent(EVENT_BRANDON_DIVINE_SHIELD, 500ms);
        Events.ScheduleEvent(EVENT_BRANDON_JUDGEMENT_OF_COMMAND, 8s, 13s);
        if (IsUndead)
            Events.ScheduleEvent(EVENT_BRANDON_HAMMER_OF_BETRAYAL, 25s, 30s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        Events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = Events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BRANDON_CRUSADER_STRIKE:
                    DoCastVictim(SPELL_CRUSADER_STRIKE);
                    Events.ScheduleEvent(EVENT_BRANDON_CRUSADER_STRIKE, 6s, 12s);
                    break;
                case EVENT_BRANDON_DIVINE_SHIELD:
                    if (HealthBelowPct(20))
                        DoCast(me, SPELL_DIVINE_SHIELD);
                    Events.ScheduleEvent(EVENT_BRANDON_DIVINE_SHIELD, 500ms);
                    break;
                case EVENT_BRANDON_JUDGEMENT_OF_COMMAND:
                    DoCastVictim(SPELL_JUDGEMENT_OF_COMMAND);
                    Events.ScheduleEvent(EVENT_BRANDON_JUDGEMENT_OF_COMMAND, 8s, 13s);
                    break;
                case EVENT_BRANDON_HAMMER_OF_BETRAYAL:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                        DoCast(target, SPELL_HAMMER_OF_BETRAYAL);
                    Events.ScheduleEvent(EVENT_BRANDON_HAMMER_OF_BETRAYAL, 45s, 60s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_captain_grondel : public npc_argent_captainAI
{
    npc_captain_grondel(Creature* creature) : npc_argent_captainAI(creature)
    {
    }

    void Reset() override
    {
        Events.Reset();
        Events.ScheduleEvent(EVENT_GRONDEL_CHARGE_CHECK, 500ms);
        Events.ScheduleEvent(EVENT_GRONDEL_MORTAL_STRIKE, 8s, 14s);
        Events.ScheduleEvent(EVENT_GRONDEL_SUNDER_ARMOR, 3s, 12s);
        if (IsUndead)
            Events.ScheduleEvent(EVENT_GRONDEL_CONFLAGRATION, 12s, 17s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        Events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = Events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_GRONDEL_CHARGE_CHECK:
                    DoCastVictim(SPELL_CHARGE);
                    Events.ScheduleEvent(EVENT_GRONDEL_CHARGE_CHECK, 500ms);
                    break;
                case EVENT_GRONDEL_MORTAL_STRIKE:
                    DoCastVictim(SPELL_MORTAL_STRIKE);
                    Events.ScheduleEvent(EVENT_GRONDEL_MORTAL_STRIKE, 10s, 15s);
                    break;
                case EVENT_GRONDEL_SUNDER_ARMOR:
                    DoCastVictim(SPELL_SUNDER_ARMOR);
                    Events.ScheduleEvent(EVENT_GRONDEL_SUNDER_ARMOR, 5s, 17s);
                    break;
                case EVENT_GRONDEL_CONFLAGRATION:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(target, SPELL_CONFLAGRATION);
                    Events.ScheduleEvent(EVENT_GRONDEL_CONFLAGRATION, 10s, 15s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_captain_rupert : public npc_argent_captainAI
{
    npc_captain_rupert(Creature* creature) : npc_argent_captainAI(creature)
    {
    }

    void Reset() override
    {
        Events.Reset();
        Events.ScheduleEvent(EVENT_RUPERT_FEL_IRON_BOMB, 15s, 20s);
        Events.ScheduleEvent(EVENT_RUPERT_MACHINE_GUN, 25s, 30s);
        Events.ScheduleEvent(EVENT_RUPERT_ROCKET_LAUNCH, 10s, 15s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        Events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = Events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_RUPERT_FEL_IRON_BOMB:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_FEL_IRON_BOMB);
                    Events.ScheduleEvent(EVENT_RUPERT_FEL_IRON_BOMB, 15s, 20s);
                    break;
                case EVENT_RUPERT_MACHINE_GUN:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                        DoCast(target, SPELL_MACHINE_GUN);
                    Events.ScheduleEvent(EVENT_RUPERT_MACHINE_GUN, 25s, 30s);
                    break;
                case EVENT_RUPERT_ROCKET_LAUNCH:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                        DoCast(target, SPELL_ROCKET_LAUNCH);
                    Events.ScheduleEvent(EVENT_RUPERT_ROCKET_LAUNCH, 10s, 15s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_frostwing_ymirjar_vrykul : public ScriptedAI
{
    npc_frostwing_ymirjar_vrykul(Creature* creature) : ScriptedAI(creature), _summons(creature)
    {
    }

    void Reset() override
    {
        _events.Reset();
        _OOCevents.Reset();
        _summons.DespawnAll();

        if (!me->IsAlive())
            return;

        switch (me->GetEntry())
        {
            case NPC_YMIRJAR_FROSTBINDER:
                me->RemoveAurasDueToSpell(SPELL_ARCTIC_CHILL);
            /* fallthrough */
            case NPC_YMIRJAR_DEATHBRINGER:
                _OOCevents.ScheduleEvent(EVENT_YMIRJAR_SPIRIT_STREAM, 10s, 20s);
                break;
            case NPC_YMIRJAR_HUNTRESS:
                if (Is25ManRaid())
                    DoCast(SPELL_SUMMON_WARHAWK);
                break;
            default:
                break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (me->GetEntry() == NPC_YMIRJAR_WARLORD)
            me->RemoveAurasDueToSpell(SPELL_WARLORDS_PRESENCE);
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_YMIRJAR_WARHAWK)
            summon->SetReactState(REACT_DEFENSIVE);

        _summons.Summon(summon);

        if (me->IsEngaged())
            DoZoneInCombat(summon);
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        _summons.Despawn(summon);
    }

    void JustEngagedWith(Unit* who) override
    {
        if (!who)
            return;

        me->InterruptNonMeleeSpells(false);

        switch (me->GetEntry())
        {
            case NPC_YMIRJAR_FROSTBINDER:
                DoCast(SPELL_ARCTIC_CHILL);
                _events.ScheduleEvent(EVENT_YMIRJAR_FROZEN_ORB, 5s, 10s);
                _events.ScheduleEvent(EVENT_YMIRJAR_TWISTED_WINDS, 10s, 20s);
                break;
            case NPC_YMIRJAR_BATTLE_MAIDEN:
                _events.ScheduleEvent(EVENT_YMIRJAR_BARBARIC_STRIKE, 5s, 8s);
                _events.ScheduleEvent(EVENT_YMIRJAR_ADRENALINE_RUSH, 10s, 20s);
                break;
            case NPC_YMIRJAR_WARLORD:
                _events.ScheduleEvent(EVENT_YMIRJAR_WHIRLWIND, 5s, 8s);
                break;
            case NPC_YMIRJAR_HUNTRESS:
                _events.ScheduleEvent(EVENT_YMIRJAR_RAPID_SHOT, 10s, 20s);
                _events.ScheduleEvent(EVENT_YMIRJAR_ICE_TRAP, 5s, 10s);
                _events.ScheduleEvent(EVENT_YMIRJAR_VOLLEY, 20s, 30s);
                _events.ScheduleEvent(EVENT_YMIRJAR_SHOOT, 1s);
                break;
            case NPC_YMIRJAR_DEATHBRINGER:
                _events.ScheduleEvent(EVENT_YMIRJAR_SHADOW_BOLT, 6s, 12s);
                _events.ScheduleEvent(EVENT_YMIRJAR_DEATH_EMBRACE, 5s, 10s);
                _events.ScheduleEvent(EVENT_YMIRJAR_BANISH, 10s, 20s);
                _events.ScheduleEvent(EVENT_YMIRJAR_SUMMON, 10s, 25s);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            _OOCevents.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _OOCevents.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_YMIRJAR_SPIRIT_STREAM:
                        DoCast(SPELL_SPIRIT_STREAM);
                        _OOCevents.Repeat(40s, 60s);
                        break;
                    default:
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
            return;
        }

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_YMIRJAR_FROZEN_ORB:
                    DoCast(me, SPELL_FROZEN_ORB_CAST);
                    _events.Repeat(10s, 20s);
                    break;
                case EVENT_YMIRJAR_TWISTED_WINDS:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.f, true))
                        DoCast(target, SPELL_TWISTED_WINDS);
                    _events.Repeat(10s, 20s);
                    break;
                case EVENT_YMIRJAR_BARBARIC_STRIKE:
                    DoCastVictim(SPELL_BARBARIC_STRIKE);
                    _events.Repeat(2s, 4s);
                    break;
                case EVENT_YMIRJAR_ADRENALINE_RUSH:
                    me->AddAura(SPELL_ADRENALINE_RUSH, me);
                    _events.Repeat(10s, 20s);
                    break;
                case EVENT_YMIRJAR_WHIRLWIND:
                    DoCastAOE(SPELL_WHIRLWIND);
                    _events.Repeat(6s, 12s);
                    break;
                case EVENT_YMIRJAR_RAPID_SHOT:
                    DoCast(SPELL_RAPID_SHOT);
                    _events.Repeat(20s, 30s);
                    break;
                case EVENT_YMIRJAR_ICE_TRAP:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 20.0f, true))
                        DoCast(target, SPELL_ICE_TRAP);
                    _events.Repeat(15s, 20s);
                    break;
                case EVENT_YMIRJAR_VOLLEY:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 40.0f, true))
                        DoCast(target, SPELL_VOLLEY);
                    _events.Repeat(10s, 20s);
                    break;
                case EVENT_YMIRJAR_SHOOT:
                    DoCastVictim(SPELL_YMIRJAR_SHOOT);
                    _events.Repeat(2s);
                    break;
                case EVENT_YMIRJAR_SHADOW_BOLT:
                    DoCastVictim(SPELL_YMIRJAR_SHADOW_BOLT);
                    _events.Repeat(5s, 8s);
                    break;
                case EVENT_YMIRJAR_DEATH_EMBRACE:
                    DoCast(SPELL_DEATH_EMBRACE);
                    _events.Repeat(10s, 20s);
                    break;
                case EVENT_YMIRJAR_BANISH:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 20.0f, true))
                        DoCast(target, SPELL_BANISH);
                    _events.Repeat(10s, 20s);
                    break;
                case EVENT_YMIRJAR_SUMMON:
                    DoCast(SPELL_SUMMON_YMIRJAR);
                    _events.DelayEvents(2s);
                    _events.Repeat(90s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    EventMap _OOCevents;
    SummonList _summons;
};

struct npc_impaling_spear : public CreatureAI
{
    npc_impaling_spear(Creature* creature) : CreatureAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _vehicleCheckTimer = 500;
    }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        Initialize();
    }

    void UpdateAI(uint32 diff) override
    {
        if (_vehicleCheckTimer <= diff)
        {
            _vehicleCheckTimer = 500;
            if (!me->GetVehicle())
                me->DespawnOrUnsummon(100);
        }
        else
            _vehicleCheckTimer -= diff;
    }

private:
    uint32 _vehicleCheckTimer;
};

class ICCSvalnaAliveCheck
{
public:
    bool operator()(WorldObject* object) const
    {
        if (Unit* unit = object->ToUnit())
            return unit->IsAlive();
        return true;
    }
};

class spell_svalna_revive_champion : public SpellScript
{
    PrepareSpellScript(spell_svalna_revive_champion);

    void RemoveAliveTarget(std::list<WorldObject*>& targets)
    {
        targets.remove_if(ICCSvalnaAliveCheck());
        Trinity::Containers::RandomResize(targets, 2);
    }

    void Land(SpellEffIndex /*effIndex*/)
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        Position pos = caster->GetNearPosition(5.0f, 0.0f);
        //pos.m_positionZ = caster->GetBaseMap()->GetHeight(caster->GetPhaseMask(), pos.GetPositionX(), pos.GetPositionY(), caster->GetPositionZ(), true, 50.0f);
        //pos.m_positionZ += 0.05f;
        caster->SetHomePosition(pos);
        caster->GetMotionMaster()->MoveLand(POINT_SVALNA_LAND, pos);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_svalna_revive_champion::RemoveAliveTarget, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
        OnEffectHit += SpellEffectFn(spell_svalna_revive_champion::Land, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_svalna_remove_spear : public SpellScript
{
    PrepareSpellScript(spell_svalna_remove_spear);

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        if (Creature* target = GetHitCreature())
        {
            if (Unit* vehicle = target->GetVehicleBase())
                vehicle->RemoveAurasDueToSpell(SPELL_IMPALING_SPEAR);
            target->DespawnOrUnsummon(1);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_svalna_remove_spear::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class at_icc_start_frostwing_gauntlet : public AreaTriggerScript
{
public:
    at_icc_start_frostwing_gauntlet() : AreaTriggerScript("at_icc_start_frostwing_gauntlet") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            if (Creature* crok = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_CROK_SCOURGEBANE)))
                crok->AI()->DoAction(ACTION_START_GAUNTLET);
        return true;
    }
};

void AddSC_boss_sister_svalna()
{
    RegisterIcecrownCitadelCreatureAI(boss_sister_svalna);
    RegisterIcecrownCitadelCreatureAI(npc_crok_scourgebane);
    RegisterIcecrownCitadelCreatureAI(npc_captain_arnath);
    RegisterIcecrownCitadelCreatureAI(npc_captain_brandon);
    RegisterIcecrownCitadelCreatureAI(npc_captain_grondel);
    RegisterIcecrownCitadelCreatureAI(npc_captain_rupert);
    RegisterIcecrownCitadelCreatureAI(npc_frostwing_ymirjar_vrykul);
    RegisterIcecrownCitadelCreatureAI(npc_impaling_spear);
    new spell_trigger_spell_from_caster("spell_svalna_caress_of_death", SPELL_IMPALING_SPEAR_KILL);
    RegisterSpellScript(spell_svalna_revive_champion);
    RegisterSpellScript(spell_svalna_remove_spear);
    new at_icc_start_frostwing_gauntlet();
}
