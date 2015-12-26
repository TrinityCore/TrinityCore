/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "naxxramas.h"
#include "Player.h"

enum Spells
{
    SPELL_DECREPIT_FEVER    = 29998, // 25-man: 55011
    SPELL_SPELL_DISRUPTION  = 29310,
    SPELL_PLAGUE_CLOUD      = 29350,
    SPELL_TELEPORT_SELF     = 30211,
};

enum Yells
{
    SAY_AGGRO               = 0,
    SAY_SLAY                = 1,
    SAY_TAUNT               = 2,
    SAY_DEATH               = 3,

    EMOTE_DANCE             = 4,
    EMOTE_DANCE_END         = 5,
};

enum Events
{
    EVENT_DISRUPT = 1,
    EVENT_FEVER,
    EVENT_ERUPT,
    EVENT_DANCE,
    EVENT_DANCE_END
};

enum Phases
{
    PHASE_FIGHT = 1,
    PHASE_DANCE
};

enum Misc
{
    DATA_SAFETY_DANCE               = 19962139
};

class boss_heigan : public CreatureScript
{
public:
    boss_heigan() : CreatureScript("boss_heigan") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_heiganAI>(creature);
    }

    struct boss_heiganAI : public BossAI
    {
        boss_heiganAI(Creature* creature) : BossAI(creature, BOSS_HEIGAN), eruptSection(0), eruptDirection(false), safetyDance(false) { }

        void Reset() override
        {
            me->SetReactState(REACT_AGGRESSIVE);
            _Reset();
        }

        void KilledUnit(Unit* who) override
        {
            Talk(SAY_SLAY);

            if (who->GetTypeId() == TYPEID_PLAYER)
                safetyDance = false;
        }

        uint32 GetData(uint32 type) const override
        {
            return (type == DATA_SAFETY_DANCE && safetyDance) ? 1u : 0u;
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            Talk(SAY_DEATH);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            Talk(SAY_AGGRO);

            eruptSection = 3;
            events.ScheduleEvent(EVENT_DISRUPT, urand(15 * IN_MILLISECONDS, 20 * IN_MILLISECONDS), 0, PHASE_FIGHT);
            events.ScheduleEvent(EVENT_FEVER, urand(10 * IN_MILLISECONDS, 20 * IN_MILLISECONDS), 0, PHASE_FIGHT);
            events.ScheduleEvent(EVENT_DANCE, 90 * IN_MILLISECONDS, 0, PHASE_FIGHT);
            events.ScheduleEvent(EVENT_ERUPT, 15 * IN_MILLISECONDS, 0, PHASE_FIGHT);

            safetyDance = true;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || !CheckInRoom())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DISRUPT:
                        DoCastAOE(SPELL_SPELL_DISRUPTION);
                        events.ScheduleEvent(EVENT_DISRUPT, 11 * IN_MILLISECONDS);
                        break;
                    case EVENT_FEVER:
                        DoCastAOE(SPELL_DECREPIT_FEVER);
                        events.ScheduleEvent(EVENT_FEVER, urand(20 * IN_MILLISECONDS, 25 * IN_MILLISECONDS));
                        break;
                    case EVENT_DANCE:
                        events.SetPhase(PHASE_DANCE);
                        Talk(SAY_TAUNT);
                        Talk(EMOTE_DANCE);
                        eruptSection = 3;
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->StopMoving();
                        DoCast(SPELL_TELEPORT_SELF);
                        DoCastAOE(SPELL_PLAGUE_CLOUD);
                        events.ScheduleEvent(EVENT_DANCE_END, 45 * IN_MILLISECONDS, 0, PHASE_DANCE);
                        events.ScheduleEvent(EVENT_ERUPT, 10 * IN_MILLISECONDS);
                        break;
                    case EVENT_DANCE_END:
                        events.SetPhase(PHASE_FIGHT);
                        Talk(EMOTE_DANCE_END);
                        eruptSection = 3;
                        events.ScheduleEvent(EVENT_DISRUPT, urand(10, 25) * IN_MILLISECONDS, 0, PHASE_FIGHT);
                        events.ScheduleEvent(EVENT_FEVER, urand(15, 20) * IN_MILLISECONDS, 0, PHASE_FIGHT);
                        events.ScheduleEvent(EVENT_DANCE, 90 * IN_MILLISECONDS, 0, PHASE_FIGHT);
                        events.ScheduleEvent(EVENT_ERUPT, 15 * IN_MILLISECONDS, 0, PHASE_FIGHT);
                        me->CastStop();
                        me->SetReactState(REACT_AGGRESSIVE);
                        DoZoneInCombat();
                        break;
                    case EVENT_ERUPT:
                        instance->SetData(DATA_HEIGAN_ERUPT, eruptSection);
                        TeleportCheaters();

                        if (eruptSection == 0)
                            eruptDirection = true;
                        else if (eruptSection == 3)
                            eruptDirection = false;

                        eruptDirection ? ++eruptSection : --eruptSection;

                        if (events.IsInPhase(PHASE_DANCE))
                            events.ScheduleEvent(EVENT_ERUPT, 3 * IN_MILLISECONDS, 0, PHASE_DANCE);
                        else
                            events.ScheduleEvent(EVENT_ERUPT, 10 * IN_MILLISECONDS, 0, PHASE_FIGHT);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        private:
            uint32 eruptSection;
            bool eruptDirection;

            bool safetyDance; // is achievement still possible? (= no player deaths yet)
    };

};

class spell_heigan_eruption : public SpellScriptLoader
{
    public:
        spell_heigan_eruption() : SpellScriptLoader("spell_heigan_eruption") { }

        class spell_heigan_eruption_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_heigan_eruption_SpellScript);

            void HandleScript(SpellEffIndex /*eff*/)
            {
                Unit* caster = GetCaster();
                if (!caster || !GetHitPlayer())
                    return;

                if (GetHitDamage() >= int32(GetHitPlayer()->GetHealth()))
                    if (InstanceScript* instance = caster->GetInstanceScript())
                        if (Creature* Heigan = ObjectAccessor::GetCreature(*caster, instance->GetGuidData(DATA_HEIGAN)))
                            Heigan->AI()->KilledUnit(GetHitPlayer());
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_heigan_eruption_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_heigan_eruption_SpellScript();
        }
};

class achievement_safety_dance : public AchievementCriteriaScript
{
    public:
        achievement_safety_dance() : AchievementCriteriaScript("achievement_safety_dance") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Heigan = target->ToCreature())
                if (Heigan->AI()->GetData(DATA_SAFETY_DANCE))
                    return true;

            return false;
        }
};

void AddSC_boss_heigan()
{
    new boss_heigan();
    new spell_heigan_eruption();
    new achievement_safety_dance();
}
