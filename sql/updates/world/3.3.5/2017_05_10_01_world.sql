-- 
UPDATE `smart_scripts` SET `action_type`=41, `action_param1`=0, `comment`="Time Watcher - On wp Ended - Despawn" WHERE `entryorguid` IN (-23440, -23439, -23438, -23437, -23436, -23433, -23432, -23429, -23426) AND `source_type`=0 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1991800, 1991801) AND `source_type`=9;
UPDATE `creature` SET `spawntimesecs`=30 WHERE  `id`=19918;
