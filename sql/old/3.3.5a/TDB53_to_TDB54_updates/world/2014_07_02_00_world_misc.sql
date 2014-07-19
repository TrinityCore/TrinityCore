--
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=32790 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=30630 AND `source_type`=0 AND `id`=0 AND `link`=1;
-- The below is also related to same quest for moonglade portal and return from moonglade portal same quest, these gained trigger flags resulting in the portals becoming non clickable.
UPDATE`creature_template` SET `flags_extra`=0 WHERE  `entry`IN(32790,32788);
