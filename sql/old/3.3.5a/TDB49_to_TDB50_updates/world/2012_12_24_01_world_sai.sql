-- Fix quest: "Words of Power" - http://www.wowhead.com/item=35354
-- Indexes
SET @TALETKHA := 26073;
SET @SCRIPT := @TALETKHA * 100;

-- Fix the previous SAIs for High Priest Talet-Kha
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@TALETKHA,-85118,-85098,-85176,-85175) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@TALETKHA,0,0,1,1,0,100,1,0,0,0,0,70,0,0,0,0,0,0,10,85098,25422,0,0,0,0,0, 'High Priest Talet-Kha - On OOC (1 time per reset/respawn) - Respawn Mystical Webbing'),
(@TALETKHA,0,1,2,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,85098,25422,0,0,0,0,0, 'High Priest Talet-Kha - Linked with previous event - Set data 0 1 to Mystical Webbing'),
(@TALETKHA,0,2,3,61,0,100,0,0,0,0,0,70,0,0,0,0,0,0,10,85118,25422,0,0,0,0,0, 'High Priest Talet-Kha - Linked with previous event - Respawn Mystical Webbing'),
(@TALETKHA,0,3,4,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,85118,25422,0,0,0,0,0, 'High Priest Talet-Kha - Linked with previous event - Set data 0 1 to Mystical Webbing'),
(@TALETKHA,0,4,5,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,85175,23033,0,0,0,0,0, 'High Priest Talet-Kha - Linked with previous event - Set data 0 1 to Invisible Stalker'),
(@TALETKHA,0,5,6,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,85176,23033,0,0,0,0,0, 'High Priest Talet-Kha - Linked with previous event - Set data 0 1 to Invisible Stalker'),
(@TALETKHA,0,6,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - Linked with previous event - Set phase 1'),
(@TALETKHA,0,7,0,38,0,100,0,0,1,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - On data set 0 1 - Increment phase by 1'),
(@TALETKHA,0,8,0,23,4,100,1,45497,0,0,0,80,@SCRIPT,2,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - On Aura missing - Run Script'),
(@TALETKHA,0,9,0,2,8,100,0,1,45,0,0,11,11640,1,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - Health 45% - Cast Renew on self'),
(@TALETKHA,0,10,0,0,8,100,0,4000,6000,5000,8000,11,15587,0,0,0,0,0,2,0,0,0,0,0,0,0, 'High Priest Talet-Kha - IC - Cast Mind Blast on victim'),
(@TALETKHA,0,11,12,25,8,100,0,0,0,0,0,18,33555200,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - On reset - Restore unit flags'),
(@TALETKHA,0,12,0,61,8,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - Linked with previous event - Set phase back to 0'),
(@SCRIPT,9,0,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - script - Text 0'),
(@SCRIPT,9,1,0,0,0,100,0,500,500,0,0,69,0,0,0,0,0,0,8,0,0,0,3788.44,3418.25,85.0562,0, 'High Priest Talet-Kha - script - Move to point'),
(@SCRIPT,9,2,0,0,0,100,0,500,500,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.1672, 'High Priest Talet-Kha - script - Set Orientation'),
(@SCRIPT,9,3,0,0,0,100,0,1500,1500,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - script - Bytes1 set to 0'),
(@SCRIPT,9,4,0,0,0,100,0,100,100,0,0,19,33555200,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - script - Remove unitflags'),
(@SCRIPT,9,5,0,0,0,100,0,100,100,0,0,11,45492,1,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - script - Aura self'),
(@SCRIPT,9,6,0,0,0,100,0,0,0,0,0,22,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - script - Set phase 4'),
(@SCRIPT,9,7,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,40,0,0,0,0,0,0, 'High Priest Talet-Kha - script - Start attack on closest player in 40 yards'),
(-85118,0,0,1,38,0,100,0,0,1,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mystical Webbing - On data set 0 1 - Set React State passive'),
(-85118,0,1,0,61,0,100,0,0,0,0,0,11,45497,2,0,0,0,0,11,26073,40,0,0,0,0,0,'Mystical Webbing - Linked with previous event - Web Beam'),
(-85118,0,2,3,6,0,100,0,0,0,0,0,45,0,2,0,0,0,0,10,85175,23033,0,0,0,0,0,'Mystical Webbing - On death - set data 0 2 Invisible Stalker'),
(-85118,0,3,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,11,26073,40,0,0,0,0,0,'Mystical Webbing - Linked with previous event - Set data 0 1 on Talet-Kha'),
(-85098,0,0,1,38,0,100,0,0,1,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mystical Webbing - On data set 0 1 - Set React State passive'),
(-85098,0,1,0,61,0,100,0,0,0,0,0,11,45497,2,0,0,0,0,11,26073,40,0,0,0,0,0,'Mystical Webbing - Linked with previous event - Web Beam'),
(-85098,0,2,3,6,0,100,0,0,0,0,0,45,0,2,0,0,0,0,10,85176,23033,0,0,0,0,0,'Mystical Webbing - On death - set data 0 2 Invisible Stalker'),
(-85098,0,3,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,11,26073,40,0,0,0,0,0,'Mystical Webbing - Linked with previous event - Set data 0 1 on Talet-Kha'),
(-85175,0,0,0,38,0,100,0,0,1,0,0,11,45497,2,0,0,0,0,11,26073,40,0,0,0,0,0, 'Invisible Stalker (Floating) - On data set 0 1 - Cast Web Beam on target'),
(-85175,0,1,0,38,0,100,0,0,2,0,0,92,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Invisible Stalker (Floating) - On data set 0 2 - Stop casting'),
(-85176,0,0,0,38,0,100,0,0,1,0,0,11,45497,2,0,0,0,0,11,26073,40,0,0,0,0,0, 'Invisible Stalker (Floating) - On data set 0 1 - Cast Web Beam on target'),
(-85176,0,1,0,38,0,100,0,0,2,0,0,92,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Invisible Stalker (Floating) - On data set 0 2 - Stop casting');
