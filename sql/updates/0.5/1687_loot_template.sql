ALTER TABLE `loot_template`
    ADD `questchance` float NOT NULL default '0';

UPDATE `loot_template` SET `questchance` = 100 WHERE `chance` = 0;
