/*
* Copyright (C) 2021 ShadowCore
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
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "SpellAuraEffects.h"
#include "castle_nathria.h"

enum Spells
{
    SPELL_GREATER_CASTIGNATION_CAST = 328885,
    SPELL_GREATER_CASTIGNATION_PERI_DUMMY = 328889, //aura
    SPELL_GREATER_CASTIGNATION_CHANNEL = 328894,
    SPELL_GREATER_CASTIGNATION_DAMAGE = 328890,
    ACTION_SPAWN_ADDS = 1,
    SPELL_FIERY_STRIKE = 326455,
    SPELL_BURNING_REMNANTS = 326456,
    EVENT_GAIN_ENERGY = 2,
    SPELL_BLAZING_SURGE = 329518,
    SPELL_BLAZING_SURGE_MISSILE = 329515,
    SPELL_SMOLDERING_REMNANTS_AT_DAMAGE = 328579,
    SPELL_SMOLDERING_REMNANTS_CREATE_AT_ONE = 328658,//20432
    SPELL_SMOLDERING_REMNANTS_CREATE_AT_TWO = 328578, //20427
    SPELL_SMOLDERING_REMNANTS_CREATE_AT_THREE = 328600, //20428
    SPELL_SMOLDERING_PLUMAGE_PERIODIC_TRIGER = 328659, // triggers smoldering remnants
    SPELL_SMOLDERING_PLUMAGE_DAMAGE = 340499,
    SPELL_EMBER_BLAST_CAST = 325877,
    SPELL_LINGERING_EMBERS_PERIODIC = 326430, //triggers from hit by ember blast
    SPELL_SOUL_INFUSION = 325665, //peri dummy
    SPELL_DRAINED_SOUL_DEBUFF = 339251,
    //Heroic
    SPELL_FRAGMENTATION = 336398,
    //Mythic
    SPELL_CLOAK_OF_FLAMES_ABSORB = 343026, //531461
    SPELL_UNLEASHED_PYROCLASM = 343025,
    SPELL_SUMMON_ESSENCE_FONT = 329565,
    SPELL_CRACKED_RESERVOIR = 329539,
    SPELL_ESSENCE_OVERFLOW = 329561,
    SPELL_PHOENIX_FLGIHT = 342474,
    SPELL_REFLECTION_OF_GUILT = 323402,
    ACTION_RESET_ENCOUNTER = 2,
};

//165759
struct boss_sun_kings_salvation : public BossAI
{
    boss_sun_kings_salvation(Creature* creature) : BossAI(creature, DATA_SUN_KINGS_SALVATION) { }

private:
    bool isInProgress;
    bool shadeOfKaelthas45;
    bool shadeOfKaelthas90;
    uint32 Timer;
    uint32 UpdateTimer;
    Map* instanceMap = me->GetMap();

    void Reset() override
    {
        BossAI::Reset();
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 0);
        me->SetReactState(REACT_PASSIVE);
        me->SetFaction(16);
        me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
       // me->setRegeneratingHealth(false);
        isInProgress = false;
        if (Creature* darithos = me->FindNearestCreature(NPC_HIGH_TORTURER_DARITHOS, 100.0f, false))
        {
            darithos->NearTeleportTo(darithos->GetHomePosition());
            darithos->Respawn();
            darithos->AI()->Reset();
        }
        shadeOfKaelthas45 = false;
        shadeOfKaelthas90 = false;
        Timer = 0;
        UpdateTimer = 0;
        me->SetFullHealth();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
        case ACTION_SPAWN_ADDS:
            me->GetScheduler().Schedule(1s, [this](TaskContext context)
            {
                if (Creature* shadeofKaelthas = me->FindNearestCreature(NPC_SHADE_OF_KAELTHAS, 100.0f, true))
                    return;

                me->SummonCreature(NPC_ROCKBOUND_VANQUISHER, -2212.901f, 6384.651f, 4367.636f, TEMPSUMMON_MANUAL_DESPAWN);
                for (uint8 i = 0; i < 2; i++)
                {
                    me->SummonCreature(NPC_BLEAKWING_ASSASIN, -2258.140f, 6344.804f, 4367.202f, 1.806f, TEMPSUMMON_MANUAL_DESPAWN);
                }
                for (uint8 i = 0; i < 2; i++)
                {
                    me->SummonCreature(NPC_BLEAKWING_ASSASIN, -2256.673f, 6424.470f, 4367.202f, 4.708f, TEMPSUMMON_MANUAL_DESPAWN);
                }
                for (uint8 i = 0; i < urand(3, 5); i++)
                {
                    me->SummonCreature(NPC_VILE_OCCULTIST, -2212.901f, 6384.651f, 4367.636f, TEMPSUMMON_MANUAL_DESPAWN);
                }
                for (uint8 i = 0; i < 8; i++)
                {
                    me->SummonCreature(NPC_PESTERING_FIEND, me->GetRandomPoint(Position(-2247.565f, 6384.229f, 4367.202f, 3.172f), 15.0f), TEMPSUMMON_MANUAL_DESPAWN);
                }
                for (uint8 i = 0; i < urand(1, 3); i++)
                {
                    me->SummonCreature(NPC_SOUL_INFUSER, me->GetRandomPoint(Position(-2207.122f, 6436.489f, 4367.776f, 3.803f), 15.0f), TEMPSUMMON_MANUAL_DESPAWN);
                }
                for (uint8 i = 0; i < urand(1, 3); i++)
                {
                    me->SummonCreature(NPC_SOUL_INFUSER, me->GetRandomPoint(Position(-2203.518f, 6328.727f, 4367.776f, 2.177f), 15.0f), TEMPSUMMON_MANUAL_DESPAWN);
                }
                if (!me->HasUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE)))
                    context.Repeat(60s);
            });
            break;

        case ACTION_RESET_ENCOUNTER:
            _JustReachedHome();
            me->RemoveAllAreaTriggers();
            me->DespawnCreaturesInArea(NPC_VILE_OCCULTIST, 200.0f);
            me->DespawnCreaturesInArea(NPC_ROCKBOUND_VANQUISHER, 200.0f);
            me->DespawnCreaturesInArea(NPC_BLEAKWING_ASSASIN, 200.0f);
            me->DespawnCreaturesInArea(NPC_PESTERING_FIEND, 200.0f);
            me->DespawnCreaturesInArea(NPC_SOUL_INFUSER, 200.0f);
            me->DespawnCreaturesInArea(NPC_SHADE_OF_KAELTHAS, 200.0f);
            me->DespawnCreaturesInArea(NPC_REBORN_PHOENIX, 200.0f);           
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlags(UNIT_FLAG_PVP_ATTACKABLE);
            me->SetFaction(16);
            me->SetFullHealth();
            break;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summon->AI()->DoZoneInCombat();
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    { 
        switch (summon->GetEntry())
        {
        case NPC_VILE_OCCULTIST:
            summon->CastSpell(nullptr, SPELL_SUMMON_ESSENCE_FONT, true);
            break;

        case NPC_PESTERING_FIEND:
            if (IsHeroic() || IsMythic())
                summon->CastSpell(nullptr, SPELL_FRAGMENTATION, true);
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (UpdateTimer <= diff)
        {
            Map::PlayerList const& playerList = instanceMap->GetPlayers();
            if (playerList.isEmpty())
                me->AI()->EnterEvadeMode(EvadeReason::EVADE_REASON_NO_HOSTILES);

            if (me->GetHealthPct() == 45 && !shadeOfKaelthas45)
            {
                shadeOfKaelthas45 = true;
                me->SummonCreature(NPC_SHADE_OF_KAELTHAS, -2251.194f, 6384.164f, 4367.203f, TEMPSUMMON_MANUAL_DESPAWN);
            }

            if (me->GetHealthPct() == 90 && !shadeOfKaelthas90)
            {
                shadeOfKaelthas90 = true;
                me->SummonCreature(NPC_SHADE_OF_KAELTHAS, -2251.194f, 6384.164f, 4367.203f, TEMPSUMMON_MANUAL_DESPAWN);
            }

            if (Timer <= diff && IsMythic() && !me->HasAura(SPELL_CLOAK_OF_FLAMES_ABSORB) && me->IsInCombat())
            {
                me->CastCustomSpell(SPELL_CLOAK_OF_FLAMES_ABSORB, SPELLVALUE_BASE_POINT0, 531461);
                me->CastSpell(nullptr, SPELL_UNLEASHED_PYROCLASM, false);
                me->GetScheduler().Schedule(5900ms, [this](TaskContext /*context*/)
                {
                    if (!me)
                        return;

                    if (me->HasAura(SPELL_CLOAK_OF_FLAMES_ABSORB) && me->HasUnitState(UNIT_STATE_CASTING))
                        me->InterruptSpell(CurrentSpellTypes::CURRENT_GENERIC_SPELL, false, true);
                });
                Timer = 30000;
            }
            else
                Timer -= diff;

            UpdateTimer = 1000;
        }
        else
            UpdateTimer -= diff;
    }

    void EnterEvadeMode(EvadeReason /*why**/) override
    {
        me->AI()->DoAction(ACTION_RESET_ENCOUNTER);
        _DespawnAtEvade();
    };
};

