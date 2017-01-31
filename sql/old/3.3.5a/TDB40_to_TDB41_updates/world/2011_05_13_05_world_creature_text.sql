DELETE FROM `script_texts` WHERE `npc_entry` IN (12429);
DELETE FROM `creature_text` WHERE `entry`=18733;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`sound`,`comment`) VALUES
(18733,0,0, 'Do not proceed. You will be eliminated!',1,11344,'doomwalker SAY_AGGRO'),
(18733,1,0, 'Tectonic disruption commencing.',1,11345,'doomwalker SAY_EARTHQUAKE_1'),
(18733,1,1, 'Magnitude set. Release.',1,11346,'doomwalker SAY_EARTHQUAKE_2'),
(18733,2,0, 'Trajectory locked.',1,11347,'doomwalker SAY_OVERRUN_1'),
(18733,2,1, 'Engage maximum speed.',1,11348,'doomwalker SAY_OVERRUN_2'),
(18733,3,0, 'Threat level zero.',1,11349,'doomwalker SAY_SLAY_1'),
(18733,3,1, 'Directive accomplished.',1,11350,'doomwalker SAY_SLAY_2'),
(18733,3,2, 'Target exterminated.',1,11351,'doomwalker SAY_SLAY_3'),
(18733,4,0, 'System failure in five, f-o-u-r...',1,11352,'doomwalker SAY_DEATH');