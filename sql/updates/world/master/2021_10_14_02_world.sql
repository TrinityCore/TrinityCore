-- Arcanist Helion (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `RangeAttackTime`=0, `VerifiedBuild`=40120 WHERE `entry`=15297;

UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15297 AND `Idx`=0;

UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID`=15528;

UPDATE `creature` SET `zoneId`=6455, `areaId`=3431, `spawntimesecs`=120, `curhealth`=522, `curmana`=1202, `VerifiedBuild`=40120 WHERE `guid`=55055;

DELETE FROM `creature_addon` WHERE `guid`=55055;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(55055, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- Arcanist Helion
