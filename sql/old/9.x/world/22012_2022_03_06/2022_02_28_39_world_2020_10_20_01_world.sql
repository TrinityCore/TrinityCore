-- Default menu
UPDATE `creature_template` SET `gossip_menu_id` = 8025 WHERE `entry` = 19481;
DELETE FROM `gossip_menu` WHERE `MenuID` = 8025 AND `TextID` = 9902;
INSERT INTO `gossip_menu` (`MenuID`,`TextID`,`VerifiedBuild`) VALUES
(8025,9902,14007);

-- Old non-sniffed menus for Dalaran, new we'll send in script since there's only one NPC but two different menus
DELETE FROM `gossip_menu` WHERE (`MenuID` = 21255 AND `TextID` = 14192) OR (`MenuID` = 21256 AND `TextID` = 14194);
UPDATE `gossip_menu_option` SET `MenuID` = 10212, `ActionMenuID` = 10213 WHERE `MenuID` = 21255;
UPDATE `gossip_menu_option` SET `MenuID` = 10213 WHERE `MenuID` = 21256;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 21255;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` IN (21255,10212);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10212,0,0,0,17,0,1956,0,0,0,0,0,"","Group 0: Show Gossip Option 0 if achievement 'Higher Learning' is completed"),
(15,10212,0,0,0,2,0,44738,1,1,1,0,0,"","Group 0: Show Gossip Option 0 if player does not have item 'Kirin Tor Familiar'");

-- Old script for NPC in Dalaran
DELETE FROM `smart_scripts` WHERE `entryorguid` = -98174 AND `source_type` = 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 19481 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1948100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19481,0,0,0,20,0,100,0,10176,0,0,0,0,80,1948100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Archmage Vargoth - On Quest 'Ar'kelos the Guardian' Finished - Run Script"),
(19481,0,1,0,64,0,100,0,0,0,0,0,0,98,10212,14192,0,0,0,0,7,0,0,0,0,0,0,0,0,"Archmage Vargoth - On Gossip Hello - Send Gossip"),
(19481,0,2,3,62,0,100,0,10213,0,0,0,0,11,61457,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Archmage Vargoth - On Gossip Option 0 Selected - Cast 'Kirin Tor Familiar'"),
(19481,0,3,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Archmage Vargoth - On Link - Close Gossip"),

(1948100,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Archmage Vargoth - On Script - Say Line 0"),
(1948100,9,1,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Archmage Vargoth - On Script - Remove NPC Flags Gossip & Questgiver"),
(1948100,9,2,0,0,0,100,0,4000,4000,0,0,0,11,30416,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Archmage Vargoth - On Script - Cast 'Quest - Wood Cleanse Effect'"),
(1948100,9,3,0,0,0,100,0,1000,1000,0,0,0,107,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Archmage Vargoth - On Script - Summon Group 0"),
(1948100,9,4,0,0,0,100,0,4000,4000,0,0,0,11,34679,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Archmage Vargoth - On Script - Cast 'Archmage Vargoth's Ritual'"),
(1948100,9,5,0,0,0,100,0,9000,9000,0,0,0,86,34725,0,11,19924,50,0,1,0,0,0,0,0,0,0,0,"Archmage Vargoth - On Script - Cross Cast 'Shadow Nova' (Invis Ritual Crystal)"),
(1948100,9,6,0,0,0,100,0,1000,1000,0,0,0,11,13360,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Archmage Vargoth - On Script - Cast 'Knockdown'"),
(1948100,9,7,0,0,0,100,0,0,0,0,0,0,17,64,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Archmage Vargoth - On Script - Set Emote State 64"),
(1948100,9,8,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Archmage Vargoth - On Script - Say Line 1"),
(1948100,9,9,0,0,0,100,0,4000,4000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Archmage Vargoth - On Script - Set Emote State 0"),
(1948100,9,10,0,0,0,100,0,2000,2000,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Archmage Vargoth - On Script - Say Line 2"),
(1948100,9,11,0,0,0,100,0,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Archmage Vargoth - On Script - Add NPC Flags Gossip & Questgiver");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 19481 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,2,19481,0,0,4,1,4395,0,0,0,0,0,"","Group 0: Execute SAI (Action 1) if creature is located in Dalaran");

DELETE FROM `creature_text` WHERE `CreatureID` = 19481;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(19481,0,0,"I can't thank you enough for your help, $n. At long last, I will be free of this tower and Kael's damnable magic!",12,0,100,1,0,0,17524,0,"Archmage Vargoth"),
(19481,1,0,"No! How could the ritual fail?",12,0,100,0,0,0,17526,0,"Archmage Vargoth"),
(19481,2,0,"The curse remains intact. We'll have to find another way.",12,0,100,5,0,0,17535,0,"Archmage Vargoth");

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 19481 AND `summonerType` = 0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(19481,0,0,19916,2240.22,2234.18,136.190,0.71558,3,13000,"Archmage Vargoth - Group 0 - Archmage's Ritual Crystal"),
(19481,0,0,19916,2236.69,2224.65,136.419,5.63741,3,13000,"Archmage Vargoth - Group 0 - Archmage's Ritual Crystal"),
(19481,0,0,19924,2236.65,2224.67,136.415,5.21853,3,13000,"Archmage Vargoth - Group 0 - Invis Ritual Crystal"),
(19481,0,0,19924,2248.51,2239.90,136.592,5.04400,3,13000,"Archmage Vargoth - Group 0 - Invis Ritual Crystal"),
(19481,0,0,19924,2240.18,2234.19,136.186,0.10471,3,13000,"Archmage Vargoth - Group 0 - Invis Ritual Crystal"),
(19481,0,0,19916,2248.53,2239.87,136.594,5.60250,3,13000,"Archmage Vargoth - Group 0 - Archmage's Ritual Crystal");

UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 33555200 WHERE `entry` = 19916;
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 33555200 WHERE `entry` = 19924;
