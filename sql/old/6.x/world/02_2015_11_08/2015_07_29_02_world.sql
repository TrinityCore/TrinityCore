-- Nordrassil Druid
SET @NPC_YSERA    := 40289;
SET @SPELL_GREEN_BRAID_CHANNEL := 74492;

SET @GUID_DRUID_0 := -371684;
SET @GUID_DRUID_1 := -371675;
SET @GUID_DRUID_2 := -371666;
SET @SOURCETYPE   := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(@GUID_DRUID_0, @GUID_DRUID_1, @GUID_DRUID_2) AND `source_type`=@SOURCETYPE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID_DRUID_0,@SOURCETYPE,0,0,1,0,100,0,1000,1000,600000,600000,11,@SPELL_GREEN_BRAID_CHANNEL,2,0,0,0,0,19,@NPC_YSERA,0,0,0.0,0.0,0.0,0.0,"Cast SPELL_GREEN_BRAID_CHANNEL (74492) on Ysera (40289)"),
(@GUID_DRUID_1,@SOURCETYPE,0,0,1,0,100,0,1000,1000,600000,600000,11,@SPELL_GREEN_BRAID_CHANNEL,2,0,0,0,0,19,@NPC_YSERA,0,0,0.0,0.0,0.0,0.0,"Cast SPELL_GREEN_BRAID_CHANNEL (74492) on Ysera (40289)"),
(@GUID_DRUID_2,@SOURCETYPE,0,0,1,0,100,0,1000,1000,600000,600000,11,@SPELL_GREEN_BRAID_CHANNEL,2,0,0,0,0,19,@NPC_YSERA,0,0,0.0,0.0,0.0,0.0,"Cast SPELL_GREEN_BRAID_CHANNEL (74492) on Ysera (40289)");
