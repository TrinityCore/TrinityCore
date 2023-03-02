/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
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
#include "siege_of_the_niuzao_temple.h"
#include "SpellAuras.h"

enum spells
{
    MALLEABLE_RESIN = 121421,
    RESIN_WEAVING = 121114,
    ENCASED_IN_RESIN = 121116,
    RESIN_SHELL = 120946,
    RESIDUE = 120938
};

class mob_sikthik_guardian : public CreatureScript
{
    public:
        mob_sikthik_guardian() : CreatureScript("mob_sikthik_guardian") {}

        struct mob_sikthik_guardianAI : public ScriptedAI
        {
            mob_sikthik_guardianAI(Creature* creature) : ScriptedAI(creature) { }

            uint32 malleableResinTimer;

            void Reset() override
            {
                malleableResinTimer = urand(5000, 8000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;
                if (malleableResinTimer <= diff)
                {
                    if (Unit* target = me->SelectNearestTarget(5.0f))
                        if (!target->IsFriendlyTo(me))
                            me->CastSpell(target, MALLEABLE_RESIN, true);
                    malleableResinTimer = urand(8000, 12000);
                }
                else
                    malleableResinTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_sikthik_guardianAI(creature);
        }
};

class mob_resin_flake : public CreatureScript
{
    public:
        mob_resin_flake() : CreatureScript("mob_resin_flake") {}

        struct mob_resin_flakeAI : public ScriptedAI
        {
            mob_resin_flakeAI(Creature* creature) : ScriptedAI(creature) { }

            uint32 residueTimer;

            void Reset() override
            {
                residueTimer = urand(5000, 7000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;
                if (residueTimer <= diff)
                {
                    if (Unit* target = me->SelectNearestTarget(5.0f))
                        if (!target->IsFriendlyTo(me))
                            me->CastSpell(target, RESIDUE, true);
                    residueTimer = urand(5000, 7000);
                }
                else
                    residueTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_resin_flakeAI(creature);
        }
};

class mob_sikthik_amber_weaver : public CreatureScript
{
    public:
        mob_sikthik_amber_weaver() : CreatureScript("mob_sikthik_amber_weaver") {}

        struct mob_sikthik_amber_weaverAI : public ScriptedAI
        {
            mob_sikthik_amber_weaverAI(Creature* creature) : ScriptedAI(creature) { }

            uint32 resinWeavingTimer;
            uint32 resinShellTimer;
            bool resinShellOnlyOne;

            void Reset() override
            {
                resinWeavingTimer = urand(10000, 12000);
                resinShellTimer = urand(8000, 15000);
                resinShellOnlyOne = true;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (resinWeavingTimer <= diff)
                {
                    if (Unit* target = me->SelectNearestTarget(5.0f))
                        if (!target->IsFriendlyTo(me))
                            me->CastSpell(target, RESIN_WEAVING, true);
                    resinWeavingTimer = urand(10000, 12000);
                }
                else
                    resinWeavingTimer -= diff;

                if (resinShellTimer <= diff && resinShellOnlyOne == true)
                {
                    if (Unit* target = me->SelectNearestTarget(5.0f))
                    {
                        me->CastSpell(target, RESIN_SHELL, true);
                        resinShellOnlyOne = false;
                    }
                }
                else
                    resinShellTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_sikthik_amber_weaverAI(creature);
        }
};

class spell_resin_weaving: public SpellScriptLoader
{
    public:
        spell_resin_weaving() : SpellScriptLoader("spell_resin_weaving") { }

        class spell_resin_weaving_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_resin_weaving_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetTarget())
                    {
                        AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
                        if (removeMode == AURA_REMOVE_BY_EXPIRE)
                            caster->CastSpell(target, ENCASED_IN_RESIN, true);
                    }
                }
            }
            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_resin_weaving_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_resin_weaving_AuraScript();
        }
};

void AddSC_siege_of_the_niuzao_temple()
{
    new mob_sikthik_guardian();
    new mob_resin_flake();
    new mob_sikthik_amber_weaver();
    new spell_resin_weaving();
}
