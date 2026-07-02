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
#include "TemporarySummon.h"

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
    static constexpr uint32 WestPlainDrifterFollower = 42400;
    static constexpr uint32 Transient = 42383;
    static constexpr uint32 LousPartingThoughtsTrigger = 42562;
    static constexpr uint32 Thug = 42387;
    static constexpr uint32 SmallTimeHustler = 42390;
    static constexpr uint32 WestfallStew = 42617;
}

namespace Quests
{
    static constexpr uint32 MurderWasTheCaseThatTheyGaveMe = 26209;
    static constexpr uint32 LousPartingThoughts = 26232;
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
    static constexpr uint32 HoboInformation = 79184;
    static constexpr uint32 FullBelly = 79451;
    static constexpr uint32 CosmeticSleep = 78677;
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

    namespace LousPartingThoughts
    {
        static constexpr uint32 SummonThugs = 1;
        static constexpr uint32 ThugSay0 = 2;
        static constexpr uint32 ThugSay1 = 3;
        static constexpr uint32 ThugSay2 = 4;
        static constexpr uint32 ThugSay3 = 5;
        static constexpr uint32 ThugSay4 = 6;
        static constexpr uint32 ThugSay5 = 7;
        static constexpr uint32 ThugSay6 = 8;
        static constexpr uint32 ThugCredit = 9;
        static constexpr uint32 ThugShoot1 = 10;
        static constexpr uint32 ThugShoot2 = 11;
        static constexpr uint32 ThugScream = 12;
        static constexpr uint32 ThugWarning = 13;
        static constexpr uint32 HustlerSay0 = 14;
        static constexpr uint32 HustlerSay1 = 15;
        static constexpr uint32 HustlerEventReset = 16;
    }
    namespace WestfallStew
    {
        static constexpr uint32 StewEventStart = 1;
        static constexpr uint32 MoveToStew = 2;
        static constexpr uint32 ReturnToHome = 3;
    }
}

namespace Actions
{
    namespace MurderWasTheCaseThatTheyGaveMe
    {
        static constexpr uint32 HoboAggroAction = 1;
        static constexpr uint32 HoboAggroActionDone = 2;
    }
    namespace LousPartingThoughts
    {
        static constexpr uint32 ThugReset = 1;
    }
}

namespace Data
{
    static constexpr uint32 DataThugDeath = 1;
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
    namespace ThugText
    {
        static constexpr uint32 ThugSay0 = 0;
        static constexpr uint32 ThugSay1 = 1;
        static constexpr uint32 ThugSay2 = 2;
        static constexpr uint32 ThugSay3 = 3;
        static constexpr uint32 ThugSay4 = 4;
        static constexpr uint32 ThugSay5 = 5;
        static constexpr uint32 ThugSay6 = 6;
        static constexpr uint32 SayWarning = 0;
    }
    namespace SmallTimeHustlerText
    {
        static constexpr uint32 HustlerSay0 = 0;
        static constexpr uint32 HustlerSay1 = 1;
    }
    namespace HomelessCitizenText
    {
        static constexpr uint32 HomelessCitizenSayStew1 = 11;
        static constexpr uint32 HomelessCitizenSayStew2 = 12;
    }
    namespace TransientText
    {
        static constexpr uint32 TransientSayStew1 = 17;
    }
    namespace WestPlainDrifterText
    {
        static constexpr uint32 WestPlainDrifterSayStew1 = 11;
        static constexpr uint32 WestPlainDrifterFollowerSayStew1 = 6;
    }
}

