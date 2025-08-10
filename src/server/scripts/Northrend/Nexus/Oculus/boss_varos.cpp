/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "oculus.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum Says
{
    SAY_AGGRO           = 0,
    SAY_AZURE           = 1,
    SAY_AZURE_EMOTE     = 2,
    SAY_DEATH           = 3
};

enum Spells
{
    SPELL_ENERGIZE_CORES_VISUAL                   = 62136,
    SPELL_ENERGIZE_CORES                          = 50785, //Damage 5938 to 6562, effec2 Triggers 54069, effect3 Triggers 56251
    SPELL_CALL_AZURE_RING_CAPTAIN                 = 51002, //Effect    Send Event (12229)
    /*SPELL_CALL_AZURE_RING_CAPTAIN_2               = 51006, //Effect    Send Event (10665)
    SPELL_CALL_AZURE_RING_CAPTAIN_3               = 51007, //Effect    Send Event (18454)
    SPELL_CALL_AZURE_RING_CAPTAIN_4               = 51008, //Effect    Send Event (18455)*/
    SPELL_CALL_AMPLIFY_MAGIC                      = 51054,

    SPELL_ICE_BEAM                                = 49549,
    SPELL_ARCANE_BEAM_PERIODIC                    = 51019,
    SPELL_SUMMON_ARCANE_BEAM                      = 51017
};

enum Events
{
    EVENT_ENERGIZE_CORES = 1,
    EVENT_CALL_AZURE,
    EVENT_AMPLIFY_MAGIC,
    EVENT_ENERGIZE_CORES_VISUAL
};

struct boss_varos : public BossAI
{
    boss_varos(Creature* creature) : BossAI(creature, DATA_VAROS)
    {
        Initialize();
    }

    void Initialize()
    {
        firstCoreEnergize = false;
        coreEnergizeOrientation = 0.0f;
    }

    void InitializeAI() override
    {
        BossAI::InitializeAI();
        if (instance->GetBossState(DATA_DRAKOS) != DONE)
            DoCast(me, SPELL_CENTRIFUGE_SHIELD);
    }

    void Reset() override
    {
        _Reset();

        events.ScheduleEvent(EVENT_AMPLIFY_MAGIC, 20s, 25s);
        events.ScheduleEvent(EVENT_ENERGIZE_CORES_VISUAL, 5s);
        // not sure if this is handled by a timer or hp percentage
        events.ScheduleEvent(EVENT_CALL_AZURE, 15s, 30s);

        Initialize();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);
    }

    float GetCoreEnergizeOrientation()
    {
        return coreEnergizeOrientation;
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
                case EVENT_ENERGIZE_CORES:
                    DoCast(me, SPELL_ENERGIZE_CORES);
                    events.CancelEvent(EVENT_ENERGIZE_CORES);
                    break;
                case EVENT_ENERGIZE_CORES_VISUAL:
                    if (!firstCoreEnergize)
                    {
                        coreEnergizeOrientation = me->GetOrientation();
                        firstCoreEnergize = true;
                    }
                    else
                        coreEnergizeOrientation = Position::NormalizeOrientation(coreEnergizeOrientation - 2.0f);

                    DoCast(me, SPELL_ENERGIZE_CORES_VISUAL);
                    events.ScheduleEvent(EVENT_ENERGIZE_CORES_VISUAL, 5s);
                    events.ScheduleEvent(EVENT_ENERGIZE_CORES, 4s);
                    break;
                case EVENT_CALL_AZURE:
                    // not sure how blizz handles this, i cant see any pattern between the differnt spells
                    DoCast(me, SPELL_CALL_AZURE_RING_CAPTAIN);
                    Talk(SAY_AZURE);
                    Talk(SAY_AZURE_EMOTE);
                    events.ScheduleEvent(EVENT_CALL_AZURE, 20s, 25s);
                    break;
                case EVENT_AMPLIFY_MAGIC:
                    DoCastVictim(SPELL_CALL_AMPLIFY_MAGIC);
                    events.ScheduleEvent(EVENT_AMPLIFY_MAGIC, 17s, 20s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        DoCast(me, SPELL_DEATH_SPELL, true); // we cast the spell as triggered or the summon effect does not occur
    }

private:
    bool firstCoreEnergize;
    float coreEnergizeOrientation;
};

