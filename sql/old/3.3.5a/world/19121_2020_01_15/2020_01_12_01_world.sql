-- 
DELETE FROM `creature_equip_template` WHERE `CreatureID`=38493;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`) VALUES
(38493, 1, 40595, 49933, 0), -- 38493
(38493, 2, 46107, 49933, 0); -- 38493
UPDATE `creature` SET `equipment_id`=2 WHERE `guid` IN (112005,111997,111996);
