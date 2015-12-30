-- instructor razuvious cleanup
DELETE FROM `creature_text` WHERE `entry`=16061;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`probability`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(16061,0,0,"Do as I taught you!",14,100,8855,13075,3,"Razuvious SAY_AGGRO #1"),
(16061,0,1,"The time for practice is over! Show me what you have learned!",14,100,8859,13078,3,"Razuvious SAY_AGGRO #2"),
(16061,0,2,"Show them no mercy!",14,100,8856,13076,3,"Razuvious SAY_AGGRO #3"),
(16061,1,0,"%s lets loose a triumphant shout.",41,30,0,13082,3,"Razuvious SAY_SLAY"),
(16061,2,0,"You should have stayed home.",14,50,8861,13081,3,"Razuvious SAY_TAUNTED #1"),
(16061,2,1,"You disappoint me, students!",14,50,8858,13077,3,"Razuvious SAY_TAUNTED #2"),
(16061,2,2,"I'm just getting warmed up!",14,50,8852,13072,3,"Razuvious SAY_TAUNTED #3"),
(16061,2,3,"Stand and fight!",14,50,8853,13073,3,"Razuvious SAY_TAUNTED #4"),
(16061,2,4,"Sweep the leg... Do you have a problem with that?",14,50,8861,13080,3,"Razuvious SAY_TAUNTED #5"),
(16061,3,0,"An honorable... death.",14,100,8860,13079,3,"Razuvious SAY_DEATH");

-- move understudies to summon groups for proper reset behavior
DELETE FROM `creature` WHERE `guid` IN (128184,128185);
DELETE FROM `linked_respawn` WHERE `guid` IN (128184,128185);
DELETE FROM `creature_summon_groups` WHERE `summonerId`=16061 AND `summonerType`=0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`) VALUES
(16061,0,1,16803,2757.476,-3111.519,267.7678,3.926991,8),
(16061,0,1,16803,2762.049,-3084.467,267.7678,2.129302,8),
(16061,0,2,16803,2778.911,-3114.142,267.7678,5.288348,8),
(16061,0,2,16803,2781.866,-3088.187,267.7678,0.9075712,8);

-- "Hopeless" debuff on death may only target understudies
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=29125;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`) VALUES
(13,1,29125,31,0,3,16803,0,"Instructor Razuvious - Hopeless debuff - only target Death Knight Understudy");

-- transition understudies to scripted AI to prevent them overriding player control
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_dk_understudy" WHERE `entry`=16803;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16803 AND `source_type`=0;
