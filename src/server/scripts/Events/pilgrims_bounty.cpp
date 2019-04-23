/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "MoveSplineInit.h"
#include "ObjectMgr.h"
#include "PassiveAI.h"
#include "ScriptMgr.h"
#include "ScriptedEscortAI.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "Vehicle.h"
#include "World.h"

// Achievement: The Turkinator
enum WildTurkey
{
    SPELL_TURKEY_TRACKER        = 62014,
};

class npc_wild_turkey : public CreatureScript
{
public:
    npc_wild_turkey() : CreatureScript("npc_wild_turkey") { }

    struct npc_wild_turkeyAI : public ScriptedAI
    {
        npc_wild_turkeyAI(Creature* creature) : ScriptedAI(creature) {}

        void JustDied(Unit* killer) override
        {
            if (killer && killer->GetTypeId() == TYPEID_PLAYER)
                killer->CastSpell(killer, SPELL_TURKEY_TRACKER);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_wild_turkeyAI(creature);
    }
};

// Item: Turkey Caller
enum LonelyTurkey
{
    SPELL_STINKER_BROKEN_HEART  = 62004,
};

class npc_lonely_turkey : public CreatureScript
{
public:
    npc_lonely_turkey() : CreatureScript("npc_lonely_turkey") { }

    struct npc_lonely_turkeyAI : public ScriptedAI
    {
        npc_lonely_turkeyAI(Creature* creature) : ScriptedAI(creature) {}

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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lonely_turkeyAI(creature);
    }
};

enum BountifulTable
{
    SEAT_TURKEY_CHAIR                       = 0,
    SEAT_CRANBERRY_CHAIR                    = 1,
    SEAT_STUFFING_CHAIR                     = 2,
    SEAT_SWEET_POTATO_CHAIR                 = 3,
    SEAT_PIE_CHAIR                          = 4,
    SEAT_FOOD_HOLDER                        = 5,
    SEAT_PLATE_HOLDER                       = 6,
    NPC_THE_TURKEY_CHAIR                    = 34812,
    NPC_THE_CRANBERRY_CHAIR                 = 34823,
    NPC_THE_STUFFING_CHAIR                  = 34819,
    NPC_THE_SWEET_POTATO_CHAIR              = 34824,
    NPC_THE_PIE_CHAIR                       = 34822,
    SPELL_CRANBERRY_SERVER                  = 61793,
    SPELL_PIE_SERVER                        = 61794,
    SPELL_STUFFING_SERVER                   = 61795,
    SPELL_TURKEY_SERVER                     = 61796,
    SPELL_SWEET_POTATOES_SERVER             = 61797
};

typedef std::unordered_map<uint32 /*Entry*/, uint32 /*Spell*/> ChairSpells;
ChairSpells const _chairSpells =
{
    { NPC_THE_CRANBERRY_CHAIR, SPELL_CRANBERRY_SERVER },
    { NPC_THE_PIE_CHAIR, SPELL_PIE_SERVER },
    { NPC_THE_STUFFING_CHAIR, SPELL_STUFFING_SERVER },
    { NPC_THE_TURKEY_CHAIR, SPELL_TURKEY_SERVER },
    { NPC_THE_SWEET_POTATO_CHAIR, SPELL_SWEET_POTATOES_SERVER },
};

class CastFoodSpell : public BasicEvent
{
    public:
        CastFoodSpell(Unit* owner, uint32 spellId) : _owner(owner), _spellId(spellId) { }

        bool Execute(uint64 /*execTime*/, uint32 /*diff*/) override
        {
            _owner->CastSpell(_owner, _spellId, true);
            return false;
        }

    private:
        Unit* _owner;
        uint32 _spellId;
};

class npc_bountiful_table : public CreatureScript
{
public:
    npc_bountiful_table() : CreatureScript("npc_bountiful_table") { }

    struct npc_bountiful_tableAI : public PassiveAI
    {
        npc_bountiful_tableAI(Creature* creature) : PassiveAI(creature) { }

