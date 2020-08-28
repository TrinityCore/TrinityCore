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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "GameObjectAI.h"
#include "GameObject.h"
#include "Spell.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "TemporarySummon.h"
#include "Map.h"
#include "MoveSplineInit.h"
#include "PassiveAI.h"
#include "Player.h"
#include "InstanceScript.h"
#include "blackwing_descent.h"

enum LordVictorNefarius
{
    // Spells
    SPELL_MOCKING_SHADOWS       = 91307,
    SPELL_TELEPORT_VISUAL_ONLY  = 41232,
    SPELL_SHADOW_WHIP           = 91304,

    // Texts
    SAY_INTRODUCTION            = 0,
    SAY_STOP_FEUD               = 1,
    SAY_PHASE_2                 = 2,
    SAY_CHIMAERON_LOST          = 3,
    SAY_ENTRANCE_INTRO_HEROIC   = 4,
    SAY_ENTRANCE_INTRO_NORMAL   = 5,
    SAY_MAGMAW_DEFEATED         = 6,
    SAY_OMNOTRON_DEFEATED       = 7,
    SAY_CHIMAERON_DEFEATED      = 8,
    SAY_ATRAMEDES_DEFEATED      = 9,
    SAY_MALORIAK_DEFEATED       = 10,

    // Actions
    ACTION_STOP_FEUD            = 1,
    ACTION_ENTER_PHASE_2        = 2,
    ACTION_CHIMAERON_DEFEATED   = 3,

    // Events
    EVENT_INTRODUCE_CHIMAERON   = 1,
    EVENT_MOCKING_SHADOWS,
    EVENT_TALK_CHIMAERON_DIED,
    EVENT_TELEPORT_AWAY,
    EVENT_TALK_INTRO_NORMAL,
    EVENT_TALK_INTRO_HEROIC,
    EVENT_TALK_BOSS_DEFEATED,

};

struct npc_bwd_lord_victor_nefarius : public NullCreatureAI
{
    npc_bwd_lord_victor_nefarius(Creature* creature) : NullCreatureAI(creature), _talkTextId(0) { }

