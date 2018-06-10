UPDATE `quest_objectives` SET `ObjectID` = '0' , `Amount` = '0' WHERE `ID` = '260718'; 
UPDATE `quest_objectives` SET `ObjectID` = '0' , `Amount` = '0' WHERE `ID` = '267528'; 
DELETE FROM `gameobject` WHERE `id`=207416;
UPDATE `spell_target_position` SET `MapID` = '730' , `PositionX` = '852.306' , `PositionY` = '1038.92' , `PositionZ` = '-5.3136' WHERE `ID` = '84464' AND `EffectIndex` = '0'; 
UPDATE `spell_target_position` SET `PositionX` = '854' , `PositionY` = '1075' , `PositionZ` = '-11.392230' WHERE `ID` = '84464' AND `EffectIndex` = '0'; 


DELETE FROM `creature` WHERE `id`=43818;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116797, 43818, 646, 0, 0, 1, 0, 0, 0, -1, 0, 1, 1027.85, 516.63, -49.3336, 2.61803, 300, 0, 0, 38640, 8726, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature_template` SET `KillCredit1` = 44839 WHERE `entry` = 44855;
-- Twilight Armsman SAI
SET @ENTRY := 44847;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Cleave"),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,79878,2,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Bloodlust at 40% HP");
-- Rockslice Flayer SAI
SET @ENTRY := 42606;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,86734,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Flayer Flurry");

DELETE FROM `creature_template_addon` WHERE (`entry`=43032);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (43032, 0, 0, 7, 1, 0, 29266);
DELETE FROM `creature_template_addon` WHERE (`entry`=43048);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (43048, 0, 0, 7, 1, 0, 29266);

UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 44887;
UPDATE `creature_equip_template` SET `ItemID1` = '52840' WHERE `CreatureID` = '44847' AND `ID` = '1'; 

UPDATE `creature_template` SET `gossip_menu_id` = 43036 WHERE `entry` = 43036;


SET @ENTRY := 43036;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,80413,0,0,0,33,43036,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit"),
(@ENTRY,0,1,0,62,0,100,0,43036,0,0,0,33,44207,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");

DELETE FROM `creature_template_addon` WHERE (`entry`=43036);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (43036, 0, 0, 7, 1, 0, 29266);
UPDATE `creature_template` SET `type_flags` = 0 WHERE `entry` = 43036;
REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('43036','0','0','Lets Go!','0','1','1','29416');
DELETE FROM `quest_objectives` WHERE `ID` = '267609'; 

DELETE FROM `creature_template_addon` WHERE (`entry`=44768);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (44768, 0, 0, 0, 1, 233, '');

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('44768','0','0','You free now!','0','1','1','29416');

SET @ENTRY := 44768;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,44768,0,0,0,33,44772,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Despawn");


UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` = 44768;




UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (45303,43036,44768);






































