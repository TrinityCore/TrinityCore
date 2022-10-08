#include "siege_of_orgrimmar.hpp"

enum ScriptedTextHaromm
{
    SAY_HAROMM_INTRO    = 0,
    SAY_HAROMM_AGGRO    = 1,
    SAY_HAROMM_DEATH    = 2,
    SAY_HAROMM_INTRO_1  = 3,
    SAY_HAROMM_INTRO_2  = 4,
    SAY_HAROMM_KILL     = 5,
    SAY_HAROMM_WATER    = 6,
    SAY_HAROMM_EARTH    = 7,
    SAY_HAROMM_SPELL    = 8,
};

enum ScriptedTextKardris
{
    SAY_KARDRIS_INTRO   = 0,
    SAY_KARDRIS_AGGRO   = 1,
    SAY_KARDRIS_DEATH   = 2,
    SAY_KARDRIS_INTRO_1 = 3,
    SAY_KARDRIS_KILL    = 4,
    SAY_KARDRIS_WIND    = 5,
    SAY_KARDRIS_FIRE    = 6,
    SAY_KARDRIS_SPELL   = 7,
};

enum Spells
{
    // Shamans shared
    SPELL_SPIRIT_LINK_HAROMM    = 144227,
    SPELL_SPIRIT_LINK_KARDRIS   = 144226,
    SPELL_BLOODLUST             = 144302,

    SPELL_POISONMIST_TOTEM      = 144288,
    SPELL_FOULSTREAM_TOTEM      = 144289,
    SPELL_ASHFLARE_TOTEM        = 144290,
    SPELL_RUSTEDIRON_TOTEM      = 144291,

    SPELL_BERSERK               = 26662,

    // Darkfang & Bloodclaw
    SPELL_SWIPE                 = 144303,
    SPELL_REND                  = 144304,

    // Earthbreaker Haromm
    SPELL_FROSTSTORM_STRIKE     = 144215,

    SPELL_TOXIC_MIST            = 144089,
    SPELL_TOXICITY              = 144107,

    SPELL_FOUL_STREAM           = 144090,

    SPELL_ASHEN_WALL            = 144070,
    SPELL_ASHEN_WALL_SUMMON     = 144071,
    SPELL_ASH_ELEMENTAL_SPAWN   = 144222,

    SPELL_IRON_TOMB_AOE         = 144328,
    SPELL_IRON_TOMB_SUMMON      = 144329,
    SPELL_IRON_TOMB_DMG         = 144334,

    // Wavebinder Kardris
    SPELL_FROSTSTORM_BOLT       = 144214,

    SPELL_TOXIC_STORM_SUMMON    = 144005,
    SPELL_TOXIC_STORM_AURA      = 144006,
    SPELL_TOXIC_STORM_DMG       = 144017,
    SPELL_TOXIC_STORM_TORNADO   = 144019, // summons toxic tornado
    SPELL_TOXIC_TORNADO_AURA    = 144029,
    SPELL_TOXIC_TORNADO_DMG     = 144030,

    SPELL_FOUL_GEYSER           = 143990,
    SPELL_FOUL_GEYSER_MISSILE   = 143992,
    SPELL_FOUL_GEYSER_DMG       = 143993,

    SPELL_FOULNESS              = 144064,
    SPELL_FOULNESS_DMG          = 144066,

    SPELL_FALLING_ASH_SUMMON    = 143973,
    SPELL_FALLING_ASH_COSMETIC  = 143986,
    SPELL_FALLING_ASH_DMG       = 143987,

    SPELL_IRON_PRISON_AOE       = 144330,
    SPELL_IRON_PRISON_DMG       = 144331,
};

enum Adds
{
    NPC_DARKFANG            = 71921,
    NPC_BLOODCLAW           = 71923,

    NPC_ASH_ELEMENTAL       = 71827,
    NPC_IRON_TOMB           = 71941,

    NPC_TOXIC_STORM         = 71801,
    NPC_TOXIC_TORNADO       = 71817,
    NPC_FOUL_SLIME          = 71825,
    NPC_FALLING_ASH         = 71789,

    NPC_POISONMIST_TOTEM    = 71915,
    NPC_FOULSTREAM_TOTEM    = 71916,
    NPC_ASHFLARE_TOTEM      = 71917,
    NPC_RUSTEDIRON_TOTEM    = 71918,
};

enum Gos
{
    GO_IRON_TOMB    = 220864,
};

enum Events
{
    // Darkfang & BloodClaw
    EVENT_SWIPE = 1,
    EVENT_REND,

    // Haromm
    EVENT_FROSTSTORM_STRIKE,
    EVENT_TOXIC_MIST,
    EVENT_FOUL_STREAM,
    EVENT_ASHEN_WALL,
    EVENT_IRON_TOMB,

    // Kardris
    EVENT_FROSTSTORM_BOLT,
    EVENT_TOXIC_STORM,
    EVENT_FOUL_GEYSER,
    EVENT_FALLING_ASH,
    EVENT_IRON_PRISON,
};

enum Actions
{

};

enum DisplayIds
{
    DISPLAY_KARDRIS_SCEPTER         = 103936,
    DISPLAY_HAROMMS_FROZEN_CRESCENT = 103926,
};

#define FALLING_ASH_OFFSET 30.0f
#define FALLING_ASH_SPEED 0.3f

#define TIMER_SWIPE_FIRST urand(5000, 10000)
#define TIMER_REND_FIRST urand(5000, 10000)
#define TIMER_SWIPE urand(15000, 20000)
#define TIMER_REND urand(15000, 20000)

