-- Some Spell focus corrections
-- Signal Fire 
SET @GUID :=208; -- 4.x guid
DELETE FROM `gameobject` WHERE `guid`=@GUID;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GUID,194151,571,1,1,4061.978,7109.135,170.0001,0,0,0,0,1,120,255,1);

DELETE FROM `gameobject_template` WHERE `entry`=300242;

-- Shrine Of Remulos
UPDATE `gameobject` SET `id`=15885 WHERE `id`=300142;
DELETE FROM `gameobject_template` WHERE `entry`=300142;

-- Witherbark Village
UPDATE `gameobject` SET `id`=142698 WHERE `id`=300016;
DELETE FROM `gameobject_template` WHERE `entry`=300016;

-- Maraudon Portal 
UPDATE `gameobject` SET `id`=178400 WHERE `id`=300037;
DELETE FROM `gameobject_template` WHERE `entry`=300037;

-- Scorched Grove Runeston
UPDATE `gameobject` SET `id`=181260 WHERE `id`=300086;
DELETE FROM `gameobject_template` WHERE `entry`=300086;
