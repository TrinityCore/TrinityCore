--
UPDATE `creature_template` SET `flags_extra` = `flags_extra` &~ 2, `flags_extra` = `flags_extra` &~ 128, `ScriptName` = 'npc_blackheart_the_inciter_dummy' WHERE `entry` IN (19300,19301,19302,19303,19304);

DELETE FROM `creature_text` WHERE `CreatureID` = 18667;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18667,0,0,"Time for fun!",14,0,100,0,0,10487,16433,0,"Blackheart SAY_CHAOS"),
(18667,1,0,"You'll be sorry!",14,0,100,0,0,10496,17563,0,"Blackheart SAY_AGGRO_1"),
(18667,1,1,"Time to kill!",14,0,100,0,0,10497,17565,0,"Blackheart SAY_AGGRO_2"),
(18667,2,0,"No coming back for you!",14,0,100,0,0,10489,17573,0,"Blackheart SAY_SLAY_1"),
(18667,2,1,"Nice try.",14,0,100,0,0,10490,17575,0,"Blackheart SAY_SLAY_2"),
(18667,2,2,"Now you gone for good!",14,0,100,0,0,10499,17576,0,"Blackheart SAY_SLAY_3"),
(18667,2,3,"You fail!",14,0,100,0,0,10500,17577,0,"Blackheart SAY_SLAY_4"),
(18667,3,0,"This... no... good...",14,0,100,0,0,10501,17569,0,"Blackheart SAY_DEATH");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 45339;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,45339,0,0,31,0,3,19300,0,0,0,0,"","Group 0: Spell 'Inciter Trigger Threat Trigger' (Effect 0) targets creature 'Blackheart the Inciter'"),
(13,1,45339,0,1,31,0,3,19301,0,0,0,0,"","Group 1: Spell 'Inciter Trigger Threat Trigger' (Effect 0) targets creature 'Blackheart the Inciter'"),
(13,1,45339,0,2,31,0,3,19302,0,0,0,0,"","Group 2: Spell 'Inciter Trigger Threat Trigger' (Effect 0) targets creature 'Blackheart the Inciter'"),
(13,1,45339,0,3,31,0,3,19303,0,0,0,0,"","Group 3: Spell 'Inciter Trigger Threat Trigger' (Effect 0) targets creature 'Blackheart the Inciter'"),
(13,1,45339,0,4,31,0,3,19304,0,0,0,0,"","Group 4: Spell 'Inciter Trigger Threat Trigger' (Effect 0) targets creature 'Blackheart the Inciter'");

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_blackheart_incite_chaos_charm';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(33684, 'spell_blackheart_incite_chaos_charm');
