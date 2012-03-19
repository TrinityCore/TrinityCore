-- Fix quest 11162 Challenge to the Black Flight
UPDATE `creature_template` SET `unit_flags`=`unit_flags`&~768 WHERE `entry`=23789; -- Smolderwing
