-- 23881 Bloodthirst (damage spell)
-- 23885 Bloodthirst (buff)
-- 23880 Bloodthirst (triggered heal)

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 23881;
INSERT INTO `spell_linked_spell` VALUES (23881, 23885, 0, 'Bloodthirst');

DELETE FROM `spell_bonus_data` WHERE `entry` = 23880;
INSERT INTO `spell_bonus_data` VALUES (23880, 0, -1, -1, -1, 'Bloodthirst');
