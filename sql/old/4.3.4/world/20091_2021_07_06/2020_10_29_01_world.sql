UPDATE `creature_template` SET `ScriptName`= 'npc_scarlet_commander_mograine' WHERE `entry`= 3976;
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry`= 3976;

UPDATE `creature_template` SET `ScriptName`= 'npc_high_inquisitor_whitemane', `minlevel`= 40, `maxlevel`= 40 WHERE `entry`= 3977;

DELETE FROM `spawn_group_template` WHERE `groupId`= 451;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(451, 'The Scarlet Monastery - Mograine and Whitemane', 4);

DELETE FROM `spawn_group` WHERE `groupId`= 451;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(451, 0, 39946),
(451, 0, 40029);
