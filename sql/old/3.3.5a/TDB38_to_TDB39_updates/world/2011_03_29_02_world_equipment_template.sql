UPDATE `creature_template` SET `equipment_id`=682 WHERE `entry`=32417; -- Scarlet Highlord Daion
-- Re-import deleted template
DELETE FROM `creature_equip_template` WHERE `entry`=2433;
INSERT INTO `creature_equip_template` (`entry`,`equipentry1`,`equipentry2`,`equipentry3`) VALUES
(2433,19903,13319,0);
