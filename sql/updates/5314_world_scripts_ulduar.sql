UPDATE creature_template SET scriptname = "spell_pool_of_tar" WHERE entry = 33090;

DELETE FROM `spell_script_target` WHERE `entry` IN (62427,62374,62399);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(62427, 1, 33109), # Load into Catapult
(62374, 1, 33060), # Pursued
(62374, 1, 33109),
(62399, 1, 33139); # Overload Circuit

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-62475,62427);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-62475,-62399, 0, 'System Shutdown'),
(-62475, 62472, 0, 'System Shutdown'), #inform, not correct spell
( 62427, 62340, 2, 'Load into Catapult - Passenger Loaded');