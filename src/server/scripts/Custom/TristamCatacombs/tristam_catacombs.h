#ifndef TRISTAM_CATACOMBS_H_
#define TRISTAM_CATACOMBS_H_

#include "CreatureAIImpl.h"

#define TCScriptName "instance_tristam_catacombs"
#define DataHeader "TC"

uint32 const EncounterCount = 5;

enum TCDataTypes
{
	// Encounter States/Boss GUIDs
	DATA_NETRISTRASZA_ENTRANCE,
	DATA_ANTONN_GRAVE,
	DATA_GHEZRIM,
	DATA_KING_LEORIC,
	DATA_ASMODAN,

	// Etc
	DATA_GHEZRIM_GUARDIAN,
	DATA_NETRISTRASZA,
};

enum TCCreaturesIds
{
    // Antonn Grave
    NPC_ANTONN_GRAVE                = 100076,
    NPC_ACOLYTE                     = 100077,

	// King Leoric
	NPC_KING_LEORIC                 = 0,

	// Ghezrim
	NPC_GHEZRIM                     = 0,
	NPC_GHEZRIM_GUARDIAN            = 0,

	// Asmodan
	NPC_ASMODAN                     = 0,

	// Mics
	NPC_INVISIBLE_STALKER           = 32780,
    NPC_TIME_RIFT                   = 28409,
	NPC_NETRISTRASZA                = 100075,
};

enum TCActions
{
	ACTION_START_DUNGEON            = -668001,
	ACTION_START_ANTONN             = -668002,
	ACTION_INTRO_ANTONN             = -668003,
};

enum TCInstanceEvents
{
    EVENT_ANTONN_GRAVE              = 1
};

enum TCInstanceTexts
{
    SAY_ANTONN_01                   = 1
};

enum TCSpells
{
    SPELL_RITUAL_CANALISATION       = 100094,
    SPELL_PORTAL_VISUAL             = 57687
};

template <class AI, class T>
inline AI* GetTristamCatacombsAI(T* obj)
{
	return GetInstanceAI<AI>(obj, TCScriptName);
}

#endif // TRISTAM_CATACOMBS_H_
