-- 
UPDATE `creature_template_addon` SET `auras`="31261" WHERE `entry` IN (20561);
UPDATE `smart_scripts` SET `action_type`=41, `action_param1`=0 WHERE `entryorguid` IN (20561) AND `source_type`=0 AND `id`=2;
