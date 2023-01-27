/*
 * Copyright 2021 ShadowCore
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

#include "AreaTriggerAI.h"
#include "CreatureTextMgr.h"
#include "DB2Stores.h"
#include "GameObject.h"
#include "GridNotifiers.h"
#include "Map.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "SpellScript.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "Log.h"
#include "Vehicle.h"

enum CaveOfMeditationSpells
{
    SPELL_MEDITATION_TIMER_BAR  = 116421,
    QUEST_THE_WAY_OF_THE_TUSHUI = 29414
};

class at_cave_of_meditation : public AreaTriggerScript
{
public:
    at_cave_of_meditation() : AreaTriggerScript("at_cave_of_meditation") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/, bool entered) override
    {
        if (player->IsAlive() && player->GetQuestStatus(QUEST_THE_WAY_OF_THE_TUSHUI) == QUEST_STATUS_INCOMPLETE)
        {
            if (entered && !player->HasAura(SPELL_MEDITATION_TIMER_BAR))
                player->CastSpell(player, SPELL_MEDITATION_TIMER_BAR, true);
            else
                player->RemoveAura(SPELL_MEDITATION_TIMER_BAR);

            return true;
        }
        return false;
    }
};

class spell_summon_troublemaker : public SpellScriptLoader
{
public:
    spell_summon_troublemaker() : SpellScriptLoader("spell_summon_troublemaker") { }

    class spell_summon_troublemaker_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_summon_troublemaker_SpellScript);

        void HandleSummon(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            uint32 entry = GetSpellInfo()->GetEffect(effIndex)->MiscValue;
            SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(GetSpellInfo()->GetEffect(effIndex)->MiscValueB);
            int32 duration = GetSpellInfo()->GetDuration();

            if (!entry || !properties || !duration)
                return;

            int32 radius;
            if (urand(0, 2) == 0)
                radius = urand(0, 6);
            else
                radius = 7;
            float angle = M_PI * (urand(0, 7) / 7.f);
            float x = 1181.75f + radius * sin(angle);
            float y = 3444.5f + radius * cos(angle);
            float z = 102.9385f;

            GetHitDest()->Relocate(x, y, z);

            Position const spawnPosition = { x, y, z, 3.285759f };

            if (TempSummon* summon = GetCaster()->GetMap()->SummonCreature(entry, spawnPosition, properties, duration, GetCaster()))
                summon->SetTempSummonType(TEMPSUMMON_CORPSE_TIMED_DESPAWN);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_summon_troublemaker_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_summon_troublemaker_SpellScript();
    }
};

enum MeditationTimerSpells
{
    SPELL_CAVE_OF_SCROLLS_CREDIT            = 102447,
    SPELL_CAVE_OF_SCROLLS_COMP_TIMER_AURA   = 128598
};

class spell_meditation_timer_bar : public SpellScriptLoader
{
public:
    spell_meditation_timer_bar() : SpellScriptLoader("spell_meditation_timer_bar") { }

    class spell_meditation_timer_bar_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_meditation_timer_bar_AuraScript);

        void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
        {
            if (Unit* target = GetTarget())
            {
                target->ModifyPower(POWER_ALTERNATE_POWER, 1);

                if (target->GetPowerPct(POWER_ALTERNATE_POWER) == 100)
                {
                    target->CastSpell(GetTarget(), SPELL_CAVE_OF_SCROLLS_CREDIT, true);
                    target->CastSpell(GetTarget(), SPELL_CAVE_OF_SCROLLS_COMP_TIMER_AURA, true);
                    target->RemoveAura(GetId());
                    target->ClearInCombat();
                }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_meditation_timer_bar_AuraScript::HandleEffectPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_meditation_timer_bar_AuraScript();
    }
};

class spell_cave_of_scrolls_comp_timer_aura : public SpellScriptLoader
{
public:
    spell_cave_of_scrolls_comp_timer_aura() : SpellScriptLoader("spell_cave_of_scrolls_comp_timer_aura") { }

    class spell_cave_of_scrolls_comp_timer_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_cave_of_scrolls_comp_timer_aura_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetTarget())
                if (Creature* creature = target->FindNearestCreature(54567, 40.0f, true))
                    creature->AI()->Talk(1, target);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_cave_of_scrolls_comp_timer_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_cave_of_scrolls_comp_timer_aura_AuraScript();
    }
};

class q_the_way_of_the_tushui : public QuestScript
{
public:
    q_the_way_of_the_tushui() : QuestScript("q_the_way_of_the_tushui") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus == QUEST_STATUS_NONE)
        {
            player->RemoveAura(SPELL_MEDITATION_TIMER_BAR);
            PhasingHandler::OnConditionChange(player);
        }
    }
};

class spell_summon_living_air : public SpellScriptLoader
{
public:
    spell_summon_living_air() : SpellScriptLoader("spell_summon_living_air") { }

    class spell_summon_living_air_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_summon_living_air_SpellScript);

        void HandleSummon(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            uint32 entry = GetSpellInfo()->GetEffect(effIndex)->MiscValue;
            SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(GetSpellInfo()->GetEffect(effIndex)->MiscValueB);
            int32 duration = GetSpellInfo()->GetDuration();

            if (!entry || !properties || !duration)
                return;

            Position const spawnPosition[6] =
            {
                { 1237.073f, 3697.739f, 93.62743f },
                { 1230.608f, 3701.063f, 93.94895f },
                { 1229.429f, 3732.776f, 92.22045f },
                { 1223.438f, 3700.607f, 93.93437f },
                { 1239.606f, 3732.907f, 94.10403f },
                { 1224.92f, 3727.201f, 92.4472f }
            };

            if (TempSummon* summon = GetCaster()->GetMap()->SummonCreature(entry, spawnPosition[urand(0, 5)], properties, duration, GetCaster()))
                summon->SetTempSummonType(TEMPSUMMON_DEAD_DESPAWN);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_summon_living_air_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_summon_living_air_SpellScript();
    }
};

enum QuestOnlyTheWorthyShallPassSpells
{
    SPELL_CANCEL_FIRE_CRASH_PHASE   = 108153
};

class q_only_the_worthy_shall_pass : public QuestScript
{
public:
    q_only_the_worthy_shall_pass() : QuestScript("q_only_the_worthy_shall_pass") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus == QUEST_STATUS_NONE)
        {
            player->CastSpell(player, SPELL_CANCEL_FIRE_CRASH_PHASE, true);
            PhasingHandler::OnConditionChange(player);
        }
    }
};

enum FanTheFlamesSpells
{
    SPELL_THROW_WOOD        = 109090,
    SPELL_BLOW_AIR          = 109095,
    SPELL_BLOW_AIR_BIG      = 109105,
    SPELL_BLOW_AIR_BIGGER   = 109109
};

enum FanTheFlamesNPCs
{
    NPC_HUO = 57779
};

class spell_fan_the_flames : public SpellScriptLoader
{
public:
    spell_fan_the_flames() : SpellScriptLoader("spell_fan_the_flames") { }

    class spell_fan_the_flames_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_fan_the_flames_AuraScript);

        uint32 counter = 0;

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();

            counter++;

            if (Unit* target = GetTarget()->FindNearestCreature(NPC_HUO, GetSpellInfo()->GetMaxRange(), true))
            {
                if (counter == 1 || counter == 4 || counter == 6)
                    caster->CastSpell(target, SPELL_THROW_WOOD, true);
                if (counter == 8 || counter == 10 || counter == 13 || counter == 15)
                    caster->CastSpell(target, SPELL_BLOW_AIR, true);
                if (counter == 12 || counter == 14)
                    caster->CastSpell(target, SPELL_BLOW_AIR_BIG, true);
                if (counter == 16)
                    caster->CastSpell(target, SPELL_BLOW_AIR_BIGGER, true);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_fan_the_flames_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_fan_the_flames_AuraScript();
    }
};

enum QuestPassionOfShenZinSuSpells
{
    SPELL_DESPAWN_FIRE_SPIRIT               = 109178,
    SPELL_SUMMON_FIRE_SPIRIT                = 128700,
    SPELL_SUMMON_FIRE_SPIRIT_AFTER_RELOG    = 102632
};

class q_passion_of_shenzin_su : public QuestScript
{
public:
    q_passion_of_shenzin_su() : QuestScript("q_passion_of_shenzin_su") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus == QUEST_STATUS_NONE)
        {
            player->CastSpell(player, SPELL_DESPAWN_FIRE_SPIRIT, true);
            player->RemoveAura(SPELL_SUMMON_FIRE_SPIRIT);
            player->RemoveAura(SPELL_SUMMON_FIRE_SPIRIT_AFTER_RELOG);
            PhasingHandler::OnConditionChange(player);
        }
    }
};

enum SingingPoolsATSpells
{
    SPELL_CURSE_OF_THE_FROG             = 102938,
    SPELL_CURSE_OF_THE_SKUNK            = 102939,
    SPELL_CURSE_OF_THE_TURTLE           = 102940,
    SPELL_CURSE_OF_THE_CRANE            = 102941,
    SPELL_CURSE_OF_THE_CROCODILE        = 102942,
    SPELL_RIDE_VEHICLE_POLE             = 102717,
    SPELL_RIDE_VEHICLE_BELL_POLE        = 107049,
    SPELL_TRAINING_BELL_EXCLUSION_AURA  = 133381
};

class at_singing_pools_transform : public AreaTriggerScript
{
public:
    at_singing_pools_transform() : AreaTriggerScript("at_singing_pools_transform") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* areaTrigger, bool entered) override
    {
        if (player->IsAlive() && !player->HasAura(SPELL_RIDE_VEHICLE_POLE))
        {
            if (entered)
            {
                switch (areaTrigger->ID)
                {
                    case 6986:

                    case 6987:
                        if (!player->HasAura(SPELL_CURSE_OF_THE_FROG))
                            player->CastSpell(player, SPELL_CURSE_OF_THE_FROG, true);
                        if (player->HasAura(SPELL_TRAINING_BELL_EXCLUSION_AURA))
                            player->RemoveAura(SPELL_TRAINING_BELL_EXCLUSION_AURA);
                        break;
                    case 6988:
                    case 6989:
                        if (!player->HasAura(SPELL_CURSE_OF_THE_SKUNK))
                            player->CastSpell(player, SPELL_CURSE_OF_THE_SKUNK, true);
                        break;
                    case 6990:
                        if (!player->HasAura(SPELL_CURSE_OF_THE_CROCODILE))
                            player->CastSpell(player, SPELL_CURSE_OF_THE_CROCODILE, true);
                        break;
                    case 6991:
                    case 6992:
                        if (!player->HasAura(SPELL_CURSE_OF_THE_CRANE))
                            player->CastSpell(player, SPELL_CURSE_OF_THE_CRANE, true);
                        break;
                    case 7011:
                    case 7012:
                        if (!player->HasAura(SPELL_CURSE_OF_THE_TURTLE))
                            player->CastSpell(player, SPELL_CURSE_OF_THE_TURTLE, true);
                        break;
                }
            }
            else
            {
                switch (areaTrigger->ID)
                {
                    case 6986:
                    case 6987:
                        if (!player->IsInAreaTriggerRadius(sAreaTriggerStore.LookupEntry(6986)) && !player->IsInAreaTriggerRadius(sAreaTriggerStore.LookupEntry(6987)))
                            if (player->HasAura(SPELL_CURSE_OF_THE_FROG))
                                player->RemoveAura(SPELL_CURSE_OF_THE_FROG);
                        break;
                    case 6988:
                    case 6989:
                        if (!player->IsInAreaTriggerRadius(sAreaTriggerStore.LookupEntry(6988)) && !player->IsInAreaTriggerRadius(sAreaTriggerStore.LookupEntry(6989)))
                            if (player->HasAura(SPELL_CURSE_OF_THE_SKUNK))
                                player->RemoveAura(SPELL_CURSE_OF_THE_SKUNK);
                        break;
                    case 6990:
                        if (player->HasAura(SPELL_CURSE_OF_THE_CROCODILE))
                            player->RemoveAura(SPELL_CURSE_OF_THE_CROCODILE);
                        break;
                    case 6991:
                    case 6992:
                        if (!player->IsInAreaTriggerRadius(sAreaTriggerStore.LookupEntry(6991)) && !player->IsInAreaTriggerRadius(sAreaTriggerStore.LookupEntry(6992)))
                            if (player->HasAura(SPELL_CURSE_OF_THE_CRANE))
                                player->RemoveAura(SPELL_CURSE_OF_THE_CRANE);
                        break;
                    case 7011:
                    case 7012:
                        if (!player->IsInAreaTriggerRadius(sAreaTriggerStore.LookupEntry(7011)) && !player->IsInAreaTriggerRadius(sAreaTriggerStore.LookupEntry(7012)))
                            if (player->HasAura(SPELL_CURSE_OF_THE_TURTLE))
                                player->RemoveAura(SPELL_CURSE_OF_THE_TURTLE);
                        break;
                }
            }
            return true;
        }
        return false;
    }
};

enum BalancePoleEvents
{
    EVENT_CAST_TRANSFORM                        = 1
};

enum BalancePoleNPCs
{
    NPC_BALANCE_POLE_1                          = 54993,
    NPC_BALANCE_POLE_2                          = 57431,
    NPC_TRAINING_BELL_BALANCE_POLE              = 55083,
    NPC_CURSED_POOL_CONTROLLER                  = 55123
};

enum BalancePoleSpells
{
    SPELL_MONK_RIDE_POLE                        = 103030,
    SPELL_TRAINING_BELL_FORCECAST_RIDE_VEHICLE  = 107050,
    SPELL_TRAINING_BELL_RIDE_VEHICLE            = 107049
};

class npc_balance_pole : public CreatureScript
{
public:
    npc_balance_pole() : CreatureScript("npc_balance_pole") { }

    struct npc_balance_poleAI : public ScriptedAI
    {
        npc_balance_poleAI(Creature* creature) : ScriptedAI(creature) {
            _passengerGuid.Clear();
        }

        void PassengerBoarded(Unit* passenger, int8 /*seat*/, bool apply) override
        {
            if (passenger->GetTypeId() == TYPEID_PLAYER)
            {
                _passengerGuid = passenger->GetGUID();

                if (!apply)
                    _events.ScheduleEvent(EVENT_CAST_TRANSFORM, 1000);
                else
                {
                    if (me->GetEntry() == NPC_TRAINING_BELL_BALANCE_POLE)
                        DoCast(passenger, SPELL_TRAINING_BELL_FORCECAST_RIDE_VEHICLE, true);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CAST_TRANSFORM:
                        // Transform is casted only when in frog pool
                        Unit* passenger = ObjectAccessor::GetUnit(*me, _passengerGuid);
                        if (passenger->GetPositionZ() > 116.0f && !passenger->HasAura(SPELL_TRAINING_BELL_RIDE_VEHICLE) && !passenger->HasAura(SPELL_RIDE_VEHICLE_POLE))
                        {
                            passenger->CastSpell(passenger, SPELL_CURSE_OF_THE_FROG, true);

                            if (passenger->HasAura(SPELL_TRAINING_BELL_EXCLUSION_AURA))
                                passenger->RemoveAura(SPELL_TRAINING_BELL_EXCLUSION_AURA);
                        }
                        break;
                }
            }
        }

    private:
        EventMap _events;
        ObjectGuid _passengerGuid;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_balance_poleAI(creature);
    }
};

