-- Remove Wendigo npc underground spawned
DELETE FROM `creature` WHERE `guid`=3564 AND `id`=1135;
-- Remove from spawn_group too
DELETE FROM `spawn_group` WHERE `spawnType`=0 AND `spawnId`=3564;
