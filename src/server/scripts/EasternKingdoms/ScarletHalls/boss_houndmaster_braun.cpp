#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "scarlet_halls.h"

enum Spells
{
    SPELL_BLOODY_RAGE    = 116140,
    SPELL_CALL_DOG       = 114259, // will be done soon
    SPELL_DEATH_BLOSSOM  = 114242,
    SPELL_BLOSSOM_JUMP   = 114241,
    SPELL_PIERCING_THROW = 114004,
    SPELL_THROW_LINKED   = 114020,
};

enum Texts
{
    SAY_AGGRO1           = 0,
    SAY_AGGRO2           = 1,
    SAY_CALL_DOG1        = 2,
    SAY_CALL_DOG2        = 3,
    SAY_BLOSSOM1         = 4,
    SAY_BLOSSOM2         = 5,
    SAY_MESS1            = 6,
    SAY_MESS2            = 7,
    SAY_RAGE1            = 8,
    SAY_RAGE2            = 9,
    SAY_KILL_DOG1        = 10,
    SAY_KILL_DOG2        = 11,
    SAY_KILL_DOG3        = 12,
    SAY_KILLER           = 13,
    SAY_RESET            = 14,
    SAY_DEATH            = 15,
};

enum Events
{
    EVENT_RAGE = 1,
    EVENT_DOG,
    EVENT_BLOSSOM,
    EVENT_THROW,
    EVENT_CLOSE_GATE,
};

enum Actions
{
    ACTION_ATTACK_BRAUN = 1,
};

Position const PosObedientHound[3] =
{
    { 991.761f, 519.f,    13.488f, 6.262798f },
    { 991.724f, 517.511f, 13.488f, 6.262798f },
    { 991.894f, 515.835f, 13.488f, 6.262798f },
};

//59303
struct boss_houndmaster_braun : public BossAI
{
    boss_houndmaster_braun(Creature* creature) : BossAI(creature, DATA_HOUNDMASTER_BRAUN) { }

private:
    bool wave1;
    bool wave2;
    bool wave3;
    bool wave4;
    bool enraged;
    bool releasedogs;

    void Reset() override
    {
        BossAI::Reset();
        me->SetReactState(REACT_DEFENSIVE);
        wave1 = false;
        wave2 = false;
        wave3 = false;
        wave4 = false;
        enraged = false;
        releasedogs = false;
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        events.ScheduleEvent(EVENT_THROW, 18000);
        events.ScheduleEvent(EVENT_BLOSSOM, 15000);
        events.ScheduleEvent(EVENT_CLOSE_GATE, 3000);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void KilledUnit(Unit* victim) override { }

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override // percent 90/80/70/60 will be done by Call Dogs (soon)
    {
        if(!wave1 && !me->IsNonMeleeSpellCast(false) && HealthBelowPct(90))
            wave1 = true;

        if(!wave2 && !me->IsNonMeleeSpellCast(false) && HealthBelowPct(80))
            wave2 = true;

        if(!wave3 && !me->IsNonMeleeSpellCast(false) && HealthBelowPct(70))         
            wave3 = true;

        if(!wave4 && !me->IsNonMeleeSpellCast(false) && HealthBelowPct(60))       
            wave4 = true;
              
        if(!enraged && !me->IsNonMeleeSpellCast(false) && HealthBelowPct(50))
        {
            enraged = true;
            DoCast(me, SPELL_BLOODY_RAGE);
        }

        if(!releasedogs && !me->IsNonMeleeSpellCast(false) && HealthBelowPct(10))
        {
            releasedogs = true;
            ReleaseDogs();
        }
    }

    void CloseGate() // summon 3 Dogs for the last gate after combat start
    {
        for (uint8 i = 0; i < 3; ++i)
        me->SummonCreature(NPC_OBEDIENT_HOUND, PosObedientHound[i], TEMPSUMMON_DEAD_DESPAWN, 0);
    }

    void ReleaseDogs()
    {
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch(eventId)
        {
        case EVENT_CLOSE_GATE:
             CloseGate();
             break;
        case EVENT_THROW:
             DoCast(SPELL_PIERCING_THROW);
             events.ScheduleEvent(EVENT_THROW, 28000);
             break;
        case EVENT_BLOSSOM:
             if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40, true))
             {
                 DoCast(target, SPELL_BLOSSOM_JUMP);
                 DoCastAOE(SPELL_DEATH_BLOSSOM);
                 events.ScheduleEvent(EVENT_BLOSSOM, 25000);
             }
             break;           
        }      
    }
};

//59309
struct npc_obedient_hound : public ScriptedAI
{
    npc_obedient_hound(Creature* creature) : ScriptedAI(creature)
    {
        me->ApplySpellImmune(0, IMMUNITY_ID, 114056, true);
    }

    void Reset()
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* /*summoner*/)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void DoAction(int32 const param)
    {
        switch (param)
        {
        case ACTION_ATTACK_BRAUN:
            if (Creature* braun = me->FindNearestCreature(NPC_HOUNDMASTER_BRAUN, 150, true))
                me->Attack(braun, true);
            break;
        }
    }
};

void AddSC_houndmaster_braun()
{
    RegisterCreatureAI(boss_houndmaster_braun);
    RegisterCreatureAI(npc_obedient_hound);
}
