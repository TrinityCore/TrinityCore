#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GridNotifiers.h"
#include "Player.h"
#include "ObjectAccessor.h"
#include "halls_of_origination.h"

enum Spells
{
    SPELL_CHAOS_PORTAL_CHANNEL  = 76784,
    SPELL_CHAOS_BOLT            = 77069,
    SPELL_REIGN_OF_CHAOS        = 77023,
    SPELL_CHAOS_BLAST_SUMMON    = 76674,
    SPELL_CHAOS_BLAST_MISSILE   = 76676,
    SPELL_CHAOS_BLAST_DAMAGE    = 76681
};

enum Entities
{
    NPC_CHAOS_SEED              = 41126,
    NPC_CHAOS_PORTAL            = 41055,
};

enum Events
{
    EVENT_CHAOS_BOLT            = 1,
    EVENT_SEED_OF_CHAOS,
    EVENT_REIGN_OF_CHAOS,
    EVENT_CHAOS_BLAST,
    EVENT_CHAOS_PORTAL_MOVE,
    EVENT_CHAOS_PORTAL,
    EVENT_CHAOS_PORTAL_RESET,
};

enum Phases
{
    PHASE_NORMAL                = 1,
    PHASE_CHAOS_PORTAL
};

enum MISC
{
    POINT_CHAOS_PORTAL          = 1,
    DATA_CHAOS_PORTAL           = 1,
    DATA_RESET_PORTAL           = 2,
};

enum Quotes
{
    SAY_AGGRO,
    SAY_DEATH,
    SAY_SLAY
};

struct boss_setesh : public BossAI
{
    boss_setesh(Creature* creature) : BossAI(creature, DATA_SETESH)
    {
        memset(&Portals, 0, sizeof(Portals));
    }

private:
    ObjectGuid Portals[5];
    //std::list<uint64> lPortals;
    int8 portal;

    void Reset() override
    {
        portal = 0;
        _Reset();
        me->SetReactState(REACT_AGGRESSIVE);
        events.SetPhase(PHASE_NORMAL);
        ResetPortals();
    }

    void KilledUnit(Unit* victim) override
    {
        if(victim->IsPlayer() && roll_chance_f(15.0f))
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        ResetPortals();
        _JustDied();
    }

    void ResetPortals()
    {
        for (int i = 0; i < 5; ++i)
            if (Creature* c = ObjectAccessor::GetCreature(*me, Portals[i]))
                c->AI()->SetData(DATA_RESET_PORTAL, 1);
    }

    void FillPortals()
    {
        std::list<Creature*> cList;
        me->GetCreatureListWithEntryInGrid(cList, NPC_CHAOS_PORTAL, 200.0f);

        if (!cList.empty())
        {
            uint8 i = 0;
            for (std::list<Creature *>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr, ++i)
                if (i < 5)
                 Portals[i] = (*itr)->GetGUID();
        }
    }

    void SpellHitTarget(Unit* victim, const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_CHAOS_BLAST_MISSILE)
            victim->CastSpell(victim, SPELL_CHAOS_BLAST_DAMAGE, true);
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        if (id == POINT_CHAOS_PORTAL)
            events.ScheduleEvent(EVENT_CHAOS_PORTAL, 500, 0, PHASE_CHAOS_PORTAL);
    }

    void EnterCombat(Unit* who) override
    {
        BossAI::EnterCombat(who);
        events.ScheduleEvent(EVENT_CHAOS_BLAST, urand(10000, 12000), 0, PHASE_NORMAL);
        events.ScheduleEvent(EVENT_CHAOS_BOLT, 1000, 0, PHASE_NORMAL);
        events.ScheduleEvent(EVENT_REIGN_OF_CHAOS, urand(20000, 25000), 0, PHASE_NORMAL);
        events.ScheduleEvent(EVENT_SEED_OF_CHAOS, urand(30000, 35000), 0, PHASE_NORMAL);
        events.ScheduleEvent(EVENT_CHAOS_PORTAL_MOVE, urand(15000, 20000), 0, PHASE_NORMAL);
        me->SetReactState(REACT_PASSIVE);
        me->GetMotionMaster()->Clear();
        me->GetMotionMaster()->MoveIdle();
        FillPortals();
        Talk(SAY_AGGRO);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_CHAOS_BLAST:
             DoCast(SPELL_CHAOS_BLAST_SUMMON);
             DoCast(SPELL_CHAOS_BLAST_MISSILE);
             events.ScheduleEvent(EVENT_CHAOS_BLAST, urand(18000, 20000), 0, PHASE_NORMAL);
             break;

        case EVENT_CHAOS_BOLT:
            DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), SPELL_CHAOS_BOLT);
            events.ScheduleEvent(EVENT_CHAOS_BOLT, 2000, 0, PHASE_NORMAL);
            break;

        case EVENT_REIGN_OF_CHAOS:
             DoCast(me, SPELL_REIGN_OF_CHAOS, false);
             events.ScheduleEvent(EVENT_REIGN_OF_CHAOS, urand(20000, 25000), 0, PHASE_NORMAL);
             break;

        case EVENT_SEED_OF_CHAOS:
             if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                if (Creature* seed = me->SummonCreature(NPC_CHAOS_SEED, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ() + 30.0f))
                    seed->GetMotionMaster()->MovePoint(1, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
             events.ScheduleEvent(EVENT_SEED_OF_CHAOS, urand(30000, 35000), 0, PHASE_NORMAL);
             break;

        case EVENT_CHAOS_PORTAL_MOVE:
        {
            events.SetPhase(PHASE_CHAOS_PORTAL);
            if (portal > 4)
                portal = 0;
            float x, y, z;
            if (Creature* chaosPortal = ObjectAccessor::GetCreature(*me, Portals[portal]))
            {
                chaosPortal->GetNearPoint(nullptr, x, y, z, 0.0f, 15.0f, chaosPortal->GetAngle(me));
                me->GetMotionMaster()->MovePoint(POINT_CHAOS_PORTAL, x, y, z);
            }
        }
        break;

        case EVENT_CHAOS_PORTAL:
             if (Creature* chaosPortal = ObjectAccessor::GetCreature(*me, Portals[portal]))
             {
                if (!chaosPortal->IsAlive())
                    chaosPortal->Respawn();
                chaosPortal->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
                chaosPortal->AI()->SetData(DATA_CHAOS_PORTAL, 1);
                DoCast(chaosPortal, SPELL_CHAOS_PORTAL_CHANNEL, false);
             }
             ++portal;
             events.ScheduleEvent(EVENT_CHAOS_PORTAL_MOVE, urand(20000, 25000), 0, PHASE_NORMAL);
             events.ScheduleEvent(EVENT_CHAOS_PORTAL_RESET, 2000, 0, PHASE_CHAOS_PORTAL);
             break;

        case EVENT_CHAOS_PORTAL_RESET:
             events.SetPhase(PHASE_NORMAL);
             events.RescheduleEvent(EVENT_CHAOS_BOLT, 2000, 0, PHASE_NORMAL);
             break;
        }
    }
};

