-- Portal Trainer Darnassus Entry: 4165 Ellisa Dumas
DELETE FROM `trainer` WHERE `Id`=130;
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(130, 0, 'Welcome!', 44325);

DELETE FROM `trainer_spell` WHERE (`TrainerId`=130 AND `SpellId` IN (344597,344587,281403,281400,224869,224871,176248,176246,132621,132620,88342,88345,33690,3562,3565,3561,53140,49359,32271,53142,49360,32266,11416,33691,11419,10059));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(130, 344597, 159600, 0, 0, 0, 0, 0, 58, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 344587, 159600, 0, 0, 0, 0, 0, 52, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 281403, 712500, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 281400, 712500, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 224869, 475000, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 224871, 475000, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 176248, 603250, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 176246, 603250, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 132621, 401850, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 132620, 401850, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 88342, 267900, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 88345, 267900, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 33690, 76950, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 3562, 4845, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 3565, 4845, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 3561, 4845, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 53140, 142500, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 49359, 4845, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 32271, 4845, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 53142, 159600, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 49360, 15675, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 32266, 15675, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 11416, 15675, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 33691, 99750, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 11419, 15675, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(130, 10059, 15675, 0, 0, 0, 0, 0, 0, 44325); -- No Faction found! MoneyCost not recalculated!

DELETE FROM `creature_trainer` WHERE (`CreatureID`=4165 AND `MenuID`=4821 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(4165, 130, 4821, 0);

-- Portal Trainer Theramore Entry: 27703 Ysuria
UPDATE `trainer` SET `VerifiedBuild`=44325 WHERE `Id`=144;

DELETE FROM `trainer_spell` WHERE (`TrainerId`=144 AND `SpellId` IN (344597,344587,281403,281400));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(144, 344597, 168000, 0, 0, 0, 0, 0, 58, 44325), -- No Faction found! MoneyCost not recalculated!
(144, 344587, 168000, 0, 0, 0, 0, 0, 52, 44325), -- No Faction found! MoneyCost not recalculated!
(144, 281403, 750000, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(144, 281400, 750000, 0, 0, 0, 0, 0, 24, 44325); -- No Faction found! MoneyCost not recalculated!

UPDATE `trainer_spell` SET `ReqLevel`=21, `VerifiedBuild`=44325 WHERE (`TrainerId`=144 AND `SpellId` IN (224869,176248,132621,88342,33690,53140)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `ReqLevel`=24, `VerifiedBuild`=44325 WHERE (`TrainerId`=144 AND `SpellId` IN (224871,176246,132620,88345,53142,33691)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `VerifiedBuild`=44325 WHERE (`TrainerId`=144 AND `SpellId` IN (3562,3565,3561,49359,32271,49360,32266,11416,11419,10059));

-- Portal Trainer Exodar Entry: 16755 Lunaraa
DELETE FROM `trainer` WHERE `Id`=140;
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(140, 0, 'Welcome!', 44325);

DELETE FROM `trainer_spell` WHERE (`TrainerId`=140 AND `SpellId` IN (344597,344587,281403,281400,224869,224871,176248,176246,132621,132620,88342,88345,33690,3562,3565,3561,53140,49359,32271,53142,49360,32266,11416,33691,11419,10059));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(140, 344597, 159600, 0, 0, 0, 0, 0, 58, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 344587, 159600, 0, 0, 0, 0, 0, 52, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 281403, 712500, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 281400, 712500, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 224869, 475000, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 224871, 475000, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 176248, 603250, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 176246, 603250, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 132621, 401850, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 132620, 401850, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 88342, 267900, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 88345, 267900, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 33690, 76950, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 3562, 4845, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 3565, 4845, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 3561, 4845, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 53140, 142500, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 49359, 4845, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 32271, 4845, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 53142, 159600, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 49360, 15675, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 32266, 15675, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 11416, 15675, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 33691, 99750, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 11419, 15675, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(140, 10059, 15675, 0, 0, 0, 0, 0, 0, 44325); -- No Faction found! MoneyCost not recalculated!

DELETE FROM `creature_trainer` WHERE (`CreatureID`=16755 AND `MenuID`=4824 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(16755, 140, 4824, 0);

-- Portal Trainer Stormwind Entry: 164956 Azunla (not yet spawned)
UPDATE `trainer` SET `Greeting`='Welcome!', `VerifiedBuild`=44325 WHERE `Id`=148;

DELETE FROM `trainer_spell` WHERE (`TrainerId`=148 AND `SpellId` IN (344597,344587,281403,281400));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(148, 344597, 159600, 0, 0, 0, 0, 0, 58, 44325), -- No Faction found! MoneyCost not recalculated!
(148, 344587, 159600, 0, 0, 0, 0, 0, 52, 44325), -- No Faction found! MoneyCost not recalculated!
(148, 281403, 712500, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(148, 281400, 712500, 0, 0, 0, 0, 0, 24, 44325); -- No Faction found! MoneyCost not recalculated!

UPDATE `trainer_spell` SET `MoneyCost`=475000, `ReqLevel`=21, `VerifiedBuild`=44325 WHERE (`TrainerId`=148 AND `SpellId`=224869); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=475000, `ReqLevel`=24, `VerifiedBuild`=44325 WHERE (`TrainerId`=148 AND `SpellId`=224871); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=603250, `ReqLevel`=21, `VerifiedBuild`=44325 WHERE (`TrainerId`=148 AND `SpellId`=176248); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=603250, `ReqLevel`=24, `VerifiedBuild`=44325 WHERE (`TrainerId`=148 AND `SpellId`=176246); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=401850, `ReqLevel`=21, `VerifiedBuild`=44325 WHERE (`TrainerId`=148 AND `SpellId`=132621); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=401850, `ReqLevel`=24, `VerifiedBuild`=44325 WHERE (`TrainerId`=148 AND `SpellId`=132620); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=267900, `ReqLevel`=21, `VerifiedBuild`=44325 WHERE (`TrainerId`=148 AND `SpellId`=88342); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=267900, `ReqLevel`=24, `VerifiedBuild`=44325 WHERE (`TrainerId`=148 AND `SpellId`=88345); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=76950, `ReqLevel`=21, `VerifiedBuild`=44325 WHERE (`TrainerId`=148 AND `SpellId`=33690); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=4845, `VerifiedBuild`=44325 WHERE (`TrainerId`=148 AND `SpellId` IN (3562,3565,3561,49359,32271)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=142500, `ReqLevel`=21, `VerifiedBuild`=44325 WHERE (`TrainerId`=148 AND `SpellId`=53140); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=159600, `ReqLevel`=24, `VerifiedBuild`=44325 WHERE (`TrainerId`=148 AND `SpellId`=53142); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=15675, `VerifiedBuild`=44325 WHERE (`TrainerId`=148 AND `SpellId` IN (49360,32266,11416,11419,10059)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=99750, `ReqLevel`=24, `VerifiedBuild`=44325 WHERE (`TrainerId`=148 AND `SpellId`=33691); -- No Faction found! MoneyCost not recalculated!

-- Portal Trainer Ironforge Entry: 2489 Milstaff Stormeye
UPDATE `trainer` SET `VerifiedBuild`=44325 WHERE `Id`=129;

DELETE FROM `trainer_spell` WHERE (`TrainerId`=129 AND `SpellId` IN (344597,344587,281403,281400));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(129, 344597, 159600, 0, 0, 0, 0, 0, 58, 44325), -- No Faction found! MoneyCost not recalculated!
(129, 344587, 159600, 0, 0, 0, 0, 0, 52, 44325), -- No Faction found! MoneyCost not recalculated!
(129, 281403, 712500, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(129, 281400, 712500, 0, 0, 0, 0, 0, 24, 44325); -- No Faction found! MoneyCost not recalculated!

UPDATE `trainer_spell` SET `MoneyCost`=475000, `ReqLevel`=21, `VerifiedBuild`=44325 WHERE (`TrainerId`=129 AND `SpellId`=224869); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=475000, `ReqLevel`=24, `VerifiedBuild`=44325 WHERE (`TrainerId`=129 AND `SpellId`=224871); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=603250, `ReqLevel`=21, `VerifiedBuild`=44325 WHERE (`TrainerId`=129 AND `SpellId`=176248); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=603250, `ReqLevel`=24, `VerifiedBuild`=44325 WHERE (`TrainerId`=129 AND `SpellId`=176246); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=401850, `ReqLevel`=21, `VerifiedBuild`=44325 WHERE (`TrainerId`=129 AND `SpellId`=132621); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=401850, `ReqLevel`=24, `VerifiedBuild`=44325 WHERE (`TrainerId`=129 AND `SpellId`=132620); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=267900, `ReqLevel`=21, `VerifiedBuild`=44325 WHERE (`TrainerId`=129 AND `SpellId`=88342); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=267900, `ReqLevel`=24, `VerifiedBuild`=44325 WHERE (`TrainerId`=129 AND `SpellId`=88345); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=76950, `ReqLevel`=21, `VerifiedBuild`=44325 WHERE (`TrainerId`=129 AND `SpellId`=33690); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=4845, `ReqLevel`=0, `VerifiedBuild`=44325 WHERE (`TrainerId`=129 AND `SpellId` IN (3562,3565,49359,32271)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=4845, `VerifiedBuild`=44325 WHERE (`TrainerId`=129 AND `SpellId`=3561); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=142500, `ReqLevel`=21, `VerifiedBuild`=44325 WHERE (`TrainerId`=129 AND `SpellId`=53140); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=159600, `ReqLevel`=24, `VerifiedBuild`=44325 WHERE (`TrainerId`=129 AND `SpellId`=53142); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=15675, `ReqLevel`=0, `VerifiedBuild`=44325 WHERE (`TrainerId`=129 AND `SpellId` IN (49360,32266,11416,11419)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=99750, `ReqLevel`=24, `VerifiedBuild`=44325 WHERE (`TrainerId`=129 AND `SpellId`=33691); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=15675, `VerifiedBuild`=44325 WHERE (`TrainerId`=129 AND `SpellId`=10059); -- No Faction found! MoneyCost not recalculated!

-- Portal Trainer Boralus Entry: 144319 Yvia Wavebound
DELETE FROM `trainer` WHERE `Id`=986;
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(986, 0, 'Welcome!', 44325);

DELETE FROM `trainer_spell` WHERE (`TrainerId`=986 AND `SpellId` IN (344597,344587,281403,281400,224869,224871,176248,176246,132621,132620,88342,88345,33690,3562,3565,3561,53140,49359,32271,53142,49360,32266,11416,33691,11419,10059));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(986, 344597, 151200, 0, 0, 0, 0, 0, 58, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 344587, 151200, 0, 0, 0, 0, 0, 52, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 281403, 675000, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 281400, 675000, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 224869, 450000, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 224871, 450000, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 176248, 571500, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 176246, 571500, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 132621, 380700, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 132620, 380700, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 88342, 253800, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 88345, 253800, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 33690, 72900, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 3562, 4590, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 3565, 4590, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 3561, 4590, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 53140, 135000, 0, 0, 0, 0, 0, 21, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 49359, 4590, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 32271, 4590, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 53142, 151200, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 49360, 14850, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 32266, 14850, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 11416, 14850, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 33691, 94500, 0, 0, 0, 0, 0, 24, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 11419, 14850, 0, 0, 0, 0, 0, 0, 44325), -- No Faction found! MoneyCost not recalculated!
(986, 10059, 14850, 0, 0, 0, 0, 0, 0, 44325); -- No Faction found! MoneyCost not recalculated!

DELETE FROM `creature_trainer` WHERE (`CreatureID`=144310 AND `MenuID`=23405 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(144310, 986, 23405, 0);

-- Update Template
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=49 WHERE `entry`=4165; -- Elissa Dumas
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=27703; -- Ysuria
UPDATE `creature_template` SET `npcflag`=49 WHERE `entry`=16755; -- Lunaraa
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1078, `npcflag`=48, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=164956; -- Azunla
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=49 WHERE `entry`=2489; -- Milstaff Stormeye
UPDATE `creature_template` SET `gossip_menu_id`=23405, `npcflag`=49 WHERE `entry`=144310; -- Yvia Wavebound
