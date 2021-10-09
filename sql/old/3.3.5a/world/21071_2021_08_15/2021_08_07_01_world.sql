--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2706 AND `source_type` = 0 AND `id` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3937 AND `source_type` = 0 AND `id` IN (1,2);
DELETE FROM `creature_text` WHERE `CreatureID` = 3937 AND `GroupID` = 1;
