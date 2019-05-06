/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "CombatAI.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "oculus.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "Vehicle.h"

enum GossipNPCs
{
    GOSSIP_MENU_VERDISA                 = 9573,
    GOSSIP_MENU_ETERNOS                 = 9574,
    GOSSIP_MENU_BELGARISTRASZ           = 9575,

    SPELL_CREATE_EMERALD_ESSENCE        = 49382, // no effects in spell_dbc
    SPELL_CREATE_AMBER_ESSENCE          = 49447, // no effects in spell_dbc
    SPELL_CREATE_RUBY_ESSENCE           = 49450, // no effects in spell_dbc
    ITEM_EMERALD_ESSENCE                = 37815,
    ITEM_AMBER_ESSENCE                  = 37859,
    ITEM_RUBY_ESSENCE                   = 37860
};

enum Drakes
{
/*
 * Ruby Drake (27756)
 * (summoned by spell Ruby Essence (37860) --> Call Amber Drake (49462) --> Summon 27756)
 */
    SPELL_RIDE_RUBY_DRAKE_QUE           = 49463,          // Apply Aura: Periodic Trigger, Interval: 3 seconds --> 49464
    SPELL_RUBY_DRAKE_SADDLE             = 49464,          // Allows you to ride on the back of an Amber Drake. --> Dummy
    SPELL_RUBY_SEARING_WRATH            = 50232,          // (60 yds) - Instant - Breathes a stream of fire at an enemy dragon, dealing 6800 to 9200 Fire damage and then jumping to additional dragons within 30 yards. Each jump increases the damage by 50%. Affects up to 5 total targets
    SPELL_RUBY_EVASIVE_AURA             = 50248,          // Instant - Allows the Ruby Drake to generate Evasive Charges when hit by hostile attacks and spells.
    SPELL_RUBY_EVASIVE_CHARGES          = 50241,
    SPELL_RUBY_EVASIVE_MANEUVERS        = 50240,          // Instant - 5 sec. cooldown - Allows your drake to dodge all incoming attacks and spells. Requires Evasive Charges to use. Each attack or spell dodged while this ability is active burns one Evasive Charge. Lasts 30 sec. or until all charges are exhausted.
    // you do not have access to until you kill the Mage-Lord Urom
    SPELL_RUBY_MARTYR                   = 50253,          // Instant - 10 sec. cooldown - Redirect all harmful spells cast at friendly drakes to yourself for 10 sec.

/*
 * Amber Drake (27755)
 * (summoned by spell Amber Essence (37859) --> Call Amber Drake (49461) --> Summon 27755)
 */
    SPELL_RIDE_AMBER_DRAKE_QUE          = 49459,          // Apply Aura: Periodic Trigger, Interval: 3 seconds --> 49460
    SPELL_AMBER_DRAKE_SADDLE            = 49460,          // Allows you to ride on the back of an Amber Drake. --> Dummy
    SPELL_AMBER_SHOCK_CHARGE            = 49836,
    SPELL_AMBER_SHOCK_LANCE             = 49840,          // (60 yds) - Instant - Deals 4822 to 5602 Arcane damage and detonates all Shock Charges on an enemy dragon. Damage is increased by 6525 for each detonated.
    SPELL_AMBER_STOP_TIME               = 49838,          // Instant - 1 min cooldown - Halts the passage of time, freezing all enemy dragons in place for 10 sec. This attack applies 5 Shock Charges to each affected target.
    // you do not have access to until you kill the Mage-Lord Urom.
    SPELL_AMBER_TEMPORAL_RIFT           = 49592,          // (60 yds) - Channeled - Channels a temporal rift on an enemy dragon for 10 sec. While trapped in the rift, all damage done to the target is increased by 100%. In addition, for every 15, 000 damage done to a target affected by Temporal Rift, 1 Shock Charge is generated.

/*
 * Emerald Drake (27692)
 * (summoned by spell Emerald Essence (37815) --> Call Emerald Drake (49345) --> Summon 27692)
 */
    SPELL_RIDE_EMERALD_DRAKE_QUE        = 49427,         // Apply Aura: Periodic Trigger, Interval: 3 seconds --> 49346
    SPELL_EMERALD_DRAKE_SADDLE          = 49346,         // Allows you to ride on the back of an Amber Drake. --> Dummy
    SPELL_EMERALD_LEECHING_POISON       = 50328,         // (60 yds) - Instant - Poisons the enemy dragon, leeching 1300 to the caster every 2 sec. for 12 sec. Stacks up to 3 times.
    SPELL_EMERALD_TOUCH_THE_NIGHTMARE   = 50341,         // (60 yds) - Instant - Consumes 30% of the caster's max health to inflict 25, 000 nature damage to an enemy dragon and reduce the damage it deals by 25% for 30 sec.
    // you do not have access to until you kill the Mage-Lord Urom
    SPELL_EMERALD_DREAM_FUNNEL          = 50344,         // (60 yds) - Channeled - Transfers 5% of the caster's max health to a friendly drake every second for 10 seconds as long as the caster channels.
/*
 * All Drakes
 * GPS System
 */
    SPELL_GPS                           = 53389,