//168973
struct npc_high_torturer_darithos : public ScriptedAI
{
    npc_high_torturer_darithos(Creature* c) : ScriptedAI(c) { }

    void EnterCombat(Unit* /*who*/) override
    {
        if (Creature* kaelthas = me->FindNearestCreature(NPC_SUN_KING_SALVATION, 100.0f, true))
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, kaelthas);
            kaelthas->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
            kaelthas->SetInCombatWithZone();
            int32 GetKaelHitPoints = std::max<uint32>(kaelthas->CountPctFromMaxHealth(int32(80)), 1);
            kaelthas->DealDamage(kaelthas, GetKaelHitPoints, 0, SPELL_DIRECT_DAMAGE, SPELL_SCHOOL_MASK_FIRE, 0, true);
            kaelthas->AI()->DoAction(ACTION_SPAWN_ADDS);
            kaelthas->SetFaction(35);
        }
        std::list<Creature*> addsList;
        me->GetCreatureListWithEntryInGrid(addsList, NPC_VILE_OCCULTIST, 150.0f);
        for (Creature* occultists : addsList)
        {
            occultists->AI()->DoZoneInCombat();
        }
        events.ScheduleEvent(SPELL_GREATER_CASTIGNATION_CAST, 6s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_GREATER_CASTIGNATION_CAST:
            me->CastSpell(nullptr, SPELL_GREATER_CASTIGNATION_CAST, false);
            break;
        }
    }

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case SPELL_GREATER_CASTIGNATION_CAST:
            break;
        }
    };

    void JustReachedHome() override
    {
        if (Creature* kaelthas = me->FindNearestCreature(NPC_SUN_KING_SALVATION, 100.0f, true))
            kaelthas->AI()->EnterEvadeMode(EvadeReason::EVADE_REASON_NO_HOSTILES);
    }
};

