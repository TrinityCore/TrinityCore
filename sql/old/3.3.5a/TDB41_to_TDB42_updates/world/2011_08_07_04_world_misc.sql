UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (29769,29770,29840);
-- Template updates for creature 25596 (Infected Kodo Beast)
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|512,`speed_run`=2 WHERE `entry`=25596;
UPDATE `creature_template_addon` SET `bytes1`=7,`bytes2`=1,`mount`=0,`emote`=0,`auras`='45771' WHERE `entry`=25596;

-- Tome
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE `entry`=12938;
UPDATE `quest_template` SET `nextquestid`=12938, `exclusivegroup`=12898 WHERE `entry` in (12898,12899);

-- Aokromes
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE `entry`=12891;
UPDATE `quest_template` SET `nextquestid`=12891, `exclusivegroup`=12887 WHERE `entry` in (12887,12892);
UPDATE `creature_template` SET `faction_A`=21,`faction_H`=21 WHERE `entry`=29851;
