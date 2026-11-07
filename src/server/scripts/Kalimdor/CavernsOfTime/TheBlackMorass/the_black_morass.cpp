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
 * Movement for Shadow Council Enforcer is NYI
 * All visuals around Medivh are NYI (see creatures spawned around Medivh)
 * Timers at which we summon portals requires to be revisited
 * The way we summon portals may be not entirely correct and requires additional research
   Current handling is:
    1. First portal is opened when event starts (correct)
    2. When Rift Lord or Rift Keeper is defeated, next portal is spawned after 0-5s (timer seems correct)
    3. When we summon boss, we summon no more portals until boss is defeated (seems to be correct)
    4. We summon next portal even if previous was not closed. We can have maximum 5 normal portals + 1 boss portal active at once (to be verified)
    5. We summon no new portal imediately after closing any portal if we already have more than one portal active(to be verified)
 */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "the_black_morass.h"

enum MedivhBlackMorassTexts
{
    // Medivh
    SAY_ENTER                            = 0,
    SAY_SHIELD_75                        = 1,
    SAY_SHIELD_50                        = 2,
    SAY_SHIELD_25                        = 3,
    SAY_WIN                              = 4,
    SAY_DEATH                            = 5,
    SAY_ORCS                             = 6,

    // Shadow Council Enforcer
    SAY_RETREAT                          = 0
};

enum MedivhBlackMorassSpells
{
    // Medivh
    SPELL_MANA_SHIELD                    = 31635,
    SPELL_MEDIVH_CHANNEL                 = 31556,
    SPELL_QUIET_SUICIDE                  = 3617,

    // Dark Portal Dummy 1.30
    SPELL_PORTAL_RUNE                    = 32570,    // NYI

    // Dark Portal Black Crystal Invisible Stalker
    SPELL_BLACK_CRYSTAL                  = 32563,    // NYI

    // Dark Portal Dummy
    SPELL_PORTAL_CRYSTAL                 = 32564,    // NYI

    // Dark Portal Beam Invisible Stalker
    SPELL_BANISH_PURPLE                  = 32566,    // NYI

    // Time Rift
    SPELL_TIME_RIFT_PERIODIC             = 31320,

    // NYI
    SPELL_SUMMON_TIME_RIFT_PERIODIC_90   = 31353,
    SPELL_SUMMON_TIME_RIFT_PERIODIC_120  = 31632,
    SPELL_SUMMON_TIME_RIFT_PERIODIC_45   = 31636,
    SPELL_SUMMON_TIME_RIFT_PERIODIC_75   = 31637,
    SPELL_SUMMON_TIME_RIFT_PERIODIC_30   = 34188,
    SPELL_SUMMON_TIME_RIFT_PERIODIC_5    = 35143,
    SPELL_SUMMON_TIME_RIFT               = 39041,
    SPELL_TIME_RIFT_1_READY              = 39570,
    SPELL_TIME_RIFT_2_READY              = 39571,
    SPELL_TIME_RIFT_3_READY              = 39572,
    SPELL_TIME_RIFT_4_READY              = 39573,
    SPELL_TIME_RIFT_READY_PRIMER         = 31352,
    SPELL_MEDIVH_LIVES                   = 31395,
    SPELL_MEDIVH_DIES                    = 31327,
    SPELL_MEDIVH_SHIELD                  = 32613,

    // Scripts
    SPELL_TIME_RIFT_CHANNEL              = 31387,
    SPELL_DRAGON_HELPER_EFFECT           = 31483,
    SPELL_CLOSE_TIME_RIFT_EFFECT         = 31323,

    SPELL_SUMMON_RIFT_LORD               = 31321,
    SPELL_SUMMON_RIFT_LORD_2             = 36234,
    SPELL_SUMMON_RIFT_KEEPER             = 36235,
    SPELL_SUMMON_RIFT_KEEPER_2           = 36236,

