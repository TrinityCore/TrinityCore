/*
21:33:55.992 -- der alptraum wandelt sich
21:33:56.834 -- reaper despawn
21:33:58.441 -- spawn ripsnarl and vanessa

21:34:00.656 -- ripsnarl wasnt always
21:34:07.895 -- his name was james harrington
21:34:12.497 -- cancel nightmare aura
21:34:12.699 -- announce nightmare
21:34:12.887 -- open door


21:34:14.899 -- vanessa casts adrenaline
21:34:15.227 -- despawn vanessa and ripsnarl

21:34:12.887 -- spawn emme harrington
21:34:12.887 -- emme casts group taunt 
21:34:24.524 -- group taunt 2


21:34:16.303 -- rette emme harrington

21:34:35.164 -- emme casts adrenaline
21:34:35.164 -- despawn emme

21:34:39.173 -- announce save erik
21:34:40.982 -- spawn worgen and erik
21:34:59.625 -- erik despawn

21:34:59.827 -- spawn calissa
21:35:03.259 -- announce save

21:35:15.287 -- james, please, I love you
21:35:16.504

21:35:24.897 -- announce calissa dies

21:35:27.190 -- ripsnarl death
21:35:27.096 -- cancel nightmare elixir
21:35:27.346 -- announce

21:35:29.530 -- despawn both

21:35:31.527 -- spawn boss
*/


