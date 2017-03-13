#include "ScriptMgr.h"
#include "Player.h"

enum HonorRanks
{
	/* Alliance */
	PRIVATE = 1,
	CORPORAL = 2,
	SERGEANT = 3,
	MASTER_SERGEANT = 4,
	SERGEANT_MAJOR = 5,
	KNIGHT = 6,
	KNIGHT_LIEUTENANT = 7,
	KNIGHT_CAPTAIN = 8,
	KNIGHT_CHAMPION = 9,
	LIEUTENANT_COMMANDER = 10,
	COMMANDER = 11,
	MARSHAL = 12,
	FIELD_MARSHAL = 13,
	GRAND_MARSHAL = 14,
	OF_THE_ALLIANCE = 126,
	/* Horde */
	SCOUT = 15,
	GRUNT = 16,
	SERGEANT_H = 17,
	SENIOR_SERGEANT = 18,
	FIRST_SERGEANT = 19,
	STONE_GUARD = 20,
	BLOOD_GUARD = 21,
	LEGIONNAIRE = 22,
	CENTURION = 23,
	CHAMPION = 24,
	LIEUTENANT_GENERAL = 25,
	GENERAL = 26,
	WARLORD = 27,
	HIGH_WARLORD = 28,
	OF_THE_HORDE = 127
};

enum HonorKills
{
	KILLS_1 = 25,
	KILLS_2 = 125,
	KILLS_3 = 250,
	KILLS_4 = 500,
	KILLS_5 = 1000,
	KILLS_6 = 1250,
	KILLS_7 = 1500,
	KILLS_8 = 2000,
	KILLS_9 = 2500,
	KILLS_10 = 3750,
	KILLS_11 = 6250,
	KILLS_12 = 10000,
	KILLS_13 = 11250,
	KILLS_14 = 12500,
	KILLS_15 = 25000
};


class player_vanilla_ranks : public PlayerScript
{
public:
	player_vanilla_ranks()
		: PlayerScript("player_vanilla_ranks")
	{
	}

	/* Pops when a player gets an Honourable Kill */
	void OnPVPKill(Player * killer, Player * killed)
	{
		// Error out of that shit yo
		if (killer == NULL)
			return;

		/* Get total honor kills and compare to enums - Unlock Achieve and Title*/
		switch (killer->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS))
		{
		case KILLS_1:
			if (killer->GetTeam() == ALLIANCE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(PRIVATE));
			else if (killer->GetTeam() == HORDE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(SCOUT));
			break;

		case KILLS_2:
			if (killer->GetTeam() == ALLIANCE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(CORPORAL));
			else if (killer->GetTeam() == HORDE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(GRUNT));
			break;

		case KILLS_3:
			if (killer->GetTeam() == ALLIANCE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(SERGEANT));
			else if (killer->GetTeam() == HORDE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(SERGEANT_H));
			break;

		case KILLS_4:
			if (killer->GetTeam() == ALLIANCE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(MASTER_SERGEANT));
			else if (killer->GetTeam() == HORDE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(SENIOR_SERGEANT));
			break;

		case KILLS_5:
			if (killer->GetTeam() == ALLIANCE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(SERGEANT_MAJOR));
			else if (killer->GetTeam() == HORDE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(FIRST_SERGEANT));
			break;

		case KILLS_6:
			if (killer->GetTeam() == ALLIANCE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(KNIGHT));
			else if (killer->GetTeam() == HORDE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(STONE_GUARD));
			break;

		case KILLS_7:
			if (killer->GetTeam() == ALLIANCE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(KNIGHT_LIEUTENANT));
			else if (killer->GetTeam() == HORDE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(BLOOD_GUARD));
			break;

		case KILLS_8:
			if (killer->GetTeam() == ALLIANCE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(KNIGHT_CAPTAIN));
			else if (killer->GetTeam() == HORDE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(LEGIONNAIRE));
			break;

		case KILLS_9:
			if (killer->GetTeam() == ALLIANCE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(KNIGHT_CHAMPION));
			else if (killer->GetTeam() == HORDE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(CENTURION));
			break;

		case KILLS_10:
			if (killer->GetTeam() == ALLIANCE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(LIEUTENANT_COMMANDER));
			else if (killer->GetTeam() == HORDE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(CHAMPION));
			break;

		case KILLS_11:
			if (killer->GetTeam() == ALLIANCE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(COMMANDER));
			else if (killer->GetTeam() == HORDE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(LIEUTENANT_GENERAL));
			break;

		case KILLS_12:
			if (killer->GetTeam() == ALLIANCE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(MARSHAL));
			else if (killer->GetTeam() == HORDE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(GENERAL));
			break;

		case KILLS_13:
			if (killer->GetTeam() == ALLIANCE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(FIELD_MARSHAL));
			else if (killer->GetTeam() == HORDE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(WARLORD));
			break;

		case KILLS_14:
			if (killer->GetTeam() == ALLIANCE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(GRAND_MARSHAL));
			else if (killer->GetTeam() == HORDE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(HIGH_WARLORD));
			break;

		case KILLS_15:
			if (killer->GetTeam() == ALLIANCE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(OF_THE_ALLIANCE));
			else if (killer->GetTeam() == HORDE)
				killer->SetTitle(sCharTitlesStore.LookupEntry(OF_THE_HORDE));
			break;
		}
	}
};

void AddSC_player_vanilla_ranks()
{
	new player_vanilla_ranks;
}