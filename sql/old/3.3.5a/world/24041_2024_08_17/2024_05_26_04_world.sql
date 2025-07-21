-- Remove wrong spawned Raging Owlbeast and Zhevra Runner
DELETE FROM `creature` WHERE `guid` IN (41372,18658) AND `id` IN (7451,3242);
DELETE FROM `spawn_group` WHERE `spawnId` IN (41372,18658);