        void PassengerBoarded(Unit* who, int8 seatId, bool /*apply*/) override
        {
            float x = 0.0f;
            float y = 0.0f;
            float z = 0.0f;
            float o = 0.0f;

            switch (seatId)
            {
                case SEAT_TURKEY_CHAIR:
                    x = 3.87f;
                    y = 2.07f;
                    o = 3.700098f;
                    break;
                case SEAT_CRANBERRY_CHAIR:
                    x = 3.87f;
                    y = -2.07f;
                    o = 2.460914f;
                    break;
                case SEAT_STUFFING_CHAIR:
                    x = -2.52f;
                    break;
                case SEAT_SWEET_POTATO_CHAIR:
                    x = -0.09f;
                    y = -3.24f;
                    o = 1.186824f;
                    break;
                case SEAT_PIE_CHAIR:
                    x = -0.18f;
                    y = 3.24f;
                    o = 5.009095f;
                    break;
                case SEAT_FOOD_HOLDER:
                case SEAT_PLATE_HOLDER:
                    if (Vehicle* holders = who->GetVehicleKit())
                        holders->InstallAllAccessories(true);
                    return;
                default:
                    break;
            }

            Movement::MoveSplineInit init(who);
            init.DisableTransportPathTransformations();
            init.MoveTo(x, y, z, false);
            init.SetFacing(o);
            init.Launch();
            who->m_Events.AddEvent(new CastFoodSpell(who, _chairSpells.at(who->GetEntry())), who->m_Events.CalculateTime(1000));
            if (Creature* creature = who->ToCreature())
                creature->SetDisplayFromModel(0);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bountiful_tableAI(creature);
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

class spell_pilgrims_bounty_buff_food : public SpellScriptLoader
{
    private:
        uint32 const _triggeredSpellId;
    public:
        spell_pilgrims_bounty_buff_food(const char* name, uint32 triggeredSpellId) : SpellScriptLoader(name), _triggeredSpellId(triggeredSpellId) { }

        class spell_pilgrims_bounty_buff_food_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pilgrims_bounty_buff_food_AuraScript);
        private:
            uint32 const _triggeredSpellId;

        public:
            spell_pilgrims_bounty_buff_food_AuraScript(uint32 triggeredSpellId) : AuraScript(), _triggeredSpellId(triggeredSpellId)
            {
                _handled = false;
            }

            void HandleTriggerSpell(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                if (_handled)
                    return;

                _handled = true;
                GetTarget()->CastSpell(GetTarget(), _triggeredSpellId, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_pilgrims_bounty_buff_food_AuraScript::HandleTriggerSpell, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }

            bool _handled;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pilgrims_bounty_buff_food_AuraScript(_triggeredSpellId);
        }
};

enum FeastOnSpells
{
    FEAST_ON_TURKEY                     = 61784,
    FEAST_ON_CRANBERRIES                = 61785,
    FEAST_ON_SWEET_POTATOES             = 61786,
    FEAST_ON_PIE                        = 61787,
    FEAST_ON_STUFFING                   = 61788,
    SPELL_CRANBERRY_HELPINS             = 61841,
    SPELL_TURKEY_HELPINS                = 61842,
    SPELL_STUFFING_HELPINS              = 61843,
    SPELL_SWEET_POTATO_HELPINS          = 61844,
    SPELL_PIE_HELPINS                   = 61845,
    SPELL_ON_PLATE_EAT_VISUAL           = 61826
};

class spell_pilgrims_bounty_feast_on : public SpellScriptLoader
{
    public:
        spell_pilgrims_bounty_feast_on() : SpellScriptLoader("spell_pilgrims_bounty_feast_on") { }

        class spell_pilgrims_bounty_feast_on_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pilgrims_bounty_feast_on_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();

