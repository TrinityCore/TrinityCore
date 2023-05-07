-- UPDATE Argent Crusader and Knight of the Ebon Blade to run instead walk to the ICC entrance
UPDATE `smart_scripts` SET `action_param1` = 1 WHERE `entryorguid` IN (38493, 38505) AND `source_type` = 0 AND `id` = 0;
