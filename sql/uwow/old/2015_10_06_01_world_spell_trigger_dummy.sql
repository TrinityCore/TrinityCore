ALTER TABLE `spell_trigger_dummy`   
  DROP COLUMN `group`, 
  DROP COLUMN `check_spell_id`;

RENAME TABLE `spell_trigger_dummy` TO `spell_dummy_trigger`;

UPDATE `spell_dummy_trigger` SET `option` = 2 WHERE `option` = 4;
UPDATE `spell_dummy_trigger` SET `option` = 3 WHERE `option` = 13;
UPDATE `spell_dummy_trigger` SET `option` = 4 WHERE `option` = 14;
UPDATE `spell_dummy_trigger` SET `option` = 5 WHERE `option` = 15;
UPDATE `spell_dummy_trigger` SET `option` = 6 WHERE `option` = 20;
UPDATE `spell_dummy_trigger` SET `option` = 7 WHERE `option` = 38;
