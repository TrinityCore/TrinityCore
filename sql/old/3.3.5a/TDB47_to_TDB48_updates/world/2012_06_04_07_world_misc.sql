-- Add Missing spell to Jotunheim Rapid-Fire Harpoon close 6435
UPDATE `creature_template` SET `spell1`=56585 WHERE `entry`=30337;
-- Wailing Winds missing aura
UPDATE `creature_template_addon` SET `auras`='56769' WHERE `entry`=30450;
-- Disturbed Taunka Ancestor missing aura
DELETE FROM `creature_template_addon` WHERE `entry`=30458;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (30458,1,43167);
