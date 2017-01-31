UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry`in(20875);

DELETE FROM `smart_scripts` WHERE `entryorguid`in(20875)  AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20875,0,0,0,4,0,100,0,0,0,0,0,11,36733,2,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Agro - Cast Elemental Response'),
(20875,0,1,0,9,0,100,0,0,8,12000,20000,11,13704,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Range  - Cast Psychic Scream'),
(20875,0,2,0,0,2,100,0,15000,25000,15000,25000,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2) - Set Phase 1'),
(20875,0,3,0,4,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Agro - Set Phase 1'),
(20875,0,4,17,8,1,100,0,0,2,0,0,11,34336,2,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Holy) (Phase 1) - Cast Damage Reduction: Holy'),
(20875,0,5,18,8,1,100,0,0,4,0,0,11,34333,2,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Fire) (Phase 1) - Cast Damage Reduction: Fire'),
(20875,0,6,19,8,1,100,0,0,8,0,0,11,34335,2,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Nature)(Phase 1) - Cast Damage Reduction: Nature'),
(20875,0,7,20,8,1,100,0,0,16,0,0,11,34334,2,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Frost) (Phase 1) - Cast Damage Reduction: Frost'),
(20875,0,8,21,8,1,100,0,0,32,0,0,11,34338,2,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Shadow) (Phase 1)  - Cast Damage Reduction: Shadow'),
(20875,0,9,22,8,1,100,0,0,64,0,0,11,34331,2,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Arcane) (Phase 1)  - Cast Damage Reduction: Arcane'),
(20875,0,10,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - Link - Set Phase 2'),
(20875,0,11,0,0,2,100,0,0,0,3000,3500,11,36742,64,0,0,0,0,2,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2)  - Cast Fireball Volley'),
(20875,0,12,0,0,2,100,0,0,0,3000,3500,11,36738,64,0,0,0,0,2,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2)  - Cast Arcane Volley'),
(20875,0,13,0,0,2,100,0,0,0,3000,3500,11,36741,64,0,0,0,0,2,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2)  - Cast Frostbolt Volley'),
(20875,0,14,0,0,2,100,0,0,0,3000,3500,11,36743,64,0,0,0,0,2,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2)  - Cast Holy Bolt Volley'),
(20875,0,15,0,0,2,100,0,0,0,3000,3500,11,36740,64,0,0,0,0,2,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2)  - Cast Lightning Bolt Volley'),
(20875,0,16,0,0,2,100,0,0,0,3000,3500,11,36736,64,0,0,0,0,2,0,0,0,0,0,0,0,'Negaton Screamer - IC (Phase 2)  - Cast Shadow Bolt Volley'),
(20875,0,17,10,61,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Holy) (Phase 1) - Say'),
(20875,0,18,10,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Fire) (Phase 1) - Say'),
(20875,0,19,10,61,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Nature)(Phase 1) - Say'),
(20875,0,20,10,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Frost) (Phase 1) - Say'),
(20875,0,21,10,61,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Shadow) (Phase 1)  - Say'),
(20875,0,22,10,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Negaton Screamer - On Spellhit (Arcane) (Phase 1)  - Say');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=20875;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 12, 20875, 0, 0, 1, 1, 34333, 0, 0, 0, 0, 0, '', 'Negaton Screamer requires Damage Reduction: Fire to cast Fireball Volley'),
(22, 13, 20875, 0, 0, 1, 1, 34331, 0, 0, 0, 0, 0, '', 'Negaton Screamer requires Damage Reduction: Arcane to cast Arcane Volley'),
(22, 14, 20875, 0, 0, 1, 1, 34334, 0, 0, 0, 0, 0, '', 'Negaton Screamer requires Damage Reduction: Frost to cast Frostbolt Volley'),
(22, 15, 20875, 0, 0, 1, 1, 34336, 0, 0, 0, 0, 0, '', 'Negaton Screamer requires Damage Reduction: Holy to cast Holy Bolt Volley'),
(22, 16, 20875, 0, 0, 1, 1, 34335, 0, 0, 0, 0, 0, '', 'Negaton Screamer requires Damage Reduction: Nature to cast Lightning Bolt Volley'),
(22, 17, 20875, 0, 0, 1, 1, 34338, 0, 0, 0, 0, 0, '', 'Negaton Screamer requires Damage Reduction: Shadow to cast Shadow Bolt Volley');

DELETE FROM `creature_text` WHERE `entry`=20875;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(20875, 0, 0, '%s absorbs the fire energy of the attack.', 16, 0, 100, 0, 0, 0, 'Negaton Screamer',17105),
(20875, 1, 0, '%s absorbs the arcane energy of the attack.', 16, 0, 100, 0, 0, 0, 'Negaton Screamer',17109),
(20875, 2, 0, '%s absorbs the frost energy of the attack.', 16, 0, 100, 0, 0, 0, 'Negaton Screamer',17106),
(20875, 3, 0, '%s absorbs the holy energy of the attack.', 16, 0, 100, 0, 0, 0, 'Negaton Screamer',17110),
(20875, 4, 0, '%s absorbs the nature energy of the attack.', 16, 0, 100, 0, 0, 0, 'Negaton Screamer',17107),
(20875, 5, 0, '%s absorbs the shadow energy of the attack.', 16, 0, 100, 0, 0, 0, 'Negaton Screamer',17108);
