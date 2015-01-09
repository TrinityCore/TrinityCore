-- Wilfred Fizzlebang SAI
SET @ENTRY := 35476;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,140000,180000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wilfred Fizzlebang - OOC - run script'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,28,45104,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wilfred Fizzlebang - Script - Remove Aura 45104"),
(@ENTRY*100,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wilfred Fizzlebang - Script - Say Line 0"),
(@ENTRY*100,9,2,0,0,0,100,0,3000,3000,0,0,5,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wilfred Fizzlebang - Script - Emote Exclamation"),
(@ENTRY*100,9,3,0,0,0,100,0,4000,4000,0,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wilfred Fizzlebang - Script - Emote Laugh"),
(@ENTRY*100,9,4,0,0,0,100,0,6000,6000,0,0,11,45104,2,0,0,0,0,1,0,0,0,0,0,0,0,"Wilfred Fizzlebang - Script - Cast 45104");

DELETE FROM `creature_ai_texts` WHERE `entry` IN (-46, -106);
INSERT INTO `creature_ai_texts` (`entry`,`content_default`,`type`,`comment`) VALUES
(-46, '%s becomes enraged!', 2, 'Enrage Text'),
(-106, '%s goes into a frenzy!', 2, 'Frenzy Text');

UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=15126, `action_param2`=0, `action_param3`=0 WHERE `entryorguid`=9707 AND `id`=0;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=16002, `action_param2`=0, `action_param3`=0 WHERE `entryorguid`=9707 AND `id`=1;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=16004, `action_param2`=0, `action_param3`=0 WHERE `entryorguid`=9707 AND `id`=2;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=16103, `action_param2`=0, `action_param3`=0 WHERE `entryorguid`=10374 AND `id`=0;
UPDATE `smart_scripts` SET `event_param1`=15000, `event_param2`=15000, `event_param3`=15000, `event_param4`=15000, `action_type`=11, `action_param1`=16104, `action_param2`=0, `action_param3`=0, `target_type`=2, `comment`= 'Spire Spider - In Combat - Cast 16104 (Normal Dungeon)' WHERE `entryorguid`=10374 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10374 AND `id` IN (2,3,4);
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=16416, `action_param2`=0, `action_param3`=0 WHERE `entryorguid`=10376 AND `id`=0;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=43806 WHERE `entryorguid`=24439 AND `id`=3;
