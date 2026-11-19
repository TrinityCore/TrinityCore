-- Proper respawn time for a lot of mobs and delete incorrectly spawned mobs
DELETE FROM `creature` WHERE `id` IN (14397,15718);
UPDATE `creature` SET `spawntimesecs`=7200 WHERE (`map` IN (209,329,429,469,509,531) AND `spawntimesecs` IN (3520,3300,1800,1650)) OR `id` IN (12129,32593); 
