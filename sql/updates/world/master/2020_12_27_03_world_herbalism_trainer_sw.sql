-- FIX HERBALISM TRAINER SW
-- Update it to new version
DELETE FROM `npc_trainer` WHERE `ID` = '5566';
DELETE FROM `trainer_spell` WHERE `Trainerid` = '133';
DELETE FROM `trainer_spell` WHERE `Trainerid` = '5566';
DELETE FROM `trainer` WHERE `id` = '133';
DELETE FROM `trainer` WHERE `id` = '5566';
DELETE FROM `creature_trainer` WHERE `CreatureId` = '5566';

INSERT INTO `creature_trainer`(`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES (5566, 5566, 643, 0);
INSERT INTO `trainer_spell`(`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES (5566, 265820, 10, 0, 0, 0, 0, 0, 5, 35622); -- Basic Herbalims
INSERT INTO `trainer_spell`(`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES (5566, 265826, 10, 2556, 1, 0, 0, 0, 0, 35662); -- Cata Herbalims
INSERT INTO `trainer`(`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES (5566, 2, 'Searching for herbs requires both knowledge and instinct.', 35662);