#define EVADE_DISTANCE 115.f

enum Timers
{
    TIMER_SYNC_HEALTH               = 1 * IN_MILLISECONDS,
    TIMER_TOTEM_CHECK               = 1 * IN_MILLISECONDS,
    TIMER_BLOODLUST_CHECK           = 1 * IN_MILLISECONDS,
    TIMER_EVADE_CHECK               = 5 * IN_MILLISECONDS,
    TIMER_BERSERK                   = 9 * MINUTE * IN_MILLISECONDS,

    TIMER_FROSTSTORM_STRIKE_FIRST   = 10 * IN_MILLISECONDS,
    TIMER_FROSTSTORM_STRIKE         = 9 * IN_MILLISECONDS,
    TIMER_TOXIC_MIST_FIRST          = 10 * IN_MILLISECONDS,
    TIMER_TOXIC_MIST                = 32 * IN_MILLISECONDS,
    TIMER_FOUL_STREAM_FIRST         = 10 * IN_MILLISECONDS,
    TIMER_FOUL_STREAM               = 32500,
    TIMER_ASHEN_WALL_FIRST          = 10 * IN_MILLISECONDS,
    TIMER_ASHEN_WALL                = 32500,
    TIMER_IRON_TOMB                 = 31500,

    // Kardris
    TIMER_FROSTSTORM_BOLT_FIRST     = 7 * IN_MILLISECONDS,
    TIMER_FROSTSTORM_BOLT           = 10 * IN_MILLISECONDS,
    TIMER_TOXIC_STORM_FIRST         = 10 * IN_MILLISECONDS,
    TIMER_TOXIC_STORM               = 32 * IN_MILLISECONDS,
    TIMER_FOUL_GEYSER_FIRST         = 10 * IN_MILLISECONDS,
    TIMER_FOUL_GEYSER               = 32500,
    TIMER_FALLING_ASH_FIRST         = 10 * IN_MILLISECONDS,
    TIMER_FALLING_ASH               = 32500,
    TIMER_IRON_PRISON               = 31500,

    TIMER_TOXIC_TORNADO             = 10000,

    TIMER_FOUL_SLIME_MOVE           = 2000, // slimes wait for 2 seconds before moving
};

enum MovementPoints : int
{
    POINT_FALLING_ASH   = 1,
};

enum TotemTypes : int
{
    POISONMIST_TOTEM    = 0,
    FOULSTREAM_TOTEM    = 1,
    ASHFLARE_TOTEM      = 2,
    RUSTEDIRON_TOTEM    = 3,

    MAX_TOTEM_TYPES,
};

enum Items
{
    ITEM_KORKRON_SHAMANS_TREASURE   = 105751,
};

const Position newHomePositions[2] =
{
    { 1602.82f, -4381.28f, 20.71f, 3.68f},  // Haromm
    { 1600.19f, -4376.89f, 20.95f, 3.68f}   // Kardris
};

class TalkHelper
{
    public:

        TalkHelper(Creature* owner) : m_Owner(owner)
        {

        }

        void AddTalk(uint32 id, uint32 timer)
        {
            m_Talks[id] = timer;
        }

        bool IsEmpty() const
        {
            return m_Talks.empty();
        }

        void Clear()
        {
            m_Talks.clear();
        }

        void Update(const uint32 diff)
        {
            if (m_Talks.empty())
                return;

            for (std::map<uint32 /*id*/, uint32 /*timer*/>::iterator itr = m_Talks.begin(); itr != m_Talks.end();)
            {
                if (itr->second <= diff)
                {
                    m_Owner->AI()->Talk(itr->first);

                    itr = m_Talks.erase(itr);
                }
                else
                {
                    itr->second -= diff;
                    ++itr;
                }
            }
        }

    private:

        Creature* m_Owner;
        std::map<uint32 /*id*/, uint32 /*timer*/> m_Talks;
};

struct korkron_dark_shaman_AI : public BossAI
{
    korkron_dark_shaman_AI(Creature* creature) : BossAI(creature, DATA_KORKRON_DARK_SHAMANS),
        mountGuid(ObjectGuid::Empty), isFirstReset(true), m_TalkHelper(creature),
        syncHealthTimer(TIMER_SYNC_HEALTH), totemCheckTimer(TIMER_TOTEM_CHECK),
        bloodlustCheckTimer(TIMER_BLOODLUST_CHECK), checkEvadeTimer(TIMER_EVADE_CHECK)
    {
        //ApplyAllImmunities(true);

        me->setActive(true);

        //me->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 8.0f);
        //me->SetFloatValue(UNIT_FIELD_COMBATREACH, 8.0f);
    }

    void Reset()
    {
        _Reset();

        DespawnCreatures();

        me->SetReactState(REACT_DEFENSIVE);
        me->LowerPlayerDamageReq(me->GetMaxHealth());

        if (isFirstReset)
        {
            isFirstReset = false;
            SummonMount();
        }

        FillIntro();

        syncHealthTimer = TIMER_SYNC_HEALTH;
        totemCheckTimer = TIMER_TOTEM_CHECK;
        bloodlustCheckTimer = TIMER_BLOODLUST_CHECK;
        memset(spawnedTotems, 0, sizeof(spawnedTotems));
        bloodlustDone = false;
        m_BerserkTimer = TIMER_BERSERK;
        m_IsBerserkDone = false;
    }

