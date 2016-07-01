/*
Author : Callmephil
Patch : 3.3.5
Version : 2.5
Script Complete : 90 % missing Healing Check / Soul Saved Currency
@todo : see if we can reduce code
@todo2 : review the random formula
*/
#ifdef TrinityCore
#include "SpellHistory.h"
#else // WoWSource
#include "ScriptPCH.h"
#endif

#include "Config.h"
#include "World.h"
#include "Group.h"
#include "Player.h"

enum QuestID
{
	QUEST_HEAL_FOR_100K = 78891,
	QUEST_HEAL_FOR_200K = 78892,
	QUEST_HEAL_FOR_300K = 78893,
	QUEST_HEAL_FOR_400K = 78894,
	QUEST_HEAL_FOR_500K = 78895
};

enum Changethis
{
	SOUL_TOKEN_ID = 0, // Put your item id here

	SOUL_BOSS_KILL_AMOUNT = 3, // 100 % de chances
	SOUL_PLAYER_KILL_AMOUNT = 1,
	SOUL_CREATURE_KILL_AMOUNT = 1

};

enum Misc
{
	// Player Level Check
	MIN_LEVEL_REQ = 80,
	// Token Reward Default Setup || Can be change by using config
	TOKEN_LOSER = 1, // Default
	TOKEN_WINNER = 3, // Default
	ITEMORCURRENCY_REWARD_ID = 0, // Default

	GEAR_STAMINA_REQ = 1750
};

enum SPELL_DEBUFF
{
	// WOTLK
	DEBUFF_SATED = 57724,
	DEBUFF_EXHAUSTION = 57723,
};

bool positionIsValid(Position* source, Position* target) {

	if (std::abs(target->GetPositionX() - source->GetPositionX()) <= 40.f) //40 meters
		return true;
	return false;
}

bool IsInDungeonOrRaid(Player* player)
{
	if (sMapStore.LookupEntry(player->GetMapId())->Instanceable())
		return true; // boolean need to return to a value
	return false;
}

static const uint32 spell_debuff[2] = { DEBUFF_SATED, DEBUFF_EXHAUSTION };

void remove_debuff_and_cooldown(Player* player)
{
	for (uint32 aura_entry : spell_debuff)
		if (player->HasAura(aura_entry))
			player->RemoveAura(aura_entry);

#ifdef TrinityCore
	player->GetSpellHistory()->ResetAllCooldowns();
#else // WoWSource
	player->RemoveAllSpellCooldown();
#endif
}

bool SecuritySystem(Player* player, Player* victim)
{
#ifdef TrinityCore
	if (!player->IsGameMaster())
#else // WoWSource
	if (!player->isGameMaster())
#endif// in case of .gm on conditions does not applies (Testing Purpose)
	{
		if (player->GetMap()->IsBattleArena())
			return true;
		if (player->GetGUIDLow() == victim->GetGUIDLow())
			return true;
		if (victim->HasAura(46705)) // 3 min cooldown world - 1 min cooldown bg
			return true;

		if (victim->GetStat(STAT_STAMINA) < GEAR_STAMINA_REQ)
			/*{ Message disabled because unusefull
				std::ostringstream ss;
				ss << "|cFFFFFC00[Anti-Farm System]|r : |cFF00FFFF Vous êtes trop fort face à votre adversaire !|r \n";
				ChatHandler(player->GetSession()).SendSysMessage(ss.str().c_str());*/
				return true;
		//}
		if (player->GetSession()->GetRemoteAddress() == victim->GetSession()->GetRemoteAddress())
		{
			std::ostringstream ss;
			ss << "|cFFFFFC00[Anti-Farm System]|r : |cFF00FFFF The Multi-Housing is not eligible for awards.|r \n";
			ChatHandler(player->GetSession()).SendSysMessage(ss.str().c_str());
			ChatHandler(victim->GetSession()).SendSysMessage(ss.str().c_str());
			return true;
		}
	}
	return false;
};

void loot_system_creature(Player* player, Creature* creature)
{
	uint8 pverandom = urand(0, 3);
	// Check for level difference.
	if (creature->getLevel() < player->getLevel())
		return;

#ifdef TrinityCore
	if (creature->IsGuard() || creature->IsCritter())
#else // WoWSource
	if (creature->isGuard() || creature->GetCritterGUID())
#endif
		return;

	// Loot Trashes PvE
	if (!creature->isWorldBoss())
	{
		if (pverandom == 3)
			player->AddItem(SOUL_TOKEN_ID, SOUL_CREATURE_KILL_AMOUNT);
	}
	// Loot BOSS PvE
	if (creature->isWorldBoss() || (creature->isElite() && creature->getLevel() >= player->getLevel())) // For the big boss and the smallest too
	{
		player->AddItem(SOUL_TOKEN_ID, SOUL_BOSS_KILL_AMOUNT);
		player->CastSpell(creature, 40855);
	}
}

