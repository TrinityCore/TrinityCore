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

#include "Player.h"
#include "PassiveAI.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

enum HallowsEndSpells
{
    SPELL_HORSEMAN_MOUNT = 48025,
    SPELL_FIRE_AURA_BASE = 42074,
    SPELL_START_FIRE     = 42132,
    SPELL_SPREAD_FIRE    = 42079,
    SPELL_CREATE_BUCKET  = 42349,
    SPELL_WATER_SPLASH   = 42348,
    SPELL_SUMMON_LANTERN = 44255,
    SPELL_SMALL_FIRE     = 42091,
    SPELL_BIG_FIRE       = 43148,
    SPELL_CLEAVE         = 15496
};

enum HallowEndEvents
{
    EVENT_BEGIN = 1,
    EVENT_TALK_INTRO,
    EVENT_APPLY_FIRE,
    EVENT_STOP_APPLYING_FIRE,
    EVENT_FINISH,
    EVENT_CLEAVE
};

enum HallowEndSays
{
    SAY_START_INTRO = 0,
    SAY_1           = 1, // unused
    SAY_2           = 2, // unused
    SAY_FAIL        = 3,
    SAY_FLAMES_DOWN = 4,
    SAY_DEFEATED    = 5
};

enum HallowEndMisc
{
    QUEST_LET_THE_FIRES_COME_A = 12135,
    QUEST_LET_THE_FIRES_COME_H = 12139,
    QUEST_STOP_THE_FIRES_A     = 11131,
    QUEST_STOP_THE_FIRES_H     = 11219,
    NPC_SHADE_OF_HORSEMAN      = 23543,
    NPC_FIRE_TRIGGER           = 23537,
    POINT_HORSEMAN_ATTACK       = 1
};


class npc_costumed_orphan_matron : public CreatureScript
{
public:
    npc_costumed_orphan_matron() : CreatureScript("npc_costumed_orphan_matron") { }

    struct npc_costumed_orphan_matronAI : public ScriptedAI
    {
        npc_costumed_orphan_matronAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            _events.Reset();
            _events.ScheduleEvent(EVENT_BEGIN, Seconds(5));
        }

        void GetInitXYZ(float &x, float &y, float &z, float &o, uint32 &path)
        {
            switch (me->GetAreaId())
            {
                case 87: // Goldshire
                    x = -9494.4f;
                    y = 48.53f;
                    z = 70.5f;
                    o = 0.5f;
                    path = 235431;
                    break;
                case 131: // Kharanos
                    x = -5558.34f;
                    y = -499.46f;
                    z = 414.12f;
                    o = 2.08f;
                    path = 235432;
                    break;
                case 3576: // Azure Watch
                    x = -4163.58f;
                    y = -12460.30f;
                    z = 63.02f;
                    o = 4.31f;
                    path = 235433;
                    break;
                case 362: // Razor Hill
                    x = 373.2f;
                    y = -4723.4f;
                    z = 31.2f;
                    o = 3.2f;
                    path = 235434;
                    break;
                case 159: // Brill
                    x = 2195.2f;
                    y = 264.0f;
                    z = 55.62f;
                    o = 0.15f;
                    path = 235435;
                    break;
                case 3665: // Falconwing Square
                    x = 9547.91f;
                    y = -6809.9f;
                    z = 27.96f;
                    o = 3.4f;
                    path = 235436;
                    break;
                default:
                    x = 0.0f;
                    y = 0.0f;
                    z = 0.0f;
                    path = 0;
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_BEGIN:
                    {
                        float x, y, z, o;
                        uint32 path;
                        GetInitXYZ(x, y, z, o, path);
                        if (Creature* shadeOfHorseman = me->SummonCreature(NPC_SHADE_OF_HORSEMAN, x, y, z, o, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000))
                        {
                            shadeOfHorseman->GetMotionMaster()->MovePath(path, true);
                            shadeOfHorseman->AI()->DoAction(path);
                        }
                        _events.Repeat(Minutes(40));
                        break;
                    }
                }
            }
        }

    private:
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_costumed_orphan_matronAI(creature);
    }
};

class npc_soh_fire_trigger : public CreatureScript
{
public:
    npc_soh_fire_trigger() : CreatureScript("npc_soh_fire_trigger") { }

    struct npc_soh_fire_triggerAI : public NullCreatureAI
    {
        npc_soh_fire_triggerAI(Creature* creature) : NullCreatureAI(creature) { }

