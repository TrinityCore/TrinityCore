--
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry` IN (33395,14031,22586,22585,14030,22584,14027,22583,14028,14029,22581,14026,33402,31878,33691,33942,34189,31462,37634,34153,39011,39012,39013,20654,31461,31670,33907,33906,33353,33352,34228,31875,30757,21584,34131,26337);
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|2 WHERE `entry`=30777;

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|130 WHERE `entry` IN (21625,31874);

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|256 WHERE `entry` IN (20596,20745);

UPDATE `creature_template` SET `flags_extra`=`flags_extra`&~1 WHERE `entry` IN (27309,27308,27307,27303);
