#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "MovementGenerator.h"
#include "terrace_of_endless_spring.h"
#include <numeric>
#include "Player.h"

enum eShaOfFearSpells
{
    // Sha of Fear
    SPELL_REACHING_ATTACK = 119775,
    SPELL_EERIE_SKULL = 119519,
    SPELL_BREATH_OF_FEAR = 119414,
    SPELL_THRASH_AURA = 131996,
    SPELL_THRASH_EXTRA_ATTACKS = 131994,
    SPELL_CONJURE_TERROR_SPAWN_TICK = 119108,
    // 4 spells for spawn, cauz' of different spawn coordinates
    SPELL_CONJURE_TERROR_SPAWN_01 = 119312,
    SPELL_CONJURE_TERROR_SPAWN_02 = 119370,
    SPELL_SEEK_THE_LIGHT = 120392,
    SPELL_CONJURE_TERROR_SPAWN_03 = 119371,
    SPELL_CONJURE_TERROR_SPAWN_04 = 119372,
    SPELL_CUSTOM_ENERGY_REGEN = 119417,

    //Heroic
    SPELL_NAKED_AND_AFRAID = 120669,
    SPELL_FADING_LIGHT = 129378,
    SPELL_IMPLACABLE_STRIKE = 120672,
    SPELL_DREAD_THRASH = 132007,
    SPELL_SUBMERGE = 120455,
    SPELL_EMERGE = 120458,
    SPELL_DREAD_THRASH_ATTACKS = 132000,
    SPELL_EMERGE_STUN = 120475,
    SPELL_HUDDLE_IN_TERROR = 120629,
    SPELL_WATERSPOUT_PERIODIC = 120520,
    SPELL_WATERSPOUT_DAMAGE = 120521,
    SPELL_WATERSPOUT_VISUAL = 120556,
    SPELL_WATERSPOUT = 120519,
    SPELL_CHAMPION_OF_THE_LIGHT = 120268,
    SPELL_TRANSFER_LIGHT = 120285,
    SPELL_DREAD_EXPANSE = 120289,
    SPELL_ETERNAL_DARKNESS = 120394,
    SPELL_TELEPORT_SHA = 120191,
    SPELL_TELEPORT_PLAYER = 120192,
    SPELL_TELEPORT_TO_DREAD_EXPANSE = 120221,
    SPELL_PHASE2_ENERGY_REGEN = 120284,

    // Other mobs
    SPELL_LIGHT_WALL = 117865,
    SPELL_CHAMPION_OF_LIGHT = 117866,
    SPELL_LIGHT_WALL_READY = 117770,
    SPELL_LIGHT_WALL_VISUAL = 107141,
    SPELL_FEARLESS = 118977,
    SPELL_WALL_OF_LIGHT_BUFF = 117999,
    SPELL_PENETRATING_BOLT = 129075,
    SPELL_PENETRATING_BOLT_MISSILE = 129077,
    SPELL_DARK_BULWARK = 119083,

    SPELL_SHA_SPINE = 120438,
    SPELL_GATHERING_SPEED = 128419,
};

enum eShaOfFearEvents
{
    EVENT_CHECK_MELEE = 1,
    EVENT_EERIE_SKULL = 2,
    EVENT_CHECK_ENERGY = 3,
    EVENT_FIRST_TERRORS = 4,
    EVENT_PENETRATING_BOLT = 5,
    EVENT_OMINOUS_CACKLE = 6,
    EVENT_EVADE = 7,
    EVENT_BERSERK = 8,
    EVENT_SET_EVADE_TRUE = 10,
    EVENT_HUDDLE_IN_TERROR = 11,
    EVENT_WATERSPOUT = 12,
    EVENT_NAKED_AND_AFRAID = 13,
    EVENT_IMPLACABLE_STRIKE = 14,
    EVENT_CAST_WATERS = 15,
    EVENT_RETURN_TO_COMBAT,
    EVENT_SHA_SPINE,
    EVENT_CHASE_VICTIM,
    EVENT_KILL_NEAR_PLAYERS,
    EVENT_GATHERING_SPEED,
    EVENT_CHECK_PLAYERS_IN_PLATFORM,
    EVENT_SPAWN_DREADS,
    EVENT_SUBMERGE,
    EVENT_MODIFY_EVENTS_SCHEDULE,
    EVENT_RESET_PLAYERS_CDS,
    EVENT_ENRAGE_TIMER,
    EVENT_LEIS_HOPE,
    EVENT_EMERGE,
    EVENT_FOLLOW_TARGETED_PLAYERS,
    EVENT_MOVE_TO_TARGET,
    EVENT_CHECK_PLAYERS,
    EVENT_MOVE_THE_LIGHT,
    EVENT_CHECK_FOR_MOVING_LIGHT,
};

enum eShaOfFearActions
{
    ACTION_ACTIVATE_WALL_OF_LIGHT,
    ACTION_DESACTIVATE_WALL_OF_LIGHT,
    ACTION_SPAWN_TERROR,
    ACTION_DO_WIPE,
};

enum eShaOfFearSays
{
    SAY_INTRO,
    SAY_AGGRO,
    SAY_BREATH_OF_FEAR,
    SAY_SLAY,
    SAY_PHASE_2,
    SAY_SUBMERGE,
    SAY_HUDDLE,
    EMOTE_PHASE_2,

};

enum Entities
{
    NPC_YANG_GUOSHI = 61038,
    NPC_JINLUN_KUN = 61046,
    NPC_CHENG_KANG = 61042,
};

enum AdditionalAIs
{
    NPC_WATERSPOUT = 48571,
    NPC_DREAD_SPAWN = 61003,
};

enum AdditionalMisc
{
    ACTION_NEW_TARGET = 12, // cel putin cred ca e 12 next ..
};

enum Misc
{
    ACTION_BOWMAN_AGGRESSIVE = 10
};

struct BowmanData
{
    uint32 entry;
    uint32 spellId;
    float x;
    float y;
    float z;
    float o;
    bool active;
};

static BowmanData bowmenData[] = // DNC
{
    { NPC_YANG_GUOSHI, 119593, -1214.795f, -2824.823f, 41.24303f, 3.506719f },
    { NPC_CHENG_KANG, 119693, -1075.198f, -2577.711f, 15.828019f, 1.725f },
    { NPC_JINLUN_KUN, 119692, -832.0764f, -2745.405f, 31.67757f, 0.1583484f }
};

Position const centerPlatform{ -1017.52f, -2772.47f, 38.57f, 0.0f };

Player* GetChampionOfLight(Creature* me)
{
    if (!me)
        return NULL;

    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
    for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
        if (Player* player = itr->GetSource())
            if (player->HasAura(SPELL_CHAMPION_OF_LIGHT))
                return player;

    return NULL;
}

static const Position spawnTerrorPos[4] =
{
    { -1052.588f, -2788.164f, 38.268f, 0.0f },
    { -983.4550f, -2787.942f, 38.269f, 0.0f },
    { -989.6860f, -2772.245f, 38.303f, 0.0f },
    { -1046.274f, -2772.215f, 38.303f, 0.0f }
};

enum eShaPhases
{
    PHASE_TERRACE = 1,
    PHASE_DREAD_EXPANSE = 2,
};

class notValidTargetPredicate
{
public:
    notValidTargetPredicate(Unit* _caster) : caster(_caster) {}

    bool operator()(WorldObject* target) const
    {
        return target && target->ToPlayer() && target->ToPlayer()->GetExactDist2d(caster) > 70.f; // && (target->ToPlayer()->HasAura(SPELL_CHAMPION_OF_LIGHT)
    }
private:
    Unit* caster;
};

static const Position lightPos = { -1017.835f, -2771.984f, 38.65444f, 4.718282f };

class boss_sha_of_fear : public CreatureScript
{
public:
    boss_sha_of_fear() : CreatureScript("boss_sha_of_fear") { }

    struct boss_sha_of_fearAI : public BossAI
    {
        boss_sha_of_fearAI(Creature* creature) : BossAI(creature, DATA_SHA_OF_FEAR)
        {
            pInstance = creature->GetInstanceScript();
            introDone = false;
            isDuringP2Transition = false;
            //me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);

            for (int i = 0; i < 3; ++i)
            {
                BowmanData* data = new BowmanData();
                data->entry = bowmenData[i].entry;
                data->spellId = bowmenData[i].spellId;
                data->x = bowmenData[i].x;
                data->y = bowmenData[i].y;
                data->z = bowmenData[i].z;
                data->o = bowmenData[i].o;
                data->active = false;

                pandaMap.insert(std::make_pair(data, data->entry));
            }

            me->ApplySpellImmune(0, IMMUNITY_ID, 108199, true); // Gorefiend's Grasp
        }

        InstanceScript* pInstance;
        EventMap m_mEvents;

        uint8 attacksCounter;
        uint8 terrorCounter;

        uint8 m_uiPhase;
        uint32 wipeTimer;

        bool m_canEvade;
        bool phase2Hidden;
        bool isDuringP2Transition;
        bool isSecondEvent;
        bool failSafe;
        uint8 adds;
        bool LeiHope;
        std::unordered_map<BowmanData*, uint32> pandaMap;

        void Reset() override
        {
            _Reset();
            wipeTimer = 1000;


            if (isDuringP2Transition)
                return;

            me->SetPower(POWER_ENERGY, 0);
            m_canEvade = true;
            isDuringP2Transition = false;

            me->AddAura(72242, me);
            failSafe = false;
            phase2Hidden = false;
            me->SetReactState(REACT_DEFENSIVE);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->RestoreDisplayId();
            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            summons.DespawnAll();
            RemoveLeisHope();
            SetPhase(0);
            adds = 0;
            attacksCounter = 0;
            terrorCounter = 0;

            for (std::unordered_map<BowmanData*, uint32>::iterator itr = pandaMap.begin(); itr != pandaMap.end(); ++itr)
            {
                itr->first->active = false;
            }

            isSecondEvent = false;

            if (pInstance)
            {
                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }
        }

        void SetPhase(uint8 m_phase)
        {
            events.Reset();

            switch (m_phase)
            {
            case PHASE_TERRACE:
                events.ScheduleEvent(EVENT_CHECK_MELEE, 1000);
                events.ScheduleEvent(EVENT_CHECK_PLAYERS, 2000, 0, 0);
                events.ScheduleEvent(EVENT_EERIE_SKULL, 6500);
                events.ScheduleEvent(EVENT_CHECK_ENERGY, 1000);
                events.ScheduleEvent(EVENT_FIRST_TERRORS, 30000);
                events.ScheduleEvent(EVENT_OMINOUS_CACKLE, 20000);
                break;
            case PHASE_DREAD_EXPANSE:
            {
                me->GetMap()->LoadGrid(-1659.16f, -3783.51f);
                Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                    if (Player* player = i->GetSource())
                        player->NearTeleportTo(-1659.16f, -3783.51f, -279.502f, 3.546f);
                me->NearTeleportTo(-1730.42f, -3839.9f, -279.502f, 6.14f);
                me->ClearUnitState(UNIT_STATE_ROOT);
                summons.DespawnAll();
                events.ScheduleEvent(EVENT_MOVE_TO_TARGET, 1000, 0, 0);
                events.ScheduleEvent(EVENT_HUDDLE_IN_TERROR, 65000, 0, 0);
                events.ScheduleEvent(EVENT_SUBMERGE, 55000, 0, 0);
                events.ScheduleEvent(EVENT_NAKED_AND_AFRAID, 30000, 0, 0);
                events.ScheduleEvent(EVENT_WATERSPOUT, 40000, 0, 0);
                events.ScheduleEvent(EVENT_CHECK_FOR_MOVING_LIGHT, 1500, 0, 0);
                events.CancelEvent(EVENT_ENRAGE_TIMER); // cancel 15 min enrage
                events.ScheduleEvent(EVENT_ENRAGE_TIMER, 10 * MINUTE * IN_MILLISECONDS); // schedule 10 mins again
                // cancel events from phase terrace
                events.CancelEvent(EVENT_CHECK_ENERGY);
                events.CancelEvent(EVENT_EERIE_SKULL);
                events.CancelEvent(EVENT_FIRST_TERRORS);
                events.CancelEvent(EVENT_CHECK_PLAYERS);
                events.CancelEvent(EVENT_CHECK_MELEE);
                events.CancelEvent(EVENT_OMINOUS_CACKLE);
                events.ScheduleEvent(EVENT_RESET_PLAYERS_CDS, 4000, 0, 0);
                me->RemoveAura(SPELL_THRASH_AURA);
                me->RemoveAura(SPELL_CUSTOM_ENERGY_REGEN);
                me->CastSpell(me, SPELL_PHASE2_ENERGY_REGEN);
                RemoveOminousFromPlayers();
                RemoveLeisHope();
                RemoveBloodlustCooldown();
                RemoveTimeWarpCooldown();
                RemoveExhaustionCooldown();
                me->SetHealth(me->CountPctFromMaxHealth(66));
                //summons.DespawnAll();
                //me->SetVisible(true);
                //DoCast(SPELL_TELEPORT_TO_DREAD_EXPANSE);
                //DoCast(SPELL_TELEPORT_SHA);
                //me->CastSpell(me, SPELL_TELEPORT_SHA, true);
                //DoCast(SPELL_TELEPORT_SHA);
                //me->SetReactState(REACT_AGGRESSIVE);
                //me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                //SetCombatMovement(true);
                //events.ScheduleEvent(EVENT_SET_EVADE_TRUE, 2000);
                //m_canEvade = false;
                Talk(SAY_PHASE_2);
                Talk(EMOTE_PHASE_2);

                for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                    if (Player* player = i->GetSource())
                        player->ModifyAuraState(AURA_STATE_UNKNOWN22, true);
                if (Player* pPlayer = GetChampionOfLight(me))
                    pPlayer->CastSpell(pPlayer, SPELL_CHAMPION_OF_THE_LIGHT, true);

                //me->RemoveAurasDueToSpell(SPELL_CUSTOM_ENERGY_REGEN);

                //SetupPhaseTwoEvents();
                //me->SetInCombatWithZone();
                //events.ScheduleEvent(EVENT_CHECK_ENERGY, 1000);

                //me->SetHealth((me->GetMaxHealth() / 66.6f) * 100);
                break;
            }
            }

            m_uiPhase = m_phase;
            //events.SetPhase(m_phase);
        }

