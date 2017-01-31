TRUNCATE `player_xp_for_level`;

ALTER TABLE `player_xp_for_level`
  CHANGE `lvl` `Level` TINYINT(3) UNSIGNED NOT NULL,
  CHANGE `xp_for_next_level` `Experience` FLOAT UNSIGNED NOT NULL;
