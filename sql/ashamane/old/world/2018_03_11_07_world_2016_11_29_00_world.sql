DELETE FROM `spell_script_names` WHERE `spell_id`=46620 AND `ScriptName`='spell_red_dragonblood';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(46620, 'spell_red_dragonblood');

DELETE FROM `creature_text` WHERE `CreatureID`=26117;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(26117, 0, 0, 'Easy now, drakeling.', 12, 0, 100, 0, 0, 0, 25325, 0, 'Raelorasz - say_drake_0'),
(26117, 1, 0, 'A wonderful specimen.', 12, 0, 100, 0, 0, 0, 25324, 0, 'Raelorasz - say_drake_1'),
(26117, 1, 1, 'Sleep now, young one....', 12, 0, 100, 0, 0, 0, 25323, 0, 'Raelorasz - say_drake_2'),
(26117, 1, 2, 'Yes, this one should advance my studies nicely....', 12, 0, 100, 0, 0, 0, 25326, 0, 'say_drake_3');

DELETE FROM conditions WHERE SourceTypeOrReferenceId=13 AND SourceEntry=46704;
INSERT INTO conditions VALUES (13, 1, 46704, 0, 0, 31, 0, 3, 26127, 0, 0, 0, 0, '', 'Target Nexus Drake Hatchling');

-- Raelorasz SAI
SET @ENTRY := 26117;
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,9253,1,0,0,85,46764,1,0,0,0,0,7,0,0,0,0,0,0,0,"Raelorasz - On Gossip Option 1 Selected - Invoker Cast 'Push Arcane Prison'"),
(@ENTRY,0,1,0,61,0,100,0,9253,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Raelorasz - On Gossip Option 1 Selected - Close Gossip"),
(@ENTRY,0,2,0,60,0,100,0,5000,5000,5000,5000,45,1,26127,0,0,0,0,11,26127,30,0,0,0,0,0,"Raelorasz - On Update - Set Data 1 26127");

-- Nexus Drake Hatchling SAI
SET @ENTRY := 26127;
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100+00 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,12000,15000,25000,35000,11,36631,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Drake Hatchling - In Combat - Cast 'Netherbreath'"),
(@ENTRY,0,1,0,0,0,100,0,5000,10000,20000,35000,11,36513,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Drake Hatchling - In Combat - Cast 'Intangible Presence'"),
(@ENTRY,0,2,3,8,0,100,0,46607,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Spellhit 'Drake Harpoon' - Store Targetlist"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,117,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Spellhit 'Drake Harpoon' - evade off"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,86,46620,2,12,1,0,0,1,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Spellhit 'Drake Harpoon' - Cross Cast 'Red Dragonblood'"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Spellhit 'Drake Harpoon' - Start Attacking"),
(@ENTRY,0,6,0,25,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Reset - Remove Flags Immune To Players & Immune To NPC's"),
(@ENTRY,0,7,0,25,0,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Reset - Remove Flag"),
(@ENTRY,0,8,0,38,0,100,1,1,26127,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Data Set 1 26127 - Run Script (No Repeat)"),
(@ENTRY,0,9,10,8,0,100,1,46704,0,0,0,11,46703,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Spellhit 'Raelorasz Fireball' - Cast 'Complete Immolation' (No Repeat)"),
(@ENTRY,0,10,11,61,0,100,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Spellhit 'Raelorasz Fireball' - Set Flag Standstate Dead (No Repeat)"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,41,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Spellhit 'Raelorasz Fireball' - Despawn In 4000 ms (No Repeat)"),
(@ENTRY,0,12,0,1,0,100,1,0,0,0,0,117,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Drake Hatchling - Ooc - evade on"),
(@ENTRY*100+00,9,0,0,0,0,100,0,0,0,0,0,33,26175,0,0,0,0,0,12,1,0,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Quest Credit ''"),
(@ENTRY*100+00,9,1,0,0,0,100,0,0,0,0,0,28,46607,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Remove Aura 'Drake Harpoon'"),
(@ENTRY*100+00,9,2,0,0,0,100,0,0,0,0,0,29,0,0,0,0,0,0,19,26175,40,0,0,0,0,0,"Nexus Drake Hatchling - On Script - follow"),
(@ENTRY*100+00,9,3,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,19,26117,30,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Say Line 0"),
(@ENTRY*100+00,9,4,0,0,0,100,0,0,0,0,0,86,46704,0,19,26117,30,0,1,0,0,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Cross Cast 'Raelorasz Fireball'"),
(@ENTRY*100+00,9,5,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,19,26117,30,0,0,0,0,0,"Nexus Drake Hatchling - On Script - Say Line 1");
