--
UPDATE `spell_linked_spell` SET `type`=0 WHERE `spell_trigger`=44869 AND `spell_effect`=44866 AND `type`=1;

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=46021 AND `spell_effect`=44852;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(46021,44852,0,'Transported to the spectral realm turn Sathrovarr Hostile');
