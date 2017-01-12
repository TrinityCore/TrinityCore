--
UPDATE `creature_template` SET `difficulty_entry_1`=0 WHERE `entry`=48862;
UPDATE `creature_template` SET `minlevel`=82, `maxlevel`=82, `exp`=3, `faction`=16, `unit_flags`=64 WHERE `entry`=49663;
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|608911343 WHERE `entry`=48822;
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|608911343 WHERE `entry`=48801;
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|608911343 WHERE `entry`=48784;
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|608911343 WHERE `entry`=48702;
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|608911343 WHERE `entry`=48337;
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry` IN (48611,48610,48597,48595);
UPDATE `creature_template` SET `VehicleId`=0 WHERE `entry`=48784;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-20181;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-20186;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1487401;
--
