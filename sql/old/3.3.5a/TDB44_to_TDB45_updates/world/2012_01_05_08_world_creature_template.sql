-- Fix Highlord Nemesis Trainer
UPDATE `creature_template` SET `unit_flags`=131072,`flags_extra`=262144,`ScriptName`= 'npc_training_dummy' WHERE `entry`=32547;
