-- 
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128, `unit_flags`=`unit_flags`|768  WHERE  `entry` IN (26468, 26469, 26470);
