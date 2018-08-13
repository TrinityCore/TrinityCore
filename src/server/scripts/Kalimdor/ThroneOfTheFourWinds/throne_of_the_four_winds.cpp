/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "GameObject.h"
#include "PhasingHandler.h"
#include "ScriptMgr.h"
#include "throne_of_the_four_winds.h"

enum SlipstreamEnums
{
    // Land Positions
    DIR_WEST_TO_SOUTH,
    DIR_SOUTH_TO_WEST,
    DIR_NORTH_TO_WEST,
    DIR_WEST_TO_NORTH,
    DIR_EAST_TO_NORTH,
    DIR_NORTH_TO_EAST,
    DIR_SOUTH_TO_EAST,
    DIR_EAST_TO_SOUTH,
    DIR_ERROR,

    // Spells
    SPELL_SLIPSTREAM_BUFF = 87740,
    SPELL_SLIPSTREAM_PLAYER_VISUAL = 85063,
};

Position const SlipstreamPositions[8] =
{
    {-245.141129f, 861.474060f, 197.386398f, 0},
    {-92.116440f, 1010.796448f, 197.475754f, 0},
    {-5.322055f, 1010.573608f, 197.520096f, 0},
    {144.480469f, 857.187927f, 197.594208f, 0},
    {144.221481f, 770.720154f, 197.629150f, 0},
    {-9.268366f, 620.736328f, 197.567032f, 0},
    {-96.089645f, 621.198730f, 197.499115f, 0},
    {-245.653870f, 774.446472f, 197.507156f, 0},
};

class npc_slipstream_raid : public CreatureScript
{
public:
    npc_slipstream_raid() : CreatureScript("npc_slipstream_raid") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_slipstream_raidAI (creature);
    }

    struct npc_slipstream_raidAI : public ScriptedAI
    {
        npc_slipstream_raidAI(Creature* creature) : ScriptedAI(creature), SlipstreamPosition(8), isUltimate(false), isActive(true), linkedSlipstreamObject(nullptr), linkedBoss(nullptr)
        {
            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NOT_SELECTABLE);

            for (uint8 i = 0; i <= 7; i++)
            {
                if (me->GetDistance2d(SlipstreamPositions[i].GetPositionX(), SlipstreamPositions[i].GetPositionY()) < 10)
                {
                    SlipstreamPosition = i;
                    break;
                }
            }

            if (SlipstreamPosition >= DIR_ERROR)
                return;

            SlipstreamPosition += (SlipstreamPosition == DIR_WEST_TO_SOUTH || SlipstreamPosition == DIR_NORTH_TO_WEST ||
            SlipstreamPosition == DIR_EAST_TO_NORTH || SlipstreamPosition == DIR_SOUTH_TO_EAST ) ? 1 : -1;

            // Assign linked Boss and Slipstream to disabled slipstreams if the bosses casts Ultimate
        }

        uint8 SlipstreamPosition;
        bool isUltimate;
        bool isActive;

        GameObject* linkedSlipstreamObject;
        Unit* linkedBoss;

        void Reset() override
        {
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (SlipstreamPosition >= DIR_ERROR || (who->GetTypeId() != TYPEID_PLAYER && !who->IsPet()) || !isActive)
                return;

            if(who->GetExactDist(me) <= 5.3f)
            {
                me->AddAura(SPELL_SLIPSTREAM_BUFF, who);
                me->AddAura(SPELL_SLIPSTREAM_PLAYER_VISUAL, who);
                // if we use the motion master only to relocate the player
                // it will cause bugs
                if (who->GetOrientation() != SlipstreamPositions[SlipstreamPosition].GetOrientation())
                    who->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TURNING);

                if (who->GetTypeId() == TYPEID_PLAYER)
                    me->GetMap()->PlayerRelocation(who->ToPlayer(), SlipstreamPositions[SlipstreamPosition].GetPositionX(), SlipstreamPositions[SlipstreamPosition].GetPositionY(), SlipstreamPositions[SlipstreamPosition].GetPositionZ(), SlipstreamPositions[SlipstreamPosition].GetOrientation());
                else
                    me->GetMap()->CreatureRelocation(who->ToCreature(), SlipstreamPositions[SlipstreamPosition].GetPositionX(), SlipstreamPositions[SlipstreamPosition].GetPositionY(), SlipstreamPositions[SlipstreamPosition].GetPositionZ(), SlipstreamPositions[SlipstreamPosition].GetOrientation());

                who->GetMotionMaster()->MoveJump(SlipstreamPositions[SlipstreamPosition].GetPositionX(), SlipstreamPositions[SlipstreamPosition].GetPositionY(), 198.458481f, SlipstreamPositions[SlipstreamPosition].GetOrientation(), 1.0f, 6.0f);
            }
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            // The Slipstreams are Deactivated before each Ultimate ability

            if (linkedSlipstreamObject && linkedBoss)
            {


            }else if (isUltimate)
                isUltimate = false;

            if (!isUltimate != isActive)
            {
                if (isActive)
                { // Activate Slipstream

                    if (linkedSlipstreamObject)
                        PhasingHandler::ResetPhaseShift(linkedSlipstreamObject);

                }else
                { // Deactivate Slipstream

                    if (linkedSlipstreamObject)
                        PhasingHandler::AddPhase(linkedSlipstreamObject, 50);
                }

                isActive = !isActive;
            }
        }
    };
};

