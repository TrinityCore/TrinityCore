-- 
UPDATE `creature_template_addon` SET `auras`=""  WHERE `entry` IN (25494,30998,30999,31000,32800,25952,25985,24029,15385,30022,29690,29733,31301,31083,32406,34047,34110,30179,29450,34925,33051,33691,33705,3739,9397,7440,28476,7438,8914,11672);
UPDATE `creature_template_addon` SET `auras`="37509 39579"  WHERE `entry` IN (22902);
UPDATE `creature_template_addon` SET `auras`="64101"  WHERE `entry` IN (33243);
UPDATE `creature_template_addon` SET `auras`="57887"  WHERE `entry` IN (30837);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (33051,33705,29450,34047,32406,25985,25952,25494);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29690,29733,33051,33705,29450,34047,32406,25985,25952,25494) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=30022 AND `source_type`=0 AND `id` IN (15);
DELETE FROM `smart_scripts` WHERE `entryorguid`=24029 AND `source_type`=0 AND `id` IN (5);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(33051,0,0,0,54,0,100,0,0,0,0,0,0,11,62019,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rune of Summoning - Just summoned - Cast Rune of Summoning"),
(33705,0,0,0,54,0,100,0,0,0,0,0,0,11,61974,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rune of Power - Just summoned - Cast Rune of Power"),
(29450,0,0,0,23,0,100,0,54512,0,3000,3000,0,11,54512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vargul Runelord - On missing aura - Cast Plague Shield"),
(29450,0,1,0,0,0,100,0,2000,4000,7000,10000,0,11,56036,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vargul Runelord - On missing aura - Cast Rune of Destruction"),
(30022,0,15,0,25,0,100,0,0,0,0,0,0,11,50689,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vladof the Butcher - On reset - cast Blood Presence"),
(34047,0,0,0,54,0,100,0,0,0,0,0,0,11,64064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rocket Strike - Just summoned - Cast Rocket Strike"),
(32406,0,0,1,54,0,100,0,0,0,0,0,0,75,60977,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ominous Cloud - Just summoned - Add aura Ominous Cloud"),
(32406,0,1,0,61,0,100,0,0,0,0,0,0,75,60984,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ominous Cloud - Just summoned - Add aura Ominous Cloud"),
(29690,0,0,0,23,0,100,0,12550,0,3000,3000,0,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Rageclaw - On missing aura - Cast Lightning Shield"),
(29690,0,1,0,11,0,100,0,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Rageclaw - On Respawn - Increment Phase By 1"),
(29733,0,0,0,23,0,100,0,12550,0,3000,3000,0,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Shaman Moky - On missing aura - Cast Lightning Shield"),
(29733,0,1,0,11,0,100,0,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Shaman Moky - On Respawn - Increment Phase By 1"),
(24029,0,5,0,23,0,100,0,54512,0,3000,3000,0,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wyrmcaller Vile - On missing aura - Cast Frost Armor"),
(25985,0,0,1,54,0,100,0,0,0,0,0,0,75,46878,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ahune Ice Spear Bunny - Just summoned - Add aura Summon Ice Spear Knockback Delayer"),
(25985,0,1,0,61,0,100,0,0,0,0,0,0,75,75498,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ahune Ice Spear Bunny - Just summoned - Add aura Ice Spear Visual"),
(25952,0,0,0,11,0,100,0,0,0,0,0,0,11,46314,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slippery Floor Bunny - On Respawn - Cast Ahune - Slippery Floor Ambient"),
(25494,0,0,0,54,0,100,0,0,0,0,0,0,11,45655,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sage Aeire's Totem - Just summoned - Cast Cauldron Purification");

UPDATE `smart_scripts` SET `event_type`=23, `event_param1`=12550, `event_param3`=3000, `event_param4`=3000, `comment`="Twilight Apostle - On Respawn - Cast 'Lightning Shield' (No Repeat)" WHERE `entryorguid` IN (30179) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=23, `event_param1`=61570, `event_param3`=3000, `event_param4`=3000, `comment`="Twilight Apostle - On Respawn - Cast 'Lightning Shield' (No Repeat)" WHERE `entryorguid` IN (30179) AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `event_type`=23, `event_param2`=0, `comment`="Living Storm - On Missing Buff 'Lightning Shield' - Cast Lightning Shield" WHERE `entryorguid` IN (9397) AND `source_type`=0 AND `id`=0;

UPDATE `creature_template` SET `scale`=1  WHERE   `entry` IN (30837);
DELETE FROM spell_linked_spell WHERE `spell_trigger` IN (57887);
INSERT INTO spell_linked_spell (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(57887, 57886, 2, 'Defense System Spawn Effect');
