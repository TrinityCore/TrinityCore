--
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (25416,25418);
-- DELETE FROM `creature_ai_texts` WHERE `entry` IN (-487,-488,-489,-498,-499,-500,-501);

UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry` IN (25416,25418);

DELETE FROM `creature_text` WHERE `entry` IN (25416,25418);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(25416,0,0,'Who dares?',12,0,0,0,0,0,''),
(25416,1,0,'STOP!',12,0,0,0,0,0,''),
(25416,2,0,'Tell Imperean that I will consider a cessation of hostilities. But first, Churn must stop his watery intrusions upon my rise!',12,0,0,0,0,0,''),
(25416,3,0,'I grow bored with you. Begone!',12,0,0,0,0,0,''),
(25418,0,0,'I... submit. As long as Simmer agrees to stop boiling my pool, I agree to an armistice.',12,0,0,0,0,0,''),
(25418,1,0,'Now, remove yourself from my presence. You would be wise not to come within sight of me again.',12,0,0,0,0,0,''),
(25418,2,0,'WAIT... NO MORE!',12,0,0,0,0,0,'');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25416,25418) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25416,0,0,1,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Simmer - On Aggro - Say line 0'),
(25416,0,1,0,61,0,100,0,0,0,0,0,42,0,5,0,0,0,0,1,0,0,0,0,0,0,0,'Simmer - Link With Event 0 - Set Invincible HP'),
(25416,0,2,0,0,0,100,1,5000,5000,5000,5000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Simmer - IC - Say Line 2 After 5 secs'),
(25416,0,3,0,0,0,100,1,10000,10000,10000,10000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Simmer - IC - Say Line 3 After 10 secs'),
(25416,0,4,5,2,0,100,1,0,5,0,0,85,45599,0,0,0,0,0,7,0,0,0,0,0,0,0,'Simmer - At 5 % HP - Give Quest Credit'),
(25416,0,5,6,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Simmer - Link With Event 4 - Say Line 1'),
(25416,0,6,7,61,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Simmer - Link With Event 5 - Change Faction'),
(25416,0,7,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Simmer - Link With Event 6 - Evade'),
(25416,0,8,0,1,0,100,0,120000,120000,120000,120000,2,1983,0,0,0,0,0,1,0,0,0,0,0,0,0,'Simmer - OOC - Change Faction After 2 mins'),
(25418,0,0,0,0,0,100,0,5300,5300,9900,9900,11,50206,0,0,0,0,0,2,0,0,0,0,0,0,0,'Churn - IC - Cast Scalding Steam'),
(25418,0,1,0,4,0,100,0,0,0,0,0,42,0,5,0,0,0,0,1,0,0,0,0,0,0,0,'Churn - On Aggro - Set Invincible HP'),
(25418,0,2,0,0,0,100,1,5000,5000,5000,5000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Churn - IC - Say Line 0 After 5 secs'),
(25418,0,3,0,0,0,100,1,10000,10000,10000,10000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Churn - IC - Say Line 1 After 10 secs'),
(25418,0,4,5,2,0,100,1,0,5,0,0,85,45598,0,0,0,0,0,7,0,0,0,0,0,0,0,'Churn - At 5 % HP - Give Quest Credit'),
(25418,0,5,6,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Churn - Link With Event 4 - Say Line 2'),
(25418,0,6,7,61,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Churn - Link With Event 5 - Change Faction'),
(25418,0,7,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Churn - Link With Event 6 - Evade'),
(25418,0,8,0,1,0,100,0,120000,120000,120000,120000,2,1984,0,0,0,0,0,1,0,0,0,0,0,0,0,'Churn - OOC - Change Faction After 2 mins');
