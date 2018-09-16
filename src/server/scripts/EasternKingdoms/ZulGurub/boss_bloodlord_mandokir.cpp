/*
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

#include "ScriptMgr.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "zulgurub.h"

enum Yells
{
    SAY_AGGRO               = 0,
    SAY_PLAYER_KILL         = 1,
    SAY_SUMMON_OHGAN        = 2,
    EMOTE_DEVASTATING_SLAM  = 3,
    SAY_REANIMATE_OHGAN     = 4,
    EMOTE_FRENZY            = 5,
    SAY_FRENZY              = 6,
    SAY_DEATH               = 7
};

enum Spells
{
    // Bloodlord Mandokir
    SPELL_BLOODLORD_AURA            = 96480,
    SPELL_SUMMON_OHGAN              = 96717,
    SPELL_REANIMATE_OHGAN           = 96724,
    SPELL_DECAPITATE                = 96682,
    SPELL_BLOODLETTING              = 96776,
    SPELL_BLOODLETTING_DAMAGE       = 96777,
    SPELL_BLOODLETTING_HEAL         = 96778,
    SPELL_FRENZY                    = 96800,
    SPELL_LEVEL_UP                  = 96662,
    SPELL_DEVASTATING_SLAM          = 96740,
    SPELL_DEVASTATING_SLAM_TRIGGER  = 96761,
    SPELL_DEVASTATING_SLAM_DAMAGE   = 97385,
    SPELL_SPIRIT_VENGEANCE_CANCEL   = 96821,

    // Chained Spirit
    SPELL_REVIVE                    = 96484,

    // Ohgan
    SPELL_OHGAN_HEART_VISUAL        = 96727,
    SPELL_PERMANENT_FEIGN_DEATH     = 96733,
    SPELL_CLEAR_ALL                 = 28471,
    SPELL_OHGAN_ORDERS              = 96721,
    SPELL_OHGAN_ORDERS_TRIGGER      = 96722
};

enum Events
{
    // Bloodlord Mandokir
    EVENT_SUMMON_OHGAN = 1,
    EVENT_TALK_SUMMON_OHGAN,
    EVENT_DECAPITATE,
    EVENT_BLOODLETTING,
    EVENT_REANIMATE_OHGAN,
    EVENT_REANIMATE_OHGAN_COOLDOWN,
    EVENT_DEVASTATING_SLAM,

    // Ohgan
    EVENT_OHGANS_ORDERS,
    EVENT_ATTACK_PLAYERS,
};

enum Action
{
    // Bloodlord Mandokir
    ACTION_OHGAN_IS_DEATH       = 1,
    ACTION_START_REVIVE         = 2,

    // Chained Spirit
    ACTION_REVIVE               = 1
};

enum Misc
{
    POINT_START_REVIVE                  = 1,
    DATA_OHGANOT_SO_FAST                = 5762,
    FACTION_TEMPLATE_CHAINED_SPIRITS    = 1665
};

enum SummonGroups
{
    SUMMON_GROUP_CHAINED_SPIRIT = 0
};

struct boss_bloodlord_mandokir : public BossAI
{
    boss_bloodlord_mandokir(Creature* creature) : BossAI(creature, DATA_BLOODLORD_MANDOKIR) { }

    void Reset() override
    {
        _Reset();
        me->SummonCreatureGroup(SUMMON_GROUP_CHAINED_SPIRIT);
        _ohganotSoFast = true;
        _reanimateOhganCooldown = false;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        DoCastAOE(SPELL_BLOODLORD_AURA);
        events.ScheduleEvent(EVENT_DECAPITATE, 10s);
        events.ScheduleEvent(EVENT_BLOODLETTING, 15s);
        events.ScheduleEvent(EVENT_SUMMON_OHGAN, 20s);
        events.ScheduleEvent(EVENT_DEVASTATING_SLAM, 25s);

        for (ObjectGuid guid : summons)
            if (Creature* creature = ObjectAccessor::GetCreature(*me, guid))
                if (creature->GetEntry() == NPC_CHAINED_SPIRIT)
                    creature->SetFaction(FACTION_TEMPLATE_CHAINED_SPIRITS);
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastAOE(SPELL_SPIRIT_VENGEANCE_CANCEL, true);
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLOODLETTING);
        Talk(SAY_DEATH);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLOODLETTING);
        DoCastAOE(SPELL_SPIRIT_VENGEANCE_CANCEL, true);
        _DespawnAtEvade();
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
        {
            Talk(SAY_PLAYER_KILL);
            DoCastSelf(SPELL_LEVEL_UP, true);
            _reviveGUID = victim->GetGUID();
            DoAction(ACTION_START_REVIVE);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        if (summon->GetEntry() == NPC_DEVASTATING_SLAM)
        {
            DoCastSelf(SPELL_DEVASTATING_SLAM);
            me->SetFacingToObject(summon);

            float angle = me->GetAngle(summon);

            // 31 casts in total - 11 in the center line and 10 on the outer lines
            for (uint8 i = 1; i < 12; i++)
            {
                float angleOffset = i > 1 ? -0.3f : 0.0f;

                for (uint8 j = 0; j < (i > 1 ? 3 : 1); j++)
                {
                    float x = me->GetPositionX() + cos(angle + angleOffset) * (i * 6.0f);
                    float y = me->GetPositionY() + sin(angle + angleOffset) * (i * 6.0f);
                    float z = me->GetPositionZ();
                    angleOffset += 0.3f;
                    me->CastSpell(x, y, z, SPELL_DEVASTATING_SLAM_DAMAGE, true);
                }
            }
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(20, damage) && !me->HasAura(SPELL_FRENZY))
        {
            DoCast(me, SPELL_FRENZY, true);
            Talk(SAY_FRENZY);
            Talk(EMOTE_FRENZY);
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_OHGAN_IS_DEATH:
                events.ScheduleEvent(EVENT_REANIMATE_OHGAN, 4s);
                _ohganotSoFast = false;
                break;
            case ACTION_START_REVIVE:
            {
                std::list<Creature*> creatures;
                GetCreatureListWithEntryInGrid(creatures, me, NPC_CHAINED_SPIRIT, 200.0f);
                creatures.remove_if(Trinity::AnyDeadUnitCheck());
                creatures.remove_if(Trinity::UnitAuraCheck(true, SPELL_OHGAN_ORDERS_TRIGGER));
                Trinity::Containers::RandomResize(creatures, 1);
                if (creatures.empty())
                    return;

                for (Creature* chainedSpirit : creatures)
                {
                    chainedSpirit->AI()->SetGUID(_reviveGUID);
                    chainedSpirit->AI()->DoAction(ACTION_REVIVE);
                    _reviveGUID.Clear();
                }
                break;
            }
            default:
                break;

        }
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_OHGANOT_SO_FAST)
            return _ohganotSoFast;

        return 0;
    }

    void SetGUID(ObjectGuid const& guid, int32 /*id = 0 **/) override
    {
        _reviveGUID = guid;
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
                case EVENT_SUMMON_OHGAN:
                    me->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, 0);
                    DoCast(me, SPELL_SUMMON_OHGAN, true);
                    events.ScheduleEvent(EVENT_TALK_SUMMON_OHGAN, 2s + 400ms);
                    break;
                case EVENT_TALK_SUMMON_OHGAN:
                    Talk(SAY_SUMMON_OHGAN);
                    if (Creature* ohgan = instance->GetCreature(DATA_OHGAN))
                        ohgan->HandleEmoteCommand(EMOTE_ONESHOT_MOUNT_SPECIAL);
                    break;
                case EVENT_DECAPITATE:
                    DoCastAOE(SPELL_DECAPITATE);
                    events.Repeat(me->HasAura(SPELL_FRENZY) ? 17s + 500ms : 35s);
                    break;
                case EVENT_BLOODLETTING:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                        DoCast(target, SPELL_BLOODLETTING, true);

                    events.Repeat(25s);
                    break;
                case EVENT_REANIMATE_OHGAN:
                    if (_reanimateOhganCooldown)
                        events.Repeat(1s);
                    else
                    {
                        DoCastAOE(SPELL_REANIMATE_OHGAN);
                        Talk(SAY_REANIMATE_OHGAN);
                        // Cooldown
                        _reanimateOhganCooldown = true;
                        events.ScheduleEvent(EVENT_REANIMATE_OHGAN_COOLDOWN, 20s);
                    }
                    break;
                case EVENT_REANIMATE_OHGAN_COOLDOWN:
                    _reanimateOhganCooldown = false;
                    break;
                case EVENT_DEVASTATING_SLAM:
                    DoCastAOE(SPELL_DEVASTATING_SLAM_TRIGGER);
                    events.Repeat(30s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _ohganotSoFast;
    bool _reanimateOhganCooldown;
    ObjectGuid _reviveGUID;
};

