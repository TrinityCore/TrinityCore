SET @NPC_WARLORD_ZOLMAZ := 28902;
SET @NPC_ENCHANTED_TIKI := 28927;
SET @GO_ZOLMAZ_GATE := 190784;
SET @GO_GATE_LEVER := 190834;

DELETE FROM `event_scripts` WHERE `id`=18940;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(18940,6,11,57571,180,0,0,0,0,0);

DELETE FROM `creature_text` WHERE `entry`=@NPC_WARLORD_ZOLMAZ;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_WARLORD_ZOLMAZ,0,0,'%s becomes enraged.',16,0,100,0,0,0,'Warlord Zol''Maz'),
(@NPC_WARLORD_ZOLMAZ,1,0,'You have an enchanted tiki? YOU KILLED MY FAMILY!',14,0,100,15,0,6200,'Warlord Zol''Maz'),
(@NPC_WARLORD_ZOLMAZ,2,0,'I WILL KILL YOU, $N!',14,0,100,0,0,0,'Warlord Zol''Maz');

UPDATE `creature_template` SET `dmg_multiplier`=2.75, `AIName`='SmartAI' WHERE `entry`=@NPC_WARLORD_ZOLMAZ;
UPDATE `creature_template` SET `minlevel`=77, `maxlevel`=77, `exp`=2, `mindmg`=371, `maxdmg`=522, `attackpower`=478, `dmg_multiplier`=1.75, `unit_flags`=32776, `unit_class`=2, `minrangedmg`=314, `maxrangedmg`=466, `rangedattackpower`=81, `AIName`='SmartAI', `equipment_id`=838 WHERE `entry`=@NPC_ENCHANTED_TIKI;
UPDATE `creature_model_info` SET `bounding_radius`=0.465, `combat_reach`=7.5 WHERE `modelid`=26286;

DELETE FROM `creature_template_addon` WHERE `entry`=@NPC_ENCHANTED_TIKI;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@NPC_ENCHANTED_TIKI,0,0,0,1,0,'52614 52670');

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@GO_GATE_LEVER;
UPDATE `gameobject_template` SET `flags`=4 WHERE `entry` IN (190836,191766,194126);
UPDATE `gameobject` SET `position_x`=6552.984, `position_y`=-3903.916, `position_z`=490.9412 WHERE `guid`=99744;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_WARLORD_ZOLMAZ,@NPC_ENCHANTED_TIKI) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GO_GATE_LEVER AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_WARLORD_ZOLMAZ,0,0,0,9,0,100,0,10,25,0,0,11,32323,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Warlord Zol''Maz - On target range 10-25y - Spellcast Charge'),
(@NPC_WARLORD_ZOLMAZ,0,1,2,2,0,100,1,0,20,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warlord Zol''Maz - On health below 20% - Spellcast Enrage'),
(@NPC_WARLORD_ZOLMAZ,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Warlord Zol''Maz - On health below 20% - Say line'),
(@NPC_WARLORD_ZOLMAZ,0,3,0,0,0,100,0,12000,12000,20000,20000,11,54670,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Warlord Zol''Maz - On update IC - Spellcast Decapitate'),
(@NPC_WARLORD_ZOLMAZ,0,4,0,2,0,100,1,0,35,0,0,11,40546,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warlord Zol''Maz - On health below 35% - Spellcast Retaliation'),
(@NPC_WARLORD_ZOLMAZ,0,5,0,38,0,100,0,0,1,0,0,1,1,7000,0,0,0,0,12,1,0,0,0,0,0,0, 'Warlord Zol''Maz - On data set 0 1 - Say line'),
(@NPC_WARLORD_ZOLMAZ,0,6,7,52,0,100,0,1,@NPC_WARLORD_ZOLMAZ,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Warlord Zol''Maz - On text over - Say line'),
(@NPC_WARLORD_ZOLMAZ,0,7,8,61,0,100,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warlord Zol''Maz - On text over - Remove unit_flags IMMUNE_TO_PC'),
(@NPC_WARLORD_ZOLMAZ,0,8,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Warlord Zol''Maz - On text over - Start attack'),
(@NPC_WARLORD_ZOLMAZ,0,9,10,6,0,100,0,0,0,0,0,32,0,0,0,0,0,0,14,57571,@GO_ZOLMAZ_GATE,0,0,0,0,0, 'Warlord Zol''Maz - On death - Reset gate'),
(@NPC_WARLORD_ZOLMAZ,0,10,0,61,0,100,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warlord Zol''Maz - On death - Set unit_flags IMMUNE_TO_PC'),
(@NPC_WARLORD_ZOLMAZ,0,11,10,21,0,100,0,0,0,0,0,32,0,0,0,0,0,0,14,57571,@GO_ZOLMAZ_GATE,0,0,0,0,0, 'Warlord Zol''Maz - On homeposition reached - Reset gate'),
(@NPC_ENCHANTED_TIKI,0,0,1,54,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@NPC_WARLORD_ZOLMAZ,50,0,0,0,0,0, 'Enchanted Tiki - Just summoned - Set data 0 1'),
(@NPC_ENCHANTED_TIKI,0,1,2,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Enchanted Tiki - Just summoned - Store targetlist'),
(@NPC_ENCHANTED_TIKI,0,2,3,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,@NPC_WARLORD_ZOLMAZ,50,0,0,0,0,0, 'Enchanted Tiki - Just summoned - Send target list'),
(@NPC_ENCHANTED_TIKI,0,3,0,61,0,100,0,0,0,0,0,3,0,25749,0,0,0,0,1,0,0,0,0,0,0,0, 'Enchanted Tiki - Just summoned - Set modelid'),
(@GO_GATE_LEVER,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,57571,@GO_ZOLMAZ_GATE,0,0,0,0,0, 'Gate lever - On activate - Activate gate');
