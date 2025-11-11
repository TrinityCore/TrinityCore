--
DELETE FROM `pool_members` WHERE `type`=1 AND `spawnId` IN (163412,163812,164212);
DELETE FROM `pool_members` WHERE `type`=2 AND `spawnId`=11612;
DELETE FROM `spawn_group` WHERE `spawnType`=1 AND `spawnId` IN (163412,163812,164212);
DELETE FROM `gameobject` WHERE `guid` IN (163412,163812,164212);
