DELETE FROM `npc_vendor` WHERE `entry`=50488 AND `item`=253168 AND `ExtendedCost`=0 AND `type`=1;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(50488, 1, 253168, 0, 0, 1, 0, 0, 69933); -- Earthen Storage Crate

UPDATE `npc_vendor` SET `slot`=6, `PlayerConditionID`=12248, `VerifiedBuild`=69933 WHERE (`entry`=50488 AND `item`=64908 AND `ExtendedCost`=0 AND `type`=1); -- Shroud of Orgrimmar
UPDATE `npc_vendor` SET `slot`=5, `PlayerConditionID`=12248, `VerifiedBuild`=69933 WHERE (`entry`=50488 AND `item`=64909 AND `ExtendedCost`=0 AND `type`=1); -- Cape of Orgrimmar
UPDATE `npc_vendor` SET `slot`=4, `PlayerConditionID`=12248, `VerifiedBuild`=69933 WHERE (`entry`=50488 AND `item`=64910 AND `ExtendedCost`=0 AND `type`=1); -- Mantle of Orgrimmar
UPDATE `npc_vendor` SET `slot`=3, `PlayerConditionID`=12247, `VerifiedBuild`=69933 WHERE (`entry`=50488 AND `item`=67533 AND `ExtendedCost`=0 AND `type`=1); -- Orgrimmar Satchel
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=69933 WHERE (`entry`=50488 AND `item`=45581 AND `ExtendedCost`=0 AND `type`=1); -- Orgrimmar Tabard
