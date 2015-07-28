-- Fix Saronite Mine Slave so these actually despawn when gossip option selected for quest credit
UPDATE `smart_scripts` SET `target_type`=1 WHERE  `entryorguid`=3139700 AND `source_type`=9 AND `id`=3 AND `link`=0;
