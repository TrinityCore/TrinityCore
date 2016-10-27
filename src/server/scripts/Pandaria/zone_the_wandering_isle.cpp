/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellScript.h"
#include "Player.h"

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
            if (!entry || !properties)
                return;

            int32 duration = GetSpellInfo()->GetDuration();
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

            Position const SpawnPosition = { x, y, z, 3.285759f };

            if (TempSummon* summon = GetCaster()->GetMap()->SummonCreature(entry, SpawnPosition, properties, duration, GetCaster()))
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
            if (!entry || !properties)
                return;

            Position const SpawnPosition[6] =
            {
                { 1237.073f, 3697.739f, 93.62743f },
                { 1230.608f, 3701.063f, 93.94895f },
                { 1229.429f, 3732.776f, 92.22045f },
                { 1223.438f, 3700.607f, 93.93437f },
                { 1239.606f, 3732.907f, 94.10403f },
                { 1224.92f, 3727.201f, 92.4472f }
            };

            int32 duration = GetSpellInfo()->GetDuration();
            uint32 randomPos = urand(0, 5);
            
            if (TempSummon* summon = GetCaster()->GetMap()->SummonCreature(entry, SpawnPosition[randomPos], properties, duration, GetCaster()))
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

enum SingingPoolsATSpells
{
    SPELL_CURSE_OF_THE_FROG     = 102938,
    SPELL_CURSE_OF_THE_SKUNK    = 102939,
    SPELL_CURSE_OF_THE_TURTLE   = 102940,
    SPELL_CURSE_OF_THE_CRANE    = 102941,
    SPELL_RIDE_VEHICLE_POLE     = 102717
};

enum SingingPoolsATNPCs
{
    NPC_CURSED_POOL_CONTROLLER  = 55123
};

enum SingingPoolsATData
{
    DATA_FROG   = 1,
    DATA_SKUNK  = 2,
    DATA_TURTLE = 3,
    DATA_CRANE  = 4
};

class at_singing_pools_transform : public AreaTriggerScript
{
public:
    at_singing_pools_transform() : AreaTriggerScript("at_singing_pools_transform") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* areaTrigger, bool /*entered*/) override
    {
        if (player->IsAlive() && !player->HasAura(SPELL_RIDE_VEHICLE_POLE))
        {
            switch (areaTrigger->ID)
            {
                case 6986:
                case 6987:
                    if (!player->HasAura(SPELL_CURSE_OF_THE_FROG))
                    {
                        player->CastSpell(player, SPELL_CURSE_OF_THE_FROG, true);

                        if (Creature* creature = player->FindNearestCreature(NPC_CURSED_POOL_CONTROLLER, 80.0f, true))
                            creature->AI()->SetDataWithTarget(DATA_FROG, player->GetGUID());
                    }
                    break;
                case 6988:
                case 6989:
                    if (!player->HasAura(SPELL_CURSE_OF_THE_SKUNK))
                    {
                        player->CastSpell(player, SPELL_CURSE_OF_THE_SKUNK, true);

                        if (Creature* creature = player->FindNearestCreature(NPC_CURSED_POOL_CONTROLLER, 60.0f, true))
                            creature->AI()->SetDataWithTarget(DATA_SKUNK, player->GetGUID());
                    }
                    break;
                case 6991:
                case 6992:
                    if (!player->HasAura(SPELL_CURSE_OF_THE_CRANE))
                    {
                        player->CastSpell(player, SPELL_CURSE_OF_THE_CRANE, true);

                        if (Creature* creature = player->FindNearestCreature(NPC_CURSED_POOL_CONTROLLER, 110.0f, true))
                            creature->AI()->SetDataWithTarget(DATA_CRANE, player->GetGUID());
                    }
                    break;
                case 7011:
                case 7012:
                    if (!player->HasAura(SPELL_CURSE_OF_THE_TURTLE))
                    {
                        player->CastSpell(player, SPELL_CURSE_OF_THE_TURTLE, true);

                        if (Creature* creature = player->FindNearestCreature(NPC_CURSED_POOL_CONTROLLER, 50.0f, true))
                            creature->AI()->SetDataWithTarget(DATA_TURTLE, player->GetGUID());
                    }
                    break;
            }
            return true;
        }
        return false;
    }
};

