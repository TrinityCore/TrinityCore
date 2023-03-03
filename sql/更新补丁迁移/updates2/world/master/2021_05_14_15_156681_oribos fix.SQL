-- Delete data from npc_trainer (not using it anymore)
DELETE FROM `npc_trainer` WHERE (`ID` = 156681);

DELETE FROM `creature_trainer` WHERE `CreatureId` = '156681';
INSERT INTO `creature_trainer`(`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES (156681, 6666, 10185, 0);

-- Define trainer
DELETE FROM `trainer` WHERE `Id` = '6666';
INSERT INTO `trainer`(`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES (6666, 2, 'Welcome!', 35662);

UPDATE creature_template SET npcflag=81 WHERE entry = 156681 ;
UPDATE creature_template SET gossip_menu_id =10185 WHERE entry = 156681 ;
UPDATE creature_template SET faction =35 WHERE entry = 156681 ;

-- DELETE old spells (there should be none since this is a new trainer id).
DELETE FROM `trainer_spell` WHERE `TrainerId` = '6666';
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel`) VALUES
('6666', '3908', '10000', '0', '0', '0'),
('6666', '310949', '5500000', '0', '0', '0'),
('6666', '184479', '10000', '0', '0', '0'),
('6666', '184480', '100000', '0', '0', '0'),
('6666', '173249', '100000', '165', '0', '0'),
('6666', '173198', '100000', '165', '0', '0'),
('6666', '173246', '10000', '165', '1', '0');