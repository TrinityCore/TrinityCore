-- Intravenous Healing Potion Fix
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=61263;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES (61263,61267,0, 'Intravenous Healing Effect' );
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES (61263,61268,0, 'Intravenous Mana Regeneration Effect' );