namespace Sounds
{
    static constexpr uint32 Shooting = 15071;
    static constexpr uint32 Scream = 17852;
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
        if (roll_chance(clueGainChance))
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
                    if (roll_chance(50)) // prevent spam
                    {
                        if (roll_chance(70)) // chance to trigger simple talk event
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

// 5988 - Areatrigger
class at_westfall_two_shoed_lou_thugs : public AreaTriggerScript
{
public:
    at_westfall_two_shoed_lou_thugs() : AreaTriggerScript("at_westfall_two_shoed_lou_thugs") {}

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*at*/) override
    {
        if (player->IsAlive())
            if (player->GetQuestStatus(Quests::LousPartingThoughts) == QUEST_STATUS_INCOMPLETE)
                if (Creature* lousPartingThoughtsTrigger = player->FindNearestCreature(Creatures::LousPartingThoughtsTrigger, 50.0f, true))
                    lousPartingThoughtsTrigger->AI()->SetGUID(player->GetGUID(), 0);

        return true;
    }
};

// 42387 - Westfall Thug
struct npc_westfall_thug : public ScriptedAI
{
    npc_westfall_thug(Creature* creature) : ScriptedAI(creature) {}

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        if (TempSummon* summon = me->ToTempSummon())
            if (Creature* summoner = summon->GetSummonerCreatureBase())
                summoner->AI()->DoAction(Actions::LousPartingThoughts::ThugReset);

        me->DespawnOrUnsummon();
    }

    void JustDied(Unit* /*who*/) override
    {
        if (TempSummon* summon = me->ToTempSummon())
            if (Creature* summoner = summon->GetSummonerCreatureBase())
                summoner->AI()->SetData(0, Data::DataThugDeath);
    }
};

Position constexpr ThugPos[4] =
{
    { -9859.36f, 1332.42f, 41.9859f, 2.49582f  },
    { -9862.52f, 1332.08f, 41.9859f, 0.855211f },
    { -9863.49f, 1335.49f, 41.9859f, 5.63741f  },
    { -9860.43f, 1335.46f, 41.9859f, 4.11898f  },
};

// 42562 - Lous Parting Thoughts Trigger
struct npc_westfall_lous_parting_thoughts_trigger : public ScriptedAI
{
    npc_westfall_lous_parting_thoughts_trigger(Creature* creature) : ScriptedAI(creature), _summonGUIDs(), _thugDeathCount(0) {}

    void SetGUID(ObjectGuid const& guid, int32 /*id*/) override
    {
        if (!_eventInvokerGUID.IsEmpty())
            return;

        _eventInvokerGUID = guid;

        _events.ScheduleEvent(Events::LousPartingThoughts::ThugSay0, 0s);
    }

    void SetData(uint32 /*type*/, uint32 data) override
    {
        if (data == Data::DataThugDeath)
        {
            _thugDeathCount++;

            if (_thugDeathCount >= 4)
            {
                _events.ScheduleEvent(Events::LousPartingThoughts::ThugCredit, 0s);
                DoAction(Actions::LousPartingThoughts::ThugReset);
            }
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case Actions::LousPartingThoughts::ThugReset:
                _events.ScheduleEvent(Events::LousPartingThoughts::SummonThugs, 60s);
                break;
        }
    }

