-- Spirit of Angerforge
UPDATE `creature_template` SET `difficulty_entry_1`= 49504 WHERE `entry`= 43119;
-- Spirit of Ironstar
UPDATE `creature_template` SET `difficulty_entry_1`= 49509 WHERE `entry`= 43127;
-- Spirit of Thaurissan
UPDATE `creature_template` SET `difficulty_entry_1`= 49508 WHERE `entry`= 43126;
-- Spirit of Burningeye
UPDATE `creature_template` SET `difficulty_entry_1`= 49512 WHERE `entry`= 43130;
-- Spirit of Moltenfist
UPDATE `creature_template` SET `difficulty_entry_1`= 49507 WHERE `entry`= 43125;
-- Spirit of Anvilrage
UPDATE `creature_template` SET `difficulty_entry_1`= 49510 WHERE `entry`= 43128;
-- Spirit of Shadowforge
UPDATE `creature_template` SET `difficulty_entry_1`= 49511 WHERE `entry`= 43129;
-- Spirit of Corehammer
UPDATE `creature_template` SET `difficulty_entry_1`= 49505 WHERE `entry`= 43122;

UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `speed_walk`= 1.2, `speed_run`= 1, `faction`= 16, `unit_class`= 2, `unit_flags`= 32832, `BaseVariance`= 0.75, `DamageModifier`= 130 WHERE `entry` IN (49504, 49509, 49508, 49512, 49507, 49510, 49511, 49505);
UPDATE `creature_template` SET `ScriptName`= 'npc_bwd_dwarven_spirit' WHERE `entry` IN (43119, 43127, 43126, 43130, 43125, 43128, 43129, 43122);

-- Execution Sentence
UPDATE `creature_template` SET `unit_flags`=33587264, `flags_extra`= 128, `AIName`= 'NullCreatureAI' WHERE `entry`= 43210;
-- Execution Sentence Visual
UPDATE `creature_template` SET `unit_flags`=33587264, `flags_extra`= 128, `AIName`= 'NullCreatureAI' WHERE `entry`= 43206;

DELETE FROM `creature_template_addon` WHERE `entry`= 43206;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `auras`) VALUES
(43206, 50331648, 1, '80736');

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (43210, 43206);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Flight`, `Rooted`) VALUES
(43210, 0, 1, 1),
(43206, 0, 1, 0);

UPDATE `creature_template` SET `mechanic_immune_mask`= 1 | 2 | 8 | 16 | 32 | 64 | 256 | 512 | 2048 | 4096 | 8192 | 65536 | 131072 | 4194304 | 8388608 WHERE `entry` IN (49504, 43119, 49509, 43127, 49508, 43126, 49512, 43130, 49507, 43125, 49510, 43128, 49511, 43129, 49505, 43122);

DELETE FROM `creature_template_addon` WHERE `entry` IN (49504, 43119, 49509, 43127, 49508, 43126, 49512, 43130, 49507, 43125, 49510, 43128, 49511, 43129, 49505, 43122);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES
-- Spirit of Angerforge
(49504, 1, '80611 80762'),
(43119, 1, '80611 80762'),
-- Spirit of Ironstar
(49509, 1, '80611 80767'),
(43127, 1, '80611 80767'),
-- Spirit of Thaurissan
(49508, 1, '80611 80766'),
(43126, 1, '80611 80766'),
-- Spirit of Burningeye
(49512, 1, '80611 80770'),
(43130, 1, '80611 80770'),
-- Spirit of Moltenfist
(49507, 1, '80611 80764'),
(43125, 1, '80611 80764'),
-- Spirit of Anvilrage
(49510, 1, '80611 80768'),
(43128, 1, '80611 80768'),
-- Spirit of Shadowforge
(49511, 1, '80611 80769'),
(43129, 1, '80611 80769'),
-- Spirit of Corehammer
(49505, 1, '80611 80763'),
(43122, 1, '80611 80763');

DELETE FROM `spell_proc` WHERE `SpellId`= 80718;
INSERT INTO `spell_proc` (`SpellId`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`) VALUES
(80718, 3, 2, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_bwd_execution_sentence_visual',
'spell_bwd_execution_sentence',
'spell_bwd_execution_sentence_dummy',
'spell_bwd_stoneblood');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(80729, 'spell_bwd_execution_sentence_visual'),
(80727, 'spell_bwd_execution_sentence'),
(85176, 'spell_bwd_execution_sentence_dummy'),
(80655, 'spell_bwd_stoneblood');