        void GetAvailablePandaAndSummon()
        {
            std::unordered_map<BowmanData*, uint32> newPandaMap;
            newPandaMap.reserve(sizeof(pandaMap));
            std::copy(pandaMap.begin(), pandaMap.end(), std::inserter(newPandaMap, newPandaMap.begin()));

            std::unordered_map<BowmanData*, uint32>::iterator itr = newPandaMap.begin();

            for (; itr != newPandaMap.end();)
            {
                if (itr->first->active)
                    itr = newPandaMap.erase(itr);
                else
                    ++itr;
            }

            itr = newPandaMap.begin();

            if (!newPandaMap.empty())
            {
                if (newPandaMap.size() > 1)
                    std::advance(itr, std::rand() % (newPandaMap.size() - 1));

                if (itr != newPandaMap.cend())
                {
                    for (std::unordered_map<BowmanData*, uint32>::const_iterator finder = pandaMap.begin(); finder != pandaMap.end(); ++finder)
                    {
                        if (finder->first->entry == itr->second)
                        {
                            PropagateSummon(finder);
                            return;
                        }
                    }
                }
            }

            itr = pandaMap.begin();

            std::advance(itr, std::rand() % (pandaMap.size() - 1));

            if (itr != pandaMap.cend())
                DoCast(me, itr->first->spellId);
        }

        void PropagateSummon(std::unordered_map<BowmanData*, uint32>::const_iterator& itr)
        {
            if (Creature* pBowman = me->SummonCreature(itr->first->entry, itr->first->x, itr->first->y, itr->first->z, itr->first->o))
            {
                DoCast(me, itr->first->spellId);
                itr->first->active = true;

                if (pBowman->AI())
                    pBowman->AI()->DoAction(ACTION_BOWMAN_AGGRESSIVE);
            }
        }

        void JustReachedHome() override
        {
            _JustReachedHome();

            if (pInstance)
                pInstance->SetBossState(DATA_SHA_OF_FEAR, FAIL);
        }

        // not used because I want to handle events with my types
        void SetupPhaseTwoEvents()
        {
            uint32 mEvents[3] = { EVENT_HUDDLE_IN_TERROR, EVENT_WATERSPOUT, EVENT_IMPLACABLE_STRIKE };

            std::iota(std::begin(mEvents), std::end(mEvents), 0);
            std::random_shuffle(std::begin(mEvents), std::end(mEvents));

            for (uint8 i = 0; i < 3; ++i)
            {
                events.ScheduleEvent(mEvents[i], urand(12000, 17000) + i * (urand(15000, 19000)));
            }
        }


        void RemoveOminousFromPlayers()
        {
            Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
            if (!PlayerList.isEmpty())
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    i->GetSource()->RemoveAura(129147); // Ominous Cackcle visual ( including immune and fly )
        }

        void RemovePlayerCooldowns()
        {
            DoCast(SPELL_FADING_LIGHT);
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    player->RemoveArenaSpellCooldowns();
        }

        void EnterCombat(Unit* /*attacker*/) override
        {

            if (isDuringP2Transition)
                return;

            me->SetPower(POWER_ENERGY, 0);
            events.ScheduleEvent(EVENT_ENRAGE_TIMER, 15 * MINUTE * IN_MILLISECONDS);
            DoCast(me, SPELL_CUSTOM_ENERGY_REGEN, true);

            if (pInstance)
            {
                pInstance->SetBossState(DATA_SHA_OF_FEAR, IN_PROGRESS);
                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                DoZoneInCombat();
                Talk(SAY_AGGRO);
            }

            SetPhase(PHASE_TERRACE);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (pInstance)
            {
                summons.DespawnAll();
                pInstance->SetBossState(DATA_SHA_OF_FEAR, DONE);
                pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _JustDied();
            }

            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            me->RemoveAura(SPELL_SUBMERGE);
            me->RestoreDisplayId();
            // trigger criteria id 23250 (ACHIEVEMENT_CRITERIA_TYPE_EARNED_PVP_TITLE), used in achievement "Ahead of the Curve: Sha of Fear"
            // and some more, but no idea why, just complete it
        }

        void EnterEvadeMode(EvadeReason w)
        {
            if (m_canEvade)
            {
                if (me->HasUnitState(UNIT_STATE_CANNOT_TURN))
                    me->ClearUnitState(UNIT_STATE_CANNOT_TURN);

                Map::PlayerList const& lPlayers = me->GetMap()->GetPlayers();

                for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                {
                    if (Player* pPlayer = itr->GetSource())
                    {
                        if (pPlayer->IsAlive() && !pPlayer->IsGameMaster())
                            pPlayer->Kill(pPlayer, false);
                        // No durability loss for a wipe in a case like this

                        if (pPlayer->HasAura(SPELL_CHAMPION_OF_THE_LIGHT))
                            pPlayer->RemoveAurasDueToSpell(SPELL_CHAMPION_OF_THE_LIGHT);

                        pPlayer->RemoveAurasDueToSpell(SPELL_DREAD_EXPANSE);
                        pPlayer->RemoveAurasDueToSpell(SPELL_FEARLESS);
                    }
                }

                if (m_uiPhase == PHASE_TERRACE)
                    BossAI::EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
                else
                {
                    //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);

                    m_mEvents.ScheduleEvent(EVENT_EVADE, 10000);

                    float x, y, z, o;
                    me->GetHomePosition(x, y, z, o);
                    me->SetVisible(true);
                    me->GetMap()->LoadGrid(x, y);

                    // enter evade causes home movement generator, manually finalize it so creature gets out of evade mode
                    BossAI::EnterEvadeMode(EVADE_REASON_NO_HOSTILES);

                    me->GetMotionMaster()->top()->Finalize(me);
                    me->NearTeleportTo(x, y, z, o);
                    me->UpdateObjectVisibility();
                    //CastLeisHope();
                    LeiHope = true;
                    // teleport players
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                            player->NearTeleportTo(-1017.87f, -2841.21f, 38.02f, 1.53f);

                }
            }
        }

        void JustSummoned(Creature* summon) override
        {
            if (summon->GetEntry() == NPC_TERROR_SPAWN)
                ++terrorCounter;

            if (summon->GetEntry() == NPC_DREAD_SPAWN)
                summon->SetInCombatWithZone();

            summons.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            if (summon->GetEntry() == NPC_TERROR_SPAWN)
                --terrorCounter;

            summons.Despawn(summon);
        }

        void SummonedCreatureDies(Creature* summon, Unit*) override
        {
            switch (summon->GetEntry())
            {
            case NPC_YANG_GUOSHI:
            case NPC_CHENG_KANG:
            case NPC_JINLUN_KUN:
                for (std::unordered_map<BowmanData*, uint32>::iterator itr = pandaMap.begin(); itr != pandaMap.end(); ++itr)
                {
                    if (itr->first->entry == summon->GetEntry())
                        itr->first->active = false;
                }
                if (events.GetNextEventTime(EVENT_OMINOUS_CACKLE) > 30000)
                    events.RescheduleEvent(EVENT_OMINOUS_CACKLE, 30000);
                break;
            default:
                return;
            }
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                Talk(SAY_SLAY);
            }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_SPAWN_TERROR:
            {
                if (!terrorCounter)
                {
                    /*me->CastSpell(spawnTerrorPos[0].GetPositionX(), spawnTerrorPos[0].GetPositionY(),
                        spawnTerrorPos[0].GetPositionZ(), SPELL_CONJURE_TERROR_SPAWN_01, true);
                    me->CastSpell(spawnTerrorPos[1].GetPositionX(), spawnTerrorPos[1].GetPositionY(),
                        spawnTerrorPos[1].GetPositionZ(), SPELL_CONJURE_TERROR_SPAWN_02, true);*/
                    me->SummonCreature(NPC_TERROR_SPAWN, spawnTerrorPos[0].GetPositionX(), spawnTerrorPos[0].GetPositionY(), spawnTerrorPos[0].GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(NPC_TERROR_SPAWN, spawnTerrorPos[1].GetPositionX(), spawnTerrorPos[1].GetPositionY(), spawnTerrorPos[1].GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN);
                }
                else
                {
                    /*me->CastSpell(spawnTerrorPos[2].GetPositionX(), spawnTerrorPos[2].GetPositionY(),
                        spawnTerrorPos[2].GetPositionZ(), SPELL_CONJURE_TERROR_SPAWN_03, true);
                    me->CastSpell(spawnTerrorPos[3].GetPositionX(), spawnTerrorPos[3].GetPositionY(),
                        spawnTerrorPos[3].GetPositionZ(), SPELL_CONJURE_TERROR_SPAWN_04, true);*/
                    me->SummonCreature(NPC_TERROR_SPAWN, spawnTerrorPos[2].GetPositionX(), spawnTerrorPos[2].GetPositionY(), spawnTerrorPos[2].GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN);
                    me->SummonCreature(NPC_TERROR_SPAWN, spawnTerrorPos[3].GetPositionX(), spawnTerrorPos[3].GetPositionY(), spawnTerrorPos[3].GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN);
                }

                break;
            }
            case ACTION_DO_WIPE:
            {
                Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                    if (Player* player = i->GetSource())
                        if (player->GetDistance2d(centerPlatform.m_positionX, centerPlatform.m_positionY) > 85.0f)
                        {
                            me->Kill(player, true);
                            break;
                        }
                break;
            }
            default:
                break;
            }
        }

