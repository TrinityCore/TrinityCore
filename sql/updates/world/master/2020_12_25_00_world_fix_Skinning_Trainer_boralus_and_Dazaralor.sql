-- Delete data from npc_trainer (not using it anymore)
DELETE FROM `npc_trainer` WHERE (`ID` = 136061);

DELETE FROM `creature_trainer` WHERE `CreatureId` = '136061';
INSERT INTO `creature_trainer`(`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES (136061, 1001, 22797, 0);

-- Define trainer
DELETE FROM `trainer` WHERE `Id` = '1001';
INSERT INTO `trainer`(`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES (1001, 2, 'Welcome!', 35662);

-- DELETE old spells (there should be none since this is a new trainer id).
DELETE FROM `trainer_spell` WHERE `TrainerId` = '1001';
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel`) VALUES
('1001', '8613', '10', '0', '0', '0'),
('1001', '257146', '10', '2557', '1', '0'),
('1001', '257149', '10', '2557', '1', '0'),
('1001', '257152', '10', '2557', '1', '0'),
('1001', '265870', '10', '393', '1', '0');

-- Delete data from npc_trainer (not using it anymore)
DELETE FROM `npc_trainer` WHERE (`ID` = 122699);

DELETE FROM `creature_trainer` WHERE `CreatureId` = '122699';
INSERT INTO `creature_trainer`(`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES (122699, 1002, 23355, 0);

-- Define trainer
DELETE FROM `trainer` WHERE `Id` = '1002';
INSERT INTO `trainer`(`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES (1002, 2, 'Welcome!', 35662);

-- DELETE old spells (there should be none since this is a new trainer id).
DELETE FROM `trainer_spell` WHERE `TrainerId` = '1002';
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel`) VALUES
('1002', '8613', '10', '0', '0', '0'),
('1002', '257146', '10', '2557', '1', '0'),
('1002', '257149', '10', '2557', '1', '0'),
('1002', '257152', '10', '2557', '1', '0'),
('1002', '265872', '10', '393', '1', '0');
