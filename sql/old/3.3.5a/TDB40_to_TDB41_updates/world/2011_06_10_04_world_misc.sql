DELETE FROM `vehicle_template_accessory` WHERE `entry` = 31269;
INSERT INTO `vehicle_template_accessory` VALUES
(31269, 27559, 0, 0, 'Kor''kron Battle Wyvern', 6, 300);
DELETE FROM `creature` WHERE `id` = 27559;
UPDATE `creature_template` SET `InhabitType` = 1 WHERE `entry` = 27559;
