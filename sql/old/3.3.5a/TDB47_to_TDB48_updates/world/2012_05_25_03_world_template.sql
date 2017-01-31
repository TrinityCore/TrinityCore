-- Fix unit flags for Blackhand Incarcerator
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|768 WHERE `entry`=10316;
-- Fix unit flags for Pyroguard Emberseer
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33554688 WHERE `entry`=9816;
-- Remove hack event script
DELETE FROM `event_scripts` WHERE `id`=4884;
-- Remove script to Dragonspire Hall Runes "UBRS"
UPDATE `gameobject_template` SET `ScriptName`= '' WHERE `entry` BETWEEN 175194 AND 175200;
