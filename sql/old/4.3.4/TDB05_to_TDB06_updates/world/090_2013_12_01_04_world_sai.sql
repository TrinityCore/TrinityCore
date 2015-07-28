-- Fix Felweaver Scornn SAI
UPDATE `smart_scripts` SET `event_type`=61, `event_flags`=0, `event_param2`=0 WHERE `entryorguid`=5822 AND `id` IN (11,12);
