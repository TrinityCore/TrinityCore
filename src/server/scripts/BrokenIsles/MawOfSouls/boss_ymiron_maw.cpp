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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "GameObject.h"
#include "AreaTrigger.h"
#include "G3D/Vector2.h"
#include "G3D/Vector3.h"
#include <iostream>
#include "maw_of_souls.h"

enum Spells
{
    SPELL_DARK_SLASH = 193211,
    SPELL_SCREAMS_OF_DEAD = 193364,
    SPELL_BANE = 193460,
    SPELL_BANE_TRIGGER = 193463,
    SPELL_BANE_AREATRIGGER = 193465,
    SPELL_WINDS_OF_NORTHREND = 193977,
    SPELL_ARISE_FALLEN = 193566,
    SPELL_ARISE_FALLEN_SUMMON = 193594,
    SPELL_KNEELING = 197227,

    SPELL_BANE_DMG_AREATRIGGER = 193513,
    SPELL_BANE_DMG_TARGET = 200194,

    SPELL_VIGOR = 203816,

    // Horn of Dammed
    SPELL_HELHEIM_TELEPORT = 191558,
    SPELL_HELHEIM_SCENE = 191559,
};

enum Events
{
    EVENT_DARK_SLASH = 1,
    EVENT_SCREAMS_OF_DEAD = 2,
    EVENT_BANE = 3,
    EVENT_WIND_OF_NORTHREND = 4,
    EVENT_ARISE_FALLEN = 5,

    // Risen Fallen
    EVENT_VIGOR = 6,
};

enum Adds
{
    NPC_RISEN_WARRIOR = 98246,
};

enum Says
{
    SAY_AGGRO = 0,
    SAY_SCREAM = 1,
    SAY_WINDS = 2,
    SAY_BANE = 3,
    SAY_ARISE = 4,
    SAY_KILL = 5,
    SAY_WIPE = 6,
    SAY_DEATH = 7,
};

class boss_ymiron_fallen : public CreatureScript
{
public:
    boss_ymiron_fallen() : CreatureScript("boss_ymiron_fallen")
    {}

    struct boss_ymiron_fallen_AI : public BossAI
    {
        boss_ymiron_fallen_AI(Creature* creature) : BossAI(creature, DATA_YMIRON)
        {}

        void Reset() override
        {
            _Reset();
            HandleHorn(false);
        }

        void HandleHorn(bool activated)
        {
            if (GameObject* horn = me->FindNearestGameObject(GO_HORN_OF_DAMMED, 150.0f))
            {
                if (activated)
                    horn->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                else
                    horn->SetFlags(GO_FLAG_NOT_SELECTABLE);
            }
        }

        void EnterCombat(Unit* /**/) override
        {
            Talk(SAY_AGGRO);
            me->RemoveAurasDueToSpell(SPELL_KNEELING);
            _EnterCombat();
            events.ScheduleEvent(EVENT_BANE, Seconds(23));
            events.ScheduleEvent(EVENT_DARK_SLASH, 3500);
            events.ScheduleEvent(EVENT_SCREAMS_OF_DEAD, Seconds(6));
            events.ScheduleEvent(EVENT_WIND_OF_NORTHREND, Seconds(15));
        }

        void JustReachedHome() override
        {
            Talk(SAY_WIPE);
            me->CastSpell(me, SPELL_KNEELING, true);
            _JustReachedHome();
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_KILL);
        }