enum TushuiMonkOnPoleEvents
{
    EVENT_THROW_ROCK                = 1,
    EVENT_SWITCH_POLE               = 2,
    EVENT_DESPAWN                   = 3
};

enum TushuiMonkOnPoleNPCs
{
    NPC_MONK_ON_POLE_1              = 55019,
    NPC_MONK_ON_POLE_2              = 65468,
};

enum TushuiMonkOnPoleSpells
{
    SPELL_FORCECAST_RIDE_POLE       = 103031,
    SPELL_THROW_ROCK                = 109308
};

enum TushuiMonkOnPoleMisc
{
    QUEST_LESSON_OF_BALANCED_ROCK   = 29663
};

class npc_tushui_monk_on_pole : public CreatureScript
{
public:
    npc_tushui_monk_on_pole() : CreatureScript("npc_tushui_monk_on_pole") { }

    struct npc_tushui_monk_on_poleAI : public ScriptedAI
    {
        npc_tushui_monk_on_poleAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _events.Reset();
            _events.ScheduleEvent(EVENT_SWITCH_POLE, 0);
            me->RestoreFaction();
            me->SetReactState(REACT_DEFENSIVE);
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_FORCECAST_RIDE_POLE)
                DoCast(caster, SPELL_MONK_RIDE_POLE, true);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _events.ScheduleEvent(EVENT_THROW_ROCK, 0);
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (damage >= me->GetHealth())
            {
                me->SetHealth(10);
                _events.Reset();
                me->RemoveAllAuras();
                me->SetFaction(35);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_UNK_15 | UNIT_FLAG_IMMUNE_TO_PC));
                me->AttackStop();
                attacker->AttackStop();
                me->_ExitVehicle();
                attacker->ToPlayer()->KilledMonsterCredit(NPC_MONK_ON_POLE_1);
                //_events.ScheduleEvent(EVENT_DESPAWN, 1000); // will cause crash if npc is dead. -Varjgard
                me->ForcedDespawn(); // tempfix.
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_THROW_ROCK:
                        if (!me->IsWithinMeleeRange(me->GetVictim()))
                            DoCastVictim(SPELL_THROW_ROCK);
                        _events.ScheduleEvent(EVENT_THROW_ROCK, 2500);
                        break;
                    case EVENT_SWITCH_POLE:
                        if (!me->IsInCombat())
                        {
                            SwitchPole();
                            _events.ScheduleEvent(EVENT_SWITCH_POLE, urand(15000, 30000));
                        }
                        break;
                    //case EVENT_DESPAWN:
                        // Transform is casted only when in frog pool
                        //if (me->FindNearestCreature(NPC_CURSED_POOL_CONTROLLER, 71.0f, true))
                        //    DoCastSelf(SPELL_CURSE_OF_THE_FROG, true);
                        //ClearThreadList();
                        //me->SetWalk(true);
                        //MoveForward(10.0f);
                        //me->DespawnOrUnsummon(3000);
                        //break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;

        void SwitchPole()
        {
            std::list<Creature*> polesList;
            std::list<Creature*> polesList2;
            // This stores objects that are too far away due to big combat reach
            me->GetCreatureListWithEntryInGrid(polesList, NPC_BALANCE_POLE_1, 1.0f);
            me->GetCreatureListWithEntryInGrid(polesList2, NPC_BALANCE_POLE_2, 1.0f);
            // Join both lists with possible different NPC entries
            polesList.splice(polesList.end(), polesList2);
            // Convert list to vector, so we can access iterator to be able to shuffle the list
            std::vector<Creature*> balancePolesList{ std::make_move_iterator(std::begin(polesList)), std::make_move_iterator(std::end(polesList)) };
            // Shuffle the list so NPCs won't jump always on the same poles
            Trinity::Containers::RandomShuffle(balancePolesList);

            for (std::vector<Creature*>::const_iterator itr = balancePolesList.begin(); itr != balancePolesList.end(); ++itr)
            {
                Position offset;
                offset.m_positionX = fabsf((*itr)->GetPositionX() - me->GetPositionX());
                offset.m_positionY = fabsf((*itr)->GetPositionY() - me->GetPositionY());

                // Object is too far
                if (offset.m_positionX > 5.0f || offset.m_positionY > 5.0f)
                    continue;

                if (!(*itr)->HasAura(SPELL_MONK_RIDE_POLE) && !(*itr)->HasAura(SPELL_RIDE_VEHICLE_POLE))
                {
                    (*itr)->CastSpell(me, SPELL_FORCECAST_RIDE_POLE, true);
                    break;
                }
            }
        }

        void ClearThreadList()
        {
            std::list<HostileReference*> threatList = me->getThreatManager().getThreatList();;
            for (std::list<HostileReference*>::const_iterator itr = threatList.begin(); itr != threatList.end(); ++itr)
                if (Unit* target = (*itr)->getTarget()->ToUnit())
                    target->ClearInCombat();
        }

        void MoveForward(float distance)
        {
            Position movePos;
            float ori = me->GetOrientation();
            float x = me->GetPositionX() + distance * cos(ori);
            float y = me->GetPositionY() + distance * sin(ori);
            float z = me->GetPositionZ();
            me->UpdateGroundPositionZ(x, y, z);
            movePos = { x, y, z };
            me->GetMotionMaster()->MovePoint(1, movePos);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tushui_monk_on_poleAI(creature);
    }
};

class at_singing_pools_training_bell : public AreaTriggerScript
{
public:
    at_singing_pools_training_bell() : AreaTriggerScript("at_singing_pools_training_bell") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/, bool entered) override
    {
        if (player->IsAlive())
        {
            if (entered)
                player->AddAura(SPELL_TRAINING_BELL_EXCLUSION_AURA, player);
            else
                player->RemoveAura(SPELL_TRAINING_BELL_EXCLUSION_AURA);

            return true;
        }
        return false;
    }
};

class spell_rock_jump_a : public SpellScriptLoader
{
public:
    spell_rock_jump_a() : SpellScriptLoader("spell_rock_jump_a") { }