        void RemoveBloodlustCooldown()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    player->RemoveAura(57724);
        }

        void RemoveTimeWarpCooldown()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    player->RemoveAura(80354);
        }

        void RemoveExhaustionCooldown()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                    player->RemoveAura(57723);
        }

        void DamageDealt(Unit* /*victim*/, uint32& /*damage*/, DamageEffectType damageType) override
        {
            if (damageType == DIRECT_DAMAGE)
            {
                if (m_uiPhase == PHASE_TERRACE)
                {
                    if (attacksCounter >= 3 && !me->m_extraAttacks)
                    {
                        me->CastSpell(me, SPELL_THRASH_EXTRA_ATTACKS, true);
                        attacksCounter = 0;
                    }
                    else if (attacksCounter >= 2 && !me->m_extraAttacks)
                    {
                        me->CastSpell(me, SPELL_THRASH_AURA, true);
                        ++attacksCounter;
                    }
                    else if (!me->m_extraAttacks)
                    {
                        me->RemoveAura(SPELL_THRASH_AURA);
                        ++attacksCounter;
                    }
                }
                else
                {
                    if (attacksCounter >= 12 && !me->m_extraAttacks)
                    {
                        DoCast(me, SPELL_DREAD_THRASH_ATTACKS, true);
                        attacksCounter = 0;
                    }
                    else if (attacksCounter >= 11 && !me->m_extraAttacks)
                    {
                        me->CastSpell(me, SPELL_DREAD_THRASH, true);
                        ++attacksCounter;
                    }
                    else if (!me->m_extraAttacks)
                    {
                        me->RemoveAura(SPELL_DREAD_THRASH);
                        ++attacksCounter;
                    }
                }
            }
        }

        void DamageTaken(Unit* /*dealer*/, uint32& uiDamage)
        {
            if (me->HealthBelowPct(67) && !failSafe)
            {
                failSafe = true;
                events.CancelEvent(EVENT_OMINOUS_CACKLE);
            }

            if (me->HealthBelowPctDamaged(66, uiDamage) && (m_uiPhase == PHASE_TERRACE))
            {
                if (me->GetMap()->IsHeroic())
                {
                    // this is useless wtf
                    /*if (auto const pInstance = me->GetInstanceScript())
                    {
                        if (pInstance->GetData(TYPE_LEIS_HOPE) != DONE)
                            pInstance->SetData(TYPE_LEIS_HOPE, DONE);
                    }*/
                    //SetPhase(PHASE_DREAD_EXPANSE); DISABLE DUE TO CORE AND GAME CHANGES
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_mEvents.Update(diff);

            switch (m_mEvents.ExecuteEvent())
            {
            case EVENT_EVADE:
                me->SetVisible(true);
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                break;
            }

            if (m_uiPhase == PHASE_DREAD_EXPANSE)
            {
                if (wipeTimer <= diff)
                {
                    wipeTimer = 1000;
                    bool alivePlayers = false;
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                            if (player->IsAlive() && !player->IsGameMaster())
                            {
                                alivePlayers = true;
                                break;
                            }
                    if (!alivePlayers)
                    {
                        me->CombatStop();
                        me->getHostileRefManager().deleteReferences();
                        EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
                        return;
                    }
                }
                else wipeTimer -= diff;
            }

            if (!UpdateVictim())
            {
                //if (pInstance && pInstance->GetData(SPELL_RITUAL_OF_PURIFICATION) == false)
                    //me->RemoveAura(SPELL_RITUAL_OF_PURIFICATION);

                return;
            }

            events.Update(diff);

            //if (me->HasUnitState(UNIT_STATE_CASTING))
             //   return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_ENERGY:
                    if (!pInstance)
                    {
                        events.ScheduleEvent(EVENT_CHECK_ENERGY, 1000);
                        break;
                    }

                    if (me->GetPower(POWER_ENERGY) >= me->GetMaxPower(POWER_ENERGY))
                    {
                        if (m_uiPhase == PHASE_TERRACE)
                        {
                            if (Creature* pureLight = me->FindNearestCreature(NPC_PURE_LIGHT_TERRACE, 500.0f))
                                me->CastSpell(pureLight, SPELL_BREATH_OF_FEAR, false);
                            Talk(SAY_BREATH_OF_FEAR);
                        }
                        me->SetPower(POWER_ENERGY, 0);
                    }

                    events.ScheduleEvent(EVENT_CHECK_ENERGY, 1000);
                    break;
                case EVENT_CHECK_MELEE:
                    if (Player* target = GetChampionOfLight(me))
                    {
                        if (me->GetVictim() && me->GetVictim()->GetGUID() != target->GetGUID())
                        {
                            me->TauntFadeOut(me->GetVictim());
                            DoResetThreat();
                            AttackStart(target);
                            me->TauntApply(target);
                            me->AddThreat(target, 5000000.0f);
                        }
                    }

                    if (!me->IsWithinMeleeRange(me->GetVictim()))
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f))
                            me->CastSpell(target, SPELL_REACHING_ATTACK, false);
                    }
                    events.ScheduleEvent(EVENT_CHECK_MELEE, 1000);
                    break;
                case EVENT_EERIE_SKULL:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 80.0f))
                        me->CastSpell(target, SPELL_EERIE_SKULL, true);
                    events.ScheduleEvent(EVENT_EERIE_SKULL, 6500);
                    break;
                case EVENT_FIRST_TERRORS:
                    me->CastSpell(me, SPELL_CONJURE_TERROR_SPAWN_TICK, true);
                    break;
                case EVENT_OMINOUS_CACKLE:
                    GetAvailablePandaAndSummon();
                    switch (me->GetMap()->GetDifficultyID())
                    {
                    case DIFFICULTY_10_N:
                    case DIFFICULTY_10_HC:
                        events.ScheduleEvent(EVENT_OMINOUS_CACKLE, 90000);
                        break;
                    case DIFFICULTY_25_N:
                    case DIFFICULTY_25_HC:
                        events.ScheduleEvent(EVENT_OMINOUS_CACKLE, 45000);
                        break;
                    }
                    break;
                case EVENT_CHECK_PLAYERS:
                {
                    bool rangePlayers = false;
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                            if (player->IsAlive() && !player->IsGameMaster() && player->GetDistance(me) < 75.0f)
                            {
                                rangePlayers = true;
                                //sWorld->SendWorldText(3, "Players found alive in 75 yards, no wipe.");
                                break;
                            }
                    if (!rangePlayers)
                    {
                        me->CombatStop();
                        me->getHostileRefManager().deleteReferences();
                        EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
                        //sWorld->SendWorldText(3, "No players found alive in 75 yards, wipe.");
                        return;
                    }
                    events.ScheduleEvent(EVENT_CHECK_PLAYERS, 2000, 0, 0);
                    break;
                }
                case EVENT_WATERSPOUT:
                {
                    switch (me->GetMap()->GetDifficultyID())
                    {
                    case DIFFICULTY_10_N:
                    case DIFFICULTY_10_HC:
                        CastWaterspout10();
                        break;
                    case DIFFICULTY_25_N:
                    case DIFFICULTY_25_HC:
                        CastWaterspout25();
                        break;
                    }
                    events.ScheduleEvent(EVENT_WATERSPOUT, 40000, 0, 0);
                    break;
                }
                case EVENT_IMPLACABLE_STRIKE:
                {
                    if (Unit* target = me->GetVictim())
                    {
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->StopMoving();
                        if (Creature* trigger = me->SummonCreature(60942, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 5000))
                        {
                            me->SetFacingToObject(trigger);
                            me->AddThreat(trigger, 9.9999999f);
                            me->CastSpell(trigger, SPELL_IMPLACABLE_STRIKE);
                        }
                        events.ScheduleEvent(EVENT_RETURN_TO_COMBAT, 4000, 0, 0);
                        events.ScheduleEvent(EVENT_NAKED_AND_AFRAID, 30000, 0, 0);
                        break;
                    }
                }
                case EVENT_RETURN_TO_COMBAT:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_MOVE_TO_TARGET:
                    if (Unit* target = me->GetVictim())
                    {
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveChase(target);
                    }
                    break;
                case EVENT_HUDDLE_IN_TERROR:
                {
                    Talk(SAY_HUDDLE);
                    switch (me->GetMap()->GetDifficultyID())
                    {
                    case DIFFICULTY_10_N:
                    case DIFFICULTY_10_HC:
                        CastHuddleInTerror10();
                        break;
                    case DIFFICULTY_25_N:
                    case DIFFICULTY_25_HC:
                        CastHuddleInTerror25();
                        break;
                    }
                    events.ScheduleEvent(EVENT_HUDDLE_IN_TERROR, 65000, 0, 0);
                    break;
                }
                case EVENT_SET_EVADE_TRUE:
                    isDuringP2Transition = false;
                    me->SetVisible(true);
                    me->UpdateObjectVisibility();
                    me->ClearUnitState(UNIT_STATE_ROOT);
                    SetCombatMovement(true);
                    DoZoneInCombat();

                    if (me->GetVictim())
                        AttackStart(me->GetVictim());

                    DoCast(me, SPELL_PHASE2_ENERGY_REGEN, true);
                    m_canEvade = true;
                    break;
                case EVENT_NAKED_AND_AFRAID:
                    me->CastSpell(me->GetVictim(), SPELL_NAKED_AND_AFRAID);
                    events.ScheduleEvent(EVENT_IMPLACABLE_STRIKE, 30000, 0, 0);
                    break;
                case EVENT_SUBMERGE:
                {
                    //me->AddAura(SPELL_SUBMERGE, me);
                    me->SetDisplayId(22452);
                    me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                    me->AddUnitState(UNIT_STATE_ROOT);
                    me->SetSpeed(MOVE_WALK, 50.0f);
                    me->SetSpeed(MOVE_RUN, 50.0f);
                    phase2Hidden = true;
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    {
                        me->NearTeleportTo(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), me->GetOrientation(), false);
                    }
                    events.ScheduleEvent(EVENT_EMERGE, 1000, 0, 0);
                    events.ScheduleEvent(EVENT_MODIFY_EVENTS_SCHEDULE, 1500, 0, 0);
                    events.ScheduleEvent(EVENT_SUBMERGE, 55000, 0, 0);
                    break;
                }
                case EVENT_MODIFY_EVENTS_SCHEDULE:
                    events.DelayEvents(10000);
                    break;
                case EVENT_EMERGE:
                    me->CastSpell(me, SPELL_EMERGE);
                    phase2Hidden = false;
                    //me->RestoreDisplayId();
                    me->SetSpeed(MOVE_WALK, 1.0f);
                    me->SetSpeed(MOVE_RUN, 1.0f);
                    events.ScheduleEvent(EVENT_SPAWN_DREADS, 500, 0, 0);
                    break;
                case EVENT_SPAWN_DREADS:
                {
                    me->SummonCreature(NPC_DREAD_SPAWN, -1779.25f, -3788.39f, -279.50f, 5.22f, TEMPSUMMON_CORPSE_DESPAWN);
                    CountAdds();
                    break;
                }
                case EVENT_ENRAGE_TIMER:
                    me->CastSpell(me, SPELL_BERSERK, true);
                    break;
                case EVENT_RESET_PLAYERS_CDS:
                    RemovePlayerCooldowns();
                    break;
                case EVENT_CHECK_FOR_MOVING_LIGHT:
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                        {
                            if (player->HasAura(SPELL_CHAMPION_OF_THE_LIGHT))
                                return;
                        }
                    events.ScheduleEvent(EVENT_MOVE_THE_LIGHT, 500, 0, 0);
                    break;
                }
                case EVENT_MOVE_THE_LIGHT:
                    if (Unit* random = SelectTarget(SELECT_TARGET_RANDOM, 0, 500.0f, true))
                        me->AddAura(SPELL_CHAMPION_OF_THE_LIGHT, random);
                    break;
                default:
                    break;
                }
            }
            if (!phase2Hidden)
                DoMeleeAttackIfReady();
        }

        // well, Dread Spawns should spawn 1 in the first timer and the second timer should be 2, next 3, next 4 .. etc, we're doing this for a couple time, i made for .. 10~
        void CountAdds()
        {
            ++adds;

            if (adds == 2)
            {
                AdditionalAdds();
            }
            if (adds == 3)
            {
                AdditionalAdds2();
            }
            if (adds == 4)
            {
                AdditionalAdds2();
                AdditionalAdds();
            }
            if (adds == 5)
            {
                AdditionalAdds();
                AdditionalAdds();
            }
            if (adds == 6)
            {
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds2();
            }
            if (adds == 7)
            {
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds2();
            }
            if (adds == 8)
            {
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds();
            }
            if (adds == 9)
            {
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds2();
            }
            if (adds == 10)
            {
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds2();
                AdditionalAdds2();
            }
            if (adds == 11)
            {
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds2();
                AdditionalAdds2();
            }
            if (adds == 12)
            {
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds();
            }
            if (adds == 13)
            {
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds();
            }
            if (adds == 14)
            {
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds();
            }
            if (adds == 15)
            {
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds2();
            }
            if (adds == 16)
            {
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds();
            }
            if (adds == 17)
            {
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds();
            }
            if (adds == 18)
            {
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds();
            }
            if (adds == 19)
            {
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds2();
                AdditionalAdds();
            }
        }

        void AdditionalAdds()
        {
            me->SummonCreature(NPC_DREAD_SPAWN, -1822.39f, -3855.75f, -279.50f, 6.13f, TEMPSUMMON_CORPSE_DESPAWN);
        }

        void AdditionalAdds2()
        {
            me->SummonCreature(NPC_DREAD_SPAWN, -1762.28f, -3932.69f, -279.50f, 1.39f, TEMPSUMMON_CORPSE_DESPAWN);
        }

        void CastLeisHope()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
            {
                if (Player* player = itr->GetSource())
                {
                    me->AddAura(SPELL_LEIS_HOPE, player);
                }
            }
        }

        void RemoveLeisHope()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
            {
                if (Player* player = itr->GetSource())
                {
                    player->RemoveAura(SPELL_LEIS_HOPE);
                }
            }
        }

        void CastHuddleInTerror25()
        {
            std::list<Unit*> targets;
            SelectTargetList(targets, 5, SELECT_TARGET_FARTHEST, 1000.0f, true);
            if (!targets.empty())
                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                {
                    if ((*itr)->HasAura(SPELL_CHAMPION_OF_THE_LIGHT))
                        return;

                    me->AddAura(SPELL_HUDDLE_IN_TERROR, (*itr));
                }
        }

        void CastHuddleInTerror10()
        {
            std::list<Unit*> targets;
            SelectTargetList(targets, 3, SELECT_TARGET_FARTHEST, 1000.0f, true);
            if (!targets.empty())
                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                {
                    if ((*itr)->HasAura(SPELL_CHAMPION_OF_THE_LIGHT))
                        return;

                    me->AddAura(SPELL_HUDDLE_IN_TERROR, (*itr));
                }
        }

        void CastWaterspout10()
        {
            std::list<Unit*> targets;
            SelectTargetList(targets, 1, SELECT_TARGET_RANDOM, 1000.0f, true);
            if (!targets.empty())
                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    (*itr)->AddAura(SPELL_WATERSPOUT, (*itr));
            //  me->SummonCreature(NPC_WATERSPOUT, (*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ(), (*itr)->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 10000);
              //DoCast(*itr, SPELL_WATERSPOUT, true);
        }

        void CastWaterspout25()
        {
            std::list<Unit*> targets;
            SelectTargetList(targets, 3, SELECT_TARGET_RANDOM, 1000.0f, true);
            if (!targets.empty())
                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    (*itr)->AddAura(SPELL_WATERSPOUT, (*itr));
            // me->SummonCreature(NPC_WATERSPOUT, (*itr)->GetPositionX(), (*itr)->GetPositionY(), (*itr)->GetPositionZ(), (*itr)->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 10000);
            // DoCast(*itr, SPELL_WATERSPOUT, true);
        }

    private:
        bool bowmenStatus[3];
        bool introDone;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_sha_of_fearAI(creature);
    }
};



