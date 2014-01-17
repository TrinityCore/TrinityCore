ALTER TABLE `spell_target_position` ADD COLUMN `effIndex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `id`;
ALTER TABLE `spell_target_position` DROP INDEX `PRIMARY`, ADD PRIMARY KEY (`id`, `effIndex`);
 
UPDATE `spell_target_position` SET `effIndex`='1' WHERE `id` IN (53821, 68081, 46473, 73655, 72546, 72340, 67838, 67835, 67836, 67837, 67834, 49098, 49097, 54963, 11012, 8606);
UPDATE `spell_target_position` SET `effIndex`='2' WHERE `id` IN (36801, 71765, 71763, 71762, 71744, 71712, 71751, 43209, 51852);
