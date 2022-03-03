--
DELETE FROM `trainer_spell` WHERE `TrainerId`=103 AND `SpellId`=12768;
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(103, 12768, 1500, 202, 205, 20222, 0, 0, 0, 0);
