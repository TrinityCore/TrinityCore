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
#include "black_temple.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Says
{
    SAY_INTRO      = 0,
    SAY_AGGRO      = 1,
    SAY_SLAY       = 2,
    SAY_INCINERATE = 3,
    SAY_BLOSSOM    = 4,
    SAY_CRUSHING   = 5,
    SAY_DEATH      = 6
};

enum Spells
{
    //Teron
    SPELL_INCINERATE                 = 40239,
    SPELL_CRUSHING_SHADOWS           = 40243,
    SPELL_SHADOW_OF_DEATH            = 40251,
    SPELL_SHADOW_OF_DEATH_REMOVE     = 41999,
    SPELL_BERSERK                    = 45078,
    SPELL_SUMMON_DOOM_BLOSSOM        = 40188,

    //Doom Blossom
    SPELL_SUMMON_BLOSSOM_MOVE_TARGET = 40186,
    SPELL_SHADOWBOLT                 = 40185,

    //Shadow Construct
    SPELL_ATROPHY                    = 40327,

    //Player
    SPELL_SUMMON_SPIRIT              = 40266,
    SPELL_SPIRITUAL_VENGEANCE        = 40268,
    SPELL_POSSESS_SPIRIT_IMMUNE      = 40282,
    SPELL_SUMMON_SKELETRON_1         = 40270,
    SPELL_SUMMON_SKELETRON_2         = 41948,
    SPELL_SUMMON_SKELETRON_3         = 41949,
    SPELL_SUMMON_SKELETRON_4         = 41950,

    //Vengeful Spirit
    SPELL_SPIRIT_STRIKE              = 40325,
    SPELL_SPIRIT_CHAINS              = 40175,
    SPELL_SPIRIT_VOLLEY              = 40314,
    SPELL_SPIRIT_SHIELD              = 40322,
    SPELL_SPIRIT_LANCE               = 40157
};

enum Npcs
{
    NPC_DOOM_BLOSSOM      = 23123,
    NPC_SHADOWY_CONSTRUCT = 23111,
    NPC_VENGEFUL_SPIRIT   = 23109 //Npc controlled by player
};

enum Events
{
    EVENT_ENRAGE = 1,
    EVENT_INCINERATE,
    EVENT_SUMMON_DOOM_BLOSSOM,
    EVENT_SHADOW_DEATH,
    EVENT_CRUSHING_SHADOWS
};

enum Actions
{
    ACTION_START_INTRO = 1
};

uint32 const SkeletronSpells[4] =
{
    SPELL_SUMMON_SKELETRON_1,
    SPELL_SUMMON_SKELETRON_2,
    SPELL_SUMMON_SKELETRON_3,
    SPELL_SUMMON_SKELETRON_4
};

