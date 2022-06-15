--
UPDATE `creature` SET `spawntimesecs` = 90 WHERE `id` = 30746;
UPDATE `creature_loot_template` SET `Chance` = 100 WHERE `Entry` = 30746 AND `Item` = 43159 AND `Reference` = 0;

DELETE FROM `spell_scripts` WHERE `id` = 57852;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (30742,30744,30745,30950) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3074200,3074400,3074500,3095000) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30742,0,0,0,8,0,100,0,57852,0,0,0,0,80,3074200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"First Summoning Altar - On Spellhit 'Destroy Altar' - Run Script"),
(30744,0,0,0,8,0,100,0,57852,0,0,0,0,80,3074400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Second Summoning Altar - On Spellhit 'Destroy Altar' - Run Script"),
(30745,0,0,0,8,0,100,0,57852,0,0,0,0,80,3074500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Third Summoning Altar - On Spellhit 'Destroy Altar' - Run Script"),
(30950,0,0,0,8,0,100,0,57852,0,0,0,0,80,3095000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fourth Summoning Altar - On Spellhit 'Destroy Altar' - Run Script"),

(3074200,9,0,0,0,0,100,0,0,0,0,0,0,11,57931,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"First Summoning Altar - On Script - Cast 'Cosmetic - Low Poly Fire'"),
(3074200,9,1,0,0,0,100,0,0,0,0,0,0,11,46419,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"First Summoning Altar - On Script - Cast 'Cosmetic - Explosion'"),
(3074200,9,2,0,0,0,100,0,0,0,0,0,0,33,30742,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"First Summoning Altar - On Script - Quest Credit 'Destroying the Altars'"),

(3074400,9,0,0,0,0,100,0,0,0,0,0,0,11,57931,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Second Summoning Altar - On Script - Cast 'Cosmetic - Low Poly Fire'"),
(3074400,9,1,0,0,0,100,0,0,0,0,0,0,11,46419,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Second Summoning Altar - On Script - Cast 'Cosmetic - Explosion'"),
(3074400,9,2,0,0,0,100,0,0,0,0,0,0,33,30744,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Second Summoning Altar - On Script - Quest Credit 'Destroying the Altars'"),

(3074500,9,0,0,0,0,100,0,0,0,0,0,0,11,57931,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Third Summoning Altar - On Script - Cast 'Cosmetic - Low Poly Fire'"),
(3074500,9,1,0,0,0,100,0,0,0,0,0,0,11,46419,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Third Summoning Altar - On Script - Cast 'Cosmetic - Explosion'"),
(3074500,9,2,0,0,0,100,0,0,0,0,0,0,33,30745,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Third Summoning Altar - On Script - Quest Credit 'Destroying the Altars'"),

(3095000,9,0,0,0,0,100,0,0,0,0,0,0,11,57931,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fourth Summoning Altar - On Script - Cast 'Cosmetic - Low Poly Fire'"),
(3095000,9,1,0,0,0,100,0,0,0,0,0,0,11,46419,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fourth Summoning Altar - On Script - Cast 'Cosmetic - Explosion'"),
(3095000,9,2,0,0,0,100,0,0,0,0,0,0,33,30950,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Fourth Summoning Altar - On Script - Quest Credit 'Destroying the Altars'");
