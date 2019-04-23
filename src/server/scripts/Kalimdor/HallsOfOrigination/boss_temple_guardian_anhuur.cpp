/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GridNotifiers.h"
#include "Player.h"
#include "halls_of_origination.h"

enum Texts
{
    SAY_AGGRO = 0,
    SAY_SHIELD = 1,
    EMOTE_SHIELD = 2,
    EMOTE_UNSHIELD = 3,
    SAY_KILL = 4,
    SAY_DEATH = 5
};

enum Events
{
    EVENT_DIVINE_RECKONING = 1,
    EVENT_BURNING_LIGHT,
    EVENT_SEAR,
    EVENT_ACHIEVEMENT_FAIL,
};

enum Entities
{
    NPC_ANHUUR                  = 39425,
    NPC_CAVE_IN_STALKER         = 40183,
    GO_LEVER_1                  = 207218,
    GO_LEVER_2                  = 207219,
};

enum Spells
{
    SPELL_DIVINE_RECKONING = 75592,
    SPELL_BURNING_LIGHT = 75115,
    SPELL_REVERBERATING_HYMN = 75322,
    SPELL_SHIELD_OF_LIGHT = 74938,

    SPELL_ACTIVATE_BEACONS = 76599,
    SPELL_TELEPORT = 74969,

    SPELL_SHIELD_VISUAL_RIGHT = 83698,
    SPELL_BEAM_OF_LIGHT_RIGHT = 76573,

    SPELL_SHIELD_VISUAL_LEFT = 83697,
    SPELL_BEAM_OF_LIGHT_LEFT = 74930,

    SPELL_SEARING_LIGHT = 75194,
};

enum Actions
{
    ACTION_DISABLE_BEACON = 1,
};

enum MiscData
{
    DATA_SHIELD                 = 1,
};

enum Phases
{
    PHASE_NORMAL                = 1,
    PHASE_SHIELDED              = 2,
};

enum AnhuurAchievementData
{
    DATA_I_HATE_THAT_SONG = 1,
};

GameObject* door;

class boss_anhuur : public CreatureScript
{

    struct boss_anhuurAI : public BossAI
    {
        boss_anhuurAI(Creature * creature) : BossAI(creature, DATA_TEMPLE_GUARDIAN_ANHUUR_EVENT)
        {
            _shieldCount = 0;
            _beacons = 0;
            _achievement = true;
            door = me->FindNearestGameObject(GO_ANHUURS_DOOR, 100.0);
        }

        //std::list<uint64> SummonList;

        uint8 _shieldCount;
        uint8 _beacons;
        bool _achievement;

        void Reset() override
        {
            /*
            RemoveSummons();
            shielded = false;
            stage = 0;
            targetGUID = ObjectGuid::Empty;
            SetLevers(false);
            memset(&beacons, false, sizeof(beacons));
            */
            _Reset();
        }

        void SetLevers(bool active)
        {
            if(GameObject * lever1 = me->FindNearestGameObject(GO_LEVER_1, 50.0f))
            {
                if(active)
                    lever1->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                else
                    lever1->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            }

            if(GameObject * lever2 = me->FindNearestGameObject(GO_LEVER_2, 50.0f))
            {
                if(active)
                    lever2->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                else
                    lever2->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_DIVINE_RECKONING, urand(10000, 12000));
            events.ScheduleEvent(EVENT_BURNING_LIGHT, 12000);
            _EnterCombat();
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            Talk(SAY_DEATH);
            _JustDied();
            //RemoveSummons();
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_KILL);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            _EnterEvadeMode();
            CleanStalkers();
            RespawnPit();
            _shieldCount = 0;
            _beacons = 0;
            _achievement = true;
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->GetMotionMaster()->MoveTargetedHome();
            events.Reset();
            _DespawnAtEvade();
        }

