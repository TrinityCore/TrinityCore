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

/*
 * Timers requires to be revisited
 * Initial movement for swarmers is NYI (SwarmerLoopSpells)
 * SPELL_DESPAWN_SWARMERS is NYI, seems like used in combat after SPELL_SWARMERS_SWARM, not just as regular cleanup spell in case of wipe \ death.
   Seems like targets only alive units
 * What's the purpose of world triggers spawned in the room? The one spawned near altar enters in combat
 * What's the purpose of Script Effect of SPELL_SUMMON_LARVA_1 & SPELL_SUMMON_LARVA_2?
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ruins_of_ahnqiraj.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum AyamissTexts
{
    EMOTE_FRENZY                = 0
};

enum AyamissSpells
{
    SPELL_STINGER_SPRAY         = 25749,
    SPELL_POISON_STINGER        = 25748,
    SPELL_PARALYZE              = 25725,
    SPELL_THRASH                = 3391,
    SPELL_LASH                  = 25852,
    SPELL_FRENZY                = 8269,

    SPELL_SUMMON_LARVA_1        = 26538,
    SPELL_SUMMON_LARVA_2        = 26539,
    SPELL_SUMMON_SWARMER        = 25708,
    SPELL_DESPAWN_SWARMERS      = 25842,
    SPELL_SWARMERS_SWARM        = 25844,

    // Hive'Zara Swarmer
    SPELL_SWARMER_START_LOOP    = 25711,
    SPELL_SWARMER_TELE_TRIGGER  = 25830,

    SPELL_SWARMER_LOOP_1        = 25833,
    SPELL_SWARMER_LOOP_2        = 25834,
    SPELL_SWARMER_LOOP_3        = 25835,

    SPELL_SWARMER_TELEPORT_1    = 25709,
    SPELL_SWARMER_TELEPORT_2    = 25825,
    SPELL_SWARMER_TELEPORT_3    = 25826,
    SPELL_SWARMER_TELEPORT_4    = 25827,
    SPELL_SWARMER_TELEPORT_5    = 25828,

    // Hive'Zara Larva
    SPELL_FEED                  = 25721,
    SPELL_LARVA_AGGRO_EFFECT    = 25724,    // NYI, most likely related to Paralyze
    SPELL_LARVA_FEAR_EFFECT     = 25726     // NYI, most likely related to Paralyze
};

enum AyamissEvents
{
    EVENT_STINGER_SPRAY         = 1,
    EVENT_POISON_STINGER,
    EVENT_SUMMON_SWARMER,
    EVENT_SWARMERS_SWARM,
    EVENT_PARALYZE,
    EVENT_LASH,
    EVENT_THRASH,
    EVENT_FRENZY
};

enum AyamissPhases
{
    PHASE_AIR                   = 0,
    PHASE_GROUND                = 1
};

enum AyamissPoints
{
    POINT_AIR                   = 0,
    POINT_GROUND                = 1,
    POINT_ALTAR                 = 2,
    POINT_SWARMER               = 3
};

const Position AyamissAirPos    = { -9689.292f, 1547.9122f, 48.027287f, 0.0f };
const Position AyamissGroundPos = { -9689.981f, 1548.2961f, 33.277330f, 0.0f };
const Position AltarPos         = { -9715.510f, 1518.8200f, 27.467716f, 0.0f };
const Position SwarmerPos       = { -9647.352f, 1578.0620f, 55.320000f, 0.0f };

std::array<uint32, 3> const SwarmerLoopSpells =
{
    SPELL_SWARMER_LOOP_1, SPELL_SWARMER_LOOP_2, SPELL_SWARMER_LOOP_3
};

std::array<uint32, 5> const SwarmerTeleportSpells =
{
    SPELL_SWARMER_TELEPORT_1, SPELL_SWARMER_TELEPORT_2, SPELL_SWARMER_TELEPORT_3, SPELL_SWARMER_TELEPORT_4, SPELL_SWARMER_TELEPORT_5
};

// 15369 - Ayamiss the Hunter
struct boss_ayamiss : public BossAI
{
    boss_ayamiss(Creature* creature) : BossAI(creature, DATA_AYAMISS), _frenzied(false), _phase(PHASE_AIR) { }

    void Reset() override
    {
        _Reset();
        _frenzied = false;
        _phase = PHASE_AIR;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_STINGER_SPRAY, 20s, 30s);
        events.ScheduleEvent(EVENT_POISON_STINGER, 5s);
        events.ScheduleEvent(EVENT_SUMMON_SWARMER, 5s);
        events.ScheduleEvent(EVENT_SWARMERS_SWARM, 1min);
        events.ScheduleEvent(EVENT_PARALYZE, 10s, 15s);

        me->SetReactState(REACT_PASSIVE);
        me->SetHover(true);
        me->SetDisableGravity(true);
        me->GetMotionMaster()->MovePoint(POINT_AIR, AyamissAirPos);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_phase == PHASE_AIR && me->HealthBelowPctDamaged(70, damage))
        {
            me->SetReactState(REACT_PASSIVE);
            _phase = PHASE_GROUND;
            me->GetMotionMaster()->MovePoint(POINT_GROUND, AyamissGroundPos);
        }

        if (!_frenzied && me->HealthBelowPctDamaged(20, damage))
        {
            _frenzied = true;
            events.ScheduleEvent(EVENT_FRENZY, 0s);
        }
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_FRENZY)
            Talk(EMOTE_FRENZY);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE)
        {
            switch (id)
            {
                case POINT_AIR:
                    SetCombatMovement(false);
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case POINT_GROUND:
                    SetCombatMovement(true);
                    me->SetHover(false);
                    me->SetDisableGravity(false);
                    me->SetReactState(REACT_AGGRESSIVE);
                    ResetThreatList();
                    events.ScheduleEvent(EVENT_LASH, 5s, 8s);
                    events.ScheduleEvent(EVENT_THRASH, 3s, 6s);
                    events.CancelEvent(EVENT_POISON_STINGER);
                    break;
            }
        }
    }

    // Do not despawn swarmers and larva
    void JustSummoned(Creature* /*summon*/) override { }

    void JustReachedHome() override
    {
        _JustReachedHome();
        SetCombatMovement(true);
        me->SetHover(false);
        me->SetDisableGravity(false);
        me->SetReactState(REACT_AGGRESSIVE);
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
                case EVENT_STINGER_SPRAY:
                    DoCastSelf(SPELL_STINGER_SPRAY);
                    events.Repeat(15s, 20s);
                    break;
                case EVENT_POISON_STINGER:
                    DoCastVictim(SPELL_POISON_STINGER);
                    events.Repeat(2s, 3s);
                    break;
                case EVENT_SUMMON_SWARMER:
                    DoCastSelf(SPELL_SUMMON_SWARMER);
                    events.Repeat(5s);
                    break;
                case EVENT_SWARMERS_SWARM:
                    DoCastSelf(SPELL_SWARMERS_SWARM);
                    events.Repeat(1min);
                    break;
                case EVENT_PARALYZE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0, true))
                    {
                        DoCast(target, SPELL_PARALYZE);
                        instance->SetGuidData(DATA_PARALYZED, target->GetGUID());
                    }
                    events.Repeat(12s, 18s);
                    break;
                case EVENT_THRASH:
                    DoCastSelf(SPELL_THRASH);
                    events.Repeat(5s, 7s);
                    break;
                case EVENT_LASH:
                    DoCastVictim(SPELL_LASH);
                    events.Repeat(8s, 15s);
                    break;
                case EVENT_FRENZY:
                    DoCastSelf(SPELL_FRENZY);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _frenzied;
    uint8 _phase;
};

