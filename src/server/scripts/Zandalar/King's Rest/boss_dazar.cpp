#include "ScriptedCreature.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "kings_rest.h"

enum Spells
{
    SPELL_BLADE_COMBO = 268586,
    SPELL_QUAKING_LEAP = 268932,
    SPELL_GALE_SLASH = 268403,
    SPELL_GALE_SLASH_AT_DAMAGE = 268419,
};

enum Events
{
    EVENT_BLADE_COMBO = 1,
    EVENT_QUAKING_LEAP,
    EVENT_GALE_SLASH,
    EVENT_IMPALING_SPEAR
};

struct boss_dazar : public BossAI
{
    boss_dazar(Creature* creature) : BossAI(creature, DATA_DAZAR) { }

    void Reset() override
    {
        BossAI::Reset();
        hp80 = false;
        hp60 = false;
    }

    void EnterCombat(Unit* u) override
    {
        _EnterCombat();
    };

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_BLADE_COMBO:
             DoCastVictim(SPELL_BLADE_COMBO);
             events.Repeat(15s);
             break;

        case EVENT_QUAKING_LEAP:
             if (Unit* tar = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f, true))
             {
                 DoCast(tar, SPELL_QUAKING_LEAP);
             }
            events.Repeat(20s);
            break;

        case EVENT_GALE_SLASH:
             DoCastRandom(SPELL_GALE_SLASH, 100.0f);
             events.Repeat(30s);
             break;

        case EVENT_IMPALING_SPEAR:
             break;
        }
    }

    void DamageTaken(Unit* done_by, uint32& /*damage*/) override
    {
        if (me->HealthBelowPct(80) && !hp80)
        {
            hp80 = true;
            me->SummonCreature(NPC_REBAN, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
        }
        if (me->HealthBelowPct(60) && !hp60)
        {
            hp80 = true;
            me->SummonCreature(NPC_TZALA, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
        }
    };

    void JustDied(Unit* u) override
    {

        switch (me->GetEntry())
        {
         case NPC_DAZAR:
            _JustDied();
            if (GameObject* go = me->FindNearestGameObject(GO_BOON_OF_THE_FIRST_KING, 300.0f))
            {
                go->RemoveFlag(GO_FLAG_LOCKED);
            }
            break;
        }
       
    }

private:
    bool hp80;
    bool hp60;
};

enum DazarMinions
{
    SPELL_HUNTING_LEAP = 270502,
    SPELL_DEATHLY_ROAR = 269369,
    SPELL_ETERNAL_GUARDIAN = 269351,
    SPELL_IMPALING_SPEAR_STUN = 268796,
    EVENT_HUNTING_LEAP = 1,
    EVENT_DEATHLY_ROAR,    
};

//136984,136976
struct npc_dazar_minions : public ScriptedAI
{
    npc_dazar_minions(Creature* c) : ScriptedAI(c) { }

    void IsSummonedBy(Unit* u) override
    {
        switch (me->GetEntry())
        {
        case NPC_REBAN:
             me->AI()->DoZoneInCombat();
             break;

        case NPC_TZALA:
             if (Creature* dazar = me->FindNearestCreature(NPC_DAZAR, 125.0f, true))
             {
                dazar->Mount(NPC_TZALA, 0, NPC_TZALA);
             }
             break;
        }
    }

    void EnterCombat(Unit* u) override
    {
        switch (me->GetEntry())
        {
        case NPC_REBAN:
            events.ScheduleEvent(EVENT_HUNTING_LEAP, 3s);
            break;

        case NPC_TZALA:
            events.ScheduleEvent(EVENT_DEATHLY_ROAR, 3s);
            break;
        }
    };

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_HUNTING_LEAP:
             DoCastRandom(SPELL_HUNTING_LEAP, 100.0f);
             events.Repeat(15s);
             break;

        case EVENT_DEATHLY_ROAR:
             DoCastAOE(SPELL_DEATHLY_ROAR);
             events.Repeat(30s);
             break;
        }
    }
};

void AddSC_boss_dazar_the_first_king()
{
    RegisterCreatureAI(boss_dazar);
    RegisterCreatureAI(npc_dazar_minions);
}
