-- cast s66747 (Totem of the Earthen Ring) after completing q14100 or q14111 (Relic of the Earthen Ring)
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=66744 AND `spell_effect`=66747;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES 
(66744,66747,0, 'totem of the earthen ring');