        void Reset() override
        {
            me->SetDisableGravity(true);
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spellInfo) override
        {
            if (spellInfo->Id == SPELL_START_FIRE || spellInfo->Id == SPELL_SPREAD_FIRE)
            {
                DoCastSelf(SPELL_FIRE_AURA_BASE, true);
                DoCastSelf(SPELL_SPREAD_FIRE, true);
            }
            else if (spellInfo->Id == SPELL_WATER_SPLASH)
            {
                if (Aura* aura = me->GetAura(SPELL_SMALL_FIRE))
                {
                    int32 stackAmount = aura->GetStackAmount();
                    if (stackAmount > 10)
                        aura->SetStackAmount(stackAmount-10);
                    else
                        me->RemoveAura(aura);
                }

                if (Aura* aura = me->GetAura(SPELL_BIG_FIRE))
                {
                    int32 stackAmount = aura->GetStackAmount();
                    if (aura->GetStackAmount() > 10)
                        aura->SetStackAmount(stackAmount-10);
                    else
                        me->RemoveAura(aura);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_soh_fire_triggerAI(creature);
    }
};

class npc_hallows_end_soh : public CreatureScript
{
public:
    npc_hallows_end_soh() : CreatureScript("npc_hallows_end_soh") { }

    struct npc_hallows_end_sohAI : public ScriptedAI
    {
        npc_hallows_end_sohAI(Creature* creature) : ScriptedAI(creature), _pos(0), _canShootFire(true)
        {
            DoCastSelf(SPELL_HORSEMAN_MOUNT);
            me->SetSpeed(MOVE_WALK, 5.0f);
        }

        void DoAction(int32 param) override
        {
            _pos = param;
        }

        void GetPosToLand(float &x, float &y, float &z)
        {
            switch (_pos)
            {
                case 235431:
                    x = -9445.1f;
                    y = 63.27f;
                    z = 58.16f;
                    break;
                case 235432:
                    x = -5616.30f;
                    y = -481.89f;
                    z = 398.99f;
                    break;
                case 235433:
                    x = -4198.1f;
                    y = -12509.13f;
                    z = 46.6f;
                    break;
                case 235434:
                    x = 360.9f;
                    y = -4735.5f;
                    z = 11.773f;
                    break;
                case 235435:
                    x = 2229.4f;
                    y = 263.1f;
                    z = 36.13f;
                    break;
                case 235436:
                    x = 9532.9f;
                    y = -6833.8f;
                    z = 18.5f;
                    break;
                default:
                    x = 0.0f;
                    y = 0.0f;
                    z = 0.0f;
                    break;
            }
        }

        void Reset() override
        {
            _events.ScheduleEvent(EVENT_TALK_INTRO, Seconds(3));
            _events.ScheduleEvent(EVENT_APPLY_FIRE, Seconds(5));
            _events.ScheduleEvent(EVENT_STOP_APPLYING_FIRE, Minutes(2));
            _events.ScheduleEvent(EVENT_FINISH, Minutes(5));

            FinishEvent(false);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_TALK_INTRO:
                        Talk(SAY_START_INTRO);
                        break;
                    case EVENT_APPLY_FIRE:
                    {
                        if (_canShootFire)
                        {
                            if (Creature* trigger = me->FindNearestCreature(NPC_FIRE_TRIGGER, 50.0f))
                                if (!trigger->GetAura(SPELL_START_FIRE) && !trigger->GetAura(SPELL_SPREAD_FIRE))
                                    DoCast(trigger, SPELL_START_FIRE);
                            _events.Repeat(Seconds(5));
                        }
                        break;
                    }
                    case EVENT_STOP_APPLYING_FIRE:
                        _canShootFire = false;
                        break;
                    case EVENT_FINISH:
                    {
                        bool failed = false;
                        std::list<Creature*> triggerList;
                        me->GetCreatureListWithEntryInGrid(triggerList, NPC_FIRE_TRIGGER);
                        for (Creature* trigger : triggerList)
                        {
                            if (trigger->HasAura(SPELL_FIRE_AURA_BASE))
                                failed = true;

                            trigger->AI()->EnterEvadeMode();
                        }
                        FinishEvent(failed);
                        break;
                    }
                    case EVENT_CLEAVE:
                        DoCastVictim(SPELL_CLEAVE);
                        _events.Repeat(Seconds(20));
                        break;
                }

            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void FinishEvent(bool failed)
        {
            _events.Reset();
            if (failed)
            {
                Talk(SAY_FAIL);
                me->DespawnOrUnsummon();
            }
            else
            {
                Talk(SAY_FLAMES_DOWN);
                float x, y, z;
                GetPosToLand(x, y, z);
                me->GetMotionMaster()->MovePoint(POINT_HORSEMAN_ATTACK, x, y, z);
            }
        }

        void MovementInform(uint32 type, uint32 point) override
        {
            if (type == POINT_MOTION_TYPE && point == POINT_HORSEMAN_ATTACK)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, 0);
                me->SetDisableGravity(false);
                me->RemoveAurasDueToSpell(SPELL_HORSEMAN_MOUNT);
                if (Unit* target = me->SelectNearestPlayer(30.0f))
                    AttackStart(target);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEFEATED);
            float x, y, z;
            GetPosToLand(x, y, z);
            me->CastSpell(x, y, z, SPELL_SUMMON_LANTERN, true);
            CompleteQuest();
        }

        void CompleteQuest()
        {
            float radius = 100.0f;
            std::list<Player*> players;
            Trinity::AnyPlayerInObjectRangeCheck checker(me, radius);
            Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, players, checker);
            Cell::VisitWorldObjects(me, searcher, radius);

            for (Player* player : players)
            {
                player->AreaExploredOrEventHappens(QUEST_STOP_THE_FIRES_H);
                player->AreaExploredOrEventHappens(QUEST_STOP_THE_FIRES_A);
                player->AreaExploredOrEventHappens(QUEST_LET_THE_FIRES_COME_H);
                player->AreaExploredOrEventHappens(QUEST_LET_THE_FIRES_COME_A);
            }
        }

