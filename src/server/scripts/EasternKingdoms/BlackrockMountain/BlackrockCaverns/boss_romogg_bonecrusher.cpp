/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "blackrock_caverns.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellScript.h"

enum Texts
{
    SAY_AGGRO                   = 0,
    SAY_SLAY                    = 1,
    SAY_CHAINS_OF_WOE           = 2,
    SAY_DEATH                   = 3,
    SAY_EMOTE_CALL_FOR_HELP     = 4,
    SAY_ANNOUNCE_SKULLCRACKER   = 5
};

enum Spells
{
    // Rom'Ogg Bonecrusher
    SPELL_CALL_FOR_HELP             = 82137,
    SPELL_CHAINS_OF_WOE             = 75539,
    SPELL_QUAKE                     = 75272,
    SPELL_THE_SKULLCRACKER          = 75543,
    SPELL_WOUNDING_STRIKE           = 75571,

    // Chains of Woe
    SPELL_CHAINS_OF_WOE_TELEPORT    = 75437,
    SPELL_CHAINS_OF_WOE_CHANNELED   = 75441,
};

enum Events
{
    // Rom'Ogg Bonecrusher
    EVENT_CHAINS_OF_WOE = 1,
    EVENT_QUAKE,
    EVENT_SKULLCRACKER,
    EVENT_WOUNDING_STRIKE
};

enum Data
{
    DATA_CRUSHING_BONES_AND_CRACKING_SKULLS = 0
};

class AttackStartEvent : public BasicEvent
{
    public:
        AttackStartEvent(Creature* owner) :  _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->SetReactState(REACT_AGGRESSIVE);
            if (_owner->IsAIEnabled)
                _owner->AI()->DoZoneInCombat();
            return true;
        }

    private:
        Creature* _owner;
};

struct boss_romogg_bonecrusher : public BossAI
{
    boss_romogg_bonecrusher(Creature* creature) : BossAI(creature, DATA_ROMOGG_BONECRUSHER)
    {
        Initialize();
    }

    void Initialize()
    {
        _killedElementals = 0;
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        Talk(SAY_DEATH);
    }

    void Reset() override
    {
        _Reset();
        instance->SetData(DATA_RAZ_LAST_AREA_INDEX, RAZ_AREA_INDEX_ROMOGG);
        Initialize();
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);

        if (who->GetEntry() == NPC_ANGERED_EARTH)
            _killedElementals++;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        Talk(SAY_AGGRO);
        Talk(SAY_EMOTE_CALL_FOR_HELP);
        DoCast(me, SPELL_CALL_FOR_HELP);

        events.ScheduleEvent(EVENT_CHAINS_OF_WOE, 30s);
        events.ScheduleEvent(EVENT_WOUNDING_STRIKE, 16s);
        events.ScheduleEvent(EVENT_QUAKE, 24s);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        _EnterEvadeMode();
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _DespawnAtEvade();
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        if (summon->GetEntry() == NPC_ANGERED_EARTH)
        {
            summon->SetReactState(REACT_PASSIVE);
            summon->SetCorpseDelay(5);
            summon->m_Events.AddEvent(new AttackStartEvent(summon), summon->m_Events.CalculateTime(500));
        }
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_CRUSHING_BONES_AND_CRACKING_SKULLS)
            return _killedElementals >= 10;

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
                case EVENT_CHAINS_OF_WOE:
                    Talk(SAY_CHAINS_OF_WOE);
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    DoCast(me, SPELL_CHAINS_OF_WOE);
                    events.ScheduleEvent(EVENT_SKULLCRACKER, 3s);
                    events.Repeat(35s);
                    break;
                case EVENT_SKULLCRACKER:
                    Talk(SAY_ANNOUNCE_SKULLCRACKER);
                    DoCast(me, SPELL_THE_SKULLCRACKER);
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_QUAKE:
                    DoCast(me, SPELL_QUAKE);
                    events.ScheduleEvent(EVENT_QUAKE, 24s);
                    break;
                case EVENT_WOUNDING_STRIKE:
                    DoCastVictim(SPELL_WOUNDING_STRIKE);
                    events.ScheduleEvent(EVENT_WOUNDING_STRIKE, 13s, 14s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    uint8 _killedElementals;
};

