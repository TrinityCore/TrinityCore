SET @GUID:=14830; -- 6 free GO guid required (spell focus)
SET @SUMMON := 49991;
SET @GOLEM  := 24825;
SET @BENCH  := 186958;
SET @Relic := 24824;
SET @Triggger :=24845;
SET @IronDwarf :=24846;
SET @LOKEN := 24847;
SET @Ouvrier:= 23672;
SET @Maitre:=23675;
SET @Garde:=23673;
SET @IRONGolem:=24271;
SET @Earth:=24340; 
SET @A1A2:=24826;
SET @B1B2:=24827;
SET @C1C2:=24828;
SET @D1:=24831;
SET @D2:=24829;
SET @D3:=24832;

DELETE FROM `spell_target_position` WHERE `id` in (49992); 
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(49992, 571, 478.951782, -5941.529297, 308.749969, 0.419872);

UPDATE `creature_template` SET `spell1`=44608, `spell2`=44610, `spell3`=44609,`AIName`='SmartAI', `InhabitType`=5 WHERE `entry`=@GOLEM;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@LOKEN, @IronDwarf, @Triggger, @Relic, @Ouvrier, @Maitre, @Garde, @IRONGolem, @Earth, @A1A2, @B1B2, @C1C2, @D1, @D2, @D3);
UPDATE `creature_template` SET `faction`= 1954 WHERE `entry`=@LOKEN;
UPDATE `creature_template` SET `flags_extra`= 0 WHERE `entry`=@Triggger;

