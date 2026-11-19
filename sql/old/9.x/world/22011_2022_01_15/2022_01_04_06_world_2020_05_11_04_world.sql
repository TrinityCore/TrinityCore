--
DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (18111,18112,18113,19627,19628,19629,18359,18361,18363,26861) AND `Item` = 35229;
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`) VALUES
(18111,35229,0,25,1,1,0,1,1),
(18112,35229,0,25,1,1,0,1,1),
(18113,35229,0,25,1,1,0,1,1),
(19627,35229,0,25,1,1,0,1,1),
(19628,35229,0,25,1,1,0,1,1),
(19629,35229,0,25,1,1,0,1,1),
(18359,35229,0,25,1,1,0,1,1),
(18361,35229,0,25,1,1,0,1,1),
(18363,35229,0,25,1,1,0,1,1),
(26861,35229,0,25,1,1,0,1,1);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (70171,70172,70170,70169,70168,70167,70166,70165,70164,70163,70162,70161) AND `Item`=35229;
INSERT INTO `skinning_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(70172, 35229, 0, 25, 1, 1, 0, 1, 1, 'Nether Residue'),
(70171, 35229, 0, 25, 1, 1, 0, 1, 1, 'Nether Residue'),
(70170, 35229, 0, 25, 1, 1, 0, 1, 1, 'Nether Residue'),
(70169, 35229, 0, 25, 1, 1, 0, 1, 1, 'Nether Residue'),
(70168, 35229, 0, 25, 1, 1, 0, 1, 1, 'Nether Residue'),
(70167, 35229, 0, 25, 1, 1, 0, 1, 1, 'Nether Residue'),
(70166, 35229, 0, 25, 1, 1, 0, 1, 1, 'Nether Residue'),
(70165, 35229, 0, 25, 1, 1, 0, 1, 1, 'Nether Residue'),
(70164, 35229, 0, 25, 1, 1, 0, 1, 1, 'Nether Residue'),
(70163, 35229, 0, 25, 1, 1, 0, 1, 1, 'Nether Residue'),
(70162, 35229, 0, 25, 1, 1, 0, 1, 1, 'Nether Residue'),
(70161, 35229, 0, 25, 1, 1, 0, 1, 1, 'Nether Residue');
