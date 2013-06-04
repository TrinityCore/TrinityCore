-- revised from Unholys original works
-- quest 12702 chicken party!
-- quest 12532 flown the coop!
--
SET @ENTRY := 28161; -- the chicken
SET @PARTY := 12702; -- chicken party quest
SET @COOP := 12532; -- flown the coop quest
SET @LIFE := 900000; -- minutes

-- set up required spells for the spells to work as they should
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@ENTRY;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(@ENTRY,39996,1,0), -- cover spell (dummy)
(@ENTRY,51037,2,0); -- creates item in players back pack

-- set npc up to use event script
UPDATE `creature_template` SET `AIName`='SmartAI'  WHERE `entry`=@ENTRY;

-- convert over to smart script
DELETE FROM `creature_ai_scripts` WHERE `id`=@ENTRY; -- delete old eai scripts
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,2000,3000,89,35,0,0,0,0,0,1,0,0,0,0,0,0,0, 'create random movement every 2-3 secs'),
(@ENTRY,0,1,0,8,0,100,0,51951,0,0,0,11,50839,0,0,0,0,0,1,0,0,0,0,0,0,0, 'when hit with net cast self stun'),
(@ENTRY,0,2,0,8,0,100,0,39996,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'force despawn @1 sec when hit with dummy spell');

-- Remove previous scripts that may interfere with this work
DELETE FROM `quest_start_scripts` WHERE `id` IN (@PARTY,@COOP);

