-- Sandfury Shadowhunter spam fix
UPDATE `smart_scripts` SET `event_flags`=3 WHERE  `entryorguid`=7246 AND `source_type`=0 AND `id`=15 AND `link`=16;
UPDATE `smart_scripts` SET `event_flags`=0 WHERE  `entryorguid`=7246 AND `source_type`=0 AND `id`=16 AND `link`=0;
