ALTER TABLE custom_texts CHANGE COLUMN emote emote smallint(5) unsigned NOT NULL DEFAULT '0';
ALTER TABLE script_texts CHANGE COLUMN emote emote smallint(5) unsigned NOT NULL DEFAULT '0';
