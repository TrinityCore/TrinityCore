-- Cleaning the database of unused/obsolete data
DELETE FROM `game_event_creature` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `game_event_gameobject` WHERE `guid` NOT IN (SELECT `guid` FROM `gameobject`);
DELETE FROM `pool_pool` WHERE `mother_pool` NOT IN (SELECT `entry` FROM `pool_template`);
DELETE FROM `game_event_creature` WHERE `guid` IN (40267,40470,40471);
DELETE FROM `creature` WHERE `id` = 18963; -- Removed from game arround wow 2.2.x
