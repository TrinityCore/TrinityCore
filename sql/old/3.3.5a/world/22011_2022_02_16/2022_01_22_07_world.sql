-- Sarannis
DELETE FROM `spell_script_names` WHERE `spell_id` = 34799 AND `ScriptName` = 'spell_commander_sarannis_arcane_devastation';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(34799,'spell_commander_sarannis_arcane_devastation');

UPDATE `creature_addon` SET `auras` = '34792 19818' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 17976);

DELETE FROM `creature_text` WHERE `CreatureID` = 17976;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(17976,0,0,"Step forward.  I will see that you are properly welcomed!",14,0,100,0,0,11071,19936,0,"Commander Sarannis SAY_AGGRO"),
(17976,1,0,"Oh, stop your whimpering!",14,0,100,0,0,11072,19937,0,"Commander Sarannis SAY_SLAY"),
(17976,1,1,"Mission accomplished!",14,0,100,0,0,11073,19938,0,"Commander Sarannis SAY_SLAY"),
(17976,2,0,"You are no longer dealing with some underling!",14,0,100,0,0,11076,19939,0,"Commander Sarannis SAY_ARCANE_DEVASTATION"),
(17976,2,1,"Band'or shorel'aran!",14,0,100,0,0,11077,19940,0,"Commander Sarannis SAY_ARCANE_DEVASTATION"),
(17976,3,0,"%s calls for reinforcements!",16,0,100,0,0,0,17562,0,"Commander Sarannis EMOTE_SUMMON"),
(17976,4,0,"Guards, rally!  Cut these invaders down!",14,0,100,0,0,11078,19941,0,"Commander Sarannis SAY_SUMMON"),
(17976,5,0,"I have not yet... begun to...",14,0,100,0,0,11079,19942,0,"Commander Sarannis SAY_DEATH");

-- Freywinn
DELETE FROM `creature_text` WHERE `CreatureID` = 17975;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(17975,0,0,"What are you doing?  These specimens are very delicate!",14,0,100,0,0,11144,19944,0,"High Botanist Freywinn SAY_AGGRO"),
(17975,1,0,"Your life cycle is now concluded.",14,0,100,0,0,11145,19945,0,"High Botanist Freywinn SAY_SLAY"),
(17975,1,1,"You will feed the worms.",14,0,100,0,0,11146,19946,0,"High Botanist Freywinn SAY_SLAY"),
(17975,2,0,"Endorel anuminor!",14,0,100,0,0,11147,19947,0,"High Botanist Freywinn SAY_TREE"),
(17975,2,1,"Nature bends to my will....",14,0,100,0,0,11148,19948,0,"High Botanist Freywinn SAY_TREE"),
(17975,3,0,"The specimens... must be preserved.",14,0,100,0,0,11149,19949,0,"High Botanist Freywinn SAY_DEATH"),
(17975,4,0,"...mumble...Petals of Fire...mumble...",12,0,100,0,0,0,16945,0,"High Botanist Freywinn SAY_OOC_RANDOM"),
(17975,4,1,"...mumble mumble...",12,0,100,0,0,0,16946,0,"High Botanist Freywinn SAY_OOC_RANDOM"),
(17975,4,2,"...thorny vines...mumble...ouch!",12,0,100,0,0,0,16947,0,"High Botanist Freywinn SAY_OOC_RANDOM"),
(17975,4,3,"...with the right mixture, perhaps...",12,0,100,0,0,0,16948,0,"High Botanist Freywinn SAY_OOC_RANDOM");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19958,19962,19964,19969,19953) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19958,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"White Seedling - On AI Initialize - Set Corpse Delay"),
(19958,0,1,0,63,0,100,0,0,0,0,0,0,11,34770,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"White Seedling - On Just Created - Cast 'Plant Spawn Effect'"),
(19958,0,2,0,0,0,100,0,5000,10000,5000,10000,0,11,34752,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"White Seedling - In Combat - Cast 'Freezing Touch'"),

(19962,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blue Seedling - On AI Initialize - Set Corpse Delay"),
(19962,0,1,0,63,0,100,0,0,0,0,0,0,11,34770,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blue Seedling - On Just Created - Cast 'Plant Spawn Effect'"),
(19962,0,2,0,63,0,100,0,0,0,0,0,0,11,34781,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blue Seedling - On Just Created - Cast 'Bind Feet'"),

(19964,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Red Seedling - On AI Initialize - Set Corpse Delay"),
(19964,0,1,0,63,0,100,0,0,0,0,0,0,11,34770,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Red Seedling - On Just Created - Cast 'Plant Spawn Effect'"),
(19964,0,2,0,0,0,100,0,5000,10000,5000,10000,0,11,36339,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Red Seedling - In Combat - Cast 'Fire Blast'"),

(19969,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Green Seedling - On AI Initialize - Set Corpse Delay"),
(19969,0,1,0,63,0,100,0,0,0,0,0,0,11,34770,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Green Seedling - On Just Created - Cast 'Plant Spawn Effect'"),
(19969,0,2,0,63,0,100,0,0,0,0,0,0,11,34757,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Green Seedling - On Just Created - Cast 'Toxic Pollen'"),

(19953,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Frayer Protector - On AI Initialize - Set Corpse Delay"),
(19953,0,1,0,0,0,100,0,0,0,2000,4000,0,11,34745,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Frayer Protector - In Combat CMC - Cast 'Shoot Thorns'"),
(19953,0,2,0,6,0,100,0,0,0,0,0,0,11,34777,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Frayer Protector - On Death - Cast 'Cancel Tranquility'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 34777;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,34777,0,0,31,0,3,17975,0,0,0,0,"","Group 0: Spell 'Cancel Tranquility' (Effect 0) targets creature 'High Botanist Freywinn'");
