#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "terrace_of_endless_spring.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Spell.h"
#include "Pet.h"
#include "Group.h"

enum eTsulongEvents
{
    EVENT_NONE,
    EVENT_FLY,
    EVENT_WAYPOINT_FIRST,
    EVENT_WAYPOINT_SECOND,
    EVENT_SWITCH_TO_NIGHT_PHASE,
    EVENT_BERSERK,
    // night phase
    EVENT_SPAWN_SUNBEAM,
    EVENT_SHADOW_BREATH,
    EVENT_DARK_OF_NIGHT,
    EVENT_NIGHTMARES,
    EVENT_DARK_AURA,
    // day phase
    EVENT_SUMMON_TERROR,
    EVENT_SUMMON_SHA,
    EVENT_SUN_BREATH,
    EVENT_EVADE_CHECK,

    EVENT_TSULONG_ENRAGE,
};

enum eTsulongSpells
{
    SPELL_DREAD_SHADOWS = 122767,
    SPELL_DREAD_SHADOWS_DEBUFF = 122768,
    SPELL_SUNBEAM_DUMMY = 122782,
    SPELL_SUNBEAM_PROTECTION = 122789,
    SPELL_NIGHT_PHASE_EFFECT = 122841,
    SPELL_SHADOW_BREATH = 122752,
    SPELL_NIGHTMARES = 122775,
    SPELL_NIGHTMARES_EFF = 122770,
    SPELL_SHA_ACTIVE = 122438, // night phase regen

    // day phase
    SPELL_GOLD_ACTIVE = 122453, // day phase regen and model
    SPELL_SUN_BREATH = 122855,
    SPELL_SUN_BREATH_PLAYER = 122858,
    SPELL_SUMMON_EMBODIED_TERROR = 122995, // 62969
    SPELL_SUMMON_SHA_PERIODIC = 122946,
    SPELL_SUMMON_SHA_PERIODIC_EFF = 122952,
    SPELL_SUMMON_SHA_MISSILE = 122953, // 62919
    SPELL_UNLEASHED_SHA_EXPLOSION = 130008,

    // Heroic mode
    SPELL_THE_DARK_OF_NIGHT = 123739,
    SPELL_DARK_FIXATE_AURA = 123740,
    SPELL_DARK_EXPLOSION = 130013,

    SPELL_LIGHT_OF_DAY_BUFF = 123716,
    SPELL_LIGHT_OF_DAY_AURA = 123816,

    SPELL_TSULONG_ENRAGE = 26662,
    SPELL_TSULONG_ACHIEVEMENT_MARKER = 123901,
};

enum eTsulongTimers
{
    TIMER_FIRST_WAYPOINT = 5000, // 5 secs for test, live : 120 000
};

enum eTsulongPhase
{
    PHASE_NONE,
    PHASE_FLY,
    PHASE_DAY,
    PHASE_NIGHT
};

enum eTsulongWaypoints
{
    WAYPOINT_FIRST = 10001,
    WAYPOINT_SECOND = 10002
};

enum eTsulongDisplay
{
    DISPLAY_TSULON_NIGHT = 42532,
    DISPLAY_TSULON_DAY = 42533,

    FACTION_DAY = 2104,
    FACTION_NIGHT = 1965,
};

enum eTsulongActions
{
    ACTION_SPAWN_SUNBEAM = 10,
    ACTION_REGEN_COMPLETE,
};

enum eTsulongCreatures
{
    SUNBEAM_DUMMY_ENTRY = 62849,
    NPC_THE_DARK_OF_THE_NIGHT = 63346,
};

enum
{
    SPELL_TERRORIZE = 123011,
    SPELL_TERRORIZE_TSULONG = 123012,
    SPELL_TINY_TERROR = 123038,
    SPELL_TINY_TERROR_EFF = 123026,
    SPELL_SUMMON_TINY_TERROR = 123508
};

class boss_tsulong : public CreatureScript
{
    enum Quotes
    {
        EMOTE_SUMMON_TERROR = 1,
        EMOTE_TERRORIZE,
        SAY_INTRO,
        SAY_AGGRO,
        SAY_NIGHTMARES,
        SAY_NIGHT_TO_DAY,
        SAY_DAY_TO_NIGHT,
        SAY_SLAY_DAY,
        SAY_SLAY_NIGHT,
        SAY_DEATH,
        SAY_WIPE,
        EMOTE_SUNBEAM,
    };
public:
    boss_tsulong() : CreatureScript("boss_tsulong") { }

    struct boss_tsulongAI : public BossAI
    {
        boss_tsulongAI(Creature* creature) : BossAI(creature, DATA_TSULONG)
        {
            started = false;
            hasBeenDefeated = false;
            me->SetMaxPower(POWER_ENERGY, 100);
            me->ApplySpellImmune(0, IMMUNITY_ID, 29166, true); // Innervate exploit
        }

        EventMap m_oocEvents;

        uint8 phase;
        bool firstSpecialEnabled;
        bool secondSpecialEnabled;
        bool inFly;
        bool hasBeenDefeated;
        bool started;

