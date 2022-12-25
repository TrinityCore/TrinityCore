/*
 * Copyright 2023 AzgathCore
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

# include "highmaul.h"

Position const g_MaggotSpawnPos[eHighmaulDatas::MaxMaggotToKill] =
{
    { 3827.051f, 7690.205f, 23.67708f, 0.000f },
    { 3751.507f, 7722.538f, 23.65485f, 4.332f },
    { 3704.671f, 7700.851f, 23.60431f, 3.872f },
    { 3687.367f, 7626.960f, 23.64627f, 1.488f },
    { 3743.118f, 7607.410f, 23.86531f, 5.192f },
    { 3799.805f, 7675.845f, 23.04378f, 3.110f }
};

Position ComputeLocationSelection(Creature* source, float searchRange, float minRadius, float radius)
{
    using Cluster = std::set<Player*>;
    std::list<Player*> targets;

    source->GetPlayerListInGrid(targets, searchRange);

    if (!targets.empty())
    {
        targets.remove_if([source, minRadius](Player* player) -> bool
        {
            if (player == nullptr)
                return true;

            if (player->GetDistance(source) < minRadius)
                return true;

            return false;
        });
    }

    std::map<uint32, Cluster> clusterMap;

    for (Player* player : targets)
    {
        Cluster l_Neighboor;
        for (Player* playerSecond : targets)
        {
            float dist = player->GetDistance(playerSecond);
            if (dist <= radius)
                l_Neighboor.insert(playerSecond);
        }

        clusterMap[player->GetGUID().GetCounter()] = Cluster();
        clusterMap[player->GetGUID().GetCounter()].insert(player);

        for (Player* playerSecond : l_Neighboor)
            clusterMap[player->GetGUID().GetCounter()].insert(playerSecond);
    }

    size_t size = 0;
    for (auto cluster : clusterMap)
    {
        if (cluster.second.size() > size)
            size = cluster.second.size();
    }

    Position pos;
    for (auto cluster : clusterMap)
    {
        if (size && cluster.second.size() == size)
        {
            float l_X = 0.0f;
            float l_Y = 0.0f;

            for (Player* player : cluster.second)
            {
                l_X += player->GetPositionX();
                l_Y += player->GetPositionY();
            }

            l_X /= (uint32)size;
            l_Y /= (uint32)size;

            pos.Relocate(l_X, l_Y, source->GetPositionZ());
            break;
        }
    }

    return pos;
}

Position GetCleaveLocation(Creature* source)
{
    return ComputeLocationSelection(source, 5.0f, 0.0f, 5.0f);
}

Position GetBoundingCleaveLocation(Creature* source)
{
    return ComputeLocationSelection(source, 500.0f, 5.1f, 10.0f);
}

void AddSC_boss_the_butcher()
{
   
}
