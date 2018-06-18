-- Magtheridon (21174)
DELETE FROM `creature_text` WHERE `CreatureID`=21174;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(21174,0,0,'Wretched, meddling insects! Release me, and perhaps I will grant you a merciful death!',14,0, 100,0,0,10247,17339,3,'Magtheridon'),
(21174,0,1,'Vermin! Leeches! Take my blood and choke on it!',14,0,100,0,0,10248,17340,3,'Magtheridon'),
(21174,0,2,'Illidan is an arrogant fool! I will crush him and reclaim Outland as my own!',14,0,100,0,0,10249,17341,3,'Magtheridon'),
(21174,0,3,'Away, you mindless parasites! My blood is my own!',14,0,100,0,0,10250,17342,3,'Magtheridon'),
(21174,0,4,'How long do you believe your pathetic sorcery can hold me?',14,0,100,0,0,10251,17343,3,'Magtheridon'),
(21174,0,5,'My blood will be the end of you!',14,0,100,0,0,10252,17344,3,'Magtheridon');
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=21174;
DELETE FROM `smart_scripts` WHERE `entryorguid`=21174 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21174,0,0,0,60,0,100,0,60000,60000,180000,180000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Magtheridon - Update - Say Line 0');

-- Laughing Skull Enforcer (17370, 18608)
DELETE FROM `creature_text` WHERE `CreatureID`=17370;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(17370,0,0,'This world is OURS!',12,0,100,0,0,0,16702,0,'Laughing Skull Enforcer'),
(17370,0,1,'We are the true Horde!',12,0,100,0,0,0,16697,0,'Laughing Skull Enforcer'),
(17370,0,2,'The blood is our power! ',12,0,100,0,0,0,16700,0,'Laughing Skull Enforcer'),
(17370,0,3,'For Kargath!  For Victory!',12,0,100,0,0,0,16698,0,'Laughing Skull Enforcer'),
(17370,0,4,'Gakarah ma!',12,0,100,0,0,0,16699,0,'Laughing Skull Enforcer'),
(17370,0,5,'Lok\'tar Illadari!\n',12,0,100,0,0,0,16701,0,'Laughing Skull Enforcer'),
(17370,0,6,'Lok narash!',12,0,100,0,0,0,16703,0,'Laughing Skull Enforcer');
UPDATE `creature_template` SET `pickpocketloot`=17370, `mechanic_immune_mask`=1 WHERE `entry`=18053;

-- Shadowmoon Warlock (17371, 18619)
UPDATE `creature_template` SET `pickpocketloot`=17371, `mechanic_immune_mask`=1 WHERE `entry`=18619;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17371 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17371,0,0,0,0,0,100,2,0,0,3300,4900,0,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,'Shadowmoon Warlock - In Combat CMC - Cast \'Shadow Bolt\' (Normal Dungeon)'),
(17371,0,1,0,0,0,100,4,0,0,3300,4900,0,11,15472,64,0,0,0,0,2,0,0,0,0,0,0,0,'Shadowmoon Warlock - In Combat CMC - Cast \'Shadow Bolt\' (Heroic Dungeon)'),
(17371,0,2,0,0,0,100,2,1100,7800,14800,30100,0,11,32197,33,0,0,0,0,5,0,0,0,0,0,0,0,'Shadowmoon Warlock - In Combat - Cast \'Corruption\' (Normal Dungeon)'),
(17371,0,3,0,0,0,100,4,1100,7800,14800,30100,0,11,37113,33,0,0,0,0,5,0,0,0,0,0,0,0,'Shadowmoon Warlock - In Combat - Cast \'Corruption\' (Heroic Dungeon)'),
(17371,0,4,0,0,0,100,6,6600,10700,14900,14900,0,11,13338,33,0,0,0,0,5,0,0,0,0,0,0,0,'Shadowmoon Warlock - In Combat - Cast \'Curse of Tongues\''),
(17371,0,5,0,0,0,100,6,12600,13700,21900,24900,0,11,33111,0,0,0,0,0,26,8,0,0,0,0,0,0,'Shadowmoon Warlock - In Combat - Cast \'Fel Power\'');

-- Shadowmoon Summoner (17395, 18617)
UPDATE `creature_template` SET `pickpocketloot`=17395 WHERE `entry`=18617;