        void SpellHitTarget(Unit* target, SpellInfo const* spell) override
        {
            switch (spell->Id)
            {
            case SPELL_NIGHTMARES:
                DoCast(target, SPELL_NIGHTMARES_EFF, true);
                break;
            case SPELL_SUMMON_SHA_PERIODIC_EFF:
                DoCast(target, SPELL_SUMMON_SHA_MISSILE, true);
                break;
            }
        }

        void SpellHit(Unit*, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_TERRORIZE_TSULONG)
                Talk(EMOTE_TERRORIZE);
        }

        void JustSummoned(Creature* pSummoned) override
        {
            summons.Summon(pSummoned);

            if (pSummoned->GetEntry() == NPC_EMBODIED_TERROR)
            {
                if (pSummoned->AI())
                    pSummoned->AI()->DoZoneInCombat();
            }

            if (pSummoned->GetEntry() == NPC_THE_DARK_OF_THE_NIGHT)
                pSummoned->SetInCombatWithZone();
        }

        void Reset() override
        {
            m_oocEvents.RescheduleEvent(1, 2000);

            dayPhaseOri = 0.0f;
            _Reset();
            events.Reset();
            summons.DespawnAll();

            inFly = false;

            me->SetDisableGravity(true);
            me->SetCanFly(true);
            me->RemoveAurasDueToSpell(SPELL_DREAD_SHADOWS);
            me->SetPower(POWER_ENERGY, 0);

            if (hasBeenDefeated)
                return;
            KillFrightSpawns();

            if (instance)
            {
                if (instance->GetData(TYPE_PROTECTORS) == DONE)
                {
                    phase = PHASE_NIGHT;
                    me->SetDisplayId(DISPLAY_TSULON_NIGHT);
                    me->SetFaction(14);
                    me->SetHomePosition(-1017.841f, -3049.621f, 12.823f, 4.72f);
                    me->GetMotionMaster()->MoveTargetedHome();
                }
                else
                {
                    phase = PHASE_DAY;
                    me->SetDisplayId(DISPLAY_TSULON_DAY);
                    me->SetFaction(35);
                }
            }
        }

        void JustReachedHome() override
        {
            _JustReachedHome();

            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            instance->SetBossState(DATA_TSULONG, FAIL);


            summons.DespawnAll();
        }

        void MoveInLineOfSight(Unit* pWho) override
        {
            CreatureAI::MoveInLineOfSight(pWho);
        }

        void EnterCombat(Unit* pWho) override
        {

            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            instance->SetBossState(DATA_TSULONG, IN_PROGRESS);
            DoZoneInCombat();
            Talk(SAY_AGGRO);
            me->SetPower(POWER_ENERGY, 0);
            me->SetHealth(me->GetMaxHealth());
            SetPhase(PHASE_NIGHT);
            me->AddAura(126848, me); // PvE Tier debuff

            events.ScheduleEvent(EVENT_TSULONG_ENRAGE, 8 * MINUTE * IN_MILLISECONDS, 0, 0);
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk((phase == PHASE_DAY) ? SAY_SLAY_DAY : SAY_SLAY_NIGHT);
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (me->IsInEvadeMode())
                damage = 0;
            else
                if (phase == PHASE_DAY)
                {
                    if (me->GetHealth() <= damage)
                    {
                        DoCast(me, SPELL_UNLEASHED_SHA_EXPLOSION, true);
                        damage = 0;
                        summons.DespawnAll();
                    }
                }
                else if (phase == PHASE_NIGHT)
                {
                    if (me->GetHealthPct() < 1.1f || me->GetHealth() <= damage)
                    {
                        damage = 0;
                        HandleDefeat(attacker);
                    }
                }
        }

        void HealReceived(Unit* healer, uint32& heal) override
        {
            if (!started)
                return;
            // victory if healed during the day phase
            if (me->HealthAbovePctHealed(99, heal))
                if (phase == PHASE_DAY)
                {
                    HandleDefeat(healer);
                }
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            KillFrightSpawns();

            _JustDied();
        }

        void DoAction(int32 action)
        {
            if (action == ACTION_START_TSULONG_WAYPOINT)
            {
                started = true;
                SetPhase(PHASE_FLY);

                Talk(SAY_INTRO);
            }

            if (action == ACTION_SPAWN_SUNBEAM)
                events.ScheduleEvent(EVENT_SPAWN_SUNBEAM, 0, 0, PHASE_NIGHT);

            if (action == ACTION_REGEN_COMPLETE)
            {
                me->SetPower(POWER_ENERGY, 0);
                SetPhase((phase == PHASE_DAY) ? PHASE_NIGHT : PHASE_DAY);
            }
        }

