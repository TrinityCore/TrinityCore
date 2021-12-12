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

#include "ahnkahet.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellScript.h"

enum PrinceTaldaramSpells
{
    SPELL_BLOODTHIRST                       = 55968, // Trigger Spell + add aura
    SPELL_CONJURE_FLAME_SPHERE              = 55931,
    SPELL_FLAME_SPHERE_SUMMON_1             = 55895, // 1x 30106
    SPELL_FLAME_SPHERE_SUMMON_2             = 59511, // 1x 31686
    SPELL_FLAME_SPHERE_SUMMON_3             = 59512, // 1x 31687
    SPELL_FLAME_SPHERE_SPAWN_EFFECT         = 55891,
    SPELL_FLAME_SPHERE_VISUAL               = 55928,
    SPELL_FLAME_SPHERE_PERIODIC             = 55926,
    SPELL_FLAME_SPHERE_DEATH_EFFECT         = 55947,
    SPELL_EMBRACE_OF_THE_VAMPYR             = 55959,
    SPELL_VANISH                            = 55964,
    SPELL_SHADOWSTEP                        = 55966,

    NPC_FLAME_SPHERE_1                      = 30106,
    NPC_FLAME_SPHERE_2                      = 31686,
    NPC_FLAME_SPHERE_3                      = 31687,

    SPELL_BEAM_VISUAL                       = 60342,
    SPELL_HOVER_FALL                        = 60425
};

enum PrinceTaldaramMisc
{
    DATA_EMBRACE_DMG                        = 20000,
    H_DATA_EMBRACE_DMG                      = 40000,
    SUMMON_GROUP_CONTROLLERS                = 1
};

enum PrinceTaldaramYells
{
    SAY_1                                   = 0,
    SAY_WARNING                             = 1,
    SAY_AGGRO                               = 2,
    SAY_SLAY                                = 3,
    SAY_DEATH                               = 4,
    SAY_FEED                                = 5,
    SAY_VANISH                              = 6
};

enum PrinceTaldaramEvents
{
    EVENT_CONJURE_FLAME_SPHERES             = 1,
    EVENT_BLOODTHIRST,
    EVENT_VANISH,
    EVENT_START_FEEDING,
    EVENT_DONE_FEEDING,

    // Flame Sphere
    EVENT_START_MOVE,
    EVENT_DESPAWN
};

float constexpr PrinceTaldaramSphereDistance = 25.f;
float constexpr PrinceTaldaramSphereAngleOffset = float(M_PI) / 2.f;
float constexpr PrinceTaldaramGroundPositionZ = 11.30809f;

struct boss_prince_taldaram : public BossAI
{
    boss_prince_taldaram(Creature* creature) : BossAI(creature, DATA_PRINCE_TALDARAM)
    {
        me->SetDisableGravity(true);
        _embraceTakenDamage = 0;
        _initialCheckTimer = 3000;
    }

