-- 
UPDATE `trainer_spell` SET `ReqLevel`=0, `VerifiedBuild`=26365 WHERE (`TrainerId`=148 AND `SpellId`=88342);
UPDATE `trainer_spell` SET `ReqLevel`=0, `VerifiedBuild`=26365 WHERE (`TrainerId`=148 AND `SpellId`=88345);
UPDATE `trainer_spell` SET `ReqLevel`=0, `VerifiedBuild`=26365 WHERE (`TrainerId`=148 AND `SpellId`=33690);
UPDATE `trainer_spell` SET `ReqLevel`=0, `VerifiedBuild`=26365 WHERE (`TrainerId`=148 AND `SpellId`=3562);
UPDATE `trainer_spell` SET `ReqLevel`=0, `VerifiedBuild`=26365 WHERE (`TrainerId`=148 AND `SpellId`=3565);
UPDATE `trainer_spell` SET `ReqLevel`=0, `VerifiedBuild`=26365 WHERE (`TrainerId`=148 AND `SpellId`=3561);
UPDATE `trainer_spell` SET `ReqLevel`=0, `VerifiedBuild`=26365 WHERE (`TrainerId`=148 AND `SpellId`=53140);
UPDATE `trainer_spell` SET `ReqLevel`=0, `VerifiedBuild`=26365 WHERE (`TrainerId`=148 AND `SpellId`=49359);
UPDATE `trainer_spell` SET `ReqLevel`=0, `VerifiedBuild`=26365 WHERE (`TrainerId`=148 AND `SpellId`=32271);
UPDATE `trainer_spell` SET `ReqLevel`=0, `VerifiedBuild`=26365 WHERE (`TrainerId`=148 AND `SpellId`=53142);
UPDATE `trainer_spell` SET `ReqLevel`=0, `VerifiedBuild`=26365 WHERE (`TrainerId`=148 AND `SpellId`=49360);
UPDATE `trainer_spell` SET `ReqLevel`=0, `VerifiedBuild`=26365 WHERE (`TrainerId`=148 AND `SpellId`=32266);
UPDATE `trainer_spell` SET `ReqLevel`=0, `VerifiedBuild`=26365 WHERE (`TrainerId`=148 AND `SpellId`=11416);
UPDATE `trainer_spell` SET `ReqLevel`=0, `VerifiedBuild`=26365 WHERE (`TrainerId`=148 AND `SpellId`=33691);
UPDATE `trainer_spell` SET `ReqLevel`=0, `VerifiedBuild`=26365 WHERE (`TrainerId`=148 AND `SpellId`=11419);
UPDATE `trainer_spell` SET `ReqLevel`=0, `VerifiedBuild`=26365 WHERE (`TrainerId`=148 AND `SpellId`=10059);

DELETE FROM `creature_default_trainer` WHERE `CreatureId` IN (26991, 26998, 27000, 26987, 26994, 26990, 26993, 26999, 26988, 35133);
INSERT INTO `creature_default_trainer` (`CreatureId`, `TrainerId`) VALUES
(26991, 407),
(26998, 56),
(27000, 196),
(26987, 122),
(26994, 133),
(26990, 62),
(26993, 10),
(26999, 91),
(26988, 27),
(35133, 386);

DELETE FROM `creature_default_trainer` WHERE `CreatureId` IN (26906, 26903, 26910, 26909, 26904, 26907, 26912, 26913, 26911);
INSERT INTO `creature_default_trainer` (`CreatureId`, `TrainerId`) VALUES
(26906, 62),
(26903, 122),
(26910, 133),
(26909, 10),
(26904, 27),
(26907, 407),
(26912, 91),
(26913, 196),
(26911, 56);

DELETE FROM `trainer` WHERE `Id` IN (114, 406);
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(114, 0, 'Welcome!', 26822),
(406, 2, 'Engineering is very simple once you grasp the basics.', 26822);


