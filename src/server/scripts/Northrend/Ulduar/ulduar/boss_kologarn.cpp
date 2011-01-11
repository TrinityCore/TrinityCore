/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ulduar.h"
#include "Vehicle.h"

#define SPELL_ARM_DEAD_DAMAGE   RAID_MODE(63629,63979)
#define SPELL_TWO_ARM_SMASH     RAID_MODE(63356,64003)
#define SPELL_ONE_ARM_SMASH     RAID_MODE(63573,64006)
#define SPELL_STONE_SHOUT       RAID_MODE(63716,64005)
#define SPELL_PETRIFY_BREATH    RAID_MODE(62030,63980)

#define SPELL_STONE_GRIP        RAID_MODE(62166,63981)
#define SPELL_STONE_GRIP_CANCEL 65594 
#define SPELL_ARM_SWEEP         RAID_MODE(63766,63983)
#define SPELL_ARM_VISUAL        64753 

#define SPELL_BERSERK           47008 // guess

enum Events
{
    EVENT_NONE = 0,
    EVENT_MELEE_CHECK,
    EVENT_SMASH,
    EVENT_STONE_SHOUT,
    EVENT_RESPAWN_ARM,
    EVENT_ENRAGE,
};

enum Yells
{
    SAY_AGGRO                                   = -1603230,
    SAY_SLAY_1                                  = -1603231,
    SAY_SLAY_2                                  = -1603232,
    SAY_LEFT_ARM_GONE                           = -1603233,
    SAY_RIGHT_ARM_GONE                          = -1603234,
    SAY_SHOCKWAVE                               = -1603235,
    SAY_GRAB_PLAYER                             = -1603236,
    SAY_DEATH                                   = -1603237,
    SAY_BERSERK                                 = -1603238,
};

enum
{
    ACHIEV_DISARMED_START_EVENT                   = 21687,
};

void EncounterInCombat(Creature* me, InstanceScript* pInstance)
{
    Creature* c;
    c = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(TYPE_KOLOGARN) : 0);
    if (c && c != me && c->isAlive())
        c->SetInCombatWithZone();

    c = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_RIGHT_ARM) : 0);
    if (c && c != me && c->isAlive())
        c->SetInCombatWithZone();
    
    c = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_LEFT_ARM) : 0);
    if (c && c != me && c->isAlive())
        c->SetInCombatWithZone();
}