DELETE FROM `creature` WHERE `id` IN (24846, 24847);
DELETE FROM `creature_addon` WHERE `guid` =97731;
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `id`= @Triggger;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GOLEM AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Relic AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@BENCH AND `source_type`=1 AND `id` IN (6,7);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Triggger AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Triggger*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@IronDwarf AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@IronDwarf*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@LOKEN AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@LOKEN*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Garde AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Garde*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Garde*100+1 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Ouvrier AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Ouvrier*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Ouvrier*100+1 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Earth AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Maitre AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Maitre*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Maitre*100+1 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@IRONGolem AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@IRONGolem*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@IRONGolem*100+1 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@A1A2*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@B1B2*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@C1C2*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@D1*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@D2*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@D3*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@BENCH,1,6,7,62,0,100,0,9024,3,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Work Bench - Gossip select - Close gossip'),
(@BENCH,1,7,0,61,0,100,0,0,0,0,0,85,@SUMMON,2,0,0,0,0,7,0,0,0,0,0,0,0,'Work Bench - Gossip select - Summon Iron Rune Construct'),
(@GOLEM,0,0,0,54,0,100,0,0,0,0,0,75,44643,0,0,0,0,0,23,0,0,0,0,0,0,0,'Iron Rune Construct - Just Summoned - Add aura to owner'),
(@GOLEM,0,1,0,28,0,100,0,0,0,0,0,28,44643,0,0,0,0,0,23,0,0,0,0,0,0,0,'Iron Rune Construct - Passenger removed - remove aura from owner'),
(@Relic,0,0,0,8,0,100,0,44610,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Relict - SpellHit - Despawn'),
(@Triggger,0,0,0,10,0,100,0,1,20,180000,180000,80,@Triggger*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Triggger - LOS - Action list'),
(@Triggger*100,9,0,0,0,0,100,0,0,0,0,0,12,@IronDwarf,5,0,0,0,0,8,0,0,0,306.098907, -5706.150391, 102.435051, 4.96977,'Triggger - Action list - Summon'),    
(@Triggger*100,9,1,0,0,0,100,0,0,0,0,0,12,@IronDwarf,5,0,0,0,0,8,0,0,0,311.025482, -5702.801270, 101.934959, 5.187225,'Triggger - Action list - Summon'),
(@Triggger*100,9,2,0,0,0,100,0,0,0,0,0,12,@IronDwarf,5,0,0,0,0,8,0,0,0,309.754456, -5703.156250, 102.070854, 5.187225,'Triggger - Action list - Summon'),
(@Triggger*100,9,3,0,0,0,100,0,0,0,0,0,12,@IronDwarf,5,0,0,0,0,8,0,0,0,308.222504, -5703.797363, 102.231758, 5.187225,'Triggger - Action list - Summon'),
(@Triggger*100,9,4,0,0,0,100,0,0,0,0,0,12,@IronDwarf,5,0,0,0,0,8,0,0,0,307.043610, -5704.315430, 102.356087, 5.187225,'Triggger - Action list - Summon'),  
(@Triggger*100,9,5,0,0,0,100,0,0,0,0,0,12,@IronDwarf,5,0,0,0,0,8,0,0,0,304.169464, -5706.838379, 102.696602, 5.187225,'Triggger - Action list - Summon'),
(@Triggger*100,9,6,0,0,0,100,0,0,0,0,0,12,@IronDwarf,5,0,0,0,0,8,0,0,0,303.129547, -5707.277344, 102.978165, 5.187225,'Triggger - Action list - Summon'),  
(@Triggger*100,9,7,0,0,0,100,0,0,0,0,0,12,@IronDwarf,5,0,0,0,0,8,0,0,0,297.246,-5726.82,96.2681,0.347607,'Triggger - Action list - Summon'),
(@Triggger*100,9,8,0,0,0,100,0,0,0,0,0,12,@IronDwarf,5,0,0,0,0,8,0,0,0,292.82,-5726.04,96.5843,0.347607,'Triggger - Action list - Summon'),
(@Triggger*100,9,9,0,0,0,100,0,0,0,0,0,12,@IronDwarf,5,0,0,0,0,8,0,0,0,292.562,-5728.57,96.5857,0.347607,'Triggger - Action list - Summon'),
(@Triggger*100,9,10,0,0,0,100,0,0,0,0,0,12,@IronDwarf,5,0,0,0,0,8,0,0,0,292.15,-5727.42,96.5874,0.347607,'Triggger - Action list - Summon'),
(@Triggger*100,9,11,0,0,0,100,0,0,0,0,0,12,@IronDwarf,5,0,0,0,0,8,0,0,0,294.578,-5730.09,96.2958,0.347607,'Triggger - Action list - Summon'),
(@Triggger*100,9,12,0,0,0,100,0,0,0,0,0,12,@IronDwarf,5,0,0,0,0,8,0,0,0,296.196,-5730.17,96.0082,0.347607,'Triggger - Action list - Summon'),
(@Triggger*100,9,13,0,0,0,100,0,0,0,0,0,12,@IronDwarf,5,0,0,0,0,8,0,0,0,297.603,-5730.79,95.6955,0.347607,'Triggger - Action list - Summon'),
(@Triggger*100,9,14,0,0,0,100,0,0,0,0,0,12,@IronDwarf,5,0,0,0,0,8,0,0,0,299.397,-5729.56,95.7274,0.347607,'Triggger - Action list - Summon'),
(@Triggger*100,9,15,0,0,0,100,0,0,0,0,0,12,@LOKEN,5,0,0,0,0,8,0,0,0,315.101,-5723.06,96.2541,3.05433,'Triggger - Action list - Summon'),
(@Triggger*100,9,16,0,0,0,100,0,70000,70000,0,0,41,0,0,0,0,0,0,11,@IronDwarf,40,0,0,0,0,0,'Triggger - Action List - Despawn'),
(@Triggger,0,1,0,25,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Triggger - On reset - set Invisible'),
(@IronDwarf,0,0,0,54,0,100,0,0,0,0,0,80,@IronDwarf*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'IronDwarf - Just Summoned - Action List'),
(@IronDwarf*100,9,0,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'IronDwarf - Action List - Set run off'),
(@IronDwarf*100,9,1,0,0,0,100,0,0,0,0,0,46,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'IronDwarf - Action List - Move forward'),
(@IronDwarf*100,9,2,0,0,0,100,0,4000,4000,0,0,11,68442,0,0,0,0,0,1,0,0,0,0,0,0,0,'IronDwarf - Action List - Cast Kneels'),
(@LOKEN,0,0,0,54,0,100,0,0,0,0,0,80,@LOKEN*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'LOKEN - Just Summoned - Action List'),
(@LOKEN*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'LOKEN - Action List - Talk'),
(@LOKEN*100,9,1,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'LOKEN - Action List - Talk'),
(@LOKEN*100,9,2,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'LOKEN - Action List - Talk'),
(@LOKEN*100,9,3,0,0,0,100,0,8000,8000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'LOKEN - Action List - Talk'),
(@LOKEN*100,9,4,0,0,0,100,0,9000,9000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'LOKEN - Action List - Talk'),
(@LOKEN*100,9,5,0,0,0,100,0,9000,9000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'LOKEN - Action List - Talk'),
(@LOKEN*100,9,6,0,0,0,100,0,7000,7000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'LOKEN - Action List - Talk'),
(@LOKEN*100,9,7,0,0,0,100,0,0,0,0,0,11,44682,0,0,0,0,0,21,30,0,0,0,0,0,0,'LOKEN - Action List - Cast Credit'),
(@LOKEN*100,9,8,0,0,0,100,0,2000,2000,0,0,41,0,0,0,0,0,0,11,@IronDwarf,40,0,0,0,0,0,'LOKEN - Action List - Despawn Dwarfs'),
(@LOKEN*100,9,9,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'LOKEN - Action List - Despawn'),
(@IronDwarf,0,1,0,4,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'IronDwarf - On aggro - despawn'),
(@LOKEN,0,1,0,4,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'LOKEN - On aggro - despawn'),
(@Garde,0,0,0,10,0,20,0,1,9,60000,60000,80,@Garde*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Garde - LOS - Action list'),
(@Garde*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Garde - Action list - TALK'),
(@Garde*100,9,1,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Garde - Action list - Set Event phase1'),
(@Garde*100,9,2,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Garde - Action list - Root'),
(@Garde*100,9,3,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,@GOLEM,20,0,0,0,0,0,'Garde - Action list - Set Orientation'),
(@Garde*100,9,4,0,0,0,100,0,10000,10000,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Garde - Action list - remove root'),
(@Garde*100,9,5,0,0,1,100,0,0,0,0,0,28,44643,0,0,0,0,0,21,50,0,0,0,0,0,0,'Garde - Action list - remove Aura'),
(@Garde*100,9,6,0,0,1,100,0,0,0,0,0,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,'Garde - Action list - Talk'),
(@Garde,0,1,0,8,1,100,0,44609,0,0,0,80,@Garde*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Garde - spell hit - action list'),
(@Garde*100+1,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Garde - Action list - Set Event phase 0'),
(@Garde*100+1,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,@GOLEM,20,0,0,0,0,0,'Garde - Action list - TALK'),
(@Garde*100+1,9,2,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Garde - Action list - TALK'),
(@Garde,0,2,0,0,0,100,0,5000,5000,30000,30000,11,42580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Garde - IC - Cast'),
(@Garde,0,3,0,4,0,100,0,0,0,0,0,11,49758,0,0,0,0,0,2,0,0,0,0,0,0,0,'Garde - On aggro - Cast'),
(@Ouvrier,0,0,0,10,0,20,0,1,9,60000,60000,80,@Ouvrier*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ouvrier - LOS - Action list'),
(@Ouvrier*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ouvrier - Action list - TALK'),
(@Ouvrier*100,9,1,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ouvrier - Action list - Set Event phase1'),
(@Ouvrier*100,9,2,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ouvrier - Action list - Root'),
(@Ouvrier*100,9,3,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,@GOLEM,20,0,0,0,0,0,'Ouvrier - Action list - Set Orientation'),
(@Ouvrier*100,9,4,0,0,0,100,0,10000,10000,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ouvrier - Action list - remove root'),
(@Ouvrier*100,9,5,0,0,1,100,0,0,0,0,0,28,44643,0,0,0,0,0,21,50,0,0,0,0,0,0,'Ouvrier - Action list - remove Aura'),
(@Ouvrier*100,9,6,0,0,1,100,0,0,0,0,0,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,'Ouvrier - Action list - Talk'),
(@Ouvrier,0,1,0,8,1,100,0,44609,0,0,0,80,@Ouvrier*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ouvrier - spell hit - action list'),
(@Ouvrier*100+1,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ouvrier - Action list - Set Event phase 0'),
(@Ouvrier*100+1,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,@GOLEM,20,0,0,0,0,0,'Ouvrier - Action list - TALK'),
(@Ouvrier*100+1,9,2,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ouvrier - Action list - TALK'),
(@Ouvrier,0,2,0,0,0,100,0,5000,5000,5000,8000,11,49749,0,0,0,0,0,2,0,0,0,0,0,0,0,'Ouvrier - IC - Cast'),
(@Maitre,0,0,0,10,0,20,0,1,9,60000,60000,80,@Maitre*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Maitre - LOS - Action list'),
(@Maitre*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Maitre - Action list - TALK'),
(@Maitre*100,9,1,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Maitre - Action list - Set Event phase1'),
(@Maitre*100,9,2,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Maitre - Action list - Root'),
(@Maitre*100,9,3,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,@GOLEM,20,0,0,0,0,0,'Maitre - Action list - Set Orientation'),
(@Maitre*100,9,4,0,0,0,100,0,10000,10000,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Maitre - Action list - remove root'),
(@Maitre*100,9,5,0,0,1,100,0,0,0,0,0,28,44643,0,0,0,0,0,21,50,0,0,0,0,0,0,'Maitre - Action list - remove Aura'),
(@Maitre*100,9,6,0,0,1,100,0,0,0,0,0,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,'Maitre - Action list - Talk'),
(@Maitre,0,1,0,8,1,100,0,44609,0,0,0,80,@Maitre*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Maitre - spell hit - action list'),
(@Maitre*100+1,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Maitre - Action list - Set Event phase 0'),
(@Maitre*100+1,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,@GOLEM,20,0,0,0,0,0,'Maitre - Action list - TALK'),
(@Maitre*100+1,9,2,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Maitre - Action list - TALK'),
(@Maitre,0,2,0,0,0,100,0,5000,5000,7000,10000,11,49753,0,0,0,0,0,2,0,0,0,0,0,0,0,'Garde - IC - Cast'),
(@IRONGolem,0,0,0,10,0,20,0,1,9,60000,60000,80,@IRONGolem*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'IRONGolem - LOS - Action list'),
(@IRONGolem*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'IRONGolem - Action list - TALK'),
(@IRONGolem*100,9,1,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'IRONGolem - Action list - Set Event phase1'),
(@IRONGolem*100,9,2,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'IRONGolem - Action list - Root'),
(@IRONGolem*100,9,3,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,@GOLEM,20,0,0,0,0,0,'IRONGolem - Action list - Set Orientation'),
(@IRONGolem*100,9,4,0,0,0,100,0,10000,10000,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'IRONGolem - Action list - remove root'),
(@IRONGolem*100,9,5,0,0,1,100,0,0,0,0,0,28,44643,0,0,0,0,0,21,50,0,0,0,0,0,0,'IRONGolem - Action list - remove Aura'),
(@IRONGolem*100,9,6,0,0,1,100,0,0,0,0,0,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,'IRONGolem - Action list - talk'),
(@IRONGolem,0,1,0,8,1,100,0,44609,0,0,0,80,@IRONGolem*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,'IRONGolem - spell hit - action list'),
(@IRONGolem*100+1,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'IRONGolem - Action list - Set Event phase 0'),
(@IRONGolem*100+1,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,@GOLEM,20,0,0,0,0,0,'IRONGolem - Action list - TALK'),
(@IRONGolem*100+1,9,2,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'IRONGolem - Action list - TALK'),
(@IRONGolem,0,2,0,0,0,100,0,5000,5000,7000,10000,11,49729,0,0,0,0,0,2,0,0,0,0,0,0,0,'IRONGolem - IC - Cast'),
(@IRONGolem,0,3,0,1,0,100,0,50000,60000,60000,90000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'IRONGolem - ooc - talk'),
(@Earth,0,0,0,0,0,100,0,2000,5000,6000,8000,11,49742,0,0,0,0,0,2,0,0,0,0,0,0,0,'IRONGolem - IC - Cast'),
(@GOLEM,0,2,0,8,0,100,0,44626,0,5000,5000,80,@A1A2*100,0,0,0,0,0,19,@A1A2,1,0,0,0,0,0,'Iron Rune Construct - On spellhit  - Action List'),
(@A1A2*100,9,0,0,0,0,100,0,0,0,0,0,9,0,0,0,0,0,0,14,57776,186953,0,0,0,0,0,'A1A2 - Action list - Activate Gobject'),
(@A1A2*100,9,1,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@GOLEM,10,0,0,0,0,0,'A1A2 - Action list - SetData'),
(@GOLEM,0,3,0,8,0,100,0,44626,0,5000,5000,80,@B1B2*100,0,0,0,0,0,19,@B1B2,1,0,0,0,0,0,'Iron Rune Construct - On spellhit  - Action List'),
(@B1B2*100,9,0,0,0,0,100,0,0,0,0,0,9,0,0,0,0,0,0,14,57915,186960,0,0,0,0,0,'B1B2 - Action list - Activate Gobject'),
(@B1B2*100,9,1,0,0,0,100,0,0,0,0,0,45,0,2,0,0,0,0,19,@GOLEM,10,0,0,0,0,0,'B1B2 - Action list - SetData'),
(@GOLEM,0,4,0,8,0,100,0,44626,0,5000,5000,80,@C1C2*100,0,0,0,0,0,19,@C1C2,1,0,0,0,0,0,'Iron Rune Construct - On spellhit  - Action List'),
(@C1C2*100,9,0,0,0,0,100,0,0,0,0,0,9,0,0,0,0,0,0,14,57963,186961,0,0,0,0,0,'C1C2 - Action list - Activate Gobject'),
(@C1C2*100,9,1,0,0,0,100,0,0,0,0,0,45,0,3,0,0,0,0,19,@GOLEM,10,0,0,0,0,0,'C1C2 - Action list - SetData'),
(@GOLEM,0,5,0,8,0,100,0,44626,0,5000,5000,80,@D1*100,0,0,0,0,0,19,@D1,1,0,0,0,0,0,'Iron Rune Construct - On spellhit  - Action List'),
(@D1*100,9,0,0,0,0,100,0,0,0,0,0,9,0,0,0,0,0,0,14,57972,186962,0,0,0,0,0,'D1 - Action list - Activate Gobject'),
(@D1*100,9,1,0,0,0,100,0,0,0,0,0,45,0,4,0,0,0,0,19,@GOLEM,10,0,0,0,0,0,'D1 - Action list - SetData'),
(@GOLEM,0,6,0,8,0,100,0,44626,0,5000,5000,80,@D2*100,0,0,0,0,0,19,@D2,1,0,0,0,0,0,'Iron Rune Construct - On spellhit  - Action List'),
(@D2*100,9,0,0,0,0,100,0,0,0,0,0,9,0,0,0,0,0,0,14,57988,186963,0,0,0,0,0,'D2 - Action list - Activate Gobject'),
(@D2*100,9,1,0,0,0,100,0,0,0,0,0,45,0,5,0,0,0,0,19,@GOLEM,10,0,0,0,0,0,'D2 - Action list - SetData'),
(@GOLEM,0,7,0,8,0,100,0,44626,0,5000,5000,80,@D3*100,0,0,0,0,0,19,@D3,1,0,0,0,0,0,'Iron Rune Construct - On spellhit  - Action List'),
(@D3*100,9,0,0,0,0,100,0,0,0,0,0,9,0,0,0,0,0,0,14,66097,186964,0,0,0,0,0,'D3 - Action list - Activate Gobject'),
(@D3*100,9,1,0,0,0,100,0,0,0,0,0,45,0,6,0,0,0,0,19,@GOLEM,10,0,0,0,0,0,'D3 - Action list - SetData'),
(@GOLEM,0,8,0,38,0,100,0,0,1,0,0,53,1,@A1A2,0,0,0,0,1,0,0,0,0,0,0,0,'Iron Rune Construct - On data set - Start waypoint'),
(@GOLEM,0,9,0,38,0,100,0,0,2,0,0,53,1,@B1B2,0,0,0,0,1,0,0,0,0,0,0,0,'Iron Rune Construct - On data set - Start waypoint'),
(@GOLEM,0,10,0,38,0,100,0,0,3,0,0,53,1,@C1C2,0,0,0,0,1,0,0,0,0,0,0,0,'Iron Rune Construct - On data set - Start waypoint'),
(@GOLEM,0,11,0,38,0,100,0,0,4,0,0,53,1,@D1,0,0,0,0,1,0,0,0,0,0,0,0,'Iron Rune Construct - On data set - Start waypoint'),
(@GOLEM,0,12,0,38,0,100,0,0,5,0,0,53,1,@D2,0,0,0,0,1,0,0,0,0,0,0,0,'Iron Rune Construct - On data set - Start waypoint'),
(@GOLEM,0,13,0,38,0,100,0,0,6,0,0,53,1,@D3,0,0,0,0,1,0,0,0,0,0,0,0,'Iron Rune Construct - On data set - Start waypoint'),
(@GOLEM,0,14,0,58,0,100,0,0,0,0,0,28,44626,0,0,0,0,0,1,0,0,0,0,0,0,0,'Iron Rune Construct - On waypoint end - Remove aura');

DELETE FROM `waypoints` WHERE `entry` IN (@C1C2, @B1B2, @A1A2, @D1, @D2, @D3);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@C1C2,1, 250.667023, -5770.241699, 252.249847,'Iron Rune Construct'),
(@C1C2,2, 158.802368, -5823.064941, 7.080285,'Iron Rune Construct'),
(@B1B2,1, 268.167053, -5814.819824, 282.507080,'Iron Rune Construct'),
(@B1B2,2, 255.435913, -5891.186035, 83.068146,'Iron Rune Construct'),
(@A1A2,1, 221.699432, -5736.851074, 289.626099,'Iron Rune Construct'),
(@A1A2,2, 157.139877, -5712.004883, 189.551346,'Iron Rune Construct'),
(@D1,1, 212.711884, -5808.783691, 297.261902,'Iron Rune Construct'),
(@D1,2, 276.179016, -5755.332031, 268.456543,'Iron Rune Construct'),
(@D2,1, 228.848938, -5740.563477, 283.448700,'Iron Rune Construct'),
(@D2,2, 278.266785, -5758.165039, 268.454834,'Iron Rune Construct'),
(@D3,1, 266.918884, -5837.802246, 304.154144,'Iron Rune Construct'),
(@D3,2, 280.913208, -5761.616699, 268.456696,'Iron Rune Construct');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=@Triggger;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@Triggger,0,31,3,24825,0,0,'','event require npc 24825');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=@IRONGolem;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@IRONGolem,0,31,3,24825,0,0,'','event require npc 24825');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=@Garde;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@Garde,0,31,3,24825,0,0,'','event require npc 24825');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=@Maitre;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@Maitre,0,31,3,24825,0,0,'','event require npc 24825');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=@Ouvrier;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@Ouvrier,0,31,3,24825,0,0,'','event require npc 24825');

DELETE FROM `creature_text` WHERE `entry`IN (@LOKEN, @GOLEM, @Garde, @Ouvrier, @Maitre, @IRONGolem); 
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextID`) VALUES
(@LOKEN,0,0,"The sound of thunder roars throughout the cavern.",41,9,100,0,0,0,'LOKEN', 23927),
(@LOKEN,1,0,"Come, minions! Your master calls!",14,9,100,0,0,0,'LOKEN', 23922),
(@LOKEN,2,0,"The work of your brothers in the Storm Peaks has reached a frenzied pace. Soon, Father will be freed.",14,9,100,0,0,0,'LOKEN', 23923),
(@LOKEN,3,0,"Your brothers to the north have subjugated the stone behemoths and set them on the path to Ulduar. Soon, the remaining defenses of the Pantheon will be neutralized.",14,9,100,0,0,0,'LOKEN', 23924),
(@LOKEN,4,0,"The three fissures opened by the mortals of this region must be silenced. The earth hears and sees what we do and will continue to interfere with our efforts if the way is not closed.",14,9,100,0,0,0,'LOKEN', 23925),
(@LOKEN,5,0,"Bury this place! Your master demands it!",14,9,100,0,0,0,'LOKEN', 23926),
(@LOKEN,6,0,"The sound of thunder dissipates.",41,9,100,0,0,0,'LOKEN', 23928),
(@GOLEM,0,0,"Alert! Alert! Construct senses that enemies have breeched our defenses. Increase pace.",12,9,100,0,0,0,'GOLEM', 23895),
(@GOLEM,0,1,"Construct class carrier reporting for duty. Primary function: Overseeing.",12,9,100,0,0,0,'GOLEM', 23896),
(@GOLEM,0,2,"There is nothing to see here. Proceed with your mandated duties.",12,9,100,0,0,0,'GOLEM', 23897),
(@GOLEM,0,3,"To interfere with construct's function results in termination. Move along.",12,9,100,0,0,0,'GOLEM', 23899),
(@GOLEM,0,4,"Construct must not be questioned by iron dwarf servant. Commence deconstruction.",12,9,100,0,0,0,'GOLEM', 23900),
(@GOLEM,0,5,"Construct is not authorized to communicate with lesser beings. Being must double their efforts.",12,9,100,0,0,0,'GOLEM', 23901),
(@GOLEM,0,6,"Did you lose your wallet? Construct has found wallet with overabundance of currency.",12,9,100,0,0,0,'GOLEM', 23902),
(@Garde,0,0,"Halt! Identify yourself immediately!",12,9,100,0,0,0,'Garde', 23903),
(@Garde,0,1,"This section is off-limits!",12,9,100,0,0,0,'Garde', 23904),
(@Garde,0,2,"I've never seen one of you around here.",12,9,100,0,0,0,'Garde', 23905),
(@Garde,0,3,"Hold it! Stop!",12,9,100,0,0,0,'Garde', 23906),
(@Garde,0,4,"Stop!! Stop!!! Scrap metal moves itself now?",12,9,100,0,0,0,'Garde', 23907),
(@Garde,1,2,"Right... my bad. Now where was I?",12,9,100,0,0,0,'Garde', 23910),
(@Garde,1,3,"All hail the great creator!",12,9,100,0,0,0,'Garde', 23911),
(@Garde,1,4,"You're right, of course. Carry on.",12,9,100,0,0,0,'Garde', 23912),
(@Garde,1,5,"Forgive my insolence!",12,9,100,0,0,0,'Garde', 23913),
(@Garde,1,6,"We will double our efforts!",12,9,100,0,0,0,'Garde', 23915),
(@Garde,2,0,"Destroy earthen infestation.",12,9,100,0,0,0,'Garde', 23921),
(@Garde,2,1,"Wrong answer!",12,9,100,0,0,0,'Garde', 23908),
(@Ouvrier,0,0,"Halt! Identify yourself immediately!",12,9,100,0,0,0,'Garde', 23903),
(@Ouvrier,0,1,"This section is off-limits!",12,9,100,0,0,0,'Garde', 23904),
(@Ouvrier,0,2,"I've never seen one of you around here.",12,9,100,0,0,0,'Garde', 23905),
(@Ouvrier,0,3,"Hold it! Stop!",12,9,100,0,0,0,'Garde', 23906),
(@Ouvrier,0,4,"Stop!! Stop!!! Scrap metal moves itself now?",12,9,100,0,0,0,'Garde', 23907),
(@Ouvrier,1,2,"Right... my bad. Now where was I?",12,9,100,0,0,0,'Garde', 23910),
(@Ouvrier,1,3,"All hail the great creator!",12,9,100,0,0,0,'Garde', 23911),
(@Ouvrier,1,4,"You're right, of course. Carry on.",12,9,100,0,0,0,'Garde', 23912),
(@Ouvrier,1,5,"Forgive my insolence!",12,9,100,0,0,0,'Garde', 23913),
(@Ouvrier,1,6,"We will double our efforts!",12,9,100,0,0,0,'Garde', 23915),
(@Ouvrier,2,0,"Destroy earthen infestation.",12,9,100,0,0,0,'Garde', 23921),
(@Ouvrier,2,1,"Wrong answer!",12,9,100,0,0,0,'Garde', 23908),
(@Maitre,0,0,"Halt! Identify yourself immediately!",12,9,100,0,0,0,'Garde', 23903),
(@Maitre,0,1,"This section is off-limits!",12,9,100,0,0,0,'Garde', 23904),
(@Maitre,0,2,"I've never seen one of you around here.",12,9,100,0,0,0,'Garde', 23905),
(@Maitre,0,3,"Hold it! Stop!",12,9,100,0,0,0,'Garde', 23906),
(@Maitre,0,4,"Stop!! Stop!!! Scrap metal moves itself now?",12,9,100,0,0,0,'Garde', 23907),
(@Maitre,1,2,"Right... my bad. Now where was I?",12,9,100,0,0,0,'Garde', 23910),
(@Maitre,1,3,"All hail the great creator!",12,9,100,0,0,0,'Garde', 23911),
(@Maitre,1,4,"You're right, of course. Carry on.",12,9,100,0,0,0,'Garde', 23912),
(@Maitre,1,5,"Forgive my insolence!",12,9,100,0,0,0,'Garde', 23913),
(@Maitre,1,6,"We will double our efforts!",12,9,100,0,0,0,'Garde', 23915),
(@Maitre,2,0,"Destroy earthen infestation.",12,9,100,0,0,0,'Garde', 23921),
(@Maitre,2,1,"Wrong answer!",12,9,100,0,0,0,'Garde', 23908),
(@IRONGolem,0,0,"Halt! Identify yourself immediately!",12,9,100,0,0,0,'Garde', 23903),
(@IRONGolem,0,1,"This section is off-limits!",12,9,100,0,0,0,'Garde', 23904),
(@IRONGolem,0,2,"I've never seen one of you around here.",12,9,100,0,0,0,'Garde', 23905),
(@IRONGolem,0,3,"Hold it! Stop!",12,9,100,0,0,0,'Garde', 23906),
(@IRONGolem,0,4,"Stop!! Stop!!! Scrap metal moves itself now?",12,9,100,0,0,0,'Garde', 23907),
(@IRONGolem,1,2,"Right... my bad. Now where was I?",12,9,100,0,0,0,'Garde', 23910),
(@IRONGolem,1,3,"All hail the great creator!",12,9,100,0,0,0,'Garde', 23911),
(@IRONGolem,1,4,"You're right, of course. Carry on.",12,9,100,0,0,0,'Garde', 23912),
(@IRONGolem,1,5,"Forgive my insolence!",12,9,100,0,0,0,'Garde', 23913),
(@IRONGolem,1,6,"We will double our efforts!",12,9,100,0,0,0,'Garde', 23915),
(@IRONGolem,2,0,"Destroy earthen infestation.",12,9,100,0,0,0,'Garde', 23921),
(@IRONGolem,2,1,"Wrong answer!",12,9,100,0,0,0,'Garde', 23908),
(@IRONGolem,3,0,"Continue deconstruction.",12,9,100,0,0,0,'Garde', 23919),
(@IRONGolem,3,1,"Do not loiter.",12,9,100,0,0,0,'Garde', 23918),
(@IRONGolem,3,2,"Work must continue. Double your efforts.",12,9,100,0,0,0,'Garde', 23916),
(@IRONGolem,3,3,"Brontes sees all.",12,9,100,0,0,0,'Garde', 23917),
(@IRONGolem,3,4,"Reinforcements en route. Function must be unabated.",12,9,100,0,0,0,'Garde', 23920),
(@IRONGolem,3,5,"Do you bring word from the creator?",12,9,100,0,0,0,'Garde', 23914),
(@IRONGolem,3,6,"All hail the great creator.",12,9,100,0,0,0,'Garde', 23898);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=44609;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 44609, 0, 31, 3, 24271, 0, 0, '', 'Bluff target'),
(13, 1, 44609, 1, 31, 3, 23673, 0, 0, '', 'Bluff target'),
(13, 1, 44609, 2, 31, 3, 23672, 0, 0, '', 'Bluff target'),
(13, 1, 44609, 3, 31, 3, 23675, 0, 0, '', 'Bluff target');

SET @ID := 9024;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@ID AND `SourceEntry`=3;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@ID,3,0,9,11495,0,0,0,'','Show gossip option if player has quest The Delicate Sound of Thunder'),
(15,@ID,3,1,9,11494,0,0,0,'','Show gossip option if player has quest Lightning Infused Relics');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=44610;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 44610, 0, 31, 3, 24824, 0, 0, '', 'Collect Data target');

DELETE FROM `gameobject` WHERE `guid` in (@GUID+0, @GUID+1, @GUID+2, @GUID+3, @GUID+4, @GUID+5);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GUID+0,186959,571,1,1,276.169006, -5755.250000, 268.455994,0,0,0,0,1,120,255,1),
(@GUID+1,186959,571,1,1,278.528992, -5758.350098, 268.455994,0,0,0,0,1,120,255,1),
(@GUID+2,186959,571,1,1,280.851990, -5761.399902, 268.455994,0,0,0,0,1,120,255,1),
(@GUID+3,186959,571,1,1,158.707001, -5823.319824, 7.006820,0,0,0,0,1,120,255,1),
(@GUID+4,186959,571,1,1,157.201996, -5712.160156, 189.315002,0,0,0,0,1,120,255,1),
(@GUID+5,186959,571,1,1,255.533997, -5891.359863, 82.992897,0,0,0,0,1,120,255,1);

UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `id` IN (24828, 24829, 24831, 24832, 24826, 24827);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 44608;
INSERT INTO `spell_linked_spell` VALUES (44608, 44626, 0, 'Rocket Jump');
