-- areatrigger for the shadow throne
DELETE FROM `areatrigger_scripts` WHERE `entry` = 5605
INSERT INTO `areatrigger_scripts` (`entry`,`scriptname`) VALUES (5605,'at_shadow_throne');

-- jaina's equipment
DELETE FROM `creature_equip_template` WHERE `entry` = 36955 AND `id` = 1
INSERT INTO `creature_equip_template` (`entry`, `id`, `itementry1`, `itementry2`,`itementry3`) VALUES (36955,1,2177,12869,0);

-- jaina's gossip menu (the same one FROM sylvanas)
update `creature_template` SET `gossip_menu_id` = 10909 WHERE `entry` = 36955;

-- jaina's scriptai part 2
update `creature_template` SET `ScriptName` = 'npc_jaina_or_sylvanas_escape_hor' WHERE `entry` in (36955,37554);

-- Raging Gnoul scriptai
update `creature_template` SET `ScriptName` = 'npc_raging_gnoul' WHERE `entry` = 36940;

-- Risen Witch Doctor scriptai
update `creature_template` SET `ScriptName` = 'npc_risen_witch_doctor' WHERE `entry` = 36941;

-- LumberINg Abomination scriptai
update `creature_template` SET `ScriptName` = 'npc_lumbering_abomination' WHERE `entry` = 37069;

-- Spells Witch Doctor / Abomination
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (70144,70145,70080, 70176);
INSERT INTO `spelldifficulty_dbc`(`id`,`spellid0`,`spellid1`) VALUES 
(70144,70144,70183),-- Spell Curse of Doom Witch Doctor
(70145,70145,70184),-- Spell Shadow Bolt Volley Witch Doctor
(70080,70080,70182),-- Spell Shadow Bolt Witch Doctor
(70176,70176,70181);-- Spell Vomit Spray Abomination

