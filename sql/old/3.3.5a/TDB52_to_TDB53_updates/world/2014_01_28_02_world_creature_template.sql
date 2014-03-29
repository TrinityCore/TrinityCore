--
UPDATE `creature_template` SET `faction_A` = 190, `faction_H` = 190 WHERE `entry` = 30794;
UPDATE `creature_template` SET `difficulty_entry_1`=0 WHERE `entry`=30023;
UPDATE `creature_template` SET `difficulty_entry_1`=22643, `difficulty_entry_2`=32027, `difficulty_entry_3`=37347 WHERE `entry`=12159;
UPDATE `creature_template` SET `faction_A`=14, `faction_H`=14 WHERE `entry` IN (32027,37347);
