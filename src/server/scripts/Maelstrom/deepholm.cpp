/*
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
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

#include "Map.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "TaskScheduler.h"
#include "Vehicle.h"
#include "CombatAI.h"

enum Spells
{
    SPELL_CAMERA_1                       = 84364,
    SPELL_FORCECAST_AGGRA_PING           = 96123,
    SPELL_AGGRA_PING                     = 96122,
    SPELL_PRE_FORCECAST_SWITCH_TO_SEAT_3 = 86971,
    SPELL_FORCECAST_TELEPORT             = 84093,
    SPELL_DEEPHOLM_INTRO_TELEPORT        = 84073,
    SPELL_DEEPHOLM_INTRO_TAXI            = 84101, // Summons Wyvern vehicle
    SPELL_EJECT_PASSENGER_2              = 62539,
};

enum NPCs
{
//  NPC_DEEPHOLM_INTRO_WYVERN_1          = 45004,
    NPC_DEEPHOLM_INTRO_WYVERN_2          = 45024,
    NPC_DEEPHOLM_INTRO_AGGRA_1           = 45028,
    NPC_DEEPHOLM_INTRO_AGGRA_2           = 45027,
};

enum Points
{
    POINT_INTRO = 1,
};

uint32 const WyvernFirstPathSize = 10;
Position const WyvernFirstPath[WyvernFirstPathSize] = // sniff
{
    { 770.34f,  949.726f,  34.8637f  },
    { 792.222f, 737.495f,  34.8637f  },
    { 920.221f, 698.87f,    3.86366f },
    { 985.457f, 788.34f,  -31.0252f  },
    { 937.471f, 883.339f, -39.7197f  },
    { 835.682f, 853.524f, -54.1363f  },
    { 842.057f, 757.833f, -80.2752f  },
    { 948.002f, 751.8f,   -107.581f  },
    { 947.352f, 798.976f, -147.995f  },
    { 893.021f, 788.55f,  -245.521f  },
};

/*uint32 const WyvernSecondPathSize = 3;
Position const WyvernSecondPath[WyvernFirstPathSize] = // sniff
{
    { 907.95f,  502.139f, -44.4632f },
    { 882.642f, 499.205f, -28.8255f },
    { 869.17f,  497.146f, -22.7786f },
};*/

uint32 const WyvernThirdPathSize = 7;
Position const WyvernThirdPath[WyvernFirstPathSize] = // sniff
{
    { 1109.14f, 649.396f, 413.65f   },
    { 954.589f, 657.99f,  289.706f  },
    { 875.491f, 621.337f, 191.761f  },
    { 837.281f, 565.34f,  122.955f  },
    { 820.571f, 487.705f,  39.7609f },
    { 903.094f, 501.446f, -36.7289f },
    { 935.057f, 506.95f,  -48.1708f },
};

// To-do:
//  - SPELL_DEEPHOLM_INTRO_TAXI summons a vehicle player has to enter, but he won't.
//    Is OnPlayerEnter called too soon when changing map? Because spell summon itself works when cast manually.
class zone_deepholm : public WorldMapScript
{
public:
    zone_deepholm() : WorldMapScript("zone_deepholm", 646) { }

    void OnPlayerEnter(Map* /*map*/, Player* player) override
    {
        if (player->HasAura(SPELL_DEEPHOLM_INTRO_TELEPORT))
            player->CastSpell((Unit*)nullptr, SPELL_DEEPHOLM_INTRO_TAXI, true);
    }
};

// To-do:
//  - Find out why this NPC won't cast spell.
class npc_deepholm_intro_wyvern : public CreatureScript
{
public:
    npc_deepholm_intro_wyvern() : CreatureScript("npc_deepholm_intro_wyvern") { }

    struct npc_deepholm_intro_wyvernAI : public VehicleAI
    {
        npc_deepholm_intro_wyvernAI(Creature* creature) : VehicleAI(creature)
        {
            teleported = me->GetEntry() == NPC_DEEPHOLM_INTRO_WYVERN_2;
            me->CastSpell((Unit*)nullptr, SPELL_CAMERA_1, true);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (!summoner->IsOnVehicle(me))
                summoner->EnterVehicle(me->GetVehicleBase(), 1);
        }

        void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
        {
            if (passenger->GetTypeId() != TYPEID_PLAYER || !apply)
                return;
            
            passenger->ChangeSeat(1, false);
            if (Vehicle* vehicle = me->GetVehicleKit())
                vehicle->InstallAccessory(teleported ? NPC_DEEPHOLM_INTRO_AGGRA_2 : NPC_DEEPHOLM_INTRO_AGGRA_1, 0, true, TEMPSUMMON_DEAD_DESPAWN, 0);
            
            scheduler.Schedule(Milliseconds(500), [this, passenger](TaskContext /*task*/)
            {
                DoCast(passenger, SPELL_FORCECAST_AGGRA_PING, true);
            });
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            if (spell->Id != SPELL_AGGRA_PING)
                return;

            // Play music during first part
            if (!teleported)
                me->PlayDirectMusic(23541, caster->ToPlayer());

            me->SetSpeedRate(MOVE_WALK, 12.0f); // hack, otherwise it is too slow (sniff speeds: walk 2.5, run 16, fly 4.5)
            me->GetMotionMaster()->MoveSmoothPath(POINT_INTRO, teleported ? WyvernThirdPath : WyvernFirstPath, teleported ? WyvernThirdPathSize : WyvernFirstPathSize, true, true);
        }

        void MovementInform(uint32 type, uint32 pointId) override
        {
            if (type != EFFECT_MOTION_TYPE || pointId != POINT_INTRO)
                return;

            // Part one: Teleports player to Deepholm and then starts some strange path (better check newer sniffs). We don't need it anyway.
            // Part two: Ejects the player.
            me->CastSpell((Unit*)nullptr, !teleported ? SPELL_FORCECAST_TELEPORT : SPELL_EJECT_PASSENGER_2, true);
            //if (!teleported) me->GetMotionMaster()->MoveSmoothPath(0, WyvernSecondPath, WyvernSecondPathSize, true, true);

            me->DespawnOrUnsummon(Seconds(5));
        }

        void UpdateAI(uint32 diff) override
        {
            scheduler.Update(diff);
        }

    private:
        TaskScheduler scheduler;
        bool teleported;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_deepholm_intro_wyvernAI(creature);
    }
};

void AddSC_deepholm()
{
    new zone_deepholm();
    new npc_deepholm_intro_wyvern();
}
