-- Spawn Tribunal Chest in heroic HoS mode and correct wrong spawnmasks
SET @GUID = 151790; -- Set by TDB team (need 1)
UPDATE `gameobject` SET `spawnMask`=1 WHERE `guid`=65564; -- Tribunal Chest non heroic
DELETE FROM `gameobject` WHERE `id`=193996;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`)VALUES
(@GUID,193996,599,2,1,880.406,345.164,203.706,0,0,0,0,1,180,0,1); -- Tribunal Chest heroic
UPDATE `gameobject_template` SET `faction`=94, `flags`=4 /* should be 4 and nothing else (temp) */ WHERE `entry` IN (193996,190586);
