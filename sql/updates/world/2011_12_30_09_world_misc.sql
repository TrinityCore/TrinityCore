-- Emergency Supplies SAI fix by nelegalno
-- Closes #4187

SET @GUID := 25841;
SET @MNID := 21248;
SET @SPEL := 46362;

DELETE FROM `smart_scripts` WHERE (`entryorguid`=@GUID AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@GUID,0,0,0,11,0,100,0,0,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fizzcrank Recon Pilot - On spawn - set gossip flag'),
(@GUID,0,1,2,62,0,100,0,@MNID,0,0,0,85,@SPEL,0,0,0,0,0,7,0,0,0,0,0,0,0,'Fizzcrank Recon Pilot - On gossip option select - cast spell'),
(@GUID,0,2,3,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Fizzcrank Recon Pilot - On gossip option select - close gossip'),
(@GUID,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fizzcrank Recon Pilot - On gossip option select - set phase 1'),
(@GUID,0,4,0,1,1,100,0,3000,3000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fizzcrank Recon Pilot - OOC - wait 3 sec despawn (Phase 1)');
