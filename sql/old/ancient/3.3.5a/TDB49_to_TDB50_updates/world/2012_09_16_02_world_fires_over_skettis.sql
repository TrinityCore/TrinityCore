-- Add support for quest ID: 11008 - "Fires Over Skettis" Warpten fix and Nelegalno/shlomi1515 updates
-- Also add support for achievement - http://www.wowhead.com/achievement=1275/bombs-away
-- Fix previous SQL what is not changed is not included
SET @TRIGGER := 22991;
SET @EGG := 185549;
SET @SKYBLAST := 39844;
SET @SUMMEGG := 39843;
-- Adds SAI support for Monstrous Kaliri Egg Trigger and the GO
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@TRIGGER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@TRIGGER AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@TRIGGER*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@TRIGGER,0,0,0,25,0,100,0,0,0,0,0,11,@SUMMEGG,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Monstrous Kaliri Egg Trigger - On spawn/reset - Summon Monstrous Kaliri Egg (object wild)'),
(@TRIGGER,0,1,2,8,0,100,0,@SKYBLAST,0,0,0,33,@TRIGGER,0,0,0,0,0,16,0,0,0,0,0,0,0, 'Monstrous Kaliri Egg Trigger - On Skyguard Blasting Charge hit - Give kill credit to invoker party'),
(@TRIGGER,0,2,0,61,0,100,0,0,0,0,0,80,@TRIGGER*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Monstrous Kaliri Egg Trigger - Linked with previous event - Start script 0'),
(@TRIGGER*100,9,0,0,0,0,100,0,44000,44000,0,0,11,@SUMMEGG,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Monstrous Kaliri Egg Trigger /On actionlist/ - Action 0 - Cast Summon Monstrous Kaliri Egg');
-- Add conditions (thanks to Vincent-Michael for adding and Shauren for noticing my failure miss)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@SKYBLAST;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@SKYBLAST,0,0,31,0,3,22991,0,0,0,'','Skyguard Blasting Charge can hit only Monstrous Kaliri Egg Trigger'),
(13,2,@SKYBLAST,0,0,31,0,5,185549,0,0,0,'','Skyguard Blasting can hit only Monstrous Kaliri Egg');
-- Remove SAI for Cannonball Stack
UPDATE `gameobject_template` SET `AIName`='' WHERE `entry`=@EGG;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@EGG AND `source_type`=1;
-- Delete GO spawns that are not needed
DELETE FROM `gameobject` WHERE `id`=@EGG;
