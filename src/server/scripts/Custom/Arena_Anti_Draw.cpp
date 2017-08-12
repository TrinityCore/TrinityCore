#include <ScriptPCH.h>
#include "Pet.h"

const uint32 SPELL_DEMENTIA = 41406;

class AntiDrawSystem : public PlayerScript
{
public:
    AntiDrawSystem() : PlayerScript("AntiDrawSystem") {}

    void OnUpdateZone(Player* player, uint32 newZone, uint32 newArea)
    {
        Pet* pet = player->GetPet();

        // Remove Dementia on updating zone for player
        if (player->HasAura(SPELL_DEMENTIA))
            player->RemoveAura(SPELL_DEMENTIA);

        // Remove Dementia on upddating zone for pet
        if (pet)
        {
            if (pet->HasAura(SPELL_DEMENTIA))
            {
                pet->RemoveAura(SPELL_DEMENTIA);
            }
        }
    }

    void OnLogin(Player* player, bool /* OnLogin */)
    {
        Pet* pet = player->GetPet();

        // Remove Dementia on player login
        if (player->HasAura(SPELL_DEMENTIA))
            player->RemoveAura(SPELL_DEMENTIA);

        // Remove Dementia on Pet Login
        if (pet)
        {
            if (pet->HasAura(SPELL_DEMENTIA))
            {
                pet->RemoveAura(SPELL_DEMENTIA);
            }
        }
    }

};

void AddSC_Arena_AntiDraw()
{
    new AntiDrawSystem();
}