//165805
struct npc_shade_of_kaelthas : public ScriptedAI
{
    npc_shade_of_kaelthas(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 0);
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetObjectScale(1.5f);
        for (uint8 i = 0; i < 2; i++)
        {
            me->SummonCreature(NPC_REBORN_PHOENIX, me->GetRandomNearPosition(30.0f), TEMPSUMMON_MANUAL_DESPAWN);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
        case NPC_REBORN_PHOENIX:
            summon->AddAura(SPELL_SMOLDERING_PLUMAGE_PERIODIC_TRIGER);
            summon->SetWalk(true);
            summon->AI()->DoZoneInCombat();
            break;
        }
    }

    void EnterCombat(Unit* /*who*/) override
    {
        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        events.ScheduleEvent(EVENT_GAIN_ENERGY, 1s);
        events.ScheduleEvent(SPELL_FIERY_STRIKE, 3s);
        events.ScheduleEvent(SPELL_EMBER_BLAST_CAST, 10s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (me->GetPower(POWER_ENERGY) == 100)
        {
            me->SetPower(POWER_ENERGY, 0);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_BLAZING_SURGE, false);
                me->GetScheduler().Schedule(3100ms, [this, target](TaskContext /*context*/)
                {
                    if (!target)
                        return;

                    for (uint8 i = 0; i < 3; i++)
                    {
                        me->CastSpell(target->GetRandomNearPosition(urand(1, 10)), SPELL_BLAZING_SURGE_MISSILE, true);
                    }
                });
            }
        }
        switch (eventId)
        {
        case EVENT_GAIN_ENERGY:
            me->ModifyPower(POWER_ENERGY, +5);
            events.Repeat(1s);
            break;

        case SPELL_FIERY_STRIKE:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                me->SetFacingToObject(target);
                me->CastSpell(target, SPELL_FIERY_STRIKE, false);
            }
            events.Repeat(15s, 20s);
            break;

        case SPELL_EMBER_BLAST_CAST:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                me->CastSpell(target, SPELL_EMBER_BLAST_CAST, false);
            break;
        }
    }

    void JustDied(Unit* /*victim*/) override
    {
        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        if (!IsMythic())
        {
            std::list<Creature*> phoenixList;
            me->GetCreatureListWithEntryInGrid(phoenixList, NPC_REBORN_PHOENIX, 200.0f);
            for (Creature* phoenixs : phoenixList)
            {
                phoenixs->DespawnOrUnsummon();
            }
        }
    }
};

