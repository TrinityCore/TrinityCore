/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "PlayerAI.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "shrine_of_the_storm.h"

enum Stormsong
{
    SPELL_VOID_BOLT = 268347,
    SPELL_MIND_REND = 268896,

    SPELL_WAKEN_THE_VOID = 269097,
    SPELL_WAKEN_THE_VOID_MISSILE = 269021,
    SPELL_WAKEN_THE_VOID_AURA = 269094,
    SPELL_FIXATE = 269103,
    SPELL_EXPLOSIVE_VOID = 269104,

    //mind control stuff
    SPELL_ANCIENT_MINDBENDER = 269131,
    SPELL_SURRENDER_TO_THE_VOID = 269242,
    SPELL_DISCIPLE_OF_THE_VOLZITH = 269289, // visual id

    SPELL_VOID_BOLT_VOLLEY = 269282,
};

enum Creatures
{
    BOSS_LORD_STORMSONG = 134060,
};

enum Events
{
    EVENT_VOID_BOLT = 1,
    EVENT_WAKEN_THE_VOID,
    EVENT_FIXATE,
    EVENT_ANCIENT_MINDBENDER,
    EVENT_MIND_REND,
};

enum Timers
{
    TIMER_FIXATE_PLAYER = 1500,
    TIMER_VOID_BOLT = 5 * IN_MILLISECONDS,
    TIMER_WAKEN_THE_VOID = 30 * IN_MILLISECONDS,
    TIMER_MIND_REND = 22 * IN_MILLISECONDS,
    TIMER_ANCIENT_MINDBENDER = 40 * IN_MILLISECONDS,
};

const Position cheatersCheck = { 3560.75f, -1484.49f, 153.31f };

#define AGGRO_TEXT "Intruders?! I shall cast your bodies to the blackened depths, to be crushed for eternity!"

class bfa_boss_lord_stormsong : public CreatureScript
{
public:
    bfa_boss_lord_stormsong() : CreatureScript("bfa_boss_lord_stormsong")
    {}

    struct bfa_boss_lord_stormsong_AI : public BossAI
    {
        bfa_boss_lord_stormsong_AI(Creature* creature) : BossAI(creature, DATA_LORD_STORMSONG), summons(me)
        {
            instance = me->GetInstanceScript();
        }

        EventMap events;
        InstanceScript* instance;
        SummonList summons;

        bool CheckCheaters()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        if (me->GetDistance(cheatersCheck.GetPositionX(), cheatersCheck.GetPositionY(), cheatersCheck.GetPositionZ()) >= 35.0f)
                        {
                            me->Kill(player, false);
                            std::ostringstream str;
                            str << "CHEATERS!";
                            me->TextEmote(str.str().c_str(), 0, true);
                            return false;
                        }
                    }

                }

            return true;
        }

        void SelectSoundAndText(Creature* me, uint32  selectedTextSound = 0)
        {
            if (!me)
                return;

            if (me)
            {
                switch (selectedTextSound)
                {
                case 1:
                    me->Yell(AGGRO_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                }
            }
        }

        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);

            switch (summon->GetEntry())
            {
            case NPC_AWOKEN_VOID:
                summon->SetInCombatWithZone();
                break;
            }
        }

        void EnterEvadeMode(EvadeReason why)
        {
            summons.DespawnAll();
            _DespawnAtEvade(15);
        }
        void Reset()
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            events.Reset();
            summons.DespawnAll();
        }

        void JustDied(Unit*)
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            summons.DespawnAll();
            RemoveAdditionalAura(SPELL_DISCIPLE_OF_THE_VOLZITH);
            RemoveAdditionalAura(SPELL_ANCIENT_MINDBENDER);
        }

        void EnterCombat(Unit*)
        {
            SelectSoundAndText(me, 1);

            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

            if (me->GetMap()->IsHeroic() || me->GetMap()->IsHeroic())
                events.ScheduleEvent(EVENT_MIND_REND, TIMER_MIND_REND);

            events.ScheduleEvent(EVENT_WAKEN_THE_VOID, TIMER_WAKEN_THE_VOID);
            events.ScheduleEvent(EVENT_ANCIENT_MINDBENDER, TIMER_ANCIENT_MINDBENDER);
            events.ScheduleEvent(EVENT_VOID_BOLT, TIMER_VOID_BOLT);
        }

        void RemoveAdditionalAura(uint32 spellId)
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    player->RemoveAura(spellId);
                }
        }

        void HandleBender()
        {
            std::list<Unit*> targets;
            SelectTargetList(targets, 1, SELECT_TARGET_RANDOM, 500.0f, true);

            if (!targets.empty())
                if (targets.size() >= 1)
                    targets.resize(1);

            for (auto target : targets)
            {
                std::ostringstream str;
                str << "An |cFFF00000|h[Ancient Mindbender]|h|r attaches to " << target->GetName();
                me->TextEmote(str.str().c_str(), 0, true);
                me->CastSpell(target, SPELL_ANCIENT_MINDBENDER, true);
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;
            
            if (me->IsInCombat())
                CheckCheaters();

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_VOID_BOLT:
                    me->CastSpell(me->GetVictim(), SPELL_VOID_BOLT);
                    events.ScheduleEvent(EVENT_VOID_BOLT, TIMER_VOID_BOLT);
                    break;
                case EVENT_WAKEN_THE_VOID:
                    me->CastSpell(me, SPELL_WAKEN_THE_VOID);
                    events.ScheduleEvent(EVENT_WAKEN_THE_VOID, TIMER_WAKEN_THE_VOID);
                    break;
                case EVENT_ANCIENT_MINDBENDER:
                    HandleBender();
                    events.ScheduleEvent(EVENT_ANCIENT_MINDBENDER, TIMER_ANCIENT_MINDBENDER);
                    break;
                case EVENT_MIND_REND:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f))
                        me->CastSpell(target, SPELL_MIND_REND);
                    events.ScheduleEvent(EVENT_MIND_REND, TIMER_MIND_REND);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_boss_lord_stormsong_AI(creature);
    }
};

