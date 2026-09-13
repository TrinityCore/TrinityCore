--
SET @SPAWN_GROUP_ID := 335; -- 7
SET @CGUID := 147407; -- 11

-- Runes
UPDATE `gameobject` SET `state` = 0 WHERE `id` BETWEEN 176951 AND 176957;

-- Majordomo & Ragnaros
UPDATE `gameobject` SET `spawntimesecs` = 604800 WHERE `guid` = 67870 AND `id` = 179703;

UPDATE `gameobject_template` SET `ScriptName`='go_ragnaros_lava_burst_trap' WHERE `entry`=178088;

DELETE FROM `spawn_group` WHERE `spawnId` = 67870 AND `spawnType` = 1;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP_ID+0,1,67870);

DELETE FROM `spawn_group_template` WHERE `groupId` = @SPAWN_GROUP_ID+0;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+0,"Molten Core - Cache of the Firelord",4);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`StringId`,`VerifiedBuild`) VALUES
(@CGUID+0,12018,409,0,0,1,1,0,1,758.0892333984375,-1176.712158203125,-118.640335083007812,3.124139308929443359,604800,0,0,0,0,0,0,0,0,'',NULL,0),

(@CGUID+1,11663,409,0,0,1,1,0,0,747.131591796875,-1158.8707275390625,-118.8970947265625,4.031710624694824218,604800,0,0,0,0,0,0,0,0,'',NULL,0),
(@CGUID+2,11663,409,0,0,1,1,0,0,757.1162109375,-1170.11962890625,-118.792976379394531,3.40339207649230957,604800,0,0,0,0,0,0,0,0,'',NULL,0),
(@CGUID+3,11663,409,0,0,1,1,0,0,755.91046142578125,-1184.4600830078125,-118.448577880859375,2.809980154037475585,604800,0,0,0,0,0,0,0,0,'',NULL,0),
(@CGUID+4,11663,409,0,0,1,1,0,0,746.93865966796875,-1194.86865234375,-118.016136169433593,2.216568231582641601,604800,0,0,0,0,0,0,0,0,'',NULL,0),

(@CGUID+5,11664,409,0,0,1,1,0,1,737.94476318359375,-1156.4805908203125,-118.945457458496093,4.468042850494384765,604800,0,0,0,0,0,0,0,0,'',NULL,0),
(@CGUID+6,11664,409,0,0,1,1,0,1,752.95281982421875,-1163.93505859375,-118.868507385253906,3.700098037719726562,604800,0,0,0,0,0,0,0,0,'',NULL,0),
(@CGUID+7,11664,409,0,0,1,1,0,1,752.520263671875,-1191.0177001953125,-118.218475341796875,2.49582076072692871,604800,0,0,0,0,0,0,0,0,'',NULL,0),
(@CGUID+8,11664,409,0,0,1,1,0,1,738.814453125,-1197.4049072265625,-118.017601013183593,1.832595705986022949,604800,0,0,0,0,0,0,0,0,'',NULL,0),

(@CGUID+9,11502,409,0,0,1,1,0,0,838.3082,-831.4665,-232.18529,2.199114799499511718,604800,0,0,0,0,0,0,0,0,'',NULL,0),

(@CGUID+10,12018,409,0,0,1,1,0,1,848.933,-812.875,-229.601,4.046000003814697265,604800,0,0,0,0,0,0,0,0,'',NULL,0);