// Pure Light Terrace - 60788
class mob_pure_light_terrace : public CreatureScript
{
public:
    mob_pure_light_terrace() : CreatureScript("mob_pure_light_terrace") { }

    struct mob_pure_light_terraceAI : public ScriptedAI
    {
        mob_pure_light_terraceAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
            wallActivated = false;
        }

        InstanceScript* pInstance;

        bool wallActivated;
        //float ang1;
        //float ang2;

        void Reset()
        {
            lightTimer = 200;
            me->SetFaction(35);
            me->CastSpell(me, SPELL_LIGHT_WALL, true);
            me->CastSpell(me, SPELL_LIGHT_WALL_READY, true);

            //Position dst1 = {-989.4236f, -2821.757f, 38.25466f, 0.0f};
            //Position dst2 = {-1045.602f, -2822.323f, 38.25466f, 0.0f};
            //
            //ang1 = src.GetAngle(&dst1) * 57.29578f;
            //ang2 = src.GetAngle(&dst2) * 57.29578f;
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_ACTIVATE_WALL_OF_LIGHT:
            {
                if (wallActivated)
                    break;

                wallActivated = true;
                me->CastSpell(me, SPELL_LIGHT_WALL_VISUAL, true);
                me->RemoveAura(SPELL_LIGHT_WALL_READY);
                break;
            }
            case ACTION_DESACTIVATE_WALL_OF_LIGHT:
            {
                if (!wallActivated)
                    break;

                wallActivated = false;
                me->CastSpell(me, SPELL_LIGHT_WALL_READY, true);
                me->RemoveAura(SPELL_LIGHT_WALL_VISUAL);
                break;
            }
            default:
                break;
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            damage = 0;
            return;
        }

        void UpdateAI(uint32 diff)
        {
            if (lightTimer >= diff)
            {
                lightTimer -= diff;
                return;
            }

            lightTimer = 100;

            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
            {
                if (Player* player = itr->GetSource())
                {
                    // 60* frontal arc
                    if (lightPos.HasInArc(3.14f/ 3.0f, player) && wallActivated)
                    {
                        if (!player->HasAura(SPELL_WALL_OF_LIGHT_BUFF) && !player->HasAura(SPELL_CHAMPION_OF_LIGHT))
                            player->CastSpell(player, SPELL_WALL_OF_LIGHT_BUFF, true);
                    }
                    else
                        player->RemoveAura(SPELL_WALL_OF_LIGHT_BUFF);
                }
            }
        }

    private:
        uint32 lightTimer;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_pure_light_terraceAI(creature);
    }
};

// Terror Spawn - 61034
class mob_terror_spawn : public CreatureScript
{
public:
    mob_terror_spawn() : CreatureScript("mob_terror_spawn") { }

    struct mob_terror_spawnAI : public ScriptedAI
    {
        mob_terror_spawnAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;


        void DamageTaken(Unit* unit, uint32& damage)
        {
            if (me->isInFront(unit))
            {
                damage = 0;
                me->SetHealth(me->GetHealth() + 1);
                me->SetHealth(me->GetHealth() - 1);
            }
        }

        void Reset()
        {
            me->AddUnitState(UNIT_STATE_ROOT);

            me->CastSpell(me, SPELL_DARK_BULWARK, true);

            events.Reset();
            events.ScheduleEvent(EVENT_PENETRATING_BOLT, 5000);
        }

        void UpdateAI(uint32 diff)
        {
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
            case EVENT_PENETRATING_BOLT:
            {
                me->CastSpell(me, SPELL_PENETRATING_BOLT, false);
                events.ScheduleEvent(EVENT_PENETRATING_BOLT, 5000);
                break;
            }
            default:
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_terror_spawnAI(creature);
    }
};

// Champion of Light - 117866
class bfa_spell_toes_champion_of_light : public SpellScriptLoader
{
public:
    bfa_spell_toes_champion_of_light() : SpellScriptLoader("bfa_spell_toes_champion_of_light") { }

    class bfa_spell_toes_champion_of_light_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_toes_champion_of_light_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
                if (caster->ToCreature() && caster->ToCreature()->AI())
                    caster->ToCreature()->AI()->DoAction(ACTION_ACTIVATE_WALL_OF_LIGHT);
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
                if (caster->ToCreature() && caster->ToCreature()->AI())
                    caster->ToCreature()->AI()->DoAction(ACTION_DESACTIVATE_WALL_OF_LIGHT);
        }

        void Register()
        {
            AfterEffectApply += AuraEffectApplyFn(bfa_spell_toes_champion_of_light_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(bfa_spell_toes_champion_of_light_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
        }
    };


    class bfa_spell_toes_champion_of_light_Spellcript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_toes_champion_of_light_Spellcript);

        void SelectChampion(std::list<WorldObject*>& targets)
        {
            for (auto itr = targets.begin(); itr != targets.end();)
            {
                Player* target = (*itr)->ToPlayer();
                // we have a target outside the trigger range
                if (!target->IsWithinDist2d(&lightPos, 3.0f))
                {
                    if (target->HasAura(SPELL_CHAMPION_OF_LIGHT))
                        target->RemoveAurasDueToSpell(SPELL_CHAMPION_OF_LIGHT);

                    itr = targets.erase(itr);
                }
                else if (target->HasAura(SPELL_CHAMPION_OF_LIGHT))
                {
                    targets.clear();
                    return;
                }
                else
                    ++itr;
            }

            if (!targets.empty())
                Trinity::Containers::RandomResize(targets, 1);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_toes_champion_of_light_Spellcript::SelectChampion, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_toes_champion_of_light_Spellcript();
    }

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_toes_champion_of_light_AuraScript();
    }
};

// Breath of Fear - 119414 / 125786
class bfa_spell_toes_breath_of_fear : public SpellScriptLoader
{
public:
    bfa_spell_toes_breath_of_fear() : SpellScriptLoader("bfa_spell_toes_breath_of_fear") { }

    class aura_impl : public AuraScript
    {
        PrepareAuraScript(aura_impl);

        void OnTick(AuraEffect const* /*aurEff*/)
        {
            // Breath of Fear only affects targets not in the wall of light
            if (Unit* player = GetUnitOwner())
                if (!player->IsWithinDist2d(GetCaster(), 60.0f) || player->HasAura(SPELL_WALL_OF_LIGHT_BUFF) || player->HasAura(SPELL_CHAMPION_OF_LIGHT))
                    PreventDefaultAction();
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(aura_impl::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new aura_impl();
    }
};

// Breath of Fear - 125786
class bfa_spell_toes_breath_of_fear_fear : public SpellScriptLoader
{
public:
    bfa_spell_toes_breath_of_fear_fear() : SpellScriptLoader("bfa_spell_toes_breath_of_fear_fear") {}

    class bfa_spell_toes_impl : public SpellScript
    {
        PrepareSpellScript(bfa_spell_toes_impl);

        void CorrectRange(std::list<WorldObject*>& targets)
        {
            targets.clear();

            // Breath of Fear only affects targets not in the wall of light
            Map::PlayerList const& players = GetCaster()->GetMap()->GetPlayers();
            if (!players.isEmpty())
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    if (Player* player = itr->GetSource())
                        if (player->IsWithinDist2d(GetCaster(), 60.0f) && !player->HasAura(SPELL_WALL_OF_LIGHT_BUFF) && !player->HasAura(SPELL_CHAMPION_OF_LIGHT) && !player->IsGameMaster())
                            targets.push_back(player);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_toes_impl::CorrectRange, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_toes_impl::CorrectRange, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_toes_impl::CorrectRange, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_toes_impl();
    }
};


// Conjure Terror Spawn - 119108
class bfa_spell_toes_conjure_terror_spawn : public SpellScriptLoader
{
public:
    bfa_spell_toes_conjure_terror_spawn() : SpellScriptLoader("bfa_spell_toes_conjure_terror_spawn") { }

    class bfa_spell_toes_conjure_terror_spawn_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_toes_conjure_terror_spawn_AuraScript);

        void OnTick(AuraEffect const* /*aurEff*/)
        {
            if (Creature* caster = GetCaster()->ToCreature())
                caster->AI()->DoAction(ACTION_SPAWN_TERROR);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_toes_conjure_terror_spawn_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_toes_conjure_terror_spawn_AuraScript();
    }
};

// Penetrating Bolt - 129075
/*class bfa_spell_toes_penetrating_bolt : public SpellScriptLoader
{
public:
    bfa_spell_toes_penetrating_bolt() : SpellScriptLoader("bfa_spell_toes_penetrating_bolt") { }

    class bfa_spell_toes_penetrating_bolt_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_toes_penetrating_bolt_SpellScript);

        uint64 targetGuid;

        void CorrectRange(std::list<WorldObject*>& targets)
        {
            targetGuid = 0;

            if (!targets.empty())
                Trinity::Containers::RandomResizeList(targets, 1);

            for (auto itr : targets)
                if (itr->GetGUID())
                    targetGuid = itr->GetGUID();
        }

        void HandleDummy(SpellEffIndex index)
        {
            if (Unit* caster = GetCaster())
            {
                if (InstanceScript* instance = caster->GetInstanceScript())
                {
                    if (Player* target = Player::GetPlayer(*caster, targetGuid))
                    {
                        if (target->HasAura(SPELL_CHAMPION_OF_LIGHT))
                            return;
                        caster->CastSpell(target, SPELL_PENETRATING_BOLT_MISSILE, true, NULL, NULL, instance->GetData64(NPC_SHA_OF_FEAR));
                    }
                }
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_toes_penetrating_bolt_SpellScript::CorrectRange, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectLaunch += SpellEffectFn(bfa_spell_toes_penetrating_bolt_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_toes_penetrating_bolt_SpellScript();
    }
};*/

// Ominous Cackle - 119593, 119692, 119693
class bfa_spell_toes_ominous_caclke_target : public SpellScriptLoader
{
public:
    bfa_spell_toes_ominous_caclke_target() : SpellScriptLoader("bfa_spell_toes_ominous_caclke_target") {}

    class bfa_spell_toes_impl : public SpellScript
    {
        PrepareSpellScript(bfa_spell_toes_impl);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            std::list<WorldObject*> vTanks;
            std::list<WorldObject*> vHealers;

            if (Unit* caster = GetCaster())
            {
                targets.remove_if(notValidTargetPredicate(caster));


                if (targets.size() > 3)
                    targets.resize(3);

                std::list<WorldObject*>::iterator itr = vTanks.begin();
                std::list<WorldObject*>::iterator itr2 = vHealers.begin();

                if (vTanks.size() > 1)
                    std::advance(itr, urand(0, vTanks.size() - 1));

                if (itr != vTanks.end())
                    targets.insert(targets.begin(), *itr);

                if (vHealers.size() > 1)
                    std::advance(itr2, urand(0, vHealers.size() - 1));

                if (itr2 != vHealers.end())
                    targets.insert(targets.begin(), *itr2);

                if (targets.empty())
                {
                    if (caster->ToCreature()->AI())
                        caster->ToCreature()->AI()->DoAction(ACTION_DO_WIPE);
                }

            }

        }