    void EnterCombat(Unit* who) override
    {
        ChangeHomePositions();

        MakeAggro();

        me->ExitVehicle();

        DoZoneInCombat();
        instance->SetBossState(DATA_KORKRON_DARK_SHAMANS, IN_PROGRESS);
    }

    void JustReachedHome() override
    {
        SummonMount();
    }

    void JustDied(Unit* killer)
    {
        _JustDied();

        /*if (IsHaromm())
        {
            SendAdditionalLoot();
        }*/

        DespawnCreatures();
    }

    void UpdateAI(const uint32 diff) override
    {
        if (!m_TalkHelper.IsEmpty())
            m_TalkHelper.Update(diff);

        SyncHealth(diff);

        CheckSpawnTotem(diff);

        CheckBloodlust(diff);

        UpdateBerserk(diff);
    }

protected:

    bool IsHaromm() const
    {
        return me->GetEntry() == NPC_EARTHBREAKER_HAROMM;
    }

    bool IsKardris() const
    {
        return me->GetEntry() == NPC_WAVEBINDER_KARDIS;
    }

    Creature* GetKardris()
    {
        return instance->instance->GetCreature(instance->GetObjectGuid(DATA_WAVEBINDER_KARDRIS));
    }

    Creature* GetHaromm()
    {
        return instance->instance->GetCreature(instance->GetObjectGuid(DATA_EARTHBREAKER_HAROMM));
    }

    Creature* GetMount()
    {
        return instance->instance->GetCreature(mountGuid);
    }

    Creature* GetOtherShaman()
    {
        return IsHaromm() ? GetKardris() : GetHaromm();
    }

    virtual void SpawnTotem(TotemTypes totemType) { }

    virtual void DoBloodlust() { }

    //todo check what Toast is
    /*void SendAdditionalLoot()
    {
        me->GetMap()->ForEachPlayer([&](Player* player) -> void
        {
            if (player && player->getClass() == CLASS_SHAMAN && roll_chance_f(18.f))
            {
                player->AddItem(ITEM_KORKRON_SHAMANS_TREASURE, 1);
                player->SendDisplayToast(ITEM_KORKRON_SHAMANS_TREASURE, 1, TOAST_TYPE_NEW_ITEM, false, false);
            }
        });
    }*/

    bool CheckEvade(const uint32 diff)
    {
        if (checkEvadeTimer <= diff)
        {
            checkEvadeTimer = TIMER_EVADE_CHECK;

            if (me->GetExactDist(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(), me->GetHomePosition().GetPositionZ()) >= EVADE_DISTANCE)
            {
                EnterEvadeMode();
                if (Creature* other = GetOtherShaman())
                    other->AI()->EnterEvadeMode();

                return true;
            }
        }
        else
        {
            checkEvadeTimer -= diff;
        }

        return false;
    }

protected:

    ObjectGuid mountGuid;
    bool isFirstReset;
    TalkHelper m_TalkHelper;

private:

    void DespawnCreatures()
    {
        me->DespawnCreaturesInArea(NPC_TOXIC_TORNADO, 200);
        me->DespawnCreaturesInArea(GO_IRON_TOMB, 200);
    }

    void FillIntro()
    {
        m_TalkHelper.Clear();

        if (IsHaromm())
        {
            m_TalkHelper.AddTalk(SAY_HAROMM_INTRO_1, 1000);
            m_TalkHelper.AddTalk(SAY_HAROMM_INTRO_2, 5000);
            m_TalkHelper.AddTalk(SAY_HAROMM_INTRO, 9000);
            m_TalkHelper.AddTalk(SAY_HAROMM_AGGRO, 18000);
        }
        else if (IsKardris())
        {
            m_TalkHelper.AddTalk(SAY_KARDRIS_INTRO_1, 3000);
            m_TalkHelper.AddTalk(SAY_KARDRIS_INTRO, 9000);
            m_TalkHelper.AddTalk(SAY_KARDRIS_AGGRO, 13000);
        }
    }

    void SummonMount()
    {
        uint32 mountEntry = 0;

        if (IsHaromm())
        {
            mountEntry = NPC_DARKFANG;
        }
        else if (IsKardris())
        {
            mountEntry = NPC_BLOODCLAW;
        }

        if (mountEntry)
        {
            if (Creature* pCreature = me->SummonCreature(mountEntry, *me))
            {
                me->EnterVehicle(pCreature);
                mountGuid = pCreature->GetGUID();

                // make creature attackable
                //todo check this
                //me->ClearUnitState(UNIT_STATE_ONVEHICLE);
            }
        }
    }

    void MakeAggro()
    {
        ///< 0.0f  = max visibility distance, prevent some exploits
        const float aggroDistance = 0.0f;

        if (Creature* pMount = GetMount())
        {
            if (!pMount->IsInCombat())
                DoZoneInCombat(pMount, aggroDistance);
        }

        if (IsHaromm())
        {
            if (Creature* pKardris = GetKardris())
            {
                if (!pKardris->IsInCombat())
                    DoZoneInCombat(pKardris, aggroDistance);
            }
        }
        else if (IsKardris())
        {
            if (Creature* pHaromm = GetHaromm())
            {
                if (!pHaromm->IsInCombat())
                    DoZoneInCombat(pHaromm, aggroDistance);
            }
        }
    }

    void ChangeHomePositions()
    {
        if (IsHaromm())
        {
            me->SetHomePosition(newHomePositions[0]);
        }
        else if (IsKardris())
        {
            me->SetHomePosition(newHomePositions[1]);
        }
    }

