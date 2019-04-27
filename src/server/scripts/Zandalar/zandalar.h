/*
Copyright (C) 2019 HeronCore
*/


#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "GameObjectAI.h"
#include "NPCHandler.h"
#include "Vehicle.h"
#include <random>


#ifndef zandalar_h
#define zandalar_h

struct  Bfa
{
    float X, Y, Z;
    bool Fired;
};

namespace ZandalarQuests
{
    enum
    {
        QuestWelcomeToZuldazar  = 46957,
        QuestRastakhan          = 46930,
        QuestSpeakerOfTheHorde  = 46931
    };
}

namespace ZandalarPhaseSpell
{
    enum
    {
        PHASE_169       = 210401193
    };
}

#endif
