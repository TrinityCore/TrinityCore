/*
17:05:42.484 -- phaseshift 105

14:55:38.148 -- summon krennan
14:55:39.333 -- move to   -1819.53 Y: 2291.25 Z: 42.32689
14:55:44.653 -- I am not giving up on you

14:55:49.364 -- forcecast summon personal godfrey  68635 
14:55:50.581 -- move wp
 -- godfrey move to  -1840.085 Y: 2293.042 Z: 42.53004
 --                  -1821.922 Y: 2295.05 Z: 42.17052

14:55:59.114

14:55:57.788 -- summon personal greymane  68636
14:55:57.788 -- greymane summon
14:55:58.194 -- move to   -1821.09 Y: 2292.597 Z: 42.23363



14:56:07.413 -- greymane (facing angle --> 1.32645)
14:56:17.039 -- das dachte ich mir
14:56:20.658 -- face to 5.497787


14:57:05.196 -- worgen intro completion  68638  (hitting 36330, 36331 and 36332

14:57:05.196 -- player casts altered form (97709)
14:57:05.617 -- everyone despawns
14:57:05.196 -- phase id 181 applied

22:17:26.108 -- assassin summon cast
22:17:26.108 -- assassin aggro
22:17:26.258 -- gilneas will soon belong to the forsaken

22:18:18.508 -- complete invasion quest

22:54:04.069 -- exodus accept
22:55:05.155 -- phase 194 applied 

phase group 415 --> phase 180, 181, 182
phase group 422 --> phase 183 - 185
phase group 431 --> phase 181 - 183
phase group 432 --> phase 184 - 186
phase group 429 --> phase 181, 182
phase group 433 --> phase 181 - 184

PHASING DOCUMENTATION:
105 - chapter two intro phase
181 - first duskhaven phase after chapter 2 intro
182 - forsaken start attacking
183 - after first terrain swap: first land piece is broken
184 - after seeing horde starts invading gilneas: exodus

186 - Koroth's Den / Stormglen phase (Ogre zone) (inclduing forsaken attack koroth event)

194 - exodus caravan phase
*/


-- Phasing Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 26 AND `SourceEntry`= 4714 AND `SourceGroup` IN (105, 181, 182, 183);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 105, 4714, 8, 14222, 0, 'Gilneas - Phase 105 - active when rewarded quest 14222'),
-- (26, 105, 4714, 8, 14375, 1, 'Gilneas - Phase 105 - inactive when rewarded quest 14375'),
(26, 181, 4714, 8, 14375, 0, 'Gilneas - Phase 181 - active when rewarded quest 14222'),
(26, 181, 4714, 8, 14321, 1, 'Gilneas - Phase 181 - inactive when rewarded quest 14321'),
(26, 182, 4714, 8, 14321, 0, 'Gilneas - Phase 182 - active when rewarded quest 14321'),
(26, 182, 4714, 8, 14386, 1, 'Gilneas - Phase 182 - inactive when rewarded quest 14386'),
(26, 183, 4714, 8, 14386, 0, 'Gilneas - Phase 183 - active when rewarded quest 14386');

-- Terrain Swaps
DELETE FROM `terrain_swap_defaults` WHERE `TerrainSwapMap`= 655;
INSERT INTO `terrain_swap_defaults` (`MapId`, `TerrainSwapMap`, `Comment`) VALUES
(654, 655, 'Gilneas - Duskmist Shore broken');

-- Terrain Swap Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 25 AND `SourceEntry` IN (655);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `NegativeCondition`, `Comment`) VALUES 
(25, 0, 655, 8, 14386, 0, 'Gilneas - Terrain Swap 655 - active when rewarded quest 14386');

DELETE FROM `phase_area` WHERE `AreaId`= 4714;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(4714, 105, 'Gilneas - Phase 105'),
(4714, 181, 'Gilneas - Phase 181'),
(4714, 182, 'Gilneas - Phase 182'),
(4714, 183, 'Gilneas - Phase 183');

