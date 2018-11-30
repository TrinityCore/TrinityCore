DELETE FROM `lfg_dungeon_template` WHERE `dungeonId` IN (30, 276);
INSERT INTO `lfg_dungeon_template` (`dungeonId`, `name`, `position_x`, `position_y`, `position_z`, `orientation`, `VerifiedBuild`) VALUES
(30,  'Blackrock Depths - Prison',     456.929, 34.0923, -68.0896, 4.712389, 11159),
(276, 'Blackrock Depths - Upper City', 456.929, 34.0923, -68.0896, 4.712389, 11159);
