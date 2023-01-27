#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "scarlet_halls.h"

enum Spells
{
    SPELL_BOOK_BURNER     = 113364,
    SPELL_BURNING_BOOKS   = 113616, // Aura stay for 30 seconds
    SPELL_FIREBALL_VOLLEY = 113691,
    SPELL_DRAGON_BREATH   = 113641,
    SPELL_PYROBLAST       = 113690,
    SPELL_QUICKENED_MIND  = 113682,
    SPELL_TELEPORT        = 113626
};

enum Talk
{
    SAY_INTRO           = 0, // Everything must burn. None shall know of the Scarlet Crusade's shame!
    SAY_AGGRO           = 1, // You, too, shall be charred to ash!
    SAY_DRAGON_BREATH_1 = 2, // Breath of the Dragon!
    SAY_DRAGON_BREATH_2 = 3, // Purged by fire!
    SAY_KILLER_1        = 4, // Burn, BURN!
    SAY_KILLER_2        = 5, // Die in a fire!
    SAY_DEATH           = 6  // My fire...has gone out.
};

enum Events
{
    EVENT_BURNING_BOOKS = 1,
    EVENT_TELEPORT,
    EVENT_DRAGON_BREATH,
    EVENT_QUICK_MIND,
    EVENT_FIREBALL,
    EVENT_PYROBLAST,
    EVENT_DRAGON_BREATH_INTRO
};

//59150
struct boss_flameweaver_koegler : public BossAI
{
    boss_flameweaver_koegler(Creature* creature) : BossAI(creature, DATA_FLAMEWEAVER_KOEGLER) { }

private:
    bool intro;

    void Reset() override
    {
        BossAI::Reset();
        intro = false;
        me->SetReactState(REACT_DEFENSIVE);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_BURNING_BOOKS, 30000);
        events.ScheduleEvent(EVENT_QUICK_MIND, 15000);
        events.ScheduleEvent(EVENT_TELEPORT, 38000);
        events.ScheduleEvent(EVENT_FIREBALL, 5000);
        events.ScheduleEvent(EVENT_PYROBLAST, 20000);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer() && roll_chance_f(15))
            Talk(RAND(SAY_KILLER_1, SAY_KILLER_2));
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who && who->GetTypeId() == TYPEID_PLAYER && me->IsValidAttackTarget(who))

        if (!intro && me->IsWithinDistInMap(who, 25))
        {
            intro = true;
            Talk(SAY_INTRO);
            ScriptedAI::MoveInLineOfSight(who);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_BURNING_BOOKS:
            DoCast(SPELL_BOOK_BURNER);
            events.ScheduleEvent(EVENT_BURNING_BOOKS, 30000); // should be 30sec after the first one
            break;
        case EVENT_TELEPORT:
            DoCast(SPELL_TELEPORT);
            me->SetTarget(ObjectGuid::Empty);
            me->StopMoving();
            events.ScheduleEvent(EVENT_TELEPORT, 45000);
            events.ScheduleEvent(EVENT_DRAGON_BREATH, 1000);
            break;
        case EVENT_DRAGON_BREATH:
            Talk(RAND(SAY_DRAGON_BREATH_1, SAY_DRAGON_BREATH_2));
            DoCast(SPELL_DRAGON_BREATH);
            events.ScheduleEvent(EVENT_QUICK_MIND, 11000);
            break;
        case EVENT_QUICK_MIND:
            AttackStart(me->GetVictim());
            me->SetReactState(REACT_AGGRESSIVE);
            DoCast(me, SPELL_QUICKENED_MIND);
            break;
        case EVENT_FIREBALL:
            DoCastVictim(SPELL_FIREBALL_VOLLEY);
            events.ScheduleEvent(EVENT_FIREBALL, 15000);
            break;
        case EVENT_PYROBLAST:
            DoCastVictim(SPELL_PYROBLAST);
            events.ScheduleEvent(EVENT_PYROBLAST, urand(25000, 35000));
            break;
        }
    }
};

//59155
struct npc_book_case : public ScriptedAI
{
    npc_book_case(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override { }

    void EnterCombat(Unit* /*who*/) override { }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_BOOK_BURNER)
            DoCast(me, SPELL_BURNING_BOOKS);
    }
};

void AddSC_flameweaver_koegler()
{
    RegisterCreatureAI(boss_flameweaver_koegler);
    RegisterCreatureAI(npc_book_case);
}
