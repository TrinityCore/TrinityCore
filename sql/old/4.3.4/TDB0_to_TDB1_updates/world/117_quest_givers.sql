-- Add Quest Giver flag to all known Taker npc's
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE entry IN (SELECT `id` FROM `creature_involvedrelation`);
-- Add Quest Giver flag to all known Giver npc's
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE entry IN (SELECT `id` FROM `creature_questrelation`);
