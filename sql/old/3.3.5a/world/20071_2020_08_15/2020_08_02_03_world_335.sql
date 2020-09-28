-- Remove event for Duggan Wildhammer, added in Cata
DELETE FROM `smart_scripts` WHERE `entryorguid` = 10817 AND `source_type` = 0 AND `id` > 2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1081700 AND `source_type` = 9;
DELETE FROM `creature_text` WHERE `CreatureID` = 10817;