    void IsSummonedBy(Unit* summoner) override
    {
        if (summoner && summoner->GetEntry() == BOSS_CHIMAERON)
        {
            _events.ScheduleEvent(EVENT_INTRODUCE_CHIMAERON, 4s);
            DoCastSelf(SPELL_TELEPORT_VISUAL_ONLY);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INTRODUCE_CHIMAERON:
                    Talk(SAY_INTRODUCTION);
                    break;
                case EVENT_MOCKING_SHADOWS:
                    Talk(SAY_PHASE_2);
                    DoCastSelf(SPELL_MOCKING_SHADOWS);
                    me->AddAura(SPELL_MOCKING_SHADOWS, me); // Tempfix until player only attribute spells accept creatures as original caster
                    break;
                case EVENT_TALK_CHIMAERON_DIED:
                    Talk(SAY_CHIMAERON_LOST);
                    _events.ScheduleEvent(EVENT_TELEPORT_AWAY, 6s);
                    break;
                case EVENT_TELEPORT_AWAY:
                    DoCastSelf(SPELL_TELEPORT_VISUAL_ONLY);
                    me->DespawnOrUnsummon(2s);
                    break;
                case EVENT_TALK_INTRO_NORMAL:
                    Talk(SAY_ENTRANCE_INTRO_NORMAL);
                    me->setActive(false);
                    break;
                case EVENT_TALK_INTRO_HEROIC:
                    Talk(SAY_ENTRANCE_INTRO_HEROIC);
                    _events.ScheduleEvent(EVENT_TELEPORT_AWAY, 6s);
                    break;
                case EVENT_TALK_BOSS_DEFEATED:
                    Talk(_talkTextId);
                    me->setActive(false);
                    break;
                default:
                    break;
            }
        }
    }

    void SetData(uint32 type, uint32 data) override
    {
        if (type == DATA_BOSS_DEFEATED && !me->GetMap()->IsHeroic())
        {
            me->setActive(true);
            switch (data)
            {
                case DATA_MAGMAW:                   _talkTextId = SAY_MAGMAW_DEFEATED; break;
                case DATA_OMNOTRON_DEFENSE_SYSTEM:  _talkTextId = SAY_OMNOTRON_DEFEATED; break;
                case DATA_CHIMAERON:                _talkTextId = SAY_CHIMAERON_DEFEATED; break;
                case DATA_ATRAMEDES:                _talkTextId = SAY_ATRAMEDES_DEFEATED; break;
                case DATA_MALORIAK:                 _talkTextId = SAY_MALORIAK_DEFEATED; break;
                default:
                    break;
            }
            _events.ScheduleEvent(EVENT_TALK_BOSS_DEFEATED, 15s);
        }
        else if (type == DATA_HEROES_ENTERED_HALLS)
        {
            me->setActive(true);
            if (me->GetMap()->IsHeroic())
            {
                DoCastSelf(SPELL_TELEPORT_VISUAL_ONLY);
                _events.ScheduleEvent(EVENT_TALK_INTRO_HEROIC, 3s);
            }
            else
                _events.ScheduleEvent(EVENT_TALK_INTRO_NORMAL, 12s);
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ENTER_PHASE_2:
                _events.ScheduleEvent(EVENT_MOCKING_SHADOWS, 1ms);
                break;
            case ACTION_CHIMAERON_DEFEATED:
                // This is only going to be triggered on heroic difficulty
                me->RemoveAllAurasExceptType(SPELL_AURA_DUMMY);
                _events.Reset();
                _events.ScheduleEvent(EVENT_TALK_CHIMAERON_DIED, 2s + 500ms);
                break;
            case ACTION_STOP_FEUD:
                Talk(SAY_STOP_FEUD);
                DoCastSelf(SPELL_SHADOW_WHIP);
                break;
            default:
                break;
        }
    }

private:
    EventMap _events;
    uint8 _talkTextId;
};

enum DrakonidChainWielder
{
    // Events
    EVENT_OVERHEAD_SMASH = 1,
    EVENT_GRIEVOUS_WOUND,
    EVENT_CONSTRICTING_CHAINS,

    // Spells
    SPELL_OVERHEAD_SMASH_SUMMON = 79578, // Serverside spell
    SPELL_OVERHEAD_SMASH        = 79580,
    SPELL_GRIEVOUS_WOUND        = 80051,
    SPELL_CONSTRICTING_CHAINS   = 79589
};

