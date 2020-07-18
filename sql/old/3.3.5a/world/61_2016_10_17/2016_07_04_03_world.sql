-- 
UPDATE `creature_template` SET `VehicleId`=732, `unit_flags`=33554432, `InhabitType`=4 WHERE `entry`=40246;

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (74890, -75731);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(74890, 75055, 0, "Instant Statue"),
(-75731, -75055, 0, "Instant Statue"),
(-75731, -74890, 0, "Instant Statue");

DELETE FROM `spell_custom_attr` WHERE `entry`=75731;
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(75731, 4096);