struct npc_romogg_chains_of_woe : public ScriptedAI
{
    npc_romogg_chains_of_woe(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
        DoCastSelf(SPELL_CHAINS_OF_WOE_TELEPORT);
        DoCastSelf(SPELL_CHAINS_OF_WOE_CHANNELED);
    }

    void EnterEvadeMode(EvadeReason why) override { }

private:
    EventMap _events;
};

class spell_romogg_quake : public SpellScript
{
    PrepareSpellScript(spell_romogg_quake);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_romogg_quake::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_romogg_chains_of_woe : public SpellScript
{
    PrepareSpellScript(spell_romogg_chains_of_woe);

    void SetDest(SpellDestination& dest)
    {
        dest.RelocateOffset({ 0.0f, 0.0f, 1.6f, 0.0f });
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_romogg_chains_of_woe::SetDest, EFFECT_0, TARGET_DEST_CASTER_FRONT);
    }
};

class spell_romogg_chains_of_woe_teleport : public SpellScript
{
    PrepareSpellScript(spell_romogg_chains_of_woe_teleport);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            GetHitUnit()->CastSpell(caster, GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_romogg_chains_of_woe_teleport::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_romogg_chains_of_woe_teleport_dest : public SpellScript
{
    PrepareSpellScript(spell_romogg_chains_of_woe_teleport_dest);

    void SetDest(SpellDestination& dest)
    {
        Position pos = dest._position;
        Unit* caster = GetCaster();
        if (!caster)
            return;

        float dist = 3.0f; // Value taken from DBC value (3 yards)
        float angle = pos.GetAngle(caster);
        pos.m_positionX += cos(angle) * dist;
        pos.m_positionY += sin(angle) * dist;
        pos.m_positionZ = caster->GetMap()->GetHeight(caster->GetPhaseShift(), pos.m_positionX, pos.m_positionY, caster->GetPositionZ() + 5.0f, true);
        dest.Relocate(pos);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_romogg_chains_of_woe_teleport_dest::SetDest, EFFECT_0, TARGET_DEST_TARGET_RADIUS);
    }
};

class spell_romogg_chains_of_woe_root : public SpellScript
{
    PrepareSpellScript(spell_romogg_chains_of_woe_root);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_romogg_chains_of_woe_root::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_romogg_call_for_help : public SpellScript
{
    PrepareSpellScript(spell_romogg_call_for_help);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        if (Creature* creature = GetHitCreature())
            if (creature->IsAIEnabled)
                creature->AI()->DoZoneInCombat();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_romogg_call_for_help::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class achievement_crushing_bones_and_cracking_skulls : public AchievementCriteriaScript
{
    public:
        achievement_crushing_bones_and_cracking_skulls() : AchievementCriteriaScript("achievement_crushing_bones_and_cracking_skulls") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            if (target->IsAIEnabled)
                return target->GetAI()->GetData(DATA_CRUSHING_BONES_AND_CRACKING_SKULLS);

            return false;
        }
};

void AddSC_boss_romogg_bonecrusher()
{
    RegisterBlackrockCavernsCreatureAI(boss_romogg_bonecrusher);
    RegisterBlackrockCavernsCreatureAI(npc_romogg_chains_of_woe);
    RegisterSpellScript(spell_romogg_quake);
    RegisterSpellScript(spell_romogg_chains_of_woe);
    RegisterSpellScript(spell_romogg_chains_of_woe_teleport);
    RegisterSpellScript(spell_romogg_chains_of_woe_teleport_dest);
    RegisterSpellScript(spell_romogg_chains_of_woe_root);
    RegisterSpellScript(spell_romogg_call_for_help);
    new achievement_crushing_bones_and_cracking_skulls();
}
