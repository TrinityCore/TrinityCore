-- Add Conditions for Deathly Usher gossip
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=1541;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,1541,0,0,0,9,0,3628,0,0,0,0,0, '', 'Gossip Option - Show Option if Quest 9537 is taken'),
(15,1541,0,0,1,2,0,10757,1,0,0,0,0, '', 'Gossip Option - Show Option if player has item 10757');

DELETE FROM `spell_script_names` WHERE `spell_id`=27686;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(27686, 'spell_razelikh_teleport_group');
