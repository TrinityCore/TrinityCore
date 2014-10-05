ALTER TABLE `guild_xp_for_level`
  CHANGE `lvl` `lvl` TINYINT(3) UNSIGNED NOT NULL,
  CHANGE `xp_for_next_level` `xp_for_next_level` INT(10) UNSIGNED NOT NULL;
