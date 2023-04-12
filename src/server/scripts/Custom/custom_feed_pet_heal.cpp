//Credits to dane from TrinityCore forum.

#include "ScriptMgr.h"
#include "Spell.h"
#include "Pet.h"
#include "Config.h"

#define FEED_PET 6991

class custom_feed_pet_heal : public PlayerScript
{
public:
    custom_feed_pet_heal() : PlayerScript("custom_feed_pet_heal") { }

    void OnSpellCast(Player* player, Spell* spell, bool /*skipCheck*/)
    {
        if (sConfigMgr->GetBoolDefault("Feed.Pet.Heal", true))
        {
            if (spell->GetSpellInfo()->Id != FEED_PET)
                return;

            Pet* pet = player->GetPet();
            if (pet) {
                uint32 health = pet->GetHealth();
                uint32 max_health = pet->GetMaxHealth();

                if (!(health && max_health))
                    return;

                uint32 new_health = std::min(max_health, health + (uint32)floor(max_health * 0.5));
                pet->SetHealth(new_health);//This is to set pet's heal to your own define
            }
        }
    }
};

void AddSC_custom_feed_pet_heal()
{
    new custom_feed_pet_heal();
}
