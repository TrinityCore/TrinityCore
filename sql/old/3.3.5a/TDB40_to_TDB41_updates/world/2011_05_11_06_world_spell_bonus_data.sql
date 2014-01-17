UPDATE `spell_bonus_data` SET `direct_bonus` = -1 WHERE `entry` = 27243;
DELETE FROM `spell_bonus_data` WHERE `entry` = 27285;
INSERT INTO `spell_bonus_data` VALUES (27285, 0.2129, -1, -1, -1,'Warlock - Seed of Corruption Proc');
