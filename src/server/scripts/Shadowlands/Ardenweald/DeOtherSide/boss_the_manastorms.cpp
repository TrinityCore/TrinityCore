/*
* Copyright 2021 ShadowCore
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
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "SpellAuraEffects.h"
#include "de_other_side.h"

enum Spells
{
    SPELL_FROSTBOLT = 320008,
    SPELL_SUMMON_POWER_CRYSTAL = 320787,
    SPELL_POWER_OVERWHELMING_MOD_STATS = 320785,
    SPELL_ECHO_FINGER_LASER_MARK = 323877,
    SPELL_ECHO_FINGER_LASER_DAMAGE = 323992,
    SPELL_ECHO_FINGER_LASER_CREATE_AT = 324011, //19844
    SPELL_ECHO_FINGER_LASER_CREATE_AT_2 = 323903, //19797
    SPELL_ECHO_FINGER_LASER_CREATE_AT_3 = 323900, //19795
    SPELL_THROW_BUZZ_SAW = 320168,
    SPELL_BUZZ_SAW_ROOT = 330434,
    SPELL_BLEEDING = 320147,
    SPELL_SUMMON_EXPERIMENTAL_SQUIRREL_BOMB = 320811,
    SPELL_SUMMON_EXPERIMENTAL_SQUIRREL_BOMB_DAMAGE = 320804,
    SPELL_SHADOWFURY = 320132,
};

//164556,164555
struct boss_the_manastorms : public BossAI
{
    boss_the_manastorms(Creature* c) : BossAI(c, DATA_THE_MANASTORMS) { }

    void Reset() override
    {
        switch (me->GetEntry())
        {
        case NPC_MILLHOUSE_MANASTORM:
        case NPC_MILLIFICENT_MANASTORM:
            BossAI::Reset();
            break;
        }
    }

    void EnterCombat(Unit* /*who*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_MILLHOUSE_MANASTORM:
            _EnterCombat();
            events.ScheduleEvent(SPELL_FROSTBOLT, 1s);
            events.ScheduleEvent(SPELL_SUMMON_POWER_CRYSTAL, 3s);
            events.ScheduleEvent(SPELL_ECHO_FINGER_LASER_MARK, 5s);
            events.ScheduleEvent(SPELL_SHADOWFURY, 10s);
            if (Creature* millificent = me->FindNearestCreature(NPC_MILLHOUSE_MANASTORM, 100.0f, true))
                millificent->AI()->DoZoneInCombat();
            break;

        case NPC_MILLIFICENT_MANASTORM:
            _EnterCombat();
            events.ScheduleEvent(SPELL_THROW_BUZZ_SAW, 3s);
            events.ScheduleEvent(SPELL_SUMMON_EXPERIMENTAL_SQUIRREL_BOMB, 5s);
            if (Creature* millhouse = me->FindNearestCreature(NPC_MILLHOUSE_MANASTORM, 100.0f, true))
                millhouse->AI()->DoZoneInCombat();
            break;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_FROSTBOLT:
            DoCastRandom(SPELL_FROSTBOLT, 100.0f, false);
            events.Repeat(3s);
            break;

        case SPELL_SUMMON_POWER_CRYSTAL:
            me->CastSpell(nullptr, SPELL_SUMMON_POWER_CRYSTAL, false);
            events.Repeat(20s, 25s);
            break;

        case SPELL_ECHO_FINGER_LASER_MARK:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, 100.0f);
            if (targetList.size() > 2)
            {
                targetList.resize(2);
                for (Player* targets : targetList)
                {
                    me->CastSpell(targets, SPELL_ECHO_FINGER_LASER_MARK, true);                
                }
            }
            events.Repeat(30s);
            break;
        }

        case SPELL_SUMMON_EXPERIMENTAL_SQUIRREL_BOMB:
            for (uint8 i = 0; i < 2; i++)
            {
                me->CastSpell(me->GetRandomNearPosition(20.0f), SPELL_SUMMON_EXPERIMENTAL_SQUIRREL_BOMB, true);
            }
            events.Repeat(10s, 15s);
            break;

        case SPELL_THROW_BUZZ_SAW:
            DoCastRandom(SPELL_THROW_BUZZ_SAW, 100.0f, false);
            events.Repeat(18s, 20s);
            break;

        case SPELL_SHADOWFURY:
            DoCastRandom(SPELL_SHADOWFURY, 100.0f, false);
            events.Repeat(35s);
            break;
        }
    }

    void JustReachedHome() override
    {
        switch (me->GetEntry())
        {
        case NPC_MILLHOUSE_MANASTORM:
        case NPC_MILLIFICENT_MANASTORM:
            _JustReachedHome();
            me->RemoveAllAreaTriggers();
            break;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_MILLHOUSE_MANASTORM:
        case NPC_MILLIFICENT_MANASTORM:
            me->RemoveAllAreaTriggers();
            _DespawnAtEvade();
            break;
        }
    }

    void JustDied(Unit* /*who*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_MILLHOUSE_MANASTORM:
        case NPC_MILLIFICENT_MANASTORM:
            _JustDied();
            me->RemoveAllAreaTriggers();
            break;
        }
    }
};

void AddSC_boss_the_manastorms()
{
    RegisterCreatureAI(boss_the_manastorms);
}