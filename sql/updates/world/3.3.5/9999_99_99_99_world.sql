UPDATE `creature_template` SET `ScriptName`='npc_felguard_degrader' WHERE `entry`=23055;
UPDATE `creature_template` SET `ScriptName`='boss_doomguard_punisher' WHERE `entry`=23113;
UPDATE `creature_template` SET `ScriptName`='boss_shivan_assassin' WHERE `entry`=23220;
UPDATE `creature_template` SET `ScriptName`='boss_shartuul' WHERE `entry`=23230;
UPDATE `creature_template` SET `ScriptName`='npc_warp_gate_shield' WHERE `entry`=23116;
UPDATE `creature_template` SET `ScriptName`='npc_shield_zapper' WHERE `entry`=23500;
UPDATE `creature_template` SET `ScriptName`='npc_overseer_shartuul' WHERE `entry`=23063;

UPDATE `creature_template` SET `flags_extra`=66, `ScriptName`='boss_eye_of_shartuul' WHERE `entry`=23228;
UPDATE `creature_template` SET `flags_extra`=66, `ScriptName`='boss_dreadmaw' WHERE `entry`=23275;
UPDATE `creature_template` SET `flags_extra`=64, `ScriptName`='npc_fel_imp_defender' WHERE `entry`=23078;
UPDATE `creature_template` SET `flags_extra`=64, `ScriptName`='npc_felhound_defender' WHERE `entry`=23173;
UPDATE `creature_template` SET `flags_extra`=64, `ScriptName`='npc_moarg_tormenter' WHERE `entry`=23212;
UPDATE `creature_template` SET `flags_extra`=64, `ScriptName`='npc_ganarg_underling' WHERE `entry`=23199;
UPDATE `creature_template` SET `flags_extra`=64, `ScriptName`='npc_portable_fel_cannon' WHERE `entry`=23278;
UPDATE `creature_template` SET `flags_extra`=64, `ScriptName`='npc_fel_eye_stalk' WHERE `entry`=23323;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (40309, 41593, 41594, 41595, 40784, 40565, 40675, 40493, 40503, 41962);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(40309, 'spell_shartuuls_transporter_possess_demon'),
(41593, 'spell_shartuuls_transporter_aspects'),
(41594, 'spell_shartuuls_transporter_aspects'),
(41595, 'spell_shartuuls_transporter_aspects'),
(40784, 'spell_shartuuls_transporter_summon_stun_trap'),
(40565, 'spell_shartuuls_transporter_consume_essence'),
(40675, 'spell_shartuuls_transporter_build_portable_fel_cannon'),
(40493, 'spell_shartuuls_transporter_super_jump'),
(40503, 'spell_shartuuls_transporter_possession_transfer'),
(41962, 'spell_shartuuls_transporter_possession_transfer');

-- Arena Boundaries and Overseer
DELETE FROM `creature` WHERE `guid` IN (230072, 230073, 230074, 230075, 230079);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(230072, 23059, 530, 0, 0, 1, 1, 0, 0, 2640.37, 7089.21, 371.327, 2.28263, 300, 0, 0, 4979, 0, 0, 0, 33554432, 0, '', 0),
(230073, 23059, 530, 0, 0, 1, 1, 0, 0, 2698.23, 7184.25, 371.327, 0.173832, 300, 0, 0, 4979, 0, 0, 0, 33554432, 0, '', 0),
(230074, 23059, 530, 0, 0, 1, 1, 0, 0, 2798.41, 7135.72, 371.327, 3.51963, 300, 0, 0, 4979, 0, 0, 0, 33554432, 0, '', 0),
(230075, 23059, 530, 0, 0, 1, 1, 0, 0, 2741.68, 7046.69, 371.327, 1.76821, 300, 0, 0, 4979, 0, 0, 0, 33554432, 0, '', 0),
(230079, 23063, 530, 0, 0, 1, 1, 0, 0, 2720.74, 7118.42, 393.85, 4.78097, 300, 0, 0, 6722, 0, 0, 0, 33554432, 0, '', 0);

-- Shield Zappers is in the center of the arena
DELETE FROM `creature` WHERE `guid` IN (230098, 230099, 230102, 230103);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(230098, 23500, 530, 0, 0, 1, 1, 0, 0, 2713.58, 7117.04, 381.815, 0.548783, 300, 0, 0, 4979, 0, 0, 0, 33554432, 0, '', 0),
(230099, 23500, 530, 0, 0, 1, 1, 0, 0, 2717.87, 7122.89, 381.708, 5.11982, 300, 0, 0, 4979, 0, 0, 0, 33554432, 0, '', 0),
(230102, 23500, 530, 0, 0, 1, 1, 0, 0, 2721.63, 7112.49, 381.709, 2.64287, 300, 0, 0, 4979, 0, 0, 0, 33554432, 0, '', 0),
(230103, 23500, 530, 0, 0, 1, 1, 0, 0, 2726, 7119.11, 381.659, 3.50053, 300, 0, 0, 4979, 0, 0, 0, 33554432, 0, '', 0);

