/* Texts */

-- Move text used in Svala Sorrowgrave from script_texts to  creature_text
-- Remove old script text for boss_svala.cpp
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1575027 AND -1575015;

DELETE FROM `creature_text` WHERE `entry` IN (26668,29281);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(26668,0,0, 'The sensation is... beyond my imagining. I am yours to command, my king.',14,0,0,0,0,13857, 'Svala Sorrowgrave SAY_DIALOG_WITH_ARTHAS_2'),
(26668,1,0, 'I will be happy to slaughter them in your name! Come, enemies of the Scourge! I will show you the might of the Lich King!',14,0,0,0,0,13858, 'Svala Sorrowgrave SAY_DIALOG_WITH_ARTHAS_3'),
(26668,2,0, 'I will vanquish your soul!',14,0,0,0,0,13842, 'Svala Sorrowgrave SAY_AGGRO'),
(26668,3,0, 'You were a fool to challenge the power of the Lich King!',14,0,0,0,0,13845, 'Svala Sorrowgrave SAY_SLAY_1'),
(26668,3,1, 'Your will is done, my king.',14,0,0,0,0,13847, 'Svala Sorrowgrave SAY_SLAY_2'),
(26668,3,2, 'Another soul for my master.',14,0,0,0,0,13848, 'Svala Sorrowgrave SAY_SLAY_3'),
(26668,4,0, 'Nooo! I did not come this far... to...',14,0,0,0,0,13855, 'Svala Sorrowgrave SAY_DEATH'),
(26668,5,0, 'Your death approaches.',14,0,0,0,0,13850, 'Svala Sorrowgrave SAY_SACRIFICE_1'),
(26668,5,1, 'Go now to my master.',14,0,0,0,0,13851, 'Svala Sorrowgrave SAY_SACRIFICE_2'),
(26668,5,2, 'Your end is inevitable.',14,0,0,0,0,13852, 'Svala Sorrowgrave SAY_SACRIFICE_3'),
(26668,5,3, 'Yor-guul mak!',14,0,0,0,0,13853, 'Svala Sorrowgrave SAY_SACRIFICE_4'),
(26668,5,4, 'Any last words?',14,0,0,0,0,13854, 'Svala Sorrowgrave SAY_SACRIFICE_5'),
(29281,0,0, 'My liege! I have done as you asked, and now beseech you for your blessing!',14,0,0,0,0,13856, 'Svala SAY_DIALOG_WITH_ARTHAS_1');

/* Templates */

UPDATE `creature_template` SET `unit_flags`=2 WHERE `entry` IN (29281, 30809); -- And this, fixes her flag so script can be started (credit to ric)
UPDATE `creature` SET `spawntimesecs`=86400 WHERE `id`=29281; -- Set Svala's  spawn time
UPDATE  `creature_template` SET `flags_extra`=`flags_extra`|1 WHERE `entry`=30809; -- Set flags_extra = 1 for Svala hero difficulty
UPDATE `creature_template` SET `InhabitType`=7, `flags_extra`=`flags_extra`|130 WHERE `entry`=30805; -- Set same data on heroic ver to triggers
UPDATE `creature_template` SET `InhabitType`=7, `flags_extra`=`flags_extra`|128 WHERE `entry`=30771; -- Set same data on heroic ver to triggers

UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`
|1 -- CHARM
|2 -- DISORIENTED
|4 -- DISARM
|8 -- DISTRACT
|16 -- FEAR
|32 -- GRIP
|64 -- ROOT
|128 -- PACIFY
|256 -- SILENCE
|512 -- SLEEP
|1024 -- SNARE
|2048 -- STUN
|4096 -- FREEZE
|8192 -- KNOCKOUT
|65536 -- POLYMORPH
|131072 -- BANISH
|524288 -- SHACKLE
|4194304 -- TURN
|8388608 -- HORROR
|67108864 -- DAZE
|536870912 -- SAPPED
WHERE `entry` IN (29281, 30809, 26668, 30810);

-- Apply Image of Arthas Visual Effect
DELETE FROM `creature_template_addon` WHERE `entry`=29280;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(29280, 0, 0, 0, 1, 0, '54134');

-- Flame Brazier triggers deletion (will spawn them after activating event 17841 called by spell Call Flames 48258)
DELETE FROM `creature` WHERE `id`=27273 AND `map`=575;
DELETE FROM `creature_addon` WHERE `guid` IN (126121, 126122);

/* Spells */

DELETE FROM `spell_target_position` WHERE `id` IN (48267,48276, 48271, 48274, 48275);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(48267, 575, 296.632, -346.075, 90.5474, 4.60767), -- Svala Ritual - Player teleport position
(48276, 575, 296.651, -346.293, 108.5474, 1.58), -- Svala Ritual - Svala teleport position
(48271, 575, 296.42, -355.01, 90.94, 1.58), -- Summon Ritual Channeler positions
(48274, 575, 302.36, -352.01, 90.54, 2.20), -- Summon Ritual Channeler positions
(48275, 575, 291.39, -352.01, 90.54, 0.91); -- Summon Ritual Channeler positions

DELETE FROM `conditions` WHERE `SourceEntry` IN (48331,48246,48277) AND `SourceTypeOrReferenceId`=13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 0, 48331, 0, 18, 1, 27327, 0, 0, '', NULL), -- Spell script target for flying sword
(13, 0, 48246, 0, 18, 1, 0, 0, 0, '', NULL), -- Spell script target for Flame Brazier's (on players only)
(13, 0, 48277, 0, 18, 1, 26555, 0, 0, '', NULL), -- Spell script target for Ritual Strike DMG -- Players
(13, 0, 48277, 0, 18, 1, 27327, 0, 0, '', NULL); -- Spell script target for Ritual Strike DMG -- Ritual Target

/* Achivements */

-- The Incredible Hulk achievement 2043
DELETE FROM `disables` WHERE `sourceType`=4 AND `entry`=7322;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=7322 AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(7322, 11, 0, 0, 'achievement_incredible_hulk');

/* AI */

DELETE FROM `creature_ai_scripts` WHERE `creature_id`=26555; -- Scourge Hulk
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=27273; -- Flame Brazier

-- Add Send Script Event (17841) summon 3 triggers
DELETE FROM `event_scripts` WHERE `id`=17841;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(17841, 0, 10, 27273, 10000, 0, 285.6, -357.5, 91.0833, 5.75959),
(17841, 3, 10, 27273, 10000, 0, 307, -357.5, 91.0833, 6.02139),
(17841, 6, 10, 27273, 10000, 0, 285.6, -357.5, 91.0833, 5.75959);

-- SmartAI script Flame Brazier's cast Ball of Flame (48246) on random player
DELETE FROM `smart_scripts` WHERE `entryorguid`=27273 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27273, 0, 0, 0, 1, 0, 100, 1, 100, 100, 100, 100, 11, 48246, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame Brazier - Ball of Flame');

/* Script names */

UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_scourge_hulk' WHERE `entry`=26555;
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=26668; -- "boss_svala_sorrowgrave" script is now merged with "boss_svala" script
UPDATE `creature_template` SET `ScriptName`='npc_spectator' WHERE `entry`=26667; -- Spectators escape script
UPDATE `creature_template` SET `ScriptName`='npc_ritual_channeler' WHERE `entry`=27281; -- Change 'mob_ritual_channeler' to 'npc_ritual_channeler'

-- Paralyze -- Filter targets -- cast only on sacrafacing target
DELETE FROM `spell_script_names` WHERE `spell_id`=48278;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(48278, 'spell_paralyze_pinnacle');

