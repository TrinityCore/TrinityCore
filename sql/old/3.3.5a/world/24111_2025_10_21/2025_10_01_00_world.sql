-- Fix Illidan Stormrage health and unit_class
UPDATE `creature_template` SET `unit_class`=1 WHERE `entry`=22917;
UPDATE `creature` SET `curhealth`=4249280 WHERE `guid`=52484;
