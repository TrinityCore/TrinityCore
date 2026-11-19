-- 
DELETE FROM `gameobject` WHERE `guid` IN (71449,71450) AND `id` IN (190717,190719);
DELETE FROM `spawn_group` WHERE `spawnType`=1 AND `SpawnId` IN (71449,71450);
