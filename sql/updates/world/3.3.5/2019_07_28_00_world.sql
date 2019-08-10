-- 
UPDATE `smart_scripts` SET `action_param3`=1 WHERE `entryorguid`=3568 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=10, `link`=0, `event_type`=19, `event_param1`=938, `comment`= "Mist - On Quest Accepted- Set faction" WHERE `entryorguid`=3568 AND `source_type`=0 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3568 AND `source_type`=0 AND `id`=4;
