DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 187 AND 191;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(187,'Tempest Keep: The Botanica - Commander Sarannis',4),
(188,'Tempest Keep: The Botanica - High Botanist Freywinn',4),
(189,'Tempest Keep: The Botanica - Thorngrin the Tender',4),
(190,'Tempest Keep: The Botanica - Laj',4),
(191,'Tempest Keep: The Botanica - Warp Splinter',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 187 AND 191;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(553,0,23,187,1),
(553,1,23,188,1),
(553,2,23,189,1),
(553,3,23,190,1),
(553,4,23,191,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 187 AND 191;
INSERT INTO `spawn_group` SELECT 187, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=82986 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 188, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=82987 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 189, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=83076 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 190, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=82989 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 191, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=82990 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(187,0,82986),
(188,0,82987),
(189,0,83076),
(190,0,82989),
(191,0,82990);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (82986,82987,83076,82989,82990);
