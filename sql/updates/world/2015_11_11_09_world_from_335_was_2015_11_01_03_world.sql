-- farlina cleanup
-- areatrigger for greeting
DELETE FROM `areatrigger_scripts` WHERE `entry`=4115;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4115,"at_faerlina_entrance");

DELETE FROM `creature_text` WHERE `entry`=15953 AND `groupid` IN (4,5);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`probability`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(15953,4,0,"%s is affected by Widow's Embrace!",41,100,31019,3,"Faerlina EMOTE_WIDOW_EMBRACE"),
(15953,5,0,"%s goes into a frenzy!",41,100,2384,3,"Faerlina EMOTE_FRENZY");

-- remove some random spiders that aren't there on retail
DELETE FROM `creature` WHERE `guid` IN (127961,127962);
-- move followers to summon groups to avoid buggy respawn behavior of minions
DELETE FROM `creature` WHERE `guid` IN (128061,128062,128063,128064);
DELETE FROM `linked_respawn` WHERE `guid` IN (128061,128062,128063,128064);
DELETE FROM `creature_summon_groups` WHERE `summonerId`=15953;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`) VALUES
(15953,0,1,16506,3362.66 ,-3620.97,261.08,4.57276,8),
(15953,0,1,16506,3356.71 ,-3620.05,261.08,4.57276,8),
(15953,0,2,16505,3359.685,-3620.51,261.08,4.57276,8),
(15953,0,1,16506,3344.3  ,-3618.31,261.08,4.69494,8),
(15953,0,1,16506,3350.26 ,-3619.11,261.08,4.69494,8),
(15953,0,2,16505,3347.28 ,-3618.71,261.08,4.69494,8);

-- adds' fireball spell
DELETE FROM `spelldifficulty_dbc` WHERE `id`=54095;
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`) VALUES
(54095,54095,54096);

-- naxxramas follower SAI changes
DELETE FROM `smart_scripts` WHERE `entryorguid`=16505 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`event_type`,`event_chance`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`target_type`,`comment`) VALUES
(16505,0,2,4,100,39,75,0,0,0, "Naxxramas Follower - On Aggro - Call For Help (75yd)");
