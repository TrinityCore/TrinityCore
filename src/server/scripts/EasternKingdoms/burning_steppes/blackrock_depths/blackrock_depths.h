/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_BRD_H
#define DEF_BRD_H

enum
{
    TYPE_RING_OF_LAW           = 0,
    TYPE_VAULT                 = 1,
    TYPE_ROCKNOT               = 2,
    TYPE_TOMB_OF_SEVEN         = 3,
    TYPE_LYCEUM                = 4,
    TYPE_IRON_HALL             = 5,
    TYPE_THUNDERBREW           = 6,
    TYPE_RELIC_COFFER          = 7,
    TYPE_DOOMGRIP              = 8,
    TYPE_RIBBLY                = 9,
    DATA_ARGELMACH_AGGRO       = 10,

    DATA_EMPEROR               = 11,
    DATA_PRINCESS              = 12,
    DATA_PHALANX               = 13,
    DATA_HATEREL               = 14,
    DATA_ANGERREL              = 15,
    DATA_VILEREL               = 16,
    DATA_GLOOMREL              = 17,
    DATA_SEETHREL              = 18,
    DATA_DOOMREL               = 19,
    DATA_DOPEREL               = 20,

    DATA_ARENA1                = 21,
    DATA_ARENA2                = 22,
    DATA_ARENA3                = 23,
    DATA_ARENA4                = 24,

    DATA_GO_BAR_KEG            = 25,
    DATA_GO_BAR_KEG_TRAP       = 26,
    DATA_GO_BAR_DOOR           = 27,
    DATA_GO_CHALICE            = 28,
    DATA_GO_TOMB_EXIT          = 29,
    DATA_THELDREN              = 30,

    TYPE_PATROL                = 31,
    TYPE_NAGMARA               = 32,
    TYPE_BRIDGE                = 33,
    TYPE_PLUGGER               = 34,

    DATA_ROCKNOT               = 35,
    DATA_NAGMARA               = 36,
    DATA_PLUGGER               = 37,

    TYPE_QUEST_JAIL_BREAK      = 38,
    TYPE_JAIL_DUGHAL           = 39,
    TYPE_JAIL_SUPPLY_ROOM      = 40,
    TYPE_JAIL_TOBIAS           = 41,

    DATA_ARENA_CHALLENGER      = 42,

    MAX_ENCOUNTER              = 20,

    EVENT_BAR_PATRONS          = 100,

    FACTION_DARK_IRON          = 54,

    NPC_EMPEROR                = 9019,
    NPC_PRINCESS               = 8929,
    NPC_HIGH_PRIESTESS         = 10076,
    NPC_PHALANX                = 9502,
    NPC_HATEREL                = 9034,
    NPC_ANGERREL               = 9035,
    NPC_VILEREL                = 9036,
    NPC_GLOOMREL               = 9037,
    NPC_SEETHREL               = 9038,
    NPC_DOOMREL                = 9039,
    NPC_DOPEREL                = 9040,
    NPC_RIBBLY_S_CRONY         = 10043,
    NPC_ARENA_SPECTATOR        = 8916,
    //NPC_PANZOR               = 8923, Ustaag : gérer par la DB
    NPC_GOLEM_RAVAGE           = 8906,
    NPC_WRATH_HAMMER_CONSTRUCT = 8907,
    NPC_GOLEM_LORD_ARGELMACH   = 8983,

    // Jail Break!
    QUEST_JAIL_BREAK           = 4322,
    
    NPC_OGRABISI               = 9677,
    NPC_SHILL                  = 9678,
    NPC_CREST                  = 9680,
    NPC_JAZ                    = 9681,

    GO_JAIL_DOOR_SUPPLY        = 170561,
    GO_JAIL_SUPPLY_CRATE       = 166872,
    GO_JAIL_DOOR_DUGHAL        = 170562,
    GO_JAIL_DOOR_TOBIAS        = 170566,
    GO_JAIL_DOOR_CREST         = 170567,
    GO_JAIL_DOOR_JAZ           = 170568,
    GO_JAIL_DOOR_SHILL         = 170569,