-- Changes to make the trigger NPCs levitate
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (23116, 23500, 23063, 23328, 23260, 23059);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(23116, 1, 1, 1, 0, 0, 0, NULL),
(23500, 1, 1, 1, 0, 0, 0, NULL),
(23063, 1, 1, 1, 0, 0, 0, NULL),
(23328, 0, 0, 1, 0, 0, 0, NULL),
(23260, 0, 0, 1, 0, 0, 0, NULL),
(23059, 0, 0, 1, 0, 0, 0, NULL);

-- Adding spells for Felguard Degrader
DELETE FROM `creature_template_spell` WHERE `CreatureID`=23055;
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES
(23055, 0, 40220, 12340),
(23055, 1, 40219, 12340),
(23055, 2, 40221, 12340),
(23055, 3, 40497, 12340),
(23055, 4, 40222, 12340),
(23055, 5, 40658, 12340);

-- Adding spells for Doomguard Punisher
DELETE FROM `creature_template_spell` WHERE `CreatureID`=23113;
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES
(23113, 0, 40560, 12340),
(23113, 1, 40561, 12340),
(23113, 2, 40563, 12340),
(23113, 3, 40493, 12340),
(23113, 4, 40565, 12340),
(23113, 5, 40659, 12340);

-- Adding spells for Shivan Assassin
DELETE FROM `creature_template_spell` WHERE `CreatureID`=23220;
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES
(23220, 0, 40736, 12340),
(23220, 1, 41597, 12340),
(23220, 2, 40737, 12340),
(23220, 3, 41593, 12340),
(23220, 4, 41594, 12340),
(23220, 5, 40741, 12340);

-- Adding spells for Shivan Assassin (Red)
DELETE FROM `creature_template_spell` WHERE `CreatureID`=23474;
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES
(23474, 0, 41578, 12340),
(23474, 1, 41596, 12340),
(23474, 2, 41589, 12340),
(23474, 3, 41595, 12340),
(23474, 4, 41594, 12340),
(23474, 5, 40741, 12340);

-- Adding spells for Shivan Assassin (Blue)
DELETE FROM `creature_template_spell` WHERE `CreatureID`=23475;
INSERT INTO `creature_template_spell` (`CreatureID`, `Index`, `Spell`, `VerifiedBuild`) VALUES
(23475, 0, 41579, 12340),
(23475, 1, 40727, 12340),
(23475, 2, 41590, 12340),
(23475, 3, 41593, 12340),
(23475, 4, 41595, 12340),
(23475, 5, 40741, 12340);

-- Replicas spoken by Overseer Shartuul
DELETE FROM `creature_text` WHERE `CreatureID`=23063;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23063, 0, 0, 'This is an outrage! Your disobedience shall not go unpunished!', 15, 0, 100, 0, 0, 0, 20825, 2, 'Overseer Shartuul'),
(23063, 0, 1, 'You are no stranger to the Legion, scum. Surely, you know what torment awaits you...', 15, 0, 100, 0, 0, 0, 21036, 2, 'Overseer Shartuul'),
(23063, 0, 2, 'What manner of deception is this!? Who turns my underlings against me?', 15, 0, 100, 0, 0, 0, 21111, 2, 'Overseer Shartuul'),
(23063, 0, 3, 'Whoever you are, trespasser, I shall make an example of you!', 15, 0, 100, 0, 0, 0, 21337, 2, 'Overseer Shartuul'),
(23063, 0, 4, 'You cannot withstand the power of my forces!', 15, 0, 100, 0, 0, 0, 21129, 2, 'Overseer Shartuul'),
(23063, 0, 5, 'Peer inside the warp-gate if you dare. I\'ve prepared something special for you...', 15, 0, 100, 0, 0, 0, 21130, 2, 'Overseer Shartuul'),
(23063, 1, 0, 'Traitor! You\'ve struck the shield! Your fate is sealed...', 15, 0, 100, 0, 0, 0, 21140, 2, 'Overseer Shartuul'),
(23063, 2, 0, 'Back to your patrol, worm! That shield is more valuable to me than a hundred of you...', 15, 0, 100, 0, 0, 0, 20824, 2, 'Overseer Shartuul'),
(23063, 3, 0, 'Your pathetic efforts shall yield you nothing but pain.', 15, 0, 100, 0, 0, 0, 21148, 2, 'Overseer Shartuul'),
(23063, 4, 0, 'Very well, intruder. You have earned my undivided attention...', 15, 0, 100, 0, 0, 0, 21248, 2, 'Overseer Shartuul'),
(23063, 5, 0, 'Dreadmaw! You shall pay dearly, trespasser...', 15, 0, 100, 0, 0, 0, 21469, 2, 'Overseer Shartuul'),
(23063, 6, 0, 'Aargh! If I must fall, I\'m taking you with me!', 15, 0, 100, 0, 0, 0, 21466, 2, 'Overseer Shartuul');

