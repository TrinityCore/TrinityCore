-- Deathbound Wards should be taunt immune
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 256 WHERE `entry` IN (37007, 38031);
