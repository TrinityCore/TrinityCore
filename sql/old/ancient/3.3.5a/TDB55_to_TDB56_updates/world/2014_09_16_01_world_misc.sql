DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(13,17) AND `SourceEntry`=39246; 

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 4, 39246, 0, 0, 31, 0, 3, 22105, 0, 0, 0, 0, '', 'Target needs to be Decrepit Clefthoof'),
(13, 4, 39246, 0, 0, 36, 0, 0, 0, 0, 1, 0, 0, '', 'Target needs to be Decrepit Clefthoof');

UPDATE `spell_dbc` SET `Effect1`=28,`EffectMiscValueB1`=64 WHERE  `Id`IN(39240,39241,39245,39247);

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry` IN(22482,22038);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(22482,22038) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2248200,2203800) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(22482, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mature Bone Sifter - On Just Summoned - Set Passive'),
(22482, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2248200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mature Bone Sifter - On Just Summoned - Run Script'),
(22482, 0, 2, 3, 4, 0, 100, 0, 0, 0, 0, 0, 28, 37751, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mature Bone Sifter - On Agro - Remove Aura - Submerged'),
(22482, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 37752, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mature Bone Sifter - On Agro - Cast Stand'),
(22482, 0, 4, 0, 0, 0, 100, 0, 0, 5000, 3000, 7000, 11, 31747, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Mature Boneshifter <The Bone Emperor> - IC - Cast Poison'),
(22038, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hai shulud <The Bone Emperor> - On Just Summoned - Set Passive'),
(22038, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2203800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hai shulud <The Bone Emperor> - On Just Summoned - Run Script'),
(22038, 0, 2, 3, 4, 0, 100, 0, 0, 0, 0, 0, 28, 37751, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hai shulud <The Bone Emperor> - On Agro - Remove Aura - Submerged'),
(22038, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 37752, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hai shulud <The Bone Emperor> - On Agro - Cast Stand'),
(22038, 0, 4, 0, 0, 0, 100, 0, 0, 3000, 3000, 5000, 11, 31747, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Hai shulud <The Bone Emperor> - On Agro - Cast Poison'),
(2248200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 37751, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mature Bone Sifter - Script - Cast Cast Submerged'),
(2248200, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 37989, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mature Bone Sifter - Script - Cast Tunnel Bore Bone Passive'),
(2248200, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Mature Bone Sifter - Script - Set Agressive'),
(2203800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 37751, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hai shulud <The Bone Emperor> - Script - Cast Cast Submerged'),
(2203800, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 38885, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hai shulud <The Bone Emperor> - Script - Cast Damaging Tunnel Bore Bone Passive'),
(2203800, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hai shulud <The Bone Emperor> - Script - Set Agressive');

DELETE FROM `smart_scripts` WHERE `entryorguid`=22105 AND `id`>2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(22105, 0, 3, 0, 8, 0, 100, 1, 39246, 0, 0, 0, 41, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Decrepit Clefthoof - On Spellhit (Fumping) - Despawn');