-- Update Phasing for Creatures
-- Phase 181, 182, 183
UPDATE `creature` SET `PhaseId`= 0, `PhaseGroup`= 431 WHERE `guid` IN (255508, 255507, 255506, 255505, 255504, 255503, 255502, 255501, 255500, 255499, 255498, 255497, 255496, 255495, 255494, 255493, 255492, 255491, 255490, 255489, 255488, 255487, 255486, 255485, 255483, 255482, 255480, 255479, 255478, 255476, 255475, 255474, 255473, 255472, 255471, 255470, 255469, 255468, 255467, 255466, 255465, 255464, 255463, 255461, 255460, 255459, 255457, 255456, 255455, 255454, 255453, 255452, 255451, 255450, 255449, 255448, 255447, 255446, 255444, 255443, 255441, 255440, 255439, 255438, 255437, 255436, 255435, 255434, 255433, 255518, 255519, 255516, 255517, 255522, 255520, 255532, 255528, 255533, 255524, 255527, 255530, 255529, 255535, 255531, 255534);
UPDATE `creature` SET `PhaseId`= 0, `PhaseGroup`= 429 WHERE `guid`= 255442;

-- Phase 182, 183
UPDATE `creature` SET `PhaseId`= 0, `PhaseGroup`= 471 WHERE `guid` IN (255677, 255676, 255679, 255681, 255680);

-- Update Phasing for GameObjects
UPDATE `gameobject` SET `PhaseId`= 0, `PhaseGroup`= 431 WHERE `guid` IN (236344, 236345, 236346, 236347, 236348, 236349, 236350, 236351, 236352, 236353, 236354, 236355, 236356, 236358, 235520, 236492);

-- Cleanup Duplicate Spawns
DELETE FROM `creature` WHERE `guid` IN (255642, 255755, 255766, 255784, 255651, 255795, 255765, 255686, 255691, 255647, 255771, 255782, 255775, 255961, 255959, 255786, 255793, 255791, 255794, 255789, 255788, 255792, 255790, 255787);
DELETE FROM `creature_addon` WHERE `guid` IN (255642, 255755, 255766, 255784, 255651, 255795, 255765, 255686, 255691, 255647, 255771, 255782, 255775, 255961, 255959, 255786, 255793, 255791, 255794, 255789, 255788, 255792, 255790, 255787);

-- Spell Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (69123, 68632, 68634, 68638, 69296, 68558, 68591, 68659, 68682) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 69123, 0, 0, 31, 0, 3, 0, 255427, 0, 0, '', 'Curse of the Worgen - Target Generic Trigger Lab - Multiphase (Ground)'),
(13, 1, 68632, 0, 0, 31, 0, 3, 0, 255423, 0, 0, '', 'Summon Personal Godfrey - Target Generic Trigger Lab - Multiphase (Ground)'),
(13, 1, 68634, 0, 0, 31, 0, 3, 0, 255421, 0, 0, '', 'Summon Personal Greymane - Target Generic Trigger Lab - Multiphase (Ground)'),
(13, 2, 68638, 0, 0, 31, 0, 3, 36331, 0, 0, 0, '', 'Worgen Intro Completion - Target Krennan Aranas'),
(13, 2, 68638, 0, 1, 31, 0, 3, 36330, 0, 0, 0, '', 'Worgen Intro Completion - Target Lord Godfrey'),
(13, 2, 68638, 0, 2, 31, 0, 3, 36332, 0, 0, 0, '', 'Worgen Intro Completion - Target King Genn Greymane'),
(13, 2, 69296, 0, 0, 31, 0, 5, 197337, 0, 0, 0, '', 'Invasion Camera - Target Invasion Camera'),
(13, 1, 68558, 0, 0, 31, 0, 3, 36140, 0, 0, 0, '', 'Gilneas - Quest - Abomination Kill Me - Target Prince Liam Greymane'),
(13, 1, 68591, 0, 0, 31, 0, 3, 36286, 0, 0, 0, '', 'Fiery Boulder - Target Generic Trigger LAB - Multiphase'),
(13, 1, 68659, 0, 0, 31, 0, 3, 0, 255538, 0, 0, '', 'Launch - Target Generic Trigger LAB - Multiphase'),
(13, 1, 68659, 0, 1, 31, 0, 3, 0, 255521, 0, 0, '', 'Launch - Target Generic Trigger LAB - Multiphase'),
(13, 1, 68659, 0, 2, 31, 0, 3, 0, 255515, 0, 0, '', 'Launch - Target Generic Trigger LAB - Multiphase'),
(13, 1, 68659, 0, 3, 31, 0, 3, 0, 255514, 0, 0, '', 'Launch - Target Generic Trigger LAB - Multiphase'),
(13, 1, 68659, 0, 4, 31, 0, 3, 0, 255510, 0, 0, '', 'Launch - Target Generic Trigger LAB - Multiphase'),
(13, 1, 68659, 0, 5, 31, 0, 3, 0, 255511, 0, 0, '', 'Launch - Target Generic Trigger LAB - Multiphase'),
(13, 1, 68659, 0, 6, 31, 0, 3, 0, 255509, 0, 0, '', 'Launch - Target Generic Trigger LAB - Multiphase'),
(13, 1, 68659, 0, 7, 31, 0, 3, 0, 255513, 0, 0, '', 'Launch - Target Generic Trigger LAB - Multiphase'),
(13, 1, 68659, 0, 8, 31, 0, 3, 0, 255512, 0, 0, '', 'Launch - Target Generic Trigger LAB - Multiphase'),
(13, 1, 68682, 0, 0, 31, 0, 3, 36312, 0, 0, 0, '', 'Call Attack Mastiff - Target Dark Ranger Thyala');

