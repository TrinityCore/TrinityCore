-- Remove 2 incorrect permanent spawns belonging to a scripted quest event
DELETE FROM `creature` WHERE `id` = 22102 AND `guid` IN (86101, 86102);
