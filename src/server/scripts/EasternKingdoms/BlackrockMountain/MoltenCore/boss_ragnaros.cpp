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
 * Is SAY_REINFORCEMENTS_2 really used?
 * Are SPELL_SUBMERGE_FADE and SPELL_EMERGE used?
 * Combat timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "molten_core.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum RagnarosTexts
{
    SAY_ARRIVAL_1               = 0,
    SAY_ARRIVAL_2               = 1,
    SAY_ARRIVAL_3               = 2,
    SAY_MIGHT                   = 3,
    SAY_WRATH                   = 4,
    SAY_REINFORCEMENTS_1        = 5,
    SAY_REINFORCEMENTS_2        = 6,
    SAY_SLAY                    = 7
};

enum RagnarosSpells
{
    // Intro
    SPELL_ELEMENTAL_FIRE_KILL   = 19773,

    // Passive
    SPELL_ELEMENTAL_FIRE        = 20563,
    SPELL_MELT_WEAPON           = 21387,

    // Combat
    SPELL_MAGMA_BLAST           = 20565,
    SPELL_WRATH_OF_RAGNAROS     = 20566,
    SPELL_MIGHT_OF_RAGNAROS     = 21154,
    SPELL_LAVA_BURST            = 21908,

    SPELL_SUBMERGE_VISUAL       = 20567,
    SPELL_SUBMERGE_EFFECT       = 21859,
    SPELL_SUBMERGE_FADE         = 21107,
    SPELL_EMERGE                = 20568,
    SPELL_SUMMON_SONS_OF_FLAME  = 21108,

    // Flame of Ragnaros
    SPELL_INTENSE_HEAT          = 21155,

    // Son of Flame
    SPELL_LAVA_SHIELD           = 21857,
    SPELL_DOUBLE_ATTACK         = 19818,

    // Scripts
    SPELL_SUMMON_LAVA_BURST_A   = 21886,
    SPELL_SUMMON_LAVA_BURST_B   = 21900,
    SPELL_SUMMON_LAVA_BURST_C   = 21901,
    SPELL_SUMMON_LAVA_BURST_D   = 21902,
    SPELL_SUMMON_LAVA_BURST_E   = 21903,
    SPELL_SUMMON_LAVA_BURST_F   = 21904,
    SPELL_SUMMON_LAVA_BURST_G   = 21905,
    SPELL_SUMMON_LAVA_BURST_H   = 21906,
    SPELL_SUMMON_LAVA_BURST_I   = 21907,

    SPELL_SUMMON_SON_OF_FLAME_A = 21117,
    SPELL_SUMMON_SON_OF_FLAME_B = 21110,
    SPELL_SUMMON_SON_OF_FLAME_C = 21111,
    SPELL_SUMMON_SON_OF_FLAME_D = 21112,
    SPELL_SUMMON_SON_OF_FLAME_E = 21113,
    SPELL_SUMMON_SON_OF_FLAME_F = 21114,
    SPELL_SUMMON_SON_OF_FLAME_G = 21115,
    SPELL_SUMMON_SON_OF_FLAME_H = 21116
};

enum RagnarosEvents
{
    EVENT_MAGMA_BLAST           = 1,
    EVENT_WRATH_OF_RAGNAROS,
    EVENT_MIGHT_OF_RAGNAROS,
    EVENT_LAVA_BURST,

    EVENT_SUBMERGE,
    EVENT_EMERGE,

    EVENT_INTRO_1,
    EVENT_INTRO_2,
    EVENT_INTRO_3,
    EVENT_INTRO_4,
    EVENT_INTRO_5
};

enum RagnarosMisc
{
    NPC_SON_OF_FLAME            = 12143,
    MAX_SONS_OF_FLAME           = 8
};

static constexpr std::array<uint32, 9> SummonLavaBurstSpells =
{
    SPELL_SUMMON_LAVA_BURST_A,
    SPELL_SUMMON_LAVA_BURST_B,
    SPELL_SUMMON_LAVA_BURST_C,
    SPELL_SUMMON_LAVA_BURST_D,
    SPELL_SUMMON_LAVA_BURST_E,
    SPELL_SUMMON_LAVA_BURST_F,
    SPELL_SUMMON_LAVA_BURST_G,
    SPELL_SUMMON_LAVA_BURST_H,
    SPELL_SUMMON_LAVA_BURST_I
};

