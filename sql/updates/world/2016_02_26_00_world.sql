UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=48351, `comment`='Bombard the Ballistae Kill Credit Bunny - On Spellhit \'Siegesmith Bombs\' - Cast  Bombard the Ballistae: Ballista Bow' WHERE  `entryorguid`=27331 AND `source_type`=0 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `event_param3`=120000, `event_param4`=120000 WHERE  `entryorguid`=27331 AND `source_type`=0 AND `id`=0 AND `link`=1;

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=27331 AND `id`>1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(27331, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48352, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bombard the Ballistae Kill Credit Bunny - On Spellhit \'Siegesmith Bombs\' - Cast Bombard the Ballistae: Ballista Frame'),
(27331, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48353, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bombard the Ballistae Kill Credit Bunny - On Spellhit \'Siegesmith Bombs\' - Cast Bombard the Ballistae: Ballista Missile'),
(27331, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48354, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bombard the Ballistae Kill Credit Bunny - On Spellhit \'Siegesmith Bombs\' - Cast Bombard the Ballistae: Ballista Wheel'),
(27331, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bombard the Ballistae Kill Credit Bunny - On Spellhit \'Siegesmith Bombs\' - Cast Bombard the Ballistae: FX Master'),
(27331, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 11, 52687, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bombard the Ballistae Kill Credit Bunny - On Spellhit \'Siegesmith Bombs\' - Cast Bombard the Ballistae: Knockback'),
(27331, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 70, 120, 0, 0, 0, 0, 0, 20, 188673, 0, 0, 0, 0, 0, 0, 'Bombard the Ballistae Kill Credit Bunny - On Spellhit \'Siegesmith Bombs\' - Despawn GO');

UPDATE `smart_scripts` SET `link`=2 WHERE  `entryorguid`=27331 AND `source_type`=0 AND `id`=1 AND `link`=0;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=48347;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 2, 48347, 0, 0, 31, 0, 5, 188673, 0, 0, 0, 0, '', 'Bombard the Ballistae: FX Master effect #2 targets go 188673');
