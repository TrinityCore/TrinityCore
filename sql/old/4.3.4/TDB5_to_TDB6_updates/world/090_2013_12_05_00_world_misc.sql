-- Fix Quest 12244 "Shredder Repair" (Aliance) and 12270 "Shred the Alliance" (Horde)

SET @GUID := 45832;
SET @OGUID := 5927;

-- Missing Broken-down Shredder spawns
DELETE FROM `creature` WHERE `guid` IN (@GUID, @GUID+1);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,27354,571,1,1,0,0,4156.482,-2963.999,283.8623,6.091199,300,0,0,1,0,0),
(@GUID+1,27354,571,1,1,0,0,4085.375,-2916.553,278.0346,5.026548,300,0,0,1,0,0);

-- Spawn Basecamp objects
DELETE FROM `gameobject` WHERE `id` = 300202;
DELETE FROM `gameobject` WHERE `guid` IN (@OGUID, @OGUID+1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID, 300202, 571, 1, 1, 4379.31, -2921.89, 309.674, 2.54818, 0, 0, 0.439743, 0.898124, 300, 0, 1),
(@OGUID+1, 300202, 571, 1, 1, 3991.77, -3186.28, 281.448, 0.069813, 0, 0, 0.94445, -0.328654, 300, 0, 1);

-- Broken-down Shredder
UPDATE `creature_template` SET `speed_run`=0.57142857, `spell1`=48558, `spell2`=48604, `spell3`=48548, `spell4`=0, `spell5`=48610 WHERE `entry`=27354;
DELETE FROM `creature_template_addon` WHERE `entry`=27354;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(27354,0,0,1,0, '48456 48458');

-- Add Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=27354;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(27354,43671,1,0);

-- conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=27354 AND `SourceEntry` = 43671;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 27354, 43671, 1, 9, 0, 12244, 0, 0, 0, '', 'Required quest active for spellclick'),
(18, 27354, 43671, 2, 9, 0, 12270, 0, 0, 0, '', 'Required quest active for spellclick');

-- Add Spellscript name
DELETE FROM `spell_script_names` WHERE `spell_id`=48610;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(48610, 'spell_shredder_delivery');