struct npc_mandokir_ohgan : public ScriptedAI
{
    npc_mandokir_ohgan(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        _allowPlayerCombat = false;
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        _events.ScheduleEvent(EVENT_OHGANS_ORDERS, 4s + 500ms);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (damage >= me->GetHealth())
        {
            damage = 0;
            me->AttackStop();
            me->SetHealth(0);
            me->SetTarget(ObjectGuid::Empty);
            DoCast(me, SPELL_CLEAR_ALL, true);
            DoCast(me, SPELL_PERMANENT_FEIGN_DEATH);

            if (Creature* mandokir = _instance->GetCreature(DATA_BLOODLORD_MANDOKIR))
                mandokir->AI()->DoAction(ACTION_OHGAN_IS_DEATH);
        }
    }

    void KilledUnit(Unit* victim) override
    {
        if (Creature* creature = victim->ToCreature())
        {
            if (creature->GetEntry() == NPC_CHAINED_SPIRIT)
            {
                _events.ScheduleEvent(EVENT_ATTACK_PLAYERS, 1s);
                DoCastAOE(SPELL_OHGAN_ORDERS);
            }
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (target && spell->Id == SPELL_OHGAN_ORDERS)
            _events.CancelEvent(EVENT_ATTACK_PLAYERS);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && _allowPlayerCombat)
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_OHGANS_ORDERS:
                    DoCastAOE(SPELL_OHGAN_ORDERS);
                    break;
                case EVENT_ATTACK_PLAYERS:
                    _allowPlayerCombat = true;
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat();
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    bool _allowPlayerCombat;
};

struct npc_mandokir_chained_spirit : public PassiveAI
{
    npc_mandokir_chained_spirit(Creature* creature) : PassiveAI(creature), _instance(me->GetInstanceScript()) { }