        void SetPhase(uint8 newPhase)
        {
            uint8 oldPhase = phase;
            phase = newPhase;
            events.SetPhase(newPhase);
            switch (newPhase)
            {
            case PHASE_FLY:
                me->RemoveAurasDueToSpell(SPELL_GOLD_ACTIVE);
                me->RemoveAurasDueToSpell(SPELL_SHA_ACTIVE);
                events.ScheduleEvent(EVENT_FLY, 5000, 0, PHASE_FLY);
                break;
            case PHASE_DAY:
            {
                me->RemoveAllAuras();
                me->AddAura(126848, me); // PvE Tier debuff
                Unit* victim = me->GetVictim();
                me->SetReactState(REACT_PASSIVE);
                me->SetFaction(FACTION_DAY);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveIdle();
                me->AttackStop();
                me->StopMoving();

                DespawnDarks();
                dayPhaseOri = victim ? me->GetAngle(victim) : 0.0f;
                me->SetFacingTo(dayPhaseOri);
                me->RemoveAurasDueToSpell(SPELL_SHA_ACTIVE);
                me->RemoveAurasDueToSpell(SPELL_DREAD_SHADOWS);

                DoCast(me, SPELL_GOLD_ACTIVE, true);
                DoCast(me, SPELL_SUMMON_SHA_PERIODIC, true);

                if (IsHeroic())
                    DoCast(me, SPELL_LIGHT_OF_DAY_AURA, true);
                events.Reset();
                events.ScheduleEvent(EVENT_SUN_BREATH, 6000, 0, PHASE_DAY);
                events.ScheduleEvent(EVENT_SUMMON_TERROR, 5000, 0, PHASE_DAY);
                events.ScheduleEvent(EVENT_EVADE_CHECK, 2000, 0, PHASE_DAY);

                if (oldPhase == PHASE_NIGHT)
                {
                    Talk(SAY_NIGHT_TO_DAY);
                    me->SetHealth(me->GetMaxHealth() - me->GetHealth());
                }
            }
            break;
            case PHASE_NIGHT:
                me->RemoveAllAuras();
                me->AddAura(126848, me); // PvE Tier debuff
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveAurasDueToSpell(SPELL_GOLD_ACTIVE);
                me->RemoveAurasDueToSpell(SPELL_SUMMON_SHA_PERIODIC);
                DoCast(me, SPELL_SHA_ACTIVE, true);

                me->SetFaction(FACTION_NIGHT);
                events.Reset();
                events.ScheduleEvent(EVENT_SWITCH_TO_NIGHT_PHASE, 0, 0, PHASE_NIGHT);
                events.ScheduleEvent(EVENT_SHADOW_BREATH, 10000, 0, PHASE_NIGHT);
                events.ScheduleEvent(EVENT_NIGHTMARES, urand(15000, 16000), 0, PHASE_NIGHT);
                events.ScheduleEvent(EVENT_SPAWN_SUNBEAM, 2000, 0, PHASE_NIGHT);
                if (IsHeroic())
                {
                    //events.ScheduleEvent(EVENT_DARK_OF_NIGHT, 30000, 0, PHASE_NIGHT);
                    me->RemoveAurasDueToSpell(SPELL_LIGHT_OF_DAY_AURA);
                }

                if (oldPhase == PHASE_DAY)
                {
                    Talk(SAY_DAY_TO_NIGHT);
                    me->SetHealth(me->GetMaxHealth() - me->GetHealth());
                }
                break;
            }

        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            switch (id)
            {
            case WAYPOINT_FIRST:
                events.ScheduleEvent(EVENT_WAYPOINT_FIRST, 0, 0, PHASE_FLY);
                break;
            case WAYPOINT_SECOND:
                events.ScheduleEvent(EVENT_WAYPOINT_SECOND, 0, 0, PHASE_FLY);
                break;
            default:
                break;
            }
        }

        void HandleDefeat(Unit* attacker)
        {
            if (hasBeenDefeated)
                return;

            me->CastSpell(me, SPELL_TSULONG_ACHIEVEMENT_MARKER, true);

            hasBeenDefeated = true;


            Talk(SAY_DEATH);

            me->SetReactState(REACT_PASSIVE);
            me->SetFaction(FACTION_DAY);
            me->RemoveAllAuras();

            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveIdle();

            events.Reset();

            //me->setRegeneratingHealth(false);
            me->SetPower(POWER_ENERGY, 0);
            me->SetMaxPower(POWER_ENERGY, 0);
            me->CombatStop();

            KillFrightSpawns();
            DoCast(me, SPELL_GOLD_ACTIVE, true);
            me->SetDisplayId(DISPLAY_TSULON_DAY);

            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
            me->SetUnitFlags(UNIT_FLAG_PACIFIED);

            instance->SetBossState(DATA_TSULONG, DONE);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

            events.Reset();

            summons.DespawnAll();

            Map::PlayerList const& lPlayers = me->GetMap()->GetPlayers();

            for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
            {
                if (auto const pPlayer = itr->GetSource())
                {
                    pPlayer->CombatStop();
                }
            }
        }