    class spell_rock_jump_a_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rock_jump_a_SpellScript);

        void HandleJumpDest(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);

            if (Unit* caster = GetCaster())
            {
                if (caster->GetPositionZ() > 92.0f)
                {
                    Position const jumpPos = { 1077.019f, 2844.103f, 95.27103f };
                    caster->GetMotionMaster()->MoveJump(jumpPos, GetSpellInfo()->GetEffect(effIndex)->MiscValue, 10);
                }
                else
                {
                    if (GameObject* go = caster->FindNearestGameObject(209576, 8.0f))
                        caster->GetMotionMaster()->MoveJump(go->GetPosition(), GetSpellInfo()->GetEffect(effIndex)->MiscValue, 5);
                }
            }
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_rock_jump_a_SpellScript::HandleJumpDest, EFFECT_0, SPELL_EFFECT_JUMP_DEST);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rock_jump_a_SpellScript();
    }
};

class spell_jump_to_front_right : public SpellScriptLoader
{
public:
    spell_jump_to_front_right() : SpellScriptLoader("spell_jump_to_front_right") { }

    class spell_jump_to_front_right_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_jump_to_front_right_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                Position const jumpPos = { 1111.13f, 2850.21f, 94.6873f };
                caster->GetMotionMaster()->MoveJump(jumpPos, 12, 15);
            }
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_jump_to_front_right_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_jump_to_front_right_SpellScript();
    }
};

class spell_jump_to_front_left : public SpellScriptLoader
{
public:
    spell_jump_to_front_left() : SpellScriptLoader("spell_jump_to_front_left") { }

    class spell_jump_to_front_left_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_jump_to_front_left_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                Position const jumpPos = { 1100.83f, 2881.36f, 94.0386f };
                caster->GetMotionMaster()->MoveJump(jumpPos, 12, 15);
            }
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_jump_to_front_left_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_jump_to_front_left_SpellScript();
    }
};

class spell_jump_to_back_right : public SpellScriptLoader
{
public:
    spell_jump_to_back_right() : SpellScriptLoader("spell_jump_to_back_right") { }

    class spell_jump_to_back_right_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_jump_to_back_right_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                Position const jumpPos = { 1127.26f, 2859.8f, 97.2817f };
                caster->GetMotionMaster()->MoveJump(jumpPos, 12, 15);
            }
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_jump_to_back_right_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_jump_to_back_right_SpellScript();
    }
};

class spell_jump_to_back_left : public SpellScriptLoader
{
public:
    spell_jump_to_back_left() : SpellScriptLoader("spell_jump_to_back_left") { }

    class spell_jump_to_back_left_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_jump_to_back_left_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                Position const jumpPos = { 1120.16f, 2882.66f, 96.345f };
                caster->GetMotionMaster()->MoveJump(jumpPos, 12, 15);
            }
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_jump_to_back_left_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_jump_to_back_left_SpellScript();
    }
};

enum ShuSpells
{
    SPELL_JUMP_FRONT_RIGHT		 = 117033,
    SPELL_JUMP_FRONT_LEFT 		 = 117034,
    SPELL_JUMP_BACK_RIGHT 		 = 117035,
    SPELL_JUMP_BACK_LEFT 		 = 117036,
    SPELL_SUMMON_WATER_SPOUT 	 = 116810,
    SPELL_WATER_SPOUT 		 	 = 117063
};

enum ShuJumpPositions
{
    JUMP_POSITION_1 = 0,
    JUMP_POSITION_2 = 1,
    JUMP_POSITION_3 = 2,
    JUMP_POSITION_4 = 3
};

enum ShuEvents
{
    EVENT_JUMP_SPELL 		= 1,
    EVENT_SET_ORIENTATION	= 2,
    EVENT_SUMMON			= 3
};

enum ShuData
{
    DATA_JUMP_POSITION = 1
};

class npc_shu_playing : public CreatureScript
{
public:
    npc_shu_playing() : CreatureScript("npc_shu_playing") { }

    struct npc_shu_playingAI : public ScriptedAI
    {
        npc_shu_playingAI(Creature* creature) : ScriptedAI(creature) { }

        void Initialize()
        {
            jumpPosition = 1;
            positionBefore = 1;
            startAI = true;
        }

        void Reset() override
        {
            events.Reset();
            Initialize();
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == EFFECT_MOTION_TYPE && id == EVENT_JUMP)
                events.ScheduleEvent(EVENT_SET_ORIENTATION, 500);
        }

        uint32 GetData(uint32 id) const override
        {
            if (id == DATA_JUMP_POSITION)
                return jumpPosition;

            return false;
        }

        void UpdateAI(uint32 diff) override
        {
            if (startAI)
            {
                events.ScheduleEvent(EVENT_JUMP_SPELL, 1000);
                startAI = false;
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_JUMP_SPELL:
                    if (urand(0, 2) != 0)
                        jumpPosition = urand(JUMP_POSITION_1, JUMP_POSITION_4);
                    else
                        jumpPosition = positionBefore;

                    if (jumpPosition == positionBefore)
                    {
                        events.CancelEvent(EVENT_SET_ORIENTATION);
                        events.ScheduleEvent(EVENT_SUMMON, 1500);
                    }
                    else
                    {
                        DoCast(jumpSpells[jumpPosition]);
                        positionBefore = jumpPosition;
                    }
                    break;
                case EVENT_SET_ORIENTATION:
                    switch (jumpPosition)
                    {
                    case JUMP_POSITION_1:
                        me->SetFacingTo(1.32645f);
                        break;
                    case JUMP_POSITION_2:
                        me->SetFacingTo(5.654867f);
                        break;
                    case JUMP_POSITION_3:
                        me->SetFacingTo(2.338741f);
                        break;
                    case JUMP_POSITION_4:
                        me->SetFacingTo(4.34587f);
                        break;
                    }
                    events.ScheduleEvent(EVENT_SUMMON, 1500);
                    break;
                case EVENT_SUMMON:
                    DoCast(SPELL_SUMMON_WATER_SPOUT);
                    DoCast(SPELL_WATER_SPOUT);
                    events.ScheduleEvent(EVENT_JUMP_SPELL, 6000);
                    break;
                }
            }
        }

    private:
        EventMap events;
        uint32 jumpSpells[4] = { SPELL_JUMP_FRONT_RIGHT, SPELL_JUMP_FRONT_LEFT, SPELL_JUMP_BACK_RIGHT, SPELL_JUMP_BACK_LEFT };
        uint8 jumpPosition;
        uint8 positionBefore;
        bool startAI;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_shu_playingAI(creature);
    }
};

class spell_summon_water_spout : public SpellScriptLoader
{
public:
    spell_summon_water_spout() : SpellScriptLoader("spell_summon_water_spout") { }

    class spell_summon_water_spout_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_summon_water_spout_SpellScript);

        void HandleSummon(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            uint32 entry = GetSpellInfo()->GetEffect(effIndex)->MiscValue;
            SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(GetSpellInfo()->GetEffect(effIndex)->MiscValueB);
            if (!entry || !properties)
                return;

            int32 duration = GetSpellInfo()->GetDuration();
            uint32 randomPos = urand(0, 6);

            Position const SpawnPosition[4][7] =
            {
                {
                    { 1117.516f, 2848.437f, 92.14017f },
                    { 1105.92f, 2853.432f, 92.14017f },
                    { 1105.231f, 2847.766f, 92.14017f },
                    { 1114.819f, 2844.094f, 92.14017f },
                    { 1110.618f, 2856.7f, 92.14017f },
                    { 1109.559f, 2843.255f, 92.14017f },
                    { 1116.04f, 2854.104f, 92.14017f }
                },
                {
                    { 1106.743f, 2879.544f, 92.14017f },
                    { 1105.793f, 2885.37f, 92.14017f },
                    { 1098.16f, 2874.628f, 92.14017f },
                    { 1104.28f, 2875.759f, 92.14017f },
                    { 1095.38f, 2885.097f, 92.14017f },
                    { 1100.078f, 2888.365f, 92.14017f },
                    { 1094.693f, 2879.431f, 92.14017f }
                },
                {
                    { 1132.911f, 2864.381f, 92.14017f },
                    { 1125.672f, 2851.84f, 92.14017f },
                    { 1121.057f, 2856.08f, 92.14017f },
                    { 1134.373f, 2858.654f, 92.14017f },
                    { 1126.556f, 2867.097f, 92.14017f },
                    { 1120.064f, 2863.003f, 92.14017f },
                    { 1131.856f, 2852.781f, 92.14017f }
                },
                {
                    { 1118.22f, 2875.427f, 92.14017f },
                    { 1113.274f, 2879.232f, 92.14017f },
                    { 1125.439f, 2887.632f, 92.14017f },
                    { 1118.766f, 2890.419f, 92.14017f },
                    { 1113.783f, 2886.404f, 92.14017f },
                    { 1123.7f, 2876.575f, 92.14017f },
                    { 1126.358f, 2881.005f, 92.14017f }
                }
            };

            uint32 stone = GetCaster()->ToCreature()->AI()->GetData(DATA_JUMP_POSITION);

            if (TempSummon* summon = GetCaster()->GetMap()->SummonCreature(entry, SpawnPosition[stone][randomPos], properties, duration, GetCaster()))
                summon->SetTempSummonType(TEMPSUMMON_MANUAL_DESPAWN);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_summon_water_spout_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_summon_water_spout_SpellScript();
    }
};

enum WaterSpoutQuestCreditSpells
{
    SPELL_AYSA_CONGRATS_TIMER = 128589,
    SPELL_SUMMON_SPIRIT_OF_WATER = 103538
};

class spell_water_spout_quest_credit : public SpellScriptLoader
{
public:
    spell_water_spout_quest_credit() : SpellScriptLoader("spell_water_spout_quest_credit") { }

    class spell_water_spout_quest_credit_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_water_spout_quest_credit_SpellScript);

        void HandleScript()
        {
            if (Player* target = GetHitPlayer())
            {
                if (target->GetQuestStatus(29679) == QUEST_STATUS_COMPLETE)
                {
                    target->AddAura(SPELL_AYSA_CONGRATS_TIMER, target);
                    target->CastSpell(target, SPELL_SUMMON_SPIRIT_OF_WATER, true);
                }
            }
        }

        void Register() override
        {
            AfterHit += SpellHitFn(spell_water_spout_quest_credit_SpellScript::HandleScript);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_water_spout_quest_credit_SpellScript();
    }
};

class spell_aysa_congrats_timer : public SpellScriptLoader
{
public:
    spell_aysa_congrats_timer() : SpellScriptLoader("spell_aysa_congrats_timer") { }

    class spell_aysa_congrats_timer_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_aysa_congrats_timer_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetTarget())
                if (Creature* creature = target->FindNearestCreature(54975, 70.0f, true))
                    creature->AI()->Talk(0, target);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_aysa_congrats_timer_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_aysa_congrats_timer_AuraScript();
    }
};