-- Template Updates
-- Vanessa VanCleef
UPDATE `creature_template` SET `ScriptName`= 'boss_vanessa_van_cleef', `DamageModifier`= 121.2, `mechanic_immune_mask`= 617299839, `mingold`= 19000, `maxgold`= 20000 WHERE `entry`= 49541;
-- Vanessa VanCleef (Intro)
UPDATE `creature_template` SET `ScriptName`= 'npc_vanessa_vanessa_van_cleef' WHERE `entry`= 49429;
-- A Note from Vanessa
UPDATE `creature_template` SET `gossip_menu_id`= 12504, `ScriptName`= 'npc_vanessa_note_from_vanessa' WHERE `entry`= 49564;
-- Magma Trap creatures
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry` IN (49454, 51624);
-- Vanessa's Trap Bunny
UPDATE `creature_template` SET `ScriptName`= 'npc_deadmines_vanessas_trap_bunny' WHERE `entry`= 49454;
-- Steam Valve
UPDATE `creature_template` SET `npcflag`= 16777216, `ScriptName`= 'npc_deadmines_steam_valve' WHERE `entry`= 49457;
-- Vanessa VanCleef Nightmare
UPDATE `creature_template` SET `ScriptName`= 'npc_deadmines_vanessa_van_cleef_nightmare' WHERE `entry`= 49671;
-- Glubtok Nightmare Fire Bunny
UPDATE `creature_template` SET `flags_extra`= 131 WHERE `entry`= 51594;
-- Collapsing Icicle
UPDATE `creature_template` SET `unit_flags`= 33587200, `flags_extra`= 131 WHERE `entry` IN (49481, 57866);
-- Glubtok Nightmare Illusion
UPDATE `creature_template` SET `ScriptName`= '' WHERE `entry`= 49670;
-- Helix Gearbreaker Illusion
UPDATE `creature_template` SET `unit_flags`= 33600, `DamageModifier`= 10, `mechanic_immune_mask`= 617299839, `ScriptName`= 'npc_deadmines_helix_nightmare' WHERE `entry`= 49674;
-- Lightning Platters
UPDATE `creature_template` SET `InhabitType`= 4, `flags_extra`= 128 WHERE `entry` IN (49520, 49521);
-- Foe Reaper 5000 Illusion
UPDATE `creature_template` SET `DamageModifier`= 42.2, `mechanic_immune_mask`= 617299839 WHERE `entry` = 49681;
-- James Harrington
UPDATE `creature_template` SET `VehicleId`= 1403 WHERE `entry`= 49539;
-- Enraged Worgen
UPDATE `creature_template` SET `DamageModifier`= 35 WHERE `entry`= 49532;


-- Template Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (49564, 51594, 49671, 49670, 92201);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `auras`) VALUES
(49564, 0, '92376'),
(51594, 0, '92169'),
(49671, 0, '48143'),
(49670, 0, '48143 69676');

UPDATE `creature_template_addon` SET `auras`= '94557' WHERE `entry`= 49457;

-- Remove encounter related spawns
DELETE FROM `creature` WHERE `guid` IN (376214, 376211, 376215, 376213);

-- Gossip
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=12504 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`) VALUES
(12504, 0, 0, 'Continue reading... <Note: This will alert Vanessa to your presence!>', 49641, 1, 1, 12505);

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (49429, 49564, 49454, 49671, 49674, 49539, 49536, 49541);
DELETE FROM `creature_text` WHERE `CreatureID`= 45979 AND `GroupID` NOT IN (0, 1, 2, 3);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES
-- Vanessa VanCleef Intro
(49429, 0, 0, 'You hear a noise from above the cabin door!', 41, 0, 100, 0, 0, 0, 49476, 'Vanessa van Cleef to Player'),
(49429, 1, 0, 'I''ve been waiting a long time for this, you know.', 12, 0, 100, 1, 0, 24613, 49477, 'Vanessa van Cleef to Player'),
(49429, 2, 0, 'Biding my time, building my forces, studying the minds of my enemies.', 12, 0, 100, 1, 0, 24614, 49478, 'Vanessa van Cleef to Player'),
(49429, 3, 0, 'I was never very good at hand-to-hand combat, you know.  Not like my father.', 12, 0, 100, 1, 0, 24615, 49479, 'Vanessa van Cleef to Player'),
(49429, 4, 0, 'But I always excelled at poisons.', 12, 0, 100, 1, 0, 24616, 49480, 'Vanessa van Cleef to Player'),
(49429, 5, 0, 'Especially venoms that affect the mind.', 12, 0, 100, 1, 0, 24617, 49481, 'Vanessa van Cleef to Player'),
(49429, 6, 0, 'Vanessa injects you with the Nightmare Elixir!', 41, 0, 100, 0, 0, 0, 49483, 'Vanessa van Cleef to Player'),
-- A Note from Vanessa VanCleef
(49564, 0, 0, 'A note falls to the floor!', 41, 0, 100, 0, 0, 0, 49658, 'A Note from Vanessa to Player'),
-- Vanessa's Trap Bunny
(49454, 0, 0, 'Activate the steam valves to free yourself!', 41, 0, 100, 0, 0, 0, 49680, 'Vanessa''s Trap Bunny to Player'),
-- General Purpose Bunny JMF
(45979, 4, 0, 'The Nightmare Elixir takes hold!', 41, 0, 100, 0, 0, 0, 49705, 'General Purpose Bunny JMF to Steam Valve'),
(45979, 5, 0, 'The nightmare shifts!', 41, 0, 100, 0, 0, 0, 49707, 'General Purpose Bunny JMF to Player'),
(45979, 6, 0, 'Save Emme Harrington!', 41, 0, 100, 0, 0, 0, 49711, 'General Purpose Bunny JMF to Player'),
(45979, 7, 0, 'Save Erik Harrington!', 41, 0, 100, 0, 0, 0, 49712, 'General Purpose Bunny JMF'),
(45979, 8, 0, 'Save Calissa Harrington!', 41, 0, 100, 0, 0, 0, 49713, 'General Purpose Bunny JMF'),
(45979, 9, 0, 'The Nightmare Elixir wears off!', 41, 0, 100, 0, 0, 0, 49714, 'General Purpose Bunny JMF'),
-- Helix Gearbreaker
(49674, 0, 0, 'You have entered Helix''s nightmare!', 41, 0, 100, 0, 0, 0, 49708, 'Helix Gearbreaker to Player'),
(49674, 1, 0, 'Nightmare spiders appear in the darkness!  Kill Helix before his nightmare overwhelms you!', 41, 0, 100, 0, 0, 0, 50871, 'Helix Geabreaker to Player'),
-- James Harrington
(49539, 0, 0, 'Calissa...I am so sorry...', 12, 0, 100, 0, 0, 0, 49761, 'James Harrington'),
-- Calissa Harrington
(49536, 0, 0, 'James...please...I love you...', 12, 0, 100, 0, 0, 0, 49762, 'Calissa Harrington'),
(49536, 1, 0, 'Calissa is dying!', 41, 0, 100, 0, 0, 0, 49763, 'Calissa Harrington'),
-- Vanessa VanCleef Nightmare
(49671, 0, 0, 'Poor Glubtok.  When his powers manifested, his own ogre mound was the first to burn.', 12, 0, 100, 1, 0, 24602, 49715, 'Vanessa van Cleef to Steam Valve'),
(49671, 1, 0, 'Deep within his soul, the one thing he feared most of all was...himself.', 12, 0, 100, 1, 0, 24603, 49716, 'Vanessa van Cleef to Steam Valve'),
(49671, 2, 0, 'You have entered Glubtok''s Nightmare!', 41, 0, 100, 0, 0, 0, 49706, 'Vanessa van Cleef to Steam Valve'),
(49671, 3, 0, 'Get back to the ship!', 41, 0, 100, 0, 0, 0, 50703, 'Vanessa van Cleef to Steam Valve'),
(49671, 4, 0, 'Most rogues prefer to cloak themselves in the shadows, but not Helix.', 12, 0, 100, 1, 0, 24604, 49723, 'Vanessa van Cleef to Player'),
(49671, 5, 0, 'You never know what skitters in the darkness.', 12, 0, 100, 1, 0, 24605, 49724, 'Vanessa van Cleef to Player'),
(49671, 6, 0, 'Can you imagine the life of a machine?', 12, 0, 100, 1, 0, 24606, 49725, 'Vanessa van Cleef to Player'),
(49671, 7, 0, 'A simple spark can mean the difference between life...and death.', 12, 0, 100, 1, 0, 24607, 49726, 'Vanessa van Cleef to Player'),
(49671, 8, 0, 'You have entered the mechanical nightmare!', 41, 0, 100, 0, 0, 0, 49709, 'Vanessa van Cleef to Player'),
(49671, 9, 0, 'Ripsnarl wasn''t always a bloodthirsty savage.  Once, he even had a family.', 12, 0, 100, 1, 0, 24608, 49742, 'Vanessa van Cleef to Player'),
(49671, 10, 0, 'He was called James Harrington.  A tragedy in three parts.', 12, 0, 100, 1, 0, 24609, 49745, 'Vanessa van Cleef to Player'),
(49671, 11, 0, 'You have entered Ripsnarl''s nightmare!', 41, 0, 100, 0, 0, 0, 49710, 'Vanessa van Cleef to Player'),
-- Vanessa VanCleef
(49541, 0, 0, 'I will not share my father''s fate!  Your tale ends here!', 14, 0, 100, 0, 0, 24599, 49748, 'Vanessa van Cleef to Player'),
(49541, 1, 0, 'The first of many.', 14, 0, 100, 0, 0, 24620, 49749, 'Vanessa van Cleef'),
(49541, 2, 0, 'Did you really think I would come to this fight alone?', 14, 0, 100, 0, 0, 24620, 49750, 'Vanessa van Cleef'),
(49541, 3, 0, 'Fools!  This entire ship is rigged with explosives!  Enjoy your fiery deaths!', 14, 0, 100, 0, 0, 24621, 49751, 'Vanessa van Cleef'),
(49541, 4, 0, 'Vanessa has detonated charges on the ship!  Get to the ropes at the side of the boat!', 41, 0, 100, 0, 0, 0, 49755, 'Vanessa van Cleef'),
(49541, 5, 0, 'You didn''t honestly think I would only plant ONE set of explosives, did you?', 14, 0, 100, 0, 0, 24622, 50706, 'Vanessa van Cleef'),
(49541, 6, 0, 'Vanessa is detonating more charges!  Get to the ropes at the side of the boat!', 41, 0, 100, 0, 0, 0, 49756, 'Vanessa van Cleef'),
(49541, 7, 0, 'ENOUGH!  I will not give you the pleasure!', 14, 0, 100, 274, 0, 24610, 49753, 'Vanessa van Cleef'),
(49541, 8, 0, 'If I''m going to die, I''m taking you all with me!', 14, 0, 100, 15, 0, 24611, 49752, 'Vanessa van Cleef'),
(49541, 9, 0, 'Vanessa pulls out a final barrel of mining powder and ignites it!  RUN!', 41, 0, 100, 0, 0, 0, 49757, 'Vanessa van Cleef'),
(49541, 10, 0, 'MY FATE IS MY OWN!', 14, 0, 100, 397, 0, 24612, 49754, 'Vanessa van Cleef');
UPDATE `creature_text` SET `TextRange`= 3 WHERE `CreatureID` IN (45979, 49539, 49536);


