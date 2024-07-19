-- Lee Brown
UPDATE `trainer` SET `VerifiedBuild`=55664 WHERE `Id`=10;

DELETE FROM `creature_trainer` WHERE (`CreatureID`=1651 AND `MenuID`=5665 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(1651, 10, 5665, 0);

DELETE FROM `trainer_spell` WHERE (`TrainerId`=10 AND `SpellId` IN (271719,310676));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(10, 271719, 10, 356, 1, 0, 0, 0, 5, 55664), -- No Faction found! MoneyCost not recalculated!
(10, 310676, 9500, 356, 1, 0, 0, 0, 10, 55664); -- No Faction found! MoneyCost not recalculated!

UPDATE `trainer_spell` SET `VerifiedBuild`=55664 WHERE (`TrainerId`=10 AND `SpellId` IN (271617,271663,271673,271659,271657,271661,271665));
