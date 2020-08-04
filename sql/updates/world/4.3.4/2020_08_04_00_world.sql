UPDATE `creature_template` SET `ScriptName`= 'npc_end_time_nozdormu' WHERE `entry`= 54751;

DELETE FROM `spawn_group_template` WHERE `groupId` IN (437, 438);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(437, 'End Time - Murozond Chest', 4),
(438, 'End Time - Murozond Trash Pack', 4);

DELETE FROM `spawn_group` WHERE `groupId` IN (437, 438);
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(437, 1, 212782),
(438, 0, 341660),
(438, 0, 341662),
(438, 0, 341661),
(438, 0, 341659),
(438, 0, 341673),
(438, 0, 341658),
(438, 0, 341656),
(438, 0, 341657);

DELETE FROM `creature` WHERE `guid`= 320247;
DELETE FROM `creature_addon` WHERE `guid`= 320247;

UPDATE `creature` SET `modelid`= 38754 WHERE `id`= 54751;

DELETE FROM `creature_onkill_reward` WHERE `creature_id`= 54432;
INSERT INTO `creature_onkill_reward` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `RewOnKillRepValue1`, `CurrencyId1`, `CurrencyCount1`) VALUES
(54432, 1162, 7, 250, 395, 7000);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId`= 438;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
(938, 4, 17, 438, 1); -- Enable group when Murozond is not DONE
