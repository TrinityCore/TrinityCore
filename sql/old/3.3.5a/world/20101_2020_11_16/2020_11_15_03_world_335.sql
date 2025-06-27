-- Linked to building events spawns with 1, linked to actual events spawns with 2 or 3, maybe they're set randomly on linked
-- to guid, I have no idea. Let's use only 2 now
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=14849 AND `ID`=2) OR (`CreatureID`=14849 AND `ID`=3);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES
(14849, 2, 3362, 13604, 0, 12340), -- Darkmoon Carnie
(14849, 3, 3362, 13605, 0, 12340); -- Darkmoon Carnie

UPDATE `creature` SET `equipment_id` = 2 WHERE `id` = 14849 AND `guid` IN (SELECT `guid` FROM `game_event_creature` WHERE `eventEntry` IN (3,4,5));
UPDATE `creature_equip_template` SET `ItemID2`=12865, `VerifiedBuild`=12340 WHERE (`CreatureID`=14822 AND `ID`=1); -- Sayge
