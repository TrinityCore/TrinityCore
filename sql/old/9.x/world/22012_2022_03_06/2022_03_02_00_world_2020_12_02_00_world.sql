-- Protectorate Demolitionist SAI (Source: https://www.youtube.com/watch?v=SgJAjwOnoBY & https://www.youtube.com/watch?v=JH5nXTkvH-o)
SET @ID := 20802;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+5 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,54,0,100,0,0,0,0,0,0,80,@ID*100+0,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Just Summoned - Run Script"),
(@ID,0,1,0,4,0,100,0,0,0,0,0,0,1,6,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Aggro - Say Line 6"),
(@ID,0,2,0,40,0,100,0,3,0,0,0,0,80,@ID*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Waypoint 3 Reached - Run Script"),
(@ID,0,3,0,40,0,100,0,4,0,0,0,0,80,@ID*100+2,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Waypoint 4 Reached - Run Script"),
(@ID,0,4,0,40,0,100,0,9,0,0,0,0,80,@ID*100+3,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Waypoint 9 Reached - Run Script"),
(@ID,0,5,0,40,0,100,0,12,0,0,0,0,80,@ID*100+4,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Waypoint 12 Reached - Run Script"),
(@ID,0,6,0,40,0,100,0,13,0,0,0,0,80,@ID*100+5,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Waypoint 13 Reached - Run Script"),
(@ID,0,7,0,6,0,100,0,0,0,0,0,0,6,10406,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Death - Fail Quest 'Delivering the Message'"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Script - Set Reactstate Passive"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,11,12980,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Script - Cast 'Simple Teleport'"),
(@ID*100+0,9,2,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Script - Say Line 0"),
(@ID*100+0,9,3,0,0,0,100,0,3000,3000,0,0,0,53,0,20802,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Script - Start Waypoint"),

(@ID*100+1,9,0,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Script - Say Line 1"),

(@ID*100+2,9,0,0,0,0,100,0,500,500,0,0,0,1,2,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Script - Say Line 2"),

(@ID*100+3,9,0,0,0,0,100,0,2000,2000,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Script - Say Line 3"),
-- Can update in combat, https://youtu.be/5Z9BJNr-lec?t=135
-- all other too
(@ID*100+4,9,0,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Script - Set Run On"),
(@ID*100+4,9,1,0,0,0,100,0,0,0,0,0,0,1,4,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Script - Say Line 4"),
(@ID*100+4,9,2,0,0,0,100,0,0,0,0,0,0,17,28,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Script - Set Emote State 28"),
(@ID*100+4,9,3,0,0,0,100,0,7000,7000,0,0,0,107,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Script - Summon Group 0"),
(@ID*100+4,9,4,0,0,0,100,0,10000,10000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Script - Set Emote State 0"),
(@ID*100+4,9,5,0,0,0,100,0,0,0,0,0,0,1,5,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Script - Say Line 5"),

(@ID*100+5,9,0,0,0,0,100,0,0,0,0,0,0,11,35680,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Script - Cast 'QID 10406'"),
(@ID*100+5,9,1,0,0,0,100,0,4000,4000,0,0,0,1,7,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Script - Say Line 7"),
(@ID*100+5,9,2,0,0,0,100,0,4000,4000,0,0,0,11,35517,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Script - Cast 'Teleport'"),
(@ID*100+5,9,3,0,0,0,100,0,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Protectorate Demolitionist - On Script - Delayed Despawn");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Let's do this... Just keep me covered and I'll deliver the package.",12,0,100,1,0,0,18432,0,"Protectorate Demolitionist"),
(@ID,1,0,"By the second sun of K'aresh, look at this place! I can only imagine what Salhadaar is planning. Come on, let's keep going.",12,0,100,1,0,0,18433,0,"Protectorate Demolitionist"),
(@ID,2,0,"With this much void waste and run-off, a toxic void horror can't be too far behind.",12,0,100,0,0,0,18434,0,"Protectorate Demolitionist"),
(@ID,3,0,"Look there, fleshling! Salhadaar's conduits! He's keeping well fed....",12,0,100,1,0,0,18435,0,"Protectorate Demolitionist"),
(@ID,4,0,"Alright, keep me protected while I plant this disruptor. This shouldn't take very long.",12,0,100,0,0,0,18436,0,"Protectorate Demolitionist"),
(@ID,5,0,"Done! Back up! Back up!",12,0,100,0,0,0,18437,0,"Protectorate Demolitionist"),
(@ID,6,0,"Keep these things off me!",12,0,100,0,0,0,18438,0,"Protectorate Demolitionist"),
(@ID,6,1,"I'm under attack! I repeat, I am under attack!",12,0,100,0,0,0,18439,0,"Protectorate Demolitionist"),
(@ID,6,2,"I need to find a new line of work.",12,0,100,0,0,0,18440,0,"Protectorate Demolitionist"),
(@ID,7,0,"Looks like my work here is done. Report back to the holo-image of Ameer over at the transponder.",12,0,100,1,0,0,18442,0,"Protectorate Demolitionist");

DELETE FROM `waypoints` WHERE `entry` = 20802;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(20802,1,4006.37,2324.59,111.455,0,0,"Protectorate Demolitionist"),
(20802,2,3998.39,2326.36,113.164,0,0,"Protectorate Demolitionist"),
(20802,3,3982.31,2330.26,113.846,2.06167,7000,"Protectorate Demolitionist"),
(20802,4,3950.65,2329.25,113.924,0,500,"Protectorate Demolitionist"),
(20802,5,3939.23,2330.99,112.197,0,0,"Protectorate Demolitionist"),
(20802,6,3927.86,2333.64,111.33,0,0,"Protectorate Demolitionist"),
(20802,7,3917.85,2337.7,113.493,0,0,"Protectorate Demolitionist"),
(20802,8,3907.74,2343.34,114.062,0,0,"Protectorate Demolitionist"),
(20802,9,3878.76,2378.61,114.037,1.58019,7000,"Protectorate Demolitionist"),
(20802,10,3863.15,2355.88,114.987,0,0,"Protectorate Demolitionist"),
(20802,11,3861.24,2344.89,115.201,0,0,"Protectorate Demolitionist"),
(20802,12,3872.46,2323.11,114.671,0,17000,"Protectorate Demolitionist"),
(20802,13,3863.74,2349.79,115.382,5.06267,11000,"Protectorate Demolitionist");

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 20802 AND `summonerType` = 0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(20802,0,0,20474,3866.84,2321.75,113.736,0.120686,4,60000,"Protectorate Demolitionist - Group 0 - Ethereum Nexus-Stalker"),
(20802,0,0,20474,3879.27,2321.94,115.065,3.13727,4,60000,"Protectorate Demolitionist - Group 0 - Ethereum Nexus-Stalker");

-- Ethereum Nexus-Stalker SAI
SET @ID := 20474;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,54,0,100,0,0,0,0,0,0,11,17673,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ethereum Nexus-Stalker - On Just Summoned - Cast 'Shade Form Visual'"),
(@ID,0,1,2,61,0,100,0,0,0,0,0,0,11,36515,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ethereum Nexus-Stalker - On Link - Cast 'Shadowtouched'"),
(@ID,0,2,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ethereum Nexus-Stalker - On Link - Say Line 0"),
(@ID,0,3,0,0,0,100,0,5000,10000,10000,15000,0,11,36517,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ethereum Nexus-Stalker - In Combat - Cast 'Shadowsurge'");

-- Image of Commander Ameer SAI (https://www.youtube.com/watch?v=kbJgCI54fbA https://www.youtube.com/watch?v=zDp2XKzqSQ0)
SET @ID := 20482;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,19,0,100,0,10406,0,0,0,0,11,35678,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Image of Commander Ameer - On Quest 'Delivering the Message' Taken - Cast 'Protectorate Demolitionist'"),
(@ID,0,1,2,54,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of Commander Ameer - On Just Summoned - Set Reactstate Passive"),
(@ID,0,2,0,61,0,100,0,0,0,0,0,0,11,12980,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of Commander Ameer - On Link - Cast 'Simple Teleport'"),
-- Doubt it's on aggro, dunno where text 1 'Protectorate transmission complete.' is used, definitely not after rewarding quest
-- Turned out currently he uses UNIT_FLAG_NON_ATTACKABLE, doubt it's correct
-- Means this will not work at all with out passive react state
(@ID,0,3,0,4,0,100,0,0,0,0,0,0,80,@ID*100+0,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of Commander Ameer - On Aggro - Run Script"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of Commander Ameer - On Script - Say Line 0"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of Commander Ameer - On Script - Remove NPC Flag Questgiver"),
-- There is an annoying problem with that object, its flags are 0 (checked sniffs) and it despawns after 4 min after use
-- I guess this script may be used to reset object before it despawns
-- No idea how to reset and not cause despawn
(@ID*100+0,9,2,0,0,0,100,0,3000,3000,0,0,0,41,0,1,0,0,0,0,20,184383,0,0,0,0,0,0,0,"Image of Commander Ameer - On Script - Despawn Instant (Ethereum Transponder Zeta)"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Image of Commander Ameer - On Script - Despawn Instant");

-- Change respawn time of Ethereum Transponder Zeta to 1 as temp solution
UPDATE `gameobject` SET `spawntimesecs` = 1 WHERE `id` = 184383;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 20482 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,20482,0,0,1,0,35679,1,0,1,0,0,"","Group 0: Execute SAI (Action 0) if player does not have aura 'Protectorate Demolitionist'");
