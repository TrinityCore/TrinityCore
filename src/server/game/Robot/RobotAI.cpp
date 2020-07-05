#include "RobotAI.h"
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

    strategyMap.clear();

    RobotStrategy_Solo* rss = new RobotStrategy_Solo(me);
    strategyMap[Strategy_Index::Strategy_Index_Solo] = rss;

    RobotStrategy_Group* rsg = new RobotStrategy_Group(me);
    strategyMap[Strategy_Index::Strategy_Index_Group] = rsg;

    RobotStrategy_Group_BlackrockSpire* rsBlackrockSpire = new RobotStrategy_Group_BlackrockSpire(me);
    strategyMap[Strategy_Index::Strategy_Index_Group_BlackrockSpire] = rsBlackrockSpire;

    RobotStrategy_Group_DoctorWeavil* rsDoctorWeavil = new RobotStrategy_Group_DoctorWeavil(me);
    strategyMap[Strategy_Index::Strategy_Index_Group_DoctorWeavil] = rsDoctorWeavil;

    RobotStrategy_Group_Emeriss* rsEmeriss = new RobotStrategy_Group_Emeriss(me);
    strategyMap[Strategy_Index::Strategy_Index_Group_Emeriss] = rsEmeriss;

    RobotStrategy_Group_Lethon* rsLethon = new RobotStrategy_Group_Lethon(me);
    strategyMap[Strategy_Index::Strategy_Index_Group_Lethon] = rsLethon;

    RobotStrategy_Group_Taerar* rsTaerar = new RobotStrategy_Group_Taerar(me);
    strategyMap[Strategy_Index::Strategy_Index_Group_Taerar] = rsTaerar;

    RobotStrategy_Group_Ysondre* rsYsondre = new RobotStrategy_Group_Ysondre(me);
    strategyMap[Strategy_Index::Strategy_Index_Group_Ysondre] = rsYsondre;

    RobotStrategy_Group_Azuregos* rsAzuregos = new RobotStrategy_Group_Azuregos(me);
    strategyMap[Strategy_Index::Strategy_Index_Group_Azuregos] = rsAzuregos;

    RobotStrategy_Group_MoltenCore* rsMoltenCore = new RobotStrategy_Group_MoltenCore(me);
    strategyMap[Strategy_Index::Strategy_Index_Group_MoltenCore] = rsMoltenCore;

    RobotStrategy_Group_Test* rsTest = new RobotStrategy_Group_Test(me);
    strategyMap[Strategy_Index::Strategy_Index_Group_Test] = rsTest;
}

void RobotAI::ResetStrategies()
{
    for (std::unordered_map<uint32, RobotStrategy_Base*>::iterator stIT = strategyMap.begin(); stIT != strategyMap.end(); stIT++)
    {
        if (RobotStrategy_Base* eachST = stIT->second)
        {
            if (eachST->sb)
            {
                eachST->sb->IdentifyCharacterSpells();
                eachST->sb->Reset();
            }
        }
    }
}

void RobotAI::Update(uint32 pmDiff)
{
    checkDelay += pmDiff;
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
