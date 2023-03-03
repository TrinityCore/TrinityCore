-- Fix emblem frost exploit in Ruby Sanctum
UPDATE `creature_template` SET `flags_extra`=`flags_extra` | 1 WHERE `entry`IN(39823,39920,39805);
