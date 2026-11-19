DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN(47585, 64382);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
( 47585, 60069, 2, 'Dispersion (transform/regen)'),
( 64382, 64380, 0, 'Shattering Throw'),
( 47585, 63230, 2, 'Dispersion (immunity)');
