SET @Guid1 := 45211;
SET @Guid2 := 45221;

DELETE FROM `creature` WHERE `guid` BETWEEN @Guid1+0 AND @Guid1+3;

INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES 
(45213, 1548, 0, 1, 1, 9020, 0, 1859.45, 516.852, 35.8201, 2.12764, 300, 10, 0, 137, 0, 1, 0, 0, 0, 0),
(45214, 24021, 571, 1, 1, 21999, 0, 6448.94, -4475.18, 451.329, 0.802851, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature` WHERE `guid` BETWEEN @Guid2+0 AND @Guid2+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@Guid2+0, 18896, 530, 1, 1,  -4119.59, -11467.84, -129.1829, 6.056293, 120, 0, 0), -- 18896 (Area: 3557)
(@Guid2+1, 18896, 530, 1, 1,  -4018.095, -11417.03, -136.0335, 5.67232, 120, 0, 0), -- 18896 (Area: 3557)
(@Guid2+2, 18896, 530, 1, 1,  -4088.29, -11393.94, -139.5034, 4.049164, 120, 0, 0), -- 18896 (Area: 3557)
(@Guid2+3, 18896, 530, 1, 1,  -4103.18, -11406.13, -138.7481, 0.8203048, 120, 0, 0); -- 18896 (Area: 3557)
