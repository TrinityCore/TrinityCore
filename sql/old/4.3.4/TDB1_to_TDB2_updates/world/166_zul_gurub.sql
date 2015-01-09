-- old Zul'Gurub
DELETE FROM `instance_template` WHERE `map`=309;
DELETE FROM `creature` WHERE `map`=309;
DELETE FROM `gameobject` WHERE `map`=309;
DELETE FROM `spell_target_position` WHERE `target_map`=309;

-- cleanup
DELETE FROM `creature_addon` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `pool_creature` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `creature_formations` WHERE `leaderGUID` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `creature_formations` WHERE `memberGUID` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `linked_respawn` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `linked_respawn` WHERE `linkedGuid` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `game_event_creature` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);
DELETE FROM `pool_gameobject` WHERE `guid` NOT IN (SELECT `guid` FROM `gameobject`);
DELETE FROM `game_event_gameobject` WHERE `guid` NOT IN (SELECT `guid` FROM `gameobject`);

-- new Zul'Gurub
UPDATE `instance_template` SET `script`='instance_zulgurub' WHERE `map`=859;

DELETE FROM `areatrigger_teleport` WHERE `id`=6775;
INSERT INTO `areatrigger_teleport` (`id`, `name`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(6775,'Zul''Gurub - Entrance',859,-11916,-1253.71,92.2921,4.712389);