class npc_cursed_pool_controller : public CreatureScript
{
public:
    npc_cursed_pool_controller() : CreatureScript("npc_cursed_pool_controller") { }

    struct npc_cursed_pool_controllerAI : public ScriptedAI
    {
        npc_cursed_pool_controllerAI(Creature* creature) : ScriptedAI(creature) { }

        void SetDataWithTarget(uint32 id, ObjectGuid target)
        {
            if (std::find(targets.begin(), targets.end(), target) == targets.end())
                targets.push_back(target);

            switch (id)
            {
                case DATA_FROG:
                    pool = 1;
                    break;
                case DATA_SKUNK:
                    pool = 2;
                    break;
                case DATA_TURTLE:
                    pool = 3;
                    break;
                case DATA_CRANE:
                    pool = 4;
                    break;
            }
        }

        void MoveInLineOfSight(Unit* who) override // need to check on greater range. now its around 55y
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (std::find(targets.begin(), targets.end(), who->GetGUID()) == targets.end())
                {
                    targets.push_back(who->GetGUID());

                    if (who->HasAura(SPELL_CURSE_OF_THE_FROG))
                        pool = 1;
                    if (who->HasAura(SPELL_CURSE_OF_THE_SKUNK))
                        pool = 2;
                    if (who->HasAura(SPELL_CURSE_OF_THE_TURTLE))
                        pool = 3;
                    if (who->HasAura(SPELL_CURSE_OF_THE_CRANE))
                        pool = 4;
                }
            }
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            for (std::list<ObjectGuid>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
            {
                Player* player = ObjectAccessor::FindPlayer(*itr);
                if (!player)
                    return;

                switch (pool)
                {
                    case 1: // TODO: check position greather than line between points 980.15, 3275.5 - 1002.5, 3281.31 & 909.96, 3280.91 - 916.8, 3283.37
                        if (player->HasAura(SPELL_CURSE_OF_THE_FROG) && player->GetPositionZ() > 118.5f && !player->HasUnitState(UNIT_STATE_JUMPING))
                        {
                            player->RemoveAura(SPELL_CURSE_OF_THE_FROG);
                            targets.erase(itr);
                        }
                        break;
                    case 2:
                        if (player->HasAura(SPELL_CURSE_OF_THE_SKUNK) && player->GetPositionZ() > 114.8f && !player->HasUnitState(UNIT_STATE_JUMPING))
                        {
                            player->RemoveAura(SPELL_CURSE_OF_THE_SKUNK);
                            targets.erase(itr);
                        }
                        break;
                    case 3:
                        if (player->HasAura(SPELL_CURSE_OF_THE_TURTLE) && player->GetPositionZ() > 106.5f && !player->HasUnitState(UNIT_STATE_JUMPING))
                        {
                            player->RemoveAura(SPELL_CURSE_OF_THE_TURTLE);
                            targets.erase(itr);
                        }
                        break;
                    case 4:
                        if (player->HasAura(SPELL_CURSE_OF_THE_CRANE) && player->GetPositionZ() > 80.95f && !player->HasUnitState(UNIT_STATE_JUMPING))
                        {
                            player->RemoveAura(SPELL_CURSE_OF_THE_CRANE);
                            targets.erase(itr);
                        }
                        break;
                }
            }
        }
        
    private:
        std::list<ObjectGuid> targets;
        uint8 pool;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_cursed_pool_controllerAI(creature);
    }
};

enum BalancePole
{
    EVENT_CAST_TRANSFORM                        = 1,
    NPC_TRAINING_BELL_BALANCE_POLE              = 55083,
    SPELL_TRAINING_BELL_EXCLUSION_AURA          = 133381,
    SPELL_TRAINING_BELL_FORCECAST_RIDE_VEHICLE  = 107050
};

class npc_balance_pole : public CreatureScript
{
public:
    npc_balance_pole() : CreatureScript("npc_balance_pole") { }

    struct npc_balance_poleAI : public ScriptedAI
    {
        npc_balance_poleAI(Creature* creature) : ScriptedAI(creature) { }