struct npc_azure_ring_captain : public ScriptedAI
{
    npc_azure_ring_captain(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        instance = creature->GetInstanceScript();
    }

    void Initialize()
    {
        targetGUID.Clear();
    }

    void Reset() override
    {
        Initialize();

        me->SetWalk(true);
        //! HACK: Creature's can't have MOVEMENTFLAG_FLYING
        me->AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_ICE_BEAM)
        {
            target->CastSpell(target, SPELL_SUMMON_ARCANE_BEAM, true);
            me->DespawnOrUnsummon();
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE ||
            id != ACTION_CALL_DRAGON_EVENT)
            return;

        me->GetMotionMaster()->MoveIdle();

        if (Unit* target = ObjectAccessor::GetUnit(*me, targetGUID))
            DoCast(target, SPELL_ICE_BEAM);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_CALL_DRAGON_EVENT:
                if (Creature* varos = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VAROS)))
                {
                    if (Unit* victim = varos->AI()->SelectTarget(SelectTargetMethod::Random, 0))
                    {
                        me->SetReactState(REACT_PASSIVE);
                        me->SetWalk(false);
                        me->GetMotionMaster()->MovePoint(ACTION_CALL_DRAGON_EVENT, victim->GetPositionX(), victim->GetPositionY(), victim->GetPositionZ() + 20.0f);
                        targetGUID = victim->GetGUID();
                    }
                }
                break;
        }
   }

private:
    ObjectGuid targetGUID;
    InstanceScript* instance;
};

// 50053 - Centrifuge Shield
class spell_varos_centrifuge_shield : public AuraScript
{
    bool Load() override
    {
        Unit* caster = GetCaster();
        return caster && caster->GetTypeId() == TYPEID_UNIT;
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            caster->SetImmuneToAll(true, true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            caster->SetImmuneToAll(false);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_varos_centrifuge_shield::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectApply += AuraEffectApplyFn(spell_varos_centrifuge_shield::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 50785, 59372 - Energize Cores
class spell_varos_energize_core_area_enemy : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Creature* varos = GetCaster()->ToCreature();
        if (!varos)
            return;

        if (varos->GetEntry() != NPC_VAROS)
            return;

        float orientation = ENSURE_AI(boss_varos, varos->AI())->GetCoreEnergizeOrientation();

        for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end();)
        {
            float angle = varos->GetAbsoluteAngle((*itr)->GetPositionX(), (*itr)->GetPositionY());
            float diff = std::fabs(orientation - angle);

            if (diff > 1.0f)
                itr = targets.erase(itr);
            else
                ++itr;
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_varos_energize_core_area_enemy::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 54069, 56251 - Energize Cores
// 61407, 62136 - Energize Cores
class spell_varos_energize_core_area_entry : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Creature* varos = GetCaster()->ToCreature();
        if (!varos)
            return;

        if (varos->GetEntry() != NPC_VAROS)
            return;

        float orientation = ENSURE_AI(boss_varos, varos->AI())->GetCoreEnergizeOrientation();

        for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end();)
        {
            float angle = varos->GetAbsoluteAngle((*itr)->GetPositionX(), (*itr)->GetPositionY());
            float diff = std::fabs(orientation - angle);

            if (diff > 1.0f)
                itr = targets.erase(itr);
            else
                ++itr;
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_varos_energize_core_area_entry::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

void AddSC_boss_varos()
{
    RegisterOculusCreatureAI(boss_varos);
    RegisterOculusCreatureAI(npc_azure_ring_captain);
    RegisterSpellScript(spell_varos_centrifuge_shield);
    RegisterSpellScript(spell_varos_energize_core_area_enemy);
    RegisterSpellScript(spell_varos_energize_core_area_entry);
}
