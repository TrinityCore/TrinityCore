DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 179 AND 183;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(179,'Coilfang: Serpentshrine Cavern - Hydross the Unstable',4),
(180,'Coilfang: Serpentshrine Cavern - The Lurker Below',4),
(181,'Coilfang: Serpentshrine Cavern - Leotheras the Blind',4),
(182,'Coilfang: Serpentshrine Cavern - Fathom-Lord Karathress',4),
(183,'Coilfang: Serpentshrine Cavern - Morogrim Tidewalker',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 179 AND 183;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(547,0,23,179,1),
(547,1,23,180,1),
(547,2,23,181,1),
(547,3,23,182,1),
(547,4,23,183,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 179 AND 183;
INSERT INTO `spawn_group` SELECT 179, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=93846 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 180, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=93838 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 181, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=93773 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 182, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=93766 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 183, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=82974 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(179,0,93846),
(180,0,93838),
(181,0,93773),
(182,0,93766),
(183,0,82974);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (93846,93838,93773,93766,82974);
