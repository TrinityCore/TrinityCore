-- 
UPDATE `creature_equip_template` SET `ItemID3`=29010 WHERE `CreatureID`=23956;

DELETE FROM `spell_custom_attr` WHERE `entry` IN (42772, 59685);
INSERT INTO `spell_custom_attr` (`entry`,`attributes`) VALUES
(42772, 0x80000),
(59685, 0x80000);