class spell_aysa_congrats_trigger_aura : public SpellScriptLoader
{
public:
    spell_aysa_congrats_trigger_aura() : SpellScriptLoader("spell_aysa_congrats_trigger_aura") { }

    class spell_aysa_congrats_trigger_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_aysa_congrats_trigger_aura_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetTarget())
                if (Creature* creature = target->FindNearestCreature(54975, 70.0f, true))
                    creature->AI()->Talk(1, target);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_aysa_congrats_trigger_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_aysa_congrats_trigger_aura_AuraScript();
    }
};

class at_temple_of_five_dawns_summon_zhaoren : public AreaTriggerScript
{
public:
    at_temple_of_five_dawns_summon_zhaoren() : AreaTriggerScript("at_temple_of_five_dawns_summon_zhaoren") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/, bool entered) override
    {
        if (player->IsAlive())
        {
            if (entered)
            {
                Position const pos = { 750.5781f, 4262.676f, 323.0713f, 5.042483f };

                player->SummonCreature(64554, pos, TEMPSUMMON_MANUAL_DESPAWN);

                return true;
            }
        }
        return false;
    }
};

enum MonkeyWisdomTexts
{
    TEXT_MONKEY_WISDOM      = 54073,
    TEXT_MONKEY_WISDOM_2    = 54074,
    TEXT_MONKEY_WISDOM_3    = 54075,
    TEXT_MONKEY_WISDOM_4    = 54076,
    TEXT_MONKEY_WISDOM_5    = 54077,
    TEXT_MONKEY_WISDOM_6    = 54078,
    TEXT_MONKEY_WISDOM_7    = 54079,
    TEXT_MONKEY_WISDOM_8    = 54080
};

class spell_monkey_wisdom_text : public SpellScriptLoader
{
public:
    spell_monkey_wisdom_text() : SpellScriptLoader("spell_monkey_wisdom_text") { }

    class spell_monkey_wisdom_text_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monkey_wisdom_text_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sBroadcastTextStore.LookupEntry(TEXT_MONKEY_WISDOM) || !sBroadcastTextStore.LookupEntry(TEXT_MONKEY_WISDOM_2) ||
                !sBroadcastTextStore.LookupEntry(TEXT_MONKEY_WISDOM_3) || !sBroadcastTextStore.LookupEntry(TEXT_MONKEY_WISDOM_4) ||
                !sBroadcastTextStore.LookupEntry(TEXT_MONKEY_WISDOM_5) || !sBroadcastTextStore.LookupEntry(TEXT_MONKEY_WISDOM_6) ||
                !sBroadcastTextStore.LookupEntry(TEXT_MONKEY_WISDOM_7) || !sBroadcastTextStore.LookupEntry(TEXT_MONKEY_WISDOM_8))
                return false;
            return true;
        }

        bool Load() override
        {
            return GetCaster()->GetTypeId() == TYPEID_PLAYER;
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            uint32 randomText = urand(0, 7);

            GetCaster()->Talk(TEXT_MONKEY_WISDOM + randomText, CHAT_MSG_RAID_BOSS_WHISPER, 0.0f, GetHitPlayer());
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_monkey_wisdom_text_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_monkey_wisdom_text_SpellScript();
    }
};

enum RukRukOoksplosions
{
    SPELL_OOKSPLOSIONS_TRIGGERED    = 125885
};

class spell_ruk_ruk_ooksplosions : public SpellScriptLoader
{
public:
    spell_ruk_ruk_ooksplosions() : SpellScriptLoader("spell_ruk_ruk_ooksplosions") { }

    class spell_ruk_ruk_ooksplosions_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_ruk_ruk_ooksplosions_AuraScript);

        void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            float x, y, z;
            caster->GetClosePoint(x, y, z, caster->GetObjectSize() / 2, frand(0, 3), frand(0, 2 * float(M_PI)));
            caster->CastSpell(x, y, z, SPELL_OOKSPLOSIONS_TRIGGERED, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_ruk_ruk_ooksplosions_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_ruk_ruk_ooksplosions_AuraScript();
    }
};

enum RukRukEvents
{
    EVENT_AIM            = 1,
    EVENT_OOKSPLOSIONS  = 2
};

enum RukRukSpells
{
    SPELL_AIM            = 125609,
    SPELL_OOKSPLOSIONS    = 125699,
    SPELL_AIM_VISUAL    = 26079
};

class npc_ruk_ruk : public CreatureScript
{
public:
    npc_ruk_ruk() : CreatureScript("npc_ruk_ruk") { }

    struct npc_ruk_rukAI : public ScriptedAI
    {
        npc_ruk_rukAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _events.ScheduleEvent(EVENT_AIM, 10000);
            _events.ScheduleEvent(EVENT_OOKSPLOSIONS, 30000);
        }

        Position GetRocketTargetPos() const
        {
            return _pos;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_AIM:
                        if (me->HasUnitState(UNIT_STATE_CASTING))
                        {
                            _events.RescheduleEvent(EVENT_AIM, 1000);
                            break;
                        }
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        {
                            me->SetFacingToObject(target);
                            CalculateSpellVisual(target);
                            DoCast(target, SPELL_AIM);
                            _events.ScheduleEvent(EVENT_AIM, urand(15000, 25000));
                        }
                        break;
                    case EVENT_OOKSPLOSIONS:
                        if (me->HasUnitState(UNIT_STATE_CASTING))
                        {
                            _events.RescheduleEvent(EVENT_OOKSPLOSIONS, 1000);
                            break;
                        }
                        DoCast(SPELL_OOKSPLOSIONS);
                        _events.ScheduleEvent(EVENT_OOKSPLOSIONS, urand(25000, 35000));
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        Position _pos;

        void CalculateSpellVisual(Unit* target)
        {
            float ori = me->GetOrientation();
            float z = me->GetPositionZ();
            float targetDist = target->GetExactDist(me->GetPosition());

            for (int radius = 1; ; radius++)
            {
                if (radius <= ceilf(targetDist))
                {
                    float x = me->GetPositionX() + radius * cos(ori);
                    float y = me->GetPositionY() + radius * sin(ori);
                    me->UpdateGroundPositionZ(x, y, z);
                    _pos = { x, y, z };
                    me->SendPlaySpellVisual(_pos, 0.0f, SPELL_AIM_VISUAL, 0, 0, 2.0f);
                }
                else
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ruk_rukAI(creature);
    }
};

typedef npc_ruk_ruk::npc_ruk_rukAI RukRukAI;

enum RukRukRocketEvents
{
    EVENT_FIRE              = 1
};

enum RukRukRocketSpells
{
    SPELL_EXPLOSSION_VISUAL = 125612,
    SPELL_EXPLOSSION_DMG    = 125619
};

class npc_ruk_ruk_rocket : public CreatureScript
{
public:
    npc_ruk_ruk_rocket() : CreatureScript("npc_ruk_ruk_rocket") { }

    struct npc_ruk_ruk_rocketAI : public ScriptedAI
    {
        npc_ruk_ruk_rocketAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->SetDisplayFromModel(0);
            _events.ScheduleEvent(EVENT_FIRE, 500);
        }

        void IsSummonedBy(Unit* owner) override
        {
            if (RukRukAI* rukRukAI = CAST_AI(RukRukAI, owner->GetAI()))
            {
                _rocketTargetPos = rukRukAI->GetRocketTargetPos();

                if (me->GetExactDist2d(_rocketTargetPos) > 30)
                    RecalculateTargetPos();
            }
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == 1)
            {
                DoCast(SPELL_EXPLOSSION_VISUAL);
                DoCast(SPELL_EXPLOSSION_DMG);
                me->DespawnOrUnsummon(1000);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_FIRE:
                        me->GetMotionMaster()->MovePoint(1, _rocketTargetPos);
                        break;
                }
            }
        }

    private:
        EventMap _events;
        Position _rocketTargetPos;

        void RecalculateTargetPos()
        {
            float ori = me->GetOrientation();
            float x = me->GetPositionX() + 30 * cos(ori);
            float y = me->GetPositionY() + 30 * sin(ori);
            float z = me->GetPositionZ();
            me->UpdateGroundPositionZ(x, y, z);
            _rocketTargetPos = { x, y, z };
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ruk_ruk_rocketAI(creature);
    }
};

enum ZhaorenEvents
{
    EVENT_LIGHTNING                 = 1,
    EVENT_MOVE_CENTER               = 2,
    EVENT_STUN                      = 3,
    EVENT_SWEEP                     = 4,
    EVENT_RESUME_WP                 = 5
};

enum ZhaorenSpells
{
    SPELL_LIGHTNING_POOL            = 126006,
    SPELL_STUNNED_BY_FIREWORKS      = 125992,
    SPELL_SERPENT_SWEEP             = 125990,
    SPELL_FORCECAST_SUMMON_SHANG    = 128808,
    SPELL_OVERPACKED_FIREWORK       = 104855,
    SPELL_FIREWORK_INACTIVE         = 125964
};

enum ZhaorenPhases
{
    PHASE_FLYING                    = 1,
    PHASE_GROUNDED                  = 2,
    PHASE_STAY_IN_CENTER            = 3
};

enum ZhaorenMisc
{
    ZHAOREN_PATH                    = 210014590,
    NPC_JI_FIREPAW                  = 64505,
    NPC_AYSA_CLOUDSINGER            = 64506,
    NPC_DAFENG                      = 64532,
    NPC_FIREWORK                    = 64507,
    DATA_1                          = 1,
    DATA_COMBAT                     = 2,
    DATA_AYSA_TALK_3                = 3,
    DATA_PHASE_OOC                  = 4,
    DATA_ZHAOREN_DEATH              = 5,
    DATA_EVADE                      = 6
};

Position ZhaoPos[] =
{
    {699.134f, 4170.06f, 216.06f}, // Center
};

//55786
struct npc_zhaoren : public ScriptedAI
{
    npc_zhaoren(Creature* creature) : ScriptedAI(creature) { }

    Position const pos = { 723.163f, 4163.8f, 204.999f };

private:
    uint8 phase;
    bool _sweepScheduled;

    void Reset() override
    {
        events.Reset();
        me->SetReactState(REACT_PASSIVE);
        me->setActive(true);
        phase = 0;
        _sweepScheduled = false;

        if (Creature* creature = me->FindNearestCreature(NPC_JI_FIREPAW, me->GetVisibilityRange(), true))
            creature->AI()->SetData(DATA_EVADE, DATA_EVADE);

        std::list<Creature*> fireworks;
        me->GetCreatureListWithEntryInGrid(fireworks, NPC_FIREWORK, me->GetVisibilityRange());
        for (std::list<Creature*>::iterator itr = fireworks.begin(); itr != fireworks.end(); ++itr)
        {
            (*itr)->RemoveAura(SPELL_FIREWORK_INACTIVE);
            (*itr)->AI()->SetData(DATA_1, DATA_1);
        }
        me->GetMotionMaster()->Clear();
        me->GetMotionMaster()->MovePoint(0, ZhaoPos[0].GetPositionX(), ZhaoPos[0].GetPositionY(), ZhaoPos[0].GetPositionZ());
    }