    // Misc
    POINT_LAND                          = 2,
    POINT_TAKE_OFF                      = 3
};

enum DrakeEvents
{
    EVENT_WELCOME = 1,
    EVENT_ABILITIES,
    EVENT_SPECIAL_ATTACK,
    EVENT_LOW_HEALTH,
    EVENT_RESET_LOW_HEALTH,
    EVENT_TAKE_OFF
};

enum Says
{
    SAY_VAROS                         = 0,
    SAY_UROM                          = 1,
    SAY_BELGARISTRASZ                 = 0,
    SAY_DRAKES_TAKEOFF                = 0,
    WHISPER_DRAKES_WELCOME            = 1,
    WHISPER_DRAKES_ABILITIES          = 2,
    WHISPER_DRAKES_SPECIAL            = 3,
    WHISPER_DRAKES_LOWHEALTH          = 4,
    WHISPER_GPS_10_CONSTRUCTS         = 5,
    WHISPER_GPS_1_CONSTRUCT           = 6,
    WHISPER_GPS_VAROS                 = 7,
    WHISPER_GPS_UROM                  = 8,
    WHISPER_GPS_EREGOS                = 9,
    WHISPER_GPS_END                   = 10
};

class npc_verdisa_beglaristrasz_eternos : public CreatureScript
{
    public:
        npc_verdisa_beglaristrasz_eternos() : CreatureScript("npc_verdisa_beglaristrasz_eternos") { }

        struct npc_verdisa_beglaristrasz_eternosAI : public ScriptedAI
        {
            npc_verdisa_beglaristrasz_eternosAI(Creature* creature) : ScriptedAI(creature) { }

            void StoreEssence(Player* player, uint32 itemId)
            {
                /// @todo: implement with spells
                uint32 count = 1;
                ItemPosCountVec dest;
                uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, count);
                if (msg == EQUIP_ERR_OK)
                    if (Item* item = player->StoreNewItem(dest, itemId, true))
                        player->SendNewItem(item, count, true, true);
            }

            void RemoveEssence(Player* player, uint32 itemId)
            {
                player->DestroyItemCount(itemId, 1, true, false);
            }

