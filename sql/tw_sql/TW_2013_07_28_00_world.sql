-- Adds Forbearance effect to Captain Brandon's Divine Shield
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 71550 AND `spell_effect` = 25771;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (71550, 25771, 0, 'Captain Brandon - Divine Shield - Forbearance');