UPDATE `creature_template` SET `npcflag`= 16777216 WHERE `entry`= 49520;

-- Vehicle Acessory
DELETE FROM `vehicle_template_accessory` WHERE `entry`= 49520;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(49520, 49521, 7, 1, 'Vanessa Lightning Platter - Vanessa Lightning Stalker', 5, 0), -- Vanessa Lightning Platter - Vanessa Lightning Stalker
(49520, 49521, 6, 1, 'Vanessa Lightning Platter - Vanessa Lightning Stalker', 5, 0), -- Vanessa Lightning Platter - Vanessa Lightning Stalker
(49520, 49521, 5, 1, 'Vanessa Lightning Platter - Vanessa Lightning Stalker', 5, 0), -- Vanessa Lightning Platter - Vanessa Lightning Stalker
(49520, 49521, 4, 1, 'Vanessa Lightning Platter - Vanessa Lightning Stalker', 5, 0), -- Vanessa Lightning Platter - Vanessa Lightning Stalker
(49520, 49521, 3, 1, 'Vanessa Lightning Platter - Vanessa Lightning Stalker', 5, 0), -- Vanessa Lightning Platter - Vanessa Lightning Stalker
(49520, 49521, 2, 1, 'Vanessa Lightning Platter - Vanessa Lightning Stalker', 5, 0), -- Vanessa Lightning Platter - Vanessa Lightning Stalker
(49520, 49521, 1, 1, 'Vanessa Lightning Platter - Vanessa Lightning Stalker', 5, 0), -- Vanessa Lightning Platter - Vanessa Lightning Stalker
(49520, 49521, 0, 1, 'Vanessa Lightning Platter - Vanessa Lightning Stalker', 5, 0); -- Vanessa Lightning Platter - Vanessa Lightning Stalker

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_deadmines_ride_magma_vehicle',
'spell_deadmines_magma_trap_throw_to_location');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(92378, 'spell_deadmines_ride_magma_vehicle'),
(92438, 'spell_deadmines_magma_trap_throw_to_location');

