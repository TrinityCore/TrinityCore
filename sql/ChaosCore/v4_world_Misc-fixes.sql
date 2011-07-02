-- Hodir rare chest Spawn
DELETE FROM `gameobject` WHERE `id`=194200;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(2711324, 194200, 603, 3, 1, 2029.19, -192.403, 432.687, 4.44005, 0, 0, 0.79655, -0.604572, -604800, 255, 1);
DELETE FROM `gameobject` WHERE `id`=194201;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(2711326, 194201, 603, 3, 1, 2029.19, -192.403, 432.687, 4.44005, 0, 0, 0.79655, -0.604572, -604800, 255, 1);

-- Startup errors
DELETE FROM `spell_script_names` WHERE `spell_id`=29371;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`)
VALUES
(29371,'spell_heigan_eruption');

DELETE FROM `disables` WHERE `entry` IN (7264,7548);
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (7264,7548) AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(7264,11,0,0,'achievement_safety_dance'),
(7548,11,0,0,'achievement_safety_dance');

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

-- Remove sigil loot from keepers wrong caches, they should be only on hardmode ones.
-- Freya
DELETE FROM gameobject_loot_template WHERE `item` IN (45788,45814) AND `entry` IN (27078,27079,27080,26959,26960,26961);
-- Mimiron
DELETE FROM gameobject_loot_template WHERE `item` IN (45787,45816) AND `entry` IN (27085,26963);
-- Thorim
DELETE FROM gameobject_loot_template WHERE `item` IN (45784,45817) AND `entry` IN (27073,40000);

-- Raise loot on ToCR 25 Encounters
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


UPDATE gameobject_loot_template SET `maxcount` = 4 WHERE `item` IN (1, 2) AND `entry` IN
(27503, -- Champions Cache 25N
 27356);  -- Champions Cache 25H
 

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