//328658,328578,328600
struct at_smoldering_remnants : public AreaTriggerAI
{
    at_smoldering_remnants(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnCreate() override
    {
        at->SetDuration(360000);
    }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (at->GetCaster())
            at->GetCaster()->AddAura(SPELL_SMOLDERING_REMNANTS_AT_DAMAGE, target);
    }

    void OnUnitExit(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (target->HasAura(SPELL_SMOLDERING_REMNANTS_AT_DAMAGE))
            target->RemoveAura(SPELL_SMOLDERING_REMNANTS_AT_DAMAGE);
    }
};

//340499
class spell_smoldering_plumage : public SpellScript
{
    PrepareSpellScript(spell_smoldering_plumage);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove(GetCaster());
    }

    void Register() override
    {
         OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_smoldering_plumage::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

//328659
class aura_smoldering_plumage : public AuraScript
{
    PrepareAuraScript(aura_smoldering_plumage);

    void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (!GetCaster() || !GetCaster()->HasAura(328659))
            return;

        GetCaster()->GetScheduler().Schedule(100ms, [this](TaskContext context)
        {
            GetCaster()->CastSpell(nullptr, SPELL_SMOLDERING_REMNANTS_CREATE_AT_ONE, true);

            if (!GetCaster() || !GetCaster()->HasAura(328659))
                return;

            context.Repeat(2500ms);
        });
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(aura_smoldering_plumage::AfterApply, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_sun_kings_salvation()
{
    RegisterCreatureAI(boss_sun_kings_salvation);
    RegisterCreatureAI(npc_high_torturer_darithos);
    RegisterCreatureAI(npc_shade_of_kaelthas);
    RegisterAreaTriggerAI(at_smoldering_remnants);
    RegisterSpellScript(spell_smoldering_plumage);
    RegisterAuraScript(aura_smoldering_plumage);
}
