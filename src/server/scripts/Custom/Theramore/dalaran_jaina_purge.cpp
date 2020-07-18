#include "ScriptMgr.h"
#include "Map.h"
#include "GameObject.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
#include "ScriptedCreature.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"
#include "CreatureGroups.h"
#include "GridNotifiers.h"
#include "CellImpl.h"
#include "World.h"
#include "ScriptedGossip.h"

#include <iostream>

constexpr uint32 NPCS_TOTAL_COUNT = 5;

enum NPCs
{
    NPC_JAINA_PROUDMOORE        = 100045,
    NPC_DISPLACED_SUNREAVER     = 100048,
    NPC_WATER_ELEMENTAL         = 100011,
    NPC_AETHAS_SUNREAVER        = 100050,
    NPC_SUNREAVER_GUARDIAN      = 100046,
    NPC_SILVER_COV_GUARDIAN     = 100047,
    NPC_INVISIBLE_STALKER       = 32780
};

enum Spells
{
    SPELL_FIREBALL              = 100002,
    SPELL_BLIZZARD              = 100001,
    SPELL_TELEPORT              = 51347,
    SPELL_DIRECT_TELEPORT       = 100045,
    SPELL_AURA_OF_BRILLANCE     = 31260,
    SPELL_WATER_BOLT            = 100046,
    SPELL_ICE_PRISON            = 100047,
    SPELL_POWER_BALL_VISUAL     = 54139,
    SPELL_FIREBALL_MINOR        = 100003,
    SPELL_FIREBLAST_MINOR       = 100004,
    SPELL_REMEMBER_THERAMORE    = 100051,
    SPELL_KNOCKBACK             = 100052,
    SPELL_ARCANE_SHIELD         = 100048,
    SPELL_FROST_CHANNELING      = 45846,
    SPELL_TELEPORT_STORMWIND    = 100057,

    SPELL_SHOT                  = 100086,
    SPELL_MULTI_SHOT            = 100088,
    SPELL_SILENCING_SHOT        = 100086,
    SPELL_SCATTER_SHOT          = 100087,
    SPELL_ARCANE_SHOT           = 100089
};

enum Misc
{
    // Quests
    QUEST_JAINAS_RESOLUTION     = 80015,
    QUEST_NOWHERE_TO_HIDE       = 80016,
    QUEST_WHAT_HAD_TO_BE_DONE   = 80019,

    // GoB
    GOB_ICE_WALL                = 500012,

    // Jaina's casting
    CASTING_BLIZZARD            = 1,
    CASTING_FIREBALL            = 2,

    // Sunreaver's casting
    CASTING_FIREBLAST           = 1,

    // Sunreaver chase
    SAY_JAINA_TELEPORT          = 0,
    SAY_JAINA_SLAIN             = 1,
    SAY_JAINA_1                 = 2,
    SAY_JAINA_2                 = 3,
    SAY_AETHAS_3                = 0,
    SAY_JAINA_4                 = 4,
    SAY_AETHAS_5                = 1,
    SAY_JAINA_6                 = 5,
    SAY_JAINA_7                 = 6,

    // Violet Hold Event
    SAY_IVRENNE_1               = 0,

    // Ice wall sunreaver Event
    SAY_ISIAN_1                 = 0,
    SAY_ISIAN_2                 = 1
};

enum Events
{
    // Starters
    ACTION_INTRO        = 1,
    ACTION_ISIAN_WALL   = 2,

    EVENT_ELEMENTAL,

    EVENT_AETHAS_1,
    EVENT_AETHAS_2,
    EVENT_AETHAS_3,
    EVENT_AETHAS_4,
    EVENT_AETHAS_5,
    EVENT_AETHAS_6,
    EVENT_AETHAS_7,
    EVENT_AETHAS_8,
    EVENT_AETHAS_9,
    EVENT_AETHAS_10,

    EVNT_ISIAN_1,
    EVNT_ISIAN_2,
    EVNT_ISIAN_3,
    EVNT_ISIAN_4,
    EVNT_ISIAN_5
};