    SPELL_SUMMON_INFINITE_WHELP          = 37606,
    SPELL_SUMMON_INFINITE_ASSASSIN       = 31318,
    SPELL_SUMMON_INFINITE_ASSASSIN_2     = 36229,
    SPELL_SUMMON_INFINITE_CHRONOMANCER   = 31421,
    SPELL_SUMMON_INFINITE_CHRONOMANCER_2 = 36231,
    SPELL_SUMMON_INFINITE_EXECUTIONER    = 33363,
    SPELL_SUMMON_INFINITE_EXECUTIONER_2  = 36232,
    SPELL_SUMMON_INFINITE_VANQUISHER     = 33364,
    SPELL_SUMMON_INFINITE_VANQUISHER_2   = 36233,

    SPELL_SUMMON_CHRONO_LORD_DEJA        = 31391,
    SPELL_SUMMON_TEMPORUS                = 31392,
    SPELL_SUMMON_AEONUS                  = 31393,
    SPELL_SUMMON_INFINITE_CHRONO_LORD    = 37177,
    SPELL_SUMMON_INFINITE_TIMEREAVER     = 37178
};

enum MedivhBlackMorassEvents
{
    EVENT_EPILOGUE_1                     = 1,
    EVENT_EPILOGUE_2,
    EVENT_EPILOGUE_3,
    EVENT_EPILOGUE_4,
    EVENT_EPILOGUE_5,
    EVENT_EPILOGUE_6,
    EVENT_EPILOGUE_7,
    EVENT_EPILOGUE_8
};

enum MedivhBlackMorassMisc
{
    ACTION_START_EVENT                   = 0,
    GO_DARK_PORTAL                       = 185103,
    SPAWN_GROUP_ENFORCERS_1              = 377,
    SPAWN_GROUP_ENFORCERS_2              = 378,
    SPAWN_GROUP_ENFORCERS_3              = 379,
    SPAWN_GROUP_ENFORCERS_4              = 380
};

// 15608 - Medivh
struct npc_medivh_bm : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void JustAppeared() override
    {
        DoCastSelf(SPELL_MANA_SHIELD);
        DoCastSelf(SPELL_MEDIVH_CHANNEL);
        me->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_EVENT:
                Talk(SAY_ENTER);
                DoCastSelf(SPELL_MEDIVH_CHANNEL);
                break;
            case ACTION_SHIELD_75:
                Talk(SAY_SHIELD_75);
                break;
            case ACTION_SHIELD_50:
                Talk(SAY_SHIELD_50);
                break;
            case ACTION_SHIELD_25:
                Talk(SAY_SHIELD_25);
                break;
            case ACTION_SHIELD_0:
                DoDespawnSpawns();
                DoCastSelf(SPELL_QUIET_SUICIDE, true);
                break;
            case ACTION_EPILOGUE:
                _events.ScheduleEvent(EVENT_EPILOGUE_1, 0s);
                break;
            default:
                break;
        }
    }

    void DoDespawnSpawns()
    {
        std::vector<Creature*> spawns;

        GetCreatureListWithEntryInGrid(spawns, me, NPC_TIME_RIFT, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_RIFT_LORD, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_RIFT_LORD_ALT, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_RIFT_KEEPER, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_RIFT_KEEPER_ALT, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_CRONO_LORD_DEJA, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_TEMPORUS, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_AEONUS, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_INFINITE_CHRONO_LORD, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_INFINITE_TIMEREAVER, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_INFINITE_WHELP, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_INFINITE_ASSASIN, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_INFINITE_ASSASIN_ALT, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_INFINITE_CRONOMANCER, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_INFINITE_CRONOMANCER_ALT, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_INFINITE_EXECUTIONER, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_INFINITE_EXECUTIONER_ALT, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_INFINITE_VANQUISHER, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_INFINITE_VANQUISHER_ALT, 500.0f);

        for (Creature* spawn : spawns)
            if (spawn->IsAlive())
                spawn->DespawnOrUnsummon();
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_EPILOGUE_1:
                    // Guessed. What should happen if portals weren't closed but Aeonus was defeated and epilogue was triggered?
                    DoDespawnSpawns();
                    me->RemoveAurasDueToSpell(SPELL_MEDIVH_CHANNEL);
                    _events.ScheduleEvent(EVENT_EPILOGUE_2, 10s);
                    break;
                case EVENT_EPILOGUE_2:
                    me->SetFacingTo(6.2657318115234375f);
                    Talk(SAY_WIN);
                    me->SetImmuneToPC(false);
                    me->SetEmoteState(EMOTE_STATE_TALK);
                    me->SummonGameObject(GO_DARK_PORTAL, -2087.3372f, 7125.657f, 29.942312f, 6.143561f, QuaternionData(0.f, 0.f, -0.069755554f, 0.99756414f), 0s);
                    _events.ScheduleEvent(EVENT_EPILOGUE_3, 18s);
                    break;
                case EVENT_EPILOGUE_3:
                    me->SetFacingTo(3.001966238021850585f);
                    me->SetEmoteState(EMOTE_ONESHOT_NONE);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    _events.ScheduleEvent(EVENT_EPILOGUE_4, 1s);
                    break;
                case EVENT_EPILOGUE_4:
                    me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_ENFORCERS_1);
                    _events.ScheduleEvent(EVENT_EPILOGUE_5, 2s);
                    break;
                case EVENT_EPILOGUE_5:
                    me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_ENFORCERS_2);
                    _events.ScheduleEvent(EVENT_EPILOGUE_6, 2400ms);
                    break;
                case EVENT_EPILOGUE_6:
                    me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_ENFORCERS_3);
                    _events.ScheduleEvent(EVENT_EPILOGUE_7, 2400ms);
                    break;
                case EVENT_EPILOGUE_7:
                    me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_ENFORCERS_4);
                    _events.ScheduleEvent(EVENT_EPILOGUE_8, 8s);
                    break;
                case EVENT_EPILOGUE_8:
                    Talk(SAY_ORCS);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

