-- None of them uses these flags
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (256|512) WHERE `entry` = 28406;
