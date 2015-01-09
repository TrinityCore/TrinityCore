SET @NPC := 7271;
DELETE FROM `creature_ai_scripts` WHERE creature_id=@NPC; 
UPDATE `creature_template` SET `AIName`='SmartAI', `unit_flags`=32768 WHERE `entry`=@NPC;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@NPC AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC, 0, 0, 1, 10, 0, 100, 1, 0, 10, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Witch Doctor Zum''rah - On OOC Los - Say Line 0'),
(@NPC, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Witch Doctor Zum''rah - On Link - Remove PC immunity'),
(@NPC, 0, 3, 0, 0, 0, 100, 0, 1000, 3000, 6000, 10000, 11, 12739, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Witch Doctor Zum''rah - IC - Cast Shadowbolt '),
(@NPC, 0, 4, 0, 2, 0, 100, 0, 30, 100, 30, 100, 23, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Witch Doctor Zum''rah - On mana pct above 30% - Decrement Phase'),
(@NPC, 0, 5, 0, 0, 0, 100, 0, 15, 0, 15, 0, 23, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Witch Doctor Zum''rah - On mana pct 15 - Decrement Phase'),
(@NPC, 0, 6, 0, 0, 0, 100, 0, 7000, 13000, 22000, 36000, 11, 15245, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Witch Doctor Zum''rah - IC - Cast Shadowbolt Volley'),
(@NPC, 0, 7, 0, 0, 0, 100, 0, 8000, 15000, 26000, 39000, 11, 11086, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Witch Doctor Zum''rah - IC - Cast Ward of Zum''rah '),
(@NPC, 0, 8, 0, 0, 0, 100, 0, 4000, 19000, 23000, 30000, 11, 12491, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Witch Doctor Zum''rah - IC - Cast Healing Wave'),
(@NPC, 0, 9, 10, 6, 0, 100, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Witch Doctor Zum''rah - On Death - Yell'),
(@NPC, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Witch Doctor Zum''rah - On Death - Set Phase 0'),
(@NPC, 0, 11, 0, 7, 0, 100, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Witch Doctor Zum''rah - On Evade - Set Friendly');

DELETE FROM `creature_text` WHERE `entry` =@NPC;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(@NPC, 0, 0, 'How dare you enter my sanctum!', 12, 0, 100, 0, 0, 0, 'Witch Doctor Zum''rah'),
(@NPC, 1, 0, 'T''eif godehsi wha!', 14, 14, 100, 0, 0, 0, 'Witch Doctor Zum''rah');
