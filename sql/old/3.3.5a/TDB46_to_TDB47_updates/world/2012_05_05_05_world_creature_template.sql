-- Fix skillup on some target dummys
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|262144 WHERE `entry` IN (31144,2674,2673);