DELETE FROM `trainer_spell` WHERE (`TrainerId`=114 AND `SpellId`=224869) OR (`TrainerId`=114 AND `SpellId`=224871) OR (`TrainerId`=114 AND `SpellId`=176248) OR (`TrainerId`=114 AND `SpellId`=176246) OR (`TrainerId`=114 AND `SpellId`=132621) OR (`TrainerId`=114 AND `SpellId`=132620) OR (`TrainerId`=114 AND `SpellId`=88342) OR (`TrainerId`=114 AND `SpellId`=88345) OR (`TrainerId`=114 AND `SpellId`=33690) OR (`TrainerId`=114 AND `SpellId`=3562) OR (`TrainerId`=114 AND `SpellId`=3565) OR (`TrainerId`=114 AND `SpellId`=3561) OR (`TrainerId`=114 AND `SpellId`=53140) OR (`TrainerId`=114 AND `SpellId`=49359) OR (`TrainerId`=114 AND `SpellId`=32271) OR (`TrainerId`=114 AND `SpellId`=53142) OR (`TrainerId`=114 AND `SpellId`=49360) OR (`TrainerId`=114 AND `SpellId`=32266) OR (`TrainerId`=114 AND `SpellId`=11416) OR (`TrainerId`=114 AND `SpellId`=33691) OR (`TrainerId`=114 AND `SpellId`=11419) OR (`TrainerId`=114 AND `SpellId`=10059) OR (`TrainerId`=406 AND `SpellId`=127139) OR (`TrainerId`=406 AND `SpellId`=84413) OR (`TrainerId`=406 AND `SpellId`=95705) OR (`TrainerId`=406 AND `SpellId`=12902) OR (`TrainerId`=406 AND `SpellId`=12905) OR (`TrainerId`=406 AND `SpellId`=12903) OR (`TrainerId`=406 AND `SpellId`=12899) OR (`TrainerId`=406 AND `SpellId`=12897) OR (`TrainerId`=406 AND `SpellId`=12895) OR (`TrainerId`=406 AND `SpellId`=30574) OR (`TrainerId`=406 AND `SpellId`=30570) OR (`TrainerId`=406 AND `SpellId`=30575) OR (`TrainerId`=406 AND `SpellId`=30569) OR (`TrainerId`=406 AND `SpellId`=30568) OR (`TrainerId`=406 AND `SpellId`=12907) OR (`TrainerId`=406 AND `SpellId`=12759) OR (`TrainerId`=406 AND `SpellId`=12906) OR (`TrainerId`=406 AND `SpellId`=56473);
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(114, 224869, 500000, 0, 0, 0, 0, 0, 105, 26822),
(114, 224871, 500000, 0, 0, 0, 0, 0, 110, 26822),
(114, 176248, 635000, 0, 0, 0, 0, 0, 92, 26822),
(114, 176246, 635000, 0, 0, 0, 0, 0, 92, 26822),
(114, 132621, 423000, 0, 0, 0, 0, 0, 90, 26822),
(114, 132620, 423000, 0, 0, 0, 0, 0, 90, 26822),
(114, 88342, 282000, 0, 0, 0, 0, 0, 0, 26822),
(114, 88345, 282000, 0, 0, 0, 0, 0, 0, 26822),
(114, 33690, 81000, 0, 0, 0, 0, 0, 0, 26822),
(114, 3562, 5100, 0, 0, 0, 0, 0, 0, 26822),
(114, 3565, 5100, 0, 0, 0, 0, 0, 0, 26822),
(114, 3561, 5100, 0, 0, 0, 0, 0, 0, 26822),
(114, 53140, 150000, 0, 0, 0, 0, 0, 0, 26822),
(114, 49359, 5100, 0, 0, 0, 0, 0, 0, 26822),
(114, 32271, 5100, 0, 0, 0, 0, 0, 0, 26822),
(114, 53142, 168000, 0, 0, 0, 0, 0, 0, 26822),
(114, 49360, 16500, 0, 0, 0, 0, 0, 0, 26822),
(114, 32266, 16500, 0, 0, 0, 0, 0, 0, 26822),
(114, 11416, 16500, 0, 0, 0, 0, 0, 0, 26822),
(114, 33691, 105000, 0, 0, 0, 0, 0, 0, 26822),
(114, 11419, 16500, 0, 0, 0, 0, 0, 0, 26822),
(114, 10059, 16500, 0, 0, 0, 0, 0, 0, 26822),
(406, 127139, 160000, 202, 600, 20219, 0, 0, 0, 26822),
(406, 84413, 160000, 202, 475, 20219, 0, 0, 0, 26822),
(406, 95705, 200000, 202, 500, 20219, 0, 0, 0, 26822),
(406, 12902, 1800, 202, 210, 20219, 0, 0, 0, 26822),
(406, 12905, 1500, 202, 210, 20219, 0, 0, 0, 26822),
(406, 12903, 2000, 202, 215, 20219, 0, 0, 0, 26822),
(406, 12899, 1500, 202, 205, 20219, 0, 0, 0, 26822),
(406, 12897, 2200, 202, 215, 20219, 0, 0, 0, 26822),
(406, 12895, 1500, 202, 205, 20219, 0, 0, 0, 26822),
(406, 30574, 100000, 202, 375, 20219, 0, 0, 0, 26822),
(406, 30570, 50000, 202, 350, 20219, 0, 0, 0, 26822),
(406, 30575, 100000, 202, 375, 20219, 0, 0, 0, 26822),
(406, 30569, 35000, 202, 340, 20219, 0, 0, 0, 26822),
(406, 30568, 25000, 202, 325, 20219, 0, 0, 0, 26822),
(406, 12907, 2600, 202, 235, 20219, 0, 0, 0, 26822),
(406, 12759, 2800, 202, 240, 20219, 0, 0, 0, 26822),
(406, 12906, 2400, 202, 230, 20219, 0, 0, 0, 26822),
(406, 56473, 150000, 202, 350, 20219, 0, 0, 0, 26822);

