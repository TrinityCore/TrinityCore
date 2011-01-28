/* Copyright (C) 2008 - 2010 TrinityCore <http://www.trinitycore.org>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ScriptPCH.h"
#include "blackrock_spire.h"

enum Achievements
{
    ACHIEV_LEROY_JENKINS                         = 2188
};

class instance_blackrock_spire : public InstanceMapScript
{
public:
	instance_blackrock_spire() : InstanceMapScript("instance_blackrock_spire", 229) { }

	InstanceScript* GetInstanceScript(InstanceMap * pMap) const
	{
		return new instance_blackrock_spire_InstanceMapScript(pMap);
	}

struct instance_blackrock_spire_InstanceMapScript : public InstanceScript
{
    instance_blackrock_spire_InstanceMapScript(Map* pMap) : InstanceScript(pMap)
	{
		Initialize();
	};
    
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
                DoSendNotifyToInstance("Leeeeeeeeeeeeeroy! achievement failed");
            } else uiLeeroyTimer -= diff;
            if (uiWhelpCount >= 50 && bLeeeeeeeeroy)
            {
                SetData(EVENT_LEEEROY, DONE);
                DoSendNotifyToInstance("Leeeeeeeeeeeeeroy! achievement completed");
            }
        }
    }
};
};

void AddSC_instance_blackrock_spire()
{
	new instance_blackrock_spire();
}