-- https://youtu.be/Jh9OtDqc7nE?t=46
DELETE FROM `gossip_menu` WHERE `MenuID` = 1054 AND `TextID` = 1654;
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES
(1054,1654);

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 1053 AND `OptionID` = 0;
INSERT INTO `gossip_menu_option` (`MenuID`,`OptionID`,`OptionIcon`,`OptionText`,`OptionBroadcastTextID`,`OptionType`,`OptionNpcFlag`,`ActionMenuID`,`ActionPoiID`,`BoxCoded`,`BoxMoney`,`BoxText`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(1053,0,0,"Continue reading...",4006,1,1,1054,0,0,0,"",0,0);

UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI", `ScriptName` = "" WHERE `entry` = 142715;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 142715 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(142715,1,0,0,62,0,100,0,1053,0,0,0,0,15,2936,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Tablet of Theka - On Gossip Option 0 Selected - Quest Credit 'The Spider God'");

-- https://youtu.be/j1xaMRo__G0?t=238
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI", `ScriptName` = "" WHERE `entry` = 178553;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 178553 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(178553,1,0,1,70,0,100,0,2,0,0,0,0,12,13301,4,60000,0,0,0,8,0,0,0,0,-7183.85,440.446,64.2642,5.43083,"Hive'Ashi Pod - On Loot State Changed - Summon Creature 'Hive'Ashi Ambusher'"),
(178553,1,1,0,61,0,100,0,0,0,0,0,0,12,13301,4,60000,0,0,0,8,0,0,0,0,-7176.25,442.055,64.1727,4.03283,"Hive'Ashi Pod - On Link - Summon Creature 'Hive'Ashi Ambusher'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 178553 AND `SourceId` = 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,178553,1,0,29,0,13301,30,0,1,0,0,"","Group 0: Execute SAI (Action 0) if alive creature 'Hive'Ashi Ambusher' is not within 30 yards");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 13301;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 13301 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(13301,0,0,1,54,0,100,0,0,0,0,0,0,11,10389,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hive'Ashi Ambusher - On Just Summoned - Cast 'Spawn Smoke'"),
(13301,0,1,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hive'Ashi Ambusher - On Link - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = 13301;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(13301,0,0,"%s springs forth to defend its hive!",16,0,100,0,0,0,8675,0,"Hive'Ashi Ambusher");
