#ifndef DEF_TRANSMOGRIFICATION_H
#define DEF_TRANSMOGRIFICATION_H

#include <vector>
#include <unordered_map>
#include "Define.h"
#include "ObjectGuid.h"
#include "TransmogrificationDefines.h"
#include <limits>

class Item;
class Player;
class WorldSession;
class SpellInfo;
struct ItemTemplate;

class TC_GAME_API Transmogrification
{
private:
    Transmogrification() = default;
public:
    Transmogrification(Transmogrification const &) = delete;
    void operator=(Transmogrification const &x) = delete;

    static Transmogrification& instance();

    bool EnableSetInfo;
    uint32 SetNpcText;

    bool EnableSets;
    uint8 MaxSets;

    bool EnableTransmogInfo;
    uint32 TransmogNpcText;

    // Use IsAllowed() and IsNotAllowed()
    // these are thread unsafe, but assumed to be data so it should be safe
    std::set<uint32> Allowed;
    std::set<uint32> NotAllowed;

    float ScaledCostModifier;
    int32 CopperCost;

    bool AllowPoor;
    bool AllowCommon;
    bool AllowUncommon;
    bool AllowRare;
    bool AllowEpic;
    bool AllowLegendary;
    bool AllowArtifact;
    bool AllowHeirloom;

    bool AllowMixedArmorTypes;
    bool AllowMixedWeaponTypes;
    bool AllowMixedInventoryTypes;
    bool AllowFishingPoles;

    bool IgnoreReqRace;
    bool IgnoreReqClass;
    bool IgnoreReqSkill;
    bool IgnoreReqSpell;
    bool IgnoreReqLevel;
    bool IgnoreReqEvent;
    bool IgnoreReqStats;
    bool IgnorePlayerMissingProfiency;
    bool IgnoreReqFaction;
    int IgnoreReqBound;

    static const std::unordered_map<uint32, std::string> enchant_visual_to_name; // contains all enchant visuals (not enchants) that should be viewable in menus

    bool IsAllowed(uint32 entry);
    bool IsNotAllowed(uint32 entry);
    bool IsAllowedQuality(uint32 quality);
    bool IsBowOrGunOrCrossbow(ItemTemplate const* itemTemplate);
    bool IsMeleeWeapon(ItemTemplate const* itemTemplate);

    std::unordered_map<uint32, std::vector<SpellInfo const*>> enchant_to_spells; // contains all enchants. Some spell lists can be empty
    std::unordered_map<uint32, std::vector<uint32>> spell_to_enchants; // does not contain all enchants as all of them dont come from spells

    void LoadConfig(bool reload); // thread unsafe
    void LoadEnchants(); // thread unsafe

    std::string GetItemIcon(uint32 entry, uint32 width, uint32 height, int x, int y);
    std::string GetSlotIcon(uint8 slot, uint32 width, uint32 height, int x, int y);
    const char * GetSlotName(uint8 slot, WorldSession* session);
    std::string GetItemName(ItemTemplate const* itemTemplate, WorldSession* session);
    std::string GetItemName(Item const* itemTemplate, WorldSession* session);
    std::string GetItemLink(Item* item, WorldSession* session);
    std::string GetItemLink(uint32 entry, WorldSession* session);
    Item* GetEquippedItem(Player* player, uint8 slot);
    void UpdateItem(Player* player, Item* item);

    TransmogResult CannotTransmogrifyItemWithItem(Player* player, ItemTemplate const* destination, ItemTemplate const* source, bool ever);
    TransmogResult CannotTransmogrifyItemWithEnchant(Player* player, ItemTemplate const* destination, uint32 enchant, bool ever);
    TransmogResult CannotTransmogrifyItem(Player* player, ItemTemplate const* proto, bool ever);
    TransmogResult CannotEquip(Player* player, ItemTemplate const* proto);
    TransmogResult CannotEverEquip(Player* player, ItemTemplate const* proto);
    TransmogResult CannotTransmogrify(ItemTemplate const* proto);
    bool HasPendingTransmog(Player* player, uint8 slot, Item** retItem = nullptr, uint32* retPending = nullptr, uint32* retCurrent = nullptr);
    bool HasPendingEnchant(Player* player, uint8 slot, Item** retItem = nullptr, uint32* retPending = nullptr, uint32* retCurrent = nullptr);

    // Call these from core to add visuals to player's collection
    void AddToCollection(Player* player, Item* item);
    void AddToCollection(Player* player, const ItemTemplate* itemtemplate);
    void AddToCollectionEnchant(Player* player, uint32 enchant_id);

    uint32 AddItemVisualToCollection(Player* player, Item* item);
    uint32 AddItemVisualToCollection(Player* player, const ItemTemplate* itemtemplate);
    uint32 AddEnchantVisualToCollection(Player* player, uint32 enchant_id);
    bool CanAddToCollection(Player* player, Item* item);
    bool CanAddToCollection(Player* player, ItemTemplate const* itemTemplate);
    bool CanAddEnchantToCollection(Player* player, Item* item);
    uint32 Save(Player* player, AppearanceType transmogtype, uint32 visual);
    void SaveToDB(Player* player, AppearanceType transmogtype, uint32 visual);

    bool HasVisual(Player* player, AppearanceType transmogtype, uint32 visual);

    std::vector<ObjectGuid> GetItemList(const Player* player);
    std::vector<Item*> GetEquippedItems(Player* player);
    PendingTransmogs GetPendingTransmogs(Player* player);
    uint32 GetCurrentVisual(Item* item);
    uint32 GetCurrentVisualEnchant(Item* item);

    uint32 GetSpecialPrice(ItemTemplate const* proto);
    int32 CalculateTransmogCost(uint32 entry);
    int32 CalculateTransmogCost(PendingTransmogs& items);

    TransmogResult TrySetPendingTransmog(Player* player, uint32 slot, uint32 entry);
    TransmogResult TrySetPendingEnchant(Player* player, uint32 slot, uint32 entry);
    TransmogResult TransmogrifyPending(Player* player, int32 expectedCost = -1);
    void Transmogrify(Player* player, Item* transmogrified, AppearanceType type, uint32 entry);

    void RemoveAllTransmogrifications(Player* player);
    void RevertAllTransmogrifications(Player* player);
    bool RevertTransmogrification(Player* player, uint8 slot);
    bool RevertEnchant(Player* player, uint8 slot);
};

#endif
