/*
-- Bookie Herod
SET @GUID := 73429;
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,815,0,0,0,1,1,0,1,-11662.9,-637.447,30.0416,0.000360489,300,0,0,993,2680,0,0,0,0,"",0);

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=815;
DELETE FROM `smart_scripts` WHERE `entryorguid`=815 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(815,0,0,0,0,0,100,0,0,0,3000,5000,0,11,20816,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bookie Herod - In Combat - Cast 'Shadow Bolt'"),
(815,0,1,0,4,0,100,0,0,0,0,0,0,11,3722,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bookie Herod - On Aggro - Cast 'Summon Syndicate Spectre'");

-- Syndicate Spectre
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2638;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2638 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2638,0,0,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Syndicate Spectre - Just Summoned - Start Attacking");
*/
