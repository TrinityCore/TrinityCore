DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 195 AND 198;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(195,'Auchindoun: Shadow Labyrinth - Ambassador Hellmaw',4),
(196,'Auchindoun: Shadow Labyrinth - Blackheart the Inciter',4),
(197,'Auchindoun: Shadow Labyrinth - Grandmaster Vorpil',4),
(198,'Auchindoun: Shadow Labyrinth - Murmur',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 195 AND 198;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(555,0,23,195,1),
(555,1,23,196,1),
(555,2,23,197,1),
(555,3,23,198,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 195 AND 198;
INSERT INTO `spawn_group` SELECT 195, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=66999 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 196, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=66937 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 197, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=67000 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 198, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=66952 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(195,0,66999),
(196,0,66937),
(197,0,67000),
(198,0,66952);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (66999,66937,67000,66952);
