--
UPDATE `smart_scripts` SET `action_type` = 90, `action_param1` = 7, `action_param2` = 0, `comment` = "Muradin - On Script - Set Flag Standstate Dead" WHERE `entryorguid` = 2748001 AND `source_type` = 9 AND `id` = 1;
UPDATE `smart_scripts` SET `action_type` = 91, `action_param1` = 7, `action_param2` = 0, `comment` = "Muradin - On Script - Remove Flag Standstate Dead" WHERE `entryorguid` = 2748001 AND `source_type` = 9 AND `id` = 2;

--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (12939000,12939100) AND `source_type` = 9 AND `id` BETWEEN 3 AND 7;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28391 AND `source_type` = 0 AND `id` = 5;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28394 AND `source_type` = 0 AND `id` = 1;

--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2170000 AND `source_type` = 9 AND `id` = 12;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 37493;
DELETE FROM `spell_script_names` WHERE `spell_id` = 37493 AND `ScriptName` = 'spell_gen_feign_death_no_dyn_flag';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(37493,'spell_gen_feign_death_no_dyn_flag');

-- Completely useless conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` IN (29770,29840,29769) AND `SourceId` = 0;
UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` IN (29770,29840,29769);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29770,29840,29769) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2977000,2984000,2976900,2976901,2976902) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Lady Nightswood
(29770,0,0,0,11,0,100,0,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Nightswood - On Spawn - Set Invincibility HP"),
(29770,0,1,0,1,0,100,0,0,0,3000,3000,0,11,55070,0,0,0,0,0,19,29771,0,0,0,0,0,0,0,"Lady Nightswood - Out of Combat - Cast 'Shadow Cultist: Blue Smoke Beam'"),
(29770,0,2,0,4,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Lady Nightswood - On Aggro - Say Line 0"),
(29770,0,3,0,0,0,100,0,10000,15000,13000,18000,0,11,5884,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Lady Nightswood - In Combat - Cast 'Banshee Curse'"),
(29770,0,4,0,0,0,100,0,15000,20000,15000,20000,0,11,16838,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Nightswood - In Combat - Cast 'Banshee Shriek'"),

(29770,0,5,6,2,0,100,1,0,1,0,0,0,117,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Nightswood - On 1% HP - Disable Evade"),
(29770,0,6,7,61,0,100,0,0,0,0,0,0,11,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Nightswood - On 1% HP - Cast 'Permament Feign Death'"),
(29770,0,7,8,61,0,100,0,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Nightswood - On 1% HP - Set Flag Immune To Players"),
(29770,0,8,9,61,0,100,0,0,0,0,0,0,27,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Nightswood - On 1% HP - Combat Stop"),
(29770,0,9,0,61,0,100,0,0,0,0,0,0,41,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Nightswood - On 1% HP - Delayed Despawn"),

(29770,0,10,0,8,0,100,0,29071,0,0,0,0,80,2977000,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Nightswood - On Spellhit 'Sovereign Rod' - Run Script"),

(2977000,9,0,0,0,0,100,0,0,0,0,0,0,11,35426,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Nightswood - On Script - Cast 'Arcane Explosion Visual'"),
(2977000,9,1,0,0,0,100,0,0,0,0,0,0,28,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Nightswood - On Script - Remove Aura 'Permament Feign Death'"),
(2977000,9,2,0,0,0,100,0,0,0,0,0,0,2,2050,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Nightswood - On Script - Set Faction 2050"),
(2977000,9,3,0,0,0,100,0,0,0,0,0,0,33,29846,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lady Nightswood - On Script - Quest Credit 'Free Your Mind'"),
(2977000,9,4,0,0,0,100,0,3000,3000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lady Nightswood - On Script - Set Orientation Invoker"),
(2977000,9,5,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lady Nightswood - On Script - Say Line 1"),
(2977000,9,6,0,0,0,100,0,6000,6000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Nightswood - On Script - Despawn"),

-- The Leaper
(29840,0,0,0,11,0,100,0,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Leaper - On Spawn - Set Invincibility HP"),
(29840,0,1,0,4,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"The Leaper - On Aggro - Say Line 0"),
(29840,0,2,0,0,0,100,0,5000,5000,5000,10000,0,11,60195,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"The Leaper - In Combat - Cast 'Sinister Strike'"),
-- No idea how it works, both at once
(29840,0,3,4,0,0,100,0,10000,15000,10000,15000,0,11,63848,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Leaper - In Combat - Cast 'Hunger For Blood'"),
(29840,0,4,0,61,0,100,0,0,0,0,0,0,11,60177,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Leaper - In Combat - Cast 'Hunger For Blood'"),

(29840,0,5,6,2,0,100,1,0,1,0,0,0,117,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Leaper - On 1% HP - Disable Evade"),
(29840,0,6,7,61,0,100,0,0,0,0,0,0,11,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Leaper - On 1% HP - Cast 'Permament Feign Death'"),
(29840,0,7,8,61,0,100,0,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Leaper - On 1% HP - Set Flag Immune To Players"),
(29840,0,8,9,61,0,100,0,0,0,0,0,0,27,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Leaper - On 1% HP - Combat Stop"),
(29840,0,9,0,61,0,100,0,0,0,0,0,0,41,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Leaper - On 1% HP - Delayed Despawn"),

(29840,0,10,0,8,0,100,0,29071,0,0,0,0,80,2984000,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Leaper - On Spellhit 'Sovereign Rod' - Run Script"),

(2984000,9,0,0,0,0,100,0,0,0,0,0,0,11,35426,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Leaper - On Script - Cast 'Arcane Explosion Visual'"),
(2984000,9,1,0,0,0,100,0,0,0,0,0,0,28,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Leaper - On Script - Remove Aura 'Permament Feign Death'"),
(2984000,9,2,0,0,0,100,0,0,0,0,0,0,2,2050,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Leaper - On Script - Set Faction 2050"),
(2984000,9,3,0,0,0,100,0,0,0,0,0,0,33,29847,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"The Leaper - On Script - Quest Credit 'Free Your Mind'"),
(2984000,9,4,0,0,0,100,0,3000,3000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"The Leaper - On Script - Set Orientation Invoker"),
(2984000,9,5,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"The Leaper - On Script - Say Line 1"),
(2984000,9,6,0,0,0,100,0,6000,6000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"The Leaper - On Script - Despawn"),

-- Vile
(29769,0,0,0,11,0,100,0,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - On Spawn - Set Invincibility HP"),
(29769,0,1,0,1,0,100,0,5000,5000,5000,5000,0,88,2976901,2976902,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - Out of Combat - Run Random Script"),
(29769,0,2,0,4,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Vile - On Aggro - Say Line 0"),
(29769,0,3,0,0,0,100,0,10000,15000,15000,20000,0,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Vile - In Combat - Cast 'Backhand'"),
(29769,0,4,0,0,0,100,0,15000,20000,10000,20000,0,11,56646,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - In Combat - Cast 'Enrage'"),

(29769,0,5,6,2,0,100,1,0,1,0,0,0,117,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - On 1% HP - Disable Evade"),
(29769,0,6,7,61,0,100,0,0,0,0,0,0,11,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - On 1% HP - Cast 'Permament Feign Death'"),
(29769,0,7,8,61,0,100,0,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - On 1% HP - Set Flag Immune To Players"),
(29769,0,8,9,61,0,100,0,0,0,0,0,0,27,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - On 1% HP - Combat Stop"),
(29769,0,9,0,61,0,100,0,0,0,0,0,0,41,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - On 1% HP - Delayed Despawn"),

(29769,0,10,0,8,0,100,0,29071,0,0,0,0,80,2976900,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - On Spellhit 'Sovereign Rod' - Run Script"),

(2976900,9,0,0,0,0,100,0,0,0,0,0,0,11,35426,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - On Script - Cast 'Arcane Explosion Visual'"),
(2976900,9,1,0,0,0,100,0,0,0,0,0,0,28,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - On Script - Remove Aura 'Permament Feign Death'"),
(2976900,9,2,0,0,0,100,0,0,0,0,0,0,2,2050,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - On Script - Set Faction 2050"),
(2976900,9,3,0,0,0,100,0,0,0,0,0,0,33,29845,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Vile - On Script - Quest Credit 'Free Your Mind'"),
(2976900,9,4,0,0,0,100,0,3000,3000,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Vile - On Script - Set Orientation Invoker"),
(2976900,9,5,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Vile - On Script - Say Line 1"),
(2976900,9,6,0,0,0,100,0,6000,6000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - On Script - Despawn"),

(2976901,9,0,0,0,0,100,0,0,0,0,0,0,4,1441,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - On Script - Play Sound 1441"),
(2976901,9,1,0,0,0,100,0,0,0,0,0,0,5,35,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - On Script - Play Emote 35"),
(2976901,9,2,0,0,0,100,0,0,0,0,0,0,4,3204,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - On Script - Play Sound 3204"),

(2976902,9,0,0,0,0,100,0,0,0,0,0,0,4,1441,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - On Script - Play Sound 1441"),
(2976902,9,1,0,0,0,100,0,0,0,0,0,0,5,36,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - On Script - Play Emote 36"),
(2976902,9,2,0,0,0,100,0,0,0,0,0,0,4,166,0,1,0,0,0,1,0,0,0,0,0,0,0,0,"Vile - On Script - Play Sound 166");
