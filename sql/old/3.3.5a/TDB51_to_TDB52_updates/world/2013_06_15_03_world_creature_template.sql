-- Fix cosmetic-drakkari-bat-ph
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|2 WHERE `entry`=27490;
