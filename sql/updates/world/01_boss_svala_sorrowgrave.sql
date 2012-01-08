-- Arthas text entrys fix by Albis (on Gitgub TC Issue tracker https://github.com/TrinityCore/TrinityCore/issues/4002)
UPDATE `script_texts` SET `sound` = 13855, `type` = 1 WHERE `entry` = -1575022;
UPDATE `script_texts` SET `sound` = 13848, `type` = 1 WHERE `entry` = -1575021;
UPDATE `script_texts` SET `sound` = 13847, `type` = 1 WHERE `entry` = -1575020;
UPDATE `script_texts` SET `sound` = 13845, `type` = 1 WHERE `entry` = -1575019;
UPDATE `script_texts` SET `sound` = 13842, `type` = 1 WHERE `entry` = -1575018;
UPDATE `script_texts` SET `sound` = 13856, `type` = 1 WHERE `entry` = -1575015;
UPDATE `script_texts` SET `sound` = 13857, `type` = 1 WHERE `entry` = -1575016;
UPDATE `script_texts` SET `sound` = 13858, `type` = 1 WHERE `entry` = -1575017;

DELETE FROM `script_texts` WHERE `entry` IN (-1575003, -1575014);
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES 
(24266,-1575003,'Your sacrifice is a testament to your obedience. Indeed you are worthy of this charge. Arise, and forever be known as Svala Sorrowgrave!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14732,1,0,0,'SAY_DIALOG_OF_ARTHAS_1'),
(24266,-1575014,'Your first test awaits you. Destroy our uninvited guests.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,14733,1,0,0,'SAY_DIALOG_OF_ARTHAS_2');

-- And this, fixes her flag so script can be started (credit to ric)
UPDATE `creature_template` SET `unit_flags`=2 WHERE `entry` IN (29281, 30809);
-- ------------------------------------------------------------------------------------------------------------------------

-- Emo fixes based on data from YT Videos, ScriptDev2 forums and Iov's custom SD2 repo https://github.com/Iov/scriptdev2

-- Set Svala's  spawn time
UPDATE `creature` SET `spawntimesecs` = '86400' WHERE `id` = 29281;

-- Update Svala's rank to 1 Elite, prevent corpse despawn after 1 min
UPDATE  `creature_template` SET  `rank` =  '1'  WHERE  `entry` IN (29281, 30809);

-- Set flags_extra = 1 for Svala hero difficulty
UPDATE  `creature_template` SET  `flags_extra` =  '1'  WHERE  `entry` = 30809;

-- Boss and
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

-- "boss_svala_sorrowgrave" script is now merged with "boss_svala" script
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 26668;

-- Spectators escape script
UPDATE `creature_template` SET `ScriptName` = 'npc_spectator' WHERE `entry` = 26667;

-- Change 'mob_ritual_channeler' to 'npc_ritual_channeler'
UPDATE `creature_template` SET `ScriptName` = 'npc_ritual_channeler' WHERE `entry` = 27281;

-- Apply Image of Arthas Visual Effect
DELETE FROM `creature_template_addon` WHERE `entry` = 29280;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
('29280', '0', '0', '0', '1', '0', '54134');

-- Svala Ritual - Player teleport position
DELETE FROM `spell_target_position` WHERE `id` = 48267;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
('48267', '575', '296.632', '-346.075', '90.5474', '4.60767');

-- Svala Ritual - Svala teleport position
DELETE FROM `spell_target_position` WHERE `id` = 48276;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
('48276', '575', '296.651', '-346.293', '108.5474', '1.58');

-- Summon Ritual Channeler positions
DELETE FROM `spell_target_position` WHERE `id` IN (48271, 48274, 48275);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
('48271', '575', '296.42', '-355.01', '90.94', '1.58'),
('48274', '575', '302.36', '-352.01', '90.54', '2.20'),
('48275', '575', '291.39', '-352.01', '90.54', '0.91');

-- Spell script target for flying sword
DELETE FROM `conditions` WHERE `SourceEntry` = 48331 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 0, 48331, 0, 18, 1, 27327, 0, 0, '', NULL);

-- Spell script target for Flame Brazier's (on players only)
DELETE FROM `conditions` WHERE `SourceEntry` = 48246 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 0, 48246, 0, 18, 1, 0, 0, 0, '', NULL);

-- Spell script target for Ritual Strike DMG -- Players and Ritual Target
DELETE FROM `conditions` WHERE `SourceEntry` = 48277 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 0, 48277, 0, 18, 1, 26555, 0, 0, '', NULL),
(13, 0, 48277, 0, 18, 1, 27327, 0, 0, '', NULL);

-- Set same data on heroic ver to triggers
UPDATE `creature_template` SET `InhabitType` = 7, `flags_extra` = 130 WHERE `entry` = 30805;
UPDATE `creature_template` SET `InhabitType` = 7, `flags_extra` = 128 WHERE `entry` = 30771;

-- Paralyze -- Filter targets -- cast only on sacrafacing target
DELETE FROM `spell_script_names` WHERE `spell_id` = 48278;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(48278, 'spell_paralyze_pinnacle');

-- Flame Brazier triggers deletion (will spawn them after activating event 17841 called by spell Call Flames 48258)
DELETE FROM `creature` WHERE `id` = 27273 AND `map` = 575;
DELETE FROM `creature_addon` WHERE `guid` IN (126121, 126122);

-- Add Send Script Event (17841) summon 3 triggers
DELETE FROM `event_scripts` WHERE `id` = 17841;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
('17841', '0', '10', '27273', '10000', '0', '285.6', '-357.5', '91.0833', '5.75959'),
('17841', '3', '10', '27273', '10000', '0', '307', '-357.5', '91.0833', '6.02139'),
('17841', '6', '10', '27273', '10000', '0', '285.6', '-357.5', '91.0833', '5.75959');

-- SmartAI for Flame Brazier's
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 27273;
UPDATE `creature_template` SET `faction_A` = 21, `faction_H` = 21 WHERE `entry` IN (27273, 30771);

-- SmartAI script Flame Brazier's cast Ball of Flame (48246) on random player
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27273;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27273, 0, 0, 0, 1, 0, 100, 1, 100, 100, 100, 100, 11, 48246, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame Brazier - Ball of Flame');

-- Scourge Hulk
DELETE FROM `creature_ai_scripts` WHERE `creature_id` = 26555;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_scourge_hulk' WHERE `entry` = 26555;

-- The Incredible Hulk achievement 2043
DELETE FROM `disables` WHERE `sourceType` = 4 AND `entry` = 7322;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 7322 AND `type` = 11;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
('7322', '11', '0', '0', 'achievement_incredible_hulk');
