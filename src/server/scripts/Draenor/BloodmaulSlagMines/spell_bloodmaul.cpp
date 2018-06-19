/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
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

#include "instance_bloodmaul.h"

namespace Instances
{
    namespace Bloodmaul
    {
        // Lava splash - 152809
        class spell_LavaSplash: public SpellScriptLoader
        {
        public:
            spell_LavaSplash()
                : SpellScriptLoader("spell_LavaSplash")
            {
            }

            enum class Spells : uint32
            {
                LavaExplosion = 152832,
            };

            class spell_SpellScript : public SpellScript
            {
                PrepareSpellScript(spell_SpellScript);

                void HandleDummy(SpellEffIndex /*effIndex*/)
                {
                    Unit* caster = GetCaster();
                    Unit* target = GetHitUnit();
                    if (!caster || !target)
                        return;

                    target->CastSpell(target, uint32(Spells::LavaExplosion), true);
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
            };

            SpellScript* GetSpellScript() const override
            {
                return new spell_SpellScript();
            }
        };

        // Volcanic Eruption - 151698
        class spell_VolcanicEruption : public SpellScriptLoader
        {
        public:
            spell_VolcanicEruption()
                : SpellScriptLoader("spell_VolcanicEruption")
            {
            }

            enum class Spells : uint32
            {
                VolcanicEruption = 152499,
            };

            class spell_SpellScript : public SpellScript
            {
                PrepareSpellScript(spell_SpellScript);

                void HandleDummy(SpellEffIndex /*effIndex*/)
                {
                    Unit* caster = GetCaster();
                    if (!caster)
                        return;

                    if (Unit* unit = caster->SelectRandomPlayerInRange(30.0f, true))
                        caster->CastSpell(unit, uint32(Spells::VolcanicEruption), true);
                }

                void Register() override
                {
                    OnEffectHit += SpellEffectFn(spell_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
            };

            SpellScript* GetSpellScript() const override
            {
                return new spell_SpellScript();
            }
        };

        // Pilar of Flames - 164546
        class spell_pilar_of_flames : public SpellScriptLoader
        {
        public:
            spell_pilar_of_flames() : SpellScriptLoader("spell_pilar_of_flames") { }

            enum class Spells : uint32
            {
                PilarOfFlamesSummon = 151626,
            };

            class spell_SpellScript : public SpellScript
            {
                PrepareSpellScript(spell_SpellScript);

                void CheckTarget(std::list<WorldObject*>& unitList)
                {
                    Trinity::Containers::RandomResize(unitList, 1);
                }

                void HandleDummy(SpellEffIndex /*effIndex*/)
                {
                    Unit* caster = GetCaster();

                    if (!caster)
                        return;

                    caster->CastSpell(caster, (uint32)Spells::PilarOfFlamesSummon, true);
                }

                void Register() override
                {
                    OnEffectHit += SpellEffectFn(spell_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
            };

            SpellScript* GetSpellScript() const override
            {
                return new spell_SpellScript();
            }
        };

        // Raise the miners - 150801
        class spell_RaiseTheMiners: public SpellScriptLoader
        {
        public:
            spell_RaiseTheMiners()
                : SpellScriptLoader("spell_RaiseTheMiners")
            {
            }

            enum class Spells : uint32
            {
                SuppresionField = 151582,
            };

            class spell_SpellScript : public SpellScript
            {
                PrepareSpellScript(spell_SpellScript);

                void HandleDummy(SpellEffIndex /*effIndex*/)
                {
                    Unit* caster = GetCaster();
                    if (caster && caster->GetInstanceScript())
                        caster->GetInstanceScript()->SetData(uint32(Data::RaiseTheMiners), 0);
                }

                void Register() override
                {
                    OnEffectHit += SpellEffectFn(spell_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
            };

            SpellScript* GetSpellScript() const override
            {
                return new spell_SpellScript();
            }
        };

        // FerociousYell - 150759
        class spell_FerociousYell: public SpellScriptLoader
        {
        public:
            spell_FerociousYell()
                : SpellScriptLoader("spell_FerociousYell")
            {
            }

            class spell_SpellScript : public SpellScript
            {
                PrepareSpellScript(spell_SpellScript);

                void CheckTarget(std::list<WorldObject*>& unitList)
                {
                    unitList.remove_if([](WorldObject* obj) {
                        return !(obj->GetEntry() == uint32(MobEntries::CapturedMinerAlliance)
                              || obj->GetEntry() == uint32(MobEntries::CapturedMinerHorde)
                              || obj->GetEntry() == uint32(MobEntries::CapturedMinerNeutral));
                    });
                }

                void Register() override
                {
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_SpellScript::CheckTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                }
            };

            SpellScript* GetSpellScript() const override
            {
                return new spell_SpellScript();
            }
        };

        // SuppressField - 151581
        class spell_SuppressionField: public SpellScriptLoader
        {
        public:
            spell_SuppressionField()
                : SpellScriptLoader("spell_SuppressionField")
            {
            }

            enum class Spells : uint32
            {
                SuppresionField = 151582,
            };

            class spell_SpellScript : public SpellScript
            {
                PrepareSpellScript(spell_SpellScript);

                void HandleDummy(SpellEffIndex /*effIndex*/)
                {
                    Unit* caster = GetCaster();
                    if (caster)
                    {
                        if (Player* l_Plr = caster->SelectRandomPlayerInRange(40.0f, true))
                            caster->CastSpell(l_Plr, uint32(Spells::SuppresionField), true);
                    }
                }

                void Register() override
                {
                    OnEffectHit += SpellEffectFn(spell_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                }
            };

            SpellScript* GetSpellScript() const override
            {
                return new spell_SpellScript();
            }
        };

        // Chain Grip - 151990
        class spell_ChainGrip: public SpellScriptLoader
        {
        public:
            spell_ChainGrip()
                : SpellScriptLoader("spell_ChainGrip")
            {
            }

            enum class Spells : uint32
            {
                ChainGrip = 152024,
                ViciousSlash = 152043,
            };

            class spell_SpellScript : public SpellScript
            {
                PrepareSpellScript(spell_SpellScript);

                void HandleDummy(SpellEffIndex /*effIndex*/)
                {
                    Unit* caster = GetCaster();
                    Unit* target = GetHitUnit();
                    if (caster && target)
                    {
                        caster->CastSpell(target, uint32(Spells::ChainGrip), true);
                        target->GetMotionMaster()->MoveJump(caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), caster->GetOrientation(), 25.0f, 2.0f);
                        caster->CastSpell(target, uint32(Spells::ViciousSlash), false);
                    }
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
            };

            SpellScript* GetSpellScript() const override
            {
                return new spell_SpellScript();
            }
        };
    }
}

void AddSC_spell_Bloodmaul()
{
    new Instances::Bloodmaul::spell_ChainGrip();
    new Instances::Bloodmaul::spell_SuppressionField();
    new Instances::Bloodmaul::spell_FerociousYell();
    new Instances::Bloodmaul::spell_RaiseTheMiners();
    new Instances::Bloodmaul::spell_VolcanicEruption();
    new Instances::Bloodmaul::spell_LavaSplash();
    new Instances::Bloodmaul::spell_pilar_of_flames();
}
