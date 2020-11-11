#ifndef TRISTAM_CATACOMBS_H_
#define TRISTAM_CATACOMBS_H_

#include "CreatureAIImpl.h"

#define TCScriptName "instance_tristam_catacombs"
#define DataHeader "TC"

uint32 const EncounterCount = 5;

enum TCDataTypes
{
	// Encounter States/Boss GUIDs
	DATA_NETRISTRASZA,
	DATA_ANTONN_GRAVE,
	DATA_GHEZRIM,
	DATA_LEORIC,
	DATA_ASMODAN,

	// Etc
	DATA_GHEZRIM_GUARDIAN,
    DATA_TIME_RIFT,
    DATA_KORMAC,

    // Doors
    DATA_NETRISTRASZA_ENTRANCE,
    DATA_ANTONN_GRAVE_ENTRANCE,
    DATA_ANTONN_GRAVE_EXIT,
};

enum TCCreaturesIds
{
    // Antonn Grave
    NPC_ANTONN_GRAVE                = 100076,
    NPC_ACOLYTE                     = 100077,

	// Leoric
	NPC_LEORIC                      = 100078,

	// Ghezrim
	NPC_GHEZRIM                     = 0,
	NPC_GHEZRIM_GUARDIAN            = 0,

	// Asmodan
	NPC_ASMODAN                     = 0,

	// Mics
	NPC_INVISIBLE_STALKER           = 32780,
    NPC_TIME_RIFT                   = 28409,
	NPC_NETRISTRASZA                = 100075,
    NPC_SKELETON_MINION             = 100079,
    NPC_MAGE_SKELETON_MINION        = 100080,
    NPC_SACRIFIED_SOUL              = 100081,
    NPC_KORMAC                      = 100082
};

enum TCGameObjecs
{
    GOB_IRON_GATE                   = 175611,
    GOB_DARK_GATE                   = 500020
};

enum TCEvents
{
    EVENT_OPEN_WIND_DOORS           = 1,
};

enum TCActions
{
	ACTION_SAY_DONE                 = -668000,
	ACTION_START_DUNGEON            = -668001,
	ACTION_AG_INTRO                 = -668002,
	ACTION_AG_SKELETON              = -668003,
	ACTION_AG_COMBAT                = -668004,
	ACTION_AG_END                   = -668005,
    ACTION_KORMAC_INTRO             = -668006,
    ACTION_KORMAC_FREED             = -668007,
    ACTION_KORMAC_WEAPON            = -668008,
};

enum TCSpells
{
    SPELL_RITUAL_CANALISATION       = 100094,
    SPELL_PORTAL_VISUAL             = 57687,
    SPELL_DEMONIC_PORTAL            = 68424,
    SPELL_SAND_STORM                = 68802,
    SPELL_VISUAL_TELEPORT           = 51347,
    SPELL_VISUAL_TELEPORT_DEMON     = 52235,
    SPELL_STASIS_FIELD              = 100101,
    SPELL_LIGHTS_BLESSING           = 71797,
};

template <class AI, class T>
inline AI* GetTristamCatacombsAI(T* obj)
{
	return GetInstanceAI<AI>(obj, TCScriptName);
}

#endif // TRISTAM_CATACOMBS_H_