        void ApplyMorph(SpellEffIndex effIndex)
        {
            Unit* caster = GetCaster();
            Player* victim = GetHitPlayer();

            if (!caster || !victim)
                return;


            victim->CastSpell(victim, 129147, true);
            uint32 path = 0;
            switch (GetSpellInfo()->Id)
            {
            case 119593: path = 1; break;
            case 119693: path = 2; break;
            case 119692: path = 3; break;
            default:
                return;
            }
            // Works for players aswell. Should it?
            victim->GetMotionMaster()->MovePath(path, false);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_toes_impl::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(bfa_spell_toes_impl::ApplyMorph, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_toes_impl();
    }
};


// Cheng Kang 61042, Yang Guoshi 61038, Jinlun Kun 61046
class npc_sha_of_fear_bowman : public CreatureScript
{
    enum
    {
        SPELL_DEATH_BLOSSOM = 119888,
        SPELL_DREAD_SPRAY = 119862,
        SPELL_SHOOT = 119862,
        SPELL_SHA_GLOBE = 129178,
        SPELL_DREAD_SPRAY_INIT = 120047,
        SPELL_FEARLESS_ENABLER = 131504,
        SPELL_SHA_CORRUPTION = 120000,
        SPELL_DREAD_SPRAY_MISSILE = 119956,
    };

    enum
    {
        EVENT_DEATH_BLOSSOM = 1,
        EVENT_DREAD_SPRAY,
        EVENT_DREAD_SPRAY_END,
        EVENT_SHOOT,
        // Kun
        EVENT_DREAD_SPRAY_RIGHT_1,
        EVENT_DREAD_SPRAY_RIGHT_2,
        EVENT_DREAD_SPRAY_RIGHT_3,
        EVENT_DREAD_SPRAY_RIGHT_4,
        EVENT_DREAD_SPRAY_RIGHT_5,
        EVENT_DREAD_SPRAY_RIGHT_6,
        EVENT_DREAD_SPRAY_RIGHT_7,
        EVENT_DREAD_SPRAY_RIGHT_8,
        EVENT_DREAD_SPRAY_RIGHT_9,
        EVENT_DREAD_SPRAY_RIGHT_10,
        EVENT_DREAD_SPRAY_RIGHT_11,
        EVENT_DREAD_SPRAY_RIGHT_12,
        EVENT_DREAD_SPRAY_RIGHT_13,
        EVENT_DREAD_SPRAY_RIGHT_14,
        EVENT_DREAD_SPRAY_RIGHT_15,
        EVENT_DREAD_SPRAY_RIGHT_16,

        // Guoshi
        EVENT_DREAD_SPRAY_LEFT_1,
        EVENT_DREAD_SPRAY_LEFT_2,
        EVENT_DREAD_SPRAY_LEFT_3,
        EVENT_DREAD_SPRAY_LEFT_4,
        EVENT_DREAD_SPRAY_LEFT_5,
        EVENT_DREAD_SPRAY_LEFT_6,
        EVENT_DREAD_SPRAY_LEFT_7,
        EVENT_DREAD_SPRAY_LEFT_8,
        EVENT_DREAD_SPRAY_LEFT_9,
        EVENT_DREAD_SPRAY_LEFT_10,
        EVENT_DREAD_SPRAY_LEFT_11,
        EVENT_DREAD_SPRAY_LEFT_12,
        EVENT_DREAD_SPRAY_LEFT_13,
        EVENT_DREAD_SPRAY_LEFT_14,
        EVENT_DREAD_SPRAY_LEFT_15,
        EVENT_DREAD_SPRAY_LEFT_16,

        // Yang
        EVENT_DREAD_SPRAY_BACK_1,
        EVENT_DREAD_SPRAY_BACK_2,
        EVENT_DREAD_SPRAY_BACK_3,
        EVENT_DREAD_SPRAY_BACK_4,
        EVENT_DREAD_SPRAY_BACK_5,
        EVENT_DREAD_SPRAY_BACK_6,
        EVENT_DREAD_SPRAY_BACK_7,
        EVENT_DREAD_SPRAY_BACK_8,
        EVENT_DREAD_SPRAY_BACK_9,
        EVENT_DREAD_SPRAY_BACK_10,
        EVENT_DREAD_SPRAY_BACK_11,
        EVENT_DREAD_SPRAY_BACK_12,
        EVENT_DREAD_SPRAY_BACK_13,
        EVENT_DREAD_SPRAY_BACK_14,
        EVENT_DREAD_SPRAY_BACK_15,
        EVENT_DREAD_SPRAY_BACK_16,

        EVENT_DREAD_SPRAY_YANG,
        EVENT_DREAD_SPRAY_CHENG,
        EVENT_DREAD_SPRAY_JINLUN,
    };

    enum
    {
        SAY_AGGRO,
        SAY_DEATH,
        SAY_UNK,
    };

    struct npc_sha_of_fear_bowmanAI : public ScriptedAI
    {
        npc_sha_of_fear_bowmanAI(Creature* creature) : ScriptedAI(creature)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, 31935, true); // Avenger's Shield
        }

        EventMap events;
        bool globe;
        bool globe1;
        bool globe2;
        bool globe3;
        bool globe4;
        bool globe5;
        bool globe6;
        bool globe7;
        bool globe8;
        bool globe9;
        bool globe10;
        bool globe11;
        bool globe12;
        bool globe13;
        bool globe14;
        bool globe15;
        bool globe16;
        bool globe17;
        bool globe18;

        void Reset() override
        {
            me->AddAura(42716, me); // root
            //me->SetReactState(REACT_PASSIVE);
            //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            // shoot spell max distance
            //me->m_ReactDistance = 40.0f;
            me->m_CombatDistance = 40.0f;
            lastHealthPct = 99;
            globe = false;
            globe1 = false;
            globe2 = false;
            globe3 = false;
            globe4 = false;
            globe5 = false;
            globe6 = false;
            globe7 = false;
            globe8 = false;
            globe9 = false;
            globe10 = false;
            globe11 = false;
            globe12 = false;
            globe13 = false;
            globe14 = false;
            globe15 = false;
            globe16 = false;
            globe17 = false;
            globe18 = false;
            events.Reset();
        }

        EventMap m_mLowEvents;

        void EnterCombat(Unit*) override
        {
            Talk(SAY_AGGRO);
            RemoveOminousIfExists();
            events.ScheduleEvent(EVENT_SHOOT, 500);
            events.ScheduleEvent(EVENT_DREAD_SPRAY, 8000);
        }



        void JustDied(Unit*) override
        {
            Talk(SAY_DEATH);

            if (Creature* pTerrace = me->FindNearestCreature(NPC_RETURN_TO_TERRACE, 500.0f))
            {
                pTerrace->UpdateObjectVisibility();
                pTerrace->AddAura(120216, pTerrace);
            }
        }

        void RemoveOminousIfExists()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (player->GetDistance(me) < 30.0f)
                    {
                        player->RemoveAura(129147);
                    }
                }
        }

        void DoAction(int32 action)
        {
            if (action == ACTION_BOWMAN_AGGRESSIVE)
            {
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->setActive(true);

                if (Creature* pTerrace = GetClosestCreatureWithEntry(me, NPC_RETURN_TO_TERRACE, 30.f))
                {
                    pTerrace->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
                    pTerrace->RemoveAura(120216);
                }
            }
        }

        // useless
        /*void HealReceived(Unit* , uint32& heal) override
        {
            lastHealthPct = me->GetHealthPct();
        }*/

