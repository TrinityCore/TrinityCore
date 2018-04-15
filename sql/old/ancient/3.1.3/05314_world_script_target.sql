DELETE FROM `spell_script_target` WHERE `entry` IN (62427,62374,62399);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(62427, 1, 33109), # Load into Catapult
(62374, 1, 33060), # Pursued
(62374, 1, 33109),
(62399, 1, 33139); # Overload Circuit
