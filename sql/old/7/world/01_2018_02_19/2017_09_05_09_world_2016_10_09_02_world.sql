--
SET @Dustbringer := 44505;

DELETE FROM `gameobject_loot_template` WHERE `Item`= @Dustbringer;
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(25662, @Dustbringer, 0, 1, 0, 1, 4, 1, 1, 'Dustbringer'),
(25663, @Dustbringer, 0, 1, 0, 1, 4, 1, 1, 'Dustbringer'),
(25664, @Dustbringer, 0, 1, 0, 1, 4, 1, 1, 'Dustbringer'),
(25665, @Dustbringer, 0, 1, 0, 1, 4, 1, 1, 'Dustbringer'),
(25668, @Dustbringer, 0, 1, 0, 1, 4, 1, 1, 'Dustbringer'),
(25670, @Dustbringer, 0, 1, 0, 1, 4, 1, 1, 'Dustbringer'),
(25671, @Dustbringer, 0, 1, 0, 1, 8, 1, 1, 'Dustbringer'),
(25673, @Dustbringer, 0, 1, 0, 1, 5, 1, 1, 'Dustbringer'),
(25674, @Dustbringer, 0, 1, 0, 1, 4, 1, 1, 'Dustbringer');

DELETE FROM `fishing_loot_template` WHERE `Item`= @Dustbringer;
INSERT INTO `fishing_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(65, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer'),
(394, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer'),
(2817, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer'),
(3711, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer'),
(3980, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer'),
(3982, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer'),
(3994, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer'),
(3999, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer'),
(4001, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer'),
(4002, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer'),
(4039, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer'),
(4043, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer'),
(4055, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer'),
(4058, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer'),
(4059, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer'),
(4071, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer'),
(4109, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer'),
(4134, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer'),
(4263, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer'),
(4479, @Dustbringer, 0, 1, 0, 1, 2, 1, 1, 'Dustbringer');
