#include "RobotAI.h"
#include "RobotStrategy_Solo.h"
#include "Group.h"
#include "RobotStrategy_Group_Azuregos.h"
#include "RobotStrategy_Group_BlackrockSpire.h"
#include "RobotStrategy_Group_DoctorWeavil.h"
#include "RobotStrategy_Group_Emeriss.h"
#include "RobotStrategy_Group_Lethon.h"
#include "RobotStrategy_Group_Lucifron.h"
#include "RobotStrategy_Group_Taerar.h"
#include "RobotStrategy_Group_Test.h"
#include "RobotStrategy_Group_Ysondre.h"

RobotAI::RobotAI(Player* pmMe)
{
    me = pmMe;
    checkDelay = 0;
    robotType = 0;
    strategyMap.clear();

    RobotStrategy_Solo* rss = new RobotStrategy_Solo(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Solo] = rss;

    RobotStrategy_Group* rsg = new RobotStrategy_Group(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Group] = rsg;

    RobotStrategy_Group_BlackrockSpire* rsBlackrockSpire = new RobotStrategy_Group_BlackrockSpire(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Group_Blackrock_Spire] = rsBlackrockSpire;

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

    RobotStrategy_Group_Lucifron* rsLucifron = new RobotStrategy_Group_Lucifron(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Group_Lucifron] = rsLucifron;

    RobotStrategy_Group_Test* rsTest = new RobotStrategy_Group_Test(pmMe);
    strategyMap[Strategy_Index::Strategy_Index_Group_Test] = rsTest;
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

void RobotAI::Reset()
{
    if (RobotStrategy_Solo* rs = (RobotStrategy_Solo*)strategyMap[Strategy_Index::Strategy_Index_Solo])
    {
        rs->Reset();
    }
}
