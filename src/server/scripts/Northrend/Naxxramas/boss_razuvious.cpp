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
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "naxxramas.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

enum Yells
{
    SAY_AGGRO = 0,
    SAY_SLAY = 1,
    SAY_TAUNTED = 2,
    SAY_DEATH = 3
};

enum Spells
{
    SPELL_UNBALANCING_STRIKE        = 26613,
    SPELL_DISRUPTING_SHOUT          = 29107,
    SPELL_JAGGED_KNIFE              = 55550,
    SPELL_HOPELESS                  = 29125,
    SPELL_UNDERSTUDY_TAUNT          = 29060,
    SPELL_UNDERSTUDY_BLOOD_STRIKE   = 61696,
    SPELL_FORCE_OBEDIENCE           = 55479
};

enum Events
{
    EVENT_ATTACK = 1,
    EVENT_STRIKE,
    EVENT_SHOUT,
    EVENT_KNIFE
};

enum SummonGroups
{
    SUMMON_GROUP_10MAN = 1,
    SUMMON_GROUP_25MAN = 2
};

class boss_razuvious : public CreatureScript
{
public:
    boss_razuvious() : CreatureScript("boss_razuvious") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetNaxxramasAI<boss_razuviousAI>(creature);
    }

    struct boss_razuviousAI : public BossAI
    {
        boss_razuviousAI(Creature* creature) : BossAI(creature, BOSS_RAZUVIOUS) { }

        void SummonAdds()
        {
            me->SummonCreatureGroup(SUMMON_GROUP_10MAN);
            if (Is25ManRaid())
                me->SummonCreatureGroup(SUMMON_GROUP_25MAN);
        }

        void InitializeAI() override
        {
            if (!me->isDead() && instance->GetBossState(BOSS_RAZUVIOUS) != DONE)
            {
                Reset();
                SummonAdds();
            }
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
            SummonAdds();
            me->GetMotionMaster()->Initialize();
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER || (victim->GetTypeId() == TYPEID_UNIT && victim->GetEntry() == NPC_DK_UNDERSTUDY))
                Talk(SAY_SLAY);
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_UNDERSTUDY_TAUNT)
                Talk(SAY_TAUNTED, caster);
        }

        void JustDied(Unit* /*killer*/) override
        {
            for (ObjectGuid summonGuid : summons)
                if (Creature* summon = ObjectAccessor::GetCreature(*me, summonGuid))
                    summon->RemoveCharmAuras();
            Talk(SAY_DEATH);
            DoCastAOE(SPELL_HOPELESS, true);

            events.Reset();
            instance->SetBossState(BOSS_RAZUVIOUS, DONE);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            _JustEngagedWith();
            me->StopMoving();
            summons.DoZoneInCombat();
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_ATTACK, Seconds(7));
            events.ScheduleEvent(EVENT_STRIKE, Seconds(21));
            events.ScheduleEvent(EVENT_SHOUT, Seconds(16));
            events.ScheduleEvent(EVENT_KNIFE, Seconds(10));
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ATTACK:
                        SetCombatMovement(true);
                        if (Unit* victim = me->GetVictim())
                            me->GetMotionMaster()->MoveChase(victim);
                        break;
                    case EVENT_STRIKE:
                        DoCastVictim(SPELL_UNBALANCING_STRIKE);
                        events.Repeat(Seconds(6));
                        return;
                    case EVENT_SHOUT:
                        DoCastAOE(SPELL_DISRUPTING_SHOUT);
                        events.Repeat(Seconds(16));
                        return;
                    case EVENT_KNIFE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f))
                            DoCast(target, SPELL_JAGGED_KNIFE);
                        events.Repeat(randtime(Seconds(10), Seconds(15)));
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }

        void Reset() override
        {
            SetCombatMovement(false);
            _Reset();
        }
    };

};

class npc_dk_understudy : public CreatureScript
{
    public:
        npc_dk_understudy() : CreatureScript("npc_dk_understudy") { }

        struct npc_dk_understudyAI : public ScriptedAI
        {
            npc_dk_understudyAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), bloodStrikeTimer(0)
            {
                creature->LoadEquipment(1);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                if (Creature* razuvious = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_RAZUVIOUS)))
                    razuvious->AI()->DoZoneInCombat();
            }

            void JustReachedHome() override
            {
                if (_instance->GetBossState(BOSS_RAZUVIOUS) == DONE)
                    me->DespawnOrUnsummon();
                else
                    ScriptedAI::JustReachedHome();
            }

            void UpdateAI(uint32 diff) override
            {
                if (!me->isPossessedByPlayer() && !UpdateVictim())
                    return;

                if (!me->isPossessedByPlayer())
                {
                    if (diff < bloodStrikeTimer)
                        bloodStrikeTimer -= diff;
                    else
                        DoCastVictim(SPELL_UNDERSTUDY_BLOOD_STRIKE);
                }

                DoMeleeAttackIfReady();
            }

            void OnCharmed(bool isNew) override
            {
                if (me->IsCharmed() && !me->IsEngaged())
                    JustEngagedWith(nullptr);
                ScriptedAI::OnCharmed(isNew);
            }
        private:
            InstanceScript* const _instance;
            ObjectGuid _charmer;
            uint32 bloodStrikeTimer;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetNaxxramasAI<npc_dk_understudyAI>(creature);
        }
};

void AddSC_boss_razuvious()
{
    new boss_razuvious();
    new npc_dk_understudy();
}