            bool GossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
            {
                switch (menuId)
                {
                    case GOSSIP_MENU_VERDISA:
                        if (gossipListId >= 1 && gossipListId <= 3)
                        {
                            if (gossipListId == 2)
                                RemoveEssence(player, ITEM_AMBER_ESSENCE);
                            else if (gossipListId == 3)
                                RemoveEssence(player, ITEM_RUBY_ESSENCE);

                            StoreEssence(player, ITEM_EMERALD_ESSENCE);
                            break;
                        }
                        return false;
                    case GOSSIP_MENU_ETERNOS:
                        if (gossipListId >= 1 && gossipListId <= 3)
                        {
                            if (gossipListId == 2)
                                RemoveEssence(player, ITEM_EMERALD_ESSENCE);
                            else if (gossipListId == 3)
                                RemoveEssence(player, ITEM_RUBY_ESSENCE);

                            StoreEssence(player, ITEM_AMBER_ESSENCE);
                            break;
                        }
                        return false;
                    case GOSSIP_MENU_BELGARISTRASZ:
                        if (gossipListId <= 2)
                        {
                            if (gossipListId == 1)
                                RemoveEssence(player, ITEM_AMBER_ESSENCE);
                            else if (gossipListId == 2)
                                RemoveEssence(player, ITEM_EMERALD_ESSENCE);

                            StoreEssence(player, ITEM_RUBY_ESSENCE);
                            break;
                        }
                        return false;
                    default:
                        return false;
                }
                player->PlayerTalkClass->SendCloseGossip();
                return false;
            }

            void MovementInform(uint32 /*type*/, uint32 id) override
            {
                if (id != POINT_MOVE_OUT)
                    return;

                // When Belgaristraz finish his moving say grateful text
                if (me->GetEntry() == NPC_BELGARISTRASZ)
                    Talk(SAY_BELGARISTRASZ);

                // The gossip flag should activate when Drakos die and not from DB
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetOculusAI<npc_verdisa_beglaristrasz_eternosAI>(creature);
        }
};

class npc_image_belgaristrasz : public CreatureScript
{
    public:
        npc_image_belgaristrasz() : CreatureScript("npc_image_belgaristrasz") { }

        struct npc_image_belgaristraszAI : public ScriptedAI
        {
            npc_image_belgaristraszAI(Creature* creature) : ScriptedAI(creature) { }

            void IsSummonedBy(Unit* summoner) override
            {
                if (summoner->GetEntry() == NPC_VAROS)
                {
                   Talk(SAY_VAROS);
                   me->DespawnOrUnsummon(60000);
                }

                if (summoner->GetEntry() == NPC_UROM)
                {
                   Talk(SAY_UROM);
                   me->DespawnOrUnsummon(60000);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetOculusAI<npc_image_belgaristraszAI>(creature);
        }
};

class npc_ruby_emerald_amber_drake : public CreatureScript
{
    public:
        npc_ruby_emerald_amber_drake() : CreatureScript("npc_ruby_emerald_amber_drake") { }

        struct npc_ruby_emerald_amber_drakeAI : public VehicleAI
        {
            npc_ruby_emerald_amber_drakeAI(Creature* creature) : VehicleAI(creature)
            {
                Initialize();
                _instance = creature->GetInstanceScript();
            }

            void Initialize()
            {
                _healthWarning = true;
            }