struct boss_teron_gorefiend : public BossAI
{
    boss_teron_gorefiend(Creature* creature) : BossAI(creature, DATA_TERON_GOREFIEND) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_ENRAGE, 10min);
        events.ScheduleEvent(EVENT_INCINERATE, 12s);
        events.ScheduleEvent(EVENT_SUMMON_DOOM_BLOSSOM, 8s);
        events.ScheduleEvent(EVENT_SHADOW_DEATH, 8s);
        events.ScheduleEvent(EVENT_CRUSHING_SHADOWS, 18s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        DoCast(SPELL_SHADOW_OF_DEATH_REMOVE);
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_START_INTRO && me->IsAlive())
            Talk(SAY_INTRO);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        DoCast(SPELL_SHADOW_OF_DEATH_REMOVE);
        _JustDied();
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
                case EVENT_ENRAGE:
                    DoCast(SPELL_BERSERK);
                    break;
                case EVENT_INCINERATE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_INCINERATE);
                    Talk(SAY_INCINERATE);
                    events.Repeat(Seconds(12), Seconds(20));
                    break;
                case EVENT_SUMMON_DOOM_BLOSSOM:
                    DoCastSelf(SPELL_SUMMON_DOOM_BLOSSOM, true);
                    Talk(SAY_BLOSSOM);
                    events.Repeat(Seconds(30), Seconds(40));
                    break;
                case EVENT_SHADOW_DEATH:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 100.0f, true, true, -SPELL_SPIRITUAL_VENGEANCE))
                        DoCast(target, SPELL_SHADOW_OF_DEATH);
                    events.Repeat(Seconds(30), Seconds(35));
                    break;
                case EVENT_CRUSHING_SHADOWS:
                    DoCastSelf(SPELL_CRUSHING_SHADOWS, { SPELLVALUE_MAX_TARGETS, 5 });
                    Talk(SAY_CRUSHING);
                    events.Repeat(Seconds(18), Seconds(30));
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_doom_blossom : public NullCreatureAI
{
    npc_doom_blossom(Creature* creature) : NullCreatureAI(creature), _instance(me->GetInstanceScript()) { }

    void Reset() override
    {
        /* Workaround - Until SMSG_SET_PLAY_HOVER_ANIM be implemented */
        Position pos;
        pos.Relocate(me);
        pos.m_positionZ += 8.0f;
        me->GetMotionMaster()->MoveTakeoff(0, pos);

        DoCast(SPELL_SUMMON_BLOSSOM_MOVE_TARGET);
        _scheduler.CancelAll();
        DoZoneInCombat();
        _scheduler.Schedule(Seconds(12), [this](TaskContext shadowBolt)
        {
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                DoCast(target, SPELL_SHADOWBOLT);

            shadowBolt.Repeat(Seconds(2));
        });
    }

    void UpdateAI(uint32 diff) override
    {
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    InstanceScript* _instance;
};

struct npc_shadowy_construct : public ScriptedAI
{
    npc_shadowy_construct(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        if (_instance->GetBossState(DATA_TERON_GOREFIEND) != IN_PROGRESS)
        {
            me->DespawnOrUnsummon();
            return;
        }

        targetGUID.Clear();
        _scheduler.CancelAll();
        _scheduler.Schedule(Seconds(12), [this](TaskContext atrophy)
        {
            DoCastVictim(SPELL_ATROPHY);
            atrophy.Repeat(Seconds(10), Seconds(12));
        });
        _scheduler.Schedule(Milliseconds(200), [this](TaskContext checkPlayer)
        {
            if (Unit* target = ObjectAccessor::GetUnit(*me, targetGUID))
            {
                if (!target->IsAlive() || !me->CanCreatureAttack(target))
                    SelectNewTarget();
            }
            else
                SelectNewTarget();

            checkPlayer.Repeat(Seconds(1));
        });

        if (Creature* teron = _instance->GetCreature(DATA_TERON_GOREFIEND))
            teron->AI()->JustSummoned(me);

        SelectNewTarget();
    }

    void UpdateAI(uint32 diff) override
    {
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

    void SelectNewTarget()
    {
        if (Creature* teron = _instance->GetCreature(DATA_TERON_GOREFIEND))
        {
            Unit* target = teron->AI()->SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true, true, -SPELL_SPIRITUAL_VENGEANCE);
            // He should target Vengeful Spirits only if has no other player available
            if (!target)
                target = teron->AI()->SelectTarget(SelectTargetMethod::Random, 0);

            if (target)
            {
                ResetThreatList();
                AttackStart(target);
                AddThreat(target, 1000000.0f);
                targetGUID = target->GetGUID();
            }
        }
    }

private:
    TaskScheduler _scheduler;
    InstanceScript* _instance;
    ObjectGuid targetGUID;
};

// 40251 - Shadow of Death
class spell_teron_gorefiend_shadow_of_death : public AuraScript
{
    PrepareAuraScript(spell_teron_gorefiend_shadow_of_death);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SUMMON_SPIRIT,
            SPELL_POSSESS_SPIRIT_IMMUNE,
            SPELL_SPIRITUAL_VENGEANCE,
            SPELL_SUMMON_SKELETRON_1,
            SPELL_SUMMON_SKELETRON_2,
            SPELL_SUMMON_SKELETRON_3,
            SPELL_SUMMON_SKELETRON_4
        });
    }

    void Absorb(AuraEffect* /*aurEff*/, DamageInfo& /*dmgInfo*/, uint32& /*absorbAmount*/)
    {
        PreventDefaultAction();
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
        {
            Unit* target = GetTarget();
            target->CastSpell(target, SPELL_SUMMON_SPIRIT, true);

            for (uint8 i = 0; i < 4; ++i)
                target->CastSpell(target, SkeletronSpells[i], true);

            target->CastSpell(target, SPELL_POSSESS_SPIRIT_IMMUNE, true);
            target->CastSpell(target, SPELL_SPIRITUAL_VENGEANCE, true);
        }
    }

    void Register() override
    {
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_teron_gorefiend_shadow_of_death::Absorb, EFFECT_0);
        AfterEffectRemove += AuraEffectRemoveFn(spell_teron_gorefiend_shadow_of_death::OnRemove, EFFECT_1, SPELL_AURA_OVERRIDE_CLASS_SCRIPTS, AURA_EFFECT_HANDLE_REAL);
    }
};

// 40268 - Spiritual Vengeance
class spell_teron_gorefiend_spiritual_vengeance : public AuraScript
{
    PrepareAuraScript(spell_teron_gorefiend_spiritual_vengeance);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->KillSelf();
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_teron_gorefiend_spiritual_vengeance::OnRemove, EFFECT_0, SPELL_AURA_MOD_POSSESS, AURA_EFFECT_HANDLE_REAL);
    }
};

// 41999 - Shadow of Death Remove
class spell_teron_gorefiend_shadow_of_death_remove : public SpellScript
{
    PrepareSpellScript(spell_teron_gorefiend_shadow_of_death_remove);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SHADOW_OF_DEATH,
            SPELL_POSSESS_SPIRIT_IMMUNE,
            SPELL_SPIRITUAL_VENGEANCE
        });
    }

    void RemoveAuras()
    {
        Unit* target = GetHitUnit();

        target->RemoveAurasDueToSpell(SPELL_POSSESS_SPIRIT_IMMUNE);
        target->RemoveAurasDueToSpell(SPELL_SPIRITUAL_VENGEANCE);
        target->RemoveAurasDueToSpell(SPELL_SHADOW_OF_DEATH);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_teron_gorefiend_shadow_of_death_remove::RemoveAuras);
    }
};

class at_teron_gorefiend_entrance : public OnlyOnceAreaTriggerScript
{
public:
    at_teron_gorefiend_entrance() : OnlyOnceAreaTriggerScript("at_teron_gorefiend_entrance") { }

    bool TryHandleOnce(Player* player, AreaTriggerDBC const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            if (Creature* teron = instance->GetCreature(DATA_TERON_GOREFIEND))
                teron->AI()->DoAction(ACTION_START_INTRO);

        return true;
    }
};

void AddSC_boss_teron_gorefiend()
{
    RegisterBlackTempleCreatureAI(boss_teron_gorefiend);
    RegisterBlackTempleCreatureAI(npc_doom_blossom);
    RegisterBlackTempleCreatureAI(npc_shadowy_construct);
    RegisterSpellScript(spell_teron_gorefiend_shadow_of_death);
    RegisterSpellScript(spell_teron_gorefiend_spiritual_vengeance);
    RegisterSpellScript(spell_teron_gorefiend_shadow_of_death_remove);
    new at_teron_gorefiend_entrance();
}
