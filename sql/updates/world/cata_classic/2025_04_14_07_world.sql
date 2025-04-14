DELETE FROM `trainer` WHERE `Id` IN (50, 127);
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(50, 0, 'Hello, druid!  Ready for some training?', 60192),
(127, 0, 'Hello, priest!  Ready for some training?', 60192);

DELETE FROM `trainer_spell` WHERE (`TrainerId`=50 AND `SpellId` IN (774,467,8921)) OR (`TrainerId`=127 AND `SpellId` IN (17,2061,589));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(50, 774, 65, 0, 0, 0, 0, 0, 3, 60192), -- MoneyCost recalculated
(50, 467, 150, 0, 0, 0, 0, 0, 5, 60192), -- MoneyCost recalculated
(50, 8921, 105, 0, 0, 0, 0, 0, 4, 60192), -- MoneyCost recalculated
(127, 17, 150, 0, 0, 0, 0, 0, 5, 60192), -- MoneyCost recalculated
(127, 2061, 65, 0, 0, 0, 0, 0, 3, 60192), -- MoneyCost recalculated
(127, 589, 105, 0, 0, 0, 0, 0, 4, 60192); -- MoneyCost recalculated

UPDATE `trainer_spell` SET `MoneyCost`=110 WHERE (`TrainerId`=15 AND `SpellId`=1494);

DELETE FROM `creature_trainer` WHERE (`CreatureID`=35873 AND `MenuID`=10696 AND `OptionID`=1) OR (`CreatureID`=35869 AND `MenuID`=10702 AND `OptionID`=1) OR (`CreatureID`=35869 AND `MenuID`=10702 AND `OptionID`=0) OR (`CreatureID`=35872 AND `MenuID`=10698 AND `OptionID`=1) OR (`CreatureID`=35871 AND `MenuID`=10699 AND `OptionID`=1) OR (`CreatureID`=35871 AND `MenuID`=10699 AND `OptionID`=0) OR (`CreatureID`=35874 AND `MenuID`=10697 AND `OptionID`=1) OR (`CreatureID`=35874 AND `MenuID`=10697 AND `OptionID`=0) OR (`CreatureID`=35839 AND `MenuID`=10694 AND `OptionID`=1) OR (`CreatureID`=35839 AND `MenuID`=10694 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(35873, 50, 10696, 1),
(35869, 32, 10702, 1),
(35869, 32, 10702, 0),
(35872, 44, 10698, 1),
(35871, 17, 10699, 1),
(35871, 17, 10699, 0),
(35874, 15, 10697, 1),
(35874, 15, 10697, 0),
(35839, 145, 10694, 1),
(35839, 145, 10694, 0);