    void SyncHealth(const uint32 diff)
    {
        if (!me->IsAlive())
            return;

        if (syncHealthTimer <= diff)
        {
            syncHealthTimer = TIMER_SYNC_HEALTH;

            Creature* pOtherShaman = nullptr;

            if (IsHaromm())
            {
                pOtherShaman = GetKardris();
            }
            else if (IsKardris())
            {
                pOtherShaman = GetHaromm();
            }

            if (pOtherShaman && pOtherShaman->IsAlive())
            {
                uint32 otherHealth = pOtherShaman->GetHealth();
                if (me->GetHealth() > otherHealth)
                    me->SetHealth(otherHealth);
                //me->SetHealth(std::min(me->GetHealth(), otherHealth));
            }
        }
        else
        {
            syncHealthTimer -= diff;
        }
    }

    void CheckSpawnTotem(const uint32 diff)
    {
        if (totemCheckTimer <= diff)
        {
            totemCheckTimer = TIMER_TOTEM_CHECK;

            if (spawnedTotems[POISONMIST_TOTEM] == false && me->GetHealthPct() <= 85.0f)
            {
                spawnedTotems[POISONMIST_TOTEM] = true;
                SpawnTotem(POISONMIST_TOTEM);
                return;
            }

            if (spawnedTotems[FOULSTREAM_TOTEM] == false && me->GetHealthPct() <= 65.0f)
            {
                spawnedTotems[FOULSTREAM_TOTEM] = true;
                SpawnTotem(FOULSTREAM_TOTEM);
                return;
            }

            if (spawnedTotems[ASHFLARE_TOTEM] == false && me->GetHealthPct() <= 50.0f)
            {
                spawnedTotems[ASHFLARE_TOTEM] = true;
                SpawnTotem(ASHFLARE_TOTEM);
                return;
            }

            if (IsHeroic())
            {
                if (spawnedTotems[RUSTEDIRON_TOTEM] == false && me->GetHealthPct() <= 95.0f)
                {
                    spawnedTotems[RUSTEDIRON_TOTEM] = true;
                    SpawnTotem(RUSTEDIRON_TOTEM);
                    return;
                }
            }
        }
        else
        {
            totemCheckTimer -= diff;
        }
    }

    void CheckBloodlust(const uint32 diff)
    {
        if (bloodlustDone)
            return;

        if (bloodlustCheckTimer <= diff)
        {
            bloodlustCheckTimer = TIMER_BLOODLUST_CHECK;

            if (!bloodlustDone && me->GetHealthPct() <= 25.0f)
            {
                bloodlustDone = true;

                DoBloodlust();
            }
        }
        else
        {
            bloodlustCheckTimer -= diff;
        }
    }

    void UpdateBerserk(const uint32 diff)
    {
        if (m_IsBerserkDone)
            return;

        if (m_BerserkTimer <= diff)
        {
            m_BerserkTimer = TIMER_BERSERK;
            m_IsBerserkDone = true;

            me->AddAura(SPELL_BERSERK, me);
        }
        else
        {
            m_BerserkTimer -= diff;
        }
    }

private:

    uint32 syncHealthTimer;
    uint32 totemCheckTimer;
    uint32 bloodlustCheckTimer;
    uint32 checkEvadeTimer;
    bool spawnedTotems[MAX_TOTEM_TYPES];
    bool bloodlustDone;
    uint32 m_BerserkTimer;
    bool m_IsBerserkDone;
};

class boss_earthbreaker_haromm : public CreatureScript
{
    public:

