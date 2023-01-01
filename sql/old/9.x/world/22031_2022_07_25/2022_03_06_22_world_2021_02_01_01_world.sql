-- https://www.youtube.com/watch?v=6jUsd_n2jg4 & https://archive.li/lsiB4

-- Matrix Punchograph 3005-A
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 1045;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,1045,1643,0,0,2,0,9279,1,0,1,0,0,"","Group 0: Show gossip text 1643 if player does not have item 'White Punch Card'"),
(14,1045,1753,0,0,2,0,9279,1,0,0,0,0,"","Group 0: Show gossip text 1753 if player does have item 'White Punch Card'");

UPDATE `gossip_menu_option` SET `ActionMenuID` = 1044 WHERE `MenuID` = 1045 AND `OptionID` = 0;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 1045;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,1045,0,0,0,2,0,9279,1,0,0,0,0,"","Group 0: Show Gossip Option 0 if player does have item 'White Punch Card'");

UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI", `ScriptName` = "" WHERE `entry` = 142345;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 142345 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(142345,1,0,0,62,0,100,0,1045,0,0,0,0,134,11512,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Matrix Punchograph 3005-A - On Gossip Option 0 Selected - Invoker Cast 'Create Yellow Punch Card'");

-- Matrix Punchograph 3005-B
DELETE FROM `gossip_menu` WHERE `MenuID` IN (57020,57021);
INSERT INTO `gossip_menu` (`MenuID`,`TextID`,`VerifiedBuild`) VALUES
(57020,1655,0),
(57020,1656,0),
(57021,1657,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` IN (1047,57020);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,1047,1647,0,0,2,0,9280,1,0,1,0,0,"","Group 0: Show gossip text 1647 if player does not have item 'Yellow Punch Card'"),
(14,1047,1754,0,0,2,0,9280,1,0,0,0,0,"","Group 0: Show gossip text 1754 if player does have item 'Yellow Punch Card'"),
(14,57020,1655,0,0,7,0,202,140,0,0,0,0,"","Group 0: Show gossip text 1655 if player does have Engineering with skill level 140"),
(14,57020,1656,0,0,7,0,202,140,0,1,0,0,"","Group 0: Show gossip text 1656 if player does not have Engineering with skill level 140");

UPDATE `gossip_menu_option` SET `ActionMenuID` = 1046 WHERE `MenuID` = 1047 AND `OptionID` = 0;

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 1047 AND `OptionID` = 1;
DELETE FROM `gossip_menu_option` WHERE `MenuID` = 57020;
INSERT INTO `gossip_menu_option` (`MenuID`,`OptionID`,`OptionIcon`,`OptionText`,`OptionBroadcastTextID`,`OptionType`,`OptionNpcFlag`,`ActionMenuID`,`ActionPoiID`,`BoxCoded`,`BoxMoney`,`BoxText`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(1047,1,0,"Use engineering to access hidden schematics!",4008,1,1,57020,0,0,0,"",0,0),
(57020,0,0,"Access: Minor Recombobulator",4010,1,1,57021,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` IN (1047,57020);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,1047,0,0,0,2,0,9280,1,0,0,0,0,"","Group 0: Show Gossip Option 0 if player does have item 'Yellow Punch Card'"),

(15,1047,1,0,0,2,0,9280,1,0,0,0,0,"","Group 0: Show Gossip Option 1 if player does have item 'Yellow Punch Card'"),
(15,1047,1,0,0,2,0,9327,1,0,0,0,0,"","Group 0: Show Gossip Option 1 if player does have item 'Security DELTA Data Access Card'"),
(15,1047,1,0,0,7,0,202,1,0,0,0,0,"","Group 0: Show Gossip Option 0 if player does have Engineering with skill level 1"),

(15,57020,0,0,0,7,0,202,140,0,0,0,0,"","Group 0: Show Gossip Option 0 if player does have Engineering with skill level 140"),
(15,57020,0,0,0,25,0,3952,0,0,1,0,0,"","Group 0: Show Gossip Option 0 if spell 'Minor Recombobulator' is not learned");

UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI", `ScriptName` = "" WHERE `entry` = 142475;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 142475 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(142475,1,0,0,62,0,100,0,1047,0,0,0,0,134,11525,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Matrix Punchograph 3005-B - On Gossip Option 0 Selected - Invoker Cast 'Create Blue Punch Card'"),
(142475,1,1,0,62,0,100,0,57020,0,0,0,0,11,4011,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Matrix Punchograph 3005-B - On Gossip Option 0 Selected - Invoker Cast 'Minor Recombobulator'");

-- Matrix Punchograph 3005-C
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 1049;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,1049,1649,0,0,2,0,9282,1,0,1,0,0,"","Group 0: Show gossip text 1649 if player does not have item 'Blue Punch Card'"),
(14,1049,1755,0,0,2,0,9282,1,0,0,0,0,"","Group 0: Show gossip text 1755 if player does have item 'Blue Punch Card'");

