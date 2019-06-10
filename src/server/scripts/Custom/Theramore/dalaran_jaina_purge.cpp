#include "ScriptMgr.h"
#include "Map.h"
#include "GameObject.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "TemporarySummon.h"
#include "ScriptedCreature.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"
#include "CreatureGroups.h"

#include <iostream>

#define NPCS_TOTAL_COUNT 5

enum NPCs
{
    NPC_JAINA_PROUDMOORE        = 100045,
    NPC_DISPLACED_SUNREAVER     = 100048,
    NPC_WATER_ELEMENTAL         = 100011,
    NPC_AETHAS_SUNREAVER        = 100050,
    NPC_SUNREAVER_GUARDIAN      = 100046
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
};

enum Misc
{
    // Jaina's casting
    CASTING_BLIZZARD            = 1,

    // Sunreaver's casting
    CASTING_FIREBLAST           = 1,

    SAY_JAINA_TELEPORT          = 0,
    SAY_JAINA_SLAIN             = 1,
    SAY_JAINA_1                 = 2,
    SAY_JAINA_2                 = 3,
    SAY_AETHAS_3                = 0,
    SAY_JAINA_4                 = 4,
    SAY_AETHAS_5                = 1,
    SAY_JAINA_6                 = 5,
    SAY_JAINA_7                 = 6
};

enum Events
{
    // Starters
    ACTION_INTRO                = 1,

    EVENT_ELEMENTAL,

    EVENT_AETHAS_1,
    EVENT_AETHAS_2,
    EVENT_AETHAS_3,
    EVENT_AETHAS_4,
    EVENT_AETHAS_5,
    EVENT_AETHAS_6,
    EVENT_AETHAS_7,
    EVENT_AETHAS_8,
    EVENT_AETHAS_9
};

struct Location
{
    uint32 entry;
    Position position;
} npcsLocation[NPCS_TOTAL_COUNT] =
{
    { NPC_AETHAS_SUNREAVER,   { 5802.06f, 839.48f, 680.05f, 4.62f }},
    { NPC_SUNREAVER_GUARDIAN, { 5794.70f, 810.40f, 661.83f, 4.53f }},
    { NPC_SUNREAVER_GUARDIAN, { 5797.40f, 809.53f, 662.04f, 4.57f }},
    { NPC_SUNREAVER_GUARDIAN, { 5800.04f, 809.05f, 662.08f, 4.66f }},
    { NPC_SUNREAVER_GUARDIAN, { 5803.09f, 809.48f, 662.86f, 4.59f }}
};