        void RespawnPit()
        {
            std::list<Creature*> snakes;
            GetCreatureListWithEntryInGrid(snakes, me, NPC_PIT_SNAKE, 500.0f);
            for (std::list<Creature*>::iterator itr = snakes.begin(); itr != snakes.end(); ++itr)
            {
                Position const pos = (*itr)->GetHomePosition();
                (*itr)->Respawn();
                (*itr)->NearTeleportTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation());
            }
        }

        void CleanStalkers()
        {
            std::list<Creature*> stalkers;
            GetCreatureListWithEntryInGrid(stalkers, me, NPC_CAVE_IN_STALKER, 100.0f);
            for (std::list<Creature*>::iterator itr = stalkers.begin(); itr != stalkers.end(); ++itr)
            {
                (*itr)->RemoveAurasDueToSpell(SPELL_BEAM_OF_LIGHT_RIGHT);
                (*itr)->RemoveAurasDueToSpell(SPELL_BEAM_OF_LIGHT_LEFT);
            }
        }

        void DamageTaken(Unit* /*done_by*/, uint32&/*damage*/) override
        {
            if ((me->HealthBelowPct(66) && _shieldCount == 0) ||
                (me->HealthBelowPct(33) && _shieldCount == 1))
            {
                _shieldCount++;
                _beacons = 2;

                RespawnPit();

                std::list<Creature*> stalkers;
                if (!door)
                    door = me->FindNearestGameObject(GO_ANHUURS_DOOR, 100.0);
                GetCreatureListWithEntryInGrid(stalkers, me, NPC_CAVE_IN_STALKER, 100.0f);

                stalkers.remove_if(Trinity::HeightDifferenceCheck(door, 0.0f, false)); // Target only the bottom ones
                for (std::list<Creature*>::iterator itr = stalkers.begin(); itr != stalkers.end(); ++itr)
                {
                    if ((*itr)->GetPositionX() > door->GetPositionX())
                    {
                        (*itr)->CastSpell((*itr), SPELL_SHIELD_VISUAL_LEFT, true);
                        (*itr)->CastSpell((*itr), SPELL_BEAM_OF_LIGHT_LEFT, true);
                    }
                    else
                    {
                        (*itr)->CastSpell((*itr), SPELL_SHIELD_VISUAL_RIGHT, true);
                        (*itr)->CastSpell((*itr), SPELL_BEAM_OF_LIGHT_RIGHT, true);
                    }
                }

                Talk(EMOTE_SHIELD);
                Talk(SAY_SHIELD);

                me->InterruptNonMeleeSpells(true);
                me->AttackStop();
                DoCast(me, SPELL_TELEPORT);

                DoCastAOE(SPELL_ACTIVATE_BEACONS);
                DoCast(me, SPELL_REVERBERATING_HYMN);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_31);
                //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);

                events.CancelEvent(EVENT_DIVINE_RECKONING);
                events.CancelEvent(EVENT_BURNING_LIGHT);
                events.ScheduleEvent(EVENT_ACHIEVEMENT_FAIL, 15000);
            }
            else if (me->HasAura(SPELL_REVERBERATING_HYMN) && !me->HasAura(SPELL_SHIELD_OF_LIGHT))
            {
                me->RemoveAurasDueToSpell(SPELL_REVERBERATING_HYMN);
                events.CancelEvent(EVENT_ACHIEVEMENT_FAIL);
                events.ScheduleEvent(EVENT_DIVINE_RECKONING, urand(10000, 12000));
                events.ScheduleEvent(EVENT_BURNING_LIGHT, 12000);
            }
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_DISABLE_BEACON)
            {
                --_beacons;
                if (!_beacons)
                {
                    me->RemoveAura(SPELL_SHIELD_OF_LIGHT);
                    Talk(EMOTE_UNSHIELD);
                }
            }
        }

        uint32 GetData(uint32 type) const override
        {
            return type == DATA_I_HATE_THAT_SONG ? _achievement : 0;
        }

        /*
        void SetData(uint32 type, uint32 data) override
        {
            if(!shielded || type != DATA_SHIELD)
                return;

            if(data == 76608)
                beacons[1] = true;
            else if (data == 76606)
                beacons[0] = true;

            if(beacons[0] && beacons[1])
            {
                me->RemoveAurasDueToSpell(SPELL_SHIELD_OF_LIGHT);
                Talk(EMOTE_SHIELD_REMOVED);
                RemoveSummons();
                memset(&beacons, false, sizeof(beacons));
            }
        }

        void RemoveSummons()
        {
            if (SummonList.empty())
                return;

            for (std::list<uint64>::const_iterator itr = SummonList.begin(); itr != SummonList.end(); ++itr)
            {
                if (Creature* pTemp = ObjectAccessor::GetCreature(*me, *itr))
                    if (pTemp)
                        pTemp->DisappearAndDie();
            }
            SummonList.clear();
        }

        void JustSummoned(Creature* summon) override
        {
            SummonList.push_back(summon->GetGUID());
            if(Player * player = ObjectAccessor::GetPlayer(*me, targetGUID))
            {
                if(Creature * stalker = player->FindNearestCreature(NPC_CAVE_IN_STALKER, 100.0f))
                    stalker->CastSpell(stalker, SPELL_BURNING_LIGHT_2, true, NULL, NULL, me->GetGUID());
                summon->setFaction(14);
                targetGUID = ObjectGuid::Empty;
            }
        }
        */

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_DIVINE_RECKONING:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true, 0))
                        DoCast(target, SPELL_DIVINE_RECKONING);
                    events.ScheduleEvent(EVENT_DIVINE_RECKONING, urand(10000, 12000));
                    break;
                case EVENT_BURNING_LIGHT:
                {
                    Unit* unit = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me));
                    if (!unit)
                        unit = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);
                    DoCast(unit, SPELL_BURNING_LIGHT);
                    events.ScheduleEvent(EVENT_SEAR, 2000);
                    events.ScheduleEvent(EVENT_BURNING_LIGHT, 12000);
                    break;
                }
                case EVENT_SEAR:
                {
                    Unit* target = me->FindNearestCreature(NPC_SEARING_LIGHT, 100.0f);
                    if (!target)
                        break;

                    std::list<Creature*> stalkers;
                    GetCreatureListWithEntryInGrid(stalkers, me, NPC_CAVE_IN_STALKER, 100.0f);
                    if (!door)
                        door = me->FindNearestGameObject(GO_ANHUURS_DOOR, 100.0);
                    if (door)
                        stalkers.remove_if(Trinity::HeightDifferenceCheck(door, 5.0f, true));

                    if (stalkers.empty())
                        break;

                    stalkers.sort(Trinity::ObjectDistanceOrderPred(target));

                    // Get the closest statue face (any of its eyes)
                    Creature* eye1 = stalkers.front();
                    stalkers.remove(eye1); // Remove the eye.
                    stalkers.sort(Trinity::ObjectDistanceOrderPred(eye1)); // Find the second eye.
                    Creature* eye2 = stalkers.front();

                    eye1->CastSpell(eye1, SPELL_SEARING_LIGHT, true);
                    eye2->CastSpell(eye2, SPELL_SEARING_LIGHT, true);
                    break;
                }
                case EVENT_ACHIEVEMENT_FAIL:
                    _achievement = false;
                    break;
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private:
        ObjectGuid targetGUID;
    };

