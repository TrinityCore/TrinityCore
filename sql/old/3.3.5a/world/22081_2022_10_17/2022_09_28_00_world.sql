DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 299 AND 303;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(299,'Ahn''Qiraj Temple - Twin Emperors',4),
(300,'Ahn''Qiraj Temple - C''Thun',4),
(301,'Ahn''Qiraj Temple - Silithid Royalty',4),
(302,'Ahn''Qiraj Temple - Viscidus',4),
(303,'Ahn''Qiraj Temple - Ouro',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 299 AND 303;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(531,4,23,299,1),
(531,5,23,300,1),
(531,6,23,301,1),
(531,7,23,302,1),
(531,8,23,303,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 299 AND 303;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(299,0,88072),
(299,0,88076),
(299,0,88077),
(300,0,87560),
(300,0,87559),
(300,0,4458),
(301,0,87601),
(301,0,87602),
(301,0,87603),
(302,0,87938),
(303,0,88073);