-- Spellclick spells
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (49457);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
-- Steam Valve
(49457, 92399, 0, 0);

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (92379) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 92379, 0, 0, 31, 0, 3, 49454, 0, 0, 0, '', 'Ride Magma Vehicle - Vanessa''s Trap Bunny');

-- Creature Collapsing Icicle 49481 SAI
SET @ENTRY := 49481;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 3, 0, 28470, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Morph to model 28470 // "),
(@ENTRY, 0, 1, 2, 60, 0, 100, 1, 3200, 3200, 0, 0, 11, 92201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 3200 and 3200 ms) - Self: Cast spell Icicle (92201) on Self // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 92202, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell Icicle (92202) on Self // ");

-- Creature Emme Harrington 49534 SAI
SET @ENTRY := 49534;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 100, 100, 5000, 5000, 11, 92308, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 5000 and 5000 ms (for the first time, timer between 100 and 100 ms) - Self: Cast spell Group Taunt (92308) on Self // ");

-- Creature Erik Harrington 49535 SAI
SET @ENTRY := 49535;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 100, 100, 5000, 5000, 11, 92308, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 5000 and 5000 ms (for the first time, timer between 100 and 100 ms) - Self: Cast spell Group Taunt (92308) on Self // ");

-- Creature Calissa Harrington 49536 SAI
SET @ENTRY := 49536;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 15400, 15400, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 15400 and 15400 ms) - Self: Talk 0 // "),
(@ENTRY, 0, 1, 0, 60, 0, 100, 1, 25000, 25000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 25000 and 25000 ms) - Self: Talk 1 // "),
(@ENTRY, 0, 2, 0, 60, 0, 100, 1, 16700, 16700, 0, 0, 1, 0, 0, 0, 0, 0, 0, 11, 49539, 10, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 16700 and 16700 ms) - Creature James Harrington (49539) in 10 yd: Talk 0 // ");

-- Creature Glubtok 49670 SAI
SET @ENTRY := 49670;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 4500, 4500, 3600, 3600, 11, 59304, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 4500 and 4500 ms (and later repeats every 3600 and 3600 ms) - Self: Cast spell Spirit Strike (59304) on Victim // ");

-- Creature Foe Reaper 5000 49681 SAI
SET @ENTRY := 49681;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 2600, 2600, 3600, 3600, 11, 59304, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2600 and 2600 ms (and later repeats every 3600 and 3600 ms) - Self: Cast spell Spirit Strike (59304) on Victim // ");

