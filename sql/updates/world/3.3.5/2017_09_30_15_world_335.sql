-- Guard Ashlock, Guard Howe, Guard Pearce and Guard Hiett
SET @Howe    := 903;
SET @Ashlock := 932;
SET @Hiett   := 933;
SET @Pearce  := 935;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@Ashlock,@Hiett,@Howe,@Pearce);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Ashlock,@Hiett,@Howe,@Pearce) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Howe,   0,0,0,1,0,100,0, 25000, 25000,180000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Howe - Out of Combat - Say Line 0"),
(@Ashlock,0,0,0,1,0,100,0, 15000, 15000,180000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Ashlock - Out of Combat - Say Line 0"),
(@Hiett,  0,0,0,1,0,100,0,105000,105000,180000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Hiett - Out of Combat - Say Line 0"),
(@Pearce, 0,0,0,1,0,100,0, 95000, 95000,180000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Pearce - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` IN (@Ashlock,@Hiett,@Howe,@Pearce);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@Howe,   0,0,"Marshal Marris expects the reserve from Stormwind any time now. . . .",12,7,100,1,0,0,53,0,"Guard Howe"),
(@Ashlock,0,0,"Where are those reinforcements from Stormwind?  Heavy Blackrock activity has been reported in the East.",12,7,100,6,0,0,51,0,"Guard Ashlock"),
(@Hiett,  0,0,"Hopefully the reinforcements from Stormwind show up soon. . . .",12,7,100,1,0,0,49,0,"Guard Hiett"),
(@Pearce, 0,0,"Still no sign of the 2nd Battalion from Stormwind.  Reports are coming in of Shadowhide movement in the Northeast.",12,7,100,6,0,0,52,0,"Guard Pearce");
