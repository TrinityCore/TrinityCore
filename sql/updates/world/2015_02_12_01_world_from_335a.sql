-- Fix 'Teleport to Lake Wintergrasp'
DELETE FROM `spell_scripts` WHERE `id`=58622;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(58622, 0, 1, 6, 571, 0, 0, 5386.05, 2840.97, 418.675, 3.14159);
