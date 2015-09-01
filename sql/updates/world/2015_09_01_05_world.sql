--
SET @GUID = 40153;
SET @OLDGUID = 19;
DELETE FROM `creature` WHERE `guid`=@GUID;
DELETE FROM `creature` WHERE `guid`=@OLDGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `modelid`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `curhealth`) VALUE
(@GUID,26712,600,3,17188,-341.31,-724.4,28.57,3.78,3600,8982);
