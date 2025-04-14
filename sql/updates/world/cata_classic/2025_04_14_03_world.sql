DELETE FROM `trainer` WHERE `Id` IN (32, 44, 17, 15, 168, 145);
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(32, 0, 'Hello, warlock!  Ready for some training?', 60192),
(44, 0, 'Hello, mage!  Ready for some training?', 60192),
(17, 0, 'Hello, rogue!  Ready for some training?', 60192),
(15, 0, 'Hello, hunter!  Ready for some training?', 60192),
(168, 0, 'Hello, paladin!  Ready for some training?', 60192),
(145, 0, 'Hello, warrior!  Ready for some training?', 60192);

UPDATE `trainer` SET `VerifiedBuild`=60192 WHERE `Id`=3;

DELETE FROM `trainer_spell` WHERE (`TrainerId`=32 AND `SpellId` IN (172,348,1454)) OR (`TrainerId`=44 AND `SpellId` IN (2136,5143)) OR (`TrainerId`=17 AND `SpellId` IN (2098,1784)) OR (`TrainerId`=15 AND `SpellId` IN (56641,1494)) OR (`TrainerId`=168 AND `SpellId` IN (465,20154,20271)) OR (`TrainerId`=145 AND `SpellId` IN (100,34428));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(32, 172, 110, 0, 0, 0, 0, 0, 4, 60192), -- MoneyCost recalculated
(32, 348, 65, 0, 0, 0, 0, 0, 3, 60192), -- MoneyCost recalculated
(32, 1454, 160, 0, 0, 0, 0, 0, 5, 60192), -- MoneyCost recalculated
(44, 2136, 160, 0, 0, 0, 0, 0, 5, 60192), -- MoneyCost recalculated
(44, 5143, 65, 0, 0, 0, 0, 0, 3, 60192), -- MoneyCost recalculated
(17, 2098, 65, 0, 0, 0, 0, 0, 3, 60192), -- MoneyCost recalculated
(17, 1784, 160, 0, 0, 0, 0, 0, 5, 60192), -- MoneyCost recalculated
(15, 56641, 65, 0, 0, 0, 0, 0, 3, 60192), -- MoneyCost recalculated
(15, 1494, 110, 0, 0, 0, 0, 0, 4, 60192), -- MoneyCost recalculated
(168, 465, 160, 0, 0, 0, 0, 0, 5, 60192), -- MoneyCost recalculated
(168, 20154, 65, 0, 0, 0, 0, 0, 3, 60192), -- MoneyCost recalculated
(168, 20271, 65, 0, 0, 0, 0, 0, 3, 60192), -- MoneyCost recalculated
(145, 100, 65, 0, 0, 0, 0, 0, 3, 60192), -- MoneyCost recalculated
(145, 34428, 160, 0, 0, 0, 0, 0, 5, 60192); -- MoneyCost recalculated

UPDATE `trainer_spell` SET `MoneyCost`=160, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=17); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=2061);
UPDATE `trainer_spell` SET `MoneyCost`=110, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=589); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=21795, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId` IN (83968,596)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=25145, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId` IN (89745,27683)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=248120, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=87495); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=315175, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=73325); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=261530, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=73510); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=435, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=139); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=26825, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=6346); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=11735, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=1706); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=28500, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=453); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=1205, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=8122); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=30175, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=8129); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=615, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=8092); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=1585, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId` IN (21562,2006)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=228000, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=64843); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=103940, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=64901); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=15090, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=605); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=2300, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=2050); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=18440, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=2060); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=167645, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=32375); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=10060, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId` IN (32379,9484)); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=23470, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=32546); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=130765, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=33076); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=13410, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=2096); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=5700, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=586); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=187765, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=48045); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=288355, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=73413); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=3115, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=14914); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=90530, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=15237); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=6705, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=527); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=4695, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=528); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=320, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=588); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=117355, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=34433); -- MoneyCost recalculated
UPDATE `trainer_spell` SET `MoneyCost`=8380, `VerifiedBuild`=60192 WHERE (`TrainerId`=3 AND `SpellId`=2944); -- MoneyCost recalculated

DELETE FROM `creature_trainer` WHERE (`CreatureID`=459 AND `MenuID`=1503 AND `OptionID`=0) OR (`CreatureID`=198 AND `MenuID`=4660 AND `OptionID`=0) OR (`CreatureID`=375 AND `MenuID`=4665 AND `OptionID`=0) OR (`CreatureID`=915 AND `MenuID`=4659 AND `OptionID`=0) OR (`CreatureID`=43278 AND `MenuID`=11860 AND `OptionID`=0) OR (`CreatureID`=925 AND `MenuID`=4663 AND `OptionID`=0) OR (`CreatureID`=911 AND `MenuID`=4650 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(459, 32, 1503, 0),
(198, 44, 4660, 0),
(375, 3, 4665, 0),
(915, 17, 4659, 0),
(43278, 15, 11860, 0),
(925, 168, 4663, 0),
(911, 145, 4650, 0);