                uint32 _spellId = 0;
                switch (GetSpellInfo()->Id)
                {
                    case FEAST_ON_TURKEY:
                        _spellId = SPELL_TURKEY_HELPINS;
                        break;
                    case FEAST_ON_CRANBERRIES:
                        _spellId = SPELL_CRANBERRY_HELPINS;
                        break;
                    case FEAST_ON_SWEET_POTATOES:
                        _spellId = SPELL_SWEET_POTATO_HELPINS;
                        break;
                    case FEAST_ON_PIE:
                        _spellId = SPELL_PIE_HELPINS;
                        break;
                    case FEAST_ON_STUFFING:
                        _spellId = SPELL_STUFFING_HELPINS;
                        break;
                    default:
                        return;
                }

                if (Vehicle* vehicle = caster->GetVehicleKit())
                    if (Unit* target = vehicle->GetPassenger(0))
                        if (Player* player = target->ToPlayer())
                        {
                            player->CastSpell(player, SPELL_ON_PLATE_EAT_VISUAL, true);
                            caster->CastSpell(player, _spellId, true, NULL, NULL, player->GetGUID());
                        }

                if (Aura* aura = caster->GetAura(GetEffectValue()))
                {
                    if (aura->GetStackAmount() == 1)
                        if (SpellEffectInfo const* effect = aura->GetSpellInfo()->GetEffect(EFFECT_0))
                            caster->RemoveAurasDueToSpell(effect->CalcValue());
                    aura->ModStackAmount(-1);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pilgrims_bounty_feast_on_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pilgrims_bounty_feast_on_SpellScript();
        }
};

enum TheTurkinator
{
    SPELL_KILL_COUNTER_VISUAL       = 62015,
    SPELL_KILL_COUNTER_VISUAL_MAX   = 62021,
    EMOTE_TURKEY_HUNTER             = 0,
    EMOTE_TURKEY_DOMINATION         = 1,
    EMOTE_TURKEY_SLAUGHTER          = 2,
    EMOTE_TURKEY_TRIUMPH            = 3
};

class spell_pilgrims_bounty_turkey_tracker : public SpellScriptLoader
{
    public:
        spell_pilgrims_bounty_turkey_tracker() : SpellScriptLoader("spell_pilgrims_bounty_turkey_tracker") { }

        class spell_pilgrims_bounty_turkey_tracker_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pilgrims_bounty_turkey_tracker_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_KILL_COUNTER_VISUAL, SPELL_KILL_COUNTER_VISUAL_MAX });
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Creature* caster = GetCaster()->ToCreature();
                Unit* target = GetHitUnit();

                if (!target || !caster)
                    return;

                if (target->HasAura(SPELL_KILL_COUNTER_VISUAL_MAX))
                    return;

                if (Aura const* aura = target->GetAura(GetSpellInfo()->Id))
                {
                    switch (aura->GetStackAmount())
                    {
                        case 10:
                            caster->AI()->Talk(EMOTE_TURKEY_HUNTER, target);
                            break;
                        case 20:
                            caster->AI()->Talk(EMOTE_TURKEY_DOMINATION, target);
                            break;
                        case 30:
                            caster->AI()->Talk(EMOTE_TURKEY_SLAUGHTER, target);
                            break;
                        case 40:
                            caster->AI()->Talk(EMOTE_TURKEY_TRIUMPH, target);
                            target->CastSpell(target, SPELL_KILL_COUNTER_VISUAL_MAX, true);
                            target->RemoveAurasDueToSpell(GetSpellInfo()->Id);
                            break;
                        default:
                            return;
                    }
                    target->CastSpell(target, SPELL_KILL_COUNTER_VISUAL, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pilgrims_bounty_turkey_tracker_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pilgrims_bounty_turkey_tracker_SpellScript();
        }
};

enum SpiritOfSharing
{
    SPELL_THE_SPIRIT_OF_SHARING    = 61849
};

class spell_pilgrims_bounty_well_fed : public SpellScriptLoader
{
    private:
        uint32 _triggeredSpellId;

    public:
        spell_pilgrims_bounty_well_fed(const char* name, uint32 triggeredSpellId) : SpellScriptLoader(name), _triggeredSpellId(triggeredSpellId) { }

