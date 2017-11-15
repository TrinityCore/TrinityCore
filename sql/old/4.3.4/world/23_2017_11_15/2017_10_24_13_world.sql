--
DELETE FROM `creature` WHERE `guid` IN (77937,77938,77939,77940);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(77937, 22062, 530, 0, 0, 1, 1, 0, 0, 7165.62744, -6604.59228, 60.65881, 5.199848, 72000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(77938, 22062, 530, 0, 0, 1, 1, 0, 0, 7226.793, -6406.289, 56.1663, 4.067284, 72000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(77939, 22062, 530, 0, 0, 1, 1, 0, 0, 6294.86865, -6463.20703, 83.01150, 0.262043, 72000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(77940, 22062, 530, 0, 0, 1, 1, 0, 0, 6299.13378, -6250.60693, 77.81383, 0.069625, 72000, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `pool_template` WHERE `entry` = 373;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(373, 1, 'Dr. Whitherlimb');

DELETE FROM `pool_creature` WHERE `pool_entry` IN (373);
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(77937, 373, 0, 'Dr. Whitherlimb 1'),
(77938, 373, 0, 'Dr. Whitherlimb 2'),
(77939, 373, 0, 'Dr. Whitherlimb 3'),
(77940, 373, 0, 'Dr. Whitherlimb 4');

UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85 WHERE `entry`=42319;
DELETE FROM conditions WHERE SourceEntry IN (79781) AND SourceGroup=1 AND SourceTypeOrReferenceId=13;
UPDATE `quest_template_addon` SET `ProvidedItemCount` = 1 WHERE `ID` IN (26333,27671);
