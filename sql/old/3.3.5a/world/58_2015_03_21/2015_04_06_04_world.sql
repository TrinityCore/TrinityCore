UPDATE `gameobject_template` SET `data5`=1 WHERE `entry`=184867;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 37639 AND `spell_effect` = 36326;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
( 37639, 36326, 0, 'Nether Whelp');
