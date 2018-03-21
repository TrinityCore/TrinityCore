-- 
UPDATE `smart_scripts` SET `target_type`=23 WHERE `entryorguid`=21926 AND `source_type`=0 AND `id`=4 AND `link`=5;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20635,20771) AND `source_type`=0 AND `id`=3 AND `target_type`=12;
UPDATE `smart_scripts` SET `id`=3 WHERE `entryorguid` IN (20635,20771) AND `source_type`=0 AND `id`=4 AND `action_type`=80;