        void JustDied(Unit* /**/) override
        {
            Talk(SAY_DEATH);
            HandleHorn(true);
            _JustDied();
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
            case EVENT_BANE:
            {
                Talk(SAY_BANE);
                DoCast(me, SPELL_BANE);
                events.ScheduleEvent(EVENT_BANE, Minutes(1));

                if (IsHeroic())
                    events.ScheduleEvent(EVENT_ARISE_FALLEN, Seconds(19));
                break;
            }

            case EVENT_DARK_SLASH:
            {
                DoCastVictim(SPELL_DARK_SLASH);
                events.ScheduleEvent(EVENT_DARK_SLASH, Seconds(17));
                break;
            }

            case EVENT_SCREAMS_OF_DEAD:
            {
                Talk(SAY_SCREAM);
                DoCast(me, SPELL_SCREAMS_OF_DEAD);
                events.ScheduleEvent(EVENT_SCREAMS_OF_DEAD, Seconds(30));
                break;
            }

            case EVENT_WIND_OF_NORTHREND:
            {
                Talk(SAY_WINDS);
                DoCast(me, SPELL_WINDS_OF_NORTHREND);
                events.ScheduleEvent(EVENT_WIND_OF_NORTHREND, Seconds(30));
                break;
            }

            case EVENT_ARISE_FALLEN:
            {
                Talk(SAY_ARISE);
                me->CastSpell(me, SPELL_ARISE_FALLEN, false);
                break;
            }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_ymiron_fallen_AI(creature);
    }
};

class npc_mos_risen_warrior : public CreatureScript
{
public:
    npc_mos_risen_warrior() : CreatureScript("npc_mos_risen_warrior")
    {}

    struct npc_mos_risen_warrior_AI : public ScriptedAI
    {
        npc_mos_risen_warrior_AI(Creature* creature) : ScriptedAI(creature)
        {}

        void EnterCombat(Unit* /**/) override
        {
            DoCast(me, SPELL_VIGOR, true);
            _events.ScheduleEvent(EVENT_VIGOR, Seconds(6));
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                if (eventId == EVENT_VIGOR)
                {
                    DoCast(me, SPELL_VIGOR, true);
                    _events.ScheduleEvent(EVENT_VIGOR, Seconds(6));
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mos_risen_warrior_AI(creature);
    }
};

class at_bane_essence : public AreaTriggerEntityScript
{
public:
    at_bane_essence() : AreaTriggerEntityScript("at_bane_essence")
    {}

    struct at_bane_essence_AI : public AreaTriggerAI
    {
        at_bane_essence_AI(AreaTrigger* at) : AreaTriggerAI(at)
        {}

        void OnInitialize()
        {
            if (!at->GetCaster())
                return;

            Unit* caster = at->GetCaster();

            G3D::Vector2 dist = { at->GetPositionX() - caster->GetPositionX(), at->GetPositionY() - caster->GetPositionY() };
            G3D::Vector2 center = { caster->GetPositionX(), caster->GetPositionY() };

            float radius = dist.length();
            float step = 2 * float(M_PI) / 23.f;
            float angle = 5.0f + at->GetOrientation();

            for (uint8 i = 0; i < 23; i++, angle += step)
            {
                G3D::Vector3 point;

                point.x = center.x + radius * cosf(angle);
                point.y = center.y + radius * sinf(angle);
                point.z = at->GetPositionZ();

                _points.push_back(point);
            }

            at->InitSplines(_points, at->GetDuration() * 0.85);

        }

        void OnUnitEnter(Unit* target) override
        {
            if (!target)
                return;

            if (target->GetTypeId() == TYPEID_PLAYER)
            {
                at->GetCaster()->CastSpell(target, SPELL_BANE_DMG_AREATRIGGER, true);
                at->GetCaster()->CastSpell(target, SPELL_BANE_DMG_TARGET, true);
                at->Remove();
            }
        }

    private:
        std::vector<G3D::Vector3> _points;
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new at_bane_essence_AI(at);
    }
};

class spell_ymiron_fallen_bane : public SpellScriptLoader
{
public:
    spell_ymiron_fallen_bane() : SpellScriptLoader("spell_ymiron_fallen_bane")
    {}

    class spell_ymiron_fallen_bane_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_ymiron_fallen_bane_SpellScript);

        void HandleCast()
        {
            if (!GetCaster())
                return;

            Unit* caster = GetCaster();
            float radius = 20.f;
            float angle = float(M_PI) / 6;

            for (uint8 i = 0; i < 5; ++i)
            {
                Position pos = caster->GetNearPosition(radius, angle);
                caster->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_BANE_TRIGGER, true);
            }
        }

