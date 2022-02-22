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
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QuestDef.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

/*######
## npc_daegarn
######*/

enum Daegarnn
{
    QUEST_DEFEAT_AT_RING = 11300,
    NPC_FIRJUS = 24213,
    NPC_JLARBORN = 24215,
    NPC_YOROS = 24214,
    NPC_OLUF = 23931,
    NPC_PRISONER_1 = 24253, // looks the same but has different abilities
    NPC_PRISONER_2 = 24254,
    NPC_PRISONER_3 = 24255,
    SAY_TEXT = 0
};

static Position const daegarnSummonPosition = { 838.81f, -4678.06f, -94.182f, 0.0f };
static Position const daegarnCenterPosition = { 801.88f, -4721.87f, -96.143f, 0.0f };

/// @todo make prisoners help (unclear if summoned or using npc's from surrounding cages (summon inside small cages?))
struct npc_daegarn : public ScriptedAI
{
    npc_daegarn(Creature* creature) : ScriptedAI(creature), _eventInProgress(false), _summons(creature)
    {
    }

    void Reset() override
    {
        _eventInProgress = false;
        _playerGUID.Clear();
        _scheduler.CancelAll();
        _summons.DespawnAll();

        _scheduler.Schedule(40s, [this](TaskContext context)
        {
            Talk(SAY_TEXT);
            context.Repeat(40s);
        });
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (!_EnterEvadeMode(why))
            return;

        if (!me->GetVehicle())
        {
            if (Unit* owner = me->GetCharmerOrOwner())
            {
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, me->GetFollowAngle());
            }
            else
            {
                me->AddUnitState(UNIT_STATE_EVADE);
                me->GetMotionMaster()->MoveTargetedHome();
            }
        }

        if (me->IsVehicle())
            me->GetVehicleKit()->Reset(true);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);

        if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
        {
            if (player->IsAlive())
            {
                summon->SetWalk(false);
                summon->SetHomePosition(daegarnCenterPosition);
                summon->GetMotionMaster()->MovePoint(0, daegarnCenterPosition);
                return;
            }
        }

        Reset();
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        _summons.Despawn(summon);
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        uint32 entry = 0;

        _summons.Despawn(summon);

        // will eventually reset the event if something goes wrong
        switch (summon->GetEntry())
        {
            case NPC_FIRJUS:
                entry = NPC_JLARBORN;
                break;
            case NPC_JLARBORN:
                entry = NPC_YOROS;
                break;
            case NPC_YOROS:
                entry = NPC_OLUF;
                break;
            case NPC_OLUF:
                Reset();
                return;
        }

        SummonGladiator(entry);
    }

    void OnQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_DEFEAT_AT_RING)
        {
            if (_eventInProgress)
                return;

            _eventInProgress = true;
            _playerGUID = player->GetGUID();
            _scheduler.CancelAll();
            _summons.DespawnAll();

            _scheduler.Schedule(20s, [this](TaskContext context)
            {
                bool reset = true;
                if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGUID))
                {
                    if (player->IsAlive() && player->IsEngaged())
                    {
                        for (auto itr = _summons.begin(); reset && itr != _summons.end(); ++itr)
                        {
                            Creature* summon = ObjectAccessor::GetCreature(*me, *_summons.begin());
                            if (summon && player->IsEngagedBy(summon))
                            {
                                context.Repeat(5s);
                                reset = false;
                            }
                        }
                    }
                }

                if (reset)
                    Reset();
            });

            SummonGladiator(NPC_FIRJUS);
        }
    }

private:
    void SummonGladiator(uint32 entry)
    {
        me->SummonCreature(entry, daegarnSummonPosition, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30s);
    }

    bool _eventInProgress;
    ObjectGuid _playerGUID;
    TaskScheduler _scheduler;
    SummonList _summons;
};

/*######
## Quest 11310: Warning: Some Assembly Required
######*/

enum SomeAssemblyRequired
{
    SPELL_PING_MASTER                          = 43393, // casted on owner after spawn, presumably has a spell script to force owner cast SPELL_MINDLESS_ABOMINATION_CONTROL (currently handled by linked spells)
    SPELL_MINDLESS_ABOMINATION_CONTROL         = 42168,

    SPELL_RANDOM_CIRCUMFERENCE_POINT_POISON    = 42266,
    SPELL_RANDOM_CIRCUMFERENCE_POINT_BONE      = 42267,
    SPELL_RANDOM_CIRCUMFERENCE_POINT_BONE_2    = 42274
};