    void Reset() override
    {
        _Reset();
        _flameSphereTargetGUID.Clear();
        _embraceTargetGUID.Clear();
        _embraceTakenDamage = 0;

        if (!CheckSpheres())
            me->SummonCreatureGroup(SUMMON_GROUP_CONTROLLERS);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_BLOODTHIRST, 10s);
        events.ScheduleEvent(EVENT_VANISH, 25s, 35s);
        events.ScheduleEvent(EVENT_CONJURE_FLAME_SPHERES, 5s);
    }

    void JustSummoned(Creature* summon) override
    {
        BossAI::JustSummoned(summon);

        switch (summon->GetEntry())
        {
            case NPC_FLAME_SPHERE_1:
            case NPC_FLAME_SPHERE_2:
            case NPC_FLAME_SPHERE_3:
                summon->AI()->SetGUID(_flameSphereTargetGUID);
                break;
            case NPC_JEDOGA_CONTROLLER:
                summon->CastSpell(me, SPELL_BEAM_VISUAL);
                break;
            default:
                return;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (_initialCheckTimer)
        {
            if (_initialCheckTimer <= diff)
            {
                CheckSpheres();
                _initialCheckTimer = 0;
            }
            else
                _initialCheckTimer -= diff;
        }

        if (me->HasAura(SPELL_VANISH))
        {
            if (me->GetThreatManager().IsThreatListEmpty(true))
            {
                EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
                return;
            }
        }
        else
        {
            if (!UpdateVictim())
                return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BLOODTHIRST:
                    DoCast(me, SPELL_BLOODTHIRST);
                    events.ScheduleEvent(EVENT_BLOODTHIRST, 10s);
                    break;
                case EVENT_CONJURE_FLAME_SPHERES:
                    // random target?
                    if (Unit* victim = me->GetVictim())
                    {
                        _flameSphereTargetGUID = victim->GetGUID();
                        DoCast(victim, SPELL_CONJURE_FLAME_SPHERE);
                    }
                    events.ScheduleEvent(EVENT_CONJURE_FLAME_SPHERES, 30s, 35s);
                    break;
                case EVENT_VANISH:
                {
                    if (me->GetThreatManager().GetThreatListSize() > 1)
                    {
                        if (Unit* embraceTarget = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                            _embraceTargetGUID = embraceTarget->GetGUID();
                        Talk(SAY_VANISH);
                        DoCast(me, SPELL_VANISH);
                        events.DelayEvents(500ms);
                        events.ScheduleEvent(EVENT_START_FEEDING, 2s);
                    }
                    events.ScheduleEvent(EVENT_VANISH, 25s, 35s);
                    break;
                }
                case EVENT_START_FEEDING:
                    me->RemoveAurasDueToSpell(SPELL_VANISH);
                    if (Unit* embraceTarget = GetEmbraceTarget())
                    {
                        DoCast(embraceTarget, SPELL_SHADOWSTEP);
                        DoCast(embraceTarget, SPELL_EMBRACE_OF_THE_VAMPYR);
                        Talk(SAY_FEED);
                        events.ScheduleEvent(EVENT_DONE_FEEDING, 20s);
                    }
                    break;
                case EVENT_DONE_FEEDING:
                    _embraceTargetGUID.Clear();
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

    void DamageTaken(Unit* /*doneBy*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        Unit* embraceTarget = GetEmbraceTarget();

        if (embraceTarget && embraceTarget->IsAlive())
        {
            _embraceTakenDamage += damage;
            if (_embraceTakenDamage > DUNGEON_MODE<uint32>(DATA_EMBRACE_DMG, H_DATA_EMBRACE_DMG))
            {
                _embraceTargetGUID.Clear();
                me->CastStop();
            }
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() != TYPEID_PLAYER)
            return;

        if (victim->GetGUID() == _embraceTargetGUID)
            _embraceTargetGUID.Clear();

        Talk(SAY_SLAY);
    }

    bool CheckSpheres()
    {
        for (uint8 i = 0; i < 2; ++i)
            if (!instance->GetData(DATA_SPHERE_1 + i))
                return false;

        RemovePrison();
        return true;
    }

    Unit* GetEmbraceTarget()
    {
        if (_embraceTargetGUID)
            return ObjectAccessor::GetUnit(*me, _embraceTargetGUID);

        return nullptr;
    }

    void RemovePrison()
    {
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
        summons.DespawnEntry(NPC_JEDOGA_CONTROLLER);
        me->RemoveAurasDueToSpell(SPELL_BEAM_VISUAL);
        me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), PrinceTaldaramGroundPositionZ, me->GetOrientation());
        DoCast(SPELL_HOVER_FALL);
        me->SetDisableGravity(false);
        me->GetMotionMaster()->MoveLand(0, me->GetHomePosition());
        Talk(SAY_WARNING);
        if (GameObject* platform = instance->GetGameObject(DATA_PRINCE_TALDARAM_PLATFORM))
            instance->HandleGameObject(platform->GetGUID(), true);
    }

private:
    ObjectGuid _flameSphereTargetGUID;
    ObjectGuid _embraceTargetGUID;
    uint32 _embraceTakenDamage;
    uint32 _initialCheckTimer;
};

// 30106, 31686, 31687 - Flame Sphere
struct npc_prince_taldaram_flame_sphere : public ScriptedAI
{
    npc_prince_taldaram_flame_sphere(Creature* creature) : ScriptedAI(creature)
    {
    }

    void Reset() override
    {
        DoCast(me, SPELL_FLAME_SPHERE_SPAWN_EFFECT, true);
        DoCast(me, SPELL_FLAME_SPHERE_VISUAL, true);

        _flameSphereTargetGUID.Clear();
        _events.Reset();
        _events.ScheduleEvent(EVENT_START_MOVE, 3s);
        _events.ScheduleEvent(EVENT_DESPAWN, 13s);
    }

    void SetGUID(ObjectGuid const& guid, int32 /*id*/) override
    {
        _flameSphereTargetGUID = guid;
    }

    void JustEngagedWith(Unit* /*who*/) override { }
    void MoveInLineOfSight(Unit* /*who*/) override { }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_START_MOVE:
                {
                    DoCast(me, SPELL_FLAME_SPHERE_PERIODIC, true);

                    /// @todo: find correct values
                    float angleOffset = 0.0f;
                    float distOffset = PrinceTaldaramSphereDistance;

                    switch (me->GetEntry())
                    {
                        case NPC_FLAME_SPHERE_1:
                            break;
                        case NPC_FLAME_SPHERE_2:
                            angleOffset = PrinceTaldaramSphereAngleOffset;
                            break;
                        case NPC_FLAME_SPHERE_3:
                            angleOffset = -PrinceTaldaramSphereAngleOffset;
                            break;
                        default:
                            return;
                    }

                    Unit* sphereTarget = ObjectAccessor::GetUnit(*me, _flameSphereTargetGUID);
                    if (!sphereTarget)
                        return;

                    float angle = me->GetAbsoluteAngle(sphereTarget) + angleOffset;
                    float x = me->GetPositionX() + distOffset * std::cos(angle);
                    float y = me->GetPositionY() + distOffset * std::sin(angle);

                    /// @todo: correct speed
                    me->GetMotionMaster()->MovePoint(0, x, y, me->GetPositionZ());
                    break;
                }
                case EVENT_DESPAWN:
                    DoCast(me, SPELL_FLAME_SPHERE_DEATH_EFFECT, true);
                    me->DespawnOrUnsummon(1s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    ObjectGuid _flameSphereTargetGUID;
};

// 193093, 193094 - Ancient Nerubian Device
struct go_prince_taldaram_sphere : public GameObjectAI
{
    go_prince_taldaram_sphere(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

    InstanceScript* instance;

    bool OnGossipHello(Player* /*player*/) override
    {
        Creature* princeTaldaram = instance->GetCreature(DATA_PRINCE_TALDARAM);
        if (princeTaldaram && princeTaldaram->IsAlive())
        {
            me->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            me->SetGoState(GO_STATE_ACTIVE);

            switch (me->GetEntry())
            {
                case GO_SPHERE_1:
                    instance->SetData(DATA_SPHERE_1, IN_PROGRESS);
                    princeTaldaram->AI()->Talk(SAY_1);
                    break;
                case GO_SPHERE_2:
                    instance->SetData(DATA_SPHERE_2, IN_PROGRESS);
                    princeTaldaram->AI()->Talk(SAY_1);
                    break;
            }

            ENSURE_AI(boss_prince_taldaram, princeTaldaram->AI())->CheckSpheres();
        }
        return true;
    }
};

// 55931 - Conjure Flame Sphere
class spell_prince_taldaram_conjure_flame_sphere : public SpellScript
{
    PrepareSpellScript(spell_prince_taldaram_conjure_flame_sphere);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FLAME_SPHERE_SUMMON_1, SPELL_FLAME_SPHERE_SUMMON_2, SPELL_FLAME_SPHERE_SUMMON_3 });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_FLAME_SPHERE_SUMMON_1, true);

        if (caster->GetMap()->IsHeroic())
        {
            caster->CastSpell(caster, SPELL_FLAME_SPHERE_SUMMON_2, true);
            caster->CastSpell(caster, SPELL_FLAME_SPHERE_SUMMON_3, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_prince_taldaram_conjure_flame_sphere::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 55895, 59511, 59512 - Flame Sphere Summon
class spell_prince_taldaram_flame_sphere_summon : public SpellScript
{
    PrepareSpellScript(spell_prince_taldaram_flame_sphere_summon);

    void SetDest(SpellDestination& dest)
    {
        Position offset = { 0.0f, 0.0f, 5.5f, 0.0f };
        dest.RelocateOffset(offset);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_prince_taldaram_flame_sphere_summon::SetDest, EFFECT_0, TARGET_DEST_CASTER);
    }
};

void AddSC_boss_taldaram()
{
    RegisterAhnKahetCreatureAI(boss_prince_taldaram);
    RegisterAhnKahetCreatureAI(npc_prince_taldaram_flame_sphere);
    RegisterAhnKahetGameObjectAI(go_prince_taldaram_sphere);
    RegisterSpellScript(spell_prince_taldaram_conjure_flame_sphere);
    RegisterSpellScript(spell_prince_taldaram_flame_sphere_summon);
}