-- start script for quest chicken party (they do not all spawn at same time)
UPDATE `quest_template` SET `StartScript`=@PARTY WHERE `id`=@PARTY; -- 12072
INSERT INTO `quest_start_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(@PARTY,1,10,@ENTRY,@LIFE, 0,5251.09,4413.76,-96.086,4.8714),
(@PARTY,2,10,@ENTRY,@LIFE, 0,5251.22,4419.74,-95.8995,3.58335),
(@PARTY,23,10,@ENTRY,@LIFE, 0,5257.58,4421.77,-95.9072,2.62124),
(@PARTY,4,10,@ENTRY,@LIFE,0, 5255.97,4420.37,-95.9999,0.0451326),
(@PARTY,5,10,@ENTRY,@LIFE,0, 5256.78,4420.63,-95.9957,0.320021),
(@PARTY,6,10,@ENTRY,@LIFE,0, 5257.58,4421.77,-95.9072,0.956194),
(@PARTY,27,10,@ENTRY,@LIFE,0, 5258.54,4420.49,-96.0195,0.551714),
(@PARTY,8,10,@ENTRY,@LIFE,0, 5250.67,4417.98,-95.9787,4.39231),
(@PARTY,9,10,@ENTRY,@LIFE,0, 5273.53,4430.32,-96.0241,1.0897),
(@PARTY,40,10,@ENTRY,@LIFE,0, 5158.3,4605.25,-130.988,3.7522),
(@PARTY,21,10,@ENTRY,@LIFE,0, 5164.6,4609.43,-130.427,3.70115),
(@PARTY,22,10,@ENTRY,@LIFE,0, 5169.53,4612.44,-130.817,4.05065),
(@PARTY,23,10,@ENTRY,@LIFE,0, 5188.49,4627.85,-132.485,3.60691),
(@PARTY,44,10,@ENTRY,@LIFE,0, 5203.19,4631.63,-132.611,2.849),
(@PARTY,25,10,@ENTRY,@LIFE,0, 5219.62,4632.46,-134.232,0.378917),
(@PARTY,26,10,@ENTRY,@LIFE,0, 5219.62,4632.46,-134.232,0.66166),
(@PARTY,27,10,@ENTRY,@LIFE,0, 5203.5,4595.02,-111.327,5.51542),
(@PARTY,48,10,@ENTRY,@LIFE,0, 5179.35,4558,-100.344,0.579192),
(@PARTY,29,10,@ENTRY,@LIFE,0, 5179.35,4558,-100.344,1.09756),
(@PARTY,30,10,@ENTRY,@LIFE,0, 5172.43,4533.25,-97.3836,1.15253),
(@PARTY,41,10,@ENTRY,@LIFE,0, 5186.29,4522.69,-91.0957,3.02571),
(@PARTY,32,10,@ENTRY,@LIFE,0, 5214.67,4485.22,-91.3113,2.40524),
(@PARTY,33,10,@ENTRY,@LIFE,0, 5221.85,4475.99,-96.8801,4.89495),
(@PARTY,34,10,@ENTRY,@LIFE,0, 5222.95,4438.1,-96.8062,1.6277),
(@PARTY,35,10,@ENTRY,@LIFE,0, 5224.36,4427.83,-96.9221,2.63301),
(@PARTY,36,10,@ENTRY,@LIFE,0, 5234.72,4406.44,-95.2917,0.0647549),
(@PARTY,47,10,@ENTRY,@LIFE,0, 5227.28,4407.01,-95.3888,3.79933),
(@PARTY,38,10,@ENTRY,@LIFE,0, 5227.28,4407.01,-95.3888,4.29414),
(@PARTY,39,10,@ENTRY,@LIFE,0, 5251.09,4413.76,-96.086,3.90536),
(@PARTY,40,10,@ENTRY,@LIFE,0, 5251.09,4413.76,-96.086,4.36089);

-- start script for quest flown the coop (they do not all spawn at same time)
UPDATE `quest_template` SET `StartScript`=@COOP WHERE `id`=@COOP; -- 12532
INSERT INTO `quest_start_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(@COOP,23,10,@ENTRY,@LIFE,0, 5257.58,4421.77,-95.9072,2.62124),
(@COOP,4,10,@ENTRY,@LIFE,0, 5255.97,4420.37,-95.9999,0.0451326),
(@COOP,5,10,@ENTRY,@LIFE,0, 5256.78,4420.63,-95.9957,0.320021),
(@COOP,6,10,@ENTRY,@LIFE,0, 5257.58,4421.77,-95.9072,0.956194),
(@COOP,27,10,@ENTRY,@LIFE,0, 5258.54,4420.49,-96.0195,0.551714),
(@COOP,8,10,@ENTRY,@LIFE,0, 5250.67,4417.98,-95.9787,4.39231),
(@COOP,9,10,@ENTRY,@LIFE,0, 5273.53,4430.32,-96.0241,1.0897),
(@COOP,40,10,@ENTRY,@LIFE,0, 5158.3,4605.25,-130.988,3.7522),
(@COOP,21,10,@ENTRY,@LIFE,0, 5164.6,4609.43,-130.427,3.70115),
(@COOP,22,10,@ENTRY,@LIFE,0, 5169.53,4612.44,-130.817,4.05065),
(@COOP,23,10,@ENTRY,@LIFE,0, 5188.49,4627.85,-132.485,3.60691),
(@COOP,44,10,@ENTRY,@LIFE,0, 5203.19,4631.63,-132.611,2.849),
(@COOP,25,10,@ENTRY,@LIFE,0, 5219.62,4632.46,-134.232,0.378917),
(@COOP,26,10,@ENTRY,@LIFE,0, 5219.62,4632.46,-134.232,0.66166),
(@COOP,27,10,@ENTRY,@LIFE,0, 5203.5,4595.02,-111.327,5.51542),
(@COOP,48,10,@ENTRY,@LIFE,0, 5179.35,4558,-100.344,0.579192),
(@COOP,29,10,@ENTRY,@LIFE,0, 5179.35,4558,-100.344,1.09756),
(@COOP,30,10,@ENTRY,@LIFE,0, 5172.43,4533.25,-97.3836,1.15253),
(@COOP,41,10,@ENTRY,@LIFE,0, 5186.29,4522.69,-91.0957,3.02571),
(@COOP,32,10,@ENTRY,@LIFE,0, 5214.67,4485.22,-91.3113,2.40524),
(@COOP,33,10,@ENTRY,@LIFE,0, 5221.85,4475.99,-96.8801,4.89495),
(@COOP,34,10,@ENTRY,@LIFE,0, 5222.95,4438.1,-96.8062,1.6277),
(@COOP,35,10,@ENTRY,@LIFE,0, 5224.36,4427.83,-96.9221,2.63301),
(@COOP,36,10,@ENTRY,@LIFE,0, 5234.72,4406.44,-95.2917,0.0647549),
(@COOP,47,10,@ENTRY,@LIFE,0, 5227.28,4407.01,-95.3888,3.79933),
(@COOP,38,10,@ENTRY,@LIFE,0, 5227.28,4407.01,-95.3888,4.29414),
(@COOP,39,10,@ENTRY,@LIFE,0, 5251.09,4413.76,-96.086,3.90536),
(@COOP,40,10,@ENTRY,@LIFE,0, 5251.09,4413.76,-96.086,4.36089);
