-- Orb of Command (179879)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=6001;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=6001;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,6001,0,0,0,8,0,7761,0,0,0,0,0,"","Show gossip option if quest '7761' is rewarded"),
(14,6001,7155,0,0,8,0,7761,0,0,0,0,0,"","Show gossip text 7155 if quest '7761' rewarded");
DELETE FROM `gossip_menu` WHERE `MenuID`=6001 AND `TextID`=7155;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES (6001,7155);
DELETE FROM `gossip_menu_option` WHERE `MenuID`=6001;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(6001,0,0,"<Place my hand on the orb.>" ,9859,1,1,0,0,0,0,"",0,0);

-- Orb of Command SAI
SET @ENTRY := 179879;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI", `scriptname` = '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,62,0,100,0,6001,0,0,0,85,23460,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orb of Command - On Gossip Option 0 Selected - Invoker Cast 'Teleport to Blackwing Lair DND'");
