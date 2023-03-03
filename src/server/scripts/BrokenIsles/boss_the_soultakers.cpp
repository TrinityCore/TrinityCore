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

#include "ScriptMgr.h"
#include "AreaTriggerAI.h"

enum eSpells
{
    // SOULTAKERS
  // capitan
    SPELL_TENTACLE_BASH = 213420,
    SPELL_SHATTER_CREWMEN = 213532,
    SPELL_CURSED_CREW = 213522,
    //ydorn
    SPELL_MARAUDING_MISTS = 213665,
    SPELL_SEADOG_SCUTTLE_COST = 213580,
    SPELL_SEADOG_SCUTTLE = 213584,
    SPELL_SEADOG_SCUTTLE_TRIG = 213588,
    // mevra
    SPELL_TELEPORT = 215681,
    SPELL_EXPEL_SOUL = 213625,
    SPELL_SOUL_REND = 213605,
    SPELL_SOUL_REND_TRIG = 213638,

    //add
    SPELL_SHATTER_CREWMEN_ADD = 213533,
};

enum Bosses
{
    NPC_CAPITAN = 106981,
    NPC_YDORN = 106982,
    NPC_MEVRA = 106984,
};

uint32 const _Bosses[3]
{
    NPC_CAPITAN,
    NPC_YDORN,
    NPC_MEVRA
};

Position const tpPos[6] =
{
    {4930.69f, 489.92f, -53.34f, 2.71f},
    {4904.75f, 471.04f, -53.34f, 2.21f},
    {4863.42f, 449.40f, -53.34f, 1.36f},
    {4840.75f, 476.77f, -53.34f, 0.60f},
    {4820.06f, 510.35f, -53.34f, 0.11f},
    {4878.81f, 524.31f, -48.90f, 4.52f}
};
/*
// 106981 106982 106984
class boss_soultakers : public CreatureScript
{
public:
    boss_soultakers() : CreatureScript("boss_soultakers") {}

    struct boss_soultakersAI : public ScriptedAI
    {
        boss_soultakersAI(Creature* creature) : ScriptedAI(creature), timer_for_energy(0)
        {
        }

        EventMap events;
        uint32 timer_for_energy;

        void Reset() override
        {
            events.Reset();
          //  me->RemoveAllAreaObjects();
           // me->setPowerType(POWER_ENERGY);
            me->SetPower(POWER_ENERGY, 0);
            timer_for_energy = 1000;
        }

        void EnterCombat(Unit* unit) override
        {
            if (me->GetEntry() == NPC_CAPITAN || me->GetEntry() == NPC_YDORN)
                events.RescheduleEvent(1, urand(13000, 16000));
            if (me->GetEntry() == NPC_MEVRA)
                events.RescheduleEvent(3, 1000); // 9000

            events.RescheduleEvent(10, 1000); // check for energy

            for (int32 n = 0; n < 3; n++)
                if (me->GetEntry() != _Bosses[n])
                    if (Creature* targ = me->FindNearestCreature(_Bosses[n], 100.0f))
                    {
                        if (targ->IsAlive())
                            targ->AI()->AttackStart(unit);
                        else
                            targ->Respawn(false);
                    }
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell) override
        {
            if (me->GetEntry() == NPC_CAPITAN)
            {
                if (spell->Id == SPELL_SHATTER_CREWMEN)
                {
                    if (target->GetTypeId() == TYPEID_UNIT)
                    {
                        if (target->ToCreature()->GetEntry() == 107569)
                        {
                            if (target->IsAlive())
                            {
                                target->CastSpell(target, SPELL_SHATTER_CREWMEN_ADD);
                                target->ToCreature()->DespawnOrUnsummon(500);
                            }
                        }
                    }
                }
            }

            if (me->GetEntry() == NPC_MEVRA)
            {
                if (spell->Id == SPELL_SOUL_REND_TRIG)
                {
                    me->CastSpell(target, 213648, true);
                }
            }
        }

        void DamageTaken(Unit* /atacker/ attacker, uint32 &damage) override
        {
            if (attacker != me)
                for (int32 n = 0; n < 3; n++)
                    if (me->GetEntry() != _Bosses[n])
                        if (Creature* targ = me->FindNearestCreature(_Bosses[n], 100.0f, true))
                        {
                            if (damage >= me->GetHealth())
                                attacker->Kill(targ);
                            else
                                targ->DealDamage(targ, damage); // targ->GetHealth() 
                        }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (timer_for_energy <= diff)
            {
                uint32 power = me->GetPower(POWER_ENERGY);
                if (power < 100)
                    me->SetPower(POWER_ENERGY, ++power);
                timer_for_energy = urand(1000, 1300);
            }
            else
                timer_for_energy -= diff;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    if (me->GetEntry() == NPC_CAPITAN)
                        DoCast(SPELL_TENTACLE_BASH);
                    else
                        DoCast(SPELL_MARAUDING_MISTS);
                    events.RescheduleEvent(1, urand(15000, 17000));
                    break;
                case 2:
                    DoCast(SPELL_SHATTER_CREWMEN);
                    break;
                case 3:
                {
                    uint32 rand = urand(0, 5);
                    me->CastSpell(tpPos[rand].GetPositionX(), tpPos[rand].GetPositionY(), tpPos[rand].GetPositionZ(), SPELL_TELEPORT);
                    if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 70.0f, true))
                        me->CastSpell(target, SPELL_EXPEL_SOUL);
                    events.RescheduleEvent(3, 8500);
                }
                break;
                case 10:
                {
                    uint32 power = me->GetPower(POWER_ENERGY);
                    if (power == 100)
                    {
                        switch (me->GetEntry())
                        {
                        case NPC_CAPITAN:
                            DoCast(SPELL_CURSED_CREW);
                            events.RescheduleEvent(2, 4000);
                            break;
                        case NPC_YDORN:
                            // repeat this 3 time
                            me->SetReactState(REACT_PASSIVE);
                            me->SetReactState(REACT_PASSIVE);
                            DoCast(SPELL_SEADOG_SCUTTLE_COST);
                            if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 70.0f, true))
                            {
                                me->CastSpell(target, SPELL_SEADOG_SCUTTLE);
                                me->CastSpell(target, SPELL_SEADOG_SCUTTLE_TRIG);
                            }

                           // me->AddDelayedEvent(5000, [this]() -> void
                            {
                                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 70.0f, true))
                                {
                                    me->CastSpell(target, SPELL_SEADOG_SCUTTLE);
                                    me->CastSpell(target, SPELL_SEADOG_SCUTTLE_TRIG);
                                }
                          //  });

                         //   me->AddDelayedEvent(10000, [this]() -> void
                            {
                                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 70.0f, true))
                                {
                                    me->CastSpell(target, SPELL_SEADOG_SCUTTLE);
                                    me->CastSpell(target, SPELL_SEADOG_SCUTTLE_TRIG);
                                }
                           // });

                          //  me->AddDelayedEvent(15000, [this]() -> void
                            {
                                me->SetReactState(REACT_AGGRESSIVE);
                         //   });
                            break;
                        case NPC_MEVRA:
                            DoCast(SPELL_SOUL_REND);
                            break;
                        }
                          me->SetPower(POWER_ENERGY, 0);
                    }
                     else
                         me->SetPower(POWER_ENERGY, ++power);
                    events.RescheduleEvent(10, urand(1000, 1100));
                }
                break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };*/

   // CreatureAI* GetAI(Creature* creature) const override
 //   {
 //       return new boss_soultakersAI(creature);
 //   }
//};

void AddSC_boss_the_soultakers()
{
    //new boss_soultakers();
}
