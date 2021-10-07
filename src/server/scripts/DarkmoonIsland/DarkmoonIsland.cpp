/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
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
#include "SpellAuras.h"
#include "GameObject.h"
#include "Transport.h"
#include "DarkmoonIsland.h"

class playerscript_darkmoon_carousel : public PlayerScript
{
    public:
        playerscript_darkmoon_carousel() : PlayerScript("playerscript_darkmoon_carousel") {}

        /*virtual void OnEnterTransport(Player* p_Player, GameObject* transport) override
        {
            if (transport->GetEntry() == GOB_DARKMOON_CAROUSEL)
                if (!p_Player->HasAura(SPELL_WHEE))
                    p_Player->CastSpell(p_Player, SPELL_WHEE, false);
        }*/
};

// Whee! - 46668
class spell_darkmoon_carousel_whee : public SpellScriptLoader
{
public:
    spell_darkmoon_carousel_whee() : SpellScriptLoader("spell_darkmoon_carousel_whee") { }

    class spell_darkmoon_carousel_whee_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_darkmoon_carousel_whee_AuraScript);

        uint32 update;

        bool Validate(SpellInfo const* /*spell*/) override
        {
            update = 0;
            return true;
        }

        void OnUpdate(uint32 diff)
        {
            update += diff;

            if (update >= 5000)
            {
                if (Player* _player = GetCaster()->ToPlayer())
                {
                    if (GameObject* transport = _player->GetTransport())
                    {
                        if (transport->GetEntry() == GOB_DARKMOON_CAROUSEL)
                        {
                            if (Aura* aura = GetAura())
                            {
                                uint32 currentMaxDuration = aura->GetMaxDuration();
                                uint32 newMaxDurantion = currentMaxDuration + (5 * MINUTE * IN_MILLISECONDS);
                                newMaxDurantion = newMaxDurantion <= (60 * MINUTE * IN_MILLISECONDS) ? newMaxDurantion : (60 * MINUTE * IN_MILLISECONDS);

                                aura->SetMaxDuration(newMaxDurantion);
                                aura->SetDuration(newMaxDurantion);
                            }
                        }
                    }
                }

                update = 0;
            }
        }

        void Register() override
        {
            OnAuraUpdate += AuraUpdateFn(spell_darkmoon_carousel_whee_AuraScript::OnUpdate);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_darkmoon_carousel_whee_AuraScript();
    }
};

// To the Staging Area! - 101260
class spell_darkmoon_staging_area_teleport : public SpellScriptLoader
{
public:
    spell_darkmoon_staging_area_teleport() : SpellScriptLoader("spell_darkmoon_staging_area_teleport") { }

    class spell_darkmoon_staging_area_teleport_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_darkmoon_staging_area_teleport_SpellScript);

        bool Load() override
        {
            return GetCaster() != nullptr;
        }

        void RelocateDest(SpellEffIndex /*effIndex*/)
        {
            if (Player* caster = GetCaster()->ToPlayer())
            {
                switch (caster->GetMapId())
                {
                    case 974: //Darkmoon Island
                        if (caster->GetTeamId() == TEAM_HORDE)
                            GetHitDest()->WorldRelocate(WorldLocation(1, -1454.415894f, 207.967484f, -7.790083f, 0.689538f));
                        else
                            GetHitDest()->WorldRelocate(WorldLocation(0, -9517.5f, 82.3f, 59.51f, 2.92168f));
                        break;
                    default:
                        GetHitDest()->WorldRelocate(WorldLocation(974, -3618.669922f, 6315.669922f, 113.190002f, 3.204420f));
                        break;
                }
            }
        }

        void Register() override
        {
            OnEffectLaunch += SpellEffectFn(spell_darkmoon_staging_area_teleport_SpellScript::RelocateDest, EFFECT_0, SPELL_EFFECT_TELEPORT_UNITS);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_darkmoon_staging_area_teleport_SpellScript();
    }
};

void AddSC_darkmoon_island()
{
    new playerscript_darkmoon_carousel();
    new spell_darkmoon_carousel_whee();
    new spell_darkmoon_staging_area_teleport();
};