// 17838 - Time Rift
struct npc_time_rift : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void JustAppeared() override
    {
        DoCastSelf(SPELL_TIME_RIFT_PERIODIC);
    }
};

// 31326 - Corrupt Medivh
class spell_black_morass_corrupt_medivh : public AuraScript
{
    PrepareAuraScript(spell_black_morass_corrupt_medivh);

    void OnPeriodic(AuraEffect const* aurEff)
    {
        if (aurEff->GetTickNumber() % 3)
            if (InstanceScript* instance = GetTarget()->GetInstanceScript())
                instance->SetData(DATA_SHIELD_PCT, SPECIAL);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_black_morass_corrupt_medivh::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 37853 - Corrupt Medivh
class spell_black_morass_corrupt_medivh_aeonus : public AuraScript
{
    PrepareAuraScript(spell_black_morass_corrupt_medivh_aeonus);

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (InstanceScript* instance = GetTarget()->GetInstanceScript())
            instance->SetData(DATA_SHIELD_PCT, SPECIAL);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_black_morass_corrupt_medivh_aeonus::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 31388 - Time Rift Channel Trigger
class spell_black_morass_time_rift_channel_trigger : public SpellScript
{
    PrepareSpellScript(spell_black_morass_time_rift_channel_trigger);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TIME_RIFT_CHANNEL });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (TempSummon* summon = GetCaster()->ToTempSummon())
            if (Unit* summoner = summon->GetSummonerUnit())
                summoner->CastSpell(summon, SPELL_TIME_RIFT_CHANNEL);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_black_morass_time_rift_channel_trigger::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 31550 - Banish Dragon Helper
class spell_black_morass_banish_dragon_helper : public SpellScript
{
    PrepareSpellScript(spell_black_morass_banish_dragon_helper);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRAGON_HELPER_EFFECT });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(nullptr, SPELL_DRAGON_HELPER_EFFECT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_black_morass_banish_dragon_helper::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 31322 - Close Time Rift Trigger
class spell_black_morass_close_time_rift_trigger : public SpellScript
{
    PrepareSpellScript(spell_black_morass_close_time_rift_trigger);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CLOSE_TIME_RIFT_EFFECT });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (TempSummon* summon = GetCaster()->ToTempSummon())
            if (Unit* summoner = summon->GetSummonerUnit())
                summon->CastSpell(summoner, SPELL_CLOSE_TIME_RIFT_EFFECT);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_black_morass_close_time_rift_trigger::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 31323 - Close Time Rift Effect
class spell_black_morass_close_time_rift_effect : public SpellScript
{
    PrepareSpellScript(spell_black_morass_close_time_rift_effect);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creature = GetHitUnit()->ToCreature())
            creature->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_black_morass_close_time_rift_effect::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 31320 - Time Rift Periodic
class spell_black_morass_time_rift_periodic : public AuraScript
{
    PrepareAuraScript(spell_black_morass_time_rift_periodic);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SUMMON_RIFT_LORD,
            SPELL_SUMMON_RIFT_LORD_2,
            SPELL_SUMMON_RIFT_KEEPER,
            SPELL_SUMMON_RIFT_KEEPER_2,
            SPELL_SUMMON_INFINITE_WHELP,
            SPELL_SUMMON_INFINITE_ASSASSIN,
            SPELL_SUMMON_INFINITE_ASSASSIN_2,
            SPELL_SUMMON_INFINITE_CHRONOMANCER,
            SPELL_SUMMON_INFINITE_CHRONOMANCER_2,
            SPELL_SUMMON_INFINITE_EXECUTIONER,
            SPELL_SUMMON_INFINITE_EXECUTIONER_2,
            SPELL_SUMMON_INFINITE_VANQUISHER,
            SPELL_SUMMON_INFINITE_VANQUISHER_2,
            SPELL_SUMMON_CHRONO_LORD_DEJA,
            SPELL_SUMMON_TEMPORUS,
            SPELL_SUMMON_AEONUS,
            SPELL_SUMMON_INFINITE_CHRONO_LORD,
            SPELL_SUMMON_INFINITE_TIMEREAVER
        });
    }

    bool Load() override
    {
        if (InstanceScript* instance = GetOwner()->GetInstanceScript())
        {
            _instance = instance;

            _riftCount = instance->GetData(DATA_RIFT_COUNT);

            if (_riftCount < 7)
                _riftWaveId = 0;
            else if (_riftCount > 6 && _riftCount < 13)
                _riftWaveId = 1;
            else if (_riftCount > 12)
                _riftWaveId = 2;

            return true;
        }

        return false;
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        if (_isLastRift)
            return;

        Unit* target = GetTarget();

        if (_isFirstSummon)
        {
            switch (_riftCount)
            {
                case 6:
                    target->CastSpell(nullptr, (_instance->GetBossState(DATA_DEJA) == DONE && target->GetMap()->IsHeroic()) ?
                        SPELL_SUMMON_INFINITE_CHRONO_LORD : SPELL_SUMMON_CHRONO_LORD_DEJA, true);
                    break;
                case 12:
                    target->CastSpell(nullptr, (_instance->GetBossState(DATA_TEMPORUS) == DONE && target->GetMap()->IsHeroic()) ?
                        SPELL_SUMMON_INFINITE_TIMEREAVER : SPELL_SUMMON_TEMPORUS, true);
                    break;
                case 18:
                    target->CastSpell(nullptr, SPELL_SUMMON_AEONUS, true);
                    _isLastRift = true;
                    break;
                default:
                    target->CastSpell(nullptr, RAND(SPELL_SUMMON_RIFT_LORD, SPELL_SUMMON_RIFT_LORD_2, SPELL_SUMMON_RIFT_KEEPER, SPELL_SUMMON_RIFT_KEEPER_2), true);
                    break;
            }

            _isFirstSummon = false;
            const_cast<AuraEffect*>(aurEff)->ResetTicks();
        }
        else
        {
            switch (_riftWaveId)
            {
                case 0:
                {
                    switch (aurEff->GetTickNumber())
                    {
                        case 1:
                            target->CastSpell(nullptr, RAND(SPELL_SUMMON_INFINITE_ASSASSIN, SPELL_SUMMON_INFINITE_ASSASSIN_2), true);
                            break;
                        case 2:
                            for (uint8 i = 0; i < 3; ++i)
                                target->CastSpell(nullptr, SPELL_SUMMON_INFINITE_WHELP, true);
                            break;
                        case 3:
                            target->CastSpell(nullptr, RAND(SPELL_SUMMON_INFINITE_CHRONOMANCER, SPELL_SUMMON_INFINITE_CHRONOMANCER_2), true);
                            const_cast<AuraEffect*>(aurEff)->ResetTicks();
                            break;
                        default:
                            break;
                    }
                    break;
                }
                case 1:
                {
                    switch (aurEff->GetTickNumber())
                    {
                        case 1:
                            target->CastSpell(nullptr, RAND(SPELL_SUMMON_INFINITE_EXECUTIONER, SPELL_SUMMON_INFINITE_EXECUTIONER_2), true);
                            break;
                        case 2:
                            target->CastSpell(nullptr, RAND(SPELL_SUMMON_INFINITE_CHRONOMANCER, SPELL_SUMMON_INFINITE_CHRONOMANCER_2), true);
                            break;
                        case 3:
                            for (uint8 i = 0; i < 3; ++i)
                                target->CastSpell(nullptr, SPELL_SUMMON_INFINITE_WHELP, true);
                            break;
                        case 4:
                            target->CastSpell(nullptr, RAND(SPELL_SUMMON_INFINITE_ASSASSIN, SPELL_SUMMON_INFINITE_ASSASSIN_2), true);
                            const_cast<AuraEffect*>(aurEff)->ResetTicks();
                            break;
                        default:
                            break;
                    }
                    break;
                }
                case 2:
                {
                    switch (aurEff->GetTickNumber())
                    {
                        case 1:
                            target->CastSpell(nullptr, RAND(SPELL_SUMMON_INFINITE_EXECUTIONER, SPELL_SUMMON_INFINITE_EXECUTIONER_2), true);
                            break;
                        case 2:
                            target->CastSpell(nullptr, RAND(SPELL_SUMMON_INFINITE_VANQUISHER, SPELL_SUMMON_INFINITE_VANQUISHER_2), true);
                            break;
                        case 3:
                            target->CastSpell(nullptr, RAND(SPELL_SUMMON_INFINITE_CHRONOMANCER, SPELL_SUMMON_INFINITE_CHRONOMANCER_2), true);
                            break;
                        case 4:
                            target->CastSpell(nullptr, RAND(SPELL_SUMMON_INFINITE_ASSASSIN, SPELL_SUMMON_INFINITE_ASSASSIN_2), true);
                            const_cast<AuraEffect*>(aurEff)->ResetTicks();
                            break;
                        default:
                            break;
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_black_morass_time_rift_periodic::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }

private:
    uint32 _riftCount = 0;
    uint32 _riftWaveId = 0;
    bool _isLastRift = false;
    bool _isFirstSummon = true;
    InstanceScript* _instance = nullptr;
};

// 4288
class at_black_morass_medivh : public AreaTriggerScript
{
    public:
        at_black_morass_medivh() : AreaTriggerScript("at_black_morass_medivh") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            if (InstanceScript* instance = player->GetInstanceScript())
            {
                if (instance->GetBossState(DATA_AEONUS) == DONE || instance->GetData(DATA_EVENT) == IN_PROGRESS || instance->GetData(DATA_EVENT) == DONE)
                    return false;

                if (Creature* medivh = instance->GetCreature(DATA_MEDIVH))
                {
                    if (medivh->IsAlive())
                    {
                        medivh->AI()->DoAction(ACTION_START_EVENT);
                        instance->SetData(DATA_EVENT, IN_PROGRESS);
                    }
                }

                return false;
            }
            return false;
        }
};

void AddSC_the_black_morass()
{
    RegisterBlackMorassCreatureAI(npc_medivh_bm);
    RegisterBlackMorassCreatureAI(npc_time_rift);
    RegisterSpellScript(spell_black_morass_corrupt_medivh);
    RegisterSpellScript(spell_black_morass_corrupt_medivh_aeonus);
    RegisterSpellScript(spell_black_morass_time_rift_channel_trigger);
    RegisterSpellScript(spell_black_morass_banish_dragon_helper);
    RegisterSpellScript(spell_black_morass_close_time_rift_trigger);
    RegisterSpellScript(spell_black_morass_close_time_rift_effect);
    RegisterSpellScript(spell_black_morass_time_rift_periodic);
    new at_black_morass_medivh();
}
