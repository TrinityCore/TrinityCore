/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "GameObject.h"
#include "cathedral_of_eternal_night.h"

enum Spells
{
    //AGRONOX
    SPELL_TIMBER_SMASH = 235751,
    SPELL_SUCCULENT_LASHERS = 236639,//Only Mythic Mode
    SPELL_POISONOUS_SPORES = 236524,
    SPELL_FULMINATING_LASHERS = 236527,

    //THRASHBITE_THE_SCORNFUL
    SPELL_HEAVE_CUDGEL = 243124,
    SPELL_PULVERIZING_CUDGEL = 237276,
    SPELL_SCORNFUL_CHARGE = 238462,
    SPELL_SCORNFUL_GAZE = 237726,
    SPELL_TASTE_OF_BLOOD = 213738,
    //DOMATRAX
    //MEPHISTROTH


};

enum Events
{
    EVENT_NONE,

    EVENT_LVR_1,
    EVENT_LVR_2,
    EVENT_OUTRO_2,
    EVENT_OUTRO_3
};


enum NalashaSpells
{
    SPELL_SPIDER_CALL = 239052,
    SPELL_VANISH = 237395,
    SPELL_VENOM_STORM = 239266,
};
struct npc_nalasha_118705 : public ScriptedAI
{
    npc_nalasha_118705(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case SPELL_SPIDER_CALL:
            {
                DoCast(SPELL_SPIDER_CALL);
                events.Repeat(5s, 10s);
                break;
            }
            case SPELL_VANISH:
            {
                DoCast(SPELL_VANISH);
                events.Repeat(5s, 10s);
                break;
            }
            case SPELL_VENOM_STORM:
            {
                DoCast(SPELL_VENOM_STORM);
                events.Repeat(5s, 10s);
                break;
            }
            default:
                break;
            }
        }

        DoMeleeAttackIfReady();
    }

    void EnterCombat(Unit* /*victim*/) override
    {
        events.ScheduleEvent(SPELL_SPIDER_CALL, 5000);
        events.ScheduleEvent(SPELL_VANISH, 5000);
        events.ScheduleEvent(SPELL_VENOM_STORM, 5000);
    }

    void JustDied(Unit* /*killer*/) override
    {
        //open door
        if (GameObject* target = instance->GetGameObject(GO_BOSS1_DOOR_4))
            target->DestroyForNearbyPlayers();
    }

    void Initialize()
    {
        instance = me->GetInstanceScript();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
    }
private:
    InstanceScript * instance;
};

void AddSC_cathedral_of_eternal_night()
{
    RegisterCreatureAI(npc_nalasha_118705);
}