        void PassengerBoarded(Unit* passenger, int8 /*seat*/, bool apply) override
        {
            if (passenger->GetTypeId() == TYPEID_PLAYER)
            {
                if (!apply)
                {
                    _passenger = passenger;
                    events.ScheduleEvent(EVENT_CAST_TRANSFORM, 1000);
                }
                else
                {
                    if (me->GetEntry() == NPC_TRAINING_BELL_BALANCE_POLE)
                        me->CastSpell(passenger, SPELL_TRAINING_BELL_FORCECAST_RIDE_VEHICLE, true);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CAST_TRANSFORM:
                        if (!_passenger->HasAura(SPELL_RIDE_VEHICLE_POLE))
                        {
                            if (_passenger->HasAura(SPELL_TRAINING_BELL_EXCLUSION_AURA))
                                _passenger->RemoveAura(SPELL_TRAINING_BELL_EXCLUSION_AURA);

                            if (Creature* creature = _passenger->FindNearestCreature(NPC_CURSED_POOL_CONTROLLER, 80.0f, true))
                            {
                                _passenger->CastSpell(_passenger, SPELL_CURSE_OF_THE_FROG, true);
                                creature->AI()->SetDataWithTarget(DATA_FROG, _passenger->GetGUID());
                            }
                        }
                        break;
                }
            }
        }

    private:
        EventMap events;
        Unit* _passenger;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_balance_poleAI(creature);
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
    SPELL_JUMP_FRONT_RIGHT      = 117033,
    SPELL_JUMP_FRONT_LEFT       = 117034,
    SPELL_JUMP_BACK_RIGHT       = 117035,
    SPELL_JUMP_BACK_LEFT        = 117036,
    SPELL_SUMMON_WATER_SPOUT    = 116810,
    SPELL_WATER_SPOUT           = 117063
};

enum ShuJumpPositions
{
    JUMP_POSITION_1             = 0,
    JUMP_POSITION_2             = 1,
    JUMP_POSITION_3             = 2,
    JUMP_POSITION_4             = 3
};

enum ShuEvents
{
    EVENT_JUMP_SPELL            = 1,
    EVENT_SET_ORIENTATION       = 2,
    EVENT_SUMMON                = 3
};

enum ShuData
{
    DATA_JUMP_POSITION          = 1
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
    SPELL_AYSA_CONGRATS_TIMER       = 128589,
    SPELL_SUMMON_SPIRIT_OF_WATER    = 103538
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

class spell_monkey_wisdom_text : public SpellScriptLoader
{
public:
    spell_monkey_wisdom_text() : SpellScriptLoader("spell_monkey_wisdom_text") { }

    class spell_monkey_wisdom_text_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monkey_wisdom_text_SpellScript);

        enum
        {
            TEXT_MONKEY_WISDOM   = 54073,
            TEXT_MONKEY_WISDOM_2 = 54074,
            TEXT_MONKEY_WISDOM_3 = 54075,
            TEXT_MONKEY_WISDOM_4 = 54076,
            TEXT_MONKEY_WISDOM_5 = 54077,
            TEXT_MONKEY_WISDOM_6 = 54078,
            TEXT_MONKEY_WISDOM_7 = 54079,
            TEXT_MONKEY_WISDOM_8 = 54080
        };

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
    SPELL_OVERPACKED_FIREWORK       = 104855
};

enum ZhaorenMisc
{
    ZHAOREN_PATH                    = 4517910,
    NPC_JI_FIREPAW                  = 64505,
    NPC_AYSA_CLOUDSINGER            = 64506,
    NPC_DAFENG                      = 64532,
    DATA_1                          = 1,
    DATA_2                          = 2,
    DATA_3                          = 3,
    DATA_PHASE_OOC                  = 4,
    DATA_DEATH                      = 5
};

class npc_zhaoren : public CreatureScript
{
public:
    npc_zhaoren() : CreatureScript("npc_zhaoren") { }

    struct npc_zhaorenAI : public ScriptedAI
    {
        npc_zhaorenAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->setActive(true);
            Initialize();
        }

        Position const pos = { 723.163f, 4163.8f, 204.999f };

