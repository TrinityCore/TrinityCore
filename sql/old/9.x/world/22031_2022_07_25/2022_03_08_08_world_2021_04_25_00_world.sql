-- delete non generic spell script for npc_wild_wyrm
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_eject_passenger_wild_wyrm';

-- add "special" generic spell script for "Eject Passenger 1"
-- the spell script "spell_eject_passenger_wild_wyrm" used this spell too
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_gen_eject_passenger_1';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(60603, 'spell_gen_eject_passenger_1');

-- add "special" generic spell script for "Eject Passenger 3"
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_gen_eject_passenger_3';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(52205, 'spell_gen_eject_passenger_3');
