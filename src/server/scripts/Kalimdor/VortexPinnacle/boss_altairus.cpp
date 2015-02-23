/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "vortex_pinnacle.h"

enum Spells
{
    SPELL_CALL_THE_WIND = 88276, // targets 47305 in hook
    SPELL_CHILLING_BREATH = 88322,

    // Invisible Stalker
    SPELL_CALL_THE_WIND_CHANNEL = 88772, // visual channeling targeting Air Current  

    // Air Current
    SPELL_CALL_THE_WIND_AURA = 88244, // periodically triggers upwind
    SPELL_UPWIND_OF_ALTAIRUS = 88282,
    SPELL_DOWNWIND_OF_ALTAIRUS = 88286,

    // Twister
    SPELL_TWISTER_AURA = 88313,
};

enum NPCs
{
    NPC_INVISIBLE_STALKER = 42844,
    NPC_AIR_CURRENT = 47305,
    NPC_TWISTER = 47342,
};

enum Texts
{
    SAY_CALL_THE_WIND = 0,
};

enum Events
{
    EVENT_NONE,
    EVENT_CALL_THE_WIND,
    EVENT_CHILLING_BREATH,

    // Air Current
    EVENT_SET_FACING,
    EVENT_CAST_VISUAL,

    // Twister
    EVENT_MOVE_RANDOM,
};

enum Actions
{
    ACTION_CALL_THE_WIND,
};

enum Points
{
    POINT_RANDOM,
    POINT_TWISTER_MAX = 24,
};

const Position InvisibleStalkerPos = { -1216.12f, 64.026f, 734.2573f };

const Position TwisterSpawnPoints[POINT_TWISTER_MAX] = {
    { -1226.936f, 58.03993f, 734.2574f },
    { -1250.604f, 78.47916f, 729.8842f },
    { -1255.609f, 63.03125f, 729.05f   },
    { -1235.368f, 85.2691f,  732.747f  },
    { -1245.059f, 61.33333f, 732.6014f },
    { -1237.84f,  72.69965f, 734.2705f },
    { -1190.684f, 69.16666f, 734.2564f },
    { -1194.172f, 54.2066f,  734.2574f },
    { -1215.405f, 65.88541f, 734.2574f },
    { -1236.722f, 48.6632f,  734.2571f },
    { -1193.104f, 82.77431f, 737.7465f },
    { -1210.278f, 80.68056f, 734.2574f },
    { -1202.799f, 68.46702f, 734.2574f },
    { -1224.179f, 76.04688f, 734.2574f },
    { -1244.069f, 92.11979f, 729.0458f },
    { -1211.163f, 53.77778f, 734.2574f },
    { -1198.332f, 106.1181f, 740.7894f },
    { -1203.602f, 93.05209f, 738.5089f },
    { -1242.745f, 37.7257f,  734.257f  },
    { -1219.642f, 93.82291f, 737.8855f },
    { -1223.229f, 40.89063f, 734.2574f },
    { -1211.016f, 105.4375f, 740.8424f },
    { -1189.568f, 95.77604f, 740.8668f },
    { -1204.863f, 40.49826f, 734.2564f },
};

// TO-DO:
// - Fix hovering with disabled gravity. Altairus falls down every time position is updated.
// - Add argument to MoveRandom() to manually set i_nextMoveTime in "RandomMovementGenerator.h". This npc needs i_nextMoveTime = 1000.

class boss_altairus : public CreatureScript
{
    public:
        boss_altairus() : CreatureScript("boss_altairus") { }

        struct boss_altairusAI : public BossAI
        {
            boss_altairusAI(Creature* creature) : BossAI(creature, DATA_ALTAIRUS)
            {
                //me->SetHover(true);
                //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            }

            void Reset() override
            {
                _Reset();

                events.ScheduleEvent(EVENT_CALL_THE_WIND, 6000);
                events.ScheduleEvent(EVENT_CHILLING_BREATH, 15000);
            }

            void EnterCombat(Unit* /*target*/) override
            {
                _EnterCombat();

                me->SummonCreature(NPC_INVISIBLE_STALKER, InvisibleStalkerPos);

                if (IsHeroic())
                    for (int8 i = 0; i < POINT_TWISTER_MAX; i++)
                        if (Creature* twister = me->SummonCreature(NPC_TWISTER, TwisterSpawnPoints[i]))
                            twister->GetMotionMaster()->MoveRandom(10.0f);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CALL_THE_WIND:
                            DoCast(me, SPELL_CALL_THE_WIND);
                            Talk(SAY_CALL_THE_WIND);
                            events.ScheduleEvent(EVENT_CALL_THE_WIND, 20500);
                            break;
                        case EVENT_CHILLING_BREATH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_CHILLING_BREATH);
                            events.ScheduleEvent(EVENT_CHILLING_BREATH, 13000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_altairusAI>(creature);
        }
};

// 47305 - Air Current
class npc_air_current : public CreatureScript
{
public:
    npc_air_current() : CreatureScript("npc_air_current") { }

