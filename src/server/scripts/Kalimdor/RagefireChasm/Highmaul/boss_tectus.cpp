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

uint8 GetEnergyGainFromHealth(float p_HealthPct)
{
    if (p_HealthPct >= 50.0f)
        return 1;
    else if (p_HealthPct >= 20.0f)
        return 2;
    else if (p_HealthPct >= 10.0f)
        return 3;
    else if (p_HealthPct >= 5.0f)
        return 4;
    else
        return 5;
}

void RespawnGuardians(Creature* source, InstanceScript* p_Instance)
{
    if (source == nullptr || p_Instance == nullptr)
        return;

    if (Creature* l_Rokka = ObjectAccessor::GetCreature(*source, p_Instance->GetGuidData(eHighmaulCreatures::Rokka)))
    {
        l_Rokka->Respawn();
        l_Rokka->GetMotionMaster()->MoveTargetedHome();
    }

    if (Creature* l_Lokk = ObjectAccessor::GetCreature(*source, p_Instance->GetGuidData(eHighmaulCreatures::Lokk)))
    {
        l_Lokk->Respawn();
        l_Lokk->GetMotionMaster()->MoveTargetedHome();
    }

    if (Creature* l_Oro = ObjectAccessor::GetCreature(*source, p_Instance->GetGuidData(eHighmaulCreatures::Oro)))
    {
        l_Oro->Respawn();
        l_Oro->GetMotionMaster()->MoveTargetedHome();
    }
}

void StartGuardians(Creature* source, Unit* target)
{
    if (source == nullptr || target == nullptr)
        return;

    if (Creature* l_Rokka = source->FindNearestCreature(eHighmaulCreatures::Rokka, 100.0f))
        l_Rokka->AI()->AttackStart(target);

    if (Creature* l_Lokk = source->FindNearestCreature(eHighmaulCreatures::Lokk, 100.0f))
        l_Lokk->AI()->AttackStart(target);

    if (Creature* l_Oro = source->FindNearestCreature(eHighmaulCreatures::Oro, 100.0f))
        l_Oro->AI()->AttackStart(target);
}

void AddSC_boss_tectus()
{
   
}