        boss_earthbreaker_haromm() : CreatureScript("boss_earthbreaker_haromm") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_earthbreaker_harommAI(creature);
        }

        struct boss_earthbreaker_harommAI : public korkron_dark_shaman_AI
        {
            boss_earthbreaker_harommAI(Creature* creature) : korkron_dark_shaman_AI(creature)
            {

            }

            void Reset()
            {
                korkron_dark_shaman_AI::Reset();

                me->AddAura(SPELL_SPIRIT_LINK_HAROMM, me);

                SetEquipmentSlots(false, DISPLAY_HAROMMS_FROZEN_CRESCENT, DISPLAY_HAROMMS_FROZEN_CRESCENT);
            }

            void EnterCombat(Unit* who)
            {
                korkron_dark_shaman_AI::EnterCombat(who);

                events.ScheduleEvent(EVENT_FROSTSTORM_STRIKE, TIMER_FROSTSTORM_STRIKE_FIRST);
            }

            void JustDied(Unit* who)
            {
                Talk(SAY_HAROMM_DEATH);

                korkron_dark_shaman_AI::JustDied(who);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                korkron_dark_shaman_AI::UpdateAI(diff);

                if (CheckEvade(diff))
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

            void ExecuteEvent(const uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_FROSTSTORM_STRIKE:
                        DoCastVictim(SPELL_FROSTSTORM_STRIKE);
                        events.ScheduleEvent(EVENT_FROSTSTORM_STRIKE, TIMER_FROSTSTORM_STRIKE);
                        break;
                    case EVENT_TOXIC_MIST:
                        me->CastCustomSpell(SPELL_TOXIC_MIST, SPELLVALUE_MAX_TARGETS, Is25ManRaid() ? 5 : 2, me, false);
                        events.ScheduleEvent(EVENT_TOXIC_MIST, TIMER_TOXIC_MIST);
                        break;
                    case EVENT_FOUL_STREAM:
                    {
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, -20.0f, 0.0f, true, -SPELL_TOXIC_MIST);
                        if (!target)
                            target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_TOXIC_MIST);
                        if (!target)
                            target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);

                        if (target)
                            DoCast(target, SPELL_FOUL_STREAM);

                        events.ScheduleEvent(EVENT_FOUL_STREAM, TIMER_FOUL_STREAM);
                        break;
                    }
                    case EVENT_ASHEN_WALL:
                        DoCastVictim(SPELL_ASHEN_WALL);
                        events.ScheduleEvent(EVENT_ASHEN_WALL, TIMER_ASHEN_WALL);
                        break;
                    case EVENT_IRON_TOMB:
                        DoIronTomb();
                        events.ScheduleEvent(EVENT_IRON_TOMB, TIMER_IRON_TOMB);
                        break;
                }
            }

        protected:

            void DoIronTomb()
            {
                DoCastAOE(SPELL_IRON_TOMB_AOE);
            }

            virtual void SpawnTotem(TotemTypes totemType) override
            {
                if (totemType == POISONMIST_TOTEM)
                {
                    DoCast(SPELL_POISONMIST_TOTEM);
                    events.ScheduleEvent(EVENT_TOXIC_MIST, TIMER_TOXIC_MIST_FIRST);
                }
                else if (totemType == FOULSTREAM_TOTEM)
                {
                    Talk(SAY_HAROMM_WATER);
                    DoCast(SPELL_FOULSTREAM_TOTEM);
                    events.ScheduleEvent(EVENT_FOUL_STREAM, TIMER_FOUL_STREAM_FIRST);
                }
                else if (totemType == ASHFLARE_TOTEM)
                {
                    DoCast(SPELL_ASHFLARE_TOTEM);
                    events.ScheduleEvent(EVENT_ASHEN_WALL, TIMER_ASHEN_WALL_FIRST);
                }
                else if (totemType == RUSTEDIRON_TOTEM)
                {
                    Talk(SAY_HAROMM_EARTH);
                    DoCast(SPELL_RUSTEDIRON_TOTEM);
                    events.ScheduleEvent(EVENT_IRON_TOMB, TIMER_IRON_TOMB);
                }
            }

            virtual void DoBloodlust() override
            {
                Talk(SAY_HAROMM_SPELL);
                DoCast(SPELL_BLOODLUST);
            }

        private:

        };
};

class boss_wavebinder_kardris : public CreatureScript
{
    public:

        boss_wavebinder_kardris() : CreatureScript("boss_wavebinder_kardris") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_wavebinder_kardrisAI(creature);
        }

        struct boss_wavebinder_kardrisAI : public korkron_dark_shaman_AI
        {
            boss_wavebinder_kardrisAI(Creature* creature) : korkron_dark_shaman_AI(creature)
            {
            }

            void Reset()
            {
                korkron_dark_shaman_AI::Reset();

                me->AddAura(SPELL_SPIRIT_LINK_KARDRIS, me);

                SetEquipmentSlots(false, DISPLAY_KARDRIS_SCEPTER, DISPLAY_KARDRIS_SCEPTER);
            }

            void EnterCombat(Unit* who)
            {
                korkron_dark_shaman_AI::EnterCombat(who);

                events.ScheduleEvent(EVENT_FROSTSTORM_BOLT, TIMER_FROSTSTORM_BOLT_FIRST);
            }

            void JustDied(Unit* who)
            {
                Talk(SAY_KARDRIS_DEATH);

                korkron_dark_shaman_AI::JustDied(who);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                korkron_dark_shaman_AI::UpdateAI(diff);

                if (CheckEvade(diff))
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    ExecuteEvent(eventId);
                }

                DoMeleeAttackIfReady();
            }

            void ExecuteEvent(const uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_FROSTSTORM_BOLT:
                        DoCastVictim(SPELL_FROSTSTORM_BOLT);
                        events.ScheduleEvent(EVENT_FROSTSTORM_BOLT, TIMER_FROSTSTORM_BOLT);
                        break;
                    case EVENT_TOXIC_STORM:
                    {
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, -20.0f, true);
                        if (!target)
                            target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);

                        if (target)
                            DoCast(target, SPELL_TOXIC_STORM_SUMMON);

                        events.ScheduleEvent(EVENT_TOXIC_STORM, TIMER_TOXIC_STORM);
                        break;
                    }
                    case EVENT_FOUL_GEYSER:
                        DoCastVictim(SPELL_FOUL_GEYSER);
                        events.ScheduleEvent(EVENT_FOUL_GEYSER, TIMER_FOUL_GEYSER);
                        break;
                    case EVENT_FALLING_ASH:
                    {
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, -20.0f, true);
                        if (!target)
                            target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);

                        if (target)
                            DoCast(target, SPELL_FALLING_ASH_SUMMON);

                        events.ScheduleEvent(EVENT_FALLING_ASH, TIMER_FALLING_ASH);
                        break;
                    }
                    case EVENT_IRON_PRISON:
                        DoIronPrison();
                        events.ScheduleEvent(EVENT_IRON_PRISON, TIMER_IRON_PRISON);
                        break;
                }
            }

        protected:

            void DoIronPrison()
            {
                DoCastAOE(SPELL_IRON_PRISON_AOE);
            }

            virtual void SpawnTotem(TotemTypes totemType) override
            {
                if (totemType == POISONMIST_TOTEM)
                {
                    Talk(SAY_KARDRIS_WIND);
                    DoCast(SPELL_POISONMIST_TOTEM);
                    events.ScheduleEvent(EVENT_TOXIC_STORM, TIMER_TOXIC_STORM_FIRST);
                }
                else if (totemType == FOULSTREAM_TOTEM)
                {
                    DoCast(SPELL_FOULSTREAM_TOTEM);
                    events.ScheduleEvent(EVENT_FOUL_GEYSER, TIMER_FOUL_GEYSER_FIRST);
                }
                else if (totemType == ASHFLARE_TOTEM)
                {
                    Talk(SAY_KARDRIS_FIRE);
                    DoCast(SPELL_ASHFLARE_TOTEM);
                    events.ScheduleEvent(EVENT_FALLING_ASH, TIMER_FALLING_ASH_FIRST);
                }
                else if (totemType == RUSTEDIRON_TOTEM)
                {
                    DoCast(SPELL_RUSTEDIRON_TOTEM);
                    events.ScheduleEvent(EVENT_IRON_PRISON, TIMER_IRON_PRISON);
                }
            }

            virtual void DoBloodlust() override
            {
                Talk(SAY_KARDRIS_SPELL);
            }
        };
};

