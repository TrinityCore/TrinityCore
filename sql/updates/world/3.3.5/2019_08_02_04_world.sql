-- 
DELETE FROM `creature_template_addon` WHERE `entry` IN (27610);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `emote`, `bytes1`, `bytes2`, `auras`) VALUES
(27610,0,0,0,0,"29266");

DELETE FROM `creature_equip_template` WHERE `CreatureID`=27566 AND `ID` IN (2,3);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`) VALUES
(27566, 2, 2827, 0, 0), -- 27566
(27566, 3, 12856, 0, 0); -- 27566

UPDATE `creature` SET `equipment_id`=3 WHERE `id`=27566 AND `guid` IN (112384);
UPDATE `creature` SET `equipment_id`=2 WHERE `id`=27566 AND `guid` IN (112379,112378);

UPDATE `creature_addon` SET `emote`=28 WHERE `guid` IN (112378);
UPDATE `creature` SET `MovementType` =0, `spawndist`=0 WHERE `id`=27529;
