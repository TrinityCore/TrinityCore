/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "blackrock_spire.h"

enum Achievements
{
    ACHIEV_LEROY_JENKINS                         = 2188
};

struct instance_blackrock_spire : public ScriptedInstance
{
    instance_blackrock_spire(Map* pMap) : ScriptedInstance(pMap) {}

    uint32 uiLeeroyTimer;
    uint32 uiWhelpCount;
    uint32 uiLeroyData;

    bool bLeeeeeeeeroy;

    void Initialize()
    {
      uiLeeroyTimer = 15*IN_MILLISECONDS;
      uiWhelpCount = 0;
      bLeeeeeeeeroy = true;
      uiLeroyData = 0;
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case EVENT_LEEEROY:
                if (data == DONE)
                    DoCompleteAchievement(ACHIEV_LEROY_JENKINS);
                uiLeroyData = data;
                break;
            case WHELP_DEATH_COUNT:
                if (data == 1)
                {
                    SetData(EVENT_LEEEROY, IN_PROGRESS);
                    //DoSendNotifyToInstance("Leeeeeeeeeeeeeroy! Started");
                }
                uiWhelpCount = data;
                break;
        }
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case EVENT_LEEEROY:      return uiLeroyData;
            case WHELP_DEATH_COUNT:  return uiWhelpCount;
        }
        return 0;
    }

    void Update(uint32 diff)
    {
        if (GetData(EVENT_LEEEROY) != FAIL && GetData(EVENT_LEEEROY) == IN_PROGRESS)
        {
            if (uiLeeroyTimer <= diff)
            {
                SetData(EVENT_LEEEROY, FAIL);
                bLeeeeeeeeroy = false;
                //DoSendNotifyToInstance("Leeeeeeeeeeeeeroy! Failed");
            } else uiLeeroyTimer -= diff;
            if (uiWhelpCount >= 50 && bLeeeeeeeeroy)
            {
                SetData(EVENT_LEEEROY, DONE);
                //DoSendNotifyToInstance("Leeeeeeeeeeeeeroy! Success");
            }
        }
    }
};

InstanceData* GetInstanceData_instance_blackrock_spire(Map* pMap)
{
    return new instance_blackrock_spire(pMap);
}

void AddSC_instance_blackrock_spire()
{
  Script *newscript;
  newscript = new Script;
  newscript->Name = "instance_blackrock_spire";
  newscript->GetInstanceData = &GetInstanceData_instance_blackrock_spire;
  newscript->RegisterSelf();
}
