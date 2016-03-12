-- Equipment Template for NPC Unworthy Initiate
DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (29519, 29520, 29565, 29566, 29567);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
(29519, 1, 38707, 0, 0, 0),
(29520, 1, 38707, 0, 0, 0),
(29565, 1, 38707, 0, 0, 0),
(29566, 1, 38707, 0, 0, 0),
(29567, 1, 38707, 0, 0, 0);