struct npc_mindless_abomination : public ScriptedAI
{
    npc_mindless_abomination(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SetCorpseDelay(0, true);

        _scheduler.Schedule(1s, [this](TaskContext task)
        {
            if (!me->IsCharmedOwnedByPlayerOrPlayer())
                me->DespawnOrUnsummon();
            else
                task.Repeat();
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 42268 - Quest - Mindless Abomination Explosion FX Master
class spell_mindless_abomination_explosion_fx_master : public SpellScript
{
    PrepareSpellScript(spell_mindless_abomination_explosion_fx_master);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_RANDOM_CIRCUMFERENCE_POINT_POISON,
            SPELL_RANDOM_CIRCUMFERENCE_POINT_BONE,
            SPELL_RANDOM_CIRCUMFERENCE_POINT_BONE_2
        });
    }

    void HandleScript(SpellEffIndex /*eff*/)
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        for (uint8 i = 0; i < 11; ++i)
            caster->CastSpell(caster, SPELL_RANDOM_CIRCUMFERENCE_POINT_POISON);

        for (uint8 i = 0; i < 6; ++i)
            caster->CastSpell(caster, SPELL_RANDOM_CIRCUMFERENCE_POINT_BONE);

        for (uint8 i = 0; i < 4; ++i)
            caster->CastSpell(caster, SPELL_RANDOM_CIRCUMFERENCE_POINT_BONE_2);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mindless_abomination_explosion_fx_master::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quest 11296: Rivenwood Captives
######*/

enum RivenwoodCaptives
{
    SPELL_SUMMON_BABY_RIVEN_WIDOWS        = 43275,
    SPELL_SUMMON_DARKCLAW_BAT             = 43276,
    SPELL_SUMMON_FANGGORE_WORG            = 43277,
    SPELL_SUMMON_GJALERBRON_RUNECASTER    = 43278,
    SPELL_SUMMON_GJALERBRON_SLEEPWATCHER  = 43279,
    SPELL_SUMMON_GJALERBRON_WARRIOR       = 43280,
    SPELL_SUMMON_PUTRID_HORROR            = 43281,
    SPELL_SUMMON_WINTERSKORN_BERSERKER    = 43282,
    SPELL_SUMMON_WINTERSKORN_WOODSMAN     = 43283,
    SPELL_SUMMON_WINTERSKORN_TRIBESMAN    = 43284,
    SPELL_SUMMON_WINTERSKORN_ORACLE       = 43285,
    SPELL_SUMMON_FREED_MIST_WHISPER_SCOUT = 43289
};

std::array<uint32, 11> const CocoonSummonSpells =
{
    SPELL_SUMMON_BABY_RIVEN_WIDOWS,
    SPELL_SUMMON_DARKCLAW_BAT,
    SPELL_SUMMON_FANGGORE_WORG,
    SPELL_SUMMON_GJALERBRON_RUNECASTER,
    SPELL_SUMMON_GJALERBRON_SLEEPWATCHER,
    SPELL_SUMMON_GJALERBRON_WARRIOR,
    SPELL_SUMMON_PUTRID_HORROR,
    SPELL_SUMMON_WINTERSKORN_BERSERKER,
    SPELL_SUMMON_WINTERSKORN_WOODSMAN,
    SPELL_SUMMON_WINTERSKORN_TRIBESMAN,
    SPELL_SUMMON_WINTERSKORN_ORACLE
};

// 43288 - Rivenwood Captives: Player Not On Quest
class spell_rivenwood_captives_not_on_quest : public SpellScript
{
    PrepareSpellScript(spell_rivenwood_captives_not_on_quest);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(CocoonSummonSpells);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), Trinity::Containers::SelectRandomContainerElement(CocoonSummonSpells), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_rivenwood_captives_not_on_quest::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 43287 - Rivenwood Captives: Player On Quest
class spell_rivenwood_captives_on_quest : public SpellScript
{
    PrepareSpellScript(spell_rivenwood_captives_on_quest);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(CocoonSummonSpells) && ValidateSpellInfo({ SPELL_SUMMON_FREED_MIST_WHISPER_SCOUT });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        if (roll_chance_i(80))
            target->CastSpell(caster, Trinity::Containers::SelectRandomContainerElement(CocoonSummonSpells), true);
        else
            target->CastSpell(caster, SPELL_SUMMON_FREED_MIST_WHISPER_SCOUT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_rivenwood_captives_on_quest::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

/*######
## Quest 11317, 11322: The Cleansing
######*/

enum TheCleansing
{
    SPELL_CLEANSING_SOUL            = 43351,
    SPELL_SUMMON_INNER_TURMOIL      = 50167,
    SPELL_RECENT_MEDITATION         = 61720,
    SPELL_MIRROR_IMAGE_AURA         = 50218,

    QUEST_THE_CLEANSING_H           = 11317,
    QUEST_THE_CLEANSING_A           = 11322
};

// 43365 - The Cleansing: Shrine Cast
class spell_the_cleansing_shrine_cast : public SpellScript
{
    PrepareSpellScript(spell_the_cleansing_shrine_cast);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_RECENT_MEDITATION, SPELL_CLEANSING_SOUL }) &&
            sObjectMgr->GetQuestTemplate(QUEST_THE_CLEANSING_H) &&
            sObjectMgr->GetQuestTemplate(QUEST_THE_CLEANSING_A);
    }

    SpellCastResult CheckCast()
    {
        // Error is correct for quest check but may be not correct for aura and this may be a wrong place to send error
        if (Player* target = GetExplTargetUnit()->ToPlayer())
        {
            if (target->HasAura(SPELL_RECENT_MEDITATION) || (!(target->GetQuestStatus(QUEST_THE_CLEANSING_H) == QUEST_STATUS_INCOMPLETE ||
                target->GetQuestStatus(QUEST_THE_CLEANSING_A) == QUEST_STATUS_INCOMPLETE)))
            {
                Spell::SendCastResult(target, GetSpellInfo(), 0, SPELL_FAILED_FIZZLE);
                return SPELL_FAILED_FIZZLE;
            }
        }
        return SPELL_CAST_OK;
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_CLEANSING_SOUL, true);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_the_cleansing_shrine_cast::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_the_cleansing_shrine_cast::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 43351 - Cleansing Soul
class spell_the_cleansing_cleansing_soul : public AuraScript
{
    PrepareAuraScript(spell_the_cleansing_cleansing_soul);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_INNER_TURMOIL, SPELL_RECENT_MEDITATION });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SetStandState(UNIT_STAND_STATE_SIT);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetStandState(UNIT_STAND_STATE_STAND);
        target->CastSpell(target, SPELL_SUMMON_INNER_TURMOIL, true);
        target->CastSpell(target, SPELL_RECENT_MEDITATION, true);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_the_cleansing_cleansing_soul::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_the_cleansing_cleansing_soul::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 50217 - The Cleansing: Script Effect Player Cast Mirror Image
class spell_the_cleansing_mirror_image_script_effect : public SpellScript
{
    PrepareSpellScript(spell_the_cleansing_mirror_image_script_effect);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MIRROR_IMAGE_AURA });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_MIRROR_IMAGE_AURA);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_the_cleansing_mirror_image_script_effect::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 50238 - The Cleansing: Your Inner Turmoil's On Death Cast on Master
