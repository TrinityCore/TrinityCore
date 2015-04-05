UPDATE `creature_template` SET `unit_flags`=0 WHERE  `entry`=19527;

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry`=19527;

DELETE FROM `smart_scripts` WHERE `entryorguid`=19527  AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19527,0,0,0,4,0,100,0,0,0,0,0,11,34524,2,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Just Summoned - Cast Elemental Response'),
(19527,0,1,0,2,0,100,1,0,10,0,0,11,34842,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Less than 10% HP - Cast De-Materialize'),
(19527,0,2,0,8,0,100,0,34842,0,0,0,41,0,2,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit De-Materialize  - Despawn'),
(19527,0,3,0,4,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Agro - Set Phase 1'),
(19527,0,4,17,8,1,100,0,0,2,0,0,11,34336,2,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Holy) (Phase 1) - Cast Damage Reduction: Holy'),
(19527,0,5,18,8,1,100,0,0,4,0,0,11,34333,2,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Fire) (Phase 1) - Cast Damage Reduction: Fire'),
(19527,0,6,19,8,1,100,0,0,8,0,0,11,34335,2,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Nature)(Phase 1) - Cast Damage Reduction: Nature'),
(19527,0,7,20,8,1,100,0,0,16,0,0,11,34334,2,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Frost) (Phase 1) - Cast Damage Reduction: Frost'),
(19527,0,8,21,8,1,100,0,0,32,0,0,11,34338,2,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Shadow) (Phase 1)  - Cast Damage Reduction: Shadow'),
(19527,0,9,22,8,1,100,0,0,64,0,0,11,34331,2,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Arcane) (Phase 1)  - Cast Damage Reduction: Arcane'),
(19527,0,10,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - Link - Set Phase 2'),
(19527,0,11,0,0,2,100,0,0,0,2000,3000,11,34348,64,0,0,0,0,2,0,0,0,0,0,0,0,'Vacillating Voidcaller - IC (Phase 2)  - Cast Fireball'),
(19527,0,12,0,0,2,100,0,0,0,5000,6000,11,34446,64,0,0,0,0,2,0,0,0,0,0,0,0,'Vacillating Voidcaller - IC (Phase 2)  - Cast Arcane Missiles'),
(19527,0,13,0,0,2,100,0,0,0,2000,3000,11,34347,64,0,0,0,0,2,0,0,0,0,0,0,0,'Vacillating Voidcaller - IC (Phase 2)  - Cast Frost Bolt'),
(19527,0,14,0,0,2,100,0,0,0,2000,3000,11,34346,64,0,0,0,0,2,0,0,0,0,0,0,0,'Vacillating Voidcaller - IC (Phase 2)  - Cast Holy Bolt'),
(19527,0,15,0,0,2,100,0,0,0,2000,3000,11,34345,64,0,0,0,0,2,0,0,0,0,0,0,0,'Vacillating Voidcaller - IC (Phase 2)  - Cast Lightning Bolt'),
(19527,0,16,0,0,2,100,0,0,0,2000,3000,11,34344,64,0,0,0,0,2,0,0,0,0,0,0,0,'Vacillating Voidcaller - IC (Phase 2)  - Cast Shadow Bolt'),
(19527,0,17,10,61,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Holy) (Phase 1) - Say'),
(19527,0,18,10,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Fire) (Phase 1) - Say'),
(19527,0,19,10,61,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Nature)(Phase 1) - Say'),
(19527,0,20,10,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Frost) (Phase 1) - Say'),
(19527,0,21,10,61,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Shadow) (Phase 1)  - Say'),
(19527,0,22,10,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vacillating Voidcaller - On Spellhit (Arcane) (Phase 1)  - Say');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=19527;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 12, 19527, 0, 0, 1, 1, 34333, 0, 0, 0, 0, 0, '', 'Vacillating Voidcaller requires Damage Reduction: Fire to cast Fireball'),
(22, 13, 19527, 0, 0, 1, 1, 34331, 0, 0, 0, 0, 0, '', 'Vacillating Voidcaller requires Damage Reduction: Arcane to cast Arcane Missiles'),
(22, 14, 19527, 0, 0, 1, 1, 34334, 0, 0, 0, 0, 0, '', 'Vacillating Voidcaller requires Damage Reduction: Frost to cast Frost Bolt'),
(22, 15, 19527, 0, 0, 1, 1, 34336, 0, 0, 0, 0, 0, '', 'Vacillating Voidcaller requires Damage Reduction: Holy to cast Holy Bolt'),
(22, 16, 19527, 0, 0, 1, 1, 34335, 0, 0, 0, 0, 0, '', 'Vacillating Voidcaller requires Damage Reduction: Nature to cast Lightning Bolt'),
(22, 17, 19527, 0, 0, 1, 1, 34338, 0, 0, 0, 0, 0, '', 'Vacillating Voidcaller requires Damage Reduction: Shadow to cast Shadowbolt');

DELETE FROM `creature_text` WHERE `entry`=19527;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`,`BroadcastTextID`) VALUES
(19527, 0, 0, '%s absorbs the fire energy of the attack.', 16, 0, 100, 0, 0, 0, 'Vacillating Voidcaller',17105),
(19527, 1, 0, '%s absorbs the arcane energy of the attack.', 16, 0, 100, 0, 0, 0, 'Vacillating Voidcaller',17109),
(19527, 2, 0, '%s absorbs the frost energy of the attack.', 16, 0, 100, 0, 0, 0, 'Vacillating Voidcaller',17106),
(19527, 3, 0, '%s absorbs the holy energy of the attack.', 16, 0, 100, 0, 0, 0, 'Vacillating Voidcaller',17110),
(19527, 4, 0, '%s absorbs the nature energy of the attack.', 16, 0, 100, 0, 0, 0, 'Vacillating Voidcaller',17107),
(19527, 5, 0, '%s absorbs the shadow energy of the attack.', 16, 0, 100, 0, 0, 0, 'Vacillating Voidcaller',17108);
