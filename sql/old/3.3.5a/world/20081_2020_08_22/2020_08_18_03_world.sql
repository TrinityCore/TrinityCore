-- Instructor Razuvious Event
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2835700,2835701,-129391,12939100,-129390,12939000,28391) AND `action_type`=48;
-- Acherus Necromancer SAI
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=-129391 AND `id`=0 AND `link`=1 AND `source_type`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=-129390 AND `id`=0 AND `link`=1 AND `source_type`=0;
-- Death Knight Initiate SAI
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid`=28391 AND `id`=1 AND `link`=6 AND `source_type`=0;

-- Gothik the Harvester Event
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28890,28906,28897) AND `action_type`=48;
-- Scourge Gryphon SAI
UPDATE `smart_scripts` SET `event_type`=38,`event_param1`=1,`event_param2`=1 WHERE `entryorguid`=28906 AND `id`=1 AND `event_type`=61 AND `source_type`=0;
UPDATE `smart_scripts` SET `event_type`=38,`event_param1`=2,`event_param2`=2 WHERE `entryorguid`=28906 AND `id`=4 AND `event_type`=61 AND `source_type`=0;