        class spell_pilgrims_bounty_well_fed_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pilgrims_bounty_well_fed_SpellScript);
        private:
            uint32 _triggeredSpellId;

        public:
            spell_pilgrims_bounty_well_fed_SpellScript(uint32 triggeredSpellId) : SpellScript(), _triggeredSpellId(triggeredSpellId) { }

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ _triggeredSpellId });
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                Player* target = GetHitPlayer();
                if (!target)
                    return;

                if (Aura const* aura = target->GetAura(GetSpellInfo()->Id))
                {
                    if (aura->GetStackAmount() == 5)
                        target->CastSpell(target, _triggeredSpellId, true);
                }

                Aura const* turkey = target->GetAura(SPELL_TURKEY_HELPINS);
                Aura const* cranberies = target->GetAura(SPELL_CRANBERRY_HELPINS);
                Aura const* stuffing = target->GetAura(SPELL_STUFFING_HELPINS);
                Aura const* sweetPotatoes = target->GetAura(SPELL_SWEET_POTATO_HELPINS);
                Aura const* pie = target->GetAura(SPELL_PIE_HELPINS);

                if ((turkey && turkey->GetStackAmount() == 5) && (cranberies && cranberies->GetStackAmount() == 5) && (stuffing && stuffing->GetStackAmount() == 5)
                    && (sweetPotatoes && sweetPotatoes->GetStackAmount() == 5) && (pie && pie->GetStackAmount() == 5))
                {
                    target->CastSpell(target, SPELL_THE_SPIRIT_OF_SHARING, true);
                    target->RemoveAurasDueToSpell(SPELL_TURKEY_HELPINS);
                    target->RemoveAurasDueToSpell(SPELL_CRANBERRY_HELPINS);
                    target->RemoveAurasDueToSpell(SPELL_STUFFING_HELPINS);
                    target->RemoveAurasDueToSpell(SPELL_SWEET_POTATO_HELPINS);
                    target->RemoveAurasDueToSpell(SPELL_PIE_HELPINS);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pilgrims_bounty_well_fed_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pilgrims_bounty_well_fed_SpellScript(_triggeredSpellId);
        }
};

enum BountifulTableMisc
{
    SEAT_PLAYER                             = 0,
    NPC_BOUNTIFUL_TABLE                     = 32823,
    SPELL_ON_PLATE_TURKEY                   = 61928,
    SPELL_ON_PLATE_CRANBERRIES              = 61925,
    SPELL_ON_PLATE_STUFFING                 = 61927,
    SPELL_ON_PLATE_SWEET_POTATOES           = 61929,
    SPELL_ON_PLATE_PIE                      = 61926,
    SPELL_PASS_THE_TURKEY                   = 66373,
    SPELL_PASS_THE_CRANBERRIES              = 66372,
    SPELL_PASS_THE_STUFFING                 = 66375,
    SPELL_PASS_THE_SWEET_POTATOES           = 66376,
    SPELL_PASS_THE_PIE                      = 66374,
    SPELL_ON_PLATE_VISUAL_PIE               = 61825,
    SPELL_ON_PLATE_VISUAL_CRANBERRIES       = 61821,
    SPELL_ON_PLATE_VISUAL_POTATOES          = 61824,
    SPELL_ON_PLATE_VISUAL_TURKEY            = 61822,
    SPELL_ON_PLATE_VISUAL_STUFFING          = 61823,
    SPELL_A_SERVING_OF_CRANBERRIES_PLATE    = 61833,
    SPELL_A_SERVING_OF_TURKEY_PLATE         = 61835,
    SPELL_A_SERVING_OF_STUFFING_PLATE       = 61836,
    SPELL_A_SERVING_OF_SWEET_POTATOES_PLATE = 61837,
    SPELL_A_SERVING_OF_PIE_PLATE            = 61838,
    SPELL_A_SERVING_OF_CRANBERRIES_CHAIR    = 61804,
    SPELL_A_SERVING_OF_TURKEY_CHAIR         = 61807,
    SPELL_A_SERVING_OF_STUFFING_CHAIR       = 61806,
    SPELL_A_SERVING_OF_SWEET_POTATOES_CHAIR = 61808,
    SPELL_A_SERVING_OF_PIE_CHAIR            = 61805
};

