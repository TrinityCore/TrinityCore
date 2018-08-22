DELETE FROM `creature` WHERE `guid` IN (304363);
DELETE FROM `creature_addon` WHERE `guid` IN (304363);

UPDATE `creature_template` SET `unit_flags`= 0x40 | 0x200 WHERE `entry` IN (39788, 48902);
UPDATE `creature_template` SET `speed_run`= 1.71429  WHERE `entry`= 48902;
