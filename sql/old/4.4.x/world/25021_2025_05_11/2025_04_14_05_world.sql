DELETE FROM `trainer` WHERE `Id`=134;
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(134, 0, 'Hello, shaman!  Ready for some training?', 60192);

DELETE FROM `trainer_spell` WHERE (`TrainerId`=134 AND `SpellId` IN (8042,8075,73899));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(134, 8042, 150, 0, 0, 0, 0, 0, 5, 60192), -- MoneyCost recalculated
(134, 8075, 105, 0, 0, 0, 0, 0, 4, 60192), -- MoneyCost recalculated
(134, 73899, 65, 0, 0, 0, 0, 0, 3, 60192); -- MoneyCost recalculated

UPDATE `trainer_spell` SET `MoneyCost`=105 WHERE (`TrainerId`=32 AND `SpellId`=172) OR (`TrainerId`=3 AND `SpellId`=589) OR (`TrainerId`=15 AND `SpellId`=1494);
UPDATE `trainer_spell` SET `MoneyCost`=150 WHERE (`TrainerId`=32 AND `SpellId`=1454) OR (`TrainerId`=44 AND `SpellId`=2136) OR (`TrainerId`=3 AND `SpellId`=17) OR (`TrainerId`=17 AND `SpellId`=1784) OR (`TrainerId`=168 AND `SpellId`=465) OR (`TrainerId`=145 AND `SpellId`=34428);
UPDATE `trainer_spell` SET `MoneyCost`=20585 WHERE (`TrainerId`=3 AND `SpellId` IN (83968,596));
UPDATE `trainer_spell` SET `MoneyCost`=23750 WHERE (`TrainerId`=3 AND `SpellId` IN (89745,27683));
UPDATE `trainer_spell` SET `MoneyCost`=234335 WHERE (`TrainerId`=3 AND `SpellId`=87495);
UPDATE `trainer_spell` SET `MoneyCost`=297665 WHERE (`TrainerId`=3 AND `SpellId`=73325);
UPDATE `trainer_spell` SET `MoneyCost`=247000 WHERE (`TrainerId`=3 AND `SpellId`=73510);
UPDATE `trainer_spell` SET `MoneyCost`=410 WHERE (`TrainerId`=3 AND `SpellId`=139);
UPDATE `trainer_spell` SET `MoneyCost`=25335 WHERE (`TrainerId`=3 AND `SpellId`=6346);
UPDATE `trainer_spell` SET `MoneyCost`=11085 WHERE (`TrainerId`=3 AND `SpellId`=1706);
UPDATE `trainer_spell` SET `MoneyCost`=26915 WHERE (`TrainerId`=3 AND `SpellId`=453);
UPDATE `trainer_spell` SET `MoneyCost`=1135 WHERE (`TrainerId`=3 AND `SpellId`=8122);
UPDATE `trainer_spell` SET `MoneyCost`=28500 WHERE (`TrainerId`=3 AND `SpellId`=8129);
UPDATE `trainer_spell` SET `MoneyCost`=580 WHERE (`TrainerId`=3 AND `SpellId`=8092);
UPDATE `trainer_spell` SET `MoneyCost`=1500 WHERE (`TrainerId`=3 AND `SpellId` IN (21562,2006));
UPDATE `trainer_spell` SET `MoneyCost`=215335 WHERE (`TrainerId`=3 AND `SpellId`=64843);
UPDATE `trainer_spell` SET `MoneyCost`=98165 WHERE (`TrainerId`=3 AND `SpellId`=64901);
UPDATE `trainer_spell` SET `MoneyCost`=14250 WHERE (`TrainerId`=3 AND `SpellId`=605);
UPDATE `trainer_spell` SET `MoneyCost`=2175 WHERE (`TrainerId`=3 AND `SpellId`=2050);
UPDATE `trainer_spell` SET `MoneyCost`=17415 WHERE (`TrainerId`=3 AND `SpellId`=2060);
UPDATE `trainer_spell` SET `MoneyCost`=158335 WHERE (`TrainerId`=3 AND `SpellId`=32375);
UPDATE `trainer_spell` SET `MoneyCost`=9500 WHERE (`TrainerId`=3 AND `SpellId` IN (32379,9484));
UPDATE `trainer_spell` SET `MoneyCost`=22165 WHERE (`TrainerId`=3 AND `SpellId`=32546);
UPDATE `trainer_spell` SET `MoneyCost`=123500 WHERE (`TrainerId`=3 AND `SpellId`=33076);
UPDATE `trainer_spell` SET `MoneyCost`=12665 WHERE (`TrainerId`=3 AND `SpellId`=2096);
UPDATE `trainer_spell` SET `MoneyCost`=5385 WHERE (`TrainerId`=3 AND `SpellId`=586);
UPDATE `trainer_spell` SET `MoneyCost`=177335 WHERE (`TrainerId`=3 AND `SpellId`=48045);
UPDATE `trainer_spell` SET `MoneyCost`=272335 WHERE (`TrainerId`=3 AND `SpellId`=73413);
UPDATE `trainer_spell` SET `MoneyCost`=2940 WHERE (`TrainerId`=3 AND `SpellId`=14914);
UPDATE `trainer_spell` SET `MoneyCost`=85500 WHERE (`TrainerId`=3 AND `SpellId`=15237);
UPDATE `trainer_spell` SET `MoneyCost`=6335 WHERE (`TrainerId`=3 AND `SpellId`=527);
UPDATE `trainer_spell` SET `MoneyCost`=4435 WHERE (`TrainerId`=3 AND `SpellId`=528);
UPDATE `trainer_spell` SET `MoneyCost`=300 WHERE (`TrainerId`=3 AND `SpellId`=588);
UPDATE `trainer_spell` SET `MoneyCost`=110835 WHERE (`TrainerId`=3 AND `SpellId`=34433);
UPDATE `trainer_spell` SET `MoneyCost`=7915 WHERE (`TrainerId`=3 AND `SpellId`=2944);

DELETE FROM `creature_trainer` WHERE (`CreatureID`=43455 AND `MenuID`=11831 AND `OptionID`=0) OR (`CreatureID`=37121 AND `MenuID`=10878 AND `OptionID`=0) OR (`CreatureID`=37115 AND `MenuID`=10879 AND `OptionID`=0) OR (`CreatureID`=837 AND `MenuID`=4679 AND `OptionID`=0) OR (`CreatureID`=916 AND `MenuID`=4676 AND `OptionID`=0) OR (`CreatureID`=895 AND `MenuID`=4675 AND `OptionID`=0) OR (`CreatureID`=926 AND `MenuID`=4678 AND `OptionID`=0) OR (`CreatureID`=912 AND `MenuID`=4684 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(43455, 32, 11831, 0),
(37121, 44, 10878, 0),
(37115, 134, 10879, 0),
(837, 3, 4679, 0),
(916, 17, 4676, 0),
(895, 15, 4675, 0),
(926, 168, 4678, 0),
(912, 145, 4684, 0);
