-- 
UPDATE `creature` SET `equipment_id`=-1 WHERE `id` IN (1976, 14901, 23745, 24015, 24062, 24212, 28579, 32710, 32711, 34838); 
UPDATE `creature` SET `equipment_id`=0 WHERE `guid` IN (34838,24212,28579,24062,23745,24015);
UPDATE `creature` SET `equipment_id`=1 WHERE `guid` IN (1976,14901,32710,32711);
