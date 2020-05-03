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
#include "GameObject.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "SpellInfo.h"

/*####
# npc_omen
####*/

enum Omen
{
    NPC_OMEN                    = 15467,

    SPELL_OMEN_CLEAVE           = 15284,
    SPELL_OMEN_STARFALL         = 26540,
    SPELL_OMEN_SUMMON_SPOTLIGHT = 26392,
    SPELL_ELUNE_CANDLE          = 26374,

    GO_ELUNE_TRAP_1             = 180876,
    GO_ELUNE_TRAP_2             = 180877,

    EVENT_CAST_CLEAVE           = 1,
    EVENT_CAST_STARFALL         = 2,
    EVENT_DESPAWN               = 3,
};

class npc_omen : public CreatureScript
{
public:
    npc_omen() : CreatureScript("npc_omen") { }

    struct npc_omenAI : public ScriptedAI
    {
        npc_omenAI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
            me->GetMotionMaster()->MovePoint(1, 7549.977f, -2855.137f, 456.9678f);
        }

        EventMap events;

        void MovementInform(uint32 type, uint32 pointId) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (pointId == 1)
            {
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                if (Player* player = me->SelectNearestPlayer(40.0f))
                    AttackStart(player);
            }
        }

        void EnterCombat(Unit* /*attacker*/) override
        {
            events.Reset();
            events.ScheduleEvent(EVENT_CAST_CLEAVE, urand(3000, 5000));
            events.ScheduleEvent(EVENT_CAST_STARFALL, urand(8000, 10000));
        }

        void JustDied(Unit* /*killer*/) override
        {
            DoCast(SPELL_OMEN_SUMMON_SPOTLIGHT);
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_ELUNE_CANDLE)
            {
                if (me->HasAura(SPELL_OMEN_STARFALL))
                    me->RemoveAurasDueToSpell(SPELL_OMEN_STARFALL);

                events.RescheduleEvent(EVENT_CAST_STARFALL, urand(14000, 16000));
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_CAST_CLEAVE:
                    DoCastVictim(SPELL_OMEN_CLEAVE);
                    events.ScheduleEvent(EVENT_CAST_CLEAVE, urand(8000, 10000));
                    break;
                case EVENT_CAST_STARFALL:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_OMEN_STARFALL);
                    events.ScheduleEvent(EVENT_CAST_STARFALL, urand(14000, 16000));
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_omenAI(creature);
    }
};

class npc_giant_spotlight : public CreatureScript
{
public:
    npc_giant_spotlight() : CreatureScript("npc_giant_spotlight") { }

    struct npc_giant_spotlightAI : public ScriptedAI
    {
        npc_giant_spotlightAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap events;

        void Reset() override
        {
            events.Reset();
            events.ScheduleEvent(EVENT_DESPAWN, 5*MINUTE*IN_MILLISECONDS);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (events.ExecuteEvent() == EVENT_DESPAWN)
            {
                if (GameObject* trap = me->FindNearestGameObject(GO_ELUNE_TRAP_1, 5.0f))
                    trap->RemoveFromWorld();

                if (GameObject* trap = me->FindNearestGameObject(GO_ELUNE_TRAP_2, 5.0f))
                    trap->RemoveFromWorld();

                if (Creature* omen = me->FindNearestCreature(NPC_OMEN, 5.0f, false))
                    omen->DespawnOrUnsummon();

                me->DespawnOrUnsummon();
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_giant_spotlightAI(creature);
    }
};

void AddSC_moonglade()
{
    new npc_omen();
    new npc_giant_spotlight();
}