    void EnterCombat(Unit* /*who*/) override
    {
        me->GetMotionMaster()->MovePath(ZHAOREN_PATH, true);
        events.SetPhase(PHASE_FLYING);
        events.ScheduleEvent(EVENT_LIGHTNING, 5000);
    }

   void SpellHit(Unit* caster, SpellInfo const* spell) override
   {
        if (spell->Id == SPELL_OVERPACKED_FIREWORK)
        {
            if (!me->IsInCombat())
                me->CombatStart(caster);
        }
   }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == EVENT_MOVE_CENTER)
            events.ScheduleEvent(EVENT_STUN, 0);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->IsPlayer())
            if (me->getThreatManager().getThreatList().empty())
                me->ForcedDespawn(0, 10s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastAOE(SPELL_FORCECAST_SUMMON_SHANG, true);

        if (Creature* creature = me->FindNearestCreature(NPC_JI_FIREPAW, me->GetVisibilityRange(), true))
            creature->AI()->SetData(DATA_ZHAOREN_DEATH, DATA_ZHAOREN_DEATH);
        if (Creature* creature = me->FindNearestCreature(NPC_AYSA_CLOUDSINGER, me->GetVisibilityRange(), true))
            creature->AI()->SetData(DATA_ZHAOREN_DEATH, DATA_ZHAOREN_DEATH);
        if (Creature* creature = me->FindNearestCreature(NPC_DAFENG, me->GetVisibilityRange(), true))
            creature->AI()->SetData(DATA_ZHAOREN_DEATH, DATA_ZHAOREN_DEATH);
        me->ForcedDespawn(10000, 10s);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);
        if (phase == 0 && HealthBelowPct(85))
        {
            phase++;
            if (Creature* creature = me->FindNearestCreature(NPC_AYSA_CLOUDSINGER, me->GetVisibilityRange(), true))
                creature->AI()->SetData(DATA_1, DATA_1);
        }
        if (phase == 1 && HealthBelowPct(75))
        {
            phase++;
            events.SetPhase(PHASE_GROUNDED);
            events.CancelEvent(EVENT_LIGHTNING);
            events.ScheduleEvent(EVENT_MOVE_CENTER, 0);
        }
        if (phase == 2 && HealthBelowPct(25))
        {
            phase++;
            events.SetPhase(PHASE_STAY_IN_CENTER);
            events.CancelEvent(EVENT_LIGHTNING);
            events.ScheduleEvent(EVENT_MOVE_CENTER, 0);
        }
        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_LIGHTNING:
            {
                std::list<HostileReference*> threatList = me->getThreatManager().getThreatList();
                if (!threatList.empty())
                {
                    for (HostileReference* ref : threatList)
                        if (ref->getTarget()->IsPlayer())
                            DoCast(ref->getTarget(), SPELL_LIGHTNING_POOL);

                    events.ScheduleEvent(EVENT_LIGHTNING, events.IsInPhase(PHASE_FLYING) ? 5000 : 3500);
                    if (!_sweepScheduled && events.IsInPhase(PHASE_STAY_IN_CENTER))
                    {
                        events.ScheduleEvent(EVENT_SWEEP, 15000, 0, PHASE_STAY_IN_CENTER);
                        _sweepScheduled = true;
                    }
                }
                else
                me->ForcedDespawn(0, 10s);
                break;
            }
            case EVENT_MOVE_CENTER:
                me->GetMotionMaster()->MovePoint(EVENT_MOVE_CENTER, pos);
                break;

            case EVENT_STUN:
                DoCast(SPELL_STUNNED_BY_FIREWORKS);
                events.ScheduleEvent(EVENT_SWEEP, 12000);
                if (Creature* creature = me->FindNearestCreature(NPC_AYSA_CLOUDSINGER, me->GetVisibilityRange(), true))
                {
                    if (phase == 2)
                        creature->AI()->SetData(DATA_COMBAT, DATA_COMBAT);
                    else if (phase == 3)
                        creature->AI()->SetData(DATA_AYSA_TALK_3, DATA_AYSA_TALK_3);
                }
                if (Creature* creature = me->FindNearestCreature(NPC_JI_FIREPAW, me->GetVisibilityRange(), true))
                    creature->AI()->SetData(DATA_COMBAT, DATA_COMBAT);
                break;

            case EVENT_SWEEP:
                events.CancelEvent(EVENT_LIGHTNING);
                DoCast(SPELL_SERPENT_SWEEP);
                _sweepScheduled = false;
                events.ScheduleEvent(EVENT_LIGHTNING, 3500, 0, PHASE_STAY_IN_CENTER);
                events.ScheduleEvent(EVENT_RESUME_WP, 5000, 0, PHASE_GROUNDED);
                if (events.IsInPhase(PHASE_GROUNDED))
                    if (Creature* creature = me->FindNearestCreature(NPC_JI_FIREPAW, me->GetVisibilityRange(), true))
                        creature->AI()->SetData(DATA_PHASE_OOC, DATA_PHASE_OOC);
                break;
            case EVENT_RESUME_WP:
                me->GetMotionMaster()->MovePath(ZHAOREN_PATH, true);
                events.SetPhase(PHASE_FLYING);
                events.ScheduleEvent(EVENT_LIGHTNING, 5000);
                break;
            }
        }
    }
};

enum SpellMasterShangFinalEscortNPCs
{
    NPC_MASTER_SHANG    = 55672
};

class spell_master_shang_final_escort_say : public SpellScriptLoader
{
public:
    spell_master_shang_final_escort_say() : SpellScriptLoader("spell_master_shang_final_escort_say") { }

    class spell_master_shang_final_escort_say_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_master_shang_final_escort_say_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetTarget())
                if (Creature* creature = target->FindNearestCreature(NPC_MASTER_SHANG, target->GetVisibilityRange(), true))
                    creature->AI()->Talk(0, target);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_master_shang_final_escort_say_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_master_shang_final_escort_say_AuraScript();
    }
};

enum ShenZinShuBunnySpells
{
    SPELL_TRIGGER_WITH_ANIM_0   = 114898,
    SPELL_TRIGGER               = 106759,
    SPELL_TRIGGER_WITH_ANIM_1   = 118571,
    SPELL_TRIGGER_WITH_TURN     = 118572
};

enum ShenZinShuBunnyTexts
{
    TEXT_1                      = 55550,
    TEXT_2                      = 55568,
    TEXT_3                      = 55569,
    TEXT_4                      = 55570,
    TEXT_5                      = 55572,
    TEXT_6                      = 63407
};

class npc_shen_zin_shu_bunny : public CreatureScript
{
public:
    npc_shen_zin_shu_bunny() : CreatureScript("npc_shen_zin_shu_bunny") { }

    struct npc_shen_zin_shu_bunnyAI : public ScriptedAI
    {
        npc_shen_zin_shu_bunnyAI(Creature* creature) : ScriptedAI(creature) { }

        void Initialize()
        {
            _hitCount = 0;
        }

        void Reset() override
        {
            Initialize();
            me->setActive(true);
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            switch (spell->Id)
            {
                case SPELL_TRIGGER_WITH_ANIM_0:
                    me->Talk(TEXT_1, CHAT_MSG_MONSTER_SAY, 300.0f, caster);
                    me->PlayDirectSound(27822, caster->ToPlayer());
                    break;
                case SPELL_TRIGGER:
                    me->Talk(TEXT_2, CHAT_MSG_MONSTER_SAY, 300.0f, caster);
                    me->PlayDirectSound(27823, caster->ToPlayer());
                    break;
                case SPELL_TRIGGER_WITH_ANIM_1:
                    if (_hitCount == 0)
                    {
                        me->Talk(TEXT_3, CHAT_MSG_MONSTER_SAY, 300.0f, caster);
                        me->PlayDirectSound(27824, caster->ToPlayer());
                        _hitCount++;
                    }
                    else if (_hitCount == 1)
                    {
                        me->Talk(TEXT_4, CHAT_MSG_MONSTER_SAY, 300.0f, caster);
                        me->PlayDirectSound(27825, caster->ToPlayer());
                        _hitCount++;
                    }
                    else if (_hitCount == 2)
                    {
                        me->Talk(TEXT_6, CHAT_MSG_MONSTER_SAY, 350.0f, caster);
                        me->PlayDirectSound(27827, caster->ToPlayer());
                        _hitCount = 0;
                    }
                    break;
                case SPELL_TRIGGER_WITH_TURN:
                    me->Talk(TEXT_5, CHAT_MSG_MONSTER_SAY, 300.0f, caster);
                    me->PlayDirectSound(27826, caster->ToPlayer());
                    break;
            }
        }

    private:
        uint8 _hitCount;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_shen_zin_shu_bunnyAI(creature);
    }
};

class spell_injured_sailor_feign_death : public SpellScriptLoader
{
public:
    spell_injured_sailor_feign_death() : SpellScriptLoader("spell_injured_sailor_feign_death") { }

    class spell_injured_sailor_feign_death_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_injured_sailor_feign_death_AuraScript);

        void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget();
            target->AddUnitFlag(UNIT_FLAG_UNK_29);
            target->AddUnitFlag2(UNIT_FLAG2_FEIGN_DEATH);
            target->SetHealth(target->CountPctFromMaxHealth(25));
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_injured_sailor_feign_death_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_injured_sailor_feign_death_AuraScript();
    }
};

enum RescueInjuredSailor
{
    SPELL_RESCUE_SAILOR_MALE_CAST   = 105520,
    SPELL_RESCUE_SAILOR_FEMALE_CAST = 129340,
    NPC_RESCUED_SAILOR              = 56236
};

class spell_rescue_injured_sailor : public SpellScriptLoader
{
public:
    spell_rescue_injured_sailor() : SpellScriptLoader("spell_rescue_injured_sailor") { }

    class spell_rescue_injured_sailor_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rescue_injured_sailor_SpellScript);

        bool Load() override
        {
            return GetCaster()->GetTypeId() == TYPEID_PLAYER;
        }

        void HandleDummy(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            Player* player = GetCaster()->ToPlayer();

            if (player->getGender() == GENDER_MALE)
                player->CastSpell(player, SPELL_RESCUE_SAILOR_MALE_CAST, true);
            else
                player->CastSpell(player, SPELL_RESCUE_SAILOR_FEMALE_CAST, true);
        }

        void HandleSummon(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            GetCaster()->GetMap()->SummonCreature(NPC_RESCUED_SAILOR, GetCaster()->GetPosition(), 0, 240000, GetCaster());
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_rescue_injured_sailor_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            OnEffectHit += SpellEffectFn(spell_rescue_injured_sailor_SpellScript::HandleSummon, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rescue_injured_sailor_SpellScript();
    }
};