const Position destinationAethas1 = { 5799.26f, 812.35f, 662.02f, 4.62f };

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

        void DamageTaken(Unit* attacker, uint32& /*damage*/) override
        {
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);

            me->SetReactState(REACT_AGGRESSIVE);
            me->Attack(attacker, true);
        }

        void JustEngagedWith(Unit* who) override
        {
            me->GetMotionMaster()->Clear();
            events.ScheduleEvent(CASTING_FIREBLAST, 2s);
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

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case CASTING_FIREBLAST:
                            DoCastVictim(SPELL_FIREBLAST_MINOR);
                            events.RescheduleEvent(CASTING_FIREBLAST, 8s, 10s);
                            break;

                        default:
                            break;
                    }
                }

                DoSpellAttackIfReady(SPELL_FIREBALL_MINOR);
            }
        }

        private:
        EventMap events;
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
            teleport = false;
            teleportTimer = 10 * IN_MILLISECONDS;
        }

        void Reset() override
        {
            events.Reset();
            Initialize();

            me->AddAura(SPELL_AURA_OF_BRILLANCE, me);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetEntry() == NPC_DISPLACED_SUNREAVER)
            {
                Talk(SAY_JAINA_SLAIN);

                teleportTimer = 3 * IN_MILLISECONDS;
            }
        }

        void AttackStart(Unit* who) override
        {
            if (!who)
                return;

            if (me->Attack(who, false))
                SetCombatMovement(false);
        }

        void JustEngagedWith(Unit* who) override
        {
            events.ScheduleEvent(CASTING_BLIZZARD, 2s);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
            {
                if (teleportTimer <= diff)
                {
                    if (Creature* sunreaver = GetClosestCreatureWithEntry(me, NPC_DISPLACED_SUNREAVER, 30.f))
                    {
                        if (me->IsWithinLOSInMap(sunreaver))
                        {
                            Talk(SAY_JAINA_TELEPORT);

                            DoCast(sunreaver, SPELL_DIRECT_TELEPORT);
                            ENSURE_AI(npc_displaced_sunreaver::npc_displaced_sunreaverAI, sunreaver->AI())->Teleport();
                            teleportTimer = urand(8 * IN_MILLISECONDS, 15 * IN_MILLISECONDS);
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
                            if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_BLIZZARD);
                            events.RescheduleEvent(CASTING_BLIZZARD, 14s, 25s);
                            break;

                        default:
                            break;
                    }
                }

                DoSpellAttackIfReady(SPELL_FIREBALL);
            }
        }

        private:
        EventMap events;
        bool teleport;
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
            aethas = nullptr;
            jaina = nullptr;
            elemental = nullptr;
            victimIndex = 0;
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

                    // Reset valeurs pour test
                    victimIndex = 0;
                    for (ObjectGuid guid : guardians)
                        guid.Clear();

                    me->PlayDirectMusic(28068);

                    jaina = me->SummonCreature(NPC_JAINA_PROUDMOORE, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
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
                                break;

                            case NPC_SUNREAVER_GUARDIAN:
                                temp->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2HL);
                                guardians.push_back(temp->GetGUID());
                                break;
                        }
                    }

                    elemental = me->SummonCreature(NPC_WATER_ELEMENTAL, 5800.13f, 793.25f, 661.86f, 1.43f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5 * IN_MILLISECONDS);
                    elemental->SetControlled(true, UNIT_STATE_ROOT);

                    events.ScheduleEvent(EVENT_ELEMENTAL, 3s);
                    events.ScheduleEvent(EVENT_AETHAS_1,  11s);
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
                        KillVictimWithElemental(victimIndex++);
                        if (victimIndex < 4)
                            events.RescheduleEvent(EVENT_ELEMENTAL, 2s, 5s);
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
                        events.ScheduleEvent(EVENT_AETHAS_7, 5s);
                        break;

                    case EVENT_AETHAS_7:
                        jaina->GetMotionMaster()->MoveCloserAndStop(0, aethas, 3.f);
                        aethas->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        elemental->CastSpell(aethas, SPELL_ICE_PRISON);
                        events.ScheduleEvent(EVENT_AETHAS_8, 5s);
                        break;

                    case EVENT_AETHAS_8:
                        jaina->AI()->Talk(SAY_JAINA_7);
                        events.ScheduleEvent(EVENT_AETHAS_9, 3s);
                        break;

                    case EVENT_AETHAS_9:
                        jaina->CastSpell(jaina, SPELL_POWER_BALL_VISUAL);
                        aethas->CastSpell(aethas, SPELL_POWER_BALL_VISUAL);
                        jaina->DespawnOrUnsummon(2s);
                        aethas->DespawnOrUnsummon(2s);
                        elemental->KillSelf();
                        break;

                    default:
                        break;
                }
            }
        }

        private:
        EventMap events;
        Creature* aethas;
        Creature* jaina;
        Creature* elemental;
        uint8 victimIndex;
        std::vector<ObjectGuid> guardians;

        void KillVictimWithElemental(uint8 index)
        {
            CastSpellExtraArgs args;
            args.SetTriggerFlags(TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD);
            args.SetTriggerFlags(TRIGGERED_IGNORE_GCD);
            args.AddSpellBP0(9999999);

            if (Creature * victim = ObjectAccessor::GetCreature(*me, guardians[index]))
            {
                victim->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                elemental->CastSpell(victim, SPELL_WATER_BOLT, args);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new dalaran_aethas_eventAI(creature);
    }
};


void AddSC_dalaran_jaina_purge()
{
    new dalaran_jaina_purge();
    new npc_displaced_sunreaver();
    new dalaran_aethas_event();
}
