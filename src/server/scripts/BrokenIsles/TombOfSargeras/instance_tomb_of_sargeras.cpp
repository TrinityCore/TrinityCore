#include "tomb_of_sargeras.h"
#include "GameObject.h"

DoorData const doorData[] =
{
    {268514,                    DATA_GOROTH,                DOOR_TYPE_PASSAGE},
    {268580,                    DATA_GOROTH,                DOOR_TYPE_PASSAGE},
    {GO_GOROTH_GATES,           DATA_GOROTH,                DOOR_TYPE_PASSAGE},
    {269975,                    DATA_GOROTH,                DOOR_TYPE_ROOM},
    {269974,                    DATA_GOROTH,                DOOR_TYPE_ROOM},
    {269973,                    DATA_GOROTH,                DOOR_TYPE_ROOM},
    { GO_INTRODESTROY_2,        DATA_GOROTH,                DOOR_TYPE_PASSAGE},
    {269120,                    DATA_HARJATAN,              DOOR_TYPE_PASSAGE},
    {269192,                    DATA_HARJATAN,              DOOR_TYPE_ROOM},
    {GO_SASSZINE_DOOR,          DATA_MISTRESS_SASSZINE,     DOOR_TYPE_ROOM},
    {GO_INQUISITION_DOOR,       DATA_DEMONIC_INQUISITION,   DOOR_TYPE_ROOM},
    {GO_HAMMER_THRONE,          DATA_DEMONIC_INQUISITION,   DOOR_TYPE_PASSAGE},
    {GO_ELUNES_THRONE,          DATA_THE_DESOLATE_HOST,     DOOR_TYPE_PASSAGE},
    {GO_GOLGANETH_THRONE,       DATA_MISTRESS_SASSZINE,     DOOR_TYPE_PASSAGE},
    {GO_MAIDEN_DOOR,            DATA_MAIDEN_OF_VIGILANCE,   DOOR_TYPE_ROOM},
    {GO_SISTERS_MOON_DOOR,      DATA_SISTERS_OF_THEMOON,    DOOR_TYPE_ROOM},
    {GO_AVATARA_DOOR,           DATA_FALLEN_AVATAR,         DOOR_TYPE_ROOM},
    {GO_DESOLATE_HOST_DOOR_1,   DATA_THE_DESOLATE_HOST,     DOOR_TYPE_ROOM},
    {GO_DESOLATE_HOST_DOOR_2,   DATA_THE_DESOLATE_HOST,     DOOR_TYPE_ROOM},
    {0,                         0,                          DOOR_TYPE_ROOM} // END
};

ObjectData const creatureData[] =
{
    {NPC_BREACH_IN_WINDOW,      NPC_BREACH_IN_WINDOW},

    {NPC_KHADGAR,               NPC_KHADGAR},
    {NPC_VELEN,                 NPC_VELEN},
    {NPC_ILLIDAN,               NPC_ILLIDAN},
    {NPC_MAEIV,                 NPC_MAEIV},
    {NPC_DURGAN,                NPC_DURGAN},
    {NPC_ATRIGAN_MISC,          NPC_ATRIGAN_MISC},

    {NPC_EVENT_1,               NPC_EVENT_1},
    {NPC_EVENT_2,               NPC_EVENT_2},
    {NPC_SASSZINE_MISC,         NPC_SASSZINE_MISC},

    {NPC_GOROTH,                DATA_GOROTH},
    {NPC_SASSZINE,              DATA_MISTRESS_SASSZINE},
    {NPC_MOON_STALKER,          DATA_SISTERS_OF_THEMOON},
    {NPC_HUNTRESS_KASPARIAN,    NPC_HUNTRESS_KASPARIAN},
    {NPC_PRIESTESS_LUNASPYRE,   NPC_PRIESTESS_LUNASPYRE},
    {NPC_CAPTAIN_YATHAE,        NPC_CAPTAIN_YATHAE},
    {NPC_KILJAEDEN,             DATA_KILJAEDEN},

    {NPC_HAMMER_1,              NPC_HAMMER_1},
    {NPC_HAMMER_2,              NPC_HAMMER_2},
    {NPC_ELUNES_1,              NPC_ELUNES_1},
    {NPC_ELUNES_2,              NPC_ELUNES_2},
    {NPC_GOLGANETH_1,           NPC_GOLGANETH_1},
    {NPC_GOLGANETH_2,           NPC_GOLGANETH_2},
    {NPC_SASSZINE_NPC_OUTRO,    NPC_SASSZINE_NPC_OUTRO},
    {NPC_KILDJEDAN_AVATARA,     NPC_KILDJEDAN_AVATARA},
    {NPC_ATRIGAN,               NPC_ATRIGAN},
    {NPC_BELAK,                 NPC_BELAK},
    {NPC_HARJATAN,              NPC_HARJATAN},
    {NPC_ELDER,                 NPC_ELDER},
    {NPC_AVATARA_MAIDEN ,       NPC_AVATARA_MAIDEN},
    {NPC_SISTERS_ACH_ADD,       NPC_SISTERS_ACH_ADD},
    {0,                         0} // END
};

ObjectData const gobjectData[] =
{
    {GO_GOROTH_GATES,       GO_GOROTH_GATES},
    {GO_INTRODESTROY_1,     GO_INTRODESTROY_1},
    {GO_INTRODESTROY_2,     GO_INTRODESTROY_2},
    {GO_INTRODESTROY_3,     GO_INTRODESTROY_3},
    {GO_ELEVATOR,           GO_ELEVATOR},
    {GO_KILJAEDEN_BRIDGE_1, GO_KILJAEDEN_BRIDGE_1},
    {GO_KILJAEDEN_BRIDGE_2, GO_KILJAEDEN_BRIDGE_2},
    {GO_KILJAEDEN_CHEST,    GO_KILJAEDEN_CHEST},

    {269164,                269164},
    {268580,                268580},
    {GO_AVATARA_FLOOR ,     GO_AVATARA_FLOOR},

    // Avataras floor blocks
    {267700,                267700},
    {267701,                267701},
    {267702,                267702},
    {267703,                267703},
    {267704,                267704},
    {267705,                267705},
    {267706,                267706},
    {267707,                267707},
    {267708,                267708},
    {267709,                267709},
    {267710,                267710},
    {267711,                267711},
    {267712,                267712},
    {267713,                267713},
    {267714,                267714},
    {267715,                267715},
    {267716,                267716},
    {267717,                267717},
    {267718,                267718},
    {267719,                267719},
    {267720,                267720},
    {267721,                267721},
    {267722,                267722},
    {267723,                267723},
    {267724,                267724},

    // end Avatara bloks
    {0,                     0 } // END
};

void AddSC_instance_tomb_of_sargeras()
{
   
}
