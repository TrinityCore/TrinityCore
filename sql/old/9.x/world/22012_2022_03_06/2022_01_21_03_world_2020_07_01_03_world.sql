--
UPDATE `smart_scripts` SET `target_type` = 19, `target_param1` = 11152, `target_param2` = 0 WHERE `entryorguid` IN (2246,2248,2250,2252,2626,2627,2628,2629,2630,2631,2632,2633,2634,2635,2636,2637) AND `source_type` = 2 AND `id` = 0;
UPDATE `smart_scripts` SET `target_type` = 19, `target_param1` = 7917, `target_param2` = 0 WHERE `entryorguid` = 1125 AND `source_type` = 2 AND `id` IN (1,2);
UPDATE `smart_scripts` SET `target_type` = 19, `target_param1` = 20242, `target_param2` = 0 WHERE `entryorguid` = 4495 AND `source_type` = 2 AND `id` IN (1,2);
UPDATE `smart_scripts` SET `target_type` = 19, `target_param1` = 19227, `target_param2` = 0 WHERE `entryorguid` = 4389 AND `source_type` = 2 AND `id` IN (1,2);

UPDATE `smart_scripts` SET `comment` = "Areatrigger (Lower City) - On Trigger - Store Targetlist" WHERE `entryorguid` = 4389 AND `source_type` = 2 AND `id` = 0;
UPDATE `smart_scripts` SET `comment` = "Areatrigger (Lower City) - On Link - Send Target 1 (Griftah)" WHERE `entryorguid` = 4389 AND `source_type` = 2 AND `id` = 1;
UPDATE `smart_scripts` SET `comment` = "Areatrigger (Lower City) - On Link - Set Data 0 1 (Griftah)" WHERE `entryorguid` = 4389 AND `source_type` = 2 AND `id` = 2;