UPDATE `trainer_spell` SET `ReqSkillRank`=350, `VerifiedBuild`=26822 WHERE (`TrainerId`=405 AND `SpellId`=56514);
UPDATE `trainer_spell` SET `MoneyCost`=50000000, `VerifiedBuild`=26822 WHERE (`TrainerId`=137 AND `SpellId`=90266);
UPDATE `trainer_spell` SET `MoneyCost`=50000000, `VerifiedBuild`=26822 WHERE (`TrainerId`=137 AND `SpellId`=34093);
UPDATE `trainer_spell` SET `MoneyCost`=40000, `VerifiedBuild`=26822 WHERE (`TrainerId`=137 AND `SpellId`=33389);
UPDATE `trainer_spell` SET `MoneyCost`=500000, `VerifiedBuild`=26822 WHERE (`TrainerId`=137 AND `SpellId`=33392);
UPDATE `trainer_spell` SET `MoneyCost`=2500000, `VerifiedBuild`=26822 WHERE (`TrainerId`=137 AND `SpellId`=34092);
UPDATE `trainer_spell` SET `MoneyCost`=50000000, `VerifiedBuild`=26822 WHERE (`TrainerId`=137 AND `SpellId`=90266);
UPDATE `trainer_spell` SET `MoneyCost`=50000000, `VerifiedBuild`=26822 WHERE (`TrainerId`=137 AND `SpellId`=34093);
UPDATE `trainer_spell` SET `MoneyCost`=40000, `VerifiedBuild`=26822 WHERE (`TrainerId`=137 AND `SpellId`=33389);
UPDATE `trainer_spell` SET `MoneyCost`=500000, `VerifiedBuild`=26822 WHERE (`TrainerId`=137 AND `SpellId`=33392);
UPDATE `trainer_spell` SET `MoneyCost`=2500000, `VerifiedBuild`=26822 WHERE (`TrainerId`=137 AND `SpellId`=34092);

DELETE FROM `creature_default_trainer` WHERE `CreatureId` IN (28693, 28702, 28704, 28706, 29509, 29508, 29507, 28700, 28696, 28697, 29514, 29513, 29506, 28694);
INSERT INTO `creature_default_trainer` (`CreatureId`, `TrainerId`) VALUES
(28693, 62),
(28702, 63),
(28704, 133),
(28706, 160),
(29509, 56),
(29508, 56),
(29507, 56),
(28700, 56),
(28696, 196),
(28697, 407),
(29514, 406),
(29513, 405),
(29506, 27),
(28694, 27);

DELETE FROM `creature_default_trainer` WHERE `CreatureId`=29924;
INSERT INTO `creature_default_trainer` (`CreatureId`, `TrainerId`) VALUES
(29924, 27);

DELETE FROM `creature_default_trainer` WHERE `CreatureId` IN (33589, 33590, 33588, 33603, 33581, 33591, 33586, 33587, 33580, 33583);
INSERT INTO `creature_default_trainer` (`CreatureId`, `TrainerId`) VALUES
(33589, 160),
(33590, 29),
(33588, 122),
(33603, 63),
(33581, 56),
(33591, 27),
(33586, 407),
(33587, 136),
(33580, 163),
(33583, 62);