enum WreckOfTheSkyseeker
{
    SPELL_CANCEL_RESCUE_AURA    = 117987,
    NPC_INJURED_SAILOR          = 56236,
    QUEST_NONE_LEFT_BEHIND      = 29794
};

class at_wreck_of_the_skyseeker_injured_sailor : public AreaTriggerScript
{
public:
    at_wreck_of_the_skyseeker_injured_sailor() : AreaTriggerScript("at_wreck_of_the_skyseeker_injured_sailor") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/, bool entered) override
    {
        if (player->IsAlive() && player->IsVehicle() && player->GetQuestStatus(QUEST_NONE_LEFT_BEHIND) == QUEST_STATUS_INCOMPLETE)
        {
            if (entered)
            {
                if (Creature* creature = player->FindNearestCreature(NPC_INJURED_SAILOR, 1.0f, true))
                    creature->CastSpell(player, SPELL_CANCEL_RESCUE_AURA, true);

                return true;
            }
        }
        return false;
    }
};

enum AysaVordrakaFightEvents
{
    EVENT_TEMPERED_FURY         = 1,
    EVENT_COMBAT_ROLL           = 2,
    EVENT_UPDATE_PHASES         = 3
};

enum AysaVordrakaFightSpells
{
    SPELL_TEMPERED_FURY         = 117275,
    SPELL_COMBAT_ROLL           = 117312,
    SPELL_FORCECAST_SUMMON_AYSA = 117499,
    SPELL_DEEP_SEA_SMASH        = 117287
};

enum AysaVordrakaFightData
{
    DATA_AYSA_TALK_INTRO        = 1,
    DATA_AYSA_TALK_SMASH        = 2,
    DATA_SUMMON_AGGRESSORS      = 3,
    DATA_VORDRAKA_DEATH         = 4,
};

enum AysaVordrakaFightTexts
{
    TEXT_INTRO                  = 0,
    TEXT_SMASH                  = 1,
    TEXT_REINFORCEMENTS         = 2,
    TEXT_LOW_HP                 = 3,
    TEXT_DEATH                  = 4
};

enum AysaVordrakaFightMisc
{
    QUEST_AN_ANCIENT_EVIL       = 29798,
    QUEST_RISKING_IT_ALL        = 30767,
    NPC_VORDRAKA                = 56009,
    DB_PHASE_FIGHT              = 543,
    DB_PHASE_AFTER_FIGHT        = 993
};

class npc_aysa_vordraka_fight : public CreatureScript
{
public:
    npc_aysa_vordraka_fight() : CreatureScript("npc_aysa_vordraka_fight") { }

    struct npc_aysa_vordraka_fightAI : public ScriptedAI
    {
        npc_aysa_vordraka_fightAI(Creature* creature) : ScriptedAI(creature) {
            me->SetReactState(REACT_DEFENSIVE);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->IsPlayer())
                if (Creature* creature = me->FindNearestCreature(NPC_VORDRAKA, me->GetVisibilityRange(), true))
                    AttackStart(creature);
        }

        void EnterCombat(Unit* who) override
        {
            who->GetAI()->AttackStart(me);
            _events.ScheduleEvent(EVENT_TEMPERED_FURY, urand(2000, 4000));
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (HealthAbovePct(85))
                damage = urand(1, 2);
            else
                me->SetHealth(me->GetMaxHealth() * 0.85f);
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_DEEP_SEA_SMASH)
            {
                _events.CancelEvent(EVENT_TEMPERED_FURY);
                _events.ScheduleEvent(EVENT_COMBAT_ROLL, 1000);
            }
        }

        void SetData(uint32 id, uint32 /*value*/) override
        {
            switch (id)
            {
                case DATA_AYSA_TALK_INTRO:
                    Talk(TEXT_INTRO);
                    break;
                case DATA_AYSA_TALK_SMASH:
                    Talk(TEXT_SMASH);
                    break;
                case DATA_SUMMON_AGGRESSORS:
                    Talk(TEXT_REINFORCEMENTS);
                    break;
                case DATA_VORDRAKA_DEATH:
                    Talk(TEXT_DEATH);
                    EnterEvadeMode(EVADE_REASON_OTHER);
                    _events.CancelEvent(EVENT_TEMPERED_FURY);
                    break;
            }
        }

        void JustReachedHome() override
        {
            _events.ScheduleEvent(EVENT_UPDATE_PHASES, 5000);
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_RISKING_IT_ALL)
                DoCast(player, SPELL_FORCECAST_SUMMON_AYSA, true);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_TEMPERED_FURY:
                        DoCastVictim(SPELL_TEMPERED_FURY);
                        _events.ScheduleEvent(EVENT_TEMPERED_FURY, urand(2000, 4000));
                        break;
                    case EVENT_COMBAT_ROLL:
                        // todo: cast combat roll only if it won't kick Vordraka outside of ship boundaries
                        DoCastVictim(SPELL_COMBAT_ROLL);
                        _events.ScheduleEvent(EVENT_TEMPERED_FURY, urand(5000, 7000));
                        break;
                    case EVENT_UPDATE_PHASES:
                        std::list<Player*> players;
                        me->GetPlayerListInGrid(players, me->GetVisibilityRange());
                        for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            if ((*itr)->ToPlayer()->GetQuestStatus(QUEST_AN_ANCIENT_EVIL) == QUEST_STATUS_COMPLETE)
                            {
                                PhasingHandler::AddPhase(*itr, DB_PHASE_AFTER_FIGHT, true);
                                PhasingHandler::RemovePhase(*itr, DB_PHASE_FIGHT, true);
                            }
                        }
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_aysa_vordraka_fightAI(creature);
    }
};

class spell_tempered_fury : public SpellScriptLoader
{
public:
    spell_tempered_fury() : SpellScriptLoader("spell_tempered_fury") { }

    class spell_tempered_fury_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_tempered_fury_SpellScript);

        void HandleJumpDest(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            Position const jumpPos = GetHitDest()->GetPosition();
            GetCaster()->GetMotionMaster()->MoveJump(jumpPos, 20, 0);
        }

        void Register() override
        {
            OnEffectLaunch += SpellEffectFn(spell_tempered_fury_SpellScript::HandleJumpDest, EFFECT_0, SPELL_EFFECT_JUMP_DEST);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_tempered_fury_SpellScript();
    }
};

enum VordrakaEvents
{
    EVENT_SMASH                     = 1,
    EVENT_RUPTURE                   = 2,
    EVENT_SUMMON_AGGRESSOR          = 3
};

enum VordrakaSpells
{
    SPELL_DEEP_SEA_RUPTURE          = 117456,
    SPELL_FORCECAST_AGGRESSOR       = 117403,
    SPELL_DEATH_INVIS               = 117555,
    SPELL_SEE_DEATH_INVIS           = 117491
};

enum VordrakaMisc
{
    NPC_AYSA_CLOUDSINGER_VORDRAKA   = 56416,
    NPC_DEEPSCALE_AGGRESSOR         = 60685
};

class npc_vordraka : public CreatureScript
{
public:
    npc_vordraka() : CreatureScript("npc_vordraka") { }

    struct npc_vordrakaAI : public ScriptedAI
    {
        npc_vordrakaAI(Creature* creature) : ScriptedAI(creature) {
            Initialize();
        }

        void Initialize()
        {
            _playerParticipating = false;
            _secondSmash = false;
            _smashAnnounced = false;
            _aggressorSummoned = 0;
        }

        void Reset() override
        {
            _events.Reset();
            Initialize();
            me->setActive(true);
            me->SetReactState(REACT_PASSIVE);
            PhasingHandler::AddPhase(me, 543, true);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _events.ScheduleEvent(EVENT_SMASH, 8000);
            _events.ScheduleEvent(EVENT_RUPTURE, urand(12000, 16000));
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (HealthAbovePct(85) && attacker->IsCreature())
                if (attacker->GetEntry() == NPC_AYSA_CLOUDSINGER_VORDRAKA)
                    damage = urand(1, 2);

            if (HealthBelowPct(85) && attacker->IsCreature())
                if (attacker->GetEntry() == NPC_AYSA_CLOUDSINGER_VORDRAKA)
                    me->SetHealth(me->GetHealth() + damage);

            if (!_playerParticipating && attacker->ToPlayer())
            {
                if (Creature* creature = me->FindNearestCreature(NPC_AYSA_CLOUDSINGER_VORDRAKA, me->GetVisibilityRange(), true))
                {
                    creature->AI()->SetData(DATA_AYSA_TALK_INTRO, DATA_AYSA_TALK_INTRO);
                    _playerParticipating = true;
                }
            }

            if (damage >= me->GetHealth())
            {
                std::list<HostileReference*> threatList;
                threatList = me->getThreatManager().getThreatList();
                for (std::list<HostileReference*>::const_iterator itr = threatList.begin(); itr != threatList.end(); ++itr)
                    if (Player* target = (*itr)->getTarget()->ToPlayer())
                        if (target->GetQuestStatus(QUEST_AN_ANCIENT_EVIL) == QUEST_STATUS_INCOMPLETE)
                            target->KilledMonsterCredit(me->GetEntry());
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            std::list<Creature*> summonedAggressors;
            me->GetCreatureListWithEntryInGrid(summonedAggressors, NPC_DEEPSCALE_AGGRESSOR, me->GetVisibilityRange());
            for (std::list<Creature*>::const_iterator itr = summonedAggressors.begin(); itr != summonedAggressors.end(); ++itr)
                (*itr)->ToCreature()->DespawnOrUnsummon(0);

            if (Creature* creature = me->FindNearestCreature(NPC_AYSA_CLOUDSINGER_VORDRAKA, me->GetVisibilityRange(), true))
                creature->AI()->SetData(DATA_VORDRAKA_DEATH, DATA_VORDRAKA_DEATH);

            std::list<Player*> playersVisibility;
            me->GetPlayerListInGrid(playersVisibility, me->GetVisibilityRange());
            for (std::list<Player*>::const_iterator itr = playersVisibility.begin(); itr != playersVisibility.end(); ++itr)
                (*itr)->CastSpell((*itr), SPELL_SEE_DEATH_INVIS, true);

            DoCastSelf(SPELL_DEATH_INVIS, true);
            me->DespawnOrUnsummon(20000, Seconds(1));
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            if (!UpdateVictim())
                return;

            if (_aggressorSummoned == 0 && HealthBelowPct(60))
            {
                _events.ScheduleEvent(EVENT_SUMMON_AGGRESSOR, 0);
                _events.ScheduleEvent(EVENT_SUMMON_AGGRESSOR, 0);
            }

            if (_aggressorSummoned == 2 && HealthBelowPct(30))
            {
                _events.ScheduleEvent(EVENT_SUMMON_AGGRESSOR, 0);
                _events.ScheduleEvent(EVENT_SUMMON_AGGRESSOR, urand(1000, 5000));
            }

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SMASH:
                        DoCastVictim(SPELL_DEEP_SEA_SMASH);
                        _events.ScheduleEvent(EVENT_SMASH, 12000);
                        if (_playerParticipating && !_smashAnnounced)
                        {
                            if (_secondSmash)
                            {
                                if (Creature* creature = me->FindNearestCreature(NPC_AYSA_CLOUDSINGER_VORDRAKA, me->GetVisibilityRange(), true))
                                {
                                    creature->AI()->SetData(DATA_AYSA_TALK_SMASH, DATA_AYSA_TALK_SMASH);
                                    _smashAnnounced = true;
                                }
                            }
                            _secondSmash = true;
                        }
                        break;
                    case EVENT_RUPTURE:
                        DoCast(SelectTarget(SELECT_TARGET_RANDOM, 1), SPELL_DEEP_SEA_RUPTURE);
                        _events.ScheduleEvent(EVENT_RUPTURE, urand(12000, 16000));
                        break;
                    case EVENT_SUMMON_AGGRESSOR:
                        DoCast(me, SPELL_FORCECAST_AGGRESSOR, true);
                        if (_aggressorSummoned == 0)
                            if (Creature* creature = me->FindNearestCreature(NPC_AYSA_CLOUDSINGER_VORDRAKA, me->GetVisibilityRange(), true))
                                creature->AI()->SetData(DATA_SUMMON_AGGRESSORS, DATA_SUMMON_AGGRESSORS);
                        _aggressorSummoned++;
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        bool _playerParticipating;
        bool _secondSmash;
        bool _smashAnnounced;
        uint8 _aggressorSummoned;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_vordrakaAI(creature);
    }
};

class spell_summon_deep_sea_aggressor : public SpellScriptLoader
{
public:
    spell_summon_deep_sea_aggressor() : SpellScriptLoader("spell_summon_deep_sea_aggressor") { }

