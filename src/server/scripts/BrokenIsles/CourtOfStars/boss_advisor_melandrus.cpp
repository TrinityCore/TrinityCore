/*
* Copyright (C) 2021 BfaCore Reforged
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
#include "SpellHistory.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "court_of_stars.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"

enum Spells
{
    SPELL_PIERCING_GALE = 209628,
    SPELL_PIERCING_GALE_BEHIND = 209630,
    SPELL_BLADE_SURGE = 209602,
    SPELL_BLADE_SURGE_DMG = 209667,
    SPELL_BLADE_SURGE_SUMMON = 209613,
    SPELL_SLICING_MAELSTROM = 209676,
    SPELL_SLICING_MAELSTROM_DMG = 209678,
    SPELL_SLICING_MAELSTROM_IMAGE_AURA = 209741,
    SPELL_SLICING_MAELSTROM_IMAGE_DMG = 209742,
    SPELL_ENVELOPING_WINDS = 224327,
    SPELL_ENVELOPING_WINDS_TARGETING = 224328,
    SPELL_ENVELOPING_WINDS_SUMMON = 224329,
    SPELL_ENVELOPING_WINDS_AREA = 224330,
    SPELL_ENVELOPING_WINDS_DMG = 224333,
    SPELL_GHOST_VISUAL = 188272,
};

enum Events
{
    EVENT_PIERCING_GALE = 1,
    EVENT_BLADE_SURGE = 2,
    EVENT_SLICING_MAELSTROM = 3,
    EVENT_ENVELOPING_WINDS = 4,
};

enum Adds
{
    NPC_IMAGE_OF_MELANDRUS = 105754,
    NPC_GALE_STALKER = 105765,
};

enum Actions
{
    ACTION_SLICING_MAELSTROM = 1,
    ACTION_PIERCING_GALE = 2,
    ACTION_INTRO = 3,
    ACTION_INTRO_ACHIEVEMENT = 4,
    ACTION_MELISSANDE_ANSWER = 5,
    ACTION_PLAYERS_DETECTED = 6,
};

enum Says
{
    SAY_INTRO = 0,
    SAY_PLAYERS_LOCATED = 1,
    SAY_INTRO_ACHIEVEMENT = 2,
    SAY_MELISSANDE_ACHIEVEMENT = 3,
    SAY_AGGRO = 4,
    SAY_SLICING = 5,
    SAY_BLADE_SURGE = 6,
    SAY_KILL = 7,
    SAY_WIPE = 8,
    SAY_DEATH = 9,
};

using SpellTargets = std::list<WorldObject*>;

struct PlayerFilter
{
    bool operator() (WorldObject*& target)
    {
        if (target && target->ToPlayer())
            return false;

        return true;
    }
};

void SummonGaleStalker(Creature* caster)
{
    if (!caster)
        return;

    Position pos = caster->GetPosition();
    pos.SetOrientation(pos.GetOrientation() + float(M_PI));

    Creature* stalker = caster->SummonCreature(NPC_GALE_STALKER, pos, TEMPSUMMON_TIMED_DESPAWN, 8 * IN_MILLISECONDS);

    if (!stalker)
        return;

    stalker->CastSpell(stalker, SPELL_PIERCING_GALE, false);
}

struct boss_advisor_melandrus : public BossAI
{
    boss_advisor_melandrus(Creature* creature) : BossAI(creature, DATA_MELANDRUS) { }

    void Reset()
    {
        _Reset();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
        case ACTION_INTRO:
            Talk(SAY_INTRO);
            break;

        case ACTION_INTRO_ACHIEVEMENT:
            Talk(SAY_INTRO_ACHIEVEMENT);
            break;

        case ACTION_MELISSANDE_ANSWER:
            Talk(SAY_MELISSANDE_ACHIEVEMENT);
            break;

        case ACTION_PLAYERS_DETECTED:
            Talk(SAY_PLAYERS_LOCATED);
            break;

        default: break;
        }
    }

    void EnterEvadeMode(EvadeReason reason) override
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLADE_SURGE_DMG);
        me->RemoveAllAreaTriggers();
        CreatureAI::EnterEvadeMode(reason);
    }

    void JustReachedHome() override
    {
        Talk(SAY_WIPE);
        _JustReachedHome();
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        Talk(SAY_DEATH);
       // instance->DoDelayedConversation(4000, 2405);
        instance->DoModifyPlayerCurrencies(1314, 1);
    }

    void EnterCombat(Unit*) override
    {
        Talk(SAY_AGGRO);
        _EnterCombat();
        events.ScheduleEvent(EVENT_SLICING_MAELSTROM, Seconds(11));
        events.ScheduleEvent(EVENT_PIERCING_GALE, Seconds(6));
        events.ScheduleEvent(EVENT_ENVELOPING_WINDS, Seconds(14));
    }

    void KilledUnit(Unit* target) override
    {
        if (!target)
            return;

        if (target->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_KILL);
    }

    void ActivateImages(uint32 action)
    {
        std::list<Creature*> images;
        me->GetCreatureListWithEntryInGrid(images, NPC_IMAGE_OF_MELANDRUS, 250.f);

        if (images.empty())
            return;

        for (auto& it : images)
        {
            if (it)
                it->AI()->DoAction(action);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {

        switch (eventId)
        {
        case EVENT_BLADE_SURGE:
        {
            me->GetSpellHistory()->ResetAllCooldowns();
            Talk(SAY_BLADE_SURGE);
            Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, NonTankTargetSelector(me, true));

            if (target)
                DoCast(target, SPELL_BLADE_SURGE);
            else
                DoCastVictim(SPELL_BLADE_SURGE);

            break;
        }
        case EVENT_PIERCING_GALE:
        {
            me->GetSpellHistory()->ResetAllCooldowns();

            DoCast(me, SPELL_PIERCING_GALE);
            SummonGaleStalker(me);

            ActivateImages(ACTION_PIERCING_GALE);

            events.ScheduleEvent(EVENT_PIERCING_GALE, Seconds(17));
            events.ScheduleEvent(EVENT_BLADE_SURGE, Seconds(10));
            break;
        }
        case EVENT_SLICING_MAELSTROM:
        {
            me->GetSpellHistory()->ResetAllCooldowns();
            Talk(SAY_SLICING);
            ActivateImages(ACTION_SLICING_MAELSTROM);
            DoCast(me, SPELL_SLICING_MAELSTROM);
            events.ScheduleEvent(EVENT_SLICING_MAELSTROM, Seconds(17));
            break;
        }
        case EVENT_ENVELOPING_WINDS:
        {
            DoCast(me, SPELL_ENVELOPING_WINDS, true);
            events.ScheduleEvent(EVENT_ENVELOPING_WINDS, Seconds(urand(15, 25)));
            break;
        }
        default:
            break;
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && me->IsWithinDist(who, 25.0f, false) && !IsLock)
        {
            IsLock = true;

            DoAction(ACTION_INTRO);
            me->GetScheduler().Schedule(Milliseconds(14000), [this](TaskContext context)
            {
                DoAction(SAY_INTRO_ACHIEVEMENT);
            }).Schedule(Milliseconds(10000), [this](TaskContext context)
            {
                DoAction(SAY_PLAYERS_LOCATED);
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            });
            if (Creature* target = me->FindNearestCreature(110443, 20.0f, true))
            {
                target->GetScheduler().Schedule(Milliseconds(5000), [who](TaskContext context)
                {
                    GetContextCreature()->AI()->Talk(0);
                }).Schedule(Milliseconds(20000), [who](TaskContext context)
                {
                    GetContextCreature()->AI()->Talk(1);
                    GetContextCreature()->DespawnOrUnsummon(2000);
                });
            }
            //me->GetMotionMaster()->MovePoint(1, Position(882.0399f, 3106.67f, 54.92872f, 2.745999f), true);
        }
    }
};
//105754
class npc_cots_image_of_melandrus : public CreatureScript
{
public:
    npc_cots_image_of_melandrus() : CreatureScript("npc_cots_image_of_melandrus")
    {}

    struct npc_cots_image_of_melandrus_AI : public ScriptedAI
    {
        npc_cots_image_of_melandrus_AI(Creature* creature) : ScriptedAI(creature)
        {}

        void Reset() override
        {
            me->CastSpell(me, SPELL_GHOST_VISUAL, true);
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetReactState(REACT_PASSIVE);
        }

        void DoAction(int32 action) override
        {
            me->GetSpellHistory()->ResetAllCooldowns();

            if (action == ACTION_PIERCING_GALE)
            {
                DoCast(me, SPELL_PIERCING_GALE);
                SummonGaleStalker(me);
            }
            else if (action == ACTION_SLICING_MAELSTROM)
                DoCast(me, SPELL_SLICING_MAELSTROM_IMAGE_AURA);
        }

        void EnterEvadeMode(EvadeReason reason) override
        {

        }

        void UpdateAI(uint32 diff) override
        {

        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_cots_image_of_melandrus_AI(creature);
    }
};
//112687
class npc_cots_enveloping_wind : public CreatureScript
{
public:
    npc_cots_enveloping_wind() : CreatureScript("npc_cots_enveloping_wind")
    {}

    struct npc_cots_enveloping_wind_AI : public ScriptedAI
    {
        npc_cots_enveloping_wind_AI(Creature* creature) : ScriptedAI(creature)
        {}

        void Reset() override
        {
            me->SetSpeed(MOVE_RUN, 0.4f);
            me->SetSpeed(MOVE_WALK, 0.4f);
            DoCast(me, SPELL_ENVELOPING_WINDS_AREA, true);
            _timerMoved = _timerDmg = 0;
            _moved = false;
        }

        void CheckPlayersNear()
        {
            Map::PlayerList const& players = me->GetMap()->GetPlayers();

            if (!players.isEmpty())
            {
                for (auto& it : players)
                {
                    if (Player* player = it.GetSource())
                    {
                        if (me->GetDistance2d(player) <= 1.4f && !player->HasAura(SPELL_ENVELOPING_WINDS_DMG))
                            me->CastSpell(player, SPELL_ENVELOPING_WINDS_DMG, true);
                    }
                }
            }
        }

        void UpdateAI(uint32 diff)
        {
            _timerMoved += diff;
            _timerDmg += diff;

            if (_timerMoved >= 5 * IN_MILLISECONDS && !_moved)
            {
                me->GetMotionMaster()->MoveRandom(5.0f);
                _moved = true;
            }

            if (_timerDmg >= 500 && _moved)
            {
                _timerDmg = 0;
                CheckPlayersNear();
            }
        }

    private:
        uint32 _timerMoved, _timerDmg;
        bool _moved;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_cots_enveloping_wind_AI(creature);
    }
};
//209628, 209630
class spell_melandrus_piercing_gale : public SpellScriptLoader
{
public:
    spell_melandrus_piercing_gale() : SpellScriptLoader("spell_melandrus_piercing_gale")
    {}

    class spell_melandrus_piercing_gale_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_melandrus_piercing_gale_SpellScript);

        void FilterTargets(SpellTargets& targets)
        {
            if (targets.empty())
                return;

            targets.remove_if([&](WorldObject* target)
            {

                float dx = GetCaster()->GetPositionX() - target->GetPositionX();
                float dy = GetCaster()->GetPositionY() - target->GetPositionY();

                dy = std::fabs(dy);
                dx = std::fabs(dx);

                if (std::fabs(dx - dy) > 2.5f)
                    return true;

                return false;
            });

        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_melandrus_piercing_gale_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_melandrus_piercing_gale_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_CONE_ENEMY_104);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_melandrus_piercing_gale_SpellScript();
    }
};
//209667
class spell_melandrus_blade_surge : public SpellScriptLoader
{
public:
    spell_melandrus_blade_surge() : SpellScriptLoader("spell_melandrus_blade_surge")
    {}

    class spell_melandrus_blade_surge_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_melandrus_blade_surge_SpellScript);

        void HandleTrigger(SpellEffIndex /**/)
        {
            if (!GetCaster())
                return;

            GetCaster()->CastSpell(GetCaster(), SPELL_BLADE_SURGE_SUMMON, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_melandrus_blade_surge_SpellScript::HandleTrigger, EFFECT_2, SPELL_EFFECT_TRIGGER_SPELL);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_melandrus_blade_surge_SpellScript();
    }
};
//224327
class spell_melandrus_enveloping_winds : public SpellScriptLoader
{
public:
    spell_melandrus_enveloping_winds() : SpellScriptLoader("spell_melandrus_enveloping_winds")
    {}

    class spell_melandrus_enveloping_winds_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_melandrus_enveloping_winds_SpellScript);

        void HandleDummy(SpellEffIndex)
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            GetCaster()->CastSpell(GetHitUnit(), SPELL_ENVELOPING_WINDS_TARGETING, true);
        }

        void FilterTargets(SpellTargets& targets)
        {
            if (targets.empty())
                return;

            targets.remove_if(PlayerFilter());
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_melandrus_enveloping_winds_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_melandrus_enveloping_winds_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_melandrus_enveloping_winds_SpellScript();
    }
};
void AddSC_boss_advisor_melandrus()
{
    RegisterCreatureAI(boss_advisor_melandrus);
    new npc_cots_image_of_melandrus();
    new npc_cots_enveloping_wind();
    new spell_melandrus_piercing_gale();
    new spell_melandrus_blade_surge();
    new spell_melandrus_enveloping_winds();
}
