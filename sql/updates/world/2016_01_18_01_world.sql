UPDATE `creature` SET `MovementType`=1 WHERE `guid` IN (134870, 134856, 134857, 134859, 134861, 134862, 134863, 134864, 134865, 134866, 134868, 134871, 134878, 134872, 134873, 134874, 134875);
UPDATE `creature` SET `spawndist`=0 WHERE `guid`=131180;

UPDATE `smart_scripts` SET `event_type`=61 WHERE  `entryorguid`=26853 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `event_type`=61 WHERE  `entryorguid`=26881 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `event_type`=61 WHERE  `entryorguid`=20234 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `event_type`=61 WHERE  `entryorguid`=26876 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `event_type`=61 WHERE  `entryorguid`=26602 AND `source_type`=0 AND `id`=2 AND `link`=0;
