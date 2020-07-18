-- 
DELETE FROM `creature` WHERE  `guid` IN (146055,146013) AND `id` IN (478,97);
DELETE FROM `spawn_group` WHERE  `spawnid` IN (146055,146013) AND `spawnType`=0;