    class spell_summon_deep_sea_aggressor_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_summon_deep_sea_aggressor_SpellScript);

        void HandleSummon(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            uint32 entry = GetSpellInfo()->GetEffect(effIndex)->MiscValue;
            SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(GetSpellInfo()->GetEffect(effIndex)->MiscValueB);
            int32 duration = GetSpellInfo()->GetDuration();

            if (!entry || !properties || !duration)
                return;

            Position const spawnPosition[15] =
            {
                { 313.9983f, 3973.418f, 86.55342f },
                { 249.4063f, 3972.389f, 75.72471f },
                { 316.1406f, 3979.06f, 85.13287f },
                { 252.6632f, 4008.125f, 78.23856f },
                { 266.5712f, 4014.581f, 79.36336f },
                { 269.8854f, 4017.54f, 79.76926f },
                { 271.9392f, 4018.929f, 79.99733f },
                { 309.474f, 3964.438f, 87.50405f },
                { 247.1337f, 3968.642f, 75.44573f },
                { 292.3837f, 3925.203f, 87.69834f },
                { 254.1892f, 3982.678f, 71.8816f },
                { 276.5608f, 4034.241f, 75.90926f },
                { 287.4236f, 3935.447f, 85.55875f },
                { 256.0226f, 3963.012f, 74.87388f },
                { 301.6267f, 3923.195f, 87.80573f }
            };

            if (TempSummon* summon = GetCaster()->GetMap()->SummonCreature(entry, spawnPosition[urand(0, 14)], properties, duration, GetCaster()))
                summon->SetTempSummonType(TEMPSUMMON_CORPSE_TIMED_DESPAWN);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_summon_deep_sea_aggressor_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_summon_deep_sea_aggressor_SpellScript();
    }
};

class areatrigger_healing_sphere : public AreaTriggerEntityScript
{
public:
    areatrigger_healing_sphere() : AreaTriggerEntityScript("areatrigger_healing_sphere") { }

    struct areatrigger_healing_sphereAI : AreaTriggerAI
    {
        areatrigger_healing_sphereAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* /*unit*/) override
        {
            at->SetDuration(0);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new areatrigger_healing_sphereAI(areatrigger);
    }
};

enum NpcHealersActive
{
    DATA_HEALER_ACTIVE          = 1,
    DATA_HEALER_DIED            = 2,
    WORLD_STATE_HEALERS_ACTIVE  = 6488
};

class npc_healers_active_bunny : public CreatureScript
{
public:
    npc_healers_active_bunny() : CreatureScript("npc_healers_active_bunny") { }

    struct npc_healers_active_bunnyAI : public ScriptedAI
    {
        npc_healers_active_bunnyAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset()
        {
            _healersActive = 0;
        }

        void SetData(uint32 id, uint32 value)
        {
            if (id == DATA_HEALER_ACTIVE)
            {
                if (_healersActive < 12)
                    _healersActive += value;
            }
            else if (id == DATA_HEALER_DIED)
            {
                if (_healersActive > 0)
                    _healersActive -= value;
            }

            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            if (playerList.isEmpty())
                return;

            for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                if (Player* player = itr->GetSource())
                    if (player->GetAreaId() == AREA_WANDERING_ISLE_WRECK_OF_THE_SKYSEEKER)
                        player->SendUpdateWorldState(WORLD_STATE_HEALERS_ACTIVE, _healersActive);
        }

        uint32 GetData(uint32 id) const
        {
            if (id == DATA_HEALER_ACTIVE)
                return _healersActive;

            return 0;
        }

    private:
        uint8 _healersActive;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_healers_active_bunnyAI(creature);
    }
};

enum HealingShenzinSuSpells
{
    SPELL_HEALING_SHENZIN_SU_CREDIT = 108898
};

class spell_healing_shenzin_su : public SpellScriptLoader
{
public:
    spell_healing_shenzin_su() : SpellScriptLoader("spell_healing_shenzin_su") { }

    class spell_healing_shenzin_su_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_healing_shenzin_su_AuraScript);

        void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
        {
            if (Unit* target = GetTarget())
            {
                // somehow get worldstate value, so the alternate power bar can fill based on active healers
                target->ModifyPower(POWER_ALTERNATE_POWER, 700);

                if (target->GetPowerPct(POWER_ALTERNATE_POWER) == 100)
                {
                    target->CastSpell(GetTarget(), SPELL_HEALING_SHENZIN_SU_CREDIT, true);
                    target->RemoveAura(GetId());
                }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_healing_shenzin_su_AuraScript::HandleEffectPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_healing_shenzin_su_AuraScript();
    }
};

enum TurtleHealedPhaseTimerSpells
{
    SPELL_TURTLE_HEALED_PHASE_UPDATE    = 118232
};

class spell_turtle_healed_phase_timer : public SpellScriptLoader
{
public:
    spell_turtle_healed_phase_timer() : SpellScriptLoader("spell_turtle_healed_phase_timer") { }

    class spell_turtle_healed_phase_timer_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_turtle_healed_phase_timer_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetTarget())
                if (target->IsPlayer())
                    target->CastSpell(GetTarget(), SPELL_TURTLE_HEALED_PHASE_UPDATE, true);
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_turtle_healed_phase_timer_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_turtle_healed_phase_timer_AuraScript();
    }
};

enum AllyHordeArgumentNPCs
{
    NPC_KORGA_STRONGMANE    = 60888,
    NPC_DELORA_LIONHEART    = 60889
};

class spell_ally_horde_argument : public SpellScriptLoader
{
public:
    spell_ally_horde_argument() : SpellScriptLoader("spell_ally_horde_argument") { }

    class spell_ally_horde_argument_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_ally_horde_argument_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetTarget())
                if (Creature* creature = target->FindNearestCreature(NPC_KORGA_STRONGMANE, 40.0f, true))
                    creature->AI()->Talk(0, target);
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetTarget())
                if (Creature* creature = target->FindNearestCreature(NPC_DELORA_LIONHEART, 40.0f, true))
                    creature->AI()->Talk(0, target);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_ally_horde_argument_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_ally_horde_argument_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_ally_horde_argument_AuraScript();
    }
};

class spell_pandaren_faction_choice : public SpellScriptLoader
{
public:
    spell_pandaren_faction_choice() : SpellScriptLoader("spell_pandaren_faction_choice") { }

    class spell_pandaren_faction_choice_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pandaren_faction_choice_SpellScript);

        void HandleScriptEffect(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (caster->IsPlayer())
                    caster->ToPlayer()->ShowNeutralPlayerFactionSelectUI();
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_pandaren_faction_choice_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pandaren_faction_choice_SpellScript();
    }
};

class spell_faction_choice_trigger : public SpellScriptLoader
{
public:
    spell_faction_choice_trigger() : SpellScriptLoader("spell_faction_choice_trigger") { }

    class spell_faction_choice_trigger_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_faction_choice_trigger_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetTarget())
                if (target->IsPlayer())
                    target->CastSpell(target, GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints, true);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_faction_choice_trigger_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_SCREEN_EFFECT, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_faction_choice_trigger_AuraScript();
    }
};

enum BalloonExitTimerSpells
{
    SPELL_BALOON_EXIT_MOVIE = 132212
};

class spell_balloon_exit_timer : public SpellScriptLoader
{
public:
    spell_balloon_exit_timer() : SpellScriptLoader("spell_balloon_exit_timer") { }

    class spell_balloon_exit_timer_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_balloon_exit_timer_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetTarget())
                if (target->IsPlayer())
                    target->CastSpell(target, SPELL_BALOON_EXIT_MOVIE, true);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_balloon_exit_timer_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_balloon_exit_timer_AuraScript();
    }
};

class npc_ji_firepaw_escort : public CreatureScript
{
public:
    npc_ji_firepaw_escort() : CreatureScript("npc_ji_firepaw_escort") { }

    struct npc_ji_firepaw_escortAI : public ScriptedAI
    {
        npc_ji_firepaw_escortAI(Creature* creature) : ScriptedAI(creature)
        {
            playerGuid = 0;
        }

        uint64 playerGuid;

        void IsSummonedBy(Unit* summoner) override
        {
            //playerGuid = summoner->GetGUID();
            me->GetMotionMaster()->MoveFollow(summoner, 1.0f, 1.0f, MOTION_SLOT_ACTIVE);
        }

