-- Delete data from npc_trainer (not using it anymore)
DELETE FROM `npc_trainer` WHERE (`ID` = 136091);

DELETE FROM `creature_trainer` WHERE `CreatureId` = '136091';
INSERT INTO `creature_trainer`(`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES (136091, 999, 22655, 0);

UPDATE creature_template SET gossip_menu_id =22655 WHERE entry = 136091 ;

-- Define trainer
DELETE FROM `trainer` WHERE `Id` = '999';
INSERT INTO `trainer`(`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES (999, 2, 'Welcome!', 35662);

-- DELETE old spells (there should be none since this is a new trainer id).
DELETE FROM `trainer_spell` WHERE `TrainerId` = '999';
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel`) VALUES
('999', '2575', '10', '0', '0', '0'),
('999', '253333', '10', '2565', '1', '0'),
('999', '253336', '10', '2565', '1', '0'),
('999', '253339', '100', '2565', '25', '0'),
('999', '253342', '100', '2565', '25', '0'),
('999', '253345', '100', '2565', '25', '0'),
('999', '265852', '10', '186', '1', '0');

-- Delete data from npc_trainer (not using it anymore)
DELETE FROM `npc_trainer` WHERE (`ID` = 122694);

UPDATE creature_template SET gossip_menu_id =23184 WHERE entry = 122694 ;

DELETE FROM `creature_trainer` WHERE `CreatureId` = '122694';
INSERT INTO `creature_trainer`(`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES (122694, 1000, 23184, 0);

-- Define trainer
DELETE FROM `trainer` WHERE `Id` = '1000';
INSERT INTO `trainer`(`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES (1000, 2, 'Welcome!', 35662);

-- DELETE old spells (there should be none since this is a new trainer id).
DELETE FROM `trainer_spell` WHERE `TrainerId` = '1000';
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel`) VALUES
('1000', '2575', '10', '0', '0', '0'),
('1000', '253333', '10', '2565', '1', '0'),
('1000', '253336', '10', '2565', '1', '0'),
('1000', '253339', '100', '2565', '25', '0'),
('1000', '253342', '100', '2565', '25', '0'),
('1000', '253345', '100', '2565', '25', '0'),
('1000', '265854', '10', '186', '1', '0');