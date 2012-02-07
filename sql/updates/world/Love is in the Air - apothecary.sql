SET @NPC_FRYE    := 36272;
SET @NPC_HUMMEL  := 36296;
SET @NPC_BAXTER  := 36565;
SET @NPC_CRAZED  := 36568;


SET @GUID  := ''; -- set by TDB
DELETE FROM `creature` WHERE `id` IN (@NPC_FRYE,@NPC_HUMMEL,@NPC_BAXTER);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,@NPC_FRYE,33,1,1,0,0,-205.449,2219.56,79.7633,3.85724,86400,0,0,269000,0,0,0,0,0),
(@GUID+1,@NPC_HUMMEL,33,1,1,0,0,-208.723,2218.5,79.7633,5.16886,86400,0,0,269000,0,0,0,0,0),
(@GUID+2,@NPC_BAXTER,33,1,1,0,0,-209.602,2215.42,79.7633,0.723503,86400,0,0, 269000,0,0,0,0,0);

UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35,`AIName`='',`ScriptName`='npc_apothecary_frye' WHERE `entry`=@NPC_FRYE;
UPDATE `creature_template` SET `gossip_menu_id`=10847,`faction_A`=35,`faction_H`=35,`AIName`='',`ScriptName`='npc_apothecary_hummel' WHERE `entry`=@NPC_HUMMEL;
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35,`AIName`='',`ScriptName`='npc_apothecary_baxter' WHERE `entry`=@NPC_BAXTER;
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_crazed_apothecary' WHERE `entry`=@NPC_CRAZED;

DELETE FROM `gossip_menu` WHERE `entry`=10847;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(10847, 15040);

DELETE FROM `creature_text` WHERE `entry` IN (@NPC_FRYE,@NPC_HUMMEL,@NPC_BAXTER);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_HUMMEL,0,0,"Did they bother to tell you who I am and why Iam doing this?",12,0,100,0,0,0,"say text"),
(@NPC_HUMMEL,1,0,"...or are they just using you like they do everybody else?",12,0,100,0,0,0,"say text"),
(@NPC_HUMMEL,2,0,"But what does it matter. It is time for this to end.",12,0,100,0,0,0,"say text"),
(@NPC_HUMMEL,3,0,"Baxter! Get in here and help! NOW!",12,0,100,0,0,0,"say text"),
(@NPC_HUMMEL,4,0,"It is time, Frye! Attack!",12,0,100,0,0,0,"say text"),
(@NPC_HUMMEL,5,0,"Apothecaries! Give your life for The Crown!",12,0,100,0,0,0,"say text"),
(@NPC_FRYE,0,0,"Great. We're nto gutless, we're incompetent.",12,0,100,0,0,0,"say text"),
(@NPC_BAXTER,0,0,"It has been the greatest honor of my life to server with you, Hummel.",12,0,100,0,0,0,"say text");

#DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (68530,68529);
#INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`)VALUES
#(17,0,68530,0,11,1,27288,0,0,'',"Ice Prison - Death Knight Champion"),
#(17,0,68529,0,11,1,27288,0,0,'',"Ice Prison - Death Knight Champion");

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (68530,68529);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(68530,-68529,0,'Remove Perfume Immune when Cologne Immune is applied'),
(68529,-68530,0,'Remove Cologne Immune when Perfume Immune is applied');