-- Strange Lockbox (Area: The Great Sea - Difficulty: 0) CreateObject1
UPDATE `gameobject` SET `position_x`=846.18243408203125, `position_y`=2207.689697265625, `position_z`=-136.863601684570312, `orientation`=1.710421562194824218, `rotation2`=0.754709243774414062, `rotation3`=0.656059443950653076, `VerifiedBuild`=63834 WHERE `guid`=27812 AND `id`=177844;
-- Strange Lockbox (Area: Longshore - Difficulty: 0) CreateObject1
UPDATE `gameobject` SET `position_x`=-10172.318359375, `position_y`=2389.10693359375, `position_z`=-138.893508911132812, `orientation`=1.605701684951782226, `rotation2`=0.719339370727539062, `rotation3`=0.694658815860748291, `VerifiedBuild`=63834 WHERE `guid`=27813 AND `id`=177790;
-- Strange Lockbox (Area: The Sludge Fen - Difficulty: 0) CreateObject1
UPDATE `gameobject` SET `position_x`=1050.55712890625, `position_y`=-3119.477783203125, `position_z`=71.33579254150390625, `orientation`=5.113816738128662109, `rotation2`=-0.55193614959716796, `rotation3`=0.833886384963989257, `VerifiedBuild`=63834 WHERE `guid`=13525 AND `id`=177794;
-- Bubbling Fissure (Area: The Sludge Fen - Difficulty: 0) CreateObject1
UPDATE `gameobject` SET `position_x`=1051.40625, `position_y`=-3111.5400390625, `position_z`=71.1983795166015625, `orientation`=3.141472816467285156, `rotation0`=0.142999649047851562, `rotation1`=-0.08195018768310546, `rotation2`=0.9862518310546875, `rotation3`=0.01194044854491949, `VerifiedBuild`=63834 WHERE `guid`=14532 AND `id`=3740;
-- Missing Bubbly Fissure
SET @OGUID=9954; -- 2 free guid
DELETE FROM `gameobject` WHERE `guid` IN (@OGUID,@OGUID+1) AND `id`=177524;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@OGUID, 177524, 0, 0, 0, 1, 1, 840.74407958984375, 2208.327392578125, -136.857894897460937, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, '', NULL, 63834), -- Bubbly Fissure (Area: The Great Sea - Difficulty: 0) CreateObject1
(@OGUID+1, 177524, 0, 0, 0, 1, 1, -10168.6826171875, 2389.03076171875, -139.214340209960937, 0.453785061836242675, 0, 0, 0.224950790405273437, 0.974370121955871582, 120, 255, 1, '', NULL, 63834); -- Bubbly Fissure (Area: Longshore - Difficulty: 0) CreateObject1
