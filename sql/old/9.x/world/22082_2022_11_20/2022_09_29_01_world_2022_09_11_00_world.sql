--
-- Add missing gossip_menu
DELETE FROM `gossip_menu` WHERE (`MenuID`,`TextID`) IN ((7552,9380),(7581,9396),(7581,9398));
INSERT INTO `gossip_menu`(`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7552, 9380, 0),
(7581, 9396, 0),
(7581, 9398, 0);

-- Add missing npc_text
DELETE FROM `npc_text` WHERE `ID` IN (9396,9398);
INSERT INTO `npc_text`(`ID`, `BroadcastTextID0`, `Probability0`, `VerifiedBuild`) VALUES
(9396, 15444, 1, 0),
(9398, 15448, 1, 0);

-- Trash Mobs Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (17899,17905,17919,17934,17932,17933,17936) AND `GroupID` IN (0,1);
DELETE FROM `creature_text` WHERE `CreatureID`=17772 AND `GroupID`=7;
INSERT INTO `creature_text`(`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17899, 0, 0, 'Lambs for the slaughter!', 12, 0, 100, 0, 0, 0, 18450, 0, 'Shadowy Necromancer say slay'),
(17899, 1, 0, 'A pleasure... to serve the master.', 12, 0, 100, 0, 0, 0, 18448, 0, 'Shadowy Necromancer say death'),
(17899, 1, 1, 'My life... to the master.', 12, 0, 100, 0, 0, 0, 18447, 0, 'Shadowy Necromancer say death'),
(17899, 1, 2, 'You will... ultimately fail.', 12, 0, 100, 0, 0, 0, 18446, 0, 'Shadowy Necromancer say death'),
(17905, 0, 0, 'Let this torment end!!', 12, 0, 100, 0, 0, 0, 18451, 0, 'Banshee say slay'),
(17905, 0, 1, 'I obey.', 12, 0, 100, 0, 0, 0, 18454, 0, 'Banshee say slay'),
(17905, 1, 0, 'I am... released?', 12, 0, 100, 0, 0, 0, 18452, 0, 'Banshee say death'),
(17905, 1, 1, 'Is it really... over?', 12, 0, 100, 0, 0, 0, 18453, 0, 'Banshee say death'),
(17919, 0, 0, 'Back, hold them back!', 12, 0, 100, 0, 0, 0, 18457, 0, 'Alliance Footman say slay'),
(17919, 0, 1, 'Let these monsters taste cold steel!', 12, 0, 100, 0, 0, 0, 18456, 0, 'Alliance Footman say slay'),
(17919, 1, 0, 'Agghh!', 12, 0, 100, 0, 0, 0, 18458, 0, 'Alliance Footman say death'),
(17934, 0, 0, 'Dis no good....', 12, 0, 100, 0, 0, 0, 18501, 0, 'Horde Headhunter say slay'),
(17934, 0, 1, 'Take their heads!', 12, 0, 100, 0, 0, 0, 18499, 0, 'Horde Headhunter say slay'),
(17934, 0, 2, 'We kill \'em good, mon.', 12, 0, 100, 0, 0, 0, 18500, 0, 'Horde Headhunter say slay'),
(17934, 0, 3, 'You stay dead.', 12, 0, 100, 0, 0, 0, 18503, 0, 'Horde Headhunter say slay'),
(17934, 0, 4, 'Da Legion gonna pay.', 12, 0, 100, 0, 0, 0, 18504, 0, 'Horde Headhunter say slay'),
(17934, 1, 0, 'It all over... now.', 12, 0, 100, 0, 0, 0, 18502, 0, 'Horde Headhunter say death'),
(17932, 0, 0, 'Destroy them all!', 12, 0, 100, 0, 0, 0, 18486, 0, 'Horde Grunt say slay'),
(17932, 0, 1, 'Have at them! Lok-Tar!', 12, 0, 100, 0, 0, 0, 18485, 0, 'Horde Grunt say slay'),
(17932, 0, 2, 'Spill their... blood!', 12, 0, 100, 0, 0, 0, 18488, 0, 'Horde Grunt say slay'),
(17932, 0, 3, 'Another one down!', 12, 0, 100, 0, 0, 0, 18490, 0, 'Horde Grunt say slay'),
(17932, 0, 4, 'Demon filth!', 12, 0, 100, 0, 0, 0, 18489, 0, 'Horde Grunt say slay'),
(17932, 1, 0, 'Keep... fighting!', 12, 0, 100, 0, 0, 0, 18487, 0, 'Horde Grunt say death'),
(17933, 0, 0, 'For the Earth Mother!', 12, 0, 100, 0, 0, 0, 18493, 0, 'Tauren Warrior say slay'),
(17933, 0, 1, 'Crush them!', 12, 0, 100, 0, 0, 0, 18494, 0, 'Tauren Warrior say slay'),
(17933, 0, 2, 'Balance must be restored!', 12, 0, 100, 0, 0, 0, 18497, 0, 'Tauren Warrior say slay'),
(17933, 0, 3, 'This world is not for you!', 12, 0, 100, 0, 0, 0, 18498, 0, 'Tauren Warrior say slay'),
(17933, 1, 0, 'I return... to the earth.', 12, 0, 100, 0, 0, 0, 18495, 0, 'Tauren Warrior say death'),
(17933, 1, 1, 'My spirit... goes on.', 12, 0, 100, 0, 0, 0, 18496, 0, 'Tauren Warrior say death'),
(17936, 0, 1, 'I am one... with all.', 12, 0, 100, 0, 0, 0, 18510, 0, 'Horde Shaman say slay'),
(17936, 1, 0, 'My spirit... goes on.', 12, 0, 100, 0, 0, 0, 18496, 0, 'Horde Shaman say death'),
(17772, 7, 0, '%s begins channelling a massive teleport spell. ', 16, 0, 100, 0, 0, 0, 15310, 0, 'jaina hyjal horde base SUCCESS');