static constexpr std::array<uint32, 8> SummonSonsOfFlameSpells =
{
    SPELL_SUMMON_SON_OF_FLAME_A,
    SPELL_SUMMON_SON_OF_FLAME_B,
    SPELL_SUMMON_SON_OF_FLAME_C,
    SPELL_SUMMON_SON_OF_FLAME_D,
    SPELL_SUMMON_SON_OF_FLAME_E,
    SPELL_SUMMON_SON_OF_FLAME_F,
    SPELL_SUMMON_SON_OF_FLAME_G,
    SPELL_SUMMON_SON_OF_FLAME_H
};

// 11502 - Ragnaros
struct boss_ragnaros : public BossAI
{
    boss_ragnaros(Creature* creature) : BossAI(creature, BOSS_RAGNAROS),
        _deadSonsOfFlameCount(0), _hasSubmergedOnce(false), _isSubmerged(false) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_ELEMENTAL_FIRE);
        DoCastSelf(SPELL_MELT_WEAPON);
        events.ScheduleEvent(EVENT_INTRO_1, 6s);
    }

    void Reset() override
    {
        BossAI::Reset();

        _hasSubmergedOnce = false;
        _isSubmerged = false;
        _deadSonsOfFlameCount = 0;

        me->SetStandState(UNIT_STAND_STATE_STAND);
        me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_MAGMA_BLAST, 3s, 4s);
        events.ScheduleEvent(EVENT_WRATH_OF_RAGNAROS, 25s, 30s);
        events.ScheduleEvent(EVENT_MIGHT_OF_RAGNAROS, 12s);
        events.ScheduleEvent(EVENT_LAVA_BURST, 13s, 14s);
        events.ScheduleEvent(EVENT_SUBMERGE, 3min);
    }

    void JustReachedHome() override
    {
        _JustReachedHome();

        DoCastSelf(SPELL_ELEMENTAL_FIRE);
        DoCastSelf(SPELL_MELT_WEAPON);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_MIGHT_OF_RAGNAROS:
                if (roll_chance_i(50))
                    Talk(SAY_MIGHT);
                break;
            case SPELL_WRATH_OF_RAGNAROS:
                Talk(SAY_WRATH);
                ResetThreatList();
                break;
            default:
                break;
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        if (summon->GetEntry() == NPC_SON_OF_FLAME)
        {
            _deadSonsOfFlameCount++;

            if (_deadSonsOfFlameCount == MAX_SONS_OF_FLAME)
            {
                _deadSonsOfFlameCount = 0;
                if (_isSubmerged)
                    events.RescheduleEvent(EVENT_EMERGE, 0s);
            }
        }
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void UpdateIntroEvents(uint32 diff)
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INTRO_1:
                    Talk(SAY_ARRIVAL_1);
                    events.ScheduleEvent(EVENT_INTRO_2, 22s);
                    break;
                case EVENT_INTRO_2:
                    Talk(SAY_ARRIVAL_2);
                    events.ScheduleEvent(EVENT_INTRO_3, 15s);
                    break;
                case EVENT_INTRO_3:
                    DoCastSelf(SPELL_ELEMENTAL_FIRE_KILL);
                    events.ScheduleEvent(EVENT_INTRO_4, 7s);
                    break;
                case EVENT_INTRO_4:
                    Talk(SAY_ARRIVAL_3);
                    events.ScheduleEvent(EVENT_INTRO_5, 4s);
                    break;
                case EVENT_INTRO_5:
                    me->SetImmuneToPC(false);
                    break;
                default:
                    break;
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            UpdateIntroEvents(diff);
            return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MAGMA_BLAST:
                    if (!me->IsWithinMeleeRange(me->GetVictim()))
                        DoCastVictim(SPELL_MAGMA_BLAST);
                    events.Repeat(3s, 4s);
                    break;
                case EVENT_WRATH_OF_RAGNAROS:
                    DoCastSelf(SPELL_WRATH_OF_RAGNAROS);
                    events.Repeat(25s, 30s);
                    break;
                case EVENT_MIGHT_OF_RAGNAROS:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_MIGHT_OF_RAGNAROS);
                    events.Repeat(9s, 12s);
                    break;
                case EVENT_LAVA_BURST:
                    DoCastSelf(SPELL_LAVA_BURST);
                    events.Repeat(2s, 15s);
                    break;

                case EVENT_SUBMERGE:
                    me->RemoveAllAurasExceptType(SPELL_AURA_PROC_TRIGGER_SPELL);
                    DoCastSelf(SPELL_SUMMON_SONS_OF_FLAME);
                    DoCastSelf(SPELL_SUBMERGE_VISUAL);
                    DoCastSelf(SPELL_SUBMERGE_EFFECT);
                    me->SetStandState(UNIT_STAND_STATE_SUBMERGED);
                    me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    me->SetReactState(REACT_PASSIVE);

                    Talk(!_hasSubmergedOnce ? SAY_REINFORCEMENTS_1 : SAY_REINFORCEMENTS_2);
                    _hasSubmergedOnce = true;
                    _isSubmerged = true;

                    events.CancelEvent(EVENT_MAGMA_BLAST);
                    events.CancelEvent(EVENT_WRATH_OF_RAGNAROS);
                    events.CancelEvent(EVENT_MIGHT_OF_RAGNAROS);
                    events.CancelEvent(EVENT_LAVA_BURST);

                    events.ScheduleEvent(EVENT_EMERGE, 90s);
                    break;
                case EVENT_EMERGE:
                    me->RemoveAurasDueToSpell(SPELL_SUBMERGE_VISUAL);
                    me->RemoveAurasDueToSpell(SPELL_SUBMERGE_EFFECT);
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    me->SetReactState(REACT_AGGRESSIVE);

                    _isSubmerged = false;

                    events.ScheduleEvent(EVENT_MAGMA_BLAST, 2400ms);
                    events.ScheduleEvent(EVENT_WRATH_OF_RAGNAROS, 25s, 30s);
                    events.ScheduleEvent(EVENT_MIGHT_OF_RAGNAROS, 12s);
                    events.ScheduleEvent(EVENT_LAVA_BURST, 13s, 14s);
                    events.ScheduleEvent(EVENT_SUBMERGE, 3min);
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
    uint8 _deadSonsOfFlameCount;
    bool _hasSubmergedOnce;
    bool _isSubmerged;
};

