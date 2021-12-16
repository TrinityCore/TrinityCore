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
#include "GameObject.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "utgarde_keep.h"

uint32 ForgeSearch[3] =
{
    GO_GLOWING_ANVIL_1,
    GO_GLOWING_ANVIL_2,
    GO_GLOWING_ANVIL_3
};

struct npc_dragonflayer_forge_master : public ScriptedAI
{
    npc_dragonflayer_forge_master(Creature* creature) : ScriptedAI(creature)
    {
        _instance = creature->GetInstanceScript();
        _forgeId = 0;
    }

    void Reset() override
    {
        if (!_forgeId)
            _forgeId = GetForgeMasterType();

        if (!me->IsAlive())
            return;

        if (_forgeId)
            _instance->SetData(DATA_FORGE_1 + _forgeId - 1, NOT_STARTED);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (!_forgeId)
            _forgeId = GetForgeMasterType();

        if (_forgeId)
            _instance->SetData(DATA_FORGE_1 + _forgeId - 1, DONE);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (!_forgeId)
            _forgeId = GetForgeMasterType();

        if (_forgeId)
            _instance->SetData(DATA_FORGE_1 + _forgeId - 1, IN_PROGRESS);

        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (!_forgeId)
            _forgeId = GetForgeMasterType();

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    uint8 GetForgeMasterType()
    {
        float diff = 30.0f;
        uint8 id = 0;

        for (uint8 i = 0; i < 3; ++i)
        {
            if (GameObject* go = me->FindNearestGameObject(ForgeSearch[i], 30))
            {
                if (me->IsWithinDist(go, diff, false))
                {
                    id = i + 1;
                    diff = me->GetDistance2d(go);
                }
            }
        }
        return id > 0 && id < 4 ? id : 0;
    }

    InstanceScript* _instance;
    uint8 _forgeId;
};

enum Fixate
{
    SPELL_FIXATE_TRIGGER = 40415
};

// 40414 - Fixate
class spell_fixate : public SpellScript
{
    PrepareSpellScript(spell_fixate);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FIXATE_TRIGGER });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), SPELL_FIXATE_TRIGGER, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fixate::HandleScriptEffect, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum SecondWind
{
    SPELL_SECOND_WIND_TRIGGER = 42771
};

// 42770 - Second Wind
class spell_uk_second_wind : public AuraScript
{
    PrepareAuraScript(spell_uk_second_wind);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SECOND_WIND_TRIGGER });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo)
            return false;

        return (spellInfo->GetAllEffectsMechanicMask() & ((1 << MECHANIC_ROOT) | (1 << MECHANIC_STUN))) != 0;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* caster = eventInfo.GetActionTarget();
        caster->CastSpell(caster, SPELL_SECOND_WIND_TRIGGER, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_uk_second_wind::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_uk_second_wind::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

enum EnslavedProtoDrake
{
    TYPE_PROTODRAKE_AT      = 28,
    DATA_PROTODRAKE_MOVE    = 6,

    PATH_PROTODRAKE         = 125946,

    EVENT_REND              = 1,
    EVENT_FLAME_BREATH      = 2,
    EVENT_KNOCKAWAY         = 3,

    SPELL_REND              = 43931,
    SPELL_FLAME_BREATH      = 50653,
    SPELL_KNOCK_AWAY        = 49722,

    POINT_LAST              = 5,
};

const Position protodrakeCheckPos = {206.24f, -190.28f, 200.11f, 0.f};

struct npc_enslaved_proto_drake : public ScriptedAI
{
    npc_enslaved_proto_drake(Creature* creature) : ScriptedAI(creature)
    {
        _setData = false;
    }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_REND, 2s, 3s);
        _events.ScheduleEvent(EVENT_FLAME_BREATH, 5500ms, 7s);
        _events.ScheduleEvent(EVENT_KNOCKAWAY, 3500ms, 6s);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == WAYPOINT_MOTION_TYPE && id == POINT_LAST)
        {
            me->SetAnimationTier(AnimationTier::Ground);
        }
    }

    void SetData(uint32 type, uint32 data) override
    {
        if (type == TYPE_PROTODRAKE_AT && data == DATA_PROTODRAKE_MOVE && !_setData && me->GetDistance(protodrakeCheckPos) < 5.0f)
        {
            _setData = true;
            me->SetAnimationTier(AnimationTier::Fly);
            me->GetMotionMaster()->MovePath(PATH_PROTODRAKE, false);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventid = _events.ExecuteEvent())
        {
            switch (eventid)
            {
                case EVENT_REND:
                    DoCast(SPELL_REND);
                    _events.ScheduleEvent(EVENT_REND, 15s, 20s);
                    break;
                case EVENT_FLAME_BREATH:
                    DoCast(SPELL_FLAME_BREATH);
                    _events.ScheduleEvent(EVENT_FLAME_BREATH, 11s, 12s);
                    break;
                case EVENT_KNOCKAWAY:
                    DoCast(SPELL_KNOCK_AWAY);
                    _events.ScheduleEvent(EVENT_KNOCKAWAY, 7s, 8500ms);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _setData;
    EventMap _events;
};

void AddSC_utgarde_keep()
{
    RegisterUtgardeKeepCreatureAI(npc_dragonflayer_forge_master);
    RegisterUtgardeKeepCreatureAI(npc_enslaved_proto_drake);
    RegisterSpellScript(spell_fixate);
    RegisterSpellScript(spell_uk_second_wind);
}
