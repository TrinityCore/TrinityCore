-- Fix Ogrimmar trainers
-- Fishing Trainer
DELETE FROM `npc_trainer` WHERE (`ID` = 3332);
DELETE FROM `creature_trainer` WHERE `CreatureId` = '3332';
INSERT INTO `creature_trainer` VALUES (3332, 3332, 17157, 0);

DELETE FROM `trainer` WHERE `Id` = '3332';
INSERT INTO `trainer` VALUES (3332, 2, 'Welcome!', 35662);

DELETE FROM `trainer_spell` WHERE `TrainerId` = '3332';
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel`) VALUES
('3332', '131476', '10', '0', '0', '0'),
('3332', '271657', '10', '356', '1', '0'),
('3332', '271659', '10', '356', '1', '0'),
('3332', '271661', '10', '356', '1', '0'),
('3332', '271663', '10', '356', '1', '0'),
('3332', '271665', '10', '356', '1', '0'),
('3332', '271673', '10', '356', '1', '0');