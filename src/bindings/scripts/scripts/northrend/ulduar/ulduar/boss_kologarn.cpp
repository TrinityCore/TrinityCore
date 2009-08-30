/*
 * Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "precompiled.h"
#include "def_ulduar.h"
#include "Vehicle.h"

#define SPELL_ARM_DEAD_DAMAGE   HEROIC(63629,63979)
#define SPELL_TWO_ARM_SMASH     HEROIC(63356,64003)
#define SPELL_ONE_ARM_SMASH     HEROIC(63573,64006)
#define SPELL_STONE_SHOUT       HEROIC(63716,64005)
#define SPELL_PETRIFY_BREATH    HEROIC(62030,63980)

#define SPELL_STONE_GRIP        HEROIC(62166,63981)
#define SPELL_ARM_SWEEP         HEROIC(63766,63983)

struct TRINITY_DLL_DECL boss_kologarnAI : public BossAI
{
    boss_kologarnAI(Creature *c) : BossAI(c, BOSS_KOLOGARN), vehicle(me->GetVehicleKit()),
        leftArm(NULL), rightArm(NULL)
    {
        assert(vehicle);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
    }

    Vehicle *vehicle;
    Creature *leftArm, *rightArm;

    void AttackStart(Unit *who)
    {
        me->Attack(who, true);
        if(leftArm)
            leftArm->Attack(who, true);
        if(rightArm)
            rightArm->Attack(who, true);
    }

    void MeleeSwing(WeaponAttackType type)
    {
        me->AttackerStateUpdate(me->getVictim(), type);
        if(leftArm)
            leftArm->AttackerStateUpdate(me->getVictim(), type);
        if(rightArm)
            rightArm->AttackerStateUpdate(me->getVictim(), type);
    }

    void PassengerBoarded(Unit *who, int8 seatId, bool apply)
    {
        if(who->GetEntry() == 32933)
            leftArm = apply ? CAST_CRE(who) : NULL;
        else if(who->GetEntry() == 32934)
            rightArm = apply ? CAST_CRE(who) : NULL;
        who->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
    }

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim())
            return;

        if (me->isAttackReady())
        {
            //If we are within range melee the target
            if (me->IsWithinMeleeRange(me->getVictim()))
            {
                WeaponAttackType type = BASE_ATTACK;
                if(leftArm && (!rightArm || rand()%2)) type = OFF_ATTACK;
                MeleeSwing(type);
                me->resetAttackTimer();
            }
        }
    }
};

CreatureAI* GetAI_boss_kologarn(Creature* pCreature)
{
    return new boss_kologarnAI (pCreature);
}

void AddSC_boss_kologarn()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_kologarn";
    newscript->GetAI = &GetAI_boss_kologarn;
    newscript->RegisterSelf();
}