UPDATE `gossip_menu_option` SET `ActionMenuID` = 1048 WHERE `MenuID` = 1049 AND `OptionID` = 0;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 1049;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,1049,0,0,0,2,0,9282,1,0,0,0,0,"","Group 0: Show Gossip Option 0 if player does have item 'Blue Punch Card'");

UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI", `ScriptName` = "" WHERE `entry` = 142476;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 142476 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(142476,1,0,0,62,0,100,0,1049,0,0,0,0,134,11528,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Matrix Punchograph 3005-C - On Gossip Option 0 Selected - Invoker Cast 'Create Red Punch Card'");

-- Matrix Punchograph 3005-D
DELETE FROM `gossip_menu` WHERE `MenuID` IN (57022);
INSERT INTO `gossip_menu` (`MenuID`,`TextID`,`VerifiedBuild`) VALUES
(57022,1655,0),
(57022,1656,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` IN (1050,57022);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,1050,1651,0,0,2,0,9281,1,0,1,0,0,"","Group 0: Show gossip text 1651 if player does not have item 'Red Punch Card'"),
(14,1050,1756,0,0,2,0,9281,1,0,0,0,0,"","Group 0: Show gossip text 1756 if player does have item 'Red Punch Card'"),

(14,57022,1655,0,0,7,0,202,160,0,0,0,0,"","Group 0: Show gossip text 1655 if player does have Engineering with skill level 160"),
(14,57022,1656,0,0,7,0,202,160,0,1,0,0,"","Group 0: Show gossip text 1656 if player does not have Engineering with skill level 160");

UPDATE `gossip_menu_option` SET `ActionMenuID` = 1052 WHERE `MenuID` = 1050 AND `OptionID` = 0;

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 1050 AND `OptionID` = 1;
DELETE FROM `gossip_menu_option` WHERE `MenuID` = 57022;
INSERT INTO `gossip_menu_option` (`MenuID`,`OptionID`,`OptionIcon`,`OptionText`,`OptionBroadcastTextID`,`OptionType`,`OptionNpcFlag`,`ActionMenuID`,`ActionPoiID`,`BoxCoded`,`BoxMoney`,`BoxText`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(1050,1,0,"Use engineering to access hidden schematics!",4008,1,1,57022,0,0,0,"",0,0),
(57022,0,0,"Access: Discombobulator Ray",4167,1,1,57021,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` IN (1050,57022);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,1050,0,0,0,2,0,9281,1,0,0,0,0,"","Group 0: Show Gossip Option 0 if player does have item 'Red Punch Card'"),

(15,1050,1,0,0,2,0,9281,1,0,0,0,0,"","Group 0: Show Gossip Option 1 if player does have item 'Red Punch Card'"),
(15,1050,1,0,0,2,0,9327,1,0,0,0,0,"","Group 0: Show Gossip Option 1 if player does have item 'Security DELTA Data Access Card'"),
(15,1050,1,0,0,7,0,202,1,0,0,0,0,"","Group 0: Show Gossip Option 0 if player does have Engineering with skill level 1"),

(15,57022,0,0,0,7,0,202,160,0,0,0,0,"","Group 0: Show Gossip Option 0 if player does have Engineering with skill level 160"),
(15,57022,0,0,0,25,0,3959,0,0,1,0,0,"","Group 0: Show Gossip Option 0 if spell 'Discombobulator Ray' is not learned");

UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI", `ScriptName` = "" WHERE `entry` = 142696;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 142696 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(142696,1,0,0,62,0,100,0,1050,0,0,0,0,134,11545,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Matrix Punchograph 3005-D - On Gossip Option 0 Selected - Cast 'Create Prismatic Punch Card'"),
(142696,1,1,0,62,0,100,0,57022,0,0,0,0,11,11595,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Matrix Punchograph 3005-D - On Gossip Option 0 Selected - Cast 'Discombobulator Ray'");

-- Schematic: Discombobulator Ray drops only from Mekgineer Thermaplugg
DELETE FROM `reference_loot_template` WHERE `Entry` = 24704 AND `Item` = 4413 AND `Reference` = 0;
