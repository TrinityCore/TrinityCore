-- Gymer
DELETE FROM `creature_template_addon` WHERE `entry`=29647;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`) VALUES (29647,1,0);
-- Gerk
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry`=29455;
