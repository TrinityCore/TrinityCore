SET @NPC_QUETZLUN := 28030;
SET @NPC_MUFUNU := 28752;
SET @NPC_MUFUNU_KC := 28753;
SET @NPC_TUATUA := 28754;
SET @NPC_TUATUA_KC := 28755;
SET @NPC_HAWINNI := 28756;
SET @NPC_HAWINNI_KC := 28757;
SET @SPELL_HIGH_PRIEST_IMMUNITY := 4309;
SET @SPELL_HEX_OF_AIR_KNOCKBACK := 41909;
SET @SPELL_RANDOM_CIRCUMFERENCE_1 := 42267;
SET @SPELL_RANDOM_CIRCUMFERENCE_2 := 42274;
SET @SPELL_SUICIDE := 45254;
SET @SPELL_HEX := 52250;
SET @SPELL_HEXXING_STICK := 52251;
SET @SPELL_HEX_OF_AIR := 52249;
SET @SPELL_HEX_OF_FIRE := 52278;
SET @SPELL_TUATUA_ON_BURN := 52279;
SET @SPELL_HEX_OF_FROST := 52287;
SET @SPELL_HAWINNI_ON_FROZEN := 52303;
SET @SPELL_RANDOM_CIRCUMFERENCE := 52320;

DELETE FROM `creature_text` WHERE `entry` IN (@NPC_QUETZLUN,@NPC_MUFUNU,@NPC_TUATUA,@NPC_HAWINNI);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_QUETZLUN,0,0,'There is no escape. There is only my wrath!',14,0,100,0,0,0,'Quetz''lun'),
(@NPC_QUETZLUN,0,1,'Eternal damnation is your future.',14,0,100,0,0,0,'Quetz''lun'),
(@NPC_QUETZLUN,0,2,'My judgment is final.',14,0,100,0,0,0,'Quetz''lun'),
(@NPC_QUETZLUN,0,3,'Beg for your life. Plead. It will do you no good!',14,0,100,0,0,0,'Quetz''lun'),
(@NPC_QUETZLUN,0,4,'Burn in the fires of my fury!',14,0,100,0,0,0,'Quetz''lun'),
(@NPC_QUETZLUN,0,5,'Die!',14,0,100,0,0,0,'Quetz''lun'),
(@NPC_QUETZLUN,0,6,'You killed me and now I will kill you... over and over!',14,0,100,0,0,0,'Quetz''lun'),
(@NPC_QUETZLUN,0,7,'I find you wanting.',14,0,100,0,0,0,'Quetz''lun'),
(@NPC_MUFUNU,0,0,'NOOOOOOOOOoooooooo.......!',12,0,100,0,0,0,'Mu''funu'),
(@NPC_TUATUA,0,0,'FIRE! AHHHHHHHH!',12,0,100,0,0,0,'Tua-tua'),
(@NPC_TUATUA,1,0,'The high priestess is reduced to charcoal.',16,0,100,0,0,0,'Tua-Tua'),
(@NPC_HAWINNI,0,0,'%s becomes enraged!',16,0,100,0,0,0,'Hawinni'),
(@NPC_HAWINNI,1,0,'BRRRRRR!',12,0,100,0,0,0,'Hawinni'),
(@NPC_HAWINNI,2,0,'%s explodes!',16,0,100,0,0,0,'Hawinni');

UPDATE `creature_model_info` SET `bounding_radius`=0.875, `combat_reach`=1.75 WHERE `modelid`=25669;
UPDATE `creature_model_info` SET `bounding_radius`=1.5, `combat_reach`=3 WHERE `modelid`=25672;

