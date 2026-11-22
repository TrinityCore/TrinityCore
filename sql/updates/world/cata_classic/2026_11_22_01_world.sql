DELETE FROM `trainer` WHERE `Id`=55;
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(55, 0, 'Well met, Death Knight.  Ready for some training?', 58158);

DELETE FROM `trainer_spell` WHERE (`TrainerId`=55 AND `SpellId` IN (87510,87492,85948,81229,70164,53343,53331,3714,49020,77606,73975,54446,62158,61999,50842,47528,77575,49998,46584,42650,48792,47568,48743,45529,48707,48265,48263,45524,48721,43265,47476,56815,56222,57330,53341,53323,53342,54447,53344));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(55, 87510, 21375, 0, 0, 0, 0, 0, 50, 58158), -- MoneyCost recalculated
(55, 87492, 210900, 0, 0, 0, 0, 0, 80, 58158), -- MoneyCost recalculated
(55, 85948, 111150, 0, 0, 0, 0, 0, 64, 58158), -- MoneyCost recalculated
(55, 81229, 111150, 0, 0, 0, 0, 0, 68, 58158), -- MoneyCost recalculated
(55, 70164, 142500, 0, 0, 0, 0, 0, 72, 58158), -- MoneyCost recalculated
(55, 53343, 24225, 0, 0, 0, 0, 0, 55, 58158), -- MoneyCost recalculated
(55, 53331, 25650, 0, 0, 0, 0, 0, 60, 58158), -- MoneyCost recalculated
(55, 3714, 57000, 0, 0, 0, 0, 0, 61, 58158), -- MoneyCost recalculated
(55, 49020, 57000, 0, 0, 0, 0, 0, 61, 58158), -- MoneyCost recalculated
(55, 77606, 267900, 0, 0, 0, 0, 0, 85, 58158), -- MoneyCost recalculated
(55, 73975, 245100, 0, 0, 0, 0, 0, 83, 58158), -- MoneyCost recalculated
(55, 54446, 82650, 0, 0, 0, 0, 0, 63, 58158), -- MoneyCost recalculated
(55, 62158, 142500, 0, 0, 0, 0, 0, 72, 58158), -- MoneyCost recalculated
(55, 61999, 133950, 0, 0, 0, 0, 0, 72, 58158), -- MoneyCost recalculated
(55, 50842, 24225, 0, 0, 0, 0, 0, 56, 58158), -- MoneyCost recalculated
(55, 47528, 24225, 0, 0, 0, 0, 0, 57, 58158), -- MoneyCost recalculated
(55, 77575, 222300, 0, 0, 0, 0, 0, 81, 58158), -- MoneyCost recalculated
(55, 49998, 24225, 0, 0, 0, 0, 0, 56, 58158), -- MoneyCost recalculated
(55, 46584, 24225, 0, 0, 0, 0, 0, 56, 58158), -- MoneyCost recalculated
(55, 42650, 210900, 0, 0, 0, 0, 0, 80, 58158), -- MoneyCost recalculated
(55, 48792, 76950, 0, 0, 0, 0, 0, 62, 58158), -- MoneyCost recalculated
(55, 47568, 168150, 0, 0, 0, 0, 0, 75, 58158), -- MoneyCost recalculated
(55, 48743, 99750, 0, 0, 0, 0, 0, 66, 58158), -- MoneyCost recalculated
(55, 45529, 88350, 0, 0, 0, 0, 0, 64, 58158), -- MoneyCost recalculated
(55, 48707, 111150, 0, 0, 0, 0, 0, 68, 58158), -- MoneyCost recalculated
(55, 48265, 125400, 0, 0, 0, 0, 0, 70, 58158), -- MoneyCost recalculated
(55, 48263, 24225, 0, 0, 0, 0, 0, 57, 58158), -- MoneyCost recalculated
(55, 45524, 25650, 0, 0, 0, 0, 0, 58, 58158), -- MoneyCost recalculated
(55, 48721, 25650, 0, 0, 0, 0, 0, 58, 58158), -- MoneyCost recalculated
(55, 43265, 25650, 0, 0, 0, 0, 0, 60, 58158), -- MoneyCost recalculated
(55, 47476, 25650, 0, 0, 0, 0, 0, 59, 58158), -- MoneyCost recalculated
(55, 56815, 105450, 0, 0, 0, 0, 0, 67, 58158), -- MoneyCost recalculated
(55, 56222, 94050, 0, 0, 0, 0, 0, 65, 58158), -- MoneyCost recalculated
(55, 57330, 94050, 0, 0, 0, 0, 0, 65, 58158), -- MoneyCost recalculated
(55, 53341, 24225, 0, 0, 0, 0, 0, 55, 58158), -- MoneyCost recalculated
(55, 53323, 82650, 0, 0, 0, 0, 0, 63, 58158), -- MoneyCost recalculated
(55, 53342, 24225, 0, 0, 0, 0, 0, 57, 58158), -- MoneyCost recalculated
(55, 54447, 24225, 0, 0, 0, 0, 0, 57, 58158), -- MoneyCost recalculated
(55, 53344, 125400, 0, 0, 0, 0, 0, 70, 58158); -- MoneyCost recalculated

DELETE FROM `creature_trainer` WHERE `CreatureId` IN (29194, 29195, 29196, 28472, 28471, 28474);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionID`) VALUES
(28474, 55, 9693, 0), -- Amal'thazad
(29194, 55, 9792, 0), -- Amal'thazad
(29195, 55, 9793, 0), -- Lady Alistra
(28471, 55, 9691, 0), -- Lady Alistra
(29196, 55, 9794, 0), -- Lord Thorval
(28472, 55, 9692, 0); -- Lord Thorval
