-- Spellscripts ToCR
DELETE FROM `spell_script_names` WHERE `spell_id` IN (67590,67602,67603,67604) AND `ScriptName`='spell_powering_up';
DELETE FROM `spell_script_names` WHERE `spell_id` IN (66316,67100,67101,67102) AND `ScriptName`='spell_spinning_pain_strike';
DELETE FROM `spell_script_names` WHERE `spell_id` = 68576 AND `ScriptName` = 'spell_eject_all_passengers';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(66316, 'spell_spinning_pain_strike'),
(67100, 'spell_spinning_pain_strike'),
(67101, 'spell_spinning_pain_strike'),
(67102, 'spell_spinning_pain_strike'),
(68576, 'spell_eject_all_passengers'),
(67590, 'spell_powering_up'),
(67602, 'spell_powering_up'),
(67603, 'spell_powering_up'),
(67604, 'spell_powering_up');
-- Increase loot bosses ToCR
UPDATE creature_loot_template SET `maxcount` = 4 WHERE `item` IN (1, 2) AND `entry` IN
(35448, -- Icehowl 25N
 35449, -- Icehowl 25H
 35268, -- Jaraxxus 25N
 35269, -- Jaraxxus 25H
 35351, -- Fjola 25N
 35352, -- Fjola 25H
 35348, -- Eydis 25N
 35349, -- Eydis 25H
 35615, -- Anub'arak 25N
 35616); -- Anub'arak 25H

-- Increase loot champions cache ToCR
UPDATE gameobject_loot_template SET `maxcount` = 4 WHERE `item` IN (1, 2) AND `entry` IN
(27503, -- Champions Cache 25N
 27356);  -- Champions Cache 25H
 
-- Increase chance de drop de recipes bosses ToCR
UPDATE creature_loot_template SET `ChanceOrQuestChance` = 5, `maxcount` = 2 WHERE `item` IN (3, 4) AND `entry` IN
(35447, -- Icehowl 10H
 35448, -- Icehowl 25N
 35449, -- Icehowl 25H
 35216, -- Jaraxxus 10H
 35268, -- Jaraxxus 25N
 35269, -- Jaraxxus 25H
 35350, -- Fjola 10H
 35351, -- Fjola 25N
 35352, -- Fjola 25H
 35347, -- Eydis 10H
 35348, -- Eydis 25N
 35349, -- Eydis 25H
 34566, -- Anub'arak 10H
 35615, -- Anub'arak 25N
 35616); -- Anub'arak 25H
 
-- Increase chance de drop de recipes champions cache ToCR
UPDATE gameobject_loot_template SET `ChanceOrQuestChance` = 5, `maxcount` = 2 WHERE `item` IN (3, 4) AND `entry` IN
(27335,
 27503,
 27356);
 
-- Immune masks nether portal + infernal volcano
UPDATE `creature_template` SET `mechanic_immune_mask` = 617299803 WHERE `entry` IN
(34813, -- Infernal Volcano 10N
 35265, -- Infernal Volcano 10H
 35266, -- Infernal Volcano 25N
 35267, -- Infernal Volcano 25H
 34825, -- Nether Portal 10N
 35278, -- Nether Portal 10H
 35279, -- Nether Portal 25N
 35280); -- Nether Portal 25H