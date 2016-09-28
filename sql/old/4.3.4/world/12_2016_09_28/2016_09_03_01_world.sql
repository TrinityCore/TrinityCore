--
UPDATE `creature_template` SET `unit_flags2`=`unit_flags2`|2048 WHERE `entry` IN (48270,42347);
UPDATE `creature_template` SET `unit_flags2`=`unit_flags2`|134217728 WHERE `entry` IN (47774,47775,47776);
UPDATE `creature_template` SET `unit_class`=4 WHERE `entry` IN (49050,49047,49053,49056);
UPDATE `creature_template` SET `faction`=14 WHERE `entry` IN (51101,51102,51103);
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216 WHERE `entry` IN (51101,51102,51103);
UPDATE `creature_template` SET `unit_flags2`=`unit_flags2`|134217728 WHERE `entry` IN (51104,51105,51106);
