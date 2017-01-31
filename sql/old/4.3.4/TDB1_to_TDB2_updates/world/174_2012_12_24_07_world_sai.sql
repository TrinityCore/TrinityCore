-- SmartGameobjectAI to spawn Eliza
DELETE FROM `smart_scripts` WHERE `entryorguid`=51708 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`event_type`,`event_param1`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`target_type`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUE
(51708,1,20,254,12,314,1,300000,0,1,8,-10267,52.52,42.54,2.5,'Eliza Grave Dirt - On Quest Complete - Spawn Eliza');
-- SmartAI for Eliza
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=314;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=314;
DELETE FROM `smart_scripts` WHERE `entryorguid`=314 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`link`,`event_type`,`event_phase_mask`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES 
(314,1,0,11,0,0,0,0,0,21,0,1,'Eliza - Phase 0 - On spawn - Prevent combat movement'),
(314,2,3,4,0,0,0,0,0,1,0,1,'Eliza - Phase 0 - On aggro - Say'),
(314,4,0,61,0,0,0,0,0,22,1,1,'Eliza - Phase 0 - On aggro - Set phase 1'),
(314,5,0,9,1,0,40,0,0,11,20819,5,'Eliza - Phase 1 - In combat - Cast Frostbolt'),
(314,6,0,9,1,0,5,0,0,21,1,1,'Eliza - Phase 1 - 0 to 5 yards - Activate combat movement'),
(314,7,0,9,1,5,35,0,0,21,0,1,'Eliza - Phase 1 - 5 to 35 yards - Deactivate combat movement'),
(314,8,0,9,1,35,80,0,0,21,1,1,'Eliza - Phase 1 - 35 to 80 yards - Activate combat movement'),
(314,9,0,0,1,4100,6400,72300,72300,11, 3107,1,'Eliza - Phase 1 - In combat - Summon Elizas Guard'),
(314,10,0,0,1,2100,2900,12500,36300,11,11831,5,'Eliza - Phase 1 - In combat - Cast Frost Nova'),
(314,11,12,3,1,0,7,0,0,21,1,1,'Eliza - Phase 1 - At 7% mana - Start combat movement'),
(314,12,0,61,1,0,0,0,0,22,2,1,'Eliza - Phase 1 - At 7% mana - Set phase 2'),
(314,13,0,3,2,100,15,100,100,22,1,1,'Eliza - Phase 2 - At 15% mana - Set phase 1');
-- Birth aura
DELETE FROM `creature_template_addon` WHERE `entry`=314;
INSERT INTO `creature_template_addon`(`entry`,`auras`) VALUE
(314,'26047');
-- Texts used in the SmartAI
-- DELETE FROM `creature_ai_texts` WHERE `entry`IN (-460,-461);
DELETE FROM `creature_text` WHERE `entry`=314;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`comment`) VALUES
(314,0,0,'Wait...you are not my husband.  But he must have sent you.  And you... look... delicious!',12,0,100,'Eliza'),
(314,0,1,'Aber? Is that you...? Oh...I''m so hungry, Aber! SO HUNGRY!!',12,0,100,'Eliza');