struct Location
{
    uint32 entry;
    Position position;
};

const Location npcsLocation[NPCS_TOTAL_COUNT] =
{
    { NPC_AETHAS_SUNREAVER,   { 5802.06f, 839.48f, 680.05f, 4.62f }},
    { NPC_SUNREAVER_GUARDIAN, { 5794.70f, 810.40f, 661.83f, 4.53f }},
    { NPC_SUNREAVER_GUARDIAN, { 5797.40f, 809.53f, 662.03f, 4.57f }},
    { NPC_SUNREAVER_GUARDIAN, { 5800.04f, 809.05f, 662.03f, 4.66f }},
    { NPC_SUNREAVER_GUARDIAN, { 5803.09f, 809.48f, 661.83f, 4.59f }}
};

const Position destinationAethas1 = { 5799.26f, 812.35f, 662.02f, 4.62f };

const Position spawnSilverCovGuardian[] =
{
    { 5769.24f, 669.04f, 643.82f, 5.59f },
    { 5833.89f, 676.41f, 643.60f, 4.06f },
    { 5842.63f, 609.25f, 650.60f, 2.50f },
    { 5774.73f, 602.09f, 650.54f, 0.90f }
};

class npc_displaced_sunreaver : public CreatureScript
{
    public:
    npc_displaced_sunreaver() : CreatureScript("npc_displaced_sunreaver") {}

    struct npc_displaced_sunreaverAI : public ScriptedAI
    {
        npc_displaced_sunreaverAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize() { }

        void Teleport()
        {
            DoCastSelf(SPELL_TELEPORT);

            me->SetFaction(35);
            me->SetControlled(true, UNIT_STATE_ROOT);
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
            me->GetMotionMaster()->Clear();
            me->DespawnOrUnsummon(1s);
        }

        void OnSpellCastInterrupt(SpellInfo const* /*spell*/) override
        {
            if (me->IsInCombat() && me->GetVictim())
            {
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveFleeing(me->GetVictim(), 5);
            }
        }

        void DamageTaken(Unit* attacker, uint32& /*damage*/) override
        {
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
            me->SetReactState(REACT_AGGRESSIVE);
        }

        void AttackStart(Unit* who) override
        {
            if (!who)
                return;

            if (me->Attack(who, false))
            {
                AddThreat(who, 50.0f);
                DoStartMovement(who, 20.0f);
                SetCombatMovement(true);
            }
        }

        void JustEngagedWith(Unit* who) override
        {
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveChase(who, 10.f);

            CallAssistance(who, 20.f);

            events.ScheduleEvent(CASTING_FIREBALL, 5ms, 1s);
            events.ScheduleEvent(CASTING_FIREBLAST, 5s);
        }

        void Reset() override
        {
            events.Reset();
            Initialize();

            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
            me->SetReactState(REACT_DEFENSIVE);
            me->SetRespawnDelay(30);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
            {
                Creature* jaina = GetClosestCreatureWithEntry(me, NPC_JAINA_PROUDMOORE, 30.f);
                if (jaina)
                {
                    if (!IsFleeing)
                    {
                        me->GetMotionMaster()->MoveFleeing(jaina);
                        IsFleeing = true;
                    }
                }
                else
                {
                    if (IsFleeing)
                    {
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MovePoint(0, me->GetHomePosition());
                        IsFleeing = false;
                    }
                }
            }
            else
            {
                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case CASTING_FIREBLAST:
                            me->InterruptNonMeleeSpells(true);
                            DoCastVictim(SPELL_FIREBLAST_MINOR);
                            events.RescheduleEvent(CASTING_FIREBLAST, 3s, 10s);
                            break;

                        case CASTING_FIREBALL:
                            DoCastVictim(SPELL_FIREBALL_MINOR);
                            events.RescheduleEvent(CASTING_FIREBALL, 2s);
                            break;

                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }
            }
        }

        private:
        EventMap events;

        void CallAssistance(Unit* who, float radius)
        {
            std::list<Creature*> assistList;
            Trinity::AllCreaturesOfEntryInRange u_check(me, NPC_DISPLACED_SUNREAVER, radius);
            Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, assistList, u_check);
            Cell::VisitGridObjects(me, searcher, radius);

