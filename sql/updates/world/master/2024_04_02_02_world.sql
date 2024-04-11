SET @CGUID := 3000073;
SET @SPAWNGROUP := 1242;

UPDATE `creature` SET `guid`=@CGUID+1 WHERE `guid`=@CGUID+55;
UPDATE `creature` SET `guid`=@CGUID+2 WHERE `guid`=@CGUID+56;
UPDATE `creature` SET `guid`=@CGUID+3 WHERE `guid`=@CGUID+57;
UPDATE `creature` SET `guid`=@CGUID+4 WHERE `guid`=@CGUID+334;
UPDATE `creature` SET `guid`=@CGUID+5 WHERE `guid`=@CGUID+335;
UPDATE `creature` SET `guid`=@CGUID+6 WHERE `guid`=@CGUID+500;
UPDATE `creature` SET `guid`=@CGUID+7 WHERE `guid`=@CGUID+501;
UPDATE `creature` SET `guid`=@CGUID+8 WHERE `guid`=@CGUID+502;

UPDATE `spawn_group` SET `spawnId`=@CGUID+1 WHERE `groupId`=@SPAWNGROUP+0 AND `spawnId`=@CGUID+55;
UPDATE `spawn_group` SET `spawnId`=@CGUID+4 WHERE `groupId`=@SPAWNGROUP+0 AND `spawnId`=@CGUID+334;
UPDATE `spawn_group` SET `spawnId`=@CGUID+5 WHERE `groupId`=@SPAWNGROUP+0 AND `spawnId`=@CGUID+335;
UPDATE `spawn_group` SET `spawnId`=@CGUID+6 WHERE `groupId`=@SPAWNGROUP+0 AND `spawnId`=@CGUID+500;
UPDATE `spawn_group` SET `spawnId`=@CGUID+7 WHERE `groupId`=@SPAWNGROUP+0 AND `spawnId`=@CGUID+501;
UPDATE `spawn_group` SET `spawnId`=@CGUID+8 WHERE `groupId`=@SPAWNGROUP+0 AND `spawnId`=@CGUID+502;