DELETE FROM `conditions` WHERE `SourceEntry`=@SPELL_HEXXING_STICK AND `SourceTypeOrReferenceId`=17;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (@NPC_MUFUNU,@NPC_TUATUA);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,@SPELL_HEXXING_STICK,0,0,31,1,3,@NPC_MUFUNU,0,0,0,'','Spell Quetz''lun''s Hexxing Stick can only be casted on High Priest Mu''funu'),
(17,0,@SPELL_HEXXING_STICK,0,1,31,1,3,@NPC_TUATUA,0,0,0,'','Spell Quetz''lun''s Hexxing Stick can only be casted on High Priestess Tua-Tua'),
(17,0,@SPELL_HEXXING_STICK,0,2,31,1,3,@NPC_HAWINNI,0,0,0,'','Spell Quetz''lun''s Hexxing Stick can only be casted on High Priest Hawinni'),
(22,2,@NPC_MUFUNU,0,0,1,1,@SPELL_HEX_OF_AIR,0,0,1,0,'','SAI High Priest Mu''funu cast Shadow Channeling if aura Hex is not applied'),
(22,2,@NPC_TUATUA,0,0,1,1,@SPELL_HEX_OF_FIRE,0,0,1,0,'','SAI High Priestess Tua-tua remove Shadow Form and cast Shadow Channeling if aura Hex is not applied');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-@SPELL_HEX_OF_AIR_KNOCKBACK,@SPELL_TUATUA_ON_BURN,@SPELL_HEX_OF_FROST,@SPELL_HAWINNI_ON_FROZEN);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-@SPELL_HEX_OF_AIR_KNOCKBACK,@SPELL_SUICIDE,0,'On spellfade Hex of Air Knockback - Spellcast Suicide'),
(@SPELL_TUATUA_ON_BURN,@SPELL_SUICIDE,1,'On spellhit Tua-Tua on Burn - Spellcast Suicide'),
(@SPELL_HEX_OF_FROST,@SPELL_HIGH_PRIEST_IMMUNITY,2,'On aura Hex of Frost - Apply High Priest Immunity'),
(@SPELL_HAWINNI_ON_FROZEN,@SPELL_SUICIDE,1,'On spellhit Hawinni on Frozen - Spellcast Suicide');

-- SmartAIs
UPDATE `smart_scripts` SET `link`=1 WHERE `entryorguid`=@NPC_QUETZLUN;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_QUETZLUN AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_MUFUNU AND `source_type`=0 AND `id` IN (11,12,13);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_TUATUA AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_HAWINNI AND `source_type`=0 AND `id` IN (3,4,5);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_MUFUNU*100,@NPC_TUATUA*100,@NPC_HAWINNI*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_QUETZLUN,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,21,100,0,0,0,0,0,0, 'Quetz''lun - On update OOC - Say line'),