            if (!assistList.empty())
            {
                for (Creature* assist : assistList)
                {
                    if (assist->IsEngaged())
                        continue;

                    if (assist->Attack(who, false))
                    {
                        DoStartMovement(who, 20.0f);
                        SetCombatMovement(true);

                        assist->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                        assist->SetReactState(REACT_AGGRESSIVE);
                        assist->GetMotionMaster()->Clear();
                        assist->GetMotionMaster()->MoveChase(who, 10.f);

                        AddThreat(who, 1000000.f, me);
                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_displaced_sunreaverAI(creature);
    }
};

class dalaran_jaina_purge : public CreatureScript
{
    public:
    dalaran_jaina_purge() : CreatureScript("dalaran_jaina_purge") {}

    struct dalaran_jaina_purgeAI : public ScriptedAI
    {
        dalaran_jaina_purgeAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            teleportTimer = 3 * IN_MILLISECONDS;
        }

        void Reset() override
        {
            events.Reset();
            Initialize();

            me->AddAura(SPELL_AURA_OF_BRILLANCE, me);
            me->AddAura(SPELL_REMEMBER_THERAMORE, me);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetEntry() == NPC_DISPLACED_SUNREAVER)
            {
                if (roll_chance_i(60))
                    Talk(SAY_JAINA_SLAIN);

                teleportTimer = 1 * IN_MILLISECONDS;
            }
        }

        void JustEngagedWith(Unit* who) override
        {
            events.ScheduleEvent(CASTING_FIREBALL, 0s);
            events.ScheduleEvent(CASTING_BLIZZARD, 5s);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
            {
                if (teleportTimer <= diff)
                {
                    if (Creature * sunreaver = GetClosestCreatureWithEntry(me, NPC_DISPLACED_SUNREAVER, 20.f))
                    {
                        if (sunreaver->IsEngaged())
                        {
                            me->Attack(sunreaver, true);
                        }
                        else
                        {
                            if (roll_chance_i(60))
                                Talk(SAY_JAINA_TELEPORT);

                            DoCast(sunreaver, SPELL_DIRECT_TELEPORT);
                            ENSURE_AI(npc_displaced_sunreaver::npc_displaced_sunreaverAI, sunreaver->AI())->Teleport();
                            teleportTimer = urand(5 * IN_MILLISECONDS, 15 * IN_MILLISECONDS);
                        }
                    }
                }
                else teleportTimer -= diff;
            }
            else
            {
                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case CASTING_BLIZZARD:
                            if (Unit * target = SelectTarget(SelectTargetMethod::Random, 0))
                                DoCast(target, SPELL_BLIZZARD);
                            events.RescheduleEvent(CASTING_BLIZZARD, 14s, 25s);
                            break;

                        case CASTING_FIREBALL:
                            if (Unit * target = SelectTarget(SelectTargetMethod::Random, 0))
                                DoCast(target, SPELL_FIREBALL);
                            events.RescheduleEvent(CASTING_FIREBALL, 5s, 8s);
                            break;

                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }
        }

        private:
        EventMap events;
        uint32 teleportTimer;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new dalaran_jaina_purgeAI(creature);
    }
};

class dalaran_aethas_event : public CreatureScript
{
    public:
    dalaran_aethas_event() : CreatureScript("dalaran_aethas_event") {}

    struct dalaran_aethas_eventAI : public ScriptedAI
    {
        dalaran_aethas_eventAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            playingEvent = false;
            aethas = nullptr;
            jaina = nullptr;
            elemental = nullptr;
            victimIndex = 0;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (playingEvent || who->GetTypeId() != TYPEID_PLAYER)
                return;

            player = who->ToPlayer();
            if (me->GetMapId() == 727)
            {
                if (player->GetPhaseMask() == me->GetPhaseMask() && me->IsFriendlyTo(player) && me->IsWithinDist(player, 30.f, false))
                    SetData(ACTION_INTRO, 1U);
            }
        }

