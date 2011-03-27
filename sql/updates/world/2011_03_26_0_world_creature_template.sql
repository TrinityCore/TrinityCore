-- vortex trigger
UPDATE `creature_template` SET `modelid1`=11686,`modelid2`=169,`InhabitType`=5,`unit_flags`=0x02000000,`VehicleId`=214,`flags_extra`=130 WHERE `entry`=30090;
UPDATE `creature` SET `modelid`=0 WHERE `id`=30090;

-- Portal (Malygos)
UPDATE `creature_template` SET `InhabitType`=5 WHERE `entry`=30118;
UPDATE `creature_template` SET `speed_walk`=2.4,`speed_run`=0.857142857 WHERE `entry`=30084;

-- Hover Disk
UPDATE `creature_template` SET `VehicleId`=224,`faction_A`=35,`faction_H`=35,`InhabitType`=5 WHERE `entry` IN (30234,30248);

-- Surge of Power
UPDATE `creature_template` SET flags_extra=130 WHERE entry=30334;

-- Wyrmrest Skytalon (Player's Mount)
UPDATE `creature_template` SET `InhabitType`=5 WHERE `entry`=30161;

-- Alexstrasza the Life-Binder
UPDATE `creature_template` SET `InhabitType`=5 WHERE `entry`=32295;

-- static Field
UPDATE `creature_template` SET `flags_extra`=130,`InhabitType`=5 WHERE `entry`=30592;

UPDATE `creature_template` SET `VehicleId`=220,`spell1`=56091,`spell2`=56092,`spell3`=57090,`spell4`=57143,`spell5`=57108,`spell6`=57092,`spell7`=60534 WHERE `entry`=30161;