-- delete wrong spawnId (duplicate)
DELETE FROM `gameobject` WHERE `guid`=21587;
DELETE FROM `gameobject_addon` WHERE `guid`=21587;
DELETE FROM `pool_members` WHERE `spawnId`=21587;
DELETE FROM `spawn_group` WHERE `spawnId`=21587 AND `spawnType`=1;
