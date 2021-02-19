-- Disable movement flag updates for Onyxia and let script handle them
UPDATE `creature_template` SET `flags_extra` = `flags_extra`| 0x200 WHERE `entry` IN (10184, 36538);
UPDATE `creature_template_movement` SET `Flight`= 0 WHERE `CreatureId` IN (10184, 36538);
