-- Template Updates
-- Halfus Wyrmbreaker
UPDATE `creature_template` SET `difficulty_entry_1`= 46209, `difficulty_entry_2`= 46210, `difficulty_entry_3` = 46211, `ScriptName`= 'boss_halfus_wyrmbreaker' WHERE `entry`= 44600;
UPDATE `creature_template` SET `minlevel`= 88, `maxlevel`= 88, `faction`= 16, `BaseAttackTime`= 1500, `DamageModifier`= 80, `mingold`= 2200000, `maxgold`= 2400000, `mechanic_immune_mask`= 80297855, `exp`= 3 WHERE `entry` IN (44600, 46209, 46210, 46211);
UPDATE `creature_template` SET `mingold`= 4900000, `maxgold`= 5100000 WHERE `entry` IN (46209, 46211);
-- Proto-Behemoth
UPDATE `creature_template` SET `difficulty_entry_1`= 46227, `difficulty_entry_2`= 46228, `difficulty_entry_3` = 46229, `ScriptName`= 'npc_halfus_proto_behemoth' WHERE `entry`= 44687;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `exp`= 3, `faction`= 16, `mechanic_immune_mask`= 617299839, `flags_extra`= 0x40000000, `InhabitType`= 12 WHERE `entry` IN (44687, 46227, 46228, 46229);
-- Enslaved Dragons
UPDATE `creature_template` SET `ScriptName`= 'npc_halfus_enslaved_dragon' WHERE `entry` IN (44645, 44652, 44650, 44797, 44641);
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `exp`= 3, `faction`= 35, `npcflag`= 1, `DamageModifier`= 30, `flags_extra`= 0x00000200 | 0x40000000, `HoverHeight`= 7.875, `mechanic_immune_mask`= 617299839 WHERE `entry` IN (46212, 46213, 46214, 46215, 46216, 46217, 46218, 46219, 46220, 46221, 46222, 46223, 44828, 44829, 44826, 44653);
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `exp`= 3, `faction`= 35, `npcflag`= 1, `DamageModifier`= 3.5, `flags_extra`= 0x40000000, `mechanic_immune_mask`= 617299839 WHERE `entry` IN (46224, 46225, 46226, 44641);
-- Nether Scion
UPDATE `creature_template` SET `difficulty_entry_1`= 46212, `difficulty_entry_2`= 46213, `difficulty_entry_3`= 46214 WHERE `entry`= 44828;
UPDATE `creature_template` SET `gossip_menu_id`= 12077 WHERE `entry`= 44645;
-- Slate Dragon
UPDATE `creature_template` SET `difficulty_entry_1`= 46215, `difficulty_entry_2`= 46216, `difficulty_entry_3`= 46217 WHERE `entry`= 44829;
-- Storm Rider
UPDATE `creature_template` SET `difficulty_entry_1`= 46218, `difficulty_entry_2`= 46219, `difficulty_entry_3`= 46220 WHERE `entry`= 44826;
-- Time Warden
UPDATE `creature_template` SET `difficulty_entry_1`= 46221, `difficulty_entry_2`= 46222, `difficulty_entry_3`= 46223 WHERE `entry`= 44653;
-- Orphaned Emerald Whelp
UPDATE `creature_template` SET `difficulty_entry_1`= 46224, `difficulty_entry_2`= 46225, `difficulty_entry_3`= 46226 WHERE `entry`= 44641;
UPDATE `creature_template` SET `gossip_menu_id`= 11884 WHERE `entry` IN (46224, 46225, 46226);
-- Cyclone Winds
UPDATE `creature_template` SET  `unit_flags`= 33554432, `flags_extra`= 128, `InhabitType`= 4 WHERE `entry`= 45026;
-- Whelp Cage
UPDATE `gameobject_template` SET `ScriptName`= 'go_halfus_whelp_cage' WHERE `entry`= 205087;
UPDATE `gameobject_template_addon` SET `flags`= 16 | 32 WHERE `entry`= 205087;

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 44600;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(44600, 0, 0, 'Cho''gall will have your heads! ALL OF THEM!', 14, 0, 100, 0, 0, 20186, 48970, 'Halfus Wyrmbreaker - Aggro'),
(44600, 1, 0, 'The wyrms will eat well tonight!', 14, 0, 100, 0, 0, 20187, 48971, 'Halfus Wyrmbreaker - Slay 1'),
(44600, 1, 1, 'The burden of the damned falls upon you!', 14, 0, 100, 0, 0, 20188, 48972, 'Halfus Wyrmbreaker - Slay 2'),
(44600, 2, 0, '%s binds the $n to his will!', 41, 0, 100, 0, 0, 20190, 48961, 'Halfus Wyrmbreaker - Bind Dragon'),
(44600, 3, 0, '%s roars furiously!', 41, 0, 100, 0, 0, 0, 48966, 'Halfus Wyrmbreaker - Furious Roar');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_halfus_bind_will',
'spell_halfus_fireball',
'spell_halfus_stone_touch',
'spell_halfus_cyclone_winds',
'spell_halfus_dancing_flames');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(84246, 'spell_halfus_bind_will'),
(86058, 'spell_halfus_fireball'),
(83719, 'spell_halfus_fireball'),
(83603, 'spell_halfus_stone_touch'),
(83612, 'spell_halfus_cyclone_winds'),
(83962, 'spell_halfus_dancing_flames');

