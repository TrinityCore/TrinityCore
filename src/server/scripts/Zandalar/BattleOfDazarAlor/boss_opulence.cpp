#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Unit.h"
#include "UnitAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "battle_of_dazaralor.h"

enum Texts
{
    SAY_GALLYWIX_OPULENCE_AGGRO = 0,
    SAY_GALLYWIX_STAGE_TWO_BEGINS = 2,
    SAY_GALLYWIX_STAGE_TWO_BEGINS_1 = 1,
    SAY_GALLYWIX_KILL = 3,
    SAY_GALLYWIX_DEATH = 4,
};

enum Spells
{
    PERIODIC_ENERGY_GAIN = 299956,
    HOARD_POWER = 287070,
    COIN_SHOWER_AT = 285014,
    COIN_SHOWER_MISSILE = 285027,
    COIN_SHOWER_DAMAGE = 285046,
    COIN_SWEEP = 287037,
    FOCUSED_ANIMUS_AURA = 284614,
    GREED_AURA = 284943,
    LIQUID_GOLD_AURA = 287072,
    LIQUID_GOLD_CREATE_AT = 287073,
    LIQUID_GOLD_AT_DAMAGE = 287074,
    SPIRITS_OF_GOLD = 285995,
    SURGING_GOLD = 289155,
    WAIL_OF_GREED = 284941,
    WAIL_OF_GREED_MOD_DAMAGE = 284942,
    //Add
    CHANNEL_OF_GOLD = 286026,
    GOLD_BURST_DAMAGE = 286040,
};

enum Events
{
    EVENT_HOARD_POWER = 1,
    EVENT_SPIRITS_OF_GOLD,
    EVENT_LIQUID_GOLD,
    EVENT_COIN_SHOWER,
    EVENT_WAIL_OF_GREED,
    EVENT_COIN_SWEEP,
};

//145261
struct boss_opulence : public BossAI
{
    boss_opulence(Creature* creature) : BossAI(creature, DATA_OPULENCE) { }

    void Reset() override
    {
        BossAI::Reset();
        me->AddUnitState(UNIT_STATE_ROOT);
        me->SetPowerType(POWER_ENERGY);
        me->RemoveAura(PERIODIC_ENERGY_GAIN);
        me->SetPower(POWER_ENERGY, 0);
        me->AddAura(AURA_OVERRIDE_POWER_COLOR_PURPLE);
        me->DespawnCreaturesInArea(NPC_SPIRIT_OF_GOLD, 125.0f);
        me->NearTeleportTo(me->GetHomePosition());
        _JustReachedHome();
        engaged = false;
        me->SetReactState(REACT_AGGRESSIVE);
        /*if (!engaged)
        {
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
            me->SetReactState(REACT_PASSIVE);
        }*/
    }

    void AttackStart(Unit* who) override
    {
        me->SetWalk(false);

        if (me->Attack(who, true))
        DoStartMovement(who);
    }

    void EnterCombat(Unit* /*unit*/) override
    {
        _EnterCombat();        
        DoCast(PERIODIC_ENERGY_GAIN);
        if (Creature* gallywix = me->FindNearestCreature(NPC_TRADE_PRINCE_GALLYWIX, 100.0f, true))
        {
            gallywix->AI()->Talk(SAY_GALLYWIX_STAGE_TWO_BEGINS);
            gallywix->GetScheduler().Schedule(7s, [this, gallywix] (TaskContext context)
            {
                gallywix->AI()->Talk(SAY_GALLYWIX_STAGE_TWO_BEGINS_1);

            }).Schedule(20s, [this, gallywix](TaskContext context)
            {
                gallywix->AI()->Talk(SAY_GALLYWIX_OPULENCE_AGGRO);
            });
        }
        events.ScheduleEvent(EVENT_HOARD_POWER, 1s);
        events.ScheduleEvent(EVENT_COIN_SWEEP, 7s);
        events.ScheduleEvent(EVENT_LIQUID_GOLD, 12s);
        events.ScheduleEvent(EVENT_SPIRITS_OF_GOLD, 17s);
        events.ScheduleEvent(EVENT_COIN_SHOWER, 20s);
        events.ScheduleEvent(EVENT_WAIL_OF_GREED, 23s);
    }

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == HOARD_POWER)        
            return;

        if (spellInfo->Id == SPIRITS_OF_GOLD)        
        {
            for (uint8 i = 0; i < 8; i++)
            me->SummonCreature(NPC_SPIRIT_OF_GOLD, me->GetPosition());
        }
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
        case NPC_SPIRIT_OF_GOLD:
             summon->AI()->DoZoneInCombat();
             break;
        }
    }

    void KilledUnit(Unit* unit) override
    {
        if (unit->IsPlayer())
            if (roll_chance_f(15))
                if (Creature* gallywix = me->FindNearestCreature(NPC_TRADE_PRINCE_GALLYWIX, 100.0f, true))
                    gallywix->AI()->Talk(SAY_GALLYWIX_KILL);
    }

    void JustDied(Unit* unit) override
    {
        _JustDied();
        me->DespawnCreaturesInArea(NPC_SPIRIT_OF_GOLD, 125.0f);
        if (IsMythic())
            instance->DoCompleteAchievement(13299);

        if (Creature* gallywix = me->FindNearestCreature(NPC_TRADE_PRINCE_GALLYWIX, 100.0f, true))
            gallywix->AI()->Talk(SAY_GALLYWIX_DEATH);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override 
    { 
        if (instance->IsWipe())
        {
            me->DespawnCreaturesInArea(NPC_SPIRIT_OF_GOLD, 125.0f);
            me->ForcedDespawn(100, 3s);            
        }
        engaged = true;
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_HOARD_POWER:
        {
            DoCast(HOARD_POWER);
            break;
        }
        case EVENT_COIN_SWEEP:
        {
            DoCastVictim(COIN_SWEEP);
            events.Repeat(10s);
            break;
        }
        case EVENT_LIQUID_GOLD:
        {
            UnitList tarlist;
            SelectTargetList(tarlist, 2, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* tar : tarlist)
            DoCast(tar, LIQUID_GOLD_AURA);
            events.Repeat(15s);
            break;
        }
        case EVENT_COIN_SHOWER:
        {
            UnitList tarlist;
            SelectTargetList(tarlist, 10, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* tar : tarlist)
            DoCast(tar, COIN_SHOWER_MISSILE);
            events.Repeat(20s);
            break;
        }
        case EVENT_SPIRITS_OF_GOLD:
        {
            DoCast(SPIRITS_OF_GOLD);
            events.Repeat(60s);
            break;
        }
        case EVENT_WAIL_OF_GREED:
        {
            DoCastAOE(WAIL_OF_GREED);
            me->AddAura(GREED_AURA);
            events.Repeat(35s);
            break;
        }
        
        default:
            break;
        }
    }
    private:
    bool engaged;
};

void AddSC_boss_opulence()
{
    RegisterCreatureAI(boss_opulence);
}
