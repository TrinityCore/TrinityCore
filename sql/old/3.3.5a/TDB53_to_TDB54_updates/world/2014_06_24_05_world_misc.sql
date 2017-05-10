-- Add support for quest Changing the Wind's Course - ID: 13058 /Horde/
SET @Stormhoof :=    30388;
SET @VehicleSpell := 56863;
SET @Ride :=         46598;
SET @Wind :=         30474;
SET @DropHorn :=     56892;
SET @Stun :=         62794;
SET @Guid :=         40509; -- Set by TDB

-- Add spawn in phase 256 for The Wind of North
DELETE FROM `creature` WHERE `guid`=@Guid;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@Guid,@Wind,571,1,256,0,0,7942.61,-2723.29,1138,6.09394,60,0,0,63000,19970,0,0,0,0);

-- SAI and spell support for StormHoof
UPDATE `creature_template` SET `AIName`='SmartAI',`spell1`=56897,`spell2`=61668,`spell3`=56896 WHERE `entry`=30388;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Stormhoof;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Stormhoof,0,0,1,54,0,100,0,0,0,0,0,85,56900,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stormhoof - On summoned - Cast power of Lorehammer on invoker /used to store invoker/'),
(@Stormhoof,0,1,0,61,0,100,0,0,0,0,0,85,@Ride,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stormhoof - Linked with previous event - Ivoker cast Ride hardcoded on Stormhoof '),
(@Stormhoof,0,2,0,4,0,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stormhoof - On aggro - Disable auto attacks'),
(@Stormhoof,0,3,0,8,0,100,0,@Ride,0,0,0,2,2141,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stormhoof - On hit by spell Ride - Change faction to hostile towards Wind'),
(@Stormhoof,0,4,5,38,0,100,0,0,1,0,0,18,8196,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stormhoof - On data set 0 1 - Set unit flags for No move, Silence and Pacified'),
(@Stormhoof,0,5,0,61,0,100,0,0,0,0,0,1,0,1000,0,0,0,0,1,0,0,0,0,0,0,0,'Stormhoof - Linked with previous event - Say text 1'),
(@Stormhoof,0,6,7,38,0,100,0,0,2,0,0,75,@Stun,0,0,0,0,0,19,@Wind,30,0,0,0,0,0,'Stormhoof - On Data set 0 2 - Set stun on wind'),
(@Stormhoof,0,7,8,61,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stormhoof - Linked with previous event - Die'),
(@Stormhoof,0,8,0,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stormhoof - Linked with previous event - Set unseen'),
(@Stormhoof,0,9,10,6,0,100,0,0,0,0,0,19,8196,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stormhoof - On death - Remove unit_flags'),
(@Stormhoof,0,10,0,61,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stormhoof - Linkedw with previous event - Change faction to 35');

-- Add SAI support for North Wind
UPDATE `creature_template` SET `mindmg`=327,`maxdmg`=362,`faction`=16,`AIName`='SmartAI' WHERE `entry`=@Wind;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Wind;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Wind,0,0,0,0,0,100,0,1000,3000,8000,11000,11,61662,0,0,0,0,0,2,0,0,0,0,0,0,0,'North Wind - IC - Cast Cyclone'),
(@Wind,0,1,0,0,0,100,0,1000,8000,12000,16000,11,61663,0,0,0,0,0,2,0,0,0,0,0,0,0,'North Wind - IC - Gust of Wind'),
(@Wind,0,2,3,2,0,100,1,10,20,20000,20000,11,@DropHorn,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Between 10 and 20% HP - Drop Horn'),
(@Wind,0,3,4,61,0,100,0,0,0,0,0,18,139270,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Linked with previous event - Set unit flags for No move, Silence and Pacified'),
(@Wind,0,4,0,61,0,100,0,0,0,0,0,1,0,1200,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Linked with previous event - Say text 0'),
(@Wind,0,5,6,52,0,100,0,0,@Wind,0,0,45,0,1,0,0,0,0,19,@Stormhoof,30,0,0,0,0,0,'North Wind - On text 0 over - Set data 0 1 on Stormhoof'),
(@Wind,0,6,0,61,0,100,0,0,0,0,0,1,1,4000,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Linked with previous event - Say text 1'),
(@Wind,0,7,0,52,0,100,0,1,@Wind,0,0,45,0,2,0,0,0,0,19,@Stormhoof,30,0,0,0,0,0,'North Wind - On text over 1 - Data set 0 2 on Stormhoof'),
(@Wind,0,8,9,38,0,100,1,0,2,0,0,1,2,1000,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - On data set 0 2 - Say text 2'),
(@Wind,0,9,0,61,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - Linked with previous event - Die'),
(@Wind,0,10,0,6,0,100,0,0,0,0,0,19,139270,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - On death - Remove unit_flags'),
(@Wind,0,11,0,4,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Wind - On Agro - Disable Auto Attack');

-- Texts
DELETE FROM `creature_text` WHERE `entry` IN (@Wind,@Stormhoof);

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(@Stormhoof, 0, 0, 'The horn! Use the horn on it while it''s weak!', 14, 0, 100, 1, 1000, 0, 'Stormhoof', 31183),
(@Wind, 2, 0, 'That horn is... MINE!', 14, 0, 100, 1, 2000, 0, 'North Wind', 31195),
(@Wind, 1, 0, 'I will never allow you to use the Horn of Elemental Fury against us! Die, weakling!', 14, 0, 100, 1, 3000, 0, 'North Wind', 31181),
(@Wind, 0, 0, 'Fool! You will never defeat me!', 14, 0, 100, 1, 1200, 0, 'North Wind', 31180);

-- Add SAI for Horn of Elemental Fury
SET @GO := 194123;
UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI' WHERE `entry`=@GO;
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=@GO;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GO,1,0,0,70,0,100,0,2,0,0,0,45,0,2,0,0,0,0,19,@Wind,30,0,0,0,0,0,'Horn of Elemental Fury - On state changed - Data set 0 2 on The Winf of North');

-- Add Npc_spell_click data
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=@Stormhoof;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@Stormhoof;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(@Stormhoof,@Ride,1,0);
