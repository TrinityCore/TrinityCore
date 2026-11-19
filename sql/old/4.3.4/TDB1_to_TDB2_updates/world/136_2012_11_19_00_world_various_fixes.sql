-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 856: NPC Jezelle Pruitt
-- Update AI in Creature_Template to Smart AI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=5702;
-- Delete static spawns of Jezelles Imp,Voidwalker and Felhunter.
DELETE FROM `creature` WHERE `id` IN (5726,5729,5730); -- Seems to be good for 4.x too, need more verification for position
-- Smart Script For Jezelle Pruitt
DELETE FROM `smart_scripts` WHERE `entryorguid`=5702;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(5702,0,0,0,1,0,100,0,0,0,235000,235000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jezelle Pruitt - OOC  - Say Line 0"),
(5702,0,1,0,1,0,100,0,10000,10000,235000,235000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jezelle Pruitt - OOC  - Say Line 1"),
(5702,0,2,0,1,0,100,0,13000,13000,235000,235000,11,8677,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jezelle Pruitt - OOC  - Cast Summon Effect"),
(5702,0,3,0,1,0,100,0,18000,18000,235000,235000,12,5730,2,30000,0,0,0,8,0,0,0,1793.26,128.034,-63.8432,3.14159,"Jezelle Pruitt - OOC  - Spawn Jezelle's Imp"),
(5702,0,4,0,1,0,100,0,20000,20000,235000,235000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jezelle Pruitt - OOC  - Say Line 2"),
(5702,0,5,0,1,0,100,0,50000,50000,235000,235000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jezelle Pruitt - OOC  - Say Line 3"),
(5702,0,6,0,1,0,100,0,53000,53000,235000,235000,11,8677,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jezelle Pruitt - OOC  - Cast Summon Effect"),
(5702,0,7,0,1,0,100,0,58000,58000,235000,235000,12,5729,2,30000,0,0,0,8,0,0,0,1793.26,128.034,-63.8432,3.14159,"Jezelle Pruitt - OOC  - Spawn Jezelle's Voidwalker"),
(5702,0,8,0,1,0,100,0,60000,60000,235000,235000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jezelle Pruitt - OOC  - Say Line 4"),
(5702,0,9,0,1,0,100,0,90000,90000,235000,235000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jezelle Pruitt - OOC  - Say Line 5"),
(5702,0,10,0,1,0,100,0,93000,93000,235000,235000,11,8677,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jezelle Pruitt - OOC  - Cast Summon Effect"),
(5702,0,11,0,1,0,100,0,98000,98000,235000,235000,12,5728,2,30000,0,0,0,8,0,0,0,1793.26,128.034,-63.8432,3.14159,"Jezelle Pruitt - OOC  - Spawn Jezelle's Succubus"),
(5702,0,12,0,1,0,100,0,100000,100000,235000,235000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jezelle Pruitt - OOC  - Say Line 6"),
(5702,0,13,0,1,0,100,0,130000,130000,235000,235000,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jezelle Pruitt - OOC  - Say Line 7"),
(5702,0,14,0,1,0,100,0,133000,133000,235000,235000,11,8677,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jezelle Pruitt - OOC  - Cast Summon Effect"),
(5702,0,15,0,1,0,100,0,138000,138000,235000,235000,12,5726,2,30000,0,0,0,8,0,0,0,1793.26,128.034,-63.8432,3.14159,"Jezelle Pruitt - OOC  - Spawn Jezelle's FelHunter"),
(5702,0,16,0,1,0,100,0,140000,140000,235000,235000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jezelle Pruitt - OOC  - Say Line 8"),
(5702,0,17,0,1,0,100,0,170000,170000,235000,235000,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jezelle Pruitt - OOC  - Say Line 9"),
(5702,0,18,0,1,0,100,0,173000,173000,235000,235000,11,8677,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jezelle Pruitt - OOC  - Cast Summon Effect"),
(5702,0,19,0,1,0,100,0,178000,178000,235000,235000,12,5727,2,30000,0,0,0,8,0,0,0,1793.26,128.034,-63.8432,3.14159,"Jezelle Pruitt - OOC  - Spawn Jezelle's Felsteed"),
(5702,0,20,0,1,0,100,0,180000,180000,235000,235000,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jezelle Pruitt - OOC  - Say Line 10"),
(5702,0,21,0,1,0,100,0,210000,210000,235000,235000,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jezelle Pruitt - OOC  - Say Line 11");
-- Jezelle Pruitt Texts
DELETE FROM `creature_text` WHERE `entry`=5702;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(5702,0,0, 'If you''re here, then it means you are prepared to begin the study of summoning demonic cohorts to do your bidding. We will start with the lowliest creatures you will be able to call and continue from there. Let us begin.',12,33,100,0,0,0, 'Jezelle Pruitt'),
(5702,1,0, 'The easiest creature for you to summon is the imp. You should already be able to bring forth this minion but for completeness'' sake I will start with him.',12,33,100,0,0,0, 'Jezelle Pruitt'),
(5702,2,0, 'This foul little beast is the imp. It is small and weak, making it almost useless as a meatshield, and its damage output is mediocre at best. This creature is best used for support of a larger group.',12,33,100,0,0,0, 'Jezelle Pruitt'),
(5702,3,0, 'Now that you have had a chance to study imp, let us move on the next minion you will be able to summon, the voidwalker.',12,33,100,0,0,0, 'Jezelle Pruitt'),
(5702,4,0, 'This demonic entity is known as the Voidwalker. Its strength and endurance are significant, making it ideal for defence. Send it to attack your enemy, then use it as a shield while you use your spells and abilities to drain away your opponent''s life.',12,33,100,0,0,0, 'Jezelle Pruitt'),
(5702,5,0, 'If you''ve never seen one, it is a sight to behold. A very impressive creature both on and off the field of battle. Next let us take a look at what I am sure all you male students have been waiting for. The succubus.',12,33,100,0,0,0, 'Jezelle Pruitt'),
(5702,6,0, 'All right now. Asside from the obvious distractions a minion like this will provide against your more masculine foes, she is also capable of dealing out impressive amounts of damage. However, her fragile endurance makes her almost useless as a shield.',12,33,100,0,0,0, 'Jezelle Pruitt'),
(5702,7,0, 'Study hard and you might one day be able to summon one on your own, but for now it''s time to move on to the felhunter.',12,33,100,0,0,0, 'Jezelle Pruitt'),
(5702,8,0, 'What you see before you is a felhunter. This creature''s natural talents include spell lock and other abilities which make it unequalled when facing a magically attuned opponent.',12,33,100,0,0,0, 'Jezelle Pruitt'),
(5702,9,0, 'When facing a spellcaster of any kind, this feral beast will be your best friend. Now, let us take a look at something a bit different. This next creature will aid your travels and make your future journeys much easier. Let''s take a look at a felsteed.',12,33,100,0,0,0, 'Jezelle Pruitt'),
(5702,10,0, 'I doubt you have had much occasion to see such a creature. These demonic equines will make your travels much faster by acting as your mount as long as you control them. However, they are difficult to control, so be sure you are ready before attempting it.',12,33,100,0,0,0, 'Jezelle Pruitt'),
(5702,11,0, 'There you have it. Our lesson on summoning has come to an end. A new class will begin shortly, so if you wish to brush up, feel free to stay around.',12,33,100,0,0,0, 'Jezelle Pruitt');
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 1539: Standards and Practices
SET @GUID := 142; -- 4.x
DELETE FROM `gameobject` WHERE `id`=182263;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GUID+0,182263,530,1,1,-2532.99,6306.90,14.0280,2.81871,0,0,0.986996,0.160743,181,100,1),-- already in TDB
(@GUID+1,182263,530,1,1,-2474.44,6111.16,91.7629,3.66388,0,0,0.966096,-0.258184,181,100,1),
(@GUID+2,182263,530,1,1,-2533.21,6168.56,59.9387,3.75028,0,0,0.954044,-0.299666,181,100,1);
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 1977: An Improper Burial
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=39189;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,39189,0,0,31,0,3,21846,0,0,0,'',"set Sha'tari Torch implicit target to Slain Auchenai Warrior"),
(13,1,39189,0,1,31,0,3,21859,0,0,0,'',"set Sha'tari Torch implicit target to Slain Sha'tar Vindicator");
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 2350: Postponing the Inevitable
-- Mark Quest Invisman - Buying Time (26105) as trigger
UPDATE `creature_template` SET `flags_extra` = 128 WHERE `entry` = 26105;
-- Add event_script for Activate Interdimensional Refabricator (46547) Effect #2 http://old.wowhead.com/spell=46547
-- Any idea how can this be made with SAI?
DELETE FROM `event_scripts` WHERE id = 17364;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(17364,0,8,26105,0,0,0,0,0,0);
-- Increase GO Range to 25 (original=10)
UPDATE `gameobject_template` SET `data1`=25 WHERE `entry`=300183;
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 2782: Rune of Dawn
-- Seal of the Dawn (13209) & Rune of the Dawn (19812) scourgestones fix
-- UPDATE `item_template` SET `spellid_2`=17670, `spelltrigger_2`=1 WHERE `entry` IN (13209,19812); -- 4.x - Item-Sparse.db2
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 4013: No Rest For The Wicked
-- Add support for quest "No Rest For the Wicked" - H {13367/13368 - daily}<>A {13367/13368 - daily}
-- Credits: based on Kiperr, Kandera and Jankic fixes
SET @SummonBunny := 32347;
SET @Alumeth     := 32300;
SET @Trigger     := 60831; -- Spell Alumeth's Remains that can hit only summoning bunny to trigger it
UPDATE `creature_template` SET `AIName`='SmartAI',`unit_flags`=4,`flags_extra`=128 WHERE `entry`=@SummonBunny;
UPDATE `creature_template` SET `AIName`='SmartAI',`faction_A`=21,`faction_H`=21 WHERE `entry`=@Alumeth; -- faction from sniffs
UPDATE `creature` SET  `spawndist`=0,`MovementType`=0 WHERE `guid`=122317; -- Summon Bunny should stay at spawn point
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@SummonBunny,@Alumeth) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SummonBunny,0,0,0,8,0,100,0,60834,0,0,0,12,32300,6,20000,0,0,8,0,0,0,8219.157,2187.093,499.8201,3.106686,0, 'Alumeth Summon Bunny - On Spellhit - Summon Alumeth the Ascended'), -- He should dissapear after death, not on timer after summon.
(@Alumeth,0,0,0,0,0,100,0,8000,9000 ,8000,9000 ,11,60472,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Alumeth - IC - Cast Mindflay'),
(@Alumeth,0,1,0,0,0,100,0,8000,10000,8000,10000,11,34322,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Alumeth - IC -  Cast Psychicscream'),
(@Alumeth,0,2,0,0,0,100,0,9000,12000,9000,12000,11,37978,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Alumeth - IC -  Cast Renew'),
(@Alumeth,0,3,0,0,0,100,0,7000,10000,7000,10000,11,34942,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Alumeth - IC -  Cast Shadow Word: Pain');
-- Fix Alumeth Soulstone GO spell focus data range
UPDATE `gameobject_template` SET `data1`=25 WHERE `entry`=300241; -- This GO isn't sniffed and is temp for that reason, value over 300k so it can be edited.
-- Add conditions for spell trigger to summon boss
DELETE FROM `conditions` WHERE `SourceEntry` IN (@Trigger,60834) AND `SourceTypeOrReferenceId`=13;
DELETE FROM `conditions` WHERE `SourceEntry`=@Trigger AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17,0,@Trigger,0,0,29,0,@Alumeth,40,0,1,0,'', 'Alumeth''s Remains can be used only, if he is not near caster in 40 yards'),
(13,1,@Trigger,0,0,31,0,3,@SummonBunny,0,0,0,'', 'Alumeth''s Remains can hit only summoning bunny'),
(13,1,60834,0,0,31,0,3,@SummonBunny,0,0,0,'','Ping Alumeth Summon Bunny can hit only SummonBunny');
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- 4.x
-- Issue 4350: Gregory Tabor
-- Spawn Gregory Tabor 
-- SET @GUID := 43465;
-- DELETE FROM `creature` WHERE `id`=34675;
-- INSERT INTO `creature` (`guid`,`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
-- (@GUID,34675,0,1,1,0,0,-9130.26,351.84,93.85,2.0151,300,0,0,1524,0,0,0,0,0);
-- DELETE FROM `game_event_creature` WHERE `eventEntry`=26 AND `guid`=@GUID;
-- INSERT INTO `game_event_creature` (`eventEntry`,`guid`) VALUES
-- (26,@GUID);
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 4551: Anatoly Will Talk
DELETE FROM `npc_spellclick_spells` WHERE npc_entry = 27626;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type` ) VALUES
(27626,49138,1,0);
UPDATE creature_template SET faction_a = 16, faction_h = 16, `AIName` = 'SmartAI' WHERE `entry` = 27626; -- Same in sniffs
DELETE FROM smart_scripts WHERE `entryorguid` in (27626,2762600);
INSERT INTO smart_scripts VALUES
(27626,0,1,0,8,0,100,0x1,49134,0,0,0,12,27626,1,300000,0,0,0,0,0,0,0,0,0,0,0, 'Tatjana''s horse - On Spell Hit - resumm'),
(27626,0,2,0,54,0,100,0,0,0,0,0,80,2762600,0,2,0,0,0,1,0,0,0,0,0,0,0,'On time - Run Script'),
(27626,0,3,0,40,0,100,1,18,0,0,0,15,12330,0,0,0,0,0,18,5,0,0,0,0,0,0,'WP 18 - KC'),
(27626,0,4,0,40,0,100,1,19,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'WP 19 - Despawn'),
(27626,0,5,0,40,0,100,1,1,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Set Run"),
(27626,0,6,0,8,0,100,0x1,49134,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tatjana''s horse - On Spell Hit - Invisible'),
(27626,0,7,0,8,0,100,0x1,49134,0,0,0,41,500,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tatjana''s horse - On Spell Hit - Despawn'),
(27626,0,8,0,54,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'On time - faction'),
(2762600,9,0,0,0,0,100,1,4000,4000,0,0,53,0,27626,0,0,0,2,0,0,0,0,0,0,0,0,'On Script - WP Start');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=49134;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES 
(13,1,49134,31,3,27626, 'Tranquilizer Dart targets Tatjana''s Horse');
DELETE FROM `waypoints` WHERE `entry`= 27626;
INSERT INTO `waypoints`
(`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`)
VALUES
(27626,1,4042.49,-4378.298,261.47,''),
(27626,2,4052.839,-4381.89,260.577,''),
(27626,3,4061.94,-4374.57,260.44,''),
(27626,4,4078.97,-4375.19,260.93,''),
(27626,5,4090.33,-4361.82,261.34,''),
(27626,6,4091.73,-4341.6,261.34,''),
(27626,7,4094.09,-4325.83,260.91,''),
(27626,8,4108.3,-4300.63,252.85,''),
(27626,9,4124.35,-4281.08,251.25,''),
(27626,10,4126.15,-4258.29,251.3,''),
(27626,11,4126.1,-4243.9,248.35,''),
(27626,12,4100.1,-4224.51,237.86,''),
(27626,13,4087.17,-4208.72,230.58,''),
(27626,14,4082.93,-4172.83,218.13,''),
(27626,15,4077.66,-4151.22,211.94,''),
(27626,16,4083.57,-4138.46,212.4,''),
(27626,17,4079.16,-4127.81,212.26,''),
(27626,18,4067.57,-4127.6,211.13,''),
(27626,19,4068.35,-4128.44,211.3,'');
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 5025: Pilgrim's Bounty
-- Insert into proper DB table Piligrim's Bounty quest to prevent random showing it during the year
DELETE FROM `creature_involvedrelation` WHERE `quest`=14036;
DELETE FROM `game_event_creature_quest` WHERE `quest`=14036;
INSERT INTO `game_event_creature_quest` (`eventEntry`, `id`, `quest`) VALUES
(26,34677,14036);
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 5419: The Fallen Sisters Bugged again
-- Quest - The Fallen Sisters
SET @ENTRY := 23678;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY,0,0,0,11,0,100,0,0,571,495,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chill Nymph - Respawn - reset faction'),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chill Nymph - Reset - set phase 1'),
(@ENTRY,0,2,3,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chill Nymph - On health 30% - Do text emote'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chill Nymph - On health 30% - set phase 2'),
(@ENTRY,0,4,0,0,0,75,0,2000,3000,2000,2000,11,9739,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Chill Nymph - In Combat - Cast Wrath on victim'),
(@ENTRY,0,5,6,8,2,100,0,43340,0,30000,30000,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Chill Nymph - On Spell hit 43340 - Face invoker'),
(@ENTRY,0,6,7,61,0,100,0,0,0,0,0,33,24117,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Chill Nymph - On Spell hit 43340 - Give Quest credit'),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,80,2367800,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Chill Nymph - On Spell hit 43340 - Load script'),
(@ENTRY,0,8,0,40,0,100,0,1,23678,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chill Nymph - On reach waypoint 1 - Despawn'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chill Nymph - Script 2 - Evade'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chill Nymph - Script 3 - Set faction 35'),
(@ENTRY*100,9,2,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chill Nymph - Script 4 - Say text 1'),
(@ENTRY*100,9,3,0,0,0,100,0,1000,1000,0,0,53,1,23678,0,0,0,0,1,0,0,0,0,0,0,0, 'Chill Nymph - Script 5 - Start waypoint movement');
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 5647: The Lost Spirits
-- Update Event Type From On Summon(11) to Reset(25)
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=25321 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=25322 AND `source_type`=0 AND `id`=0;
-- Update Core of Malice drop rate
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry`=25355 AND `item`=34711;
-- Remove item Tuskarr Ritual Object from Beryl Hounds
DELETE FROM `creature_loot_template` WHERE `item`=34713;
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 5679: Feedin' Da Goolz
SET @GHOUL := 28565;
SET @TRIGER := 28591;
SET @SOURCETYPE := 0;
UPDATE `creature_template` SET `AiName`='SmartAI',`flags_extra`=`flags_extra`|2|128 WHERE `entry`=@TRIGER;
UPDATE `creature_template` SET `AiName`='SmartAI' WHERE `entry`=@GHOUL;
-- DELETE FROM `creature_ai_scripts`WHERE `creature_id` IN (@GHOUL,@TRIGER); 4.x
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@GHOUL,@TRIGER);
INSERT INTO `smart_scripts` VALUES 
(@GHOUL,@SOURCETYPE,0,0,38,0,100,0,0,1,0,0,29,1,1,28591,0,0,0,19,@TRIGER,15,0,0,0,0,0, 'Ghoul - on data 1 set - start follow'),
(@GHOUL,@SOURCETYPE,1,2,65,0,100,0,0,0,0,0,33,28591,0,0,0,0,0,21,20,0,0,0,0,0,0, 'Ghoul - on follow completed - give kill credit'),
(@GHOUL,@SOURCETYPE,2,3,61,0,100,0,0,0,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ghoul - on follow completed - despawn'),
(@GHOUL,@SOURCETYPE,3,0,61,0,100,0,0,0,0,0,51,0,0,0,0,0,0,11,@TRIGER,50,0,0,0,0,0, 'Ghoul - on follow completed - kill ghoul'),
(@TRIGER,@SOURCETYPE,0,0,25,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@GHOUL,15,0,0,0,0,0, 'Ghoul Trigger - on just summoned - set data 1 on nearest Ghoul');
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 5764: The One That Got Away
-- Fix quest The One That Got Away /Alliance only/ ID: 11410
SET @Frostfin := 24500; -- The required npc to be summoned
SET @Bite := 48287; -- Npc special attack
SET @Event := 16103;
-- Makes the specific spell that already have the callevent defined summon Frostfin
DELETE FROM `event_scripts` WHERE `id`=@Event;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`x`,`y`,`z`,`o`) VALUES
(16103,0,10,@Frostfin,300000,2321.083740,-5260.119629,221.108795,0.248830);
-- Add SAI for Frostfin
UPDATE `creature_template` SET `InhabitType`=2,`AIName`= 'SmartAI' WHERE `entry`= @Frostfin;
-- DELETE FROM `creature_ai_scripts` WHERE creature_id = @Frostfin; -- 4.x
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Frostfin;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Frostfin,0,0,0,0,0,100,0,2000,3000,5000,8000,11,@Bite,0,0,0,0,0,2,0,0,0,0,0,0,0,'IC - Cast Powerful Bite');
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 5785: Find the Ancient Hero
SET @Mjordin := 30718;
SET @Iskalder := 30884; -- the hostile version
SET @FriendlyI := 30886; -- the friendly version
SET @Script1 := 3088400; -- spawn mjoldir on gossip
SET @Script2 := 3088401; -- spawn Iskalder on gossip
SET @Amulet := 3921; -- the spell casted on Iskalder
SET @Witch := 30232; -- Bonne witch
SET @Credit := 25729; -- quest credit
-- Add SAI for Slumbering Mjording
UPDATE `creature_template` SET AIName='SmartAI', unit_flags=0 WHERE `entry`=@Mjordin;
DELETE FROM `smart_scripts` WHERE entryorguid IN(@Mjordin,@Script1,@Script2);
INSERT INTO `smart_scripts` VALUES
(@Mjordin,0,0,0,62,0,100,0,10008,0,0,0,87,@Script1,@Script1,@Script1,@Script2,@Script1,@Script1,1,0,0,0,0,0,0,0,'Slumbering Mjordin - Gossip - Random Script'),
(@Script1,9,0,0,0,0,100,0,500,500,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'Slumbering Mjordin - Script - Enemy'), -- Option 1
(@Script1,9,1,0,0,0,100,0,1000,1000,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Slumbering Mjordin - Script - Aggresive'),
(@Script2,9,0,0,0,0,100,0,1000,1000,0,0,12,@Iskalder,3,180000,0,0,0,1,0,0,0,0,0, 0,0,'Slumbering Mjordin - Script - Summon Iskalder '), -- Option 2
(@Script2,9,1,0,0,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0, 0,0,'Slumbering Mjordin - Script - Unseen'),
(@Script2,9,2,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0, 0,0,'Slumbering Mjordin - Script - Despawn');
-- Add SAI for Iskalder hostile - these values are not sniffed they are guessed by wowhead comments...
UPDATE `creature_template` SET `exp`=2,`faction_A`=1885, `faction_H`=1885, `minlevel`=80, `maxlevel`=80, `mindmg`=300, `maxdmg`=350, `AIName`='SmartAI' WHERE `entry`=@Iskalder; -- Faction from sniffs
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Iskalder;
INSERT INTO `smart_scripts` VALUES
(@Iskalder,0,0,0,54,0,100,0,0,0,0,0,1,1,100,0,0,0,0,1,0,0,0,0,0,0,0,'Iskalder - On summon - Say text'),
(@Iskalder,0,1,0,8,0,100,0,@Amulet,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Iskalder - On hit by spell from amulet - Despawn');
-- Add SAI for Iskalder Friendly
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@FriendlyI;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@FriendlyI;
INSERT INTO `smart_scripts` VALUES
(@FriendlyI,0,0,0,0,0,100,1,1,1,1,1,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,'Friendly Iskalder - On IC - Change field flag to immune to npc/prevents from not moving bug/'),
(@FriendlyI,0,1,0,1,0,100,0,2000,3000,2000,3000,29,0,0,@Witch,0,1,0,9,@Witch,1,10,0,0,0,0,'Friendly Iskalder - On OOC - Follow Bonnewitch if in range 10 yards'),
(@FriendlyI,0,2,0,65,0,100,0,0,0,0,0,11,@Credit,0,0,0,0,0,23,0,0,0,0,0,0,0,'Friendly Iskalder - On follow complete - Cast spell credit to player');
-- Makes amulet target only the required npc
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=@Amulet;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,@Amulet,0,0,31,1,3,@Iskalder,0,0,0,'','Amulet can target only Iskalder');
-- The purple beam effect of amulet can target only Iskalder
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@Amulet;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,2,@Amulet,0,0,31,1,3,@Iskalder,0,0,0,'','The purple beam effect of amulet can target only Iskalder');
-- Cast amulet on Iskalder warning /text/
DELETE FROM `creature_text` WHERE `entry`=@Iskalder;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Iskalder,1,1,'You have found him! Now is the time to use the The Bone Witch"s Amulet!',41,0,100,0,100,0,'Originaly it as the Bonne witch guide');
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 5821: Shattrath Daily Quests missing ExclusiveGroup
-- Set ExclusiveGroup for Shattrath Daily Quests, you can have only one per questgiver
UPDATE `quest_template` SET `ExclusiveGroup`=11364 WHERE `Id` IN (11376, 11383, 11385, 11371, 11389, 11500, 11364, 11387);
UPDATE `quest_template` SET `ExclusiveGroup`=11354 WHERE `Id` IN (11382, 11368, 11378, 11374, 11499, 11370, 11372, 11369, 11388, 11362, 11363, 11375, 11354, 11386, 11373, 11384);
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Hacks!
-- Issue 6284: Nether Drake Egg
-- UPDATE `gameobject_template` SET `data10`=36326,`data5`=1 WHERE `entry`=184867;
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 6627: Quest - 28056
-- Add condition for gossip option
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=1282;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,1282,0,0,0,9,3566,0,0,0,0,'','Alter of Suntara - Show gossip option only if player has taken quest "Rise, Obsidion"');
-- Adding SmartAI Text for Lathoric the Black
DELETE FROM `creature_text` WHERE `entry`=8391;
INSERT INTO creature_text (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(8391,0,0, 'You are here to stop the Archduke?',14,0,100,0,0,0, 'Lathoric the Black'),
(8391,1,0, 'Fools.  Obsidion!  Rise, and destroy the interlopers!',14,0,100,0,0,0, 'Lathoric the Black');
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 5760: Before the Gate of Horror
-- Fix {Qs} Before the Gate of Horror Id: 13335 /Alliance/ and Before the Gate of Horror Id: 13329 /Horde/
SET @SkeletalReaver  := 32467; -- The main npcs that can be hit with spell Dissolve only in dead condition
SET @FreedRemnant    := 32288; -- Kill credit from quest that has no spell to be used with, so requires action 33
SET @Dissolve        := 60428; -- Spell used to trigger npc to cast kill credit on invoker
-- Add SAI for Skeletal Reaver
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@SkeletalReaver;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@SkeletalReaver;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SkeletalReaver,0,0,1,8,0,100,0,@Dissolve,0,0,0,33,@FreedRemnant,0,0,0,0,0,7,0,0,0,0,0,0,0,'Skeletal Reaver - On hit by spell Dissolve - Give kill credit to invoker'),
(@SkeletalReaver,0,1,2,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Skeletal Reaver - Linked with previous event - Set unseen'),
(@SkeletalReaver,0,2,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Skeletal Reaver - Linked with previous event - Set despawn in 1 ms');
-- Add conditions for spell Dissolve to target only dead Skeletal Reavers
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=@Dissolve;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,@Dissolve,0,0,36,1,0,0,0,1,0,'','Dissolve can be casted only on creatures that are not alive'),
(17,0,@Dissolve,0,0,31,1,3,@SkeletalReaver,0,0,0,'','Dissolve can be casted only on Skeletal Reavers');
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 6632: Quest Audio - 12593
UPDATE `creature_template` SET `AIName`= 'SmartAI'  WHERE `entry`=25462;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=25462 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(25462,0,0,0,19,0,100,0,12593,0,0,0,4,14734,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Lich King - On Quest Accept - Play Sound');
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 6724: Souls of the Decursed
DELETE FROM `conditions` WHERE `SourceEntry`=46485 AND `ConditionValue2`=26814; -- /slap to the guy that entered this query
UPDATE `conditions` SET `ConditionValue2`=25814,`ElseGroup`=0 WHERE `SourceEntry`=46485 AND `ConditionTypeOrReference`=31;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25814 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25814,0,0,0,4,0,100,0,0,0,0,0,1,1,10000,0,0,0,0,0,0,0,0,0,0,0,0, 'Fizzcrank Mechagnome - On Aggro - Say Line'),
(25814,0,1,0,8,0,100,0,45980,0,0,0,33,25773,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Fizzcrank Mechagnome - On Spellhit 45980 - Give Kill Credit (Re-Cursive)'),
(25814,0,2,3,8,0,100,0,46485,0,0,0,33,26096,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Fizzcrank Mechagnome - On Spellhit 46485 - Give Kill Credit (Souls of the Decursed'),
(25814,0,3,0,61,0,100,0,0,0,0,0,41,10,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fizzcrank Mechagnome - On Spellhit 46485 - Despawn after 10 ms');
-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- ------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7837: Norgannon's Shell (12872,12928)
-- Loot
DELETE FROM `creature_loot_template` WHERE `entry`=29775 AND `item`=41258;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(29775,41258,-100,1,0,1,1); -- Norgannon's Shell
-- Charged Disk event script for summoning Archivist Mechaton
DELETE FROM `creature` WHERE `id`=29775;
DELETE FROM `event_scripts` WHERE `id`=19410;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(19410,2,10,29775,300000,0,7991.81,-827.674,968.263,2.89725);
-- ------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7907: Windcaller Yessendra (15498),Warden Haro (15499),Keyl Swiftclaw (15500),Mokvar (16012) & Deliana (16013) quests 
UPDATE `quest_template` SET `RequiredClasses`=1 WHERE `Id`=8556; -- Warrior
UPDATE `quest_template` SET `RequiredClasses`=2 WHERE `Id`=8703; -- Paladin
UPDATE `quest_template` SET `RequiredClasses`=4 WHERE `Id`=8704; -- Hunter
UPDATE `quest_template` SET `RequiredClasses`=8 WHERE `Id`=8701; -- Rogue
UPDATE `quest_template` SET `RequiredClasses`=16 WHERE `Id`=8697; -- Priest
UPDATE `quest_template` SET `RequiredClasses`=64 WHERE `Id`=8698; -- Shaman
UPDATE `quest_template` SET `RequiredClasses`=128 WHERE `Id`=8699; -- Mage
UPDATE `quest_template` SET `RequiredClasses`=256 WHERE `Id`=8702; -- Warlock
UPDATE `quest_template` SET `RequiredClasses`=1024 WHERE `Id`=8700; -- Druid
-- Warden Haro (15499) quests RequiredClasses fix by nelegalno
UPDATE `quest_template` SET `RequiredClasses`=1 WHERE `Id`=8558; -- Warrior
UPDATE `quest_template` SET `RequiredClasses`=2 WHERE `Id`=8711; -- Paladin
UPDATE `quest_template` SET `RequiredClasses`=4 WHERE `Id`=8712; -- Hunter
UPDATE `quest_template` SET `RequiredClasses`=8 WHERE `Id`=8709; -- Rogue
UPDATE `quest_template` SET `RequiredClasses`=16 WHERE `Id`=8705; -- Priest
UPDATE `quest_template` SET `RequiredClasses`=64 WHERE `Id`=8706; -- Shaman
UPDATE `quest_template` SET `RequiredClasses`=128 WHERE `Id`=8707; -- Mage
UPDATE `quest_template` SET `RequiredClasses`=256 WHERE `Id`=8710; -- Warlock
UPDATE `quest_template` SET `RequiredClasses`=1024 WHERE `Id`=8708; -- Druid
-- Keyl Swiftclaw (15500) quests RequiredClasses fix by nelegalno
UPDATE `quest_template` SET `RequiredClasses`=1 WHERE `Id`=8557; -- Warrior
UPDATE `quest_template` SET `RequiredClasses`=2 WHERE `Id`=8695; -- Paladin
UPDATE `quest_template` SET `RequiredClasses`=4 WHERE `Id`=8696; -- Hunter
UPDATE `quest_template` SET `RequiredClasses`=8 WHERE `Id`=8693; -- Rogue
UPDATE `quest_template` SET `RequiredClasses`=16 WHERE `Id`=8689; -- Priest
UPDATE `quest_template` SET `RequiredClasses`=64 WHERE `Id`=8690; -- Shaman
UPDATE `quest_template` SET `RequiredClasses`=128 WHERE `Id`=8691; -- Mage
UPDATE `quest_template` SET `RequiredClasses`=256 WHERE `Id`=8694; -- Warlock
UPDATE `quest_template` SET `RequiredClasses`=1024 WHERE `Id`=8692; -- Druid
-- Mokvar (16012) quests RequiredClasses fix by nelegalno
UPDATE `quest_template` SET `RequiredClasses`=1 WHERE `Id` IN (8920,8944,9013,9022); -- Warrior
UPDATE `quest_template` SET `RequiredClasses`=2 WHERE `Id` IN (10493,10495,10497,10499); -- Paladin
UPDATE `quest_template` SET `RequiredClasses`=4 WHERE `Id` IN (8914,8938,9008,9017); -- Hunter
UPDATE `quest_template` SET `RequiredClasses`=8 WHERE `Id` IN (8917,8941,9010,9020); -- Rogue
UPDATE `quest_template` SET `RequiredClasses`=16 WHERE `Id` IN (8916,8940,9009,9019); -- Priest
UPDATE `quest_template` SET `RequiredClasses`=64 WHERE `Id` IN (8918,8942,8957,9011); -- Shaman
UPDATE `quest_template` SET `RequiredClasses`=128 WHERE `Id` IN (8915,8939,9014,9018); -- Mage
UPDATE `quest_template` SET `RequiredClasses`=256 WHERE `Id` IN (8919,8943,9012,9021); -- Warlock
UPDATE `quest_template` SET `RequiredClasses`=1024 WHERE `Id` IN (8913,8927,9007,9016); -- Druid
-- Deliana (16013) quests RequiredClasses fix by nelegalno
UPDATE `quest_template` SET `RequiredClasses`=1 WHERE `Id` IN (8912,8959,8937,9006); -- Warrior
UPDATE `quest_template` SET `RequiredClasses`=2 WHERE `Id` IN (8908,8954,10494,9002); -- Paladin
UPDATE `quest_template` SET `RequiredClasses`=4 WHERE `Id` IN (8906,8952,8931,9000); -- Hunter
UPDATE `quest_template` SET `RequiredClasses`=8 WHERE `Id` IN (8910,8956,8935,9004); -- Rogue
UPDATE `quest_template` SET `RequiredClasses`=16 WHERE `Id` IN (8909,8955,8934,9003); -- Priest
UPDATE `quest_template` SET `RequiredClasses`=64 WHERE `Id` IN (10492,10496,10494,10498); -- Shaman
UPDATE `quest_template` SET `RequiredClasses`=128 WHERE `Id` IN (8907,8953,8932,9001); -- Mage
UPDATE `quest_template` SET `RequiredClasses`=256 WHERE `Id` IN (8911,8958,8936,9005); -- Warlock
UPDATE `quest_template` SET `RequiredClasses`=1024 WHERE `Id` IN (8905,8951,8926,8999); -- Druid
-- ------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7908: Attunement to the Core (7487,7848)
-- Attunement to the Core (7848) quest RequiredRaces fix by nelegalno
-- UPDATE `quest_template` SET `RequiredRaces`=0 WHERE `Id`=7848;
-- Revert previous Attunement to the Core (7487,7848) quest fix
UPDATE `quest_template` SET `RequiredRaces`=1101 WHERE `Id`=7848; -- A
UPDATE `quest_template` SET `RequiredRaces`=690 WHERE `Id`=7487; -- H
-- ------------------------------------------------------------------------------------------------------------------------------------------------
-- 4.x
-- Issue 8021: spawn location in OG near Rogg (37072)
-- SET @GUID := 76; -- set by TDB team
-- DELETE FROM `gameobject` WHERE `guid`=@GUID;
-- INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
-- (@GUID,1685,1,1,1,1523.778,-4368.241,18.21412,6.07367,0,0,0,1,300,100,1);
-- ------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8086: Missing Fires for Hallow End Q 
-- This won't fix the quest until the rest of the event is scripted.
SET @CREATURE_GUID := 222; -- set by TDB team - 4.x
DELETE FROM `creature` WHERE `id` IN (23537,23686) AND `guid` BETWEEN @CREATURE_GUID+00 AND @CREATURE_GUID+12;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
-- Spawn fire dummys for fire effigys
(@CREATURE_GUID+0,23537,530,1,1,0,0,-4192.38,-12268.1,2.53389,-1.72788,300,0,0,45780,0,0,0,0,0),
(@CREATURE_GUID+1,23537,530,1,1,0,0,-4207.84,-12276.7,4.82085,-0.069813,300,0,0,45780,0,0,0,0,0),
-- (@CREATURE_GUID+2,23537,0,1,1,0,0,-5753.24,-533.652,405.022,1.15192,300,0,0,45780,0,0,0,0,0),
-- (@CREATURE_GUID+3,23537,0,1,1,0,0,-5761.17,-528.193,404.855,1.16937,300,0,0,15260,0,0,0,0,0),
-- (@CREATURE_GUID+4,23537,0,1,1,0,0,-5747.52,-527.634,401.297,0.610865,300,0,0,15260,0,0,0,0,0),
-- (@CREATURE_GUID+5,23537,1,1,1,0,0,286.565,-4561.45,28.5742,2.42601,300,0,0,15260,0,0,0,0,0),
(@CREATURE_GUID+2,23537,530,1,1,0,0,9235.05,-6783.4,26.4426,1.5708,300,0,0,15260,0,0,0,0,0);
-- (@CREATURE_GUID+7,23537,0,1,1,0,0,2240.44,459.159,39.2838,0.820305,300,0,0,15260,0,0,0,0,0),
-- (@CREATURE_GUID+8,23537,0,1,1,0,0,2239.49,487.861,38.3446,-0.715585,300,0,0,15260,0,0,0,0,0),
-- (@CREATURE_GUID+9,23537,0,1,1,0,0,-9328.25,56.2778,63.2509,2.60054,300,0,0,15260,0,0,0,0,0),
-- (@CREATURE_GUID+10,23537,0,1,1,0,0,-9314.1,52.4562,77.7343,2.93215,300,0,0,15260,0,0,0,0,0),
-- Spawn Fire Handlers for villages
-- (@CREATURE_GUID+11,23686,1,1,1,0,0,305.144,-4724.5,9.83766,3.68348,300,0,0,7185,7196,0,0,0,0),
-- (@CREATURE_GUID+12,23686,0,1,1,0,0,-9465.54,63.2228,55.8587,6.25841,300,0,0,7185,7196,0,0,0,0);
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CREATURE_GUID+00 AND @CREATURE_GUID+12;
INSERT INTO `game_event_creature` VALUES
(12,@CREATURE_GUID+00),
(12,@CREATURE_GUID+01),
(12,@CREATURE_GUID+02);
-- ------------------------------------------------------------------------------------------------------------------------------------------------
-- 4.x removed (map 0 and 1)
-- Issue 8133: Wickerman Festival NPC & GO's
-- Wickerman Festival
-- SET @GO_GUID       := 17868; -- set by TDB team (14)
-- SET @CREATURE_GUID := 85632; -- set by TDB team (5)
-- UPDATE `gameobject_template` SET `flags` = 17 WHERE `entry` = 180433;
-- DELETE FROM `gameobject` WHERE id IN (180432,180433,180434,180437,180405,180406) AND `guid` BETWEEN @GO_GUID+00 AND @GO_GUID+13;
-- INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
-- Forsaken Banner
-- (@GO_GUID+00,180432,0,1,1,1749.28,507.611,39.2312,1.49635,0,0,0.680301,0.732933,300,0,1),
-- (@GO_GUID+01,180432,0,1,1,1712.63,507.05,38.2495,1.58824,0,0,0.713246,0.700914,300,0,1),
-- The Wickerman
-- (@GO_GUID+02,180433,0,1,1,1734.04,504.05,42.2861,1.4131,0,0,0.649213,0.760607,300,0,0),
-- Bonfire
-- (@GO_GUID+03,180434,0,1,1,1758.89,513.276,35.8655,1.28897,0,0,0.600788,0.799409,300,0,1),
-- (@GO_GUID+04,180434,0,1,1,1704.48,518.689,35.4045,1.30704,0,0,0.607984,0.793949,300,0,1),
-- (@GO_GUID+05,180434,0,1,1,1739.78,473.238,61.6565,1.59371,0,0,0.71516,0.698961,300,0,1),
-- (@GO_GUID+06,180434,0,1,1,1717.32,472.723,61.6566,1.59371,0,0,0.71516,0.698961,300,0,1),
-- Wickerman Ember
-- (@GO_GUID+07,180437,0,1,1,1744.62,504.954,40.8518,1.23403,0,0,0.578603,0.81561,300,0,1),
-- (@GO_GUID+08,180437,0,1,1,1729.13,510.378,40.8719,1.23403,0,0,0.578603,0.81561,300,0,1),
-- (@GO_GUID+09,180437,0,1,1,1721.77,503.938,41.1381,1.23403,0,0,0.578603,0.81561,300,0,1),
-- (@GO_GUID+10,180437,0,1,1,1744.96,496.25,41.44,1.24581,0,0,0.583397,0.812187,300,0,1),
-- G_Pumpkin_01
-- (@GO_GUID+11,180405,0,1,1,1746.07,517.066,38.936,2.83466,0,0,0.988247,0.152864,300,0,1),
-- (@GO_GUID+12,180405,0,1,1,1728,475.099,63.6779,3.08363,0,0,0.99958,0.0289791,300,0,1),
-- G_Pumpkin_02
-- (@GO_GUID+13,180406,0,1,1,1719.67,522.979,36.8828,2.93283,0,0,0.994557,0.10419,300,0,1);
-- DELETE FROM `creature` WHERE `id` IN (15195,15197,15199) AND `guid` BETWEEN @CREATURE_GUID+00 AND @CREATURE_GUID+04;
-- INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
-- Wickerman Guardian
-- (@CREATURE_GUID+0,15195,0,1,1,0,0,1713.1,511.295,37.2005,1.48063,300,0,0,45780,0,0,0,0,0),
-- (@CREATURE_GUID+1,15195,0,1,1,0,0,1750.57,511.697,37.7587,1.25444,300,0,0,45780,0,0,0,0,0),
-- (@CREATURE_GUID+2,15195,0,1,1,0,0,1732.31,520.874,36.3326,1.30942,300,0,0,45780,0,0,0,0,0),
-- Darkcaller Yanka
-- (@CREATURE_GUID+3,15197,0,1,1,0,0,1734.6,508.803,41.2847,1.6173,300,0,0,15260,0,0,0,0,0),
-- Sergeant Hartman
-- (@CREATURE_GUID+4,15199,0,1,1,0,0,-813.614,-547.184,15.6377,1.69193,300,0,0,15260,0,0,0,0,0);
-- DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @GO_GUID+00 AND @GO_GUID+13;
-- INSERT INTO `game_event_gameobject` VALUES
-- (12,@GO_GUID+00),
-- (12,@GO_GUID+01),
-- (12,@GO_GUID+02),
-- (12,@GO_GUID+03),
-- (12,@GO_GUID+04),
-- (12,@GO_GUID+05),
-- (12,@GO_GUID+06),
-- (12,@GO_GUID+07),
-- (12,@GO_GUID+08),
-- (12,@GO_GUID+09),
-- (12,@GO_GUID+10),
-- (12,@GO_GUID+11),
-- (12,@GO_GUID+12),
-- (12,@GO_GUID+13);
-- DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CREATURE_GUID+00 AND @CREATURE_GUID+04;
-- INSERT INTO `game_event_creature` VALUES
-- (12,@CREATURE_GUID+00),
-- (12,@CREATURE_GUID+01),
-- (12,@CREATURE_GUID+02),
-- (12,@CREATURE_GUID+03),
-- (12,@CREATURE_GUID+04);
-- Wickerman Ashes
DELETE FROM `gossip_menu` WHERE `entry` = 6535;
INSERT INTO `gossip_menu` VALUES
(6535,7737),
(6535,7738);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=6535 AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(6535,0,0, 'Smear the ash on my face like war paint!',1,1,0,0,0,0, ''); -- need text confirmation
-- gossip conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=6535;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,6535,7738,0,0,1,0,24705,0,0,0,0, '', 'Wickerman Ember - Show different gossip if player is affected by aura 24705'),
(14,6535,7737,0,0,1,0,24705,0,0,1,0, '', 'Wickerman Ember - Show different gossip if player is affected by aura 24705'),
(15,6535,0,0,0,1,0,24705,0,0,1,0, '', 'Wickerman Ember - Show different gossip option if player is affected by aura 24705');
-- GO smart script
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=180437;
DELETE FROM `smart_scripts` WHERE `entryorguid`=180437 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(180437,1,0,1,62,0,100,0,6535,0,0,0,85,24705,34,0,0,0,0,7,0,0,0,0,0,0,0, 'Wickerman Ember - on Gossip Select - Cast Invocation of the Wickerman'),
(180437,1,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Wickerman Ember - on Link - Close gossip');
-- ------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8244: Hallow's End Pumpkin Treat & Tricky Treat time fix
-- Hallow's End Pumpkin Treat time fix & Tricky Treat time fix
-- UPDATE `item_template` SET `flagsCustom`=1 WHERE `entry` IN(20557,33226); -- 4.x
-- ------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8288: Exhausted Vrykul - not responding after using discipline stick on him
SET @ENTRY := 30146; -- Exhausted Vrykul
SET @SPELL := 56033; -- Disciplining Rod
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100,@ENTRY*100+1) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,25,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Exhausted Vrykul - Reset - Switch to Phase 1'),
(@ENTRY,0,1,0,1,1,100,0,0,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Exhausted Vrykul - On phase 1 - Seat'),
(@ENTRY,0,2,3,8,1,100,0,@SPELL,0,0,0,33,29886,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Exhausted Vrykul - On Spell hit & phase 1 - Kill Credit'),
(@ENTRY,0,3,0,61,1,100,0,0,0,0,0,31,2,3,0,0,0,0,1,0,0,0,0,0,0,0, 'Exhausted Vrykul - Link Spell hit - Switch to Phase 2 or 3'),
(@ENTRY,0,4,5,1,2,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Exhausted Vrykul - If phase 2 - Say random text 0'),
(@ENTRY,0,5,6,61,2,100,0,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Exhausted Vrykul - If phase 2 - Stand up'),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Exhausted Vrykul - On phase 2 - Start Attack'),
(@ENTRY,0,7,8,1,4,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Exhausted Vrykul - On phase 3 - Say random text 1'),
(@ENTRY,0,8,9,61,4,100,0,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Exhausted Vrykul - If phase 3 - Stand up'),
(@ENTRY,0,9,10,61,4,100,0,0,0,0,0,46,6,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Exhausted Vrykul - If phase 3 - walk 6 yards'),
(@ENTRY,0,10,0,61,4,100,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Exhausted Vrykul - On phase 3 - Emote Work mining'),
(@ENTRY,0,11,0,1,4,100,1,60000,60000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Exhausted Vrykul - On phase 3 & 1 minute OOC - despawn'),
(@ENTRY,0,12,0,2,0,100,1,0,30,0,0,11,57395,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Exhausted Vrykul - At 30% Hp - Cast Desperate Blow');
-- ------------------------------------------------------------------------------------------------------------------------------------------------
DELETE FROM `creature_addon` WHERE `guid` IN (85486);
