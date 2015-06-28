--
DELETE FROM `creature_addon` WHERE `guid` IN (104706, 104705);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (53099, 54640, 55288);
DELETE FROM `spell_scripts` WHERE `id` IN (53099, 55288);
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(53099,0,0,15,53098,0,0,0,0,0,0),
(55288,0,0,15,55289,0,0,0,0,0,0);
