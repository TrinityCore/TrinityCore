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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stormstout_brewery.h"
#include "Vehicle.h"

class boss_ook_ook : public CreatureScript
{
    public:
        boss_ook_ook() : CreatureScript("boss_ook_ook") { }

        struct boss_ook_ook_AI : public BossAI
        {
            boss_ook_ook_AI(Creature* creature) : BossAI(creature, DATA_OOK_OOK) {}

            void Reset() override
            {}

            void EnterCombat(Unit* /*who*/) override
            {}

            void DoAction(const int32 /*action*/) override
            {}

            void KilledUnit(Unit* /*victim*/) override
            {}

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
            {}

            void MoveInLineOfSight(Unit* /*who*/) override
            {}

            void UpdateAI(uint32 /*diff*/) override
            {}
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_ook_ook_AI(creature);
        }
};

enum eSpells
{
    SPELL_BAREL_EXPLOSION           = 106769,
    SPELL_FORCECAST_BARREL_DROP     = 122385
};

class npc_barrel : public CreatureScript
{
    public:
        npc_barrel() : CreatureScript("npc_barrel") { }

        struct npc_barrel_AI : public ScriptedAI
        {
            npc_barrel_AI(Creature* creature) : ScriptedAI(creature) {}

            void Reset() override
            {
                me->GetMotionMaster()->MovePoint(100, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
            }

            void MovementInform(uint32 /*type*/, uint32 id) override
            {
                if (id != 100)
                    return;

                float x = 0, y = 0;
                me->GetPositionWithDistInOrientation(5.0f, me->GetOrientation(), x, y);

                me->GetMotionMaster()->MovePoint(100, x, y, me->GetPositionZ());
            }

            bool CheckIfAgainstWall()
            {
                float x = 0, y = 0;
                me->GetPositionWithDistInOrientation(5.0f,  me->GetOrientation(),x, y);

                if (!me->IsWithinLOS(x, y, me->GetPositionZ()))
                    return true;

                return false;
            }

            bool CheckIfAgainstUnit()
            {
                if (me->SelectNearbyTarget(NULL, 1.0f))
                    return true;

                return false;
            }

            void DoExplode()
            {
                if (Vehicle* barrel = me->GetVehicleKit())
                    barrel->RemoveAllPassengers();

                me->Kill(me);
                me->CastSpell(me, SPELL_BAREL_EXPLOSION, true);
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (CheckIfAgainstWall() || CheckIfAgainstUnit())
                    DoExplode();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_barrel_AI(creature);
        }
};

class spell_ook_ook_barrel_ride: public SpellScriptLoader
{
    public:
        spell_ook_ook_barrel_ride() :  SpellScriptLoader("spell_ook_ook_barrel_ride") { }

        class spell_ook_ook_barrel_ride_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_ook_ook_barrel_ride_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget())
                    if (Unit* barrelBase = GetTarget())
                        barrelBase->GetMotionMaster()->MoveIdle();
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_ook_ook_barrel_ride_AuraScript::OnApply, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_ook_ook_barrel_ride_AuraScript();
        }
};

class spell_ook_ook_barrel: public SpellScriptLoader
{
    public:
        spell_ook_ook_barrel() :  SpellScriptLoader("spell_ook_ook_barrel") { }

        class spell_ook_ook_barrel_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_ook_ook_barrel_AuraScript);

            bool CheckIfAgainstWall(Unit* caster)
            {
                float x = caster->GetPositionX() + (2 * cos(caster->GetOrientation()));
                float y = caster->GetPositionY() + (2 * sin(caster->GetOrientation()));

                if (!caster->IsWithinLOS(x, y, caster->GetPositionZ()))
                    return true;

                return false;
            }

            bool CheckIfAgainstUnit(Unit* caster)
            {
                if (caster->SelectNearbyTarget(NULL, 1.0f))
                    return true;

                return false;
            }

            void OnUpdate(uint32 /*diff*/)
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                if (CheckIfAgainstWall(caster) || CheckIfAgainstUnit(caster))
                {
                    if (Vehicle* barrel = caster->GetVehicle())
                    {
                        barrel->RemoveAllPassengers();

                        if (Unit* barrelBase = barrel->GetBase())
                        {
                            barrelBase->CastSpell(barrelBase, SPELL_BAREL_EXPLOSION, true);
                            barrelBase->Kill(barrelBase);
                        }
                    }

                    caster->CastSpell(caster, SPELL_FORCECAST_BARREL_DROP, true);
                    caster->RemoveAurasDueToSpell(GetSpellInfo()->Id);
                }
            }

            void Register() override
            {
                OnAuraUpdate += AuraUpdateFn(spell_ook_ook_barrel_AuraScript::OnUpdate);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_ook_ook_barrel_AuraScript();
        }
};

void AddSC_boss_ook_ook()
{
    new boss_ook_ook();
    new npc_barrel();
    new spell_ook_ook_barrel_ride();
    new spell_ook_ook_barrel();
}
