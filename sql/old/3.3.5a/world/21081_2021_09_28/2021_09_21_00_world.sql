-- Thiassi the Lightning Bringer & Grand Necrolord Antiok
UPDATE `creature_addon` SET `auras` = '50771' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 28018);
UPDATE `creature` SET `position_x` = 4399.2, `position_y` = 563.5354, `position_z` = 116.6008, `orientation` = 4.62256 WHERE `id` = 28018; -- CreateObject2

DELETE FROM `smart_scripts` WHERE `entryorguid` = 28018 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28018,0,0,0,37,0,100,512,0,0,0,0,0,116,120,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thiassi the Lightning Bringer - On AI Initialize - Set Corpse Delay"), -- Sniff
(28018,0,1,0,0,0,100,512,0,0,2000,2000,0,11,50456,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Thiassi the Lightning Bringer - In Combat CMC - Cast 'Thiassi's Stormbolt'"),
(28018,0,2,0,0,0,100,512,10000,15000,10000,15000,0,11,15593,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thiassi the Lightning Bringer - In Combat - Cast 'War Stomp'"),
(28018,0,3,0,6,0,100,512,0,0,0,0,0,45,0,1,0,0,0,0,19,28006,10,0,0,0,0,0,0,"Thiassi the Lightning Bringer - On Death - Set Data 0 1 (Grand Necrolord Antiok)");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 28006 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2800600 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28006,0,0,0,37,0,100,0,0,0,0,0,0,116,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On AI Initialize - Set Corpse Delay"), -- Sniff
(28006,0,1,0,11,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Spawn - Set Event Phase 1"),
-- Antiok Random Broadcast 50460
(28006,0,2,0,1,0,100,0,90000,90000,90000,90000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Necrolord Antiok - Out of Combat - Say Line 0"),
(28006,0,3,0,38,0,100,0,0,1,0,0,0,80,2800600,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Data Set 0 1 - Run Script"),
(28006,0,4,0,0,1,100,0,0,0,2000,2000,0,11,50455,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Grand Necrolord Antiok - In Combat CMC - Cast 'Shadow Bolt' (Phase 1)"),
(28006,0,5,0,0,2,100,0,0,0,5000,5000,0,11,55984,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Grand Necrolord Antiok - In Combat CMC - Cast 'Shadow Bolt' (Phase 2)"),
-- Not sure how exactly, definitely not at %HP
(28006,0,6,0,0,2,100,0,5000,15000,25000,35000,0,11,50497,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Necrolord Antiok - In Combat - Cast 'Scream of Chaos' (Phase 2)"),
(28006,0,7,0,6,0,100,0,0,0,0,0,0,11,50472,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Death - Cast 'Drop Scythe of Antiok'"),
(28006,0,8,0,6,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Death - Say Line 3"),

(2800600,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Script - Set Reactstate Passive"),
(2800600,9,1,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Script - Say Line 1"),
(2800600,9,2,0,0,0,100,0,5000,5000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Script - Say Line 2"),
(2800600,9,3,0,0,0,100,0,1000,1000,0,0,0,11,50501,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Script - Cast 'Flesh Harvest'"),
(2800600,9,4,0,0,0,100,0,0,0,0,0,0,28,50494,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Script - Remove Aura 'Shroud of Lightning'"),
(2800600,9,5,0,0,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Script - Set Event Phase 2"),
(2800600,9,6,0,0,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Script - Set Reactstate Aggressive");

DELETE FROM `creature_text` WHERE `CreatureID` = 28006;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(28006,0,0,"Faster, dogs! We mustn't relent in our assault against the interlopers!",14,0,100,0,0,0,27405,0,"Grand Necrolord Antiok"),
(28006,0,1,"Soon, the bones of Galakrond will rise from their eternal slumber and wreak havoc upon this world!",14,0,100,0,0,0,27406,0,"Grand Necrolord Antiok"),
(28006,0,2,"Hear me, minions! Hear your lord, Antiok! Double your efforts or pay the consequences of failure!",14,0,100,0,0,0,27407,0,"Grand Necrolord Antiok"),
(28006,0,3,"The Lich King demands more frost wyrms be sent to Angrathar! Meet his demands or face my wrath!",14,0,100,0,0,0,27408,0,"Grand Necrolord Antiok"),
(28006,0,4,"Attackers are upon us! Let none through to this ancient grave!",14,0,100,0,0,0,27409,0,"Grand Necrolord Antiok"),
(28006,1,0,"You think you've won, mortal? Face the unbridled power of Antiok!",14,0,100,5,0,0,27415,0,"Grand Necrolord Antiok"),
(28006,2,0,"Behold! The Scythe of Antiok!",14,0,100,397,0,0,27416,0,"Grand Necrolord Antiok"),
(28006,3,0,"The Scythe of Antiok drops to the ground!",41,0,100,0,0,0,27410,0,"Grand Necrolord Antiok");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 50501;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,3,50501,0,0,31,0,3,27996,0,0,0,0,"","Group 0: Spell 'Flesh Harvest' (Effect 1 & 2) targets creature 'Wyrmrest Vanquisher'");

-- Amani'shi Warbringer
UPDATE `creature_template_addon` SET `auras` = '23255' WHERE `entry` = 23580;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 23580 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23580,0,0,0,0,0,100,0,5000,10000,10000,15000,0,11,43273,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Amani'shi Warbringer - In Combat - Cast 'Cleave'"),
(23580,0,1,0,0,0,100,0,15000,25000,20000,25000,0,11,42496,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Amani'shi Warbringer - In Combat - Cast 'Furious Roar'"),
(23580,0,2,3,2,0,100,1,0,25,0,0,0,11,43274,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Amani'shi Warbringer - Between 0-25% Health - Cast 'Dismount Bear' (No Repeat)"),
(23580,0,3,4,61,0,100,0,0,0,0,0,0,11,40743,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Amani'shi Warbringer - Between 0-25% Health - Cast 'Frenzy' (No Repeat)"),
(23580,0,4,0,61,0,100,0,0,0,0,0,0,43,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Amani'shi Warbringer - Between 0-25% Health - Dismount (No Repeat)");

-- Scrapped Fel Reaver
UPDATE `smart_scripts` SET `action_type` = 8, `action_param1` = 0, `comment` = "Scrapped Fel Reaver - On Spellhit 'Fel Zapper' - Set Reactstate Passive" WHERE `entryorguid` = 20243 AND `source_type` = 0 AND `id` = 2;
UPDATE `smart_scripts` SET `event_type` = 25 WHERE `entryorguid` = 20243 AND `source_type` = 0 AND `id` = 9;

-- Claw
UPDATE `smart_scripts` SET `action_param1` = 256, `comment` = "Claw - On Script - Set Flag Immune To Players" WHERE `entryorguid` = 1782700 AND `source_type` = 9 AND `id` = 4;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1782700 AND `source_type` = 9 AND `id` = 9;

-- Mogor
-- There's no 'wipe support' (https://youtu.be/n4x8vfcR03Y?t=146) and old implementation can make creature unattackable until grid unload
DELETE FROM `creature_text` WHERE `CreatureID` = 18069 AND `GroupID` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18069 AND `source_type` = 0 AND `id` IN (2,3,4,16,17,18,19,20,21);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1806901 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18069,0,4,0,2,1,100,1,0,1,0,0,0,80,1806901,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mogor - On 1% HP - Run Script (No Repeat) (Phase 1)"),

(1806901,9,0,0,0,0,100,0,0,0,0,0,0,11,31261,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mogor - On Script - Cast 'Permanent Feign Death (Root)'"),
(1806901,9,1,0,0,0,100,0,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mogor - On Script - Set Uninteractible"),
(1806901,9,2,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mogor - On Script - Set Reactstate Passive"),
(1806901,9,3,0,0,0,100,0,6000,6000,0,0,0,11,32343,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mogor - On Script - Cast 'Revive Self'"),
(1806901,9,4,0,0,0,100,0,3000,3000,0,0,0,28,31261,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mogor - On Script - Remove Aura 'Permanent Feign Death (Root)'"),
(1806901,9,5,0,0,0,100,0,0,0,0,0,0,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mogor - On Script - Remove Uninteractible"),
(1806901,9,6,0,0,0,100,0,0,0,0,0,0,42,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mogor - On Script - Turn Invinvibility HP OFF"),
(1806901,9,7,0,0,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mogor - On Script - Set Phase 2"),
(1806901,9,8,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mogor - On Script - Set Reactstate Aggressive"),
(1806901,9,9,0,0,0,100,0,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mogor - On Script - Say Line 5"),
(1806901,9,10,0,0,0,100,0,0,0,0,0,0,11,28747,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mogor - On Script - Cast 'Frenzy'");

-- Wyrmcult Blackwhelp
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2138700 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2138700,9,0,0,0,0,100,0,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wyrmcult Blackwhelp - On Script - Set Flag Standstate Dead"),
(2138700,9,1,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wyrmcult Blackwhelp - On Script - Set Reactstate Passive"),
(2138700,9,2,0,0,0,100,0,5000,5000,0,0,0,11,38178,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Wyrmcult Blackwhelp - On Script - Cast 'Create Wyrmcult Blackwhelp Item'"),
(2138700,9,3,0,0,0,100,0,0,0,0,0,0,11,16245,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wyrmcult Blackwhelp - On Script - Cast 'Freeze Anim'"),
(2138700,9,4,0,0,0,100,0,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wyrmcult Blackwhelp - On Script - Remove Flag Standstate Dead"),
(2138700,9,5,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wyrmcult Blackwhelp - On Script - Despawn");

-- Bloodrose Datura
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28532,28541) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2853200,2853201,2853202,2854100) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28532,0,0,0,62,0,100,0,9714,0,0,0,0,80,2853200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Gossip Option 0 Selected - Run Script"),
(28532,0,1,0,40,0,100,0,1,2853200,0,0,0,80,2853201,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Waypoint 1 Reached - Run Script"),
(28532,0,2,0,40,0,100,0,1,2853201,0,0,0,80,2853202,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Waypoint 1 Reached - Run Script"),

(2853200,9,0,0,0,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Script - Close Gossip"),
(2853200,9,1,0,0,0,100,0,0,0,0,0,0,11,51949,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Script - Cast 'Margarita Kill Credit'"),
(2853200,9,2,0,0,0,100,0,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Script - Remove NPC Flag Gossip"),
(2853200,9,3,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Script - Remove NPC Flag Questgiver"),
(2853200,9,4,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Script - Say Line 0"),
(2853200,9,5,0,0,0,100,0,3000,3000,0,0,0,53,0,2853200,0,0,0,3,1,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Script - Start Waypoint"),

(2853201,9,0,0,0,0,100,0,0,0,0,0,0,11,51925,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Script - Cast 'Throw'"),
(2853201,9,1,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Script - Say Line 1"),
(2853201,9,2,0,0,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,28541,10,0,0,0,0,0,0,"Bloodrose Datura - On Script - Set Data 0 1 (Captured Drakkari Scout)"),
(2853201,9,3,0,0,0,100,0,4000,4000,0,0,0,1,0,0,0,0,0,0,19,28541,10,0,0,0,0,0,0,"Bloodrose Datura - On Script - Say Line 0 (Captured Drakkari Scout)"),
(2853201,9,4,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,19,28541,10,0,0,0,0,0,0,"Bloodrose Datura - On Script - Say Line 1 (Captured Drakkari Scout)"),
(2853201,9,5,0,0,0,100,0,3000,3000,0,0,0,86,43327,0,19,28541,10,0,1,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Script - Cross Cast 'Vomit' (Captured Drakkari Scout)"),
(2853201,9,6,0,0,0,100,0,3000,3000,0,0,0,86,51929,0,19,28541,10,0,1,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Script - Cross Cast 'Bloody Explosion (Green)' (Captured Drakkari Scout)"),
(2853201,9,7,0,0,0,100,0,0,0,0,0,0,86,51930,0,19,28541,10,0,1,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Script - Cross Cast 'Scourge Troll Transform' (Captured Drakkari Scout)"),
(2853201,9,8,0,0,0,100,0,3000,3000,0,0,0,45,0,2,0,0,0,0,19,28541,10,0,0,0,0,0,0,"Bloodrose Datura - On Script - Set Data 0 2 (Captured Drakkari Scout)"),
(2853201,9,9,0,0,0,100,0,5000,5000,0,0,0,11,51927,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Script - Cast 'Death_Decay Visual'"),
(2853201,9,10,0,0,0,100,0,0,0,0,0,0,86,40148,0,19,28541,10,0,1,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Script - Cross Cast 'Immolation' (Captured Drakkari Scout)"),
(2853201,9,11,0,0,0,100,0,0,0,0,0,0,90,7,0,0,0,0,0,19,28541,10,0,0,0,0,0,0,"Bloodrose Datura - On Script - Set Flag Standstate Dead (Captured Drakkari Scout)"),
(2853201,9,12,0,0,0,100,0,0,0,0,0,0,41,5000,0,0,0,0,0,19,28541,10,0,0,0,0,0,0,"Bloodrose Datura - On Script - Delayed Despawn (Captured Drakkari Scout)"),
(2853201,9,13,0,0,0,100,0,3000,3000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Script - Say Line 2"),
(2853201,9,14,0,0,0,100,0,0,0,0,0,0,53,0,2853201,0,0,0,3,1,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Script - Start Waypoint"),

(2853202,9,0,0,0,0,100,0,0,0,0,0,0,82,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Script - Set NPC Flag Gossip"),
(2853202,9,1,0,0,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodrose Datura - On Script - Set NPC Flag Questgiver"),

(28541,0,0,0,38,0,100,0,0,1,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,1.832595705986022949,"Captured Drakkari Scout - On Data Set 0 1 - Set Orientation"),
(28541,0,1,0,38,0,100,0,0,2,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0.453785598278045654,"Captured Drakkari Scout - On Data Set 0 2 - Set Orientation");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (51925,51927);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,51925,0,0,31,0,3,28541,0,0,0,0,"","Group 0: Spell 'Throw' (Effect 1) targets creature 'Captured Drakkari Scout'"),
(13,1,51927,0,0,31,0,3,28541,0,0,0,0,"","Group 0: Spell 'Death_Decay Visual' (Effect 1) targets creature 'Captured Drakkari Scout'");

DELETE FROM `waypoints` WHERE `entry` IN (2853200,2853201);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(2853200,1,5203.563,-1318.108,242.52626,0,0,"Bloodrose Datura"),
(2853201,1,5203.7305,-1313.0774,242.76698,0.418879032135009765,1,"Bloodrose Datura");

UPDATE `creature` SET `spawntimesecs` = 20 WHERE `id` = 28541;