class npc_korkron_dark_shaman_wolf : public CreatureScript
{
    public:
        npc_korkron_dark_shaman_wolf() : CreatureScript("npc_korkron_dark_shaman_wolf") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_korkron_dark_shaman_wolfAI(creature);
        }

        struct npc_korkron_dark_shaman_wolfAI : public ScriptedAI
        {
            npc_korkron_dark_shaman_wolfAI(Creature* creature) : ScriptedAI(creature)
            {
                //ApplyAllImmunities(true);

                me->setActive(true);
            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();

                me->SetReactState(REACT_DEFENSIVE);
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_SWIPE, TIMER_SWIPE_FIRST);
                events.ScheduleEvent(EVENT_REND, TIMER_REND_FIRST);

                if (InstanceScript* pInstance = me->GetInstanceScript())
                {
                    if (Creature* pHaromm = pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_EARTHBREAKER_HAROMM)))
                    {
                        if (!pHaromm->IsInCombat())
                            DoZoneInCombat(pHaromm);
                    }
                }
            }

            void JustDied(Unit* who)
            {
                events.Reset();
                summons.DespawnAll();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SWIPE:
                            DoCastVictim(SPELL_SWIPE);
                            events.ScheduleEvent(EVENT_SWIPE, TIMER_SWIPE);
                            break;
                        case EVENT_REND:
                            DoCastVictim(SPELL_REND);
                            events.ScheduleEvent(EVENT_REND, TIMER_REND);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class npc_korkron_dark_shaman_ash_elemental : public CreatureScript
{
    public:
        npc_korkron_dark_shaman_ash_elemental() : CreatureScript("npc_korkron_dark_shaman_ash_elemental") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_korkron_dark_shaman_ash_elementalAI(creature);
        }

        struct npc_korkron_dark_shaman_ash_elementalAI : public Scripted_NoMovementAI
        {
            npc_korkron_dark_shaman_ash_elementalAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                //ApplyAllImmunities(true);

                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);

                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));
                me->AddAura(SPELL_ASH_ELEMENTAL_SPAWN, me);

                checkTargetTimer = 1000;
                m_LastTarget = NULL;
            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();
            }

            void JustDied(Unit* who)
            {
                events.Reset();
                summons.DespawnAll();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                AttackNearbyPlayer(diff);

                DoMeleeAttackIfReady();
            }

        private:

            void AttackNearbyPlayer(const uint32 diff)
            {
                if (checkTargetTimer <= diff)
                {
                    checkTargetTimer = 2000;

                    Unit* target = me->SelectNearestPlayer(1.0f);
                    if (m_LastTarget != target)
                    {
                        m_LastTarget = target;
                        AttackStart(m_LastTarget);
                    }
                }
                else
                {
                    checkTargetTimer -= diff;
                }
            }

        private:

            uint32 checkTargetTimer;
            Unit* m_LastTarget;

        };
};

class npc_korkron_dark_shaman_toxic_storm : public CreatureScript
{
    public:
        npc_korkron_dark_shaman_toxic_storm() : CreatureScript("npc_korkron_dark_shaman_toxic_storm") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_korkron_dark_shaman_toxic_stormAI(creature);
        }

        struct npc_korkron_dark_shaman_toxic_stormAI : public Scripted_NoMovementAI
        {
            npc_korkron_dark_shaman_toxic_stormAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);

                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));

                summonTornadoTimer = 10000;
                despawnTornadoTimer = 55000;
            }

            void Reset()
            {
                me->AddAura(SPELL_TOXIC_STORM_AURA, me);
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
                if (me->IsInCombat())
                {
                    DoZoneInCombat(summon);
                }
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                summons.Despawn(summon);
            }

            void UpdateAI(const uint32 diff)
            {
                DespawnToxicTornados(diff);

                if (!UpdateVictim())
                    return;

                SummonToxicTornado(diff);
            }

        private:

            void SummonToxicTornado(const uint32 diff)
            {
                if (summonTornadoTimer <= diff)
                {
                    summonTornadoTimer = TIMER_TOXIC_TORNADO;

                    DoCast(me, SPELL_TOXIC_STORM_TORNADO);
                }
                else
                {
                    summonTornadoTimer -= diff;
                }
            }

            void DespawnToxicTornados(const uint32 diff)
            {
                if (despawnTornadoTimer <= diff)
                {
                    despawnTornadoTimer = 55000;

                    summons.DespawnEntry(NPC_TOXIC_TORNADO);
                }
                else
                {
                    despawnTornadoTimer -= diff;
                }
            }

        private:

            uint32 summonTornadoTimer;
            uint32 despawnTornadoTimer;
        };
};