-- Spellclick Spells
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (44828, 44829, 44826, 44653);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(44828, 83589, 1, 1),
(44829, 83590, 1, 1),
(44826, 83591, 1, 1),
(44653, 83447, 1, 1);

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (83487, 83611, 83603, 84092, 87683, 83601, 83609, 84246, 83962) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 83487, 0, 0, 31, 0, 3, 44645, 0, 0, 0, '', 'Chain - Target Nether Scion'),
(13, 1, 83487, 0, 1, 31, 0, 3, 44652, 0, 0, 0, '', 'Chain - Target Slate Dragon'),
(13, 1, 83487, 0, 2, 31, 0, 3, 44650, 0, 0, 0, '', 'Chain - Target Storm Rider'),
(13, 1, 83487, 0, 3, 31, 0, 3, 44797, 0, 0, 0, '', 'Chain - Target Time Warden'),
(13, 7, 83611, 0, 0, 31, 0, 3, 44600, 0, 0, 0, '', 'Nether Blindness - Target Halfus Wyrmbreaker'),
(13, 1, 83603, 0, 0, 31, 0, 3, 44600, 0, 0, 0, '', 'Stone Touch - Target Halfus Wyrmbreaker'),
(13, 1, 84092, 0, 0, 31, 0, 3, 44600, 0, 0, 0, '', 'Cyclone Winds - Target Halfus Wyrmbreaker'),
(13, 1, 87683, 0, 0, 31, 0, 3, 44600, 0, 0, 0, '', 'Dragon''s Vengeance - Target Halfus Wyrmbreaker'),
(13, 1, 84246, 0, 0, 31, 0, 3, 44600, 0, 0, 0, '', 'Bind Will - Target Halfus Wyrmbreaker'),
(13, 1, 83601, 0, 0, 31, 0, 3, 44687, 0, 0, 0, '', 'Time Dilation - Target Proto-Behemoth'),
(13, 1, 83609, 0, 0, 31, 0, 3, 44687, 0, 0, 0, '', 'Atrophic Poison - Target Proto-Behemoth'),
(13, 1, 83962, 0, 0, 31, 0, 3, 42098, 0, 0, 0, '', 'Dancing Flames - Target Cataclysm Stalker');

-- Creature Spike 44765 SAI
SET @ENTRY := 44765;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 200, 200, 0, 0, 11, 83487, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 200 and 200 ms) - Self: Cast spell Chain (83487) on Self // ");

-- Creature Cyclone Winds 45026 SAI
SET @ENTRY := 45026;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 63, 0, 100, 0, 0, 0, 0, 0, 11, 84092, 0, 0, 0, 0, 0, 11, 44600, 100, 0, 0, 0, 0, 0, "When just created - Self: Cast spell Cyclone Winds (84092) on Creature Halfus Wyrmbreaker (44600) in 100 yd // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 11400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Despawn in 11400 ms // ");