    void Reset() override
    {
        me->AddUnitMovementFlag(MOVEMENTFLAG_HOVER);
        _revivePlayerGUID.Clear();
    }

    void SetGUID(ObjectGuid const& guid, int32 /*id = 0 */) override
    {
        _revivePlayerGUID = guid;
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_REVIVE)
        {
            Position pos;
            if (Player* target = ObjectAccessor::GetPlayer(*me, _revivePlayerGUID))
            {
                target->GetNearPoint(me, pos.m_positionX, pos.m_positionY, pos.m_positionZ, 0.0f, 5.0f, target->GetAngle(me));
                me->GetMotionMaster()->MovePoint(POINT_START_REVIVE, pos);
            }
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE || !_revivePlayerGUID)
            return;

        if (pointId == POINT_START_REVIVE)
        {
            if (Player* target = ObjectAccessor::GetPlayer(*me, _revivePlayerGUID))
                DoCast(target, SPELL_REVIVE);

            me->DespawnOrUnsummon(2s);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        // We died before we could revive our player, so let another spirit do the job
        if (!_revivePlayerGUID.IsEmpty())
        {
            if (Player* target = ObjectAccessor::GetPlayer(*me, _revivePlayerGUID))
            {
                if (Creature* mandokir = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_BLOODLORD_MANDOKIR)))
                {
                    mandokir->GetAI()->SetGUID(target->GetGUID());
                    mandokir->GetAI()->DoAction(ACTION_START_REVIVE);
                }
            }
        }
        me->DespawnOrUnsummon(4s);
    }

    void UpdateAI(uint32 /*diff*/) override { }

private:
    InstanceScript * _instance;
    ObjectGuid _revivePlayerGUID;
};

class NonVictimTargetSelector
{
    public:
        NonVictimTargetSelector(Creature* me) : _me(me) { }

        bool operator() (WorldObject* target)
        {
            if (Unit* victim = _me->GetVictim())
                return victim == target;

            return true;
        }

        Creature* _me;
};