        void Register()
        {
            OnCast += SpellCastFn(spell_ymiron_fallen_bane_SpellScript::HandleCast);
        }
    };

    class spell_ymiron_fallen_bane_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_ymiron_fallen_bane_AuraScript);

        bool Load() override
        {
            _reverse = false;
            _restantAreas = 10;
            _radius = 30.0f;
            _angle = float(M_PI) / 6.0f;
            return true;
        }

        void HandlePeriodic(AuraEffect const* /**/)
        {
            if (!GetCaster())
                return;

            Unit* caster = GetCaster();
            Difficulty diff = GetCaster()->GetMap()->GetDifficultyID();

            if (_restantAreas <= 0)
                return;

            if (diff == DIFFICULTY_HEROIC)
            {
                for (uint8 i = 0; i < 2; ++i && _restantAreas > 0, _restantAreas--)
                {

                    Position pos = caster->GetNearPosition(_radius, _angle);

                    _angle += _angle;

                    if (_radius <= 10.0f)
                        _reverse = true;
                    else if (_radius >= 30.0f)
                        _reverse = false;

                    if (_reverse)
                        _radius += 5.0f;
                    else
                        _radius -= 5.0f;

                    caster->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_BANE_TRIGGER, true);
                }
            }
            else if (diff == DIFFICULTY_MYTHIC)
            {
                Position pos = caster->GetNearPosition(_radius, _angle);

                _angle += _angle;

                if (_radius <= 10.0f)
                    _reverse = true;
                else if (_radius >= 30.0f)
                    _reverse = false;

                if (_reverse)
                    _radius += 5.0f;
                else
                    _radius -= 5.0f;

                caster->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_BANE_TRIGGER, true);
                _restantAreas--;
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_ymiron_fallen_bane_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }

    private:
        uint8 _restantAreas;
        bool _reverse;
        float _radius;
        float _angle;
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_ymiron_fallen_bane_SpellScript();
    }

    AuraScript* GetAuraScript() const override
    {
        return new spell_ymiron_fallen_bane_AuraScript();
    }
};

class spell_ymiron_arise_fallen : public SpellScriptLoader
{
public:
    spell_ymiron_arise_fallen() : SpellScriptLoader("spell_ymiron_arise_fallen")
    {}

    class spell_ymiron_arise_fallen_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_ymiron_arise_fallen_SpellScript);

        void FilterTargets(SpellTargets & targets)
        {
            if (targets.empty())
                return;

            std::vector<AreaTrigger*> banes_essences(GetCaster()->GetAreaTriggers(SPELL_BANE_AREATRIGGER));

            if (banes_essences.empty())
            {
                targets.clear();
                return;
            }

            targets.remove_if(PlayerFilter());

            for (auto & it : banes_essences)
            {
                it->Remove();
                WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
                GetCaster()->CastSpell(target->ToUnit(), SPELL_ARISE_FALLEN_SUMMON, true);
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ymiron_arise_fallen_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_ymiron_arise_fallen_SpellScript();
    }
};

class go_echoing_horn_of_dammed : public GameObjectScript
{
public:
    go_echoing_horn_of_dammed() : GameObjectScript("go_echoing_horn_of_dammed")
    {}

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (!player)
            return false;

        Map::PlayerList const & players = go->GetMap()->GetPlayers();

        if (!players.isEmpty())
        {
            for (auto & it : players)
            {
                if (Player* player_ptr = it.GetSource())
                {
                    player_ptr->CastSpell(player_ptr, SPELL_HELHEIM_SCENE, true);
                    player_ptr->CastSpell(player_ptr, SPELL_HELHEIM_TELEPORT, true);
                }
            }
        }

        return true;
    }
};

void AddSC_boss_ymiron_maw()
{
    new boss_ymiron_fallen();
    new npc_mos_risen_warrior();
    new spell_ymiron_fallen_bane();
    new spell_ymiron_arise_fallen();
    new at_bane_essence();
    new go_echoing_horn_of_dammed();
}
