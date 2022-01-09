DELETE FROM `instance_spawn_groups` WHERE `spawnGroupId` IN (409, 410);
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
(36, 4, 0x1 | 0x2 | 0x4 | 0x8, 409, 0x1 | 0x4),
(36, 4, 0x1 | 0x2 | 0x4 | 0x8, 410, 0x1 | 0x8);
