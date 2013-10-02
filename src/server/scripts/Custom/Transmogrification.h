#ifndef DEF_TRANSMOGRIFICATION_H
#define DEF_TRANSMOGRIFICATION_H

#define PRESETS // comment this line to disable preset feature totally

#include "ScriptPCH.h"
#include "Language.h"
#include "Config.h"

#define MAX_OPTIONS 25 // do not alter

enum TransmogTrinityStrings // Language.h might have same entries, appears when executing SQL, change if needed
{
    LANG_ERR_TRANSMOG_OK = 11100, // change this
    LANG_ERR_TRANSMOG_INVALID_SLOT,
    LANG_ERR_TRANSMOG_INVALID_SRC_ENTRY,
    LANG_ERR_TRANSMOG_MISSING_SRC_ITEM,
    LANG_ERR_TRANSMOG_MISSING_DEST_ITEM,
    LANG_ERR_TRANSMOG_INVALID_ITEMS,
    LANG_ERR_TRANSMOG_NOT_ENOUGH_MONEY,
    LANG_ERR_TRANSMOG_NOT_ENOUGH_TOKENS,

    LANG_ERR_UNTRANSMOG_OK,
    LANG_ERR_UNTRANSMOG_NO_TRANSMOGS,

#ifdef PRESETS
    LANG_PRESET_ERR_INVALID_NAME,
#endif
};

class Transmogrification
{
public:
    typedef UNORDERED_MAP<uint64, uint64> transmogData;
    typedef UNORDERED_MAP<uint64, transmogData> transmogMap;
    transmogMap entryMap; // entryMap[pGUID][iGUID] = entry
    transmogData dataMap; // dataMap[iGUID] = pGUID

#ifdef PRESETS
    typedef std::map<uint8, uint32> slotMap;
    typedef std::map<uint8, slotMap> presetData;
    typedef UNORDERED_MAP<uint64, presetData> presetDataMap;
    presetDataMap presetById; // presetById[pGUID][presetID][slot] = entry
    typedef std::map<uint8, std::string> presetIdMap;
    typedef UNORDERED_MAP<uint64, presetIdMap> presetNameMap;
    presetNameMap presetByName; // presetByName[pGUID][presetID] = presetName

    void PresetTransmog(Player* player, Item* itemTransmogrified, uint32 fakeEntry, uint8 slot);

    bool EnableSets;
    uint8 MaxSets;
    float SetCostModifier;
    int32 SetCopperCost;

    bool GetEnableSets() const;
    uint8 GetMaxSets() const;
    float GetSetCostModifier() const;
    int32 GetSetCopperCost() const;

    void LoadPlayerSets(uint64 pGUID);
    void UnloadPlayerSets(uint64 pGUID);
#endif

    std::string GetItemIcon(uint32 entry, uint32 width, uint32 height, int x, int y);
    std::string GetSlotIcon(uint8 slot, uint32 width, uint32 height, int x, int y);
    const char * GetSlotName(uint8 slot, WorldSession* session) const;
    std::string GetItemLink(Item* item, WorldSession* session);
    std::string GetItemLink(uint32 entry, WorldSession* session);
    uint32 GetFakeEntry(uint64 itemGUID) const;
    void DeleteFakeFromDB(uint64 itemGUID, SQLTransaction* trans = NULL);
    void DeleteFakeEntry(Player* player, uint8 slot, Item* itemTransmogrified, SQLTransaction* trans = NULL);
    void SetFakeEntry(Player* player, uint32 newEntry, uint8 slot, Item* itemTransmogrified);

    TransmogTrinityStrings Transmogrify(Player* player, uint64 itemGUID, uint8 slot, /*uint32 newEntry, */bool no_cost = false);
    bool CanTransmogrifyItemWithItem(Player* player, ItemTemplate const* destination, ItemTemplate const* source);
    bool SuitableForTransmogrification(Player* player, ItemTemplate const* proto);
    // bool CanBeTransmogrified(Item const* item);
    // bool CanTransmogrify(Item const* item);
    uint32 GetSpecialPrice(ItemTemplate const* proto) const;
    bool IsRangedWeapon(uint32 Class, uint32 SubClass) const;

    // config values
    bool EnableTransmogInfo;
    uint32 TransmogNpcText;
    bool EnableSetInfo;
    uint32 SetNpcText;

    std::set<uint32> Allowed;
    std::set<uint32> NotAllowed;

    float ScaledCostModifier;
    int32 CopperCost;

    bool RequireToken;
    uint32 TokenEntry;
    uint32 TokenAmount;

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

    // Config
    bool GetEnableTransmogInfo() const;
    uint32 GetTransmogNpcText() const;
    bool GetEnableSetInfo() const;
    uint32 GetSetNpcText() const;

    bool IsAllowed(uint32 entry) const;
    bool IsNotAllowed(uint32 entry) const;

    float GetScaledCostModifier() const;
    int32 GetCopperCost() const;

    bool GetRequireToken() const;
    uint32 GetTokenEntry() const;
    uint32 GetTokenAmount() const;

    bool IsAllowedQuality(uint32 quality) const;
    bool GetAllowMixedArmorTypes() const;
    bool GetAllowMixedWeaponTypes() const;

    void LoadConfig(bool reload);
};
#define sTransmogrification ACE_Singleton<Transmogrification, ACE_Null_Mutex>::instance()

#endif
