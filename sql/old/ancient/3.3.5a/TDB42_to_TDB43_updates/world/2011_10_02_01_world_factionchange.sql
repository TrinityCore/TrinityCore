DELETE FROM `player_factionchange_items` WHERE `alliance_id`=48356; -- Wrong entry

DELETE FROM `player_factionchange_spells` WHERE `alliance_id` IN (67093,67091,67095,67096,67092,67085,67080,67082,67087,67083,67084,67086,60867,67065,67064,67079,67066);
INSERT INTO `player_factionchange_spells` (`alliance_id`,`horde_id`) VALUES
(67093,67132),
(67091,67130),
(67095,67134),
(67096,67135),
(67092,67131),
(67085,67141),
(67080,67136),
(67082,67138),
(67087,67139),
(67083,67143),
(67084,67140),
(67086,67142),
(60867,60866),
(67065,67147),
(67064,67144),
(67079,67145),
(67066,67146);

DELETE FROM `player_factionchange_items` WHERE `alliance_id` IN (47003,47626,44503,47654);
INSERT INTO `player_factionchange_items` (`race_A`,`alliance_id`,`commentA`,`race_H`,`horde_id`,`commentH`) VALUES
(0,47003,'Dawnbreaker Greaves',0,47430,'Dawnbreaker Sabatons'),
(0,47626,'Plans: Sunforged Breastplate',0,47643,'Plans: Sunforged Breastplate'),
(0,44503,'Schematic: Mekgineers Chopper',0,44502,'Schematic: Mechano-Hog'),
(0,47654,'Pattern: Bejeweled Wizards Bracers',0,47639,'Pattern: Bejeweled Wizards Bracers');
