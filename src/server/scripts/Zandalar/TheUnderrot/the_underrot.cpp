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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "the_underrot.h"

// 138281
struct npc_underrot_faceless_corruptor : public ScriptedAI
{
    npc_underrot_faceless_corruptor(Creature* creature) : ScriptedAI(creature) { }

    void JustDied(Unit* /*killer*/) override
    {
        if (InstanceScript* instanceScript = me->GetInstanceScript())
        {
            ScriptParam param = me->GetScriptParam(1);

            if (param.numericValue == 1)
                instanceScript->SetData(DATA_FACELESS_CORRUPTOR_1, 1);
            else if (param.numericValue == 2)
                instanceScript->SetData(DATA_FACELESS_CORRUPTOR_2, 1);
        }
    }
};

// 279271
class aura_underrot_open_web_door : public AuraScript
{
    PrepareAuraScript(aura_underrot_open_web_door);

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (InstanceScript* instanceScript = GetTarget()->GetInstanceScript())
            instanceScript->SetData(DATA_EVENT_HERZEL, DONE);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(aura_underrot_open_web_door::HandleEffectRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

struct at_underrot_tunnel : AreaTriggerAI
{
    at_underrot_tunnel(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    enum
    {
        SPELL_GATEWAY   = 253773
    };

    Position unboundAbominationPath[3] =
    {
        { 1125.237183f, 1366.732910f,    7.305541f, 0.956234f },
        { 1203.495728f, 1489.153198f,  -45.093700f, 0.999432f },
        { 1206.048584f, 1490.873169f, -181.704376f, 5.154191f },
    };

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsPlayer())
        {
            unit->CastSpell(unit, SPELL_GATEWAY, true);
            unit->GetMotionMaster()->MoveSmoothPath(1, unboundAbominationPath, 3, false, true, 35.f);
        }
    }
};

void AddSC_the_underrot()
{
    RegisterCreatureAI(npc_underrot_faceless_corruptor);

    RegisterAuraScript(aura_underrot_open_web_door);

    RegisterAreaTriggerAI(at_underrot_tunnel);
}
