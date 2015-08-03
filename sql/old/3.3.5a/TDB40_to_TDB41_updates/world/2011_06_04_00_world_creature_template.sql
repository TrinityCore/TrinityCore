DELETE FROM `creature_text` WHERE `entry`=39746;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(39746,0,0, 'Alexstrasza has chosen capable allies.... A pity that I must END YOU!',14,0,100,0,0,17512, 'Baltharus the Warborn'),
(39746,1,0, 'You thought you stood a chance?',14,0,50,0,0,17513, 'General Zarithrian'),
(39746,1,1, 'It''s for the best.',14,0,50,0,0,17514, 'General Zarithrian'),
(39746,2,0, 'Turn them to ash, minions!',14,0,100,0,0,17516, 'General Zarithrian'),
(39746,3,0, 'HALION! I...',14,0,100,0,0,17515, 'General Zarithrian');

UPDATE `creature_template` SET `ScriptName`= 'npc_baltharus_the_warborn_clone' WHERE `ScriptName`= 'npc_baltarhus_the_warborn_clone';
UPDATE `creature_template` SET `InhabitType`=3 WHERE `entry`=39794;
UPDATE `creature_template` SET `ScriptName`= 'boss_general_zarithrian' WHERE `entry`=39746;
UPDATE `creature_template` SET `ScriptName`= 'npc_onyx_flamecaller' WHERE `entry`=39814;
