/*
-- 
-- Change weapons of Commander Springvale to the correct pre-cataclysm ones
UPDATE `creature_equip_template` SET `ItemID1`=5191, `ItemID2`=1201 WHERE `CreatureID`=4278 AND `ID`=1;

-- Update Lupine Horror and Slavering Worg MovementType to stand still
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `guid` IN (16240, 16238);

-- Add chain aggro to Worgs infront of Wolf Master Nandos
DELETE FROM `creature_formations` WHERE `leaderGUID`=16241;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(16241, 16241, 0, 0, 3),
(16241, 16240, 0, 0, 3),
(16241, 16238, 0, 0, 3),
(16241, 16239, 0, 0, 3);

-- Add random movement to Razorclaw the Butcher
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE `guid`=16253;
*/
