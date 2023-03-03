-- Delete data from npc_trainer (not using it anymore)
DELETE FROM `npc_trainer` WHERE (`ID` = 5493);

DELETE FROM `creature_trainer` WHERE `CreatureId` = '5493';
INSERT INTO `creature_trainer`(`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES (5493, 10, 17157, 0);

-- Define trainer
DELETE FROM `trainer` WHERE `Id` = '10';
INSERT INTO `trainer`(`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES (10, 2, 'Welcome!', 35662);

-- DELETE old spells (there should be none since this is a new trainer id).
DELETE FROM `trainer_spell` WHERE `TrainerId` = '10';
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel`) VALUES
('10', '271660', '10000', '356', '0', '0'),
('10', '271664', '5500000', '356', '0', '0'),
('10', '7620', '10000', '356', '0', '0'),
('10', '271672', '100000', '356', '0', '0'),
('10', '271658', '100000', '356', '0', '0'),
('10', '271656', '100000', '356', '0', '0'),
('10', '271662', '10000', '356', '1', '0');



UPDATE creature_template SET npcflag=81 WHERE entry = 5493 ;
UPDATE creature_template SET gossip_menu_id =17157 WHERE entry = 5493 ;