        void Reset() override
        {
            events.Reset();
            Initialize();
        }

        void SetData(uint32 id, uint32 /*value*/) override
        {
            switch (id)
            {
                case ACTION_INTRO:

                    playingEvent = true;
                    victimIndex = 0;
                    for (ObjectGuid guid : guardians)
                        guid.Clear();

                    me->PlayDirectMusic(28068);

                    jaina = GetClosestCreatureWithEntry(me, NPC_JAINA_PROUDMOORE, 10.f);
                    jaina->setActive(false);
                    jaina->SetSheath(SHEATH_STATE_UNARMED);
                    jaina->RemoveAllAuras();
                    jaina->SetWalk(true);
                    jaina->SetReactState(REACT_PASSIVE);
                    jaina->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                    for (uint8 i = 0; i < NPCS_TOTAL_COUNT; i++)
                    {
                        Creature* temp = me->SummonCreature(npcsLocation[i].entry, npcsLocation[i].position, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5s);
                        temp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        temp->SetReactState(REACT_PASSIVE);
                        temp->SetFaction(2129);

                        switch (npcsLocation[i].entry)
                        {
                            case NPC_AETHAS_SUNREAVER:
                                aethas = temp;
                                temp->SetWalk(true);
                                temp->GetMotionMaster()->MovePoint(0, destinationAethas1);
                                temp->SetSheath(SHEATH_STATE_UNARMED);
                                break;

                            case NPC_SUNREAVER_GUARDIAN:
                                temp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2HL);
                                guardians.push_back(temp->GetGUID());
                                break;
                        }
                    }

                    elemental = GetClosestCreatureWithEntry(me, NPC_WATER_ELEMENTAL, 10.f);
                    elemental->SetControlled(true, UNIT_STATE_ROOT);

                    events.ScheduleEvent(EVENT_ELEMENTAL, 3s);
                    events.ScheduleEvent(EVENT_AETHAS_1, 11s);
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ELEMENTAL:
                        if (currentVictim && currentVictim->IsAlive())
                            currentVictim->KillSelf();
                        KillVictimWithElemental(victimIndex++);
                        if (victimIndex < 4)
                            events.RescheduleEvent(EVENT_ELEMENTAL, 3s);
                        break;

                    case EVENT_AETHAS_1:
                        jaina->AI()->Talk(SAY_JAINA_1);
                        events.ScheduleEvent(EVENT_AETHAS_2, 6s);
                        break;

                    case EVENT_AETHAS_2:
                        jaina->AI()->Talk(SAY_JAINA_2);
                        events.ScheduleEvent(EVENT_AETHAS_3, 6s);
                        break;

                    case EVENT_AETHAS_3:
                        aethas->AI()->Talk(SAY_AETHAS_3);
                        events.ScheduleEvent(EVENT_AETHAS_4, 3s);
                        break;

                    case EVENT_AETHAS_4:
                        jaina->AI()->Talk(SAY_JAINA_4);
                        events.ScheduleEvent(EVENT_AETHAS_5, 5s);
                        break;

                    case EVENT_AETHAS_5:
                        aethas->AI()->Talk(SAY_AETHAS_5);
                        events.ScheduleEvent(EVENT_AETHAS_6, 2s);
                        break;

                    case EVENT_AETHAS_6:
                        aethas->SetHomePosition(destinationAethas1);
                        aethas->SetControlled(true, UNIT_STATE_ROOT);
                        jaina->AI()->Talk(SAY_JAINA_6);
                        events.ScheduleEvent(EVENT_AETHAS_7, 2s);
                        break;

                    case EVENT_AETHAS_7:
                    {
                        aethas->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        aethas->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STUN);

                        CastSpellExtraArgs args;
                        args.SetTriggerFlags(TRIGGERED_CAST_DIRECTLY);
                        elemental->CastSpell(aethas, SPELL_ICE_PRISON, args);

                        jaina->GetMotionMaster()->MoveCloserAndStop(0, aethas, 3.f);
                        events.ScheduleEvent(EVENT_AETHAS_8, 5s);
                        break;
                    }

