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
 * Combat timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "utgarde_keep.h"

enum KelesethTexts
{
    // Prince Keleseth
    SAY_AGGRO                         = 0,
    SAY_FROST_TOMB                    = 1,
    SAY_SLAY                          = 2,
    SAY_SUMMON_SKELETONS              = 3,
    SAY_DEATH                         = 4,
    EMOTE_FROST_TOMB                  = 5,

    // Vrykul Skeleton
    EMOTE_RISES                       = 0
};

enum KelesethSpells
{
    // Prince Keleseth
    SPELL_SHADOW_BOLT                 = 43667,
    SPELL_FROST_TOMB                  = 42672,

    // Vrykul Skeleton
    SPELL_DECREPIFY                   = 42702,
    SPELL_BONE_ARMOR                  = 59386,
    SPELL_SHADOW_FISSURE              = 50657,
    SPELL_FULL_HEAL                   = 17683,
    SPELL_INSTAKILL_SELF              = 29878,

    // Frost Tomb
    SPELL_FROST_TOMB_CHANNEL          = 48400,

    // Scripts
    SPELL_FROST_TOMB_SUMMON           = 42714
};

enum KelesethEvents
{
    // Prince Keleseth
    EVENT_SHADOW_BOLT                 = 1,
    EVENT_FROST_TOMB,
    EVENT_SUMMON_SKELETONS,

    // Vrykul Skeleton
    EVENT_ATTACK,
    EVENT_DECREPIFY,
    EVENT_BONE_ARMOR,
    EVENT_RESURRECT_1,
    EVENT_RESURRECT_2
};

enum KelesethMisc
{
    SUMMON_GROUP_SKELETONS            = 0,
    DATA_ON_THE_ROCKS                 = 1,
    ACTION_INSTAKILL_SELF             = 0,
    NPC_SKELETON                      = 23970
};

// 23953 - Prince Keleseth
struct boss_keleseth : public BossAI
{
    boss_keleseth(Creature* creature) : BossAI(creature, DATA_PRINCE_KELESETH), _onTheRocks(true) { }

    void Reset() override
    {
        _Reset();

        _onTheRocks = true;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_SHADOW_BOLT, 0s);
        events.ScheduleEvent(EVENT_FROST_TOMB, 14s, 19s);
        events.ScheduleEvent(EVENT_SUMMON_SKELETONS, 5s);

        /// @todo: Should he really call for help? Check this
        me->CallForHelp(50.0f);
    }

    void KillSkeletons()
    {
        std::vector<Creature*> skeletons;
        GetCreatureListWithEntryInGrid(skeletons, me, NPC_SKELETON, 200.0f);
        for (Creature* skeleton : skeletons)
            skeleton->AI()->DoAction(ACTION_INSTAKILL_SELF);
    }

    // Do not engage or despawn summons, killed by spells
    void JustSummoned(Creature* /*summon*/) override { }

    void SetData(uint32 data, uint32 value) override
    {
        if (data == DATA_ON_THE_ROCKS)
            _onTheRocks = value != 0;
    }

    uint32 GetData(uint32 data) const override
    {
        if (data == DATA_ON_THE_ROCKS)
            return _onTheRocks;

        return 0;
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        KillSkeletons();
        BossAI::EnterEvadeMode(why);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        KillSkeletons();
        Talk(SAY_DEATH);
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
                case EVENT_SHADOW_BOLT:
                    DoCastVictim(SPELL_SHADOW_BOLT);
                    events.Repeat(2s, 3s);
                    break;
                case EVENT_FROST_TOMB:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true, true, -SPELL_FROST_TOMB_CHANNEL))
                    {
                        Talk(SAY_FROST_TOMB, target);
                        Talk(EMOTE_FROST_TOMB, target);
                        DoCast(target, SPELL_FROST_TOMB);
                    }
                    events.Repeat(14s, 19s);
                    break;
                case EVENT_SUMMON_SKELETONS:
                    Talk(SAY_SUMMON_SKELETONS);
                    me->SummonCreatureGroup(SUMMON_GROUP_SKELETONS);
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
    bool _onTheRocks;
};

// 23970 - Vrykul Skeleton
struct npc_vrykul_skeleton : public ScriptedAI
{
    npc_vrykul_skeleton(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(15, true);
    }

