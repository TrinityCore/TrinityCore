/* Remove guildmaster script from npc's. Core has full support */
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` IN (4974,5054,4613);
