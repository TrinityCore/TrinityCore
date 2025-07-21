-- LFGDungeonsEntry changed from "Scarlet Monastery - Armory" in 4.x to "Scarlet Halls" in 5.x, coords are invalid on new map
DELETE FROM `lfg_dungeon_template` WHERE `dungeonId` = 163;

-- LFGDungeonsEntry changed from "Scarlet Monastery - Cathedral" to "Scarlet Monastery" in 5.x, coords are invalid on new map
DELETE FROM `lfg_dungeon_template` WHERE `dungeonId` = 164;

-- Fix LFG entrance for dungeons that have multiple entrances
DELETE FROM `lfg_dungeon_template` WHERE `dungeonId` IN (14, 22, 276);
INSERT INTO `lfg_dungeon_template` (`dungeonId`, `name`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(14, 'Gnomeregan', -329.484, -3.22991, -152.846, 2.9670597284),
(22, 'Uldaman', -228.859, 46.1018, -46.0186, 1.5707963268),
(276, 'Blackrock Depths - Upper City', 926.904, -288.134, -49.9401, 1.1140925308);
