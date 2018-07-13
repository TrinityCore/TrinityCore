-- add missing text for npcs
SET @NPC_HOGGER                                       := 448;
SET @NPC_RAGAMUFFIN                                   := 46943;
SET @NPC_GENERAL_HAMMOND_CLAY                         := 65153;
SET @NPC_HOGGER_MINION                                := 46932;
SET @NPC_DUMAS                                        := 46940;
SET @NPC_ANDROMATH                                    := 46941;
SET @NPC_GENERAL_MARCUS_JONATHON                      := 46942;

DELETE FROM `creature_text` WHERE `CreatureID` IN (@NPC_HOGGER, @NPC_RAGAMUFFIN, @NPC_GENERAL_HAMMOND_CLAY);

INSERT INTO `creature_text` 
(`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`)
 VALUES
 (@NPC_HOGGER,0,0,'More bones to gnaw on...',12,0,100,0,0,0,1871,0,'Hogger Agro Say 1'),
 (@NPC_HOGGER,1,0,'Grrrr... fresh meat!',12,0,100,0,0,0,1870,0,'Hogger Agro Say 2'),
 (@NPC_HOGGER,2,0,'Yipe!  Help Hogger!',14,0,0,0,0,0,46936,0,'Hogger help'),
 (@NPC_HOGGER,3,0,'No hurt Hogger!',14,0,0,0,0,0,47000,0,'Hogger nohurt'),
 (@NPC_HOGGER,4,0,'Hogger is stunned!',14,0,0,0,0,0,46940,0,'Hogger stunned'),
 (@NPC_HOGGER,5,0,'Hogger is eating!  Stop him!',14,0,0,0,0,0,46939,0,'Hogger eating'),
 (@NPC_HOGGER,6,0,'Grrr...',12,0,0,0,0,0,46937,0,'Hogger grrr'),
 (@NPC_HOGGER,7,0,'Nooooo...',12,0,0,0,0,0,46938,0,'Hogger no'),
 (@NPC_RAGAMUFFIN,0,0,'General Hammond Clay!',12,0,0,0,0,0,47005,0,'Child to hogger'),   
 (@NPC_RAGAMUFFIN,1,0,'Wow!',12,0,0,0,0,0,47006,0,'Child to hogger wow'), 
 (@NPC_GENERAL_HAMMOND_CLAY,0,0,'Hold your blade, adventurer!',14,0,0,0,0,0,47004,0,'General hold blade'), 
 (@NPC_GENERAL_HAMMOND_CLAY,1,0,'This beast leads the Riverpaw gnoll gang and may be the key to ending gnoll aggression in Elwynn.',12,0,0,0,0,0,47007,0,'General speech'), 
 (@NPC_GENERAL_HAMMOND_CLAY,2,0,'We''re taking him into custody in the name of King Varian Wrynn.',12,0,0,0,0,0,47008,0,'General take custody'), 
 (@NPC_GENERAL_HAMMOND_CLAY,3,0,'Take us to the Stockades, Andromath.',12,0,0,0,0,0,47009,0,'General take custody');
 
-- remove smart_scripts and handle via c++
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_hogger' WHERE `entry` = @NPC_HOGGER;

-- fix up hogger minion
UPDATE `creature_template` SET `HealthModifier` = 1, `ScriptName` = 'npc_hogger_minion' WHERE `entry` = @NPC_HOGGER_MINION;

-- delete spawns that should not there there
DELETE FROM `creature`
WHERE `id` IN (@NPC_GENERAL_MARCUS_JONATHON,@NPC_ANDROMATH,@NPC_DUMAS,@NPC_RAGAMUFFIN);
