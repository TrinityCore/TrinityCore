#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "temple_of_sethraliss.h"

const Position pos = { };

enum Spells
{
    SPELL_CONSUME_CHARGE = 266512,
    SPELL_CAPACITANCE = 266511,
    //Energy core
    SPELL_ENERGY_CORE_VISUAL = 265977,
    SPELL_SUMMON_ENERGY_CORE = 274006,
    SPELL_ARC = 265986,
    SPELL_GALVANIZE = 266923,
};

enum Events
{
    EVENT_ENERGY_CORE = 1,
    EVENT_CONSUME_CHARGE,
};

//133389
struct boss_galvazzt : public BossAI
{
    boss_galvazzt(Creature* creature) : BossAI(creature, DATA_GALVAZZT) 
    {
        me->RemoveUnitFlag2(UNIT_FLAG2_REGENERATE_POWER);
    }

private:
    uint8 energyCore;

    void Reset() override
    {
        BossAI::Reset();
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 0);
        me->AddAura(AURA_OVERRIDE_POWER_COLOR_OCEAN);
        this->energyCore = 0;
    }

    void EnterCombat(Unit* who) override
    {
        _EnterCombat();
        events.ScheduleEvent(EVENT_ENERGY_CORE, 15s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (me->GetPower(POWER_ENERGY) == 100)
        {
            me->SetPower(POWER_ENERGY, 0);
            me->CastSpell(nullptr, SPELL_CONSUME_CHARGE, false);
        }
        switch (eventId)
        {
        case EVENT_ENERGY_CORE:
            for (uint8 i = 0; i < 3; i++)
            {                
                me->CastSpell(me->GetRandomNearPosition(20.0f), SPELL_SUMMON_ENERGY_CORE, true);
            }
            events.Repeat(15s, 30s);
            break;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->DespawnCreaturesInArea(NPC_ENERGY_CORE, 125.0f);
    }

    void JustDied(Unit* u) override
    {
        _JustDied();
        me->DespawnCreaturesInArea(NPC_ENERGY_CORE, 125.0f);
        if (auto* GalvazztDoor = me->FindNearestGameObject(GO_GALVAZZT_EXIT, 100.0f))
            GalvazztDoor->SetGoState(GO_STATE_ACTIVE);
    }
};

//135445
struct npc_energy_core : public ScriptedAI
{
    npc_energy_core(Creature* c) : ScriptedAI(c) { }

private: 
    uint32 Timer = 0;

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC));
        me->CastSpell(nullptr, SPELL_ENERGY_CORE_VISUAL, true);
        me->CastSpell(nullptr, SPELL_ARC, true);
        me->GetOwnerGUID();
    }

    void Initialize()
    {
        Timer = 0;
    }

    void UpdateAI(uint32 diff) override
    {
        if (Timer <= diff)
        {
            if (Unit* owner = me->GetOwner())
            {
                if (owner->IsInCombat())
                {
                    if (Player* player = me->SelectNearestPlayer(5.0f))
                    {
                        me->CastSpell(player, SPELL_GALVANIZE, true);
                        return;
                    }
                    else
                    {
                        if (Creature* galvazzt = me->FindNearestCreature(NPC_GALVAZZT, 100.0f, true))                            
                            galvazzt->ModifyPower(POWER_ENERGY, +1);
                    }
                }
                Timer = 1000;
            }
        }
        else Timer -= diff;
    }
};

void AddSC_boss_galvazzt()
{
    RegisterCreatureAI(boss_galvazzt);
    RegisterCreatureAI(npc_energy_core);
}
