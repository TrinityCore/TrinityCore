-- Duggan Wildhammer faction
UPDATE `creature_template` SET `faction`=1055 WHERE `entry`=10817;

-- Duggan Wildhammer equipment
UPDATE `creature_equip_template` SET `ItemID1`=12951, `VerifiedBuild`=0 WHERE `CreatureID`=10817 AND `ID`=1;

-- Remove again event
DELETE FROM `smart_scripts` WHERE `entryorguid`=10817 AND `source_type`=0 AND `id` > 2;
DELETE FROM `creature_text` WHERE `CreatureID`=10817;