DELETE FROM `spawn_group` WHERE `spawnId` BETWEEN @CGUID+0 AND @CGUID+10 AND `spawnType` = 0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
-- 336
(@SPAWN_GROUP_ID+1,0,@CGUID+0),
-- 337
(@SPAWN_GROUP_ID+2,0,@CGUID+1),
(@SPAWN_GROUP_ID+2,0,@CGUID+2),
(@SPAWN_GROUP_ID+2,0,@CGUID+3),
(@SPAWN_GROUP_ID+2,0,@CGUID+4),
(@SPAWN_GROUP_ID+2,0,@CGUID+5),
(@SPAWN_GROUP_ID+2,0,@CGUID+6),
(@SPAWN_GROUP_ID+2,0,@CGUID+7),
(@SPAWN_GROUP_ID+2,0,@CGUID+8),
-- 338
(@SPAWN_GROUP_ID+3,0,@CGUID+9),
-- 339
(@SPAWN_GROUP_ID+4,0,@CGUID+10);

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP_ID+1 AND @SPAWN_GROUP_ID+4;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+1,"Molten Core - Majordomo Executus",4),
(@SPAWN_GROUP_ID+2,"Molten Core - Flamewakers",4),
(@SPAWN_GROUP_ID+3,"Molten Core - Ragnaros",4),
(@SPAWN_GROUP_ID+4,"Molten Core - Majordomo Executus (Alt)",4);

DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+0;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+0,@CGUID+0,0,0,3,0,0),
(@CGUID+0,@CGUID+1,0,0,3,0,0),
(@CGUID+0,@CGUID+2,0,0,3,0,0),
(@CGUID+0,@CGUID+3,0,0,3,0,0),
(@CGUID+0,@CGUID+4,0,0,3,0,0),
(@CGUID+0,@CGUID+5,0,0,3,0,0),
(@CGUID+0,@CGUID+6,0,0,3,0,0),
(@CGUID+0,@CGUID+7,0,0,3,0,0),
(@CGUID+0,@CGUID+8,0,0,3,0,0);

DELETE FROM `spawn_group` WHERE `spawnId` IN (7091,7098) AND `spawnType` = 1;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP_ID+5,1,7091),
(@SPAWN_GROUP_ID+6,1,7098);

DELETE FROM `spawn_group_template` WHERE `groupId` IN (@SPAWN_GROUP_ID+5,@SPAWN_GROUP_ID+6);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+5,"Molten Core - Lava Steam",4),
(@SPAWN_GROUP_ID+6,"Molten Core - Lava Splash",4);

DELETE FROM `creature_text` WHERE `CreatureID` = 12018;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(12018,0,0,"Reckless mortals! None may challenge the Sons of the Living flame!",14,0,100,0,0,8035,7612,0,"Majordomo SAY_AGGRO"),
(12018,1,0,"Ashes to ashes!",14,0,100,0,0,8037,9425,0,"Majordomo SAY_SLAY"),
(12018,2,0,"Impossible! Stay your attack, mortals... I submit! I submit!",14,0,100,0,0,8038,7561,0,"Majordomo SAY_DEFEAT_1"),
(12018,3,0,"Brashly, you have come to wrest the secrets of the Living Flame! You will soon regret the recklessness of your quest.",14,0,100,0,0,0,7567,0,"Majordomo SAY_DEFEAT_2"),
(12018,4,0,"I go now to summon the lord whose house this is. Should you seek an audience with him, your paltry lives will surely be forfeit! Nevertheless, seek out his lair, if you dare!",14,0,100,0,0,0,7568,0,"Majordomo SAY_DEFEAT_3"),
(12018,5,0,"The runes of warding have been destroyed! Hunt down the infidels, my brethren!",14,0,100,0,0,8039,7566,0,"Majordomo SAY_SPAWN"),
(12018,6,0,"You think you've won already? Perhaps you'll need another lesson in pain!",14,0,100,0,0,0,8545,0,"Majordomo SAY_CHAMPION"),
(12018,7,0,"Very well, $n.",12,0,100,0,0,0,7649,0,"Majordomo SAY_SUMMON_1"),
(12018,8,0,"Impudent whelps! You've rushed headlong to your own deaths! See now, the master stirs!\n",14,0,100,0,0,0,7655,0,"Majordomo SAY_SUMMON_2"),
(12018,9,0,"Behold Ragnaros - the Firelord! He who was ancient when this world was young! Bow before him, mortals! Bow before your ending!",14,0,100,0,0,8040,7657,0,"Majordomo SAY_SUMMON_3"),
(12018,10,0,"These mortal infidels, my lord! They have invaded your sanctum and seek to steal your secrets!",14,0,100,0,0,8041,7661,0,"Majordomo SAY_SUMMON_4");

