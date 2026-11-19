-- Remove model aura when shadowy disguise is removed
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=-32756;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-32756,-38080,0, 'Shadowy Disguise: Remove model aura'),
(-32756,-38081,0, 'Shadowy Disguise: Remove model aura');
