SET @Mammoth   := 28851; -- NPC: Enraged Mammoth

DELETE FROM `smart_scripts` WHERE `entryorguid`=@Mammoth AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Mammoth,0,0,1,8,0,100,0,52596,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Enraged Mammoth - On Spell Hit(Medallion of Mam''toth) - Change Faction To friendly'),
(@Mammoth,0,1,0,61,0,100,0,0,0,0,0,81,16777216,0,0,0,0,0,1,0,0,0,0,0,0,0,'Enraged Mammoth - Link With Previous Event - Set Flags 16777216'),
(@Mammoth,0,2,3,1,0,100,0,10000,10000,10000,10000,2,1924,0,0,0,0,0,1,0,0,0,0,0,0,0,'Enraged Mammoth - On OOC for 10 sec - Change Faction Back To Normal'),
(@Mammoth,0,3,0,61,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Enraged Mammoth - Link With Previous Event - Restore flags'),
(@Mammoth,0,4,0,28,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Enraged Mammoth - On Passenger Removed - Despawn');
