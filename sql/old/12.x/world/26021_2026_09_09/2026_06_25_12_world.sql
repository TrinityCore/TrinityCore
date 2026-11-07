UPDATE `gameobject` SET `guid`=`guid`-23298+24613 WHERE `guid` BETWEEN 23298 AND 23313;
UPDATE `spawn_group` SET `spawnId`=`spawnId`-23298+24613 WHERE `spawnType`=1 AND `spawnId` BETWEEN 23298 AND 23313;
