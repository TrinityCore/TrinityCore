#include "ScriptMgr.h"
#include "Player.h"
#include "InstanceScript.h"
#include "Conversation.h"
#include "ObjectMgr.h"
#include "operation_mechagon.h"

/*DoorData const doorData[] =
{
    { , , DOOR_TYPE_ROOM },
    { , , DOOR_TYPE_ROOM },
    { , , DOOR_TYPE_ROOM },
};*/

struct instance_operation_mechagon : public InstanceScript
{
    instance_operation_mechagon(InstanceMap* map) : InstanceScript(map)
    {
        SetHeaders(DataHeader);
        SetBossNumber(EncounterCount);
    }

    void OnPlayerEnter(Player* player) override
    {        
        Conversation::CreateConversation(CONVERSATION_OPERATION_MECHAGON_INTRO, player, player->GetPosition(), { player->GetGUID() });
    };

    void OnCreatureCreate(Creature* cre) override
    {
        if (CreatureTemplate const* cInfo = sObjectMgr->GetCreatureTemplate(cre->GetEntry()))
        {
            if (cInfo->MechanicImmuneMask == 0)
            {
                if (instance->IsMythic())
                    if (cre->getFaction() == 16)
                        cre->SetBaseHealth(cre->GetMaxHealth() * 6.0f);

                if (instance->IsHeroic())
                    if (cre->getFaction() == 16)
                        cre->SetBaseHealth(cre->GetMaxHealth() * 5.0f);

                else
                    if (cre->getFaction() == 16)
                        cre->SetBaseHealth(cre->GetMaxHealth() * 4.0f);
            }
        }
    };
};

void AddSC_instance_operation_mechagon()
{
    RegisterInstanceScript(instance_operation_mechagon, 2097);
}