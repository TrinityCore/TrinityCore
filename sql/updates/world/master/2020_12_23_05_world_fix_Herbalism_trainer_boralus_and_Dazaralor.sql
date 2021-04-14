-- Delete data from npc_trainer (not using it anymore)
DELETE FROM `npc_trainer` WHERE (`ID` = 136096);

DELETE FROM `creature_trainer` WHERE `CreatureId` = '136096';
INSERT INTO `creature_trainer`(`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES (136096, 997, 22544, 0);

-- Define trainer
DELETE FROM `trainer` WHERE `Id` = '997';
INSERT INTO `trainer`(`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES (997, 2, 'Welcome!', 35662);

-- DELETE old spells (there should be none since this is a new trainer id).
DELETE FROM `trainer_spell` WHERE `TrainerId` = '997';
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel`) VALUES
('997', '2366', '10', '0', '0', '0'),
('997', '252405', '10', '2549', '1', '0'),
('997', '252408', '10', '2549', '1', '0'),
('997', '252411', '10', '2549', '1', '0'),
('997', '252415', '10', '2549', '1', '0'),
('997', '252418', '10', '2549', '1', '0'),
('997', '252421', '10', '2549', '1', '0'),
('997', '252424', '100', '2549', '25', '0'),
('997', '265833', '10', '182', '1', '0');

-- Delete data from npc_trainer (not using it anymore)
DELETE FROM `npc_trainer` WHERE (`ID` = 122704);

DELETE FROM `creature_trainer` WHERE `CreatureId` = '122704';
INSERT INTO `creature_trainer`(`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES (122704, 998, 22545, 0);

-- Define trainer
DELETE FROM `trainer` WHERE `Id` = '998';
INSERT INTO `trainer`(`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES (998, 2, 'Welcome!', 35662);

-- DELETE old spells (there should be none since this is a new trainer id).
DELETE FROM `trainer_spell` WHERE `TrainerId` = '998';
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel`) VALUES
('998', '2366', '10', '0', '0', '0'),
('998', '252405', '10', '2549', '1', '0'),
('998', '252408', '10', '2549', '1', '0'),
('998', '252411', '10', '2549', '1', '0'),
('998', '252415', '10', '2549', '1', '0'),
('998', '252418', '10', '2549', '1', '0'),
('998', '252421', '10', '2549', '1', '0'),
('998', '252424', '100', '2549', '25', '0'),
('998', '265836', '10', '182', '1', '0');
