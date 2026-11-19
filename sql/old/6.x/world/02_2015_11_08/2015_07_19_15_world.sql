DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (106877, 147640, 147647);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(106877,106871,1,'Sha Spike Dummy Effect - Cast Sha Spike on Spellhit.'),
(147647,147648,1,'Grasp of Y''Shaarj damage - Cast Grasp of Y''Shaarj summon Manifestation on Spellhit.'),
(147640,147644,1,'Charge - Cast Reaper on Spellhit.');

-- Harbinger of Y'Shaarj SAI
SET @ENTRY := 73452;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,9000,11000,11,147647,0,0,0,0,0,2,0,0,0,0,0,0,0,"Harbinger of Y'Shaarj - IC Timer - Cast Grasp of Y'Shaarj on Victim."),
(@ENTRY,0,1,0,74,0,100,0,40,60,20000,25000,11,147553,32,0,0,0,0,7,0,0,0,0,0,0,0,"Harbinger of Y'Shaarj - On Friendly Health Pct between 40-60% - Cast Touch of Y'Shaarj on Action Invoker."),
(@ENTRY,0,2,0,17,0,100,0,73454,1000,1000,0,85,147754,34,0,0,0,0,1,0,0,0,0,0,0,0,"Harbinger of Y'Shaarj - On Summoned Manifestation - Invoker Cast Bound Y'Shaarj Power on Self."),
(@ENTRY,0,3,0,17,0,100,0,73454,1000,1000,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Harbinger of Y'Shaarj - On Summoned Manifestation - Store Target List."),
(@ENTRY,0,4,0,25,0,100,0,0,0,0,0,51,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Harbinger of Y'Shaarj - On Reset - Kill Store Target."),
(@ENTRY,0,5,0,6,0,100,0,0,0,0,0,51,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Harbinger of Y'Shaarj - On Death- Kill Store Target.");

-- Kor'kron Reaper SAI
SET @ENTRY := 73414;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,31,0,100,0,147640,0,2000,3000,11,147642,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Reaper - On Spellhit Target Charge. - Cast Reaping Whirlwind."),
(@ENTRY,0,1,0,0,0,100,0,9000,11000,14000,16000,11,147640,0,0,0,0,0,17,0,45,0,0,0,0,0,"Kor'kron Reaper - IC Timer - Cast Charge on Random Player Range between 0-45 yards.");