class spell_the_cleansing_on_death_cast_on_master : public SpellScript
{
    PrepareSpellScript(spell_the_cleansing_on_death_cast_on_master);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (TempSummon* casterSummon = GetCaster()->ToTempSummon())
            if (Unit* summoner = casterSummon->GetSummonerUnit())
                summoner->CastSpell(summoner, uint32(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_the_cleansing_on_death_cast_on_master::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quest 11472: The Way to His Heart...
######*/

enum TheWayToHisHeart
{
    SPELL_CREATE_TASTY_REEF_FISH   = 12602,
    SPELL_FISHED_UP_REEF_SHARK     = 20713
};

// 21014 - Anuniaq's Net
class spell_the_way_to_his_heart_anuniaq_net : public SpellScript
{
    PrepareSpellScript(spell_the_way_to_his_heart_anuniaq_net);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_CREATE_TASTY_REEF_FISH, SPELL_FISHED_UP_REEF_SHARK });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, roll_chance_i(75) ? SPELL_CREATE_TASTY_REEF_FISH : SPELL_FISHED_UP_REEF_SHARK, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_the_way_to_his_heart_anuniaq_net::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_howling_fjord()
{
    RegisterCreatureAI(npc_daegarn);
    RegisterCreatureAI(npc_mindless_abomination);
    RegisterSpellScript(spell_mindless_abomination_explosion_fx_master);
    RegisterSpellScript(spell_rivenwood_captives_not_on_quest);
    RegisterSpellScript(spell_rivenwood_captives_on_quest);
    RegisterSpellScript(spell_the_cleansing_shrine_cast);
    RegisterSpellScript(spell_the_cleansing_cleansing_soul);
    RegisterSpellScript(spell_the_cleansing_mirror_image_script_effect);
    RegisterSpellScript(spell_the_cleansing_on_death_cast_on_master);
    RegisterSpellScript(spell_the_way_to_his_heart_anuniaq_net);
}
