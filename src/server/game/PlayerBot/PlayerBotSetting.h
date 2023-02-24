
#ifndef __PLAYERBOTSETTING_H__
#define __PLAYERBOTSETTING_H__

#include "Log.h"
#include "Common.h"
#include "SharedDefines.h"
#include "DatabaseEnv.h"
#include "Player.h"
#include "ItemTemplate.h"

struct InvLevelItems
{
    std::vector<uint32> items[MAX_LEVEL+1][INVTYPE_QUIVER];
};

class TC_GAME_API PlayerBotSetting
{
public:
	static void Initialize();
	static bool BindingPlayerHomePosition(Player* player);
	static bool CheckHunterPet(Player* player);
	static uint32 FindPlayerTalentType(Player* player);
	static uint32 RandomMountByLevel(uint32 level);
	static bool MatchEquipmentSlot(uint8 pos, const ItemTemplate* itemTemplate);
	static uint32 GetItemLevelByAI(const ItemTemplate* item);
	static bool IsBetterEquip(Player* player, const ItemTemplate* itemTemplate, int32 rndPropID);
	static void ClearUnknowMount(Player* player);
	static uint32 CheckMaxLevel(uint32 level);

    static std::vector<InvLevelItems*> InvLevelItemsBySpec;
    static std::vector<uint32> beastCreatureEntrys;
    static std::vector<uint32> exoticCreatureEntrys;

	PlayerBotSetting(Player* player);
	~PlayerBotSetting();

	bool EquipIsTidiness();
	bool IsFinish() { return m_Finish; }
	bool ResetPlayerToLevel(uint32 level, uint32 spec);
	uint32 SwitchPlayerSpec(uint32 spec);
	void UpdateReset();
	void LearnTalents();
	void LearnSpells();
	void CheckBotLearnSpell(uint32 spell);
	bool EquipItem(Item* pItem);
    void LearnRandomTalentSpell(uint32 level, uint32 spell1, uint32 spell2, uint32 spell3);
    void SetUpdateEquip(bool update) { m_UpdateEquip = update; }
private:
	void CheckInventroy();
	void UnEquipAll();
	void AddEquip();
	void EquipAll();

	void AddOnceEquip(uint32 item);
	uint32 GetRandomItemFromLoopLV(uint32 spec, InventoryType iType, uint32 startLV, uint32 filter = 0);

private:
	bool m_Finish;
	uint32 m_ResetStep;
	Player* m_Player;
    std::vector<Item*> m_NeedEquips;
    bool m_UpdateEquip;
};

#endif // __PLAYERBOTSETTING_H__
