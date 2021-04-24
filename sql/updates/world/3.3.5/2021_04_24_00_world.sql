-- delete non generic spell script for wild wyrm
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_eject_passenger_wild_wyrm';

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_gen_eject_passenger_1';
-- add "special" generic for "Eject Passenger 1", "spell_eject_passenger_wild_wyrm" used this too
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(60603, 'spell_gen_eject_passenger_1');

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_gen_eject_passenger_3';
-- add "special" generic for "Eject Passenger 3"
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(52205, 'spell_gen_eject_passenger_3');