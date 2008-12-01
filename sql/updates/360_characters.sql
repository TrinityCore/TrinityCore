ALTER TABLE arena_team_member CHANGE played_week games_week int(10) unsigned NOT NULL default '0';
ALTER TABLE arena_team_member CHANGE wons_week wins_week int(10) unsigned NOT NULL default '0';
ALTER TABLE arena_team_member CHANGE played_season games_season int(10) unsigned NOT NULL default '0';
ALTER TABLE arena_team_member CHANGE wons_season wins_season int(10) unsigned NOT NULL default '0';