DELETE FROM `spell_target_position` WHERE `ID` IN (20534,20618);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(20534,0,409,736.516,-1176.35,-119.006,0,12340),
(20618,0,409,736.516,-1176.35,-119.006,0,12340);

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_majordomo_separation_anxiety';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(21094, 'spell_majordomo_separation_anxiety');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (20619,21075,21094,21087,21090,21086);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,20619,0,0,31,0,3,11663,0,0,0,0,"","Group 0: Spell 'Magic Reflection' (Effect 0) targets creature 'Flamewaker Healer'"),
(13,1,20619,0,1,31,0,3,11664,0,0,0,0,"","Group 1: Spell 'Magic Reflection' (Effect 0) targets creature 'Flamewaker Elite'"),
(13,1,21075,0,0,31,0,3,11663,0,0,0,0,"","Group 0: Spell 'Damage Shield' (Effect 0) targets creature 'Flamewaker Healer'"),
(13,1,21075,0,1,31,0,3,11664,0,0,0,0,"","Group 1: Spell 'Damage Shield' (Effect 0) targets creature 'Flamewaker Elite'"),
(13,1,21094,0,0,31,0,3,11663,0,0,0,0,"","Group 0: Spell 'Separation Anxiety' (Effect 0) targets creature 'Flamewaker Healer'"),
(13,1,21094,0,1,31,0,3,11664,0,0,0,0,"","Group 1: Spell 'Separation Anxiety' (Effect 0) targets creature 'Flamewaker Elite'"),
(13,3,21087,0,0,31,0,3,11663,0,0,0,0,"","Group 0: Spell 'Immunity' (Effect 0, 1) targets creature 'Flamewaker Healer'"),
(13,3,21087,0,1,31,0,3,11664,0,0,0,0,"","Group 1: Spell 'Immunity' (Effect 0, 1) targets creature 'Flamewaker Elite'"),
(13,7,21090,0,0,31,0,3,11663,0,0,0,0,"","Group 0: Spell 'Champion' (Effect 0, 1, 2) targets creature 'Flamewaker Healer'"),
(13,7,21090,0,1,31,0,3,11664,0,0,0,0,"","Group 1: Spell 'Champion' (Effect 0, 1, 2) targets creature 'Flamewaker Elite'"),
(13,3,21086,0,0,31,0,3,11663,0,0,0,0,"","Group 0: Spell 'Encouragement' (Effect 0, 1) targets creature 'Flamewaker Healer'"),
(13,3,21086,0,1,31,0,3,11664,0,0,0,0,"","Group 1: Spell 'Encouragement' (Effect 0, 1) targets creature 'Flamewaker Elite'");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (11663,11664) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(11663,0,0,0,0,0,100,0,5000,15000,10000,20000,0,11,20603,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Flamewaker Healer - In Combat - Cast 'Shadow Shock'"),
(11663,0,1,0,0,0,100,0,5000,15000,5000,15000,0,11,21077,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Flamewaker Healer - In Combat - Cast 'Shadow Bolt'"),

(11664,0,0,0,0,0,100,0,15000,20000,20000,35000,0,11,20229,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Flamewaker Elite - In Combat - Cast 'Blast Wave'"),
(11664,0,1,0,0,0,100,0,10000,15000,10000,25000,0,11,20420,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Flamewaker Elite - In Combat - Cast 'Fireball'"),
(11664,0,2,0,0,0,100,0,10000,20000,10000,20000,0,11,20623,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Flamewaker Elite - In Combat - Cast 'Fire Blast'");

DELETE FROM `creature_text` WHERE `CreatureID` = 11502;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11502,0,0,"TOO SOON! YOU HAVE AWAKENED ME TOO SOON, EXECUTUS! WHAT IS THE MEANING OF THIS INTRUSION???",14,0,100,15,0,8043,7636,0,"Ragnaros SAY_ARRIVAL_1"),
(11502,1,0,"FOOL! YOU ALLOWED THESE INSECTS TO RUN RAMPANT THROUGH THE HALLOWED CORE? AND NOW YOU LEAD THEM TO MY VERY LAIR? YOU HAVE FAILED ME, EXECUTUS! JUSTICE SHALL BE MET, INDEED!",14,0,100,15,0,8044,7662,0,"Ragnaros SAY_ARRIVAL_2"),
(11502,2,0,"NOW FOR YOU, INSECTS! BOLDLY, YOU SOUGHT THE POWER OF RAGNAROS. NOW YOU SHALL SEE IT FIRSTHAND!\n",14,0,100,15,0,8045,7685,0,"Ragnaros SAY_ARRIVAL_3"),
(11502,3,0,"BY FIRE BE PURGED!",14,0,100,0,0,8046,9426,0,"Ragnaros SAY_MIGHT"),
(11502,4,0,"TASTE THE FLAMES OF SULFURON!",14,0,100,0,0,8047,9427,0,"Ragnaros SAY_WRATH"),
(11502,5,0,"COME FORTH, MY SERVANTS! DEFEND YOUR MASTER!",14,0,100,0,0,8049,8572,0,"Ragnaros SAY_REINFORCEMENTS_1"),
(11502,6,0,"YOU CANNOT DEFEAT THE LIVING FLAME! COME YOU MINIONS OF FIRE! COME FORTH, YOU CREATURES OF HATE! YOUR MASTER CALLS!",14,0,100,0,0,8050,8573,0,"Ragnaros SAY_REINFORCEMENTS_2"),
(11502,7,0,"DIE, INSECT!",14,0,100,0,0,8051,7626,0,"Ragnaros SAY_SLAY");

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 11502;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(11502,1,1,0,1,0,0,NULL);

UPDATE `creature_template` SET `ScriptName` = 'npc_flame_of_ragnaros' WHERE `entry` = 13148;

DELETE FROM `spell_target_position` WHERE `ID` IN (21886,21900,21901,21902,21903,21904,21905,21906,21907,21110,21111,21112,21113,21114,21115,21116,21117);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(21886,0,409,906.695,-828.611,-229.928,0,0),
(21900,0,409,843.509,-798.313,-229.432,0,0),
(21901,0,409,892.633,-790.41,-228.928,0,0),
(21902,0,409,871.54,-839.115,-228.992,0,0),
(21903,0,409,827.276,-874.028,-229.594,0,0),
(21904,0,409,862.862,-866.955,-228.943,0,0),
(21905,0,409,811.001,-822.282,-229.311,0,0),
(21906,0,409,819.757,-807.176,-229.033,0,0),
(21907,0,409,864.573,-806.463,-229.786,0,0),

(21117,0,409,811.448,-814.058,-233.17667,0,12340),
(21110,0,409,842.542,-797.822,-233.33968,0,12340),
(21111,0,409,870.668,-821.862,-232.93767,0,12340),
(21112,0,409,874.851,-861.112,-232.33568,0,12340),
(21113,0,409,875.1703,-796.7169,-228.15884,0,0),
(21114,0,409,824.827,-871.046,-232.42067,0,12340),
(21115,0,409,868.206,-895.036,-233.09967,0,12340),
(21116,0,409,818.517,-898.278,-232.90288,0,12340);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_ragnaros_lava_burst',
'spell_ragnaros_summon_sons_of_flame');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(21908, 'spell_ragnaros_lava_burst'),
(21108, 'spell_ragnaros_summon_sons_of_flame');

UPDATE `gossip_menu_option` SET `OptionBroadcastTextID` = 7646 WHERE `MenuID` = 4093;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID` = 7675 WHERE `MenuID` = 4108;