(@NPC_MUFUNU,0,11,0,8,0,100,0,@SPELL_HEX,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Mu''funu - On spellhit Hex - Set invincibility 1 HP'),
(@NPC_MUFUNU,0,12,13,2,0,100,1,0,0.1,0,0,33,@NPC_MUFUNU_KC,0,0,0,0,0,16,0,0,0,0,0,0,0, 'High Priest Mu''funu - On health below 0.1% - Quest credit'),
(@NPC_MUFUNU,0,13,0,61,0,100,0,0,0,0,0,80,@NPC_MUFUNU*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Mu''funu - On health below 0.1% - Run script'),
(@NPC_MUFUNU*100,9,0,0,0,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Mu''funu script - Set homeposition'),
(@NPC_MUFUNU*100,9,1,0,0,0,100,0,0,0,0,0,102,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Mu''funu script - Stop health regen'),
(@NPC_MUFUNU*100,9,2,0,0,0,100,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Mu''funu script - Set unit_flags IMMUNE_TO_PC'),
(@NPC_MUFUNU*100,9,3,0,0,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Mu''funu script - Evade'),
(@NPC_MUFUNU*100,9,4,0,0,0,100,0,0,0,0,0,42,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Mu''funu script - Remove invincibility'),
(@NPC_MUFUNU*100,9,5,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'High Priest Mu''funu script - Say line'),
(@NPC_MUFUNU*100,9,6,0,0,0,100,0,0,0,0,0,11,@SPELL_HEX_OF_AIR,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Mu''funu script - Spellcast Hex of Air'),
(@NPC_MUFUNU*100,9,7,0,0,0,100,0,10000,10000,0,0,11,@SPELL_HEX_OF_AIR_KNOCKBACK,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Mu''funu script - Spellcast Knockback'),
(@NPC_MUFUNU*100,9,8,0,0,0,100,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Mu''funu script - Remove unit_flags IMMUNE_TO_PC'),

(@NPC_TUATUA,0,0,0,11,0,100,0,0,0,0,0,11,51733,0,0,0,0,0,1,0,0,0,0,0,0,0,'High Priestess Tua-Tua - On spawn - Spellcast Shadow Channelling'),
(@NPC_TUATUA,0,1,2,21,0,100,0,0,0,0,0,28,29406,0,0,0,0,0,1,0,0,0,0,0,0,0,'High Priestess Tua-Tua - On homeposition reached - Spellcast Shadow Channelling'),
(@NPC_TUATUA,0,2,0,61,0,100,0,0,0,0,0,11,51733,0,0,0,0,0,1,0,0,0,0,0,0,0,'High Priestess Tua-Tua - On homeposition reached - Remove aura Shadowform'),
(@NPC_TUATUA,0,3,0,4,0,100,0,0,0,0,0,11,29406,0,0,0,0,0,1,0,0,0,0,0,0,0,'High Priestess Tua-Tua - On aggro - Spellcast Shadowform'),
(@NPC_TUATUA,0,4,0,0,0,100,0,2000,3000,15000,20000,11,51818,0,0,0,0,0,2,0,0,0,0,0,0,0,'High Priestess Tua-Tua - On update IC - Spellcast Shadow Word: Death'),
(@NPC_TUATUA,0,5,0,0,0,100,0,4000,5000,3000,5000,11,13860,0,0,0,0,0,2,0,0,0,0,0,0,0,'High Priestess Tua-Tua - On update IC - Spellcast Mind Blast'),
(@NPC_TUATUA,0,6,0,8,0,100,0,@SPELL_HEX,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priestess Tua-tua - On spellhit Hex - Set invincibility 1 HP'),
(@NPC_TUATUA,0,7,8,2,0,100,1,0,0.1,0,0,33,@NPC_TUATUA_KC,0,0,0,0,0,16,0,0,0,0,0,0,0, 'High Priestess Tua-tua - On health below 0.1% - Quest credit'),
(@NPC_TUATUA,0,8,0,61,0,100,0,0,0,0,0,80,@NPC_TUATUA*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priestess Tua-tua - On health below 0.1% - Run script'),
(@NPC_TUATUA*100,9,0,0,0,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priestess Tua-tua script - Set homeposition'),
(@NPC_TUATUA*100,9,1,0,0,0,100,0,0,0,0,0,102,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priestess Tua-tua script - Stop health regen'),
(@NPC_TUATUA*100,9,2,0,0,0,100,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priestess Tua-tua script - Set unit_flags IMMUNE_TO_PC'),
(@NPC_TUATUA*100,9,3,0,0,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priestess Tua-tua script - Evade'),
(@NPC_TUATUA*100,9,4,0,0,0,100,0,0,0,0,0,42,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priestess Tua-tua script - Remove invincibility'),
(@NPC_TUATUA*100,9,5,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'High Priestess Tua-tua script - Say line'),
(@NPC_TUATUA*100,9,6,0,0,0,100,0,0,0,0,0,11,@SPELL_HEX_OF_FIRE,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priestess Tua-tua script - Spellcast Hex of Fire'),
(@NPC_TUATUA*100,9,7,0,0,0,100,0,10000,10000,0,0,11,@SPELL_TUATUA_ON_BURN,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priestess Tua-tua script - Spellcast Tua-tua on Burn'),
(@NPC_TUATUA*100,9,8,0,0,0,100,0,0,0,0,0,3,0,25669,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priestess Tua-tua script - Change modelid'),
(@NPC_TUATUA*100,9,9,0,0,0,100,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priestess Tua-tua script - Remove unit_flags IMMUNE_TO_PC'),
(@NPC_TUATUA*100,9,10,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'High Priestess Tua-tua script - Say line'),

(@NPC_HAWINNI,0,3,0,8,0,100,0,@SPELL_HEX,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Hawinni - On spellhit Hex - Set invincibility 1 HP'),
(@NPC_HAWINNI,0,4,5,2,0,100,1,0,0.1,0,0,33,@NPC_HAWINNI_KC,0,0,0,0,0,16,0,0,0,0,0,0,0, 'High Priest Hawinni - On health below 0.1% - Quest credit'),
(@NPC_HAWINNI,0,5,0,61,0,100,0,0,0,0,0,80,@NPC_HAWINNI*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Hawinni - On health below 0.1% - Run script'),
(@NPC_HAWINNI*100,9,0,0,0,0,100,0,0,0,0,0,11,@SPELL_HEX_OF_FROST,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Hawinni script - Spellcast Hex of Frost'),
(@NPC_HAWINNI*100,9,1,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Hawinni script - Say line'),
(@NPC_HAWINNI*100,9,2,0,0,0,100,0,10000,10000,0,0,11,@SPELL_RANDOM_CIRCUMFERENCE_1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Hawinni script - Spellcast Random Circumference Point Bone'),
(@NPC_HAWINNI*100,9,3,0,0,0,100,0,0,0,0,0,11,@SPELL_RANDOM_CIRCUMFERENCE_2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Hawinni script - Spellcast Random Circumference Point Bone 2'),
(@NPC_HAWINNI*100,9,4,0,0,0,100,0,0,0,0,0,11,@SPELL_RANDOM_CIRCUMFERENCE_1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Hawinni script - Spellcast Random Circumference Point Bone'),
(@NPC_HAWINNI*100,9,5,0,0,0,100,0,0,0,0,0,11,@SPELL_RANDOM_CIRCUMFERENCE_2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Hawinni script - Spellcast Random Circumference Point Bone 2'),
(@NPC_HAWINNI*100,9,6,0,0,0,100,0,0,0,0,0,11,@SPELL_RANDOM_CIRCUMFERENCE,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Hawinni script - Spellcast Random Circumference Ice Chunk'),
(@NPC_HAWINNI*100,9,7,0,0,0,100,0,0,0,0,0,11,@SPELL_RANDOM_CIRCUMFERENCE_1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Hawinni script - Spellcast Random Circumference Point Bone'),
(@NPC_HAWINNI*100,9,8,0,0,0,100,0,0,0,0,0,11,@SPELL_RANDOM_CIRCUMFERENCE_2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Hawinni script - Spellcast Random Circumference Point Bone 2'),
(@NPC_HAWINNI*100,9,9,0,0,0,100,0,0,0,0,0,11,@SPELL_RANDOM_CIRCUMFERENCE,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Hawinni script - Spellcast Random Circumference Ice Chunk'),
(@NPC_HAWINNI*100,9,10,0,0,0,100,0,0,0,0,0,11,@SPELL_RANDOM_CIRCUMFERENCE,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Hawinni script - Spellcast Random Circumference Ice Chunk'),
(@NPC_HAWINNI*100,9,11,0,0,0,100,0,0,0,0,0,11,@SPELL_RANDOM_CIRCUMFERENCE,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Hawinni script - Spellcast Random Circumference Ice Chunk'),
(@NPC_HAWINNI*100,9,12,0,0,0,100,0,0,0,0,0,11,@SPELL_RANDOM_CIRCUMFERENCE,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Hawinni script - Spellcast Random Circumference Ice Chunk'),
(@NPC_HAWINNI*100,9,13,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0, 'High Priest Hawinni script - Say line'),
(@NPC_HAWINNI*100,9,14,0,0,0,100,0,0,0,0,0,42,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Hawinni script - Remove invincibility'),
(@NPC_HAWINNI*100,9,15,0,0,0,100,0,50,50,0,0,11,@SPELL_HAWINNI_ON_FROZEN,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Hawinni script - Spellcast Hawinni on Frozen'),
(@NPC_HAWINNI*100,9,16,0,0,0,100,0,0,0,0,0,3,0,25672,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Hawinni script - Change modelid');
