--
DELETE FROM `pool_members` WHERE `type` = 1 AND `spawnId` IN (16022,15968);
DELETE FROM `spawn_group` WHERE `spawnType` = 1 AND `spawnId` IN (16022,15968);
DELETE FROM `gameobject_addon` WHERE `guid` IN (16022,15968);
DELETE FROM `gameobject` WHERE `guid` IN (16022,15968) AND `id` = 142141;
