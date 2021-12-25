-- Sunstrider Guardian (Area: Sunstrider Isle - Difficulty: 0)
UPDATE `creature_template` SET `minlevel`=63, `maxlevel`=63, `VerifiedBuild`=40120 WHERE `entry`=15371;

UPDATE `creature_template_model` SET `VerifiedBuild`=40120 WHERE `CreatureID`=15371 AND `Idx` IN (0,1,2,3,4,5,6,7);

UPDATE `creature_model_info` SET `VerifiedBuild`=40120 WHERE `DisplayID` IN (89418,89420,89421,89800,89801,89802);

UPDATE `creature` SET `zoneId`=6455, `areaId`=3431, `position_z`=1.13558, `spawntimesecs`=120, `curhealth`=176865, `curmana`=5240, `VerifiedBuild`=40120 WHERE `guid`=55168;
UPDATE `creature` SET `zoneId`=6455, `areaId`=3431, `position_z`=1.32708, `spawntimesecs`=120, `curhealth`=176865, `curmana`=5240, `VerifiedBuild`=40120 WHERE `guid`=55169;
UPDATE `creature` SET `zoneId`=6455, `areaId`=3431, `position_z`=2.00616, `spawntimesecs`=120, `curhealth`=176865, `curmana`=5240, `VerifiedBuild`=40120 WHERE `guid`=55170;
UPDATE `creature` SET `zoneId`=6455, `areaId`=3431, `position_z`=2.15025, `spawntimesecs`=120, `curhealth`=176865, `curmana`=5240, `VerifiedBuild`=40120 WHERE `guid`=55171;
UPDATE `creature` SET `zoneId`=6455, `areaId`=3431, `position_z`=38.5174, `spawntimesecs`=120, `curhealth`=176865, `curmana`=5240, `VerifiedBuild`=40120 WHERE `guid`=55172;
UPDATE `creature` SET `zoneId`=6455, `areaId`=3431,                       `spawntimesecs`=120, `curhealth`=176865, `curmana`=5240, `VerifiedBuild`=40120 WHERE `guid`=55173;
UPDATE `creature` SET `zoneId`=6455, `areaId`=3431,                       `spawntimesecs`=120, `curhealth`=176865, `curmana`=5240, `VerifiedBuild`=40120 WHERE `guid`=55174;
UPDATE `creature` SET `zoneId`=6455, `areaId`=3431,                       `spawntimesecs`=120, `curhealth`=176865, `curmana`=5240, `VerifiedBuild`=40120 WHERE `guid`=55175;
UPDATE `creature` SET `zoneId`=6455, `areaId`=3431,                       `spawntimesecs`=120, `curhealth`=176865, `curmana`=5240, `VerifiedBuild`=40120 WHERE `guid`=55176;

DELETE FROM `creature_addon` WHERE `guid` BETWEEN 55168 AND 55175;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(55168, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Sunstrider Guardian
(55169, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Sunstrider Guardian
(55170, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Sunstrider Guardian
(55171, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Sunstrider Guardian
(55172, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Sunstrider Guardian
(55173, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Sunstrider Guardian
(55174, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Sunstrider Guardian
(55175, 0, 0, 0, 257, 0, 0, 0, 0, ''); -- Sunstrider Guardian

UPDATE `creature_addon` SET `bytes2`=257 WHERE `guid`=55176;
