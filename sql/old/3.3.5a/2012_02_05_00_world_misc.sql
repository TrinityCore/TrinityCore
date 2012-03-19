-- Argent Tournament Trainers part
SET @SPELL_ON_ARGENT_MOUNT         := 63034;

SET @NPC_JAERAN_LOCKWOOD           := 33973;
SET @QUEST_MASTERY_OF_MELEE_A      := 13828;
SET @QUEST_MASTERY_OF_MELEE_H      := 13829;

SET @GOSSIP_MENU_JERAN_MOUNTED     := 10398;
SET @GOSSIP_MENU_JERAN_EXPLANATION := 10397; -- From Aokromes Sniffs

SET @GOSSIP_TEXT_JERAN_MOUNTED     := 14431;
SET @GOSSIP_TEXT_JERAN_EXPLANATION := 14434;
SET @SPELL_CREDIT_JERAN            := 64113;

SET @NPC_RUGAN_STEELBELLY          := 33972;
SET @QUEST_MASTERY_OF_CHARGE_A     := 13837;
SET @QUEST_MASTERY_OF_CHARGE_H     := 13839;

SET @GOSSIP_MENU_RUGAN_MOUNTED     := 10400;
SET @GOSSIP_MENU_RUGAN_EXPLANATION := 10399; -- From Aokromes Sniffs

SET @GOSSIP_TEXT_RUGAN_MOUNTED     := 14436;
SET @GOSSIP_TEXT_RUGAN_EXPLANATION := 14437;
SET @SPELL_CREDIT_RUGAN            := 64114;

SET @NPC_VALIS_WINDCHASER          := 33974;
SET @QUEST_MASTERY_OF_SH_BREAKER_A := 13835;
SET @QUEST_MASTERY_OF_SH_BREAKER_H := 13838;

SET @GOSSIP_MENU_VALIS_MOUNTED     := 10402;
SET @GOSSIP_MENU_VALIS_EXPLANATION := 10401; -- From Aokromes Sniffs

