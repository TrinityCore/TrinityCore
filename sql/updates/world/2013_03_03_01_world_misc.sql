-- Issue 9311
-- Add Missing Sunreaver Guardian Mage inside Sunreaver Tavern (Thx Aokromes) 
SET @CGUID := 40267; -- Set by TDB Team
DELETE FROM `creature` WHERE `guid`=@CGUID;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`MovementType`) VALUES
(@CGUID,29255,571,1,1,5900.299,505.75,641.6531,4.171337,120,0,0);

-- Issue 9322: 
-- fix SAI to make the quest Mission: The Abyssal Shelf (10162) Horde completable (thx Kirkhammett) 
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=19273;
DELETE FROM `smart_scripts` WHERE `entryorguid`=19273;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19273,0,0,0,19, 0,100,0,10162,0,0,0,15,10162,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Commander To''arch - On Quest Accept - Call Areaexplored');
