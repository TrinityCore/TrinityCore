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
#include "Map.h"
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
    SPELL_CONSTRICTING_CHAINS   = 79589,
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

struct go_bwd_ancient_bell : public GameObjectAI
{
    go_bwd_ancient_bell(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()) { }

    bool GossipHello(Player* /*player*/) override
    {
        if (_instance->GetData(DATA_ATRAMEDES_INTRO) == DONE)
            return true;

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
    PrepareSpellScript(spell_bwd_dragon_orb);

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
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_bwd_dragon_orb::SetDest, EFFECT_0, TARGET_DEST_CASTER_RANDOM);
    }
};

class spell_bwd_grievous_wound : public AuraScript
{
    PrepareAuraScript(spell_bwd_grievous_wound);

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
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_bwd_grievous_wound::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
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
    RegisterGameObjectAI(go_bwd_ancient_bell);
    RegisterSpellScript(spell_bwd_dragon_orb);
    RegisterAuraScript(spell_bwd_grievous_wound);
    new at_bwd_intro();
}
