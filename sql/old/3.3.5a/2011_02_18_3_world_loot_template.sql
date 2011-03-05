-- Fix wrong loot being dropped by ICC trash
UPDATE `reference_loot_template` SET `item`=50450 WHERE `item`=50775 AND `entry`=35071;
