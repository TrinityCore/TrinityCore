-- 
UPDATE `creature_template` SET `unit_flags2` = `unit_flags2`|0x8000 WHERE `entry` IN (32930,33909);
