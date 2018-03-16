/*
-- Laris Geardawdle - fix Gossip Texts
DELETE FROM `gossip_menu` WHERE `MenuID`=2405 AND `TextID` IN (3099,3098,3097);
DELETE FROM `gossip_menu` WHERE `MenuID` IN (2406,2407,2408);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(2405,3097,0),
(2405,3099,0),
(2405,3098,0),
(2406,3100,0),
(2407,3101,0),
(2408,3102,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (2406,2407,2405);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(2405,0,0,"Is there a difference between ooze and slime?",5450,1,1,2406,0,0,0,"",0,0),
(2406,0,0,"What do you mean by \"pure?\"",5452,1,1,2407,0,0,0,"",0,0),
(2407,0,0,"Are there any areas you can think of that would be so untouched?",5454,1,1,2408,0,0,0,"",0,0);

DELETE FROM `npc_text` WHERE `ID` IN (3097,3099);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_1`) VALUES
(3097,"Incredible! Amazing! I don't even know what this means!","",5447,0,1,0),
(3099,"There must be someplace on Azeroth that we can find oozes uncorrupted by the Scourge or anything else. But where?!","",5449,0,1,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=2405;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,2405,3097,0,0,8,0,4512,0,0,0,0,0,"","Show gossip text 3099 if quest 'A Little Slime Goes a Long Way (Part 1)' is rewarded"),
(14,2405,3097,0,0,9,0,4513,0,0,1,0,0,"","Show gossip text 3099 if quest 'A Little Slime Goes a Long Way (Part 2)' is not taken"),
(14,2405,3099,0,0,9,0,4513,0,0,0,0,0,"","Show gossip text 3099 if quest 'A Little Slime Goes a Long Way (Part 2)' is taken"),
(14,2405,3098,0,0,8,0,4513,0,0,0,0,0,"","Show gossip text 3098 if quest 'A Little Slime Goes a Long Way (Part 2)' is rewarded"),
(15,2405,0,0,0,9,0,4513,0,0,0,0,0,"","Show gossip option if quest 'A Little Slime Goes a Long Way (Part 2)' is taken");
*/
