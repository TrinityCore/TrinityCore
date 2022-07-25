UPDATE `trainer` SET `VerifiedBuild`=44325 WHERE `Id` IN (877, 880);

UPDATE `trainer_spell` SET `MoneyCost`=6175, `VerifiedBuild`=44325 WHERE (`SpellId`=7928 AND `TrainerId` IN (877,880)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=17100, `VerifiedBuild`=44325 WHERE (`SpellId`=7929 AND `TrainerId` IN (877,880)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=1662, `VerifiedBuild`=44325 WHERE (`SpellId`=3278 AND `TrainerId` IN (877,880)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=380, `VerifiedBuild`=44325 WHERE (`SpellId`=3277 AND `TrainerId` IN (877,880)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=142, `VerifiedBuild`=44325 WHERE (`SpellId`=3276 AND `TrainerId` IN (877,880)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=532000, `VerifiedBuild`=44325 WHERE (`SpellId`=18630 AND `TrainerId` IN (877,880)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=43700, `VerifiedBuild`=44325 WHERE (`SpellId`=10840 AND `TrainerId` IN (877,880)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=123500, `VerifiedBuild`=44325 WHERE (`SpellId`=10841 AND `TrainerId` IN (877,880)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=247000, `VerifiedBuild`=44325 WHERE (`SpellId`=18629 AND `TrainerId` IN (877,880)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=332, `VerifiedBuild`=44325 WHERE (`TrainerId`=880 AND `SpellId` IN (74558,88893)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `VerifiedBuild`=44325 WHERE (`TrainerId`=880 AND `SpellId` IN (74556,27032,45545,7928,7929,3278,3277,74558,88893,74557,27033,45546,3276,18630,10840,10841,18629));
UPDATE `trainer_spell` SET `MoneyCost`=95, `VerifiedBuild`=44325 WHERE (`TrainerId`=880 AND `SpellId`=74557); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=109, `VerifiedBuild`=44325 WHERE (`TrainerId`=880 AND `SpellId`=27033); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=48, `VerifiedBuild`=44325 WHERE (`TrainerId`=880 AND `SpellId`=45546); -- No Faction found! MoneyCost not recalculated!

DELETE FROM `creature_trainer` WHERE (`CreatureID`=5150 AND `MenuID`=4762 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(5150, 880, 4762, 0);

UPDATE `creature_trainer` SET `TrainerID`=877 WHERE (`CreatureID`=6094 AND `MenuID`=5855 AND `OptionID`=0) OR (`CreatureID`=17424 AND `MenuID`=7455 AND `OptionID`=0) OR (`CreatureID`=17214 AND `MenuID`=7380 AND `OptionID`=0) OR (`CreatureID`=16731 AND `MenuID`=5855 AND `OptionID`=0) OR (`CreatureID`=2326 AND `MenuID`=5855 AND `OptionID`=0) OR (`CreatureID`=2329 AND `MenuID`=5855 AND `OptionID`=0);
UPDATE `creature_trainer` SET `TrainerID`=880 WHERE (`CreatureID`=4211 AND `MenuID`=5855 AND `OptionID`=0);

-- Update Template
UPDATE `creature_template` SET `gossip_menu_id`=4762, `minlevel`=60, `maxlevel`=60, `npcflag`=83 WHERE `entry`=5150; -- Nissa Firestone
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `npcflag`=81 WHERE `entry`=2326; -- Thamner Pol
UPDATE `creature_template` SET `gossip_menu_id`=657, `minlevel`=60, `npcflag`=81 WHERE `entry`=56796; -- Angela Leifeld
UPDATE `creature_template` SET `npcflag`=81 WHERE `entry`=2329; -- Michelle Belle
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `npcflag`=83 WHERE `entry`=17424; -- Anchorite Paetheus
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=81 WHERE `entry`=16731; -- Nus
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `npcflag`=83 WHERE `entry`=17214; -- Anchorite Fateema
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=81 WHERE `entry`=4211; -- Dannelor
UPDATE `creature_template` SET `npcflag`=81 WHERE `entry`=6094; -- Byancie
