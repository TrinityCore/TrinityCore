-- Trapping the Light Fantastic (10674) & Gather the Orbs (10859)
SET @GOB_TRAP           := 185011;	-- Multi-Spectrum Light Trap
SET @NPC_BUNNY          := 21926;   -- Multi-Spectrum Light Trap Bunny
SET @ORB_TOTEM          := 22333;   -- Orb Collecting Totem
SET @NPC_CREDIT         := 21929;   -- Trapping the Light Kill Credit Trigger
SET @NPC_ORB1           := 20635;   -- Razaani Light Orb
SET @NPC_ORB2           := 20771;   -- Razaani Light Orb - Mini
SET @SPELL_PULL         := 28337;   -- Magnetic Pull
SET @ARC_EXPLOSION      := 35426;   -- Arcane Explosion

DELETE FROM `creature_template_addon` WHERE `entry` IN (@NPC_ORB1,@NPC_ORB2);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(20635,0,0,0,4097,0,'32566'),
(20771,0,0,0,4097,0,'32566');

UPDATE `creature_template` SET `AIName`='SmartAI',`unit_flags`=unit_flags|0x02000000,`flags_extra`=130,`ScriptName`='' WHERE `entry` IN (@NPC_ORB1,@NPC_ORB2);
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (@NPC_ORB1,@NPC_ORB2);
UPDATE `creature` SET `MovementType`=0 WHERE `id`=@NPC_ORB1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_ORB1,@NPC_ORB1*100,@NPC_ORB1*101,@NPC_ORB2,@NPC_ORB2*100,@NPC_ORB2*101) AND `source_type` IN (0,9);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Alliance Version
(@NPC_ORB1,0,0,0,8,0,100,0,@SPELL_PULL,0,0,0,80,@NPC_ORB1*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Orb Bunny - On Spellhit - Start Action Script'),
(@NPC_ORB1*100,9,0,0,0,0,100,0,1000,1000,0,0,11,@ARC_EXPLOSION,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Orb Bunny - On Script - Cast Arcane Explosion'),
(@NPC_ORB1*100,9,1,0,0,0,100,0,500,500,0,0,45,1,1,0,0,0,0,19,@NPC_BUNNY,5,0,0,0,0,0, 'Orb Bunny - On Script - Cast Arcane Explosion'),
(@NPC_ORB1*100,9,2,0,0,0,100,0,0,0,0,0,41,100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Orb Bunny - On Script - Despawn'),
-- Horde Version
(@NPC_ORB1,0,1,0,38,0,100,0,0,1,30000,30000,69,1,0,0,0,0,0,19,@ORB_TOTEM,20,0,0,0,0,0, 'Light Orb - On Data Set 0 1 - Move to totem'),
(@NPC_ORB1,0,2,3,34,0,100,1,8,1,0,0,11,@ARC_EXPLOSION,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Light Orb - On point 1 reached - Cast arcane explosion'),
(@NPC_ORB1,0,3,4,61,0,100,0,0,0,0,0,33,@NPC_CREDIT,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Light Orb - On Link - Call kill credit'),
(@NPC_ORB1,0,4,0,61,0,100,0,0,0,0,0,80,@NPC_ORB1*101,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Light Orb - On Link - Start action list to display arcase explosion'),
(@NPC_ORB1*101,9,0,0,0,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Light Orb - Action 0 - Set unseen'),
(@NPC_ORB1*101,9,1,0,0,0,100,0,0,0,0,0,41,100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Light Orb - Action 1 - Despawn in 100 ms'),
-- Alliance Version
(@NPC_ORB2,0,0,0,8,0,100,0,@SPELL_PULL,0,0,0,80,@NPC_ORB2*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Orb Bunny - On Spellhit - Start Action Script'),
(@NPC_ORB2*100,9,0,0,0,0,100,0,1000,1000,0,0,11,@ARC_EXPLOSION,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Orb Bunny - On Script - Cast Arcane Explosion'),
(@NPC_ORB2*100,9,1,0,0,0,100,0,500,500,0,0,45,1,1,0,0,0,0,19,@NPC_BUNNY,5,0,0,0,0,0, 'Orb Bunny - On Script - Cast Arcane Explosion'),
(@NPC_ORB2*100,9,2,0,0,0,100,0,0,0,0,0,41,100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Orb Bunny - On Script - Despawn'),
-- Horde Version
(@NPC_ORB2,0,1,0,38,0,100,0,1,1,30000,30000,69,1,0,0,0,0,0,19,@ORB_TOTEM,20,0,0,0,0,0, 'Light Orb - On Data Set 0 1 - Move to totem'),
(@NPC_ORB2,0,2,3,34,0,100,1,8,1,0,0,11,@ARC_EXPLOSION,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Light Orb - On point 1 reached - Cast arcane explosion'),
(@NPC_ORB2,0,3,4,61,0,100,0,0,0,0,0,33,@NPC_CREDIT,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Light Orb - On Link - Call kill credit'),
(@NPC_ORB2,0,4,0,61,0,100,0,0,0,0,0,80,@NPC_ORB2*101,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Light Orb - On Link - Start action list to display arcase explosion'),
(@NPC_ORB2*101,9,0,0,0,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Light Orb - Action 0 - Set unseen'),
(@NPC_ORB2*101,9,1,0,0,0,100,0,0,0,0,0,41,100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Light Orb - Action 1 - Despawn in 100 ms');

-- Alliance Multi-Spectrum Light Trap
UPDATE `creature_template` SET `AIName`='SmartAI',`flags_extra`=130,`ScriptName`='' WHERE `entry`=@NPC_BUNNY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_BUNNY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_BUNNY,0,0,0,54,0,100,1,0,0,0,0,50,@GOB_TRAP,30000,0,0,0,0,1,0,0,0,0,0,0,0, 'Multi-Spectrum Light Trap - On spawn - Summon gob'),
(@NPC_BUNNY,0,1,0,1,0,100,1,0,0,0,0,9,0,0,0,0,0,0,15,@GOB_TRAP,0,0,0,0,0,0, 'Multi-Spectrum Light Trap - OOC - Activate gob'),
--
(@NPC_BUNNY,0,2,0,1,0,100,1,3000,3000,3000,3000,11,@SPELL_PULL,0,0,0,0,0,19,@NPC_ORB1,20,0,0,0,0,0, 'Multi-Spectrum Light Trap - OOC 3 sec - Pull Razaani Light Orb'),
(@NPC_BUNNY,0,3,0,1,0,100,1,3000,3000,3000,3000,11,@SPELL_PULL,0,0,0,0,0,19,@NPC_ORB2,20,0,0,0,0,0, 'Multi-Spectrum Light Trap - OOC 3 sec - Pull Razaani Light Orb - Mini'),
(@NPC_BUNNY,0,4,5,38,0,100,1,1,1,0,0,33,@NPC_CREDIT,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Multi-Spectrum Light Trap - On Data Set - Give Quest Credit'),
(@NPC_BUNNY,0,5,0,61,0,100,1,0,0,0,0,9,0,0,0,0,0,0,15,@GOB_TRAP,0,0,0,0,0,0, 'Link - Activate gob - Gob');

-- Horde Totem
UPDATE `creature_template` SET `AIName`='SmartAI',`flags_extra`=0,`ScriptName`='' WHERE `entry`=@ORB_TOTEM;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ORB_TOTEM;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ORB_TOTEM,0,0,1,54,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@NPC_ORB1,20,0,0,0,0,0, 'Orb collecting totem - On spawned - Set Data 0 1'),
(@ORB_TOTEM,0,1,2,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Orb collecting totem - On Link - Store invoker'),
(@ORB_TOTEM,0,2,0,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,@NPC_ORB1,20,0,0,0,0,0, 'Orb collecting totem - On Link - Send stored target list 1'),
--
(@ORB_TOTEM,0,3,4,54,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,@NPC_ORB2,20,0,0,0,0,0, 'Orb collecting totem - On spawned - Set Data 0 1'),
(@ORB_TOTEM,0,4,5,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Orb collecting totem - On Link - Store invoker'),
(@ORB_TOTEM,0,5,0,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,@NPC_ORB2,20,0,0,0,0,0, 'Orb collecting totem - On Link - Send stored target list 1');
