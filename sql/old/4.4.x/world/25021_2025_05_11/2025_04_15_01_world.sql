UPDATE `trainer_spell` SET `MoneyCost`=105 WHERE (`TrainerId`=15 AND `SpellId`=1494);
UPDATE `trainer_spell` SET `MoneyCost`=60 WHERE (`TrainerId`=145 AND `SpellId`=100);
UPDATE `trainer_spell` SET `MoneyCost`=140 WHERE (`TrainerId`=145 AND `SpellId`=34428);

DELETE FROM `creature_trainer` WHERE (`CreatureID`=16500 AND `MenuID`=7264 AND `OptionID`=0) OR (`CreatureID`=17089 AND `MenuID`=7522 AND `OptionID`=0) OR (`CreatureID`=16502 AND `MenuID`=7349 AND `OptionID`=0) OR (`CreatureID`=16499 AND `MenuID`=7262 AND `OptionID`=0) OR (`CreatureID`=16501 AND `MenuID`=7260 AND `OptionID`=0) OR (`CreatureID`=16503 AND `MenuID`=7263 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(16500, 44, 7264, 0),
(17089, 134, 7522, 0),
(16502, 3, 7349, 0),
(16499, 15, 7262, 0),
(16501, 168, 7260, 0),
(16503, 145, 7263, 0);
