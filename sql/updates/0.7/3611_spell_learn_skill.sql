-- Add spell_skill for riding 225 and 300 skill
DELETE FROM `spell_learn_skill` WHERE `entry` IN ('34091', '34090');
INSERT INTO `spell_learn_skill` VALUES ('34091', '762', '300', '300');
INSERT INTO `spell_learn_skill` VALUES ('34090', '762', '225', '225');

