/*
 * Copyright 2023 AzgathCore
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

void AddSC_the_underrot()
{
  
}
