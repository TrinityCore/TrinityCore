-- Fix SAI for Lothos Riftwaker
UPDATE `smart_scripts` SET `event_param1`=5750 WHERE `entryorguid`=14387 AND `id`=0;
UPDATE `smart_scripts` SET `event_param1`=0 WHERE `entryorguid`=14387 AND `id`=1;
