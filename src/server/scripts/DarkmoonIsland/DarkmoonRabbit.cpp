/*
 *  (C) - For Farahlon : All right reserved 2016 - 2017
 */

#include "ScriptPCH.h"

enum Enums
{
    //Spells
    SPELL_HUGE_SHARP_TEETH          = 114078,
    SPELL_INTERDIMENSIONAL_HOP      = 135056,

    //Events

};

// 58336 - Darkmoon Rabbit
class npc_darkmoon_rabbit_ird : public CreatureScript
{
public:
    npc_darkmoon_rabbit_ird() : CreatureScript("npc_darkmoon_rabbit_ird") { }

    struct npc_darkmoon_rabbit_irdAI : public ScriptedAI
    {
        npc_darkmoon_rabbit_irdAI(Creature* creature) : ScriptedAI(creature) { }

        void EnterCombat(Unit* who) override
        {
            me->CastSpell(who, SPELL_HUGE_SHARP_TEETH);
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            events.Reset();
            _EnterEvadeMode();
            me->GetMotionMaster()->MoveTargetedHome();
        }

        void UpdateAI(uint32 p_Diff) override
        {
            events.Update(p_Diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (!UpdateVictim())
                    return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                default:
                break;
                }
            }

            DoMeleeAttackIfReady();
        }

        EventMap events;
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new npc_darkmoon_rabbit_irdAI(p_Creature);
    }
};

void AddSC_darkmoon_rabbit()
{
    new npc_darkmoon_rabbit_ird();
}