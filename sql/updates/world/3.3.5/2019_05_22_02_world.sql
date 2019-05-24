-- 
DELETE FROM `creature` WHERE `guid` IN (105649, 105665, 105856, 105860, 105874, 105910)  AND `id`=20995;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(105649, 20995, 530, 0, 0, 1, 1, 0, 0,-3010.659, 2454.61, 63.35447, 4.2586, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(105665, 20995, 530, 0, 0, 1, 1, 0, 1,-2990.048, 2422.758, 61.41714, 4.328, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(105856, 20995, 530, 0, 0, 1, 1, 0, 0,-2988.613, 2442.192, 60.9212, 1.5882, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(105860, 20995, 530, 0, 0, 1, 1, 0, 0,-3050.783, 2455.764, 65.23952, 0.087, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(105874, 20995, 530, 0, 0, 1, 1, 0, 0,-2998.921, 2484.682, 62.26966, 3.752, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(105910, 20995, 530, 0, 0, 1, 1, 0, 0,-3048.497, 2455.866, 65.69756, 3.403, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (105649, 105665, 105856, 105860, 105874, 105910);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(105649, 0, 0, 65539, 1, 0, '10848 37467'),
(105665, 0, 0, 65536, 1, 0, '10848 37467'),
(105856, 0, 0, 65544, 1, 0, '10848 37467'),
(105860, 0, 0, 65536, 1, 0, '10848 37467'),
(105874, 0, 0, 65536, 1, 0, '10848 37467'),
(105910, 0, 0, 65536, 1, 0, '10848 37467');

UPDATE `creature_template_addon` SET `auras`="37467 37509" WHERE `entry` IN (21788);

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=20995 AND `ID`=1) OR (`CreatureID`=21788 AND `ID`=1) OR (`CreatureID`=19362 AND `ID`=1) OR (`CreatureID`=19362 AND `ID`=2) OR (`CreatureID`=19362 AND `ID`=3) OR (`CreatureID`=19362 AND `ID`=4);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`) VALUES
(20995, 1, 1117, 0, 0), -- 20995
(21788, 1, 1902, 0, 0), -- 21788
(19362, 4, 30180, 30180, 2507), -- 19362
(19362, 3, 30178, 0, 2507), -- 19362
(19362, 2, 30179, 0, 2507), -- 19362
(19362, 1, 30181, 21549, 2507); -- 19362

UPDATE `creature` SET `equipment_id`=-1 WHERE `id` IN (19362);
UPDATE `creature` SET `equipment_id`=1 WHERE `id` IN (21788);