-- enable gargoyle frost wyrm fly
DELETE FROM `creature_template_movement` WHERE `CreatureID` IN (17906,17907);
INSERT INTO `creature_template_movement`(`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(17906, 0, 0, 1, 0, 0, 0, NULL),
(17907, 0, 0, 1, 0, 0, 0, NULL);

-- add protection of elune(38528) spell script
DELETE FROM `spell_script_names` WHERE `spell_id`=38528;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(38528,'spell_protection_of_elune');

-- change wrong position and movement type of worldtree channel target
UPDATE `creature` SET `position_x`=5502.2876, `position_y`=-3525.4714, `position_z`=1607.9094, `orientation`=2.61799, `MovementType`=0 WHERE `guid`=22418;

-- update doomfire(18095) and doomfire_spirit(18104) flag_extra to 128
UPDATE `creature_template` SET `flags_extra` = `flags_extra`|128 WHERE `entry` IN (18095,18104);

-- add say slay and death text for guards
DELETE FROM `smart_scripts` WHERE (`entryorguid`,`source_type`,`id`,`link`) IN ((17919,0,1,0),(17919,0,2,0),(17932,0,1,0),(17932,0,2,0),(17933,0,1,0),(17933,0,2,0),(17934,0,0,0),(17934,0,1,0),(17936,0,3,0),(17936,0,4,0));
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17919, 0, 1, 0, 5, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Alliance Footman - In Combat - Say Slay'),
(17919, 0, 2, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Alliance Footman - In Combat - Say Death'),
(17932, 0, 1, 0, 5, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Horde Grunt - In Combat - Say Slay'),
(17932, 0, 2, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Horde Grunt - In Combat - Say Death'),
(17933, 0, 1, 0, 5, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Tauren Warrior - In Combat - Say Slay'),
(17933, 0, 2, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Tauren Warrior - In Combat - Say Death'),
(17934, 0, 0, 0, 5, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Horde Headhunter - In Combat - Say Slay'),
(17934, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Horde Headhunter - In Combat - Say Death'),
(17936, 0, 3, 0, 5, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Horde Shaman - In Combat - Say Slay'),
(17936, 0, 4, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Horde Shaman - In Combat - Say Death');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (17919,17934,17932,17933,17936);
