/*
 # Collection of Feedback-PatchFixes / 20.07.2013
 #
 # Including sql codestyle updates and check for accuracy. (one by one)
 # by FireEmerald / Thx @DDuarte for the base pull request.
 #
 # Including:
 # DB/Spell: Update: Correct Spell Power Coefficient (107.43%) for Tranquility | by lendan (@6232)
 # DB/LOS: Add: Ignore LOS for Ignite Horde Siege Engine | by dr-j (@6718)
 # DB/SmartAI: Update: Correct casted spell by Defias Rogue Wizard | by Rochet2 (@9976)
 # DB/Quest: Fix: Bloody Imp-ossible! (10924) | by Kirkhammett (@10276)
 # DB/Quest: Fix: Mistcaller Yngvar (14102) / Add missing event script and conditions. | (@3563)
 # DB/SmartAI: Update: Give quest credit for The Ring of Blood: The Final Challenge (9977) | by JunkyBulgaria (@7724)
 # DB/Waypoints: Add: Missing waypoints for Mmmrrrggglll | by Hobbilis (@9602)
 # DB/Conditions: Add: Missing conditions for Displacing Temporal Rift | by FireEmerald
*/

-- DB/Spell: Update: Correct Spell Power Coefficient (107.43%) for Tranquility | by lendan (@6232)
SET @SPELL          := 44203; -- Tranquility

UPDATE `spell_bonus_data` SET `direct_bonus` = 1.0743 WHERE `entry` = @SPELL;

-- DB/Quest: Fix: A Dire Situation (10506) | by Rohlik & Exodius (@6283)
SET @WOLF           := 20058; -- Bloodmaul Dire Wolf
SET @SPELL_INVIS    := 18950; -- Invisibility and Stealth Detection
SET @WOLF_TRIGGER   := 21176; -- Bloodmaul Dire Wolf Trigger
SET @SPELL_POWDER   := 36310; -- Rina's Diminution Powder

-- DELETE FROM `creature_ai_scripts` WHERE `creature_id` = @WOLF; 4.x removed
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = @WOLF;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @WOLF AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@WOLF, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 75, @SPELL_INVIS, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodmaul Dire Wolf - On spawn - Add Invisibility and Stealth Detection Aura on self');

DELETE FROM `event_scripts` WHERE `id` = 13584;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`) VALUES
(13584, 2, 8, @WOLF_TRIGGER);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = @SPELL_POWDER;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,@SPELL_POWDER,0,31,1,3,@WOLF,0,0,0,'', 'Rina''s Diminution Powder can be used only on Bloodmaul Dire Wolf');

-- DB/LOS: Add: Ignore LOS for Ignite Horde Siege Engine | by dr-j (@6718)
SET @IGNITE         := 32979; -- Ignite Horde Siege Engine

DELETE FROM `disables` WHERE `sourceType` = 0 AND `entry` = @IGNITE;
INSERT INTO `disables`(`sourceType`,`entry`,`flags`,`comment`) VALUES
(0,@IGNITE,64,'Ignore LOS on Ignite Horde Siege Engine');

-- DB/SmartAI: Update: Correct casted spell by Defias Rogue Wizard | by Rochet2 (@9976)
SET @WIZARD         :=   474; -- Rogue Wizard
SET @SPELL          := 13322; -- Frostbolt

UPDATE `smart_scripts` SET `action_param2`= @SPELL WHERE `entryorguid` = @WIZARD AND `source_type` = 0 AND `id` = 0 AND `link` = 0;

-- DB/Quest: Fix: Bloody Imp-ossible! (10924) | by Kirkhammett (@10276)
SET @CHASER         := 18884; -- Warp Chaser
SET @ZEPPIT         := 22484; -- Zeppit
SET @SPELL_INVIS    := 32942; -- Phasing Invisibility
SET @SPELL_CHARGE   := 37417; -- Warp Charge
SET @SPELL_BITE     := 32739; -- Venomous Bite
SET @SPELL_BLOOD    := 39244; -- Gather Warp Chaser Blood

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = @CHASER;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id` = @CHASER; 4.x removed

