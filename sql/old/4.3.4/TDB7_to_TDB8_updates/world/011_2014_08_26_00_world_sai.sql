UPDATE `smart_scripts` SET `event_flags`=0 WHERE  `entryorguid`=5261 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=0 WHERE  `entryorguid`=5263 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=0 WHERE  `entryorguid`=5269 AND `source_type`=0 AND `id`IN(0,1,2);
UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid`=5269 AND `source_type`=0 AND `id`IN(3);
