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

#include "icecrown_citadel.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"

enum ScriptTexts
{
    SAY_STINKY_DEAD             = 0,
    SAY_AGGRO                   = 1,
    EMOTE_GAS_SPORE             = 2,
    EMOTE_WARN_GAS_SPORE        = 3,
    SAY_PUNGENT_BLIGHT          = 4,
    EMOTE_WARN_PUNGENT_BLIGHT   = 5,
    EMOTE_PUNGENT_BLIGHT        = 6,
    SAY_KILL                    = 7,
    SAY_BERSERK                 = 8,
    SAY_DEATH                   = 9,
};

enum Spells
{
    // Festergut
    SPELL_INHALE_BLIGHT         = 69165,
    SPELL_PUNGENT_BLIGHT        = 69195,
    SPELL_GASTRIC_BLOAT         = 72219, // 72214 is the proper way (with proc) but atm procs can't have cooldown for creatures
    SPELL_GASTRIC_EXPLOSION     = 72227,
    SPELL_GAS_SPORE             = 69278,
    SPELL_VILE_GAS              = 69240,
    SPELL_INOCULATED            = 69291,

    // Stinky
    SPELL_MORTAL_WOUND          = 71127,
    SPELL_DECIMATE              = 71123,
    SPELL_PLAGUE_STENCH         = 71805,
};

// Used for HasAura checks
#define PUNGENT_BLIGHT_HELPER RAID_MODE<uint32>(69195, 71219, 73031, 73032)
#define INOCULATED_HELPER     RAID_MODE<uint32>(69291, 72101, 72102, 72103)

uint32 const gaseousBlight[3]        = {69157, 69162, 69164};
uint32 const gaseousBlightVisual[3]  = {69126, 69152, 69154};

enum Events
{
    EVENT_BERSERK       = 1,
    EVENT_INHALE_BLIGHT = 2,
    EVENT_VILE_GAS      = 3,
    EVENT_GAS_SPORE     = 4,
    EVENT_GASTRIC_BLOAT = 5,

    EVENT_DECIMATE      = 6,
    EVENT_MORTAL_WOUND  = 7,
};

enum Misc
{
    DATA_INOCULATED_STACK       = 69291
};

struct boss_festergut : public BossAI
{
    boss_festergut(Creature* creature) : BossAI(creature, DATA_FESTERGUT)
    {
        _maxInoculatedStack = 0;
        _inhaleCounter = 0;
    }