        void HandleEvadeDuringDay()
        {
            if (me->IsInEvadeMode())
                return;

            Map::PlayerList const& lPlayers = me->GetMap()->GetPlayers();

            for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
            {
                if (Player* pPlayer = itr->GetSource())
                {
                    if (pPlayer->IsAlive() && pPlayer->IsWithinDist(me, 40.f))
                        return;
                }
            }

            summons.DespawnAll();

        }

        void EnterEvadeMode(EvadeReason why)
        {
            CreatureAI::EnterEvadeMode();

            me->SetFullHealth();
            me->GetMotionMaster()->Clear();

            if (!hasBeenDefeated)
            {
                instance->SetData(TYPE_TSULONG, FAIL);
                me->GetMotionMaster()->MoveTargetedHome();
                Talk(SAY_WIPE);
            }
        }

        void KillFrightSpawns()
        {
            std::list<Creature*> cList;
            me->GetCreatureListWithEntryInGrid(cList, 62977, 500.0f);
            if (!cList.empty())
                for (std::list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();
        }

        void DespawnDarks()
        {
            std::list<Creature*> cList;
            me->GetCreatureListWithEntryInGrid(cList, NPC_THE_DARK_OF_THE_NIGHT, 500.0f);
            if (!cList.empty())
                for (std::list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!me->IsInEvadeMode() && !me->IsInCombat() && !inFly)
            {
                m_oocEvents.Update(diff);

                while (uint32 eventId = m_oocEvents.ExecuteEvent())
                {
                    if (eventId == 1)
                    {
                        summons.DespawnAll();
                        m_oocEvents.ScheduleEvent(1, 1500);

                    }
                }
            }

            events.Update(diff);

            {
                if (phase == PHASE_FLY)
                {
                    switch (events.ExecuteEvent())
                    {
                    case EVENT_FLY:
                        me->setActive(true);
                        me->UpdateObjectVisibility(true);
                        me->SetFaction(FACTION_NIGHT);
                        me->SetReactState(REACT_PASSIVE);
                        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
                        me->SetDisplayId(DISPLAY_TSULON_NIGHT);
                        me->GetMotionMaster()->MovePoint(WAYPOINT_FIRST, -1018.10f, -2947.431f, 50.12f);
                        inFly = true;
                        break;
                    case EVENT_WAYPOINT_FIRST:
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MovePoint(WAYPOINT_SECOND, -1017.841f, -3049.621f, 12.823f);
                        break;
                    case EVENT_WAYPOINT_SECOND:
                        me->SetHomePosition(-1017.841f, -3049.621f, 12.823f, 4.72f);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                        inFly = false;
                        events.SetPhase(PHASE_NONE);
                        phase = PHASE_NONE;
                        break;
                    default:
                        break;
                    }
                }
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (phase == PHASE_NIGHT)
            {
                if (!UpdateVictim())
                    return;

                switch (events.ExecuteEvent())
                {
                case EVENT_BERSERK:
                    DoCast(me, SPELL_BERSERK, true);
                    break;
                case EVENT_SWITCH_TO_NIGHT_PHASE:
                    //me->SetDisplayId(DISPLAY_TSULON_NIGHT);
                    me->SetFaction(FACTION_NIGHT);
                    me->CastSpell(me, SPELL_DREAD_SHADOWS, true);
                    break;
                case EVENT_SPAWN_SUNBEAM:
                    if (Creature* pSunbeam = GetClosestCreatureWithEntry(me, SUNBEAM_DUMMY_ENTRY, 200.0f))
                        pSunbeam->DisappearAndDie();

                    Talk(EMOTE_SUNBEAM, me);
                    if (Creature* trigger = me->FindNearestCreature(63420, 10000.0f)) // trigger in centeroom
                        trigger->GetRandomNearPosition(15.0f);
                    me->SummonCreature(SUNBEAM_DUMMY_ENTRY, me->GetPosition());
                    events.ScheduleEvent(EVENT_SPAWN_SUNBEAM, 30000, 0, PHASE_NIGHT);
                    if (me->GetMap()->IsHeroic())
                    {
                        events.ScheduleEvent(EVENT_DARK_OF_NIGHT, 10000, 0, PHASE_NIGHT);
                    }
                    break;
                case EVENT_NIGHTMARES:
                    Talk(SAY_NIGHTMARES);
                    DoCast(me, SPELL_NIGHTMARES, true);
                    events.ScheduleEvent(EVENT_NIGHTMARES, 15000, 0, PHASE_NIGHT);
                    break;
                case EVENT_SHADOW_BREATH:
                    DoCastVictim(SPELL_SHADOW_BREATH, false);
                    events.ScheduleEvent(EVENT_SHADOW_BREATH, urand(25000, 30000), 0, PHASE_NIGHT);
                    break;
                case EVENT_DARK_OF_NIGHT:
                {
                    switch (me->GetMap()->GetDifficultyID())
                    {
                    case DIFFICULTY_10_HC:
                        me->SummonCreature(NPC_THE_DARK_OF_THE_NIGHT, -1030.27f, -3087.59f, 12.56f, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                        me->SummonCreature(NPC_THE_DARK_OF_THE_NIGHT, -987.26f, -3075.06f, 12.56f, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                        me->SummonCreature(NPC_THE_DARK_OF_THE_NIGHT, -987.08f, -3023.25f, 12.56f, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                        me->SummonCreature(NPC_THE_DARK_OF_THE_NIGHT, -1036.83f, -3013.99f, 12.56f, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                        me->SummonCreature(NPC_THE_DARK_OF_THE_NIGHT, -1057.35f, -3061.36f, 12.56f, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                        break;
                    case DIFFICULTY_25_HC:
                        me->SummonCreature(NPC_THE_DARK_OF_THE_NIGHT, -1030.27f, -3087.59f, 12.56f, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                        me->SummonCreature(NPC_THE_DARK_OF_THE_NIGHT, -987.26f, -3075.06f, 12.56f, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                        me->SummonCreature(NPC_THE_DARK_OF_THE_NIGHT, -987.08f, -3023.25f, 12.56f, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                        me->SummonCreature(NPC_THE_DARK_OF_THE_NIGHT, -1036.83f, -3013.99f, 12.56f, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                        me->SummonCreature(NPC_THE_DARK_OF_THE_NIGHT, -1057.35f, -3061.36f, 12.56f, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                        me->SummonCreature(NPC_THE_DARK_OF_THE_NIGHT, -1006.19f, -3086.52f, 12.56f, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                        me->SummonCreature(NPC_THE_DARK_OF_THE_NIGHT, -979.41f, -3058.02f, 12.56f, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                        me->SummonCreature(NPC_THE_DARK_OF_THE_NIGHT, -1012.67f, -3010.40f, 12.56f, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                        me->SummonCreature(NPC_THE_DARK_OF_THE_NIGHT, -1054.45f, -3033.09f, 12.56f, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                        me->SummonCreature(NPC_THE_DARK_OF_THE_NIGHT, -1038.71f, -3070.08f, 12.56f, me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
                        break;
                    }
                    break;
                }
                //events.ScheduleEvent(EVENT_DARK_OF_NIGHT, 30000, 0, PHASE_NIGHT);
                case EVENT_TSULONG_ENRAGE:
                    me->AddAura(SPELL_TSULONG_ENRAGE, me);
                    break;
                default:
                    break;
                }

                DoMeleeAttackIfReady();
            }
            else if (phase == PHASE_DAY)
            {
                switch (events.ExecuteEvent())
                {
                case EVENT_SUMMON_TERROR:
                    Talk(EMOTE_SUMMON_TERROR, me);
                    DoCast(me, SPELL_SUMMON_EMBODIED_TERROR, true);
                    events.ScheduleEvent(EVENT_SUMMON_TERROR, 37000, 0, PHASE_DAY);
                    break;
                case EVENT_SUN_BREATH:
                    me->SetFacingTo(dayPhaseOri);
                    me->SetOrientation(dayPhaseOri);
                    KillFrightSpawns();
                    DoCast(me, SPELL_SUN_BREATH, false);
                    events.ScheduleEvent(EVENT_SUN_BREATH, 29000, 0, PHASE_DAY);
                    break;
                case EVENT_SUMMON_SHA:
                    //events.ScheduleEvent(EVENT_SUN_BREATH, 30000, 0, PHASE_DAY);
                    break;
                case EVENT_EVADE_CHECK:
                    HandleEvadeDuringDay();
                    events.ScheduleEvent(EVENT_EVADE_CHECK, 2000, 0, PHASE_DAY);
                    break;
                }
            }

        }
    private:
        float dayPhaseOri;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_tsulongAI(creature);
    }
};

class npc_sunbeam : public CreatureScript
{
public:
    npc_sunbeam() : CreatureScript("npc_sunbeam") { }

    struct npc_sunbeamAI : public CreatureAI
    {
        InstanceScript* pInstance;

        npc_sunbeamAI(Creature* creature) : CreatureAI(creature)
        {
            pInstance = creature->GetInstanceScript();
            creature->SetObjectScale(5.0f);
            creature->SetReactState(REACT_PASSIVE);
            //creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            creature->CastSpell(creature, SPELL_SUNBEAM_DUMMY, true);
        }

        void UpdateAI(uint32 diff)
        {
        }

    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_sunbeamAI(creature);
    }
};

// Embodied Terror - 62969
class npc_embodied_terror : public CreatureScript
{
    struct npc_embodied_terrorAI : public CreatureAI
    {
        npc_embodied_terrorAI(Creature* creature) : CreatureAI(creature) {}

        void Reset() override
        {
            pInstance = me->GetInstanceScript();

            /*if (pInstance)
            {
                if (pInstance->GetData(TYPE_TSULONG) != DONE)
                    terrorizeTimer = urand(3000, 6000);
            }*/

            died = false;
        }

        InstanceScript* pInstance;

        void DamageTaken(Unit*, uint32& damage) override
        {
            if (died)
            {
                damage = 0;
                return;
            }

            if (me->GetHealth() <= damage)
            {
                died = true;
                me->DespawnOrUnsummon(5000);
                DoCast(me, SPELL_TINY_TERROR, true);
            }
        }

        void EnterCombat(Unit*)
        {
            terrorizeTimer = urand(3000, 6000);
        }

        void SpellHit(Unit*, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_TINY_TERROR_EFF)
                for (int i = 0; i < 5; ++i)
                    DoCast(me, SPELL_SUMMON_TINY_TERROR, true);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || !pInstance)
                return;

            if (terrorizeTimer)
            {
                if (terrorizeTimer <= diff)
                {
                    DoCast(me, SPELL_TERRORIZE, true);
                    DoCast(me, SPELL_TERRORIZE_TSULONG, true);
                    terrorizeTimer = 0;
                }
                else
                    if (pInstance->GetData(TYPE_TSULONG) < FAIL)
                        terrorizeTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }

    private:
        uint32 terrorizeTimer;
        bool died;
    };

public:
    npc_embodied_terror() : CreatureScript("npc_embodied_terror") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_embodied_terrorAI(creature);
    }
};

// Terrorize - 123018
class bfa_spell_toes_terrorize_periodic_player : public SpellScriptLoader
{
    class bfa_spell_toes_impl : public SpellScript
    {
        PrepareSpellScript(bfa_spell_toes_impl);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* target = GetHitUnit())
                SetHitDamage(target->CountPctFromCurHealth(GetHitDamage()));
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_toes_impl::HandleDummy, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

public:
    bfa_spell_toes_terrorize_periodic_player() : SpellScriptLoader("bfa_spell_toes_terrorize_periodic_player") {}

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_toes_impl();
    }
};

// Fright Spawn - 62977
class npc_fright_spawn : public CreatureScript
{
    enum
    {
        SPELL_FRIGHT = 123036
    };

    struct npc_fright_spawnAI : public CreatureAI
    {
        npc_fright_spawnAI(Creature* creature) : CreatureAI(creature) {}

        void Reset() override
        {
            frightTimer = urand(3000, 5000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (frightTimer <= diff)
            {
                DoCast(me, SPELL_FRIGHT, false);
                frightTimer = urand(8000, 10000);
            }
            else frightTimer -= diff;

            DoMeleeAttackIfReady();
        }

    private:
        uint32 frightTimer;
    };

public:
    npc_fright_spawn() : CreatureScript("npc_fright_spawn") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_fright_spawnAI(creature);
    }
};

// Unstable Sha - 62962
class npc_unstable_sha : public CreatureScript
{
    enum
    {
        SPELL_INSTABILITY_RIDE = 122928,
        SPELL_INSTABILITY_TRANSFORM = 122930,
        SPELL_INSTABILITY_DAMAGE = 123697,
        SPELL_INSTABILITY_HEAL = 130078,
        SPELL_UNSTABLE_BOLT = 122881
    };

    struct npc_unstable_shaAI : public ScriptedAI
    {
        npc_unstable_shaAI(Creature* creature) : ScriptedAI(creature)
        {
            summonerGUID = 0;
            riding = false;
            cast = false;
        }

        EventMap events;

        void Reset() override
        {
            events.ScheduleEvent(1, urand(2000, 6000));
        }

        void IsSummonedBy(Unit* summoner) override
        {
            //me->GetMotionMaster()->MoveChase(summoner);
            //me->SetReactState(REACT_PASSIVE);
            me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
            DoZoneInCombat();
            SetGazeOn(summoner);
        }

        void UpdateAI(uint32 uiDiff) override
        {
            if (!UpdateVictimWithGaze() || riding)
                return;

            /*if (Unit * summoner = Unit::GetUnit(*me, summonerGUID))
            {
                if (me->IsWithinMeleeRange(summoner))
                {
                    riding = true;
                    //DoCast(summoner, SPELL_INSTABILITY_RIDE);
                    if (Creature* tsulong = me->FindNearestCreature(NPC_TSULONG, 1.0f, true))
                    {
                        tsulong->CastSpell(tsulong, SPELL_INSTABILITY_DAMAGE);
                    }
                }
            }*/

            if (Creature* tsulong = me->FindNearestCreature(NPC_TSULONG, 1.0f, true))
            {
                if (tsulong->HasAura(SPELL_GOLD_ACTIVE))
                {
                    tsulong->CastSpell(tsulong, SPELL_INSTABILITY_DAMAGE);
                    me->DespawnOrUnsummon(1);
                }
                else if (tsulong->HasAura(SPELL_SHA_ACTIVE))
                {
                    tsulong->CastSpell(tsulong, SPELL_INSTABILITY_HEAL);
                    me->DespawnOrUnsummon(1);
                }
            }

            me->SetSpeed(MOVE_RUN, 0.7f);
            me->SetSpeed(MOVE_WALK, 0.7f);

            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    if (Unit* pUnit = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, 0))
                    {
                        DoCast(pUnit, SPELL_UNSTABLE_BOLT);
                        events.ScheduleEvent(1, 4000);
                    }
                    break;
                }
            }
        }

        bool riding;
        bool cast;
        uint64 summonerGUID;
    };

public:
    npc_unstable_sha() : CreatureScript("npc_unstable_sha") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_unstable_shaAI(creature);
    }
};

// 125843, jam spell ?
class bfa_spell_toes_dread_shadows_damage : public SpellScriptLoader
{
public:
    bfa_spell_toes_dread_shadows_damage() : SpellScriptLoader("bfa_spell_toes_dread_shadows_damage") { }

    class bfa_spell_toes_dread_shadows_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_toes_dread_shadows_damage_SpellScript);

        void RemoveInvalidTargets(std::list<WorldObject*>& targets)
        {
            targets.clear();
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_toes_dread_shadows_damage_SpellScript::RemoveInvalidTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_toes_dread_shadows_damage_SpellScript::RemoveInvalidTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_toes_dread_shadows_damage_SpellScript();
    }
};

class DreadShadowsTargetCheck
{
public:
    bool operator()(WorldObject* object) const
    {
        // check Sunbeam protection
        if (object->ToUnit() && object->ToUnit()->HasAura(122789))
            return true;

        return false;
    }
};

// 122768
class bfa_spell_toes_dread_shadows_malus : public SpellScriptLoader
{
public:
    bfa_spell_toes_dread_shadows_malus() : SpellScriptLoader("bfa_spell_toes_dread_shadows_malus") { }

    class bfa_spell_toes_dread_shadows_malus_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_toes_dread_shadows_malus_SpellScript);

        void RemoveInvalidTargets(std::list<WorldObject*>& targets)
        {
            targets.remove(GetCaster());
            targets.remove_if(DreadShadowsTargetCheck());
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_toes_dread_shadows_malus_SpellScript::RemoveInvalidTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_toes_dread_shadows_malus_SpellScript::RemoveInvalidTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_toes_dread_shadows_malus_SpellScript();
    }
};

// 122789
class bfa_spell_toes_sunbeam : public SpellScriptLoader
{
public:
    bfa_spell_toes_sunbeam() : SpellScriptLoader("bfa_spell_toes_sunbeam") { }

    class bfa_spell_toes_sunbeam_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_toes_sunbeam_SpellScript);

        void CheckTargets(std::list<WorldObject*>& targets)
        {
            targets.clear();
            Map::PlayerList const& players = GetCaster()->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            {
                Player* plr = itr->GetSource();
                if (!plr)
                    continue;
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_toes_sunbeam_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_toes_sunbeam_SpellScript();
    }


    class bfa_spell_toes_sunbeam_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_toes_sunbeam_aura_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (GetTarget()->GetTypeId() == TYPEID_PLAYER)
            {
                if (Pet* pet = GetTarget()->ToPlayer()->GetPet())
                    pet->AddAura(SPELL_SUNBEAM_PROTECTION, pet);
            }

            GetTarget()->RemoveAurasDueToSpell(SPELL_DREAD_SHADOWS_DEBUFF);
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (GetTarget()->GetTypeId() == TYPEID_PLAYER)
            {
                if (Pet* pet = GetTarget()->ToPlayer()->GetPet())
                    pet->RemoveAurasDueToSpell(SPELL_SUNBEAM_PROTECTION);
            }
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(bfa_spell_toes_sunbeam_aura_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_toes_sunbeam_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_toes_sunbeam_aura_AuraScript();
    }
};

// Day and Night regen auras - 122438 and 122453
class bfa_spell_toes_tsulong_sha_regen : public SpellScriptLoader
{
public:
    bfa_spell_toes_tsulong_sha_regen() : SpellScriptLoader("bfa_spell_toes_tsulong_sha_regen") {}

    class script_impl : public AuraScript
    {
        PrepareAuraScript(script_impl);

        void HandleEffectPeriodic(AuraEffect const* aurEff)
        {
            Unit* target = GetUnitOwner();
            if (!target)
                return;

            if (target->GetPower(POWER_ENERGY) == 99)
            {
                target->ToCreature()->AI()->DoAction(ACTION_REGEN_COMPLETE);
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(script_impl::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new script_impl();
    }
};

class bfa_spell_toes_tsulong_nightmares : public SpellScriptLoader
{
public:
    bfa_spell_toes_tsulong_nightmares() : SpellScriptLoader("bfa_spell_toes_tsulong_nightmares") {}

    class script_impl : public SpellScript
    {
        PrepareSpellScript(script_impl);

        bool Validate(SpellInfo const* /*spell*/)
        {
            return true;
        }

        void SelectTargets(std::list<WorldObject*>& targets)
        {
            if (Unit* caster = GetCaster())
            {
                // Melee targets should be low priority
                targets.sort(Trinity::ObjectDistanceOrderPred(caster, false));

                uint32 m_maxTargets = (caster->GetMap()->GetDifficultyID() == DIFFICULTY_25_N || caster->GetMap()->GetDifficultyID() == DIFFICULTY_25_HC) ? 3 : 1;

                if (targets.size() > m_maxTargets)
                {
                    targets.resize(m_maxTargets);
                }
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(script_impl::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new script_impl();
    }
};

class bfa_spell_toes_tsulong_terrorize : public SpellScriptLoader
{
public:
    bfa_spell_toes_tsulong_terrorize() : SpellScriptLoader("bfa_spell_toes_tsulong_terrorize") {}

    class bfa_spell_toes_impl : public SpellScript
    {
        PrepareSpellScript(bfa_spell_toes_impl);

        void SelectTargets(std::list<WorldObject*>& targets)
        {
            if (Unit* pCaster = GetCaster())
            {
                uint32 m_maxTargets = (pCaster->GetMap()->GetDifficultyID() == DIFFICULTY_25_N || pCaster->GetMap()->GetDifficultyID() == DIFFICULTY_25_HC) ? 5 : 2;

                if (targets.size() > m_maxTargets)
                {
                    targets.resize(m_maxTargets);
                }
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_toes_impl::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_toes_impl();
    }
};

// Dark of Night - 63346
class npc_dark_of_night : public CreatureScript
{
public:
    npc_dark_of_night() : CreatureScript("npc_dark_of_night") {}

    struct npc_dark_of_nightAI : public ScriptedAI
    {
        npc_dark_of_nightAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetSpeed(MOVE_WALK, 0.7f);
            me->SetSpeed(MOVE_RUN, 0.7f);
        }

        void UpdateAI(uint32 diff)
        {
            me->AddAura(SPELL_DARK_FIXATE_AURA, me);

            if (Creature* beam = me->FindNearestCreature(SUNBEAM_DUMMY_ENTRY, 1000.0f, true))
            {
                me->GetMotionMaster()->MoveFollow(beam, 0.f, 0.f);
            }

            if (Creature* beam = me->FindNearestCreature(SUNBEAM_DUMMY_ENTRY, 1.0f, true))
            {
                DoCast(SPELL_DARK_EXPLOSION);
                me->DespawnOrUnsummon(100);
                beam->DespawnOrUnsummon(100);
            }
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_dark_of_nightAI(pCreature);
    }
};

// The Light of Day - 63337
class bfa_npc_the_light_of_day : public CreatureScript
{
public:
    bfa_npc_the_light_of_day() : CreatureScript("bfa_npc_the_light_of_day") { }

    bool OnGossipHello(Player* player, Creature* me)
    {
        if (!me || !player)
            return false;

        player->AddAura(SPELL_LIGHT_OF_DAY_BUFF, player);
        me->DespawnOrUnsummon();
        return true;
    }
};

// The Light of Day interval - 123816
class bfa_spell_the_light_of_day : public SpellScriptLoader
{
public:
    bfa_spell_the_light_of_day() : SpellScriptLoader("bfa_spell_the_light_of_day") { }

    class bfa_spell_the_light_of_day_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_the_light_of_day_AuraScript);

        std::list<Unit*> targetList;

        void CalcPeriodic(AuraEffect const* /*aurEff*/, bool& isPeriodic, int32& amplitude)
        {
            Unit* caster = GetCaster();

            switch (caster->GetMap()->GetDifficultyID())
            {
            case DIFFICULTY_10_HC:
                amplitude = 25000;
                break;
            case DIFFICULTY_25_HC:
                amplitude = 10000;
                break;
            }
        }

        void Register()
        {
            DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(bfa_spell_the_light_of_day_AuraScript::CalcPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_the_light_of_day_AuraScript();
    }
};

// Unstable Bolt - 122881
class bfa_spell_unstable_bolt_selfdamage : public SpellScriptLoader
{
public:
    bfa_spell_unstable_bolt_selfdamage() : SpellScriptLoader("bfa_spell_unstable_bolt_selfdamage") { }

    class bfa_spell_unstable_bolt_selfdamage_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_unstable_bolt_selfdamage_SpellScript);

        void HandleDamage()
        {
            Unit* caster = GetCaster();

            int32 damage = (GetCaster()->CountPctFromCurHealth(15));
            caster->CastCustomSpell(caster, 122907, &damage, 0, 0, true);
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_unstable_bolt_selfdamage_SpellScript::HandleDamage);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_unstable_bolt_selfdamage_SpellScript();
    }
};

void AddSC_boss_tsulong()
{
    new boss_tsulong();
    new npc_sunbeam();
    new bfa_spell_toes_dread_shadows_damage();
    new bfa_spell_toes_dread_shadows_malus();
    new bfa_spell_toes_sunbeam();
    new bfa_spell_toes_tsulong_sha_regen();
    new bfa_spell_toes_terrorize_periodic_player();
    new bfa_spell_toes_tsulong_terrorize();
    new bfa_spell_toes_tsulong_nightmares();
    new npc_embodied_terror();
    new npc_fright_spawn();
    new npc_unstable_sha();
    new npc_dark_of_night();
    new bfa_npc_the_light_of_day();
    new bfa_spell_the_light_of_day();
    new bfa_spell_unstable_bolt_selfdamage();
}