/* 66250 - Pass The Turkey
   66259 - Pass The Stuffing
   66260 - Pass The Pie
   66261 - Pass The Cranberries
   66262 - Pass The Sweet Potatoes */
class spell_pilgrims_bounty_on_plate : public SpellScriptLoader
{
    private:
        uint32 _triggeredSpellId1;
        uint32 _triggeredSpellId2;
        uint32 _triggeredSpellId3;
        uint32 _triggeredSpellId4;

    public:
        spell_pilgrims_bounty_on_plate(const char* name, uint32 triggeredSpellId1, uint32 triggeredSpellId2, uint32 triggeredSpellId3, uint32 triggeredSpellId4) : SpellScriptLoader(name),
            _triggeredSpellId1(triggeredSpellId1), _triggeredSpellId2(triggeredSpellId2), _triggeredSpellId3(triggeredSpellId3), _triggeredSpellId4(triggeredSpellId4) { }

        class spell_pilgrims_bounty_on_plate_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pilgrims_bounty_on_plate_SpellScript);
        private:
            uint32 _triggeredSpellId1;
            uint32 _triggeredSpellId2;
            uint32 _triggeredSpellId3;
            uint32 _triggeredSpellId4;

        public:
            spell_pilgrims_bounty_on_plate_SpellScript(uint32 triggeredSpellId1, uint32 triggeredSpellId2, uint32 triggeredSpellId3, uint32 triggeredSpellId4) : SpellScript(),
                _triggeredSpellId1(triggeredSpellId1), _triggeredSpellId2(triggeredSpellId2), _triggeredSpellId3(triggeredSpellId3), _triggeredSpellId4(triggeredSpellId4) { }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    _triggeredSpellId1,
                    _triggeredSpellId2,
                    _triggeredSpellId3,
                    _triggeredSpellId4
                });
            }

            Vehicle* GetTable(Unit* target)
            {
                if (target->GetTypeId() == TYPEID_PLAYER)
                {
                    if (Unit* vehBase = target->GetVehicleBase())
                        if (Vehicle* table = vehBase->GetVehicle())
                            if (table->GetCreatureEntry() == NPC_BOUNTIFUL_TABLE)
                                return table;
                }
                else if (Vehicle* veh = target->GetVehicle())
                    if (veh->GetCreatureEntry() == NPC_BOUNTIFUL_TABLE)
                        return veh;

                return nullptr;
            }

            Unit* GetPlateInSeat(Vehicle* table, uint8 seat)
            {
                if (Unit* holderUnit = table->GetPassenger(SEAT_PLATE_HOLDER))
                    if (Vehicle* holder = holderUnit->GetVehicleKit())
                        if (Unit* plate = holder->GetPassenger(seat))
                            return plate;

                return nullptr;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                Unit* target = GetHitUnit();
                if (!target || caster == target)
                    return;

                Vehicle* table = GetTable(caster);
                if (!table || table != GetTable(target))
                    return;

                if (Vehicle* casterChair = caster->GetVehicleKit())
                    if (Unit* casterPlr = casterChair->GetPassenger(SEAT_PLAYER))
                    {
                        if (casterPlr == target)
                            return;

                        casterPlr->CastSpell(casterPlr, _triggeredSpellId2, true); //Credit for Sharing is Caring(always)

                        uint8 seat = target->GetTransSeat();
                        if (target->GetTypeId() == TYPEID_PLAYER && target->GetVehicleBase())
                            seat = target->GetVehicleBase()->GetTransSeat();

                        if (Unit* plate = GetPlateInSeat(table, seat))
                        {
                            if (target->GetTypeId() == TYPEID_PLAYER) //Food Fight case
                            {
                                casterPlr->CastSpell(target, _triggeredSpellId1, true);
                                caster->CastSpell(target->GetVehicleBase(), _triggeredSpellId4, true); //CanEat-chair(always)
                            }
                            else
                            {
                                casterPlr->CastSpell(plate, _triggeredSpellId3, true); //Food Visual on plate
                                caster->CastSpell(target, _triggeredSpellId4, true); //CanEat-chair(always)
                            }
                        }
                    }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pilgrims_bounty_on_plate_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pilgrims_bounty_on_plate_SpellScript(_triggeredSpellId1, _triggeredSpellId2, _triggeredSpellId3, _triggeredSpellId4);
        }
};

