-- Add script to 3 revealers outside Ironforge
UPDATE `creature` SET `ScriptName` = "npc_brewfest_reveler_2" WHERE `guid` IN (47648,86731,84899);
UPDATE `creature_addon` SET `emote` = 0 WHERE `guid` IN (47648,86731);
