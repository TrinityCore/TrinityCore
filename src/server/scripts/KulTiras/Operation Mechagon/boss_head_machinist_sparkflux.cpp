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
};

enum Spells
{
    SPELL_PERIODIC_ENERGY_GAIN = 295065,
    SPELL_HIDDEN_FLAME_CANNON_PERIODIC = 285443,
    SPELL_HIDDEN_FLAME_CANNON_APPLY_AT = 285437,
    SPELL_ROARING_FLAME_MISSILE = 294867,
    SPELL_DISCOM_MISSILE = 285454,
    SPELL_SELF_TRIMMING_HEDGE_DAMAGE = 294954,
};

enum Events
{
    EVENT_HIDDEN_FLAME_CANNON = 1,
    EVENT_PLANTS, //npc 152033
    EVENT_DISCOM,
    EVENT_HEDGE
};

//144248
struct boss_head_machinist_sparkflux : public BossAI
{
    boss_head_machinist_sparkflux(Creature* creature) : BossAI(creature, DATA_HEAD_MACHINIST_SPARKFLUX) { }

    void Reset() override
    {
        BossAI::Reset();
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        DoCastSelf(SPELL_PERIODIC_ENERGY_GAIN);
    }

    void ExecuteEvent(uint32 eventid) override
    {
        if (me->GetPower(POWER_ENERGY) == 100)
        {
            me->ModifyPower(POWER_ENERGY, -100);
            events.ScheduleEvent(EVENT_HIDDEN_FLAME_CANNON, 1s);
        }

        switch (eventid)
        {
        case EVENT_HIDDEN_FLAME_CANNON:
            break;

        case EVENT_PLANTS:
            break;

        case EVENT_DISCOM:
            DoCastRandom(SPELL_DISCOM_MISSILE, 100.0f, true);
            events.Repeat(20s);
            break;

        case EVENT_HEDGE:
            break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->DoModifyPlayerCurrencies(1553, 35);
    }
};

void AddSC_boss_machinists_garden()
{
    RegisterCreatureAI(boss_head_machinist_sparkflux);
};
