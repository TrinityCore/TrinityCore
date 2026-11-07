-- Update Health
UPDATE `creature_template` SET `RegenHealth` = 0 WHERE `entry` = 80793;

UPDATE `creature` SET `curHealthPct` = 25 WHERE `guid` IN (460109, 460106, 460049, 460055, 460053, 460100, 460098, 460102, 460103);