-- Shadowmoon Adept (17397, 18615)
DELETE FROM `creature_text` WHERE `CreatureID`=17397;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(17397,0,0,'This world is OURS!',12,0,100,0,0,0,16702,0,'Shadowmoon Adept'),
(17397,0,1,'We are the true Horde!',12,0,100,0,0,0,16697,0,'Shadowmoon Adept'),
(17397,0,2,'The blood is our power! ',12,0,100,0,0,0,16700,0,'Shadowmoon Adept'),
(17397,0,3,'For Kargath!  For Victory!',12,0,100,0,0,0,16698,0,'Shadowmoon Adept'),
(17397,0,4,'Gakarah ma!',12,0,100,0,0,0,16699,0,'Shadowmoon Adept'),
(17397,0,5,'Lok\'tar Illadari!\n',12,0,100,0,0,0,16701,0,'Shadowmoon Adept'),
(17397,0,6,'Lok narash!',12,0,100,0,0,0,16703,0,'Shadowmoon Adept');
UPDATE `creature_template` SET `pickpocketloot`=17397 WHERE `entry`=18615;
DELETE FROM `creature_template_addon` WHERE `entry`=18615;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (18615, 0, 0, 0, 4097, 0, '');
DELETE FROM `smart_scripts` WHERE `entryorguid`=17397 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(17397,0,0,0,1,0,100,1,1000,1000,0,0,0,11,31059,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shadowmoon Adept - Out of Combat - Cast \'Hellfire Channeling\''),
(17397,0,1,0,4,0,10,7,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shadowmoon Adept - On Aggro - Say Line 0'),
(17397,0,2,0,0,0,100,6,2600,7800,7200,13300,0,11,12787,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shadowmoon Adept - In Combat - Cast \'Thrash\''),
(17397,0,3,0,0,0,100,6,5600,12300,9600,11400,0,11,11978,0,0,0,0,0,5,0,0,0,0,0,0,0,'Shadowmoon Adept - In Combat - Cast \'Kick\''),
(17397,0,4,0,2,0,100,7,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Shadowmoon Adept - Between 0-15% Health - Flee For Assist');
DELETE FROM `conditions` WHERE `SourceEntry`=17397 AND `SourceTypeOrReferenceId`=22;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22,0+1,17397,0,0,29,1,17477,10,0,0,0,0,'','Requires NPC Nearby');

-- Nascent Fel Orc (17398, 18612)
DELETE FROM `creature_text` WHERE `CreatureID`=17398;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(17398,0,0,'This world is OURS!',12,0,100,0,0,0,16702,0,'Nascent Fel Orc'),
(17398,0,1,'We are the true Horde!',12,0,100,0,0,0,16697,0,'Nascent Fel Orc'),
(17398,0,2,'The blood is our power! ',12,0,100,0,0,0,16700,0,'Nascent Fel Orc'),
(17398,0,3,'For Kargath!  For Victory!',12,0,100,0,0,0,16698,0,'Nascent Fel Orc'),
(17398,0,4,'Gakarah ma!',12,0,100,0,0,0,16699,0,'Nascent Fel Orc'),
(17398,0,5,'Lok\'tar Illadari!\n',12,0,100,0,0,0,16701,0,'Nascent Fel Orc'),
(17398,0,6,'Lok narash!',12,0,100,0,0,0,16703,0,'Nascent Fel Orc');
UPDATE `creature_template` SET `pickpocketloot`=17398, `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=17398;
UPDATE `creature_template` SET `pickpocketloot`=17398, `AIName`='', `ScriptName`='' WHERE `entry`=18612;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17398 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17398,0,0,0,4,0,10,7,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Laughing Skull Legionnaire - On Aggro - Say Line 0'),
(17398,0,1,0,0,0,100,6,0,500,1800,7800,0,11,22427,0,0,0,0,0,2,0,0,0,0,0,0,0,'Laughing Skull Legionnaire - In Combat - Cast \'Concussion Blow\''),
(17398,0,2,0,0,0,100,6,7000,8200,15800,20800,0,11,31900,0,0,0,0,0,2,0,0,0,0,0,0,0,'Laughing Skull Legionnaire - In Combat - Cast \'Stomp\'');

-- Hellfire Imp (17477, 18606)
DELETE FROM `smart_scripts` WHERE `entryorguid`=17477 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17477,0,0,0,1,0,100,1,1000,1000,0,0,0,11,30540,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hellfire Imp - Out of Combat - Cast \'Summon Visual\''),
(17477,0,1,0,4,0,100,1,0,0,0,0,0,28,30540,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hellfire Imp - On Aggro - Remove \'Summon Visual\''),
(17477,0,2,0,0,0,100,2,1000,3400,3400,4800,0,11,15242,64,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Imp - In Combat CMC - Cast \'Fireball\' (Normal Dungeon)'),
(17477,0,3,0,0,0,100,4,1000,3400,3400,4800,0,11,17290,64,0,0,0,0,5,0,0,0,0,0,0,0,'Hellfire Imp - In Combat CMC - Cast \'Fireball\' (Heroic Dungeon)'),
(17477,0,4,0,0,0,100,4,6000,9000,6000,9000,0,11,16144,1,0,0,0,0,2,0,0,0,0,0,0,0,'Hellfire Imp - In Combat - Cast \'Fire Blast\'');
DELETE FROM `conditions` WHERE `SourceEntry`=17477 AND `SourceTypeOrReferenceId`=22;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,0+1,17477,0,0,29,1,17397,10,0,0,0,0,'','Requires NPC Nearby');

-- Shadowmoon Technician (17414, 18618)
DELETE FROM `creature_text` WHERE `CreatureID`=17414;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(17414,0,0,'This world is OURS!',12,0,100,0,0,0,16702,0,'Shadowmoon Technician'),
(17414,0,1,'We are the true Horde!',12,0,100,0,0,0,16697,0,'Shadowmoon Technician'),
(17414,0,2,'The blood is our power! ',12,0,100,0,0,0,16700,0,'Shadowmoon Technician'),
(17414,0,3,'For Kargath!  For Victory!',12,0,100,0,0,0,16698,0,'Shadowmoon Technician'),
(17414,0,4,'Gakarah ma!',12,0,100,0,0,0,16699,0,'Shadowmoon Technician'),
(17414,0,5,'Lok\'tar Illadari!\n',12,0,100,0,0,0,16701,0,'Shadowmoon Technician'),
(17414,0,6,'Lok narash!',12,0,100,0,0,0,16703,0,'Shadowmoon Technician'),
(17414,1,0,'%s begins to arm the Proximity Bomb!',16,0,100,0,0,0,15129,0,'Shadowmoon Technician');
UPDATE `creature_template` SET `pickpocketloot`=17414 WHERE `entry`=18618;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17414 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17414,0,0,0,4,0,10,7,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shadowmoon Technician - On Aggro - Say Line 0'),
(17414,0,1,2,0,0,100,2,2800,4700,1400,23400,0,11,30846,1,0,0,0,0,5,0,0,0,0,0,0,0,'Shadowmoon Technician - In Combat - Cast \'Throw Proximity Bomb\''),
(17414,0,2,0,61,0,100,2,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shadowmoon Technician - In Combat - Say Line 1 (Normal Dungeon)'),
(17414,0,3,4,0,0,100,4,2800,4700,17700,23400,0,11,32784,1,0,0,0,0,5,0,0,0,0,0,0,0,'Shadowmoon Technician - In Combat - Cast \'Throw Proximity Bomb\''),
(17414,0,4,0,61,0,100,4,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shadowmoon Technician - In Combat - Say Line 1 (Heroic Dungeon)'),
(17414,0,5,0,0,0,100,2,4400,10600,3600,6200,0,11,40062,0,0,0,0,0,5,0,0,0,0,0,0,0,'Shadowmoon Technician - In Combat - Cast \'Throw Dynamite\' (Heroic Dungeon)'),
(17414,0,6,0,0,0,100,4,4400,10600,3600,6200,0,11,40064,0,0,0,0,0,5,0,0,0,0,0,0,0,'Shadowmoon Technician - In Combat - Cast \'Throw Dynamite\' (Heroic Dungeon)'),
(17414,0,7,0,0,0,100,6,5400,11600,24300,24300,0,11,6726,1,0,0,0,0,5,0,0,0,0,0,0,0,'Shadowmoon Technician - In Combat - Cast \'Silence\' (Heroic Dungeon)');

-- Laughing Skull Rogue (17491, 18610)
UPDATE `creature_template` SET `mechanic_immune_mask`=1 WHERE `entry`=17491;
UPDATE `creature_template` SET `pickpocketloot`=17491, `mechanic_immune_mask`=1 WHERE `entry`=18610;

-- Laughing Skull Legionnaire (17626, 18609)
DELETE FROM `creature_text` WHERE `CreatureID`=17626;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES 
(17626,0,0,'This world is OURS!',12,0,100,0,0,0,16702,0,'Laughing Skull Legionnaire'),
(17626,0,1,'We are the true Horde!',12,0,100,0,0,0,16697,0,'Laughing Skull Legionnaire'),
(17626,0,2,'The blood is our power! ',12,0,100,0,0,0,16700,0,'Laughing Skull Legionnaire'),
(17626,0,3,'For Kargath!  For Victory!',12,0,100,0,0,0,16698,0,'Laughing Skull Legionnaire'),
(17626,0,4,'Gakarah ma!',12,0,100,0,0,0,16699,0,'Laughing Skull Legionnaire'),
(17626,0,5,'Lok\'tar Illadari!\n',12,0,100,0,0,0,16701,0,'Laughing Skull Legionnaire'),
(17626,0,6,'Lok narash!',12,0,100,0,0,0,16703,0,'Laughing Skull Legionnaire'),
(17626,1,0,'%s goes into a frenzy!',16,0,100,0,0,0,38630,0,'Laughing Skull Legionnaire');
UPDATE `creature_template` SET `pickpocketloot`=17626 WHERE `entry`=18609;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17626 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17626,0,0,0,4,0,10,7,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Laughing Skull Legionnaire - On Aggro - Say Line 0'),
(17626,0,1,0,0,0,100,6,5800,7200,11900,12400,0,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,'Laughing Skull Legionnaire - In Combat - Cast \'Uppercut\''),
(17626,0,2,3,2,0,100,519,0,30,0,0,0,11,8599,2,0,0,0,0,1,0,0,0,0,0,0,0,'Laughing Skull Legionnaire - Between 0-30% Health - Cast \'Enrage\' (No Repeat)'),
(17626,0,3,0,61,0,100,512,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Laughing Skull Legionnaire - Between 0-30% Health - Say Line 1 (No Repeat)');
