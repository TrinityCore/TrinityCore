--
UPDATE `creature_addon` SET `emote`=0 WHERE `guid`=111855;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (24191,24233,24232);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24191,24233) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2419100,2419101) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24191,0,0,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Irulon Trueblade - On Reset - Set Event Phase 1'),
(24191,0,1,0,20,1,100,0,11289,0,0,0,80,2419100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Irulon Trueblade - On Quest 'Guided by Honor' Finished - Run Script (Phase 1)"),
(24191,0,2,0,38,0,100,0,1,1,0,0,80,2419101,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Irulon Trueblade - On Data Set 1 1 - Run Script'),

(2419100,9,0,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Set Event Phase 2'),
(2419100,9,1,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Set Active'),
(2419100,9,2,0,0,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Set NPC Flags'),
(2419100,9,3,0,0,0,100,0,1000,1000,0,0,17,0,0,0,0,0,0,19,24233,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Set Emote State 0 (Cleric of the Crusade)'),
(2419100,9,4,0,0,0,100,0,1500,1500,0,0,1,0,0,0,0,0,0,19,24233,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Say Line 0 (Cleric of the Crusade)'),
(2419100,9,5,0,0,0,100,0,2000,2000,0,0,45,1,1,0,0,0,0,19,24233,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Set Data to 1 1 (Cleric of the Crusade)'),

(2419101,9,0,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,19,24233,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Say Line 1 (Cleric of the Crusade)'),
(2419101,9,1,0,0,0,100,0,0,0,0,0,36,24232,0,0,0,0,0,19,24233,0,0,0,0,0,0,"Lord Irulon Trueblade - On Script - Update Template To 'Highlord Tirion Fordring' (Cleric of the Crusade)"),
(2419101,9,2,0,0,0,100,0,0,0,0,0,71,0,0,0,0,0,0,19,24232,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Change Equipment (Highlord Tirion Fordring)'),
(2419101,9,3,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,24232,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Set Orientation'),
(2419101,9,4,0,0,0,100,0,1500,1500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Say Line 0'),
(2419101,9,5,0,0,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Set NPC Flags'),
(2419101,9,6,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,19,24232,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Say Line 2 (Highlord Tirion Fordring)'),
(2419101,9,7,0,0,0,100,0,4000,4000,0,0,5,274,0,0,0,0,0,19,24232,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Play Emote 274 (Highlord Tirion Fordring)'),
(2419101,9,8,0,0,0,100,0,6000,6000,0,0,1,3,0,0,0,0,0,19,24232,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Say Line 3 (Highlord Tirion Fordring)'),
(2419101,9,9,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Say Line 1'),
(2419101,9,10,0,0,0,100,0,4000,4000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Play Emote 1'),
(2419101,9,11,0,0,0,100,0,4000,4000,0,0,5,274,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Play Emote 274'),
(2419101,9,12,0,0,0,100,0,3000,3000,0,0,1,4,0,0,0,0,0,19,24232,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Say Line 4 (Highlord Tirion Fordring)'),
(2419101,9,13,0,0,0,100,0,3000,3000,0,0,1,5,0,0,0,0,0,19,24232,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Say Line 5 (Highlord Tirion Fordring)'),
(2419101,9,14,0,0,0,100,0,3000,3000,0,0,5,1,0,0,0,0,0,19,24232,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Play Emote 1 (Highlord Tirion Fordring)'),
(2419101,9,15,0,0,0,100,0,3000,3000,0,0,1,6,0,0,0,0,0,19,24232,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Say Line 6 (Highlord Tirion Fordring)'),
(2419101,9,16,0,0,0,100,0,3000,3000,0,0,5,1,0,0,0,0,0,19,24232,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Play Emote 1 (Highlord Tirion Fordring)'),
(2419101,9,17,0,0,0,100,0,3000,3000,0,0,1,7,0,0,0,0,0,19,24232,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Say Line 7 (Highlord Tirion Fordring)'),
(2419101,9,18,0,0,0,100,0,2000,2000,0,0,45,1,2,0,0,0,0,19,24232,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Set Data 1 2 (Highlord Tirion Fordring)'),
(2419101,9,19,0,0,0,100,0,0,0,0,0,71,0,0,13262,0,0,0,19,24232,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Change Equipment (Highlord Tirion Fordring)'),
(2419101,9,20,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6.19592,'Lord Irulon Trueblade - On Script - Set Orientation'),
(2419101,9,21,0,0,0,100,0,2000,2000,0,0,1,8,0,0,0,0,0,19,24232,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Say Line 8 (Highlord Tirion Fordring)'),
(2419101,9,22,0,0,0,100,0,4000,4000,0,0,5,397,0,0,0,0,0,19,24232,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Play Emote 397 (Highlord Tirion Fordring)'),
(2419101,9,23,0,0,0,100,0,59000,59000,0,0,45,1,3,0,0,0,0,19,24232,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Set Data 1 3 (Highlord Tirion Fordring)'),
(2419101,9,24,0,0,0,100,0,0,0,0,0,36,24233,0,0,0,0,0,19,24232,0,0,0,0,0,0,"Lord Irulon Trueblade - On Script - Update Template To 'Cleric of the Crusade' (Highlord Tirion Fordring)"),
(2419101,9,25,0,0,0,100,0,0,0,0,0,71,0,0,0,0,0,0,19,24233,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Change Equipment (Cleric of the Crusade)'),
(2419101,9,26,0,0,0,100,0,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Set Inactive'),
(2419101,9,27,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lord Irulon Trueblade - On Script - Set Event Phase 1'),

(24233,0,0,0,11,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cleric of the Crusade - On Respawn - Set Emote State 69'),
(24233,0,1,0,11,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cleric of the Crusade - On Respawn - Set Set Run Off'),
(24233,0,2,0,38,0,100,0,1,1,0,0,69,1,0,0,0,0,0,8,0,0,0,600.944,-5007.85,3.65394,0,'Cleric of the Crusade - On Data Set 1 1 - Move to Position'),
(24233,0,3,4,38,0,100,0,1,2,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6.23082,'Cleric of the Crusade - On Data Set 1 2 - Set Orientation'),
(24233,0,4,0,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cleric of the Crusade - On Link - Set Sheath Melee'),
(24233,0,5,0,38,0,100,0,1,3,0,0,69,2,0,0,0,0,0,8,0,0,0,601.464,-5003.82,3.90394,1.76278,'Cleric of the Crusade - On Data Set 1 3 - Move to Position'),
(24233,0,6,7,34,0,100,0,8,1,0,0,45,1,1,0,0,0,0,19,24191,0,0,0,0,0,0,'Cleric of the Crusade - On Reached Point 1 - Set Data 1 1 (Lord Irulon Trueblade)'),
(24233,0,7,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,24191,0,0,0,0,0,0,"Cleric of the Crusade - On Link - Set Orientation Closest Creature 'Lord Irulon Trueblade'"),
(24233,0,8,0,34,0,100,0,8,2,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cleric of the Crusade - On Reached Point 2 - Set Emote State 69');

DELETE FROM `creature_text` WHERE `CreatureID` IN (24232,24233,24191);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(24233, 0, 0, 'That will be enough, Irulon.', 12, 7, 100, 0, 0, 0, 22997, 0, 'Cleric of the Crusade'),
(24233, 1, 0, '%s removes his disguise', 16, 0, 100, 0, 0, 0, 22999, 0, 'Cleric of the Crusade'),
(24232, 2, 0, 'The boy\'s death and, in fact, the deaths of all of the knights involved in the redemption of the blade could have been avoided.', 12, 7, 100, 1, 0, 0, 23000, 0, 'Tirion Fordring'),
(24232, 3, 0, 'Their passing weighs heavily upon my soul.', 12, 7, 100, 1, 0, 0, 23001, 0, 'Tirion Fordring'),
(24232, 4, 0, '%s grimaces.', 16, 7, 100, 0, 0, 0, 23003, 0, 'Tirion Fordring'),
(24232, 5, 0, 'It should have been me that carried the blade to Northrend. The burden was mine to bear.', 12, 7, 100, 1, 0, 0, 23004, 0, 'Tirion Fordring'),
(24232, 6, 0, 'But you are right, Irulon. The price of our freedom will undoubtedly cost thousands more of their lives.', 12, 7, 100, 1, 0, 0, 23005, 0, 'Tirion Fordring'),
(24232, 7, 0, '%s picks up the Ashbringer', 16, 7, 100, 0, 0, 0, 23006, 0, 'Tirion Fordring'),
(24232, 8, 0, 'Do you hear me, Arthas? The Argent Crusade comes for you! Your kingdom shall crumble beneath the weight of justice! By the Light!', 14, 0, 100, 22, 0, 0, 23007, 0, 'Tirion Fordring'),
(24191, 0, 0, 'Lord Fordring, you mustn\'t reveal yourself!', 12, 7, 100, 5, 0, 0, 22998, 0, 'Lord Irulon Trueblade'),
(24191, 1, 0, 'The path of freedom has always been beset with tragedy, sire. We could not risk losing you. The Crusade could not have survived such a blow.', 12, 7, 100, 1, 0, 0, 23002, 0, 'Lord Irulon Trueblade');