class boss_kologarn : public CreatureScript
{
public:
    boss_kologarn() : CreatureScript("boss_kologarn") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_kologarnAI (pCreature);
    }

    struct boss_kologarnAI : public BossAI
    {
        boss_kologarnAI(Creature *pCreature) : BossAI(pCreature, TYPE_KOLOGARN), vehicle(pCreature->GetVehicleKit()),
            uiArmCount(0)
        {
            ASSERT(vehicle);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            SetCombatMovement(false);
            Reset();
        }

        Vehicle *vehicle;
        uint8 uiArmCount;

        void Reset()
        {
            _Reset();
        }

        void EnterCombat(Unit * /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);
            _EnterCombat();
            events.ScheduleEvent(EVENT_MELEE_CHECK, 6000);
            events.ScheduleEvent(EVENT_SMASH, 5000);
            events.ScheduleEvent(EVENT_ENRAGE, 600000);
            EncounterInCombat(me, instance);
        }

        void JustDied(Unit * /*victim*/)
        {
            DoScriptText(SAY_DEATH, me);
            _JustDied();
        }

        void KilledUnit(Unit* /*who*/)
        {
            DoScriptText(RAND(SAY_SLAY_2,SAY_SLAY_2), me);
        }

        void PassengerBoarded(Unit *who, int8 /*seatId*/, bool apply)
        {
            if (who->GetTypeId() == TYPEID_UNIT)
            {
                if (apply)
                {
                    ++uiArmCount;
                    events.CancelEvent(EVENT_STONE_SHOUT);
                }
                else
                {
                    if (--uiArmCount == 0)
                        events.ScheduleEvent(EVENT_STONE_SHOUT, 5000);

                    events.ScheduleEvent(EVENT_RESPAWN_ARM, 40000);
                    if (instance)
                        instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_DISARMED_START_EVENT);
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!me->getVictim() && instance->GetBossState(TYPE_KOLOGARN) == NOT_STARTED)
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            switch (events.GetEvent())
            {
                case EVENT_MELEE_CHECK:
                    if (!me->IsWithinMeleeRange(me->getVictim()))
                        DoCast(SPELL_PETRIFY_BREATH);
                    events.RepeatEvent(1000);
                    break;
                case EVENT_SMASH:
                    if (uiArmCount == 2)
                        DoCastVictim(SPELL_TWO_ARM_SMASH);
                    else if (uiArmCount == 1)
                        DoCastVictim(SPELL_ONE_ARM_SMASH);
                    events.RepeatEvent(15000);
                    break;
                case EVENT_STONE_SHOUT:
                    DoCast(SPELL_STONE_SHOUT);
                    events.RepeatEvent(2000);
                    break;
                case EVENT_ENRAGE:
                    DoCast(SPELL_BERSERK);
                    DoScriptText(SAY_BERSERK, me);
                    break;
                case EVENT_RESPAWN_ARM:
                {
                    Creature* curArm = Unit::GetCreature(*me, instance ? instance->GetData64(DATA_RIGHT_ARM) : 0);
                    if (!(curArm && curArm->isAlive()))
                        curArm = Unit::GetCreature(*me, instance ? instance->GetData64(DATA_LEFT_ARM) : 0);
                    if (!(curArm && curArm->isAlive()))
                        break;

                    curArm->Respawn();
                    curArm->SetInCombatWithZone();
                    curArm->EnterVehicle(me);
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_right_arm : public CreatureScript
{
public:
    npc_right_arm() : CreatureScript("npc_right_arm") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_right_armAI(pCreature);
    }

    struct npc_right_armAI : public ScriptedAI
    {
        npc_right_armAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = me->GetInstanceScript();
            SetCombatMovement(false);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            Reset();
        }

        uint32 uiStoneGripTimer;
        uint64 uiGrippedTargets[3];
        uint32 uiPermittedDamage;
        InstanceScript * pInstance;

        void EnterCombat(Unit* /*who*/)
        {
            EncounterInCombat(me, pInstance);
            uiStoneGripTimer = 30000;
        }

        void Reset()
        {
            memset(&uiGrippedTargets, 0, sizeof(uiGrippedTargets));
            uiPermittedDamage = RAID_MODE(100000, 480000);
            uiStoneGripTimer = 0;
            DoCast(SPELL_ARM_VISUAL);
        }

        void DamageTaken(Unit* /*who*/, uint32& damage)
        {
            if (uiGrippedTargets[0] == 0)
                return;

            if (damage > uiPermittedDamage)
                uiPermittedDamage = 0;
            else
                uiPermittedDamage -= damage;

            if (!uiPermittedDamage)
                ReleaseGrabbedPlayers();
        }

        void JustDied(Unit* /*who*/)
        {
            ReleaseGrabbedPlayers();

            if (Creature* Kologarn = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(TYPE_KOLOGARN) : 0))
            {
                if (Kologarn->isAlive())
                {
                    Kologarn->CastSpell(Kologarn, SPELL_ARM_DEAD_DAMAGE, true);
                    DoScriptText(SAY_RIGHT_ARM_GONE, Kologarn);
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiStoneGripTimer <= diff)
            {
                GrabPlayers();
                if (Creature* Kologarn = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(TYPE_KOLOGARN) : 0))
                    DoScriptText(SAY_GRAB_PLAYER, Kologarn);

                uiStoneGripTimer = urand(30000, 35000);
                uiPermittedDamage = RAID_MODE(100000, 480000);
            }
            else
                uiStoneGripTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void ReleaseGrabbedPlayers()
        {
             for (uint8 i = 0; i < RAID_MODE(1, 3); ++i)
                    if (Unit* grabbed = Unit::GetUnit(*me, uiGrippedTargets[i]))
                        me->CastSpell(grabbed, SPELL_STONE_GRIP_CANCEL, false);
        }

        void GrabPlayers()
        {
            for (uint8 i = 0; i < RAID_MODE(1, 3); ++i)
            {
                if (Unit* grabbed = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                {
                    DoCast(grabbed, SPELL_STONE_GRIP);
                    uiGrippedTargets[i] = grabbed->GetGUID();
                }
            }
        }
    };
};

class npc_left_arm : public CreatureScript
{
public:
    npc_left_arm() : CreatureScript("npc_left_arm") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_left_armAI(pCreature);
    }

    struct npc_left_armAI : public ScriptedAI
    {
        npc_left_armAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = me->GetInstanceScript();
            SetCombatMovement(false);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            Reset();
        }

        uint32 uiSweepTimer;
        InstanceScript * pInstance;

        void EnterCombat(Unit* /*who*/)
        {
            EncounterInCombat(me, pInstance);
            uiSweepTimer = 15000;
        }

        void Reset()
        {
            DoCast(SPELL_ARM_VISUAL);
            EncounterInCombat(me, pInstance);
            uiSweepTimer = 0;
        }

        void JustDied(Unit* /*who*/)
        {
            if (Creature* Kologarn = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(TYPE_KOLOGARN) : 0))
            {
                if (Kologarn->isAlive())
                {
                    Kologarn->CastSpell(Kologarn, SPELL_ARM_DEAD_DAMAGE, true);
                    DoScriptText(SAY_LEFT_ARM_GONE, Kologarn);
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiSweepTimer <= diff)
            {
                DoCast(SPELL_ARM_SWEEP);
                uiSweepTimer = urand(15000, 25000);
            }
            else
                uiSweepTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_kologarn()
{
    new boss_kologarn();
    new npc_right_arm();
    new npc_left_arm();
}
