-- Steelbreaker: Fix wrong itemId for Belt of the Crystal Tree 
UPDATE creature_loot_template SET `Item`=45455 WHERE `entry`=32867 AND `Item`=25455;