class npc_korkron_dark_shaman_toxic_tornado : public CreatureScript
{
    public:
        npc_korkron_dark_shaman_toxic_tornado() : CreatureScript("npc_korkron_dark_shaman_toxic_tornado") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_korkron_dark_shaman_toxic_tornadoAI(creature);
        }

        struct npc_korkron_dark_shaman_toxic_tornadoAI : public ScriptedAI
        {
            npc_korkron_dark_shaman_toxic_tornadoAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetSpeed(MOVE_RUN, 0.5f);
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);

                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            }

            void Reset()
            {
                me->AddAura(SPELL_TOXIC_TORNADO_AURA, me);

                me->GetMotionMaster()->MoveRandom(40.0f);
            }
        };
};

class npc_korkron_dark_shaman_foul_slime : public CreatureScript
{
    public:
        npc_korkron_dark_shaman_foul_slime() : CreatureScript("npc_korkron_dark_shaman_foul_slime") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_korkron_dark_shaman_foul_slimeAI(creature);
        }

        struct npc_korkron_dark_shaman_foul_slimeAI : public ScriptedAI
        {
            npc_korkron_dark_shaman_foul_slimeAI(Creature* creature) : ScriptedAI(creature)
            {
                me->setActive(true);

                me->SetReactState(REACT_PASSIVE);

                m_MoveTimer = TIMER_FOUL_SLIME_MOVE;
                m_IsMoving = false;
            }

            void Reset()
            {
                me->SetSpeed(MOVE_RUN, 0.3f);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                BeginMoving(diff);

                DoMeleeAttackIfReady();
            }

        private:

            void BeginMoving(const uint32 diff)
            {
                if (m_IsMoving)
                    return;

                if (m_MoveTimer <= diff)
                {
                    m_IsMoving = true;

                    me->SetReactState(REACT_AGGRESSIVE);
                    me->AddAura(SPELL_FOULNESS, me);
                }
                else
                {
                    m_MoveTimer -= diff;
                }
            }

        private:

            uint32 m_MoveTimer;
            bool m_IsMoving;

        };
};

class npc_korkron_dark_shaman_falling_ash : public CreatureScript
{
    public:
        npc_korkron_dark_shaman_falling_ash() : CreatureScript("npc_korkron_dark_shaman_falling_ash") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_korkron_dark_shaman_falling_ashAI(creature);
        }

        struct npc_korkron_dark_shaman_falling_ashAI : public ScriptedAI
        {
            npc_korkron_dark_shaman_falling_ashAI(Creature* creature) : ScriptedAI(creature)
            {
                me->setActive(true);

                me->SetReactState(REACT_PASSIVE);

                me->SetCanFly(true);
                me->SetDisableGravity(true);

                me->SetSpeed(MOVE_RUN, FALLING_ASH_SPEED);
                me->SetSpeed(MOVE_FLIGHT, FALLING_ASH_SPEED);

                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            }

            void Reset()
            {
                me->AddAura(SPELL_FALLING_ASH_COSMETIC, me);
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type == POINT_MOTION_TYPE && id == POINT_FALLING_ASH)
                {
                    DoCastAOE(SPELL_FALLING_ASH_DMG, true);
                    me->DespawnOrUnsummon(100);
                }
            }
        };
};

class npc_korkron_dark_shaman_iron_tomb : public CreatureScript
{
    public:
        npc_korkron_dark_shaman_iron_tomb() : CreatureScript("npc_korkron_dark_shaman_iron_tomb") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_korkron_dark_shaman_iron_tombAI(creature);
        }

        struct npc_korkron_dark_shaman_iron_tombAI : public Scripted_NoMovementAI
        {
            npc_korkron_dark_shaman_iron_tombAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);

                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            }

            void IsSummonedBy(Unit* owner) override
            {
                DoCast(me, SPELL_IRON_TOMB_DMG);
            }
        };
};

class spell_korkron_dark_shaman_toxic_mist : public SpellScriptLoader
{
    public:
        spell_korkron_dark_shaman_toxic_mist() : SpellScriptLoader("spell_korkron_dark_shaman_toxic_mist") { }

        class spell_korkron_dark_shaman_toxic_mist_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_korkron_dark_shaman_toxic_mist_SpellScript);

            void FilterTargets(std::list<WorldObject*> &targets)
            {
                // Recalculate targets
                targets.clear();

                if (!GetCaster())
                    return;

                if (Creature* pCreature = GetCaster()->ToCreature())
                {
                    uint8 targetsCount = pCreature->GetMap()->Is25ManRaid() ? 5 : 2;
                    std::list<Unit*> newTargets;
                    pCreature->AI()->SelectTargetList(newTargets, targetsCount, SELECT_TARGET_RANDOM, 0.0f, true);

                    for (auto target : newTargets)
                        targets.push_back(target);

                    if (targets.size() > targetsCount)
                        Trinity::Containers::RandomResize(targets, targetsCount);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_korkron_dark_shaman_toxic_mist_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_korkron_dark_shaman_toxic_mist_SpellScript();
        }

        class spell_korkron_dark_shaman_toxic_mist_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_korkron_dark_shaman_toxic_mist_AuraScript);

            void HandleAfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (!GetUnitOwner())
                    return;

                GetUnitOwner()->RemoveAura(SPELL_TOXICITY);
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_korkron_dark_shaman_toxic_mist_AuraScript::HandleAfterRemove, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_korkron_dark_shaman_toxic_mist_AuraScript();
        }
};

