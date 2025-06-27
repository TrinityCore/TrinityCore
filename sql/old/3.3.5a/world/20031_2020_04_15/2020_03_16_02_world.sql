-- 
UPDATE `creature` SET `equipment_id`=1 WHERE `id` IN (24927,32700);
DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (24927,32700);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
(24927, 1, 2716, 0, 0, 0),
(32700, 1, 44638, 0, 0, 0);
