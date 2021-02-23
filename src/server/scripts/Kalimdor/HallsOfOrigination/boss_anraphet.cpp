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
#include "GridNotifiers.h"
#include "halls_of_origination.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Texts
{
    ANRAPHET_SAY_INTRO              = 0,
    ANRAPHET_SAY_AGGRO              = 1,
    ANRAPHET_SAY_OMEGA_STANCE       = 2,
    ANRAPHET_SAY_KILL               = 3,
    ANRAPHET_SAY_DEATH              = 4,
};

enum Events
{
    // Anraphet
    EVENT_LEAVE_CONTROL_ROOM = 1,
    EVENT_ANRAPHET_ACTIVATE,
    EVENT_ANRAPHET_DESTRUCTION,
    EVENT_ANRAPHET_READY,
    EVENT_ANRAPHET_NEMESIS_STRIKE,
    EVENT_ANRAPHET_ALPHA_BEAMS,
    EVENT_ANRAPHET_OMEGA_STANCE,
    EVENT_ANRAPHET_CRUMBLING_RUIN,
    EVENT_ANRAPHET_ACTIVATE_OMEGA
};

enum Spells
{
    // Anraphet
    SPELL_DESTRUCTION_PROTOCOL          = 77437,
    SPELL_ALPHA_BEAMS                   = 76184,
    SPELL_ALPHA_BEAMS_BACK_CAST         = 76912,
    SPELL_CRUMBLING_RUIN                = 75609,
    SPELL_NEMESIS_STRIKE                = 75604,

    // Omega Stance
    SPELL_OMEGA_STANCE_SUMMON           = 77106,
    SPELL_OMEGA_STANCE                  = 75622,
    SPELL_OMEGA_STANCE_SPIDER_TRIGGER   = 77121
};

enum Phases
{
    PHASE_INTRO         = 1,
    PHASE_COMBAT        = 2
};

enum Points
{
    POINT_ANRAPHET_ACTIVATE,
    POINT_BRANN_SAY_TROGGS, 
    POINT_BRANN_SAY_MOMENT,
    POINT_BRANN_TURN_BACK
};

uint32 const AnraphetPathSize = 6;
Position const AnraphetPath[AnraphetPathSize] =
{
    { -125.4643f, 366.5138f, 89.88697f },
    { -132.7143f, 366.5138f, 89.88697f },
    { -143.9643f, 366.5138f, 89.88697f },
    { -159.2143f, 366.5138f, 85.38697f },
    { -188.2143f, 366.7638f, 76.38697f },
    { -193.656f,  366.689f,  75.91001f }
};

// Brann's intro
Position const BrannBossHomePos = { -429.583f, 367.019f, 89.79282f, 0.01745329f };

// Brann's outro
uint32 const BrannOutroPathSize = 13;
Position const BrannOutroPath[BrannOutroPathSize] =
{
    { -409.9531f, 367.0469f, 89.81111f, 0.0f },
    { -397.8246f, 366.967f,  86.37722f, 0.0f },
    { -383.7813f, 366.8229f, 82.07919f, 0.0f },
    { -368.2604f, 366.7448f, 77.0984f,  0.0f },
    { -353.6458f, 366.4896f, 75.92504f, 0.0f },
    { -309.0608f, 366.7205f, 75.91345f, 0.0f },
    { -276.3303f, 367.0f,    75.92413f, 0.0f },
    { -246.5104f, 366.6389f, 75.87791f, 0.0f },
    { -202.0417f, 366.7517f, 75.92508f, 0.0f },
    { -187.6024f, 366.7656f, 76.23077f, 0.0f },
    { -155.0938f, 366.783f,  86.45834f, 0.0f },
    { -143.5694f, 366.8177f, 89.73354f, 0.0f },
    { -128.5608f, 366.8629f, 89.74199f, 0.0f }
};

uint32 const BrannFinalPathSize = 3;
Position const BrannFinalPath[BrannFinalPathSize] =
{
    { -103.559f,  366.5938f, 89.79725f, 0.0f },
    { -71.58507f, 367.0278f, 89.77069f, 0.0f },
    { -35.04861f, 366.6563f, 89.77447f, 0.0f }
};

