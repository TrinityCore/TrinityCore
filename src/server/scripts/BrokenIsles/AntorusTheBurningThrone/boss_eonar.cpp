/*
* Copyright (C) 2021 BfaCore Reforged
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
#include "antorus.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "GameObject.h"
#include "ScriptedGossip.h"

//245764
enum Spells
{
    SPELL_LIFE_ENERGY = 257673,//life power
    SPELL_YELL_PASSED_POINTS_0 = 254447,
    SPELL_LIFE_FORCE = 250048,

    SPELL_ESSENCE_OF_THE_LIFEBINDER = 245764,
    SPELL_SURGE_OF_LIFE = 245781,

    SPELL_SURGE_OF_LIFE_BUFF = 245786,
    SPELL_SURGE_OF_LIFE_JUMP = 255079,
    SPELL_DIVE_DOWN = 254497,

    GO_BOX = 276503,
    NPC_THE_PARAXIS = 124445,

    NPC_FEL_INFUSED_DESTRUCTOR = 123760,
    NPC_FEL_HOUND = 123191,
    NPC_FELGUARD = 123451,
    NPC_FEL_LORD = 123452,
};
Position const boxpos = { -3968.913f,-10754.69f,696.663f };
Position const posData[] =
{
    { -3993.1f, -10939.099f, 721.812f, 0.0146f },
    { -3880.1f, -10927.4f, 685.9f, 0.0f },
    { -3927.58f, -10668.0f, 751.6f, 0.07f },
};

enum talkEvent
{
    EVENT_START = 1,
    EVENT_POWER_1,
    EVENT_POWER_2,
    EVENT_FINISH,
    EVENT_CHECK = 3000,
};

TalkData const talkData[] =
{
    { EVENT_START,         EVENT_TYPE_TALK,            0 },
    { SPELL_LIFE_FORCE,    EVENT_TYPE_TALK,            1 },
    { EVENT_POWER_1,       EVENT_TYPE_TALK,            2 },
    { EVENT_POWER_2,       EVENT_TYPE_TALK,            3 },
    { EVENT_FINISH,        EVENT_TYPE_TALK,            4 },
};

class playerscript_surge_of_life_trigger : public PlayerScript
{
public:
    playerscript_surge_of_life_trigger() : PlayerScript("playerscript_surge_of_life_trigger") {}

    uint32 checkTimer = 5000;
    bool needRecast = true;
  //void OnUpdateArea(Player* player, Area* newArea, Area* /*oldArea*/) override
  //  {
   /*     if (newArea->GetId() == 9333)
        {
            player->RemoveAurasDueToSpell(SPELL_ESSENCE_OF_THE_LIFEBINDER);
            player->RemoveAurasDueToSpell(SPELL_SURGE_OF_LIFE_BUFF);
            player->CastSpell(player, SPELL_ESSENCE_OF_THE_LIFEBINDER, true);
        }
    }*/

    void OnSuccessfulSpellCast(Player* player, Spell* spell)
    {
        if (player->GetAreaId() == 9333)
        {
            if (spell->GetSpellInfo()->Id == SPELL_SURGE_OF_LIFE)
            {
                player->RemoveAurasDueToSpell(SPELL_ESSENCE_OF_THE_LIFEBINDER);
                player->CastSpell(player, SPELL_SURGE_OF_LIFE_BUFF, true);
                player->CastSpell(player, SPELL_SURGE_OF_LIFE_JUMP, true);
                needRecast = true;
                checkTimer = 5000;
            }
            if (spell->GetSpellInfo()->Id == SPELL_DIVE_DOWN)
            {
                needRecast = true;
                checkTimer = 5000;
            }
        }
    }

    void OnUpdate(Player* player, uint32 diff) override
    {
        if (checkTimer <= diff)
        {
            if (needRecast && player->GetAreaId() == 9333)
            {
                player->RemoveAurasDueToSpell(SPELL_ESSENCE_OF_THE_LIFEBINDER);
                player->RemoveAurasDueToSpell(SPELL_SURGE_OF_LIFE_BUFF);
                player->CastSpell(player, SPELL_ESSENCE_OF_THE_LIFEBINDER, true);
                needRecast = false;
            }
            checkTimer = 5000;
        }
        else checkTimer -= diff;
    }

};
//122500
struct boss_essence_of_eonar : public BossAI
{
    boss_essence_of_eonar(Creature* creature) : BossAI(creature, DATA_ESSENCE_OF_EONAR) {}

    void DoAction(int32 action) override
    {
        if (action == EVENT_START)
        {
            GetTalkData(EVENT_START);
            instance->SetBossState(DATA_ESSENCE_OF_EONAR, SPECIAL);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
            me->SetPower(POWER_ENERGY, 0);
           // me->SetInt32Value(UNIT_FIELD_POWER + 1, 0);
            events.Reset();
            DoZoneInCombat();
            events.ScheduleEvent(EVENT_CHECK, 10000);
            events.ScheduleEvent(PHASE_01, 11s);
        }
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        player->CastSpell(player, 240796, true);
    }

