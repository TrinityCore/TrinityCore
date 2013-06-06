ALTER TABLE `spell_area` ADD COLUMN `quest_start_status` INT(11) NOT NULL DEFAULT 64; -- default is QUEST_STATUS_REWARDED
ALTER TABLE `spell_area` ADD COLUMN `quest_end_status` INT(11) NOT NULL DEFAULT 11; -- default is QUEST_STATUS_COMPLETE | QUEST_STATUS_NONE | QUEST_STATUS_INCOMPLETE
UPDATE spell_area SET `quest_start_status` = (1 << 6) | (1 << 3) | (1 << 1) WHERE `quest_start_active` = 1;
ALTER TABLE spell_area DROP COLUMN `quest_start_active`;