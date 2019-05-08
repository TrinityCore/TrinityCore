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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "blackwing_descent.h"

enum Spells
{
    // Omnotron
    SPELL_CONTROLLER_RECHARGE                   = 78696,
    SPELL_RECHARGING_ELECTRON                   = 78697,
    SPELL_RECHARGING_MAGMATRON                  = 78698,
    SPELL_RECHARGING_ARCANOTRON                 = 78699,
    SPELL_RECHARGING_TOXITRON                   = 78700,

    // Omnotron Defense System
    SPELL_INACTIVE                              = 78726,
    SPELL_POWERED_DOWN                          = 82265,
    SPELL_SHARED_HEALTH                         = 79920,
    SPELL_ACTIVATED                             = 78740,
    SPELL_SHUTTING_DOWN                         = 78746,
};

enum Texts
{
    // Omnotron
    SAY_ACTIVATE_ELECTRON   = 0,
    SAY_ACTIVATE_TOXITRON   = 1,
    SAY_ACTIVATE_MAGMATRON  = 2,
    SAY_ACTIVATE_ARCANOTRON = 3,

    SAY_SHIELD_ELECTRON     = 4,
    SAY_SHIELD_TOXITRON     = 5,
    SAY_SHIELD_MAGMATRON    = 6,
    SAY_SHIELD_ARCANOTRON   = 7,
};

enum Events
{
    // Omnotron
    EVENT_LINK_GOLEM_HEALTH = 1,
    EVENT_POWER_UP_FIRST_GOLEM,

    // Omnotron Defense System
};

enum Actions
{
    // Omnotron
    ACTION_GOLEM_ACTIVATED      = 0,
    ACTION_START_ENCOUNTER      = 1,
    ACTION_STOP_ENCOUNTER       = 2,

    // Omnotron Defense System
    ACTION_ACTIVATE_GOLEM       = 0,
    ACTION_DEACTIVATE_GOLEM     = 1
};

enum Data
{
    DATA_NEXT_GOLEM_IN_QUEUE = 0
};

Position const FirstGolemPatrolStartPoint = { -324.665f, -398.085f, 213.8214f };

enum MovePoints
{
    POINT_START_WAYPOINTS = 1
};

enum SummonGroups
{
    SUMMON_GROUP_GOLEMS = 0
};

struct GolemInfo
{
    uint8 ActivateTextId;
    uint8 ShieldTextId;
};

std::unordered_map<uint32, GolemInfo> _golemInfoMap =
{
    { NPC_ELECTRON,     { SAY_ACTIVATE_ELECTRON,    SAY_SHIELD_ELECTRON     } },
    { NPC_MAGMATRON,    { SAY_ACTIVATE_MAGMATRON,   SAY_SHIELD_MAGMATRON    } },
    { NPC_ARCANOTRON,   { SAY_ACTIVATE_ARCANOTRON,  SAY_SHIELD_ARCANOTRON   } },
    { NPC_TOXITRON,     { SAY_ACTIVATE_TOXITRON,    SAY_SHIELD_TOXITRON     } }
};

struct boss_omnotron_defense_system : public BossAI
{
    boss_omnotron_defense_system(Creature* creature) : BossAI(creature, DATA_OMNOTRON_DEFENSE_SYSTEM)
    {
        Initialize();
    }

    void Initialize()
    {
    }

    void Reset() override
    {
        _Reset();
        Initialize();
        me->SummonCreatureGroup(SUMMON_GROUP_GOLEMS);
        events.ScheduleEvent(EVENT_LINK_GOLEM_HEALTH, 5s);
        events.ScheduleEvent(EVENT_POWER_UP_FIRST_GOLEM, 10s);
    }

    void JustSummoned(Creature* summon) override
    {

        switch (summon->GetEntry())
        {
            case NPC_ELECTRON:
            case NPC_MAGMATRON:
            case NPC_TOXITRON:
            case NPC_ARCANOTRON:
                _golemGuidVector.push_back(summon->GetGUID());
                break;
            default:
                summons.Summon(summon);
                break;
        }
    }

    ObjectGuid GetGUID(int32 type) const override
    {
        switch (type)
        {
            case DATA_NEXT_GOLEM_IN_QUEUE:
                return _nextGolemGUID;
            default:
                return ObjectGuid::Empty;
        }

        return ObjectGuid::Empty;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_GOLEM_ACTIVATED:
                if (instance->GetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM) == IN_PROGRESS)
                {
                    if (Creature* golem = ObjectAccessor::GetCreature(*me, _nextGolemGUID))
                    {
                        Talk(_golemInfoMap[golem->GetEntry()].ActivateTextId);
                        golem->CastSpell(golem, SPELL_ACTIVATED);
                    }

                    SelectNextGolemGUID();
                    DoCastAOE(SPELL_CONTROLLER_RECHARGE, true);
                }
                break;
            case ACTION_START_ENCOUNTER:
                instance->SetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM, IN_PROGRESS);
                // Since we blocked the first action call with our first golem we call it right away now to continue the cycle
                DoAction(ACTION_GOLEM_ACTIVATED);
                break;
            case ACTION_STOP_ENCOUNTER:
                for (uint8 i = DATA_ELECTRON; i < DATA_ELECTRON + 4; i++)
                {
                    if (Creature* golem = instance->GetCreature(i))
                    {
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, golem);
                        golem->DespawnOrUnsummon(100ms);
                    }
                }
  
                instance->SetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM, FAIL);
                _DespawnAtEvade();
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_LINK_GOLEM_HEALTH:
                    for (ObjectGuid guid : _golemGuidVector)
                        if (Creature* golem = ObjectAccessor::GetCreature(*me, guid))
                            golem->CastSpell(golem, SPELL_SHARED_HEALTH, true);
                    break;
                case EVENT_POWER_UP_FIRST_GOLEM:
                    // Randomize our golem order for each encounter
                    Trinity::Containers::RandomShuffle(_golemGuidVector);
                    SelectNextGolemGUID();
                    DoCastAOE(SPELL_CONTROLLER_RECHARGE);
                    break;
                default:
                    break;
            }
        }
    }

