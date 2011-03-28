#include "ScriptPCH.h"
#include "SpellAuraEffects.h"
#include "ScriptMgr.h"

/*#####
#INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('62960', 'spell_tournament_charge');
#####*/
class spell_tournament_charge : public SpellScriptLoader
{
    public:
        spell_tournament_charge() : SpellScriptLoader("spell_tournament_charge") { }

        class spell_tournament_charge_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_tournament_charge_SpellScript);

            void HandleEffectScriptEffect(SpellEffIndex /*effIndex*/)
            {
                if (Unit* pTarget = GetHitUnit())
                {
                    Unit *caster = GetCaster();
                    caster->CastSpell(pTarget,74399,true );
                    caster->CastSpell(pTarget,68321,true );

                    if (pTarget->GetAura(64100))
                        pTarget->RemoveAuraFromStack(64100);
                    else if (pTarget->GetAura(62552))
                        pTarget->RemoveAuraFromStack(62552);

                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_tournament_charge_SpellScript::HandleEffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript *GetSpellScript() const
        {
            return new spell_tournament_charge_SpellScript();
        }
};



void AddSC_argen_tournament()
{
    new spell_tournament_charge;
}

