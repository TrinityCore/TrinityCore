SET @GROUP = 1121;
DELETE FROM `spell_group_stack_rules` WHERE `group_id`=@GROUP;
INSERT INTO `spell_group_stack_rules` (`group_id`,`stack_rule`) VALUES
(@GROUP, 1); -- SPEL_GROUP_STACK_RULE_EXCLUSIVE

DELETE FROM `spell_group` WHERE `id`=@GROUP;
INSERT INTO `spell_group` (`id`,`spell_id`) VALUES
(@GROUP, 73413), -- Inner will
(@GROUP, 588);   -- Inner fire

-- Adding missing proc event for Fingers of Frost (Rank 3)
DELETE FROM `spell_proc_event` WHERE `entry`=83074;
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(83074, 0, 3, 1049120, 4096, 0, 65536, 0, 0, 20, 0);

-- Updating spell_learn_spell's spell IDs range...
ALTER TABLE `spell_learn_spell` MODIFY `entry` MEDIUMINT(8) NOT NULL;
ALTER TABLE `spell_learn_spell` MODIFY `SpellID` MEDIUMINT(8) NOT NULL;
-- ...So we can have sinister strike's combo point enabler.
DELETE FROM `spell_learn_spell` WHERE `SpellID`=79327 AND `entry`=2098;
INSERT INTO `spell_learn_spell` (`entry`,`SpellID`,`Active`) VALUES
(2098, 79327, 0);
