-- Sentinel Glynda NalShea
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2930;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2930 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2930,0,0,0,1,0,100,0,1000,15000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Glynda Nal'Shea - Out of Combat - Say Line 0");
DELETE FROM `creature_text` WHERE `CreatureID`=2930;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2930,0,0,"The forest spirits are uneasy...",12,0,100,0,0,0,908,0,"Sentinel Glynda NalShea"),
(2930,0,1,"The Blackwood tribe is disrupting our sacred lands.",12,0,100,0,0,0,909,0,"Sentinel Glynda Nal'Shea"),
(2930,0,2,"Something needs to be done about the Blackwood tribe.",12,0,100,0,0,0,910,0,"Sentinel Glynda Nal'Shea"),
(2930,0,3,"A corruption taints our sacred forest.",12,0,100,0,0,0,911,0,"Sentinel Glynda Nal'Shea"),
(2930,0,4,"The Blackwood tribe must not be permitted to interfere with the progress of nature.",12,0,100,0,0,0,912,0,"Sentinel Glynda Nal'Shea"),
(2930,0,5,"I sense danger deep within the grove...",12,0,100,0,0,0,913,0,"Sentinel Glynda Nal'Shea");