                    case EVENT_AETHAS_8:
                        jaina->AI()->Talk(SAY_JAINA_7);
                        events.ScheduleEvent(EVENT_AETHAS_9, 4s);
                        break;

                    case EVENT_AETHAS_9:
                        jaina->CastSpell(jaina, SPELL_POWER_BALL_VISUAL);
                        aethas->CastSpell(aethas, SPELL_POWER_BALL_VISUAL);
                        jaina->DespawnOrUnsummon(2s);
                        aethas->DespawnOrUnsummon(2s);
                        events.ScheduleEvent(EVENT_AETHAS_10, 3s);
                        break;

                    case EVENT_AETHAS_10:
                        player->CompleteQuest(QUEST_JAINAS_RESOLUTION);
                        player->SetPhaseMask(1, true);
                        elemental->KillSelf();
                        elemental->DespawnOrUnsummon(2s);
                        me->setActive(false);
                        break;

                    default:
                        break;
                }
            }
        }

        private:
        EventMap events;
        Player* player;
        Creature* aethas;
        Creature* jaina;
        Creature* elemental;
        uint8 victimIndex;
        Creature* currentVictim;
        std::vector<ObjectGuid> guardians;
        bool playingEvent;

        void KillVictimWithElemental(uint8 index)
        {
            CastSpellExtraArgs args;
            args.SetTriggerFlags(TRIGGERED_CAST_DIRECTLY);
            args.SetTriggerFlags(TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD);
            args.SetTriggerFlags(TRIGGERED_IGNORE_GCD);
            args.AddSpellBP0(9999999);

            if (currentVictim = ObjectAccessor::GetCreature(*me, guardians[index]))
            {
                currentVictim->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                elemental->CastSpell(currentVictim, SPELL_WATER_BOLT, args);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new dalaran_aethas_eventAI(creature);
    }
};

class npc_arcanist_ivrenne : public CreatureScript
{
    public:
    npc_arcanist_ivrenne() : CreatureScript("npc_arcanist_ivrenne") {}

    struct npc_arcanist_ivrenneAI : public ScriptedAI
    {
        npc_arcanist_ivrenneAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            playingEvent = false;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (playingEvent || who->GetTypeId() != TYPEID_PLAYER)
                return;

            player = who->ToPlayer();
            if (me->GetMapId() == 727)
            {
                if (me->IsFriendlyTo(player) && me->IsWithinDist2d(player, 10.f))
                {
                    playingEvent = true;

                    me->AI()->Talk(SAY_IVRENNE_1);
                    events.ScheduleEvent(1, 2s);
                }
            }
        }

        void Reset() override
        {
            events.Reset();
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case 1:
                        DoCast(player, SPELL_KNOCKBACK);
                        events.ScheduleEvent(2, 5s);
                        break;

                    case 2:
                        playingEvent = false;
                        break;

                    default:
                        break;
                }
            }
        }

        private:
        EventMap events;
        Player* player;
        bool playingEvent;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_arcanist_ivrenneAI(creature);
    }
};

class SilverCovenantGuardian : public BasicEvent
{
    public:
    SilverCovenantGuardian(Creature* owner, Creature* uovril, const Position& final) : owner(owner), step(0), uovril(uovril), finalPos(final) { }

    bool Execute(uint64 eventTime, uint32 /*updateTime*/) override
    {
        switch (step)
        {
            case 0:
                owner->SetHomePosition(finalPos);
                owner->GetMotionMaster()->MoveCloserAndStop(0, uovril, 6.f);
                owner->m_Events.AddEvent(this, eventTime + 1000);
                break;

            case 1:
            {
                if (!owner->IsWithinDist2d(uovril, 8.f))
                {
                    owner->m_Events.AddEvent(this, eventTime + 500);
                    return false;
                }

                owner->SetWalk(true);
                owner->SetReactState(REACT_AGGRESSIVE);
                owner->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                owner->GetMotionMaster()->MovePoint(0, finalPos, true, finalPos.GetOrientation());
                owner->DespawnOrUnsummon(30s);

                return true;
            }
        }

        step++;
        return false;
    }

