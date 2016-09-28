--
UPDATE `creature_template` SET `unit_flags2`=`unit_flags2`|2048 WHERE `entry` IN (42166,42178,42179,42180);
UPDATE `creature_template` SET `unit_class`=4 WHERE `entry` IN (49051,49048,49054,49057);
