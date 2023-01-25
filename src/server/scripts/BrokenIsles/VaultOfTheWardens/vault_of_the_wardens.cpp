#include "ScriptMgr.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "vault_of_the_wardens.h"

enum Spells
{
    SPELL_VEILED_IN_SHADOW = 192750,
    SPELL_VEILED_IN_SHADOW_BOSS = 204461,
    SPELL_REVEALED = 192752,
    SPELL_ELUNES_LIGHT = 197890,
    SPELL_ELUNES_LIGHT_2 = 192656,
    SPELL_ELUNES_LIGHT_AURA = 197941,
    SPELL_INTERACT_DUMMY = 68742,
};

//AT : 9668
//Spell : 197941
struct at_elunes_light : AreaTriggerAI
{
    at_elunes_light(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;
        if (!unit->IsAlive())
            return;
        if (!unit->IsPlayer())
        {
            caster->CastSpell(unit, SPELL_REVEALED, true);
            unit->RemoveAurasDueToSpell(SPELL_VEILED_IN_SHADOW);
            unit->RemoveAurasDueToSpell(SPELL_VEILED_IN_SHADOW_BOSS);
            unit->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
        }
    }

    void OnUnitExit(Unit* /*unit*/) override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;
    }
};

struct npc_glowing_sentry_120300 : public ScriptedAI
{
    npc_glowing_sentry_120300(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void Initialize()
    {
        SetCombatMovement(false);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;
        DoStopAttack();
    }
};


void AddSC_vault_of_the_wardens()
{
    RegisterAreaTriggerAI(at_elunes_light);
    RegisterCreatureAI(npc_glowing_sentry_120300);
}
