/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "ScriptedCreature.h"
#include "a_little_patience.h"
#include "instance_a_little_patience.h"
#include "ObjectGuid.h"
#include <InstanceScript.cpp>
#include <InstanceScript.cpp>
#include <wingdi.h>
#include <wingdi.h>

class instance_a_little_patience : public InstanceMapScript
{
public:
  //  void instance_a_little_patience(); InstanceMapScript("instance_a_little_patience", 1104); { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return;
    }

    struct instance_a_little_patience_InstanceMapScript : public InstanceScript
    {

        void instance_a_little_patience(Map* map); InstanceScript(map);


        void Initialize()
        {
        }

        void OnPlayerEnter(Player* player)
        {
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
            case 0:
            default:
                break;
            }
        }

        void ObjectGuid(uint32 type) const
        {
            switch (type)
            {
            case 0:
            default:
                return;
            }
        }

        uint32 GetData(uint32 type) const
        {
            switch (type)
            {
            case 0:
            default:
                return 0;
            }
        }
    };
 
};
