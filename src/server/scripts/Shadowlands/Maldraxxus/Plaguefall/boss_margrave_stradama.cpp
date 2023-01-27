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
#include "InstanceScript.h"
#include "SpellAuras.h"
#include "plaguefall.h"

enum Spells
{
    SPELL_PLAGUE_ROT_CAST = 322491,
    SPELL_PLAGUE_ROT_PERIODIC = 322492,
    SPELL_INFECTION_RAIN = 322232,
    SPELL_PLAGUE_CRASH_MAIN_LAND = 322475,
    EVENT_PLAGUE_CRASH_END = 1,
};

//164267
struct boss_margrave_stradama : public BossAI
{
    boss_margrave_stradama(Creature* creature) : BossAI(creature, DATA_MARGRAGE_STRADAMA) { }

private:
    bool hp66;
    bool hp33;

    void Reset() override
    {
        BossAI::Reset();
        SetCombatMovement(false);
        me->SetPowerType(POWER_MANA);
        me->SetMaxPower(POWER_MANA, 100);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        Talk(0);
        me->SummonCreature(NPC_MALIGNANT_SPAWN, me->GetRandomNearPosition(15.0f), TEMPSUMMON_MANUAL_DESPAWN);
        events.ScheduleEvent(SPELL_INFECTION_RAIN, 15s);
    }

    void ExecuteEvent(uint32 eventId) override
    {         
        switch (eventId)
        {
        case SPELL_INFECTION_RAIN:
            me->CastSpell(nullptr, SPELL_INFECTION_RAIN, false);
            events.Repeat(25s, 30s);
            break;

        case EVENT_PLAGUE_CRASH_END:            
            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            me->SetReactState(REACT_AGGRESSIVE);
            me->SummonCreature(NPC_MALIGNANT_SPAWN, me->GetRandomNearPosition(15.0f), TEMPSUMMON_MANUAL_DESPAWN);
            events.ScheduleEvent(SPELL_INFECTION_RAIN, 15s);
            break;
        }
    }

    void DamageTaken(Unit* done_by, uint32& damage) override
    {
        if (me->HealthBelowPct(66) && !hp66)
        {
            hp66 = true;
            me->SetReactState(REACT_PASSIVE);
            events.Reset();
            me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);

            std::list<Creature*> teleportStalkerList;
            me->GetCreatureListWithEntryInGrid(teleportStalkerList, NPC_TELEPORT_STALKER, 50.0f);
            for (Creature* stalkers : teleportStalkerList)
            {
                stalkers->CastSpell(nullptr, SPELL_PLAGUE_CRASH_MAIN_LAND, false);
            }
            for (uint8 i = 0; i < 4; i++)
            {
                me->SummonCreature(NPC_PLAGUE_DEVOTED, me->GetRandomNearPosition(25.0f), TEMPSUMMON_MANUAL_DESPAWN);
            }
            events.ScheduleEvent(EVENT_PLAGUE_CRASH_END, 15s);
        }
        if (me->HealthBelowPct(33) && !hp33)
        {
            hp66 = true;
            me->SetReactState(REACT_PASSIVE);
            events.Reset();
            me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);

            std::list<Creature*> teleportStalkerList;
            me->GetCreatureListWithEntryInGrid(teleportStalkerList, NPC_TELEPORT_STALKER, 50.0f);
            for (Creature* stalkers : teleportStalkerList)
            {
                stalkers->CastSpell(nullptr, SPELL_PLAGUE_CRASH_MAIN_LAND, false);
            }
            for (uint8 i = 0; i < 4; i++)
            {
                me->SummonCreature(NPC_PLAGUE_DEVOTED, me->GetRandomNearPosition(25.0f), TEMPSUMMON_MANUAL_DESPAWN);
            }
            events.ScheduleEvent(EVENT_PLAGUE_CRASH_END, 15s);
        }
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        _JustReachedHome();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*who*/) override
    {
        _JustDied();
        Talk(4);
        me->RemoveAllAreaTriggers();
    }
};

void AddSC_boss_margrave_stradama()
{
    RegisterCreatureAI(boss_margrave_stradama);
}
