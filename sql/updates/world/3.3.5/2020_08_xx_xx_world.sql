-- Disable movement flag updates for Grauf and let script handle them
UPDATE `creature_template` SET `flags_extra` = `flags_extra`|512 WHERE `entry`=26893;
