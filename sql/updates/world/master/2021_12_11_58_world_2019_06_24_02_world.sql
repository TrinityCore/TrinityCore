UPDATE `creature_template` SET `DamageModifier`=7.5 WHERE `entry`=29621;
UPDATE `creature` SET `position_x`=7494.89, `position_y`=4871.53, `position_z`=-12.6553, `orientation`=1.4174, `spawndist`=0, `MovementType`=0 WHERE `id`=29621;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29621, 2962100, 2962101) AND source_type IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29621, 0, 0, 1, 4, 0, 100, 512, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Aggro - Set Invincibility At 1 Hp"),
(29621, 0, 1, 2, 61, 0, 100, 512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Aggro - Say Line 0"),
(29621, 0, 2, 0, 61, 0, 100, 512, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Aggro - Set Event Phase 1"),
(29621, 0, 3, 4, 2, 0, 100, 513, 0, 50, 0, 0, 0, 11, 50161, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - Between 0-50% Health - Cast 'Protection Sphere' (No Repeat)"),
(29621, 0, 4, 0, 61, 0, 100, 512, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - Between 0-50% Health - Say Line 1 (No Repeat)"),
(29621, 0, 5, 6, 8, 0, 100, 512, 31699, 0, 0, 0, 0, 28, 50161, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Spellhit 'The Admiral Revealed: Lord-Commander's Nullifier Effect' - Remove Aura 'Protection Sphere'"),
(29621, 0, 6, 0, 61, 0, 100, 512, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Spellhit 'The Admiral Revealed: Lord-Commander's Nullifier Effect' - Say Line 2"),
(29621, 0, 7, 8, 2, 0, 100, 513, 0, 40, 0, 0, 0, 36, 29620, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - Between 0-40% Health - Turn Into Dreadlord Mal'Ganis (No Repeat)"),
(29621, 0, 8, 9, 61, 0, 100, 512, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - Between 0-40% Health - Set Event Phase 2 (No Repeat)"),
(29621, 0, 9, 0, 61, 0, 100, 512, 0, 0, 0, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - Between 0-40% Health - Set Equip 0 (No Repeat)"),
(29621, 0, 10, 0, 2, 0, 100, 513, 0, 30, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - Between 0-30% Health - Say Line 0 (No Repeat)"),
(29621, 0, 11, 0, 2, 0, 100, 1, 0, 15, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - Between 0-15% Health - Say Line 1 (No Repeat)"),
(29621, 0, 12, 0, 2, 0, 100, 513, 0, 1, 0, 0, 0, 80, 2962100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - Between 0-1% Health - Run Script (No Repeat)"),
(29621, 0, 13, 0, 0, 1, 100, 0, 15000, 16000, 16000, 16000, 0, 11, 49807, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - In Combat - Cast 'Whirlwind' (No Repeat)"),
(29621, 0, 14, 0, 0, 1, 100, 0, 6000, 7000, 6000, 7000, 0, 11, 57846, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - In Combat - Cast 'Heroic Strike' (No Repeat)"),
(29621, 0, 15, 0, 0, 2, 100, 0, 15000, 16000, 15000, 16000, 0, 11, 53045, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, "Mal'ganis - In Combat - Cast 'Sleep' (No Repeat)"),
(29621, 0, 16, 0, 0, 2, 100, 0, 6000, 7000, 6000, 7000, 0, 11, 60501, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mal'ganis - In Combat - Cast 'Vampiric Touch' (No Repeat)"),
(29621, 0, 17, 0, 0, 1, 100, 0, 13000, 13500, 13000, 13500, 0, 11, 15284, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Mal'ganis - In Combat - Cast 'Cleave' (No Repeat)"),
(29621, 0, 18, 0, 0, 2, 100, 0, 8000, 9000, 8000, 9000, 0, 11, 60502, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mal'ganis - In Combat - Cast 'Carrion Swarm' (No Repeat)"),
(29621, 0, 19, 0, 0, 2, 100, 0, 18000, 19000, 18000, 19000, 0, 11, 60500, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Mal'ganis - In Combat - Cast 'Mind Blast' (No Repeat)"),
(29621, 0, 20, 21, 25, 0, 100, 512, 0, 0, 0, 0, 0, 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Reset - Start Attacking (No Repeat)"),
(29621, 0, 21, 22, 61, 0, 100, 512, 0, 0, 0, 0, 0, 36, 29621, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Reset - Turn Into Grand Admiral Westwind (No Repeat)"),
(29621, 0, 22, 23, 61, 0, 100, 512, 0, 0, 0, 0, 0, 71, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Reset - Set Equip 1"),
(29621, 0, 23, 0, 61, 0, 100, 512, 0, 0, 0, 0, 0, 19, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Reset - Remove Flags Not Attackable"),
(29621, 0, 24, 0, 5, 0, 100, 512, 0, 0, 1, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Killed Player - Talk 3"),
(29621, 0, 25, 0, 34, 0, 100, 512, 8, 1, 0, 0, 0, 80, 2962101, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On MovementInform Point 1 - Run Script"),
(2962100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Script - Set Event Phase 3"),
(2962100, 9, 1, 0, 0, 0, 100, 513, 1, 1, 0, 0, 0, 18, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Script - Set Flag Not Attackable"),
(2962100, 9, 2, 0, 0, 0, 100, 513, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Script - Stop Attacking (No Repeat)"),
(2962100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 33, 29627, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Script - Quest Credit 'The Admiral Revealed'"),
(2962100, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Script - Say Line 2"),
(2962100, 9, 5, 0, 0, 0, 100, 513, 0, 0, 0, 0, 0, 12, 29627, 1, 25000, 0, 0, 0, 8, 0, 0, 0, 7494.89, 4871.53, -12.6553, 1.376, "Grand Admiral Westwind - On Script - Summon Creature 'Grand Admiral Westwind Kill Credit Bunny' (No Repeat)"),
(2962100, 9, 6, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Script - Set Run Off"),
(2962100, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, 7494.9375, 4871.9707, -12.6825, 0, "Grand Admiral Westwind - On Script - Move To Pos"),
(2962101, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Script - Say Line 4"),
(2962101, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Script - Face Invoker"),
(2962101, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 86, 35502, 2, 19, 29627, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Script - Cross Cast 'Legion Teleport Target' (Grand Admiral Westwind Kill Credit Bunny)"),
(2962101, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 28, 35502, 0, 0, 0, 0, 0, 19, 29627, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Script - Remove Aura 'Legion Teleport Target' From Creature 'Grand Admiral Westwind Kill Credit Bunny'"),
(2962101, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Grand Admiral Westwind - On Script - Despawn");

DELETE FROM `creature_text` WHERE `CreatureID`=29621 AND `GroupID` IN (3, 4, 5, 6, 7);
DELETE FROM `creature_text` WHERE `CreatureID`=29620;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(29621, 3, 0, "AHAHAHAHAHA! Incompetence at its finest!", 12, 0, 100, 0, 0, 14821, 30282, 0, "Grand Admiral Westwind"),
(29621, 3, 1, "You gave in too soon!", 12, 0, 100, 0, 0, 14202, 30409, 0, "Grand Admiral Westwind"),
(29621, 3, 2, "How disappointing for you.", 12, 0, 100, 0, 0, 14203, 30410, 0, "Grand Admiral Westwind"),
(29621, 3, 3, "Unfortunate. The best was yet to come.", 12, 0, 100, 0, 0, 14204, 30411, 0, "Grand Admiral Westwind"),
(29620, 0, 0, "Gah! I spent too much time in that weak little shell.", 14, 0, 100, 0, 0, 14426, 30275, 0, "Mal'Ganis"),
(29620, 1, 0, "Kirel narak! I am Mal'Ganis. I AM ETERNAL!", 14, 0, 100, 0, 0, 14427, 30276, 0, "Mal'Ganis"),
(29620, 2, 0, "ENOUGH! I waste my time here. I must gather my strength on the homeworld.", 14, 0, 100, 1, 0, 14428, 30277, 0, "Mal'Ganis"),
(29620, 3, 0, "Anakh kyree!", 14, 0, 100, 0, 0, 14422, 30412, 0, "Mal'Ganis"),
(29620, 3, 1, "My Onslaught will wash over the Lich King's forces!", 14, 0, 100, 0, 0, 14423, 30413, 0, "Mal'Ganis"),
(29620, 3, 2, "Your death is in vain, tiny mortal.", 14, 0, 100, 0, 0, 14424, 30414, 0, "Mal'Ganis"),
(29620, 3, 3, "Your time has come to an end.", 14, 0, 100, 0, 0, 14425, 30415, 0, "Mal'Ganis"),
(29620, 4, 0, "You'll never defeat the Lich King without my forces. I'll have my revenge... on him AND you!", 14, 0, 100, 25, 0, 14429, 30278, 0, "Mal'Ganis");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=20211;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 20211, 0, 0, 31, 1, 3, 29621, 0, 0, 0, 0, "", "Spell 'Lord-Commander's Nullifier' can only target 'Grand Admiral Westwind' AND"),
(17, 0, 20211, 0, 0, 1, 1, 50161, 0, 0, 0, 0, 0, "", "Spell 'Lord-Commander's Nullifier' can only target a NPC that has aura 'Protection Sphere'");
