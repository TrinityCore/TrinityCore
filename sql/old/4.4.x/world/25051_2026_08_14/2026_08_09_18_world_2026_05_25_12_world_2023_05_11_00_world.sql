-- Guard Slip'kik minor movement correction
UPDATE `creature_template` SET `speed_walk`=2 WHERE `entry`=14323;

UPDATE `creature_template_addon` SET `SheathState`=1 WHERE `entry` IN (14323, 14321, 14326, 14327, 14325, 11501, 14324, 11488, 11486);

UPDATE `creature` SET `equipment_id`=1 WHERE `guid`=56945 AND `id`=14324;
DELETE FROM `creature_equip_template` WHERE `CreatureID`=14324 AND `ID`=1;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
(14324, 1, 2176, 0, 0, 0);
