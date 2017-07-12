--
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|4 WHERE `entry`=34045;
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|1536 WHERE `entry`=21574;
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|16384 WHERE `entry` IN (32104,37425,31990,37309);
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|65536 WHERE `entry`=20175;
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|13108096 WHERE `entry`=19886;
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|71970058 WHERE `entry`=30600;
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|80358666 WHERE `entry` IN (37243,37244);
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|268435456 WHERE `entry` IN (38973,38974,38975,38970,38971,38972,38233,38459,38460);
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|277165934 WHERE `entry`=32796;
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|344276858 WHERE `entry` IN (35427,35410);
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|541800015 WHERE `entry` IN (39299,39300,39301);
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|617299835 WHERE `entry` IN (38483,37341,37363,33911,33910);

UPDATE `creature_template` SET `unit_flags2`=`unit_flags2`|32 WHERE `entry`=30794;

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|2 WHERE `entry` IN (37628,30808,25546,25543,30769,30758,30768,30776,30813,30812,30811,30800,30792,30796,30801,30797,30799,31997,37316,31995,37314,21620,20665,19901,31979,37298,32092,37413,32003,37322,32032,37352,32137,37465,37484,37483,37480,32044,37365,32056,37377,37320,32112,37433,37315,37482,37481,37479,37323,37236,37305,37420,37301,37416,37399,37485,37809,37348,37427,37344,37349,37242,37373,34140,37318,34256,34257,34254,33191,37486);

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|64 WHERE `entry` IN (31585,31183,31635);
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry` IN (25558,25557);
