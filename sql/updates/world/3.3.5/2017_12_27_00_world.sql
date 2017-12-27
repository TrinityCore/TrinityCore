-- Restore deleted pool
SET @POOL_1 := 382;

DELETE FROM `pool_template` WHERE `entry`=@POOL_1;
INSERT INTO `pool_template` VALUES 
(@POOL_1, 1, "Eye of DarKhan/Wailer Spawn 1");

DELETE FROM `pool_creature` WHERE `guid` IN (82897, 85744);
INSERT INTO `pool_creature` VALUES 
(82897, @POOL_1, 0, "Wailer Spawn 1"),
(85744, @POOL_1, 0, "Eye of DarKhan Spawn 1");
