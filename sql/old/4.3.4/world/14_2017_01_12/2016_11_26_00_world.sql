--
DELETE FROM `npc_vendor` WHERE `entry`=50305 AND `slot` IN (1,2,3,4,5);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`, `type`, `VerifiedBuild`) VALUES
(50305, 1, 67526, 0, 0, 0, 1, 0), -- Darnassian Satchel
(50305, 2, 64886, 0, 0, 0, 1, 0), -- Shroud of Darnassus
(50305, 3, 64887, 0, 0, 0, 1, 0), -- Cape of Darnassus
(50305, 4, 64888, 0, 0, 0, 1, 0), -- Mantle of Darnassus
(50305, 5, 45579, 0, 0, 0, 1, 0); -- Darnassus Tabard
--
