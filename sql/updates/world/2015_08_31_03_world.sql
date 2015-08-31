-- Fate of the Titans (12986)
-- http://www.youtube.com/watch?v=H6HED6PaxIs

SET @NPC_DISK              := 30313; -- Mobile Databank
SET @NPC_BUNNY_INVENTION   := 30315; -- Temple of Invention Bunny
SET @NPC_BUNNY_LIFE        := 30316; -- Temple of Life Bunny
SET @NPC_BUNNY_WINTER      := 30317; -- Temple of Winter Bunny
SET @NPC_BUNNY_ORDER       := 30318; -- Temple of Order Bunny
SET @NPC_BUNNY_DATASCAN    := 30889; -- Data Scan Target Bunny
SET @SPELL_DATASCAN        := 56523; -- Data Scan
SET @SPELL_INVENTION_KC    := 56532; -- Temple of Invention Kill Credit
SET @SPELL_LIFE_KC         := 56534; -- Temple of Life Kill Credit
SET @SPELL_WINTER_KC       := 56533; -- Temple of Winter Kill Credit
SET @SPELL_ORDER_KC        := 56535; -- Temple of Order Kill Credit
SET @GUID                  := 127294;

-- Sniffed
DELETE FROM `creature` WHERE `id` IN (@NPC_BUNNY_INVENTION,@NPC_BUNNY_LIFE,@NPC_BUNNY_WINTER,@NPC_BUNNY_ORDER,@NPC_BUNNY_DATASCAN);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
-- Databank should go from one to another and say text
(@GUID+0,@NPC_BUNNY_INVENTION,571,1,1,0,0,7865.214,-1397.313,1534.143,3.752458,300,0,0,1,0,0,0,0,0),
(@GUID+1,@NPC_BUNNY_LIFE,571,1,1,0,0,7994.017,-2734.839,1133.662,0.3316126,300,0,0,1,0,0,0,0,0),
(@GUID+2,@NPC_BUNNY_WINTER,571,1,1,0,0,7498.68,-1899.41,1473.61,0.132902,300,0,0,1,0,0,0,0,0),
(@GUID+3,@NPC_BUNNY_ORDER,571,1,1,0,0,8194.199,-1963.597,1738.56,1.954769,300,0,0,1,0,0,0,0,0),
-- At the Temple of Order:
(@GUID+4,@NPC_BUNNY_DATASCAN,571,1,1,0,0,8130.811,-1995.321,1781.117,0.05235988,300,0,0,1,0,0,0,0,0),
(@GUID+5,@NPC_BUNNY_DATASCAN,571,1,1,0,0,8213.646,-1901.764,1744.02,0.5759587,300,0,0,1,0,0,0,0,0),
(@GUID+6,@NPC_BUNNY_DATASCAN,571,1,1,0,0,8255.328,-1982.391,1742.117,4.031711,300,0,0,1,0,0,0,0,0),
-- At the Temple of Invention:
(@GUID+7,@NPC_BUNNY_DATASCAN,571,1,1,0,0,7868.994,-1375.799,1541.754,4.712389,300,0,0,1,0,0,0,0,0),
(@GUID+8,@NPC_BUNNY_DATASCAN,571,1,1,0,0,7924.429,-1385.165,1534.788,6.038839,300,0,0,1,0,0,0,0,0),
(@GUID+9,@NPC_BUNNY_DATASCAN,571,1,1,0,0,7903.273, -1424.807, 1539.821,2.048841,300,0,0,1,0,0,0,0,0),
(@GUID+10,@NPC_BUNNY_DATASCAN,571,1,1,0,0,7863.330, -1434.625, 1537.565,3.072831,300,0,0,1,0,0,0,0,0),
-- At the Temple of Life:
(@GUID+11,@NPC_BUNNY_DATASCAN,571,1,1,0,0,7924.706,-2748.963,1151.056,4.520403,300,0,0,1,0,0,0,0,0),
(@GUID+12,@NPC_BUNNY_DATASCAN,571,1,1,0,0,8010.217,-2750.608,1151.104,0.418879,300,0,0,1,0,0,0,0,0),
(@GUID+13,@NPC_BUNNY_DATASCAN,571,1,1,0,0,8027.505,-2728.616,1139.939,3.944444,300,0,0,1,0,0,0,0,0),
(@GUID+14,@NPC_BUNNY_DATASCAN,571,1,1,0,0,7978.187,-2714.357,1137.354,2.643541,300,0,0,1,0,0,0,0,0),
-- At the Temple of Winter:
(@GUID+15,@NPC_BUNNY_DATASCAN,571,1,1,0,0,7520.712,-1929.840,1482.500,4.520403,300,0,0,1,0,0,0,0,0),
(@GUID+16,@NPC_BUNNY_DATASCAN,571,1,1,0,0,7478.601, -1917.123, 1473.615,0.418879,300,0,0,1,0,0,0,0,0),
(@GUID+17,@NPC_BUNNY_DATASCAN,571,1,1,0,0,7473.774, -1875.455, 1473.614,3.944444,300,0,0,1,0,0,0,0,0);


DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@NPC_DISK,@NPC_BUNNY_INVENTION);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@NPC_DISK*100+0,@NPC_DISK*100+1,@NPC_DISK*100+2,@NPC_DISK*100+3);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_DISK,0,0,0,10,0,100,1,500,1000,500,1000,80,@NPC_DISK*100+0,2,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - OOC near npc -  Run script'),
--
(@NPC_DISK,0,1,0,10,0,100,1,500,1000,500,1000,80,@NPC_DISK*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - OOC near npc -  Run script'),
--
(@NPC_DISK,0,2,0,10,0,100,1,500,1000,500,1000,80,@NPC_DISK*100+2,2,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - OOC near npc -  Run script'),
-- 
(@NPC_DISK,0,3,0,10,0,100,1,500,1000,500,1000,80,@NPC_DISK*100+3,2,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - OOC near npc -  Run script'),
--
(@NPC_DISK*100+0,9,0,0,0,0,100,0,5000,5000,5000,5000,69,1,0,0,0,0,0,10,@GUID+7,@NPC_BUNNY_DATASCAN,0,0,0,0,0,'Mobile Databank - On Script - Move to Pos'),
(@NPC_DISK*100+0,9,1,0,0,0,100,0,3000,3000,3000,3000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - On Script - Say'),
(@NPC_DISK*100+0,9,2,0,0,0,100,0,2000,2000,2000,2000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - On Script - Say'),
(@NPC_DISK*100+0,9,3,0,0,0,100,0,8000,8000,8000,8000,69,1,0,0,0,0,0,10,@GUID+8,@NPC_BUNNY_DATASCAN,0,0,0,0,0,'Mobile Databank - On Script - Move to Pos'),
(@NPC_DISK*100+0,9,4,0,0,0,100,0,7000,7000,7000,7000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - On Script - Say'),
(@NPC_DISK*100+0,9,5,0,0,0,100,0,9000,9000,9000,9000,69,1,0,0,0,0,0,10,@GUID+9,@NPC_BUNNY_DATASCAN,0,0,0,0,0,'Mobile Databank - On Script - Move to Pos'),
(@NPC_DISK*100+0,9,6,0,0,0,100,0,3000,3000,3000,3000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - On Script - Say'),
(@NPC_DISK*100+0,9,7,0,0,0,100,0,9000,9000,9000,9000,69,1,0,0,0,0,0,10,@GUID+10,@NPC_BUNNY_DATASCAN,0,0,0,0,0,'Mobile Databank - On Script - Move to Pos'),
(@NPC_DISK*100+0,9,8,0,0,0,100,0,3000,3000,3000,3000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - On Script - Say'),
(@NPC_DISK*100+0,9,9,0,0,0,100,0,0,0,0,0,11,@SPELL_INVENTION_KC,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - On script - Cast Credit'),
--
(@NPC_DISK*100+1,9,0,0,0,0,100,0,5000,5000,5000,5000,69,1,0,0,0,0,0,10,@GUID+15,@NPC_BUNNY_DATASCAN,0,0,0,0,0,'Mobile Databank - On Script - Move to Pos'),
(@NPC_DISK*100+1,9,1,0,0,0,100,0,3000,3000,3000,3000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - On Script - Say'),
(@NPC_DISK*100+1,9,2,0,0,0,100,0,2000,2000,2000,2000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - On Script - Say'),
(@NPC_DISK*100+1,9,3,0,0,0,100,0,8000,8000,8000,8000,69,1,0,0,0,0,0,10,@GUID+16,@NPC_BUNNY_DATASCAN,0,0,0,0,0,'Mobile Databank - On Script - Move to Pos'),
(@NPC_DISK*100+1,9,4,0,0,0,100,0,7000,7000,7000,7000,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - On Script - Say'),
(@NPC_DISK*100+1,9,5,0,0,0,100,0,9000,9000,9000,9000,69,1,0,0,0,0,0,10,@GUID+17,@NPC_BUNNY_DATASCAN,0,0,0,0,0,'Mobile Databank - On Script - Move to Pos'),
(@NPC_DISK*100+1,9,6,0,0,0,100,0,3000,3000,3000,3000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - On Script - Say'),
(@NPC_DISK*100+1,9,7,0,0,0,100,0,3000,3000,3000,3000,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - On Script - Say'),
(@NPC_DISK*100+1,9,8,0,0,0,100,0,0,0,0,0,11,@SPELL_WINTER_KC,0,0,0,0,0,7,0,0,0,0,0,0,0,'Mobile Databank - On script - Cast Credit'),
--
(@NPC_DISK*100+2,9,0,0,0,0,100,0,5000,5000,5000,5000,69,1,0,0,0,0,0,10,@GUID+11,@NPC_BUNNY_DATASCAN,0,0,0,0,0,'Mobile Databank - On Script - Move to Pos'),
(@NPC_DISK*100+2,9,1,0,0,0,100,0,3000,3000,3000,3000,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - On Script - Say'),
(@NPC_DISK*100+2,9,2,0,0,0,100,0,2000,2000,2000,2000,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - On Script - Say'),
(@NPC_DISK*100+2,9,3,0,0,0,100,0,8000,8000,8000,8000,69,1,0,0,0,0,0,10,@GUID+12,@NPC_BUNNY_DATASCAN,0,0,0,0,0,'Mobile Databank - On Script - Move to Pos'),
(@NPC_DISK*100+2,9,4,0,0,0,100,0,7000,7000,7000,7000,1,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - On Script - Say'),
(@NPC_DISK*100+2,9,5,0,0,0,100,0,9000,9000,9000,9000,69,1,0,0,0,0,0,10,@GUID+13,@NPC_BUNNY_DATASCAN,0,0,0,0,0,'Mobile Databank - On Script - Move to Pos'),
(@NPC_DISK*100+2,9,6,0,0,0,100,0,3000,3000,3000,3000,1,13,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - On Script - Say'),
(@NPC_DISK*100+2,9,7,0,0,0,100,0,9000,9000,9000,9000,69,1,0,0,0,0,0,10,@GUID+14,@NPC_BUNNY_DATASCAN,0,0,0,0,0,'Mobile Databank - On Script - Move to Pos'),
(@NPC_DISK*100+2,9,8,0,0,0,100,0,3000,3000,3000,3000,1,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'MMobile Databank - On Script - Say'),
(@NPC_DISK*100+2,9,9,0,0,0,100,0,0,0,0,0,11,@SPELL_LIFE_KC,0,0,0,0,0,7,0,0,0,0,0,0,0,'Mobile Databank - On script - Cast Credit'),
--
(@NPC_DISK*100+3,9,0,0,0,0,100,0,5000,5000,5000,5000,69,1,0,0,0,0,0,10,@GUID+4,@NPC_BUNNY_DATASCAN,0,0,0,0,0,'Mobile Databank - On Script - Move to Pos'),
(@NPC_DISK*100+3,9,1,0,0,0,100,0,3000,3000,3000,3000,1,15,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - On Script - Say'),
(@NPC_DISK*100+3,9,2,0,0,0,100,0,2000,2000,2000,2000,1,16,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - On Script - Say'),
(@NPC_DISK*100+3,9,3,0,0,0,100,0,8000,8000,8000,8000,69,1,0,0,0,0,0,10,@GUID+5,@NPC_BUNNY_DATASCAN,0,0,0,0,0,'Mobile Databank - On Script - Move to Pos'),
(@NPC_DISK*100+3,9,4,0,0,0,100,0,7000,7000,7000,7000,1,17,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - On Script - Say'),
(@NPC_DISK*100+3,9,5,0,0,0,100,0,9000,9000,9000,9000,69,1,0,0,0,0,0,10,@GUID+6,@NPC_BUNNY_DATASCAN,0,0,0,0,0,'Mobile Databank - On Script - Move to Pos'),
(@NPC_DISK*100+3,9,6,0,0,0,100,0,3000,3000,3000,3000,1,18,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mobile Databank - On Script - Say'),
(@NPC_DISK*100+3,9,7,0,0,0,100,0,0,0,0,0,11,@SPELL_ORDER_KC,0,0,0,0,0,7,0,0,0,0,0,0,0,'Mobile Databank - On script - Cast Credit');
