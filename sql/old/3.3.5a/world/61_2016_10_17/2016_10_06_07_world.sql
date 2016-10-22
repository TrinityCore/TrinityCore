-- Update equip for Brewfest Reveler
DELETE FROM `creature_equip_template` WHERE `CreatureID`=24484;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`) VALUES
(24484, 8, 37059, 0, 0), -- 24484
(24484, 7, 2704, 0, 0), -- 24484
(24484, 6, 13861, 0, 0), -- 24484
(24484, 5, 46733, 0, 0), -- 24484
(24484, 4, 2703, 0, 13859), -- 24484
(24484, 3, 33963, 0, 0), -- 24484
(24484, 2, 2705, 0, 0), -- 24484
(24484, 1, 2703, 0, 0); -- 24484