/* 61804 - A Serving of Cranberries
   61805 - A Serving of Pie
   61806 - A Serving of Stuffing
   61807 - A Serving of Turkey
   61808 - A Serving of Sweet Potatoes
   61793 - Cranberry Server
   61794 - Pie Server
   61795 - Stuffing Server
   61796 - Turkey Server
   61797 - Sweet Potatoes Server */
class spell_pilgrims_bounty_a_serving_of : public SpellScriptLoader
{
    private:
        uint32 _triggeredSpellId;
    public:
        spell_pilgrims_bounty_a_serving_of(const char* name, uint32 triggeredSpellId) : SpellScriptLoader(name), _triggeredSpellId(triggeredSpellId) { }

        class spell_pilgrims_bounty_a_serving_of_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pilgrims_bounty_a_serving_of_AuraScript);

        private:
            uint32 _triggeredSpellId;

        public:
            spell_pilgrims_bounty_a_serving_of_AuraScript(uint32 triggeredSpellId) : AuraScript(), _triggeredSpellId(triggeredSpellId) { }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ _triggeredSpellId });
            }

            void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                target->CastSpell(target, uint32(aurEff->GetBaseAmount()), true);
                HandlePlate(target, true);
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                target->RemoveAurasDueToSpell(aurEff->GetBaseAmount());
                HandlePlate(target, false);
            }

            void HandlePlate(Unit* target, bool apply)
            {
                if (Vehicle* table = target->GetVehicle())
                    if (Unit* holderUnit = table->GetPassenger(SEAT_PLATE_HOLDER))
                        if (Vehicle* holder = holderUnit->GetVehicleKit())
                            if (Unit* plate = holder->GetPassenger(target->GetTransSeat()))
                            {
                                if (apply)
                                    target->CastSpell(plate, _triggeredSpellId, true);
                                else
                                    plate->RemoveAurasDueToSpell(_triggeredSpellId);
                            }
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_pilgrims_bounty_a_serving_of_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_pilgrims_bounty_a_serving_of_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pilgrims_bounty_a_serving_of_AuraScript(_triggeredSpellId);
        }
};

class achievement_food_fight : public AchievementCriteriaScript
{
public:
    achievement_food_fight() : AchievementCriteriaScript("achievement_food_fight") { }

    bool OnCheck(Player* /*source*/, Unit* target) override
    {
        if (!target)
            return false;

        if (Player* victim = target->ToPlayer())
        {
            if (Vehicle* vehicle = victim->GetVehicle())
                if (vehicle->GetVehicleInfo()->ID == 321)
                    return true;
        }

        return false;
    }
};

