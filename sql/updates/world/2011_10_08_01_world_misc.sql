DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 23881;
DELETE FROM `spell_bonus_data` WHERE `entry` = 23880;
INSERT INTO `spell_bonus_data` VALUES (23880, 0, -1, -1, -1, 'Bloodthirst');