    void JustAppeared() override
    {
        _events.ScheduleEvent(Events::LousPartingThoughts::SummonThugs, 0s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);
        while (uint32 eventId = _events.ExecuteEvent())
        {
            Player* invoker = ObjectAccessor::GetPlayer(*me, _eventInvokerGUID);

            switch (eventId)
            {
                case Events::LousPartingThoughts::SummonThugs:
                    for (uint8 i = 0; i < 4; i++)
                    {
                        if (Creature* thug = me->SummonCreature(Creatures::Thug, ThugPos[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 60s))
                            _summonGUIDs[i] = thug->GetGUID();
                    }
                    _eventInvokerGUID = ObjectGuid::Empty;
                    _thugDeathCount = 0;
                    break;
                case Events::LousPartingThoughts::ThugSay0:
                {
                    Creature* thug1 = ObjectAccessor::GetCreature(*me, _summonGUIDs[0]);
                    if (invoker && thug1)
                        thug1->AI()->Talk(Text::ThugText::ThugSay0, invoker);
                    _events.ScheduleEvent(Events::LousPartingThoughts::ThugSay1, 5s);
                    break;
                }
                case Events::LousPartingThoughts::ThugSay1:
                {
                    Creature* thug2 = ObjectAccessor::GetCreature(*me, _summonGUIDs[1]);
                    if (invoker && thug2)
                        thug2->AI()->Talk(Text::ThugText::ThugSay1, invoker);
                    _events.ScheduleEvent(Events::LousPartingThoughts::ThugSay2, 5s);
                    break;
                }
                case Events::LousPartingThoughts::ThugSay2:
                {
                    Creature* thug2 = ObjectAccessor::GetCreature(*me, _summonGUIDs[1]);
                    if (invoker && thug2)
                        thug2->AI()->Talk(Text::ThugText::ThugSay2, invoker);
                    _events.ScheduleEvent(Events::LousPartingThoughts::ThugSay3, 8s + 500ms);
                    break;
                }
                case Events::LousPartingThoughts::ThugSay3:
                {
                    Creature* thug3 = ObjectAccessor::GetCreature(*me, _summonGUIDs[2]);
                    if (invoker && thug3)
                        thug3->AI()->Talk(Text::ThugText::ThugSay3, invoker);
                    _events.ScheduleEvent(Events::LousPartingThoughts::ThugSay4, 5s);
                    break;
                }
                case Events::LousPartingThoughts::ThugSay4:
                {
                    Creature* thug1 = ObjectAccessor::GetCreature(*me, _summonGUIDs[0]);
                    if (invoker && thug1)
                    {
                        thug1->AI()->Talk(Text::ThugText::ThugSay4, invoker);

                        for (ObjectGuid const& guid : _summonGUIDs)
                            if (Creature* thug = ObjectAccessor::GetCreature(*me, guid))
                                thug->SetFacingToObject(invoker);
                    }

                    _events.ScheduleEvent(Events::LousPartingThoughts::ThugSay5, 8s + 500ms);
                    break;
                }
                case Events::LousPartingThoughts::ThugSay5:
                {
                    Creature* thug1 = ObjectAccessor::GetCreature(*me, _summonGUIDs[0]);
                    if (invoker && thug1)
                        thug1->AI()->Talk(Text::ThugText::ThugSay5, invoker);

                    _events.ScheduleEvent(Events::LousPartingThoughts::ThugSay6, 5s);
                    break;
                }
                case Events::LousPartingThoughts::ThugSay6:
                {
                    Creature* thug1 = ObjectAccessor::GetCreature(*me, _summonGUIDs[0]);
                    if (invoker && thug1)
                    {
                        thug1->AI()->Talk(Text::ThugText::ThugSay6, invoker);

                        for (ObjectGuid const& guid : _summonGUIDs)
                            if (Creature* thug = ObjectAccessor::GetCreature(*me, guid))
                            {
                                thug->SetImmuneToAll(false);
                                thug->AI()->AttackStart(invoker);
                            }
                    }
                    break;
                }
                case Events::LousPartingThoughts::ThugCredit:
                {
                    if (invoker)
                    {
                        invoker->CastSpell(invoker, Spells::HoboInformation, TriggerCastFlags(TRIGGERED_FULL_MASK));
                        /*
                        if (Group* group = invoker->GetGroup())
                        {
                            for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                            {
                                Player* groupMember = itr->GetSource();
                                if (groupMember && groupMember->IsInMap(invoker) && groupMember->GetQuestStatus(Quests::LousPartingThoughts) == QUEST_STATUS_INCOMPLETE && groupMember->GetDistance(me) <= 75.f)
                                {
                                    groupMember->CastSpell(groupMember, Spells::HoboInformation, TriggerCastFlags(TRIGGERED_FULL_MASK));
                                }
                            }
                        }
                        */
                    }
                    _events.ScheduleEvent(Events::LousPartingThoughts::ThugShoot1, 1s + 500ms);
                    break;
                }
                case Events::LousPartingThoughts::ThugShoot1:
                {
                    if (invoker)
                        me->PlayDistanceSound(Sounds::Shooting, invoker);

                    _events.ScheduleEvent(Events::LousPartingThoughts::ThugShoot2, 1s + 200ms);
                    break;
                }
                case Events::LousPartingThoughts::ThugShoot2:
                {
                    if (invoker)
                        me->PlayDistanceSound(Sounds::Shooting, invoker);

                    _events.ScheduleEvent(Events::LousPartingThoughts::ThugScream, 1s + 200ms);
                    break;
                }
                case Events::LousPartingThoughts::ThugScream:
                {
                    if (invoker)
                        me->PlayDistanceSound(Sounds::Scream, invoker);

                    _events.ScheduleEvent(Events::LousPartingThoughts::ThugWarning, 2s + 500ms);
                    break;
                }
                case Events::LousPartingThoughts::ThugWarning:
                {
                    if (invoker)
                        Talk(Text::ThugText::SayWarning, invoker);
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    ObjectGuid _eventInvokerGUID;
    std::array<ObjectGuid, 4> _summonGUIDs;
    uint32 _thugDeathCount;
};

// 42390 - Areatrigger
class at_westfall_small_time_hustler : public AreaTriggerScript
{
public:
    at_westfall_small_time_hustler() : AreaTriggerScript("at_westfall_small_time_hustler") {}

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*at*/) override
    {
        if (player->IsAlive())
            if (Creature* lousPartingThoughtsTrigger = player->FindNearestCreature(Creatures::SmallTimeHustler, 10.0f, true))
                lousPartingThoughtsTrigger->AI()->SetGUID(player->GetGUID(), 0);

        return true;
    }
};

// 42390 - Small Time Hustler
struct npc_westfall_small_time_hustler : public ScriptedAI
{
    npc_westfall_small_time_hustler(Creature* creature) : ScriptedAI(creature) {}

    void SetGUID(ObjectGuid const& guid, int32 /*id*/) override
    {
        if (!_eventInvokerGUID.IsEmpty())
            return;

        _eventInvokerGUID = guid;

        _events.ScheduleEvent(Events::LousPartingThoughts::HustlerSay0, 0s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);
        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case Events::LousPartingThoughts::HustlerSay0:
                {
                    Player* invoker = ObjectAccessor::GetPlayer(*me, _eventInvokerGUID);
                    if (invoker)
                    {
                        me->SetFacingToObject(invoker);
                        Talk(Text::SmallTimeHustlerText::HustlerSay0, invoker);
                        _events.ScheduleEvent(Events::LousPartingThoughts::HustlerSay1, 4s);
                    }
                    break;
                }
                case Events::LousPartingThoughts::HustlerSay1:
                {
                    Player* invoker = ObjectAccessor::GetPlayer(*me, _eventInvokerGUID);
                    if (invoker)
                    {
                        Talk(Text::SmallTimeHustlerText::HustlerSay1, invoker);
                        _events.ScheduleEvent(Events::LousPartingThoughts::HustlerEventReset, 60s);
                    }
                    break;
                }
                case Events::LousPartingThoughts::HustlerEventReset:
                {
                    _eventInvokerGUID = ObjectGuid::Empty;
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    ObjectGuid _eventInvokerGUID;
};

// 42617 - Westfall Stew
struct npc_westfall_westfall_stew : public ScriptedAI
{
    npc_westfall_westfall_stew(Creature* creature) : ScriptedAI(creature) {}

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (summoner->GetTypeId() == TYPEID_PLAYER)
        {
            std::vector<Creature*> homelessCitizens;
            me->GetCreatureListWithEntryInGrid(homelessCitizens, Creatures::HomelessStormwindCitizen1, 8.f);
            me->GetCreatureListWithEntryInGrid(homelessCitizens, Creatures::HomelessStormwindCitizen2, 8.f);
            me->GetCreatureListWithEntryInGrid(homelessCitizens, Creatures::Transient, 8.f);
            me->GetCreatureListWithEntryInGrid(homelessCitizens, Creatures::WestPlainDrifter, 8.f);
            me->GetCreatureListWithEntryInGrid(homelessCitizens, Creatures::WestPlainDrifterFollower, 8.f);
            for (Creature* homelessCitizen : homelessCitizens)
            {
                if (homelessCitizen->HasAura(Spells::FullBelly))
                    continue;

                homelessCitizen->AI()->SetGUID(me->GetGUID(), 0);
            }
        }
    }
};

// 42386 - Homeless Stormwind Citizen
// 42384 - Homeless Stormwind Citizen
struct npc_westfall_homless_stormwind_citizen : public ScriptedAI
{
    npc_westfall_homless_stormwind_citizen(Creature* creature) : ScriptedAI(creature) {}

    void SetGUID(ObjectGuid const& guid, int32 /*id*/) override
    {
        if (!_westfallStewGUID.IsEmpty())
            return;

        _westfallStewGUID = guid;

        _events.ScheduleEvent(Events::WestfallStew::StewEventStart, 0s);
    }

    void MovementInform(uint32 MotionType, uint32 PointId) override
    {
        if ((MotionType == POINT_MOTION_TYPE) && (PointId == 1))
        {
            me->CastSpell(me, Spells::FullBelly);

            if (Creature* stew = ObjectAccessor::GetCreature(*me, _westfallStewGUID))
            {
                if (Unit* summoner = stew->ToTempSummon()->GetSummonerCreatureBase())
                   if (Player* player = summoner->ToPlayer())
                       player->KilledMonsterCredit(Creatures::WestfallStew);

                if (urand(0, 1) == 0)
                {
                    switch (me->GetEntry())
                    {
                        case Creatures::HomelessStormwindCitizen1:
                        Talk(Text::HomelessCitizenText::HomelessCitizenSayStew1, stew);
                        break;
                        case Creatures::HomelessStormwindCitizen2:
                        Talk(Text::HomelessCitizenText::HomelessCitizenSayStew2, stew);
                        break;
                        case Creatures::Transient:
                        Talk(Text::TransientText::TransientSayStew1, stew);
                        break;
                        case Creatures::WestPlainDrifter:
                        Talk(Text::WestPlainDrifterText::WestPlainDrifterSayStew1, stew);
                        break;
                        case Creatures::WestPlainDrifterFollower:
                        Talk(Text::WestPlainDrifterText::WestPlainDrifterFollowerSayStew1, stew);
                        break;
                    default:
                        break;
                    }
                }
            }
            _events.ScheduleEvent(Events::WestfallStew::ReturnToHome, 5s + 500ms);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);
        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
            case Events::WestfallStew::StewEventStart:
            {
                me->SetStandState(UNIT_STAND_STATE_STAND);

                if (me->HasAura(Spells::CosmeticSleep))
                    me->RemoveAurasDueToSpell(Spells::CosmeticSleep);

                _events.ScheduleEvent(Events::WestfallStew::MoveToStew, 2s);
                break;
            }
            case Events::WestfallStew::MoveToStew:
            {
                Creature* stew = ObjectAccessor::GetCreature(*me, _westfallStewGUID);
                if (stew)
                {
                    float x, y, z;
                    stew->GetContactPoint(me, x, y, z, 0.2f);
                    me->GetMotionMaster()->MovePoint(1, x, y, z);
                }
                else
                    me->GetMotionMaster()->MoveTargetedHome();
                break;
            }
            case Events::WestfallStew::ReturnToHome:
            {
                me->GetMotionMaster()->MoveTargetedHome();
                break;
            }
            default:
                break;
            }
        }
        if (!UpdateVictim())
            return;
    }

private:
    EventMap _events;
    ObjectGuid _westfallStewGUID;
};

// 42391 - Westfall Plain Drifter
struct npc_westfall_west_plains_drifter : public ScriptedAI
{
    npc_westfall_west_plains_drifter(Creature* creature) : ScriptedAI(creature) {}

    void SetGUID(ObjectGuid const& guid, int32 /*id*/) override
    {
        if (!_westfallStewGUID.IsEmpty())
            return;

        _westfallStewGUID = guid;
        _events.ScheduleEvent(Events::WestfallStew::StewEventStart, 0s);
    }

    void MovementInform(uint32 motionType, uint32 pointId) override
    {
        if (motionType != POINT_MOTION_TYPE || pointId != 1)
            return;

        me->CastSpell(me, Spells::FullBelly);

        if (Creature* stew = ObjectAccessor::GetCreature(*me, _westfallStewGUID))
        {
            // Should never happen, unless the stew has been spawned via db which indicates dirty db data
            if (!stew->IsSummon())
                return;

            if (Unit* summoner = stew->ToTempSummon()->GetSummonerCreatureBase())
                if (Player* player = summoner->ToPlayer())
                    player->KilledMonsterCredit(Creatures::WestfallStew);

            if (urand(0, 1) == 0)
            {
                switch (me->GetEntry())
                {
                    case Creatures::HomelessStormwindCitizen1:
                    Talk(Text::HomelessCitizenText::HomelessCitizenSayStew1, stew);
                    break;
                    case Creatures::HomelessStormwindCitizen2:
                    Talk(Text::HomelessCitizenText::HomelessCitizenSayStew2, stew);
                    break;
                    case Creatures::Transient:
                    Talk(Text::TransientText::TransientSayStew1, stew);
                    break;
                    case Creatures::WestPlainDrifter:
                    Talk(Text::WestPlainDrifterText::WestPlainDrifterSayStew1, stew);
                    break;
                    case Creatures::WestPlainDrifterFollower:
                    Talk(Text::WestPlainDrifterText::WestPlainDrifterFollowerSayStew1, stew);
                    break;
                default:
                    break;
                }
            }
        }
        _events.ScheduleEvent(Events::WestfallStew::ReturnToHome, 5s + 500ms);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);
        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
            case Events::WestfallStew::StewEventStart:
                me->SetStandState(UNIT_STAND_STATE_STAND);

                if (me->HasAura(Spells::CosmeticSleep))
                    me->RemoveAurasDueToSpell(Spells::CosmeticSleep);

                _events.ScheduleEvent(Events::WestfallStew::MoveToStew, 2s);
                break;
            case Events::WestfallStew::MoveToStew:
                if (Creature* stew = ObjectAccessor::GetCreature(*me, _westfallStewGUID))
                {
                    float x, y, z;
                    stew->GetContactPoint(me, x, y, z, 0.2f);
                    me->GetMotionMaster()->MovePoint(1, x, y, z);
                }
                else
                    me->GetMotionMaster()->MoveTargetedHome();
                break;
                case Events::WestfallStew::ReturnToHome:
                me->GetMotionMaster()->MoveTargetedHome();
                break;
            default:
                break;
            }
        }
        if (!UpdateVictim())
            return;
    }

private:
    EventMap _events;
    ObjectGuid _westfallStewGUID;
};
}

void AddSC_westfall()
{
    using namespace Scripts::EasternKingdoms::Westfall;

    // Creature
    RegisterCreatureAI(npc_westfall_overloaded_harvest_golem);
    RegisterCreatureAI(npc_westfall_hobo_witness);
    RegisterCreatureAI(npc_westfall_thug);
    RegisterCreatureAI(npc_westfall_lous_parting_thoughts_trigger);
    RegisterCreatureAI(npc_westfall_small_time_hustler);
    RegisterCreatureAI(npc_westfall_westfall_stew);
    RegisterCreatureAI(npc_westfall_homless_stormwind_citizen);
    RegisterCreatureAI(npc_westfall_west_plains_drifter);

    // Areatrigger
    new at_westfall_two_shoed_lou_thugs();
    new at_westfall_small_time_hustler();

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