-- Replicas spoken by Gan\arg Underling
DELETE FROM `creature_text` WHERE `CreatureID`=23199;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23199, 0, 0, 'I gotcha boss!', 12, 0, 10, 0, 0, 0, 21296, 0, 'Gan\'arg Underling'),
(23199, 0, 1, 'I\'m coming, boss!', 12, 0, 10, 0, 0, 0, 21297, 0, 'Gan\'arg Underling'),
(23199, 0, 2, 'Looks like that hurt!', 12, 0, 10, 0, 0, 0, 21298, 0, 'Gan\'arg Underling'),
(23199, 1, 0, 'Repair module activated!', 12, 0, 100, 0, 0, 0, 21299, 0, 'Gan\'arg Underling');

-- Replicas spoken by Shartuul
DELETE FROM `creature_text` WHERE `CreatureID`=23230;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23230, 0, 0, 'Now you shall witness the meaning of true power!', 14, 0, 100, 0, 0, 0, 21283, 0, 'Shartuul'),
(23230, 1, 0, 'Prepare to be incinerated!', 14, 0, 100, 0, 0, 0, 21965, 0, 'Shartuul');

-- Replicas spoken by Eye of Shartuul
DELETE FROM `creature_text` WHERE `CreatureID`=23228;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(23228, 0, 0, '%s focuses intensely!', 41, 0, 100, 0, 0, 0, 22000, 3, 'Eye of Shartuul');

-- Replicas spoken by Dreadmaw
DELETE FROM `creature_text` WHERE `CreatureID`=23275;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(23275, 0, 0, '%s lashes out, opening a large gash on $n!', 41, 0, 100, 0, 0, 0, 21987, 3, 'Dreadmaw');

-- Set an implicit target for the "Shield of Shattering" spell
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup` IN (1, 2) AND `SourceEntry`=40222 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=23116 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 40222, 0, 0, 31, 0, 3, 23116, 0, 0, 0, 0, '', NULL),
(13, 2, 40222, 0, 0, 31, 0, 3, 23116, 0, 0, 0, 0, '', NULL);

-- Set an implicit target for the "Possess Demon" and "Possession Transfer(Doom Punisher)" spells
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry` IN (40309, 40503)AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=23055 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 40309, 0, 0, 31, 0, 3, 23055, 0, 0, 0, 0, '', NULL),
(13, 1, 40503, 0, 0, 31, 0, 3, 23055, 0, 0, 0, 0, '', NULL);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=39985 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=23055 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 39985, 0, 0, 31, 0, 3, 23055, 0, 0, 0, 0, '', NULL);

-- Set an implicit target for the "Build Portable Fel Cannon" and "Possession Transfer (Shivan Assassin)" spells
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry` IN (40675, 41962)AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=23113 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 40675, 0, 0, 31, 0, 3, 23113, 0, 0, 0, 0, '', NULL),
(13, 1, 41962, 0, 0, 31, 0, 3, 23113, 0, 0, 0, 0, '', NULL);

-- Set implicit targets for the "Legion Ring - Charm - North 02 (Possess)" and "Legion Ring - Charm - North 03 (Possess)" spells
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry` IN (40382, 40523) AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2` IN (23113, 23220) AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 40382, 0, 0, 31, 0, 3, 23113, 0, 0, 0, 0, '', NULL),
(13, 1, 40523, 0, 0, 31, 0, 3, 23220, 0, 0, 0, 0, '', NULL);

-- Set implicit targets for the "Madness Rift" and "Touch of Madness" spells
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry` IN (40824, 40821) AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2` IN (23323, 23063) AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 40824, 0, 0, 31, 0, 3, 23323, 0, 0, 0, 0, '', NULL),
(13, 1, 40821, 0, 0, 31, 0, 3, 23063, 0, 0, 0, 0, '', NULL);