    // Ambassador Flamelash
    GO_DWARF_RUNE_A01          = 170578,
    GO_DWARF_RUNE_B01          = 170579,
    GO_DWARF_RUNE_C01          = 170580,
    GO_DWARF_RUNE_D01          = 170581,
    GO_DWARF_RUNE_E01          = 170582,
    GO_DWARF_RUNE_F01          = 170583,
    GO_DWARF_RUNE_G01          = 170584,

    // Grim Guzzler
    NPC_PLUGGER_SPAZZRING      = 9499,
    NPC_PRIVATE_ROCKNOT        = 9503,
    NPC_MISTRESS_NAGMARA       = 9500,
    NPC_GUZZLING_PATRON        = 9547,
    NPC_GRIM_PATRON            = 9545,
    NPC_HAMMERED_PATRON        = 9554,

    PATRON_EMOTE               = 0,
    PATRON_PISSED              = 1,
    PATRON_HOSTILE             = 2,
    SAY_PISSED_PATRON_1        = -1230042,
    SAY_PISSED_PATRON_2        = -1230040,
    SAY_PISSED_PATRON_3        = -1230044,
    SAY_ROCKNOT_DESPAWN        = -1230045,
    YELL_PATROL_1              = -1230046,
    YELL_PATROL_2              = -1230047,
    SPELL_NAGMARA_VANISH       = 15341,

    NPC_FIREGUARD_DESTROYER    = 8911,
    NPC_ANVILRAGE_OFFICER      = 8895,

    NPC_SHADOWFORGE_SENATOR    = 8904,
    NPC_GRIMSTONE              = 10096,
    NPC_THELDREN               = 16059,

    GO_ARENA1                  = 161525,
    GO_ARENA2                  = 161522,
    GO_ARENA3                  = 161524,
    GO_ARENA4                  = 161523,
    GO_SHADOW_LOCK             = 161460,
    GO_SHADOW_MECHANISM        = 161461,
    GO_SHADOW_GIANT_DOOR       = 157923,
    GO_SHADOW_DUMMY            = 161516,
    GO_BAR_KEG_SHOT            = 170607,
    GO_BAR_KEG_TRAP            = 171941,
    GO_BAR_DOOR                = 170571,
    GO_TOMB_ENTER              = 170576,
    GO_TOMB_EXIT               = 170577,
    GO_LYCEUM                  = 170558,
    GO_GOLEM_ROOM_N            = 170573,
    GO_GOLEM_ROOM_S            = 170574,
    GO_THRONE_ROOM             = 170575,

    GO_SPECTRAL_CHALICE        = 164869,
    GO_CHEST_SEVEN             = 169243,
    GO_SECRET_DOOR             = 174553,

    GO_ARENA_SPOILS            = 181074,

    QUEST_ROYAL_RESCUE         = 4003,   // horde quest
    QUEST_FATE_KINGDOM         = 4362,   // alliance quest

    YELL_MAGMUS                = -1230052,

    // Emperor Dagran Thaurissan
    YELL_SENATOR_1             = -1230048,
    YELL_SENATOR_2             = -1230049,
    YELL_SENATOR_3             = -1230050,
    YELL_SENATOR_4             = -1230051,
};

// Random emotes for Grim Guzzler patrons
static uint32 const aPatronsEmotes[] =
{
    EMOTE_ONESHOT_EXCLAMATION, EMOTE_ONESHOT_CHEER, EMOTE_ONESHOT_CHEER, EMOTE_ONESHOT_LAUGH, EMOTE_ONESHOT_LAUGH, EMOTE_ONESHOT_LAUGH
};

// Used to summon the patrol in Grim Guzzler
static float const aBarPatrolPositions[2][4] = {
    {872.7059f, -232.5491f, -43.7525f, 2.069044f},
    {865.5645f, -219.7471f, -43.7033f, 2.033881f}
};

static uint32 const aBarPatrolId[3] = {NPC_FIREGUARD_DESTROYER, NPC_ANVILRAGE_OFFICER, NPC_ANVILRAGE_OFFICER};

#endif
