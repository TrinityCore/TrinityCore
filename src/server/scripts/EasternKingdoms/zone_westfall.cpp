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

#include "CombatAI.h"
#include "Containers.h"
#include "CreatureAIImpl.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "SharedDefines.h"

namespace Scripts::EasternKingdoms::Westfall
{
namespace Creatures
{
    static constexpr uint32 EnergizedHarvestReaper = 42342;
    static constexpr uint32 OverloadedHarvestGolem = 42601;
    static constexpr uint32 JangolodeMineGlubtok = 42492;
    static constexpr uint32 JangolodeMineFigure = 42515;
    static constexpr uint32 HomelessStormwindCitizen1 = 42386;
    static constexpr uint32 HomelessStormwindCitizen2 = 42384;
    static constexpr uint32 WestPlainDrifter = 42391;
    static constexpr uint32 Transient = 42383;
}

namespace Quests
{
    static constexpr uint32 MurderWasTheCaseThatTheyGaveMe = 26209;
}

namespace Spells
{
    static constexpr uint32 JangolodeMineSummonFigure = 79265;
    static constexpr uint32 JangolodeMineSummonGlubtok = 79263;
    static constexpr uint32 HoboInformation1 = 79181;
    static constexpr uint32 HoboInformation2 = 79182;
    static constexpr uint32 HoboInformation3 = 79183;
    static constexpr uint32 HoboInformation4 = 79184;
    static constexpr uint32 SummonRagamuffinLooter = 79169;
    static constexpr uint32 SummonRagamuffinLooter1 = 79170;
    static constexpr uint32 SummonRagamuffinLooter2 = 79171;
    static constexpr uint32 SummonRagamuffinLooter3 = 79172;
    static constexpr uint32 SummonRagamuffinLooter4 = 79173;
    static constexpr uint32 HoboAggro = 79168;
}

namespace Gossip
{
    namespace GossipOption
    {
        static constexpr uint32 GossipOption0 = 0;
        static constexpr uint32 GossipOption1 = 1;
    }
}

namespace Events
{
    namespace ItsAlive
    {
        static constexpr uint32 CheckArea = 1;
        static constexpr uint32 DespawnHarvester = 2;
    }

    namespace MurderWasTheCaseThatTheyGaveMe
    {
        static constexpr uint32 HoboTalk = 1;
        static constexpr uint32 JackpotIntro = 2;
        static constexpr uint32 HoboCry = 3;
        static constexpr uint32 PropertyRage = 4;
        static constexpr uint32 JackpotMiddle = 5;
        static constexpr uint32 JackpotEnd = 6;
        static constexpr uint32 ResumeMove = 7;
        static constexpr uint32 GroupOOC = 1;
    }
}

namespace Actions
{
    namespace MurderWasTheCaseThatTheyGaveMe
    {
        static constexpr uint32 HoboAggroAction = 1;
        static constexpr uint32 HoboAggroActionDone = 2;
    }
}

namespace Text
{
    namespace HarvestGolem
    {
        static constexpr uint32 AnnounceOutOfArea = 0;
    }

    namespace HoboText
    {
        static constexpr uint32 HoboSayClue1 = 0;
        static constexpr uint32 HoboSayClue2 = 1;
        static constexpr uint32 HoboSayClue3 = 2;
        static constexpr uint32 HoboSayClue4 = 3;
        static constexpr uint32 HoboAggroBribe = 4;
        static constexpr uint32 HoboAggroConvince = 5;
        static constexpr uint32 HoboEvent = 6;
        static constexpr uint32 HoboJackpotIntro = 7;
        static constexpr uint32 HoboJackpotEnd = 8;
        static constexpr uint32 HoboPropertyRage = 9;
        static constexpr uint32 HoboFlee = 10;
    }
}

namespace Area
{
    static constexpr uint32 TheMoestFarm = 918;
}

// 79084 - Unbound Energy
class spell_westfall_unbound_energy : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Unit* caster = GetCaster();
        targets.remove_if([caster](WorldObject const* target) -> bool
        {
            return caster->ToWorldObject() == target;
        });

