/*
* Copyright 2021 ShadowCore
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "ScriptMgr.h"
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "SpellAuraEffects.h"
#include "spires_of_ascension.h"

enum KintaraAzules
{
    SPELL_LIFE_LINK = 345561,
    SPELL_OVERHEAD_SLASH = 320966,
    SPELL_DARK_LANCE = 327481,
    SPELL_CHARGED_SPEAR_MISSILE = 321009,
    SPELL_CHARGED_SPEAR_DAMAGE = 321034,
    SPELL_IONIZED_PLASTMA_CREATE_AT = 324663,
    SPELL_IONIZED_PLASMA_AT_DAMAGE = 324662,
    EVENT_ENERGY_GAIN,
    //
    SPELL_INSIDIOUS_VENOM = 317661,
    SPELL_ATTENUATED_BARRAGE = 324368,
    SPELL_ATTENUATED_BARRAGE_CREATE_AT = 324369,
    SPELL_ATTENUATED_BARRAGE_DAMAGE = 324370,

};

//162059
struct boss_kintara : public BossAI
{
    boss_kintara(Creature* creature) : BossAI(creature, DATA_KINTARA) { }

    void Reset() override
    {
        BossAI::Reset();
        me->AddAura(SPELL_LIFE_LINK);
        if (Creature* azules = me->FindNearestCreature(NPC_AZULES, 100.0f, true))
        {
            azules->AddAura(SPELL_LIFE_LINK);
            me->CastSpell(azules, SPELL_LIFE_LINK, true);
        }
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 0);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        Talk(0);
        events.ScheduleEvent(EVENT_ENERGY_GAIN, 1s);
        events.ScheduleEvent(SPELL_OVERHEAD_SLASH, 5s);
        events.ScheduleEvent(SPELL_DARK_LANCE, 5s);
        events.ScheduleEvent(SPELL_CHARGED_SPEAR_MISSILE, 5s);
        if (Creature* azules = me->FindNearestCreature(NPC_AZULES, 100.0f, true))
        {
            azules->NearTeleportTo(me->GetPosition());
            azules->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
            azules->AI()->DoZoneInCombat();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, azules);
        }
    }

    void DamageTaken(Unit* target, uint32& damage) override
    {
        _DamageTaken(target, damage);
        TransferDamage(NPC_AZULES, damage);
    }

    void TransferDamage(uint32 entry, uint32& damage)
    {
        if (Creature* target = me->FindNearestCreature(entry, 100.0f, true))
        {
            uint64 health = target->GetHealth() - damage;
            target->SetHealth(health > 0 ? health : 0);

            if (health <= 0)
                target->setDeathState(JUST_DIED);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {   
        case EVENT_ENERGY_GAIN:
            me->ModifyPower(POWER_ENERGY, + 1);
            events.Repeat(500ms);
            break;
        case SPELL_OVERHEAD_SLASH:
            DoCastVictim(SPELL_OVERHEAD_SLASH, false);
            events.Repeat(15s, 18s);
            break;

        case SPELL_DARK_LANCE:
            DoCastRandom(SPELL_DARK_LANCE, 100.0f, false);
            events.Repeat(20s, 23s);
            break;

        case SPELL_CHARGED_SPEAR_MISSILE:
            DoCastRandom(SPELL_CHARGED_SPEAR_MISSILE, 100.0f, false);
            events.Repeat(24s, 27s);
            break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override 
    { 
        switch (spellInfo->Id)
        {
        case SPELL_CHARGED_SPEAR_MISSILE:
            me->CastSpell(target->GetPosition(), SPELL_IONIZED_PLASTMA_CREATE_AT, true);
            break;
        }
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        if (Creature* azules = me->FindNearestCreature(NPC_AZULES, 100.0f, false))
        {
            azules->Respawn();
            azules->NearTeleportTo(azules->GetHomePosition());
        }
        if (Creature* azules = me->FindNearestCreature(NPC_AZULES, 100.0f, true))
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, azules);
    }

    void JustDied(Unit* /*who*/) override
    {
        _JustDied();
        Talk(1);
        if (Creature* azules = me->FindNearestCreature(NPC_AZULES, 100.0f, true))
        {
            azules->KillSelf();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, azules);
        }
    }
};

//23887
struct at_ionized_plasma : public AreaTriggerAI
{
    at_ionized_plasma(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        if (!unit->HasAura(SPELL_IONIZED_PLASMA_AT_DAMAGE))
            at->GetCaster()->AddAura(SPELL_IONIZED_PLASMA_AT_DAMAGE, unit);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (unit->HasAura(SPELL_IONIZED_PLASMA_AT_DAMAGE))
            unit->RemoveAura(SPELL_IONIZED_PLASMA_AT_DAMAGE);
    }
};

//163077
struct npc_azules : public ScriptedAI
{
    npc_azules(Creature* c) : ScriptedAI(c) { }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(SPELL_INSIDIOUS_VENOM, 5s);
        events.ScheduleEvent(SPELL_ATTENUATED_BARRAGE, 10s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {   
        case SPELL_INSIDIOUS_VENOM:
            DoCastVictim(SPELL_INSIDIOUS_VENOM, false);
            events.Repeat(15s, 18s);
            break;

        case SPELL_ATTENUATED_BARRAGE:
            me->CastSpell(nullptr, SPELL_ATTENUATED_BARRAGE, false);
            events.Repeat(20s, 23s);
            break;
        }
    }

    void OnSpellFinished(SpellInfo const* spellInfo)
    {
        switch (spellInfo->Id)
        {
        case SPELL_ATTENUATED_BARRAGE:
            for (uint8 i = 0; i < 3; i++)
            {
                me->CastSpell(me->GetRandomNearPosition(10.0f), SPELL_ATTENUATED_BARRAGE_CREATE_AT, true);
            }
            break;
        }
    }
};

//23839
struct at_attenuated_barrage : public AreaTriggerAI
{
    at_attenuated_barrage(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnInitialize() override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        Position movePos = caster->GetPosition();
        at->MovePosition(movePos, 30.0f, 0.0f);
        //at->SetDestination(movePos, 3500);
    }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (at->GetCaster())
            at->GetCaster()->CastSpell(target, SPELL_ATTENUATED_BARRAGE_DAMAGE, true);
    }
};

void AddSC_boss_kintara()
{
    RegisterCreatureAI(boss_kintara);
    RegisterAreaTriggerAI(at_ionized_plasma);
    RegisterCreatureAI(npc_azules);
    RegisterAreaTriggerAI(at_attenuated_barrage);
}
