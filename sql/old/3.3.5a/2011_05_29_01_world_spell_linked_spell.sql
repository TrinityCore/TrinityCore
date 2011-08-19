DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (70923,-70923);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(70923,70924,1,'Blood-Queen: Uncontrollable Frenzy damage buff'),
(-70923,-70924,0,'Blood-Queen: Uncontrollable Frenzy remove 10man'),
(-70923,-73015,0,'Blood-Queen: Uncontrollable Frenzy remove 25man');
