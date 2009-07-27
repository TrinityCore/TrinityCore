UPDATE `creature_template` SET `ScriptName`='npc_ame' WHERE `entry`=9623;

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000205 AND -1000200;
INSERT INTO `script_texts`
   (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
   (-1000200, 'A-Me good.Good A-me.Follow...A-ME follow.Home.A-ME go home.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
   (-1000201, 'Bad Un´Goro Stomper.Stomper evil.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
   (-1000202, 'Good..good,A-ME. Home. Search way.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
   (-1000203, 'A-Me home.A-ME go home!Tar Lord dont disturb A-ME.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
   (-1000204, 'Tar Lord A-ME no hurt.A-ME good.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL),
   (-1000205, 'A-ME at home!A-ME good!Good A-ME.At home.Home.Home', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL);
UPDATE `quest_template` SET `QuestFlags` = 2, `SpecialFlags` = 2 WHERE `entry` = 4245;
