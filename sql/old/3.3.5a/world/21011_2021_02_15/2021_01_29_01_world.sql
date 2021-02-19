-- Passive react state set in Feign Death aura script should be changed back to aggressive to allow aggro
-- This removes hacky attack start on LoS, they should not have fixed aggro range and can be skipped by high level characters
DELETE FROM `smart_scripts` WHERE `entryorguid` = 20869 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- 46107 in normal / 62315 in heroic
(20869,0,0,0,25,0,100,0,0,0,0,0,0,142,40,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcatraz Sentinel - On Reset - Set Health 40%"),
(20869,0,1,0,25,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcatraz Sentinel - On Reset - Set Reactstate Aggressive"),
(20869,0,2,0,4,0,100,0,0,0,0,0,0,28,31261,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcatraz Sentinel - On Aggro - Remove Aura 'Permanent Feign Death (Root)'"),
(20869,0,3,0,2,0,100,1,0,10,0,0,0,11,36719,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcatraz Sentinel - Between 0-10% Health - Cast 'Explode' (No Repeat)"),
(20869,0,4,0,6,0,100,0,0,0,0,0,0,11,37394,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcatraz Sentinel - On Death - Cast 'Summon Destroyed Sentinel'");
UPDATE `creature` SET `curhealth` = 115269 WHERE `id` = 20869;
