DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN 242 AND 245;
INSERT INTO `spawn_group_template` (`groupId`,`groupName`,`groupFlags`) VALUES
(242,'Halls of Stone - Krystallus',4),
(243,'Halls of Stone - Maiden of Grief',4),
(244,'Halls of Stone - Tribunal of Ages',4),
(245,'Halls of Stone - Sjonnir the Ironshaper',4);

DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` BETWEEN 242 AND 245;
INSERT INTO `instance_spawn_groups` (`instanceMapId`,`bossStateId`,`bossStates`,`spawnGroupId`,`flags`) VALUES
(599,0,23,242,1),
(599,1,23,243,1),
(599,2,23,244,1),
(599,3,23,245,1);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 242 AND 245;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(242,0,126790),
(243,0,126789),
(244,0,126743),
(244,0,126742),
(244,0,126737),
(244,0,126733),
(244,0,126738),
(244,0,126745),
(244,0,126744),
(244,0,126739),
(244,0,126815),
(244,0,126816),
(244,0,126817),
(244,0,126801),
(244,0,126800),
(244,0,126746),
(244,0,126749),
(244,0,126750),
(244,1,65564),
(244,1,151790),
(245,0,126792);

DELETE FROM `linked_respawn` WHERE `linkedGuid` IN (126790,126789,126792);