            void Reset() override
            {
                _events.Reset();
                Initialize();
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
            {
                if (Unit* creator = ObjectAccessor::GetUnit(*me, me->GetCreatorGUID()))
                    if (spell->Id == SPELL_GPS)
                    {
                        if (_instance->GetBossState(DATA_EREGOS) == DONE)
                            Talk(WHISPER_GPS_END, creator);
                        else if (_instance->GetBossState(DATA_UROM) == DONE)
                            Talk(WHISPER_GPS_EREGOS, creator);
                        else if (_instance->GetBossState(DATA_VAROS) == DONE)
                            Talk(WHISPER_GPS_UROM, creator);
                        else if (_instance->GetData(DATA_CONSTRUCTS) == KILL_NO_CONSTRUCT)
                            Talk(WHISPER_GPS_VAROS, creator);
                        else if (_instance->GetData(DATA_CONSTRUCTS) == KILL_ONE_CONSTRUCT)
                            Talk(WHISPER_GPS_1_CONSTRUCT, creator);
                        else if (_instance->GetData(DATA_CONSTRUCTS) == KILL_MORE_CONSTRUCT)
                            Talk(WHISPER_GPS_10_CONSTRUCTS, creator);
                    }
            }

            void IsSummonedBy(Unit* summoner) override
            {
                if (_instance->GetBossState(DATA_EREGOS) == IN_PROGRESS)
                    if (Creature* eregos = me->FindNearestCreature(NPC_EREGOS, 450.0f, true))
                        eregos->DespawnOrUnsummon(); // On retail this kills abusive call of drake during engaged Eregos

                me->SetFacingToObject(summoner);

                switch (me->GetEntry())
                {
                    case NPC_RUBY_DRAKE_VEHICLE:
                        me->CastSpell(summoner, SPELL_RIDE_RUBY_DRAKE_QUE);
                        break;
                    case NPC_EMERALD_DRAKE_VEHICLE:
                        me->CastSpell(summoner, SPELL_RIDE_EMERALD_DRAKE_QUE);
                        break;
                    case NPC_AMBER_DRAKE_VEHICLE:
                        me->CastSpell(summoner, SPELL_RIDE_AMBER_DRAKE_QUE);
                        break;
                    default:
                        return;
                }

                Position pos = summoner->GetPosition();
                me->GetMotionMaster()->MovePoint(POINT_LAND, pos);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == POINT_MOTION_TYPE && id == POINT_LAND)
                    me->SetDisableGravity(false); // Needed this for proper animation after spawn, the summon in air fall to ground bug leave no other option for now, if this isn't used the drake will only walk on move.
            }

            void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
            {
                if (passenger->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (apply)
                {
                    if (_instance->GetBossState(DATA_VAROS) != DONE)
                        _events.ScheduleEvent(EVENT_WELCOME, 10s);

                    else if (_instance->GetBossState(DATA_UROM) == DONE)
                        _events.ScheduleEvent(EVENT_SPECIAL_ATTACK, 10s);
                }
                else
                {
                    _events.Reset();
                    _events.ScheduleEvent(EVENT_TAKE_OFF, 2s);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (_healthWarning)
                {
                    if (me->GetHealthPct() <= 40.0f)
                        _events.ScheduleEvent(EVENT_LOW_HEALTH, 0);
                }

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WELCOME:
                            if (Unit* creator = ObjectAccessor::GetUnit(*me, me->GetCreatorGUID()))
                                Talk(WHISPER_DRAKES_WELCOME, creator);
                            _events.ScheduleEvent(EVENT_ABILITIES, 5s);
                            break;
                        case EVENT_ABILITIES:
                            if (Unit* creator = ObjectAccessor::GetUnit(*me, me->GetCreatorGUID()))
                                Talk(WHISPER_DRAKES_ABILITIES, creator);
                            break;
                        case EVENT_SPECIAL_ATTACK:
                            if (Unit* creator = ObjectAccessor::GetUnit(*me, me->GetCreatorGUID()))
                                Talk(WHISPER_DRAKES_SPECIAL, creator);
                            break;
                        case EVENT_LOW_HEALTH:
                            if (Unit* creator = ObjectAccessor::GetUnit(*me, me->GetCreatorGUID()))
                                Talk(WHISPER_DRAKES_LOWHEALTH, creator);
                            _healthWarning = false;
                            _events.ScheduleEvent(EVENT_RESET_LOW_HEALTH, 25s);
                            break;
                        case EVENT_RESET_LOW_HEALTH:
                            _healthWarning = true;
                            break;
                        case EVENT_TAKE_OFF:
                        {
                            me->DespawnOrUnsummon(2050);
                            me->SetOrientation(2.5f);
                            me->SetSpeedRate(MOVE_FLIGHT, 1.0f);
                            Talk(SAY_DRAKES_TAKEOFF);
                            Position pos = me->GetPosition();
                            Position offset = { 10.0f, 10.0f, 12.0f, 0.0f };
                            pos.RelocateOffset(offset);
                            me->SetDisableGravity(true);
                            me->GetMotionMaster()->MovePoint(POINT_TAKE_OFF, pos);
                            break;
                        }
                        default:
                            break;
                    }
                }
            };

