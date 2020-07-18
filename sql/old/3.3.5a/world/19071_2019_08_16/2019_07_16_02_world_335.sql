-- 
DELETE FROM `creature` WHERE `guid` IN (111202);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(111202, 14222, 0, 1, 1, 0, 0, -242.918, -306.493, 164.816, 2.8492, 43200, 15, 0, 1342, 0, 1);
UPDATE `pool_members` SET `spawnId`=111202 WHERE `spawnId`=82864 AND `poolSpawnId`=1117;

UPDATE `pool_members` SET `poolSpawnId`=650 WHERE `spawnId`IN (14990,14991,14992,14993) AND `type`=1;
UPDATE `pool_members` SET `poolSpawnId`=651 WHERE `spawnId`IN (14994,14995,14996,14997,14998) AND `type`=1;

DELETE FROM `pool_template` WHERE `entry` IN (650,651);
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES 
(650, 1, "Takk's Nest spawn"),
(651, 1, "Ravasaur Matriarch's Nest");
