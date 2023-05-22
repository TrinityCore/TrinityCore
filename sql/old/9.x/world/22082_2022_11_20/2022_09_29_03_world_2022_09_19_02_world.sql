DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 145 AND 148;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(145,'Ahn''Qiraj Temple - The Prophet Skeram',4),
(146,'Ahn''Qiraj Temple - Battleguard Sartura',4),
(147,'Ahn''Qiraj Temple - Fankriss the Unyielding',4),
(148,'Ahn''Qiraj Temple - Princess Huhuran',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 145 AND 148;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(531,0,23,145,1),
(531,1,23,146,1),
(531,2,23,147,1),
(531,3,23,148,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 145 AND 148;
INSERT INTO `spawn_group` SELECT 145, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=88075 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 146, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=87648 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 147, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=87911 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 148, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=88014 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(145,0,88075),
(146,0,87648),
(147,0,87911),
(148,0,88014);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (88075,87648,87911,88014);
