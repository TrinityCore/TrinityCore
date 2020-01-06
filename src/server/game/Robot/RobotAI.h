#ifndef ROBOT_AI_H
#define ROBOT_AI_H

#ifndef MELEE_COMBAT_DISTANCE
# define MELEE_COMBAT_DISTANCE 1.5f
#endif

#ifndef MELEE_MAX_DISTANCE
# define MELEE_MAX_DISTANCE 2.0f
#endif

#include "Unit.h"
#include "Player.h"
#include "Item.h"
#include "Bag.h"
#include "Globals/ObjectAccessor.h"
#include "RobotManager.h"
#include "Spells/Spell.h"
#include "Chat/Chat.h"
#include "Strategies/Strategy_Group_Normal.h"
#include "Strategies/Strategy_Solo_Normal.h"
#include "Scripts/Script_Base.h"
#include "Scripts/Script_Warrior.h"
#include "Scripts/Script_Hunter.h"
#include "Scripts/Script_Shaman.h"
#include "Scripts/Script_Paladin.h"
#include "Scripts/Script_Warlock.h"
#include "Scripts/Script_Priest.h"
#include "Scripts/Script_Rogue.h"
#include "Scripts/Script_Mage.h"
#include "Scripts/Script_Druid.h"
#include "SpellInfo.h"
#include "SpellHistory.h"

class Strategy_Solo_Normal;
class Strategy_Group_Normal;

class RobotAI
{
public:
	RobotAI(Player* pmSourcePlayer);
	~RobotAI();
	void Update();
	Item* GetItemInInventory(uint32 pmEntry);
	void InitializeCharacter();
	void SetStrategy(std::string pmStrategyName, bool pmEnable);
	void ResetStrategy();
    void Prepare();
    void Refresh();
    void RandomTeleport();
	void MoveMelee(Unit* pmTarget);
	void MoveCLose(Unit* pmTarget, float pmDistance);
	void DoAttack(Unit* pmTarget, bool pmMelee = true);
	void BaseMove(Unit* pmTarget, float pmDistance = ATTACK_DISTANCE, bool pmMelee = true, bool pmAttack = true);
	bool CastSpell(Unit* pmTarget, std::string pmSpellName, float pmDistance = 100, bool pmCheckAura = false, bool pmOnlyMyAura = false, bool pmClearShapeshift = false);
	bool HasAura(Unit* pmTarget, std::string pmSpellName, bool pmOnlyMyAura = false);
	bool UseItem(Item* pmItem, Unit* pmTarget);
    bool EquipNewItem(uint32 pmEntry);
    bool EquipNewItem(uint32 pmEntry, uint8 pmEquipSlot);
    bool EquipItem(std::string pmEquipName);
    bool UnequipItem(std::string pmEquipName);
    bool UnequipAll();
    bool EquipAll();    
	void HandlePacket(WorldPacket pmPacket);
	void HandleChatCommand(std::string pmCommand, Player* pmSender);	
	uint32 FindSpellID(std::string pmSpellName);
	bool SpellValid(uint32 pmSpellID);
	bool CancelAura(std::string pmSpellName);
	void CancelAura(uint32 pmSpellID);
	void ClearShapeshift();
	void WhisperTo(std::string pmContent, Language pmLanguage, Player* pmTarget);

public:
	time_t prevUpdate;
	Player * sourcePlayer;
	Player* masterPlayer;
	std::unordered_map<std::string, bool> strategiesMap;
	uint8 characterTalentTab;
	// 0 dps, 1 tank, 2 healer
	uint8 characterType;

	std::unordered_map<std::string, uint32> spellIDMap;
	std::unordered_map<std::string, uint8> spellLevelMap;
	std::unordered_map<uint64, bool> interestMap;


	Strategy_Solo_Normal* st_Solo_Normal;
	Strategy_Group_Normal* st_Group_Normal;

	Script_Base* s_base;
	//std::unordered_map<int, Script_Base*> scriptMap;
};
#endif
