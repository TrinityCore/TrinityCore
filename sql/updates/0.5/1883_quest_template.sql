ALTER TABLE `quest_template`
    ADD COLUMN `QuestSort` int(11) unsigned NOT NULL default '0' AFTER `ZoneId`;
