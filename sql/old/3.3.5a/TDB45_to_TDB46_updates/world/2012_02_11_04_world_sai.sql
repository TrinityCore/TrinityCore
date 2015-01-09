SET @NPC_DATURA_BLOODROSE := 28532;
SET @NPC_CAPTURED_DRAKKARI_SCOUT := 28541;
SET @SPELL_IMMOLATION := 40148;

-- Insert creature_text from sniff
DELETE FROM `creature_text` WHERE `entry` IN (@NPC_DATURA_BLOODROSE,@NPC_CAPTURED_DRAKKARI_SCOUT);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_DATURA_BLOODROSE,0,0,'Indeed. Watch this, $r.',12,0,100,1,0,0,'Bloodrose Datura'),
(@NPC_DATURA_BLOODROSE,1,0,'Here, troll... a gift!',12,0,100,0,0,0,'Bloodrose Datura'),
(@NPC_DATURA_BLOODROSE,2,0,'Ugh... disgusting!',12,0,100,0,0,0,'Bloodrose Datura'),
(@NPC_CAPTURED_DRAKKARI_SCOUT,0,0,'For me? Really, mon?',12,0,100,6,0,0,'Captured Drakkari Scout'),
(@NPC_CAPTURED_DRAKKARI_SCOUT,1,0,'It....it be beautiful!',12,0,100,5,0,0,'Captured Drakkari Scout');

-- SmartAIs
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@NPC_DATURA_BLOODROSE,@NPC_CAPTURED_DRAKKARI_SCOUT);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_DATURA_BLOODROSE,@NPC_CAPTURED_DRAKKARI_SCOUT) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_DATURA_BLOODROSE*100,@NPC_CAPTURED_DRAKKARI_SCOUT*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_DATURA_BLOODROSE,0,0,1,62,0,100,0,9714,0,0,0,11,51949,0,0,0,0,0,7,0,0,0,0,0,0,0,'Bloodrose Datura - On gossip select - Spellcast Margarita Kill Credit'),
(@NPC_DATURA_BLOODROSE,0,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Bloodrose Datura - On gossip select - Close gossip'),
(@NPC_DATURA_BLOODROSE,0,2,0,61,0,100,0,0,0,0,0,80,@NPC_DATURA_BLOODROSE*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Bloodrose Datura - On gossip select - Run script'),
(@NPC_DATURA_BLOODROSE*100,9,0,0,0,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bloodrose Datura script - Remove npcflag gossip'),
(@NPC_DATURA_BLOODROSE*100,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Bloodrose Datura script - Say line'),
(@NPC_DATURA_BLOODROSE*100,9,2,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bloodrose Datura script - Set walk'),
(@NPC_DATURA_BLOODROSE*100,9,3,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,5202.604,-1317.188,242.642,0,'Bloodrose Datura script - Move to position'),
(@NPC_DATURA_BLOODROSE*100,9,4,0,0,0,100,0,2400,2400,0,0,11,51925,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bloodrose Datura script - Spellcast Throw'),
(@NPC_DATURA_BLOODROSE*100,9,5,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Bloodrose Datura script - Say line'),
(@NPC_DATURA_BLOODROSE*100,9,6,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,11,@NPC_CAPTURED_DRAKKARI_SCOUT,10,0,0,0,0,0,'Bloodrose Datura script - Set data'),
(@NPC_DATURA_BLOODROSE*100,9,7,0,0,0,100,0,19000,19000,0,0,11,51927,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bloodrose Datura script - Spellcast Death_Decay Visual'),
(@NPC_DATURA_BLOODROSE*100,9,8,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,'Bloodrose Datura script - Say line'),
(@NPC_DATURA_BLOODROSE*100,9,9,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,5203.73,-1313.077,242.767,0,'Bloodrose Datura script - Move to position'),
(@NPC_DATURA_BLOODROSE*100,9,10,0,0,0,100,0,2500,2500,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.419,'Bloodrose Datura script - Set orientation'),
(@NPC_DATURA_BLOODROSE*100,9,11,0,0,0,100,0,500,500,0,0,82,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bloodrose Datura script - Add npcflag gossip'),

(@NPC_CAPTURED_DRAKKARI_SCOUT,0,0,0,6,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captured Drakkari Scout - On death - Despawn'),
(@NPC_CAPTURED_DRAKKARI_SCOUT,0,1,2,11,0,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captured Drakkari Scout - On reset - Remove unit field bytes'),
(@NPC_CAPTURED_DRAKKARI_SCOUT,0,2,3,61,0,100,0,0,0,0,0,96,32,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captured Drakkari Scout - On reset - Remove dynamicflags'),
(@NPC_CAPTURED_DRAKKARI_SCOUT,0,3,0,61,0,100,0,0,0,0,0,28,@SPELL_IMMOLATION,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captured Drakkari Scout - On reset - Remove aura'),
(@NPC_CAPTURED_DRAKKARI_SCOUT,0,4,0,38,0,100,0,0,1,0,0,80,@NPC_CAPTURED_DRAKKARI_SCOUT*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Captured Drakkari Scout - On data set - Run script'),
(@NPC_CAPTURED_DRAKKARI_SCOUT*100,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.653,'Captured Drakkari Scout script - Set orientation'),
(@NPC_CAPTURED_DRAKKARI_SCOUT*100,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Captured Drakkari Scout script - Say line'),
(@NPC_CAPTURED_DRAKKARI_SCOUT*100,9,2,0,0,0,100,0,3600,3600,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Captured Drakkari Scout script - Say line'),
(@NPC_CAPTURED_DRAKKARI_SCOUT*100,9,3,0,0,0,100,0,3500,3500,0,0,11,43327,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captured Drakkari Scout script - Spellcast Vomit'),
(@NPC_CAPTURED_DRAKKARI_SCOUT*100,9,4,0,0,0,100,0,2500,2500,0,0,11,51929,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captured Drakkari Scout script - Spellcast Bloody Explosion (Green)'),
(@NPC_CAPTURED_DRAKKARI_SCOUT*100,9,5,0,0,0,100,0,0,0,0,0,11,51930,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captured Drakkari Scout script - Spellcast Scourge Troll Transform'),
(@NPC_CAPTURED_DRAKKARI_SCOUT*100,9,6,0,0,0,100,0,10000,10000,0,0,11,@SPELL_IMMOLATION,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captured Drakkari Scout script - Spellcast'),
(@NPC_CAPTURED_DRAKKARI_SCOUT*100,9,7,0,0,0,100,0,500,500,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captured Drakkari Scout script - Set unit field bytes'),
(@NPC_CAPTURED_DRAKKARI_SCOUT*100,9,8,0,0,0,100,0,1500,1500,0,0,95,32,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captured Drakkari Scout script - Set dynamicflags'),
(@NPC_CAPTURED_DRAKKARI_SCOUT*100,9,9,0,0,0,100,0,8000,8000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captured Drakkari Scout script - Die');
