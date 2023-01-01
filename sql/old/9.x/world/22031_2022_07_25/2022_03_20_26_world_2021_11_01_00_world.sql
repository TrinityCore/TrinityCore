--
UPDATE `creature_text` SET `BroadcastTextId` = 31900, `Text` = "Bin dorei am'ovel!", `Language` = 0 WHERE `CreatureID` = 29308 AND `GroupID` = 3 AND `ID` = 0;

-- Now it doesn't work for Volgur, will be fixed one day
DELETE FROM `creature_text` WHERE `CreatureID` IN (30483,30484);
UPDATE `smart_scripts` SET `action_type` = 88, `action_param1` = 3048301, `action_param2` = 3048310, `comment` = "Volgur - On Aggro - Run Random Script" WHERE `entryorguid` = 30483 AND `source_type` = 0 AND `id` = 1;
UPDATE `smart_scripts` SET `action_type` = 88, `action_param1` = 3048401, `action_param2` = 3048408, `comment` = "Brita - On Aggro - Run Random Script" WHERE `entryorguid` = 30484 AND `source_type` = 0 AND `id` = 6;

DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 3048301 AND 3048310 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 3048401 AND 3048408 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3048301,9,0,0,0,0,100,0,0,0,0,0,0,4,13533,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Volgur - On Script - Play Sound 13533"),
(3048302,9,0,0,0,0,100,0,0,0,0,0,0,4,13534,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Volgur - On Script - Play Sound 13534"),
(3048303,9,0,0,0,0,100,0,0,0,0,0,0,4,13535,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Volgur - On Script - Play Sound 13535"),
(3048304,9,0,0,0,0,100,0,0,0,0,0,0,4,13536,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Volgur - On Script - Play Sound 13536"),
(3048305,9,0,0,0,0,100,0,0,0,0,0,0,4,13537,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Volgur - On Script - Play Sound 13537"),
(3048306,9,0,0,0,0,100,0,0,0,0,0,0,4,13538,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Volgur - On Script - Play Sound 13538"),
(3048307,9,0,0,0,0,100,0,0,0,0,0,0,4,13539,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Volgur - On Script - Play Sound 13539"),
(3048308,9,0,0,0,0,100,0,0,0,0,0,0,4,13540,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Volgur - On Script - Play Sound 13540"),
(3048309,9,0,0,0,0,100,0,0,0,0,0,0,4,13541,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Volgur - On Script - Play Sound 13541"),
(3048310,9,0,0,0,0,100,0,0,0,0,0,0,4,13542,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Volgur - On Script - Play Sound 13542"),

(3048401,9,0,0,0,0,100,0,0,0,0,0,0,4,14384,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Brita - On Script - Play Sound 14384"),
(3048402,9,0,0,0,0,100,0,0,0,0,0,0,4,14385,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Brita - On Script - Play Sound 14385"),
(3048403,9,0,0,0,0,100,0,0,0,0,0,0,4,14386,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Brita - On Script - Play Sound 14386"),
(3048404,9,0,0,0,0,100,0,0,0,0,0,0,4,14387,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Brita - On Script - Play Sound 14387"),
(3048405,9,0,0,0,0,100,0,0,0,0,0,0,4,14388,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Brita - On Script - Play Sound 14388"),
(3048406,9,0,0,0,0,100,0,0,0,0,0,0,4,14389,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Brita - On Script - Play Sound 14389"),
(3048407,9,0,0,0,0,100,0,0,0,0,0,0,4,14390,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Brita - On Script - Play Sound 14390"),
(3048408,9,0,0,0,0,100,0,0,0,0,0,0,4,14391,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Brita - On Script - Play Sound 14391");
