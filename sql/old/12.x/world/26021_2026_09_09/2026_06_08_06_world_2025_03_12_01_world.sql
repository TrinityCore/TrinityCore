-- Add correct equipment to Darkspear Dragon Hunter
SET @NPC=26870;
DELETE FROM `creature_equip_template` WHERE `CreatureID`=@NPC;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
(@NPC, 1, 36790, 0, 0, 59570),
(@NPC, 2, 36791, 0, 0, 59570),
(@NPC, 3, 36792, 0, 0, 59570);

UPDATE `creature` SET `equipment_id`=-1 WHERE `id`=@NPC;
UPDATE `creature_addon` SET `emote`=425 WHERE `guid`=203379;
UPDATE `creature_addon` SET `PvpFlags`=0 WHERE `guid` BETWEEN 203380 AND 203385;
