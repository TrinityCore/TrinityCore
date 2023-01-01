--
UPDATE `smart_scripts` SET `link` = 0 WHERE `entryorguid` = 27213 AND `source_type` = 0 AND `id` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27213 AND `source_type` = 0 AND `id` = 2;

UPDATE `smart_scripts` SET `link` = 0 WHERE `entryorguid` = 21837 AND `source_type` = 0 AND `id` = 4;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 21837 AND `source_type` = 0 AND `id` = 5;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2183701 AND `source_type` = 9;