-- Spellclick Conditions
DELETE FROM `conditions` WHERE `SourceGroup` IN (36287, 36288, 36289) AND `SourceTypeOrReferenceId`= 18;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(18, 36287, 68597, 0, 0, 9, 0, 14368, 0, 0, 0, 0, '', 'Required quest active for spellclick'),
(18, 36288, 68598, 0, 0, 9, 0, 14368, 0, 0, 0, 0, '', 'Required quest active for spellclick'),
(18, 36289, 68596, 0, 0, 9, 0, 14368, 0, 0, 0, 0, '', 'Required quest active for spellclick');

-- Template Updates
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 36198;
UPDATE `creature_template` SET `ScriptName`= 'npc_gilneas_horrid_abomination' WHERE `entry`= 36231;
UPDATE `creature_template` SET `npcflag`= 16777216, `ScriptName`= 'npc_gilneas_save_the_children' WHERE `entry` IN (36287, 36288, 36289);
UPDATE `creature_template` SET `flags_extra`= 128, `InhabitType`= 4 WHERE `entry`= 36286;
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 36198;

UPDATE `creature_template` SET `unit_flags`= 0x100, `ScriptName`= 'npc_gilneas_forsaken_catapult' WHERE `entry`= 36283;

-- Respawn Time corrections
UPDATE `creature` SET `spawntimesecs`= 30 WHERE `id` IN (36287, 36288, 36289);

