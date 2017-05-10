DELETE FROM `creature_addon` WHERE `guid` NOT IN (SELECT `guid` FROM `creature`);

UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE entry IN (SELECT `id` FROM `creature_involvedrelation`);
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE entry IN (SELECT `id` FROM `creature_questrelation`);
