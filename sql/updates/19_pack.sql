ALTER TABLE `quest_template` ADD COLUMN `Method` tinyint(3) unsigned NOT NULL default '2' AFTER `entry`;
DELETE FROM mangos_string WHERE entry IN (331);
INSERT INTO mangos_string VALUES
(331,'Extended item cost %u not exist',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
