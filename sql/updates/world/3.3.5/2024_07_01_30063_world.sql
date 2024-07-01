-- Set PvP flag for "Draenei Youngling" to allow targeting for quest "A Hearty Thanks!"
UPDATE `creature_template_addon` SET `PvPFlags` = `PvPFlags` | 0x1 WHERE `entry` = 17587;