class spell_mandokir_decapitate : public SpellScript
{
    PrepareSpellScript(spell_mandokir_decapitate);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(NonVictimTargetSelector(GetCaster()->ToCreature()));

        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Player* target = GetHitPlayer())
            caster->CastSpell(target, uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mandokir_decapitate::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_mandokir_decapitate::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_mandokir_bloodletting : public AuraScript
{
    PrepareAuraScript(spell_mandokir_bloodletting);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_BLOODLETTING_DAMAGE,
                SPELL_BLOODLETTING_HEAL
            });
    }

    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();
        Unit* caster = GetCaster();
        if (!caster)
            return;

        int32 damage = std::max<int32>(7500, target->CountPctFromCurHealth(aurEff->GetAmount()));

        caster->CastCustomSpell(target, SPELL_BLOODLETTING_DAMAGE, &damage, 0, 0, true);
        target->CastCustomSpell(caster, SPELL_BLOODLETTING_HEAL, &damage, 0, 0, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_mandokir_bloodletting::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_mandokir_spirit_vengeance_cancel : public SpellScript
{
    PrepareSpellScript(spell_mandokir_spirit_vengeance_cancel);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Player* target = GetHitPlayer())
            target->RemoveAura(uint32(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mandokir_spirit_vengeance_cancel::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnEffectHitTarget += SpellEffectFn(spell_mandokir_spirit_vengeance_cancel::HandleScript, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

class spell_mandokir_devastating_slam : public SpellScript
{
    PrepareSpellScript(spell_mandokir_devastating_slam);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(NonVictimTargetSelector(GetCaster()->ToCreature()));

        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleSummon(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetHitUnit()->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].TriggerSpell, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mandokir_devastating_slam::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_mandokir_devastating_slam::HandleSummon, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
    }
};

class spell_mandokir_ohgan_orders : public SpellScript
{
    PrepareSpellScript(spell_mandokir_ohgan_orders);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* target = GetHitUnit())
            caster->CastSpell(target, uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mandokir_ohgan_orders::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_mandokir_ohgan_orders::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_mandokir_ohgan_orders_trigger : public SpellScript
{
    PrepareSpellScript(spell_mandokir_ohgan_orders_trigger);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        // Enabling melee attacks to kill the spirits
        caster->ClearUnitState(UNIT_STATE_CASTING);

        if (Creature* creature = caster->ToCreature())
            if (creature->IsAIEnabled)
                creature->AI()->AttackStart(GetHitUnit());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mandokir_ohgan_orders_trigger::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_mandokir_reanimate_ohgan : public SpellScript
{
    PrepareSpellScript(spell_mandokir_reanimate_ohgan);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
        {
            target->RemoveAura(SPELL_PERMANENT_FEIGN_DEATH);
            target->CastSpell(target, SPELL_OHGAN_HEART_VISUAL, true);
            target->CastSpell(target, SPELL_OHGAN_ORDERS, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mandokir_reanimate_ohgan::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_clear_all : public SpellScript
{
    PrepareSpellScript(spell_clear_all);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->RemoveAllAurasOnDeath();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_clear_all::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class achievement_ohganot_so_fast : public AchievementCriteriaScript
{
   public:
       achievement_ohganot_so_fast() : AchievementCriteriaScript("achievement_ohganot_so_fast") { }

       bool OnCheck(Player* /*player*/, Unit* target)
       {
           return target && target->GetAI()->GetData(DATA_OHGANOT_SO_FAST);
       }
};

void AddSC_boss_mandokir()
{
    RegisterZulGurubCreatureAI(boss_bloodlord_mandokir);
    RegisterZulGurubCreatureAI(npc_mandokir_ohgan);
    RegisterZulGurubCreatureAI(npc_mandokir_chained_spirit);
    RegisterSpellScript(spell_mandokir_decapitate);
    RegisterAuraScript(spell_mandokir_bloodletting);
    RegisterSpellScript(spell_mandokir_spirit_vengeance_cancel);
    RegisterSpellScript(spell_mandokir_devastating_slam);
    RegisterSpellScript(spell_mandokir_ohgan_orders);
    RegisterSpellScript(spell_mandokir_ohgan_orders_trigger);
    RegisterSpellScript(spell_mandokir_reanimate_ohgan);
    RegisterSpellScript(spell_clear_all);
    new achievement_ohganot_so_fast();
}