    void Reset() override
    {
        _Reset();
        events.ScheduleEvent(EVENT_BERSERK, 5min);
        events.ScheduleEvent(EVENT_INHALE_BLIGHT, 25s, 30s);
        events.ScheduleEvent(EVENT_GAS_SPORE, 20s, 25s);
        events.ScheduleEvent(EVENT_GASTRIC_BLOAT, 12500ms, 15s);
        _maxInoculatedStack = 0;
        _inhaleCounter = 0;
        me->RemoveAurasDueToSpell(SPELL_BERSERK2);
        if (Creature* gasDummy = me->FindNearestCreature(NPC_GAS_DUMMY, 100.0f, true))
        {
            _gasDummyGUID = gasDummy->GetGUID();
            for (uint8 i = 0; i < 3; ++i)
            {
                me->RemoveAurasDueToSpell(gaseousBlight[i]);
                gasDummy->RemoveAurasDueToSpell(gaseousBlightVisual[i]);
            }
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        if (!instance->CheckRequiredBosses(DATA_FESTERGUT, who->ToPlayer()))
        {
            EnterEvadeMode(EVADE_REASON_OTHER);
            instance->DoCastSpellOnPlayers(LIGHT_S_HAMMER_TELEPORT);
            return;
        }

        me->setActive(true);
        Talk(SAY_AGGRO);
        if (Creature* gasDummy = me->FindNearestCreature(NPC_GAS_DUMMY, 100.0f, true))
            _gasDummyGUID = gasDummy->GetGUID();
        if (Creature* professor = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_PROFESSOR_PUTRICIDE)))
            professor->AI()->DoAction(ACTION_FESTERGUT_COMBAT);
        DoZoneInCombat();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        if (Creature* professor = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_PROFESSOR_PUTRICIDE)))
            professor->AI()->DoAction(ACTION_FESTERGUT_DEATH);

        RemoveBlight();
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        instance->SetBossState(DATA_FESTERGUT, FAIL);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode(why);
        if (Creature* professor = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_PROFESSOR_PUTRICIDE)))
            professor->AI()->EnterEvadeMode();
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_KILL);
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        Unit* unitTarget = target->ToUnit();
        if (!unitTarget)
            return;

        if (spellInfo->Id == PUNGENT_BLIGHT_HELPER)
            unitTarget->RemoveAurasDueToSpell(INOCULATED_HELPER);
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
                case EVENT_INHALE_BLIGHT:
                {
                    RemoveBlight();
                    if (_inhaleCounter == 3)
                    {
                        Talk(EMOTE_WARN_PUNGENT_BLIGHT);
                        Talk(SAY_PUNGENT_BLIGHT);
                        DoCastSelf(SPELL_PUNGENT_BLIGHT);
                        _inhaleCounter = 0;
                        if (Creature* professor = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_PROFESSOR_PUTRICIDE)))
                            professor->AI()->DoAction(ACTION_FESTERGUT_GAS);
                        events.RescheduleEvent(EVENT_GAS_SPORE, 20s, 25s);
                    }
                    else
                    {
                        DoCastSelf(SPELL_INHALE_BLIGHT);
                        // just cast and dont bother with target, conditions will handle it
                        ++_inhaleCounter;
                        if (_inhaleCounter < 3)
                            me->CastSpell(me, gaseousBlight[_inhaleCounter], CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                                .SetOriginalCaster(me->GetGUID()));
                    }

                    events.ScheduleEvent(EVENT_INHALE_BLIGHT, 33500ms, 35s);
                    break;
                }
                case EVENT_VILE_GAS:
                {
                    std::list<Unit*> ranged, melee;
                    uint32 minTargets = RAID_MODE<uint32>(3, 8, 3, 8);
                    SelectTargetList(ranged, 25, SelectTargetMethod::Random, 0, -5.0f, true);
                    SelectTargetList(melee, 25, SelectTargetMethod::Random, 0, 5.0f, true);
                    while (ranged.size() < minTargets)
                    {
                        if (melee.empty())
                            break;

                        Unit* target = Trinity::Containers::SelectRandomContainerElement(melee);
                        ranged.push_back(target);
                        melee.remove(target);
                    }

                    if (!ranged.empty())
                    {
                        Trinity::Containers::RandomResize(ranged, RAID_MODE<uint32>(1, 3, 1, 3));
                        for (std::list<Unit*>::iterator itr = ranged.begin(); itr != ranged.end(); ++itr)
                            DoCast(*itr, SPELL_VILE_GAS);
                    }

                    events.ScheduleEvent(EVENT_VILE_GAS, 28s, 35s);
                    break;
                }
                case EVENT_GAS_SPORE:
                    Talk(EMOTE_WARN_GAS_SPORE);
                    Talk(EMOTE_GAS_SPORE);
                    me->CastSpell(me, SPELL_GAS_SPORE, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, RAID_MODE<int32>(2, 3, 2, 3)));
                    events.ScheduleEvent(EVENT_GAS_SPORE, 40s, 45s);
                    events.RescheduleEvent(EVENT_VILE_GAS, 28s, 35s);
                    break;
                case EVENT_GASTRIC_BLOAT:
                    DoCastVictim(SPELL_GASTRIC_BLOAT);
                    events.ScheduleEvent(EVENT_GASTRIC_BLOAT, 15s, 17500ms);
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK2);
                    Talk(SAY_BERSERK);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

    void SetData(uint32 type, uint32 data) override
    {
        if (type == DATA_INOCULATED_STACK && data > _maxInoculatedStack)
            _maxInoculatedStack = data;
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_INOCULATED_STACK)
            return uint32(_maxInoculatedStack);

        return 0;
    }

    void RemoveBlight()
    {
        if (Creature* gasDummy = ObjectAccessor::GetCreature(*me, _gasDummyGUID))
            for (uint8 i = 0; i < 3; ++i)
            {
                me->RemoveAurasDueToSpell(gaseousBlight[i]);
                gasDummy->RemoveAurasDueToSpell(gaseousBlightVisual[i]);
            }
    }

