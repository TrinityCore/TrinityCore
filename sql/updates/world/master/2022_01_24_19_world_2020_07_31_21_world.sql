-- Rework support for 'Oh Noes, the Tadpoles!' (11560)
-- Source: Sniffs & Wowhead & https://www.youtube.com/watch?v=LLWlj38eRZ4

-- I pressume they should respawn instantly because they despawn after 3 minutes after starting follow player
-- so 3 min + normal respawn time is too much
-- https://youtu.be/LLWlj38eRZ4?t=74 cage is open, https://youtu.be/LLWlj38eRZ4?t=256 cage is closed and murlocs inside it
UPDATE `creature` SET `spawntimesecs` = 1 WHERE `id` = 25201;

-- Everything is handled by spell 45344 which is used by cages when player opens them
-- Removing everything related to cages
UPDATE `gameobject_template` SET `AIName` = "" WHERE `entry` = 187373;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 187373 AND `source_type` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 18737300 AND `source_type` = 9;
-- According to comments and sniffs player can release murlocs with or without quest
-- https://www.wowhead.com/npc=25201/winterfin-tadpole#comments
-- Removing condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 187373 AND `SourceId` = 1;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 25201 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2520100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Doubt we need it because murlocs despawns after 3 minutes and gameobject resets after 90 secs
(25201,0,0,0,11,0,100,0,0,0,0,0,0,32,0,0,0,0,0,0,20,187373,5,0,0,0,0,0,0,"Winterfin Tadpole - On Respawn - Reset Closest Gameobject 'Cage'"),
(25201,0,1,0,11,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Winterfin Tadpole - On Respawn - Set Event Phase 1"),
(25201,0,2,0,1,0,100,0,30000,60000,30000,60000,0,4,8475,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Winterfin Tadpole - Out of Combat - Play Sound 8475"),
-- Do not repeat because the spell may hit them once again
(25201,0,3,0,8,1,50,1,45279,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Winterfin Tadpole - On Spellhit 'Winterfin Tadpole Cage Opened - Player Cast' - Say Line 0 (No Repeat) (Phase 1)"),
(25201,0,4,5,8,1,100,1,45279,0,0,0,0,4,8475,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Winterfin Tadpole - On Spellhit 'Winterfin Tadpole Cage Opened - Player Cast' - Play Sound 8475 (No Repeat) (Phase 1)"),
(25201,0,5,6,61,0,100,0,0,0,0,0,0,33,25201,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Winterfin Tadpole - On Link - Quest Credit 'Oh Noes, the Tadpoles!'"),
(25201,0,6,7,61,0,100,0,0,0,0,0,0,29,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Winterfin Tadpole - On Link - Start Follow Invoker"),
(25201,0,7,8,61,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Winterfin Tadpole - On Link - Set Active"),
(25201,0,8,9,61,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Winterfin Tadpole - On Link - Set Event Phase 0"),
(25201,0,9,0,61,0,100,0,0,0,0,0,0,41,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Winterfin Tadpole - On Link - Despawn (180000)"),
-- If player is not on quest or quest is taken but already completed, close the cage and say alternative text
-- Run only in phase 1 or it will be used by already released murlocs
(25201,0,10,0,8,1,50,0,45279,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Winterfin Tadpole - On Spellhit 'Winterfin Tadpole Cage Opened - Player Cast' - Say Line 1 (Phase 1)"),
(25201,0,11,0,8,1,100,0,45279,0,0,0,0,80,2520100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Winterfin Tadpole - On Spellhit 'Winterfin Tadpole Cage Opened - Player Cast' - Run Script (Phase 1)"),
-- I don't know if we should make gameobject open-able here
-- (2520100,9,0,0,0,0,100,0,1000,1000,0,0,0,118,1,0,0,0,0,0,20,187373,5,0,0,0,0,0,0,"Winterfin Tadpole - On Script - Set Gameobject State Ready (Cage)");
(2520100,9,0,0,0,0,100,0,1000,1000,0,0,0,32,0,0,0,0,0,0,20,187373,5,0,0,0,0,0,0,"Winterfin Tadpole - On Script - Reset Closest Gameobject 'Cage'");

-- Removing condition to check if murloc is alive. They cannot be killed
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 25201 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- The thing is there's always 3 murlocs in cage so last murloc will not follow player because at
-- that moment the quest will be already completed and we can't check if quest is taken and not completed
-- because they should not follow if quest is completed.
-- But that last murloc number 21 should follow, heh
(22,4,25201,0,0,9,0,11560,0,0,0,0,0,"","Group 0: Execute SAI (Action 3) if player has taken quest 'Oh Noes, the Tadpoles!'"),
(22,5,25201,0,0,9,0,11560,0,0,0,0,0,"","Group 0: Execute SAI (Action 4) if player has taken quest 'Oh Noes, the Tadpoles!'"),
(22,11,25201,0,0,9,0,11560,0,0,1,0,0,"","Group 0: Execute SAI (Action 10) if quest 'Oh Noes, the Tadpoles!' is not taken"),
(22,12,25201,0,0,9,0,11560,0,0,1,0,0,"","Group 0: Execute SAI (Action 11) if quest 'Oh Noes, the Tadpoles!' is not taken");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 45279;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,45279,0,0,31,0,3,25201,0,0,0,0,"","Group 0: Spell 'Winterfin Tadpole Cage Opened - Player Cast' (Effect 0) targets creature 'Winterfin Tadpole'");

DELETE FROM `creature_text` WHERE `CreatureID` = 25201 AND `GroupID` = 0 AND `ID` = 4;
DELETE FROM `creature_text` WHERE `CreatureID` = 25201 AND `GroupID` = 1;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25201,1,0,"Close!",12,0,100,0,0,0,24454,0,"Winterfin Tadpole"),
(25201,1,1,"No go with stranger!",12,0,100,0,0,0,24455,0,"Winterfin Tadpole"),
(25201,1,2,"Eww... $r!",12,0,100,0,0,0,24456,0,"Winterfin Tadpole"),
(25201,1,3,"You not $g da-da : ma-ma;!",12,0,100,0,0,0,24457,0,"Winterfin Tadpole");
