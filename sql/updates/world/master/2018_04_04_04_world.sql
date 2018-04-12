-- 
DELETE FROM `npc_vendor` WHERE `entry`=44027 AND `item` IN (2320,2321,2325,2604,2605,4289,4291,4340,4341,4342,6260,6261,7005,8343,10290,14341,38426);
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`ExtendedCost`,`type`,`PlayerConditionID`,`IgnoreFiltering`,`VerifiedBuild`) VALUES
(44027,  1,  7005, 0, 0, 1, 0, 0, 25961), -- Skinning Knife
(44027,  2,  4289, 0, 0, 1, 0, 0, 25961), -- Salt
(44027,  3,  2320, 0, 0, 1, 0, 0, 25961), -- Coarse Thread
(44027,  4,  2321, 0, 0, 1, 0, 0, 25961), -- Fine Thread
(44027,  5,  4291, 0, 0, 1, 0, 0, 25961), -- Silken Thread
(44027,  6,  8343, 0, 0, 1, 0, 0, 25961), -- Heavy Silken Thread
(44027,  7, 14341, 0, 0, 1, 0, 0, 25961), -- Rune Thread
(44027,  8, 38426, 0, 0, 1, 0, 0, 25961), -- Eternium Thread
(44027,  9,  2325, 0, 0, 1, 0, 0, 25961), -- Black Dye
(44027, 10,  6260, 0, 0, 1, 0, 0, 25961), -- Blue Dye
(44027, 11,  2604, 0, 0, 1, 0, 0, 25961), -- Red Dye
(44027, 13,  4340, 0, 0, 1, 0, 0, 25961), -- Gray Dye
(44027, 12,  2605, 0, 0, 1, 0, 0, 25961), -- Green Dye
(44027, 14,  4341, 0, 0, 1, 0, 0, 25961), -- Yellow Dye
(44027, 15,  6261, 0, 0, 1, 0, 0, 25961), -- Orange Dye
(44027, 16,  4342, 0, 0, 1, 0, 0, 25961), -- Purple Dye
(44027, 17, 10290, 0, 0, 1, 0, 0, 25961); -- Pink Dye