private:
    ObjectGuid _gasDummyGUID;
    uint32 _maxInoculatedStack;
    uint32 _inhaleCounter;
};

struct npc_stinky_icc : public ScriptedAI
{
    npc_stinky_icc(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_DECIMATE, 20s, 25s);
        _events.ScheduleEvent(EVENT_MORTAL_WOUND, 3s, 7s);
    }

    void JustEngagedWith(Unit* /*target*/) override
    {
        DoCastSelf(SPELL_PLAGUE_STENCH);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_DECIMATE:
                    DoCastVictim(SPELL_DECIMATE);
                    _events.ScheduleEvent(EVENT_DECIMATE, 20s, 25s);
                    break;
                case EVENT_MORTAL_WOUND:
                    DoCastVictim(SPELL_MORTAL_WOUND);
                    _events.ScheduleEvent(EVENT_MORTAL_WOUND, 10s, 12500ms);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* festergut = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_FESTERGUT)))
            if (festergut->IsAlive())
                festergut->AI()->Talk(SAY_STINKY_DEAD);
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

class spell_festergut_pungent_blight : public SpellScript
{
    PrepareSpellScript(spell_festergut_pungent_blight);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->RemoveAurasDueToSpell(uint32(GetEffectValue()));
        GetCaster()->ToCreature()->AI()->Talk(EMOTE_PUNGENT_BLIGHT);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_festergut_pungent_blight::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_festergut_gastric_bloat : public SpellScript
{
    PrepareSpellScript(spell_festergut_gastric_bloat);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_GASTRIC_EXPLOSION });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Aura const* aura = GetHitUnit()->GetAura(GetSpellInfo()->Id);
        if (!(aura && aura->GetStackAmount() == 10))
            return;

        GetHitUnit()->RemoveAurasDueToSpell(GetSpellInfo()->Id);
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_GASTRIC_EXPLOSION, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_festergut_gastric_bloat::HandleScript, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_festergut_blighted_spores : public AuraScript
{
    PrepareAuraScript(spell_festergut_blighted_spores);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_INOCULATED, SPELL_ORANGE_BLIGHT_RESIDUE });
    }

    void ExtraEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_INOCULATED, true);
        if (InstanceScript* instance = GetTarget()->GetInstanceScript())
            if (Creature* festergut = ObjectAccessor::GetCreature(*GetTarget(), instance->GetGuidData(DATA_FESTERGUT)))
                festergut->AI()->SetData(DATA_INOCULATED_STACK, GetStackAmount());

        HandleResidue();
    }

    void HandleResidue()
    {
        Player* target = GetUnitOwner()->ToPlayer();
        if (!target)
            return;

        if (target->HasAura(SPELL_ORANGE_BLIGHT_RESIDUE))
            return;

        uint32 questId = target->GetMap()->Is25ManRaid() ? QUEST_RESIDUE_RENDEZVOUS_25 : QUEST_RESIDUE_RENDEZVOUS_10;
        if (target->GetQuestStatus(questId) != QUEST_STATUS_INCOMPLETE)
            return;

        target->CastSpell(target, SPELL_ORANGE_BLIGHT_RESIDUE, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_festergut_blighted_spores::ExtraEffect, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

class achievement_flu_shot_shortage : public AchievementCriteriaScript
{
    public:
        achievement_flu_shot_shortage() : AchievementCriteriaScript("achievement_flu_shot_shortage") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (target && target->GetTypeId() == TYPEID_UNIT)
                return target->ToCreature()->AI()->GetData(DATA_INOCULATED_STACK) < 3;

            return false;
        }
};

void AddSC_boss_festergut()
{
    // Creatures
    RegisterIcecrownCitadelCreatureAI(boss_festergut);
    RegisterIcecrownCitadelCreatureAI(npc_stinky_icc);

    // Spells
    RegisterSpellScript(spell_festergut_pungent_blight);
    RegisterSpellScript(spell_festergut_gastric_bloat);
    RegisterSpellScript(spell_festergut_blighted_spores);

    // Achievements
    new achievement_flu_shot_shortage();
}
