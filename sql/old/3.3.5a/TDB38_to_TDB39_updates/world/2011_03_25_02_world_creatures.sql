-- Arcanimus should not have random movement
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `guid`=96298;
-- Fixup Big Electromental Flavor
UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0 WHERE `id`=21757;
UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry`=21757;
-- Remove Fizzcrank Airman missspawn
DELETE FROM `creature` WHERE `guid` IN (117923);
DELETE FROM `creature_addon` WHERE `guid` IN (117923);
-- Fixup South Sinkhole, Northeast Sinkhole, Northwest Sinkhole Set as trigger
UPDATE `creature` SET `modelid`=0 WHERE `id` IN (25664,25665,25666);
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry` IN (25664,25665,25666);
