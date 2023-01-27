#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Vehicle.h"
#include "InstanceScript.h"
#include "operation_mechagon.h"

enum Texts
{
    SAY_AGGRO = 0,
    SAY_AIR_DROP,
    SAY_VENTING_FLAMES,
    SAY_EXPLOSIVE_LEAP,
    SAY_DEATH
};

enum Spells
{
    SPELL_AIR_DROP_DAMAGE_KNOCK = 291930,
    SPELL_JUNK_BOMB_DAMAGE = 291953,
    SPELL_EXPLOSIVE_LEAP_TRIGGER = 291973,
    SPELL_EXPLOSIVE_LEAP_DAMAGE = 292035,
    SPELL_VENTING_FLAMES = 291946,
    SPELL_VENTING_FLAMES_DAMAGE = 291949, // triggered by previous spell already
    SPELL_BLAZING_CHOMP = 294929,
};

enum Events
{
    EVENT_AIR_DROP = 1,
    EVENT_EXPLOSIVE_LEAP,
    EVENT_VENTING_FLAMES,
    EVENT_BLAZING_CHOMP
};

const Position middle_of_the_room = { 583.771f, 245.203f, -333.555f, 1.05f };

//144246
struct boss_kujo : public BossAI
{
    boss_kujo(Creature* creature) : BossAI(creature, DATA_KUJO) { }

    void Reset() override
    {
        BossAI::Reset();
        me->DespawnCreaturesInArea(NPC_FLYING_CLAW);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        if (Creature* wendy = me->FindNearestCreature(NPC_WENDY_COGSWORTH, 300.0f, true))
            wendy->AI()->Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_BLAZING_CHOMP, 3s);
        events.ScheduleEvent(EVENT_AIR_DROP, 5s);
        events.ScheduleEvent(EVENT_VENTING_FLAMES, 15s);
        events.ScheduleEvent(EVENT_EXPLOSIVE_LEAP, 38s);
    }

    void ExecuteEvent(uint32 eventid) override
    {
        switch (eventid)
        {
        case EVENT_EXPLOSIVE_LEAP:
            if (Creature* wendy = me->FindNearestCreature(NPC_WENDY_COGSWORTH, 300.0f, true))
                wendy->AI()->Talk(SAY_EXPLOSIVE_LEAP);

            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f, true))
            {
                me->SetFacingToObject(target);
                me->GetScheduler().Schedule(3s, [this, target](TaskContext context)
                {
                    me->GetMotionMaster()->MoveCharge(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 80.0f, 1, true);
                });
            }
            events.Repeat(20s);
            break;

        case EVENT_AIR_DROP:
            if (Creature* wendy = me->FindNearestCreature(NPC_WENDY_COGSWORTH, 300.0f, true))
                wendy->AI()->Talk(SAY_AIR_DROP);
            me->SummonCreature(NPC_FLYING_CLAW, me->GetRandomPoint(middle_of_the_room, 30.0f));
            events.Repeat(30s);
            break;

        case EVENT_VENTING_FLAMES:
            if (Creature* wendy = me->FindNearestCreature(NPC_WENDY_COGSWORTH, 300.0f, true))
                wendy->AI()->Talk(SAY_VENTING_FLAMES);
            DoCastAOE(SPELL_VENTING_FLAMES);
            events.Repeat(35s);
            break;

        case EVENT_BLAZING_CHOMP:
            DoCastVictim(SPELL_BLAZING_CHOMP, true);
            events.Repeat(60s);
            break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        if (Creature* wendy = me->FindNearestCreature(NPC_WENDY_COGSWORTH, 300.0f, true))
            wendy->AI()->Talk(SAY_DEATH);
        me->DespawnCreaturesInArea(NPC_FLYING_CLAW);
        instance->DoModifyPlayerCurrencies(1553, 35);
    }
};

//150442
struct npc_flying_claw : public ScriptedAI
{
    npc_flying_claw(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {        
        me->GetMotionMaster()->MoveFall();
    }
};

void AddSC_boss_kujo()
{
    RegisterCreatureAI(boss_kujo);
    RegisterCreatureAI(npc_flying_claw);
};
