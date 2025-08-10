-- Spore
UPDATE `smart_scripts` SET `event_param4` = 4000 WHERE `entryorguid` = 23876 AND `source_type` = 0 AND `id` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 23876 AND `source_type` = 0 AND `id` = 4;

-- Gnomeregan
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` IN (6219,7079);
UPDATE `creature_template_addon` SET `auras` = '9460' WHERE `entry` = 6219;
UPDATE `creature_template_addon` SET `auras` = '9205' WHERE `entry` = 6220;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6218,6219,6220,7079) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6218,0,0,0,6,0,100,0,0,0,0,0,0,11,10341,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Irradiated Slime - On Death - Cast 'Radiation Cloud'"),

(6220,0,0,0,0,0,100,0,15600,19300,9700,21700,0,11,8211,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Irradiated Horror - In Combat - Cast 'Chain Burn'");

-- Fallen Hero's Spirit
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3214901 AND `source_type` = 9 AND `id` = 0;

-- Random
UPDATE `smart_scripts` SET `action_type` = 11 WHERE `entryorguid` IN (26336,29627,30407,3821,28665,14884,30399,22137,20243,2236,10158,2167,2186) AND `source_type` = 0 AND `action_type` = 75;

UPDATE `smart_scripts` SET `action_type` = 11 WHERE `entryorguid` IN (2885703,3039000,497900) AND `source_type` = 9 AND `action_type` = 75;

UPDATE `smart_scripts` SET `action_type` = 11 WHERE `entryorguid` IN (24972,-107135,-107136,-107137,37966,37980,36812,3797) AND `source_type` = 0 AND `action_type` = 75;

UPDATE `smart_scripts` SET `action_type` = 11 WHERE `entryorguid` IN (2640600,2700300) AND `source_type` = 9 AND `action_type` = 75;
UPDATE `smart_scripts` SET `action_type` = 11 WHERE `entryorguid` IN (26405) AND `source_type` = 0 AND `action_type` = 75;

-- Iron Rune Construct
UPDATE `smart_scripts` SET `action_type` = 11 WHERE `entryorguid` = 24825 AND `source_type` = 0 AND `action_type` = 75;

-- Farseer Nobundo
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1720401 AND `source_type` = 9 AND `id` IN (3,4);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1720401,9,3,0,0,0,100,0,6000,6000,0,0,0,86,33010,0,10,67174,18814,0,1,0,0,0,0,0,0,0,0,"Farseer Nobundo - On Script - Cross Cast 'Windfury Impact Visual'"),
(1720401,9,4,0,0,0,100,0,0,0,0,0,0,86,33010,0,10,67177,18814,0,1,0,0,0,0,0,0,0,0,"Farseer Nobundo - On Script - Cross Cast 'Windfury Impact Visual'");

-- Jimmy the Stable Boy
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2736400 AND `source_type` = 9 AND `id` IN (2);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2736400,9,2,0,0,0,100,0,0,0,0,0,0,86,48478,0,10,117793,27365,0,1,0,0,0,0,0,0,0,0,"Jimmy the Stable Boy - On Script - Cross Cast 'Transform - Stabled Pet Appearance'");

-- Brann, should be Set Data, most likely
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3040500 AND `source_type` = 9 AND `id` IN (33,35);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3040500,9,33,0,0,0,100,0,0,0,0,0,0,86,71385,0,11,30408,20,0,1,0,0,0,0,0,0,0,0,"brann - ActionList - add aura"),
(3040500,9,35,0,0,0,100,0,4000,4000,0,0,0,86,71385,0,11,30411,20,0,1,0,0,0,0,0,0,0,0,"brann - ActionList - add aura");

-- 7th Legion Siege Engineer
UPDATE `smart_scripts` SET `action_type` = 11 WHERE `entryorguid` = 2716301 AND `source_type` = 9 AND `action_type` = 75;

-- Tormar Frostgut
UPDATE `smart_scripts` SET `action_type` = 11, `action_param2` = 2, `target_type` = 1, `target_param1` = 0 WHERE `entryorguid` = 29626 AND `source_type` = 0 AND `action_type` = 75;

-- Tethyr
DELETE FROM `smart_scripts` WHERE `entryorguid` = 23900 AND `source_type` = 0 AND `id` = 4;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 23899 AND `source_type` = 0 AND `id` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23900,0,4,0,6,0,100,0,0,0,0,0,0,63,1,1,0,0,0,0,19,23899,80,0,0,0,0,0,0,"Theramore Marksman - On Death - Set Counter 1 1 (Tethyr)"),

(23899,0,1,0,77,0,100,0,1,5,0,0,0,80,2389901,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tethyr - On Counter Set 1 5 - Run Script");

-- Loken
UPDATE `smart_scripts` SET `action_type` = 11, `target_type` = 1, `target_param1` = 0, `target_param2` = 0 WHERE `entryorguid` = 3039600 AND `source_type` = 9 AND `action_type` = 75;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 3039600 AND `source_type` = 9 AND `id` IN (12,20);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3039600,9,20,0,0,0,100,0,0,0,0,0,0,28,56696,0,0,0,0,0,19,30399,0,0,0,0,0,0,0,"Loken - Script - Interrupt Spell");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (56696);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,56696,0,0,31,0,3,30399,0,0,0,0,"","Group 0: Spell 'Loken - Defeat Thorim' (Effect 0) targets creature 'Thorim'");

-- Plagued Sprayer
DELETE FROM `smart_scripts` WHERE `entryorguid` = 29457 AND `source_type` = 0 AND `id` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28274 AND `source_type` = 0 AND `id` = 4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- This is correct
(29457,0,0,0,11,0,100,0,0,0,0,0,0,11,54495,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Plague Sprayer Trigger - On Spawn - Cast 'Plague Spray'"),
-- Old code with spell above, no idea what he does but nothing like this, it looks like OOC event, not quest event
(28274,0,4,0,8,0,100,1,54495,0,0,0,0,69,1,0,0,0,0,0,19,29457,20,0,0,0,0,0,0,"Plagued Sprayer - On 'Plague Spray' Spellhit - Move to closest trigger in 20 yards");

-- Looks like last update to this creature simply removed half of quest support, this part does nothing for a long time, should be rewritten 
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2837600 AND `source_type` = 9 AND `action_type` = 75;

-- Random
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2179700 AND `source_type` = 9 AND `id` IN (4);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 34102 AND `source_type` = 0 AND `id` IN (19,20,21,22);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2179700,9,4,0,0,0,100,512,1000,1000,0,0,0,86,37782,0,12,1,0,0,1,0,0,0,0,0,0,0,0,"Ancient Shadowmoon Spirit - On Script - Cross Cast - Teron Gorefiend"),

(34102,0,19,20,61,0,100,0,0,0,0,0,0,86,45066,2,19,36065,0,0,1,0,0,0,0,0,0,0,0,"Argent Confessor Paletress - IC - Add aura stun"),
(34102,0,20,21,61,0,100,0,0,0,0,0,0,86,45066,2,19,36066,0,0,1,0,0,0,0,0,0,0,0,"Argent Confessor Paletress - IC - Add aura stun"),
(34102,0,21,22,61,0,100,0,0,0,0,0,0,86,68342,2,19,36065,0,0,1,0,0,0,0,0,0,0,0,"Argent Confessor Paletress - IC - Add aura Shackle Undead"),
(34102,0,22,0,61,0,100,0,0,0,0,0,0,86,68342,2,19,36066,0,0,1,0,0,0,0,0,0,0,0,"Argent Confessor Paletress - IC - Add aura Shackle Undead");
