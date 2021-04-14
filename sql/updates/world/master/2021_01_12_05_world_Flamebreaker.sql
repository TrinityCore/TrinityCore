-- Blazebound Elemental
SET @ENTRY := 38896;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,5000,5000,12500,15300,11,80031,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Cast Flaming Slice"),
(@ENTRY,@SOURCETYPE,1,0,8,0,100,0,75206,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Die w Spellhit on Q item"),
(@ENTRY,@SOURCETYPE,2,0,8,0,100,0,75206,0,0,0,12,40065,1,30,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Summon w Spellhit on Q item (100%)"),
(@ENTRY,@SOURCETYPE,3,0,8,0,100,0,75206,0,0,0,12,40065,1,30,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Summon w Spellhit on Q item (100%)"),
(@ENTRY,@SOURCETYPE,4,0,8,0,100,0,75206,0,0,0,12,40065,1,30,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Summon w Spellhit on Q item (100%)"),
(@ENTRY,@SOURCETYPE,5,0,8,0,100,0,75206,0,0,0,12,40065,1,30,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Summon w Spellhit on Q item (100%)"),
(@ENTRY,@SOURCETYPE,6,0,8,0,100,0,75206,0,0,0,12,40065,1,30,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Summon w Spellhit on Q item (100%)"),
(@ENTRY,@SOURCETYPE,7,1,8,0,43,0,75206,0,0,0,12,40065,1,30,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Summon w Spellhit on Q item (Bonus 42%)"),
(@ENTRY,@SOURCETYPE,8,1,8,0,43,0,75206,0,0,0,12,40065,1,30,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Summon w Spellhit on Q item (Bonus 42%)"),
(@ENTRY,@SOURCETYPE,9,1,8,0,13,0,75206,0,0,0,12,40065,1,30,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Summon w Spellhit on Q item (Bonus 13%)");