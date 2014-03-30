-- TDB 3.3.5a have faction 1214 for mob 37384, TDB 4.3.4 have the same faction for mob 13328 this makes the fix generic for both TDB.
UPDATE `creature_template` SET `faction_A` = 1214, `faction_H` = 1214 WHERE `entry` IN (13328,22715,32063,37384);
UPDATE `creature_template` SET `faction_A`=1693, `faction_H`=1693 WHERE `entry` IN (29062,31589,29096,31590,29098,31602,31590);
UPDATE `creature_template` SET `faction_A`=14, `faction_H`=14 WHERE `entry` IN (31588,31600);
