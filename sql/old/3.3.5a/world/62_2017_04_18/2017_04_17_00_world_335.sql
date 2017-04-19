DELETE FROM `npc_vendor` WHERE `entry` IN(32296,32294) AND `item`=44115 AND `ExtendedCost`=2576;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`, `VerifiedBuild`) VALUES 
(32296, 0, 44115, 0, 0, 2576, 0),
(32294, 0, 44115, 0, 0, 2576, 0);
