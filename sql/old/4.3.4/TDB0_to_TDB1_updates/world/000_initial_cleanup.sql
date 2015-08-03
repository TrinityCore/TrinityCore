DELETE FROM `creature` WHERE `map` IN (0, 1);
DELETE FROM `creature_addon` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `pool_creature` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `creature_formations` WHERE `leaderGUID` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `creature_formations` WHERE `memberGUID` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `smart_scripts` WHERE `entryorguid` < 0 AND ABS(`entryorguid`) NOT IN (SELECT `guid` FROM `creature`);
DELETE `waypoint_data` FROM `waypoint_data` LEFT JOIN `creature_addon` ON `creature_addon`.`path_id` = `waypoint_data`.`id` WHERE `waypoint_data`.`id` IS NULL;
DELETE FROM `game_event_creature` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `game_event_model_equip` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `game_event_npc_vendor` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `game_event_npcflag` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);

DELETE FROM `linked_respawn` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `linked_respawn` WHERE `linkedGuid` NOT IN (SELECT `guid` FROM `creature`);

DELETE FROM `gameobject` WHERE `map` IN (0,1);
DELETE FROM `pool_gameobject` WHERE `guid` NOT IN (SELECT `guid` FROM `gameobject`);
DELETE FROM `game_event_gameobject` WHERE `guid` NOT IN (SELECT `guid` FROM `gameobject`);

DELETE FROM `spell_target_position` WHERE `target_map` IN (0, 1);

UPDATE `creature_template` SET `AIName`='' WHERE `AIName`='EventAI';

TRUNCATE `npc_trainer`;
TRUNCATE `spell_ranks`;
TRUNCATE `hotfix_data`;
TRUNCATE `disables`;
