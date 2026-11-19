-- Training Dummy (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `VerifiedBuild`=40120 WHERE `entry`=44937;

UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=44937 AND `Idx`=0;

UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=3019;

UPDATE `creature` SET `zoneId`=6455, `areaId`=3431, `spawntimesecs`=120, `curhealth`=1244, `VerifiedBuild`=40120 WHERE `guid` IN (250887,250888,250889,250890,250891,250892);

DELETE FROM `creature_addon` WHERE `guid` BETWEEN 250887 AND 250892;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(250887, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Training Dummy
(250888, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Training Dummy
(250889, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Training Dummy
(250890, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Training Dummy
(250891, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Training Dummy
(250892, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- Training Dummy
