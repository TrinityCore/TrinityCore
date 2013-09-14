--Arcaniafr--trinitycore 2013--

-- Chakra
DELETE FROM `spell_proc_event` WHERE `entry` = 14751;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) 
VALUES (14751, 6, 6, 7808, 18, 2710, 0, 0, 0, 0, 0);
 
DELETE FROM `spell_script_names` WHERE `spell_id` IN (81208,81585,81206,88685,88667,88687);
INSERT INTO `spell_script_names` VALUES
(81208,'spell_pri_chakra_swap_supressor'),
(81585,'spell_pri_chakra_serenity_proc'),
(81206,'spell_pri_chakra_swap_supressor'),
(88685,'spell_pri_chakra_sanctuary_heal'),
(88667,'spell_pri_chakra_sanctuary_heal');
 
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (81206);
INSERT INTO `spell_linked_spell` VALUES
(81206,81207,0,'Chakra:Sanctuary - Renew spellmod link');
 
DELETE FROM `spell_group` WHERE `id` = 1501;
INSERT INTO `spell_group` VALUES
(1501,81206), -- Sanctuary
(1501,81208), -- Serenity
(1501,81209); -- Chastise
 
DELETE FROM `spell_group_stack_rules` WHERE `group_id` = 1501;
INSERT INTO `spell_group_stack_rules` VALUES
(1501,2); -- one chakra effect can be active on the caster.