class spell_korkron_dark_shaman_ashen_wall : public SpellScriptLoader
{
    public:
        spell_korkron_dark_shaman_ashen_wall() : SpellScriptLoader("spell_korkron_dark_shaman_ashen_wall") { }

        class spell_korkron_dark_shaman_ashen_wall_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_korkron_dark_shaman_ashen_wall_SpellScript);

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                Position centerPos = GetHitUnit()->GetPosition();

                for (uint8 i = 0; i < 8; ++i)
                {
                    Position summonPos = GetHitUnit()->GetNearPosition(-20.0f + (5.0f * i), GetHitUnit()->GetRelativeAngle(GetCaster()) + (M_PI / 2));;
                    summonPos.SetOrientation(GetCaster()->GetOrientation());
                    GetCaster()->CastSpell(summonPos, SPELL_ASHEN_WALL_SUMMON, true);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_korkron_dark_shaman_ashen_wall_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_korkron_dark_shaman_ashen_wall_SpellScript();
        }
};

class spell_korkron_dark_shaman_falling_ash : public SpellScriptLoader
{
    public:
        spell_korkron_dark_shaman_falling_ash() : SpellScriptLoader("spell_korkron_dark_shaman_falling_ash") { }

        class spell_korkron_dark_shaman_falling_ash_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_korkron_dark_shaman_falling_ash_SpellScript);

            void HandleOnHit(SpellEffIndex effIndex)
            {
                if (!GetCaster())
                    return;

                PreventHitEffect(effIndex);

                WorldLocation summonPos = *GetExplTargetDest();
                Position groundPos = summonPos;

                summonPos.m_positionZ += FALLING_ASH_OFFSET;
                SetExplTargetDest(summonPos);

                WorldLocation* dest = GetHitDest();
                if (dest)
                {
                    dest->Relocate(summonPos);
                }

                if (Creature* pAsh = GetCaster()->SummonCreature(NPC_FALLING_ASH, summonPos, TEMPSUMMON_TIMED_DESPAWN, 60000))
                {
                    pAsh->GetMotionMaster()->MovePoint(POINT_FALLING_ASH, groundPos);
                }
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_korkron_dark_shaman_falling_ash_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_korkron_dark_shaman_falling_ash_SpellScript();
        }
};

class spell_korkron_dark_shaman_foul_geyser : public SpellScriptLoader
{
    public:
        spell_korkron_dark_shaman_foul_geyser() : SpellScriptLoader("spell_korkron_dark_shaman_foul_geyser") { }

        class spell_korkron_dark_shaman_foul_geyser_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_korkron_dark_shaman_foul_geyser_AuraScript);

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                PreventDefaultAction();

                if (!GetUnitOwner())
                    return;

                if (Unit* target = GetUnitOwner()->GetVictim())
                {
                    GetUnitOwner()->CastSpell(target, SPELL_FOUL_GEYSER_MISSILE, true);
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_korkron_dark_shaman_foul_geyser_AuraScript::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_korkron_dark_shaman_foul_geyser_AuraScript();
        }
};

class spell_korkron_dark_shaman_iron_tomb_aoe : public SpellScriptLoader
{
    public:
        spell_korkron_dark_shaman_iron_tomb_aoe() : SpellScriptLoader("spell_korkron_dark_shaman_iron_tomb_aoe") { }

        class spell_korkron_dark_shaman_iron_tomb_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_korkron_dark_shaman_iron_tomb_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (Creature* pCreature = GetCaster()->ToCreature())
                {
                    targets.clear();

                    Unit* target = pCreature->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, -15.0f, true);
                    if (!target)
                        target = pCreature->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);

                    if (target)
                        targets.push_back(target);
                }
            }

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_IRON_TOMB_SUMMON, true);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_korkron_dark_shaman_iron_tomb_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_korkron_dark_shaman_iron_tomb_aoe_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_korkron_dark_shaman_iron_tomb_aoe_SpellScript();
        }
};

void AddSC_boss_korkron_dark_shaman()
{
    new boss_earthbreaker_haromm();                 // 71859
    new boss_wavebinder_kardris();                  // 71858
    new npc_korkron_dark_shaman_wolf();             // 71921 71923
    new npc_korkron_dark_shaman_ash_elemental();    // 71827
    new npc_korkron_dark_shaman_toxic_storm();      // 71801
    new npc_korkron_dark_shaman_toxic_tornado();    // 71817
    new npc_korkron_dark_shaman_foul_slime();       // 71825
    new npc_korkron_dark_shaman_falling_ash();      // 71789
    new npc_korkron_dark_shaman_iron_tomb();        // 71941

    new spell_korkron_dark_shaman_toxic_mist();     // 144089
    new spell_korkron_dark_shaman_ashen_wall();     // 144070
    new spell_korkron_dark_shaman_falling_ash();    // 143973
    new spell_korkron_dark_shaman_foul_geyser();    // 143990
    new spell_korkron_dark_shaman_iron_tomb_aoe();  // 144328
}
