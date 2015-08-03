-- Restore horrible mistake in UP34 from myself
UPDATE `gameobject_template` SET `data1`=27512 WHERE `entry`=195669;
UPDATE `gameobject_template` SET `data1`=27517 WHERE `entry`=195670;
UPDATE `gameobject_template` SET `data1`=27518 WHERE `entry`=195671;
-- Fix loottemplates along with it
UPDATE `gameobject_loot_template` SET `entry`=27512 WHERE `entry`=195669;
UPDATE `gameobject_loot_template` SET `entry`=27517 WHERE `entry`=195670;
UPDATE `gameobject_loot_template` SET `entry`=27518 WHERE `entry`=195671;
