-- Missing Content Tuning Id from beer kegs in Coldridge Valley
UPDATE `gameobject_template` SET `ContentTuningId`=1477 WHERE `entry` IN (201609,201610,201611);

-- Gossip missing for flight master
DELETE FROM `gossip_menu` WHERE `MenuID`=11777;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(11777, 16509, 53007); -- 43701
DELETE FROM `gossip_menu_option` WHERE `MenuID`=11777;
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(11777, 38309, 0, 2, 'Show me where I can fly.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 53007);

-- Proper quest starter exist
DELETE FROM `creature_queststarter` WHERE `id`=1377 AND `quest`=313;

-- Quest Forced to Watch from Afar

-- Remove db spawn of temp Remote Observation Bot
DELETE FROM `creature` WHERE `guid`=305498; 

-- Captain Tharran smart ai
SET @ENTRY := 40950;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 19, 0, 100, 0, 313, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Forced to Watch from Afar (313) - Self: Talk 0 to invoker');

-- Mountaineer Dunstan smart ai
SET @ENTRY := 40991;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (4099100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 1, '', 62, 0, 100, 0, 11455, 0, 0, 0, 78, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action Captain Tharran wants you... (0) from menu 11455 selected - Self: Call OnReset() event'),
(@ENTRY, 0, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 80, 4099100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action Captain Tharran wants you... (0) from menu 11455 selected - Self: Start timed action list id #Mountaineer Dunstan #0 (4099100) (update out of combat) // -inline'),
(@ENTRY * 100, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 11, 76702, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell  Mountaineer Dunstan Credit (76702) on Last action invoker'),
(@ENTRY * 100, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Last action invoker: Close gossip'),
(@ENTRY * 100, 9, 2, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Talk 0 to invoker'),
(@ENTRY * 100, 9, 3, 0, '', 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to STATE_USESTANDING (69)'),
(@ENTRY * 100, 9, 4, 0, '', 0, 0, 100, 0, 3000, 3000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Set emote state to 0'),
(@ENTRY * 100, 9, 5, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 12, 41052, 3, 13000, 0, 0, 0, 8, 0, 0, 0, -5476.73, -227.271, 354.411, 1.53265, 'After 0 seconds - Self: Summon creature Remote Observation Bot (41052) at (-5476.73, -227.271, 354.411, 1.53265) as summon type timed despawn with duration 13 seconds');

-- Mountaineer Lewin smart ai
SET @ENTRY := 40994;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (4099400);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 1, '', 62, 0, 100, 0, 11456, 0, 0, 0, 78, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action Captain Tharran wants you... (0) from menu 11456 selected - Self: Call OnReset() event'),
(@ENTRY, 0, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 80, 4099400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action Captain Tharran wants you... (0) from menu 11456 selected - Self: Start timed action list id #Mountaineer Lewin #0 (4099400) (update out of combat) // -inline'),
(@ENTRY * 100, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 11, 76704, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell  Mountaineer Lewin Credit (76704) on Last action invoker'),
(@ENTRY * 100, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Last action invoker: Close gossip'),
(@ENTRY * 100, 9, 2, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Talk 0 to invoker'),
(@ENTRY * 100, 9, 3, 0, '', 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to STATE_USESTANDING (69)'),
(@ENTRY * 100, 9, 4, 0, '', 0, 0, 100, 0, 3000, 3000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Set emote state to 0'),
(@ENTRY * 100, 9, 5, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 12, 41052, 3, 13000, 0, 0, 0, 8, 0, 0, 0, -5501.69, -273.946, 354.217, 4.96495, 'After 0 seconds - Self: Summon creature Remote Observation Bot (41052) at (-5501.69, -273.946, 354.217, 4.96495) as summon type timed despawn with duration 13 seconds');

-- Mountaineer Valgrum smart ai
SET @ENTRY := 41056;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (4105600);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 1, '', 62, 0, 100, 0, 11457, 0, 0, 0, 78, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action Captain Tharran wants you... (0) from menu 11457 selected - Self: Call OnReset() event'),
(@ENTRY, 0, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 80, 4105600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action Captain Tharran wants you... (0) from menu 11457 selected - Self: Start timed action list id #Mountaineer Valgrum #0 (4105600) (update out of combat) // -inline'),
(@ENTRY * 100, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 11, 76705, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell  Mountaineer Valgrum Credit (76705) on Last action invoker'),
(@ENTRY * 100, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Last action invoker: Close gossip'),
(@ENTRY * 100, 9, 2, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Talk 0 to invoker'),
(@ENTRY * 100, 9, 3, 0, '', 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set emote state to STATE_USESTANDING (69)'),
(@ENTRY * 100, 9, 4, 0, '', 0, 0, 100, 0, 3000, 3000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Set emote state to 0'),
(@ENTRY * 100, 9, 5, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 12, 41052, 3, 13000, 0, 0, 0, 8, 0, 0, 0, -5389, -277.311, 363.067, 0.75923, 'After 0 seconds - Self: Summon creature Remote Observation Bot (41052) at (-5389, -277.311, 363.067, 0.75923) as summon type timed despawn with duration 13 seconds');

-- Remote Observation Bot smart ai
SET @ENTRY := 41052;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 1, 0, 100, 0, 9000, 9000, 9000, 9000, 89, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 9 seconds (OOC) - Self: Move randomly in radius 5 yards');

UPDATE `gossip_menu_option` SET `GossipOptionID`=37802 WHERE `MenuID`=11455;
UPDATE `gossip_menu_option` SET `GossipOptionID`=37803 WHERE `MenuID`=11456;
UPDATE `gossip_menu_option` SET `GossipOptionID`=37551 WHERE `MenuID`=11457;

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (76702,76704,76705);
INSERT INTO `serverside_spell_effect` (`SpellID`,`Effect`,`EffectMiscValue1`,`ImplicitTarget1`) VALUES
(76702,134,40991,25),
(76704,134,40994,25),
(76705,134,41056,25);

DELETE FROM `creature_text` WHERE `CreatureID` IN (40950,40991,40994,41056);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(40950, 0, 0, 'There\'s no substitute for live observers, but I need those mountaineers here. We\'ll have to rely on those little gnomish observer bots for now...', 12, 0, 100, 6, 0, 0, 43522, 0, 'Captain Tharran to Player'),
(40991, 0, 0, 'Tell Captain Tharran that I\'ll be back in Kharanos as soon as I\'ve verified that the bot is working correctly.', 12, 0, 100, 66, 0, 0, 41005, 0, 'Mountaineer Dunstan to Player'),
(40994, 0, 0, 'I can\'t wait to get out there and help in the fight against those trolls.', 12, 0, 100, 66, 0, 0, 41006, 0, 'Mountaineer Lewin to Player'),
(41056, 0, 0, 'We\'ve been fighting nonstop since the cataclysm. It\'ll be nice to get a rest, if a brief one.', 12, 0, 100, 66, 0, 0, 41008, 0, 'Mountaineer Valgrum to Player');

-- Objects should only be lootable if player has quest
UPDATE `gameobject_template_addon` SET `flags` = 4 WHERE `entry` IN (203129, 203130);

-- Condition for source Gossip menu option condition type Quest objective complete
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (11455,11456,11457) AND `SourceEntry`=0 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 11455, 0, 0, 0, 47, 0, 313, 10, 0, 0, 0, 0, '', 'Show gossip menu 11455 option id 0 if quest Forced to Watch from Afar in progress | complete.'),
(15, 11456, 0, 0, 0, 47, 0, 313, 10, 0, 0, 0, 0, '', 'Show gossip menu 11455 option id 0 if quest Forced to Watch from Afar in progress | complete.'),
(15, 11457, 0, 0, 0, 47, 0, 313, 10, 0, 0, 0, 0, '', 'Show gossip menu 11455 option id 0 if quest Forced to Watch from Afar in progress | complete.');

-- Operation Recombobulation quest

-- Loot for Frostmane Scavenger
SET @ID := 41146;
UPDATE `creature_template_difficulty` SET `LootID`=@ID, GoldMin=10, GoldMax=40 WHERE `Entry` IN (@ID);
DELETE FROM `creature_loot_template` WHERE `Entry` IN (@ID);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ID,3084,0,100,1,1,0,1,1,'Frostmane Scavenger - Gyromechanic Gear');

-- Pushing forward quest

-- Kharanos Mountaineer missing aura
UPDATE `creature_template_addon` SET `auras`='77311' WHERE `entry`=41237;

-- Condition for source Spell implicit target condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=77314 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 77314, 0, 0, 31, 0, 3, 41202, 0, 0, 0, 0, '', 'Spell Burn Constriction Totem (effect 0) will hit the potential target of the spell if target is unit Constriction Totem.');

-- Replace 79 Young Wendigo and Wendigo spawns with 39 spawns reusing the fist 39 guids In front of and in The Grizzed Den.
DELETE FROM `creature` WHERE `id` in (40940,40941);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(306015, 40940, 0, 1, 136, '0', 0, 0, 0, 0, -5680.0712890625, -308.63714599609375, 367.446533203125, 2.835796356201171875, 120, 0, 0, 1, 0, 2, NULL, NULL, NULL, NULL, 53007),
(306016, 40940, 0, 1, 136, '0', 0, 0, 0, 0, -5675.12841796875, -298.0225830078125, 369.583770751953125, 2.860849618911743164, 120, 7, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(306017, 40940, 0, 1, 136, '0', 0, 0, 0, 0, -5727.23974609375, -271.7413330078125, 357.255615234375, 3.631609916687011718, 120, 15, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(306018, 40940, 0, 1, 136, '0', 0, 0, 0, 0, -5690.861328125, -277.526031494140625, 363.99627685546875, 6.096832275390625, 120, 15, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(306019, 40940, 0, 1, 136, '0', 0, 0, 0, 0, -5684.6787109375, -355.8038330078125, 368.884674072265625, 4.836206912994384765, 120, 15, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(306023, 40940, 0, 1, 136, '0', 0, 0, 0, 0, -5716.40478515625, -368.21527099609375, 365.363525390625, 0.006283469963818788, 120, 15, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(306026, 40940, 0, 1, 136, '0', 0, 0, 0, 0, -5707.01220703125, -341.805572509765625, 365.659912109375, 5.42330789566040039, 120, 15, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(306028, 40940, 0, 1, 136, '0', 0, 0, 0, 0, -5718.80224609375, -321.755218505859375, 364.340301513671875, 3.445452451705932617, 120, 15, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(306029, 40940, 0, 1, 136, '0', 0, 0, 0, 0, -5747.73095703125, -309.43402099609375, 360.325714111328125, 1.030947446823120117, 120, 15, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(306030, 40940, 0, 1, 136, '0', 0, 0, 0, 0, -5747.830078125, -339.876739501953125, 365.01165771484375, 5.869902610778808593, 120, 7, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(306031, 40940, 0, 1, 136, '0', 0, 0, 0, 0, -5756.50537109375, -277.4132080078125, 356.9256591796875, 1.792140364646911621, 120, 15, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(306070, 40940, 0, 1, 136, '0', 0, 0, 0, 0, -5759.98291015625, -247.345489501953125, 354.08697509765625, 2.757476806640625, 120, 15, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(306073, 40940, 0, 1, 136, '0', 0, 0, 0, 0, -5699.4150390625, -226.69097900390625, 361.1861572265625, 5.83659982681274414, 120, 15, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(306076, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5651.12841796875, -284.486114501953125, 371.81982421875, 5.271619319915771484, 120, 8, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(306077, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5631.90283203125, -274.0850830078125, 368.600372314453125, 1.588249564170837402, 120, 8, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(306078, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5607.939453125, -270.25347900390625, 368.22760009765625, 4.697319507598876953, 120, 5, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(306086, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5578.63525390625, -298.96527099609375, 364.9268798828125, 3.515988111495971679, 120, 5, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(306124, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5577.56591796875, -279.357635498046875, 366.074005126953125, 0.923526406288146972, 120, 0, 0, 1, 0, 2, NULL, NULL, NULL, NULL, 53007),
(306126, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5541.48291015625, -234.78125, 359.494964599609375, 0, 120, 2, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(306128, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5490.65625, -219.274307250976562, 354.34295654296875, 5.158249855041503906, 120, 5, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(306237, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5490.38916015625, -245.670135498046875, 354.15875244140625, 3.528468608856201171, 120, 4, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(306240, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5527.85595703125, -221.942703247070312, 355.1053466796875, 6.175639152526855468, 120, 0, 0, 1, 0, 2, NULL, NULL, NULL, NULL, 53007),
(306243, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5446.60791015625, -272.927093505859375, 356.325439453125, 6.1741180419921875, 120, 0, 0, 1, 0, 2, NULL, NULL, NULL, NULL, 53007),
(306246, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5418.09033203125, -264.9444580078125, 361.328887939453125, 3.420845270156860351, 120, 8, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(304427, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5491.94287109375, -288.916656494140625, 353.36749267578125, 1.593692779541015625, 120, 8, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(304431, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5506.892578125, -318.529510498046875, 352.37152099609375, 4.632875919342041015, 120, 2, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(304432, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5423.88037109375, -297.06597900390625, 357.8558349609375, 2.70088505744934082, 120, 5, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(304433, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5378.580078125, -278.40972900390625, 358.72406005859375, 4.694935798645019531, 120, 3, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(304434, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5362.470703125, -254.371536254882812, 361.23260498046875, 2.36943817138671875, 120, 8, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(304441, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5400.1650390625, -183.338546752929687, 370.2523193359375, 4.847203254699707031, 120, 5, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(305428, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5410.1005859375, -190.368057250976562, 371.396331787109375, 3.8939208984375, 120, 0, 0, 1, 0, 2, NULL, NULL, NULL, NULL, 53007),
(305430, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5377.564453125, -213.854171752929687, 359.936614990234375, 2.247099876403808593, 120, 0, 0, 1, 0, 2, NULL, NULL, NULL, NULL, 53007),
(305497, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5392.06591796875, -169.041671752929687, 369.462982177734375, 1.522531986236572265, 120, 0, 0, 1, 0, 2, NULL, NULL, NULL, NULL, 53007),
(305520, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5433.88916015625, -168.380203247070312, 351.2913818359375, 0, 120, 6, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(305523, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5434.125, -154.703125, 351.75396728515625, 1.503861665725708007, 120, 0, 0, 1, 0, 2, NULL, NULL, NULL, NULL, 53007),
(305527, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5449.26416015625, -99.171875, 346.910186767578125, 2.600540637969970703, 120, 8, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(305529, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5457.2880859375, -144.657989501953125, 346.910186767578125, 3.465970754623413085, 120, 8, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(305530, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5481.015625, -156.439239501953125, 346.910186767578125, 5.968484878540039062, 120, 8, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007),
(305536, 40941, 0, 1, 136, '0', 0, 0, 0, 0, -5483.15966796875, -114.387153625488281, 346.91015625, 5.964405059814453125, 120, 8, 0, 1, 0, 1, NULL, NULL, NULL, NULL, 53007);

-- Pathing for Young Wendigo Entry: 40940
SET @NPC := 306015;
SET @PATH := 40940 * 100 + 0;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`PathId`,`mount`,`StandState`,`SheathState`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,0,0,'Young Wendigo The Grizzed Den');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-5697.691,-303.08682,364.62872,NULL,0),
(@PATH,2,-5716.6284,-296.92014,360.31097,NULL,0),
(@PATH,3,-5735.0454,-294.67535,358.94733,NULL,0),
(@PATH,4,-5754.068,-291.12326,359.4975,NULL,0),
(@PATH,5,-5783.389,-279.99652,356.82654,NULL,0),
(@PATH,6,-5754.068,-291.12326,359.4975,NULL,0),
(@PATH,7,-5735.0454,-294.67535,358.94733,NULL,0),
(@PATH,8,-5716.6284,-296.92014,360.31097,NULL,0),
(@PATH,9,-5697.691,-303.08682,364.62872,NULL,0),
(@PATH,10,-5683.3213,-307.967,366.80826,NULL,0);

-- Pathing for Wendigo Entry: 40941
SET @NPC := 305428;
SET @PATH := 40940 * 100 + 1;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`PathId`,`mount`,`StandState`,`SheathState`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,0,0,'Wendigo The Grizzed Den');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-5415.547,-195.46529,372.04425,NULL,0),
(@PATH,2,-5423.3423,-210.78473,373.1206,NULL,0),
(@PATH,3,-5424.663,-222.1875,371.91193,NULL,0),
(@PATH,4,-5423.3423,-210.78473,373.1206,NULL,0),
(@PATH,5,-5415.547,-195.46529,372.04425,NULL,0),
(@PATH,6,-5410.5034,-190.62154,371.5363,NULL,0);

-- Pathing for Wendigo Entry: 40941
SET @NPC := 305430;
SET @PATH := 40940 * 100 + 2;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`PathId`,`mount`,`StandState`,`SheathState`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,0,0,'Wendigo The Grizzed Den');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-5384.186,-205.60764,357.51697,NULL,0),
(@PATH,2,-5398.592,-193.58705,352.6223,NULL,0),
(@PATH,3,-5415.132,-187.94098,349.65527,NULL,0),
(@PATH,4,-5445.65,-182.1272,349.8584,NULL,0),
(@PATH,5,-5415.132,-187.94098,349.65527,NULL,0),
(@PATH,6,-5398.592,-193.58705,352.6223,NULL,0),
(@PATH,7,-5384.186,-205.60764,357.51697,NULL,0),
(@PATH,8,-5377.7954,-213.96355,359.8448,NULL,0);

-- Pathing for Wendigo Entry: 40941
SET @NPC := 305497;
SET @PATH := 40940 * 100 + 3;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`PathId`,`mount`,`StandState`,`SheathState`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,0,0,'Wendigo The Grizzed Den');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-5391.752,-162.42014,368.58902,NULL,0),
(@PATH,2,-5392.4688,-151.50348,367.65872,NULL,0),
(@PATH,3,-5399.3403,-130.72395,367.83624,NULL,0),
(@PATH,4,-5392.4736,-151.48874,367.6481,NULL,0),
(@PATH,5,-5391.752,-162.42014,368.58902,NULL,0),
(@PATH,6,-5391.913,-168.78125,369.5989,NULL,0);

-- Pathing for Wendigo Entry: 40941
SET @NPC := 305523;
SET @PATH := 40940 * 100 + 4;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`PathId`,`mount`,`StandState`,`SheathState`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,0,0,'Wendigo The Grizzed Den');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-5433.262,-141.80208,351.33594,NULL,0),
(@PATH,2,-5430.5176,-122.78993,348.24203,NULL,0),
(@PATH,3,-5421.514,-112.52431,345.7881,NULL,0),
(@PATH,4,-5430.5176,-122.78993,348.24203,NULL,0),
(@PATH,5,-5433.262,-141.80208,351.33163,NULL,0),
(@PATH,6,-5434.283,-154.72223,351.79062,NULL,0);

-- Pathing for Wendigo Entry: 40941
SET @NPC := 306124;
SET @PATH := 40940 * 100 + 5;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`PathId`,`mount`,`StandState`,`SheathState`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,0,0,'Wendigo The Grizzed Den');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-5570.078,-269.4566,367.37564,NULL,0),
(@PATH,2,-5565.4443,-252.40105,366.96545,NULL,0),
(@PATH,3,-5558.2485,-240.26389,364.53876,NULL,0),
(@PATH,4,-5540.856,-225.42708,357.9266,NULL,5000),
(@PATH,5,-5558.2485,-240.26389,364.53876,NULL,0),
(@PATH,6,-5565.4443,-252.40105,366.96545,NULL,0),
(@PATH,7,-5570.078,-269.4566,367.37564,NULL,0),
(@PATH,8,-5577.2275,-279.04166,366.27246,NULL,0);

-- Pathing for Wendigo Entry: 40941
SET @NPC := 306240;
SET @PATH := 40940 * 100 + 6;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`PathId`,`mount`,`StandState`,`SheathState`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,0,0,'Wendigo The Grizzed Den');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-5513.318,-223.51216,353.49283,NULL,0),
(@PATH,2,-5499.146,-231.13368,353.7129,NULL,0),
(@PATH,3,-5484.6475,-233.76736,354.64172,NULL,0),
(@PATH,4,-5473.382,-241.0191,354.45215,NULL,0),
(@PATH,5,-5462.646,-249.62848,354.31207,NULL,0),
(@PATH,6,-5455.538,-263.52258,354.31473,NULL,0),
(@PATH,7,-5462.646,-249.62848,354.31207,NULL,3000),
(@PATH,8,-5473.382,-241.0191,354.45215,NULL,0),
(@PATH,9,-5484.6475,-233.76736,354.64172,NULL,0),
(@PATH,10,-5499.146,-231.13368,353.7129,NULL,0),
(@PATH,11,-5513.318,-223.51216,353.49283,NULL,0),
(@PATH,12,-5526.5767,-221.15973,355.00888,NULL,0);

-- Pathing for Wendigo Entry: 40941
SET @NPC := 306243;
SET @PATH := 40940 * 100 + 7;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`PathId`,`mount`,`StandState`,`SheathState`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,0,0,'Wendigo The Grizzed Den');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-5432.259,-274.49826,358.54572,NULL,0),
(@PATH,2,-5413.3438,-273.65237,361.4378,NULL,0),
(@PATH,3,-5402.9463,-272.60245,362.57605,NULL,0),
(@PATH,4,-5387.222,-262.5521,363.20764,NULL,0),
(@PATH,5,-5402.9463,-272.60245,362.57605,NULL,0),
(@PATH,6,-5413.1978,-273.64584,361.46658,NULL,0),
(@PATH,7,-5432.259,-274.49826,358.54572,NULL,0),
(@PATH,8,-5446.2065,-272.88022,356.39362,NULL,0);