struct npc_bwd_drakonid_chainwielder : public ScriptedAI
{
    npc_bwd_drakonid_chainwielder(Creature* creature) : ScriptedAI(creature) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_GRIEVOUS_WOUND, 9s);
        _events.ScheduleEvent(EVENT_OVERHEAD_SMASH, 12s);
        _events.ScheduleEvent(EVENT_CONSTRICTING_CHAINS, 42s);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode(why);
        _events.Reset();
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_OVERHEAD_SMASH)
        {
            me->SetFacingToObject(summon);
            DoCast(summon, SPELL_OVERHEAD_SMASH);
        }
    }

    void JustDied(Unit* killer) override
    {
        ScriptedAI::JustDied(killer);
        _events.Reset();
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
                case EVENT_OVERHEAD_SMASH:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.f, true))
                        DoCast(target, SPELL_OVERHEAD_SMASH_SUMMON);
                    _events.Repeat(27s, 36s);
                    break;
                case EVENT_GRIEVOUS_WOUND:
                    DoCastVictim(SPELL_GRIEVOUS_WOUND);
                    _events.Repeat(22s, 25s);
                    break;
                case EVENT_CONSTRICTING_CHAINS:
                    DoCastAOE(SPELL_CONSTRICTING_CHAINS);
                    _events.Repeat(7s, 11s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

enum DwarvenSpirits
{
    // Spells
    SPELL_SPIRIT_OF_ANGERFORGE          = 80762,
    SPELL_SPIRIT_OF_IRONSTAR            = 80767,
    SPELL_SPIRIT_OF_THAURISSAN          = 80766,
    SPELL_SPIRIT_OF_BURNINGEYE          = 80770,
    SPELL_SPIRIT_OF_MOLTENFIST          = 80764,
    SPELL_SPIRIT_OF_ANVILRAGE           = 80768,
    SPELL_SPIRIT_OF_SHADOWFORGE         = 80769,
    SPELL_SPIRIT_OF_COREHAMMER          = 80763,

    SPELL_BESTOWAL_OF_THAURISSAN        = 80871,
    SPELL_BESTOWAL_OF_BURNINGEYE        = 80872,
    SPELL_BESTOWAL_OF_SHADOWFORGE       = 80873,
    SPELL_BESTOWAL_OF_ANVILRAGE         = 80874,
    SPELL_BESTOWAL_OF_IRONSTAR          = 80875,
    SPELL_BESTOWAL_OF_MOLTENFIST        = 80876,
    SPELL_BESTOWAL_OF_COREHAMMER        = 80877,
    SPELL_BESTOWAL_OF_ANGERFORGE        = 80878,

    SPELL_BURDEN_OF_THE_CROWN           = 80718,
    SPELL_CHAIN_LIGHTNING               = 80646,
    SPELL_STORMBOLT                     = 80648,
    SPELL_THUNDERCLAP                   = 80649,
    SPELL_WHIRLWIND                     = 80652,
    SPELL_AVATAR                        = 80645,
    SPELL_STONEBLOOD                    = 80655,
    SPELL_EXECUTION_SENTENCE_SUMMON_1   = 80738,
    SPELL_EXECUTION_SENTENCE_SUMMON_2   = 80729,
    SPELL_EXECUTION_SENTENCE_DUMMY      = 85176,
    SPELL_EXECUTION_SENTENCE            = 80727,

    // Events
    EVENT_BURDEN_OF_THE_CROWN = 1,
    EVENT_CHAIN_LIGHTNING,
    EVENT_STORMBOLT,
    EVENT_THUNDERCLAP,
    EVENT_WHIRLWIND,
    EVENT_AVATAR,
    EVENT_STONEBLOOD,
    EVENT_SHIELD_OF_LIGHT,
    EVENT_EXECUTION_SENTENCE
};

#define SPELL_SHIELD_OF_LIGHT RAID_MODE<uint32>(80747, 95537)

struct npc_bwd_dwarven_spirit : public ScriptedAI
{
    npc_bwd_dwarven_spirit(Creature* creature) : ScriptedAI(creature) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        uint32 initialEventId = 0;
        switch (me->GetEntry())
        {
            case NPC_SPIRIT_OF_COREHAMMER:  initialEventId = EVENT_BURDEN_OF_THE_CROWN; break;
            case NPC_SPIRIT_OF_SHADOWFORGE: initialEventId = EVENT_CHAIN_LIGHTNING; break;
            case NPC_SPIRIT_OF_ANVILRAGE:   initialEventId = EVENT_STORMBOLT; break;
            case NPC_SPIRIT_OF_MOLTENFIST:  initialEventId = EVENT_THUNDERCLAP; break;
            case NPC_SPIRIT_OF_BURNINGEYE:  initialEventId = EVENT_WHIRLWIND; break;
            case NPC_SPIRIT_OF_THAURISSAN:  initialEventId = EVENT_AVATAR; break;
            case NPC_SPIRIT_OF_ANGERFORGE:  initialEventId = EVENT_STONEBLOOD; break;
            case NPC_SPIRIT_OF_IRONSTAR:    initialEventId = EVENT_SHIELD_OF_LIGHT; break;
            default:
                break;
        }

        if (initialEventId)
            _events.ScheduleEvent(initialEventId, 11s, 18s);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode(why);
        _events.Reset();

        if (InstanceScript* instance = me->GetInstanceScript())
        {
            switch (me->GetEntry())
            {
                case NPC_SPIRIT_OF_MOLTENFIST:
                case NPC_SPIRIT_OF_ANVILRAGE:
                case NPC_SPIRIT_OF_SHADOWFORGE:
                case NPC_SPIRIT_OF_COREHAMMER:
                    instance->SetData(DATA_RESET_DWARVEN_SPIRIT_GROUP, DWARVEN_SPIRIT_GROUP_LEFT);
                    break;
                default:
                    instance->SetData(DATA_RESET_DWARVEN_SPIRIT_GROUP, DWARVEN_SPIRIT_GROUP_RIGHT);
                    break;
            }
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _events.Reset();
        uint32 bestowalSpellId = 0;
        switch (me->GetEntry())
        {
            case NPC_SPIRIT_OF_ANGERFORGE:  bestowalSpellId = SPELL_BESTOWAL_OF_ANGERFORGE; break;
            case NPC_SPIRIT_OF_ANVILRAGE:   bestowalSpellId = SPELL_BESTOWAL_OF_ANVILRAGE; break;
            case NPC_SPIRIT_OF_BURNINGEYE:  bestowalSpellId = SPELL_BESTOWAL_OF_BURNINGEYE; break;
            case NPC_SPIRIT_OF_COREHAMMER:  bestowalSpellId = SPELL_BESTOWAL_OF_COREHAMMER; break;
            case NPC_SPIRIT_OF_IRONSTAR:    bestowalSpellId = SPELL_BESTOWAL_OF_IRONSTAR; break;
            case NPC_SPIRIT_OF_MOLTENFIST:  bestowalSpellId = SPELL_BESTOWAL_OF_MOLTENFIST; break;
            case NPC_SPIRIT_OF_SHADOWFORGE: bestowalSpellId = SPELL_BESTOWAL_OF_SHADOWFORGE; break;
            case NPC_SPIRIT_OF_THAURISSAN:  bestowalSpellId = SPELL_BESTOWAL_OF_THAURISSAN; break;
            default:
                break;
        }

        if (bestowalSpellId)
            DoCastAOE(bestowalSpellId);

        if (InstanceScript* instance = me->GetInstanceScript())
        {
            switch (me->GetEntry())
            {
                case NPC_SPIRIT_OF_MOLTENFIST:
                case NPC_SPIRIT_OF_ANVILRAGE:
                case NPC_SPIRIT_OF_SHADOWFORGE:
                case NPC_SPIRIT_OF_COREHAMMER:
                    instance->SetData(DATA_DWARVEN_SPIRIT_DIED, DWARVEN_SPIRIT_GROUP_LEFT);
                    break;
                default:
                    instance->SetData(DATA_DWARVEN_SPIRIT_DIED, DWARVEN_SPIRIT_GROUP_RIGHT);
                    break;
            }
        }
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        uint32 triggeredEventId = 0;
        switch (spell->Id)
        {
            case SPELL_BESTOWAL_OF_COREHAMMER:    triggeredEventId = EVENT_BURDEN_OF_THE_CROWN; break;
            case SPELL_BESTOWAL_OF_SHADOWFORGE:   triggeredEventId = EVENT_CHAIN_LIGHTNING; break;
            case SPELL_BESTOWAL_OF_ANVILRAGE:     triggeredEventId = EVENT_STORMBOLT; break;
            case SPELL_BESTOWAL_OF_MOLTENFIST:    triggeredEventId = EVENT_THUNDERCLAP; break;
            case SPELL_BESTOWAL_OF_BURNINGEYE:    triggeredEventId = EVENT_WHIRLWIND; break;
            case SPELL_BESTOWAL_OF_THAURISSAN:    triggeredEventId = EVENT_AVATAR; break;
            case SPELL_BESTOWAL_OF_ANGERFORGE:    triggeredEventId = EVENT_AVATAR; break;
            case SPELL_BESTOWAL_OF_IRONSTAR:      triggeredEventId = EVENT_SHIELD_OF_LIGHT; break;
            default:
                break;
        }

        if (triggeredEventId)
            _events.ScheduleEvent(triggeredEventId, 1s);
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_EXECUTION_SENTENCE_VISUAL)
        {
            summon->m_Events.AddEventAtOffset([summon]()
            {
                Movement::MoveSplineInit init(summon);
                init.MoveTo(summon->GetPositionX(), summon->GetPositionY(), summon->GetFloorZ(), false);
                init.SetVelocity(0.54f);
                init.Launch();
            }, 2s+ 500ms);
        }
    }

    void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason reason) override
    {
        if (spell->Id == SPELL_SHIELD_OF_LIGHT && reason == SPELL_FINISHED_SUCCESSFUL_CAST)
        {
            _events.DelayEvents(1s + 100ms);
            _events.ScheduleEvent(EVENT_EXECUTION_SENTENCE, 1s);
        }
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
                case EVENT_BURDEN_OF_THE_CROWN:
                    DoCastVictim(SPELL_BURDEN_OF_THE_CROWN);
                    _events.Repeat(31s);
                    break;
                case EVENT_CHAIN_LIGHTNING:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 90.f, true))
                        DoCast(target, SPELL_CHAIN_LIGHTNING);
                    _events.Repeat(10s, 11s);
                    break;
                case EVENT_STORMBOLT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.f, true))
                        DoCast(target, SPELL_STORMBOLT);
                    _events.Repeat(19s, 23s);
                    break;
                case EVENT_THUNDERCLAP:
                    if (me->GetVictim()->IsWithinMeleeRange(me))
                    {
                        DoCastAOE(SPELL_THUNDERCLAP);
                        _events.Repeat(6s, 8s);
                    }
                    else
                        _events.Repeat(1s);
                    break;
                case EVENT_WHIRLWIND:
                    DoCastSelf(SPELL_WHIRLWIND);
                    _events.Repeat(34s, 36s);
                    break;
                case EVENT_AVATAR:
                    DoCastSelf(SPELL_AVATAR);
                    _events.Repeat(34s, 36s);
                    break;
                case EVENT_STONEBLOOD:
                    DoCastSelf(SPELL_STONEBLOOD);
                    _events.Repeat(19s, 23s);
                    break;
                case EVENT_SHIELD_OF_LIGHT:
                    DoCastSelf(SPELL_SHIELD_OF_LIGHT);
                    break;
                case EVENT_EXECUTION_SENTENCE:
                    if (me->GetVictim() && !me->GetVictim()->HasAura(SPELL_EXECUTION_SENTENCE))
                    {
                        DoCastVictim(SPELL_EXECUTION_SENTENCE_SUMMON_1);
                        DoCastVictim(SPELL_EXECUTION_SENTENCE_SUMMON_2);
                        DoCastVictim(SPELL_EXECUTION_SENTENCE);
                    }
                    _events.Repeat(34s, 36s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

struct go_bwd_ancient_bell : public GameObjectAI
{
    go_bwd_ancient_bell(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()) { }

    bool GossipHello(Player* /*player*/) override
    {
        _instance->SetData(DATA_ATRAMEDES_INTRO, DONE);
        me->SendCustomAnim(0);
        me->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
        if (Creature* column = _instance->GetCreature(DATA_COLUMN_OF_LIGHT))
            column->DespawnOrUnsummon();

        me->DespawnOrUnsummon(7s + 400ms);

        return true;
    }
private:
    InstanceScript* _instance;
};

enum DragonOrb
{
    SPELL_DRAGON_ORB_1 = 78219
};

Position const DragonOrb1Offset = { -28.80208f, -216.4497f, 71.34686f };
Position const DragonOrb2Offset = { -28.80208f, -232.4497f, 71.34686f };

class spell_bwd_dragon_orb : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRAGON_ORB_1 });
    }

    void SetDest(SpellDestination& dest)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;
        if (GetSpellInfo()->Id == SPELL_DRAGON_ORB_1)
            dest.Relocate(DragonOrb1Offset);
        else
            dest.Relocate(DragonOrb2Offset);
    }

    void Register() override
    {
        OnDestinationTargetSelect.Register(&spell_bwd_dragon_orb::SetDest, EFFECT_0, TARGET_DEST_CASTER_RANDOM);
    }
};

