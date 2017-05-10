--
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=25743;
DELETE FROM `creature_loot_template` WHERE `entry`=25802 AND `item`=35234;
UPDATE `item_template` SET `flagsCustom`=1 WHERE `entry`=44834;
