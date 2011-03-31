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
                    if (Unit *caster = GetCaster())
                    {
                        caster->CastSpell(pTarget,74399,true);
                        caster->CastSpell(pTarget,68321,true);

                        if (pTarget->GetTypeId() == TYPEID_UNIT && pTarget->ToCreature()->GetEntry() == 33272)
                        {
                            //Kill Credit
                            if (Unit *player = caster->GetCharmerOrOwner())
                                player->CastSpell(player,62658,true);
                        }
                    }

                    if (pTarget->GetAura(64100))
                        pTarget->RemoveAuraFromStack(64100);
                    else if (pTarget->GetAura(62552))
                        pTarget->RemoveAuraFromStack(62552);
                    else if (pTarget->GetAura(62719))
                        pTarget->RemoveAuraFromStack(62719);
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


/*#####
#INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('62575', 'spell_tournament_shield');
#####*/
class spell_tournament_shield : public SpellScriptLoader
{
    public:
        spell_tournament_shield() : SpellScriptLoader("spell_tournament_shield") { }

        class spell_tournament_shield_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_tournament_shield_SpellScript);

            void HandleEffectScriptEffect(SpellEffIndex /*effIndex*/)
            {
                if (Unit* pTarget = GetHitUnit())
                {
                    if (Unit *caster = GetCaster())
                    {
                        caster->CastSpell(pTarget,62626,true );

                        if (pTarget->GetTypeId() == TYPEID_UNIT && pTarget->ToCreature()->GetEntry() == 33243)
                        {
                            //Kill Credit
                            if (Unit *player = caster->GetCharmerOrOwner())
                                player->CastSpell(player,62673,true);
                        }
                    }

                    if (pTarget->GetAura(64100))
                        pTarget->RemoveAuraFromStack(64100);
                    else if (pTarget->GetAura(62552))
                        pTarget->RemoveAuraFromStack(62552);
                    else if (pTarget->GetAura(62719))
                        pTarget->RemoveAuraFromStack(62719);
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_tournament_shield_SpellScript::HandleEffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript *GetSpellScript() const
        {
            return new spell_tournament_shield_SpellScript();
        }
};


/*#####
#INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('62544', 'spell_tournament_melee');
#####*/
class spell_tournament_melee : public SpellScriptLoader
{
    public:
        spell_tournament_melee() : SpellScriptLoader("spell_tournament_melee") { }

        class spell_tournament_melee_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_tournament_melee_SpellScript);

            void HandleEffectScriptEffect(SpellEffIndex /*effIndex*/)
            {
                if (Unit* pTarget = GetHitUnit())
                {
                    if (Unit *caster = GetCaster())
                    {
                        if (pTarget->GetTypeId() == TYPEID_UNIT && pTarget->ToCreature()->GetEntry() == 33229)
                        {
                            //Kill Credit
                            if (Unit *player = caster->GetCharmerOrOwner())
                                player->CastSpell(player,62672,true);
                        }
                    }
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_tournament_melee_SpellScript::HandleEffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript *GetSpellScript() const
        {
            return new spell_tournament_melee_SpellScript();
        }
};


/*#####
#INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('62863', 'spell_tournament_duel');
#####*/
class spell_tournament_duel : public SpellScriptLoader
{
    public:
        spell_tournament_duel() : SpellScriptLoader("spell_tournament_duel") { }

        class spell_tournament_duel_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_tournament_duel_SpellScript);

            void HandleEffectScriptEffect(SpellEffIndex /*effIndex*/)
            {
                if (Unit* pTarget = GetHitUnit())
                {
                    if (pTarget->GetTypeId() != TYPEID_PLAYER)
                        return;

                    if (Unit *caster = GetCaster()->GetCharmerOrOwner())
                        caster->CastSpell(pTarget,62875,true);
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_tournament_duel_SpellScript::HandleEffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript *GetSpellScript() const
        {
            return new spell_tournament_duel_SpellScript();
        }
};


void AddSC_argen_tournament()
{
    new spell_tournament_charge;
    new spell_tournament_shield;
    new spell_tournament_melee;
    new spell_tournament_duel;
}

