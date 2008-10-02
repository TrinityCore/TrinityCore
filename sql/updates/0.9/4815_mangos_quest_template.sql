ALTER TABLE `quest_template`
    CHANGE COLUMN `SpecialFlags` `QuestFlags` int(11) unsigned NOT NULL default '0';
UPDATE `quest_template` SET `QuestFlags`=`QuestFlags`&4096;
