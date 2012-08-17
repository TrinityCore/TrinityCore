DROP TABLE IF EXISTS `guild_xp_for_level`;
CREATE TABLE `guild_xp_for_level` (
  `lvl` int(11) NOT NULL,
  `xp_for_next_level` bigint(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1
 -- Needs data fill