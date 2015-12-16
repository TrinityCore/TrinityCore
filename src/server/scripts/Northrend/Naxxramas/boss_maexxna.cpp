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
#include "PassiveAI.h"
#include "SpellScript.h"
#include "naxxramas.h"

enum Spells
{
    SPELL_WEB_WRAP              = 28622,
    SPELL_WEB_SPRAY             = 29484,
    SPELL_POISON_SHOCK          = 28741,
    SPELL_NECROTIC_POISON       = 28776,
    SPELL_FRENZY                = 54123
};
#define SPELL_FRENZY_HELPER RAID_MODE(54123,54124)

enum Emotes
{
    EMOTE_SPIDERS           = 0,
    EMOTE_WEB_WRAP          = 1,
    EMOTE_WEB_SPRAY         = 2
};

enum Creatures
{
    NPC_WEB_WRAP                = 16486,
    NPC_SPIDERLING              = 17055,
};

#define MAX_WRAP_POSITION  7
const Position WrapPositions[MAX_WRAP_POSITION] =
{
    {3453.818f, -3854.651f, 308.7581f, 4.362833f},
    {3535.042f, -3842.383f, 300.795f,  3.179324f},
    {3538.399f, -3846.088f, 299.964f,  4.310297f},
    {3548.464f, -3854.676f, 298.6075f, 4.546609f},
    {3557.663f, -3870.123f, 297.5027f, 3.756433f},
    {3560.546f, -3879.353f, 297.4843f, 2.508937f},
    {3562.535f, -3892.507f, 298.532f,  6.022466f},
};

enum Events
{
    EVENT_NONE,
    EVENT_SPRAY,
    EVENT_SHOCK,
    EVENT_POISON,
    EVENT_WRAP,
    EVENT_SUMMON,
};

const float WEB_WRAP_MOVE_SPEED = 20.0f;

struct WebTargetSelector : public std::unary_function<Unit*, bool>
{
    WebTargetSelector(Unit* maexxna) : _maexxna(maexxna) {}
    bool operator()(Unit const* target) const
    {
        if (_maexxna->GetVictim() == target) // never target tank
            return false;
        if (target->HasAura(SPELL_WEB_WRAP)) // never target targets that are already webbed
            return false;
        return true;
    }

    private:
        const Unit* _maexxna;
};

class boss_maexxna : public CreatureScript
{
public:
    boss_maexxna() : CreatureScript("boss_maexxna") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_maexxnaAI(creature);
    }

    struct boss_maexxnaAI : public BossAI
    {
        boss_maexxnaAI(Creature* creature) : BossAI(creature, BOSS_MAEXXNA)  {  }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_WRAP, 20 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_SPRAY, 40 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_SHOCK, urandms(5, 10));
            events.ScheduleEvent(EVENT_POISON, urandms(10, 15));
            events.ScheduleEvent(EVENT_SUMMON, 30 * IN_MILLISECONDS);
        }

        void Reset() override
        {
            _Reset();
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WEB_WRAP);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || !CheckInRoom())
                return;

            if (HealthBelowPct(30) && !me->HasAura(SPELL_FRENZY_HELPER))
            {
                DoCast(SPELL_FRENZY);
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_WRAP:
                    {
                        std::list<Unit*> targets;
                        SelectTargetList(targets, WebTargetSelector(me), RAID_MODE(1, 2), SELECT_TARGET_RANDOM);
                        if (!targets.empty())
                        {
                            Talk(EMOTE_WEB_WRAP);
                            int8 wrapPos = -1;
                            for (Unit* target : targets)
                            {
                                if (wrapPos == -1) // allow all positions on the first target
                                    wrapPos = urand(0, MAX_WRAP_POSITION - 1);
                                else // on subsequent iterations, only allow positions that are not equal to the previous one (this is sufficient since we should only have two targets at most, ever)
                                    wrapPos = (wrapPos + urand(1, MAX_WRAP_POSITION - 1)) % MAX_WRAP_POSITION;

                                target->RemoveAura(sSpellMgr->GetSpellIdForDifficulty(SPELL_WEB_SPRAY, me));
                                if (Creature* wrap = DoSummon(NPC_WEB_WRAP, WrapPositions[wrapPos], 70 * IN_MILLISECONDS, TEMPSUMMON_TIMED_DESPAWN))
                                {
                                    wrap->AI()->SetGUID(target->GetGUID()); // handles application of debuff
                                    target->GetMotionMaster()->MoveJump(WrapPositions[wrapPos], WEB_WRAP_MOVE_SPEED, WEB_WRAP_MOVE_SPEED); // move after stun to avoid stun cancelling move
                                }
                            }
                        }
                        events.ScheduleEvent(EVENT_WRAP, 40000);
                        break;
                    }
                    case EVENT_SPRAY:
                        Talk(EMOTE_WEB_SPRAY);
                        DoCastAOE(SPELL_WEB_SPRAY);
                        events.ScheduleEvent(EVENT_SPRAY, 40000);
                        break;
                    case EVENT_SHOCK:
                        DoCastAOE(SPELL_POISON_SHOCK);
                        events.ScheduleEvent(EVENT_SHOCK, urandms(10, 20));
                        break;
                    case EVENT_POISON:
                        DoCastVictim(SPELL_NECROTIC_POISON);
                        events.ScheduleEvent(EVENT_POISON, urandms(10, 20));
                        break;
                    case EVENT_SUMMON:
                        Talk(EMOTE_SPIDERS);
                        uint8 amount = urand(8, 10);
                        for (uint8 i = 0; i < amount; ++i)
                            DoSummon(NPC_SPIDERLING, me, 4.0f, 5 * IN_MILLISECONDS, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                        events.ScheduleEvent(EVENT_SUMMON, 40000);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class npc_webwrap : public CreatureScript
{
public:
    npc_webwrap() : CreatureScript("npc_webwrap") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_webwrapAI(creature);
    }

    struct npc_webwrapAI : public NullCreatureAI
    {
        npc_webwrapAI(Creature* creature) : NullCreatureAI(creature), visibleTimer(0) { }

        ObjectGuid victimGUID;
        uint32 visibleTimer;

        void InitializeAI() override
        {
            me->SetVisible(false);
        }

        void SetGUID(ObjectGuid guid, int32 /*param*/) override
        {
            if (!guid)
                return;
            victimGUID = guid;
            if (Unit* victim = ObjectAccessor::GetUnit(*me, victimGUID))
            {
                visibleTimer = (me->GetDistance2d(victim)/WEB_WRAP_MOVE_SPEED + 0.5f) * IN_MILLISECONDS;
                victim->CastSpell(victim, SPELL_WEB_WRAP, true, NULL, NULL, me->GetGUID());
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!visibleTimer)
                return;

            if (diff >= visibleTimer)
            {
                visibleTimer = 0;
                me->SetVisible(true);
            }
            else
                visibleTimer -= diff;
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (victimGUID)
                if (Unit* victim = ObjectAccessor::GetUnit(*me, victimGUID))
                    victim->RemoveAurasDueToSpell(SPELL_WEB_WRAP, me->GetGUID());

            me->DespawnOrUnsummon(5 * IN_MILLISECONDS);
        }
    };

};

void AddSC_boss_maexxna()
{
    new boss_maexxna();
    new npc_webwrap();
}
