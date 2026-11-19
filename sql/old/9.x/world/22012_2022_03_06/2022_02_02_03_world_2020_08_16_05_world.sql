--
DELETE FROM `spawn_group` WHERE `spawnType` = 1 AND `groupId` = 2 AND `spawnId` IN (SELECT `guid` FROM `gameobject` WHERE `spawntimesecs` < 0);
