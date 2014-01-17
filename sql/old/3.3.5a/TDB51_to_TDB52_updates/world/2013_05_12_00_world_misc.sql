DELETE FROM `creature` WHERE `guid` IN (116020,116021,116022,116023,116024,116025,116026,116029,116030,116031,116032,116033,116035,116037,116038,116039,116040,116042,116043,116044,116045,116046,116047,116049,116050,116051,116053,116054,116055,116056,116057,116058,116059,116060,116061,116065);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (47374,47469,47634,50546,50547,50548);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (47374,47469,47634);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorType`,`ScriptName`,`Comment`) VALUES
(13,1,47374,0,31,0,3,23837,0,0,'','Spell Ley Line Focus Control Ring targets ELM General Purpose Bunny'),
(13,1,47469,0,31,0,3,23837,0,0,'','Spell Ley Line Focus Control Amulet targets ELM General Purpose Bunny'),
(13,1,47634,0,31,0,3,23837,0,0,'','Spell Ley Line Focus Control Talisman targets ELM General Purpose Bunny'),
(13,1,50546,0,31,0,3,23837,0,0,'','Spell The Focus on the Beach: Ley Line Focus Control Ring Effect targets ELM General Purpose Bunny'),
(13,1,50547,0,31,0,3,23837,0,0,'','Spell Atop the Woodlands: Ley Line Focus Control Amulet Effect targets ELM General Purpose Bunny'),
(13,1,50548,0,31,0,3,23837,0,0,'','Spell The End of the Line: Ley Line Focus Control Talisman Effect targets ELM General Purpose Bunny'),
(17,0,47374,0,29,0,23837,7,0,97,'','Spell Ley Line Focus Control Ring can be casted only within 7y from ELM General Purpose Bunny'),
(17,0,47469,0,29,0,23837,7,0,97,'','Spell Ley Line Focus Control Amulet can be casted only within 7y from ELM General Purpose Bunny'),
(17,0,47634,0,29,0,23837,7,0,97,'','Spell Ley Line Focus Control Talisman can be casted only within 7y from ELM General Purpose Bunny');

DELETE FROM `creature_text` WHERE `entry` IN (26762,26815);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(26762,0,0,'Keep them away from the focus!',12,0,100,0,0,0,'Captain Emmy Malin'),
(26815,0,0,'Ya shouldn''a taken the boat north, mon!',12,0,100,0,0,0,'Lieutenant Ta''zinni');

DELETE FROM `spell_scripts` WHERE `id` IN (47393,47615,47638);
INSERT INTO `spell_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(47393,0,14,47391,0,0,0,0,0,0),
(47615,0,14,47473,0,0,0,0,0,0),
(47638,0,14,47636,0,0,0,0,0,0);

DELETE FROM `areatrigger_scripts` WHERE `entry`=4956;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4956,'SmartTrigger');

UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=26873;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (26762,26815);
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (26762,26815);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-98534,-98535,-98537,-98564,-98599,-98617,-115920,-115921,-115922,-115923,-115924,-115925,-115926,-115927,-115945,-115946,-115947,-115948,-115958,-115959,-115973,-115974,-115975,-115976,24021,26762,26815) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4956 AND `source_type`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 24021*100+0 AND 24021*100+16 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-98534,0,0,0,8,0,100,0,47469,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Ley Line Focus Control Amulet - Store targetlist'),
(-98534,0,1,0,8,0,100,0,50547,0,0,0,11,47472,0,0,0,0,0,12,1,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Atop the Woodlands: Ley Line Focus Control Amulet Effect - Spellcast Atop the Woodlands: Ley Line Focus Bunny Beam'),
(-98535,0,0,0,8,0,100,0,47469,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Ley Line Focus Control Amulet - Store targetlist'),
(-98535,0,1,0,8,0,100,0,50547,0,0,0,11,47472,0,0,0,0,0,12,1,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Atop the Woodlands: Ley Line Focus Control Amulet Effect - Spellcast Atop the Woodlands: Ley Line Focus Bunny Beam'),
(-98537,0,0,0,8,0,100,0,47374,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Ley Line Focus Control Ring - Store targetlist'),
(-98537,0,1,0,8,0,100,0,50546,0,0,0,11,47390,0,0,0,0,0,12,1,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit The Focus on the Beach: Ley Line Focus Control Ring Effect - Spellcast The Focus on the Beach: Ley Line Focus Bunny Beam'),
(-98564,0,0,0,8,0,100,0,47634,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Ley Line Focus Control Talisman - Store targetlist'),
(-98564,0,1,0,8,0,100,0,50548,0,0,0,11,47635,0,0,0,0,0,12,1,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit The End of the Line: Ley Line Focus Control Talisman Effect - Spellcast The End of the Line: Ley Line Focus Bunny Beam'),
(-98599,0,0,0,8,0,100,0,47374,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Ley Line Focus Control Ring - Store targetlist'),
(-98599,0,1,0,8,0,100,0,50546,0,0,0,11,47390,0,0,0,0,0,12,1,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit The Focus on the Beach: Ley Line Focus Control Ring Effect - Spellcast The Focus on the Beach: Ley Line Focus Bunny Beam'),
(-98617,0,0,0,8,0,100,0,47634,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit Ley Line Focus Control Talisman - Store targetlist'),
(-98617,0,1,0,8,0,100,0,50548,0,0,0,11,47635,0,0,0,0,0,12,1,0,0,0,0,0,0, 'ELM General Purpose Bunny - On spellhit The End of the Line: Ley Line Focus Control Talisman Effect - Spellcast The End of the Line: Ley Line Focus Bunny Beam'),

(-115924,0,0,0,1,0,100,0,0,1000,24000,25000,87,24021*100+1,24021*100+2,24021*100+3,24021*100+4,24021*100+5,24021*100+6,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On update OOC - Run random script'),
(-115925,0,0,0,1,0,100,0,0,1000,24000,25000,87,24021*100+1,24021*100+2,24021*100+3,24021*100+4,24021*100+5,24021*100+6,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On update OOC - Run random script'),
(-115926,0,0,0,1,0,100,0,0,1000,24000,25000,87,24021*100+1,24021*100+2,24021*100+3,24021*100+4,24021*100+5,24021*100+6,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On update OOC - Run random script'),
(-115927,0,0,0,1,0,100,0,0,1000,24000,25000,87,24021*100+1,24021*100+2,24021*100+3,24021*100+4,24021*100+5,24021*100+6,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On update OOC - Run random script'),
(-115947,0,0,0,1,0,100,0,0,1000,24000,25000,87,24021*100+1,24021*100+2,24021*100+3,24021*100+4,24021*100+5,24021*100+6,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On update OOC - Run random script'),
(-115948,0,0,0,1,0,100,0,0,1000,24000,25000,87,24021*100+1,24021*100+2,24021*100+3,24021*100+4,24021*100+5,24021*100+6,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On update OOC - Run random script'),

(-115920,0,0,0,1,0,100,0,0,1000,20000,21000,87,24021*100+7,24021*100+8,24021*100+9,24021*100+10,24021*100+11,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On update OOC - Run random script'),
(-115921,0,0,0,1,0,100,0,0,1000,20000,21000,87,24021*100+7,24021*100+8,24021*100+9,24021*100+10,24021*100+11,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On update OOC - Run random script'),
(-115922,0,0,0,1,0,100,0,0,1000,20000,21000,87,24021*100+7,24021*100+8,24021*100+9,24021*100+10,24021*100+11,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On update OOC - Run random script'),
(-115923,0,0,0,1,0,100,0,0,1000,20000,21000,87,24021*100+7,24021*100+8,24021*100+9,24021*100+10,24021*100+11,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On update OOC - Run random script'),
(-115945,0,0,0,1,0,100,0,0,1000,20000,21000,87,24021*100+7,24021*100+8,24021*100+9,24021*100+10,24021*100+11,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On update OOC - Run random script'),
(-115946,0,0,0,1,0,100,0,0,1000,20000,21000,87,24021*100+7,24021*100+8,24021*100+9,24021*100+10,24021*100+11,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On update OOC - Run random script'),

(-115958,0,0,0,1,0,100,0,0,1000,24000,25000,87,24021*100+12,24021*100+13,24021*100+14,24021*100+15,24021*100+16,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On update OOC - Run random script'),
(-115959,0,0,0,1,0,100,0,0,1000,24000,25000,87,24021*100+12,24021*100+13,24021*100+14,24021*100+15,24021*100+16,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On update OOC - Run random script'),
(-115973,0,0,0,1,0,100,0,0,1000,24000,25000,87,24021*100+12,24021*100+13,24021*100+14,24021*100+15,24021*100+16,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On update OOC - Run random script'),
(-115974,0,0,0,1,0,100,0,0,1000,24000,25000,87,24021*100+12,24021*100+13,24021*100+14,24021*100+15,24021*100+16,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On update OOC - Run random script'),
(-115975,0,0,0,1,0,100,0,0,1000,24000,25000,87,24021*100+12,24021*100+13,24021*100+14,24021*100+15,24021*100+16,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On update OOC - Run random script'),
(-115976,0,0,0,1,0,100,0,0,1000,24000,25000,87,24021*100+12,24021*100+13,24021*100+14,24021*100+15,24021*100+16,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On update OOC - Run random script'),

(24021,0,0,0,54,0,100,0,0,0,0,0,80,24021*100+0,2,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - Just summoned - Run script'),

(26762,0,0,0,11,0,100,0,0,0,0,0,11,46906,0,0,0,0,0,10,115948,24021,0,0,0,0,0, 'Captain Emmy Malin - On spawn - Spellcast Surge Needle Beam'),
(26762,0,1,0,21,0,100,0,0,0,0,0,11,46906,0,0,0,0,0,10,115948,24021,0,0,0,0,0, 'Captain Emmy Malin - On homeposition reached - Spellcast Surge Needle Beam'),
(26762,0,2,0,9,0,100,0,0,40,3000,4000,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Emmy Malin - On target within 40y - Spellcast Frostbolt'),
(26762,0,3,0,0,0,100,0,7000,10000,9000,12000,11,49906,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Emmy Malin - On update IC - Spellcast Ice Lance'),
(26762,0,4,0,9,0,100,0,0,5,9000,12000,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Captain Emmy Malin - On target within 5y - Spellcast Frost Nova'),
(26762,0,5,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Captain Emmy Malin - On aggro - Say line'),

(26815,0,0,0,9,0,100,0,0,40,3000,4000,11,51779,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Lieutenant Ta''zinni - On target within 40y - Spellcast Frostfirebolt'),
(26815,0,1,0,9,0,100,0,0,10,12000,18000,11,35250,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Lieutenant Ta''zinni - On target within 10y - Spellcast Dragon''s Breath'),
(26815,0,2,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Lieutenant Ta''zinni - On aggro - Say line'),

(4956,2,0,0,46,0,100,0,4956,0,0,0,33,26889,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Areatrigger Azure Dragonshire - On trigger - Quest credit'),

(24021*100+0,9,0,0,0,0,100,0,0,0,0,0,11,47334,0,0,0,0,0,7,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large script 0 - Spellcast Ley Line Beam (no cast kit)'),
(24021*100+0,9,1,0,0,0,100,0,3000,4000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large  script 0 - Despawn'),

(24021*100+1,9,0,0,0,0,100,0,0,0,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3126.05,2140.401,17.8579,5.585053, 'ELM General Purpose Bunny Large script 1 - Summon ELM General Purpose Bunny Large'),
(24021*100+1,9,1,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3125.524,2146.786,15.84835,2.129302, 'ELM General Purpose Bunny Large script 1 - Summon ELM General Purpose Bunny Large'),
(24021*100+1,9,2,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3121.857,2144.208,19.87348,0.3141593, 'ELM General Purpose Bunny Large script 1 - Summon ELM General Purpose Bunny Large'),
(24021*100+1,9,3,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3131.571,2143.177,19.43405,0.4014257, 'ELM General Purpose Bunny Large script 1 - Summon ELM General Purpose Bunny Large'),
(24021*100+1,9,4,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3128.101,2141.035,17.94403,1.902409, 'ELM General Purpose Bunny Large script 1 - Summon ELM General Purpose Bunny Large'),
(24021*100+1,9,5,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3123.163,2141.134,16.98522,3.316126, 'ELM General Purpose Bunny Large script 1 - Summon ELM General Purpose Bunny Large'),

(24021*100+2,9,0,0,0,0,100,0,0,0,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3125.091,2140.601,17.71151,2.443461, 'ELM General Purpose Bunny Large script 2 - Summon ELM General Purpose Bunny Large'),
(24021*100+2,9,1,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3132.777,2149.866,15.00388,5.986479, 'ELM General Purpose Bunny Large script 2 - Summon ELM General Purpose Bunny Large'),
(24021*100+2,9,2,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3127.046,2144.976,16.4135,5.183628, 'ELM General Purpose Bunny Large script 2 - Summon ELM General Purpose Bunny Large'),
(24021*100+2,9,3,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3122.372,2139.047,17.24562,5.009095, 'ELM General Purpose Bunny Large script 2 - Summon ELM General Purpose Bunny Large'),
(24021*100+2,9,4,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3126.123,2142.99,17.00723,2.792527, 'ELM General Purpose Bunny Large script 2 - Summon ELM General Purpose Bunny Large'),
(24021*100+2,9,5,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3128.526,2145.889,15.85672,0.2443461, 'ELM General Purpose Bunny Large script 2 - Summon ELM General Purpose Bunny Large'),

(24021*100+3,9,0,0,0,0,100,0,0,0,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3126.866,2149.983,13.7796,1.832596, 'ELM General Purpose Bunny Large script 3 - Summon ELM General Purpose Bunny Large'),
(24021*100+3,9,1,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3131.825,2144.75,17.25836,1.570796, 'ELM General Purpose Bunny Large script 3 - Summon ELM General Purpose Bunny Large'),
(24021*100+3,9,2,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3121.043,2140.726,16.30317,4.24115, 'ELM General Purpose Bunny Large script 3 - Summon ELM General Purpose Bunny Large'),
(24021*100+3,9,3,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3129.281,2141.083,18.61101,3.124139, 'ELM General Purpose Bunny Large script 3 - Summon ELM General Purpose Bunny Large'),
(24021*100+3,9,4,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3125.717,2146.401,16.13597,5.72468, 'ELM General Purpose Bunny Large script 3 - Summon ELM General Purpose Bunny Large'),
(24021*100+3,9,5,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3123.911,2142.552,17.50746,4.380776, 'ELM General Purpose Bunny Large script 3 - Summon ELM General Purpose Bunny Large'),

(24021*100+4,9,0,0,0,0,100,0,0,0,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3130.754,2151.47,14.37193,5.183628, 'ELM General Purpose Bunny Large script 4 - Summon ELM General Purpose Bunny Large'),
(24021*100+4,9,1,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3124.838,2143.604,17.12428,0.4014257, 'ELM General Purpose Bunny Large script 4 - Summon ELM General Purpose Bunny Large'),
(24021*100+4,9,2,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3127.993,2143.675,16.80205,5.148721, 'ELM General Purpose Bunny Large script 4 - Summon ELM General Purpose Bunny Large'),
(24021*100+4,9,3,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3121.175,2142.392,17.06362,0.9075712, 'ELM General Purpose Bunny Large script 4 - Summon ELM General Purpose Bunny Large'),
(24021*100+4,9,4,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3128.526,2145.889,15.85672,0.2443461, 'ELM General Purpose Bunny Large script 4 - Summon ELM General Purpose Bunny Large'),
(24021*100+4,9,5,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3134.843,2147.028,18.17949,5.864306, 'ELM General Purpose Bunny Large script 4 - Summon ELM General Purpose Bunny Large'),

(24021*100+5,9,0,0,0,0,100,0,0,0,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3122.565,2142.866,17.20188,3.647738, 'ELM General Purpose Bunny Large script 5 - Summon ELM General Purpose Bunny Large'),
(24021*100+5,9,1,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3126.29,2142.063,17.4064,5.72468, 'ELM General Purpose Bunny Large script 5 - Summon ELM General Purpose Bunny Large'),
(24021*100+5,9,2,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3129.656,2149.474,14.7912,5.550147, 'ELM General Purpose Bunny Large script 5 - Summon ELM General Purpose Bunny Large'),
(24021*100+5,9,3,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3124.519,2149.514,14.5581,4.29351, 'ELM General Purpose Bunny Large script 5 - Summon ELM General Purpose Bunny Large'),
(24021*100+5,9,4,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3127.796,2138.372,19.97332,0.01745329, 'ELM General Purpose Bunny Large script 5 - Summon ELM General Purpose Bunny Large'),
(24021*100+5,9,5,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3132.397,2147.686,15.91525,0.9599311, 'ELM General Purpose Bunny Large script 5 - Summon ELM General Purpose Bunny Large'),

(24021*100+6,9,0,0,0,0,100,0,0,0,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3131.072,2147.995,15.61533,1.466077, 'ELM General Purpose Bunny Large script 6 - Summon ELM General Purpose Bunny Large'),
(24021*100+6,9,1,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3128.782,2144.123,16.61955,5.742133, 'ELM General Purpose Bunny Large script 6 - Summon ELM General Purpose Bunny Large'),
(24021*100+6,9,2,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3123.601,2139.016,17.71019,0.4537856, 'ELM General Purpose Bunny Large script 6 - Summon ELM General Purpose Bunny Large'),
(24021*100+6,9,3,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3133.935,2143.841,21.74682,6.178465, 'ELM General Purpose Bunny Large script 6 - Summon ELM General Purpose Bunny Large'),
(24021*100+6,9,4,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3126.675,2146.103,16.11657,1.43117, 'ELM General Purpose Bunny Large script 6 - Summon ELM General Purpose Bunny Large'),
(24021*100+6,9,5,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3130.211,2145.085,16.58946,2.827433, 'ELM General Purpose Bunny Large script 6 - Summon ELM General Purpose Bunny Large'),

(24021*100+7,9,0,0,0,0,100,0,0,0,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2894.85,1820.674,131.0997,1.012291, 'ELM General Purpose Bunny Large script 7 - Summon ELM General Purpose Bunny Large'),
(24021*100+7,9,1,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2891.408,1818.045,128.5932,0.541052, 'ELM General Purpose Bunny Large script 7 - Summon ELM General Purpose Bunny Large'),
(24021*100+7,9,2,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2888.546,1816.658,131.655,2.024582, 'ELM General Purpose Bunny Large script 7 - Summon ELM General Purpose Bunny Large'),
(24021*100+7,9,3,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2890.363,1810.202,129.936,0.7679449, 'ELM General Purpose Bunny Large script 7 - Summon ELM General Purpose Bunny Large'),
(24021*100+7,9,4,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2889.329,1822.168,130.1942,2.600541, 'ELM General Purpose Bunny Large script 7 - Summon ELM General Purpose Bunny Large'),
(24021*100+7,9,5,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2892.142,1809.754,129.4616,5.689773, 'ELM General Purpose Bunny Large script 7 - Summon ELM General Purpose Bunny Large'),

(24021*100+8,9,0,0,0,0,100,0,0,0,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2894.762,1813.133,132.1913,1.256637, 'ELM General Purpose Bunny Large script 8 - Summon ELM General Purpose Bunny Large'),
(24021*100+8,9,1,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2888.24,1811.167,131.9773,3.473205, 'ELM General Purpose Bunny Large script 8 - Summon ELM General Purpose Bunny Large'),
(24021*100+8,9,2,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2891.765,1820.341,128.2378,2.443461, 'ELM General Purpose Bunny Large script 8 - Summon ELM General Purpose Bunny Large'),
(24021*100+8,9,3,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2889.968,1816.515,130.1833,3.577925, 'ELM General Purpose Bunny Large script 8 - Summon ELM General Purpose Bunny Large'),
(24021*100+8,9,4,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2895.262,1817.665,131.9376,4.415683, 'ELM General Purpose Bunny Large script 8 - Summon ELM General Purpose Bunny Large'),
(24021*100+8,9,5,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2892.956,1819.63,129.6165,3.106686, 'ELM General Purpose Bunny Large script 8 - Summon ELM General Purpose Bunny Large'),

(24021*100+9,9,0,0,0,0,100,0,0,0,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2890.813,1812.197,129.4449,4.24115, 'ELM General Purpose Bunny Large script 9 - Summon ELM General Purpose Bunny Large'),
(24021*100+9,9,1,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2894.83,1810.606,132.5347,1.37881, 'ELM General Purpose Bunny Large script 9 - Summon ELM General Purpose Bunny Large'),
(24021*100+9,9,2,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2891.949,1816.533,128.7643,4.502949, 'ELM General Purpose Bunny Large script 9 - Summon ELM General Purpose Bunny Large'),
(24021*100+9,9,3,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2888.356,1820.349,131.507,3.839724, 'ELM General Purpose Bunny Large script 9 - Summon ELM General Purpose Bunny Large'),
(24021*100+9,9,4,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2893.333,1820.718,129.6705,1.48353, 'ELM General Purpose Bunny Large script 9 - Summon ELM General Purpose Bunny Large'),

(24021*100+10,9,0,0,0,0,100,0,0,0,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2889.118,1823.984,130.3343,3.455752, 'ELM General Purpose Bunny Large script 10 - Summon ELM General Purpose Bunny Large'),
(24021*100+10,9,1,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2896.332,1820.913,131.8123,5.689773, 'ELM General Purpose Bunny Large script 10 - Summon ELM General Purpose Bunny Large'),
(24021*100+10,9,2,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2894.166,1819.122,130.8789,3.211406, 'ELM General Purpose Bunny Large script 10 - Summon ELM General Purpose Bunny Large'),
(24021*100+10,9,3,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2890.605,1822.912,128.89,1.762783, 'ELM General Purpose Bunny Large script 10 - Summon ELM General Purpose Bunny Large'),
(24021*100+10,9,4,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2888.642,1809.098,131.9985,3.385939, 'ELM General Purpose Bunny Large script 10 - Summon ELM General Purpose Bunny Large'),
(24021*100+10,9,5,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2892.705,1812.745,129.8363,1.308997, 'ELM General Purpose Bunny Large script 10 - Summon ELM General Purpose Bunny Large'),

(24021*100+11,9,0,0,0,0,100,0,0,0,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2895.333,1822.925,131.1403,2.879793, 'ELM General Purpose Bunny Large script 11 - Summon ELM General Purpose Bunny Large'),
(24021*100+11,9,1,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2891.805,1822.136,128.129,6.161012, 'ELM General Purpose Bunny Large script 11 - Summon ELM General Purpose Bunny Large'),
(24021*100+11,9,2,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2894.475,1823.367,130.2928,1.937315, 'ELM General Purpose Bunny Large script 11 - Summon ELM General Purpose Bunny Large'),
(24021*100+11,9,3,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2889.26,1810.871,130.8892,0.8726646, 'ELM General Purpose Bunny Large script 11 - Summon ELM General Purpose Bunny Large'),
(24021*100+11,9,4,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,2893.049,1810.656,130.546,1.396263, 'ELM General Purpose Bunny Large script 11 - Summon ELM General Purpose Bunny Large'),

(24021*100+12,9,0,0,0,0,100,0,0,0,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3057.062,1394.183,113.0584,5.8294, 'ELM General Purpose Bunny Large script 12 - Summon ELM General Purpose Bunny Large'),
(24021*100+12,9,1,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3054.48,1394.618,112.7426,1.762783, 'ELM General Purpose Bunny Large script 12 - Summon ELM General Purpose Bunny Large'),
(24021*100+12,9,2,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3060.249,1394.656,113.9411,0.3141593, 'ELM General Purpose Bunny Large script 12 - Summon ELM General Purpose Bunny Large'),
(24021*100+12,9,3,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3055.488,1393.478,112.698,3.141593, 'ELM General Purpose Bunny Large script 12 - Summon ELM General Purpose Bunny Large'),
(24021*100+12,9,4,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3061.458,1396.66,115.1446,0.1570796, 'ELM General Purpose Bunny Large script 12 - Summon ELM General Purpose Bunny Large'),
(24021*100+12,9,5,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3051.968,1401.044,116.3351,0.9424778, 'ELM General Purpose Bunny Large script 12 - Summon ELM General Purpose Bunny Large'),

(24021*100+13,9,0,0,0,0,100,0,0,0,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3054.074,1397.247,113.4051,0.4712389, 'ELM General Purpose Bunny Large script 13 - Summon ELM General Purpose Bunny Large'),
(24021*100+13,9,1,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3057.188,1403.892,115.3656,4.380776, 'ELM General Purpose Bunny Large script 13 - Summon ELM General Purpose Bunny Large'),
(24021*100+13,9,2,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3052.451,1405.315,117.081,0.8552113, 'ELM General Purpose Bunny Large script 13 - Summon ELM General Purpose Bunny Large'),
(24021*100+13,9,3,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3059.104,1401.156,116.369,5.096361, 'ELM General Purpose Bunny Large script 13 - Summon ELM General Purpose Bunny Large'),
(24021*100+13,9,4,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3049.546,1404.567,114.6574,4.24115, 'ELM General Purpose Bunny Large script 13 - Summon ELM General Purpose Bunny Large'),
(24021*100+13,9,5,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3060.958,1399.016,117.6381,0.3665192, 'ELM General Purpose Bunny Large script 13 - Summon ELM General Purpose Bunny Large'),

(24021*100+14,9,0,0,0,0,100,0,0,0,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3056.078,1396.021,113.2624,1.919862, 'ELM General Purpose Bunny Large script 14 - Summon ELM General Purpose Bunny Large'),
(24021*100+14,9,1,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3051.097,1400.683,119.1771,3.124139, 'ELM General Purpose Bunny Large script 14 - Summon ELM General Purpose Bunny Large'),
(24021*100+14,9,2,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3061.056,1398.113,116.3519,2.303835, 'ELM General Purpose Bunny Large script 14 - Summon ELM General Purpose Bunny Large'),
(24021*100+14,9,3,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3057.511,1398.638,114.0719,0.4886922, 'ELM General Purpose Bunny Large script 14 - Summon ELM General Purpose Bunny Large'),
(24021*100+14,9,4,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3055.962,1397.876,113.629,4.171337, 'ELM General Purpose Bunny Large script 14 - Summon ELM General Purpose Bunny Large'),
(24021*100+14,9,5,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3053.035,1396.689,115.7215,3.054326, 'ELM General Purpose Bunny Large script 14 - Summon ELM General Purpose Bunny Large'),

(24021*100+15,9,0,0,0,0,100,0,0,0,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3054.111,1406.132,118.344,5.183628, 'ELM General Purpose Bunny Large script 15 - Summon ELM General Purpose Bunny Large'),
(24021*100+15,9,1,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3058.348,1399.74,114.4599,1.117011, 'ELM General Purpose Bunny Large script 15 - Summon ELM General Purpose Bunny Large'),
(24021*100+15,9,2,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3060.409,1401.954,119.1423,4.433136, 'ELM General Purpose Bunny Large script 15 - Summon ELM General Purpose Bunny Large'),
(24021*100+15,9,3,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3055.117,1405.109,116.396,1.867502, 'ELM General Purpose Bunny Large script 15 - Summon ELM General Purpose Bunny Large'),
(24021*100+15,9,4,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3051.709,1402.488,113.6939,5.009095, 'ELM General Purpose Bunny Large script 15 - Summon ELM General Purpose Bunny Large'),
(24021*100+15,9,5,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3059.448,1404.954,119.1292,4.712389, 'ELM General Purpose Bunny Large script 15 - Summon ELM General Purpose Bunny Large'),

(24021*100+16,9,0,0,0,0,100,0,0,0,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3056.558,1406.72,119.7402,3.124139, 'ELM General Purpose Bunny Large script 16 - Summon ELM General Purpose Bunny Large'),
(24021*100+16,9,1,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3052.471,1393.973,116.9445,5.637414, 'ELM General Purpose Bunny Large script 16 - Summon ELM General Purpose Bunny Large'),
(24021*100+16,9,2,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3061.914,1394.956,114.8677,0.7853982, 'ELM General Purpose Bunny Large script 16 - Summon ELM General Purpose Bunny Large'),
(24021*100+16,9,3,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3054.167,1403.503,114.3343,1.256637, 'ELM General Purpose Bunny Large script 16 - Summon ELM General Purpose Bunny Large'),
(24021*100+16,9,4,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3049.392,1406.412,118.5037,2.80998, 'ELM General Purpose Bunny Large script 16 - Summon ELM General Purpose Bunny Large'),
(24021*100+16,9,5,0,0,0,100,0,4000,4000,0,0,12,24021,8,4000,0,0,0,8,0,0,0,3057.68,1392.579,112.8306,2.792527, 'ELM General Purpose Bunny Large script 16 - Summon ELM General Purpose Bunny Large');
