-- Set PvP flag for "Draenei Survivor" to allow targeting for quest "Rescue the Survivors!"
UPDATE `creature_template_addon` SET `PvPFlags`=0x1 WHERE `entry`=16483;