DELETE FROM `smart_scripts` WHERE `entryorguid` = @CHASER;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@CHASER,0,0,0,11,0,100,0,0,0,0,0,11,@SPELL_INVIS,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warp Chaser - On Spawn - Cast Phasing Invisibility'),
(@CHASER,0,1,0,0,0,100,0,500,2000,7000,15000,11,@SPELL_CHARGE,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Warp Chaser - In Combat - Cast Charge'),
(@CHASER,0,2,0,0,0,100,0,3000,5000,10000,15000,11,@SPELL_BITE,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Warp Chaser - In Combat - Cast Venomous Bite'),
(@CHASER,0,3,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,@ZEPPIT,10,0,0,0,0,0, 'Warp Chaser - On Death - Set Data on Zeppit');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = @ZEPPIT;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id` = @ZEPPIT; 4.x removed

DELETE FROM `smart_scripts` WHERE `entryorguid` = @ZEPPIT;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ZEPPIT,0,0,0,38,0,100,0,1,1,0,0,11,@SPELL_BLOOD,0,0,0,0,0,21,10,0,0,0,0,0,0, 'Zeppit - On Data Set - Cast on Master');

-- DB/Quest: Fix: Mistcaller Yngvar (14102) / Add missing event script and conditions. | (@3563)
SET @ENTRY          := 34965; -- Mistcaller Yngvar
SET @SPELL          := 66621; -- Summon the Mistcaller
SET @QUEST          := 14102; -- Mistcaller Yngvar (Quest)

DELETE FROM `event_scripts` WHERE `id` = 21997 AND `command` = 10;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(21997, 2, 10, @ENTRY, 120000, 0, 10181.96, 1183.417, 76.12115, 5.934119);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = @SPELL;
INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, comment ) VALUES
(17, 0, @SPELL, 0, 0, 29, @ENTRY, 40, 0, 1, 0, "Cant use Mistcallers Charm within 40 yards of Yngvar"),
(17, 0, @SPELL, 0, 0, 28, @QUEST, 0, 0, 1, 0, "Cant use Mistcallers Charm, if player has quest objective completed, but not yet rewarded.");

-- DB/SmartAI: Update: Give quest credit for The Ring of Blood: The Final Challenge (9977) | by JunkyBulgaria (@7724)
SET @MOGOR  := 18069; -- Mogor <Hero of the Warmaul>
SET @QUEST  :=  9977; -- The Ring of Blood: The Final Challenge

DELETE FROM `smart_scripts` WHERE `entryorguid` = @MOGOR AND `source_type` = 0 AND `id` = 14;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@MOGOR, 0, 14, 0, 6, 0, 100, 1, 0, 0, 0, 0, 15, @QUEST, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 'Mogor - On Death - Give Quest Credit');

-- DB/Waypoints: Add: Missing waypoints for Mmmrrrggglll | by Hobbilis (@9602)
SET @MURLOC         :=  15937; -- Mmmrrrggglll
SET @GUID           :=  41792;
SET @PATH           := 417920;

-- Set creature location
UPDATE `creature` SET `MovementType`=2,`position_x`=8869.872,`position_y`=-5775.960,`position_z`=0.405, `spawnDist`=0, `currentwaypoint`=1 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES (@GUID, @PATH, 1);

-- Waypoint Data
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 8880.688, -5754.608, 0.25531, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 8873.341, -5735.012, 0.43308, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 8862.790, -5722.625, 0.42263, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 8846.429, -5720.661, 0.49396, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 8836.920, -5726.737, 0.83736, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 8828.789, -5743.622, 0.82590, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 8818.041, -5755.890, 0.64673, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 8804.548, -5762.792, 0.51199, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 8791.789, -5762.271, 0.45083, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 8777.225, -5753.970, 0.55571, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 8776.860, -5738.229, 0.61609, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 8785.234, -5722.790, 0.75764, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 8786.402, -5701.790, 0.67103, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 8771.277, -5696.080, 0.67596, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 8758.604, -5694.220, 0.55669, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 8746.010, -5704.514, 0.50786, 0, 0, 0, 0, 100, 0),
(@PATH, 17, 8735.815, -5722.942, 0.94607, 0, 0, 0, 0, 100, 0),
(@PATH, 18, 8720.269, -5730.856, 0.89406, 0, 0, 0, 0, 100, 0),
(@PATH, 19, 8706.965, -5730.076, 0.77437, 0, 0, 0, 0, 100, 0),
(@PATH, 20, 8693.575, -5720.971, 0.86999, 0, 0, 0, 0, 100, 0),
(@PATH, 21, 8679.183, -5710.540, 1.10842, 0, 0, 0, 0, 100, 0),
(@PATH, 22, 8656.022, -5704.337, 1.80973, 0, 0, 0, 0, 100, 0),
(@PATH, 23, 8640.976, -5691.507, 0.47690, 0, 0, 0, 0, 100, 0),
(@PATH, 24, 8635.418, -5689.706, 0.53144, 0, 0, 0, 0, 100, 0),
(@PATH, 25, 8620.438, -5687.679, 0.86486, 0, 0, 0, 0, 100, 0),
(@PATH, 26, 8601.687, -5688.443, 0.49338, 1.930, 36000, 0, 0, 100, 0),
(@PATH, 27, 8619.985, -5679.970, 0.75128, 0, 0, 0, 0, 100, 0),
(@PATH, 28, 8635.668, -5671.577, 0.53144, 0, 0, 0, 0, 100, 0),
(@PATH, 29, 8648.297, -5670.150, 0.49488, 0, 0, 0, 0, 100, 0),
(@PATH, 30, 8664.989, -5679.421, 0.55752, 0, 0, 0, 0, 100, 0),
(@PATH, 31, 8679.183, -5710.540, 1.10842, 0, 0, 0, 0, 100, 0),
(@PATH, 32, 8693.575, -5720.971, 0.86999, 0, 0, 0, 0, 100, 0),
(@PATH, 33, 8706.965, -5730.076, 0.77437, 0, 0, 0, 0, 100, 0),
(@PATH, 34, 8721.716, -5745.012, 0.62278, 0, 0, 0, 0, 100, 0),
(@PATH, 35, 8735.529, -5753.923, 1.24721, 0, 0, 0, 0, 100, 0),
(@PATH, 36, 8767.193, -5758.179, 0.50536, 0, 0, 0, 0, 100, 0),
(@PATH, 37, 8791.789, -5762.271, 0.45083, 0, 0, 0, 0, 100, 0),
(@PATH, 38, 8804.548, -5762.792, 0.51199, 0, 0, 0, 0, 100, 0),
(@PATH, 39, 8818.041, -5755.890, 0.64673, 0, 0, 0, 0, 100, 0),
(@PATH, 40, 8828.789, -5743.622, 0.82590, 0, 0, 0, 0, 100, 0),
(@PATH, 41, 8836.920, -5726.737, 0.83736, 0, 0, 0, 0, 100, 0),
(@PATH, 42, 8846.429, -5720.661, 0.49396, 0, 0, 0, 0, 100, 0),
(@PATH, 43, 8873.341, -5735.012, 0.43308, 0, 0, 0, 0, 100, 0),
(@PATH, 44, 8880.688, -5754.608, 0.25531, 6.105, 60000, 0, 0, 100, 0);

-- DB/Conditions: Add: Missing conditions for Displacing Temporal Rift | by FireEmerald
SET @PARASITE       := 10717; -- Temporal Parasite
SET @SPELL          := 16613; -- Displacing Temporal Rift
SET @QUEST          :=  4971; -- A Matter of Time

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = @SPELL;
INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, comment ) VALUES
(17, 0, @SPELL, 0, 0, 29, @PARASITE, 100, 0, 1, 0, "Cant use Temporal Displacer within 100 yards of Temporal Parasite"),
(17, 0, @SPELL, 0, 0, 28, @QUEST, 0, 0, 1, 0, "Cant use Temporal Displacer, if player has quest objective completed, but not yet rewarded");
