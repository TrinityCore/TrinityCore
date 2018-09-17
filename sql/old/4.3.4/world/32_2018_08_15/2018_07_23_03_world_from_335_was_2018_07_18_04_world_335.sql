/*
-- 
-- Anthion Harmon
UPDATE `creature_template` SET `npcflag`=3, `gossip_menu_id`=7072 WHERE `entry`=16016;

DELETE FROM `gossip_menu` WHERE `MenuID`=7072;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7072,8334,0),
(7072,8337,0),
(7072,8338,0);

DELETE FROM `npc_text` WHERE `ID` IN (8337,8338);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_1`) VALUES
(8337,"Ysida lives thanks to your courage, $n.  I am deeply in your debt and shall assist you as much as it is in my power.","",11933,0,1,0),
(8338,"I guess it's all just about over, right $n? I'm going to miss you... it'll be pretty lonely up here without someone to talk to.$B$BBut that doesn't mean that you can't come back to see me in the future!","",11912,0,1,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7072;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7072,8334,0,0,8,0,8946,0,0,1,0,0,"","Show gossip text 8334 if quest 'Proof of Life' is not rewarded"),
(14,7072,8337,0,0,8,0,8946,0,0,0,0,0,"","Show gossip text 8337 if quest 'Proof of Life' is rewarded"),
(14,7072,8337,0,0,8,0,9015,0,0,1,0,0,"","Show gossip text 8337 if quest 'The Challenge' is NOT rewarded"),
(14,7072,8338,0,0,8,0,9015,0,0,0,0,0,"","Show gossip text 8338 if quest 'The Challenge' is rewarded");

-- Falrin Treeshaper
UPDATE `creature_template` SET `npcflag`=3, `gossip_menu_id`=7073 WHERE `entry`=16032;

DELETE FROM `gossip_menu` WHERE `MenuID`=7073;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7073,8336,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=7073;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(7073,0,0,"I believe I misplaced that banner you enchanted for me, Falrin.",11910,1,1,0,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7073;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,7073,0,0,0,14,0,9015,0,0,1,0,0,"","Show gossip option if quest 'The Challenge' is taken, completed or rewarded"),
(15,7073,0,0,0,2,0,21986,1,1,1,0,0,"","Show gossip option if player does not have item 'Banner of Provocation'");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16032;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16032 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16032,0,0,1,62,0,100,0,7073,0,0,0,85,27755,2,0,0,0,0,7,0,0,0,0,0,0,0,"Falrin Treeshaper - On Gossip Option 0 Selected - Invoker Cast 'Create Banner of Provocation'"),
(16032,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Falrin Treeshaper - On Gossip Option 0 Selected - Close Gossip");
*/
