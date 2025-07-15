-- Fix Gahz'rilla random movement on wp 2 end
UPDATE `smart_scripts` SET `event_type`=58, `comment`="Gahz'rilla - On Waypoint 2 Ended - Start Random Movement" WHERE `entryorguid`=7273 AND `source_type`=0 AND `id`=6;