DELETE FROM `creature_text` WHERE `CreatureID` IN (36330, 36331, 36332, 36231, 36287, 36288, 36289);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES
-- Chapter Two Intro
(36330, 0, 0, 'Give it up, Krennan.  It''s time to put this one down.  It''s protocol.', 12, 0, 100, 274, 0, 19635, 36336, 'Lord Godfrey to Player'),
(36331, 0, 0, 'I am not giving up on you.  I don''t have a cure for the Curse yet... but there are treatments.  You will have control again.', 12, 0, 100, 274, 0, 20919, 36344, 'Krennan Aranas to Player'),
(36332, 0, 0, 'Tell me, Godfrey.  Those that stayed in Gilneas City so that we could live.  Were they following protocol?', 12, 0, 100, 1, 0, 19721, 36340, 'King Genn Greymane to Player'),
(36332, 1, 0, 'I didn''t think so.  Now hand me that potion, Krennan... and double the dosage.', 12, 0, 100, 1, 0, 19722, 36341, 'King Genn Greymane to Player'),
-- Horrid Abomination
(36231, 0, 0, 'Barrel smell like gunpowder...', 12, 0, 100, 0, 0, 20909, 36311, 'Horrid Abomination - Keg Placed'),
(36231, 0, 1, 'GAH!!!!  I CAN''T SEE IN HERE!!!!', 12, 0, 100, 0, 0, 20908, 36310, 'Horrid Abomination - Keg Placed'),
(36231, 0, 2, 'Uh-oh... this gonna hurts me...', 12, 0, 100, 0, 0, 20911, 36313, 'Horrid Abomination - Keg Placed'),
(36231, 0, 3, 'This not be good...', 12, 0, 100, 0, 0, 20911, 36312, 'Horrid Abomination - Keg Placed'),
(36231, 0, 4, 'I gots bad feeling...', 12, 0, 100, 0, 0, 20911, 36314, 'Horrid Abomination - Keg Placed'),
-- Save the Children
(36287, 0, 0, 'You are scary!  I just want my mommy!', 12, 0, 100, 0, 0, 0, 36325, 'Cynthia to Player'),
(36288, 0, 0, 'Are you one of the good worgen, $g mister:ma''am;?  Did you see Cynthia hiding in the sheds outside?', 12, 0, 100, 0, 0, 0, 36326, 'Ashley to Player'),
(36289, 0, 0, 'Don''t hurt me!  I was just looking for my sisters!  I think Ashley''s inside that house!', 12, 0, 100, 0, 0, 0, 36324, 'James to Player');

DELETE FROM `waypoints` WHERE `entry`= 36330;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES
(36330, 1, -1840.085, 2293.042, 42.53004),
(36330, 2, -1821.922, 2295.05, 42.17052);