    void JustAppeared() override
    {
        _events.ScheduleEvent(EVENT_ATTACK, 7s);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_DECREPIFY, 4s, 6s);
        if (IsHeroic())
            _events.ScheduleEvent(EVENT_BONE_ARMOR, 10s, 15s);
    }

    void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        // Creature is unkillable by default. But allow to kill self with spell
        if (damage >= me->GetHealth() && attacker != me)
        {
            damage = me->GetHealth() - 1;

            // There are some issues with pets
            // they will still attack. I would say it is a PetAI bug
            if (!me->HasUnitFlag(UNIT_FLAG_UNINTERACTIBLE))
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                me->SetStandState(UNIT_STAND_STATE_DEAD);

                _events.Reset();
                _events.ScheduleEvent(EVENT_RESURRECT_1, 18s, 22s);
            }
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_INSTAKILL_SELF)
        {
            /// @todo: Spell doesn't work if creature is in evade mode
            DoCastSelf(SPELL_INSTAKILL_SELF, true);
            me->KillSelf();
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ATTACK:
                        DoZoneInCombat();
                        break;
                    default:
                        break;
                }
            }
            return;
        }

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_DECREPIFY:
                    DoCastVictim(SPELL_DECREPIFY);
                    _events.Repeat(1s, 5s);
                    break;
                case EVENT_BONE_ARMOR:
                    /// It is unclear how exactly this ability is used
                    if (roll_chance_i(50))
                        DoCastSelf(SPELL_BONE_ARMOR);
                    _events.Repeat(20s, 30s);
                    break;
                case EVENT_RESURRECT_1:
                    DoCastSelf(SPELL_SHADOW_FISSURE);
                    DoCastSelf(SPELL_FULL_HEAL);
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    Talk(EMOTE_RISES);
                    _events.ScheduleEvent(EVENT_RESURRECT_2, 1s);
                    break;
                case EVENT_RESURRECT_2:
                    me->SetReactState(REACT_AGGRESSIVE);
                    _events.ScheduleEvent(EVENT_DECREPIFY, 4s, 6s);
                    if (IsHeroic())
                        _events.ScheduleEvent(EVENT_BONE_ARMOR, 10s, 15s);
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
    EventMap _events;
};

// 23965 - Frost Tomb
struct npc_frost_tomb : public ScriptedAI
{
    npc_frost_tomb(Creature* creature) : ScriptedAI(creature), _isKilled(false), _instance(creature->GetInstanceScript()) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        if (TempSummon* summon = me->ToTempSummon())
            if (Unit* summoner = summon->GetSummonerUnit())
                DoCast(summoner, SPELL_FROST_TOMB_CHANNEL);
    }

    void DamageTaken(Unit* /*who*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth())
        {
            damage = me->GetHealth() -1;

            if (_isKilled)
                return;

            _isKilled = true;

            _scheduler.Schedule(0s, [this](TaskContext task)
            {
                switch (task.GetRepeatCounter())
                {
                    case 0:
                        if (Creature* keleseth = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_PRINCE_KELESETH)))
                            keleseth->AI()->SetData(DATA_ON_THE_ROCKS, false);
                        me->InterruptNonMeleeSpells(false);
                        task.Repeat(1s);
                        break;
                    case 1:
                        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                        task.Repeat(1s);
                        break;
                    case 2:
                        me->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    bool _isKilled;
    TaskScheduler _scheduler;
    InstanceScript* _instance;
};

// 42672 - Frost Tomb
class spell_keleseth_frost_tomb_periodic : public AuraScript
{
    PrepareAuraScript(spell_keleseth_frost_tomb_periodic);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FROST_TOMB_SUMMON });
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        if (aurEff->GetTickNumber() == 1)
            GetTarget()->CastSpell(GetTarget(), SPELL_FROST_TOMB_SUMMON, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_keleseth_frost_tomb_periodic::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 48400 - Frost Tomb
class spell_keleseth_frost_tomb_channel : public AuraScript
{
    PrepareAuraScript(spell_keleseth_frost_tomb_channel);

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH)
            if (Unit* caster = GetCaster())
                if (caster->IsAlive())
                    if (Creature* creature = caster->ToCreature())
                        creature->DespawnOrUnsummon(1s);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_keleseth_frost_tomb_channel::AfterRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

class achievement_on_the_rocks : public AchievementCriteriaScript
{
    public:
        achievement_on_the_rocks() : AchievementCriteriaScript("achievement_on_the_rocks") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            // todo: migrate to worldstate 3895 (worldstateexpression 6312)
            return target && target->GetAI() && target->GetAI()->GetData(DATA_ON_THE_ROCKS);
        }
};

void AddSC_boss_keleseth()
{
    RegisterUtgardeKeepCreatureAI(boss_keleseth);
    RegisterUtgardeKeepCreatureAI(npc_frost_tomb);
    RegisterUtgardeKeepCreatureAI(npc_vrykul_skeleton);
    RegisterSpellScript(spell_keleseth_frost_tomb_periodic);
    RegisterSpellScript(spell_keleseth_frost_tomb_channel);
    new achievement_on_the_rocks();
}