void AddSC_event_pilgrims_bounty()
{
    // Npc
    new npc_wild_turkey();
    new npc_lonely_turkey();
    new npc_bountiful_table();

    // Spells
    new spell_pilgrims_bounty_buff_food("spell_gen_slow_roasted_turkey", SPELL_WELL_FED_AP_TRIGGER);
    new spell_pilgrims_bounty_buff_food("spell_gen_cranberry_chutney", SPELL_WELL_FED_ZM_TRIGGER);
    new spell_pilgrims_bounty_buff_food("spell_gen_spice_bread_stuffing", SPELL_WELL_FED_HIT_TRIGGER);
    new spell_pilgrims_bounty_buff_food("spell_gen_pumpkin_pie", SPELL_WELL_FED_SPIRIT_TRIGGER);
    new spell_pilgrims_bounty_buff_food("spell_gen_candied_sweet_potato", SPELL_WELL_FED_HASTE_TRIGGER);
    new spell_pilgrims_bounty_feast_on();
    new spell_pilgrims_bounty_well_fed("spell_pilgrims_bounty_well_fed_turkey", SPELL_WELL_FED_AP_TRIGGER);
    new spell_pilgrims_bounty_well_fed("spell_pilgrims_bounty_well_fed_cranberry", SPELL_WELL_FED_ZM_TRIGGER);
    new spell_pilgrims_bounty_well_fed("spell_pilgrims_bounty_well_fed_stuffing", SPELL_WELL_FED_HIT_TRIGGER);
    new spell_pilgrims_bounty_well_fed("spell_pilgrims_bounty_well_fed_sweet_potatoes", SPELL_WELL_FED_HASTE_TRIGGER);
    new spell_pilgrims_bounty_well_fed("spell_pilgrims_bounty_well_fed_pie", SPELL_WELL_FED_SPIRIT_TRIGGER);
    new spell_pilgrims_bounty_turkey_tracker();
    new spell_pilgrims_bounty_on_plate("spell_pilgrims_bounty_on_plate_turkey", SPELL_ON_PLATE_TURKEY, SPELL_PASS_THE_TURKEY, SPELL_ON_PLATE_VISUAL_TURKEY, SPELL_A_SERVING_OF_TURKEY_CHAIR);
    new spell_pilgrims_bounty_on_plate("spell_pilgrims_bounty_on_plate_cranberries", SPELL_ON_PLATE_CRANBERRIES, SPELL_PASS_THE_CRANBERRIES, SPELL_ON_PLATE_VISUAL_CRANBERRIES, SPELL_A_SERVING_OF_CRANBERRIES_CHAIR);
    new spell_pilgrims_bounty_on_plate("spell_pilgrims_bounty_on_plate_stuffing", SPELL_ON_PLATE_STUFFING, SPELL_PASS_THE_STUFFING, SPELL_ON_PLATE_VISUAL_STUFFING, SPELL_A_SERVING_OF_STUFFING_CHAIR);
    new spell_pilgrims_bounty_on_plate("spell_pilgrims_bounty_on_plate_sweet_potatoes", SPELL_ON_PLATE_SWEET_POTATOES, SPELL_PASS_THE_SWEET_POTATOES, SPELL_ON_PLATE_VISUAL_POTATOES, SPELL_A_SERVING_OF_SWEET_POTATOES_CHAIR);
    new spell_pilgrims_bounty_on_plate("spell_pilgrims_bounty_on_plate_pie", SPELL_ON_PLATE_PIE, SPELL_PASS_THE_PIE, SPELL_ON_PLATE_VISUAL_PIE, SPELL_A_SERVING_OF_PIE_CHAIR);
    new spell_pilgrims_bounty_a_serving_of("spell_pilgrims_bounty_a_serving_of_cranberries", SPELL_A_SERVING_OF_CRANBERRIES_PLATE);
    new spell_pilgrims_bounty_a_serving_of("spell_pilgrims_bounty_a_serving_of_turkey", SPELL_A_SERVING_OF_TURKEY_PLATE);
    new spell_pilgrims_bounty_a_serving_of("spell_pilgrims_bounty_a_serving_of_stuffing", SPELL_A_SERVING_OF_STUFFING_PLATE);
    new spell_pilgrims_bounty_a_serving_of("spell_pilgrims_bounty_a_serving_of_potatoes", SPELL_A_SERVING_OF_SWEET_POTATOES_PLATE);
    new spell_pilgrims_bounty_a_serving_of("spell_pilgrims_bounty_a_serving_of_pie", SPELL_A_SERVING_OF_PIE_PLATE);

    // Achievements
    new achievement_food_fight();
}