DELETE FROM `conditions` WHERE `SourceEntry` IN (85176, 80876, 80874, 80873, 80877, 80878, 80875, 80871, 80872) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 85176, 0, 0, 31, 0, 3, 43210, 0, 0, 0, '', 'Execution Sentence - Target Execution Sentence'),
(13, 1, 85176, 0, 1, 31, 0, 3, 43206, 0, 0, 0, '', 'Execution Sentence - Target Execution Sentence Visual'),
(13, 1, 80876, 0, 0, 31, 0, 3, 43128, 0, 0, 0, '', 'Bestowal of Moltenfist'),
(13, 1, 80876, 0, 1, 31, 0, 3, 43129, 0, 0, 0, '', 'Bestowal of Moltenfist'),
(13, 1, 80876, 0, 2, 31, 0, 3, 43122, 0, 0, 0, '', 'Bestowal of Moltenfist'),
(13, 1, 80874, 0, 0, 31, 0, 3, 43125, 0, 0, 0, '', 'Bestowal of Anvilrage'),
(13, 1, 80874, 0, 1, 31, 0, 3, 43129, 0, 0, 0, '', 'Bestowal of Anvilrage'),
(13, 1, 80874, 0, 2, 31, 0, 3, 43122, 0, 0, 0, '', 'Bestowal of Anvilrage'),
(13, 1, 80873, 0, 0, 31, 0, 3, 43125, 0, 0, 0, '', 'Bestowal of Shadowforge'),
(13, 1, 80873, 0, 1, 31, 0, 3, 43128, 0, 0, 0, '', 'Bestowal of Shadowforge'),
(13, 1, 80873, 0, 2, 31, 0, 3, 43122, 0, 0, 0, '', 'Bestowal of Shadowforge'),
(13, 1, 80877, 0, 0, 31, 0, 3, 43125, 0, 0, 0, '', 'Bestowal of Corehammer'),
(13, 1, 80877, 0, 1, 31, 0, 3, 43128, 0, 0, 0, '', 'Bestowal of Corehammer'),
(13, 1, 80877, 0, 2, 31, 0, 3, 43129, 0, 0, 0, '', 'Bestowal of Corehammer'),
(13, 1, 80878, 0, 0, 31, 0, 3, 43127, 0, 0, 0, '', 'Bestowal of Angerforge'),
(13, 1, 80878, 0, 1, 31, 0, 3, 43126, 0, 0, 0, '', 'Bestowal of Angerforge'),
(13, 1, 80878, 0, 2, 31, 0, 3, 43130, 0, 0, 0, '', 'Bestowal of Angerforge'),
(13, 1, 80875, 0, 0, 31, 0, 3, 43119, 0, 0, 0, '', 'Bestowal of Ironstar'),
(13, 1, 80875, 0, 1, 31, 0, 3, 43126, 0, 0, 0, '', 'Bestowal of Ironstar'),
(13, 1, 80875, 0, 2, 31, 0, 3, 43130, 0, 0, 0, '', 'Bestowal of Ironstar'),
(13, 1, 80871, 0, 0, 31, 0, 3, 43119, 0, 0, 0, '', 'Bestowal of Thaurissan'),
(13, 1, 80871, 0, 1, 31, 0, 3, 43127, 0, 0, 0, '', 'Bestowal of Thaurissan'),
(13, 1, 80871, 0, 2, 31, 0, 3, 43130, 0, 0, 0, '', 'Bestowal of Thaurissan'),
(13, 1, 80872, 0, 0, 31, 0, 3, 43119, 0, 0, 0, '', 'Bestowal of Burningeye'),
(13, 1, 80872, 0, 1, 31, 0, 3, 43127, 0, 0, 0, '', 'Bestowal of Burningeye'),
(13, 1, 80872, 0, 2, 31, 0, 3, 43126, 0, 0, 0, '', 'Bestowal of Burningeye');

-- Spawn Groups
DELETE FROM `spawn_group_template` WHERE `groupId` IN (435, 436);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(435, 'Blackwing Descent - Dwarven Spirits Left', 4),
(436, 'Blackwing Descent - Dwarven Spirits Left', 4);

DELETE FROM `spawn_group` WHERE `groupId` IN (435, 436);
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(435, 0, 250134),
(435, 0, 250137),
(435, 0, 250138),
(435, 0, 250133),
(436, 0, 250132),
(436, 0, 250136),
(436, 0, 250135),
(436, 0, 250139);