        void Initialize()
        {
            phase = 0;
            inCombat = false;
            lightningPhase = true;
            isInCenter = false;
            sweepScheduled = false;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->GetMotionMaster()->MovePath(ZHAOREN_PATH, true);
            events.ScheduleEvent(EVENT_LIGHTNING, 5000);
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_OVERPACKED_FIREWORK)
            {
                if (!inCombat)
                {
                    me->CombatStart(caster);
                    inCombat = true;
                }
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE && id == EVENT_MOVE_CENTER)
            {
                if (!isInCenter)
                {
                    events.ScheduleEvent(EVENT_STUN, 0);
                    isInCenter = true;
                }
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->CastSpell(me, SPELL_FORCECAST_SUMMON_SHANG, true);

            if (Creature* creature = me->FindNearestCreature(NPC_JI_FIREPAW, 100.0f, true))
                creature->AI()->SetData(DATA_DEATH, DATA_DEATH);
            if (Creature* creature = me->FindNearestCreature(NPC_AYSA_CLOUDSINGER, 100.0f, true))
                creature->AI()->SetData(DATA_DEATH, DATA_DEATH);
            if (Creature* creature = me->FindNearestCreature(NPC_DAFENG, 100.0f, true))
                creature->AI()->SetData(DATA_DEATH, DATA_DEATH);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (phase == 0 && HealthBelowPct(85))
            {
                phase++;
                if (Creature* creature = me->FindNearestCreature(NPC_AYSA_CLOUDSINGER, 100.0f, true))
                    creature->AI()->SetData(DATA_1, DATA_1);
            }

            if (phase == 1 && HealthBelowPct(75))
            {
                phase++;
                events.ScheduleEvent(EVENT_MOVE_CENTER, 0);
            }

            if (phase == 2 && HealthBelowPct(25))
            {
                phase++;
                events.ScheduleEvent(EVENT_MOVE_CENTER, 0);
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_LIGHTNING:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
                        {
                            if (phase < 3 && lightningPhase)
                            {
                                DoCast(target, SPELL_LIGHTNING_POOL);
                                events.ScheduleEvent(EVENT_LIGHTNING, 5000);
                            }
                            if (phase == 3 && lightningPhase)
                            {
                                DoCast(target, SPELL_LIGHTNING_POOL);
                                events.ScheduleEvent(EVENT_LIGHTNING, 3500);
                                if (!sweepScheduled)
                                {
                                    events.ScheduleEvent(EVENT_SWEEP, 15000);
                                    sweepScheduled = true;
                                }
                            }
                        }
                        break;
                    case EVENT_MOVE_CENTER:
                        lightningPhase = false;
                        me->GetMotionMaster()->MovePoint(EVENT_MOVE_CENTER, pos);
                        break;
                    case EVENT_STUN:
                        DoCast(SPELL_STUNNED_BY_FIREWORKS);
                        events.ScheduleEvent(EVENT_SWEEP, 12000);
                        if (Creature* creature = me->FindNearestCreature(NPC_AYSA_CLOUDSINGER, 100.0f, true))
                        {
                            if (phase == 2)
                                creature->AI()->SetData(DATA_2, DATA_2);
                            else if (phase == 3)
                                creature->AI()->SetData(DATA_3, DATA_3);
                        }
                        if (Creature* creature = me->FindNearestCreature(NPC_JI_FIREPAW, 100.0f, true))
                            creature->AI()->SetData(DATA_1, DATA_1);
                        break;
                    case EVENT_SWEEP:
                        DoCast(SPELL_SERPENT_SWEEP);
                        if (phase == 3)
                        {
                            sweepScheduled = false;
                            if (!lightningPhase)
                                events.ScheduleEvent(EVENT_LIGHTNING, 3500);
                            lightningPhase = true;
                        }
                        if (phase < 3)
                        {
                            if (Creature* creature = me->FindNearestCreature(NPC_AYSA_CLOUDSINGER, 100.0f, true))
                                creature->AI()->SetData(DATA_PHASE_OOC, DATA_PHASE_OOC);
                            if (Creature* creature = me->FindNearestCreature(NPC_JI_FIREPAW, 100.0f, true))
                                creature->AI()->SetData(DATA_PHASE_OOC, DATA_PHASE_OOC);
                            events.ScheduleEvent(EVENT_RESUME_WP, 5000);
                        }
                        break;
                    case EVENT_RESUME_WP:
                        lightningPhase = true;
                        me->GetMotionMaster()->MovePath(ZHAOREN_PATH, true);
                        isInCenter = false;
                        events.ScheduleEvent(EVENT_LIGHTNING, 5000);
                        break;
                }
            }
        }

