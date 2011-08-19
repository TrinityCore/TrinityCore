-- Make training dummies immune to death grip
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|32 WHERE `ScriptName`='npc_training_dummy';