    void SwitchPhase(uint32 phase)
    {
        switch (phase)
        {
        case PHASE_01:
        case PHASE_04:
        case PHASE_07:
            //NPC_FEL_INFUSED_DESTRUCTOR 15 ,NPC_FEL_HOUND,NPC_FELGUARD 5 ,NPC_FEL_LORD 5 40%
            me->SummonCreature(NPC_FEL_INFUSED_DESTRUCTOR, posData[0], TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            for (uint8 i = 0; i < 3; ++i)
                me->SummonCreature(NPC_FEL_HOUND, posData[0], TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            for (uint8 i = 0; i < 2; ++i)
                me->SummonCreature(NPC_FELGUARD, posData[0], TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            break;
        case PHASE_02:
        case PHASE_05:
            me->SummonCreature(NPC_FEL_INFUSED_DESTRUCTOR, posData[1], TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            for (uint8 i = 0; i < 3; ++i)
                me->SummonCreature(NPC_FEL_HOUND, posData[1], TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            for (uint8 i = 0; i < 2; ++i)
                me->SummonCreature(NPC_FELGUARD, posData[1], TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            break;
        case PHASE_03:
        case PHASE_06:
            me->SummonCreature(NPC_FEL_INFUSED_DESTRUCTOR, posData[2], TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            for (uint8 i = 0; i < 3; ++i)
                me->SummonCreature(NPC_FEL_LORD, posData[2], TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);
        switch (uint32 eventId = events.ExecuteEvent())
        {
        case PHASE_01:
        {
            SwitchPhase(PHASE_01);
            events.ScheduleEvent(PHASE_02, 35s);
            break;
        }
        case PHASE_02:
        {
            GetTalkData(SPELL_LIFE_FORCE);
            DoCast(SPELL_LIFE_FORCE);
            GetTalkData(EVENT_POWER_1);
            SwitchPhase(PHASE_02);
            events.ScheduleEvent(PHASE_03, 35s);
            break;
        }
        case PHASE_03:
        {
            SwitchPhase(PHASE_03);
            events.ScheduleEvent(PHASE_04, 40s);
            break;
        }
        case PHASE_04:
        {
            SwitchPhase(PHASE_04);
            events.ScheduleEvent(PHASE_05, 35s);
            break;
        }
        case PHASE_05:
        {
            GetTalkData(SPELL_LIFE_FORCE);
            DoCast(SPELL_LIFE_FORCE);
            GetTalkData(EVENT_POWER_2);
            SwitchPhase(PHASE_05);
            events.ScheduleEvent(PHASE_06, 35s);
            break;
        }
        case PHASE_06:
        {
            SwitchPhase(PHASE_06);
            events.ScheduleEvent(PHASE_07, 40s);
            break;

        case PHASE_07:
        {
            SwitchPhase(PHASE_07);
            events.ScheduleEvent(PHASE_08, 10s);
            break;
        }
        case PHASE_08:
        {
            GetTalkData(SPELL_LIFE_FORCE);
            DoCast(SPELL_LIFE_FORCE);
            GetTalkData(EVENT_FINISH);
            events.Reset();
            summons.DespawnAll();
            me->GetScheduler().CancelAll();
            if (instance)
            {
                instance->SetBossState(DATA_ESSENCE_OF_EONAR, DONE);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->SendBossKillCredit(2075);
            }
            me->SummonGameObject(GO_BOX, boxpos, QuaternionData(0.0f, 0.0f, -0.345448f, 0.938438f), WEEK);
            break;
       // }
       /* case EVENT_CHECK:
        {
            if (me->GetUInt32Value(UNIT_FIELD_POWER + 1) < 90)
            {
                int32 power = me->GetUInt32Value(UNIT_FIELD_POWER + 1);
                power = power + 10;
                me->SetPower(POWER_ENERGY, power);
                me->SetInt32Value(UNIT_FIELD_POWER + 1, power);
            }
            else if (me->GetUInt32Value(UNIT_FIELD_POWER + 1) >= 90)
            {
                me->SetPower(POWER_ENERGY, 0);
                me->SetInt32Value(UNIT_FIELD_POWER + 1, 0);
            }
            events.Repeat(10s);
            break;*/
        }
        }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && me->IsWithinDist(who, 50.0f, false) && !IsLock)
        {
            IsLock = true;
            DoAction(EVENT_START);
        }
    }
};

void AddSC_boss_eonar()
{
    new playerscript_surge_of_life_trigger();
    RegisterCreatureAI(boss_essence_of_eonar);
}
