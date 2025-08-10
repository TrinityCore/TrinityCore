-- Return To Myralion Sunblaze
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-202775,-202776,-202777,-202778) AND `source_type` = 0 AND `action_type` = 75;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3784600 AND `source_type` = 9 AND `id` IN (4,5);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 71365;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,71365,0,0,31,0,3,36656,0,0,0,0,"","Group 0: Spell 'Freeze Guards' (Effect 0) targets creature 'Silver Covenant Sentinel'"),
(13,1,71365,0,1,31,0,3,36657,0,0,0,0,"","Group 1: Spell 'Freeze Guards' (Effect 0) targets creature 'Sunreaver War Mage'");

-- Archmage Pentarus' Flying Machine
UPDATE `smart_scripts` SET `action_type` = 11 WHERE `entryorguid` = 2819202 AND `source_type` = 9 AND `action_type` = 75;
