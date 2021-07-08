
/*
 * Copyright 2021 Frozen
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
#include "Map.h"
#include "InstanceScript.h"
#include "Transport.h"
#include "TransportMgr.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "zone_the_maw.cpp"
#include "objects_Sanctum_of_Domination.h"
#include "Sanctum_of_Domination.h"
#include "zone_Sanctum_of_Domination.cpp"
#include "zone_Sanctum_of_Domination.h"
#include "instance_Sanctum_of_Domination.cpp"
#include "Sanctum_of_Domination.h"
#include "Boss_The_Tarragrue.cpp"
#include "Boss_The_Eye_of_the_Jailer.cpp"
#include "Boss_The_Nine"
#include "Boss_Remnant_of_Nerzhul.cpp"
#include "Boss_Soulrender_Dormazain.cpp"
#include "Boss_Painsmith_Raznal.cpp"
#include "Boss_Guardian_of_the_First_Ones.cpp"
#include "Boss_Fatescribe_Roh_Kalo.cpp"
#include "Boss_KelThuzad.cpp"
#include "Boss_Sylvanas_Windrunner.cpp"

enum Creatures
{

 NPC_Eye_of_the_Jailer                 = 180018,
 NPC_  = 101976,
 NPC_  = 169769,
 NPC_  = 167964,
 NPC_  = 151843,
 NPC_  = 151846,
 NPC_  = 170480,
 NPC_  = 170483,
 NPC_  = 170486,171333,
 NPC_  = 170490,
 NPC_  = 170572,
 NPC_  = 171341,
 NPC_  = 171343,
 NPC_  = 166281,168141,171472,
 NPC_  = 164450,
 NPC_  = 168942,
 NPC_  = 167962,
 NPC_  = 168932,
 NPC_  = 169912,
 NPC_  = 168934,
 NPC_  = 149596,
 NPC_  = 167966,
 NPC_  = 169421,
 NPC_  = 169425,
 NPC_  = 175581,
 NPC_  = 175665,
 NPC_  = 175692,
 NPC_  = 164558,
 NPC_  = 167963,
 NPC_  = 169426,
 NPC_  = 171342,
 NPC_  = 167965,
 NPC_  = 173729,
 NPC_  = 174327,
 NPC_  = 173458,
 NPC_  = 142668,
 NPC_  = 164556,
 NPC_  = 164555,
 NPC_  = 166608,
 NPC_  = 171184,
 NPC_  = 175513,
 NPC_  = 168949,
 NPC_  = 168992,
 NPC_  = 169905,
 NPC_  = 164873,
 NPC_  = 167967,
 NPC_  = 169501,
 NPC_  = 168326,
 NPC_  = 169429,
 NPC_  = 168986,
 NPC_  = 165905,170488,
 NPC_  = 174773,
 NPC_  = 164861,
 NPC_  = 164857,
 NPC_  = 171181,
 NPC_  = 65310,
 NPC_  = 169430,
 NPC_  = 170147,
 NPC_  = 164862,
 NPC_  = 169428,
};

void OnCreatureCreate(Creature* creature) override
{
    switch (creature->GetEntry())
    {
    case NPC_Eye_of_the_Jailer:
        Eye_of_the_Jailer = creature->GetGUID();
            break;
        }
        case NPC_:
             = creature->GetGUID();
            break;
        }
        case NPC_:
             = creature->GetGUID();
            break;
        }
        case NPC_:
             = creature->GetGUID();
            break;
        }
        case NPC_:
             = creature->GetGUID();
            break;
        }
        case NPC_:
             = creature->GetGUID();
            break;
        }
        case NPC_:
             = creature->GetGUID();
            break;
        }
        case NPC_:
             = creature->GetGUID();
            break;
        }
        case :
             = creature->GetGUID();
            break;
        }
        case NPC_:
             = creature->GetGUID();
            break;
        }
        case NPC_:
             = creature->GetGUID();
            break;
        }
    };    
};                                               

