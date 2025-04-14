DELETE FROM `npc_vendor` WHERE (`entry`=52034 AND `item`=1901 AND `ExtendedCost`=3408 AND `type`=2);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(52034, 9, 1901, 25000, 3408, 2, 0, 0, 60192); -- 1901
