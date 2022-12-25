/*
 * Copyright 2023 AzgathCore
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "grimrail_depot.h"
#include "GameObject.h"

enum eRocketsparkAndBorkaTalks
{
    TalkBorkaAggro = 1,     ///< I got this boss [45775]
    TalkBorkaDeath,         ///< Awwww!! sweet time.. now.. [45776]
    TalkBorkaSpell01,       ///< Don't get in my way! [45782]
    TalkBorkaSpell02,       ///< I'm unstoppable! [45783]
    TalkBorkaIntro01,       ///< Where you want this box? [45778]
    TalkBorkaIntro02,       ///< Why I gotta move all the boxes..?[45779]
    TalkBorkaKill01,        ///< Haha it's too much fun [45780]
    TalkBorkaKill02,        ///< [45781]

    TalkRocketsparkDeath,   ///< This was not the plan [43731]
    TalkRocketsparkEvent03, ///< Oh you big oof! stop breaking my things! [43732]
    TalkRocketsparkEvent04, ///< That was my entire collection of heartstone cards [43733]
    TalkRocketsparkEvent05, ///< Argh.. that was my last --- do you know how hard those are to get? [43734]
    TalkRocketsparkEvent06, ///< Hey dummy.. how would you like it if I'll break all your things![43735]
    TalkRocketsparkEvent07, ///< Time to go to plan B! [43736]
    TalkRocketsparkEvent08, ///< All systems online! Fire! [43737]
    TalkRocketsparkIntro,   ///< Overthere why do you keep asking? you're always move the boxes from here to there [43738]
    TalkRocketsparkKill01,  ///< Hah, got one! [43740]
    TalkRocketsparkKill02,  ///< Stop asking and get back to work [43741]
    TalkRocketsparkSpell01, ///< Acquiring targets! [43741]
    TalkRocketsparkSpell02, ///< Correcting for A speed volecity! [43741]
    TalkRocketsparkSpell03, ///< Adjusting for drang coefficient![43741]
};

enum eRocksparkAndBorkaActions
{
    ActionBorkaUnmanagedAggression = 1,
    ActionRocketSparkNewPlan,
    ActionBorkaActivateMadDash,
    ActionRocketSparkShootMissilesVX18,
    ActionMadDashContact
};

enum eRocksparkAndBorkaMovementInformed
{
    MovementInformedRocketsparkHigherGroundsStartx2101aMissileBarrage = 1,
    MovementInformBetterPosition,
    MovementHigherPlatform,
    MovementMadDashContact,
};

enum eRocksparkAndBorkaCreatures
{
    CreatureX21Triggers = 877894,
    CreatureTriggerLineOfSight = 432425,
    CreatureBottomTrigger = 80518
};

Position const g_PositionRandomRocketSparkMovements[4] =
{
{ 1718.639f, 1572.846f, 7.7136f, 3.616752f },
{ 1687.059f, 1572.249f, 7.7136f, 0.032194f },
{ 1719.248f, 1553.528f, 7.7136f, 2.866693f },
{ 1692.416f, 1583.240f, 7.7136f, 5.500137f },
};

Position const g_PostionRocketSparkHigherPlatform[2] =
{
{ 1708.924f, 1647.510f, 17.315f, 1.610062f },
{ 1726.215f, 1580.797f, 14.062f, 4.130380f },
};

Position const g_PositionNewRocketSparkHomePoint = { 1683.582f, 1558.110f, 7.7140f };
Position const g_PositionNewBorkaSparkHomePoint = { 1683.414f, 1546.511f, 7.714f };

#define g_FloorPositionZ 7.713f

void AddSC_RocketsparkandBorka()
{
   
};
