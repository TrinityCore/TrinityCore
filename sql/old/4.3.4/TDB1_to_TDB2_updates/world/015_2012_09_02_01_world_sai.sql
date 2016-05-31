-- Lok'lira the Crone
SET @ENTRY := 29975;
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,9910,0,0,0,33,30467,0,0,0,0,0,7,0,0,0,0,0,0,0,'Loklira - gossip select 4 - The Hyldsmeet Kill credit'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Loklira - gossip select 4 - Close gossip');

UPDATE `gossip_menu_option` SET `action_menu_id`=9908 WHERE `menu_id`=9907;
UPDATE `gossip_menu_option` SET `action_menu_id`=9909 WHERE `menu_id`=9908;
UPDATE `gossip_menu_option` SET `action_menu_id`=9910 WHERE `menu_id`=9909;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9907;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9907,0,0,9,12970,0,0,0,'','Loklira - Show gossip if quest accepted');

-- Thorim
SET @THORIM :=29445;
UPDATE `creature` SET `modelid`=0 WHERE `id`=@THORIM;
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@THORIM;
DELETE FROM `creature_addon` WHERE `guid`=97128;
DELETE FROM `creature_template_addon` WHERE `entry`=@THORIM;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@THORIM,0,0,1,0,0,'');

DELETE FROM `smart_scripts` WHERE `entryorguid`=@THORIM AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@THORIM,0,0,0,62,0,100,0,9926,0,0,0,33,30514,0,0,0,0,0,7,0,0,0,0,0,0,0,'Thorim - gossip select  - give quest credit');

UPDATE `gossip_menu_option` SET `action_menu_id`=9927 WHERE `menu_id`=9924;
UPDATE `gossip_menu_option` SET `action_menu_id`=9926 WHERE `menu_id`=9927;
UPDATE `gossip_menu_option` SET `action_menu_id`=9925 WHERE `menu_id`=9926;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9924;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9924,0,0,9,13064,0,0,0,'','Thorim - Show gossip if quest accepted');