SET @GOSSIP_TEXT_VALIS_MOUNTED     := 14438;
SET @GOSSIP_TEXT_VALIS_EXPLANATION := 14439;
SET @SPELL_CREDIT_VALIS            := 64115;

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (@NPC_JAERAN_LOCKWOOD,@NPC_RUGAN_STEELBELLY,@NPC_VALIS_WINDCHASER);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_JAERAN_LOCKWOOD,@NPC_RUGAN_STEELBELLY,@NPC_VALIS_WINDCHASER) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@NPC_JAERAN_LOCKWOOD,0,0,0,64,0,100,0,0,0,0,0,98,@GOSSIP_MENU_JERAN_MOUNTED,@GOSSIP_TEXT_JERAN_MOUNTED,0,0,0,0,7,0,0,0,0,0,0,0,'Jeran Lockwood - Send different gossip when mounted (Requires conditions)'),
(@NPC_JAERAN_LOCKWOOD,0,1,3,62,0,100,0,@GOSSIP_MENU_JERAN_MOUNTED,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jeran Lockwood - Send text when option clicked'),
(@NPC_JAERAN_LOCKWOOD,0,2,3,62,0,100,0,@GOSSIP_MENU_JERAN_EXPLANATION,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jeran Lockwood - Send text when option clicked'),
(@NPC_JAERAN_LOCKWOOD,0,3,4,61,0,100,0,0,0,0,0,11,@SPELL_CREDIT_JERAN,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jeran Lockwood - Give Credit'),
(@NPC_JAERAN_LOCKWOOD,0,4,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Jeran Lockwood - Close Gossip'),

(@NPC_RUGAN_STEELBELLY,0,0,0,64,0,100,0,0,0,0,0,98,@GOSSIP_MENU_RUGAN_MOUNTED,@GOSSIP_TEXT_RUGAN_MOUNTED,0,0,0,0,7,0,0,0,0,0,0,0,'Rugan Steelbelly - Send different gossip when mounted (Requires conditions)'),
(@NPC_RUGAN_STEELBELLY,0,1,3,62,0,100,0,@GOSSIP_MENU_RUGAN_MOUNTED,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Rugan Steelbelly - Send text when option clicked'),
(@NPC_RUGAN_STEELBELLY,0,2,3,62,0,100,0,@GOSSIP_MENU_RUGAN_EXPLANATION,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Rugan Steelbelly - Send text when option clicked'),
(@NPC_RUGAN_STEELBELLY,0,3,4,61,0,100,0,0,0,0,0,11,@SPELL_CREDIT_RUGAN,0,0,0,0,0,7,0,0,0,0,0,0,0,'Rugan Steelbelly - Give Credit'),
(@NPC_RUGAN_STEELBELLY,0,4,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Rugan Steelbelly - Close Gossip'),

(@NPC_VALIS_WINDCHASER,0,0,0,64,0,100,0,0,0,0,0,98,@GOSSIP_MENU_VALIS_MOUNTED,@GOSSIP_TEXT_VALIS_MOUNTED,0,0,0,0,7,0,0,0,0,0,0,0,'Valis Windchaser - Send different gossip when mounted (Requires conditions)'),
(@NPC_VALIS_WINDCHASER,0,1,3,62,0,100,0,@GOSSIP_MENU_VALIS_MOUNTED,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Valis Windchaser - Send text when option clicked'),
(@NPC_VALIS_WINDCHASER,0,2,3,62,0,100,0,@GOSSIP_TEXT_VALIS_EXPLANATION,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Valis Windchaser - Send text when option clicked'),
(@NPC_VALIS_WINDCHASER,0,3,4,61,0,100,0,0,0,0,0,11,@SPELL_CREDIT_VALIS,0,0,0,0,0,7,0,0,0,0,0,0,0,'Valis Windchaser - Give Credit'),
(@NPC_VALIS_WINDCHASER,0,4,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Valis Windchaser - Close Gossip');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (@NPC_JAERAN_LOCKWOOD,@NPC_RUGAN_STEELBELLY,@NPC_VALIS_WINDCHASER);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (@GOSSIP_MENU_JERAN_MOUNTED,@GOSSIP_MENU_RUGAN_MOUNTED,@GOSSIP_MENU_VALIS_MOUNTED);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@NPC_JAERAN_LOCKWOOD,0,0,1,@SPELL_ON_ARGENT_MOUNT,0,0,0,'','SAI - Jeran Lockwood show different menu if player mounted'),
(15,@GOSSIP_MENU_JERAN_MOUNTED,0,0,0,9,@QUEST_MASTERY_OF_MELEE_A,0,0,0,'',"Jeran Lockwood - Show gossip if player has quest"),
(15,@GOSSIP_MENU_JERAN_MOUNTED,0,0,0,1,@SPELL_ON_ARGENT_MOUNT,0,0,0,'',"Jeran Lockwood - Show gossip if player has aura"),
(15,@GOSSIP_MENU_JERAN_MOUNTED,0,0,1,9,@QUEST_MASTERY_OF_MELEE_H,0,0,0,'',"Jeran Lockwood - Show gossip if player has quest"),
(15,@GOSSIP_MENU_JERAN_MOUNTED,0,0,1,1,@SPELL_ON_ARGENT_MOUNT,0,0,0,'',"Jeran Lockwood - Show gossip if player has aura"),
(15,@GOSSIP_MENU_JERAN_MOUNTED,1,0,0,9,@QUEST_MASTERY_OF_MELEE_A,0,0,0,'',"Jeran Lockwood - Show gossip if player has quest"),
(15,@GOSSIP_MENU_JERAN_MOUNTED,1,0,0,1,@SPELL_ON_ARGENT_MOUNT,0,0,0,'',"Jeran Lockwood - Show gossip if player has aura"),
(15,@GOSSIP_MENU_JERAN_MOUNTED,1,0,1,9,@QUEST_MASTERY_OF_MELEE_H,0,0,0,'',"Jeran Lockwood - Show gossip if player has quest"),
(15,@GOSSIP_MENU_JERAN_MOUNTED,1,0,1,1,@SPELL_ON_ARGENT_MOUNT,0,0,0,'',"Jeran Lockwood - Show gossip if player has aura"),

(22,1,@NPC_RUGAN_STEELBELLY,0,0,1,@SPELL_ON_ARGENT_MOUNT,0,0,0,'','SAI - Rugan Steelbelly show different menu if player mounted'),
(15,@GOSSIP_MENU_RUGAN_MOUNTED,0,0,0,9,@QUEST_MASTERY_OF_CHARGE_A,0,0,0,'',"Rugan Steelbelly - Show gossip if player has quest"),
(15,@GOSSIP_MENU_RUGAN_MOUNTED,0,0,0,1,@SPELL_ON_ARGENT_MOUNT,0,0,0,'',"Rugan Steelbelly - Show gossip if player has aura"),
(15,@GOSSIP_MENU_RUGAN_MOUNTED,0,0,1,9,@QUEST_MASTERY_OF_CHARGE_H,0,0,0,'',"Rugan Steelbelly - Show gossip if player has quest"),
(15,@GOSSIP_MENU_RUGAN_MOUNTED,0,0,1,1,@SPELL_ON_ARGENT_MOUNT,0,0,0,'',"Rugan Steelbelly - Show gossip if player has aura"),
(15,@GOSSIP_MENU_RUGAN_MOUNTED,1,0,0,9,@QUEST_MASTERY_OF_CHARGE_A,0,0,0,'',"Rugan Steelbelly - Show gossip if player has quest"),
(15,@GOSSIP_MENU_RUGAN_MOUNTED,1,0,0,1,@SPELL_ON_ARGENT_MOUNT,0,0,0,'',"Rugan Steelbelly - Show gossip if player has aura"),
(15,@GOSSIP_MENU_RUGAN_MOUNTED,1,0,1,9,@QUEST_MASTERY_OF_CHARGE_H,0,0,0,'',"Rugan Steelbelly - Show gossip if player has quest"),
(15,@GOSSIP_MENU_RUGAN_MOUNTED,1,0,1,1,@SPELL_ON_ARGENT_MOUNT,0,0,0,'',"Rugan Steelbelly - Show gossip if player has aura"),

(22,1,@NPC_VALIS_WINDCHASER,0,0,1,@SPELL_ON_ARGENT_MOUNT,0,0,0,'','SAI - Valis Windchaser show different menu if player mounted'),
(15,@GOSSIP_MENU_VALIS_MOUNTED,0,0,0,9,@QUEST_MASTERY_OF_SH_BREAKER_A,0,0,0,'',"Valis Windchaser - Show gossip if player has quest"),
(15,@GOSSIP_MENU_VALIS_MOUNTED,0,0,0,1,@SPELL_ON_ARGENT_MOUNT,0,0,0,'',"Valis Windchaser - Show gossip if player has aura"),
(15,@GOSSIP_MENU_VALIS_MOUNTED,0,0,1,9,@QUEST_MASTERY_OF_SH_BREAKER_H,0,0,0,'',"Valis Windchaser - Show gossip if player has quest"),
(15,@GOSSIP_MENU_VALIS_MOUNTED,0,0,1,1,@SPELL_ON_ARGENT_MOUNT,0,0,0,'',"Valis Windchaser - Show gossip if player has aura"),
(15,@GOSSIP_MENU_VALIS_MOUNTED,1,0,0,9,@QUEST_MASTERY_OF_SH_BREAKER_A,0,0,0,'',"Valis Windchaser - Show gossip if player has quest"),
(15,@GOSSIP_MENU_VALIS_MOUNTED,1,0,0,1,@SPELL_ON_ARGENT_MOUNT,0,0,0,'',"Valis Windchaser - Show gossip if player has aura"),
(15,@GOSSIP_MENU_VALIS_MOUNTED,1,0,1,9,@QUEST_MASTERY_OF_SH_BREAKER_H,0,0,0,'',"Valis Windchaser - Show gossip if player has quest"),
(15,@GOSSIP_MENU_VALIS_MOUNTED,1,0,1,1,@SPELL_ON_ARGENT_MOUNT,0,0,0,'',"Valis Windchaser - Show gossip if player has aura");

DELETE FROM `gossip_menu` WHERE `entry` IN (@GOSSIP_MENU_JERAN_EXPLANATION,@GOSSIP_MENU_RUGAN_EXPLANATION,@GOSSIP_MENU_VALIS_EXPLANATION);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(@GOSSIP_MENU_JERAN_EXPLANATION,@GOSSIP_TEXT_JERAN_EXPLANATION),
(@GOSSIP_MENU_RUGAN_EXPLANATION,@GOSSIP_TEXT_RUGAN_EXPLANATION),
(@GOSSIP_MENU_VALIS_EXPLANATION,@GOSSIP_TEXT_VALIS_EXPLANATION);

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (@GOSSIP_MENU_JERAN_MOUNTED,@GOSSIP_MENU_JERAN_EXPLANATION,@GOSSIP_MENU_RUGAN_MOUNTED,@GOSSIP_MENU_RUGAN_EXPLANATION,@GOSSIP_MENU_VALIS_MOUNTED,@GOSSIP_MENU_VALIS_EXPLANATION);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP_MENU_JERAN_MOUNTED,0,0,'Show me how to train with a Melee Target.',1,1,0,0,0,0,''),
(@GOSSIP_MENU_JERAN_MOUNTED,1,0,'Tell me more about Defend and Thrust!',1,1,@GOSSIP_MENU_JERAN_EXPLANATION,0,0,0,''),
(@GOSSIP_MENU_JERAN_EXPLANATION,0,0,'Show me how to train with a Melee Target.',1,1,0,0,0,0,''),

(@GOSSIP_MENU_RUGAN_MOUNTED,0,0,'Show me how to train with a Charge Target.',1,1,0,0,0,0,''),
(@GOSSIP_MENU_RUGAN_MOUNTED,1,0,'Tell me more about the Charge!',1,1,@GOSSIP_MENU_RUGAN_EXPLANATION,0,0,0,''),
(@GOSSIP_MENU_RUGAN_EXPLANATION,0,0,'Show me how to train with a Charge Target.',1,1,0,0,0,0,''),

(@GOSSIP_MENU_VALIS_MOUNTED,0,0,'Show me how to train with a Ranged Target.',1,1,0,0,0,0,''),
(@GOSSIP_MENU_VALIS_MOUNTED,1,0,'Tell me more about the Shield-Breaker!',1,1,@GOSSIP_MENU_VALIS_EXPLANATION,0,0,0,''),
(@GOSSIP_MENU_VALIS_EXPLANATION,0,0,'Show me how to train with a Ranged Target.',1,1,0,0,0,0,'');

DELETE FROM `creature_text` WHERE `entry` IN (@NPC_JAERAN_LOCKWOOD,@NPC_RUGAN_STEELBELLY,@NPC_VALIS_WINDCHASER);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_JAERAN_LOCKWOOD,0,0,'Put up defend$B|TInterface\\Icons\\ability_warrior_shieldmastery.blp:32|t$BThen use Thrust on a Melee Target$B|TInterface\\Icons\\inv_sword_65.blp:32|t',42,0,0,0,0,0,'Argent Tournament - Melee Tutorial'),
(@NPC_RUGAN_STEELBELLY,0,0,'Use Shield-Breaker on a Charge Target$B|TInterface\\Icons\\ability_warrior_shieldbreak.blp:32|t$BFollow up with Charge while the target is vulnerable$B|TInterface\\Icons\\ability_mount_charger.blp:32|t',42,0,0,0,0,0,'Argent Tournament - Charge Tutorial'),
(@NPC_VALIS_WINDCHASER,0,0,'Use Shield-Breaker on a Ranged Target$B|TInterface\\Icons\\ability_warrior_shieldbreak.blp:32|t$BThen use Shield-Breaker while the target is defenseless$B|TInterface\\Icons\\ability_warrior_shieldbreak.blp:32|t',42,0,0,0,0,0,'Argent Tournament - Ranged Tutorial');

-- Training Dummies Part
UPDATE `creature_template` SET `ScriptName` = 'npc_tournament_training_dummy' WHERE `entry` IN (33272,33229,33243);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=62709;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,62709,0,0,18,1,33845,0,0, '','Counterattack! (Argent Tournament) - Target near aspirant mounts'),
(13,0,62709,0,0,18,1,33323,0,0, '','Counterattack! (Argent Tournament) - Target near aspirant mounts');

DELETE FROM `spell_script_names` WHERE `spell_id`=62709;
INSERT INTO `spell_script_names` VALUES (62709, 'spell_gen_tournament_counterattack');