        private:
            InstanceScript* _instance;
            EventMap _events;
            bool _healthWarning;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetOculusAI<npc_ruby_emerald_amber_drakeAI>(creature);
        }
};

// 49345 - Call Emerald Drake
// 49461 - Call Amber Drake
// 49462 - Call Ruby Drake
class spell_oculus_call_ruby_emerald_amber_drake : public SpellScriptLoader
{
    public:
        spell_oculus_call_ruby_emerald_amber_drake() : SpellScriptLoader("spell_oculus_call_ruby_emerald_amber_drake") { }

        class spell_oculus_call_ruby_emerald_amber_drake_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_oculus_call_ruby_emerald_amber_drake_SpellScript);

            void SetDest(SpellDestination& dest)
            {
                // Adjust effect summon position
                Position const offset = { 0.0f, 0.0f, 12.0f, 0.0f };
                dest.RelocateOffset(offset);
            }

            void Register() override
            {
                OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_oculus_call_ruby_emerald_amber_drake_SpellScript::SetDest, EFFECT_0, TARGET_DEST_CASTER_FRONT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_oculus_call_ruby_emerald_amber_drake_SpellScript();
        }
};

// 49427 - Ride Emerald Drake Que
// 49459 - Ride Amber Drake Que
// 49463 - Ride Ruby Drake Que
class spell_oculus_ride_ruby_emerald_amber_drake_que : public SpellScriptLoader
{
    public:
        spell_oculus_ride_ruby_emerald_amber_drake_que() : SpellScriptLoader("spell_oculus_ride_ruby_emerald_amber_drake_que") { }

        class spell_oculus_ride_ruby_emerald_amber_drake_que_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_oculus_ride_ruby_emerald_amber_drake_que_AuraScript);

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                // caster of the triggered spell is wrong for an unknown reason, handle it here correctly
                PreventDefaultAction();
                if (Unit* caster = GetCaster())
                    GetTarget()->CastSpell(caster, GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_oculus_ride_ruby_emerald_amber_drake_que_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_oculus_ride_ruby_emerald_amber_drake_que_AuraScript();
        }
};

// 50240 - Evasive Maneuvers
class spell_oculus_evasive_maneuvers : public SpellScriptLoader
{
    public:
        spell_oculus_evasive_maneuvers() : SpellScriptLoader("spell_oculus_evasive_maneuvers") { }

        class spell_oculus_evasive_maneuvers_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_oculus_evasive_maneuvers_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_RUBY_EVASIVE_CHARGES });
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->RemoveAuraFromStack(SPELL_RUBY_EVASIVE_CHARGES);
                if (!GetTarget()->HasAura(SPELL_RUBY_EVASIVE_CHARGES))
                    Remove();
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_oculus_evasive_maneuvers_AuraScript::HandleProc, EFFECT_2, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_oculus_evasive_maneuvers_AuraScript();
        }
};

// 49840 - Shock Lance
class spell_oculus_shock_lance : public SpellScriptLoader
{
    public:
        spell_oculus_shock_lance() : SpellScriptLoader("spell_oculus_shock_lance") { }

        class spell_oculus_shock_lance_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_oculus_shock_lance_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_AMBER_SHOCK_CHARGE });
            }

            void CalcDamage(SpellEffIndex /*effIndex*/)
            {
                int32 damage = GetEffectValue();
                if (Unit* target = GetHitUnit())
                {
                    if (AuraEffect const* shockCharges = target->GetAuraEffect(SPELL_AMBER_SHOCK_CHARGE, EFFECT_0, GetCaster()->GetGUID()))
                    {
                        damage += shockCharges->GetAmount();
                        shockCharges->GetBase()->Remove(AURA_REMOVE_BY_ENEMY_SPELL);
                    }
                }

                SetEffectValue(damage);
            }

            void Register() override
            {
                OnEffectLaunchTarget += SpellEffectFn(spell_oculus_shock_lance_SpellScript::CalcDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_oculus_shock_lance_SpellScript();
        }
};