    private:
        EventMap _events;
        int32 _pos;
        bool _canShootFire;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_hallows_end_sohAI(creature);
    }
};

// 42339 - Bucket Lands
class spell_hallows_end_bucket_lands : public SpellScriptLoader
{
public:
    spell_hallows_end_bucket_lands() : SpellScriptLoader("spell_hallows_end_bucket_lands") { }

    class spell_hallows_end_bucket_lands_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_hallows_end_bucket_lands_SpellScript);

        bool handled;

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_CREATE_BUCKET,
                SPELL_WATER_SPLASH
            });
        }

        bool Load() override
        {
            handled = false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (handled)
                return;

            handled = true;
            Unit* caster = GetCaster();

            if (Player* targetPlayer = GetHitPlayer())
                caster->CastSpell(targetPlayer, SPELL_CREATE_BUCKET, true);
            else if (Unit* target = GetHitUnit())
                caster->CastSpell(target, SPELL_WATER_SPLASH, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_hallows_end_bucket_lands_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_hallows_end_bucket_lands_SpellScript();
    }
};

 // 42074 - Headless Horseman - Fire
class spell_hallows_end_base_fire : public SpellScriptLoader
{
public:
    spell_hallows_end_base_fire() : SpellScriptLoader("spell_hallows_end_base_fire") { }

    class spell_hallows_end_base_fire_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_hallows_end_base_fire_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_SMALL_FIRE,
                SPELL_BIG_FIRE
            });
        }

        void HandleEffectPeriodicUpdate(AuraEffect* /*aurEff*/)
        {
            Unit* owner = GetUnitOwner();

            if (Aura* aura = owner->GetAura(SPELL_SMALL_FIRE))
                if (aura->GetStackAmount() < 20)
                    owner->CastSpell(owner, SPELL_SMALL_FIRE, true);

            if (Aura* aura = owner->GetAura(SPELL_BIG_FIRE))
                if (aura->GetStackAmount() < 20)
                    owner->CastSpell(owner, SPELL_BIG_FIRE, true);
        }

        void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* owner = GetUnitOwner();

            if (roll_chance_i(50))
                owner->SetAuraStack(SPELL_BIG_FIRE, owner, 20);
            else
                owner->SetAuraStack(SPELL_SMALL_FIRE, owner, 20);
        }

        void Register() override
        {
            OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_hallows_end_base_fire_AuraScript::HandleEffectPeriodicUpdate, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            OnEffectApply += AuraEffectApplyFn(spell_hallows_end_base_fire_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_hallows_end_base_fire_AuraScript();
    }
};

void AddSC_event_hallows_end()
{
    new npc_costumed_orphan_matron();
    new npc_soh_fire_trigger();
    new npc_hallows_end_soh();
    new spell_hallows_end_bucket_lands();
    new spell_hallows_end_base_fire();
}
