DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 224 AND 225;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(224,'Utgarde Pinnacle - Svala Sorrowgrave',4),
(225,'Utgarde Pinnacle - King Ymiron',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 224 AND 225;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(575,0,23,224,1),
(575,3,23,225,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 224 AND 225;
INSERT INTO `spawn_group` SELECT 224, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=126115 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 225, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=126255 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(224,0,126115),
(225,0,126255);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (126115,126255);
