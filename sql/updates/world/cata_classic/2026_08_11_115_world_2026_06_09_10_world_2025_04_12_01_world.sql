-- Fix Impsy random movement on wp 11 end
UPDATE `smart_scripts` SET `event_type`=58, `comment`="Impsy - On Waypoint 11 Ended - Start Random Movement" WHERE `entryorguid`=14470 AND `source_type`=0 AND `id`=3;
