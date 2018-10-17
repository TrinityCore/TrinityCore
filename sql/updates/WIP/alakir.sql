-- Template Updates
-- Al'Akir
UPDATE `creature_template` SET `ScriptName`= 'boss_alakir', `InhabitType`= 12 WHERE `entry`= 46753;
-- Slipstream
UPDATE `creature_template` SET `InhabitType`= 4, `ScriptName`= 'npc_totfw_slipstream' WHERE `entry`= 47066;
-- Lightning Strike Trigger
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry`= 48977;

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 46753;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(46753, 0, 0, 'The Conclave of Wind has dissipated. Your honorable conduct and determination have earned you the right to face me in battle, mortals. I await your assault on my platform! Come!', 14, 0, 100, 0, 0, 0, 50553, 7, 'Al''Akir - Conclave of Wind defeated'),
(46753, 1, 0, 'Your challenge is accepted, mortals! Know that you face Al''Akir, Elemental Lord of Air! You have no hope of defeating me!', 14, 0, 100, 0, 0, 0, 50565, 7, 'Al''Akir - Aggro'),
(46753, 2, 0, '|TINTERFACE\\ICONS\\Spell_Frost_WindWalkOn.blp:20|t%s begins to cast |cFFFF0000|Hspell:87770|h[Wind Burst]|h|r!', 41, 0, 100, 0, 0, 0, 49014, 7, 'Al''Akir - Announce Wind Burst');

/*
(46753, @GROUP_ID+3, @ID+, 'Winds! Obey my command!', 14, 0, 100, 0, 0, 0, UNKNOWN, 'Al''Akir'),
(46753, @GROUP_ID+4, @ID+, 'Your futile persistance angers me!', 14, 0, 100, 0, 0, 0, UNKNOWN, 'Al''Akir'),
(46753, @GROUP_ID+5, @ID+, 'Storms! I summon you to my side!', 14, 0, 100, 0, 0, 0, UNKNOWN, 'Al''Akir'),
(46753, @GROUP_ID+6, @ID+, 'Enough! I will no longer be contained!', 14, 0, 100, 0, 0, 0, UNKNOWN, 'Al''Akir'),
(46753, @GROUP_ID+7, @ID+, 'After every storm, comes the calm...', 14, 0, 100, 0, 0, 0, UNKNOWN, 'Al''Akir to Player');
*/

-- Template Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (47066);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(47066, '87713');

-- Summon Groups
DELETE FROM `creature_summon_groups` WHERE `summonerId`= 46753 AND `summonerType`= 0;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(46753, 0, 0, 47066, -51.0972, 576.807, 209.7063, 1.553343, 8, 0),
(46753, 0, 0, 47066, -287.604, 816.51,  209.7063, 0,        8, 0),
(46753, 0, 0, 47066, -47.9531, 1053.3,  209.7063, 4.694936, 8, 0),
(46753, 0, 0, 47066, 188.823,  813.54,  209.7063, 3.124139, 8, 0);

-- Spellclicks
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 47066;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(47066, 87742, 1, 0);
