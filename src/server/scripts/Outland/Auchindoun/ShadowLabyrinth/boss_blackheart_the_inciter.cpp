/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "InstanceScript.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "Player.h"
#include "PlayerAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "shadow_labyrinth.h"

enum BlackheartTheInciter
{
    SPELL_INCITE_CHAOS      = 33676,
    SPELL_INCITE_CHAOS_B    = 33684,                         //debuff applied to each member of party
    SPELL_CHARGE            = 33709,
    SPELL_WAR_STOMP         = 33707,

    SAY_INTRO               = 0,
    SAY_AGGRO               = 1,
    SAY_SLAY                = 2,
    SAY_HELP                = 3,
    SAY_DEATH               = 4,

    //below, not used
    SAY2_INTRO              = 5,
    SAY2_AGGRO              = 6,
    SAY2_SLAY               = 7,
    SAY2_HELP               = 8,
    SAY2_DEATH              = 9
};

enum Events
{
    EVENT_INCITE_CHAOS          = 1,
    EVENT_CHARGE_ATTACK         = 2,
    EVENT_WAR_STOMP             = 3
};

class BlackheartCharmedPlayerAI : public SimpleCharmedPlayerAI
{
    using SimpleCharmedPlayerAI::SimpleCharmedPlayerAI;
    void OnCharmed(bool isNew) override
    {
        if (me->GetMap()->IsDungeon())
            if (Creature* blackheart = ObjectAccessor::GetCreature(*me, me->GetInstanceScript()->GetGuidData(DATA_BLACKHEART_THE_INCITER)))
            {
                blackheart->AI()->SetData(0, me->IsCharmed());
                blackheart->GetThreatManager().AddThreat(me, 0.0f);
            }
        SimpleCharmedPlayerAI::OnCharmed(isNew);
    }
};

struct boss_blackheart_the_inciter : public BossAI
{
    boss_blackheart_the_inciter(Creature* creature) : BossAI(creature, DATA_BLACKHEART_THE_INCITER) { }

    void Reset() override
    {
        me->SetReactState(REACT_AGGRESSIVE);
        _Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        events.ScheduleEvent(EVENT_INCITE_CHAOS, 20000);
        events.ScheduleEvent(EVENT_CHARGE_ATTACK, 5000);
        events.ScheduleEvent(EVENT_WAR_STOMP, 15000);

        Talk(SAY_AGGRO);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    uint8 charmCount = 0;
    void SetData(uint32 /*index*/, uint32 data) override
    {
        if (data)
            ++charmCount;
        else
        {
            if (!charmCount)
                EnterEvadeMode(EVADE_REASON_OTHER); // sanity check
            --charmCount;
        }
        if (charmCount)
            me->SetReactState(REACT_PASSIVE);
        else
            me->SetReactState(REACT_AGGRESSIVE);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);
        if (me->HasReactState(REACT_PASSIVE) || !UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INCITE_CHAOS:
                {
                    if (me->GetThreatManager().GetThreatListSize() > 1)
                    {
                        ResetThreatList();
                        DoCast(me, SPELL_INCITE_CHAOS);
                    }
                    events.ScheduleEvent(EVENT_INCITE_CHAOS, 40000);
                    break;
                }
                case EVENT_CHARGE_ATTACK:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_CHARGE);
                    events.ScheduleEvent(EVENT_CHARGE, urand(15000, 25000));
                    break;
                case EVENT_WAR_STOMP:
                    DoCast(me, SPELL_WAR_STOMP);
                    events.ScheduleEvent(EVENT_WAR_STOMP, urand(18000, 24000));
                    break;
            }

            if (me->HasReactState(REACT_PASSIVE) || me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

struct boss_blackheart_the_inciter_mc_dummy : public NullCreatureAI
{
    using NullCreatureAI::NullCreatureAI;
    void InitializeAI() override { me->SetReactState(REACT_PASSIVE); }
    static const uint32 FIRST_DUMMY = NPC_BLACKHEART_DUMMY1, LAST_DUMMY = NPC_BLACKHEART_DUMMY5;
    void IsSummonedBy(Unit* who) override
    {
        me->CastSpell(who, SPELL_INCITE_CHAOS_B, true);

        // ensure everyone is in combat with everyone
        if (auto* dummies = GetBlackheartDummies(me->GetInstanceScript()))
            for (ObjectGuid const& guid : *dummies)
                if (Creature* trigger = ObjectAccessor::GetCreature(*me, guid))
                    if (me->GetEntry() != trigger->GetEntry())
                    {
                        me->GetThreatManager().AddThreat(trigger, 0.0f);
                        trigger->GetThreatManager().AddThreat(who, 0.0f);
                        for (Unit* other : trigger->m_Controlled)
                        {
                            me->GetThreatManager().AddThreat(other, 0.0f);
                            other->GetThreatManager().AddThreat(who, 0.0f);
                        }
                    }
    }
    void UpdateAI(uint32 /*diff*/) override
    {
        if (me->m_Controlled.empty())
            me->DespawnOrUnsummon();
    }
    PlayerAI* GetAIForCharmedPlayer(Player* player) override
    {
        return new BlackheartCharmedPlayerAI(player);
    }
};

class spell_blackheart_incite_chaos : public SpellScript
{
    PrepareSpellScript(spell_blackheart_incite_chaos);
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_INCITE_CHAOS_B });
    }

    static const uint8 NUM_INCITE_SPELLS = 5;
    static const uint32 INCITE_SPELLS[NUM_INCITE_SPELLS];
    uint8 i=0;
    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
        {
            target->CastSpell(nullptr, INCITE_SPELLS[i], true);
            i = (i + 1) % NUM_INCITE_SPELLS;
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_blackheart_incite_chaos::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};
const uint32 spell_blackheart_incite_chaos::INCITE_SPELLS[spell_blackheart_incite_chaos::NUM_INCITE_SPELLS] = { 33677,33680,33681,33682,33683 };

void AddSC_boss_blackheart_the_inciter()
{
    RegisterCreatureAIWithFactory(boss_blackheart_the_inciter, GetShadowLabyrinthAI);
    RegisterCreatureAIWithFactory(boss_blackheart_the_inciter_mc_dummy, GetShadowLabyrinthAI);
    RegisterSpellScript(spell_blackheart_incite_chaos);
}