// 15555 - Hive'Zara Larva
struct npc_hive_zara_larva : public ScriptedAI
{
    npc_hive_zara_larva(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(3, true);
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        me->GetMotionMaster()->MovePoint(POINT_ALTAR, AltarPos, true, 3.724058866500854492f);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == POINT_ALTAR)
            if (Player* target = ObjectAccessor::GetPlayer(*me, _instance->GetGuidData(DATA_PARALYZED)))
                DoCast(target, SPELL_FEED);
    }

private:
    InstanceScript* _instance;
};

// 15546 - Hive'Zara Swarmer
struct npc_hive_zara_swarmer : public ScriptedAI
{
    npc_hive_zara_swarmer(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(3, true);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_SWARMER_START_LOOP);
        DoCastSelf(SPELL_SWARMER_TELE_TRIGGER);

        /// @todo: Temporary, replace with splines
        Position pos = me->GetRandomPoint(SwarmerPos, 40.0f);
        pos.m_positionZ = 55.0f;
        me->GetMotionMaster()->MovePoint(POINT_SWARMER, pos);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_DESPAWN_SWARMERS:
                me->SetReactState(REACT_PASSIVE);
                me->DespawnOrUnsummon(2s);
                break;
            case SPELL_SWARMERS_SWARM:
                me->SetDisableGravity(false);
                me->GetMotionMaster()->MoveFall();
                DoZoneInCombat();
                break;
            case SPELL_SWARMER_LOOP_1:
                break;
            case SPELL_SWARMER_LOOP_2:
                break;
            case SPELL_SWARMER_LOOP_3:
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

// 25725 - Paralyze
class spell_ayamiss_paralyze : public SpellScript
{
    PrepareSpellScript(spell_ayamiss_paralyze);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_LARVA_1, SPELL_SUMMON_LARVA_2 });
    }

    void HandleAfterHit()
    {
        GetCaster()->CastSpell(GetCaster(), RAND(SPELL_SUMMON_LARVA_1, SPELL_SUMMON_LARVA_2), true);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_ayamiss_paralyze::HandleAfterHit);
    }
};

// 25711 - Hive'Zara Swarmer Start Loop
class spell_ayamiss_swarmer_start_loop : public SpellScript
{
    PrepareSpellScript(spell_ayamiss_swarmer_start_loop);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(SwarmerLoopSpells);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), Trinity::Containers::SelectRandomContainerElement(SwarmerLoopSpells));
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_ayamiss_swarmer_start_loop::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 25830 - Hive'Zara Swarmer Teleport Trigger
class spell_ayamiss_swarmer_teleport_trigger : public SpellScript
{
    PrepareSpellScript(spell_ayamiss_swarmer_teleport_trigger);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(SwarmerTeleportSpells);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), Trinity::Containers::SelectRandomContainerElement(SwarmerTeleportSpells));
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_ayamiss_swarmer_teleport_trigger::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_ayamiss()
{
    RegisterAQ20CreatureAI(boss_ayamiss);
    RegisterAQ20CreatureAI(npc_hive_zara_larva);
    RegisterAQ20CreatureAI(npc_hive_zara_swarmer);
    RegisterSpellScript(spell_ayamiss_paralyze);
    RegisterSpellScript(spell_ayamiss_swarmer_start_loop);
    RegisterSpellScript(spell_ayamiss_swarmer_teleport_trigger);
}
