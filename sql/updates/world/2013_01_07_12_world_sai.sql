-- Fixup some runtime errors, linked events that were not SMART_EVENT_LINK
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid`=38017 AND `id`=1 AND `source_type`=0;
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid`=1443 AND `id`=1 AND `source_type`=0;
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid`=3448 AND `id` IN (1, 2, 3) AND `source_type`=0;
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid`=3616 AND `id` IN (1, 2) AND `source_type`=0;
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid`=4049 AND `id`=1 AND `source_type`=0;
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid`=305400 AND `id` IN (1, 2) AND `source_type`=9;
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid`=83600 AND `id` IN (1, 2, 3) AND `source_type`=9;
