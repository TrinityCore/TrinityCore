--
DELETE FROM `terrain_swap_defaults` WHERE `MapId` IN (1,654);
INSERT INTO `terrain_swap_defaults` (`MapId`, `TerrainSwapMap`, `Comment`) VALUES
(1, 719, 'Mount Hyjal default terrain'),
(654, 638, 'Gilneas default terrain');
