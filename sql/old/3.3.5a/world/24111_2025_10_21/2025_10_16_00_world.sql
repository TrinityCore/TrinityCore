--
UPDATE `spell_dbc` SET `RangeIndex`= 12, `ProcChance` = 101, `Effect1` = 140, `EffectImplicitTargetA1` = 25, `EffectTriggerSpell1` = 47681 WHERE `Id` = 47680;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 47681;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,47681,0,0,31,0,3,26811,0,0,0,0,"","Group 0: Spell 'Aggro Ancient Drakkari' (Effect 0) targets creature 'Ancient Drakkari Warmonger'"),
(13,1,47681,0,1,31,0,3,26812,0,0,0,0,"","Group 1: Spell 'Aggro Ancient Drakkari' (Effect 0) targets creature 'Ancient Drakkari Soothsayer'");

DELETE FROM `creature_text` WHERE `CreatureID` IN (26811,26812) AND `GroupID` = 1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(26811,1,0,"You take my heart, now I take yours!",12,0,100,0,0,0,26085,0,"Ancient Drakkari Warmonger"),
(26811,1,1,"Why ya wanna mess wit me innards, mon?",12,0,100,0,0,0,26086,0,"Ancient Drakkari Warmonger"),
(26811,1,2,"Dat me liver you be squeezin, mon!",12,0,100,0,0,0,26087,0,"Ancient Drakkari Warmonger"),
(26811,1,3,"Come back here with me guts, $r!",12,0,100,0,0,0,26088,0,"Ancient Drakkari Warmonger"),

(26812,1,0,"You take my heart, now I take yours!",12,0,100,0,0,0,26085,0,"Ancient Drakkari Soothsayer"),
(26812,1,1,"Why ya wanna mess wit me innards, mon?",12,0,100,0,0,0,26086,0,"Ancient Drakkari Soothsayer"),
(26812,1,2,"Dat me liver you be squeezin, mon!",12,0,100,0,0,0,26087,0,"Ancient Drakkari Soothsayer"),
(26812,1,3,"Come back here with me guts, $r!",12,0,100,0,0,0,26088,0,"Ancient Drakkari Soothsayer");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 26811 AND `source_type` = 0 AND `id` IN (12,13);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 26812 AND `source_type` = 0 AND `id` IN (21,22);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26811,0,12,0,8,0,100,0,47681,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Ancient Drakkari Warmonger - On Spellhit 'Aggro Ancient Drakkari' - Say Line 1"),
(26811,0,13,0,8,0,100,0,47681,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Ancient Drakkari Warmonger - On Spellhit 'Aggro Ancient Drakkari' - Start Attacking"),

(26812,0,21,0,8,0,100,0,47681,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Ancient Drakkari Soothsayer - On Spellhit 'Aggro Ancient Drakkari' - Say Line 1"),
(26812,0,22,0,8,0,100,0,47681,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Ancient Drakkari Soothsayer - On Spellhit 'Aggro Ancient Drakkari' - Start Attacking");
