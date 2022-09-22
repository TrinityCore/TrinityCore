DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 228 AND 231;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(228,'The Oculus - Drakos the Interrogator',4),
(229,'The Oculus - Varos Cloudstrider',4),
(230,'The Oculus - Mage-Lord Urom',4),
(231,'The Oculus - Ley-Guardian Eregos',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 228 AND 231;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(578,0,23,228,1),
(578,1,23,229,1),
(578,2,23,230,1),
(578,3,23,231,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 228 AND 231;
INSERT INTO `spawn_group` SELECT 228, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=100172 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 229, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=100235 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 230, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=100220 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` SELECT 231, 0, `guid` FROM `linked_respawn` WHERE `linkedGuid`=100221 AND `linkType` IN (0,3);
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(228,0,100172),
(229,0,100235),
(230,0,100220),
(231,0,100221);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (100172,100235,100220,100221);
