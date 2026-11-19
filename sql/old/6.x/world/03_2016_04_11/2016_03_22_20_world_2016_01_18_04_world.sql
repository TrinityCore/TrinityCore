--
DELETE FROM `creature` WHERE id=27535;
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (27761);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `minion`, `description`, `summontype`) VALUES (27761, 27535,1, "Fordragon Battle Steed", 7);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=27761;