// 13148 - Flame of Ragnaros
struct npc_flame_of_ragnaros : public ScriptedAI
{
    npc_flame_of_ragnaros(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_INTENSE_HEAT);
        me->DespawnOrUnsummon();
    }
};

// 12143 - Son of Flame
struct npc_son_of_flame : public ScriptedAI
{
    npc_son_of_flame(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetCorpseDelay(1, true);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_LAVA_SHIELD);
        DoCastSelf(SPELL_DOUBLE_ATTACK);
        DoZoneInCombat();
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

// 21908 - Lava Burst Randomizer
class spell_ragnaros_lava_burst : public SpellScript
{
    PrepareSpellScript(spell_ragnaros_lava_burst);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(SummonLavaBurstSpells);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), Trinity::Containers::SelectRandomContainerElement(SummonLavaBurstSpells), true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_ragnaros_lava_burst::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 21108 - Summon Sons of Flame
class spell_ragnaros_summon_sons_of_flame : public SpellScript
{
    PrepareSpellScript(spell_ragnaros_summon_sons_of_flame);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(SummonSonsOfFlameSpells);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        for (uint32 spell : SummonSonsOfFlameSpells)
            caster->CastSpell(caster, spell, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_ragnaros_summon_sons_of_flame::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 178088 - Ragnaros
struct go_ragnaros_lava_burst_trap : public GameObjectAI
{
    using GameObjectAI::GameObjectAI;

    void InitializeAI() override
    {
        // This trap is supposed to trigger immediately after spawning without any nearby players
        me->m_Events.AddEventAtOffset([go = me]()
        {
            // no spell found in sniff (either serverside and not in spell_dbc or just a manual script action)
            go->ActivateObject(GameObjectActions::AnimateCustom0);

            if (Creature* ragnaros = go->GetInstanceScript()->GetCreature(BOSS_RAGNAROS))
                go->ActivateObject(GameObjectActions::Disturb, ragnaros);
        }, 1ms);
    }
};

void AddSC_boss_ragnaros()
{
    RegisterMoltenCoreCreatureAI(boss_ragnaros);
    RegisterMoltenCoreCreatureAI(npc_flame_of_ragnaros);
    RegisterMoltenCoreCreatureAI(npc_son_of_flame);
    RegisterSpellScript(spell_ragnaros_lava_burst);
    RegisterSpellScript(spell_ragnaros_summon_sons_of_flame);
    RegisterMoltenCoreGameObjectAI(go_ragnaros_lava_burst_trap);
}