        void DamageTaken(Unit*, uint32& damage) override
        {
            /*if (me->HealthBelowPctDamaged(lastHealthPct, damage))
            {
            if (me->HealthBelowPctDamaged(int32(lastHealthPct - 5.0f), damage))
            DoCast(SPELL_SHA_GLOBE);
            }*/

            if (me->HealthBelowPct(95) && !globe)
            {
                globe = true;
                DoCast(SPELL_SHA_GLOBE);
            }
            if (me->HealthBelowPct(90) && !globe1)
            {
                globe1 = true;
                DoCast(SPELL_SHA_GLOBE);
            }
            if (me->HealthBelowPct(85) && !globe2)
            {
                globe2 = true;
                DoCast(SPELL_SHA_GLOBE);
            }
            if (me->HealthBelowPct(80) && !globe3)
            {
                globe3 = true;
                DoCast(SPELL_SHA_GLOBE);
            }
            if (me->HealthBelowPct(75) && !globe4)
            {
                globe4 = true;
                DoCast(SPELL_SHA_GLOBE);
            }
            if (me->HealthBelowPct(70) && !globe5)
            {
                globe5 = true;
                DoCast(SPELL_SHA_GLOBE);
            }
            if (me->HealthBelowPct(65) && !globe6)
            {
                globe6 = true;
                DoCast(SPELL_SHA_GLOBE);
            }
            if (me->HealthBelowPct(60) && !globe7)
            {
                globe7 = true;
                DoCast(SPELL_SHA_GLOBE);
            }
            if (me->HealthBelowPct(55) && !globe8)
            {
                globe8 = true;
                DoCast(SPELL_SHA_GLOBE);
            }
            if (me->HealthBelowPct(50) && !globe9)
            {
                globe9 = true;
                DoCast(SPELL_SHA_GLOBE);
            }
            if (me->HealthBelowPct(45) && !globe10)
            {
                globe10 = true;
                DoCast(SPELL_SHA_GLOBE);
            }
            if (me->HealthBelowPct(40) && !globe11)
            {
                globe11 = true;
                DoCast(SPELL_SHA_GLOBE);
            }
            if (me->HealthBelowPct(35) && !globe12)
            {
                globe12 = true;
                DoCast(SPELL_SHA_GLOBE);
            }
            if (me->HealthBelowPct(30) && !globe13)
            {
                globe13 = true;
                DoCast(SPELL_SHA_GLOBE);
            }
            if (me->HealthBelowPct(25) && !globe14)
            {
                globe14 = true;
                DoCast(SPELL_SHA_GLOBE);
                events.ScheduleEvent(EVENT_DEATH_BLOSSOM, 1000);
            }
            if (me->HealthBelowPct(20) && !globe15)
            {
                globe15 = true;
                DoCast(SPELL_SHA_GLOBE);
            }
            if (me->HealthBelowPct(15) && !globe16)
            {
                globe16 = true;
                DoCast(SPELL_SHA_GLOBE);
            }
            if (me->HealthBelowPct(10) && !globe17)
            {
                globe17 = true;
                DoCast(SPELL_SHA_GLOBE);
            }
            if (me->HealthBelowPct(10) && !globe18)
            {
                globe18 = true;
                DoCast(SPELL_SHA_GLOBE);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case EVENT_DREAD_SPRAY:
                me->SetReactState(REACT_PASSIVE);
                me->AttackStop();
                //DoCast(me, SPELL_DREAD_SPRAY_INIT, false);
                events.DelayEvents(9000);
                events.ScheduleEvent(EVENT_DREAD_SPRAY, 20000);
                events.ScheduleEvent(EVENT_DREAD_SPRAY_END, 8500);
                switch (me->GetEntry())
                {
                    // Yang Guoshi (right side)
                case NPC_YANG_GUOSHI:
                    events.ScheduleEvent(EVENT_DREAD_SPRAY_YANG, 100);
                    break;
                    // Cheng Kang (back shrine)
                case NPC_CHENG_KANG:
                    events.ScheduleEvent(EVENT_DREAD_SPRAY_CHENG, 100);
                    break;
                    // Jinlun Kun (left side)
                case NPC_JINLUN_KUN:
                    events.ScheduleEvent(EVENT_DREAD_SPRAY_JINLUN, 100);
                    break;
                }
                break;
            case EVENT_DREAD_SPRAY_YANG:
                events.ScheduleEvent(EVENT_DREAD_SPRAY_LEFT_1, 300);
                break;
            case EVENT_DREAD_SPRAY_CHENG:
                events.ScheduleEvent(EVENT_DREAD_SPRAY_BACK_1, 300);
                break;
            case EVENT_DREAD_SPRAY_JINLUN:
                events.ScheduleEvent(EVENT_DREAD_SPRAY_RIGHT_1, 300);
                break;
            case EVENT_DREAD_SPRAY_LEFT_1:
            {
                if (Creature* dread = me->SummonCreature(60942, -1207.77f, -2808.16f, 41.27f, 4.33f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    //me->SetTarget(0);
                    me->SetFacingToObject(dread);
                    me->AddThreat(dread, 9999999999.0f);
                    me->AI()->AttackStart(dread);
                    me->SetOrientation(4.33f);
                    me->SetFacingTo(4.33f);
                    me->CastSpell(dread, SPELL_DREAD_SPRAY_MISSILE, true);
                    //me->Kill(dread, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_LEFT_2, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_LEFT_2:
            {
                if (Creature* dread1 = me->SummonCreature(60942, -1221.70f, -2840.50f, 41.27f, 1.18f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    //->SetTarget(0);
                    me->SetFacingToObject(dread1);
                    me->AddThreat(dread1, 9999999999.0f);
                    me->AI()->AttackStart(dread1);
                    me->SetOrientation(1.18f);
                    me->SetFacingTo(1.18f);
                    me->CastSpell(dread1, SPELL_DREAD_SPRAY_MISSILE, true);
                    //me->Kill(dread1, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_LEFT_3, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_LEFT_3:
            {
                if (Creature* dread3 = me->SummonCreature(60942, -1221.70f, -2840.50f, 41.27f, 1.18f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    //me->SetTarget(0);
                    me->SetFacingToObject(dread3);
                    me->AddThreat(dread3, 9999999999.0f);
                    me->AI()->AttackStart(dread3);
                    me->SetOrientation(1.18f);
                    me->SetFacingTo(1.18f);
                    me->CastSpell(dread3, SPELL_DREAD_SPRAY_MISSILE, true);
                    //me->Kill(dread3, false);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_LEFT_4, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_LEFT_4:
            {
                if (Creature* dread4 = me->SummonCreature(60942, -1207.77f, -2808.16f, 41.27f, 4.33f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    //me->SetTarget(0);
                    me->SetFacingToObject(dread4);
                    me->AddThreat(dread4, 9999999999.0f);
                    me->AI()->AttackStart(dread4);
                    me->SetOrientation(4.33f);
                    me->SetFacingTo(4.33f);
                    me->CastSpell(dread4, SPELL_DREAD_SPRAY_MISSILE, true);
                    //me->Kill(dread4, false);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_LEFT_5, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_LEFT_5:
            {
                if (Creature* dread5 = me->SummonCreature(60942, -1207.72f, -2841.015f, 41.27f, 2.00f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    //me->SetTarget(0);
                    me->SetFacingToObject(dread5);
                    me->AddThreat(dread5, 9999999999.0f);
                    me->AI()->AttackStart(dread5);
                    me->SetOrientation(2.00f);
                    me->SetFacingTo(2.00f);
                    me->CastSpell(dread5, SPELL_DREAD_SPRAY_MISSILE, true);
                    // me->Kill(dread5, false);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_LEFT_6, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_LEFT_6:
            {
                if (Creature* dread6 = me->SummonCreature(60942, -1221.52f, -2808.03f, 41.26f, 2.00f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    //me->SetTarget(0);
                    me->SetFacingToObject(dread6);
                    me->AddThreat(dread6, 9999999999.0f);
                    me->AI()->AttackStart(dread6);
                    me->SetOrientation(2.00f);
                    me->SetFacingTo(2.00f);
                    me->CastSpell(dread6, SPELL_DREAD_SPRAY_MISSILE, true);
                    //me->Kill(dread6, false);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_LEFT_7, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_LEFT_7:
            {
                if (Creature* dread7 = me->SummonCreature(60942, -1221.52f, -2808.033f, 41.26f, 2.00f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    // me->SetTarget(0);
                    me->SetFacingToObject(dread7);
                    me->AddThreat(dread7, 9999999999.0f);
                    me->AI()->AttackStart(dread7);
                    me->SetOrientation(2.00f);
                    me->SetFacingTo(2.00f);
                    me->CastSpell(dread7, SPELL_DREAD_SPRAY_MISSILE, true);
                    //me->Kill(dread7, false);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_LEFT_8, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_LEFT_8:
            {
                if (Creature* dread8 = me->SummonCreature(60942, -1207.72f, -2841.01f, 41.27f, 2.00f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    //me->SetTarget(0);
                    me->SetFacingToObject(dread8);
                    me->AddThreat(dread8, 9999999999.0f);
                    me->AI()->AttackStart(dread8);
                    me->SetOrientation(2.00f);
                    me->SetFacingTo(2.00f);
                    me->CastSpell(dread8, SPELL_DREAD_SPRAY_MISSILE, true);
                    //me->Kill(dread8, false);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_LEFT_9, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_LEFT_9:
            {
                if (Creature* dread9 = me->SummonCreature(60942, -1196.94f, -2832.35f, 41.27f, 2.72f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    //me->SetTarget(0);
                    me->SetFacingToObject(dread9);
                    me->AddThreat(dread9, 9999999999.0f);
                    me->AI()->AttackStart(dread9);
                    me->SetOrientation(2.72f);
                    me->SetFacingTo(2.72f);
                    me->CastSpell(dread9, SPELL_DREAD_SPRAY_MISSILE, true);
                    //me->Kill(dread9, false);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_LEFT_10, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_LEFT_10:
            {
                if (Creature* dread10 = me->SummonCreature(60942, -1231.92f, -2816.89f, 41.27f, 2.72f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    // me->SetTarget(0);
                    me->SetFacingToObject(dread10);
                    me->AddThreat(dread10, 9999999999.0f);
                    me->AI()->AttackStart(dread10);
                    me->SetOrientation(2.72f);
                    me->SetFacingTo(2.72f);
                    me->CastSpell(dread10, SPELL_DREAD_SPRAY_MISSILE, true);
                    //me->Kill(dread10, false);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_LEFT_11, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_LEFT_11:
            {
                if (Creature* dread11 = me->SummonCreature(60942, -1231.92f, -2816.89f, 41.27f, 2.72f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    //me->SetTarget(0);
                    me->SetFacingToObject(dread11);
                    me->AddThreat(dread11, 9999999999.0f);
                    me->AI()->AttackStart(dread11);
                    me->SetOrientation(2.72f);
                    me->SetFacingTo(2.72f);
                    me->CastSpell(dread11, SPELL_DREAD_SPRAY_MISSILE, true);
                    //me->Kill(dread11, false);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_LEFT_12, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_LEFT_12:
            {
                if (Creature* dread12 = me->SummonCreature(60942, -1196.94f, -2832.35f, 41.27f, 2.72f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    //me->SetTarget(0);
                    me->SetFacingToObject(dread12);
                    me->AddThreat(dread12, 9999999999.0f);
                    me->AI()->AttackStart(dread12);
                    me->SetOrientation(2.72f);
                    me->SetFacingTo(2.72f);
                    me->CastSpell(dread12, SPELL_DREAD_SPRAY_MISSILE, true);
                    //me->Kill(dread12, false);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_LEFT_13, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_LEFT_13:
            {
                if (Creature* dread13 = me->SummonCreature(60942, -1234.26f, -2832.70f, 41.27f, 3.56f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dread13);
                    me->AddThreat(dread13, 9999999999.0f);
                    me->AI()->AttackStart(dread13);
                    me->SetOrientation(3.56f);
                    me->SetFacingTo(3.56f);
                    me->CastSpell(dread13, SPELL_DREAD_SPRAY_MISSILE, true);
                    // me->Kill(dread13, false);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_LEFT_14, 500);
                break;
            }

            case EVENT_DREAD_SPRAY_LEFT_14:
            {
                if (Creature* dread14 = me->SummonCreature(60942, -1194.13f, -2817.33f, 41.27f, 0.40f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {

                    me->SetFacingToObject(dread14);
                    me->AddThreat(dread14, 9999999999.0f);
                    me->AI()->AttackStart(dread14);
                    me->SetOrientation(0.40f);
                    me->SetFacingTo(0.40f);
                    me->CastSpell(dread14, SPELL_DREAD_SPRAY_MISSILE, true);
                    // me->Kill(dread14, false);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_LEFT_15, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_LEFT_15:
            {
                if (Creature* dread15 = me->SummonCreature(60942, -1194.13f, -2817.33f, 41.27f, 0.40f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dread15);
                    me->AddThreat(dread15, 9999999999.0f);
                    me->AI()->AttackStart(dread15);
                    me->SetOrientation(0.40f);
                    me->SetFacingTo(0.40f);
                    me->CastSpell(dread15, SPELL_DREAD_SPRAY_MISSILE, true);
                    // me->Kill(dread15, false);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_LEFT_16, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_LEFT_16:
            {
                if (Creature* dread16 = me->SummonCreature(60942, -1234.26f, -2832.70f, 41.27f, 3.56f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    //me->SetTarget(0);
                    me->SetFacingToObject(dread16);
                    me->AddThreat(dread16, 9.9999999f);
                    me->AI()->AttackStart(dread16);
                    me->SetOrientation(3.56f);
                    me->SetFacingTo(3.56f);
                    me->CastSpell(dread16, SPELL_DREAD_SPRAY_MISSILE, true);
                    // me->Kill(dread16, false);
                }
                break;
            }
            case EVENT_DREAD_SPRAY_RIGHT_1:
            {
                if (Creature* dreads1 = me->SummonCreature(60942, -851.40f, -2749.25f, 31.70f, 3.40f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreads1);
                    me->AddThreat(dreads1, 9.9999999f);
                    me->AI()->AttackStart(dreads1);
                    me->SetOrientation(3.40f);
                    me->SetFacingTo(3.40f);
                    me->CastSpell(dreads1, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_RIGHT_2, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_RIGHT_2:
            {
                if (Creature* dreads2 = me->SummonCreature(60942, -849.71f, -2732.63f, 31.70f, 2.52f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreads2);
                    me->AddThreat(dreads2, 9.9999999f);
                    me->AI()->AttackStart(dreads2);
                    me->SetOrientation(2.52f);
                    me->SetFacingTo(2.52f);
                    me->CastSpell(dreads2, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_RIGHT_3, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_RIGHT_3:
            {
                if (Creature* dreads3 = me->SummonCreature(60942, -821.18f, -2729.04f, 31.70f, 0.87f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreads3);
                    me->AddThreat(dreads3, 9.9999999f);
                    me->AI()->AttackStart(dreads3);
                    me->SetOrientation(0.87f);
                    me->SetFacingTo(0.87f);
                    me->CastSpell(dreads3, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_RIGHT_4, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_RIGHT_4:
            {
                if (Creature* dreads4 = me->SummonCreature(60942, -812.44f, -2741.92f, 31.70f, 0.19f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreads4);
                    me->AddThreat(dreads4, 9.9999999f);
                    me->AI()->AttackStart(dreads4);
                    me->SetOrientation(0.19f);
                    me->SetFacingTo(0.19f);
                    me->CastSpell(dreads4, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_RIGHT_5, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_RIGHT_5:
            {
                if (Creature* dreads5 = me->SummonCreature(60942, -836.01f, -2726.12f, 31.70f, 1.75f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreads5);
                    me->AddThreat(dreads5, 9.9999999f);
                    me->AI()->AttackStart(dreads5);
                    me->SetOrientation(1.75f);
                    me->SetFacingTo(1.75f);
                    me->CastSpell(dreads5, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_RIGHT_6, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_RIGHT_6:
            {
                if (Creature* dreads6 = me->SummonCreature(60942, -820.79f, -2729.70f, 31.70f, 0.86f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreads6);
                    me->AddThreat(dreads6, 9.9999999f);
                    me->AI()->AttackStart(dreads6);
                    me->SetOrientation(0.86f);
                    me->SetFacingTo(0.86f);
                    events.ScheduleEvent(EVENT_DREAD_SPRAY_RIGHT_7, 500);
                    me->CastSpell(dreads6, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                break;
            }
            case EVENT_DREAD_SPRAY_RIGHT_7:
            {
                if (Creature* dreads7 = me->SummonCreature(60942, -816.08f, -2756.60f, 31.70f, 5.62f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreads7);
                    me->AddThreat(dreads7, 9.9999999f);
                    me->AI()->AttackStart(dreads7);
                    me->SetOrientation(5.62f);
                    me->SetFacingTo(5.62f);
                    me->CastSpell(dreads7, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_RIGHT_8, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_RIGHT_8:
            {
                if (Creature* dreads8 = me->SummonCreature(60942, -828.26f, -2765.74f, 31.70f, 4.86f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreads8);
                    me->AddThreat(dreads8, 9.9999999f);
                    me->AI()->AttackStart(dreads8);
                    me->SetOrientation(4.86f);
                    me->SetFacingTo(4.86f);
                    me->CastSpell(dreads8, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_RIGHT_9, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_RIGHT_9:
            {
                if (Creature* dreads9 = me->SummonCreature(60942, -812.54f, -2741.03f, 31.70f, 0.08f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreads9);
                    me->AddThreat(dreads9, 9.9999999f);
                    me->AI()->AttackStart(dreads9);
                    me->SetOrientation(0.08f);
                    me->SetFacingTo(0.08f);
                    me->CastSpell(dreads9, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_RIGHT_10, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_RIGHT_10:
            {
                if (Creature* dreads10 = me->SummonCreature(60942, -815.97f, -2756.46f, 31.70f, 5.74f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreads10);
                    me->AddThreat(dreads10, 9.9999999f);
                    me->AI()->AttackStart(dreads10);
                    me->SetOrientation(5.74f);
                    me->SetFacingTo(5.74f);
                    me->CastSpell(dreads10, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_RIGHT_11, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_RIGHT_11:
            {
                if (Creature* dreads11 = me->SummonCreature(60942, -843.77f, -2762.26f, 31.70f, 4.08f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreads11);
                    me->AddThreat(dreads11, 9.9999999f);
                    me->AI()->AttackStart(dreads11);
                    me->SetOrientation(4.08f);
                    me->SetFacingTo(4.08f);
                    me->CastSpell(dreads11, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_RIGHT_12, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_RIGHT_12:
            {
                if (Creature* dreads12 = me->SummonCreature(60942, -851.19f, -2748.67f, 31.70f, 3.28f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreads12);
                    me->AddThreat(dreads12, 9.9999999f);
                    me->AI()->AttackStart(dreads12);
                    me->SetOrientation(3.28f);
                    me->SetFacingTo(3.28f);
                    me->CastSpell(dreads12, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_RIGHT_13, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_RIGHT_13:
            {
                if (Creature* dreads13 = me->SummonCreature(60942, -828.93f, -2764.36f, 31.70f, 4.87f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreads13);
                    me->AddThreat(dreads13, 9.9999999f);
                    me->AI()->AttackStart(dreads13);
                    me->SetOrientation(4.87f);
                    me->SetFacingTo(4.87f);
                    me->CastSpell(dreads13, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_RIGHT_14, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_RIGHT_14:
            {
                if (Creature* dreads14 = me->SummonCreature(60942, -842.89f, -2762.34f, 31.70f, 4.10f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreads14);
                    me->AddThreat(dreads14, 9.9999999f);
                    me->AI()->AttackStart(dreads14);
                    me->SetOrientation(4.10f);
                    me->SetFacingTo(4.10f);
                    me->CastSpell(dreads14, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_RIGHT_15, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_RIGHT_15:
            {
                if (Creature* dreads15 = me->SummonCreature(60942, -849.22f, -2733.77f, 31.70f, 2.50f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreads15);
                    me->AddThreat(dreads15, 9.9999999f);
                    me->AI()->AttackStart(dreads15);
                    me->SetOrientation(2.50f);
                    me->SetFacingTo(2.50f);
                    me->CastSpell(dreads15, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_RIGHT_16, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_RIGHT_16:
            {
                if (Creature* dreads16 = me->SummonCreature(60942, -835.79f, -2723.76f, 31.70f, 1.73f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreads16);
                    me->AddThreat(dreads16, 9.9999999f);
                    me->AI()->AttackStart(dreads16);
                    me->SetOrientation(1.73f);
                    me->SetFacingTo(1.73f);
                    me->CastSpell(dreads16, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                break;
            }
            case EVENT_DREAD_SPRAY_BACK_1:
            {
                if (Creature* dreadz1 = me->SummonCreature(60942, -1078.83f, -2557.93f, 15.87f, 1.73f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreadz1);
                    me->AddThreat(dreadz1, 9.9999999f);
                    me->AI()->AttackStart(dreadz1);
                    me->SetOrientation(1.73f);
                    me->SetFacingTo(1.73f);
                    me->CastSpell(dreadz1, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_BACK_2, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_BACK_2:
            {
                if (Creature* dreadz2 = me->SummonCreature(60942, -1058.56f, -2589.18f, 15.87f, 5.69f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreadz2);
                    me->AddThreat(dreadz2, 9.9999999f);
                    me->AI()->AttackStart(dreadz2);
                    me->SetOrientation(5.69f);
                    me->SetFacingTo(5.69f);
                    me->CastSpell(dreadz2, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_BACK_3, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_BACK_3:
            {
                if (Creature* dreadz3 = me->SummonCreature(60942, -1071.72f, -2598.70f, 15.87f, 4.88f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreadz3);
                    me->AddThreat(dreadz3, 9.9999999f);
                    me->AI()->AttackStart(dreadz3);
                    me->SetOrientation(4.88f);
                    me->SetFacingTo(4.88f);
                    me->CastSpell(dreadz3, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_BACK_4, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_BACK_4:
            {
                if (Creature* dreadz4 = me->SummonCreature(60942, -1087.81f, -2595.07f, 15.87f, 4.11f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreadz4);
                    me->AddThreat(dreadz4, 9.9999999f);
                    me->AI()->AttackStart(dreadz4);
                    me->SetOrientation(4.11f);
                    me->SetFacingTo(4.11f);
                    me->CastSpell(dreadz4, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_BACK_5, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_BACK_5:
            {
                if (Creature* dreadz5 = me->SummonCreature(60942, -1055.42f, -2574.16f, 15.88f, 0.10f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreadz5);
                    me->AddThreat(dreadz5, 9.9999999f);
                    me->AI()->AttackStart(dreadz5);
                    me->SetOrientation(0.10f);
                    me->SetFacingTo(0.10f);
                    me->CastSpell(dreadz5, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_BACK_6, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_BACK_6:
            {
                if (Creature* dreadz6 = me->SummonCreature(60942, -1088.07f, -2595.21f, 15.87f, 4.04f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreadz6);
                    me->AddThreat(dreadz6, 9.9999999f);
                    me->AI()->AttackStart(dreadz6);
                    me->SetOrientation(4.04f);
                    me->SetFacingTo(4.04f);
                    events.ScheduleEvent(EVENT_DREAD_SPRAY_BACK_7, 500);
                    me->CastSpell(dreadz6, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                break;
            }
            case EVENT_DREAD_SPRAY_BACK_7:
            {
                if (Creature* dreadz7 = me->SummonCreature(60942, -1096.06f, -2580.90f, 15.87f, 3.26f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreadz7);
                    me->AddThreat(dreadz7, 9.9999999f);
                    me->AI()->AttackStart(dreadz7);
                    me->SetOrientation(3.26f);
                    me->SetFacingTo(3.26f);
                    me->CastSpell(dreadz7, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_BACK_8, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_BACK_8:
            {
                if (Creature* dreadz8 = me->SummonCreature(60942, -1092.23f, -2565.01f, 15.87f, 2.59f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreadz8);
                    me->AddThreat(dreadz8, 9.9999999f);
                    me->AI()->AttackStart(dreadz8);
                    me->SetOrientation(2.59f);
                    me->SetFacingTo(2.59f);
                    me->CastSpell(dreadz8, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_BACK_9, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_BACK_9:
            {
                if (Creature* dreadz9 = me->SummonCreature(60942, -1071.75f, -2599.01f, 15.87f, 4.86f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreadz9);
                    me->AddThreat(dreadz9, 9.9999999f);
                    me->AI()->AttackStart(dreadz9);
                    me->SetOrientation(4.86f);
                    me->SetFacingTo(4.86f);
                    me->CastSpell(dreadz9, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_BACK_10, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_BACK_10:
            {
                if (Creature* dreadz10 = me->SummonCreature(60942, -1092.18f, -2565.35f, 15.87f, 2.48f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreadz10);
                    me->AddThreat(dreadz10, 9.9999999f);
                    me->AI()->AttackStart(dreadz10);
                    me->SetOrientation(2.48f);
                    me->SetFacingTo(2.48f);
                    me->CastSpell(dreadz10, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_BACK_11, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_BACK_11:
            {
                if (Creature* dreadz11 = me->SummonCreature(60942, -1079.00f, -2556.97f, 15.87f, 1.72f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreadz11);
                    me->AddThreat(dreadz11, 9.9999999f);
                    me->AI()->AttackStart(dreadz11);
                    me->SetOrientation(1.72f);
                    me->SetFacingTo(1.72f);
                    me->CastSpell(dreadz11, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_BACK_12, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_BACK_12:
            {
                if (Creature* dreadz12 = me->SummonCreature(60942, -1062.07f, -2561.13f, 15.87f, 0.99f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreadz12);
                    me->AddThreat(dreadz12, 9.9999999f);
                    me->AI()->AttackStart(dreadz12);
                    me->SetOrientation(0.99f);
                    me->SetFacingTo(0.99f);
                    me->CastSpell(dreadz12, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_BACK_13, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_BACK_13:
            {
                if (Creature* dreadz13 = me->SummonCreature(60942, -1096.55f, -2581.47f, 15.87f, 3.29f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreadz13);
                    me->AddThreat(dreadz13, 9.9999999f);
                    me->AI()->AttackStart(dreadz13);
                    me->SetOrientation(3.29f);
                    me->SetFacingTo(3.29f);
                    me->CastSpell(dreadz13, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_BACK_14, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_BACK_14:
            {
                if (Creature* dreadz14 = me->SummonCreature(60942, -1063.79f, -2561.32f, 15.87f, 0.89f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreadz14);
                    me->AddThreat(dreadz14, 9.9999999f);
                    me->AI()->AttackStart(dreadz14);
                    me->SetOrientation(0.89f);
                    me->SetFacingTo(0.89f);
                    me->CastSpell(dreadz14, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_BACK_15, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_BACK_15:
            {
                if (Creature* dreadz15 = me->SummonCreature(60942, -1054.36f, -2574.63f, 15.87f, 0.21f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreadz15);
                    me->AddThreat(dreadz15, 9.9999999f);
                    me->AI()->AttackStart(dreadz15);
                    me->SetOrientation(0.21f);
                    me->SetFacingTo(0.21f);
                    me->CastSpell(dreadz15, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                events.ScheduleEvent(EVENT_DREAD_SPRAY_BACK_16, 500);
                break;
            }
            case EVENT_DREAD_SPRAY_BACK_16:
            {
                if (Creature* dreadz16 = me->SummonCreature(60942, -1058.87f, -2589.76f, 15.87f, 5.69f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                {
                    me->SetFacingToObject(dreadz16);
                    me->AddThreat(dreadz16, 9.9999999f);
                    me->AI()->AttackStart(dreadz16);
                    me->SetOrientation(5.69f);
                    me->SetFacingTo(5.69f);
                    me->CastSpell(dreadz16, SPELL_DREAD_SPRAY_MISSILE, true);
                }
                break;
            }
            case EVENT_DREAD_SPRAY_END:
                me->SetReactState(REACT_AGGRESSIVE);
                break;
            case EVENT_SHOOT:
                me->CastSpell(me->GetVictim(), SPELL_SHOOT, false);
                events.ScheduleEvent(EVENT_SHOOT, 3000);
                break;
            case EVENT_DEATH_BLOSSOM:
            {
                Talk(SAY_UNK);
                DoCast(me, SPELL_DEATH_BLOSSOM, false);
                events.DelayEvents(8000);
                break;
            }
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    private:
        uint32 lastHealthPct;
    };

public:
    npc_sha_of_fear_bowman() : CreatureScript("npc_sha_of_fear_bowman") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_sha_of_fear_bowmanAI(creature);
    }
};

// Sha Globe - 65691
class npc_sha_globe : public CreatureScript
{
    enum
    {
        SPELL_SHA_GLOBE_VISUAL = 129187,
        SPELL_SHA_GLOBE_PRE_VISUAL = 132214,
        SPELL_SHA_GLOBE_HEAL = 129190,
        SPELL_SHA_GLOBE_DMG = 129189
    };

    struct npc_sha_globeAI : public ScriptedAI
    {
        npc_sha_globeAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            me->AddAura(42716, me); // root
            DoCast(me, SPELL_SHA_GLOBE_VISUAL, true);
            visualTimer = 5000;
            healTimer = 8000;
            me->SetReactState(REACT_PASSIVE);
        }

        void EnterCombat(Unit*) override
        {
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_SHA_GLOBE_DMG)
            {
                visualTimer = 0;
                healTimer = 0;
                me->RemoveAllAuras();
                me->DespawnOrUnsummon(500);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (visualTimer)
            {
                if (visualTimer <= diff)
                {
                    DoCast(me, SPELL_SHA_GLOBE_PRE_VISUAL);
                    visualTimer = 0;
                }
                else visualTimer -= diff;

            }
            else if (healTimer)
            {
                if (healTimer <= diff)
                {
                    DoCast(me, SPELL_SHA_GLOBE_HEAL, true);
                    me->RemoveAllAuras();
                    me->DespawnOrUnsummon(1000);
                    healTimer = 0;
                }
                else healTimer -= diff;
            }
        }

    private:
        uint32 visualTimer;
        uint32 healTimer;
    };

public:
    npc_sha_globe() : CreatureScript("npc_sha_globe") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_sha_globeAI(creature);
    }
};

/*class bfa_spell_toes_sha_globe_regen : public SpellScriptLoader
{
public:
    bfa_spell_toes_sha_globe_regen() : SpellScriptLoader("bfa_spell_toes_sha_globe_regen") {}

    class bfa_spell_toes_impl : public SpellScript
    {
        PrepareSpellScript(bfa_spell_toes_impl);

        void RemoveOldAura()
        {
            if (Unit* victim = GetHitUnit())
                victim->RemoveAurasDueToSpell(129189);
        }

        void Register()
        {
            BeforeHit += SpellHitFn(bfa_spell_toes_impl::RemoveOldAura);
        }

        bool prevented;
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_toes_impl();
    }
};*/

// Death Blossom - 119887
class bfa_spell_toes_death_blossom : public SpellScriptLoader
{
    class bfa_spell_toes_impl : public SpellScript
    {
        PrepareSpellScript(bfa_spell_toes_impl);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (Unit* caster = GetCaster())
                targets.remove_if([&caster](WorldObject* u) { return !u->IsWithinLOSInMap(caster); });
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_toes_impl::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

public:
    bfa_spell_toes_death_blossom() : SpellScriptLoader("bfa_spell_toes_death_blossom") {}

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_toes_impl();
    }
};

// Dread Spray - 120047
class bfa_spell_toes_dread_spray : public SpellScriptLoader
{
public:
    bfa_spell_toes_dread_spray() : SpellScriptLoader("bfa_spell_toes_dread_spray") {}

    class aura_impl : public AuraScript
    {
        PrepareAuraScript(aura_impl);

        void OnTick(AuraEffect const* /*aurEff*/)
        {
            if (Unit* owner = GetUnitOwner())
            {
                float ori = float(rand_norm()) * static_cast<float>(2 * M_PI);
                owner->SetOrientation(ori);
                owner->SetFacingTo(ori);
                //Position pos;
                //owner->GetRandomNearPosition(pos, 15.0f);
                owner->CastSpell(owner, 119958, true);
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(aura_impl::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new aura_impl();
    }
};

class notPlayerPredicate
{
public:
    bool operator()(WorldObject* target) const
    {
        return target && !target->ToPlayer();
    }
};

class bfa_spell_toes_teleport_to_dread_expanse : public SpellScriptLoader
{
public:
    bfa_spell_toes_teleport_to_dread_expanse() : SpellScriptLoader("bfa_spell_toes_dread_expanse_tp") {}

    class bfa_spell_toes_teleport_to_dread_expanse_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_toes_teleport_to_dread_expanse_SpellScript);

        void HandleOnHit()
        {
            if (Unit* pUnit = GetHitUnit())
            {
                pUnit->CastSpell(pUnit, SPELL_TELEPORT_PLAYER, true);

                if (pUnit->IsAlive())
                    pUnit->CastSpell(pUnit, SPELL_FADING_LIGHT);

                pUnit->CastSpell(pUnit, SPELL_DREAD_EXPANSE, true);
            }
        }

        void SelectTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(notPlayerPredicate());
        }

        void Register()
        {
            OnHit += SpellHitFn(bfa_spell_toes_teleport_to_dread_expanse_SpellScript::HandleOnHit);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_toes_teleport_to_dread_expanse_SpellScript::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_toes_teleport_to_dread_expanse_SpellScript();
    }
};

class bfa_spell_toes_implacable_strike : public SpellScriptLoader
{
public:
    bfa_spell_toes_implacable_strike() : SpellScriptLoader("bfa_spell_toes_implacable_strike") {}

    class bfa_spell_toes_impl : public SpellScript
    {
        PrepareSpellScript(bfa_spell_toes_impl);

        void HandleAfterCast()
        {
            if (Unit* caster = GetCaster())
            {
                caster->ClearUnitState(UNIT_STATE_CANNOT_TURN);
                caster->ClearUnitState(UNIT_STATE_ROOT);
            }
        }
    };
};

class bfa_npc_return_to_terrace : public CreatureScript
{
public:
    bfa_npc_return_to_terrace() : CreatureScript("bfa_npc_return_to_terrace") { }

    bool OnGossipHello(Player* player, Creature* me)
    {
        if (!me || !player)
            return false;

        player->AddAura(SPELL_FEARLESS, player);
        player->TeleportTo(996, -1017.94f, -2812.59f, 38.26f, 1.54f);
        return true;
    }
};

class bfa_npc_waterspout : public CreatureScript
{
public:
    bfa_npc_waterspout() : CreatureScript("bfa_npc_waterspout") { }

    struct bfa_npc_waterspoutAI : public ScriptedAI
    {
        bfa_npc_waterspoutAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void IsSummonedBy(Unit* summoner)
        {
            me->CastSpell(me, SPELL_WATERSPOUT_VISUAL, true);
            events.ScheduleEvent(EVENT_CAST_WATERS, 3000, 0, 0);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CAST_WATERS:
                    me->CastSpell(me, SPELL_WATERSPOUT_DAMAGE);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_waterspoutAI(creature);
    }
};

class bfa_npc_dread_spawn : public CreatureScript
{
public:
    bfa_npc_dread_spawn() : CreatureScript("bfa_npc_dread_spawn") { }

    struct bfa_npc_dread_spawnAI : public ScriptedAI
    {
        bfa_npc_dread_spawnAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_NEW_TARGET:
            {
                me->CastSpell(me->GetVictim(), SPELL_SHA_SPINE);
                me->RemoveAura(SPELL_GATHERING_SPEED);
                me->AddAura(SPELL_SEEK_THE_LIGHT, me);
                //sWorld->SendWorldText(3, "NEW TARGET");
                break;
            }
            }
        }

        void EnterCombat(Unit*)
        {
            events.ScheduleEvent(EVENT_GATHERING_SPEED, 10000, 0, 0);
            events.ScheduleEvent(EVENT_FOLLOW_TARGETED_PLAYERS, 1000, 0, 0);
            events.ScheduleEvent(EVENT_KILL_NEAR_PLAYERS, 2500, 0, 0);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_GATHERING_SPEED:
                    me->CastSpell(me, SPELL_GATHERING_SPEED);
                    events.ScheduleEvent(EVENT_GATHERING_SPEED, 10000, 0, 0);
                    break;
                case EVENT_FOLLOW_TARGETED_PLAYERS:
                {
                    Unit* currentTarget = me->GetVictim();
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                            if (player->IsAlive())
                                if (player->HasAura(SPELL_CHAMPION_OF_THE_LIGHT))
                                {
                                    if (player == currentTarget)
                                        break;
                                    me->getThreatManager().clearReferences();
                                    me->SetInCombatWithZone();
                                    me->AddThreat(player, 99999999.0f);
                                    me->AI()->AttackStart(player);
                                    break;
                                }
                    events.ScheduleEvent(EVENT_FOLLOW_TARGETED_PLAYERS, 1000, 0, 0);
                    break;
                }
                case EVENT_KILL_NEAR_PLAYERS:
                {
                    if (Unit* victim = me->GetVictim())
                    {
                        if (victim->IsWithinMeleeRange(me))
                        {
                            me->CastSpell(victim, SPELL_ETERNAL_DARKNESS);
                        }
                    }
                    events.ScheduleEvent(EVENT_KILL_NEAR_PLAYERS, 2500, 0, 0);
                    break;
                }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bfa_npc_dread_spawnAI(creature);
    }
};

class bfa_spell_emerge : public SpellScriptLoader
{
public:
    bfa_spell_emerge() : SpellScriptLoader("bfa_spell_emerge") {}

    class bfa_spell_emerge_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_emerge_SpellScript);

        void HandleAfterCast()
        {
            if (Unit* caster = GetCaster())
            {
                caster->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                caster->RemoveAura(SPELL_SUBMERGE);
                caster->RestoreDisplayId();
                caster->ClearUnitState(UNIT_STATE_ROOT);
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_emerge_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_emerge_SpellScript();
    }
};

// Transfer Light - 120285
class bfa_spell_transfer_light : public SpellScriptLoader
{
public:
    bfa_spell_transfer_light() : SpellScriptLoader("bfa_spell_transfer_light") { }

    class bfa_spell_transfer_light_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_transfer_light_SpellScript);

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();

            std::list<Creature*> creatures;
            caster->GetCreatureListWithEntryInGrid(creatures, NPC_DREAD_SPAWN, 500.0f);
            for (auto it = creatures.begin(); it != creatures.end(); ++it)
            {
                Creature* creatures = *it;
                creatures->AI()->DoAction(ACTION_NEW_TARGET);
            }

            caster->RemoveAura(SPELL_CHAMPION_OF_THE_LIGHT);
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_transfer_light_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_transfer_light_SpellScript();
    }
};

// Ominous Cackle - 129147
class bfa_spell_toes_ominous_cackle_immunities : public SpellScriptLoader
{
public:
    bfa_spell_toes_ominous_cackle_immunities() : SpellScriptLoader("bfa_spell_toes_ominous_cackle_immunities") { }

    class bfa_spell_toes_ominous_cackle_immunities_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_toes_ominous_cackle_immunities_AuraScript);

        void OnApply(AuraEffect const* aurFf, AuraEffectHandleModes mode)
        {
            Player* player = GetTarget()->ToPlayer();

            if (!player)
                return;

            player->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_LEAP, true);
            player->UnsummonPetTemporaryIfAny();
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Player* player = GetTarget()->ToPlayer();

            if (!player)
                return;

            player->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_LEAP, false);
            player->ResummonPetTemporaryUnSummonedIfAny();
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_toes_ominous_cackle_immunities_AuraScript::OnApply, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_toes_ominous_cackle_immunities_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_toes_ominous_cackle_immunities_AuraScript();
    }
};

// Waterspout - 120519
class bfa_spell_toes_waterspout_periodic : public SpellScriptLoader
{
public:
    bfa_spell_toes_waterspout_periodic() : SpellScriptLoader("bfa_spell_toes_waterspout_periodic") { }

    class bfa_spell_toes_waterspout_periodic_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_toes_waterspout_periodic_AuraScript);

        void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();

            caster->SummonCreature(NPC_WATERSPOUT, caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), caster->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 10000);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_toes_waterspout_periodic_AuraScript::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_toes_waterspout_periodic_AuraScript();
    }
};

// Fearless - 118977
class bfa_spell_toes_fearless : public SpellScriptLoader
{
public:
    bfa_spell_toes_fearless() : SpellScriptLoader("bfa_spell_toes_fearless") { }

    class bfa_spell_toes_fearless_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_toes_fearless_AuraScript);

        void OnApply(AuraEffect const* aurFf, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;

            caster->ApplySpellImmune(0, IMMUNITY_ID, 119414, true); // Breath of Fear periodic damage aura
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;

            caster->ApplySpellImmune(0, IMMUNITY_ID, 119414, false); // Breath of Fear periodic damage aura
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_toes_fearless_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_toes_fearless_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_toes_fearless_AuraScript();
    }
};

// Fearless - 136584
class bfa_spell_toes_fearless_pet : public SpellScriptLoader
{
public:
    bfa_spell_toes_fearless_pet() : SpellScriptLoader("bfa_spell_toes_fearless_pet") { }

    class bfa_spell_toes_fearless_pet_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_toes_fearless_pet_AuraScript);

        void OnApply(AuraEffect const* aurFf, AuraEffectHandleModes mode)
        {
            Player* player = GetTarget()->ToPlayer();

            if (!player)
                return;
            player->UnsummonPetTemporaryIfAny();
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Player* player = GetTarget()->ToPlayer();

            if (!player)
                return;
            player->ResummonPetTemporaryUnSummonedIfAny();
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_toes_fearless_pet_AuraScript::OnApply, EFFECT_1, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_toes_fearless_pet_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_toes_fearless_pet_AuraScript();
    }
};

void AddSC_boss_sha_of_fear()
{
    new boss_sha_of_fear();
    new mob_pure_light_terrace();
    new mob_terror_spawn();
    new bfa_spell_toes_champion_of_light();
    new bfa_spell_toes_breath_of_fear();
    new bfa_spell_toes_conjure_terror_spawn();
    //new bfa_spell_toes_penetrating_bolt();
    new bfa_spell_toes_ominous_caclke_target();
    new npc_sha_of_fear_bowman();
    //new bfa_spell_toes_dread_spray_stackable();
    new bfa_spell_toes_dread_spray();
    new npc_sha_globe();
    //new bfa_spell_toes_sha_globe_regen();
    new bfa_spell_toes_breath_of_fear_fear();
    new bfa_spell_toes_death_blossom();
    new bfa_spell_toes_teleport_to_dread_expanse();
    new bfa_npc_return_to_terrace();
    new bfa_npc_waterspout();
    new bfa_npc_dread_spawn();
    new bfa_spell_emerge();
    new bfa_spell_transfer_light();
    new bfa_spell_toes_ominous_cackle_immunities();
    new bfa_spell_toes_waterspout_periodic();
    new bfa_spell_toes_fearless();
    new bfa_spell_toes_fearless_pet();
}