        void UpdateAI(const uint32 diff)
        {
            Player* summoner;
            //Player* summoner = sObjectAccessor->FindPlayer(playerGuid);
//            if (!summoner)
                return;

            if (Unit* target = summoner->GetVictim())
            {
                me->Attack(target, true);
                DoMeleeAttackIfReady();
                return;
            }

            if ((summoner->GetQuestStatus(29780) == QUEST_STATUS_COMPLETE || summoner->GetQuestStatus(29780) == QUEST_STATUS_REWARDED) && (summoner->GetQuestStatus(29779) == QUEST_STATUS_COMPLETE
                || summoner->GetQuestStatus(29779) == QUEST_STATUS_REWARDED) && (summoner->GetQuestStatus(29781) == QUEST_STATUS_COMPLETE || summoner->GetQuestStatus(29781) == QUEST_STATUS_REWARDED))
                me->DespawnOrUnsummon();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ji_firepaw_escortAI(creature);
    }
};

class npc_ji_firepaw : public CreatureScript
{
public:
    npc_ji_firepaw() : CreatureScript("npc_ji_firepaw")
    {
        isSummoned = false;
    }

    bool isSummoned;

    void SummonHiFirepawHelper(Player* summoner, uint32 entry)
    {
        //uint32 phase = summoner->GetPhaseMask();
        uint32 team = summoner->GetTeam();
        Position pos;

       // summoner->GetPosition(&pos);

        Guardian* summon = new Guardian(NULL, summoner, false);

      //  if (!summon->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_UNIT), summoner->GetMap(), phase, entry, 0, team, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation()))
        {
            delete summon;
            return;
        }



        summon->SetHomePosition(pos);
        summon->InitStats(0);
        summoner->GetMap()->AddToMap(summon->ToCreature());
        summon->InitSummon();
        summon->InitStatsForLevel(10);
        summon->SetFollowAngle(summoner->GetAngle(summon));
        summon->SetReactState(REACT_AGGRESSIVE);

    }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        std::list<Creature*> summonList;
        GetCreatureListWithEntryInGrid(summonList, player, 59960, 6.0f);

        for (auto summoned : summonList)
            isSummoned = true;

        if (isSummoned == false)
        {
            if (quest->GetQuestId() == 29779)
            {
                SummonHiFirepawHelper(player, 59960);
                isSummoned = true;
            }

            if (quest->GetQuestId() == 29780)
            {
                SummonHiFirepawHelper(player, 59960);
                isSummoned = true;
            }

            if (quest->GetQuestId() == 29781)
            {
                SummonHiFirepawHelper(player, 59960);
                isSummoned = true;
            }
        }

        return true;
    }
};

class mob_tushui_trainee : public CreatureScript
{
public:
    mob_tushui_trainee() : CreatureScript("mob_tushui_trainee") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_tushui_trainee_AI(creature);
    }

    struct mob_tushui_trainee_AI : public ScriptedAI
    {
        mob_tushui_trainee_AI(Creature* creature) : ScriptedAI(creature) {}

        enum data
        {
            EVENT_1 = 1,
            EVENT_2 = 2,
            SPELL = 109080,
        };

        EventMap events;

        void Reset()
        {
            events.Reset();
            me->SetReactState(REACT_DEFENSIVE);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
            events.RescheduleEvent(EVENT_2, 5000);
        }

        void EnterCombat(Unit* unit)
        {
            events.RescheduleEvent(EVENT_1, 5000);
            events.CancelEvent(EVENT_2);
        }

        void DamageTaken(Unit* attacker , uint32& damage) override
        {
            if (attacker && me->HealthBelowPctDamaged(5, damage))
            {
                if (attacker->GetTypeId() == TYPEID_PLAYER)
                    attacker->ToPlayer()->KilledMonsterCredit(54586, ObjectGuid::Empty);
                me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
                me->CombatStop();
                me->SetFullHealth();
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
                me->DespawnOrUnsummon(4000);
                damage = 0;
            }
        }

        void UpdateAI(uint32 diff)
        {
            UpdateVictim();

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    if (me->GetVictim())
                        me->CastSpell(me->GetVictim(), SPELL, true);
                    events.RescheduleEvent(EVENT_1, 5000);
                    break;
                case EVENT_2:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMEDOFF);
                    events.RescheduleEvent(EVENT_2, 5000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

// Should be done by summon npc 59591
class mob_master_shang_xi : public CreatureScript
{
public:
    mob_master_shang_xi() : CreatureScript("mob_master_shang_xi") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == 29408) // La lecon du parchemin brulant
        {
            creature->AddAura(114610, creature);
            creature->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER));
            creature->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
            player->KilledMonsterCredit(59591);
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_master_shang_xi_AI(creature);
    }

    struct mob_master_shang_xi_AI : public ScriptedAI
    {
        mob_master_shang_xi_AI(Creature* creature) : ScriptedAI(creature)
        {
            checkPlayersTime = 2000;
        }

        uint32 checkPlayersTime;

        void SpellHit(Unit* caster, const SpellInfo* pSpell)
        {
            if (pSpell->Id == 114746) // Attraper la flamme
            {
                if (caster->GetTypeId() == TYPEID_PLAYER)
                {
                    if (caster->ToPlayer()->GetQuestStatus(29408) == QUEST_STATUS_INCOMPLETE)
                    {
                        me->CastSpell(caster, 114611, true);
                        me->RemoveAurasDueToSpell(114610);
                        me->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER));
                        me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
                    }
                }
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (checkPlayersTime <= diff)
            {
                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, me, 5.0f);

                bool playerWithQuestNear = false;

                for (std::list<Player*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                {
                    if ((*itr)->GetQuestStatus(29408) == QUEST_STATUS_INCOMPLETE && !(*itr)->HasItemCount(80212))
                        playerWithQuestNear = true;
                }

                if (playerWithQuestNear && !me->HasAura(114610))
                {
                    me->AddAura(114610, me);
                    me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER));
                    me->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
                }
                else if (!playerWithQuestNear && me->HasAura(114610))
                {
                    me->RemoveAurasDueToSpell(114610);
                    me->AddUnitFlag(UnitFlags(UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER));
                    me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_SPELLCLICK));
                }

                checkPlayersTime = 2000;
            }
            else
                checkPlayersTime -= diff;
        }
    };
};

// cast 88811 for check something
class boss_jaomin_ro : public CreatureScript
{
public:
    boss_jaomin_ro() : CreatureScript("boss_jaomin_ro") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_jaomin_roAI(creature);
    }

    struct boss_jaomin_roAI : public ScriptedAI
    {
        boss_jaomin_roAI(Creature* creature) : ScriptedAI(creature) {}

        enum eEvents
        {
            EVENT_JAOMIN_JUMP = 1,
            EVENT_HIT_CIRCLE = 2,
            EVENT_FALCON = 3,
            EVENT_RESET = 4,
        };

        EventMap events;
        bool isInFalcon;
        bool fightEnd;

        void EnterCombat(Unit* unit)
        {
            events.RescheduleEvent(EVENT_JAOMIN_JUMP, 1000);
            events.RescheduleEvent(EVENT_HIT_CIRCLE, 2000);
        }

        void Reset()
        {
            events.Reset();
            me->SetReactState(REACT_DEFENSIVE);
            me->SetDisplayId(39755);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1));
            isInFalcon = false;
            fightEnd = false;
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (me->HealthBelowPctDamaged(30, damage) && !isInFalcon)
            {
                isInFalcon = true;
                me->SetDisplayId(39796); //faucon
                events.RescheduleEvent(EVENT_FALCON, 1000);
                events.CancelEvent(EVENT_JAOMIN_JUMP);
                events.CancelEvent(EVENT_HIT_CIRCLE);
            }

            if (me->HealthBelowPctDamaged(5, damage) && !fightEnd)
            {
                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, me, 10.0f);
                for (std::list<Player*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                    (*itr)->KilledMonsterCredit(me->GetEntry(), ObjectGuid::Empty);

                fightEnd = true;
                me->AttackStop();
                me->SetFullHealth();
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1));
                attacker->AttackStop();
                me->SetDisplayId(39755);
                me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
                events.Reset();
                events.RescheduleEvent(EVENT_RESET, 9000);
                DoCast(me, 108959, true);
                damage = 0;
            }

            if (damage >= me->GetHealth())
                damage = 0;
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
          
            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_JAOMIN_JUMP:
                    DoCastVictim(108938);
                    events.RescheduleEvent(EVENT_JAOMIN_JUMP, 30000);
                    break;
                case EVENT_HIT_CIRCLE:
                    DoCastVictim(119301);
                    events.RescheduleEvent(EVENT_HIT_CIRCLE, 8000);
                    break;
                case EVENT_FALCON:
                    DoCast(108935);
                    events.RescheduleEvent(EVENT_FALCON, 6000);
                    break;
                case EVENT_RESET:
                    me->NearTeleportTo(me->GetHomePosition());
                    EnterEvadeMode();
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};


void AddSC_the_wandering_isle()
{
    new spell_summon_troublemaker();
    new spell_meditation_timer_bar();
    new spell_cave_of_scrolls_comp_timer_aura();
    new spell_summon_living_air();
    new spell_fan_the_flames();
    new spell_rock_jump_a();
    new spell_jump_to_front_right();
    new spell_jump_to_front_left();
    new spell_jump_to_back_right();
    new spell_jump_to_back_left();
    new spell_summon_water_spout();
    new spell_water_spout_quest_credit();
    new spell_aysa_congrats_timer();
    new spell_aysa_congrats_trigger_aura();
    new spell_monkey_wisdom_text();
    new spell_ruk_ruk_ooksplosions();
    new spell_master_shang_final_escort_say();
    new spell_injured_sailor_feign_death();
    new spell_rescue_injured_sailor();
    new spell_tempered_fury();
    new spell_summon_deep_sea_aggressor();
    new spell_healing_shenzin_su();
    new spell_turtle_healed_phase_timer();
    new spell_ally_horde_argument();
    new spell_pandaren_faction_choice();
    new spell_faction_choice_trigger();
    new spell_balloon_exit_timer();
    new at_cave_of_meditation();
    new at_singing_pools_transform();
    new at_singing_pools_training_bell();
    new at_temple_of_five_dawns_summon_zhaoren();
    new at_wreck_of_the_skyseeker_injured_sailor();
    new areatrigger_healing_sphere();
    new q_the_way_of_the_tushui();   
    new q_only_the_worthy_shall_pass();   
    new q_passion_of_shenzin_su();
    new npc_balance_pole();
    new npc_tushui_monk_on_pole();
    new npc_shu_playing();
    new npc_ji_firepaw_escort();         
    new npc_ruk_ruk();
    new npc_ruk_ruk_rocket();
    RegisterCreatureAI(npc_zhaoren);
    new npc_ji_firepaw();
    new npc_shen_zin_shu_bunny();
    new npc_aysa_vordraka_fight();
    new npc_vordraka();
    new npc_healers_active_bunny();
    new mob_tushui_trainee();
    new mob_master_shang_xi();
}
