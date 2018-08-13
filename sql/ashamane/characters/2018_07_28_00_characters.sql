ALTER TABLE `pvpstats_players`
  CHANGE `score_killing_blows` `score_killing_blows` int(10) unsigned NOT NULL,
  CHANGE `score_deaths` `score_deaths` int(10) unsigned NOT NULL,
  CHANGE `score_honorable_kills` `score_honorable_kills` int(10) unsigned NOT NULL,
  CHANGE `score_bonus_honor` `score_bonus_honor` int(10) unsigned NOT NULL,
  CHANGE `score_damage_done` `score_damage_done` int(10) unsigned NOT NULL,
  CHANGE `score_healing_done` `score_healing_done` int(10) unsigned NOT NULL,
  CHANGE `attr_1` `attr_1` int(10) unsigned NOT NULL,
  CHANGE `attr_2` `attr_2` int(10) unsigned NOT NULL,
  CHANGE `attr_3` `attr_3` int(10) unsigned NOT NULL,
  CHANGE `attr_4` `attr_4` int(10) unsigned NOT NULL,
  CHANGE `attr_5` `attr_5` int(10) unsigned NOT NULL;
