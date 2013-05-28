-- Tempfix for Last Zuldrak Arena quest
delete from smart_scripts where entryorguid=30022;
Insert into smart_scripts values 
(30022, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 50689, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blood presence'),
(30022, 0, 1, 0, 0, 0, 100, 0, 12000, 12000, 12000, 12000, 11, 55977, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Whirlind'),
(30022, 0, 2, 0, 0, 0, 100, 0, 25000, 25000, 25000, 25000, 11, 55975, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hysteria'),
(30022, 0, 3, 0, 0, 0, 100, 0, 40000, 40000, 40000, 40000, 11, 55974, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Blood boil'),
(30022, 0, 4, 0, 0, 0, 100, 0, 13000, 13000, 13000, 13000, 11, 55973, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Blood plague'),
(30022, 0, 5, 0, 0, 0, 100, 0, 30000, 75000, 30000, 75000, 11, 55976, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'spell deflection');

update creature_template set AIname='SmartAI',mechanic_immune_mask=113983487 where entry=30022;

UPDATE `quest_template` SET `RequiredNpcOrGo1` = 30022, `RequiredNpcOrGoCount1` = 1, `SpecialFlags` = 0 WHERE `Id` = 12948;