    private:
    Creature* owner;
    Creature* uovril;
    Position finalPos;
    uint8 step;
};

class npc_arcanist_uovril : public CreatureScript
{
    public:
    npc_arcanist_uovril() : CreatureScript("npc_arcanist_uovril") {}

    struct npc_arcanist_uovrilAI : public ScriptedAI
    {
        npc_arcanist_uovrilAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize() { }

        void Reset() override
        {
            events.Reset();
            Initialize();

            DoCastSelf(SPELL_ARCANE_SHIELD);

            events.ScheduleEvent(1, 5s);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case 1:
                    {
                        int randomPos = irand(0, 3);
                        if (Creature* guardian = me->SummonCreature(RAND(NPC_SUNREAVER_GUARDIAN, NPC_SILVER_COV_GUARDIAN), spawnSilverCovGuardian[randomPos], TEMPSUMMON_CORPSE_DESPAWN))
                        {
                            guardian->SetReactState(REACT_PASSIVE);
                            guardian->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            guardian->m_Events.AddEvent(new SilverCovenantGuardian(guardian, me, GetRandomPosition(frand(4.f, 9.f))), guardian->m_Events.CalculateTime(500));
                        }
                        events.Repeat(10s, 20s);
                        break;
                    }

                    default:
                        break;
                }
            }
        }

        private:
        EventMap events;

        Position GetRandomPosition(float dist)
        {
            const Position center = me->GetPosition();
            float alpha = 2 * float(M_PI) * float(rand_norm());
            float r = dist * sqrtf(float(rand_norm()));
            float x = r * cosf(alpha) + center.GetPositionX();
            float y = r * sinf(alpha) + center.GetPositionY();
            return { x, y, center.GetPositionZ(), 0.f };
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_arcanist_uovrilAI(creature);
    }
};

class npc_enchanter_isian : public CreatureScript
{
    public:
    npc_enchanter_isian() : CreatureScript("npc_enchanter_isian") {}

    struct npc_enchanter_isianAI : public ScriptedAI
    {
        npc_enchanter_isianAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {

        }

        bool GossipHello(Player* player) override
        {
            if (player->IsGameMaster() || player->GetQuestStatus(QUEST_NOWHERE_TO_HIDE) == QUEST_STATUS_INCOMPLETE)
            {
                AddGossipItemFor(player, 57021, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, 100004, me->GetGUID());
                return true;
            }

            SendGossipMenuFor(player, 100003, me->GetGUID());
            return true;
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            switch (action)
            {
                case GOSSIP_ACTION_INFO_DEF + 1:
                    SetData(ACTION_ISIAN_WALL, 1U);
                    break;
            }

            CloseGossipMenuFor(player);
            return true;
        }

        void SetData(uint32 id, uint32 value) override
        {
            switch (id)
            {
                case ACTION_ISIAN_WALL:
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                    icewall = GetClosestGameObjectWithEntry(me, GOB_ICE_WALL, 100.f);
                    events.ScheduleEvent(EVNT_ISIAN_1, 2s);
                    break;
            }
        }

        void Reset() override
        {
            events.Reset();
            Initialize();
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVNT_ISIAN_1:
                        Talk(SAY_ISIAN_1);
                        events.ScheduleEvent(EVNT_ISIAN_2, 3s);
                        break;

                    case EVNT_ISIAN_2:
                        Talk(SAY_ISIAN_2);
                        events.ScheduleEvent(EVNT_ISIAN_3, 5s);
                        break;

                    case EVNT_ISIAN_3:
                        DoCastSelf(SPELL_FROST_CHANNELING);
                        events.ScheduleEvent(EVNT_ISIAN_4, 3s);
                        break;

                    case EVNT_ISIAN_4:
                        if (Creature * fx = me->SummonCreature(NPC_INVISIBLE_STALKER, icewall->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 5s))
                            fx->CastSpell(fx, 73773);
                        icewall->UseDoorOrButton();
                        events.ScheduleEvent(EVNT_ISIAN_5, 3s);
                        break;

                    case EVNT_ISIAN_5:
                        me->RemoveAurasDueToSpell(SPELL_FROST_CHANNELING);
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2HL);
                        break;

