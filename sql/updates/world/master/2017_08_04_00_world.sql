--
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216 WHERE `entry` IN (48803,48804,48913,51101); -- vehichleCursor, Spellclick
UPDATE `creature_template` SET `unit_flags2`=`unit_flags2`|1 WHERE `entry` IN (31485,31489,38126,38131,38401,38784,38785); -- UNIT_FLAG2_FEIGN_DEATH
UPDATE `creature_template` SET `unit_flags2`=`unit_flags2`|2048 WHERE `entry` IN (38262,38683,38684); -- UNIT_FLAG2_REGENERATE_POWER
UPDATE `creature_template` SET `unit_flags2`=`unit_flags2`|526336 WHERE `entry` IN (57359,57360,57361);
UPDATE `creature_template` SET `unit_flags2`=`unit_flags2`|2097152 WHERE `entry`=49709; -- Baron Silverlaine (1) level 87