class spell_bwd_grievous_wound : public AuraScript
{
    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (GetUnitOwner()->HealthAbovePct(90))
        {
            PreventDefaultAction();
            Remove(AuraRemoveFlags::ByEnemySpell);
        }
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_bwd_grievous_wound::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

class spell_bwd_execution_sentence_visual : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.RelocateOffset({ 0.0f, 0.0f, 15.0f, 0.0f });
    }

    void Register()
    {
        OnDestinationTargetSelect.Register(&spell_bwd_execution_sentence_visual::SetDest, EFFECT_0, TARGET_DEST_TARGET_ENEMY);
    }
};

class spell_bwd_execution_sentence_dummy : public SpellScript
{
    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Creature* creature = GetHitCreature();
        if (!caster || !creature)
            return;

        if (TempSummon* summon = creature->ToTempSummon())
            if (summon->GetSummoner() == caster)
                summon->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_bwd_execution_sentence_dummy::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_bwd_execution_sentence : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_EXECUTION_SENTENCE_DUMMY });
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode().HasFlag(AuraRemoveFlags::ByCancel | AuraRemoveFlags::ByDeath))
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster, SPELL_EXECUTION_SENTENCE_DUMMY, true);
    }

    void Register() override
    {
        OnEffectRemove.Register(&spell_bwd_execution_sentence::HandleRemove, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_bwd_stoneblood : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        std::unordered_set<Aura*> aurasToRemove;
        Unit* target = GetHitUnit();
        for (auto itr : target->GetAppliedAuras())
        {
            Aura* aura = itr.second->GetBase();
            if (!aura)
                continue;

            // Todo: this check should be more generic so it can detect actual hostile effects but it'll do for the dwarven spirits for the time being.
            if (Unit* caster = aura->GetCaster())
                if (caster->IsPlayer() || caster->IsSummon())
                    aurasToRemove.insert(aura);
        }

        for (std::unordered_set<Aura*>::const_iterator itr = aurasToRemove.begin(); itr != aurasToRemove.end();)
        {
            (*itr)->Remove(AuraRemoveFlags::ByEnemySpell);
            itr = aurasToRemove.erase(itr);
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_bwd_stoneblood::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class at_bwd_intro: public OnlyOnceAreaTriggerScript
{
    public:
        at_bwd_intro() : OnlyOnceAreaTriggerScript("at_bwd_intro") { }

        bool _OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                instance->SetData(DATA_ENTRANCE_INTRO, IN_PROGRESS);
            return true;
        }
};

void AddSC_blackwing_descent()
{
    RegisterBlackwingDescentCreatureAI(npc_bwd_lord_victor_nefarius);
    RegisterBlackwingDescentCreatureAI(npc_bwd_drakonid_chainwielder);
    RegisterBlackwingDescentCreatureAI(npc_bwd_dwarven_spirit);
    RegisterGameObjectAI(go_bwd_ancient_bell);
    RegisterSpellScript(spell_bwd_dragon_orb);
    RegisterSpellScript(spell_bwd_grievous_wound);
    RegisterSpellScript(spell_bwd_execution_sentence_visual);
    RegisterSpellScript(spell_bwd_execution_sentence_dummy);
    RegisterSpellScript(spell_bwd_execution_sentence);
    RegisterSpellScript(spell_bwd_stoneblood);
    new at_bwd_intro();
}
