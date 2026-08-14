--
DELETE FROM `creature_text` WHERE `CreatureID` = 7358;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7358,0,0,"You'll never leave this place alive.",14,0,100,0,0,5825,6187,0,"amnennar SAY_AGGRO"),
(7358,1,0,"Too easy.",12,0,100,0,0,5826,6188,0,"amnennar SAY_SLAY"),
(7358,2,0,"I am the hand of the Lich King!",14,0,100,0,0,5827,6192,0,"amnennar SAY_HEALTH_75"),
(7358,3,0,"To me, my servants!",14,0,100,0,0,5828,6189,0,"amnennar SAY_SUMMON_60"),
(7358,4,0,"Come, spirits - attend your master!",14,0,100,0,0,5829,6190,0,"amnennar SAY_SUMMON_30"),
(7358,5,0,"%s begins to summon wraiths out of the freezing cold air!",16,0,100,0,0,0,4483,0,"amnennar EMOTE_SUMMON");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 12660;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,12660,0,0,31,0,3,8585,0,0,0,0,"","Group 0: Spell 'Banish Frost Spectres' (Effect 0) targets creature 'Frost Spectre'");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 8585 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8585,0,0,0,37,0,100,0,0,0,0,0,0,116,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Frost Spectre - On AI Initialize - Set Corpse Delay"),
(8585,0,1,0,8,0,100,0,12660,0,0,0,0,11,3617,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Frost Spectre - On Spellhit 'Banish Frost Spectres' - Cast 'Quiet Suicide'");
