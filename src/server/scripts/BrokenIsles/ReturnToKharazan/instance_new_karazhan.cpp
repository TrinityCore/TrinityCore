#include "Group.h"
#include "LFGMgr.h"
#include "new_karazhan.h"
#include "ScenarioMgr.h"
#include "GameObject.h"

DoorData const doorData[] =
{
    {GO_OPERA_SCENE_LEFT_DOOR,  DATA_OPERA_HALL,        DOOR_TYPE_PASSAGE},
    {GO_OPERA_SCENE_RIGHT_DOOR, DATA_OPERA_HALL,        DOOR_TYPE_ROOM},
    {GO_OPERA_DOOR_TO_MOROES,   DATA_OPERA_HALL,        DOOR_TYPE_PASSAGE},
    {GO_MOROES_DOOR_1,          DATA_MOROES,            DOOR_TYPE_ROOM},
    {GO_MOROES_DOOR_2,          DATA_MOROES,            DOOR_TYPE_ROOM},
    {GO_CURATOR_DOOR,           DATA_CURATOR,           DOOR_TYPE_PASSAGE},
    {GO_MEDIVH_DOOR_1,          DATA_SHADE_OF_MEDIVH,   DOOR_TYPE_ROOM},
    {GO_MEDIVH_DOOR_2,          DATA_SHADE_OF_MEDIVH,   DOOR_TYPE_PASSAGE},
    {GO_VIZADUUM_DOOR_1,        DATA_VIZADUUM,          DOOR_TYPE_ROOM},
};

enum Actions
{
    ACTION_1 = 1,
};

void AddSC_instance_new_karazhan()
{
  
}
