/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_MOVEMENTGENERATOR_H
#define TRINITY_MOVEMENTGENERATOR_H

#include "Define.h"
#include <ace/Singleton.h>
#include "ObjectRegistry.h"
#include "FactoryHolder.h"
#include "Common.h"
#include "MotionMaster.h"

class Unit;
class MovementGenerator
{
    public:
        virtual ~MovementGenerator();
        //! Called after adding movement generator to motion slot
        virtual void Initialize(Unit &) = 0;
        //! Called after remove movement generator from motion slot
        virtual void Finalize(Unit &unit) { unit.StopMoving(); }
        //! Called after return movement generator to top position (after remove above movement generator)
        virtual void Reset(Unit &) = 0;
        //! Called in MotionMaster::UpdateMotion
        virtual bool Update(Unit &, const uint32 time_diff) = 0;
        //! Get current movement generator type
        virtual MovementGeneratorType GetMovementGeneratorType() = 0;
        //! Stop current movement generator for some period of time (should be supported by movement generator)
        virtual void StopMovement(uint32) {}

        virtual void unitSpeedChanged() { }
};

template<class T, class D>
class MovementGeneratorMedium : public MovementGenerator
{
    public:
        void Initialize(Unit &unit)
        {
            //u->AssertIsType<T>();
            (static_cast<D*>(this))->Initialize(*((T*)&unit));
        }
        void Finalize(Unit &unit)
        {
            //u->AssertIsType<T>();
            MovementGenerator::Finalize(unit);
            (static_cast<D*>(this))->Finalize(*((T*)&unit));
        }
        void Reset(Unit &unit)
        {
            //u->AssertIsType<T>();
            (static_cast<D*>(this))->Reset(*((T*)&unit));
        }
        bool Update(Unit &unit, const uint32 time_diff)
        {
            //u->AssertIsType<T>();
            return (static_cast<D*>(this))->Update(*((T*)&unit), time_diff);
        }
    public:
        // will not link if not overridden in the generators
        void Initialize(T &unit);
        void Finalize(T &unit);
        void Reset(T &unit);
        bool Update(T &unit, const uint32 time_diff);
};

struct SelectableMovement : public FactoryHolder<MovementGenerator, MovementGeneratorType>
{
    SelectableMovement(MovementGeneratorType mgt) : FactoryHolder<MovementGenerator, MovementGeneratorType>(mgt) {}
};

template<class REAL_MOVEMENT>
struct MovementGeneratorFactory : public SelectableMovement
{
    MovementGeneratorFactory(MovementGeneratorType mgt) : SelectableMovement(mgt) {}

    MovementGenerator* Create(void *) const;
};

typedef FactoryHolder<MovementGenerator, MovementGeneratorType> MovementGeneratorCreator;
typedef FactoryHolder<MovementGenerator, MovementGeneratorType>::FactoryHolderRegistry MovementGeneratorRegistry;
typedef FactoryHolder<MovementGenerator, MovementGeneratorType>::FactoryHolderRepository MovementGeneratorRepository;
#endif