public:
    boss_anhuur() : CreatureScript("boss_temple_guardian_anhuur") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_anhuurAI(creature);
    }
};

class spell_anhuur_shield_of_light : public SpellScriptLoader
{
public:
    spell_anhuur_shield_of_light() : SpellScriptLoader("spell_anhuur_shield_of_light") { }

    class spell_anhuur_shield_of_light_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_anhuur_shield_of_light_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (InstanceMap* instance = GetCaster()->GetMap()->ToInstanceMap())
            {
                if (instance->GetInstanceScript())
                {
                    if (door)
                    {
                        targets.remove_if(Trinity::HeightDifferenceCheck(door, 5.0f, false));
                        targets.remove(GetCaster());
                        targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster()));
                        targets.resize(2);
                    }
                }
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anhuur_shield_of_light_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_anhuur_shield_of_light_SpellScript();
    }
};

class spell_anhuur_disable_beacon_beams : public SpellScriptLoader
{
public:
    spell_anhuur_disable_beacon_beams() : SpellScriptLoader("spell_anhuur_disable_beacon_beams") { }

    class spell_anhuur_disable_beacon_beams_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_anhuur_disable_beacon_beams_SpellScript);

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            GetHitUnit()->RemoveAurasDueToSpell(GetEffectValue());
        }

        void Notify(SpellEffIndex /*index*/)
        {
            if (InstanceMap* instance = GetCaster()->GetMap()->ToInstanceMap())
                if (instance->GetInstanceScript())
                    if (door)
                        if (Creature* anhuur = door->ToCreature())
                            anhuur->AI()->DoAction(ACTION_DISABLE_BEACON);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_anhuur_disable_beacon_beams_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            OnEffectHit += SpellEffectFn(spell_anhuur_disable_beacon_beams_SpellScript::Notify, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_anhuur_disable_beacon_beams_SpellScript();
    }
};

class spell_anhuur_activate_beacons : public SpellScriptLoader
{
public:
    spell_anhuur_activate_beacons() : SpellScriptLoader("spell_anhuur_activate_beacons") { }

    class spell_anhuur_activate_beacons_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_anhuur_activate_beacons_SpellScript);

        void Activate(SpellEffIndex index)
        {
            PreventHitDefaultEffect(index);
            GetHitGObj()->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_anhuur_activate_beacons_SpellScript::Activate, EFFECT_0, SPELL_EFFECT_ACTIVATE_OBJECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_anhuur_activate_beacons_SpellScript();
    }
};

class spell_anhuur_divine_reckoning : public SpellScriptLoader
{
public:
    spell_anhuur_divine_reckoning() : SpellScriptLoader("spell_anhuur_divine_reckoning") { }

    class spell_anhuur_divine_reckoning_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_anhuur_divine_reckoning_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            if (Unit* caster = GetCaster())
            {
                CustomSpellValues values;
                values.AddSpellMod(SPELLVALUE_BASE_POINT0, aurEff->GetAmount());
                caster->CastCustomSpell(GetSpellInfo()->GetEffect(EFFECT_0)->TriggerSpell, values, GetTarget());
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_anhuur_divine_reckoning_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_anhuur_divine_reckoning_AuraScript();
    }
};

class achievement_hate_that_song : public AchievementCriteriaScript
{
public:
    achievement_hate_that_song() : AchievementCriteriaScript("achievement_hate_that_song") { }

    bool OnCheck(Player* /*source*/, Unit* target) override
    {
        if (!target)
            return false;

        if (target->GetMap()->IsHeroic())
            if (target->ToCreature())
                return target->ToCreature()->AI()->GetData(DATA_I_HATE_THAT_SONG);

        return false;
    }
};


void AddSC_boss_temple_guardian_anhuur()
{
    new boss_anhuur();
    new spell_anhuur_shield_of_light();
    new spell_anhuur_disable_beacon_beams();
    new spell_anhuur_activate_beacons();
    new spell_anhuur_divine_reckoning();
    new achievement_hate_that_song();
}
