DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 184 AND 186;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(184,'Tempest Keep: The Arcatraz - Zereketh the Unbound',4),
(185,'Tempest Keep: The Arcatraz - Wrath-Scryer Soccothrates',4),
(186,'Tempest Keep: The Arcatraz - Harbinger Skyriss',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 184 AND 186;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(552,0,23,184,1),
(552,2,23,185,1),
(552,3,23,186,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 184 AND 186;
INSERT INTO `spawn_group` SELECT 184, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=79391 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 185, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=79398 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 186, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=79451 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(184,0,79391),
(185,0,79398),
(186,0,79451);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (79391,79398,79451);
