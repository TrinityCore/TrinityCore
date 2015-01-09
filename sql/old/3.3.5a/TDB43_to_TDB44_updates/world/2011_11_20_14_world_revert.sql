-- revert 2011_11_20_11_world_sai.sql
SET @ENTRY := 26503;
UPDATE `creature_template` SET `AIName`='',`npcflag`=`npcflag`&~1,`IconName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`= @ENTRY AND `source_type`=0;
