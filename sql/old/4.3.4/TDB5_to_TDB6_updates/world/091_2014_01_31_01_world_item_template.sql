UPDATE `item_template` SET `spellcharges_1`=0 WHERE `spellcharges_1` IS NULL;
UPDATE `item_template` SET `spellcharges_2`=0 WHERE `spellcharges_2` IS NULL;
UPDATE `item_template` SET `spellcharges_3`=0 WHERE `spellcharges_3` IS NULL;
UPDATE `item_template` SET `spellcharges_4`=0 WHERE `spellcharges_4` IS NULL;
UPDATE `item_template` SET `spellcharges_5`=0 WHERE `spellcharges_5` IS NULL;

ALTER TABLE `item_template` CHANGE `spellcharges_1` `spellcharges_1` SMALLINT( 6 ) NOT NULL DEFAULT '0',
                            CHANGE `spellcharges_2` `spellcharges_2` SMALLINT( 6 ) NOT NULL DEFAULT '0',
                            CHANGE `spellcharges_3` `spellcharges_3` SMALLINT( 6 ) NOT NULL DEFAULT '0',
                            CHANGE `spellcharges_4` `spellcharges_4` SMALLINT( 6 ) NOT NULL DEFAULT '0',
                            CHANGE `spellcharges_5` `spellcharges_5` SMALLINT( 6 ) NOT NULL DEFAULT '0';