-- Quest Chains
DELETE FROM `quest_template_addon` WHERE `ID` IN (14321, 14369, 14382, 14368, 14386, 14396);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`) VALUES
(14321, 14320),
(14369, 14367),
(14382, 14367),
(14368, 14367),
(14386, 14369),
(14396, 14386);

UPDATE `quest_template_addon` SET `PrevQuestID`= 14336, `ExclusiveGroup`= -14347 WHERE `ID` IN (14347, 14348);
UPDATE `quest_template_addon` SET `ExclusiveGroup`= -14369 WHERE `ID` IN (14369, 14382, 14368);

UPDATE `gameobject_template` SET `ScriptName`= 'go_gilneas_invasion_camera' WHERE `entry`= 197337;

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (196394, 196403);
INSERT INTO `gameobject_template_addon` (`entry`, `flags`) VALUES
(196394, 4),
(196403, 4);

-- Sparring Entries
DELETE FROM `creature_sparring_template` WHERE `AttackerEntry` IN (36211, 36140, 34511);
INSERT INTO `creature_sparring_template` (`AttackerEntry`, `VictimEntry`, `HealthLimitPct`) VALUES
(36211, 34511, 90),
(36140, 34511, 100),
(34511, 36211, 90),
(34511, 36140, 100);

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_gilneas_quest_save_the_children',
'spell_gilneas_quest_save_james',
'spell_gilneas_launch',
'spell_gilneas_call_attack_mastiff');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(68596, 'spell_gilneas_quest_save_james'),
(68597, 'spell_gilneas_quest_save_the_children'),
(68598, 'spell_gilneas_quest_save_the_children'),
(68659, 'spell_gilneas_launch'),
(68682, 'spell_gilneas_call_attack_mastiff');

-- Creature Krennan Aranas 36331 SAI
SET @ENTRY := 36331;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 63, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set walk // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3633100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #3633100 // "),
(@ENTRY, 0, 2, 0, 8, 0, 100, 0, 68638, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Worgen Intro Completion (68638) hit  - Self: Despawn instantly // ");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3633100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3633100,9,0,0,0,0,100,0,1200,1200,0,0,69,0,0,0,0,0,0,8,0,0,0,-1819.53,2291.25,42.32689,0,""),
(3633100,9,1,0,0,0,100,0,5300,5300,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,""),
(3633100,9,2,0,0,0,100,0,4700,4700,0,0,11,68635,0,0,0,0,0,23,0,0,0,0,0,0,0,""),
(3633100,9,3,0,0,0,100,0,8400,8400,0,0,11,68636,0,0,0,0,0,23,0,0,0,0,0,0,0,"");

-- Creature Lord Godfrey 36330 SAI
SET @ENTRY := 36330;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, 3633000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Start timed action list id #3633000 // "),
(@ENTRY, 0, 1, 0, 8, 0, 100, 0, 68638, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Worgen Intro Completion (68638) hit  - Self: Despawn instantly // ");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3633000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3633000,9,0,0,0,0,100,0,1200,1200,0,0,53,0,36330,0,0,0,0,1,0,0,0,0,0,0,0,""),
(3633000,9,1,0,0,0,100,0,5300,5300,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"");

-- Creature King Genn Greymane 36332 SAI
SET @ENTRY := 36332;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On just summoned - Self: Set walk // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3633200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #3633200 // "),
(@ENTRY, 0, 2, 3, 20, 0, 100, 1, 0, 0, 0, 0, 28, 68630, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When player rewards any quest - Action invoker: Remove aura due to spell Curse of the Worgen (68630) // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 68639, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell Forcecast Worgen Intro Completion (68639) on Action invoker // "),
(@ENTRY, 0, 4, 0, 8, 0, 100, 0, 68638, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Worgen Intro Completion (68638) hit  - Self: Despawn instantly // ");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3633200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3633200,9,0,0,0,0,100,0,400,400,0,0,69,0,0,0,0,0,0,8,0,0,0,-1821.09,2292.597,42.23363,0,""),
(3633200,9,1,0,0,0,100,0,11000,11000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,""),
(3633200,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.32645,""),
(3633200,9,3,0,0,0,100,0,9600,9600,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,""),
(3633200,9,4,0,0,0,100,0,3600,3600,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.497787,""),
(3633200,9,5,0,0,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"");

-- Creature Slain Watchman 36205 SAI
SET @ENTRY := 36205;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 14321, 0, 0, 0, 11, 68492, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When player accepts quest 14321 - Self: Cast spell Forcecast Summon Forsaken Assassin (68492) on Action invoker // ");
UPDATE `creature_template` SET `flags_extra`= 2, `unit_flags`= 537166592 WHERE `entry`= 36205;

-- Creature Forsaken Assassin 36207 SAI
SET @ENTRY := 36207;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On just summoned - Self: Talk 0 // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Attack Owner/Summoner // "),
(@ENTRY, 0, 2, 0, 67, 0, 100, 0, 9000, 12000, 0, 0, 11, 75360, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When victim is behind me (wait 9000 - 12000 ms before next event trigger) - Self: Cast spell 75360 on Victim // Forsaken Assassin - On Behind Target - Cast 'Backstab'");

-- Creature Forsaken Invader 34511 SAI
SET @ENTRY := 34511;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 10000, 10000, 49, 0, 0, 0, 0, 0, 0, 19, 36211, 10, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 1000 and 1000 ms (and later repeats every 10000 and 10000 ms) - Self: Attack Closest alive creature Duskhaven Watchman (36211) in 10 yards // ");

-- Creature Prince Liam Greymane 36140 SAI
SET @ENTRY := 36140;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 68558, 0, 0, 0, 11, 68559, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On spell 68558 hit  - Self: Cast spell 68559 on Action invoker // ");

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 36283 AND `spell_id`= 46598;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(36283, 46598, 0, 1);

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (36283);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`) VALUES
(36283,36292,0,0,'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 18 AND `SourceGroup`= 36283;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 36283, 46598, 0, 0, 31, 0, 3, 36292, 0, 0, 0, 0, '', 'Required quest active for spellclick'),
(18, 36283, 69434, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Required quest active for spellclick');

-- Creature Lord Godfrey 36290 SAI
SET @ENTRY := 36290;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 20, 0, 100, 0, 14386, 0, 0, 0, 11, 69027, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When player rewards quest Leader of the Pack (14386) - Self: Cast spell 69027 on Action invoker // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // ");