class npc_chaos_seed : public CreatureScript
{
    enum
    {
        SPELL_SEED_OF_CHAOS             = 76870
    };

    struct npc_chaos_seedAI : public ScriptedAI
    {
        npc_chaos_seedAI(Creature* creature) : ScriptedAI(creature) {}

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == 1)
            {
                DoCast(me, SPELL_SEED_OF_CHAOS, true);
                me->DespawnOrUnsummon(2000);
            }
        }
    };

public:
    npc_chaos_seed() : CreatureScript("npc_chaos_seed") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_chaos_seedAI(creature);
    }
};

class npc_chaos_portal : public CreatureScript
{
    enum
    {
        NPC_VOID_SEEKER             = 41148,
        NPC_VOID_SENTINEL           = 41208,
        NPC_VOID_WURM               = 41212,

        SPELL_PORTAL_VISUAL         = 76714,

        EVENT_ENABLE_VISUAL         = 1,
        EVENT_SUMMON_WURMS,
        EVENT_SUMMON_SENTINEL,
        EVENT_SUMMON_SEEKER,
        EVENT_DESPAWN,
    };

    struct npc_chaos_portalAI : public ScriptedAI
    {
        npc_chaos_portalAI(Creature* creature) : ScriptedAI(creature), summons(me) {}

        void Reset() override
        {
            done = false;
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            events.Reset();
            me->SetObjectScale(1.0f);
            me->SetReactState(REACT_PASSIVE);
        }

        void SetData(uint32 type, uint32 /*value*/) override
        {
            if (type == DATA_CHAOS_PORTAL)
            {
                events.ScheduleEvent(EVENT_ENABLE_VISUAL, 2000);

                if (IsHeroic())
                {
                    events.ScheduleEvent(EVENT_SUMMON_SENTINEL, 3000);
                    events.ScheduleEvent(EVENT_SUMMON_WURMS, 9000);
                    events.ScheduleEvent(EVENT_SUMMON_SEEKER, 19000);
                }else
                {
                    events.ScheduleEvent(EVENT_SUMMON_WURMS, 3000);
                    events.ScheduleEvent(EVENT_SUMMON_SEEKER, 15000);
                    events.ScheduleEvent(EVENT_SUMMON_SENTINEL, 30000);
                    events.ScheduleEvent(EVENT_DESPAWN, 32000);
                }
            }
            else if (type == DATA_RESET_PORTAL)
            {
                EnterEvadeMode();
                summons.DespawnAll();
            }
        }

        void JustSummoned(Creature* summon) override
        {
            summon->SetInCombatWithZone();
            summons.Summon(summon);
        }

        void JustDied(Unit* ) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_ENABLE_VISUAL:
                    DoCast(SPELL_PORTAL_VISUAL);
                    me->SetObjectScale(3.0f);
                    //me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
                    break;
                case EVENT_SUMMON_WURMS:
                    for (uint8 i = 0; i < 2; ++i)
                        me->SummonCreature(NPC_VOID_WURM, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 500);
                    if (done)
                        events.ScheduleEvent(urand(EVENT_SUMMON_WURMS, EVENT_SUMMON_SENTINEL), 15000);
                    break;
                case EVENT_SUMMON_SENTINEL:
                    me->SummonCreature(NPC_VOID_SENTINEL, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 500);
                    if (done)
                        events.ScheduleEvent(urand(EVENT_SUMMON_WURMS, EVENT_SUMMON_SENTINEL), 15000);
                    break;
                case EVENT_SUMMON_SEEKER:
                    me->SummonCreature(NPC_VOID_SEEKER, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 500);
                    if (IsHeroic())
                    {
                        done = true;
                        events.ScheduleEvent(urand(EVENT_SUMMON_WURMS, EVENT_SUMMON_SENTINEL), 15000);
                    }
                    break;
                case EVENT_DESPAWN:
                    EnterEvadeMode();
                    break;
                }
            }
        }
    private:
        EventMap events;
        SummonList summons;
        bool done;
    };

public:
    npc_chaos_portal() : CreatureScript("npc_chaos_portal") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_chaos_portalAI(creature);
    }
};

void AddSC_boss_setesh()
{
    RegisterCreatureAI(boss_setesh);
    new npc_chaos_seed();
    new npc_chaos_portal();
};
