#include "precompiled.h"
            case ACTION_T_SUMMON_GO:
            {
                GameObject* pObject = NULL;

                float x,y,z;
                m_creature->GetPosition(x,y,z);
                pObject = m_creature->SummonGameObject(param1, x, y, z, 0, 0, 0, 0, 0, param2);
                if (!pObject)
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log( "SD2: EventAI failed to spawn object %u. Spawn event %d is on creature %d", param1, EventId, m_creature->GetEntry());
                }
            }
            break;