        if (targets.size() > 1)
            Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_westfall_unbound_energy::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// 42601 - Overloaded Harvest Golem
struct npc_westfall_overloaded_harvest_golem : public ScriptedAI
{
    npc_westfall_overloaded_harvest_golem(Creature* creature) : ScriptedAI(creature) {}

    void JustAppeared() override
    {
        _events.ScheduleEvent(Events::ItsAlive::CheckArea, 1s);
    }

    void PassengerBoarded(Unit* /*passenger*/, int8 /*seatId*/, bool apply) override
    {
        if (!apply)
            me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);
        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case Events::ItsAlive::CheckArea:
                    if (me->GetAreaId() != Area::TheMoestFarm)
                    {
                        if (Unit* owner = me->GetCharmerOrOwner())
                            Talk(Text::HarvestGolem::AnnounceOutOfArea, owner);
                        _events.ScheduleEvent(Events::ItsAlive::DespawnHarvester, 8s);
                    }
                    else
                        _events.Repeat(1s);
                    break;
                case Events::ItsAlive::DespawnHarvester:
                    if (me->GetAreaId() != Area::TheMoestFarm)
                        me->DespawnOrUnsummon();
                    else
                        _events.ScheduleEvent(Events::ItsAlive::CheckArea, 1s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

// 79425 - Reaping Blows
class spell_westfall_reaping_blows : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } }) && ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_1).TriggerSpell) });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        // HACK
        // periodic ticks are forcing to cast the spell onto himself instead of target
        // ref AuraEffect::HandlePeriodicTriggerSpellAuraTick
        PreventDefaultAction();
        if (Creature* reaper = GetTarget()->FindNearestCreature(Creatures::EnergizedHarvestReaper, 5.f, true))
            GetTarget()->CastSpell(reaper, GetSpellInfo()->GetEffect(EFFECT_1).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_westfall_reaping_blows::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 79436 - Wake Harvest Golem
class spell_westfall_wake_harvest_golem : public SpellScript
{
    SpellCastResult CheckTarget()
    {
        Unit* target = GetExplTargetUnit();
        if (!target || !target->IsCreature())
            return SPELL_FAILED_BAD_TARGETS;

        return SPELL_CAST_OK;
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster || !caster->IsPlayer())
            return;

        if (Creature* target = GetHitCreature())
        {
            caster->ToPlayer()->KilledMonsterCredit(Creatures::OverloadedHarvestGolem);
            target->DespawnOrUnsummon(100ms);
        }
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_westfall_wake_harvest_golem::CheckTarget);
        OnEffectHitTarget += SpellEffectFn(spell_westfall_wake_harvest_golem::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 79262 - Summon Lou's House
class spell_westfall_summon_lous_house : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(nullptr, Spells::JangolodeMineSummonFigure, CastSpellExtraArgs(TRIGGERED_FULL_MASK));
        caster->CastSpell(nullptr, Spells::JangolodeMineSummonGlubtok, CastSpellExtraArgs(TRIGGERED_FULL_MASK));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_westfall_summon_lous_house::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 79275 - Quest Credit: Jangolde Event
class spell_westfall_quest_credit_jangolode_event : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->ExitVehicle();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_westfall_quest_credit_jangolode_event::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 79290 - General Trigger 1: Glubtok
// 79292 - General Trigger 2: Glubtok
// 79294 - General Trigger 3: Glubtok
// 79297 - General Trigger 4: Glubtok
class spell_westfall_livin_the_life_ping_glubtok : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Player* player = Object::ToPlayer(GetCaster());
        if (!player)
            return;

        targets.clear();
        if (Creature* creature = player->FindNearestCreatureWithOptions(50.0f, { .CreatureId = Creatures::JangolodeMineGlubtok, .OwnerGuid = player->GetGUID() }))
            targets.push_back(creature);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_westfall_livin_the_life_ping_glubtok::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// 79279 - General Trigger 1: Figure
// 79283 - General Trigger 2: Figure
// 79284 - General Trigger 3: Figure
// 79287 - General Trigger 4: Figure
class spell_westfall_livin_the_life_ping_figure : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Player* player = Object::ToPlayer(GetCaster());
        if (!player)
            return;

        targets.clear();
        if (Creature* creature = player->FindNearestCreatureWithOptions(50.0f, { .CreatureId = Creatures::JangolodeMineFigure, .OwnerGuid = player->GetGUID() }))
            targets.push_back(creature);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_westfall_livin_the_life_ping_figure::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// 79273 - Despawn Jangolode Actor
class spell_westfall_despawn_jangolode_actor : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Player* player = Object::ToPlayer(GetCaster());
        if (!player)
            return;

        targets.clear();
        if (Creature* creature = player->FindNearestCreatureWithOptions(50.0f, { .CreatureId = Creatures::JangolodeMineGlubtok, .OwnerGuid = player->GetGUID() }))
            targets.push_back(creature);

        if (Creature* creature = player->FindNearestCreatureWithOptions(50.0f, { .CreatureId = Creatures::JangolodeMineFigure, .OwnerGuid = player->GetGUID() }))
            targets.push_back(creature);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_westfall_despawn_jangolode_actor::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// 42386 - Homeless Stormwind Citizen
// 42384 - Homeless Stormwind Citizen
// 42384 - West Plain Drifter
// 42383 - Transient
struct npc_westfall_hobo_witness : public ScriptedAI
{
    npc_westfall_hobo_witness(Creature* creature) : ScriptedAI(creature), _bribeFailed(false), _hoboRage(false), _flee(false) {}

    struct HoboClueData
    {
        uint32 SpellID;
        uint32 TextID;
    };

    static constexpr std::array<HoboClueData, 4> HoboClues =
    { {
        { Spells::HoboInformation1, Text::HoboText::HoboSayClue1 },
        { Spells::HoboInformation2, Text::HoboText::HoboSayClue2 },
        { Spells::HoboInformation3, Text::HoboText::HoboSayClue3 },
        { Spells::HoboInformation4, Text::HoboText::HoboSayClue4 },
    } };

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
    {
        uint8 clueGainChance = 0;
        switch (gossipListId)
        {
            case Gossip::GossipOption::GossipOption0:
            {
                clueGainChance = 25;
                break;
            }
            case Gossip::GossipOption::GossipOption1:
            {
                clueGainChance = 75;
                _bribeFailed = true;
                break;
            }
            default:
                return true;
        }

        me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        CloseGossipMenuFor(player);
        if (roll_chance_i(clueGainChance))
            GiveClue(player);
        else
        {
            me->SetImmuneToPC(false);
            AttackStart(player);
        }

        return false;
    }

    void GiveClue(Player* player)
    {
        _events.CancelEventGroup(Events::MurderWasTheCaseThatTheyGaveMe::GroupOOC);
        me->SetFacingToObject(player);

        uint16 slot = player->FindQuestSlot(Quests::MurderWasTheCaseThatTheyGaveMe);

        for (uint8 i = 0; i < HoboClues.size(); i++)
        {
            if (player->GetQuestSlotCounter(slot, i) == 0)
            {
                HoboClueData const& data = HoboClues[i];

                player->CastSpell(player, data.SpellID);
                Talk(data.TextID, player);

                me->DespawnOrUnsummon(12s);
                return;
            }
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        me->SetAIAnimKitId(0);
        _events.CancelEventGroup(Events::MurderWasTheCaseThatTheyGaveMe::GroupOOC);

        if (!who->IsPlayer())
            return;

        Talk(_bribeFailed ? Text::HoboText::HoboAggroBribe : Text::HoboText::HoboAggroConvince, who);
    }

    void DamageTaken(Unit* /*killer*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_flee && me->HealthBelowPctDamaged(20, damage))
        {
            _flee = true;
            me->DoFleeToGetAssistance();
            Talk(Text::HoboText::HoboFlee);
        }
    }

    void JustDied(Unit* who) override
    {
        if (Creature* creature = who->ToCreature())
            creature->AI()->DoAction(Actions::MurderWasTheCaseThatTheyGaveMe::HoboAggroActionDone);
        DoCastSelf(Spells::SummonRagamuffinLooter);
    }

    void Reset() override
    {
        ScriptedAI::Reset();
        _events.Reset();
        _bribeFailed = false;
        _hoboRage = false;
        _flee = false;
        me->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        me->SetImmuneToPC(true);
        _events.ScheduleEvent(Events::MurderWasTheCaseThatTheyGaveMe::ResumeMove, 100ms, Events::MurderWasTheCaseThatTheyGaveMe::GroupOOC);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case Actions::MurderWasTheCaseThatTheyGaveMe::HoboAggroAction:
                if (Unit* target = ObjectAccessor::GetUnit(*me, _targetGUID))
                {
                    _hoboRage = true;
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    me->PauseMovement();
                    me->SetFacingToObject(target);
                    AttackStart(target);
                }
                break;
            case Actions::MurderWasTheCaseThatTheyGaveMe::HoboAggroActionDone:
                _hoboRage = false;
                break;
            default:
                return;
        }
    }

    void SetGUID(ObjectGuid const& guid, int32 /*id*/) override
    {
        _targetGUID = guid;
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);
        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case Events::MurderWasTheCaseThatTheyGaveMe::HoboTalk:
                    me->PauseMovement();
                    Talk(Text::HoboText::HoboEvent);
                    _events.ScheduleEvent(Events::MurderWasTheCaseThatTheyGaveMe::ResumeMove, 6s, Events::MurderWasTheCaseThatTheyGaveMe::GroupOOC);
                    break;
                case Events::MurderWasTheCaseThatTheyGaveMe::JackpotIntro:
                    me->PauseMovement();
                    Talk(Text::HoboText::HoboJackpotIntro);
                    _events.ScheduleEvent(Events::MurderWasTheCaseThatTheyGaveMe::JackpotMiddle, 2s + 500ms, Events::MurderWasTheCaseThatTheyGaveMe::GroupOOC);
                    break;
                case Events::MurderWasTheCaseThatTheyGaveMe::JackpotMiddle:
                    me->SetAIAnimKitId(648);
                    Talk(Text::HoboText::HoboJackpotEnd);
                    _events.ScheduleEvent(Events::MurderWasTheCaseThatTheyGaveMe::JackpotEnd, 6s, Events::MurderWasTheCaseThatTheyGaveMe::GroupOOC);
                    break;
                case Events::MurderWasTheCaseThatTheyGaveMe::JackpotEnd:
                    me->SetAIAnimKitId(0);
                    _events.ScheduleEvent(Events::MurderWasTheCaseThatTheyGaveMe::ResumeMove, 4s, Events::MurderWasTheCaseThatTheyGaveMe::GroupOOC);
                    break;
                case Events::MurderWasTheCaseThatTheyGaveMe::HoboCry:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_CRY);
                    me->PauseMovement();
                    _events.ScheduleEvent(Events::MurderWasTheCaseThatTheyGaveMe::ResumeMove, 2s, Events::MurderWasTheCaseThatTheyGaveMe::GroupOOC);
                    break;
                case Events::MurderWasTheCaseThatTheyGaveMe::PropertyRage:
                {
                    uint32 creatureId = RAND(Creatures::HomelessStormwindCitizen1, Creatures::HomelessStormwindCitizen2, Creatures::Transient, Creatures::WestPlainDrifter);
                    if (Creature* creature = GetClosestCreatureWithEntry(me, creatureId, 25.0f))
                    {
                        if (!creature->IsAlive() || creature->IsInCombat())
                        {
                            _events.ScheduleEvent(Events::MurderWasTheCaseThatTheyGaveMe::ResumeMove, 100ms, Events::MurderWasTheCaseThatTheyGaveMe::GroupOOC);
                            return;
                        }
                        _hoboRage = true;
                        Talk(Text::HoboText::HoboPropertyRage);
                        me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                        me->PauseMovement();
                        me->CastSpell(creature, Spells::HoboAggro, true);
                        me->SetFacingToObject(creature);
                    }
                    else
                        _events.ScheduleEvent(Events::MurderWasTheCaseThatTheyGaveMe::ResumeMove, 100ms, Events::MurderWasTheCaseThatTheyGaveMe::GroupOOC);
                    break;
                }
                case Events::MurderWasTheCaseThatTheyGaveMe::ResumeMove:
                    me->ResumeMovement();
                    if (roll_chance_i(50)) // prevent spam
                    {
                        if (roll_chance_i(70)) // chance to trigger simple talk event
                            _events.ScheduleEvent(Events::MurderWasTheCaseThatTheyGaveMe::HoboTalk, 30s, 80s, Events::MurderWasTheCaseThatTheyGaveMe::GroupOOC);
                        else
                            _events.ScheduleEvent(urand(Events::MurderWasTheCaseThatTheyGaveMe::JackpotIntro, Events::MurderWasTheCaseThatTheyGaveMe::PropertyRage), 30s, 80s, Events::MurderWasTheCaseThatTheyGaveMe::GroupOOC);
                    }
                    else
                        _events.Repeat(30s, 80s);
                    break;
                default:
                    break;
            }
        }

        if (!_hoboRage)
            if (!UpdateVictim())
                return;
    }

