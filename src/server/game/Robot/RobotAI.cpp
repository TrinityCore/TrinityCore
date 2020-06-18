#include "RobotAI.h"
#include "Script_Warrior.h"
#include "Script_Hunter.h"
#include "Script_Shaman.h"
#include "Script_Paladin.h"
#include "Script_Warlock.h"
#include "Script_Priest.h"
#include "Script_Rogue.h"
#include "Script_Mage.h"
#include "Script_Druid.h"
#include "RobotStrategy_Solo.h"
#include "Group.h"
#include "RobotStrategy_Group_Azuregos.h"
#include "RobotStrategy_Group_BlackrockSpire.h"
#include "RobotStrategy_Group_DoctorWeavil.h"
#include "RobotStrategy_Group_Emeriss.h"
#include "RobotStrategy_Group_Lethon.h"
#include "RobotStrategy_Group_MoltenCore.h"
#include "RobotStrategy_Group_Taerar.h"
#include "RobotStrategy_Group_Test.h"
#include "RobotStrategy_Group_Ysondre.h"

RobotAI::RobotAI(Player* pmMe)
{
    me = pmMe;
    checkDelay = 0;
    robotType = 0;

    switch (me->GetClass())
    {
    case Classes::CLASS_WARRIOR:
    {
        sb = new Script_Warrior(me);
        break;
    }
    case Classes::CLASS_HUNTER:
    {
        sb = new Script_Hunter(me);
        break;
    }
    case Classes::CLASS_SHAMAN:
    {
        sb = new Script_Shaman(me);
        break;
    }
    case Classes::CLASS_PALADIN:
    {
        sb = new Script_Paladin(me);
        break;
    }
    case Classes::CLASS_WARLOCK:
    {
        sb = new Script_Warlock(me);
        break;
    }
    case Classes::CLASS_PRIEST:
    {
        sb = new Script_Priest(me);
        break;
    }
    case Classes::CLASS_ROGUE:
    {
        sb = new Script_Rogue(me);
        break;
    }
    case Classes::CLASS_MAGE:
    {
        sb = new Script_Mage(me);
        break;
    }
    case Classes::CLASS_DRUID:
    {
        sb = new Script_Druid(me);
        break;
    }
    }

    strategyMap.clear();

    RobotStrategy_Solo* rss = new RobotStrategy_Solo(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Solo] = rss;

    RobotStrategy_Group* rsg = new RobotStrategy_Group(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Group] = rsg;

    RobotStrategy_Group_BlackrockSpire* rsBlackrockSpire = new RobotStrategy_Group_BlackrockSpire(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Group_BlackrockSpire] = rsBlackrockSpire;

    RobotStrategy_Group_DoctorWeavil* rsDoctorWeavil = new RobotStrategy_Group_DoctorWeavil(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Group_DoctorWeavil] = rsDoctorWeavil;

    RobotStrategy_Group_Emeriss* rsEmeriss = new RobotStrategy_Group_Emeriss(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Group_Emeriss] = rsEmeriss;

    RobotStrategy_Group_Lethon* rsLethon = new RobotStrategy_Group_Lethon(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Group_Lethon] = rsLethon;

    RobotStrategy_Group_Taerar* rsTaerar = new RobotStrategy_Group_Taerar(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Group_Taerar] = rsTaerar;

    RobotStrategy_Group_Ysondre* rsYsondre = new RobotStrategy_Group_Ysondre(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Group_Ysondre] = rsYsondre;

    RobotStrategy_Group_Azuregos* rsAzuregos = new RobotStrategy_Group_Azuregos(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Group_Azuregos] = rsAzuregos;

    RobotStrategy_Group_MoltenCore* rsMoltenCore = new RobotStrategy_Group_MoltenCore(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Group_MoltenCore] = rsMoltenCore;

    RobotStrategy_Group_Test* rsTest = new RobotStrategy_Group_Test(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Group_Test] = rsTest;
}

void RobotAI::Update(uint32 pmDiff)
{
    checkDelay += pmDiff;
    if (sb->Update(pmDiff))
    {
        if (checkDelay > AI_CHECK_DELAY)
        {
            if (Group* myGroup = me->GetGroup())
            {
                strategyMap[myGroup->groupStrategyIndex]->Update(checkDelay);
            }
            else
            {
                strategyMap[Strategy_Index::Strategy_Index_Solo]->Update(checkDelay);
            }
            checkDelay = 0;
        }
    }
}

void RobotAI::Reset()
{
    if (RobotStrategy_Solo* rs = (RobotStrategy_Solo*)strategyMap[Strategy_Index::Strategy_Index_Solo])
    {
        rs->Reset();
    }
}
