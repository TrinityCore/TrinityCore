/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "vault_of_the_wardens.h"

enum InquisitorSpells
{
    //Just some visual fancy effects?
    SPELL_TORMENT_ = 206470,
    SPELL_TORMENT_DUMMY = 206483,
    SPELL_TORMENT_DUMMY_2 = 206485,
    SPELL_TORMENT_DUMMY_3 = 206472,

    //Start combat 14:59:37.656

    //First spell 14:59:50.821
    SPELL_SAP_SOUL_CHANNEL = 206303,
    SPELL_SAPPED_SOUL = 200904,

    //14:59:58.150
    //(Cast) SpellID: 214970 (Summon Tormenting Orb) Entry: 107114
    SPELL_SUMMON_TORMENTING_ORB = 214970, 
    SPELL_SUMMON_TORMENTING_ORB_2 = 212569, 
    SPELL_SUMMON_TORMENTING_ORB_3 = 212567,


    //15:00:04.238
    //(Cast) SpellID: 200898 (Teleport)
    SPELL_TELEPORT_1 = 200898,

};
enum InquisitorEvents
{
    EVENT_SAP_SOUL = 1,
    EVENT_SUMM_TORMENTING_ORBS = 2,
    EVENT_TELEPORT_1 = 3,
};
enum InquisitorTalk
{
    TALK_ENTER_COMBAT = 1,
    TALK_SAP_SOUL = 2,
    TALK_SOUL_SAP_TO_PLAYER = 3,
    TALK_SUCCESS_CAST = 4,
};
//96015
struct boss_inquisitor_tormentorum : public BossAI
{
    boss_inquisitor_tormentorum(Creature* creature) : BossAI(creature, DATA_INQUISITOR)
    {

    }

    void EnterCombat(Unit* /*who*/) override
    {
        Talk(TALK_ENTER_COMBAT);
    }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(EVENT_SAP_SOUL, Milliseconds(10000), Milliseconds(15000));
        events.ScheduleEvent(EVENT_SUMM_TORMENTING_ORBS, Milliseconds(19000), Milliseconds(21000));
    }
    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;
        events.Update(diff);

        switch(events.ExecuteEvent())
        {
            case EVENT_SAP_SOUL:
            {
                UnitList targetList;
                SelectTargetList(targetList, 5, SELECT_TARGET_RANDOM, 0, 200.0f, true, true, 0);

                for (Unit* target : targetList)
                    me->CastSpell(target, SPELL_SAP_SOUL_CHANNEL);
                Talk(TALK_SAP_SOUL);
                break;
            }
            case EVENT_SUMM_TORMENTING_ORBS:
                DoCast(SPELL_SUMMON_TORMENTING_ORB);
                DoCast(SPELL_SUMMON_TORMENTING_ORB_2);
                DoCast(SPELL_SUMMON_TORMENTING_ORB_3);
                Talk(TALK_SUCCESS_CAST);
                break;
            
        }
        if (me->HealthBelowPct(70) && !m_casted70)
        {
            DoCast(SPELL_TELEPORT_1);
            m_casted70  = true;
        }
        DoMeleeAttackIfReady();
    }
    bool m_casted70 = false;
};
void AddSC_boss_inquisitor_tormentorum()
{
    RegisterCreatureAI(boss_inquisitor_tormentorum);
    
}
