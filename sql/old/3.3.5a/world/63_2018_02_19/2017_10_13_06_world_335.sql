-- Bazil Thredd
DELETE FROM `creature_text` WHERE `CreatureID`=1716;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1716,0,0,"Eh? What have we here?",12,7,100,0,0,0,1386,0,"Bazil Thredd"),
(1716,0,1,"Welcome to the Stockade!",12,7,100,0,0,0,1387,0,"Bazil Thredd"),
(1716,0,2,"Outsiders! Kill em all!",12,7,100,0,0,0,1388,0,"Bazil Thredd"),
(1716,0,3,"More of the Warden's errand boys!",12,7,100,0,0,0,1390,0,"Bazil Thredd"),
(1716,0,4,"Tell the Warden this prison is ours now!",12,7,100,0,0,0,1391,0,"Bazil Thredd"),
(1716,0,5,"It'll be quick, but it won't be painless!",12,7,100,0,0,0,1392,0,"Bazil Thredd"),
(1716,0,6,"Fresh meat!",12,7,100,0,0,0,1393,0,"Bazil Thredd"),
(1716,0,7,"I'll crush your skull beneath my boot!",12,7,100,0,0,0,1394,0,"Bazil Thredd"),
(1716,0,8,"Death to the Warden's men!",12,7,100,0,0,0,1395,0,"Bazil Thredd");

DELETE FROM `smart_scripts` WHERE `entryorguid`=1716 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1716,0,1,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bazil Thredd - On Aggro - Say Line 0");
