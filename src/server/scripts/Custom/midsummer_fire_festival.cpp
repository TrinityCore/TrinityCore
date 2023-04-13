//
//#include "PrecompiledHeaders/ScriptPCH.h"
//#include "SpellAuras.h"
//#include "SpellAuraEffects.h"
//#include "Spell.h"
//
//#define ACHIEVEMENT_FIRE_DANCING 271
//#define ACHIEVEMENT_TORCH_JUGGLER 272
//#define SPELL_JUGGLE_TORCH 45638
//#define SPELL_TORCHES_CAUGHT 45693
//#define GO_RIBBON_POLE 181605
//
//// spell 45418
//class spell_fire_dancing : public SpellScriptLoader
//{
//public:
//    spell_fire_dancing() : SpellScriptLoader("spell_fire_dancing") { }
//
//    class spell_fire_dancingAuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_fire_dancingAuraScript);
//
//        void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
//        {
//            Unit* caster = GetCaster();
//            // caster may be not avalible (logged out for example)
//            if (!caster)
//                return;
//
//            if (GameObject* Cage = caster->FindNearestGameObject(GO_RIBBON_POLE, 10))
//                if (AchievementEntry const* AchievWC = sAchievementStore.LookupEntry(ACHIEVEMENT_FIRE_DANCING))
//                    caster->ToPlayer()->CompletedAchievement(AchievWC);
//        }
//
//        // function registering
//        void Register() override
//        {
//            OnEffectRemove += AuraEffectRemoveFn(spell_fire_dancingAuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
//        }
//    };
//
//    // function which creates AuraScript
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_fire_dancingAuraScript();
//    }
//};
//
//// spell 45693 - äàåì à÷èâêó
//class spell_torches_caught : public SpellScriptLoader
//{
//public:
//    spell_torches_caught() : SpellScriptLoader("spell_torches_caught") { }
//
//    class spell_torches_caughtAuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_torches_caughtAuraScript);
//
//        void OnStackChange(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
//        {
//            Unit* caster = GetCaster();
//            // caster may be not avalible (logged out for example)
//            if (caster)
//                if (GetStackAmount() >= 39)
//                    if (AchievementEntry const* Achiev = sAchievementStore.LookupEntry(ACHIEVEMENT_TORCH_JUGGLER))
//                        caster->ToPlayer()->CompletedAchievement(Achiev);
//        }
//
//        // function registering
//        void Register() override
//        {
//            OnEffectApply += AuraEffectApplyFn(spell_torches_caughtAuraScript::OnStackChange, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
//        }
//    };
//
//    // function which creates AuraScript
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_torches_caughtAuraScript();
//    }
//};
//
//// spell 45669
//class spell_throw_torch : public SpellScriptLoader
//{
//public:
//    spell_throw_torch() : SpellScriptLoader("spell_throw_torch") { }
//
//    class spell_throw_torch_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_throw_torch_SpellScript);
//
//        void CheckTarget(SpellEffIndex effIndex)
//        {
//            PreventHitDefaultEffect(EFFECT_0);
//
//            Unit* caster = GetCaster();
//            Unit* target = caster->ToPlayer()->GetSelectedUnit();
//            if (!caster)
//                return;
//            if (target && target->GetTypeId() == TYPEID_PLAYER && target != caster)
//            {
//                caster->CastSpell(caster, SPELL_TORCHES_CAUGHT, true);
//                target->CastSpell(caster, SPELL_JUGGLE_TORCH, true);
//            }
//        }
//
//        void Register() override
//        {
//            OnEffectHit += SpellEffectFn(spell_throw_torch_SpellScript::CheckTarget, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
//        }
//    };
//
//    SpellScript* GetSpellScript() const override
//    {
//        return new spell_throw_torch_SpellScript();
//    }
//};
//
//class item_juggling_torch : public ItemScript
//{
//public:
//    item_juggling_torch() : ItemScript("item_juggling_torch") { }
//
//    bool OnUse(Player* pPlayer, Item* pItem, SpellCastTargets const& /*targets*/) override
//    {
//        pPlayer->CastSpell(pPlayer->GetSelectedUnit(), 45669, true);
//
//        pPlayer->DestroyItemCount(pItem->GetEntry(), 1, true);
//        return true;
//    }
//};
//
//// spell 45819
//class spell_throw_torch2 : public SpellScriptLoader
//{
//public:
//    spell_throw_torch2() : SpellScriptLoader("spell_throw_torch2") { }
//
//    class spell_throw_torch2_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_throw_torch2_SpellScript);
//
//        void CheckTarget(SpellEffIndex effIndex)
//        {
//            PreventHitDefaultEffect(EFFECT_0);
//
//            Unit* caster = GetCaster();
//            if (!caster)
//                return;
//            Unit* target = caster->getVictim();
//            // caster may be not avalible (logged out for example)
//            if (target)
//                caster->CastSpell(target, 45669, true);
//        }
//
//        void Register() override
//        {
//            OnEffectHit += SpellEffectFn(spell_throw_torch2_SpellScript::CheckTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
//        }
//    };
//
//    SpellScript* GetSpellScript() const override
//    {
//        return new spell_throw_torch2_SpellScript();
//    }
//};
//
//// spell 45693 - äàåì à÷èâêó
//class spell_hawka : public SpellScriptLoader
//{
//public:
//    spell_hawka() : SpellScriptLoader("spell_hawka") { }
//
//    class spell_hawkaAuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_hawkaAuraScript);
//
//        void OnStackChange(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
//        {
//            Unit* target = GetTarget();
//            // caster may be not avalible (logged out for example)
//            if (target)
//                if (GetStackAmount() >= 5)
//                {
//                    switch (GetId())
//                    {
//                    case 61841:
//                        target->CastSpell(target, 66372, true);
//                        break;
//                    case 61842:
//                        target->CastSpell(target, 66373, true);
//                        break;
//                    case 61843:
//                        target->CastSpell(target, 66375, true);
//                        break;
//                    case 61844:
//                        target->CastSpell(target, 66376, true);
//                        break;
//                    case 61845:
//                        target->CastSpell(target, 66374, true);
//                        break;
//                    default:
//                        break;
//                    }
//                    if (Aura* aura1 = target->GetAura(61841))
//                        if (Aura* aura2 = target->GetAura(61842))
//                            if (Aura* aura3 = target->GetAura(61843))
//                                if (Aura* aura4 = target->GetAura(61844))
//                                    if (Aura* aura5 = target->GetAura(61845))
//                                    {
//                                        if (aura1->GetStackAmount() >= 5 && aura2->GetStackAmount() >= 5 && aura3->GetStackAmount() >= 5 && aura4->GetStackAmount() >= 5 && aura5->GetStackAmount() >= 5)
//                                        {
//                                            target->CastSpell(target, 61849, true);
//                                            aura1->SetStackAmount(0);
//                                            aura2->SetStackAmount(0);
//                                            aura3->SetStackAmount(0);
//                                            aura4->SetStackAmount(0);
//                                            aura5->SetStackAmount(0);
//                                        }
//                                    }
//                }
//        }
//
//        // function registering
//        void Register() override
//        {
//            OnEffectApply += AuraEffectApplyFn(spell_hawkaAuraScript::OnStackChange, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
//        }
//    };
//
//    // function which creates AuraScript
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_hawkaAuraScript();
//    }
//};
//
//// 62014
//class spell_turkey_tracker : public SpellScriptLoader
//{
//public:
//    spell_turkey_tracker() : SpellScriptLoader("spell_turkey_tracker") { }
//
//    class spell_turkey_trackerAuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_turkey_trackerAuraScript);
//
//        void OnStackChange(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
//        {
//            if (GetStackAmount() >= 39)
//                if (Unit* caster = GetCaster())
//                    if (Player* player = caster->ToPlayer())
//                    {
//                        player->CastSpell(player, 62021, true);
//                        GetAura()->Remove();
//                    }
//        }
//
//        void Register() override
//        {
//            OnEffectApply += AuraEffectApplyFn(spell_turkey_trackerAuraScript::OnStackChange, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_turkey_trackerAuraScript();
//    }
//};
//
//class spell_pass_the_turkey : public SpellScriptLoader
//{
//public:
//    spell_pass_the_turkey() : SpellScriptLoader("spell_pass_the_turkey") { }
//
//    class spell_pass_the_turkey_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_pass_the_turkey_SpellScript);
//
//        void Dummy(SpellEffIndex effIndex)
//        {
//            PreventHitDefaultEffect(EFFECT_0);
//
//            if (Unit* caster = GetCaster())
//                if (Player* player = caster->GetCharmerOrOwnerPlayerOrPlayerItself())
//                    if (AchievementEntry const* Achiev = sAchievementStore.LookupEntry(3579))
//                        if (!player->HasAchieved(Achiev->ID))
//                            player->CompletedAchievement(Achiev);
//        }
//
//        void Register() override
//        {
//            OnEffectHit += SpellEffectFn(spell_pass_the_turkey_SpellScript::Dummy, EFFECT_0, SPELL_EFFECT_DUMMY);
//        }
//    };
//
//    SpellScript* GetSpellScript() const override
//    {
//        return new spell_pass_the_turkey_SpellScript();
//    }
//};
//
//class spell_achiev_snow : public SpellScriptLoader
//{
//public:
//    spell_achiev_snow() : SpellScriptLoader("spell_achiev_snow") { }
//
//    class spell_achiev_snow_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_achiev_snow_SpellScript);
//
//        void Dummy(SpellEffIndex effIndex)
//        {
//            PreventHitDefaultEffect(EFFECT_0);
//
//            Unit* target = GetHitUnit();
//            if (!target || target->GetEntry() != 42928)
//                return;
//
//            if (Unit* caster = GetCaster())
//                if (Player* player = caster->GetCharmerOrOwnerPlayerOrPlayerItself())
//                    if (AchievementEntry const* Achiev = sAchievementStore.LookupEntry(1255))
//                        player->CompletedAchievement(Achiev);
//        }
//
//        void Register() override
//        {
//            OnEffectHitTarget += SpellEffectFn(spell_achiev_snow_SpellScript::Dummy, EFFECT_0, SPELL_EFFECT_DUMMY);
//        }
//    };
//
//    SpellScript* GetSpellScript() const override
//    {
//        return new spell_achiev_snow_SpellScript();
//    }
//};
//
//void AddSC_midsummer_fire_festival()
//{
//    new spell_fire_dancing;
//    new spell_torches_caught;
//    new spell_throw_torch;
//    new spell_throw_torch2;
//    new item_juggling_torch;
//    new spell_hawka;
//    new spell_turkey_tracker();
//    new spell_pass_the_turkey();
//    new spell_achiev_snow();
//}