private:
    EventMap _events;
    ObjectGuid _targetGUID;
    bool _bribeFailed;
    bool _hoboRage;
    bool _flee;
};

// 79169 - Summon Ragamuffin Looter
class spell_westfall_summon_ragamuffin_looter : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                Spells::SummonRagamuffinLooter1,
                Spells::SummonRagamuffinLooter2,
                Spells::SummonRagamuffinLooter3,
                Spells::SummonRagamuffinLooter4
            });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, Spells::SummonRagamuffinLooter1, CastSpellExtraArgs(TRIGGERED_FULL_MASK));
        caster->CastSpell(caster, Spells::SummonRagamuffinLooter2, CastSpellExtraArgs(TRIGGERED_FULL_MASK));
        caster->CastSpell(caster, Spells::SummonRagamuffinLooter3, CastSpellExtraArgs(TRIGGERED_FULL_MASK));
        caster->CastSpell(caster, Spells::SummonRagamuffinLooter4, CastSpellExtraArgs(TRIGGERED_FULL_MASK));
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_westfall_summon_ragamuffin_looter::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 79168 - Hobo Aggro
class spell_westfall_aggro_hobo : public SpellScript
{
    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creature = GetHitCreature())
        {
            creature->AI()->SetGUID(GetCaster()->GetGUID(), 0);
            creature->AI()->DoAction(Actions::MurderWasTheCaseThatTheyGaveMe::HoboAggroAction);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_westfall_aggro_hobo::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};
}

void AddSC_westfall()
{
    using namespace Scripts::EasternKingdoms::Westfall;

    // Creature
    RegisterCreatureAI(npc_westfall_overloaded_harvest_golem);
    RegisterCreatureAI(npc_westfall_hobo_witness);

    // Spells
    RegisterSpellScript(spell_westfall_unbound_energy);
    RegisterSpellScript(spell_westfall_reaping_blows);
    RegisterSpellScript(spell_westfall_wake_harvest_golem);
    RegisterSpellScript(spell_westfall_summon_lous_house);
    RegisterSpellScript(spell_westfall_quest_credit_jangolode_event);
    RegisterSpellScript(spell_westfall_despawn_jangolode_actor);
    RegisterSpellScript(spell_westfall_livin_the_life_ping_glubtok);
    RegisterSpellScript(spell_westfall_livin_the_life_ping_figure);
    RegisterSpellScript(spell_westfall_summon_ragamuffin_looter);
    RegisterSpellScript(spell_westfall_aggro_hobo);
}
