/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "PointMovementGenerator.h"
#include "Errors.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "World.h"
#include "MoveSplineInit.h"
#include "MoveSpline.h"
#include "Player.h"
#include "CreatureGroups.h"

template<class T>
void PointMovementGenerator<T>::DoInitialize(T* owner)
{
    if (!owner->IsStopped())
        owner->StopMoving();

    if (m_id == EVENT_CHARGE_PREPATH)
    {
        owner->AddUnitState(UNIT_STATE_ROAMING | UNIT_STATE_ROAMING_MOVE);
        return;
    }

    owner->AddUnitState(UNIT_STATE_ROAMING);

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE))
    {
        m_interrupt = true;
        return;
    }

    owner->AddUnitState(UNIT_STATE_ROAMING_MOVE);

    Movement::MoveSplineInit init(owner);
    init.MoveTo(m_x, m_y, m_z, m_generatePath);
    if (m_speed > 0.0f)
        init.SetVelocity(m_speed);
    init.Launch();

    /* Figure out a better way */
    /*
    // Call for creature group update
    if (Creature* creature = unit->ToCreature())
        if (creature->GetFormation() && creature->GetFormation()->getLeader() == creature)
            creature->GetFormation()->LeaderMoveTo(m_x, m_y, m_z);
    */
}

template<class T>
bool PointMovementGenerator<T>::DoUpdate(T* owner, uint32 /*diff*/)
{
    if (!owner)
        return false;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE))
    {
        owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
        return true;
    }

    owner->AddUnitState(UNIT_STATE_ROAMING_MOVE);

    if (m_id == EVENT_CHARGE_PREPATH)
        return !owner->movespline->Finalized();

    if (m_interrupt || (m_recalculateSpeed && !owner->movespline->Finalized()))
    {
        m_recalculateSpeed = false;
        m_interrupt = false;

        Movement::MoveSplineInit init(owner);
        init.MoveTo(m_x, m_y, m_z, m_generatePath);
        if (m_speed > 0.0f) // Default value for point motion type is 0.0, if 0.0 spline will use GetSpeed on unit
            init.SetVelocity(m_speed);
        init.Launch();

        /* Figure out a better way */
        /*
        // Call for creature group update
        if (Creature* creature = unit->ToCreature())
            if (creature->GetFormation() && creature->GetFormation()->getLeader() == creature)
                creature->GetFormation()->LeaderMoveTo(m_x, m_y, m_z);
        */
    }

    return !owner->movespline->Finalized();
}

template<class T>
void PointMovementGenerator<T>::DoFinalize(T* owner)
{
    if (owner->HasUnitState(UNIT_STATE_CHARGING))
        owner->ClearUnitState(UNIT_STATE_ROAMING | UNIT_STATE_ROAMING_MOVE);

    if (owner->movespline->Finalized())
        MovementInform(owner);
}

template<class T>
void PointMovementGenerator<T>::DoReset(T* owner)
{
    if (!owner->IsStopped())
        owner->StopMoving();

    owner->AddUnitState(UNIT_STATE_ROAMING | UNIT_STATE_ROAMING_MOVE);
}

template<class T>
void PointMovementGenerator<T>::MovementInform(T*) { }

template <> void PointMovementGenerator<Creature>::MovementInform(Creature* owner)
{
    if (owner->AI())
        owner->AI()->MovementInform(POINT_MOTION_TYPE, m_id);
}

template<class T>
void PointMovementGenerator<T>::DoInterrupt(T* owner)
{
    if (!m_interrupt && !owner->movespline->Finalized())
    {
        owner->ClearUnitState(UNIT_STATE_MOVING);
        Movement::MoveSplineInit init(owner);
        init.Stop();
    }

    m_interrupt = true;
}

template void PointMovementGenerator<Player>::DoInitialize(Player*);
template void PointMovementGenerator<Creature>::DoInitialize(Creature*);
template void PointMovementGenerator<Player>::DoFinalize(Player*);
template void PointMovementGenerator<Creature>::DoFinalize(Creature*);
template void PointMovementGenerator<Player>::DoReset(Player*);
template void PointMovementGenerator<Creature>::DoReset(Creature*);
template bool PointMovementGenerator<Player>::DoUpdate(Player*, uint32);
template bool PointMovementGenerator<Creature>::DoUpdate(Creature*, uint32);
template void PointMovementGenerator<Player>::DoInterrupt(Player*);
template void PointMovementGenerator<Creature>::DoInterrupt(Creature*);

//---- AssistanceMovementGenerator

template<class T>
void AssistanceMovementGenerator<T>::DoFinalize(T* owner)
{
    if (owner->movespline->Finalized())
    {
        PointMovementGenerator<T>::MovementInform(owner);
        owner->ToCreature()->SetNoCallAssistance(false);
        owner->ToCreature()->CallAssistance();
        if (owner->IsAlive())
            owner->GetMotionMaster()->MoveSeekAssistanceDistract(sWorld->getIntConfig(CONFIG_CREATURE_FAMILY_ASSISTANCE_DELAY));
    }
}

template void AssistanceMovementGenerator<Creature>::DoFinalize(Creature*);

//---- EffectMovementGenerator

bool EffectMovementGenerator::Update(Unit* owner, uint32)
{
    return !owner->movespline->Finalized();
}

void EffectMovementGenerator::Finalize(Unit* owner)
{
    /* Previous movement is stored in motionMaster no need to recreate */
    /*
    if (unit->IsAlive() && !unit->HasUnitState(UNIT_STATE_CONFUSED | UNIT_STATE_FLEEING))
    {
        if (Unit* victim = unit->GetVictim())
            unit->GetMotionMaster()->MoveChase(victim);
        else
            unit->GetMotionMaster()->Initialize();
    }
    */

    if (owner->movespline->Finalized())
        MovementInform(owner);
}

void EffectMovementGenerator::MovementInform(Unit* owner)
{
    if (Creature* creature = owner->ToCreature())
        if (creature->AI())
            creature->AI()->MovementInform(EFFECT_MOTION_TYPE, m_id);
}