// 49838 - Stop Time
class spell_oculus_stop_time : public SpellScriptLoader
{
    public:
        spell_oculus_stop_time() : SpellScriptLoader("spell_oculus_stop_time") { }

        class spell_oculus_stop_time_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_oculus_stop_time_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_AMBER_SHOCK_CHARGE });
            }

            void Apply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                Unit* target = GetTarget();
                for (uint32 i = 0; i < 5; ++i)
                    caster->CastSpell(target, SPELL_AMBER_SHOCK_CHARGE, true);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_oculus_stop_time_AuraScript::Apply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_oculus_stop_time_AuraScript();
        }
};

// 49592 - Temporal Rift
class spell_oculus_temporal_rift : public SpellScriptLoader
{
    public:
        spell_oculus_temporal_rift() : SpellScriptLoader("spell_oculus_temporal_rift") { }

        class spell_oculus_temporal_rift_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_oculus_temporal_rift_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_AMBER_SHOCK_CHARGE });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return;

                int32 amount = aurEff->GetAmount() + damageInfo->GetDamage();
                if (amount >= 15000)
                {
                    if (Unit* caster = GetCaster())
                        caster->CastSpell(GetTarget(), SPELL_AMBER_SHOCK_CHARGE, true);
                    amount -= 15000;
                }

                const_cast<AuraEffect*>(aurEff)->SetAmount(amount);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_oculus_temporal_rift_AuraScript::HandleProc, EFFECT_2, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_oculus_temporal_rift_AuraScript();
        }
};

// 50341 - Touch the Nightmare
class spell_oculus_touch_the_nightmare : public SpellScriptLoader
{
    public:
        spell_oculus_touch_the_nightmare() : SpellScriptLoader("spell_oculus_touch_the_nightmare") { }

        class spell_oculus_touch_the_nightmare_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_oculus_touch_the_nightmare_SpellScript);

            void HandleDamageCalc(SpellEffIndex /*effIndex*/)
            {
                SetHitDamage(int32(GetCaster()->CountPctFromMaxHealth(30)));
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_oculus_touch_the_nightmare_SpellScript::HandleDamageCalc, EFFECT_2, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_oculus_touch_the_nightmare_SpellScript();
        }
};

// 50344 - Dream Funnel
class spell_oculus_dream_funnel : public SpellScriptLoader
{
    public:
        spell_oculus_dream_funnel() : SpellScriptLoader("spell_oculus_dream_funnel") { }

        class spell_oculus_dream_funnel_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_oculus_dream_funnel_AuraScript);

            void HandleEffectCalcAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
            {
                if (Unit* caster = GetCaster())
                    amount = int32(caster->CountPctFromMaxHealth(5));

                canBeRecalculated = false;
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_oculus_dream_funnel_AuraScript::HandleEffectCalcAmount, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_oculus_dream_funnel_AuraScript::HandleEffectCalcAmount, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_oculus_dream_funnel_AuraScript();
        }
};

void AddSC_oculus()
{
    new npc_verdisa_beglaristrasz_eternos();
    new npc_image_belgaristrasz();
    new npc_ruby_emerald_amber_drake();
    new spell_oculus_call_ruby_emerald_amber_drake();
    new spell_oculus_ride_ruby_emerald_amber_drake_que();
    new spell_oculus_evasive_maneuvers();
    new spell_oculus_shock_lance();
    new spell_oculus_stop_time();
    new spell_oculus_temporal_rift();
    new spell_oculus_touch_the_nightmare();
    new spell_oculus_dream_funnel();
}