DELETE FROM `creature_loot_template` WHERE `Entry` IN (44600, 46209, 46210, 46211);
UPDATE `creature_template` SET `lootid`= `entry` WHERE `entry` IN (46209, 46210, 46211);
DELETE FROM `reference_loot_template` WHERE `Entry` IN (446000, 462100, 462101);

INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
-- Normal Mode
(446000, 59483, 0, 1, 1, 1, 1), -- Wyrmbreaker's Amulet
(446000, 59484, 0, 1, 1, 1, 1), -- Book of Binding Will
(446000, 59473, 0, 1, 1, 1, 1), -- Essence of the Cyclone
(446000, 59475, 0, 1, 1, 1, 1), -- Bracers of the Bronze Flight
(446000, 59470, 0, 1, 1, 1, 1), -- Bracers of Impossible Strength
(446000, 59474, 0, 1, 1, 1, 1), -- Malevolence
(446000, 59471, 0, 1, 1, 1, 1), -- Paudrons of the Great Ettin
(446000, 59472, 0, 1, 1, 1, 1), -- Proto-Handler's Gauntlets
(446000, 59481, 0, 1, 1, 1, 1), -- Helm of the Nether Scion
(446000, 59476, 0, 1, 1, 1, 1), -- Legguards of the Emerald Brook
(446000, 59482, 0, 1, 1, 1, 1), -- Robes of the Burning Acolyte
(446000, 59469, 0, 1, 1, 1, 1), -- Storm Rider's Boots
-- Heroic Mode
(462100, 65134, 0, 1, 1, 1, 1), -- Wyrmbreaker's Amulet
(462100, 65133, 0, 1, 1, 1, 1), -- Book of Binding Will
(462100, 65140, 0, 1, 1, 1, 1), -- Essence of the Cyclone
(462100, 65138, 0, 1, 1, 1, 1), -- Bracers of the Bronze Flight
(462100, 65143, 0, 1, 1, 1, 1), -- Bracers of Impossible Strength
(462100, 65139, 0, 1, 1, 1, 1), -- Malevolence
(462100, 65142, 0, 1, 1, 1, 1), -- Paudrons of the Great Ettin
(462100, 65141, 0, 1, 1, 1, 1), -- Proto-Handler's Gauntlets
(462100, 65136, 0, 1, 1, 1, 1), -- Helm of the Nether Scion
(462100, 65137, 0, 1, 1, 1, 1), -- Legguards of the Emerald Brook
(462100, 65135, 0, 1, 1, 1, 1), -- Robes of the Burning Acolyte
(462100, 65144, 0, 1, 1, 1, 1), -- Storm Rider's Boots
-- Tier Set Token
(462101, 67424, 0, 1, 1, 1, 1), -- Chest of the Forlorn Protector
(462101, 67423, 0, 1, 1, 1, 1), -- Chest of the Forlorn Conqueror
(462101, 67425, 0, 1, 1, 1, 1); -- Chest of the Forlorn Vanquisher

INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `Reference`, `MaxCount`) VALUES
-- 10 Player Normal
(44600, 446000, 100, 1, 446000, 2),
-- 25 Player Normal
(46209, 446000, 100, 1, 446000, 6),
-- 10 Player Heroic
(46210, 462100, 100, 1, 462100, 2),
(46210, 462101, 100, 1, 462101, 1),
-- 25 Player Heroic
(46211, 462100, 100, 1, 462100, 6),
(46211, 462101, 100, 1, 462101, 3);

-- Achievements
DELETE FROM `achievement_criteria_data` WHERE `ScriptName`= 'achievement_the_only_escape';
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(15094, 11, 0, 0, 'achievement_the_only_escape');

-- Currency loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (44600, 46209, 46210, 46211);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(44600, 396, 11500),
(46209, 396, 13500),
(46210, 396, 11500),
(46211, 396, 13500);
