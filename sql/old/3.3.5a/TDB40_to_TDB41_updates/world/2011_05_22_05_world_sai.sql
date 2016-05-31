SET @Valkyr = 38391;
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (@Valkyr,@Valkyr+1); -- 9 scripts

UPDATE `creature_template` SET `AIName`='SmartAI',`exp`=2,`minlevel`=80,`maxlevel`=80,`baseattacktime`=2000,`unit_flags`=`unit_flags`|0x8000,`speed_walk`=2.8,`speed_run`=1.07143 WHERE `entry`=@Valkyr+1; -- Val'kyr Protector

DELETE FROM `creature_template_addon` WHERE `entry`=@Valkyr+1;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@Valkyr+1,0,0x3000000,0x801,0, NULL); -- Val'kyr Protector

DELETE FROM `smart_scripts` WHERE `entryorguid`=@Valkyr+1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Valkyr+1,0,0,0,25,0,100,0,0,0,0,0,58,1,71842,1500,2500,45,0,1,0,0,0,0,0,0,0, 'Val''kyr Protector - On reset install AI template caster - Cast Smite (Rank 12) every 1.5/2.5 seconds');
