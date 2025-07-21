-- Fix quest Cleansing the Scar by updating Eversong Ranger PvpFlags with retail 10.2.5.53262 build: V10_2_5_53262 sniffed value.
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=15938; -- 15938 (Eversong Ranger)