    struct npc_air_currentAI : public ScriptedAI
    {
        npc_air_currentAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetDisableGravity(true);
        }

        void SpellHit(Unit* /*unit*/, const SpellInfo* spellInfo) override
        {
            if (spellInfo->Id != SPELL_CALL_THE_WIND)
                return;

            DoCast(me, SPELL_CALL_THE_WIND_AURA);

            events.ScheduleEvent(EVENT_SET_FACING, 400);
            events.ScheduleEvent(EVENT_CAST_VISUAL, 1600);
        }

        void UpdateAI(uint32 diff) override
        {
            if (events.Empty())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SET_FACING:
                        if (Creature* invisibleStalker = me->FindNearestCreature(NPC_INVISIBLE_STALKER, 100.0f))
                        {
                            invisibleStalker->CastStop();
                            invisibleStalker->SetFacingToObject(me);
                        }
                        break;
                    case EVENT_CAST_VISUAL:
                        if (Creature* invisibleStalker = me->FindNearestCreature(NPC_INVISIBLE_STALKER, 100.0f))
                            invisibleStalker->CastSpell(me, SPELL_CALL_THE_WIND_CHANNEL);
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_air_currentAI>(creature);
    }
};

// 88276 - Call The Wind
class spell_call_the_wind : public SpellScriptLoader
{
public:
    spell_call_the_wind() : SpellScriptLoader("spell_call_the_wind") { }

    class spell_call_the_wind_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_call_the_wind_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_CALL_THE_WIND_AURA))
                return false;
            return true;
        }

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (targets.empty())
                return;

            targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_CALL_THE_WIND_AURA));
            Trinity::Containers::RandomResizeList(targets, 1);
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            GetHitUnit()->CastSpell(GetHitUnit(), SPELL_CALL_THE_WIND_AURA);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_call_the_wind_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnEffectHitTarget += SpellEffectFn(spell_call_the_wind_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_call_the_wind_SpellScript();
    }
};

// 88282 - Upwind of Altairus
class spell_upwind_of_altairus : public SpellScriptLoader
{
public:
    spell_upwind_of_altairus() : SpellScriptLoader("spell_upwind_of_altairus") { }

    class spell_upwind_of_altairus_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_upwind_of_altairus_SpellScript);

        void GetDistance()
        {
            Unit* caster = GetCaster();
            if (InstanceScript* instance = caster->GetInstanceScript())
                if (Creature* altairus = instance->GetCreature(DATA_ALTAIRUS))
                    upwindDistance = caster->GetExactDist(altairus);
        }

        void CheckDistance(SpellEffIndex /*effIndex*/)
        {
            Unit* target = GetHitUnit();
            if (GetCaster()->GetExactDist(target) < upwindDistance) 
            {
                // Upwind of Altairus (applied by default effects)
                if (target->HasAura(SPELL_DOWNWIND_OF_ALTAIRUS))
                    target->RemoveAurasDueToSpell(SPELL_DOWNWIND_OF_ALTAIRUS);
            }
            else
            {
                // Downwind of Altairus
                PreventHitDefaultEffect(EFFECT_0);
                PreventHitDefaultEffect(EFFECT_1);
                if (target->HasAura(SPELL_UPWIND_OF_ALTAIRUS))
                    target->RemoveAurasDueToSpell(SPELL_UPWIND_OF_ALTAIRUS);
                target->CastSpell(target, SPELL_DOWNWIND_OF_ALTAIRUS, true);
            }
        }

        void Register() override
        {
            BeforeCast += SpellCastFn(spell_upwind_of_altairus_SpellScript::GetDistance);
            OnEffectHitTarget += SpellEffectFn(spell_upwind_of_altairus_SpellScript::CheckDistance, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        }

    private:
        float upwindDistance;
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_upwind_of_altairus_SpellScript();
    }
};

// 88772 - Call the Wind (visual, channeling on Air Current with Call The Wind aura)
class spell_call_the_wind_channel : public SpellScriptLoader
{
public:
    spell_call_the_wind_channel() : SpellScriptLoader("spell_call_the_wind_channel") { }

    class spell_call_the_wind_channel_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_call_the_wind_channel_AuraScript);

        void RemoveCallTheWindAura(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Creature* creature = GetOwner()->ToCreature())
                creature->RemoveAurasDueToSpell(SPELL_CALL_THE_WIND_AURA);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_call_the_wind_channel_AuraScript::RemoveCallTheWindAura, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_call_the_wind_channel_AuraScript();
    }
};

// 88322 - Chilling Breath
class spell_chilling_breath : public SpellScriptLoader
{
public:
    spell_chilling_breath() : SpellScriptLoader("spell_chilling_breath") { }

    class spell_chilling_breath_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_chilling_breath_SpellScript);

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectValue()));
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_chilling_breath_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_chilling_breath_SpellScript();
    }
};

void AddSC_boss_altairus()
{
    new boss_altairus();
    new npc_air_current();
    new spell_call_the_wind();
    new spell_upwind_of_altairus();
    new spell_call_the_wind_channel();
    new spell_chilling_breath();
}
