ALTER TABLE guild_member ADD COLUMN profId1 smallint(5) unsigned NOT NULL DEFAULT '0' AFTER AchPoint;
ALTER TABLE guild_member ADD COLUMN profValue1 smallint(5) unsigned NOT NULL DEFAULT '0' AFTER profId1;
ALTER TABLE guild_member ADD COLUMN profRank1 smallint(5) unsigned NOT NULL DEFAULT '0' AFTER profValue1;

ALTER TABLE guild_member ADD COLUMN profId2 smallint(5) unsigned NOT NULL DEFAULT '0' AFTER profRank1;
ALTER TABLE guild_member ADD COLUMN profValue2 smallint(5) unsigned NOT NULL DEFAULT '0' AFTER profId2;
ALTER TABLE guild_member ADD COLUMN profRank2 smallint(5) unsigned NOT NULL DEFAULT '0' AFTER profValue2;
