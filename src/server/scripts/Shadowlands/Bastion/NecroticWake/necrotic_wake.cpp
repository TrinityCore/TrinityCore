#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "necrotic_wake.h"

enum Spells
{
    SPELL_ANIMA_MISSILE = 335159,
    SPELL_ANIMA_CREATE_AT = 335160,
    SPELL_ANIMA_BUFF = 335161,
    SPELL_COLLAPSED_GOLIATH = 335155,
};

//171750
struct npc_malfunctioning_goliath : public ScriptedAI
{
    npc_malfunctioning_goliath(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
    }

    void OnSpellClick(Unit* clicker, bool& result) override
    {
        me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
        me->RemoveAura(SPELL_COLLAPSED_GOLIATH);
        for (uint16 i = 0; i < 16; i++)
        {
            me->CastSpell(me->GetRandomNearPosition(15.0f), SPELL_ANIMA_MISSILE, true);
        }
    }
};

//25432
struct at_anima_exhaust : public AreaTriggerAI
{
    at_anima_exhaust(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        if (!unit->HasAura(SPELL_ANIMA_BUFF))
            at->GetCaster()->AddAura(SPELL_ANIMA_BUFF, unit);
    }
};

void AddSC_necrotic_wake()
{
    RegisterCreatureAI(npc_malfunctioning_goliath);
    RegisterAreaTriggerAI(at_anima_exhaust);
}