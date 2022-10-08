/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "shrine_of_the_storm.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"

enum Texts
{
    TALK_REXXAR_TALK_01 = 0,
    TALK_REXXAR_TALK_02 = 1,
    TALK_REXXAR_TALK_03 = 2,

    YELL_STORMSONG_01 = 0,
    YELL_STORMSONG_02 = 1,

    TALK_BROTHER_PIKE_TALK_01 = 0,
};

enum Spells
{
    SPELL_BURST                 = 243237,
    SPELL_REQUIEM_OF_THE_ABYSS  = 274364,
    SPELL_SPLASHING_WATER       = 241680,
    SPELL_EMERGE_VISUAL         = 274948,
    SPELL_WATER_RITUAL          = 274341,
    SPELL_SLICING_HURRICANE     = 276286,
};

// 139971
struct npc_rexxar : public ScriptedAI
{
    npc_rexxar(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
        {
            if (player->GetDistance(me) < 8.0f && instance && !instance->GetData(DATA_INSTANCE_ENTER))
            {
                instance->SetData(DATA_INSTANCE_ENTER, 1);
                Talk(TALK_REXXAR_TALK_01);
                me->GetScheduler().Schedule(7s, [this](TaskContext context) { GetContextCreature()->AI()->Talk(TALK_REXXAR_TALK_02); });
                me->GetScheduler().Schedule(14s, [this](TaskContext context) { GetContextCreature()->AI()->Talk(TALK_REXXAR_TALK_03); });
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);
    }
};

// 139970
struct npc_brother_pike : public ScriptedAI
{
    npc_brother_pike(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
        {
            if (player->GetDistance(me) < 8.0f && instance && !instance->GetData(DATA_INSTANCE_ENTER))
            {
                instance->SetData(DATA_INSTANCE_ENTER, 1);
                Talk(TALK_BROTHER_PIKE_TALK_01);
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);
    }
};


// 240443 - Burst
class spell_burst_sots : public SpellScriptLoader
{
public:
    spell_burst_sots() : SpellScriptLoader("spell_burst_sots") { }

    class spell_burst_sots_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_burst_sots_AuraScript);

        void OnTick(AuraEffect const* aurEff)
        {
            GetTarget()->CastSpell(GetTarget(), SPELL_BURST, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_burst_sots_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_burst_sots_AuraScript();
    }
};

// 139737
struct npc_lord_stormsong : public ScriptedAI
{
    npc_lord_stormsong(Creature* creature) : ScriptedAI(creature)
    {
        introDone = false;
    }

    bool introDone;

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        DoCast(SPELL_WATER_RITUAL);
    }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
        {
            if (!introDone && player->GetDistance(me) < 40.0f && instance)
            {
                introDone = true;
                me->RemoveAurasDueToSpell(SPELL_WATER_RITUAL);
                me->SetFacingTo(0.1939797f);
                Talk(YELL_STORMSONG_01);
                me->GetScheduler().Schedule(6s, [this](TaskContext context) { GetContextCreature()->AI()->Talk(YELL_STORMSONG_02); });
                me->GetScheduler().Schedule(13s, [this](TaskContext context)
                {
                    GetContextCreature()->AI()->DoCast(SPELL_WATER_RITUAL);
                    GetContextCreature()->AI()->DoCast(SPELL_REQUIEM_OF_THE_ABYSS);
                });
                me->GetScheduler().Schedule(18s, [this](TaskContext context)
                {
                    if (Creature* aqusirr = GetContextCreature()->FindNearestCreature(NPC_AQUSIRR, 100.0f))
                    {
                        aqusirr->SetReactState(REACT_AGGRESSIVE);
                        aqusirr->SetVisible(true);
                        aqusirr->AI()->DoCast(SPELL_EMERGE_VISUAL);
                    }
                });

                me->GetScheduler().Schedule(20s, [this](TaskContext context)
                {
                    GetContextCreature()->AI()->DoCast(SPELL_SPLASHING_WATER);
                    GetContextCreature()->DespawnOrUnsummon(2500);
                });
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);
    }
};

// Spell 276282 - Slicing Hurricane
// AT 19019
struct at_slicing_hurricane : AreaTriggerAI
{
    at_slicing_hurricane(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnInitialize() override
    {
        at->SetPeriodicProcTimer(2000);
    }

    void OnPeriodicProc() override
    {
        if (Unit* caster = at->GetCaster())
            for (ObjectGuid guid : at->GetInsideUnits())
                if (Unit* unit = ObjectAccessor::GetUnit(*at, guid))
                    if (caster->IsValidAttackTarget(unit))
                        unit->CastSpell(unit, SPELL_SLICING_HURRICANE, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_SLICING_HURRICANE);
    }
};

void AddSC_shrine_of_the_storm()
{
    RegisterCreatureAI(npc_rexxar);
    RegisterCreatureAI(npc_brother_pike);
    RegisterCreatureAI(npc_lord_stormsong);
    new spell_burst_sots();
    RegisterAreaTriggerAI(at_slicing_hurricane);
}