class bfa_spell_ancient_mindbender : public SpellScriptLoader
{
public:
    bfa_spell_ancient_mindbender() : SpellScriptLoader("bfa_spell_ancient_mindbender") { }

    class bfa_spell_ancient_mindbender_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_ancient_mindbender_AuraScript);

        void CalculateAmount(AuraEffect const* auraEffect, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = -1;
        }

        void OnAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            absorbAmount = 0;
        }

        void HandleOnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Player* plr = GetTarget()->ToPlayer())
            {
                plr->AddAura(SPELL_DISCIPLE_OF_THE_VOLZITH, plr);
                plr->CastSpell(plr, SPELL_SURRENDER_TO_THE_VOID);
            }
        }

        void HandleOnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (!GetTarget())
                return;
            GetTarget()->ToPlayer()->RemoveAura(SPELL_DISCIPLE_OF_THE_VOLZITH);
        }

        void Register()
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(bfa_spell_ancient_mindbender_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(bfa_spell_ancient_mindbender_AuraScript::OnAbsorb, EFFECT_0);
            OnEffectApply += AuraEffectApplyFn(bfa_spell_ancient_mindbender_AuraScript::HandleOnApply, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_ancient_mindbender_AuraScript::HandleOnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_ancient_mindbender_AuraScript();
    }
};

class bfa_spell_disciple_of_the_volzith : public SpellScriptLoader
{
public:
    bfa_spell_disciple_of_the_volzith() : SpellScriptLoader("bfa_spell_disciple_of_the_volzith") { }

    class bfa_spell_disciple_of_the_volzith_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_disciple_of_the_volzith_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_VOID_BOLT_VOLLEY);
            if (caster->GetHealthPct() <= 50)
            {
                caster->RemoveAura(SPELL_ANCIENT_MINDBENDER);
                caster->CastStop();
            }

        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_disciple_of_the_volzith_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_disciple_of_the_volzith_AuraScript();
    }
};

class bfa_spell_surrender_to_the_void : public SpellScriptLoader
{
public:
    bfa_spell_surrender_to_the_void() : SpellScriptLoader("bfa_spell_surrender_to_the_void") { }

    class bfa_spell_surrender_to_the_void_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_surrender_to_the_void_SpellScript);

        void HandleAfterCast()
        {
            if (Unit* caster = GetCaster())
            {
                caster->Kill(caster);
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(bfa_spell_surrender_to_the_void_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_surrender_to_the_void_SpellScript();
    }
};


enum VoidEvents
{
    EVENT_CHECK_DIST_PLAYER = 1,
    EVENT_FIXATE_FOLLOW,
};

class bfa_npc_awoken_void : public CreatureScript
{
public:
    bfa_npc_awoken_void() : CreatureScript("bfa_npc_awoken_void")
    {}

    struct bfa_npc_awoken_void_AI : public ScriptedAI
    {
        bfa_npc_awoken_void_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetSpeed(MOVE_WALK, 0.8f);
            me->SetSpeed(MOVE_FLIGHT, 0.8f);
            me->SetSpeed(MOVE_RUN, 0.8f);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
            me->SetWalk(true);
        }

        EventMap events;

        void Reset()
        {
            me->GetScheduler().Schedule(500ms, [this](TaskContext context)
                {
                    me->CastSpell(me, SPELL_WAKEN_THE_VOID_MISSILE, true);
                });

            events.Reset();
        }

        void EnterCombat(Unit*)
        {
            me->CastSpell(me, SPELL_WAKEN_THE_VOID_AURA, true);
            me->SetReactState(REACT_AGGRESSIVE);

            events.ScheduleEvent(EVENT_FIXATE, TIMER_FIXATE_PLAYER);
            events.ScheduleEvent(EVENT_CHECK_DIST_PLAYER, 3000);
        }

        void CheckNearbyPlayers()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        if (me->GetDistance(player) <= 3.0f)
                        {
                            me->CastSpell(player, SPELL_EXPLOSIVE_VOID, true);
                            me->DespawnOrUnsummon();
                        }
                    }
                }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_FIXATE:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 1, SELECT_TARGET_RANDOM, 500.0f, true);

                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (auto target : targets)
                    {
                        me->AddThreat(target, 9999999999.9f);
                        me->CastSpell(target, SPELL_FIXATE, true);
                        me->AI()->AttackStart(target);
                    }
                    events.ScheduleEvent(EVENT_FIXATE_FOLLOW, 2000);
                    break;
                }
                case EVENT_FIXATE_FOLLOW:
                    if (Unit* victim = me->GetVictim())
                    {
                        me->GetMotionMaster()->MoveFollow(victim, 0.0f, 0.0f);

                    }
                    events.ScheduleEvent(EVENT_FIXATE_FOLLOW, 1000);
                    break;
                case EVENT_CHECK_DIST_PLAYER:
                {
                    CheckNearbyPlayers();
                    events.ScheduleEvent(EVENT_CHECK_DIST_PLAYER, 2000);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_awoken_void_AI(creature);
    }
};

void AddSC_boss_lord_stormsong()
{
    new bfa_boss_lord_stormsong();
    new bfa_npc_awoken_void();

    new bfa_spell_ancient_mindbender();
    new bfa_spell_surrender_to_the_void();
    new bfa_spell_disciple_of_the_volzith();
}
