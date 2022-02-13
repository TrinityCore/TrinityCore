/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

/* ScriptData
SDName: Hinterlands
SD%Complete: 100
SDComment: Quest support:
SDCategory: The Hinterlands
EndScriptData */

/* ContentData
EndContentData */

#include "ScriptMgr.h"
#include "MotionMaster.h"
#include "Position.h"
#include "ScriptedCreature.h"

/*######
## npc_sharpbeak used by Entrys 43161 & 51125
######*/

enum Sharpbeak
{
    NPC_SHARPBEAK_CAMP            = 43161,
    NPC_SHARPBEAK_JINTHAALOR      = 51125,
    SPELL_EJECT_ALL_PASSENGERS    = 50630
};

Position const campPath[] =
{
    { -75.40077f, -4037.111f, 114.6418f },
    { -68.80193f, -4034.235f, 123.6844f },
    { -62.2031f, -4031.36f, 132.727f },
    { -48.5851f, -4008.04f, 156.977f },
    { -26.2691f, -3987.88f, 176.755f },
    { 11.5087f, -3960.86f, 203.561f },
    { 45.0087f, -3922.58f, 236.672f },
    { 75.4427f, -3856.91f, 255.672f },
    { 74.8351f, -3768.84f, 279.839f },
    { -53.0104f, -3582.62f, 287.755f },
    { -169.123f, -3582.08f, 282.866f },
    { -241.8403f, -3625.01f, 247.4203f }
};
size_t constexpr campPathSize = std::extent<decltype(campPath)>::value;

Position const jinthaalorPath[] =
{
    { -249.4681f, -3632.487f, 232.6947f },
    { -241.606f, -3627.713f, 236.61870f },
    { -235.6163f, -3624.076f, 239.6081f },
    { -226.8698f, -3623.929f, 244.8882f },
    { -193.6406f, -3618.776f, 244.8882f },
    { -149.7292f, -3613.349f, 244.8882f },
    { -103.8976f, -3623.828f, 238.0368f },
    { -41.33681f, -3710.568f, 232.4109f },
    { 6.201389f, -3739.243f, 214.2869f },
    { 37.44097f, -3773.431f, 189.4650f },
    { 44.21875f, -3884.991f, 177.7446f },
    { 39.81424f, -3934.679f, 168.1627f },
    { 32.17535f, -3983.781f, 166.1228f },
    { 21.34896f, -4005.293f, 162.9598f },
    { -5.734375f, -4028.695f, 149.0161f },
    { -23.23611f, -4040.689f, 140.1189f },
    { -35.45139f, -4047.543f, 133.2071f },
    { -59.21181f, -4051.257f, 128.0297f },
    { -76.90625f, -4040.207f, 126.0433f },
    { -77.51563f, -4022.026f, 123.2135f }
};
size_t constexpr jinthaalorPathSize = std::extent<decltype(jinthaalorPath)>::value;

class npc_sharpbeak : public CreatureScript
{
public:
    npc_sharpbeak() : CreatureScript("npc_sharpbeak") { }

    struct npc_sharpbeak_AI : public ScriptedAI
    {
        npc_sharpbeak_AI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            endPoint = 0;
        }

        void PassengerBoarded(Unit* /*who*/, int8 /*seatId*/, bool apply) override
        {
            if (!apply)
                return;

            switch (me->GetEntry())
            {
                case NPC_SHARPBEAK_CAMP:
                    me->GetMotionMaster()->MoveSmoothPath(uint32(campPathSize), campPath, campPathSize, false);
                    endPoint = campPathSize;
                    break;
                case NPC_SHARPBEAK_JINTHAALOR:
                    me->GetMotionMaster()->MoveSmoothPath(uint32(jinthaalorPathSize), jinthaalorPath, jinthaalorPathSize, false, true);
                    endPoint = jinthaalorPathSize;
                    break;
            }
        }

        void MovementInform(uint32 type, uint32 pointId) override
        {
            if (type == EFFECT_MOTION_TYPE && pointId == endPoint)
            {
                DoCast(SPELL_EJECT_ALL_PASSENGERS);
            }
        }

    private:
        size_t endPoint;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sharpbeak_AI(creature);
    }
};

void AddSC_hinterlands()
{
    new npc_sharpbeak();
}
