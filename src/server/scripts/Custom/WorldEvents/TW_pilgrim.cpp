#include "ScriptPCH.h"
#include "ScriptMgr.h"
#include "Vehicle.h"

// Achievement: The Turkinator
enum TheTurkinator
{
    SPELL_KILL_COUNTER_VISUAL       = 62015,
    SPELL_KILL_COUNTER_VISUAL_MAX   = 62021
};

#define THE_THUKINATOR_10           "Turkey Hunter!"
#define THE_THUKINATOR_20           "Turkey Domination!"
#define THE_THUKINATOR_30           "Turkey Slaughter!"
#define THE_THUKINATOR_40           "TURKEY TRIUMPH!"

class TW_spell_gen_turkey_tracker : public SpellScriptLoader
{
    public:
        TW_spell_gen_turkey_tracker() : SpellScriptLoader("TW_spell_gen_turkey_tracker") { }

        class TW_spell_gen_turkey_tracker_SpellScript : public SpellScript
        {
            PrepareSpellScript(TW_spell_gen_turkey_tracker_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_KILL_COUNTER_VISUAL))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_KILL_COUNTER_VISUAL_MAX))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (GetCaster()->GetAura(SPELL_KILL_COUNTER_VISUAL_MAX))
                    return;

                Player* target = GetHitPlayer();
                if (!target)
                    return;

                if (Aura const* aura = GetCaster()->ToPlayer()->GetAura(GetSpellInfo()->Id))
                {
                    switch (aura->GetStackAmount())
                    {
                    case 10:
                        target->TextEmote(THE_THUKINATOR_10, 0, true);
                        GetCaster()->CastSpell(target, SPELL_KILL_COUNTER_VISUAL);
                        break;
                    case 20:
                        target->TextEmote(THE_THUKINATOR_20, 0, true);
                        GetCaster()->CastSpell(target, SPELL_KILL_COUNTER_VISUAL);
                        break;
                    case 30:
                        target->TextEmote(THE_THUKINATOR_30, 0, true);
                        GetCaster()->CastSpell(target, SPELL_KILL_COUNTER_VISUAL);
                        break;
                    case 40:
                        target->TextEmote(THE_THUKINATOR_40, 0, true);
                        GetCaster()->CastSpell(target, SPELL_KILL_COUNTER_VISUAL);
                        GetCaster()->CastSpell(target, SPELL_KILL_COUNTER_VISUAL_MAX); // Achievement Credit
                        break;
                    default:
                        break;
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(TW_spell_gen_turkey_tracker_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new TW_spell_gen_turkey_tracker_SpellScript();
        }
};

class TW_spell_gen_feast_on : public SpellScriptLoader
{
    public:
        TW_spell_gen_feast_on() : SpellScriptLoader("TW_spell_gen_feast_on") { }

        class TW_spell_gen_feast_on_SpellScript : public SpellScript
        {
            PrepareSpellScript(TW_spell_gen_feast_on_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                int32 bp0 = GetSpellInfo()->Effects[EFFECT_0].CalcValue();

                Unit* caster = GetCaster();
                if (caster->IsVehicle())
                    if (Unit* player = caster->GetVehicleKit()->GetPassenger(0))
                        caster->CastSpell(player, bp0, true, NULL, NULL, player->ToPlayer()->GetGUID());
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(TW_spell_gen_feast_on_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new TW_spell_gen_feast_on_SpellScript();
        }
};

enum WellFedPilgrimsBounty
{
    // Feast On
    SPELL_A_SERVING_OF_TURKEY           = 61807,
    SPELL_A_SERVING_OF_CRANBERRIES      = 61804,
    SPELL_A_SERVING_OF_STUFFING         = 61806,
    SPELL_A_SERVING_OF_SWEET_POTATOES   = 61808,
    SPELL_A_SERVING_OF_PIE              = 61805,

    // Well Fed
    SPELL_WELL_FED_AP                   = 65414,
    SPELL_WELL_FED_ZM                   = 65412,
    SPELL_WELL_FED_HIT                  = 65416,
    SPELL_WELL_FED_HASTE                = 65410,
    SPELL_WELL_FED_SPIRIT               = 65415,

    // Pilgrim's Paunch
    SPELL_THE_SPIRIT_OF_SHARING         = 61849
};

class TW_spell_gen_well_fed_pilgrims_bounty : public SpellScriptLoader
{
    private:
        uint32 _triggeredSpellId1;
        uint32 _triggeredSpellId2;

    public:
        TW_spell_gen_well_fed_pilgrims_bounty(const char* name, uint32 triggeredSpellId1, uint32 triggeredSpellId2) : SpellScriptLoader(name),
            _triggeredSpellId1(triggeredSpellId1), _triggeredSpellId2(triggeredSpellId2) { }

        class TW_spell_gen_well_fed_pilgrims_bounty_SpellScript : public SpellScript
        {
            PrepareSpellScript(TW_spell_gen_well_fed_pilgrims_bounty_SpellScript);
        private:
            uint32 _triggeredSpellId1;
            uint32 _triggeredSpellId2;

        public:
            TW_spell_gen_well_fed_pilgrims_bounty_SpellScript(uint32 triggeredSpellId1, uint32 triggeredSpellId2) : SpellScript(),
                _triggeredSpellId1(triggeredSpellId1), _triggeredSpellId2(triggeredSpellId2) { }

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(_triggeredSpellId2))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                Player* target = GetHitPlayer();
                if (!target)
                    return;

                Aura const* Turkey = target->GetAura(SPELL_A_SERVING_OF_TURKEY);
                Aura const* Cranberies = target->GetAura(SPELL_A_SERVING_OF_CRANBERRIES);
                Aura const* Stuffing = target->GetAura(SPELL_A_SERVING_OF_STUFFING);
                Aura const* SweetPotatoes = target->GetAura(SPELL_A_SERVING_OF_SWEET_POTATOES);
                Aura const* Pie = target->GetAura(SPELL_A_SERVING_OF_PIE);

                if (Aura const* aura = target->GetAura(_triggeredSpellId1))
                {
                    if (aura->GetStackAmount() == 5)
                        target->CastSpell(target, _triggeredSpellId2, true);
                }

                // The Spirit of Sharing - Achievement Credit
                if (!target->GetAura(SPELL_THE_SPIRIT_OF_SHARING))
                {
                    if ((Turkey && Turkey->GetStackAmount() == 5) && (Cranberies && Cranberies->GetStackAmount() == 5) && (Stuffing && Stuffing->GetStackAmount() == 5) &&
                        (SweetPotatoes && SweetPotatoes->GetStackAmount() == 5) && (Pie && Pie->GetStackAmount() == 5))
                        target->CastSpell(target, SPELL_THE_SPIRIT_OF_SHARING, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(TW_spell_gen_well_fed_pilgrims_bounty_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new TW_spell_gen_well_fed_pilgrims_bounty_SpellScript(_triggeredSpellId1, _triggeredSpellId2);
        }
};

enum OnPlatePilgrimsBounty
{
    // "FOOD FIGHT!" - Achivement Credit
    SPELL_ON_PLATE_TURKEY           = 61928,
    SPELL_ON_PLATE_CRANBERRIES      = 61925,
    SPELL_ON_PLATE_STUFFING         = 61927,
    SPELL_ON_PLATE_SWEET_POTATOES   = 61929,
    SPELL_ON_PLATE_PIE              = 61926,

    // Sharing is Caring - Achivement Credit
    SPELL_PASS_THE_TURKEY           = 66373,
    SPELL_PASS_THE_CRANBERRIES      = 66372,
    SPELL_PASS_THE_STUFFING         = 66375,
    SPELL_PASS_THE_SWEET_POTATOES   = 66376,
    SPELL_PASS_THE_PIE              = 66374
};

class TW_spell_gen_on_plate_pilgrims_bounty : public SpellScriptLoader
{
    private:
        uint32 _triggeredSpellId1;
        uint32 _triggeredSpellId2;

    public:
        TW_spell_gen_on_plate_pilgrims_bounty(const char* name, uint32 triggeredSpellId1, uint32 triggeredSpellId2) : SpellScriptLoader(name),
            _triggeredSpellId1(triggeredSpellId1), _triggeredSpellId2(triggeredSpellId2) { }

        class TW_spell_gen_on_plate_pilgrims_bounty_SpellScript : public SpellScript
        {
            PrepareSpellScript(TW_spell_gen_on_plate_pilgrims_bounty_SpellScript);
        private:
            uint32 _triggeredSpellId1;
            uint32 _triggeredSpellId2;

        public:
            TW_spell_gen_on_plate_pilgrims_bounty_SpellScript(uint32 triggeredSpellId1, uint32 triggeredSpellId2) : SpellScript(),
                _triggeredSpellId1(triggeredSpellId1), _triggeredSpellId2(triggeredSpellId2) { }

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(_triggeredSpellId1))
                    return false;
                if (!sSpellMgr->GetSpellInfo(_triggeredSpellId2))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (caster->IsVehicle())
                {
                    Unit* player = caster->GetVehicleKit()->GetPassenger(0);
                    if (!player)
                        return;

                    player->CastSpell(GetHitUnit(), _triggeredSpellId1, true, NULL, NULL, player->ToPlayer()->GetGUID());
                    player->CastSpell(player, _triggeredSpellId2, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(TW_spell_gen_on_plate_pilgrims_bounty_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new TW_spell_gen_on_plate_pilgrims_bounty_SpellScript(_triggeredSpellId1, _triggeredSpellId2);
        }
};

enum BountifulFeast
{
    // Bountiful Feast
    SPELL_BOUNTIFUL_FEAST_DRINK          = 66041,
    SPELL_BOUNTIFUL_FEAST_FOOD           = 66478,
    SPELL_BOUNTIFUL_FEAST_REFRESHMENT    = 66622
};

class TW_spell_gen_bountiful_feast : public SpellScriptLoader
{
    public:
        TW_spell_gen_bountiful_feast() : SpellScriptLoader("TW_spell_gen_bountiful_feast") { }

        class TW_spell_gen_bountiful_feast_SpellScript : public SpellScript
        {
            PrepareSpellScript(TW_spell_gen_bountiful_feast_SpellScript);

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                caster->CastSpell(caster, SPELL_BOUNTIFUL_FEAST_DRINK, true);
                caster->CastSpell(caster, SPELL_BOUNTIFUL_FEAST_FOOD, true);
                caster->CastSpell(caster, SPELL_BOUNTIFUL_FEAST_REFRESHMENT, true);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(TW_spell_gen_bountiful_feast_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new TW_spell_gen_bountiful_feast_SpellScript();
        }
};

enum PilgrimsBountyBuffFood
{
    // Pilgrims Bounty Buff Food
    SPELL_WELL_FED_AP_TRIGGER       = 65414,
    SPELL_WELL_FED_ZM_TRIGGER       = 65412,
    SPELL_WELL_FED_HIT_TRIGGER      = 65416,
    SPELL_WELL_FED_HASTE_TRIGGER    = 65410,
    SPELL_WELL_FED_SPIRIT_TRIGGER   = 65415
};

class TW_spell_pilgrims_bounty_buff_food : public SpellScriptLoader
{
    private:
        uint32 _triggeredSpellId;
    public:
        TW_spell_pilgrims_bounty_buff_food(const char* name, uint32 triggeredSpellId) : SpellScriptLoader(name), _triggeredSpellId(triggeredSpellId) { }

        class TW_spell_pilgrims_bounty_buff_food_AuraScript : public AuraScript
        {
            PrepareAuraScript(TW_spell_pilgrims_bounty_buff_food_AuraScript);
        private:
            uint32 _triggeredSpellId;

        public:
            TW_spell_pilgrims_bounty_buff_food_AuraScript(uint32 triggeredSpellId) : AuraScript(), _triggeredSpellId(triggeredSpellId) { }

            bool Load() override
            {
                _handled = false;
                return true;
            }

            void HandleTriggerSpell(AuraEffect const* /*aurEff*/)
            {
                if (_handled)
                    return;

                Unit* caster = GetCaster();
                if (!caster)
                    return;

                _handled = true;
                caster->CastSpell(caster, _triggeredSpellId, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(TW_spell_pilgrims_bounty_buff_food_AuraScript::HandleTriggerSpell, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }

            bool _handled;
        };

        AuraScript* GetAuraScript() const
        {
            return new TW_spell_pilgrims_bounty_buff_food_AuraScript(_triggeredSpellId);
        }
};

class TW_achievement_food_fight : public AchievementCriteriaScript
{
public:
    TW_achievement_food_fight() : AchievementCriteriaScript("TW_achievement_food_fight") { }

    bool OnCheck(Player* /*source*/, Unit* target) override
    {
        if (!target)
            return false;

        if (Player* victim = target->ToPlayer())
        {
            if (Vehicle* vehicle = victim->GetVehicle())
                if (vehicle->GetVehicleInfo()->m_ID == 321)
                    return true;
        }

        return false;
    }
};

// Item: Turkey Caller
enum LonelyTurkey
{
    SPELL_STINKER_BROKEN_HEART  = 62004
};

class TW_npc_lonely_turkey : public CreatureScript
{
public:
    TW_npc_lonely_turkey() : CreatureScript("TW_npc_lonely_turkey") { }

    struct TW_npc_lonely_turkeyAI : public ScriptedAI
    {
        TW_npc_lonely_turkeyAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            if (me->IsSummon())
                if (Unit* owner = me->ToTempSummon()->GetSummoner())
                    me->GetMotionMaster()->MovePoint(0, owner->GetPositionX() + 25 * cos(owner->GetOrientation()), owner->GetPositionY() + 25 * cos(owner->GetOrientation()), owner->GetPositionZ());

            _StinkerBrokenHeartTimer = 3.5 * IN_MILLISECONDS;
        }

        void UpdateAI(uint32 diff) override
        {
            if (_StinkerBrokenHeartTimer <= diff)
            {
                DoCast(SPELL_STINKER_BROKEN_HEART);
                me->setFaction(31);
            }
            _StinkerBrokenHeartTimer -= diff;
        }
    private:
        uint32 _StinkerBrokenHeartTimer;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_lonely_turkeyAI(creature);
    }
};


void AddSC_TW_pilgrim()
{
    new TW_spell_gen_turkey_tracker();
    new TW_spell_gen_feast_on();
    new TW_spell_gen_well_fed_pilgrims_bounty("TW_spell_gen_well_fed_pilgrims_bounty_ap", SPELL_A_SERVING_OF_TURKEY, SPELL_WELL_FED_AP);
    new TW_spell_gen_well_fed_pilgrims_bounty("TW_spell_gen_well_fed_pilgrims_bounty_zm", SPELL_A_SERVING_OF_CRANBERRIES, SPELL_WELL_FED_ZM);
    new TW_spell_gen_well_fed_pilgrims_bounty("TW_spell_gen_well_fed_pilgrims_bounty_hit", SPELL_A_SERVING_OF_STUFFING, SPELL_WELL_FED_HIT);
    new TW_spell_gen_well_fed_pilgrims_bounty("TW_spell_gen_well_fed_pilgrims_bounty_haste", SPELL_A_SERVING_OF_SWEET_POTATOES, SPELL_WELL_FED_HASTE);
    new TW_spell_gen_well_fed_pilgrims_bounty("TW_spell_gen_well_fed_pilgrims_bounty_spirit", SPELL_A_SERVING_OF_PIE, SPELL_WELL_FED_SPIRIT);
    new TW_spell_gen_on_plate_pilgrims_bounty("TW_spell_gen_on_plate_pilgrims_bounty_turkey", SPELL_ON_PLATE_TURKEY, SPELL_PASS_THE_TURKEY);
    new TW_spell_gen_on_plate_pilgrims_bounty("TW_spell_gen_on_plate_pilgrims_bounty_cranberries", SPELL_ON_PLATE_CRANBERRIES, SPELL_PASS_THE_CRANBERRIES);
    new TW_spell_gen_on_plate_pilgrims_bounty("TW_spell_gen_on_plate_pilgrims_bounty_stuffing", SPELL_ON_PLATE_STUFFING, SPELL_PASS_THE_STUFFING);
    new TW_spell_gen_on_plate_pilgrims_bounty("TW_spell_gen_on_plate_pilgrims_bounty_sweet_potatoes", SPELL_ON_PLATE_SWEET_POTATOES, SPELL_PASS_THE_SWEET_POTATOES);
    new TW_spell_gen_on_plate_pilgrims_bounty("TW_spell_gen_on_plate_pilgrims_bounty_pie", SPELL_ON_PLATE_PIE, SPELL_PASS_THE_PIE);
    new TW_spell_gen_bountiful_feast();
    new TW_spell_pilgrims_bounty_buff_food("TW_spell_gen_slow_roasted_turkey", SPELL_WELL_FED_AP_TRIGGER);
    new TW_spell_pilgrims_bounty_buff_food("TW_spell_gen_cranberry_chutney", SPELL_WELL_FED_ZM_TRIGGER);
    new TW_spell_pilgrims_bounty_buff_food("TW_spell_gen_spice_bread_stuffing", SPELL_WELL_FED_HIT_TRIGGER);
    new TW_spell_pilgrims_bounty_buff_food("TW_spell_gen_pumpkin_pie", SPELL_WELL_FED_SPIRIT_TRIGGER);
    new TW_spell_pilgrims_bounty_buff_food("TW_spell_gen_candied_sweet_potato", SPELL_WELL_FED_HASTE_TRIGGER);
    new TW_achievement_food_fight();
    new TW_npc_lonely_turkey();
}