-- Remove beast lore info from all creatures
UPDATE `creature_template` SET `dynamicflags`=`dynamicflags`&~16;
