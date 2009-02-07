DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN ('-33711','-38794','33686');
INSERT INTO `spell_linked_spell`(`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
('-33711','33686','0','Murmur\'s Shockwave (Normal)'),
('-38794','33686','0','Murmur\'s Shockwave (Heroic)'),
('33686','31705','0','Murmur\'s Shockwave Jump');