                    default:
                        break;
                }
            }
        }

        private:
        EventMap events;
        GameObject* icewall;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_enchanter_isianAI(creature);
    }
};

class npc_vereesa_windrunner : public CreatureScript
{
    public:
    npc_vereesa_windrunner() : CreatureScript("npc_vereesa_windrunner") {}

    struct npc_vereesa_windrunnerAI : public ScriptedAI
    {
        npc_vereesa_windrunnerAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            scheduler.SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            });
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            switch (quest->GetQuestId())
            {
                case QUEST_NOWHERE_TO_HIDE:
                {
                    const Position pos = player->GetPositionWithOffset({ 2.0f, 2.0f, 0.0f, 0.0f });
                    player->SummonPet(100071, pos.GetPositionX(), pos.GetPositionY(), player->GetPositionZ(), PET_FOLLOW_ANGLE, SUMMON_PET, 0U, true);
                    break;
                }

                case QUEST_WHAT_HAD_TO_BE_DONE:
                    player->SetPhaseMask(4, true);
                    player->CastSpell(player, SPELL_TELEPORT_STORMWIND);
                    break;
            }
        }

        void AttackStart(Unit* who) override
        {
            if (!who)
                return;

            if (me->Attack(who, false))
            {
                AddThreat(who, 50.0f);
                DoStartMovement(who, 20.0f);
                SetCombatMovement(true);
            }
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            scheduler
                .Schedule(5ms, [this](TaskContext shot)
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    {
                        if (!target->HasAura(SPELL_SCATTER_SHOT))
                            DoCast(target, SPELL_SHOT);
                    }
                    shot.Repeat(2s);
                })
                .Schedule(3s, [this](TaskContext multi_shot)
                {
                    DoCastAOE(SPELL_MULTI_SHOT);
                    multi_shot.Repeat(4s, 8s);
                })
                .Schedule(8s, [this](TaskContext arcane_shot)
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    {
                        if (!target->HasAura(SPELL_SCATTER_SHOT))
                            DoCast(target, SPELL_ARCANE_SHOT);
                    }
                    arcane_shot.Repeat(2s, 4s);
                })
                .Schedule(12s, [this](TaskContext scatter_shot)
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    {
                        if (target->HasAura(SPELL_SCATTER_SHOT))
                        {
                            scatter_shot.Repeat(1s);
                        }
                        else
                        {
                            DoCast(target, SPELL_SCATTER_SHOT);
                            scatter_shot.Repeat(14s, 32s);
                        }
                    }
                    else
                    {
                        scatter_shot.Repeat(1s);
                    }
                })
                .Schedule(3s, [this](TaskContext silencing_shot)
                {
                    if (Unit* target = DoSelectCastingUnit(SPELL_SILENCING_SHOT, 35.f))
                    {
                        if (!target->HasAura(SPELL_SCATTER_SHOT))
                        {
                            DoCast(target, SPELL_SILENCING_SHOT);
                            silencing_shot.Repeat(35s, 40s);
                        }
                        else
                        {
                            silencing_shot.Repeat(1s);
                        }
                    }
                    else
                    {
                        silencing_shot.Repeat(1s);
                    }
                });
        }

        void JustDied(Unit* /*killer*/) override
        {
            scheduler.CancelAll();
        }

        void Reset() override
        {
            Initialize();

            scheduler.CancelAll();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            scheduler.Update();
        }

        private:
        TaskScheduler scheduler;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_vereesa_windrunnerAI(creature);
    }
};

void AddSC_dalaran_jaina_purge()
{
    new dalaran_jaina_purge();
    new npc_displaced_sunreaver();
    new dalaran_aethas_event();
    new npc_arcanist_ivrenne();
    new npc_arcanist_uovril();
    new npc_enchanter_isian();
    new npc_vereesa_windrunner();
}
