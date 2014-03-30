DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4848,0,5,0,61,1,100,2,0,15,100,100,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Darkcaster - Between 0-15% Mana - Increment Phase (Phase 1) (Normal Dungeon)");
UPDATE `smart_scripts` SET `event_type`=11, `event_flags`=1, `comment`= 'Val''kyr Guardian - On spawn install AI template caster - Cast Smite every 1.5/2.5 seconds' WHERE `entryorguid`=38391 AND `source_type`=0;
UPDATE `smart_scripts` SET `event_type`=11, `event_flags`=1, `comment`= 'Val''kyr Protector - On spawn install AI template caster - Cast Smite (Rank 12) every 1.5/2.5 seconds' WHERE `entryorguid`=38392 AND `source_type`=0;
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid`=31135 AND `source_type`=0 AND `id` IN (27);
UPDATE `smart_scripts` SET `link`=12 WHERE `entryorguid`=19707 AND `source_type`=0 AND `id` IN (11);
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid`=16332 AND `source_type`=0 AND `id` IN (9);
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid`=30860 AND `source_type`=0 AND `id` IN (11);
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid`=30285 AND `source_type`=0 AND `id` IN (5);
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid`=6221 AND `source_type`=0 AND `id` IN (19,20);
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid`=28079 AND `source_type`=0 AND `id` IN (12);