struct boss_anraphet : public BossAI
{
    boss_anraphet(Creature* creature) : BossAI(creature, DATA_ANRAPHET) { }

    void Reset() override
    {
        _Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(ANRAPHET_SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.SetPhase(PHASE_COMBAT);
        events.ScheduleEvent(EVENT_ANRAPHET_NEMESIS_STRIKE, Seconds(8), 0, PHASE_COMBAT);
        events.ScheduleEvent(EVENT_ANRAPHET_ALPHA_BEAMS, Seconds(10), 0, PHASE_COMBAT);
        events.ScheduleEvent(EVENT_ANRAPHET_OMEGA_STANCE, Seconds(35), 0, PHASE_COMBAT);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_ANRAPHET, FAIL);
        summons.DespawnAll();
        _EnterEvadeMode();
        me->DespawnOrUnsummon();
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        Talk(ANRAPHET_SAY_DEATH);
        _JustDied();

        if (Creature* brann = instance->GetCreature(DATA_BRANN_0))
            if (brann->IsAIEnabled)
                brann->AI()->DoAction(ACTION_ANRAPHET_DIED);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(ANRAPHET_SAY_KILL);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_ANRAPHET_INTRO)
        {
            events.SetPhase(PHASE_INTRO);
            events.ScheduleEvent(EVENT_LEAVE_CONTROL_ROOM, 10s, 0, PHASE_INTRO);
        }
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != EFFECT_MOTION_TYPE || point != POINT_ANRAPHET_ACTIVATE)
            return;

        events.ScheduleEvent(EVENT_ANRAPHET_ACTIVATE, Seconds(1), 0, PHASE_INTRO);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !events.IsInPhase(PHASE_INTRO))
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_LEAVE_CONTROL_ROOM:
                    me->GetMotionMaster()->MoveSmoothPath(POINT_ANRAPHET_ACTIVATE, AnraphetPath, AnraphetPathSize);
                    break;
                case EVENT_ANRAPHET_ACTIVATE:
                    Talk(ANRAPHET_SAY_INTRO);
                    events.ScheduleEvent(EVENT_ANRAPHET_DESTRUCTION, Seconds(10), 0, PHASE_INTRO);
                    break;
                case EVENT_ANRAPHET_DESTRUCTION:
                    DoCastAOE(SPELL_DESTRUCTION_PROTOCOL);
                    events.ScheduleEvent(EVENT_ANRAPHET_READY, Seconds(6), 0, PHASE_INTRO);
                    break;
                case EVENT_ANRAPHET_READY:
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    break;
                case EVENT_ANRAPHET_NEMESIS_STRIKE:
                    DoCastVictim(SPELL_NEMESIS_STRIKE);
                    events.ScheduleEvent(EVENT_ANRAPHET_NEMESIS_STRIKE, Seconds(21), 0, PHASE_COMBAT);
                    break;
                case EVENT_ANRAPHET_ALPHA_BEAMS:
                    DoCastSelf(SPELL_ALPHA_BEAMS);
                    events.ScheduleEvent(EVENT_ANRAPHET_CRUMBLING_RUIN, Seconds(12), 0, PHASE_COMBAT);
                    events.ScheduleEvent(EVENT_ANRAPHET_ALPHA_BEAMS, Seconds(40), Seconds(45), 0, PHASE_COMBAT);
                    break;
                case EVENT_ANRAPHET_OMEGA_STANCE:
                    DoCastSelf(SPELL_OMEGA_STANCE);
                    Talk(ANRAPHET_SAY_OMEGA_STANCE);
                    events.ScheduleEvent(EVENT_ANRAPHET_OMEGA_STANCE, Seconds(45), Seconds(50), 0, PHASE_COMBAT);
                    events.ScheduleEvent(EVENT_ANRAPHET_CRUMBLING_RUIN, Seconds(13), 0, PHASE_COMBAT);
                    break;
                case EVENT_ANRAPHET_CRUMBLING_RUIN:
                    DoCastSelf(SPELL_CRUMBLING_RUIN);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_alpha_beam : public ScriptedAI
{
    npc_alpha_beam(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        if (Creature* anraphet = _instance->GetCreature(DATA_ANRAPHET))
            anraphet->CastSpell(me, SPELL_ALPHA_BEAMS_BACK_CAST);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override { } // Never evade

private:
    InstanceScript * _instance;
};

struct npc_omega_stance : public ScriptedAI
{
    npc_omega_stance(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(Unit* /*who*/) override
    {
        DoCastSelf(SPELL_OMEGA_STANCE_SPIDER_TRIGGER, true);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override { }
};

class PlayerCheck
{
    public:
        PlayerCheck() { }

        bool operator()(WorldObject* object)
        {
            return (object->GetTypeId() != TYPEID_PLAYER);
        }
};

// 77437 - Destruction Protocol
class spell_anraphet_destruction_protocol : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(PlayerCheck());
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Creature* trogg = GetHitCreature())
        {
            trogg->SetCorpseDelay(4);
            trogg->SetRespawnDelay(DAY);
        }
    }

    void HandlePlayerDamage(SpellEffIndex /*effIndex*/)
    {
        if (Player* player = GetHitPlayer())
            SetHitDamage(CalculatePct(player->GetHealth(), 50));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_anraphet_destruction_protocol::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_anraphet_destruction_protocol::HandlePlayerDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnEffectHitTarget.Register(&spell_anraphet_destruction_protocol::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

class spell_anraphet_alpha_beams : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_anraphet_alpha_beams::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_anraphet_omega_stance : public AuraScript
{
    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_OMEGA_STANCE_SUMMON, true);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* omegaStanceDummy = GetTarget()->FindNearestCreature(NPC_OMEGA_STANCE, 50.0f, true))
            omegaStanceDummy->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectApply.Register(&spell_anraphet_omega_stance::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove.Register(&spell_anraphet_omega_stance::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 77106 - Omega Stance (Summon)
class spell_anraphet_omega_stance_summon : public SpellScript
{
    void SetDestPosition(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            float x = caster->GetPositionX();
            float y = caster->GetPositionY();
            float z = caster->GetPositionZ() + 30.0f;

            const_cast<WorldLocation*>(GetExplTargetDest())->Relocate(x, y, z);
            GetHitDest()->Relocate(x, y, z);
        }
    }

    void Register()
    {
        OnEffectLaunch.Register(&spell_anraphet_omega_stance_summon::SetDestPosition, EFFECT_0, SPELL_EFFECT_SUMMON);
    }
};

// 77127 Omega Stance Spider Effect
class spell_anraphet_omega_stance_spider_effect : public SpellScript
{
    void SetDestPosition(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        float angle = float(rand_norm()) * static_cast<float>(2 * M_PI);
        uint32 dist = caster->GetCombatReach() + GetSpellInfo()->Effects[EFFECT_0].CalcRadius(caster) * (float)rand_norm();

        float x = caster->GetPositionX() + dist * std::cos(angle);
        float y = caster->GetPositionY() + dist * std::sin(angle);
        float z = caster->GetMap()->GetHeight(caster->GetPhaseShift(), x, y, caster->GetPositionZ());
        float o = GetHitDest()->GetOrientation();

        GetHitDest()->Relocate({ x, y, z, o });
    }

    void Register()
    {
        OnEffectLaunch.Register(&spell_anraphet_omega_stance_spider_effect::SetDestPosition, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_anraphet()
{
    RegisterHallsOfOriginationCreatureAI(boss_anraphet);
    RegisterHallsOfOriginationCreatureAI(npc_alpha_beam);
    RegisterHallsOfOriginationCreatureAI(npc_omega_stance);
    RegisterSpellScript(spell_anraphet_destruction_protocol);
    RegisterSpellScript(spell_anraphet_alpha_beams);
    RegisterSpellScript(spell_anraphet_omega_stance);
    RegisterSpellScript(spell_anraphet_omega_stance_summon);
    RegisterSpellScript(spell_anraphet_omega_stance_spider_effect);
}