class npc_wind_bridge : public CreatureScript
{
public:
    npc_wind_bridge() : CreatureScript("npc_wind_bridge") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_wind_bridgeAI (creature);
    }

    struct npc_wind_bridgeAI : public ScriptedAI
    {
        npc_wind_bridgeAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NOT_SELECTABLE);
        }

        InstanceScript* instance;

        void Reset() override
        {
        }

        void MoveInLineOfSight(Unit* who) override
        {
            ScriptedAI::MoveInLineOfSight(who);
            if (instance)
                if (instance->GetData(DATA_WEATHER_EVENT) == IN_PROGRESS)
                    return;

            if (who->GetTypeId() != TYPEID_PLAYER && !who->IsPet())
                return;

            if (who->IsWithinDistInMap(me, 10.0f) && !who->HasAura(SPELL_SLIPSTREAM_BUFF))
            {
                switch (me->GetEntry())
                {
                    case 470660: me->AddAura(SPELL_SLIPSTREAM_BUFF, who); me->AddAura(SPELL_SLIPSTREAM_PLAYER_VISUAL, who); who->GetMotionMaster()->MoveJump(-82.05f, 1019.41f, 199.49f, 0.0f, 75.0f, 25.0f); break;
                    case 470661: me->AddAura(SPELL_SLIPSTREAM_BUFF, who); me->AddAura(SPELL_SLIPSTREAM_PLAYER_VISUAL, who); who->GetMotionMaster()->MoveJump(-263.82f, 840.92f, 199.49f, 0.0f, 75.0f, 25.0f); break;
                    case 470662: me->AddAura(SPELL_SLIPSTREAM_BUFF, who); me->AddAura(SPELL_SLIPSTREAM_PLAYER_VISUAL, who); who->GetMotionMaster()->MoveJump(-81.59f, 607.18f, 199.49f, 0.0f, 75.0f, 25.0f); break;
                    case 470663: me->AddAura(SPELL_SLIPSTREAM_BUFF, who); me->AddAura(SPELL_SLIPSTREAM_PLAYER_VISUAL, who); who->GetMotionMaster()->MoveJump(-261.84f, 790.64f, 199.49f, 0.0f, 75.0f, 25.0f); break;
                    case 470664: me->AddAura(SPELL_SLIPSTREAM_BUFF, who); me->AddAura(SPELL_SLIPSTREAM_PLAYER_VISUAL, who); who->GetMotionMaster()->MoveJump(158.55f, 783.50f, 199.49f, 0.0f, 75.0f, 25.0f); break;
                    case 470665: me->AddAura(SPELL_SLIPSTREAM_BUFF, who); me->AddAura(SPELL_SLIPSTREAM_PLAYER_VISUAL, who); who->GetMotionMaster()->MoveJump(-20.90f, 606.96f, 199.49f, 0.0f, 75.0f, 25.0f); break;
                    case 470666: me->AddAura(SPELL_SLIPSTREAM_BUFF, who); me->AddAura(SPELL_SLIPSTREAM_PLAYER_VISUAL, who); who->GetMotionMaster()->MoveJump(-16.75f, 1022.54f, 199.49f, 0.0f, 75.0f, 25.0f); break;
                    case 470667: me->AddAura(SPELL_SLIPSTREAM_BUFF, who); me->AddAura(SPELL_SLIPSTREAM_PLAYER_VISUAL, who); who->GetMotionMaster()->MoveJump(157.76f, 844.96f, 199.49f, 0.0f, 75.0f, 25.0f); break;
                }
            }
        }
    };
};

class npc_slipstream_alakir : public CreatureScript
{
public:
    npc_slipstream_alakir() : CreatureScript("npc_slipstream_alakir") { }

    bool OnGossipHello(Player* player, Creature* /*creature*/) override
    {
        player->TeleportTo(754, -111.186859f, 815.128662f, 221.018799f, 0.02332f);
        return true;
    }
};

void AddSC_throne_of_the_four_winds()
{
    new npc_slipstream_raid();
    new npc_wind_bridge();
    new npc_slipstream_alakir();
}
