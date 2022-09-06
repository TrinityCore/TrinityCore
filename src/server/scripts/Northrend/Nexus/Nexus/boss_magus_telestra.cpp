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
 Achievement implementation requires additional research.
 Telestra's clones are unkillable and only executes set of actions when damaged to full health. Those actions includes cast of
 'Telestra Clone Dies' aura which lands on boss(3 auras for 3 clones). Comments claims 'frost' clone can fail achievement due to
 her Blizzard spell. Thing is action sets on retail cannot be started when creature casts spell(general mechanic or supported by flag or by
 special action-check which can be used directly in action set as first action, preventing execution of next events until current cast is
 finished. You can notice that everywhere - bosses don't enter in another phase while casting spells, for example).

 But while actions clones executes surely has something related to achievement, Telestra Clone Dies auras probably aren't. The problem is those
 auras are missiles and it may take seconds to hit boss, leaving a small chance to complete achievement. Speed of missiles is just 5 and unique
 missile motion makes it slower. On top of that when clone dies, it can be not close enough to the boss.

 That achievement is more trickier, some people claim it can be enough to kill clones only once, or it requires to kill clones twice. Or that
 it is possible to get achievement even if she didn't summoned clones.
 At least we can be sure auras are scripted to inform AI that all 3 clones are dead because once 3 auras are applied on boss, she casts a spell
 which we can use later in SpellHit hook to perform merge sequence.

 Currently we force clones to use SetData (in DB) to inform boss that clone is dead. And auras are used only to inform boss that
 all clones are dead.
 World Trigger spawned in front of boss may be related to something.
 */

#include "GameEventMgr.h"
#include "GameTime.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "nexus.h"

enum Texts
{
    SAY_AGGRO                        = 0,
    SAY_KILL                         = 1,
    SAY_DEATH                        = 2,
    SAY_MERGE                        = 3,
    SAY_SPLIT                        = 4
};

enum Spells
{
    SPELL_ICE_NOVA                   = 47772,
    SPELL_FIREBOMB                   = 47773,
    SPELL_GRAVITY_WELL               = 47756,

    SPELL_SUMMON_CLONE_FIRE          = 47707,
    SPELL_SUMMON_CLONE_ARCANE        = 47708,
    SPELL_SUMMON_CLONE_FROST         = 47709,
    SPELL_SUMMON_CLONES              = 47710,

    SPELL_CLONE_DIES_FIRE            = 47711,
    SPELL_CLONE_DIES_FROST           = 47712,
    SPELL_CLONE_DIES_ARCANE          = 47713,
    SPELL_TRIGGER_000                = 36294,

    SPELL_TELEPORT                   = 47754,
    SPELL_SPAWN_BACK_IN              = 47714,

    SPELL_WEAR_CHRISTMAS_HAT         = 61400
};

enum Events
{
    EVENT_ICE_NOVA                   = 1,
    EVENT_FIREBOMB,
    EVENT_GRAVITY_WELL,

    EVENT_SPLIT,
    EVENT_SPLIT_2,
    EVENT_SPLIT_3,

    EVENT_MERGE,
    EVENT_MERGE_2
};

enum Misc
{
    ACTION_MAGUS_DEAD                = 1,
    DATA_SPLIT_PERSONALITY           = 2,

    GAME_EVENT_WINTER_VEIL           = 2
};

struct boss_magus_telestra : public BossAI
{
    boss_magus_telestra(Creature* creature) : BossAI(creature, DATA_MAGUS_TELESTRA),
        _split1(false), _split2(false), _unkillable(false), _splitted(false)
    {
        Initialize();
    }

    void Initialize()
    {
        for (uint8 n = 0; n < 3; ++n)
            time[n] = 0;

        splitPersonality = 0;
    }

    void Reset() override
    {
        _Reset();
        _split1 = false;
        _split2 = false;
        _unkillable = false;
        _splitted = false;
        Initialize();

        me->SetReactState(REACT_AGGRESSIVE);
        me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);

        if (IsHeroic() && sGameEventMgr->IsActiveEvent(GAME_EVENT_WINTER_VEIL) && !me->HasAura(SPELL_WEAR_CHRISTMAS_HAT))
            me->AddAura(SPELL_WEAR_CHRISTMAS_HAT, me);
    }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_AGGRO);
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_ICE_NOVA, 20s, 25s);
        events.ScheduleEvent(EVENT_FIREBOMB, 0s);
        events.ScheduleEvent(EVENT_GRAVITY_WELL, 10s, 15s);
    }

    void AttackStart(Unit* who) override
    {
        ScriptedAI::AttackStartCaster(who, 40.0f);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_KILL);
    }

    void DamageTaken(Unit* /*killer*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth() && _unkillable)
            damage = me->GetHealth() - 1;

        // Boss can receive damage while being already splitted, prevent performing second split if already splitted
        if (_splitted)
            return;

        // Once in normal
        if (!_split1 && me->HealthBelowPctDamaged(50, damage) && !IsHeroic())
        {
            _split1 = true;
            events.ScheduleEvent(EVENT_SPLIT, 0s);
        }

        // Twice in heroic
        if (!_split1 && me->HealthBelowPctDamaged(65, damage) && IsHeroic())
        {
            _split1 = true;
            events.ScheduleEvent(EVENT_SPLIT, 0s);
        }

        if (!_split2 && me->HealthBelowPctDamaged(35, damage) && IsHeroic())
        {
            _split2 = true;
            events.ScheduleEvent(EVENT_SPLIT, 0s);
        }
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_SUMMON_CLONES)
            events.ScheduleEvent(EVENT_SPLIT_2, 0s);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_TRIGGER_000)
            events.ScheduleEvent(EVENT_MERGE, 5s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void SetData(uint32 type, uint32 data) override
    {
        if (type == 0 && data == 1)
            DoAction(ACTION_MAGUS_DEAD);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_MAGUS_DEAD)
        {
            uint8 i = 0;
            while (time[i] != 0)
                ++i;

            time[i] = GameTime::GetGameTime();
            if (i == 2)
            {
                if ((time[2] - time[1] < 5) && (time[1] - time[0] < 5))
                    ++splitPersonality;

                // Reset time
                for (uint8 n = 0; n < 3; ++n)
                    time[n] = 0;
            }
        }
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_SPLIT_PERSONALITY)
            return splitPersonality;

        return 0;
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
                // Combat spells
                case EVENT_ICE_NOVA:
                    DoCastSelf(SPELL_ICE_NOVA);
                    events.Repeat(20s, 25s);
                    break;
                case EVENT_FIREBOMB:
                    DoCastVictim(SPELL_FIREBOMB);
                    events.Repeat(1600ms, 2400ms);
                    break;
                case EVENT_GRAVITY_WELL:
                    DoCastSelf(SPELL_GRAVITY_WELL);
                    events.Repeat(20s, 25s);
                    break;

                // Split sequence, continues in OnSpellCast
                case EVENT_SPLIT:
                    _splitted = true;
                    // Cancel combat spells
                    events.Reset();
                    Talk(SAY_SPLIT);
                    me->SetReactState(REACT_PASSIVE);
                    DoCastSelf(SPELL_SUMMON_CLONES);
                    break;
                case EVENT_SPLIT_2:
                    _unkillable = true;
                    // Hack, transform creature (from aura) has visible and invisible models and probability is NYI
                    me->SetDisplayId(15435);
                    me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    // Not restored later, maybe after wipe
                    SetEquipmentSlots(false, EQUIP_UNEQUIP);
                    events.ScheduleEvent(EVENT_SPLIT_3, 4s);
                    break;
                case EVENT_SPLIT_3:
                    DoCastSelf(SPELL_TELEPORT);
                    break;

                // Merge sequence
                case EVENT_MERGE:
                    DoCastSelf(SPELL_SPAWN_BACK_IN);
                    me->RemoveAurasDueToSpell(SPELL_CLONE_DIES_FIRE);
                    me->RemoveAurasDueToSpell(SPELL_CLONE_DIES_FROST);
                    me->RemoveAurasDueToSpell(SPELL_CLONE_DIES_ARCANE);
                    me->RemoveAurasDueToSpell(SPELL_SUMMON_CLONES);
                    Talk(SAY_MERGE);
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    _unkillable = false;
                    events.ScheduleEvent(EVENT_MERGE_2, 3s);
                    break;
                case EVENT_MERGE_2:
                    me->SetReactState(REACT_AGGRESSIVE);
                    events.ScheduleEvent(EVENT_GRAVITY_WELL, 0s);
                    events.ScheduleEvent(EVENT_ICE_NOVA, 6s);
                    events.ScheduleEvent(EVENT_FIREBOMB, 8s);
                    _splitted = false;
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
    bool _split1;
    bool _split2;
    bool _unkillable;
    bool _splitted;
    time_t time[3];
    uint8 splitPersonality;
};

// 47710 - Summon Telestra Clones
class spell_magus_telestra_summon_clones : public SpellScript
{
    PrepareSpellScript(spell_magus_telestra_summon_clones);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SUMMON_CLONE_FIRE,
            SPELL_SUMMON_CLONE_ARCANE,
            SPELL_SUMMON_CLONE_FROST
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_SUMMON_CLONE_FIRE);
        caster->CastSpell(caster, SPELL_SUMMON_CLONE_ARCANE);
        caster->CastSpell(caster, SPELL_SUMMON_CLONE_FROST);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_magus_telestra_summon_clones::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 47711 - Telestra Clone Dies (Fire)
// 47712 - Telestra Clone Dies (Frost)
// 47713 - Telestra Clone Dies (Arcane)
class spell_magus_telestra_clone_dies : public AuraScript
{
    PrepareAuraScript(spell_magus_telestra_clone_dies);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TRIGGER_000 });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target->HasAura(SPELL_CLONE_DIES_FIRE) && target->HasAura(SPELL_CLONE_DIES_FROST) && target->HasAura(SPELL_CLONE_DIES_ARCANE))
            target->CastSpell(target, SPELL_TRIGGER_000);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_magus_telestra_clone_dies::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class achievement_split_personality : public AchievementCriteriaScript
{
    public:
        achievement_split_personality() : AchievementCriteriaScript("achievement_split_personality")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Telestra = target->ToCreature())
                if (Telestra->AI()->GetData(DATA_SPLIT_PERSONALITY) == 2)
                    return true;

            return false;
        }
};

void AddSC_boss_magus_telestra()
{
    RegisterNexusCreatureAI(boss_magus_telestra);
    RegisterSpellScript(spell_magus_telestra_summon_clones);
    RegisterSpellScript(spell_magus_telestra_clone_dies);
    new achievement_split_personality();
}
