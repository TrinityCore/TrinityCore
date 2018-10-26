/*
-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=10799 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10799,0,1,0,20,0,100,1,4867,0,0,0,11,16801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warosh <The Cursed> - On Quest 'Urok Doomhowl' Rewarded - Cast Warosh's Transform"),
(10799,0,2,0,8,0,100,1,16801,0,0,0,36,10800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warosh <The Cursed> - On spell hit - Change template to Warosh the Redeemed");

DELETE FROM `creature_questender` WHERE `id`=10800 AND `quest`=4867;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES (10800,4867);
*/