private:
    GuidVector _golemGuidVector;
    ObjectGuid _nextGolemGUID;

    // Selects the ObjectGuid for the next Golem
    void SelectNextGolemGUID()
    {
        _nextGolemGUID = _golemGuidVector.front();
        _golemGuidVector.erase(_golemGuidVector.begin());
        _golemGuidVector.push_back(_nextGolemGUID);
    }
};

struct npc_omnotron_golem : public ScriptedAI
{
    npc_omnotron_golem(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (_instance->GetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM) != IN_PROGRESS)
        {
            if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
                omnotron->AI()->DoAction(ACTION_START_ENCOUNTER);
        }

        _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();

        if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
            omnotron->AI()->DoAction(ACTION_STOP_ENCOUNTER);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_START_WAYPOINTS)
        {
            me->GetMotionMaster()->MovePath(BOSS_OMNOTRON * 100, true);
            me->SetWalk(true);
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ACTIVATE_GOLEM:
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveAurasDueToSpell(SPELL_INACTIVE);
                me->RemoveAurasDueToSpell(SPELL_POWERED_DOWN);

                if (_instance->GetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM) != IN_PROGRESS)
                {
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(POINT_START_WAYPOINTS, FirstGolemPatrolStartPoint);
                }
                else
                    DoZoneInCombat();

                // Golem is online, time to inform the controller about it
                if (Creature* omnotron = _instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
                    omnotron->AI()->DoAction(ACTION_GOLEM_ACTIVATED);
                break;
            case ACTION_DEACTIVATE_GOLEM:
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                _events.Reset();
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case 0:
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

class GuidCheck
{
    public:
        GuidCheck(ObjectGuid golemGUID) : _golemGUID(golemGUID)  { }

        bool operator()(WorldObject* object)
        {
            return object->GetGUID() != _golemGUID;
        }
    private:
        ObjectGuid _golemGUID;
};

class spell_omnotron_controller_recharge : public SpellScript
{
    PrepareSpellScript(spell_omnotron_controller_recharge);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_RECHARGING_ELECTRON,
                SPELL_RECHARGING_MAGMATRON,
                SPELL_RECHARGING_TOXITRON,
                SPELL_RECHARGING_ARCANOTRON
            });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        Creature* omnotron = instance->GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM);
        if (!omnotron)
            return;

        ObjectGuid golemGuid = omnotron->AI()->GetGUID(DATA_NEXT_GOLEM_IN_QUEUE);
        targets.remove_if(GuidCheck(golemGuid));
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            uint32 rechargingSpellId = 0;
            switch (GetHitUnit()->GetEntry())
            {
                case NPC_ELECTRON:
                    rechargingSpellId = SPELL_RECHARGING_ELECTRON;
                    break;
                case NPC_MAGMATRON:
                    rechargingSpellId = SPELL_RECHARGING_MAGMATRON;
                    break;
                case NPC_TOXITRON:
                    rechargingSpellId = SPELL_RECHARGING_TOXITRON;
                    break;
                case NPC_ARCANOTRON:
                    rechargingSpellId = SPELL_RECHARGING_ARCANOTRON;
                    break;
                default:
                    break;
            }

            if (rechargingSpellId)
                caster->CastSpell(caster, rechargingSpellId);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_omnotron_controller_recharge::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_omnotron_controller_recharge::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_omnotron_recharging : public AuraScript
{
    PrepareAuraScript(spell_omnotron_recharging);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_INACTIVE,
                SPELL_POWERED_DOWN
            });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* golem = GetTarget()->ToCreature())
            if (golem->IsAIEnabled)
                golem->AI()->DoAction(ACTION_ACTIVATE_GOLEM);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_omnotron_recharging::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_omnotron_activated : public AuraScript
{
    PrepareAuraScript(spell_omnotron_activated);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHUTTING_DOWN });
    }

    void HandleTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (Unit* caster = GetCaster())
            if (caster->GetVictim())
            if (caster->GetVictim())
                caster->CastSpell(GetCaster()->GetVictim(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_POWER_AND_REAGENT_COST));
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_SHUTTING_DOWN);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_omnotron_activated::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_omnotron_activated::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_omnotron_inactive : public SpellScript
{
    PrepareSpellScript(spell_omnotron_inactive);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_RECHARGING_ELECTRON });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, SPELL_POWERED_DOWN, true);
        if (Creature* golem = target->ToCreature())
            if (golem->IsAIEnabled)
                golem->AI()->DoAction(ACTION_DEACTIVATE_GOLEM);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_omnotron_inactive::HandleScriptEffect, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_omnotron_defense_system()
{
    RegisterBlackwingDescentCreatureAI(boss_omnotron_defense_system);
    RegisterBlackwingDescentCreatureAI(npc_omnotron_golem);
    RegisterSpellScript(spell_omnotron_controller_recharge);
    RegisterAuraScript(spell_omnotron_recharging);
    RegisterAuraScript(spell_omnotron_activated);
    RegisterSpellScript(spell_omnotron_inactive);
}
