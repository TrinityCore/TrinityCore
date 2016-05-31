-- Old spawns
DELETE FROM `creature` WHERE `map`=568;
DELETE FROM `gameobject` WHERE `map`=568;
DELETE FROM `spell_target_position` WHERE `target_map`=568;


-- Cleanup
DELETE FROM `creature_addon` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `pool_creature` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `creature_formations` WHERE `leaderGUID` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `creature_formations` WHERE `memberGUID` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `linked_respawn` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `linked_respawn` WHERE `linkedGuid` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `game_event_creature` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `pool_gameobject` WHERE `guid` NOT IN (SELECT `guid` FROM `gameobject`);
DELETE FROM `game_event_gameobject` WHERE `guid` NOT IN (SELECT `guid` FROM `gameobject`);
