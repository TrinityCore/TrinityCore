--
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|2 WHERE `entry` IN (30808,32118,37441,32117,37440,32114,37437,32115,37438,32116,37439,32113,37436,37308,37331);
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=22582;
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|130 WHERE `entry` IN (30786,30784,30782,30780);

UPDATE `creature_template` SET `unit_flags2`=`unit_flags2`|1 WHERE `entry` IN (38131,38126,31496,31489,31485,30521,25546,21623,21592,20173);
UPDATE `creature_template` SET `unit_flags2`=`unit_flags2`|32 WHERE `entry` IN (34216,33070,31217,31537);
UPDATE `creature_template` SET `unit_flags2`=`unit_flags2`|2048 WHERE `entry` IN (38304,38303,38299,38298,38174,38641,38773,48835,48913,48803,48804,40143,40144,40145,39864,39944,39945,38774,34649,35419,35421,35415,35427,35410,35429,34162,33724,34332,34215,31539,31546,31544,31461,31734,32796,31366,32795,30522,30775,30528,25562,21786,20657);
UPDATE `creature_template` SET `unit_flags2`=`unit_flags2`|2049 WHERE `entry` IN (21586,38400,38771,38772,38399,38769,38770,38401,38784,38785);
UPDATE `creature_template` SET `unit_flags2`=`unit_flags2`|32768 WHERE `entry` IN (33995,33909);
UPDATE `creature_template` SET `unit_flags2`=`unit_flags2`|34816 WHERE `entry`=33954;
UPDATE `creature_template` SET `unit_flags2`=`unit_flags2`|34848 WHERE `entry`=33955;
UPDATE `creature_template` SET `unit_flags2`=`unit_flags2`|65536 WHERE `entry` IN (34111,34003);
UPDATE `creature_template` SET `unit_flags2`=`unit_flags2`|67584 WHERE `entry`=34214;
UPDATE `creature_template` SET `unit_flags2`=`unit_flags2`|131072 WHERE `entry` IN (33911,33910);

UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|80358666 WHERE `entry` IN (37444,37283);
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|617299839 WHERE `entry` IN (43879,43876,43874,49538);
