-- 
DELETE FROM `creature` WHERE `guid` IN (84843)  AND `id`=20922;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(84843, 20922, 530, 0, 0, 1, 1, 0, 0, 4038.75585, 3547.24096, 121.42054, 1.682029, 900, 0, 0, 0, 0, 0, 0, 0, 0, 0);
UPDATE `creature_template` SET `unit_flags`= `unit_flags`|537166592 WHERE `entry`=20922;
DELETE FROM `creature_template_addon` WHERE `entry` IN (20922);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(20922, '29266');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (20780);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20780) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20780, 0, 0, 0, 1, 0, 100, 0, 4000, 4000, 60000, 60000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kaylaan - OOC - Say text"),
(20780, 0, 1, 0, 1, 0, 100, 0, 15000, 20000, 60000, 60000, 11, 35746, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Kaylaan - OOC - Cast Resurrection");


DELETE FROM `creature_text` WHERE `CreatureID`=20780;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(20780,0,0,"Do not die on me, vindicator!",12,0,100,0,0,0,18386,0,"Kaylaan"),
(20780,0,1,"I've failed. The Light has abandoned me.",12,0,100,0,0,0,18595,0,"Kaylaan"),
(20780,0,2,"It is hopeless... I've done all I can.",12,0,100,0,0,0,18594,0,"Kaylaan"),
(20780,0,3,"Kael'thas and the Legion... just what we needed!",12,0,100,0,0,0,18387,0,"Kaylaan"),
(20780,0,4,"Light! Do not fail me!",12,0,100,0,0,0,18385,0,"Kaylaan");
