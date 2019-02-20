-- Nathanos Blightcaller
DELETE FROM `smart_scripts` WHERE `entryorguid`=11878 AND `source_type`=0 AND `id` IN (4, 5);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11878,0,4,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Nathanos Blightcaller - On Aggro - Say Line 0"),
(11878,0,5,0,5,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nathanos Blightcaller - On Killed Unit - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=11878;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11878,0,0,"Prepare for a severe beating.",12,0,100,0,0,0,7229,0,"Nathanos Blightcaller"),
(11878,0,1,"I shall wear your entrails as a necklace.",12,0,100,0,0,0,7230,0,"Nathanos Blightcaller"),
(11878,0,2,"I can smell your fear, $r.",12,0,100,0,0,0,7231,0,"Nathanos Blightcaller"),
(11878,0,3,"If you run now, you may live.",12,0,100,0,0,0,7232,0,"Nathanos Blightcaller"),
(11878,0,4,"How dare you!",12,0,100,0,0,0,7233,0,"Nathanos Blightcaller"),
(11878,1,0,"Pathetic.",12,0,100,0,0,0,7234,0,"Nathanos Blightcaller"),
(11878,1,1,"The reckoning is upon you, weakling!",12,0,100,0,0,0,7235,0,"Nathanos Blightcaller"),
(11878,1,2,"Disappointing.",12,0,100,0,0,0,7236,0,"Nathanos Blightcaller"),
(11878,1,3,"Is that the best you can do?",12,0,100,0,0,0,7237,0,"Nathanos Blightcaller"),
(11878,1,4,"You weren't worth the energy expenditure. <Nathanos spits.>",12,0,100,0,0,0,7238,0,"Nathanos Blightcaller"),
(11878,1,5,"Next time, bring friends.",12,0,100,0,0,0,7239,0,"Nathanos Blightcaller");