// Check if player is cheating
void loot_system_pvp(Player* player, Player* victim)
{
	Aura* aura = NULL;

	uint8 pvprandom = urand(0, 1);
	if (pvprandom == 1)
	{
		player->AddItem(SOUL_TOKEN_ID, SOUL_PLAYER_KILL_AMOUNT);
		victim->CastSpell(victim, 40855, true); // visual

		if (!victim->HasAura(46705))
			victim->CastSpell(victim, 46705, true); // 45 seconds

		aura = victim->GetAura(46705);
		if (aura)
		{
#ifdef TrinityCore
	if (victim->GetMap()->IsBattleground() || victim->IsFFAPvP() || victim->GetAreaId() == 1741)
#else // WoWSource
	if (victim->GetMap()->IsBattleground() || victim->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP) || victim->GetAreaId() == 1741)
#endif
		aura->SetDuration(60 * IN_MILLISECONDS, true); // 60 sec in battleground/FFA @todo move spell to spellscript 
	else
		aura->SetDuration(180 * IN_MILLISECONDS, true); // 3 minutes in world (skip mass farm)
		}
	}
}

// regroupe la meme fonctions pour plusieurs utilisations 
void PlayerIsInGroup(Player* player, Unit* victim)
{
	Group * group = player->GetGroup();

	Group::MemberSlotList const &members = group->GetMemberSlots();
	for (Group::MemberSlotList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
	{
		Group::MemberSlot const &slot = *itr;
		Player* player = ObjectAccessor::FindPlayer((*itr).guid);
		// pvp
		if ((victim->ToPlayer() && (player && player->GetSession()) && positionIsValid(victim->ToPlayer(), player)))
			loot_system_pvp(player, victim->ToPlayer()); // Disabled Security Check, moved to Void OnPvPKill
		// pve
		if ((victim->ToCreature() && (player && player->GetSession()) && positionIsValid(victim->ToCreature(), player)))
			loot_system_creature(player, victim->ToCreature()); // Active Security 
		// PvE Legacy raids
		if ((victim->ToCreature() && (player && player->GetSession()) && positionIsValid(victim->ToCreature(), player)) &&
			((IsInDungeonOrRaid(player) && (victim->ToCreature()->isWorldBoss() || victim->ToCreature()->IsDungeonBoss()))))
			remove_debuff_and_cooldown(player); // for debuffs & cooldowns only  

	}
}

class Cooldown_Reset : public PlayerScript
{
public:
	Cooldown_Reset() : PlayerScript("Cooldown_Reset") {}

	void OnCreatureKill(Player* player, Creature* boss)
	{
		if ((IsInDungeonOrRaid(player)) && (boss->isWorldBoss() || boss->IsDungeonBoss()))
		{
			if (player->GetGroup()) // Check Again If he is in group
				PlayerIsInGroup(player, boss);
			else // else for player that are solo (if removed server crash)
				remove_debuff_and_cooldown(player);
		}
	}
};

class Soul_System : public PlayerScript
{
public:
	Soul_System() : PlayerScript("Soul_System") {}

	// Remove the debff Aura if the player get killed in world and just join battleground.
	void OnUpdateZone(Player* player, uint32 newZone, uint32 newArea)
	{
		if (player->GetAura(SPELL_PREPARATION) && (player->GetMap()->IsBattleground() && player->GetAura(46705)))
			player->RemoveAura(46705);
	}


	void OnCreatureKill(Player* player, Creature* boss)
	{
		if (player->GetGroup()) // Check Again If he is in group
			PlayerIsInGroup(player, boss);
		else // else for player that are solo (if removed server crash)
			loot_system_creature(player, boss);
	}

	void OnPVPKill(Player * player, Player * victim)
	{
		if (SecuritySystem(player, victim)) // Check Again If all conditions are ok.
			return;

		if (player->GetGroup()) // // Check Again If he is in group
			PlayerIsInGroup(player, victim);
		else // else for player that are solo (if removed server crash)
			loot_system_pvp(player, victim);
	}

};

void AddSC_Soul_System()
{
	new Cooldown_Reset();
	new Soul_System();
}

/* Special Quest/Action for Healer */
/*	// Area id is checked in SpellEffects.cpp L2323 so it's less expensive
void OnPVPHeal(Player* healer, Unit* healed, uint32 healAmount)
{

healer->GetSession()->SendNotification("Okay", LANG_UNIVERSAL);

if (!healed || !healer)
return;

// If it's for example a (bugged) area-heal that also heals enemies we should not count this for the quest
if (!healed->IsFriendlyTo(healer))
return;

#ifdef TrinityCore
if (!healed->IsPet() || healed->GetTypeId() == TYPEID_PLAYER)
#else// WoW Source
if (!healed->isPet() || healed->GetTypeId() == TYPEID_PLAYER)
#endif
if (healer->GetQuestStatus(QUEST_HEAL_FOR_100K) == QUEST_STATUS_INCOMPLETE || healer->GetQuestStatus(QUEST_HEAL_FOR_200K) == QUEST_STATUS_INCOMPLETE ||
healer->GetQuestStatus(QUEST_HEAL_FOR_300K) == QUEST_STATUS_INCOMPLETE || healer->GetQuestStatus(QUEST_HEAL_FOR_400K) == QUEST_STATUS_INCOMPLETE ||
healer->GetQuestStatus(QUEST_HEAL_FOR_500K) == QUEST_STATUS_INCOMPLETE)
{
//healer->KilledMonsterCredit(NPC_HEAL_QUEST_CREDIT, 0, healAmount / 1000);
}

/*healAmount = NULL;
if (healAmount >= 3000)
{
healer->AddItem(4312, 1);
}

}*/