UPDATE creature_template SET VehicleId = 312 WHERE entry IN (31857,31858,31861,31862,32212,32213,32633,32640);
UPDATE creature_template SET VehicleId = 174 WHERE entry IN (31125,31722);

DELETE FROM `spell_linked_spell` WHERE spell_trigger IN (58666,60882);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
( 58666, 58672, 1, 'Impale (Archavon)'),
( 60882, 58672, 1, 'Impale (Archavon)');

DELETE FROM `spell_script_target` WHERE entry IN
(58672);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(58672, 1, 31125);