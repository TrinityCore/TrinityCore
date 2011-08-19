-- Zeppelin Power Core
SET @ENTRY := 23832;
-- Remove aura hack
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=@ENTRY);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@ENTRY,0,0,1,0, NULL); -- Zeppelin Power Core

-- Remove random movement
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `id`=@ENTRY;

-- SmartAI for Zeppelin Power Core
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,1,0,100,0,1000,60000,90000,120000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zeppelin Power Core - OOC - Load script every 1.5-2 min'),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,0,0,11,42491,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Zeppelin Power Core - Script - Cast Energized Periodic on self'),
(@ENTRY*100,9,1,0,0,0,100,0,60000,90000,0,0,28,42491,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zeppelin Power Core - Script - After 1 - 1.5 min, remove Energized Periodic on self');

-- Add condition for Ooze Buster (item 33108, spell 42489)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry`=33108;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,0,33108,0,24,1,4394,0,0, '', 'Item 33108 can target Bubbling Swamp Ooze'),
(18,0,33108,1,24,1,4393,0,0, '', 'Item 33108 can target Acidic Swamp Ooze');