    private:
        EventMap events;
        uint8 phase;
        bool inCombat;
        bool lightningPhase;
        bool isInCenter;
        bool sweepScheduled;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_zhaorenAI(creature);
    }
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
                if (Creature* creature = target->FindNearestCreature(55672, 70.0f, true))
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

enum ShenZinShuBunny
{
    SPELL_TRIGGER_WITH_ANIM_0   = 114898,
    SPELL_TRIGGER               = 106759,
    SPELL_TRIGGER_WITH_ANIM_1   = 118571,
    SPELL_TRIGGER_WITH_TURN     = 118572,
    TEXT_1                      = 55550,
    TEXT_2                      = 55568,
    TEXT_3                      = 55569,
    TEXT_4                      = 55570,
    TEXT_5                      = 55572,
    TEXT_6                      = 63407
};

class shen_zin_shu_bunny : public CreatureScript
{
public:
    shen_zin_shu_bunny() : CreatureScript("shen_zin_shu_bunny") { }

    struct shen_zin_shu_bunnyAI : public ScriptedAI
    {
        shen_zin_shu_bunnyAI(Creature* creature) : ScriptedAI(creature)
        {
            me->setActive(true);
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            switch (spell->Id)
            {
                case SPELL_TRIGGER_WITH_ANIM_0:
                    me->Talk(TEXT_1, CHAT_MSG_MONSTER_SAY, 300.0f, caster);
                    me->PlayDirectSound(27822);
                    break;
                case SPELL_TRIGGER:
                    me->Talk(TEXT_2, CHAT_MSG_MONSTER_SAY, 300.0f, caster);
                    me->PlayDirectSound(27823);
                    break;
                case SPELL_TRIGGER_WITH_ANIM_1:
                    if (hitCount == 0)
                    {
                        me->Talk(TEXT_3, CHAT_MSG_MONSTER_SAY, 300.0f, caster);
                        me->PlayDirectSound(27824);
                        hitCount++;
                    }
                    else if (hitCount == 1)
                    {
                        me->Talk(TEXT_4, CHAT_MSG_MONSTER_SAY, 300.0f, caster);
                        me->PlayDirectSound(27825);
                        hitCount++;
                    }
                    else if (hitCount == 2)
                    {
                        me->Talk(TEXT_6, CHAT_MSG_MONSTER_SAY, 300.0f, caster);
                        me->PlayDirectSound(27827);
                        hitCount = 0;
                    }
                    break;
                case SPELL_TRIGGER_WITH_TURN:
                    me->Talk(TEXT_5, CHAT_MSG_MONSTER_SAY, 300.0f, caster);
                    me->PlayDirectSound(27826);
                    break;
            }
        }

    private:
        uint8 hitCount;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new shen_zin_shu_bunnyAI(creature);
    }
};

void AddSC_the_wandering_isle()
{
    new spell_summon_troublemaker();
    new spell_meditation_timer_bar();
    new spell_cave_of_scrolls_comp_timer_aura();
    new spell_summon_living_air();
    new spell_fan_the_flames();
    new at_singing_pools_transform();
    new npc_cursed_pool_controller();
    new npc_balance_pole();
    new at_singing_pools_training_bell();
    new spell_rock_jump_a();
    new spell_jump_to_front_right();
    new spell_jump_to_front_left();
    new spell_jump_to_back_right();
    new spell_jump_to_back_left();
    new npc_shu_playing();
    new spell_summon_water_spout();
    new spell_water_spout_quest_credit();
    new spell_aysa_congrats_timer();
    new spell_aysa_congrats_trigger_aura();
    new at_temple_of_five_dawns_summon_zhaoren();
    new spell_monkey_wisdom_text();
    new npc_zhaoren();
    new spell_master_shang_final_escort_say();
    new shen_zin_shu_bunny();
}
