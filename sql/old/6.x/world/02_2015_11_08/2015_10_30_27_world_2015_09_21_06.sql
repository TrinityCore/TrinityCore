-- 
-- North Sea Kraken SAI
SET @ENTRY := 34925;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,7000,9000,11,66514,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Sea Kraken - IC - Cast Frost Breath'),
(@ENTRY,0,1,0,8,0,40,0,66588,0,0,0,80,@ENTRY*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'North Sea Kraken - On Spell hit Flaming Spear - ActionList'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,11,50142,2,0,0,0,0,1,0,0,0,0,0,0,0,'North Sea Kraken - actionList - Cast Submerge'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Sea Kraken - actionList - Add unitflag not selectable'),
(@ENTRY*100,9,2,0,0,0,100,0,3000,3000,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Sea Kraken - actionList - Turn Invisible'),
(@ENTRY*100,9,3, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Northsea Kraken - actionList - Turn Visible'),
(@ENTRY*100,9,4,0,0,0,100,0,0,0,0,0,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,'North Sea Kraken - actionList - Remove unitflag not selectable'),
(@ENTRY, 0, 2, 3, 2, 0, 100, 1, 1, 6, 0, 0, 11, 66994, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Northsea Kraken - On Between 1 and 6% HP - Cast Kraken Tooth Explosion'),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Northsea Kraken - Linked With Previous Event - Die'),
(@ENTRY, 0, 4, 0, 1, 0, 100, 0, 30000, 30000, 30000, 30000, 11, 68909, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Northsea Kraken - OOC - Cast Submerge '),
(@ENTRY, 0, 5, 0, 0, 0, 100, 0, 15000, 20000, 15000, 20000, 11, 66511, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Northsea Kraken - IC - Cast Whirl'),
(@ENTRY,0,6,0,8,0,100,0,66588,0,0,0,11,66717,2,0,0,0,0,7,0,0,0,0,0,0,0,'North Sea Kraken - On spell Hit - Cast Quest credit');
