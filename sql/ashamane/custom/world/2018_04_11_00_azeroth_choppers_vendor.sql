-- Table `creature_template`
UPDATE `creature_template` SET `faction` = 35 WHERE (entry = 87501);

-- Table `npc_vendor` of entry 87501
DELETE FROM `npc_vendor` WHERE (entry = 87501) AND (item IN (116788));
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`, `OverrideGoldCost`, `VerifiedBuild`, `type`, `PlayerConditionID`, `IgnoreFiltering`) VALUES
(87501, 1, 116788, 0, 0, 0, 100000, 0, 1, 0, 0);
